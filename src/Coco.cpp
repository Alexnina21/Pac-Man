#include "Coco.hpp"
#include "NoEntiendo.hpp"
#include <stdio.h>

Coco::Coco(int px, int py,  Tablero* t)
{
    posX = px;
    posY = py;
    tablero = t;
    comido = false;
}
void Coco::Actualiza()
{

}
int Coco::ObtenPosX()
{
    return posX;
}
int Coco::ObtenPosY()
{
    return posY;
}
bool Coco::EstaComido()
{
    return comido;
}
void Coco::IntentaComer()
{
    if(EstaComido() == false)
    {
        comido = true;
    }
}
void Coco::Dibuja()
{
    NOE_PonTile(TILEMAP_COCOS, posX, posY, 1);
}
Coco::~Coco()
{

}