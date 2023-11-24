#include "visualize/Layer.hpp"

#include "src/Logger.hpp"

using namespace Sada;

Layer::Layer(uint8_t count, Node::Property property, const std::string& name)
    : mName(name)
{
    for(auto index = 0; index < count; index++) {
        auto node = std::make_shared<Node>(property);
        node->setText(mName + std::to_string(index));
        mNodes.emplace_back(node);
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

void Layer::setPostion(sf::Vector2f position)
{
    auto nodePosition = position;
    for(auto& node : mNodes) {
        node->setPosition(nodePosition);
        const auto nodeSize = node->getSize();
        nodePosition.y += nodeSize.y + 20;
    }
}
