#pragma once
#include <iostream>

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

    // Game Objects
    sf::RectangleShape enemy;

    // Private functions
    void initializeVariables();
    void initWindow();
    void initEnemies();

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