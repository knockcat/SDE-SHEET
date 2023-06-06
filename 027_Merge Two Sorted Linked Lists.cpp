Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.

    if(!first)
        return second;
    if(!second)
        return first;
    
    if(first->data <= second->data)
        first->next= sortTwoLists(first->next, second);
    else
        second->next = sortTwoLists(first, second->next);
}
