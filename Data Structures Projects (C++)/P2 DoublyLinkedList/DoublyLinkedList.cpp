//DoublyLinkedList.cpp
#include "DoublyLinkedList.h"
#include <iostream>

/*
 * default constructor
 * Post-Condition: List is created.
 * Written by: Jacob Maraffi
 */
 DoublyLinkedList::DoublyLinkedList(){
   length = 0;
   head = NULL;
   tail = NULL;
 }//DoublyLinkedList

 /*
  * destructor
  * Pre-Condition: List is created.
  * Post-Condition: All nodes are freed.
  * Written by: Jacob Maraffi
  */
  DoublyLinkedList::~DoublyLinkedList(){
    NodeType * tempNode = nullptr;
    //while head is not NULL (end of the list)
    while (head){
      tempNode = head->next;
      delete tempNode;
    }//while
  }//destructor

  /*
   * prototype for the lengthIs function which returns
   * the length of the DoublyLinkedList
   * Pre-Condition: List is initialized.
   * Post-Condition: Return length instance variable.\
   * Written by: Jacob Maraffi
   */
   int DoublyLinkedList::lengthIs() const{
     return length;
   }//lengthIs

   /*
    * prototype for the insertItem function which inserts
    * the item into the list unless it already exists
    * Pre-Condition: List exists.
    * Post-Condition: Item is inserted into the list in sorted
    * order. If the item exists do not insert the new item and
    * print "Item already exists."
    * Written by: Jacob Maraffi
    */
    void DoublyLinkedList::insertItem(ItemType &item){
      //initialize new node to be inserted
      NodeType * newNode = new NodeType;
      //initialize location tracking node for the searchItem function
      NodeType * location = new NodeType;
      //give the target node the value of item
      newNode->data = item;
      bool found;
      //calling the searchItem function to find where the item is to be inserted
      searchItem(head,item,location,found);

      //item was found in the list and already exists
      if (found == true){
        std::cout << "Item is already in the list" << std::endl;
      }//if

      //Case 1: If the list is empty
      if (head == NULL){
        head = newNode;
        tail = head;
        length++;
      }//if

      //Case 2: Inserting at the beginning of the List
      if ((newNode->data).compareTo(head->data) == LESS){
        newNode->next = head;
        head = newNode;
        length++;
      }//if

      //Case 3: Inserting at the end of the List
      if ((newNode->data).compareTo(tail->data) == EQUAL || (newNode->data).compareTo(tail->data) == GREATER ){
        newNode->back = tail;
        tail->next = newNode;
        tail = newNode;
        length++;
      }//if

      //Case : Inserting into the middle of the List
      else {
        newNode->back = location->back;
        newNode->next = location;
        location->back->next = newNode;
        location->back = newNode;
        length++;
      }//else
      delete location;
    }//insertItem

    /*
     * prototype for the deleteItem function which deletes
     * the item from the list unless it does not exist
     * Pre-Condition: List exists and item initialized.
     * Post-Condition: The node that contains item is removed
     * from the list
     * Written by: Jacob Maraffi
     */
     void DoublyLinkedList::deleteItem (ItemType &item){
       //initialize location tracking node for the searchItem function
       NodeType * location = new NodeType;
       bool found;
       searchItem(head, item, location, found);

       //item was not found by searchItem
       if(found == false){
         std::cout << "Item not found in the list" << endl;
       }//if

       //Case 1: Deleting the first node
       if (location->back == NULL){
         head = head->next;
         delete head;
         length--;
       }//if

       //Case 2: Deleting the last node
       if (location->next == NULL){
         location->back->next = NULL;
         length--;
       }//if

       //Case 3: Deleting the only node in the List
       if (location->back == NULL && location->next == NULL){
         NodeType * tempNode = new NodeType;
         location = head;
         tempNode = location;
         location = NULL;
         delete tempNode;
         length--;
       }//if

       //General Case: Deleting a node in the middle
       else{
         location->back->next = location->next;
         location->next->back = location->back;
         length--;
       }//else

       delete location;
     }//deleteItem

     /*
     * prototype for the searchItem function which locates the Node
     * that contains the target values
     * Pre-Condition: List is not empty
     * Post-Condition: If there is an elemeent whose key matches item's key,
     * then found = true, location contains the address of the element;
     * otherwise, location contains the address of the logical successor of item
     * Written by: Jacob Maraffi
     */
     void DoublyLinkedList::searchItem (NodeType * head, ItemType item, NodeType * &location, bool &found){
       bool moreToSearch = true;
       location = head;
       found = false;
       while (moreToSearch && !found){
          if(item.compareTo(location->data) == LESS)
            moreToSearch = false;
          else if (item.compareTo(location->data) == EQUAL)
            found = true;
          else
          {
            location = location->next;
            moreToSearch = (location != NULL);
          }
       }//while
     }//searchItem

     /*
      * prototype for the print funtion which prints
      * all values of the list
      * Pre-condition: List exists.
      * Post-condition: Items are printed to standard-out based
      * on the implementation fo ItemType.
      * Written by: Jacob Maraffi
      */
      void DoublyLinkedList::print(){
        NodeType * location;
        location = head;

        for (int i = 0; i < length; i++){
          (location->data).print();
          location = location->next;
        }//for
        std::cout << std:: endl;
      }//print
