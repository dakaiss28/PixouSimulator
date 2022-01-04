#include "Reward.h"

class Star : public Reward
{
private:
public:
    Star(int rw = 10, int sp = 5);
    virtual void dropReward();
    ~Star();
};