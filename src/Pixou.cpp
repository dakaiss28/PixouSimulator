
#include "../header/Pixou.hpp"

Pixou::Pixou(string name, int pts, float x, float y)
{
    _name = name;
    _points = pts;
    _position.set_x(50);
    _position.set_y(100);
    _speed = 5;
    pixouViz.setPosition(Vector2f(x, y));

    pixouViz.setSize(Vector2f(150.f, 150.f));
    pixouViz.setFillColor(Color::Red);
}
void Pixou::updatePoints(int points)
{
    _points += points;
}

void Pixou::movePixou(int dir)
{
    int sp = dir * _speed;
    _position.set_x(_position.x() + sp);
    pixouViz.move(Vector2f(static_cast<float>(sp), 0.f));
}