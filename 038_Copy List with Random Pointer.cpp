// TC -> O(N) + O(N) = O(2N) ~ O(N)
// SC -> O(N)

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.

    unordered_map<LinkedListNode<int>*, LinkedListNode<int>*> mp;

    LinkedListNode<int>* ptr = head, *dummy = new LinkedListNode<int>(0), *res = dummy;

    while(ptr)
    {
        res->next = new LinkedListNode<int>(ptr->data);
        
        res = res->next;
        
        mp[ptr] = res;
        
        ptr = ptr->next;
    }

    ptr = head;

    while(ptr)
    {
        mp[ptr]->next = ptr->next;
        mp[ptr]->random = ptr->random;
        ptr = ptr->next;
    }

    return dummy->next;
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// TC -> O(N) + O(N) + O(N) = O(3N) ~ O(N)
// SC -> O(1)

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.

    LinkedListNode<int> *dummy = new LinkedListNode<int>(0), *temp = head, *res = dummy;
    
    while(temp)
    {
        LinkedListNode<int> * ptr = new LinkedListNode<int>(temp->data);

        LinkedListNode<int> *nex;
        
        if(temp->next)
            nex = temp->next;
        else
            nex = nullptr;

        temp->next = ptr;

        ptr->next = nex;
        
        temp = nex;
    }
    
    temp = head;

    // while(temp)
    // {
    //     cout<<temp->data<<' ';
    //     temp = temp->next;
    // }

    while(temp)
    {
        if(temp->random)
            temp->next->random = temp->random->next;
        else
            temp->next->random = nullptr;
            
        temp = temp->next->next;
    }

    temp = head;

    while(temp)
    {
        LinkedListNode<int> *nex = temp->next;
        temp->next = nex->next;
        res->next = nex;
        res = res->next;
        temp = temp->next;
    }

    return dummy->next;
}
