#include "Network.h"

NEAT::Network::Network() {

}

NEAT::Network::Network(int inputAmount, int outputAmount) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(0, std::nextafter(10, DBL_MAX));

	this->layer.clear();

	double amt = dist(mt);

	this->layer.push_back(new NEAT::Layer());
	this->layer.at(0)->populateWeights(inputAmount);

	for (int i = 1; i < amt; i++) {
		this->layer.push_back(new NEAT::Layer());
		this->layer.at(i)->populateWeights(layer.at(i - 1)->getSize());
	}

	this->layer.push_back(new NEAT::Layer(outputAmount));
	this->layer.back()->populateWeights(layer.at(layer.size()-2)->getSize());
}

dVector NEAT::Network::calculateOutput(dVector* inputs) {
	layer.at(0)->fireNeurons(inputs);
	for (int i = 1; i < this->layer.size(); i++) {
		dVector previousLayerValues = this->layer.at(i - 1)->getNeuronValues();
		this->layer.at(i)->fireNeurons(&previousLayerValues);
	}
	return this->layer.back()->getNeuronValues();
}


NEAT::Network::~Network() {

}