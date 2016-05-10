//Neuron Class Implemention
// mkrum

#include "Neuron.h"
//default activation functions
double sigmoid(double);
double sigmoidDer(double);

Neuron::Neuron(int size){
    std::random_device r;
    std::default_random_engine gen(r());
    std::uniform_real_distribution<double> dist(0, 1);
    for(int i = 0; i < size; i++){
        weights.push_back(dist(gen));
    }
    error.reserve(size);
    inputs.reserve(size);
    bias = dist(gen);
    _activation = &sigmoid;
    _activationDer = &sigmoidDer;
    stepSize = .1;
}

double Neuron::feedForward(vector<double> ins){
    inputs = ins;
    double sum = 0;
    for(int i = 0; i < weights.size(); i++){
        sum += inputs[i] * weights[i];
    }
    output = _activation(sum + bias);
    return output;
}

vector<double> Neuron::backPropagate(double inError){
    for(int i = 0; i < weights.size(); i++){
        error[i] = inError * _activationDer(output) * weights[i];
        weights[i] -= inError * _activationDer(output) * inputs[i]; 
    }
    bias -= inError * _activationDer(output) * bias;
    return error;
}
 
double sigmoid(double val){
    return 1/(1 + exp(-val));
}

double sigmoidDer(double val){
    return sigmoid(val) * ( 1 - sigmoid(val));
}

   
