#pragma once

#include "visualize/Node.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

struct Layer
{
    Layer(uint8_t count, Node::Property property, const std::string& name);

    void draw(sf::RenderWindow& window);

private:
    std::vector<Node> mNodes;
};
