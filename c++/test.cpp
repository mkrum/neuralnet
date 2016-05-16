//Testing the neuron
//mkrum

#include "network.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    Network test = Network(3, 2);
    vector<double> temp;
    temp.push_back(.5);
    temp.push_back(.6);
    std::cout << test.feedForward(temp) << std::endl; 
    for(int i = 0; i < 1000; i++){
        test.backPropagate(.75);
        test.feedForward(temp);
    }
    std::cout << test.feedForward(temp) << std::endl; 
}
