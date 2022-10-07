#ifndef __PARED_HPP__
#define __PARED_HPP__

#define TILEMAP_PAREDES 1

class Pared
{
    public:
        Pared(int px, int py);
        void Actualiza();
        int ObtenPosX();
        int ObtenPosY();
        void Dibuja();
        ~Pared();
    private:
        int posX;
        int posY;
};


#endif