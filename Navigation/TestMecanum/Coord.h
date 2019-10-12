#ifndef _COORD_H
#define _COORD_H

class Coord{
    public:
        Coord();
        Coord(int x, int y);
        void setX(int x);
        int getX()const;

        void setY(int y);
        int getY()const;
        bool operator==(const Coord& c);

        void setCoord(Coord coord);
    private:
        int x = 0, y = 0;
};

#endif
