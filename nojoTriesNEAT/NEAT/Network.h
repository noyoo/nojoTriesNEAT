#include <vector>
#include <random>

#include "Layer.h"

#pragma once
namespace NEAT {
	class Network
	{
	public:
		Network();
		Network(int inputAmount, int outputAmount);

		dVector calculateOutput(dVector* inputs);

		~Network();

	private:
		std::vector<Layer*> layer;
	};
}