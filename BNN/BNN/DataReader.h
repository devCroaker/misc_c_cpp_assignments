#pragma once

#include "Trainer.h"
#include <string>

class DataReader
{
public:

	DataReader(std::string const& filename, int32_t numInputs, int32_t numOutputs);

	bool ReadData();

	inline int32_t GetNumInputs() const { return m_numInputs; }
	inline int32_t GetNumOutputs() const { return m_numOutputs; }

	inline int32_t GetNumTrainingSets() const { return 0; }
	TrainingData const& GetTrainingData() const { return m_data; }

private:

	void CreateTrainingData();

private:

	std::string                     m_filename;
	int32_t                         m_numInputs;
	int32_t                         m_numOutputs;

	std::vector<TrainingEntry>      m_entries;
	TrainingData                    m_data;
};

