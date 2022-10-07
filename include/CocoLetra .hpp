#ifndef __COCOLETRA_HPP__
#define __COCOLETRA_HPP__

#define TILE_COCOLETRA_P 22
#define TILE_COCOLETRA_A1 23
#define TILE_COCOLETRA_C 24
#define TILE_COCOLETRA_M 25
#define TILE_COCOLETRA_A2 26
#define TILE_COCOLETRA_N 27

#include "Tablero.hpp"
#include "Coco.hpp"
class Tablero;

class CocoLetra:public Coco
{
    public:
        CocoLetra(int px, int py, Letra l, Tablero* t);
        void IntentaComer();
        void Dibuja();
        ~CocoLetra();
    private:
        int letra;
};


#endif