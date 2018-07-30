#ifndef DATA_STRUCTURES_BUILDING_BLOCKS_COMMON_HPP
#define DATA_STRUCTURES_BUILDING_BLOCKS_COMMON_HPP

#include "../common/typedef.hpp"

/************************************************************************
*************************************************************************
Common interface for operating with graph data structures.
*************************************************************************
************************************************************************/

//=======================================================================
// Declarations
//=======================================================================

class GraphDataStructuresBuildingBlocksCommon {
private:
public:
	virtual void show() = 0;
	virtual big_int_t get_size() = 0;
};


/************************************************************************
*************************************************************************
Interface for operations with all types of arrays
*************************************************************************
************************************************************************/

//=======================================================================
// Declarations
//=======================================================================

template<typename data_t>
class Array : public GraphDataStructuresBuildingBlocksCommon {
private:
	big_int_t varNumberOfElementsInArray;
public:
	big_int_t get_number_of_elements();
	void set_number_of_elements(big_int_t varNumOfElements);
	
	virtual data_t get_element_value(big_int_t varElementNumber) = 0;
	virtual void set_element_value(big_int_t varElementNumber, data_t varValue) = 0;
	
	virtual void add_element() = 0;
	virtual void add_elements_range(big_int_t varNumberOfElements) = 0;
	
	virtual void delete_element(big_int_t varPosition) = 0;
	virtual void delete_elements_range(big_int_t varStartPosition, big_int_t varEndPosition) = 0;
};

//=======================================================================
// Implementations
//=======================================================================

template<typename data_t>
big_int_t Array<data_t>::get_number_of_elements()
{
	return varNumberOfElementsInArray;
}

template<typename data_t>
void Array<data_t>::set_number_of_elements(big_int_t varNumOfElements)
{
	varNumberOfElementsInArray = varNumOfElements;
}

#endif