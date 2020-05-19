#pragma once

//#include "StadiumFactory.h"

namespace Core
{
	class Stadium
	{
		friend class StadiumFactory;
	public:
		Stadium() {}
		~Stadium() {}

		//getter/setter
		std::string getName() { return name; }
		std::string getLocation() { return location; }
		short getScoreboard() { return scoreboard; }
		bool getHeating() { return heating; }
		bool getFloodlight() { return floodlight; }
		short getFanSector() { return fanSector; }
		short getGuestSector() { return guestSector; }
		bool getCityLocation() { return cityLocation; }
		bool getInPossesion() { return inPossession; }
		bool getHighwayAccess() { return highwayAccess; }
		bool getTelevisionTowser() { return televisionTower; }
		int getMainStandStandPlaces() { return mainStandStandPlaces; }
		int getMainStandSeatings() { return mainStandSeatings; }
		int getMainStandVIP() { return mainStandVIP; }
		short getMainStandCondition() { return mainStandCondition; }
		int getOppositeStandStandPlaces() { return oppositeStandStandPlaces; }
		int getOppositeStandSeatings() { return oppositeStandSeatings; }
		int getOppositeStandVIP() { return oppositeStandVIP; }
		short getOppositeStandCondition() { return oppositeStandCondition; }
		int getLeftStandStandPlaces() { return leftStandStandPlaces; }
		int getLeftStandSeatings() { return leftStandSeatings; }
		int getLeftStandVIP() { return leftStandVIP; }
		short getLeftStandCondition() { return leftStandCondition; }
		int getRightStandStandPlaces() { return rightStandStandPlaces; }
		int getRightStandSeatings() { return rightStandSeatings; }
		int getRightStandVIP() { return rightStandVIP; }
		short getRightStandCondition() { return rightStandCondition; }
		bool getMainStandRoof() { return mainStandRoof; }
		bool getOppositeStandRoof() { return oppositeStandRoof; }
		bool getLeftStandRoof() { return leftStandRoof; }
		bool getRightStandRoof() { return rightStandRoof; }
		bool getTrack() { return track; }
		bool getMainStandRadiantHeaters() { return mainStandRadiantHeaters; }
		bool getOppositeStandRadiantHeaters() { return oppositeStandRadiantHeaters; }
		bool getLeftStandRadiantHeaters() { return leftStandRadiantHeaters; }
		bool getRightStandRadiantHeaters() { return rightStandRadiantHeaters; }
		bool getLuxuryCabins() { return luxuryCabins; }
		bool getSeatCushions() { return seatCushions; }
		bool getHeatedSeats() { return heatedSeats; }
		bool getExtendablePlayingField() { return extendablePlayingField; }
		bool getMountains() { return mountains; }
		bool getCastle() { return castle; }
		bool getPalace() { return palace; }
		short getUnknown1() { return unknown1; }
		short getUnknown2() { return unknown2; }

