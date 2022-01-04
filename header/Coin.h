#include "Reward.h"

class Coin : public Reward
{
private:
public:
    Coin(int rw = 5, int sp = 2);
    virtual void dropReward();
    ~Coin();
};
