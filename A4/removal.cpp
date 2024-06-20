void LinkedList::removeNode(int key)
{
    //Case #1: Key is head 
    //Case #2: Key is tail
    //Case #3: Key is somewhere else

    if (key == head_ ->getData())
    {
        //Case #1 
        if (head_->hasNextLinkedNode())
        {
            LinkedNode * currentHead = head_;
            LinkedNode * nextNode = head_->getNextLinkedNode();
            head_ = nextNode;
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
    else if (key == tail_ ->getData())
    {
        //Case #2
        LinkedNode * previousNode = nullptr;
        LinkedNode * currentNode = head_;

        while (currentNode->hasNextLinkedNode())
        {
            previousNode = currentNode;
            currentNode = currentNode->getNextLinkedNode();

            //if (currentNode->getNextLinkedNode() == tail_)
            //{
            //  break;
            //}
        }

        previousNode->setNextLinkedNode(nullptr);
        tail_ = previousNode;
        delete currentNode;

    }
    else 
    {
        //Case #3
        // See code above 
        previousNode->setNextLinkedNode(currentNode->getNextLinkedNode());
        currentNode->setNextLinkedNode(nullptr);
        delete currentNode;

    }
    
}