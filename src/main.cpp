#include "Network.hpp"

#include <iostream>

int main()
{
    NetworkConfig networkConfig;
    networkConfig.mInputCount = 2;
    networkConfig.mLayerCount = 2;
    networkConfig.mOutputCount = 1;

    networkConfig.mNodeCount.emplace_back(3);
    networkConfig.mNodeCount.emplace_back(2);

    Network network(networkConfig);

    network.train();

    network.test();

    return 0;
}