#include "../header/Cell.hpp"

Cell::Cell(int id, int x1, int x2, int y1, int y2)
{
    id = id;
    x1 = x1;
    x2 = x2;
    y1 = y1;
    y2 = y2;
}

bool Cell::isInCell(int x, int y)
{
    return x > x1 && x <= x2 && y > y1 && y <= y2;
}