	protected:
		void setName(const std::string name) { this->name = name; }
		void setLocation(const std::string location) { this->location = location; }
		void setScoreboard(const short scoreboard) { this->scoreboard = scoreboard; }
		void setHeating(const bool heating) { this->heating = heating; }
		void setFloodlight(const bool floodlight) { this->floodlight = floodlight; }
		void setFanSector(const short fanSector) { this->fanSector = fanSector; }
		void setGuestSector(const short guestSector) { this->guestSector = guestSector; }
		void setCityLocation(const bool cityLocation) { this->cityLocation = cityLocation; }
		void setInPossesion(const bool inPossession) { this->inPossession = inPossession; }
		void setHighwayAccess(const bool highwayAccess) { this->highwayAccess = highwayAccess; }
		void setTelevisionTowser(const bool televisionTower) { this->televisionTower = televisionTower; }
		void setMainStandStandPlaces(const int mainStandStandPlaces) { this->mainStandStandPlaces = mainStandStandPlaces; }
		void setMainStandSeatings(const int mainStandSeatings) { this->mainStandSeatings = mainStandSeatings; }
		void setMainStandVIP(const int mainStandVIP) { this->mainStandVIP = mainStandVIP; }
		void setMainStandCondition(const short mainStandCondition) { this->mainStandCondition = mainStandCondition; }
		void setOppositeStandStandPlaces(const int oppositeStandStandPlaces) { this->oppositeStandStandPlaces = oppositeStandStandPlaces; }
		void setOppositeStandSeatings(const int oppositeStandSeatings) { this->oppositeStandSeatings = oppositeStandSeatings; }
		void setOppositeStandVIP(const int oppositeStandVIP) { this->oppositeStandVIP = oppositeStandVIP; }
		void setOppositeStandCondition(const short oppositeStandCondition) { this->oppositeStandCondition = oppositeStandCondition; }
		void setLeftStandStandPlaces(const int leftStandStandPlaces) { this->leftStandStandPlaces = leftStandStandPlaces; }
		void setLeftStandSeatings(const int leftStandSeatings) { this->leftStandSeatings = leftStandSeatings; }
		void setLeftStandVIP(const int leftStandVIP) { this->leftStandVIP = leftStandVIP; }
		void setLeftStandCondition(const short leftStandCondition) { this->leftStandCondition = leftStandCondition; }
		void setRightStandStandPlaces(const int rightStandStandPlaces) { this->rightStandStandPlaces = rightStandStandPlaces; }
		void setRightStandSeatings(const int rightStandSeatings) { this->rightStandSeatings = rightStandSeatings; }
		void setRightStandVIP(const int rightStandVIP) { this->rightStandVIP = rightStandVIP; }
		void setRightStandCondition(const short rightStandCondition) { this->rightStandCondition = rightStandCondition; }
		void setMainStandRoof(const bool mainStandRoof) { this->mainStandRoof = mainStandRoof; }
		void setOppositeStandRoof(const bool oppositeStandRoof) { this->oppositeStandRoof = oppositeStandRoof; }
		void setLeftStandRoof(const bool leftStandRoof) { this->leftStandRoof = leftStandRoof; }
		void setRightStandRoof(const bool rightStandRoof) { this->rightStandRoof = rightStandRoof; }
		void setTrack(const bool track) { this->track = track; }
		void setMainStandRadiantHeaters(const bool mainStandRadiantHeaters) { this->mainStandRadiantHeaters = mainStandRadiantHeaters; }
		void setOppositeStandRadiantHeaters(const bool oppositeStandRadiantHeaters) { this->oppositeStandRadiantHeaters = oppositeStandRadiantHeaters; }
		void setLeftStandRadiantHeaters(const bool leftStandRadiantHeaters) { this->leftStandRadiantHeaters = leftStandRadiantHeaters; }
		void setRightStandRadiantHeaters(const bool rightStandRadiantHeaters) { this->rightStandRadiantHeaters = rightStandRadiantHeaters; }
		void setLuxuryCabins(const bool luxuryCabins) { this->luxuryCabins = luxuryCabins; }
		void setSeatCushions(const bool seatCushions) { this->seatCushions = seatCushions; }
		void setHeatedSeats(const bool heatedSeats) { this->heatedSeats = heatedSeats; }
		void setExtendablePlayingField(const bool extendablePlayingField) { this->extendablePlayingField = extendablePlayingField; }
		void setMountains(const bool mountains) { this->mountains = mountains; }
		void setCastle(const bool castle) { this->castle = castle; }
		void setPalace(const bool palace) { this->palace = palace; }
		void setUnknown1(const short unknown1) { this->unknown1 = unknown1; }
		void setUnknown2(const short unknown2) { this->unknown2 = unknown2; }

	private:
		std::string name;
		std::string location;
		short scoreboard;
		bool heating;

		bool floodlight;
		// 0..Haupt, 1..Gegen, 2..Links, 3..Rechts
		short fanSector;
		short guestSector;
		bool cityLocation;
		bool inPossession;
		bool highwayAccess;
		bool televisionTower;
		int mainStandStandPlaces;
		int mainStandSeatings;
		int mainStandVIP;
		bool mainStandRoof;
		bool mainStandRadiantHeaters;
		short mainStandCondition;
		int oppositeStandStandPlaces;
		int oppositeStandSeatings;
		int oppositeStandVIP;
		bool oppositeStandRoof;
		bool oppositeStandRadiantHeaters;
		short oppositeStandCondition;
		int leftStandStandPlaces;
		int leftStandSeatings;
		int leftStandVIP;
		bool leftStandRoof;
		bool leftStandRadiantHeaters;
		short leftStandCondition;
		int rightStandStandPlaces;
		int rightStandSeatings;
		int rightStandVIP;
		short rightStandCondition;
		bool rightStandRoof;
		bool rightStandRadiantHeaters;
		bool track;
		bool luxuryCabins;
		bool seatCushions;
		bool heatedSeats;
		bool extendablePlayingField;
		bool mountains;
		bool castle;
		bool palace;
		short unknown1;
		short unknown2;
	};
}