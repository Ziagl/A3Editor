#include "Graph.h"
#include "RandomNumberGenerator.h"

/*
 * create an empty graph
 */
Graph GraphFactory::create()
{
	Graph g;

	int id = 0;		// id of root is always 0
	auto root = boost::add_vertex(VertexProperty{ id, Node_type::UNKNOWN, nullptr }, g);

	return g;
}

/*
 * this functions outputs the number of vertices from a given graph and optionally a list of all vertices
 */
void GraphFactory::showVertices(const Graph& g, bool listVertices)
{
	std::pair<vertex_iterator, vertex_iterator> vi = boost::vertices(g);
	std::cout << "Number of vertices: " << boost::num_vertices(g) << std::endl;
	if (listVertices)
	{
		std::cout << "Vertex list:" << std::endl;
		for (vertex_iterator i = vi.first; i != vi.second; ++i)
		{
			std::cout << g[*i].toString() << std::endl;
		}
	}
}

/*
 * this function outputs the number of edges from a given graph and optionally a list of all edges
 */
void GraphFactory::showEdges(const Graph& g, bool listEdges)
{
	std::pair<edge_iterator, edge_iterator> ei = boost::edges(g);
	std::cout << "Number of edges: " << boost::num_edges(g) << std::endl;
	if (listEdges)
	{
		std::cout << "Edge list: " << std::endl;
		for (edge_iterator it = ei.first; it != ei.second; ++it)
		{
			std::cout << *it << std::endl;
		}
	}
}

/*
 * this function is used to find all players in given graph with same lastname as given name tuple
 */
void GraphFactory::findPlayer(Graph& g, const std::tuple<std::string, std::string> name)
{
	vertex_iterator vi, vi_end;
	for (boost::tie(vi, vi_end) = boost::vertices(g); vi != vi_end; ++vi)
	{
		if (g[*vi].getType() == Node_type::PLAYER)
		{
			GraphData player = g[*vi].getData();
			// split name into firstname and lastname
			std::string fullname = player->toString();
			std::vector<std::string> names;
			std::istringstream ss(fullname);
			std::string s;
			while (std::getline(ss, s, ' '))
			{
				names.push_back(s);
			}
			// check player lastname
			if (names.size() == 2 && names[1] == std::get<1>(name))
			{
				// now traverse graph to top by in edges
				// get team
				in_edge_iterator ei, ei_end;
				for (boost::tie(ei, ei_end) = boost::in_edges(*vi, g); ei != ei_end; ++ei)
				{
					vertex_t v_team = boost::source(*ei, g);
					GraphData team = g[v_team].getData();

					// get league
					in_edge_iterator ei_team, ei_end_team;
					for (boost::tie(ei_team, ei_end_team) = boost::in_edges(v_team, g); ei_team != ei_end_team; ++ei_team)
					{
						vertex_t v_league = boost::source(*ei_team, g);
						GraphData league = g[v_league].getData();

						//get country
						in_edge_iterator ei_league, ei_end_league;
						for (boost::tie(ei_league, ei_end_league) = boost::in_edges(v_league, g); ei_league != ei_end_league; ++ei_league)
						{
							vertex_t v_country = boost::source(*ei_league, g);
							GraphData country = g[v_country].getData();

							// print full data
							std::cout << "    " << player->toString() << " (" << team->toString() << ", " << league->toString() << ", " << country->toString() << ")" << std::endl;
						}
					}
				}
			}
		}
	}
}

/*
 * find a random team vertex and print all connected player vertices
 */
void GraphFactory::listRandomTeam(Graph& g)
{
	// get all ids of country vertices
	auto countryIds = GraphFactory::findVerticesOfType(g, Node_type::COUNTRY);
	//std::cout << "Found " << countryIds.size() << " countries." << std::endl;

	// choose random country
	int randomCountry = RandomNumberGenerator::randomNumber(0, static_cast<int>(countryIds.size()));
	vertex_t v_country = countryIds[randomCountry];
	GraphData country = g[v_country].getData();

	// get all leagues of random country
	std::vector<vertex_t> leagueIds;
	out_edge_iterator eo, eo_end;
	for (boost::tie(eo, eo_end) = boost::out_edges(v_country, g); eo != eo_end; ++eo)
	{
		leagueIds.push_back(boost::target(*eo, g));
	}
	//std::cout << "Found " << leagueIds.size() << " leagues for " << country->toString() << "." << std::endl;

	// choose random league
	int randomLeague = RandomNumberGenerator::randomNumber(0, static_cast<int>(leagueIds.size()));
	vertex_t v_league = leagueIds[randomLeague];
	GraphData league = g[v_league].getData();

	// get all teams for random league
	std::vector<vertex_t> teamIds;
	for (boost::tie(eo, eo_end) = boost::out_edges(v_league, g); eo != eo_end; ++eo)
	{
		teamIds.push_back(boost::target(*eo, g));
	}
	//std::cout << "Found " << teamIds.size() << " teams for " << league->toString() << " of " << country->toString() << "." << std::endl;

	// choose random team
	int randomTeam = RandomNumberGenerator::randomNumber(0, static_cast<int>(teamIds.size()));
	vertex_t v_team = teamIds[randomTeam];
	GraphData team = g[v_team].getData();

	// print all players of random team
	std::cout << "List " << team->toString() << " (" << league->toString() << ", " << country->toString() << ")" << std::endl;
	for (boost::tie(eo, eo_end) = boost::out_edges(v_team, g); eo != eo_end; ++eo)
	{
		vertex_t v_player = boost::target(*eo, g);
		GraphData player = g[v_player].getData();

		std::cout << "    " << player->toString() << std::endl;
	}
}

