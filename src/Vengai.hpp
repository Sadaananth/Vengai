#pragma once

#include <vector>
#include <cstdint>

namespace Vengai
{

using LayerWeightsListType = std::vector<std::vector<float>>;
using LayerInputType = std::vector<float>;
using LayerOutputType = std::vector<float>;
using LayerDeltaType = std::vector<float>;

enum class LayerType : uint16_t
{
    HiddenLayer = 0,
    OutputLayer
};

class Layer
{
    LayerType mLayerType;
    uint16_t mNodeCount;

    /**
     * @brief Input Weights list also contains biases.
     * 
     */
    LayerWeightsListType mLayerWeightsList;
    LayerWeightsListType mWeightsGradientList;
    LayerInputType mLayerInputList;
    LayerOutputType mLayerOutputList;
    LayerDeltaType mLayerDeltaList;

public:
    Layer(LayerType layerType, uint16_t LayerNumber, uint16_t numberOfNodes, uint16_t numberOfInputs);

    /**
     * @brief Set the Weights object. Biases are part of WeightsList
     * 
     * @param WeightsList 
     */
    LayerType getType() const;
    LayerDeltaType DeltaList() const;
    LayerWeightsListType WeightsList() const;
    void setWeights(const LayerWeightsListType& WeightsList);
    LayerOutputType forwardPropogate(const LayerInputType& input);
    void CalculateGradientOutputLayer();
    void CalculateGradientHiddenLayer(const Layer& NextLayer);
    void updateWeights();
};

struct NetworkConfig
{
    uint16_t mLayerCount{0};
    uint16_t mInputCount{0};
    uint16_t mOutputCount{0};
    std::vector<uint16_t> mNodeCount{};
};

using NetworkInputType = std::vector<std::vector<float>>;
using NetworkOutputType = std::vector<float>;

class Network
{
    NetworkConfig mNetworkConfig;
    std::vector<Layer> mLayersList;

    void initLayers();
public:
    explicit Network(const NetworkConfig& networkConfig);

    void train(const NetworkInputType& input, const NetworkOutputType& output);
    float test(const std::vector<float>& input);
};

} // namespace Vengai
