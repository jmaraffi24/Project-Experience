#include "ListNode.h"
#include "DataType.h"
#include <iostream>
#include <string>

/**
 * Default constructor
 */
ListNode::ListNode(){
    item = 0; 
}//ListNode


/**
 * Constructor
 */
ListNode::ListNode(DataType &newItem){
    item = newItem.getValue();
}//ListNode

/**
 * Returns the DataType member in ListNode
 */
DataType ListNode::getItem() const {

  return item;

}//GetItem
