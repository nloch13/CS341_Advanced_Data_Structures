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
#include <algorithm>

BinaryTree::BinaryTree() : root_(nullptr)
{

}

BinaryTree::~BinaryTree()
{
    if (root_ != nullptr)
    {
        delete root_;
    }
}

TreeNode * BinaryTree::getRoot()
{
    return root_;
}

void BinaryTree::setRoot(TreeNode * node)
{
    root_ = node;
}

void BinaryTree::insert(int data)
{
    TreeNode * newNode = new TreeNode(data);
    root_ = insertNode(root_, newNode);
}

TreeNode * BinaryTree::insertNode(TreeNode * root, TreeNode * node)
{
    if(root == nullptr)
    {
        return node;
    }
    else if (node->getData() < root->getData())
    {
        root->setLeftChild(insertNode(root->getLeftChild(), node));
        root->getLeftChild()->setParent(root);
    }
    else
    {
        root->setRightChild(insertNode(root->getRightChild(), node));
        root->getRightChild()->setParent(root);
      
    }

    return root;
}

void BinaryTree::printTree()
{

}