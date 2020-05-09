#pragma once

#include "Graph.h"


class GraphFactory
{
public:
    /*
     * create an empty graph
     */
    static auto create() 
    {
        auto g = std::make_shared<Graph>();

        int id = 0;		// id of root is always 0
        auto root = boost::add_vertex(VertexProperty{ id, Node_type::UNKNOWN, nullptr }, *g);

        return g;
    };
};