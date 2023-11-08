#include "src/Vengai.hpp"

#include "visualize/LinearRegression.hpp"

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Vengai-Gui");
    LinearRegression linearRegression;

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
        linearRegression.draw(window);
        window.display();
    }
    return 0;
}
