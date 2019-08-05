#include "BinaryTree.h"

/**
 * Pre-Condition: none
 * Post-Condition: Tree is initialized.
 */
BinaryTree::BinaryTree(){


}//BinaryTree

/**
 * Pre-Condition: Tree has been initialized.
 * Post-Condition: All node pointers freed, root pointers to null,
 * and length equals 0.
 */
BinaryTree::~BinaryTree(){

}//~BinaryTree

/**
 * Pre-Condition: Tree and paramenter key initialized.
 * Post-Condition: Insert a node with the value of key into
 * the tree. NO DUPLICATES ARE ALLOWED.
 */
void BinaryTree::insert(ItemType &key){


}//insert

/**
 * Pre-Condition: Tree and parameter key initialized.
 * Post-Condition: Remove a node with the key value equal to the parameter
 * key's vaue and decrement length, otherwise leave tree unchanged. In
 * situations, where the node to be deleted has two children, replace 
 * the deleted node with its immediate predecessor.
 */
void BinaryTree::deleteItem(ItemType &key){

}//deleteItem

/**
 * Pre-Condition: Tree, item, and found are all initialized.
 * Post-Condition: Item should refer to a key of a Node n in the
 * tree where the value of n.key is equal to the value of item AND found 
 * should be equal to true if n exists. Otherwise found should be equal to
 * false.
 */
void BinaryTree::retrieve(ItemType &item, bool &found) const {

}//BinaryTree

/**
 * Pre-Condition: The tree has been initialized.
 * Post-Condition: Print out the tree in pre-order.
 */
void BinaryTree::preOrder() const {

}//preOrder

/**
 * Pre-Condition: The tree has been initialized.
 * Post-Condition: Print out the tree in in-order.
 */
void BinaryTree::inOrder() const {

}//inOrder

/**
 * Pre-Condition: The tree has been initialized.
 * Post-Condition: Print out the tree in post-order.
 */
void BinaryTree::postOrder() const {

}//postOrder

/**
 * Pre-Condition: The tree has been initialized.
 * Post-Condition: Return value of length.
 */
int BinaryTree::getLength() const {

}//getLength

/**
 * BONUS ONLY.
 * Pre-Condition: The tree and the paramenter key has
 * been initialized.
 * Post-Condition: Print the value of the node in the same level
 * other than its own siblings. If no same level nodes that are not own
 * siblings were found, print "No same level non siblings found".
 * The maximum time complexity should O(n).
 */
void BinaryTree::getSameLevelNonSiblings(ItemType &key) {

}//getSameLevelNonSiblings
 

