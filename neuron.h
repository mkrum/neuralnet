// Neuron Header
// mkrum

#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <random>
#include <math.h>

using std::vector;

class Neuron {
    public:
        Neuron(int);
        double feedForward(vector<double>);
        vector<double> backProp(double);
    private:
        vector<double> weights;
        vector<double> error;
        vector<double> inputs;
        double bias;
        double output;
        double stepSize;
        double (*_activation)(double);
        double (*_activationDer)(double);
};

#endif
