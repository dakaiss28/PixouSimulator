#include "../header/Position.h"

Position::Position(int x, int y)
{
    _x = x;
    _y = y;
}

bool operator==(Position p1, Position p2)
{
    return p1.x() == p2.x() && p1.y() == p2.y();
}
