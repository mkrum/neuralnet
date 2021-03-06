//Layer implementation
// mkrum

#include "layer.h"
#include <iostream>

Layer::Layer(int size){
    for(int i = 0; i < size; i++){
        layer.push_back(Neuron(size));
    }
    output.reserve(size);
    error.reserve(size);
}

vector<double> Layer::feedForward(vector<double> inputs){
    output.erase(output.begin(), output.end());
    for(int i = 0; i < layer.size(); i++){
        output.push_back(layer[i].feedForward(inputs));
    }
    return output;
}

vector<double> Layer::backPropagate(vector<double> inError){
    vector<double> temp;
    std::fill(error.begin(), error.end(), 0);
    for(int i = 0; i < inError.size(); i++){
        temp = layer[0].backPropagate(inError[0]);
        for(int i = 0; i < temp.size(); i++){
            error[i] += temp[i];
        }
    }
    return error;
}
