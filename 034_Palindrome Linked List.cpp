bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.

    LinkedListNode<int> *slow = head, *fast = head;

    while(fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    LinkedListNode<int> *secondHalf = slow, *prev = nullptr;

    while(secondHalf)
    {
        LinkedListNode<int> *temp = secondHalf->next;
        secondHalf->next = prev;
        prev = secondHalf;
        secondHalf = temp;
    }

    while(head != slow)
    {
        if(head->data != prev->data)
            return false;
        head = head->next;
        prev = prev->next;
    }

    return true;
}
