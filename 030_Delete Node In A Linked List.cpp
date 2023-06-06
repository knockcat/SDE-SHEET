void deleteNode(LinkedListNode<int> * node) {
    // Write your code here.

    node->data = node->next->data;
    node->next = node->next->next;
    
}
