#ifndef _State_h_
#define _State_h_

#include <string>
#include <stdio.h>
#include <vector>
#include "Cell.hpp"
#include "Reward.hpp"
#include "Pixou.hpp"

#include <iostream>
using namespace std;

class State
{
private:
    vector<pair<int, int>> rewardsCells;
    pair<int, int> pixouCell;

public:
    State(vector<Reward> rewards, Pixou pixou, int windowSize, int cellSize);
    bool operator==(const State &a);
    bool operator<(const State &a) const;
    vector<pair<int, int>> getrewardsCells();
    pair<int, int> getpixouCell();
};

inline bool State::operator==(const State &a)
{
    return a.pixouCell == pixouCell && std::equal(a.rewardsCells.begin(), a.rewardsCells.end(), rewardsCells.begin());
}

inline bool State::operator<(const State &a) const
{
    return a.pixouCell > pixouCell && !std::equal(a.rewardsCells.begin(), a.rewardsCells.end(), rewardsCells.begin());
}

inline pair<int, int> State::getpixouCell()
{
    return pixouCell;
}

inline vector<pair<int, int>> State::getrewardsCells()
{
    return rewardsCells;
}

#endif