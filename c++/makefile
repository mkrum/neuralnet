LINK=-std=c++11 

main: test neuron.o layer.o network.o

test: neuron.o layer.o network.o test.cpp ; g++ $(LINK) $^ -o $@

%.o: %.cpp ; g++ $(LINK) -c $^ -o $@
