#pragma once

#include <memory>
#include <string>

#include "Country.h"
#include "Team.h"
#include "Player.h"
//#include "Stadium.h"


struct GraphDataFacility
{
	virtual ~GraphDataFacility() = default;
	virtual std::string toString() = 0;
};

using GraphData = std::shared_ptr<GraphDataFacility>;

struct GraphCountry : public Country, public GraphDataFacility
{
	GraphCountry() : Country() {}
	virtual std::string toString() override { return ""; }
};

struct GraphTeam : public Team, public GraphDataFacility
{
	GraphTeam() : Team() {}
	virtual std::string toString() override { return ""; }
};

struct GraphPlayer : public Player, public GraphDataFacility
{
	GraphPlayer() : Player() {}
	virtual std::string toString() override { return ""; }
};
/*
struct GraphStadium : public Stadium, public GraphDataFacility
{
	GraphStadium() : Stadium() {}
	virtual std::string toString() override { return ""; }
};*/