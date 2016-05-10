//Layer class, basically a way to store a vector of neurons
// mkrum

#ifndef LAYER_H
#define LAYER_H

#include "neuron.h"
#include <vector>

using std::vector;

class Layer {
    public:
        Layer(int);
        vector<double> feedForward(vector<double>);
        vector<double> backPropagate(vector<double>);
    private:
        vector<Neuron> layer;
        vector<double> output;
        vector<double> error;
};
#endif
