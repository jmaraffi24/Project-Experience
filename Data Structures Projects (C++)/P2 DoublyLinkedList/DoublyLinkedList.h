//DoublyLinkedList.h
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "NodeType.h"
#include "ItemType.h"

class DoublyLinkedList {
  public:
    /*
     * default constructor
     * Post-Condition: List is created.
     * Written by: Jacob Maraffi
     */
    DoublyLinkedList();

    /*
     * destructor
     * Pre-Condition: List is created.
     * Post-Condition: All nodes are freed.
     * Written by: Jacob Maraffi
     */
    ~DoublyLinkedList();

    /*
     * prototype for the lengthIs function which returns
     * the length of the DoublyLinkedList
     * Pre-Condition: List is initialized.
     * Post-Condition: Return length instance variable.\
     * Written by: Jacob Maraffi
     */
    int lengthIs() const;

    /*
     * prototype for the insertItem function which inserts
     * the item into the list unless it already exists
     * Pre-Condition: List exists.
     * Post-Condition: Item is inserted into the list in sorted
     * order. If the item exists do not insert the new item and
     * print "Item already exists."
     * Written by: Jacob Maraffi
     */
    void insertItem(ItemType &item);

    /*
     * prototype for the deleteItem function which deletes
     * the item from the list unless it does not exist
     * Pre-Condition: List exists and item initialized.
     * Post-Condition: The node that contains item is removed
     * from the list
     * Written by: Jacob Maraffi
     */
    void deleteItem(ItemType &item);

    /*
    * prototype for the searchItem function which locates the Node
    * that contains the target values
    * Pre-Condition: List is not empty
    * Post-Condition: If there is an elemeent whose key matches item's key,
    * then found = true, location contains the address of the element;
    * otherwise, location contains the address of the logical successor of item
    */
    void searchItem(NodeType * head, ItemType item, NodeType * &location, bool &found);

    /*
     * prototype for the print funtion which prints
     * all values of the list
     * Pre-condition: List exists.
     * Post-condition: Items are printed to standard-out based
     * on the implementation fo ItemType.
     * Written by: Jacob Maraffi
     */
    void print();

  private:
    int length;
    NodeType *head;
    NodeType *tail;
};

#endif
