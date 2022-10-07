#ifndef __TABLERO_HPP__
#define __TABLERO_HPP__

#define MAX_FANTASMAS 8
#define MAX_COCOS 64
#define MAX_PAREDES 64
#define TILES_COuNT 96

class Pared;
class Coco;
class Fantasma;
class Pacman;
enum Direcciones
{
    DIRECCION_ARRIBA,
    DIRECCION_ABAJO,
    DIRECCION_IZQUIERDA,
    DIRECCION_DERECHA
};
enum Letra
{
    LETRA_VACIA,
    LETRA_P,
    LETRA_A1,
    LETRA_C,
    LETRA_M,
    LETRA_A2,
    LETRA_N
};

class Tablero
{
    public:
        Tablero();
        void CompruebaChoques();
        void Actualiza();
        void Dibuja();
        Pacman* ObtenPacman();
        Pared* BuscaPared(int posX, int posY);
        Fantasma *BuscaFantasma(int posX, int posY);
        Pacman* BuscaPacman(int posX, int posY);
        Pacman* BuscaPacmanDireccion(int posX, int posY, int dirX, int dirY);
        Coco* BuscaCoco(int posX, int posY);
        bool TodosCocosComidos();
        ~Tablero();
    private:
        Pacman *pacman;       
        Fantasma *fantasmas[MAX_FANTASMAS];      
        int numFantasmas;        
        Coco *cocos[MAX_COCOS];        
        int numCocos;       
        int numCocosComidos;        
        Pared *paredes[MAX_PAREDES];        
        int numParedes;        
        int ancho;
        int alto;
        Direcciones direccion;
        Letra letra;
};

#endif