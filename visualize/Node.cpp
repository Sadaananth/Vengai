#include "visualize/Node.hpp"

#include <SFML/Graphics/Color.hpp>

Node::Node(Property property)
    : mProperty(property)
{
    mInput.setFillColor(sf::Color::Blue);
    mOutput.setFillColor(sf::Color::Green);
}

void Node::setPosition(const sf::Vector2f& position)
{
    mOutline.setPosition(position);
    mText.setPosition(position);

    const auto outlineSize = mOutline.getSize();
    mInput.setPosition(position.x, position.y + outlineSize.y / 2);
    mOutput.setPosition(position.x + outlineSize.x / 2, position.y + outlineSize.y / 2);
}

void Node::setSize(const sf::Vector2f& size)
{
    mOutline.setSize(size);

    const auto x = size.x;
    const auto y = size.y;
    mInput.setSize(sf::Vector2f(x / 2, y / 2));
    mOutput.setSize(sf::Vector2f(x / 2, y / 2));
}

void Node::draw(sf::RenderWindow& window)
{
    window.draw(mOutline);
    window.draw(mText);

    switch(mProperty) {
        case Property::InputOnly:
            window.draw(mInput);
            break;
        case Property::OutputOnly:
            window.draw(mOutput);
            break;
        case Property::Both:
            window.draw(mInput);
            window.draw(mOutput);
            break;
    }
}
