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

#include "TreeNode.h"

TreeNode::TreeNode(int data) : data_(0), leftChild_(nullptr), rightChild_(nullptr), color_(NONE)
{
    data_ = data;
}

TreeNode::~TreeNode()
{
    if (leftChild_ != nullptr)
    {
        delete leftChild_;
    }

    if (rightChild_ != nullptr)
    {
        delete rightChild_;
    }
}



void TreeNode::setParent(TreeNode * parent)
{
    parent_ = parent;
}

void TreeNode::setLeftChild(TreeNode * leftChild)
{
    leftChild_ = leftChild;
}

void TreeNode::setRightChild(TreeNode * rightChild)
{
    rightChild_ = rightChild;
}

TreeNode * TreeNode::getLeftChild()
{
    return leftChild_;
}

TreeNode * TreeNode::getRightChild()
{
    return rightChild_;
}

TreeNode * TreeNode::getParent() const
{
    return parent_;
}

void TreeNode::setData(int data)
{
    data_ = data;
}

int TreeNode::getData()
{
    return data_;
}

Color TreeNode::getColor() const
{
    return color_;
}

void TreeNode::setColor(Color color)
{
    color_ = color;
}