//DataType.cpp
#include <iostream>
#include <fstream>
#include <string>
#include "DataType.h"

/**
 * default constructor
 */
DataType::DataType()
{
    value = 0; //not sure if this value is correct
}//DataType

/**
 * constructor
 */
DataType::DataType(int newValue)
{
    value = newValue;
}//DataType

/**
 * initializes DataType object with newValue
 */
void DataType::initialize(int newValue)
{
    value = newValue;
}//initialize

/**
 * implementation of the fucntion that compares two items and returns
* one of the values (GREATER,LESS,EQUAL) depending on the relationship
 */
Comparison DataType::compareTo(DataType &item)
{
  //compares value and item.value to determine if target is LESS
  if(value < item.value)
    return LESS;
  else if(value > item.value)
    return GREATER;
  else return EQUAL;
}//compareTo

/**
* implementation of getValue function that returns the value of item
*/
int DataType::getValue() const
{
  return value;
}//getValue

/**
 * implementation of Print function that prints the value of items
 */
void DataType::print() const
{
    std::cout << value << " ";
}
