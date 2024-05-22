#pragma once
#include <iostream>
#include <vector>
#include <ctime>

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

    // Mouse Positions
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    // Game Logic
    int points;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int max_enemies;

    // Game Objects
    std::vector<sf::RectangleShape> enemies;
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
    void spawnEnemy();
    void updateEnemies();
    void renderEnemies();
    void pollEvents();
    void updateMousePositions();
    void update();
    void render();
};