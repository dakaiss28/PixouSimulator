#include "../header/Game.hpp"

void Game::initVar()
{
    window = nullptr;
    windowSize = 100;
    text.setFont(font);
    text.setPosition(Vector2f(50, 50));

    // Game logic
    rewardsTimerMax = 10.f;
    rewardsTimer = rewardsTimerMax;
    maxRewards = 5;
    nbStates = 0;
    currentStateId = 0;
    epsilon = 0.8;
}

void Game::initWindow()
{
    videoMode = videoMode.getDesktopMode();
    window = new RenderWindow(videoMode, "Pixou Simulator", Style::Titlebar | Style::Resize | Style::Close);

    window->setFramerateLimit(60);
    window->setPosition(Vector2i(500, 500));
    window->setSize(Vector2u(windowSize, windowSize));
    pixou = new Pixou("myPixou", 0, window->getSize().x / 2, window->getSize().y - 150);
}

bool Game::intersectRectangles(RectangleShape a, RectangleShape b)
{
    return a.getPosition().x <= b.getPosition().x + b.getSize().x &&
           a.getPosition().x + a.getSize().x >= b.getPosition().x &&
           a.getPosition().y <= b.getPosition().y + b.getSize().y &&
           a.getPosition().y + a.getSize().y >= b.getPosition().y;
}

void Game::updateQtable(float alpha, float gamma, float epsilon)
{

    int action;
    int currentScore = pixou->points();
    // current state stocké dans currentStateId
    int state1Id = currentStateId;

    // exploratory : we perform a random action
    if (epsilon > 0.6)
    {
        action = randomAction();
    }

    // action based on Q-table
    else
    {
        // Get action index with max value in qtable at table[currentStateId]
        int action = distance(table[state1Id].begin(), max_element(table[state1Id].begin(), table[state1Id].end()));
    }

    // do the action -> updatePixou
    updatePixou(action);

    updateRewards();

    // reward =  difference scorePixou between current state and new state
    int reward = pixou->points() - currentScore;

    //  get new state and updatecurrentState
    int state2Id = updateStates();

    //  update Q-table with bellman-equation ( with currentState and newState)

    table[state1Id][action] += alpha * (reward + (gamma * *max_element(table[state2Id].begin(), table[state2Id].end())) - table[state1Id][action]);

    // reduce epsilon
    epsilon -= 0.1;
}
int Game::randomAction()
{
    return rand() % 3 - 1;
}

Game::Game()
{
    initVar();
    initWindow();
    // initCells();
    // initRewards();
}

Game::~Game()
{
    delete window;
}

bool Game::running() const
{
    return window->isOpen();
}

void Game::pollEvents()
{
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case Event::Closed:
            window->close();
            break;
        }
    }
}
void Game::update()
{
    pollEvents();
    // updateRewards();
    // updateStates();
    updateQtable(0.2, 0.9, 0.8);
    // updatePixou(randomAction());
}

void Game::updateRewards()
{
    if (rewards.size() < maxRewards)
    {
        if (rewardsTimer >= rewardsTimerMax)
        {
            rewardsTimer = 0.f;
            spawnRewards();
        }
        else
            rewardsTimer += 1.f;
    }

    for (int i = 0; i < rewards.size(); i++)
    {
        bool deleted = false;

        rewards[i].dropReward();

        // Check if pos reward = pos pixou

        if (intersectRectangles(rewards[i].visu(), pixou->visu()))
        {
            deleted = true;
            pixou->updatePoints(rewards[i].rewards());
        }

        // check if reward out of screen

        if (rewards[i].visu().getPosition().y > window->getSize().y)
        {
            deleted = true;
            pixou->updatePoints(-rewards[i].rewards());
        }

        if (deleted)
        {
            rewards.erase(rewards.begin() + i);
        }
    }
}

void Game::spawnRewards()
{

    int pos = rand() % static_cast<int>(window->getSize().x);
    rewards.push_back(Reward(pos));
}

/**
 * @brief analyse the window and crete a state. If configuration already exists in qtable, just get id of the state
 * else : add state in qtable and then update id of current state and nb of states.
 *
 */
int Game::updateStates()
{

    State currentState(rewards, *pixou);

    if (states.find(currentState) == states.end())
    {
        states.insert(pair<State, int>(currentState, nbStates));
        nbStates++;
        currentStateId = nbStates - 1;
        table.insert(pair<int, array<double, 3>>(currentStateId, {0.0, 0.0, 0.0}));
    }
    else
    {
        currentStateId = states[currentState];
    }
    return currentStateId;
}

// TO DO rearanger mouvements de pixou pour qu'il ne soit pas en dehors de la fenetre !!!!!!!!!!
void Game::updatePixou(int mvt)
{
    pixou->movePixou(mvt);
    float y = pixou->visu().getPosition().y;
    if (pixou->visu().getPosition().x > window->getPosition().x)
    {
        pixou->visu().setPosition(window->getPosition().x, y);
    }
    if (pixou->visu().getPosition().x < 0)
    {
        pixou->visu().setPosition(0, y);
    }
}

void Game::renderRewards()
{
    for (auto &r : rewards)
    {
        window->draw(r.visu());
    }
}

void Game::renderPixou()
{
    window->draw(pixou->visu());
    text.setString(to_string(pixou->points()));
    window->draw(text);
}

void Game::render()
{
    window->clear();

    // Draw game
    renderRewards();
    renderPixou();
    cout << pixou->points() << endl;
    cout << pixou->visu().getPosition().x << "  " << pixou->visu().getPosition().y << endl;
    window->display();
}