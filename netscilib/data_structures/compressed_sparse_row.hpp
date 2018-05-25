#ifndef COMRESSED_SPARSE_ROW_HPP
#define COMRESSED_SPARSE_ROW_HPP

#include <iostream>
#include <vector>

#include "data_structures_common.hpp"

/************************************************************************
*************************************************************************
Common interface for operating with compressed sparse row
graph data structure.
*************************************************************************
************************************************************************/

//=======================================================================
// Declarations
//=======================================================================

template<typename counter_t, typename weight_t, class csr_t, class graph_data_t>
class CompressedSparseRow : public GraphDataStructureCommon<counter_t, weight_t> {
private:
	csr_t *ptrRowstarts;
	csr_t *ptrColumnIds;
	graph_data_t *ptrWeight;

public:
	CompressedSparseRow() {}
	CompressedSparseRow(bool varDirected,
						bool varWeighted,
						counter_t varNumberOfNodes,
						counter_t varNumberOfEdges,
						std::vector<counter_t> objRowstarts,
						std::vector<counter_t> objColumnIds,
						std::vector<weight_t> objWeight);
	
	void set_directed();
	void set_undirected();
	void set_weighted();
	void set_unweighted();
	
	bool has_node(counter_t varU);
	bool has_edge(counter_t varU, counter_t varV);
	
	weight_t get_edge_weight(counter_t varU, counter_t varV);
	void set_edge_weight(counter_t varU, counter_t varV, weight_t w);
	
	void get_ingoing_neighbors(counter_t varV, std::vector<counter_t> *ptrIngoingNeighbors);
	void get_outgoing_neighbors(counter_t varV, std::vector<counter_t> *ptrOutgoingNeighbors);
	
	void add_node();
	void add_nodes(counter_t varNumberOfNodesToAdd);
	void delete_node(counter_t varU);	
	void add_edge(counter_t varU, counter_t varV);
	void delete_edge(counter_t varU, counter_t varV);
	
	//void show_graph_info(bool varShowGraphStructure);
	void show_graph();
};

//=======================================================================
// Implementations
//=======================================================================

template<typename counter_t, typename weight_t, class csr_t, class graph_data_t>
CompressedSparseRow<counter_t, weight_t, csr_t, graph_data_t>::CompressedSparseRow(	bool varDirected,
																					bool varWeighted,
																					counter_t varNumberOfNodes,
																					counter_t varNumberOfEdges,
																					std::vector<counter_t> objRowstarts,
																					std::vector<counter_t> objColumnIds,
																					std::vector<weight_t> objWeight)
{
	GraphDataStructureCommon<counter_t, weight_t>::set_directed_value(varDirected);
	GraphDataStructureCommon<counter_t, weight_t>::set_weighted_value(varWeighted);
	
	GraphDataStructureCommon<counter_t, weight_t>::set_number_of_nodes(varNumberOfNodes);
	GraphDataStructureCommon<counter_t, weight_t>::set_number_of_edges(varNumberOfEdges);
	
	counter_t _varNumberOfEdges;
	if(varDirected)
	{
		_varNumberOfEdges = varNumberOfEdges;
	}
	else
	{
		_varNumberOfEdges = varNumberOfEdges * 2;
	}
	
	ptrRowstarts = new csr_t(varNumberOfNodes + 1);
	ptrColumnIds = new csr_t(_varNumberOfEdges);
	if(varWeighted)
	{
		ptrWeight = new graph_data_t(_varNumberOfEdges);
	}
	
	for(counter_t i = 0; i < objRowstarts.size(); i++)
	{
		(*ptrRowstarts).set_element_value(i, objRowstarts[i]);
	}
	for(counter_t i = 0; i < objColumnIds.size(); i++)
	{
		(*ptrColumnIds).set_element_value(i, objColumnIds[i]);
	}
	if(varWeighted)
	{
		for(counter_t i = 0; i < objWeight.size(); i++)
		{
			(*ptrWeight).set_element_value(i, objWeight[i]);
		}
	}
	
	//std::cout << (*ptrRowstarts).get_size() << std::endl;
	//std::cout << (*ptrColumnIds).get_size() << std::endl;
	//std::cout << (*ptrWeight).get_size() << std::endl;
	
	//(*ptrRowstarts).show();
	//(*ptrColumnIds).show();
	//(*ptrWeight).show();
}

template<typename counter_t, typename weight_t, class csr_t, class graph_data_t>											
void CompressedSparseRow<counter_t, weight_t, csr_t, graph_data_t>::set_directed()
{
	
}

template<typename counter_t, typename weight_t, class csr_t, class graph_data_t>
void CompressedSparseRow<counter_t, weight_t, csr_t, graph_data_t>::set_undirected()
{
	
}

