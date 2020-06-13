#pragma once

#include <boost/graph/adjacency_list.hpp>
#include "GraphVertexProperty.h"    

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::bidirectionalS, Core::VertexProperty> graph_t;
typedef boost::graph_traits<graph_t>::vertex_descriptor vertex_t;
typedef boost::graph_traits<graph_t>::vertex_iterator vertex_iterator;
typedef boost::graph_traits<graph_t>::edge_iterator edge_iterator;
typedef boost::graph_traits<graph_t>::in_edge_iterator in_edge_iterator;
typedef boost::graph_traits<graph_t>::out_edge_iterator out_edge_iterator;

namespace Core
{
    class Graph : public graph_t
    {
    public:
        Graph() { root = 0; lastId = 0; };
        ~Graph() {}

        size_t numberVertices() { return boost::num_vertices(*this); };
        void showVertices(bool listVertices = false);
        size_t numberEdges() { return boost::num_edges(*this); };
        void showEdges(bool listEdges = false);
        //void findPlayer(const std::tuple<std::string, std::string> name);
        //void listRandomTeam();
        //void moveRandomPlayerToRandomTeam();

        // nodes
        // country
        vertex_t addCountry(std::shared_ptr<Country> country, vertex_t nation);
        std::shared_ptr<Country> getCountryById(vertex_t countryId);
        vertex_t getCountryIdByShortname(std::string shortname);
        std::vector<vertex_t> getCountryIds();
        // league
        vertex_t addLeague(std::shared_ptr<League> league, vertex_t countryId);
        std::shared_ptr<League> getLeagueById(vertex_t leagueId);
        std::vector<vertex_t> getLeagueIds();
        std::vector<vertex_t> getLeagueIdsByCountryId(vertex_t countryId);
        vertex_t getLeagueIdByTeamId(vertex_t teamId);
        // team
        vertex_t addTeam(std::shared_ptr<Team> team, vertex_t country, vertex_t nation);
        std::shared_ptr<Team> getTeamById(vertex_t teamId);
        std::vector<vertex_t> getTeamIdsByCountryId(vertex_t countryId);
        // player
        vertex_t addPlayer(std::shared_ptr<Player> player, vertex_t team);
        std::shared_ptr<Player> getPlayerById(vertex_t playerId);
        std::vector<vertex_t> getPlayerIdsByTeamId(vertex_t teamId);
        // nation
        vertex_t addNation(std::shared_ptr<Nation> nation);
        std::shared_ptr<Nation> getNationById(vertex_t nationId);
        std::vector<vertex_t> getNationIds();
        vertex_t getNationIdByIndex(short countryId);
        vertex_t getNationIdByCountryId(vertex_t countryId);
        // other
        vertex_t addUefaRanking(std::shared_ptr<UefaRanking> uefaranking);
        std::shared_ptr<UefaRanking> getUefaRanking();
        vertex_t addEurowinner(std::shared_ptr<Eurowinner> eurowinner);
        std::shared_ptr<Eurowinner> getEurowinner();
        vertex_t addInternational(std::shared_ptr<International> international);
        std::shared_ptr<International> getInternational();

        // special node methods
        std::vector<std::tuple<vertex_t, vertex_t>> getPlayableCountries();
        std::vector<std::tuple<vertex_t, vertex_t>> getCountriesWithLeagues();

    private:
        void setRoot(size_t root) { this->root = root; lastId = root; }

        size_t  root;
        size_t  lastId;
        std::vector<vertex_t> getParentIds(vertex_t vertex);
        std::vector<vertex_t> getParentIds(vertex_t vertex, Node_type type);
        std::vector<vertex_t> getChildIds(vertex_t vertex);
        std::vector<vertex_t> getChildIds(vertex_t vertex, Node_type type);
        std::vector<vertex_t> findVerticesOfType(Node_type type);

        friend class GraphFactory;      // for special case setRoot
    };
}