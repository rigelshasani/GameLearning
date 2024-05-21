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
}

Game::Game()
{
    this->initializeVariables();
    this->initWindow();
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
    pollEvents();
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

    this->window->clear(sf::Color(255, 0, 0, 255));
    // Draw game objects
    this->window->display();
}
