#include "Pared.hpp"
#include "NoEntiendo.hpp"
#include <stdio.h>

Pared::Pared(int px, int py)
{
    posX = px;
    posY = py;
}
void Pared::Actualiza()
{

}
int Pared::ObtenPosX()
{
    return posX;
}
int Pared::ObtenPosY()
{
    return posY;
}
void Pared::Dibuja()
{
    NOE_PonTile(TILEMAP_PAREDES, posX, posY, 17);
}
Pared::~Pared()
{

}