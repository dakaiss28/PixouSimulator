#ifndef _Coin_h_
#define _Coin_h_

#include "Reward.hpp"

class Coin : public Reward
{

public:
    Coin(int pos);
    virtual void dropReward();
    ~Coin();
};

#endif