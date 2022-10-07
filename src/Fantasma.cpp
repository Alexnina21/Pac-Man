#include "Fantasma.hpp"
#include <stdio.h>
#include "NoEntiendo.hpp"
#include "Pared.hpp"
#include "Tablero.hpp"

Fantasma::Fantasma(int px, int py, Tablero *t)
{
    posX = px;
    posY = py;
    tablero = t;
    enPersecucion = false;

    direccion = DIRECCION_FANTASMA_DERECHA;
}
bool Fantasma::asustados = false;
void Fantasma::CompruebaChoques(Pared* paredes[], int numParedes)
{
    chocaConParedAbajo = false;
    chocaConParedArriba = false;
    chocaConParedDerecha = false;
    chocaConParedIzquierda = false;
    for (int i = 0; i < numParedes; i++)
    {
        if(posX == paredes[i]->ObtenPosX() && posY - 1 == paredes[i]->ObtenPosY())
        {
            chocaConParedArriba = true;
        }
        if(posX == paredes[i]->ObtenPosX() && posY + 1 == paredes[i]->ObtenPosY())
        {
            chocaConParedAbajo = true;
        }
        if(posY == paredes[i]->ObtenPosY() && posX - 1 == paredes[i]->ObtenPosX())
        {
            chocaConParedIzquierda = true;
        }
        if(posY == paredes[i]->ObtenPosY() && posX + 1 == paredes[i]->ObtenPosX())
        {
            chocaConParedDerecha = true;
        }
    }
}
void Fantasma::Actualiza()
{
    int direction = BuscaPacman();
    int random;
    random = NOE_ObtenNumeroAleatorio(0, 1);


    if(asustados == false)
    {
        if (oculto == true)
        {
            oculto = false;
        }
        
        if((random == 1 || enPersecucion) && direction >= 0)
        {    
            enPersecucion = true;

            direccion = (DireccionFamtasma)direction;
            if(direction == DIRECCION_FANTASMA_ARRIBA && chocaConParedArriba == false)
            {
                posY = ObtenPosY() -1;
            }
            else if(direction == DIRECCION_FANTASMA_ABAJO && chocaConParedAbajo == false)
            {
                posY = ObtenPosY() +1;
            }
            else if(direction == DIRECCION_FANTASMA_IZQUIERDA && chocaConParedIzquierda == false)
            {
                posX = ObtenPosX() -1;
            }
            else if(direction == DIRECCION_FANTASMA_DERECHA && chocaConParedDerecha == false)
            {
                posX = ObtenPosX() +1;
            }
            else
            {
                Actualiza();
            }
        }
        else
        {
            enPersecucion = false;
            random = NOE_ObtenNumeroAleatorio(0, 4);

            if(random == DIRECCION_FANTASMA_ARRIBA && chocaConParedArriba == false)
            {
                posY = ObtenPosY() -1;
            }
            else if(random == DIRECCION_FANTASMA_ABAJO && chocaConParedAbajo == false)
            {
                posY = ObtenPosY() +1;
            }
            else if(random == DIRECCION_FANTASMA_IZQUIERDA && chocaConParedIzquierda == false)
            {
                posX = ObtenPosX() -1;
            }
            else if(random == DIRECCION_FANTASMA_DERECHA && chocaConParedDerecha == false)
            {
                posX = ObtenPosX() +1;
            }
            else
            {
                Actualiza();
            }
        }                
    }
    else
    {
        if((random == 1 || enPersecucion) && direction >= 0)
        {    
            enPersecucion = true;

            direccion = (DireccionFamtasma)direction;
            if(direction == DIRECCION_FANTASMA_ABAJO && chocaConParedAbajo == false)
            {
                posY = ObtenPosY() -1;
            }
            else if(direction == DIRECCION_FANTASMA_ARRIBA && chocaConParedAbajo == false)
            {
                posY = ObtenPosY() +1;
            }
            else if(direction == DIRECCION_FANTASMA_DERECHA && chocaConParedIzquierda == false)
            {
                posX = ObtenPosX() -1;
            }
            else if(direction == DIRECCION_FANTASMA_IZQUIERDA && chocaConParedDerecha == false)
            {
                posX = ObtenPosX() +1;
            }
            else
            {
                Actualiza();
            }
        }
        else
        {
            enPersecucion = false;
            random = NOE_ObtenNumeroAleatorio(0, 4);

            if(random == DIRECCION_FANTASMA_ABAJO && chocaConParedArriba == false)
            {
                posY = ObtenPosY() -1;
            }
            else if(random == DIRECCION_FANTASMA_ARRIBA && chocaConParedAbajo == false)
            {
                posY = ObtenPosY() +1;
            }
            else if(random == DIRECCION_FANTASMA_DERECHA && chocaConParedIzquierda == false)
            {
                posX = ObtenPosX() -1;
            }
            else if(random == DIRECCION_FANTASMA_IZQUIERDA && chocaConParedDerecha == false)
            {
                posX = ObtenPosX() +1;
            }
            else
            {
                Actualiza();
            }
        }
    }

}
int Fantasma::ObtenPosX()
{
    return posX;
}
int Fantasma::ObtenPosY()
{
    return posY;
}
void Fantasma::Asustar()
{
    asustados = true;
}
void Fantasma::Tranquilizar()
{
    asustados = false;
}
void Fantasma::Oculta()
{
    oculto = true;
}
void Fantasma::Dibuja()
{
    if(oculto == true)
    {
    }
    else if(asustados == true)
    {
        NOE_PonTile(TILEMAP_FANTASMA, posX, posY, 11);
    }
    else
    {
        NOE_PonTile(TILEMAP_FANTASMA, posX, posY, 8);
    }
    
    
}
int Fantasma::BuscaPacman()
{
    int ret = -1;

    if(tablero->BuscaPacmanDireccion(posX, posY, 0, -1))
    {
        ret = DIRECCION_FANTASMA_ARRIBA;
    }
    else if(tablero->BuscaPacmanDireccion(posX, posY, 0, 1))
    {
        ret = DIRECCION_FANTASMA_ABAJO;
    }
    else if(tablero->BuscaPacmanDireccion(posX, posY, -1, 0))
    {
        ret = DIRECCION_FANTASMA_IZQUIERDA;
    }
    else if(tablero->BuscaPacmanDireccion(posX, posY, 1, 0))
    {
        ret = DIRECCION_FANTASMA_DERECHA;
    }

    return ret;
}
Fantasma::~Fantasma()
{

}
