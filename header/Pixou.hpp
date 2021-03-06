#ifndef _Pixou_h_
#define _Pixou_h_

#include <string>
#include <SFML/Graphics.hpp>
#include "Position.hpp"
#include <stdio.h>

using namespace sf;
using namespace std;

class Pixou
{
private:
    string _name;
    Position _position;
    int _points;
    int _speed;
    RectangleShape pixouViz;

public:
    Pixou(string name, int points, float x, float y);
    void movePixou(int dir);
    void updatePoints(int upd);
    int points() const;
    int getSpeed() const;
    string name() const;
    Position position() const;
    RectangleShape visu();
    ~Pixou() = default;
};

inline int Pixou::points() const { return _points; }
inline string Pixou::name() const { return _name; }
inline Position Pixou::position() const { return _position; }
inline RectangleShape Pixou::visu() { return pixouViz; }
inline int Pixou::getSpeed() const { return _speed; }

#endif