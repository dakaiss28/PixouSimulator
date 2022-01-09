#include "../header/Position.hpp"

Position::Position()
{
    _x = 0;
    _y = 0;
}
Position::Position(int x, int y)
{
    _x = x;
    _y = y;
}

bool Position::operator==(const Position &p)
{
    return _x == p.x() && _y == p.y();
}
