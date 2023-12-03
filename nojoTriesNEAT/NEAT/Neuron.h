#include <vector>
#include <stdexcept>
#include <random>
typedef std::vector<double> dVector;

#pragma once

namespace NEAT {

	enum ActivationFunction {
		LINEAR,
		ReLU,
		SIGMOID,
	};

	class Neuron {
	public:
		Neuron();

		double getValue();
		void setActivationFunction(ActivationFunction newActivationFunction);
		double fire(dVector* previousLayerValue, dVector* previousLayerWeight);

		~Neuron();

	private:
		double value = 0;
		ActivationFunction activationFunction;
	};
}
