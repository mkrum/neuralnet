//Testing the neuron
//mkrum

#include "Neuron.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){
    Neuron test = Neuron(1);
    vector<double> temp;
    temp.push_back(.5);
    std::cout << test.feedForward(temp) << std::endl;    

}
