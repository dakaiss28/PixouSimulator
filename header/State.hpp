#ifndef _State_h_
#define _State_h_

#include <string>
#include <stdio.h>
#include <vector>
#include "Cell.hpp"

using namespace std;

class State
{
private:
    vector<int> rewardsCells;
    int pixouCell;

public:
    State(vector<int> rewards, int pixou);
};

#endif