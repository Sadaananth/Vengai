#include "visualize/Application.hpp"

#include <SFML/Graphics.hpp>

Application::Application(ApplicationConfig&& config)
    : mConfig(std::move(config))
    , mWindow{sf::VideoMode(mConfig.width, mConfig.height), mConfig.name}
{
}

void Application::render()
{
    while (mWindow.isOpen()) {
        sf::Event event;
        while (mWindow.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    mWindow.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    break;
                case sf::Event::KeyPressed:
                    break;
                default:
                    break;
            }
        }

        mWindow.clear();
        mLinearRegression.draw(mWindow);
        mWindow.display();
    }
}
