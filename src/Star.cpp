#include "../header/Star.hpp"
#include "../header/Reward.hpp"

Star::Star(int x)
{
    _rewards = 10;
    _speed = 4;
    _position.set_x(x);
}

void Star::dropReward()
{
    _position.set_y(_position.y() + _speed);
}