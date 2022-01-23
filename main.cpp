#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <algorithm>

#include "header/Game.hpp"

using namespace std;

int main()
{
    srand(time(NULL));
    //Init game
    Game game;

    while (game.running())
    {
        //update

        game.update();

        //render

        game.render();
    }

    return 0;
}
