#include "Graph.h"
#include "RandomNumberGenerator.h"

using namespace Core;

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
/*
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
*/
/*
 * find a random team vertex and print all connected player vertices
 */
/*
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
}*/

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
 * returns a list of all vertex ids of all parents that are connected by in edges of a given vertex and given type
 */
std::vector<vertex_t> Graph::getParentIds(vertex_t vertex, Node_type type)
{
	std::vector<vertex_t> result;

	in_edge_iterator ei, ei_end;
	for (boost::tie(ei, ei_end) = boost::in_edges(vertex, *this); ei != ei_end; ++ei)
	{
		auto node = boost::source(*ei, *this);
		if((*this)[node].getType() == type)
			result.push_back(node);
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
		result.push_back(boost::target(*eo, *this));
	}

	return result;
}

/*
 * returns a list of all vertex ids of all children that are connected by out edges of a given vertex and given type
 */
std::vector<vertex_t> Graph::getChildIds(vertex_t vertex, Node_type type)
{
	std::vector<vertex_t> result;

	out_edge_iterator eo, eo_end;
	for (boost::tie(eo, eo_end) = boost::out_edges(vertex, *this); eo != eo_end; ++eo)
	{
		auto node = boost::target(*eo, *this);
		if((*this)[node].getType() == type)
			result.push_back(node);
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
vertex_t Graph::addCountry(std::shared_ptr<Country> country, vertex_t nation)
{
	vertex_t c = boost::add_vertex(VertexProperty{ ++lastId, Node_type::COUNTRY, country }, *this);
	boost::add_edge(root, c, *this);
	if (nation > 0)
	{
		boost::add_edge(nation, c, *this);
	}
	return c;
}

/*
 * gets country data for a specific country id
 */
std::shared_ptr<Country> Graph::getCountryById(vertex_t countryId)
{
	return std::static_pointer_cast<Country>((*this)[countryId].getData());
}

/*
 * gets countryId for specific shortname (for example AUT)
 */
vertex_t Graph::getCountryIdByShortname(std::string shortname)
{
	auto countryIds = getChildIds(root, Node_type::COUNTRY);
	for (std::vector<vertex_t>::iterator it = countryIds.begin(); it < countryIds.end(); ++it)
	{
		auto nationId = getNationIdByCountryId(*it);
		auto nation = getNationById(nationId);
		if (nation->getShortname() == shortname)
		{
			return *it;
		}
	}
	return 0;	// if nothing found return 0 (=root)
}

/*
 * returns list of all country ids
 */
std::vector<vertex_t> Graph::getCountryIds()
{
	return getChildIds(root, Node_type::COUNTRY);
}

/*
 * adds a new team node to this graph, increments lastId and creates edge from country to team
 */
vertex_t Graph::addTeam(std::shared_ptr<Team> team, vertex_t country, vertex_t nation)
{
	vertex_t t = boost::add_vertex(VertexProperty{ ++lastId, Node_type::TEAM, team }, *this);
	boost::add_edge(country, t, *this);
	if (nation > 0)
	{
		boost::add_edge(nation, t, *this);
	}
	return t;
}

std::shared_ptr<Team> Graph::getTeamById(vertex_t teamId)
{
	return std::static_pointer_cast<Team>((*this)[teamId].getData());
}

std::vector<vertex_t> Graph::getTeamIdsByCountryId(vertex_t countryId)
{
	return getChildIds(countryId, Node_type::TEAM);
}

/*
 * adds a new player node to this graph, increments lastId and creates edge from team to player
 */
vertex_t Graph::addPlayer(std::shared_ptr<Player> player, vertex_t teamId)
{
	vertex_t p = boost::add_vertex(VertexProperty{ ++lastId, Node_type::PLAYER, player }, *this);
	boost::add_edge(teamId, p, *this);
	return p;
}

std::shared_ptr<Player> Graph::getPlayerById(vertex_t playerId)
{
	return std::static_pointer_cast<Player>((*this)[playerId].getData());
}

std::vector<vertex_t> Graph::getPlayerIdsByTeamId(vertex_t teamId)
{
	return getChildIds(teamId, Node_type::PLAYER);
}

/*
 * adds a new league node to this graph, increments lastId and creates edge from country to league
 */
vertex_t Graph::addLeague(std::shared_ptr<League> league, vertex_t countryId)
{
	vertex_t l = boost::add_vertex(VertexProperty{ ++lastId, Node_type::LEAGUE, league }, *this);
	boost::add_edge(countryId, l, *this);
	return l;
}

std::shared_ptr<League> Graph::getLeagueById(vertex_t leagueId)
{
	return std::static_pointer_cast<League>((*this)[leagueId].getData());
}


std::vector<vertex_t> Graph::getLeagueIds()
{
	return findVerticesOfType(Node_type::LEAGUE);
}

/*
 * adds a new nation node to this graph, increments lastId and creates edge from root to nation
 */
vertex_t Graph::addNation(std::shared_ptr<Nation> nation)
{
	vertex_t p = boost::add_vertex(VertexProperty{ ++lastId, Node_type::NATION, nation }, *this);
	boost::add_edge(root, p, *this);
	return p;
}

/*
 * returns list of all country ids
 */
std::vector<vertex_t> Graph::getNationIds()
{
	return getChildIds(root, Node_type::NATION);
}

std::shared_ptr<Nation> Graph::getNationById(vertex_t nationId)
{
	return std::static_pointer_cast<Nation>((*this)[nationId].getData());
}

/*
 * return vertex_t of nation node that has given countryId or -1
 */
vertex_t Graph::getNationIdByIndex(short countryId)
{
	auto nations = getNationIds();
	for (std::vector<vertex_t>::iterator it = nations.begin(); it < nations.end(); ++it)
	{
		auto nation = getNationById(*it);
		if (countryId == nation->getCountryId())
		{
			return *it;
		}
	}

	return -1;
}

vertex_t Graph::getNationIdByCountryId(vertex_t countryId)
{
	auto parents = getParentIds(countryId, Node_type::NATION);
	return parents[0];
}

vertex_t Graph::addEurowinner(std::shared_ptr<Eurowinner> eurowinner)
{
	vertex_t e = boost::add_vertex(VertexProperty{ ++lastId, Node_type::EUROWINNER, eurowinner }, *this);
	boost::add_edge(root, e, *this);
	return e;
}

std::shared_ptr<Eurowinner> Graph::getEurowinner()
{
	auto eurowinnerId = getChildIds(root, Node_type::EUROWINNER);
	return std::static_pointer_cast<Eurowinner>((*this)[eurowinnerId[0]].getData());
}

/*
 * returns tuples of country and nation node ids of all playable countries
 */
std::vector<std::tuple<vertex_t, vertex_t>> Graph::getPlayableCountries()
{
	std::vector<std::tuple<vertex_t, vertex_t>> result;

	auto countries = getCountryIds();
	for (std::vector<vertex_t>::iterator it = countries.begin(); it < countries.end(); ++it)
	{
		auto country = getCountryById(*it);
		if (country->isPlayable())
		{
			std::tuple<vertex_t, vertex_t> countryNation(*it, getNationIdByCountryId(*it));
			result.push_back(countryNation);
		}
	}

	return result;
}

/*
 * returns tuples of country and nation node ids of all counries
 */
std::vector<std::tuple<vertex_t, vertex_t>> Graph::getCountriesWithLeagues()
{
	std::vector<std::tuple<vertex_t, vertex_t>> result;

	auto countries = getCountryIds();
	for (std::vector<vertex_t>::iterator it = countries.begin(); it < countries.end(); ++it)
	{
		std::tuple<vertex_t, vertex_t> countryNation(*it, getNationIdByCountryId(*it));
		result.push_back(countryNation);
	}

	return result;
}