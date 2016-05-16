// Network implementation
// mkrum

#include "network.h"
#include <iostream>

Network::Network(int length, int width): output(width){
    for(int i = 0; i < length; i++){
        layers.push_back(Layer(width));
    }
}

double Network::feedForward(vector<double> inputs){
    for(int i = 0; i < layers.size(); i++){
        inputs = layers[i].feedForward(inputs);
    }
    out = output.feedForward(inputs);
    return out;
}

void Network::backPropagate(double target){
    double error = -(target - out);
    auto temp = output.backPropagate(error);
    for(int i = layers.size(); i > 0; i--){
        temp = layers[i].backPropagate(temp);
    }
}
