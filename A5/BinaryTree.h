// Color Me Dawgs
// Assignment #5
// CS341 Spring 2024
// Due 04/17/2024
// By: Nathaniel Loch
//
// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// nloch

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"

class BinaryTree
{
    public:
        BinaryTree();
        virtual ~BinaryTree();
        TreeNode * getRoot();
        void setRoot(TreeNode * node);
        virtual void insert(int data);
        void printTree();
        TreeNode * insertNode(TreeNode * root, TreeNode * node);
    protected:
        TreeNode * root_;
};

#endif