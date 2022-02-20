#include "../header/State.hpp"

State::State(vector<Reward> rewards, Pixou pixou)
{

    vector<pair<int, int>> rewardsCells;
    transform(rewards.begin(), rewards.end(), back_inserter(rewardsCells), [](Reward r) -> pair<int, int>
              { return make_pair(r.visu().getOrigin().x / 100, r.visu().getOrigin().y / 100); });

    pair<int, int> pixouCell = make_pair(pixou.visu().getOrigin().x / 100, pixou.visu().getOrigin().y / 100);
}