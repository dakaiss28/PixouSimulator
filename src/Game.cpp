#include "../header/Game.hpp"

void Game::initVar()
{
    window = nullptr;
    // Game logic
    rewardsTimerMax = 10.f;
    rewardsTimer = rewardsTimerMax;
    maxRewards = 5;
}

void Game::initWindow()
{
    videoMode = videoMode.getDesktopMode();
    window = new RenderWindow(videoMode, "Pixou Simulator", Style::Titlebar | Style::Resize | Style::Close);

    window->setFramerateLimit(60);
    window->setPosition(Vector2i(500, 500));
    pixou = new Pixou("myPixou", 0, window->getSize().x / 2, window->getSize().y - 150);
}

void Game::initRewards()
{
}

bool Game::intersectRectangles(RectangleShape a, RectangleShape b)
{
    return a.getPosition().x <= b.getPosition().x + b.getSize().x &&
           a.getPosition().x + a.getSize().x >= b.getPosition().x &&
           a.getPosition().y <= b.getPosition().y + b.getSize().y &&
           a.getPosition().y + a.getSize().y >= b.getPosition().y;
}

Game::Game()
{
    initVar();
    initWindow();
    initRewards();
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
    updateRewards();
    updatePixou();
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

void Game::updatePixou()
{
    int mvt = rand() % 3 - 1;
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
}

void Game::render()
{
    window->clear();

    //Draw game
    renderRewards();
    renderPixou();
    cout << pixou->points() << endl;
    window->display();
}