#ifndef _State_h_
#define _State_h_

#include <string>
#include <stdio.h>
#include <vector>
#include "Cell.hpp"
#include "Reward.hpp"
#include "Pixou.hpp"

using namespace std;

class State
{
private:
    vector<pair<int, int>> rewardsCells;
    pair<int, int> pixouCell;

public:
    State(vector<Reward> rewards, Pixou pixou, int N);
    bool operator==(State &a);
    bool operator<(const State &a) const;
};

inline bool State::operator==(State &a)
{
    return a.pixouCell == pixouCell && std::equal(a.rewardsCells.begin(), a.rewardsCells.end(), rewardsCells.begin());
}

inline bool State::operator<(const State &a) const
{
    return a.pixouCell < pixouCell;
}

#endif