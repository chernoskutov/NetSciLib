#ifndef DATA_STRUCTURES_COMMON_HPP
#define DATA_STRUCTURES_COMMON_HPP

#include <vector>

/************************************************************************
*************************************************************************
Common interface for operating with graph data structures.
*************************************************************************
************************************************************************/

//=======================================================================
// Declarations
//=======================================================================

template<typename counter_t, typename weight_t>
class GraphDataStructureCommon {
private:
	bool varDirected, varDirectednessTypeIsUnknown;
	bool varWeighted;
	
	bool varParallelEdges, varParallelEdgesPresenceIsUnknown;
	bool varSelfLoops, varSelfLoopsPresenceIsUnknown;
	bool varHyperEdges, varHyperEdgesPresenceIsUnknown;
	
	bool varModified;
	
	bool varVerboseOutput;
	
	counter_t varNumberOfNodes;
	counter_t varNumberOfEdges;
	
	void set_default();	
	
public:
	GraphDataStructureCommon() {}
	~GraphDataStructureCommon() {}
	
	void set_number_of_nodes(counter_t _varNumberOfNodes);
	void set_number_of_edges(counter_t _varNumberOfEdges);
	
	void update_number_of_nodes(counter_t varDifference);
	void update_number_of_edges(counter_t varDifference);
	
	void set_directed_value(bool _varDirected);
	void set_weighted_value(bool _varWeighted);
	
	bool is_directed();
	bool is_weighted();
	
	bool directedness_type_is_unknown();
	
	bool is_parallel_edges_allowed();
	bool is_self_loops_edges_allowed();
	bool is_hyper_edges_allowed();		
	
	counter_t get_number_of_nodes();	
	counter_t get_number_of_edges();
	
	virtual void set_directed() = 0;
	virtual void set_undirected() = 0;
	virtual void set_weighted() = 0;
	virtual void set_unweighted() = 0;
	
	virtual bool has_node(counter_t varU) = 0;
	virtual bool has_edge(counter_t varU, counter_t varV) = 0;
	
	virtual weight_t get_edge_weight(counter_t varU, counter_t varV) = 0;
	virtual void set_edge_weight(counter_t varU, counter_t varV, weight_t w) = 0;
	
	virtual void get_ingoing_neighbors(counter_t varV, std::vector<counter_t> *ptrIngoingNeighbors) = 0;
	virtual void get_outgoing_neighbors(counter_t varV, std::vector<counter_t> *ptrOutgoingNeighbors) = 0;
	
	virtual void add_node() = 0;
	virtual void add_nodes(counter_t varNumberOfNodesToAdd) = 0;
	virtual void delete_node(counter_t varU) = 0;	
	virtual void add_edge(counter_t varU, counter_t varV) = 0;
	virtual void delete_edge(counter_t varU, counter_t varV) = 0;
	
	//void show_graph_info(bool varShowGraphStructure);
	virtual void show_graph() = 0;
};

//=======================================================================
// Implementations
//=======================================================================

template<typename counter_t, typename weight_t>
void GraphDataStructureCommon<counter_t, weight_t>::set_default()
{
	
}

template<typename counter_t, typename weight_t>
void GraphDataStructureCommon<counter_t, weight_t>::set_number_of_nodes(counter_t _varNumberOfNodes)
{
	varNumberOfNodes = _varNumberOfNodes;
}

template<typename counter_t, typename weight_t>
void GraphDataStructureCommon<counter_t, weight_t>::set_number_of_edges(counter_t _varNumberOfEdges)
{
	varNumberOfEdges = _varNumberOfEdges;
}

template<typename counter_t, typename weight_t>
void GraphDataStructureCommon<counter_t, weight_t>::update_number_of_nodes(counter_t varDifference)
{
	varNumberOfNodes += varDifference;
}

template<typename counter_t, typename weight_t>
void GraphDataStructureCommon<counter_t, weight_t>::update_number_of_edges(counter_t varDifference)
{
	varNumberOfEdges += varDifference;
}

template<typename counter_t, typename weight_t>
void GraphDataStructureCommon<counter_t, weight_t>::set_directed_value(bool _varDirected)
{
	varDirected = _varDirected;
}

template<typename counter_t, typename weight_t>
void GraphDataStructureCommon<counter_t, weight_t>::set_weighted_value(bool _varWeighted)
{
	varWeighted = _varWeighted;
}

template<typename counter_t, typename weight_t>
bool GraphDataStructureCommon<counter_t, weight_t>::is_directed()
{
	return varDirected;
	/*if(!directedness_type_is_unknown())
	{
		return varDirected;
	}
	else
	{
		// To do...
	}*/
}

template<typename counter_t, typename weight_t>
bool GraphDataStructureCommon<counter_t, weight_t>::is_weighted()
{
	return varWeighted;
}

template<typename counter_t, typename weight_t>
bool GraphDataStructureCommon<counter_t, weight_t>::directedness_type_is_unknown()
{
	return varDirectednessTypeIsUnknown;
}

template<typename counter_t, typename weight_t>
bool GraphDataStructureCommon<counter_t, weight_t>::is_parallel_edges_allowed()
{
	return varParallelEdges;
}

template<typename counter_t, typename weight_t>
bool GraphDataStructureCommon<counter_t, weight_t>::is_self_loops_edges_allowed()
{
	return varSelfLoops;
}

template<typename counter_t, typename weight_t>
bool GraphDataStructureCommon<counter_t, weight_t>::is_hyper_edges_allowed()
{
	return varHyperEdges;
}
	
template<typename counter_t, typename weight_t>
counter_t GraphDataStructureCommon<counter_t, weight_t>::get_number_of_nodes()
{
	return varNumberOfNodes;
}

template<typename counter_t, typename weight_t>
counter_t GraphDataStructureCommon<counter_t, weight_t>::get_number_of_edges()
{
	return varNumberOfEdges;
}

#endif