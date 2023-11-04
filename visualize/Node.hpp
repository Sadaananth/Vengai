#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

#include <iostream>

class Node
{
private:
    sf::RectangleShape mOutline;
    sf::RectangleShape mInput;
    sf::RectangleShape mOutput;
    sf::Text mText;
};
