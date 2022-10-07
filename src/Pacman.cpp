#include <stdio.h>
#include "NoEntiendo.hpp"
#include "Tablero.hpp"
#include "Pacman.hpp"
#include "Coco.hpp"
#include "Fantasma.hpp"

Pacman::Pacman(int px, int py, Tablero *t, Direcciones d)
{
    posX = px;
    posY = py;
    muerto = false;
    tablero = t;
    direccion = d;
    tile = 3;
    numLetrasRecibidas = 0;
    enfadado = false;   
}
void Pacman::CompruebaChoques()
{
    chocaConParedAbajo = false;
    chocaConParedArriba = false;
    chocaConParedDerecha = false;
    chocaConParedIzquierda = false;

    if(tablero->BuscaPared(posX, posY - 1))
    {
        chocaConParedArriba = true;
    }
    if(tablero->BuscaPared(posX, posY + 1))
    {
        chocaConParedAbajo = true;
    }
    if(tablero->BuscaPared(posX - 1, posY))
    {
        chocaConParedIzquierda = true;
    }
    if(tablero->BuscaPared(posX + 1, posY))
    {
        chocaConParedDerecha = true;
    }

    Coco* coconut =  tablero->BuscaCoco(posX, posY);
    if(coconut)
    {
        coconut->IntentaComer();
    }

    if(tablero->BuscaFantasma(posX, posY))
    {
        if (enfadado == true)
        {
            tablero->BuscaFantasma(posX, posY)->Oculta();
        }
        else
        {
            muerto = true;
        } 
    }

}
void Pacman::RecibeLetra()
{
    numLetrasRecibidas = numLetrasRecibidas + 1;
}
int Pacman::ObtenNumLetrasRecibidas()
{
    return numLetrasRecibidas;
}
Direcciones Pacman::ObtenDireccion()
{
    return direccion;
}
int Pacman::ObtenPosX()
{
    return posX;
}
int Pacman::ObtenPosY()
{
    return posY;
}
void Pacman::Actualiza()
{
    if(enfadado == true)
    {
        ciclosEnfado = ciclosEnfado - 1;

        if(ciclosEnfado <= 0)
        {
            enfadado = false;
            Fantasma::Tranquilizar();
        }
        
        if (tile == 12)
        {
            switch (direccion)
            {
            case DIRECCION_ARRIBA:
                tile = 13;
                break;
            case DIRECCION_ABAJO:
                tile = 14;
                break;
            case DIRECCION_IZQUIERDA:
                tile = 15;
                break;
            case DIRECCION_DERECHA:
                tile = 16;
                break;        
            default:
                break;
            }
        }
        else
        {
            tile = 12;
        }
    }
    else
    {
        if (tile == 3)
        {
            switch (direccion)
            {
            case DIRECCION_ARRIBA:
                tile = 4;
                break;
            case DIRECCION_ABAJO:
                tile = 5;
                break;
            case DIRECCION_IZQUIERDA:
                tile = 6;
                break;
            case DIRECCION_DERECHA:
                tile = 7;
                break;        
            default:
                break;
            }
        }
        else
        {
            tile = 3;
        }
    }
    
    
    if(NOE_ObtenTeclaPulsada(NOE_TECLA_W))
    {
        direccion = DIRECCION_ARRIBA;
        
    }
    else if(NOE_ObtenTeclaPulsada(NOE_TECLA_S))
    {
        direccion = DIRECCION_ABAJO;
        
    }
    else if(NOE_ObtenTeclaPulsada(NOE_TECLA_A))
    {
        direccion = DIRECCION_IZQUIERDA;
        
    }
    else if(NOE_ObtenTeclaPulsada(NOE_TECLA_D))
    {
        direccion = DIRECCION_DERECHA;
        
    }

    switch (direccion)
        {
        case DIRECCION_ARRIBA:
            if (chocaConParedArriba == false)
            {
                posY = posY - 1;
            }
            break;
        case DIRECCION_ABAJO:
            if (chocaConParedAbajo == false)
            {
                posY = posY + 1;
            }
            break;
        case DIRECCION_IZQUIERDA:
            if (chocaConParedIzquierda == false)
            {
                posX = posX - 1;
            }
            break;
        case DIRECCION_DERECHA:
            if (chocaConParedDerecha == false)
            {
                posX = posX + 1;
            }
            break;        
        default:
            break;
        }
}
bool Pacman::EstaMuerto()
{
    return muerto;
}
bool Pacman::Enfada()
{
    enfadado = true;
    ciclosEnfado = CICLOS_ENFADO_PACMAN;
    Fantasma::Asustar();
    return enfadado; 
}
void Pacman::Dibuja()
{
    NOE_PonTile(TILEMAP_PACMAN, posX, posY, tile); 
}
Pacman::~Pacman()
{

}