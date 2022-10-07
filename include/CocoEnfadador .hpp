#ifndef __COCOENFADADOR_HPP__
#define __COCOENFADADOR_HPP__

#define TILE_COCOENFADADOR 2


#include "Tablero.hpp"
#include "Coco.hpp"
class Tablero;

class CocoEnfadador:public Coco
{
    public:
        CocoEnfadador(int px, int py, Tablero* t);
        void IntentaComer();
        void Dibuja();
        ~CocoEnfadador();
};


#endif