#include "Pacman.hpp"
#include "Fantasma.hpp"
#include "Pared.hpp"
#include "Coco.hpp"
#include "CocoLetra .hpp"
#include "CocoOrientado.hpp"
#include "CocoEnfadador .hpp"
#include <stdio.h>
#include "NoEntiendo.hpp"
#include "Tablero.hpp"

Tablero::Tablero()
{
    numCocos = 0;
    numParedes = 0;
    numCocos = 0;
    alto = 8;
    ancho = 12;
    int tabl[8][12] = {{0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                       {0, 0, 0, 1, 22, 3, 3, 23, 3, 3, 24, 1},
                       {0, 0, 0, 1, 3, 1, 1, 3, 1, 1, 3, 1},
                       {0, 0, 0, 1, 3, 1, 1, 19, 1, 1, 3, 1},
                       {0, 0, 0, 1, 2, 3, 21, 3, 20, 3, 2, 1},
                       {0, 0, 0, 1, 3, 1, 1, 18, 1, 1, 3, 1},
                       {0, 0, 0, 1, 25, 3, 3, 26, 3, 3, 27, 1},
                       {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    for (int i = 0; i < alto; i++)
    {
        for (int j = 0; j < ancho; j++)
        {
            if (tabl[i][j] == 1)
            {
                paredes[numParedes] = new Pared(j, i);
                numParedes++;
            }
            else if (tabl[i][j] == 3)
            {
                cocos[numCocos] = new Coco(j, i, this);
                numCocos++;
            }
            else if (tabl[i][j] == 2)
            {
                cocos[numCocos] = new CocoEnfadador(j, i, this);
                numCocos++;
            }
            else if (tabl[i][j] == 22)
            {
                cocos[numCocos] = new CocoLetra(j, i, LETRA_P, this);
                numCocos++;
            }
            else if (tabl[i][j] == 23)
            {
                cocos[numCocos] = new CocoLetra(j, i, LETRA_A1, this);
                numCocos++;
            }
            else if (tabl[i][j] == 24)
            {
                cocos[numCocos] = new CocoLetra(j, i, LETRA_C, this);
                numCocos++;
            }
            else if (tabl[i][j] == 25)
            {
                cocos[numCocos] = new CocoLetra(j, i, LETRA_M, this);
                numCocos++;
            }
            else if (tabl[i][j] == 26)
            {
                cocos[numCocos] = new CocoLetra(j, i, LETRA_A2, this);
                numCocos++;
            }
            else if (tabl[i][j] == 27)
            {
                cocos[numCocos] = new CocoLetra(j, i, LETRA_N, this);
                numCocos++;
            }
            else if (tabl[i][j] == 18)
            {
                cocos[numCocos] = new CocoOrientado(j, i, DIRECCION_ARRIBA, this);
                numCocos++;
            }
            else if (tabl[i][j] == 19)
            {
                cocos[numCocos] = new CocoOrientado(j, i, DIRECCION_ABAJO, this);
                numCocos++;
            }
            else if (tabl[i][j] == 20)
            {
                cocos[numCocos] = new CocoOrientado(j, i, DIRECCION_IZQUIERDA, this);
                numCocos++;
            }
            else if (tabl[i][j] == 21)
            {
                cocos[numCocos] = new CocoOrientado(j, i, DIRECCION_DERECHA, this);
                numCocos++;
            }
        }
    }

    for (numFantasmas = 0; numFantasmas < 1; numFantasmas++)
    {
        fantasmas[numFantasmas] = new Fantasma(4, 1, this);
    }
    pacman = new Pacman(7, 4, this, DIRECCION_DERECHA);
}
void Tablero::CompruebaChoques()
{
    for (int i = 0; i < numFantasmas; i++)
    {
        fantasmas[i]->CompruebaChoques(paredes, numParedes);
    }
    pacman->CompruebaChoques();
}
void Tablero::Actualiza()
{
    for (int i = 0; i < numParedes; i++)
    {
        paredes[i]->Actualiza();
    }
    for (int i = 0; i < numCocos; i++)
    {
        cocos[i]->Actualiza();
    }
    for (int i = 0; i < numFantasmas; i++)
    {
        fantasmas[i]->Actualiza();
    }
    pacman->Actualiza();
    int aux = 0;
    for (int i = 0; i < numCocos; i++)
    {

        if (cocos[i]->EstaComido() == false)
        {
            aux++;
        }
        numCocosComidos = numCocos - aux;
    }
}
void Tablero::Dibuja()
{
    NOE_LimpiaTilemap(TILEMAP_PAREDES, 0);
    NOE_LimpiaTilemap(TILEMAP_COCOS, 0);
    NOE_LimpiaTilemap(TILEMAP_FANTASMA, 0);
    NOE_LimpiaTilemap(TILEMAP_PACMAN, 0);

    for (int i = 0; i < numParedes; i++)
    {
        paredes[i]->Dibuja();
    }
    for (int i = 0; i < numCocos; i++)
    {
        if (cocos[i]->EstaComido() == false)
        {
            cocos[i]->Dibuja();
        }
    }

    for (int i = 0; i < numFantasmas; i++)
    {
        fantasmas[i]->Dibuja();
    }

    pacman->Dibuja();

    NOE_DibujaTilemap(TILEMAP_PAREDES);
    NOE_DibujaTilemap(TILEMAP_COCOS);
    NOE_DibujaTilemap(TILEMAP_FANTASMA);
    NOE_DibujaTilemap(TILEMAP_PACMAN);
}
Pacman *Tablero::ObtenPacman()
{
    return pacman;
}
Pared *Tablero::BuscaPared(int posX, int posY)
{
    Pared *pared = 0;

    for (int i = 0; i < numParedes; i++)
    {
        if (paredes[i]->ObtenPosX() == posX && paredes[i]->ObtenPosY() == posY)
        {
            pared = paredes[i];
        }
    }

    return pared;
}
Fantasma *Tablero::BuscaFantasma(int posX, int posY)
{
    Fantasma *casper = 0;

    for (int i = 0; i < numFantasmas; i++)
    {
        if (fantasmas[i]->ObtenPosX() == posX && fantasmas[i]->ObtenPosY() == posY)
        {
            casper = fantasmas[i];
        }
    }

    return casper;
}
Pacman *Tablero::BuscaPacman(int posX, int posY)
{
    Pacman *pac = 0;

    if (pacman->ObtenPosX() == posX && pacman->ObtenPosY() == posY)
    {
        pac = pacman;
    }

    return pac;
}
Pacman *Tablero::BuscaPacmanDireccion(int posX, int posY, int dirX, int dirY)
{
    if(dirX!=0){
        for(int i=posX; true; i+=dirX){
            if(BuscaPared(i,posY)!=0){
                if(BuscaPacman(i, posY)!=0){
                    return BuscaPacman(i, posY);

                }
            }
            else{
                return 0;
            }
        }
    }
    else{
        for(int i=posY; true; i+=dirY){
            if(BuscaPared(posX,i)!=0){
                if(BuscaPacman(posX, i)!=0){
                    return BuscaPacman(posX, i);
            
                }
            }
            else{
                return 0;
            }     
        }
    }
    return 0;
}
Coco *Tablero::BuscaCoco(int posX, int posY)
{
    Coco *coc = 0;

    for (int i = 0; i < numCocos; i++)
    {
        if (cocos[i]->ObtenPosX() == posX && cocos[i]->ObtenPosY() == posY)
        {
            coc = cocos[i];
        }
    }

    return coc;
}
bool Tablero::TodosCocosComidos()
{
    bool full = false;

    if (numCocos == numCocosComidos)
    {
        full = true;
    }

    return full;
}
Tablero::~Tablero()
{
    for (int i = 0; i < numParedes; i++)
    {
        delete paredes[numParedes];
        paredes[numParedes] = 0;
    }
    for (int i = 0; i < numCocos; i++)
    {
        delete cocos[numCocos];
        cocos[numCocos] = 0;
    }
    for (int i = 0; i < numFantasmas; i++)
    {
        delete fantasmas[numFantasmas];
        fantasmas[numFantasmas] = 0;
    }
    delete pacman;
    pacman = 0;
}