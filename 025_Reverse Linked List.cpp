#include <bits/stdc++.h>

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here

    LinkedListNode<int> *prev = nullptr;

    while(head)
    {
        LinkedListNode<int> *temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }

    return prev;
}
