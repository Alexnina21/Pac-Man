#include "CocoLetra .hpp"
#include "Coco.hpp"
#include "Tablero.hpp"
#include "NoEntiendo.hpp"
#include "Pacman.hpp"
#include <stdio.h>

CocoLetra::CocoLetra(int px, int py, Letra l, Tablero* t):Coco(px, py, t)
{
    letra = l;
}
void CocoLetra::IntentaComer()
{
    switch (tablero->ObtenPacman()->ObtenNumLetrasRecibidas())
    {
        case 0:
        if(letra == LETRA_P)
        {
            tablero->ObtenPacman()->RecibeLetra();
            comido = true;
        }
        break;
        case 1:
        if(letra == LETRA_A1)
        {
            tablero->ObtenPacman()->RecibeLetra();
            comido = true;
        }
        break;
        case 2:
        if(letra == LETRA_C)
        {
            tablero->ObtenPacman()->RecibeLetra();
            comido = true;
        }
        break;
        case 3:
        if(letra == LETRA_M)
        {
            tablero->ObtenPacman()->RecibeLetra();
            comido = true;
        }
        break;
        case 4:
        if(letra == LETRA_A2)
        {
            tablero->ObtenPacman()->RecibeLetra();
            comido = true;
        }
        break;
        case 5:
        if(letra == LETRA_N)
        {
            tablero->ObtenPacman()->RecibeLetra();
            comido = true;
        }
        break;
    
    default:
        break;
    }
}
void CocoLetra::Dibuja()
{
    
    switch (letra)
    {
        case LETRA_P:
        NOE_PonTile(TILEMAP_COCOS, posX, posY, 22);
        break;
        case LETRA_A1:
        NOE_PonTile(TILEMAP_COCOS, posX, posY, 23);
        break;
        case LETRA_C:
        NOE_PonTile(TILEMAP_COCOS, posX, posY, 24);
        break;
        case LETRA_M:
        NOE_PonTile(TILEMAP_COCOS, posX, posY, 25);
        break;
        case LETRA_A2:
        NOE_PonTile(TILEMAP_COCOS, posX, posY, 26);
        break;
        case LETRA_N:
        NOE_PonTile(TILEMAP_COCOS, posX, posY, 27);
        break;
    
    default:
        break;
    }
}
CocoLetra::~CocoLetra()
{

}