#pragma once

#include "visualize/LinearRegression.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#include <string>

struct ApplicationConfig
{
    std::string name;
    uint16_t width;
    uint16_t height;
};

class Application
{
public:
    Application(ApplicationConfig&& config);

    void render();

private:
    ApplicationConfig mConfig;
    sf::RenderWindow mWindow;

    std::unique_ptr<LinearRegression> mLinearRegression;
};
