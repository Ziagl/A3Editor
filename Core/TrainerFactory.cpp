#include "TrainerFactory.h"

Trainer TrainerFactory::create()
{
	return Trainer();
}

Trainer TrainerFactory::createFromSAV(std::vector<std::string> data)
{
	Trainer trainer;

	if (data.empty())
	{
		logger->writeErrorEntry("Trainer data is empty.");
		return trainer;
	}

	trainer.setFirstname(data[0]);
	trainer.setLastname(data[1]);
	trainer.setCompetence(std::stoi(data[2]));
	trainer.setReputation(std::stoi(data[3]));
	trainer.setAge(std::stoi(data[4]));
	trainer.setBirthday(data[5]);
	trainer.setUnknown1(std::stoi(data[6]));
	trainer.setUnknown2(std::stoi(data[7]));

	return trainer;
}