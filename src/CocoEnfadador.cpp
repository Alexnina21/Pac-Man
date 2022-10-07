#include "CocoEnfadador .hpp"
#include "Coco.hpp"
#include "Tablero.hpp"
#include "NoEntiendo.hpp"
#include "Pacman.hpp"
#include <stdio.h>

CocoEnfadador::CocoEnfadador(int px, int py, Tablero* t):Coco(px, py, t)
{
    
}
void CocoEnfadador::IntentaComer()
{
    if(EstaComido() == false)
    {
        comido = true;
        tablero->BuscaPacman(posX, posY)->Enfada();
    }
}
void CocoEnfadador::Dibuja()
{    
     NOE_PonTile(TILEMAP_COCOS, posX, posY, 2);
}
CocoEnfadador::~CocoEnfadador()
{

}