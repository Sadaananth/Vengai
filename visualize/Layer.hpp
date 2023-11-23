#pragma once

#include "visualize/Node.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#include <memory>

struct Layer
{
    Layer(uint8_t count, Node::Property property, const std::string& name);

    void draw(sf::RenderWindow& window);

    void setSize(sf::Vector2f size);
    void setPostion(sf::Vector2f postion);
private:
    std::vector<std::shared_ptr<Node>> mNodes;
    Node mTestNode;
};
