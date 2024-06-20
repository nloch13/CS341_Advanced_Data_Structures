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

#include "BinaryTree.h"
#include "TreeNode.h"
#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

class RedBlackTree : public BinaryTree
{
    public:
        RedBlackTree();
        virtual ~RedBlackTree();
        virtual void insert(int data);
        void printRedNodes(TreeNode * root);
        void printBlackNodes(TreeNode * root);
    private:
        void rotateLeft(TreeNode *& root, TreeNode *& newNode);
        void rotateRight(TreeNode *& root, TreeNode *& newNode);
        void balanceColor(TreeNode *& root, TreeNode *& newNode);
};

#endif