void GraphFactory::moveRandomPlayerToRandomTeam(Graph& g)
{
	// get all ids of player vertices
	auto playerIds = GraphFactory::findVerticesOfType(g, Node_type::PLAYER);
	// get all ids of team vertices
	auto teamIds = GraphFactory::findVerticesOfType(g, Node_type::TEAM);

	// choose random player to change team
	int randomPlayer = RandomNumberGenerator::randomNumber(0, static_cast<int>(playerIds.size()));
	vertex_t v_player = playerIds[randomPlayer];
	GraphData player = g[v_player].getData();

	// choose random new team for player
	int randomTeam = RandomNumberGenerator::randomNumber(0, static_cast<int>(teamIds.size()));
	vertex_t v_team_new = teamIds[randomTeam];
	GraphData team_new = g[v_team_new].getData();

	vertex_t v_team_old = GraphFactory::getParentIds(g, v_player)[0];
	GraphData team_old = g[v_team_old].getData();
	vertex_t v_league_old = GraphFactory::getParentIds(g, v_team_old)[0];
	GraphData league_old = g[v_league_old].getData();
	vertex_t v_country_old = GraphFactory::getParentIds(g, v_league_old)[0];
	GraphData country_old = g[v_country_old].getData();
	std::cout << "Move Player " << player->toString() << " from " << team_old->toString() << " (" << league_old->toString() << ", " << country_old->toString() << ") to ";

	vertex_t v_league_new = GraphFactory::getParentIds(g, v_team_new)[0];
	GraphData league_new = g[v_league_new].getData();
	vertex_t v_country_new = GraphFactory::getParentIds(g, v_league_new)[0];
	GraphData country_new = g[v_country_new].getData();
	std::cout << team_new->toString() << " (" << league_new->toString() << ", " << country_new->toString() << ")" << std::endl;

	// remove edge to old team and link player to new team
	boost::remove_edge(v_team_old, v_player, g);
	boost::add_edge(v_team_new, v_player, g);

	// print players for both teams
	std::cout << "List old " << team_old->toString() << " (" << league_old->toString() << ", " << country_old->toString() << ")" << std::endl;
	out_edge_iterator eo, eo_end;
	for (boost::tie(eo, eo_end) = boost::out_edges(v_team_old, g); eo != eo_end; ++eo)
	{
		vertex_t v_player = boost::target(*eo, g);
		GraphData player = g[v_player].getData();

		std::cout << "    " << player->toString() << std::endl;
	}

	std::cout << "List new " << team_new->toString() << " (" << league_new->toString() << ", " << country_new->toString() << ")" << std::endl;
	for (boost::tie(eo, eo_end) = boost::out_edges(v_team_new, g); eo != eo_end; ++eo)
	{
		vertex_t v_player = boost::target(*eo, g);
		GraphData player = g[v_player].getData();

		std::cout << "    " << player->toString() << std::endl;
	}
}

/*
 * returns a list of all vertex ids of all parents that are connected by in edges of a given vertex
 */
std::vector<vertex_t> GraphFactory::getParentIds(Graph& g, vertex_t vertex)
{
	std::vector<vertex_t> result;

	in_edge_iterator ei, ei_end;
	for (boost::tie(ei, ei_end) = boost::in_edges(vertex, g); ei != ei_end; ++ei)
	{
		result.push_back(boost::source(*ei, g));
	}

	return result;
}

/*
 * returns a list of all vertex ids of all children that are connected by out edges of a given vertex
 */
std::vector<vertex_t> GraphFactory::getChildIds(Graph& g, vertex_t vertex)
{
	std::vector<vertex_t> result;

	out_edge_iterator eo, eo_end;
	for (boost::tie(eo, eo_end) = boost::out_edges(vertex, g); eo != eo_end; ++eo)
	{
		result.push_back(boost::source(*eo, g));
	}

	return result;
}

/*
 * loop whole given graph and return all vertex_t from given type
 */
std::vector<vertex_t> GraphFactory::findVerticesOfType(Graph& g, Node_type type)
{
	std::vector<vertex_t> result;

	vertex_iterator vi, vi_end;
	for (boost::tie(vi, vi_end) = boost::vertices(g); vi != vi_end; ++vi)
	{
		if (g[*vi].getType() == type)
		{
			result.push_back(*vi);
		}
	}

	return result;
}