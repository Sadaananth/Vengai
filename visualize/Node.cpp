#include "visualize/Node.hpp"

#include <SFML/Graphics/Color.hpp>

namespace {
auto getInputColor(Node::Property property) -> sf::Color
{
    switch(property) {
        case Node::Property::InputOnly:
            return sf::Color::Cyan;
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
            return sf::Color::Cyan;
        case Node::Property::Both:
            return sf::Color::Magenta;
    }

    throw std::runtime_error("Unknown property received");
}
} // namespace

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

    // const auto text = mText.getString().toAnsiString();
    // auto pos = mOutline.getPosition();
    // std::cout << text << " outline " << pos.x << "," << pos.y << std::endl;

    // pos = mInput.getPosition();
    // std::cout << text << " input " << pos.x << "," << pos.y << std::endl;

    // pos = mOutput.getPosition();
    // std::cout << text << " output " << pos.x << "," << pos.y << std::endl;
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
        window.draw(mText);
        window.draw(mInput);
        window.draw(mOutput);
    } catch(...) {
        std::cerr << "Exception occured" << std::endl;
    }
}
