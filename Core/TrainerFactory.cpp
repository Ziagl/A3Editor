#include "TrainerFactory.h"
#include "globals.h"
#include <fstream>

using namespace Core;

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
	// trainer / cotrainer
	if (data.size() > 7)
	{
		trainer.setReputation(std::stoi(data[3]));
		trainer.setAge(std::stoi(data[4]));
		trainer.setBirthday(data[5]);
		trainer.setUnknown1(std::stoi(data[6]));
		trainer.setUnknown2(std::stoi(data[7]));
	}
	// goalkeeper trainer
	else
	{
		trainer.setAge(std::stoi(data[3]));
		trainer.setBirthday(data[4]);
		trainer.setUnknown1(std::stoi(data[5]));
		trainer.setUnknown2(std::stoi(data[6]));
	}

	return trainer;
}

void TrainerFactory::writeToSAV(Trainer& trainer, std::ofstream& out, bool goalkeeper)
{
	out << trainer.getFirstname() << ENDOFLINE;
	out << trainer.getLastname() << ENDOFLINE;
	out << trainer.getCompetence() << ENDOFLINE;
	if(!goalkeeper)
		out << trainer.getReputation() << ENDOFLINE;
	out << trainer.getAge() << ENDOFLINE;
	out << trainer.getBirthday() << ENDOFLINE;
	out << trainer.getUnknown1() << ENDOFLINE;
	out << trainer.getUnknown2() << ENDOFLINE;
}