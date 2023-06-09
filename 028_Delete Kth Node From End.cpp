Node* removeKthNode(Node* head, int K)
{
    // Write your code here.

    Node* fast = head, *slow = head;

    while(K > 0)
    {
        fast = fast->next;
        --K;
    }

    if(!fast)
        return head->next;

    while(fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    slow->next = slow->next->next;

    return head;
}
