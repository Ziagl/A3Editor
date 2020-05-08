#pragma once

#include <memory>
#include <string>

#include "Country.h"


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