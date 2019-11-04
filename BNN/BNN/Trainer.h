#pragma once

#include "NeuralNetwork.h"
#include <fstream>

// a single training entry. 16 inputs and expected output, used to populate the training set vectors
struct TrainingEntry
{
	std::vector<double>         m_inputs;
	std::vector<int32_t>        m_expectedOutputs;
};

// shorten the Training set vector definition
typedef std::vector<TrainingEntry> TrainingSet;

// Breaks the 20000 data entries into 3 groups.
// 60% training set
// 20% generalization set
// 20% validation set
struct TrainingData
{
	TrainingSet m_trainingSet;
	TrainingSet m_generalizationSet;
	TrainingSet m_validationSet;
};

// The main trainer class
class Trainer
{
public:

	// Structure used in constructors
	struct Settings
	{
		// Learning params *Need to learn more about these
		double      m_learningRate = 0.001;
		double      m_momentum = 0.9;

		// Stopping conditions
		// Stop the net at a certain number of epochs or once adesired accuracy is reached
		uint32_t    m_maxEpochs = 150;
		double      m_desiredAccuracy = 90;
	};

public:

	Trainer(Settings const& settings, Network* pNetwork);

	void Train(TrainingData const& trainingData);

private:

	// Error gradient maths
	inline double GetOutputErrorGradient(double desiredValue, double outputValue) const { return outputValue * (1.0 - outputValue) * (desiredValue - outputValue); }
	double GetHiddenErrorGradient(int32_t hiddenIdx) const;

	// Main functions for running the NN
	void RunEpoch(TrainingSet const& trainingSet);
	void Backpropagate(std::vector<int32_t> const& expectedOutputs);
	void UpdateWeights();

	void GetSetAccuracyAndMSE(TrainingSet const& trainingSet, double& accuracy, double& mse) const;

private:

	// The network to train
	Network * m_pNetwork;

	// Training settings
	double                      m_learningRate;             // Adjusts the step size of the weight update
	double                      m_momentum;                 // Improves performance of stochastic learning
	double                      m_desiredAccuracy;          // Target accuracy for training
	uint32_t                    m_maxEpochs;                // Max number of training epochs

	// Training data
	std::vector<double>         m_deltaInputHidden;         // Delta for input hidden layer
	std::vector<double>         m_deltaHiddenOutput;        // Delta for hidden output layer
	std::vector<double>         m_errorGradientsHidden;     // Error gradients for the hidden layer
	std::vector<double>         m_errorGradientsOutput;     // Error gradients for the outputs

	uint32_t                    m_currentEpoch;             // Epoch counter
	double                      m_trainingSetAccuracy;
	double                      m_validationSetAccuracy;
	double                      m_generalizationSetAccuracy;
	double                      m_trainingSetMSE;
	double                      m_validationSetMSE;
	double                      m_generalizationSetMSE;
};
