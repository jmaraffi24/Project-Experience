#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

#include <iostream>
#include "ListNode.h"
#include "DataType.h"

class SortedLinkedList {
public:
    SortedLinkedList();
    ~SortedLinkedList();
    int length() const;
    void insertItem(DataType &item);
    void deleteItem(DataType &item);
    int searchItem(DataType &item);
    void clear();
    void reverse();     //extra credit only
    void iterator();
    void resetIterator();
    void printAll();
    
private:
    int count; 
    ListNode *head;
    ListNode *currentNode;
    ListNode *prevNode;
    int currentPos;
};

#endif
