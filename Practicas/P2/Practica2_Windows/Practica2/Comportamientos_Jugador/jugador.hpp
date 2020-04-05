#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"

#include <list>
#include <set>

struct Coordenadas{
    int x;
    int y;
    unsigned int dato;

    Coordenadas *dltizd = 0;
    Coordenadas *dltdcha = 0;
};

struct Estado {
  int fila;
  int columna;
  int orientacion;

  Estado& operator=(const Estado &este){
    if(this != &este){
        this->columna = este.columna;
        this->fila = este.fila;
        this->orientacion = este.orientacion;
    }
    return *this;
  }

    inline bool operator== (const Estado &pasado)const{
        return (this->fila == pasado.fila && this->columna == pasado.columna );
    }

    inline bool operator!= (const Estado &pasado)const{
        return !(*this == pasado );
    }
};

struct Nodo{
    Estado estado;
    Action accion;
    list<Action>accionesPosibles;
    list<Action>accionesLlegada;
    bool operator<(const Nodo &pasado)const{
        if(estado.fila < pasado.estado.fila)
            return true;
        else
            if(estado.fila == pasado.estado.fila && estado.columna < pasado.estado.columna)
                return true;
            else
                if(estado.fila == pasado.estado.fila && estado.columna == pasado.estado.columna && estado.orientacion < pasado.estado.orientacion)
                    return true;
                else
                    return false;
    }

    bool operator== (const Nodo &pasado)const{
        return (this->estado == pasado.estado && this->accion == pasado.accion &&
                this->accionesLlegada == pasado.accionesLlegada && this->accionesPosibles == pasado.accionesPosibles);
    }
};

class ComportamientoJugador : public Comportamiento {
  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size) {
      // Inicializar Variables de Estado
      fil = col = 99;
      brujula = 0; // 0: Norte, 1:Este, 2:Sur, 3:Oeste
      destino.fila = -1;
      destino.columna = -1;
      destino.orientacion = -1;
      ultimaAccion = actIDLE;
      hayPlan = false;
      bien_situado = false;
      InicializarMatrizPulgarcito();
      for(int imini=0; imini<9; imini++){
        for(int jmini=0; jmini<9; jmini++){
            miniMapa[imini][jmini] = '?';
        }
      }
      filp = colp = 99;
      marca = 1;
      girar_derecha = false;
      filk = colk = 4;
      primera_vez = false;
      contador = 0;
      aldeano_tonto = false;
    }
    ComportamientoJugador(std::vector< std::vector< unsigned char> > mapaR) : Comportamiento(mapaR) {
      // Inicializar Variables de Estado
      fil = col = 99;
      brujula = 0; // 0: Norte, 1:Este, 2:Sur, 3:Oeste
      destino.fila = -1;
      destino.columna = -1;
      destino.orientacion = -1;
      ultimaAccion = actIDLE;
      hayPlan = false;
      bien_situado = false;
      InicializarMatrizPulgarcito();
      for(int imini=0; imini<9; imini++){
        for(int jmini=0; jmini<9; jmini++){
            miniMapa[imini][jmini] = '?';
        }
      }
      filp = colp = 99;
      marca = 1;
      girar_derecha = false;
      filk = colk = 4;
      primera_vez = false;
      contador = 0;
      aldeano_tonto = false;
    }
    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);
    void VisualizaPlan(const Estado &st, const list<Action> &plan);
    void comprobarPosiblesAcciones(Nodo &pasado);
    Estado hacerNuevoEstado(const Estado &pasado, const Action &accion);
    ///// Nivel 3 //////
    void DescubrirMapa(const Sensores& sensores);
    void HayGPSCercano(const Sensores& sensores);
    void InicializarMatrizPulgarcito();
    Action AndarPulgarcito(const Sensores& sensores);
    Action DeterminarMovimiento(const Coordenadas& dlt, const Coordenadas& izd, const Coordenadas& dcha, const Sensores& sensores);
    void ActualizarDato(Coordenadas coor,unsigned int valor);
    void ActualizarDatoPuntero(Coordenadas *coor,unsigned int valor);
    Action BuscarMenor(const Coordenadas& dlt, const Coordenadas& izd, const Coordenadas& dcha, const Sensores& sensores);
    void descargarMapa(const Sensores& sensores);


    ComportamientoJugador * clone(){return new ComportamientoJugador(*this);}

  private:
    // Declarar Variables de Estado
    int fil, col, brujula;
    Estado destino;
    Estado destinoK;
    Estado origenK;
    list<Action> plan;

    // Nuevas Variables de Estado
    Action ultimaAccion;
    bool hayPlan;
    bool bien_situado;
    unsigned int pulgarcito[200][200];
    unsigned char miniMapa[9][9];
    int filp, colp, marca;
    bool girar_derecha;
    int filk, colk;
    bool gps_cerca=false;
    bool hayK = false;
    bool primera_vez;
    int contador;
    bool aldeano_tonto;



    bool pathFinding(const Estado &origen, const Estado &destino, list<Action> &plan);
    void PintaPlan(list<Action> plan);
};

#endif
