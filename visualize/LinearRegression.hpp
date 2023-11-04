#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include <vector>

struct Layer
{

};

class LinearRegression
{
public:
    void draw(sf::RenderWindow& window);
private:
    Layer mInputLayer;
    std::vector<Layer> mHiddenLayer;
    Layer mOutputLayer;
};
