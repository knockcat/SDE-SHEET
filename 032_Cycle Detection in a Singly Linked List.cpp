bool detectCycle(Node *head)
{
	//	Write your code here

    Node* fast = head;
    Node* slow = head;

    while(fast and fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
            return true;
    }

    return false;

}
