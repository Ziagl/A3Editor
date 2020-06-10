#pragma once

#include <string>
#include "Trainer.h"
#include "Referee.h"
#include "Manager.h"
#include "Sponsor.h"
#include "Celebrity.h"
#include "Reporter.h"
#include "YouthPlayer.h"

namespace Core
{
	class Country
	{
		friend class CountryFactory;
	public:
		Country() : teamsCount(0), playable(false), unknown2(0), unknown4(0), unknown5(0), unknown6(0) {}
		~Country() {}

		// getter
		std::string getCupName() { return cup; }
		short getTeamsCount() { return teamsCount; }
		short getUnknown2() { return unknown2; }
		short getUnknown4() { return unknown4; }
		short getUnknown5() { return unknown5; }
		short getUnknown6() { return unknown6; }
		Person getPresident() { return president; }
		Trainer getNationalTrainer() { return nationalTrainer; }
		std::vector<Person> getCritics() { return critics; }
		std::vector<Reporter> getReporter() { return reporter; }
		std::vector<Celebrity> getCelebrities() { return celebrity; }
		std::vector<Sponsor> getSponsors() { return sponsors; }
		std::vector<Referee> getReferees() { return referees; }
		std::vector<Manager> getUnemployedManager() { return unemployedManager; }
		std::vector<Trainer> getGoalKeeperTrainer() { return goalKeeperTrainer; }
		std::vector<Trainer> getCoTrainer() { return coTrainer; }
		std::vector<YouthPlayer> getYouthPlayer() { return youthPlayer; }
		std::vector<std::string> getAmateurTeams() { return amateurTeams; }
		std::string getAssociationName() { return associationName; }
		// setter
		void setNationalTrainer(Trainer& nationalTrainer) { this->nationalTrainer = nationalTrainer; }
		void setPresident(Person& president) { this->president = president; }
		void setCoTrainer(std::vector<Trainer>& coTrainer) { this->coTrainer = coTrainer; }
		void setCoTrainer(Trainer cotrainer, size_t index) { this->coTrainer.at(index) = cotrainer; }
		void setGoalKeeperTrainer(std::vector<Trainer>& goalKeeperTrainer) { this->goalKeeperTrainer = goalKeeperTrainer; }
		void setGoalKeeperTrainer(Trainer goalkeepertrainer, size_t index) { this->goalKeeperTrainer.at(index) = goalkeepertrainer; }
		void setUnemployedManager(std::vector<Manager>& unemployedManager) { this->unemployedManager = unemployedManager; }
		void setUnemployedManager(Manager manager, size_t index) { this->unemployedManager.at(index) = manager; }
		void setReferees(std::vector<Referee>& referees) { this->referees = referees; }
		void setReferee(Referee referee, size_t index) { this->referees.at(index) = referee; }
		void setSponsors(std::vector<Sponsor>& sponsors) { this->sponsors = sponsors; }
		void setCelebrity(std::vector<Celebrity>& celebrity) { this->celebrity = celebrity; }
		void setReporter(std::vector<Reporter>& reporter) { this->reporter = reporter; }
		void setCritics(std::vector<Person>& critics) { this->critics = critics; }
		void setAmateurTeams(std::vector<std::string>& amateurTeams) { this->amateurTeams = amateurTeams; }
		void setYouthPlayer(std::vector<YouthPlayer>& youthPlayer) { this->youthPlayer = youthPlayer; }
		void setAssociationName(const std::string associationName) { this->associationName = associationName; }
		void setCupName(const std::string cup) { this->cup = cup; }

		//metadata
		std::string getFilename() { return filename; }
		bool isPlayable() { return playable; }

	protected:
		
		void setTeamsCount(const short teamsCount) { this->teamsCount = teamsCount; }
		void setUnknown2(const short unknown2) { this->unknown2 = unknown2; }
		void setUnknown4(const short unknown4) { this->unknown4 = unknown4; }
		void setUnknown5(const short unknown5) { this->unknown5 = unknown5; }
		void setUnknown6(const short unknown6) { this->unknown6 = unknown6; }
		
	private:
		// metadata
		void setPlayable(const bool playable) { this->playable = playable; }
		void setFilename(std::string filename) { this->filename = filename; }

		Trainer nationalTrainer;
		Person president;
		std::vector<Trainer> coTrainer;
		std::vector<Trainer> goalKeeperTrainer;
		std::vector<Manager> unemployedManager;
		std::vector<Referee> referees;
		std::vector<Sponsor> sponsors;
		std::vector<Celebrity> celebrity;
		std::vector<Reporter> reporter;
		std::vector<Person> critics;
		std::vector<std::string> amateurTeams;
		std::vector<YouthPlayer> youthPlayer;

		std::string cup;
		short teamsCount = 0;
		short unknown2 = 0;
		short unknown4 = 0;
		short unknown5 = 0;
		short unknown6 = 0;

		// from Kleinig.sav
		std::string associationName;

		// metadata
		std::string filename;	// filename A3Legacy
		bool playable;			// flag countries from individual country files that are playable in game
	};
}