#include "layer.h"

#define RANDOM_NEURON_CAP 20

NEAT::Layer::Layer() {
	//srand(time(NULL));

	for (int i = 0; i < rand() % RANDOM_NEURON_CAP+1; i++) {
		this->neuron.push_back(new NEAT::Neuron());
	}
}

NEAT::Layer::Layer(unsigned int* neuronAmount) {
	for (int i = 0; i < (int)*neuronAmount; i++) {
	this->neuron.push_back(new NEAT::Neuron());

	}
}

int NEAT::Layer::getSize() {
	return this->neuron.size();
}

std::vector<std::vector<double>>* NEAT::Layer::getWeights() {
	return &this->incomingWeights;
}

NEAT::Layer::~Layer() {

}