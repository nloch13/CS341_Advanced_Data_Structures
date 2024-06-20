void DoubleLinkedList::removeNode(int key)
{
    //Case #1
    if (key == head_->getData())
    {
        if (head_->hasNextLinkedNode())
        {
            LinkedNode * currentHead = head_;
            LinkedNode * nextNode = head_->getNextLinkedNode();
            head_ = nextNode;
            nextNode->setPreviousLinkedNode(nullptr);
            currentHead->setNextLinkedNode(nullptr);
            delete currentHead;

        }
        else
        {
            LinkedNode * currentHead = head_;
            head_ = nullptr;
            tail_ = nullptr;
            delete currentHead;
        }
        
    }
    else if (key == tail_->getData())
    {
        //Case #2
        if (tail_ -> hasPreviousLinkedNode())
        {
            LinkedNode * currentTail = tail_;
            LinkedNode * previousNode = tail_->getPreviousLinkedNode();
            tail_ = previousNode;
            previousNode -> setNextLinkedNode(nullptr);
            currentTail->setPreviousLinkedNode(nullptr);
            delete currentTail;
        }
    }
    else
    {
        //Case #3
        LinkedNode * currentNode = head_;

        bool isFound = false;

        while (currentNode->hasNextLinkedNode && !isFound)
        {
            currentNode = currentNode->getNextLinkedNode();

            if (currentNode->getData() == key)
            {
                isFound = true;
            }
        }

        if (isFound)
        {
            currentNode->getPreviousLinkedNode()->setNextLinkedNode(currentNode->getNextLinkedNode());
            currentNode->getNextLinkedNode()->setPreviousLinkedNode(currentNode->getPreviousLinkedNode());
            currentNode->setNextLinkedNode(nullptr);
            currentNode->setPreviousLinkedNode(nullptr);
            delete currentNode;
        }
        else
        {
            std::cout << "Key not found." << std::endl;
        }
    }
}