#include "visualize/Node.hpp"

#include <SFML/Graphics/Color.hpp>

namespace {
auto getInputColor(Node::Property property) -> sf::Color
{
    switch(property) {
        case Node::Property::InputOnly:
            return sf::Color::Black;
        case Node::Property::OutputOnly:
            return sf::Color::Green;
        case Node::Property::Both:
            return sf::Color::Yellow;
    }

    throw std::runtime_error("Unknown property received");
}

auto getOutputColor(Node::Property property) -> sf::Color
{
    switch(property) {
        case Node::Property::InputOnly:
            return sf::Color::Green;
        case Node::Property::OutputOnly:
            return sf::Color::Black;
        case Node::Property::Both:
            return sf::Color::Magenta;
    }

    throw std::runtime_error("Unknown property received");
}
}

Node::Node(Property property)
    : mProperty(property)
{
    mInput.setFillColor(getInputColor(mProperty));
    mOutput.setFillColor(getOutputColor(mProperty));

    if(!mTextFont.loadFromFile("resources/Test.ttf")) {
        throw std::runtime_error("Failed to load font");
    }
    mText.setFont(mTextFont);
    mText.setCharacterSize(50);
    mText.setFillColor(sf::Color::Green);
}

void Node::setText(const std::string& text)
{
    mText.setString(text);
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
    try {
        window.draw(mOutline);
        // window.draw(mText);

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
    } catch(...) {
        std::cerr << "Exception occured" << std::endl;
    }
}
