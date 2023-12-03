#include "Layer.h"

NEAT::Layer::Layer() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(1, std::nextafter(10, DBL_MAX));

	this->neuron.clear();

	double amt = dist(mt);

	for (int i = 0; i < amt; i++) {
		this->neuron.push_back(new NEAT::Neuron());
	}
}

NEAT::Layer::Layer(int amount) {
	this->neuron.clear();

	for (int i = 0; i < amount; i++) {
		this->neuron.push_back(new NEAT::Neuron());
	}
}

void NEAT::Layer::populateWeights(int inputCount) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(-10, std::nextafter(10, DBL_MAX));

	for (int i = 0; i < this->neuron.size(); i++) {
		this->neuronWeights.emplace_back();

		for (int j = 0; j < inputCount; j++) {
			this->neuronWeights.at(i).push_back(dist(mt));
		}
	}
}

dVector NEAT::Layer::fireNeurons(dVector* inputValues) {
	this->neuronValues.clear();

	for (int i = 0; i < this->neuron.size(); i++) {
		this->neuronValues.push_back(this->neuron.at(i)->fire(inputValues, &neuronWeights.at(i)));
	}

	return this->neuronValues;
}

dVector NEAT::Layer::getNeuronValues() {
	return this->neuronValues;
}

int NEAT::Layer::getSize() {
	return (int)this->neuron.size();
}

NEAT::Layer::~Layer() {

}