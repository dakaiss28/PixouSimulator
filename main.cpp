#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <algorithm>

#include "header/Coin.hpp"
#include "header/Star.hpp"
#include "header/Pixou.hpp"
#include "header/Position.hpp"

using namespace std;

int main(int argc, char **argv)
{
    srand(time(NULL));

    int N = 100;
    vector<Reward *> rewards;
    int nb_rewards = 25;

    for (int i = 0; i < nb_rewards; i++)
    {
        int pos = rand() % 100 + 1;

        if (i < 20)
        {
            Coin *c = new Coin(pos);
            rewards.push_back((Reward *)c);
        }
        else
        {
            Star *s = new Star(pos);
            rewards.push_back(s);
        }
    }

    Pixou *salim = new Pixou("Salim", 0);

    int i = 0;
    vector<Reward *> inWindow;
    while (true)
    {
        if (i < 25)
        {
            inWindow.push_back(rewards[i]);
        }

        int rand_moves = rand() % 3 + (-1);
        salim->movePixou(rand_moves);
        cout << "Position of Pixou  x : " << salim->position().x() << endl;

        for (auto rw : inWindow)
        {
            rw->dropReward();
            int rw_points = rw->rewards();

            cout << "Position of Reward"
                 << " x : " << rw->position().x() << " y : " << rw->position().y() << endl;

            if (rw->outOfWindow())
            {
                inWindow.erase(remove(inWindow.begin(), inWindow.end(), rw), inWindow.end());

                salim->updatePoints(-rw_points);
            }

            if (rw->position() == salim->position())
            {
                salim->updatePoints(rw_points);
                inWindow.erase(remove(inWindow.begin(), inWindow.end(), rw), inWindow.end());
            }
        }

        cout << "Pixou : " << salim->name() << " nb Points : " << salim->points() << endl;

        i++;
        //sleep(2);

        if (inWindow.empty())
        {
            cout << "GAME OVER "
                 << " Final Score " << salim->points() << endl;
            break;
        }
    }

    return 0;
}