#include "visualize/LinearRegression.hpp"

#include "src/Logger.hpp"

using namespace Sada;

LinearRegression::LinearRegression(Vengai::NetworkConfig&& config)
    : mNetworkConfig(std::move(config))
    , mInputLayer(mNetworkConfig.mInputCount, Node::Property::InputOnly, "Input")
    , mOutputLayer(mNetworkConfig.mOutputCount, Node::Property::OutputOnly, "Output")
{
    for(auto nodeCount : mNetworkConfig.mNodeCount) {
        mHiddenLayer.emplace_back(nodeCount, Node::Property::Both, "Hidden");
    }
    setLayerPosition();
}

void LinearRegression::draw(sf::RenderWindow& window)
{
    mInputLayer.draw(window);
    mOutputLayer.draw(window);

    for(auto& layer : mHiddenLayer) {
        layer.draw(window);
    }
}

void LinearRegression::setLayerPosition()
{
    const uint32_t applicationWidth = 1080;
    const uint32_t applicationHeight = 720;

    const uint32_t NodeSpace = 20;

    uint32_t layerCount = mHiddenLayer.size() + 2;
    uint32_t NodeSpaceCount = layerCount + 1;
    uint32_t nodeWidth = (applicationWidth - NodeSpaceCount * NodeSpace) / layerCount;

    uint32_t maxNodeinLayer = mNetworkConfig.mInputCount > mNetworkConfig.mOutputCount ? mNetworkConfig.mInputCount : mNetworkConfig.mOutputCount;
    for(auto nodeCount : mNetworkConfig.mNodeCount) {
        if(maxNodeinLayer < nodeCount) {
            maxNodeinLayer = nodeCount;
        }
    }

    uint32_t VerticalNodeSpaceCount = maxNodeinLayer + 1;
    uint32_t nodeHeight = (applicationHeight - VerticalNodeSpaceCount * NodeSpace) / maxNodeinLayer;

    uint32_t widthOffset = 0;
    auto setSizePosition = [&widthOffset, NodeSpace, nodeHeight, nodeWidth](Layer& layer) {
        layer.setSize(sf::Vector2f(nodeWidth, nodeHeight));
        layer.setPostion(sf::Vector2f(widthOffset + NodeSpace, NodeSpace));
        widthOffset += NodeSpace + nodeWidth;
    };
    setSizePosition(mInputLayer);
    for(auto& layer : mHiddenLayer) {
        setSizePosition(layer);
    }
    setSizePosition(mOutputLayer);
}
