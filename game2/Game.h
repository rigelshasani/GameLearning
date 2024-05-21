#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
/*
    Class that acts as game engine.
    Wrapper class
*/

class Game
{
private:
    // Variables
    // Window
    sf::RenderWindow *window;
    sf::VideoMode videomode;
    sf::Event ev;

    // Private functions
    void initializeVariables();
    void initWindow();

public:
    // Constructor
    Game();
    // Destructor
    virtual ~Game();
    // Accessors
    const bool running() const;

    // Functions
    void pollEvents();
    void update();
    void render();
};