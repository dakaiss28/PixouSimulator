#include "../header/Reward.hpp"

Reward::Reward(int x)
{
    _rewards = 5;
    _speed = 2;
    _position.set_x(x);

    _visu.setPosition(Vector2f(static_cast<float>(x), 0.f));

    _visu.setSize(Vector2f(100.f, 100.f));
    _visu.setFillColor(Color::Cyan);
}

void Reward::dropReward()
{
    _position.set_y(_position.y() + _speed);
    _visu.move(Vector2f(0.f, static_cast<float>(_speed)));
}