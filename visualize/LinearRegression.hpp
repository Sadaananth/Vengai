#pragma once

#include "src/Vengai.hpp"
#include "visualize/Layer.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#include <vector>

class LinearRegression
{
public:
    LinearRegression(Vengai::NetworkConfig&& config);

    void draw(sf::RenderWindow& window);
private:
    Vengai::NetworkConfig mNetworkConfig;

    Layer mInputLayer;
    std::vector<Layer> mHiddenLayer;
    Layer mOutputLayer;
};
