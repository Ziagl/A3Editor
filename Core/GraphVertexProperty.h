#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include "GraphData.h"

enum class Node_type 
{ 
    COUNTRY, 
    LEAGUE, 
    TEAM, 
    PLAYER, 
    UNKNOWN 
};

static std::ostream& operator<<(std::ostream& os, Node_type type) 
{
    switch (type) 
    {
        case Node_type::COUNTRY:
            return os << "COUNTRY";
        case Node_type::LEAGUE:
            return os << "LEAGUE";
        case Node_type::TEAM:
            return os << "TEAM";
        case Node_type::PLAYER:
            return os << "PLAYER";
        default:
        case Node_type::UNKNOWN:
            return os << "UNKNOWN";
    }
}

class VertexProperty
{
public:
    VertexProperty(int id = -1, Node_type type = Node_type::UNKNOWN) : id(id), type(type) { }
    VertexProperty(int id, Node_type type, GraphData data) : id(id), type(type), data(data) { }

    std::string toString() const
    {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    }

    int getVertexID() { return id; }
    Node_type getType() { return type; }
    GraphData getData() { return data; }

private:
    friend std::ostream& operator<<(std::ostream& os, VertexProperty const& v) {
        return os << "id " << v.id << " type " << v.type;
    }

    int id;
    Node_type type;
    GraphData data;
};