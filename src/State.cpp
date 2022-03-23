#include "../header/State.hpp"
#include <iostream>
#include <cmath>
using namespace std;

State::State(vector<Reward> rewards, Pixou pixou, int windowSize, int cellSize)
{
    // int N = (int)floor(windowSize / (double)cellSize);

    for (Reward r : rewards)
    {
        pair<int, int> coord(r.visu().getPosition().x / cellSize, r.visu().getPosition().y / cellSize);
        rewardsCells.push_back(coord);
    }

    pixouCell = make_pair(pixou.visu().getPosition().x / cellSize, pixou.visu().getPosition().y / cellSize);
}