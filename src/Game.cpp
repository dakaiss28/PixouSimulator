#include "../header/Game.hpp"

void Game::initVar()
{
    window = nullptr;
    // Game logic
    rewardsTimerMax = 10.f;
    rewardsTimer = rewardsTimerMax;
    maxRewards = 5;
    nbStates = 0;
    vector<float> initVector(3, 0);
    qTable.push_back(initVector);
}

void Game::initWindow()
{
    videoMode = videoMode.getDesktopMode();
    window = new RenderWindow(videoMode, "Pixou Simulator", Style::Titlebar | Style::Resize | Style::Close);

    window->setFramerateLimit(60);
    window->setPosition(Vector2i(500, 500));
    window->setSize(Vector2u(100, 100));
    pixou = new Pixou("myPixou", 0, window->getSize().x / 2, window->getSize().y - 150);
}

bool Game::intersectRectangles(RectangleShape a, RectangleShape b)
{
    return a.getPosition().x <= b.getPosition().x + b.getSize().x &&
           a.getPosition().x + a.getSize().x >= b.getPosition().x &&
           a.getPosition().y <= b.getPosition().y + b.getSize().y &&
           a.getPosition().y + a.getSize().y >= b.getPosition().y;
}

void Game::initCells()
{
    int absc = window->getSize().x;
    int ord = window->getSize().y;

    int nbCells = 1;
    for (int i = 0; i < absc - 10; i += 10)
    {
        for (int j = 0; j < ord - 10; j += 10)
        {
            Cell currentCell(nbCells, i, i + 10, j, j + 10);
            nbCells++;
            cells.push_back(currentCell);
        }
    }
}

// TO DO : determiner dans quel state on est suivant la composition de la grille
// En suivant une methode greedy epsilon commencer par une recherche random puis actions choisies
// Calculer avec methode de Bellman le reward pour chaque action à la ligne de l'action courante
// on selectionne l'action avec le plus haut reward puis on update Pixou
// Boucler jusqu'à ?? ( mettre un max de points à atteindre ?? )
void Game::updateQtable(float alpha, float gamma)
{
    State currentState = states[nbStates];
}
int Game::randomAction()
{
    return rand() % 3 - 1;
}

int Game::specificAction()
{
}

Game::Game()
{
    initVar();
    initWindow();
    initCells();
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
    updateStates();
    //updatePixou();
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

void Game::updateStates()
{
    vector<int> rewardsCells;
    int pixouCell;
    for (auto rw : rewards)
    {
        for (auto cell : cells)
        {
            if (cell.isInCell(rw.visu().getOrigin().x, rw.visu().getOrigin().y))
                rewardsCells.push_back(cell.cellId());
            if (cell.isInCell(pixou->visu().getOrigin().x, pixou->visu().getOrigin().y))
                pixouCell = cell.cellId();
        }
    }

    State currentState(rewardsCells, pixouCell);
    states.insert(pair<int, State>(nbStates, currentState));
    nbStates++;
}
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