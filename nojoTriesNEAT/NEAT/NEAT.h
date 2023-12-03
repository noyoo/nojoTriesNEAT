

#ifndef NEAT_H
#define NEAT_H

namespace NEAT {

}

#endif

// population ()
//	-> network ()
//		-> layers ()
//			-> neurons (value, activation function)

// to fire a neuron, it needs the values from previous layer as well as their weights
// doing it all in a neuron requires referencing to layer - doesn't make sense
// doing it from the layer scope is better - pass two vectors (previous layer values and weights) then calculate

// each individual is a network
// network initialization = creating layers		|
// layer initialization = creating neurons		| -> random amounts

// n-best genetic optimalization: weights are inherited, n is 25%
// mutations: amount of layers+/-, amount of neurons on one of the layers +/-, activation function, mutation chances are user-defined
// activation functions: ReLU, linear, sigmoid (to be expanded), indexed using enum and switch



// STATIC MODE
// network optimization IN: learning dataset from file, OUT: optimalization log to file, best configuration to separate file
// network application IN: file of best config, vector of inputs OUT: file of outputs

// DYNAMIC MODE  calculateOutputs()
// optimization inputs IN: hooked up, OUT: outputs hooked up, optimalization log to file, best configuration to separate file, 
// application IN: file of best config, inputs hooked up, OUT: outputs hooked up
// is fired manually