#ifndef __COCOORIENTADO_HPP__
#define __COCOORIENTADO_HPP__

#define TILE_COCOORIENTADO_ARRIBA 18
#define TILE_COCOORIENTADO_ABAJO 19
#define TILE_COCOORIENTADO_IZQUIERDA 20
#define TILE_COCOORIENTADO_DERECHA 21

#include "Tablero.hpp"
#include "Coco.hpp"
class Tablero;

class CocoOrientado:public Coco
{
    public:
        CocoOrientado(int px, int py,  Direcciones d, Tablero* t);
        void IntentaComer();
        void Dibuja();
        ~CocoOrientado();
    private:
        int direccion;
};


#endif