#include <vector>
#include <random>
#include "Neuron.h"

#pragma once

namespace NEAT {
	class Layer
	{
	public:
		Layer();
		Layer(int amount);

		void populateWeights(int inputCount);
		dVector fireNeurons(dVector* inputValues);
		dVector getNeuronValues();
		int getSize();
		
		~Layer();

	private:
		std::vector<Neuron*> neuron;
		std::vector<dVector> neuronWeights;
		dVector neuronValues;
	};
}

