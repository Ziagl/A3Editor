#include "Graph.h"
#include "RandomNumberGenerator.h"

/*
 * this functions outputs the number of vertices from a given graph and optionally a list of all vertices
 */
void Graph::showVertices(bool listVertices)
{
	std::cout << "Number of vertices: " << numberVertices() << std::endl;
	if (listVertices)
	{
		std::pair<vertex_iterator, vertex_iterator> vi = boost::vertices(*this);
		std::cout << "Vertex list:" << std::endl;
		for (vertex_iterator i = vi.first; i != vi.second; ++i)
		{
			std::cout << (*this)[*i].toString() << std::endl;
		}
	}
}

/*
 * this function outputs the number of edges from a given graph and optionally a list of all edges
 */
void Graph::showEdges(bool listEdges)
{
	std::cout << "Number of edges: " << numberEdges() << std::endl;
	if (listEdges)
	{
		std::pair<edge_iterator, edge_iterator> ei = boost::edges(*this);
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
void Graph::findPlayer(const std::tuple<std::string, std::string> name)
{
	vertex_iterator vi, vi_end;
	for (boost::tie(vi, vi_end) = boost::vertices(*this); vi != vi_end; ++vi)
	{
		if ((*this)[*vi].getType() == Node_type::PLAYER)
		{
			GraphData player = (*this)[*vi].getData();
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
				for (boost::tie(ei, ei_end) = boost::in_edges(*vi, *this); ei != ei_end; ++ei)
				{
					vertex_t v_team = boost::source(*ei, *this);
					GraphData team = (*this)[v_team].getData();

					// get league
					in_edge_iterator ei_team, ei_end_team;
					for (boost::tie(ei_team, ei_end_team) = boost::in_edges(v_team, *this); ei_team != ei_end_team; ++ei_team)
					{
						vertex_t v_league = boost::source(*ei_team, *this);
						GraphData league = (*this)[v_league].getData();

						//get country
						in_edge_iterator ei_league, ei_end_league;
						for (boost::tie(ei_league, ei_end_league) = boost::in_edges(v_league, *this); ei_league != ei_end_league; ++ei_league)
						{
							vertex_t v_country = boost::source(*ei_league, *this);
							GraphData country = (*this)[v_country].getData();

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
void Graph::listRandomTeam()
{
	// get all ids of country vertices
	auto countryIds = findVerticesOfType(Node_type::COUNTRY);
	//std::cout << "Found " << countryIds.size() << " countries." << std::endl;

	// choose random country
	int randomCountry = RandomNumberGenerator::randomNumber(0, static_cast<int>(countryIds.size()));
	vertex_t v_country = countryIds[randomCountry];
	GraphData country = (*this)[v_country].getData();

	// get all leagues of random country
	std::vector<vertex_t> leagueIds;
	out_edge_iterator eo, eo_end;
	for (boost::tie(eo, eo_end) = boost::out_edges(v_country, *this); eo != eo_end; ++eo)
	{
		leagueIds.push_back(boost::target(*eo, *this));
	}
	//std::cout << "Found " << leagueIds.size() << " leagues for " << country->toString() << "." << std::endl;

	// choose random league
	int randomLeague = RandomNumberGenerator::randomNumber(0, static_cast<int>(leagueIds.size()));
	vertex_t v_league = leagueIds[randomLeague];
	GraphData league = (*this)[v_league].getData();

	// get all teams for random league
	std::vector<vertex_t> teamIds;
	for (boost::tie(eo, eo_end) = boost::out_edges(v_league, *this); eo != eo_end; ++eo)
	{
		teamIds.push_back(boost::target(*eo, *this));
	}
	//std::cout << "Found " << teamIds.size() << " teams for " << league->toString() << " of " << country->toString() << "." << std::endl;

	// choose random team
	int randomTeam = RandomNumberGenerator::randomNumber(0, static_cast<int>(teamIds.size()));
	vertex_t v_team = teamIds[randomTeam];
	GraphData team = (*this)[v_team].getData();

	// print all players of random team
	std::cout << "List " << team->toString() << " (" << league->toString() << ", " << country->toString() << ")" << std::endl;
	for (boost::tie(eo, eo_end) = boost::out_edges(v_team, *this); eo != eo_end; ++eo)
	{
		vertex_t v_player = boost::target(*eo, *this);
		GraphData player = (*this)[v_player].getData();

		std::cout << "    " << player->toString() << std::endl;
	}
}

void Graph::moveRandomPlayerToRandomTeam()
{
	// get all ids of player vertices
	auto playerIds = findVerticesOfType(Node_type::PLAYER);
	// get all ids of team vertices
	auto teamIds = findVerticesOfType(Node_type::TEAM);

	// choose random player to change team
	int randomPlayer = RandomNumberGenerator::randomNumber(0, static_cast<int>(playerIds.size()));
	vertex_t v_player = playerIds[randomPlayer];
	GraphData player = (*this)[v_player].getData();

	// choose random new team for player
	int randomTeam = RandomNumberGenerator::randomNumber(0, static_cast<int>(teamIds.size()));
	vertex_t v_team_new = teamIds[randomTeam];
	GraphData team_new = (*this)[v_team_new].getData();

	vertex_t v_team_old = getParentIds(v_player)[0];
	GraphData team_old = (*this)[v_team_old].getData();
	vertex_t v_league_old = getParentIds(v_team_old)[0];
	GraphData league_old = (*this)[v_league_old].getData();
	vertex_t v_country_old = getParentIds(v_league_old)[0];
	GraphData country_old = (*this)[v_country_old].getData();
	std::cout << "Move Player " << player->toString() << " from " << team_old->toString() << " (" << league_old->toString() << ", " << country_old->toString() << ") to ";

	vertex_t v_league_new = getParentIds(v_team_new)[0];
	GraphData league_new = (*this)[v_league_new].getData();
	vertex_t v_country_new = getParentIds(v_league_new)[0];
	GraphData country_new = (*this)[v_country_new].getData();
	std::cout << team_new->toString() << " (" << league_new->toString() << ", " << country_new->toString() << ")" << std::endl;

	// remove edge to old team and link player to new team
	boost::remove_edge(v_team_old, v_player, *this);
	boost::add_edge(v_team_new, v_player, *this);

	// print players for both teams
	std::cout << "List old " << team_old->toString() << " (" << league_old->toString() << ", " << country_old->toString() << ")" << std::endl;
	out_edge_iterator eo, eo_end;
	for (boost::tie(eo, eo_end) = boost::out_edges(v_team_old, *this); eo != eo_end; ++eo)
	{
		vertex_t v_player = boost::target(*eo, *this);
		GraphData player = (*this)[v_player].getData();

		std::cout << "    " << player->toString() << std::endl;
	}

	std::cout << "List new " << team_new->toString() << " (" << league_new->toString() << ", " << country_new->toString() << ")" << std::endl;
	for (boost::tie(eo, eo_end) = boost::out_edges(v_team_new, *this); eo != eo_end; ++eo)
	{
		vertex_t v_player = boost::target(*eo, *this);
		GraphData player = (*this)[v_player].getData();

		std::cout << "    " << player->toString() << std::endl;
	}
}

/*
 * returns a list of all vertex ids of all parents that are connected by in edges of a given vertex
 */
std::vector<vertex_t> Graph::getParentIds(vertex_t vertex)
{
	std::vector<vertex_t> result;

	in_edge_iterator ei, ei_end;
	for (boost::tie(ei, ei_end) = boost::in_edges(vertex, *this); ei != ei_end; ++ei)
	{
		result.push_back(boost::source(*ei, *this));
	}

	return result;
}

/*
 * returns a list of all vertex ids of all children that are connected by out edges of a given vertex
 */
std::vector<vertex_t> Graph::getChildIds(vertex_t vertex)
{
	std::vector<vertex_t> result;

	out_edge_iterator eo, eo_end;
	for (boost::tie(eo, eo_end) = boost::out_edges(vertex, *this); eo != eo_end; ++eo)
	{
		result.push_back(boost::source(*eo, *this));
	}

	return result;
}

/*
 * loop whole given graph and return all vertex_t from given type
 */
std::vector<vertex_t> Graph::findVerticesOfType(Node_type type)
{
	std::vector<vertex_t> result;

	vertex_iterator vi, vi_end;
	for (boost::tie(vi, vi_end) = boost::vertices(*this); vi != vi_end; ++vi)
	{
		if ((*this)[*vi].getType() == type)
		{
			result.push_back(*vi);
		}
	}

	return result;
}

/*
 * adds a new country node to this graph, increments lastId and creates edge from root to country
 */
vertex_t Graph::addCountry(std::shared_ptr<Country> country)
{
	auto graphCountry = std::static_pointer_cast<GraphCountry>(country);
	vertex_t c = boost::add_vertex(VertexProperty{ ++lastId, Node_type::COUNTRY, graphCountry }, *this);
	boost::add_edge(root, c, *this);
	return c;
}

/*
 * gets all countries from graph
 */
std::vector<vertex_t> Graph::getCountries()
{
	return getChildIds(root);
}

/*
 * adds a new team node to this graph, increments lastId and creates edge from country to team
 */
vertex_t Graph::addTeam(std::shared_ptr<Team> team, vertex_t country)
{
	auto graphTeam = std::static_pointer_cast<GraphTeam>(team);
	vertex_t t = boost::add_vertex(VertexProperty{ ++lastId, Node_type::TEAM, graphTeam }, *this);
	boost::add_edge(country, t, *this);
	return t;
}

/*
 * adds a new player node to this graph, increments lastId and creates edge from team to player
 */
vertex_t Graph::addPlayer(std::shared_ptr<Player> player, vertex_t team)
{
	auto graphPlayer = std::static_pointer_cast<GraphPlayer>(player);
	vertex_t p = boost::add_vertex(VertexProperty{ ++lastId, Node_type::PLAYER, graphPlayer }, *this);
	boost::add_edge(team, p, *this);
	return p;
}