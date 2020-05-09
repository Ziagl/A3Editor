#pragma once

#include "boost/graph/adjacency_list.hpp"

#include "GraphVertexProperty.h"

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::bidirectionalS, VertexProperty> graph_t;
typedef boost::graph_traits<graph_t>::vertex_descriptor vertex_t;
typedef boost::graph_traits<graph_t>::vertex_iterator vertex_iterator;
typedef boost::graph_traits<graph_t>::edge_iterator edge_iterator;
typedef boost::graph_traits<graph_t>::in_edge_iterator in_edge_iterator;
typedef boost::graph_traits<graph_t>::out_edge_iterator out_edge_iterator;

class Graph : public graph_t
{
public:
    size_t numberVertices() { return boost::num_vertices(*this); };
    void showVertices(bool listVertices = false);
    size_t numberEdges() { return boost::num_edges(*this); };
    void showEdges(bool listEdges = false);
    void findPlayer(const std::tuple<std::string, std::string> name);
    void listRandomTeam();
    void moveRandomPlayerToRandomTeam();

private:
    std::vector<vertex_t> getParentIds(vertex_t vertex);
    std::vector<vertex_t> getChildIds(vertex_t vertex);
    std::vector<vertex_t> findVerticesOfType(Node_type type);
};