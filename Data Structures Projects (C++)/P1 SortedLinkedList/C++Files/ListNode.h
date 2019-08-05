#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
#include "DataType.h"

struct ListNode {
public:
    DataType item;
    ListNode *next;
    
    ListNode();
    ListNode(DataType &newItem);
    DataType getItem() const;
        
};

#endif
