#include <iostream>
#include <vector>

#include "../../netscilib/data_structures_building_blocks/data_structures_building_blocks_common.hpp"
#include "../../netscilib/data_structures_building_blocks/array.hpp"

#include "../../netscilib/data_structures/data_structures_common.hpp"
#include "../../netscilib/data_structures/compressed_sparse_row.hpp"

int main()
{
	/*int num_of_elem = 10;
	SimpleArray<float, int> objArray(num_of_elem);
	
	std::cout << objArray.get_number_of_elements() << std::endl;
	
	for(int i = 0; i < num_of_elem; i++)
	{
		objArray.set_element_value(i, i * 0.5);
	}
	
	objArray.show();
	
	objArray.delete_element(5);
	objArray.show();
	
	objArray.delete_element(0);
	objArray.show();
	
	objArray.delete_element(objArray.get_number_of_elements() - 1);
	objArray.show();*/
	
	bool directed = false;
	bool weighted = true;
	
	int num_of_nodes = 7;
	int num_of_edges = 9;
	
	std::vector<int> rowstarts = {0, 3, 5, 7, 12, 15, 16, 18};
	std::vector<int> column_ids = {1, 2, 3, 0, 3, 0, 3, 0, 1, 2, 4, 6, 3, 5, 6, 4, 3, 4};
	std::vector<float> weights = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 0.10, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18};
	
	CompressedSparseRow<int, float, SimpleArray<int, int>, SimpleArray<double, int>> csr(directed, weighted, num_of_nodes, num_of_edges, rowstarts, column_ids, weights);
	
	csr.show_graph();
	
	return 0;
}