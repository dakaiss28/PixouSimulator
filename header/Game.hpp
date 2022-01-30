#ifndef _Game_h
#define _Game_h

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include "Reward.hpp"
#include "Pixou.hpp"
#include "Cell.hpp"
#include "State.hpp"

using namespace std;

using namespace sf;

class Game
{
private:
    //Variables
    RenderWindow *window;
    Event event;
    VideoMode videoMode;

    // Game logic
    float rewardsTimer;
    float rewardsTimerMax;
    int maxRewards;

    //Qlearning Implementation
    vector<Cell> cells;
    map<int, State> states;
    int nbStates;

    vector<vector<float>> qTable;

    // Text

    Text text;

    //sf::Font font;

    Pixou *pixou;
    vector<Reward> rewards;
    //set<State> states;

    //Functions

    void initVar();
    void initWindow();
    void initRewards();

    int specificAction();
    int randomAction();
    void updateQtable(float alpha, float gamm);

    void initCells();
    void initText();
    bool intersectRectangles(RectangleShape a, RectangleShape b);

public:
    Game();
    virtual ~Game();

    bool running() const;

    void update();
    void updateRewards();
    void spawnRewards();
    void updateStates();
    void updatePixou(int mvt);
    void pollEvents();
    void renderRewards();
    void renderPixou();
    void render();
};

#endif