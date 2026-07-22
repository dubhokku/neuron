#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

// Sigmoid activation function to introduce non-linearity
double sigmoid(double x) {
    return 1.0 / (1.0 + std::exp(-x));
}

// Single neuron functional unit
class Neuron {
private:
    std::vector<double> weights;
    double bias;

public:
    // Initialize neuron with specific weights and bias
    Neuron(const std::vector<double>& initial_weights, double initial_bias)
        : weights(initial_weights), bias(initial_bias) {}

    // Feedforward process: (inputs * weights) + bias
    double feedforward(const std::vector<double>& inputs) {
        double dot_product = 0.0;
        for (size_t i = 0; i < inputs.size(); ++i) {
            dot_product += inputs[i] * weights[i];
        }
        return sigmoid(dot_product + bias);
    }
};

int main() {
    // Define inputs and model parameters
    std::vector<double> inputs = {0.5, 0.2, 0.8};
    std::vector<double> weights = {0.3, 0.1, -0.4};
    double bias = 0.2;

    // Create the neuron
    Neuron neuron(weights, bias);

    // Get output (prediction)
    double output = neuron.feedforward(inputs);

    std::cout << "Neuron Output: " << output << "\n";

    return 0;
}
