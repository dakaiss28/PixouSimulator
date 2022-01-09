#ifndef _Reward_h_
#define _Reward_h_

#include "Position.hpp"

class Reward
{
protected:
    Position _position;
    int _rewards;
    int _speed;

public:
    Reward() = default;
    Position position() const;
    int rewards() const;
    int speed() const;
    virtual void dropReward() = 0;
    bool outOfWindow();
    bool operator==(Reward &r);
    ~Reward();
};

inline Position Reward::position() const
{
    return _position;
}
inline int Reward::rewards() const { return _rewards; }
inline int Reward::speed() const { return _speed; }
inline bool Reward::outOfWindow() { return _position.y() > 100; }

inline bool Reward::operator==(Reward &r)
{
    return _position == r._position && _speed == r._speed && _rewards == r._rewards;
}
#endif