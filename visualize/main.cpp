#include "src/Vengai.hpp"

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 480), "Vengai-Gui");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    break;
                case sf::Event::KeyPressed:
                    break;
                default:
                    break;
            }
        }

        window.clear();
        window.display();
    }
    return 0;
}
