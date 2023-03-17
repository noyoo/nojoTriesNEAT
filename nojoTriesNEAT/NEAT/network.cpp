#include "network.h"

#define RANDOM_LAYER_CAP 20

NEAT::Network::Network() {

}

NEAT::Network::Network(int inputAmount, int outputAmount) {
	srand(time(NULL));

	// create input and output layers independently
	this->inputLayer = new NEAT::Layer((unsigned int*)&inputAmount);
	this->outputLayer = new NEAT::Layer((unsigned int*)&outputAmount);

	// then create the rest of the network at random

	for (int i = 0; i < rand() % RANDOM_LAYER_CAP; i++) {
		this->innerNetwork.push_back(new NEAT::Layer());
	}

	// populate weights of inner network

	for (int i = 0; i < this->innerNetwork.at(0)->getSize(); i++) {
		this->innerNetwork.at(0)->getWeights()->emplace_back();

		for (int j = 0; j < this->inputLayer->getSize(); j++) {
			this->innerNetwork.at(0)->getWeights()->at(i).push_back((double)(rand() % 2001) / 100 - 10);
		}
	}
	for (int i = 1; i < this->innerNetwork.size(); i++) {
		for (int j = 0; j < this->innerNetwork.at(i)->getSize(); j++) {
			this->innerNetwork.at(i)->getWeights()->emplace_back();
			for (int k = 0; k < this->innerNetwork.at(i - 1)->getSize(); k++) {
				this->innerNetwork.at(i)->getWeights()->at(j).push_back((double)(rand() % 2001) / 100 - 10);
			}
		}
	}

	// and of the output layer

	for (int i = 0; i < this->outputLayer->getSize(); i++) {
		this->outputLayer->getWeights()->emplace_back();

		for (int j = 0; j < this->innerNetwork.back()->getSize(); j++) {
			this->outputLayer->getWeights()->at(i).push_back((double)(rand() % 2001) / 100 - 10);
		}
	}
}

NEAT::Network::~Network() {

}