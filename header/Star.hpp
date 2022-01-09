#ifndef _Star_h_
#define _Star_h_

#include "Reward.hpp"

class Star : public Reward
{

public:
    Star(int pos);
    virtual void dropReward();
    ~Star();
};

#endif