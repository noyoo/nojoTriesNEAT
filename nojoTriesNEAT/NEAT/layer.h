#include <vector>
#include <stdlib.h>
#include <time.h>
#include "neuron.h"

#ifndef NEAT_LAYER_H
#define NEAT_LAYER_H

namespace NEAT {

	class Layer {
	public:
		Layer();
		Layer(unsigned int* neuronAmount);

		int getSize();
		std::vector<std::vector<double>>* getWeights();

		~Layer();

	private:
		std::vector<Neuron*> neuron;
		std::vector<std::vector<double>> incomingWeights;
	};
}

#endif // !NEAT_LAYER_H

