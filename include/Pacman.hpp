#ifndef __PACMAN_HPP__
#define __PACMAN_HPP__

#define TILEMAP_PACMAN 3
#define CICLOS_ENFADO_PACMAN 20

#include "Tablero.hpp"
class Tablero;
class Pacman
{
    public:
        Pacman(int px, int py, Tablero *t, Direcciones d);
        void CompruebaChoques();
        void Actualiza();
        void RecibeLetra();
        int ObtenNumLetrasRecibidas();
        Direcciones ObtenDireccion();
        int ObtenPosX();
        int ObtenPosY();
        bool EstaMuerto();
        bool Enfada();
        void Dibuja();
        ~Pacman();
    private:
        bool muerto;
        Direcciones direccion;
        int numLetrasRecibidas;
        int posX;
        int posY;
        bool chocaConParedArriba;
        bool chocaConParedAbajo;
        bool chocaConParedIzquierda;
        bool chocaConParedDerecha;
        bool enfadado;
        int ciclosEnfado;
        Tablero * tablero;
        int tile;
};

#endif