#include "visualize/Layer.hpp"

Layer::Layer(uint8_t count, Node::Property property, const std::string& name)
{
    mNodes.assign(count, std::make_shared<Node>(property));
    for(auto& node : mNodes) {
        node->setText(name);
    }
}

void Layer::draw(sf::RenderWindow& window)
{
    for(auto& node : mNodes) {
        node->draw(window);
    }
}

void Layer::setSize(sf::Vector2f size)
{
    for(auto& node : mNodes) {
        node->setSize(size);
    }
}

void Layer::setPostion(sf::Vector2f postion)
{
    for(auto& node : mNodes) {
        node->setPosition(postion);
    }
}
