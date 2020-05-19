#include "StadiumFactory.h"
#include <fstream>

using namespace Core;

Stadium StadiumFactory::create()
{
	return Stadium();
}

Stadium StadiumFactory::createFromSAV(std::vector<std::string> data)
{
	Stadium stadium;

	if (data.empty())
	{
		logger->writeErrorEntry("Stadium data is empty.");
		return stadium;
	}

	stadium.setName(data[0]);
	stadium.setLocation(data[1]);
	stadium.setScoreboard(std::stoi(data[2]));
	stadium.setHeating(std::stoi(data[3]) != 0);
	stadium.setUnknown1(std::stoi(data[4]));
	stadium.setUnknown2(std::stoi(data[5]));
	stadium.setFloodlight(std::stoi(data[6]) != 0);
	stadium.setFanSector(std::stoi(data[7]));
	stadium.setGuestSector(std::stoi(data[8]));
	stadium.setCityLocation(std::stoi(data[9]) != 0);
	stadium.setInPossesion(std::stoi(data[10]) != 0);
	stadium.setHighwayAccess(std::stoi(data[11]) != 0);
	stadium.setTelevisionTowser(std::stoi(data[12]) != 0);
	stadium.setMainStandStandPlaces(std::stoi(data[13]));
	stadium.setMainStandSeatings(std::stoi(data[14]));
	stadium.setMainStandVIP(std::stoi(data[15]));
	stadium.setMainStandCondition(std::stoi(data[16]));
	stadium.setOppositeStandStandPlaces(std::stoi(data[17]));
	stadium.setOppositeStandSeatings(std::stoi(data[18]));
	stadium.setOppositeStandVIP(std::stoi(data[19]));
	stadium.setOppositeStandCondition(std::stoi(data[20]));
	stadium.setLeftStandStandPlaces(std::stoi(data[21]));
	stadium.setLeftStandSeatings(std::stoi(data[22]));
	stadium.setLeftStandVIP(std::stoi(data[23]));
	stadium.setLeftStandCondition(std::stoi(data[24]));
	stadium.setRightStandStandPlaces(std::stoi(data[25]));
	stadium.setRightStandSeatings(std::stoi(data[26]));
	stadium.setRightStandVIP(std::stoi(data[27]));
	stadium.setRightStandCondition(std::stoi(data[28]));
	stadium.setMainStandRoof((std::stoi(data[29]) & 1) != 0);		// 0001
	stadium.setOppositeStandRoof((std::stoi(data[29]) & 2) != 0);	// 0010
	stadium.setLeftStandRoof((std::stoi(data[29]) & 4) != 0);		// 0100
	stadium.setRightStandRoof((std::stoi(data[29]) & 8) != 0);		// 1000
	stadium.setTrack(std::stoi(data[30]) != 0);			// 0 (0000) oder 15	(1111)
	stadium.setMainStandRadiantHeaters((std::stoi(data[31]) & 1) != 0);		// 0001
	stadium.setOppositeStandRadiantHeaters((std::stoi(data[31]) & 2) != 0);	// 0010
	stadium.setLeftStandRadiantHeaters((std::stoi(data[31]) & 4) != 0);		// 0100
	stadium.setRightStandRadiantHeaters((std::stoi(data[31]) & 8) != 0);	// 1000
	stadium.setLuxuryCabins(std::stoi(data[32]) != 0);
	stadium.setSeatCushions(std::stoi(data[33]) != 0);
	stadium.setHeatedSeats(std::stoi(data[34]) != 0);
	stadium.setExtendablePlayingField(std::stoi(data[35]) != 0);
	stadium.setMountains(std::stoi(data[36]) != 0);
	stadium.setCastle(std::stoi(data[37]) != 0);
	stadium.setPalace(std::stoi(data[38]) != 0);
	return stadium;
}

void StadiumFactory::writeToSAV(Stadium& stadium, std::ofstream& out)
{
	out << stadium.getName() << "\n";
	out << stadium.getLocation() << "\n";
	out << stadium.getScoreboard() << "\n";
	out << (stadium.getHeating()?"1":"0") << "\n";
	out << stadium.getUnknown1() << "\n";
	out << stadium.getUnknown2() << "\n";
	out << (stadium.getFloodlight()?"1":"0") << "\n";
	out << stadium.getFanSector() << "\n";
	out << stadium.getGuestSector() << "\n";
	out << (stadium.getCityLocation()?"1":"0") << "\n";
	out << (stadium.getInPossesion() ? "1" : "0") << "\n";
	out << (stadium.getHighwayAccess() ? "1" : "0") << "\n";
	out << (stadium.getTelevisionTowser()?"1":"0") << "\n";
	out << stadium.getMainStandStandPlaces() << "\n";
	out << stadium.getMainStandSeatings() << "\n";
	out << stadium.getMainStandVIP() << "\n";
	out << stadium.getMainStandCondition() << "\n";
	out << stadium.getOppositeStandStandPlaces() << "\n";
	out << stadium.getOppositeStandSeatings() << "\n";
	out << stadium.getOppositeStandVIP() << "\n";
	out << stadium.getOppositeStandCondition() << "\n";
	out << stadium.getLeftStandStandPlaces() << "\n";
	out << stadium.getLeftStandSeatings() << "\n";
	out << stadium.getLeftStandVIP() << "\n";
	out << stadium.getLeftStandCondition() << "\n";
	out << stadium.getRightStandStandPlaces() << "\n";
	out << stadium.getRightStandSeatings() << "\n";
	out << stadium.getRightStandVIP() << "\n";
	out << stadium.getRightStandCondition() << "\n";
	short value = 0;
	if (stadium.getMainStandRoof())
		value += 1;							// 0001
	if (stadium.getOppositeStandRoof())
		value += 2;							// 0010
	if (stadium.getLeftStandRoof())
		value += 4;							// 0100
	if (stadium.getRightStandRoof())
		value += 8;							// 1000
	out << value << "\n";
	out << (stadium.getTrack()?"15":"0") << "\n";
	value = 0;
	if (stadium.getMainStandRadiantHeaters())
		value += 1;							// 0001
	if (stadium.getOppositeStandRadiantHeaters())
		value += 2;							// 0010
	if (stadium.getLeftStandRadiantHeaters())
		value += 4;							// 0100
	if (stadium.getRightStandRadiantHeaters())
		value += 8;							// 1000
	out << value << "\n";
	out << (stadium.getLuxuryCabins()?"1":"0") << "\n";
	out << (stadium.getSeatCushions()?"1":"0") << "\n";
	out << (stadium.getHeatedSeats()?"1":"0") << "\n";
	out << (stadium.getExtendablePlayingField()?"1":"0") << "\n";
	out << (stadium.getMountains()?"1":"0") << "\n";
	out << (stadium.getCastle()?"1":"0") << "\n";
	out << (stadium.getPalace()?"1":"0") << "\n";
}