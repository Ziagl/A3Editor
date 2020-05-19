#pragma once

#include "Graph.h"

namespace Core
{
    class GraphFactory
    {
    public:
        /*
         * create an empty graph
         */
        static auto create()
        {
            auto g = std::make_shared<Graph>();

            // id of root is always 0
            auto root = boost::add_vertex(VertexProperty{ 0, Node_type::UNKNOWN, nullptr }, *g);
            g->setRoot(root);   // the graph needs to remember one thing....its root node

            return g;
        };
    };
}