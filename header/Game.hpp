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
    // Variables
    RenderWindow *window;
    Event event;
    VideoMode videoMode;
    int windowSize;

    // Game logic
    float rewardsTimer;
    float rewardsTimerMax;
    int maxRewards;

    // Qlearning Implementation

    map<State, int> states;
    int nbStates;
    int currentStateId;
    double epsilon;
    map<int, array<double, 3>> table;

    // Text

    Text text;

    Font font;

    Pixou *pixou;
    vector<Reward> rewards;

    // Functions

    void initVar();
    void initWindow();
    // void initRewards();

    int specificAction();
    int randomAction();
    void updateQtable(float alpha, float gamma, float epsilon);

    // void initCells();
    void initText();
    bool intersectRectangles(RectangleShape a, RectangleShape b);

public:
    Game();
    virtual ~Game();

    bool running() const;

    void update();
    void updateRewards();
    void spawnRewards();
    int updateStates();
    void updatePixou(int mvt);
    void pollEvents();
    void renderRewards();
    void renderPixou();
    void render();
};

#endif