/****************************************************************************
*   Generated by ACUITY 6.6.0
*   Match timvx 1.1.30
*
*   Neural Network appliction network definition source file
****************************************************************************/
#include "vx_lenet.h"

#include <iostream>
#include <fstream>
#include <vector>

namespace
{

char *get_const_data(const char *data_file_name)
{
    std::ifstream fin(data_file_name, std::ios::in | std::ios::binary);
    if (fin)
    {
        fin.seekg(0, std::ios::end);
        int size = fin.tellg();
        fin.seekg(0, std::ios::beg);
        char *buffer = new char [size];
        std::cout<<"File "<<data_file_name <<" size:"<<size<<std::endl;
        fin.read(buffer, size);
        fin.close();
        return buffer;
    }
    else
    {
        std::cout<<"Load file "<<data_file_name <<" failed"<<std::endl;
        return NULL;
    }
}

}  // namespace

namespace acuitylite
{

std::vector<std::vector<uint32_t>> lenet::input_size_list = {{28 , 28 , 1 , 1}};
std::vector<uint32_t> lenet::input_bytes_list = {28 * 28 * 1 * 1 * sizeof(input_0_type)};
std::vector<std::vector<uint32_t>> lenet::output_size_list = {{10 , 1}};
std::vector<std::shared_ptr<tim::vx::Tensor>> lenet::inputs_tensor;
std::vector<std::shared_ptr<tim::vx::Tensor>> lenet::outputs_tensor;

void lenet::construct_graph
    (
    std::shared_ptr<tim::vx::Graph> graph,
    const char *data_file_name
    )
{
    char *coef_data_ptr = get_const_data(data_file_name);

    tim::vx::Quantization convolution_1_out0_quant(tim::vx::QuantType::ASYMMETRIC, 5.209146976470947, 131);
    tim::vx::TensorSpec convolution_1_out0_spec(tim::vx::DataType::UINT8, {},
    tim::vx::TensorAttribute::TRANSIENT, convolution_1_out0_quant);
    auto convolution_1_out0 = graph->CreateTensor(convolution_1_out0_spec);

    tim::vx::ShapeType convolution_1_weight_shape({5,5,1,20});
    tim::vx::Quantization convolution_1_weight_quant(tim::vx::QuantType::ASYMMETRIC, 0.0033623368944972754, 119);
    tim::vx::TensorSpec convolution_1_weight_spec(tim::vx::DataType::UINT8, convolution_1_weight_shape,
    tim::vx::TensorAttribute::CONSTANT, convolution_1_weight_quant);
    auto convolution_1_weight = graph->CreateTensor(convolution_1_weight_spec, coef_data_ptr + 80);

    tim::vx::ShapeType convolution_1_bias_shape({20});
    tim::vx::Quantization convolution_1_bias_quant(tim::vx::QuantType::ASYMMETRIC, 0.0033623368944972754, 0);
    tim::vx::TensorSpec convolution_1_bias_spec(tim::vx::DataType::INT32, convolution_1_bias_shape,
    tim::vx::TensorAttribute::CONSTANT, convolution_1_bias_quant);
    auto convolution_1_bias = graph->CreateTensor(convolution_1_bias_spec, coef_data_ptr + 0);

    tim::vx::Quantization pooling_2_out0_quant(tim::vx::QuantType::ASYMMETRIC, 5.209146976470947, 131);
    tim::vx::TensorSpec pooling_2_out0_spec(tim::vx::DataType::UINT8, {},
    tim::vx::TensorAttribute::TRANSIENT, pooling_2_out0_quant);
    auto pooling_2_out0 = graph->CreateTensor(pooling_2_out0_spec);

    tim::vx::Quantization convolution_3_out0_quant(tim::vx::QuantType::ASYMMETRIC, 10.594023704528809, 145);
    tim::vx::TensorSpec convolution_3_out0_spec(tim::vx::DataType::UINT8, {},
    tim::vx::TensorAttribute::TRANSIENT, convolution_3_out0_quant);
    auto convolution_3_out0 = graph->CreateTensor(convolution_3_out0_spec);

    tim::vx::ShapeType convolution_3_weight_shape({5,5,20,50});
    tim::vx::Quantization convolution_3_weight_quant(tim::vx::QuantType::ASYMMETRIC, 0.0011482049012556672, 128);
    tim::vx::TensorSpec convolution_3_weight_spec(tim::vx::DataType::UINT8, convolution_3_weight_shape,
    tim::vx::TensorAttribute::CONSTANT, convolution_3_weight_quant);
    auto convolution_3_weight = graph->CreateTensor(convolution_3_weight_spec, coef_data_ptr + 780);

    tim::vx::ShapeType convolution_3_bias_shape({50});
    tim::vx::Quantization convolution_3_bias_quant(tim::vx::QuantType::ASYMMETRIC, 0.005981168244034052, 0);
    tim::vx::TensorSpec convolution_3_bias_spec(tim::vx::DataType::INT32, convolution_3_bias_shape,
    tim::vx::TensorAttribute::CONSTANT, convolution_3_bias_quant);
    auto convolution_3_bias = graph->CreateTensor(convolution_3_bias_spec, coef_data_ptr + 580);

    tim::vx::Quantization pooling_4_out0_quant(tim::vx::QuantType::ASYMMETRIC, 10.594023704528809, 145);
    tim::vx::TensorSpec pooling_4_out0_spec(tim::vx::DataType::UINT8, {},
    tim::vx::TensorAttribute::TRANSIENT, pooling_4_out0_quant);
    auto pooling_4_out0 = graph->CreateTensor(pooling_4_out0_spec);

    tim::vx::Quantization fullconnect_5_out0_quant(tim::vx::QuantType::ASYMMETRIC, 4.961546421051025, 0);
    tim::vx::TensorSpec fullconnect_5_out0_spec(tim::vx::DataType::UINT8, {},
    tim::vx::TensorAttribute::TRANSIENT, fullconnect_5_out0_quant);
    auto fullconnect_5_out0 = graph->CreateTensor(fullconnect_5_out0_spec);

    tim::vx::ShapeType fullconnect_5_weight_shape({800,500});
    tim::vx::Quantization fullconnect_5_weight_quant(tim::vx::QuantType::ASYMMETRIC, 0.0007354848785325885, 130);
    tim::vx::TensorSpec fullconnect_5_weight_spec(tim::vx::DataType::UINT8, fullconnect_5_weight_shape,
    tim::vx::TensorAttribute::CONSTANT, fullconnect_5_weight_quant);
    auto fullconnect_5_weight = graph->CreateTensor(fullconnect_5_weight_spec, coef_data_ptr + 27780);

    tim::vx::ShapeType fullconnect_5_bias_shape({500});
    tim::vx::Quantization fullconnect_5_bias_quant(tim::vx::QuantType::ASYMMETRIC, 0.007791744079440832, 0);
    tim::vx::TensorSpec fullconnect_5_bias_spec(tim::vx::DataType::INT32, fullconnect_5_bias_shape,
    tim::vx::TensorAttribute::CONSTANT, fullconnect_5_bias_quant);
    auto fullconnect_5_bias = graph->CreateTensor(fullconnect_5_bias_spec, coef_data_ptr + 25780);

    tim::vx::Quantization relu_6_out0_quant(tim::vx::QuantType::ASYMMETRIC, 4.961546421051025, 0);
    tim::vx::TensorSpec relu_6_out0_spec(tim::vx::DataType::UINT8, {},
    tim::vx::TensorAttribute::TRANSIENT, relu_6_out0_quant);
    auto relu_6_out0 = graph->CreateTensor(relu_6_out0_spec);

    tim::vx::Quantization fullconnect_7_out0_quant(tim::vx::QuantType::ASYMMETRIC, 16.404624938964844, 81);
    tim::vx::TensorSpec fullconnect_7_out0_spec(tim::vx::DataType::UINT8, {},
    tim::vx::TensorAttribute::TRANSIENT, fullconnect_7_out0_quant);
    auto fullconnect_7_out0 = graph->CreateTensor(fullconnect_7_out0_spec);

    tim::vx::ShapeType fullconnect_7_weight_shape({500,10});
    tim::vx::Quantization fullconnect_7_weight_quant(tim::vx::QuantType::ASYMMETRIC, 0.0015804264694452286, 135);
    tim::vx::TensorSpec fullconnect_7_weight_spec(tim::vx::DataType::UINT8, fullconnect_7_weight_shape,
    tim::vx::TensorAttribute::CONSTANT, fullconnect_7_weight_quant);
    auto fullconnect_7_weight = graph->CreateTensor(fullconnect_7_weight_spec, coef_data_ptr + 427820);

    tim::vx::ShapeType fullconnect_7_bias_shape({10});
    tim::vx::Quantization fullconnect_7_bias_quant(tim::vx::QuantType::ASYMMETRIC, 0.00784135889261961, 0);
    tim::vx::TensorSpec fullconnect_7_bias_spec(tim::vx::DataType::INT32, fullconnect_7_bias_shape,
    tim::vx::TensorAttribute::CONSTANT, fullconnect_7_bias_quant);
    auto fullconnect_7_bias = graph->CreateTensor(fullconnect_7_bias_spec, coef_data_ptr + 427780);

    tim::vx::ShapeType input_0_shape({28,28,1,1});
    tim::vx::Quantization input_0_quant(tim::vx::QuantType::ASYMMETRIC, 1.0, 0);
    tim::vx::TensorSpec input_0_spec(tim::vx::DataType::UINT8, input_0_shape,
    tim::vx::TensorAttribute::INPUT, input_0_quant);
    auto input_0 = graph->CreateTensor(input_0_spec);

    tim::vx::ShapeType output_9_shape({10,1});
    tim::vx::TensorSpec output_9_spec(tim::vx::DataType::FLOAT32, output_9_shape,
    tim::vx::TensorAttribute::OUTPUT);
    auto output_9 = graph->CreateTensor(output_9_spec);

    lenet::inputs_tensor.push_back(input_0);

    lenet::outputs_tensor.push_back(output_9);

    auto convolution_1 = graph->CreateOperation <tim::vx::ops::Conv2d>(
        20,    // weights
        tim::vx::PadType::NONE,    // padding
        std::array<uint32_t, 2>({5,5}),    // ksize
        std::array<uint32_t, 2>({1,1}),    // stride
        std::array<uint32_t, 2>({1,1}),    // dilation
        std::array<uint32_t, 4>({0,0,0,0}),    // pad
        0);    // multiplier

    auto pooling_2 = graph->CreateOperation <tim::vx::ops::Pool2d>(
        tim::vx::PoolType::MAX,    // type
        std::array<uint32_t, 4>({0,0,0,0}),    // pad
        std::array<uint32_t, 2>({2,2}),    // ksize
        std::array<uint32_t, 2>({2,2}),    // stride
        tim::vx::RoundType::CEILING);    // round_type

    auto convolution_3 = graph->CreateOperation <tim::vx::ops::Conv2d>(
        50,    // weights
        tim::vx::PadType::NONE,    // padding
        std::array<uint32_t, 2>({5,5}),    // ksize
        std::array<uint32_t, 2>({1,1}),    // stride
        std::array<uint32_t, 2>({1,1}),    // dilation
        std::array<uint32_t, 4>({0,0,0,0}),    // pad
        0);    // multiplier

    auto pooling_4 = graph->CreateOperation <tim::vx::ops::Pool2d>(
        tim::vx::PoolType::MAX,    // type
        std::array<uint32_t, 4>({0,0,0,0}),    // pad
        std::array<uint32_t, 2>({2,2}),    // ksize
        std::array<uint32_t, 2>({2,2}),    // stride
        tim::vx::RoundType::CEILING);    // round_type

    auto fullconnect_5 = graph->CreateOperation <tim::vx::ops::FullyConnected>(
        2,    // axis
        500);    // weights

    auto relu_6 = graph->CreateOperation <tim::vx::ops::Relu>();

    auto fullconnect_7 = graph->CreateOperation <tim::vx::ops::FullyConnected>(
        0,    // axis
        10);    // weights

    auto softmax_8 = graph->CreateOperation <tim::vx::ops::Softmax>(
        1.0,    // beta
        0);    // axis

    (*convolution_1)
        .BindInputs({input_0, convolution_1_weight, convolution_1_bias})
        .BindOutputs({convolution_1_out0});

    (*pooling_2)
        .BindInputs({convolution_1_out0})
        .BindOutputs({pooling_2_out0});

    (*convolution_3)
        .BindInputs({pooling_2_out0, convolution_3_weight, convolution_3_bias})
        .BindOutputs({convolution_3_out0});

    (*pooling_4)
        .BindInputs({convolution_3_out0})
        .BindOutputs({pooling_4_out0});

    (*fullconnect_5)
        .BindInputs({pooling_4_out0, fullconnect_5_weight, fullconnect_5_bias})
        .BindOutputs({fullconnect_5_out0});

    (*relu_6)
        .BindInputs({fullconnect_5_out0})
        .BindOutputs({relu_6_out0});

    (*fullconnect_7)
        .BindInputs({relu_6_out0, fullconnect_7_weight, fullconnect_7_bias})
        .BindOutputs({fullconnect_7_out0});

    (*softmax_8)
        .BindInputs({fullconnect_7_out0})
        .BindOutputs({output_9});

    free(coef_data_ptr);
}

}  // namespace acuitylite