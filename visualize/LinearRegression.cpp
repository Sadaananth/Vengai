#include "visualize/LinearRegression.hpp"

LinearRegression::LinearRegression()
    : mInputLayer(4, Node::Property::Both)
    , mOutputLayer(0, Node::Property::Both)
{
}

void LinearRegression::draw(sf::RenderWindow& window)
{
    mInputLayer.draw(window);
}
