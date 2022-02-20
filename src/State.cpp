#include "../header/State.hpp"

State::State(vector<Reward> rewards, Pixou pixou, int N)
{

    vector<pair<int, int>> rewardsCells;
    transform(rewards.begin(), rewards.end(), back_inserter(rewardsCells), [N](Reward r) -> pair<int, int>
              { return make_pair(r.visu().getOrigin().x / N, r.visu().getOrigin().y / N); });

    pair<int, int> pixouCell = make_pair(pixou.visu().getOrigin().x / N, pixou.visu().getOrigin().y / N);
}