#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include "GraphData.h"

namespace Core
{
    enum class Node_type
    {
        PLAYERPOOL,
        NATION,
        EUROWINNER,
        UEFARANKING,
        INTERNATIONAL,
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
        case Node_type::PLAYERPOOL:
            return os << "PLAYERPOOL";
        case Node_type::NATION:
            return os << "NATION";
        case Node_type::EUROWINNER:
            return os << "EUROWINNER";
        case Node_type::UEFARANKING:
            return os << "UEFARANKING";
        case Node_type::INTERNATIONAL:
            return os << "INTERNATIONAL";
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
        VertexProperty(size_t id = -1, Node_type type = Node_type::UNKNOWN) : id(id), type(type) { }
        VertexProperty(size_t id, Node_type type, GraphData data) : id(id), type(type), data(data) { }

        std::string toString() const
        {
            std::ostringstream oss;
            oss << *this;
            return oss.str();
        }

        size_t getVertexID() { return id; }
        Node_type getType() { return type; }
        GraphData getData() { return data; }

    private:
        friend std::ostream& operator<<(std::ostream& os, VertexProperty const& v) {
            return os << "id " << v.id << " type " << v.type;
        }

        size_t id;
        Node_type type;
        GraphData data;
    };
}