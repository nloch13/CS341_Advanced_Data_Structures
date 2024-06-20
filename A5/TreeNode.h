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

#ifndef TREENODE_H
#define TREENODE_H

enum Color {NONE, RED, BLACK };

class TreeNode
{
    public:
        TreeNode();
        TreeNode(int data);
        virtual ~TreeNode();

        void setParent(TreeNode * parent);
        void setLeftChild(TreeNode * leftChild);
        void setRightChild(TreeNode * rightChild);
        void setColor(Color color);
        void setData(int data);

        TreeNode * getLeftChild();
        TreeNode * getRightChild();
        TreeNode * getParent() const;
        Color getColor() const;
        int getData();

    private:
        TreeNode * leftChild_;
        TreeNode * rightChild_;
        TreeNode * parent_;
        int data_;
        Color color_;
};

#endif
