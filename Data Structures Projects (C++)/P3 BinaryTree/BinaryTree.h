#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "ItemType.h"
#include<iostream>

class BinaryTree {
 public:
  struct Node {
    ItemType key;
    Node * left;
    Node * right;
  };

  BinaryTree();
  ~BinaryTree();
  void insert(ItemType &key);
  void deleteItem(ItemType &key);
  void retrieve(ItemType &item, bool &found) const;
  void preOrder() const;
  void inOrder() const;
  void postOrder() const;
  int getLength() const;
  void getSameLengthLevelNonsiblings(Itemtype &key); //bonus only

 private:
  Node * root;
  int length;



};




#endif
