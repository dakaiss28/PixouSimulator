#ifndef _Game_h
#define _Game_h

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>
#include "Reward.hpp"
#include "Pixou.hpp"

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

    // Text

    Text text;

    //sf::Font font;

    Pixou *pixou;
    vector<Reward> rewards;

    //Functions

    void initVar();
    void initWindow();
    void initRewards();
    void initText();
    bool intersectRectangles(RectangleShape a, RectangleShape b);

public:
    Game();
    virtual ~Game();

    bool running() const;

    void update();
    void updateRewards();
    void spawnRewards();
    void updatePixou();
    void pollEvents();
    void renderRewards();
    void renderPixou();
    void render();
};

#endif