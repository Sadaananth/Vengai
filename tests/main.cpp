#include "src/Vengai.hpp"

#include <iostream>

int main()
{
    Vengai::NetworkConfig networkConfig;
    networkConfig.mInputCount = 2;
    networkConfig.mLayerCount = 2;
    networkConfig.mOutputCount = 1;

    networkConfig.mNodeCount.emplace_back(3);
    networkConfig.mNodeCount.emplace_back(2);

    Vengai::Network network(networkConfig);

    //network.train();

    //network.test();

    return 0;
}