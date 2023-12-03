#include "NEAT/NEAT.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "NEAT\Neuron.h"
#include "NEAT\Layer.h"
#include "NEAT\Network.h"

int main() {
	dVector input;
	input.clear();
	input.push_back(1);
	input.push_back(2);

	NEAT::Network* net = new NEAT::Network(input.size(), 3);
	auto a = net->calculateOutput(&input);

	return 0;
}