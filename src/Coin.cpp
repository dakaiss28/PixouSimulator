#include "../header/Coin.hpp"
#include "../header/Reward.hpp"

Coin::Coin(int x)
{
    _rewards = 5;
    _speed = 2;
    _position.set_x(x);
}

void Coin::dropReward()
{
    _position.set_y(_position.y() + _speed);
}