#include "../header/State.hpp"
#include <iostream>
using namespace std;

State::State(vector<Reward> rewards, Pixou pixou, int N)
{

    for (Reward r : rewards)
    {
        pair<int, int> coord(r.visu().getPosition().x / N, r.visu().getPosition().y / N);
        rewardsCells.push_back(coord);
    }

    pixouCell = make_pair(pixou.visu().getPosition().x / N, pixou.visu().getPosition().y / N);
}