#include <iostream>

#include "../../netscilib/common/typedef.hpp"
#include "../../netscilib/data_structures_building_blocks/data_structures_building_blocks_common.hpp"
#include "../../netscilib/data_structures_building_blocks/array.hpp"

int main()
{
	int num_of_elem = 10;
	SimpleArray<float> objArray(num_of_elem);
	
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
	objArray.show();
	
	return 0;
}