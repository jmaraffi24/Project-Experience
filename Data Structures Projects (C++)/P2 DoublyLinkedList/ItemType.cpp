//ItemType.cpp
#include <iostream>
#include <ItemType.h>

/*
 * default constructor
 * Post-Condition: ItemType object is created.
 * Written By: Jacob Maraffi
 */
ItemType::ItemType()
{
  value = 0;
}//ItemType

/*
 * constructor
 * Pre-Condition: Number has been initialized.
 * Post-Condition: ItemType object is created.
 * Written By: Jacob Maraffi
 */
ItemType::ItemType(int number)
{
  value = number;
}//ItemType(int number)

/*
 * initializes ItemType with newValue
 * Pre-Condition: Number has been initialized.
 * Post-Condition: The value instance variable is set to number.
 * Written By: Jacob Maraffi
 */
void ItemType::initialize(int number)
{
  value = number;
}//initialize

/*
 * implementation of the function that compares two items and returns one of
 * the values (GREATER, LESS, EQUAL) depending on the relationship
 * Pre-Condition: ItemType item has been initialized. ItemType with value
 * has been initialized.
 * Post-Condition: One of the cases of enum (GREATER, LESS, EQUAL) is returned
 * from the result of the comparison
 * Written By: Jacob Maraffi
 */
Comparison ItemType::compareTo (ItemType &item)
{
  //compares value and item.value to determine if target is LESS
  if(value < item.value)
    return LESS;
  else if(value > item.value)
    return GREATER;
  else return EQUAL;
}//compareTo

/*
 * implemetation of getValue function that returns the value of item
 * Pre-Condition: ItemType object has been initialized.
 * Post-Condition: Return the value instance variable.
 * Written By: Jacob Maraffi
 */
int ItemType::getValue() const
{
  return value;
}//getValue

/*
 * implemetation of the print function that prints the value of item
 * Pre-Condition: ItemType object has been initialized.
 * Post-Conditon: Value instance varibale is printed to standard-out
 * Written By: Jacob Maraffi
 */
void ItemType::print() const
{
  std::cout << value << " ";
}//print
