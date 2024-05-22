#include "Game.h"

void Game::initializeVariables()
{
    this->window = nullptr;

    // Game Logic
    this->points = 0;
    this->enemySpawnTimerMax = 1000.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->max_enemies = 5;
}

void Game::initWindow()
{
    this->videomode.height = 600;
    this->videomode.width = 800;
    this->window = new sf::RenderWindow(this->videomode, "Game 4", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);
}

void Game::initEnemies()
{
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.f);
}

Game::Game()
{
    this->initializeVariables();
    this->initWindow();
    this->initEnemies();
}

/*
    Destructor, remember to DELETE resources at the end of scope!!!
*/
Game::~Game()
{
    delete this->window;
}

const bool Game::running() const
{
    return this->window->isOpen();
}

void Game::pollEvents()
{
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
        {
            this->window->close();
            break;
        }
        case sf::Event::KeyPressed:
        {
            if (ev.key.code = sf::Keyboard::Escape)
            {
                this->window->close();
                break;
            }
        }
        }
    }
}

// Functions
/*
    Updates mouse position as a variable
*/
void Game::updateMousePositions()
{
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

/*
    Spawns enemies and sets their colors and positions.
    Random position, green color. Adds enemy to vector.
*/
void Game::spawnEnemy()
{
    this->enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))
    );  

    this->enemy.setFillColor(sf::Color::Green);
    this->enemies.push_back(this->enemy);
}

/*
    Updates enemy spawn timer and spawns enemies while there are less enemies than max. Moves enemies downwards.
    Removes the enemies at the edge of the screen. TODO!!
*/
void Game::updateEnemies()
{
    // Updating the timer for enemy spawning
    if (this->enemies.size() < this->max_enemies)
    {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
        {
            // Spawn the enemy and reset timer
            this -> spawnEnemy();
            this->enemySpawnTimer = 0.f;
        }
        else
            this->enemySpawnTimer += 1.f;
    }

    // Move the enemies.
    for (auto &e : this->enemies)
    {
        e.move(0.9f, 1.9f);
    }
}

void Game::renderEnemies()
{
    // Draw the enemies.
    for (auto &e : this->enemies)
    {
        this->window->draw(e);
    }
}

/*
    Gets updates
*/
void Game::update()
{
    this->pollEvents();
    this->updateMousePositions();
    this->updateEnemies();
}

/*
    @return void

    Renders the game objects
    -clear old frame
    -render objects
    -display frame in window
*/
void Game::render()
{

    this->window->clear();
    //---------------------
    // Draw game objects in the middle
    this->renderEnemies();
    //---------------------
    this->window->display();
}