template<typename counter_t, typename weight_t, class csr_t, class graph_data_t>
void CompressedSparseRow<counter_t, weight_t, csr_t, graph_data_t>::set_weighted()
{
	
}

template<typename counter_t, typename weight_t, class csr_t, class graph_data_t>
void CompressedSparseRow<counter_t, weight_t, csr_t, graph_data_t>::set_unweighted()
{
	
}

template<typename counter_t, typename weight_t, class csr_t, class graph_data_t>
bool CompressedSparseRow<counter_t, weight_t, csr_t, graph_data_t>::has_node(counter_t varU)
{
	
}

template<typename counter_t, typename weight_t, class csr_t, class graph_data_t>
bool CompressedSparseRow<counter_t, weight_t, csr_t, graph_data_t>::has_edge(counter_t varU, counter_t varV)
{
	
}

template<typename counter_t, typename weight_t, class csr_t, class graph_data_t>
weight_t CompressedSparseRow<counter_t, weight_t, csr_t, graph_data_t>::get_edge_weight(counter_t varU, counter_t varV)
{
	for(int i = (*ptrRowstarts).get_element_value(varU); i < (*ptrRowstarts).get_element_value(varU + 1); i++)
	{
		counter_t _varV = (*ptrColumnIds).get_element_value(i);
		if(_varV == varV)
		{
			return (*ptrWeight).get_element_value(i);
		}
	}
}

template<typename counter_t, typename weight_t, class csr_t, class graph_data_t>
void CompressedSparseRow<counter_t, weight_t, csr_t, graph_data_t>::set_edge_weight(counter_t varU, counter_t varV, weight_t w)
{
	
}

template<typename counter_t, typename weight_t, class csr_t, class graph_data_t>
void CompressedSparseRow<counter_t, weight_t, csr_t, graph_data_t>::get_ingoing_neighbors(counter_t varV, std::vector<counter_t> *ptrIngoingNeighbors)
{
	
}

template<typename counter_t, typename weight_t, class csr_t, class graph_data_t>
void CompressedSparseRow<counter_t, weight_t, csr_t, graph_data_t>::get_outgoing_neighbors(counter_t varV, std::vector<counter_t> *ptrOutgoingNeighbors)
{
	if((*ptrOutgoingNeighbors).size() > 0)
	{
		(*ptrOutgoingNeighbors).clear();
	}
	
	for(int i = (*ptrRowstarts).get_element_value(varV); i < (*ptrRowstarts).get_element_value(varV + 1); i++)
	{
		(*ptrOutgoingNeighbors).push_back((counter_t) (*ptrColumnIds).get_element_value(i));
	}
}

template<typename counter_t, typename weight_t, class csr_t, class graph_data_t>
void CompressedSparseRow<counter_t, weight_t, csr_t, graph_data_t>::add_node()
{
	
}

template<typename counter_t, typename weight_t, class csr_t, class graph_data_t>
void CompressedSparseRow<counter_t, weight_t, csr_t, graph_data_t>::add_nodes(counter_t varNumberOfNodesToAdd)
{
	
}

template<typename counter_t, typename weight_t, class csr_t, class graph_data_t>
void CompressedSparseRow<counter_t, weight_t, csr_t, graph_data_t>::delete_node(counter_t varU)
{
	
}

template<typename counter_t, typename weight_t, class csr_t, class graph_data_t>
void CompressedSparseRow<counter_t, weight_t, csr_t, graph_data_t>::add_edge(counter_t varU, counter_t varV)
{
	
}

template<typename counter_t, typename weight_t, class csr_t, class graph_data_t>
void CompressedSparseRow<counter_t, weight_t, csr_t, graph_data_t>::delete_edge(counter_t varU, counter_t varV)
{
	
}

template<typename counter_t, typename weight_t, class csr_t, class graph_data_t>
void CompressedSparseRow<counter_t, weight_t, csr_t, graph_data_t>::show_graph()
{
	counter_t varNumOfNodes = GraphDataStructureCommon<counter_t, weight_t>::get_number_of_nodes();
	bool varWeighted = GraphDataStructureCommon<counter_t, weight_t>::is_weighted();
	std::vector<counter_t> neighb;
	
	for(counter_t i = 0; i < varNumOfNodes; i++)
	{
		std::cout << "Edges of " << i << " node:";
		neighb.clear();
		get_outgoing_neighbors(i, &neighb);
		for(counter_t j = 0; j < neighb.size(); j++)
		{
			std::cout << " " << neighb[j];
			if(varWeighted)
			{
				std::cout << " (" << get_edge_weight(i, neighb[j]) << ")";
			}
		}
		std::cout << std::endl;
	}
}

#endif