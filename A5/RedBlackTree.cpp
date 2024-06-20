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

#include "RedBlackTree.h"
#include <iostream>

RedBlackTree::RedBlackTree() : BinaryTree(){}

RedBlackTree::~RedBlackTree(){}

void RedBlackTree::insert(int data)
{
    TreeNode * newNode = new TreeNode(data);
    newNode->setColor(RED);
    BinaryTree::setRoot(BinaryTree::insertNode(BinaryTree::getRoot(), newNode));
    TreeNode * root = BinaryTree::getRoot();
    balanceColor(root, newNode);
}

void RedBlackTree::printRedNodes(TreeNode* root) {
    if (root != nullptr) {
        printRedNodes(root->getLeftChild());
        if (root->getColor() == RED) {
            std::cout << root->getData() << " ";
        }
        printRedNodes(root->getRightChild());
    }
}

void RedBlackTree::printBlackNodes(TreeNode* root) {
    if (root != nullptr) {
        if (root->getColor() == BLACK) {
            std::cout << root->getData() << " ";
        }
        printBlackNodes(root->getLeftChild());
        printBlackNodes(root->getRightChild());
    }
}

void RedBlackTree::rotateLeft(TreeNode *& root, TreeNode *& newNode)
{
    TreeNode * newRightNode = newNode->getRightChild();
    newNode->setRightChild(newRightNode->getLeftChild());

    if(newNode->getRightChild() != nullptr)
    {
        newNode->getRightChild()->setParent(newNode);
    }

    newRightNode-> setParent(newNode->getParent());

    if(newNode->getParent() == nullptr)
    {
        root = newRightNode;
        BinaryTree::setRoot(newRightNode);
    }
    else if (newNode == newNode->getParent()->getLeftChild())
    {
        newNode->getParent()->setLeftChild(newRightNode);
    }
    else
    {
        newNode->getParent()->setRightChild(newRightNode);
    }

    newRightNode->setLeftChild(newNode);
    newNode->setParent(newRightNode);
}

void RedBlackTree::rotateRight(TreeNode *& root, TreeNode *& newNode)
{
    TreeNode *newLeftNode = newNode->getLeftChild();
    newNode->setLeftChild(newLeftNode->getRightChild());

    if(newNode->getLeftChild() != nullptr)
    {
        newNode->getLeftChild()->setParent(newNode);
    }

    newLeftNode-> setParent(newNode->getParent());

    if(newNode->getParent() == nullptr)
    {
       BinaryTree::setRoot(newLeftNode);
        root = newLeftNode;
    }
    else if (newNode == newNode->getParent()->getLeftChild())
    {
        newNode->getParent()->setLeftChild(newLeftNode);
    }
    else
    {
        newNode->getParent()->setRightChild(newLeftNode);
    }

    newLeftNode->setRightChild(newNode);
    newNode->setParent(newLeftNode);
}

void RedBlackTree::balanceColor(TreeNode *& root, TreeNode *& newNode)
{
    TreeNode *parentNode = nullptr;
    TreeNode *grandparentNode = nullptr;

    while ((newNode != root) && (newNode->getColor() != BLACK) && (newNode->getParent()->getColor() == RED)) 
    {
        parentNode = newNode->getParent();
        grandparentNode = newNode->getParent()->getParent();

		
        //parent of newNode is left child of grandparent of newNode 
        if (parentNode == grandparentNode->getLeftChild()) 
        {
            TreeNode *uncNode = grandparentNode->getRightChild();


               //uncle of newNode is also red
            if (uncNode != nullptr && uncNode->getColor() == RED) 
            {
                grandparentNode->setColor(RED);
                parentNode->setColor(BLACK);
                uncNode->setColor(BLACK);
                newNode = grandparentNode;
            } 
            else 
            {
                //newNode is right child of its parent
                if (newNode == parentNode->getRightChild()) 
                {
                    rotateLeft(root, parentNode);
                    newNode = parentNode;
                    parentNode = newNode->getParent();
                }
                else
                {
                //newNode is left child of its parent
                rotateRight(root, grandparentNode);
                Color temp = parentNode->getColor();
				parentNode->setColor(grandparentNode->getColor());
				grandparentNode->setColor(temp);
				newNode = parentNode;
                }
            }
        }
        //parent of newNode is right child of grandparent of newNode
        else 
        {
            TreeNode * uncNode = grandparentNode->getLeftChild();

               //uncle of newNode is also red
            if ((uncNode != nullptr) && (uncNode->getColor() == RED)) 
            {
                grandparentNode->setColor(RED);
                parentNode->setColor(BLACK);
                uncNode->setColor(BLACK);
                newNode = grandparentNode;
            } 
            else 
            {
                // newNode is left child of its parent
                if (newNode == parentNode->getLeftChild()) 
                {
                    rotateRight(root, parentNode);
                    newNode = parentNode;
                    parentNode = newNode->getParent();
                }
                else
                {
                  // newNode is right child of its parent
                rotateLeft(root, grandparentNode);
                Color temp = parentNode->getColor();
				parentNode->setColor(grandparentNode->getColor());
				grandparentNode->setColor(temp);
				newNode = parentNode;
                }
            }
        }
    }

    root->setColor(BLACK);
}