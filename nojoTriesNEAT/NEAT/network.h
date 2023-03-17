#include "layer.h"

#ifndef NEAT_NETWORK_H
#define NEAT_NETWORK_H

namespace NEAT {
	class Network {
	public:
		Network();
		Network(int inputAmount, int outputAmount);

		~Network();

	private:
		std::vector<Layer*> innerNetwork;
		NEAT::Layer* inputLayer = new Layer();
		NEAT::Layer* outputLayer = new Layer();
	};
}

#endif // !NEAT_NETWORK_H

