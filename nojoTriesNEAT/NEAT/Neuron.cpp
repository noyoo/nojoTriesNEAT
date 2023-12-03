#include "Neuron.h"

NEAT::Neuron::Neuron() {
	this->activationFunction = LINEAR;
	this->value = 0;
}

double NEAT::Neuron::getValue() {
	return value;
}

void NEAT::Neuron::setActivationFunction(NEAT::ActivationFunction newActivationFunction) {
	this->activationFunction = newActivationFunction;
}

double NEAT::Neuron::fire(dVector* previousLayerValue, dVector* previousLayerWeight) {
	if (previousLayerValue->size() != previousLayerWeight->size()) throw std::invalid_argument("Data mismatch. Input vectors are not of the same length.");
	double weightedSum = 0;

	for (int i = 0; i < previousLayerValue->size(); i++) {
		weightedSum += previousLayerValue->at(i) * previousLayerWeight->at(i);
	}

	switch (this->activationFunction) {
	case LINEAR:
		return this->value = weightedSum;
		break;

	case ReLU:
		return this->value = weightedSum < 0 ? 0 : weightedSum;
		break;

	case SIGMOID:
		return this->value = 1 / (1 + exp(-weightedSum));
		break;

	default:
		throw std::invalid_argument("Incorrect activation function.");
		break;
	}
}

NEAT::Neuron::~Neuron() {

}
