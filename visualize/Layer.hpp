#pragma once

#include "visualize/Node.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

struct Layer
{
    Layer(uint8_t count, Node::Property property, const std::string& name);

    void draw(sf::RenderWindow& window);

    void setSize(sf::Vector2f size);
    void setPostion(sf::Vector2f postion);
private:
    std::vector<Node> mNodes;
};
