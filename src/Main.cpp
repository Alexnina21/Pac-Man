#include "NoEntiendo.hpp"
#include "Pacman.hpp"
#include "Fantasma.hpp"
#include "Coco.hpp"
#include "Pared.hpp"
#include <stdio.h>
#include "Tablero.hpp"

#define TIEMPO_PASO 0.1f
#define MAX_FANTASMAS 8
#define MAX_COCOS 64
#define MAX_PAREDES 64

#define MUSICA 0
#define DECORADO_FONDO 0
#define DECORADO_FRENTE 1

float tiempoPaso;

Tablero *tablero = 0;

int main()
{
	NOE_Inicia();
	
	NOE_ReproduceMusica(MUSICA, 100, 100);
	
	// Crear objetos
	tablero = new Tablero;
		
	tiempoPaso = TIEMPO_PASO;
	
	while(!NOE_ObtenTeclaPulsada(NOE_TECLA_ESCAPE) && tablero->TodosCocosComidos() == false && tablero->ObtenPacman()->EstaMuerto() == false)
	{	
		NOE_Actualiza();
		
		tiempoPaso = tiempoPaso - NOE_ObtenTiempoDesdeActualizacion() / 1000.0f;
		
		if(tiempoPaso <= 0)
		{
			// Actualizar física
			tablero->CompruebaChoques();
			
			// Actualizar lógica
			tablero->Actualiza();
			
			tiempoPaso = TIEMPO_PASO;
		}		
		
		// Dibujado
		
		NOE_LimpiaPantalla(0, 0, 0);		
				
		NOE_DibujaDecorado(DECORADO_FONDO);
		
		// Limpiar tilemaps
		tablero->Dibuja();		
		
		// Dibujar tilemaps
		NOE_DibujaDecorado(DECORADO_FRENTE);
		
		NOE_MuestraPantalla();
	}
	// Eliminar objetos
	tablero->~Tablero();	

	NOE_ParaMusica();
	
	NOE_Finaliza();

    return 0;
	
}