#ifndef __FANTASMA_HPP__
#define __FANTASMA_HPP__

#define TILEMAP_FANTASMA 2

enum DireccionFamtasma
{
    DIRECCION_FANTASMA_IZQUIERDA,
    DIRECCION_FANTASMA_DERECHA,
    DIRECCION_FANTASMA_ARRIBA,
    DIRECCION_FANTASMA_ABAJO
};

class Pared;
class Tablero;
class Fantasma
{
    public:
        Fantasma(int px, int py, Tablero *t);
        void CompruebaChoques(Pared* paredes[], int numParedes);
        void Actualiza();
        int ObtenPosX();
        int ObtenPosY();
        static void Asustar();
        static void Tranquilizar();
        void Oculta();
        void Dibuja();
        int BuscaPacman();
        ~Fantasma();
    private:
        DireccionFamtasma direccion;
        int posX;
        int posY;
        bool chocaConParedArriba;
        bool chocaConParedAbajo;
        bool chocaConParedIzquierda;
        bool chocaConParedDerecha;
        static bool asustados;
        bool oculto;
        bool enPersecucion;
        Tablero * tablero;
};



#endif