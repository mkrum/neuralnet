LINK=-std=c++11 

main: test neuron.o

test: neuron.o test.cpp ; g++ $(LINK) $^ -o $@

%.o: %.cpp ; g++ $(LINK) -c $^ -o $@
