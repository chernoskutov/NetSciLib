#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <cstring>

#include "../common/typedef.hpp"
#include "data_structures_building_blocks_common.hpp"

/************************************************************************
*************************************************************************
Interface for operations with simple linear array
*************************************************************************
************************************************************************/

//=======================================================================
// Declarations
//=======================================================================

template<typename data_t>
class SimpleArray : public Array<data_t> {
private:
	data_t *ptrArray;
	void resize_array(big_int_t varNewNumberOfElementsInArray);
	void move_chunk(big_int_t varNewPosition, big_int_t varOldPositionStart, big_int_t varOldPositionEnd);
public:
	SimpleArray();
	SimpleArray(big_int_t varNumberOfElementsInArray);

	void show();
	big_int_t get_size();
	
	data_t get_element_value(big_int_t varElementNumber);
	void set_element_value(big_int_t varElementNumber, data_t varValue);
	
	void add_element();
	void add_elements_range(big_int_t varNumberOfElements);
	
	void delete_element(big_int_t varPosition);
	void delete_elements_range(big_int_t varStartPosition, big_int_t varEndPosition);
};

//=======================================================================
// Implementations
//=======================================================================

template <typename data_t>
SimpleArray<data_t>::SimpleArray()
{
	
}

template <typename data_t>
SimpleArray<data_t>::SimpleArray(big_int_t varNumberOfElementsInArray)
{
	ptrArray = new data_t[varNumberOfElementsInArray];
	this -> Array<data_t>::set_number_of_elements(varNumberOfElementsInArray);
}

template <typename data_t>
void SimpleArray<data_t>::show()
{
	for(big_int_t i = 0; i < Array<data_t>::get_number_of_elements(); i++)
	{
		std::cout << get_element_value(i) << " ";
	}
	std::cout << std::endl;
}

template <typename data_t>
big_int_t SimpleArray<data_t>::get_size()
{
	return (sizeof(data_t) * (Array<data_t>::get_number_of_elements()));
}

template <typename data_t>	
data_t SimpleArray<data_t>::get_element_value(big_int_t varElementNumber)
{
	return ptrArray[varElementNumber];	
}

template <typename data_t>
void SimpleArray<data_t>::set_element_value(big_int_t varElementNumber, data_t varValue)
{
	ptrArray[varElementNumber] = varValue;
}

template <typename data_t>
void SimpleArray<data_t>::add_element()
{
	resize_array(Array<data_t>::get_number_of_elements() + 1);
	Array<data_t>::set_number_of_elements(Array<data_t>::get_number_of_elements() + 1);
}

template <typename data_t>
void SimpleArray<data_t>::add_elements_range(big_int_t varNumberOfElements)
{
	resize_array(Array<data_t>::get_number_of_elements() + varNumberOfElements);
	Array<data_t>::set_number_of_elements(Array<data_t>::get_number_of_elements() + varNumberOfElements);
}

template <typename data_t>
void SimpleArray<data_t>::delete_element(big_int_t varPosition)
{
	move_chunk(varPosition, varPosition + 1, Array<data_t>::get_number_of_elements());
	Array<data_t>::set_number_of_elements(Array<data_t>::get_number_of_elements() - 1);
}

template <typename data_t>
void SimpleArray<data_t>::delete_elements_range(big_int_t varStartPosition, big_int_t varEndPosition)
{
	move_chunk(varStartPosition, varEndPosition, Array<data_t>::get_number_of_elements());
	Array<data_t>::set_number_of_elements(Array<data_t>::get_number_of_elements() - (varEndPosition - varStartPosition));
}

template <typename data_t>
void SimpleArray<data_t>::resize_array(big_int_t varNewNumberOfElementsInArray)
{
	ptrArray = (data_t*) realloc(ptrArray, varNewNumberOfElementsInArray * sizeof(data_t));
}

template <typename data_t>
void SimpleArray<data_t>::move_chunk(big_int_t varNewPosition, big_int_t varOldPositionStart, big_int_t varOldPositionEnd)
{
	memmove(&ptrArray[varNewPosition], &ptrArray[varOldPositionStart], (varOldPositionEnd - varOldPositionStart) * sizeof(data_t));
}

#endif