#pragma once

#include <string>
#include "Trainer.h"
#include "Referee.h"
#include "Manager.h"
#include "Sponsor.h"
#include "Celebrity.h"
#include "Reporter.h"
#include "YouthPlayer.h"

class Country
{
	friend class CountryFactory;
public:
	Country() {}
	~Country() {}

	void setNationalTrainer(Trainer& nationalTrainer) { this->nationalTrainer = nationalTrainer; }
	void setPresident(Person& president) { this->president = president; }
	void setCoTrainer(std::vector<Trainer>& coTrainer) { this->coTrainer = coTrainer; }
	void setGoalKeeperTrainer(std::vector<Trainer>& goalKeeperTrainer) { this->goalKeeperTrainer = goalKeeperTrainer; }
	void setUnemployedManager(std::vector<Manager>& unemployedManager) { this->unemployedManager = unemployedManager; }
	void setReferees(std::vector<Referee>& referees) { this->referees = referees; }
	void setSponsors(std::vector<Sponsor>& sponsors) { this->sponsors = sponsors; }
	void setCelebrity(std::vector<Celebrity>& celebrity) { this->celebrity = celebrity; }
	void setReporter(std::vector<Reporter>& reporter) { this->reporter = reporter; }
	void setCritics(std::vector<Person>& critics) { this->critics = critics; }
	void setAmateurTeams(std::vector<std::string>& amateurTeams) { this->amateurTeams = amateurTeams; }
	void setYouthPlayer(std::vector<YouthPlayer>& youthPlayer) { this->youthPlayer = youthPlayer; }

	// getter/setter
	std::string getCupName() { return cup; }
	short getCountryId() { return countryId; }
	short getUnknown2() { return unknown2; }
	short getUnknown4() { return unknown4; }
	short getUnknown5() { return unknown5; }
	short getUnknown6() { return unknown6; }
	Person getPresident() { return president; }
	std::vector<Person> getCritics() { return critics; }
	std::vector<Reporter> getReporter() { return reporter; }
	std::vector<Celebrity> getCelebrities() { return celebrity; }
	std::vector<Sponsor> getSponsors() { return sponsors; }
	std::vector<Referee> getReferees() { return referees; }
	std::vector<Manager> getUnemployedManager() { return unemployedManager; }
	std::vector<Trainer> getGoalKeeperTrainer() { return goalKeeperTrainer; }
	std::vector<Trainer> getCoTrainer() { return coTrainer; }

	//metadata
	std::string getFilename() { return filename; }
	void setFilename(std::string filename) { this->filename = filename; }
protected:
	void setCupName(const std::string cup) { this->cup = cup; }
	void setCountryId(const short countryId) { this->countryId = countryId; }
	void setUnknown2(const short unknown2) { this->unknown2 = unknown2; }
	void setUnknown4(const short unknown4) { this->unknown4 = unknown4; }
	void setUnknown5(const short unknown5) { this->unknown5 = unknown5; }
	void setUnknown6(const short unknown6) { this->unknown6 = unknown6; }
private:
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
	short countryId;
	short unknown2;
	short unknown4;
	short unknown5;
	short unknown6;

	// metadata
	std::string filename;	// filename A3Legacy
};