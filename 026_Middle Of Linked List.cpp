
Node *findMiddle(Node *head) {
    // Write your code here

    Node* fast = head, *slow =head;

    while(fast and fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;

}

