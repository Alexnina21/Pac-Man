#include "CocoOrientado.hpp"
#include "Coco.hpp"
#include "Tablero.hpp"
#include "NoEntiendo.hpp"
#include "Pacman.hpp"
#include <stdio.h>

CocoOrientado::CocoOrientado(int px, int py, Direcciones d, Tablero* t):Coco(px, py, t)
{
    direccion = d;
}
void CocoOrientado::IntentaComer()
{
    if(direccion == tablero->ObtenPacman()->ObtenDireccion() && EstaComido() == false)
    {
        comido = true;
    }
}
void CocoOrientado::Dibuja()
{    
    switch (direccion)
    {
        case DIRECCION_ARRIBA:
        NOE_PonTile(TILEMAP_COCOS, posX, posY, 18);
        break;
        case DIRECCION_ABAJO:
        NOE_PonTile(TILEMAP_COCOS, posX, posY, 19);
        break;
        case DIRECCION_IZQUIERDA:
        NOE_PonTile(TILEMAP_COCOS, posX, posY, 20);
        break;
        case DIRECCION_DERECHA:
        NOE_PonTile(TILEMAP_COCOS, posX, posY, 21);
        break;
    
    default:
        break;
    }
}
CocoOrientado::~CocoOrientado()
{

}