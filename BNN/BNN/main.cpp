#include "Trainer.h"
#include "DataReader.h"
#include <iostream>

int main(int argc, char* argv[])
{

	/* Data from http://archive.ics.uci.edu/ml/datasets/Letter+Recognition 
		- Contains 16 attribute values of a letter per row
		- The last column is the expected output, a simple boolean representing whether the leter is an a or not
	*/
	std::string trainingDataPath = "ExampleDataSet.csv";
	uint32_t const numInputs = 16;
	uint32_t const numHidden = 16;
	uint32_t const numOutputs = 3;

	DataReader dataReader(trainingDataPath, numInputs, numOutputs);
	if (!dataReader.ReadData())
	{
		return 1;
	}

	Network::Settings networkSettings{ numInputs, numHidden, numOutputs };
	Network nn(networkSettings);

	Trainer::Settings trainerSettings;
	trainerSettings.m_learningRate = 0.001;
	trainerSettings.m_momentum = 0.9;
	trainerSettings.m_maxEpochs = 200;
	trainerSettings.m_desiredAccuracy = 90;

	Trainer trainer(trainerSettings, &nn);
	trainer.Train(dataReader.GetTrainingData());
	
	return 0;
}