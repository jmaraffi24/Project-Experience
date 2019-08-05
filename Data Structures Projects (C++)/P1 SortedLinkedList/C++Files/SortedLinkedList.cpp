#include "SortedLinkedList.h"
#include "DataType.h"
#include "ListNode.h"
#include <iostream>
#include <string>

struct ListNode;

/**
 * Initialise a sorted linked list object.
 */
SortedLinkedList::SortedLinkedList(){
    count = 0;
    head = NULL;
    resetIterator();
    //currentPos = -1;
}//SortedLinkedList

/**
 * Free up the used memory and destruct the SortedLinkedList instance.
 * This method should handle memory leaks.
 */
SortedLinkedList::~SortedLinkedList(){
    ListNode * tPtr;
    
    while(head != NULL){
        tPtr = head;
        head = head->next;
        delete tPtr;
    }//while
    
}//~SortedLinkedList

/**
 * Return the length of the linked list.
 */
int SortedLinkedList::length() const{
    return count;
}//legnth

/**
 * Item should be inserted to the linked list maintaining
 * the ascending sorted order.
 * You have to handle inserting the first element as a
 * special case.
 */
void SortedLinkedList::insertItem(DataType &item){
    ListNode * newNode;
    ListNode * predLoc;
    ListNode * loc;
    bool shouldSearchMore;
    
    //case one: inserting an item that is not the first element in list
    loc = head;
    predLoc = NULL;
    shouldSearchMore = (loc != NULL);
    
    while(shouldSearchMore){
        switch(item.compareTo(loc->item)){
            case GREATER:
                predLoc = loc;
                loc = loc->next;
                shouldSearchMore = (loc != NULL);
                break;
            case EQUAL: //if equal do not insert/do anything b.c item already in list
            case LESS:
                shouldSearchMore = false;
                break;
        }//switch
        
    }//while
    
    //create a new node to insert
    newNode = new ListNode(item);
    
    //insert node into list
    if(predLoc == NULL){
        newNode->next = head;
        head = newNode;
    }//if
    
    else {
        newNode->next = loc;
        predLoc->next = newNode;
    }//else
    
    count++;
    
}//insertItem

/**
 * ListNode that contains an item equal to the item parameter should be removed.
 *  You should handle all cases of deleting an element.
 *      Deleting first element.
 *      Deleting the last element or an element in the middle.
 *      Deleting the only element.
 *      Attempt to delete a non-existing item should print “Item not found”.
 */
void SortedLinkedList::deleteItem(DataType &newItem){
    ListNode * loc = new ListNode;
    ListNode * tempLoc = new ListNode;
    int index = searchItem(newItem);
    
    //case one: Deleting first element
    if(newItem.compareTo(head->item) == EQUAL){
        tempLoc = head;
        head = head->next;
        delete tempLoc;
        count--;
    }//if
    
    //case two: Deleting the last element or an element in the middle
    else if(index != -1 && count > 1){
        ListNode * predLoc = new ListNode;
        loc = head;
        
        for(int i = 1; i < length(); i++){ //only searches middle and end ListNodes
            predLoc = loc;
            loc = loc->next;
            
            if(newItem.compareTo(loc->item) == EQUAL){
                tempLoc = loc;
                predLoc->next = loc->next;
                delete tempLoc;
                count--;
                break;
            }//if
        }//for
    }//else if
    
    //case three: Deleting the only element
    else if(index != -1 && count == 1){
        loc = head;
        tempLoc = loc;
        loc = NULL;
        delete tempLoc;
        count--;
    }//else if
}//deleteItem

/**
 * Search the ListNode that contains an item equal to the parameter
 * item and return its index. Print “Item not found” if the item was
 * not found in the list.
 */
int SortedLinkedList::searchItem(DataType &newItem){
    ListNode * loc;
    loc = head;
    currentPos = -1;
    bool shouldSearchMore = (loc != NULL);
    
    while(shouldSearchMore){
        switch(newItem.compareTo(loc->item)){
            case EQUAL:
                currentPos++;
                shouldSearchMore = false;
                break;
            case GREATER:
            case LESS:
                currentPos++;
                loc = loc->next;
                shouldSearchMore = (loc != NULL);
                break;
        }//switch
    }//while
    
    if(loc != NULL){
        return currentPos;
    }//if
    
    std::cout << "Item not found" << std::endl;
    return -1;
    
}//searchItem

/**
 * Remove all elements in the linked list and free up the memory.
 * This method should handle memory leaks.
*/
void SortedLinkedList::clear(){
    ListNode * tPtr;
    
    while(head != NULL){
        tPtr = head;
        head = head->next;
        delete tPtr;
    }//while
    count = 0;
    
}//clear

/**
 * You should implement this method only if you wish to complete
 *  the bonus question. In this method you should reverse the
 * linked list without using a separate list or an array.
 */
void SortedLinkedList::reverse(){
    ListNode * curr = head;
    ListNode * previous = NULL;
    ListNode * next = NULL;
    
    while(curr != NULL){
        
        next = curr->next;  //store next
        curr->next = previous; //reverse curr's pointer
        previous = curr; //move pointers forward by one
        curr = next; //move pointers forward by one
        
    }//while
    head = previous;
    
}//reverse

/**
 * Iterates through the sorted linked list.
 * Returns the next value from the current position in the list.
 * If the list is empty, prints "List is empty".
 * If the end of the list has been reached, "The end of the list has been
 * reached" prints.
 */
void SortedLinkedList::iterator(){
    //ListNode * tempLoc;
    
    if(count == 0){ //list is empty
        std::cout << "List is empty" << std::endl;
        resetIterator();
        return;
    }//if
    
    else if(currentNode == NULL && (currentPos != count-1)){
        resetIterator();
    }//else if

    
    if(currentPos == count-1){ //count is the length of the list
        std::cout << "The end of the list has been reached" << std::endl;
        return;
    }//if
    
    currentPos++;
    prevNode = currentNode;
    currentNode = currentNode->next;
    std::cout << prevNode->item.getValue() << std::endl;
}//Iterator

/**
 * Resets the iterator back to the initial position at the beginning of
 * the list.
 */
void SortedLinkedList::resetIterator(){
    currentPos = -1;
    currentNode = head;
}//ResetIterator

/**
 *
 */
void SortedLinkedList::printAll(){
    ListNode * loc;
    loc = head;
    
    for(int i = 0; i < count; i++){
        (loc->item).print();
        loc = loc->next;
    }//for
    std::cout << std::endl;

    
}//PrintAll

