#ifndef NEAT_NEURON_H
#define NEAT_NEURON_H
namespace NEAT {

	class Neuron {
	public:
		Neuron();

		double fire();

		~Neuron();

	private:
		double sum;
		//activation function
	};
}
#endif