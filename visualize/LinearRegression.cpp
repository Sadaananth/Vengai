#include "visualize/LinearRegression.hpp"

LinearRegression::LinearRegression(Vengai::NetworkConfig&& config)
    : mNetworkConfig(std::move(config))
    , mInputLayer(mNetworkConfig.mInputCount, Node::Property::InputOnly, "Input")
    , mOutputLayer(mNetworkConfig.mOutputCount, Node::Property::OutputOnly, "Output")
{
    for(auto nodeCount : mNetworkConfig.mNodeCount) {
        mHiddenLayer.emplace_back(nodeCount, Node::Property::Both, "Hidden");
    }
}

void LinearRegression::draw(sf::RenderWindow& window)
{
    mInputLayer.draw(window);
    mOutputLayer.draw(window);

    for(auto& layer : mHiddenLayer) {
        layer.draw(window);
    }
}
