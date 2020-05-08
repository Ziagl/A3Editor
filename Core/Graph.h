#pragma once

#include "boost/graph/adjacency_list.hpp"

#include "GraphVertexProperty.h"

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::bidirectionalS, VertexProperty> Graph;
typedef boost::graph_traits<Graph>::vertex_descriptor vertex_t;
typedef boost::graph_traits<Graph>::vertex_iterator vertex_iterator;
typedef boost::graph_traits<Graph>::edge_iterator edge_iterator;
typedef boost::graph_traits<Graph>::in_edge_iterator in_edge_iterator;
typedef boost::graph_traits<Graph>::out_edge_iterator out_edge_iterator;

class GraphFactory
{
public:
    static Graph create();
    static void showVertices(const Graph& g, bool listVertices = false);
    static void showEdges(const Graph& g, bool listEdges = false);
    static void findPlayer(Graph& g, const std::tuple<std::string, std::string> name);
    static void listRandomTeam(Graph& g);
    static void moveRandomPlayerToRandomTeam(Graph& g);

private:
    static std::vector<vertex_t> getParentIds(Graph& g, vertex_t vertex);
    static std::vector<vertex_t> getChildIds(Graph& g, vertex_t vertex);
    static std::vector<vertex_t> findVerticesOfType(Graph& g, Node_type type);
};