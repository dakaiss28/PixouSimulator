
#include "../header/Pixou.hpp"

Pixou::Pixou(string name, int pts)
{
    _name = name;
    _points = pts;
    _position.set_x(50);
    _position.set_y(100);
    _speed = 5;
}
void Pixou::updatePoints(int points)
{
    _points += points;
}

void Pixou::movePixou(int dir)
{
    int sp = dir * _speed;
    _position.set_x(_position.x() + sp);
}