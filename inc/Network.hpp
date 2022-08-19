#ifndef __NETWORK_HPP__
#define __NETWORK_HPP__

#include "Layer.hpp"

struct NetworkConfig
{
    uint16_t mLayerCount;
    uint16_t mInputCount;
    uint16_t mOutputCount;
    std::vector<uint16_t> mNodeCount;
};

class Network
{
    NetworkConfig mNetworkConfig;
    std::vector<Layer> mLayersList;

    void initLayers();
public:
    Network(const NetworkConfig& networkConfig);

    void train(const std::vector<float>& input);
    void test(const std::vector<float>& input);
};


Network::Network(const NetworkConfig& networkConfig)
{
    mNetworkConfig = networkConfig;

    initLayers();
}

void Network::initLayers()
{
    auto CurrNodeCountItr = mNetworkConfig.mNodeCount.begin();
    uint16_t inputCount = mNetworkConfig.mInputCount;
    for(uint16_t layerIndex = 0; layerIndex < mNetworkConfig.mLayerCount; layerIndex++)
    {
        if(CurrNodeCountItr != mNetworkConfig.mNodeCount.end())
        {
            mLayersList.emplace_back(Layer(*CurrNodeCountItr, inputCount));
            inputCount = *CurrNodeCountItr;
            CurrNodeCountItr++;
        }
    }
}

void Network::train(const std::vector<float>& input)
{

}

void Network::test(const std::vector<float>& input)
{

}

#endif