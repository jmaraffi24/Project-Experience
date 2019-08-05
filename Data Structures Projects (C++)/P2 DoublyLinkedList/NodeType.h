//NodeType.h ****BinaryTree****
#ifndef NODETYPE_H
#define NODETYPE_H

#include <ItemType.h>

struct NodeType{
  ItemType key;
  NodeType *left;
  NodeType *right;
};

#endif
