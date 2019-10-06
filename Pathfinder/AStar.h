#ifndef __ASTART_H_
#define __ASTART_H_
#include "Path.h"
#include "Absis.h"
#include "Coord.h"
#include "Field.h"

class AStar{
public:
    static Path getPath(Coord start, Coord end, Field &maze);
private:
    static int heuristic(Coord start, Coord end);
};
#endif