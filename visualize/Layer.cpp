#include "visualize/Layer.hpp"

Layer::Layer(uint8_t count, Node::Property property)
{
    mNodes.assign(count, Node::Property::Both);

    uint32_t index = 0;
    for(auto& node : mNodes) {
        node.setSize(sf::Vector2f(100, 100));
        node.setPosition(sf::Vector2f(0, index));
        index = index + 150;
    }
}

void Layer::draw(sf::RenderWindow& window)
{
    for(auto& node : mNodes) {
        node.draw(window);
    }
}
