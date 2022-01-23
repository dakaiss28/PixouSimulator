#ifndef _Reward_h_
#define _Reward_h_

#include "Position.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;

class Reward
{
protected:
    Position _position;
    int _rewards;
    int _speed;
    RectangleShape _visu;

public:
    Reward(int x);
    Position position() const;
    int rewards() const;
    int speed() const;
    RectangleShape visu();
    void dropReward();
    bool outOfWindow();
    bool operator==(Reward &r);
    ~Reward(){};
};

inline Position Reward::position() const
{
    return _position;
}
inline int Reward::rewards() const { return _rewards; }
inline int Reward::speed() const { return _speed; }

inline RectangleShape Reward::visu() { return _visu; }
inline bool Reward::outOfWindow() { return _position.y() > 100; }

inline bool Reward::operator==(Reward &r)
{
    return _position == r._position && _speed == r._speed && _rewards == r._rewards;
}

#endif