#ifndef __LAYER_HPP__
#define __LAYER_HPP__

#include <iostream>
#include <vector>

using InputWeightsList = std::vector<std::vector<float>>;

class Layer
{
    uint16_t mNodeCount;
    uint16_t mInputCount;

    /**
     * @brief Input Weights list also contains biases.
     * 
     */
    InputWeightsList mInputWeightsList;

public:
    Layer(int numberOfNodes, int numberOfInputs) : mNodeCount(numberOfNodes), mInputCount(numberOfInputs) {}

    /**
     * @brief Set the Weights object. Biases are part of WeightsList
     * 
     * @param WeightsList 
     */
    void setWeights(const InputWeightsList& WeightsList);
    std::vector<float> forwardPropogate();
};


void Layer::setWeights(const InputWeightsList& WeightsList)
{
    mInputWeightsList = WeightsList;
}

std::vector<float> Layer::forwardPropogate()
{

}

#endif