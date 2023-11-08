#pragma once

#include "visualize/Layer.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#include <vector>

class LinearRegression
{
public:
    LinearRegression();

    void draw(sf::RenderWindow& window);
private:
    Layer mInputLayer;
    std::vector<Layer> mHiddenLayer;
    Layer mOutputLayer;
};
