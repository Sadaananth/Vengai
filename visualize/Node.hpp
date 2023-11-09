#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <iostream>

class Node
{
public:
    enum class Property : uint8_t
    {
        InputOnly,
        OutputOnly,
        Both
    };

    Node(Property property = Property::Both);

    void setText(const std::string& text);
    void setPosition(const sf::Vector2f& position);
    void setSize(const sf::Vector2f& size);

    void draw(sf::RenderWindow& window);
private:

    void setInput();
    void setOutput();
    void setText();

    /**
     * @brief Node structure will be like the following
     * Whole content will be mOutline
     * ---------------------------------------
     * |                mText                 |
     * |--------------------------------------|
     * |     mInput       |      mOutput      |
     * ----------------------------------------
     */
    sf::RectangleShape mOutline;
    sf::RectangleShape mInput;
    sf::RectangleShape mOutput;
    sf::Text mText;
    sf::Font mTextFont;

    Property mProperty;
};
