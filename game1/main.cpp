#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

int main()
{
    // Window stuff
    sf::RenderWindow window(sf::VideoMode(800, 600), "My first game", sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev;

    // Game loop
    while (window.isOpen())
    {
        while (window.pollEvent(ev))
        {
            switch (ev.type)
            {
            case sf::Event::Closed:
            {
                window.close();
                break;
            }
            case sf::Event::KeyPressed:
            {
                if (ev.key.code = sf::Keyboard::Escape)
                {
                    window.close();
                    break;
                }
            }
            }
        }
        window.clear(sf::Color::Blue); // clear old frame
        // draw game

        window.display(); // tell app that app is done drawing
    }

    return 0;
}
