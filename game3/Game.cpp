#include "Game.h"

void Game::initializeVariables()
{
    this->window = nullptr;
}

void Game::initWindow()
{
    this->videomode.height = 600;
    this->videomode.width = 800;
    this->window = new sf::RenderWindow(this->videomode, "Game 2", sf::Style::Titlebar | sf::Style::Close);

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
    Gets updates
*/
void Game::update()
{
    this->pollEvents();
    // Update mouse position
    // Relative to the screen
    //std::cout << "Mouse position: " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << '\n';
    // Relative to the window
    std::cout << "Mouse position: " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << '\n';
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
    this->window->draw(this->enemy);
    //---------------------
    this->window->display();
}
