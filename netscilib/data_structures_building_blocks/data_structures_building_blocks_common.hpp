#ifndef DATA_STRUCTURES_BUILDING_BLOCKS_COMMON_HPP
#define DATA_STRUCTURES_BUILDING_BLOCKS_COMMON_HPP

/************************************************************************
*************************************************************************
Common interface for operating with graph data structures.
*************************************************************************
************************************************************************/

//=======================================================================
// Declarations
//=======================================================================

template<typename counter_t>
class GraphDataStructuresBuildingBlocksCommon {
private:
public:
	virtual void show() = 0;
	virtual counter_t get_size() = 0;
};


/************************************************************************
*************************************************************************
Interface for operations with all types of arrays
*************************************************************************
************************************************************************/

//=======================================================================
// Declarations
//=======================================================================

template<typename data_t, typename counter_t>
class Array : public GraphDataStructuresBuildingBlocksCommon<counter_t> {
private:
	counter_t varNumberOfElementsInArray;
public:
	counter_t get_number_of_elements();
	void set_number_of_elements(counter_t varNumOfElements);
	
	virtual data_t get_element_value(counter_t varElementNumber) = 0;
	virtual void set_element_value(counter_t varElementNumber, data_t varValue) = 0;
	
	virtual void add_element() = 0;
	virtual void add_elements_range(counter_t varNumberOfElements) = 0;
	
	virtual void delete_element(counter_t varPosition) = 0;
	virtual void delete_elements_range(counter_t varStartPosition, counter_t varEndPosition) = 0;
};

//=======================================================================
// Implementations
//=======================================================================

template<typename data_t, typename counter_t>
counter_t Array<data_t, counter_t>::get_number_of_elements()
{
	return varNumberOfElementsInArray;
}

template<typename data_t, typename counter_t>
void Array<data_t, counter_t>::set_number_of_elements(counter_t varNumOfElements)
{
	varNumberOfElementsInArray = varNumOfElements;
}

#endif