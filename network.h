// the full network class
// mkrum

#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "layer.h"

class Network {
    public:
        Network(int, int);
        double feedForward(vector<double>);
        void backPropagate(double);
    private:
        vector<Layer> layers;
        double out;
        Neuron output;
};

#endif
