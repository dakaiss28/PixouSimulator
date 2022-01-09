#include "Position.hpp"
#include <stdio.h>
#ifndef _Pixou_h_
#define _Pixou_h_

#include <string>
using namespace std;

class Pixou
{
private:
    string _name;
    Position _position;
    int _points;
    int _speed;

public:
    Pixou(string name, int points);
    void movePixou(int dir);
    void updatePoints(int upd);
    int points() const;
    string name() const;
    Position position() const;
    ~Pixou();
};

inline int Pixou::points() const { return _points; }
inline string Pixou::name() const { return _name; }
inline Position Pixou::position() const { return _position; }

#endif