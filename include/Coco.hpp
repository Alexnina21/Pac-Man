#ifndef __COCO_HPP__
#define __COCO_HPP__

#define TILEMAP_COCOS 3

class Tablero;
class Coco
{
    public:
        Coco(int px, int py, Tablero* t);
        void Actualiza();
        int ObtenPosX();
        int ObtenPosY();
        bool EstaComido();
        virtual void IntentaComer();
        virtual void Dibuja();
        virtual ~Coco();
    protected:
        int posX;
        int posY;
        bool comido;
        Tablero* tablero;
};


#endif