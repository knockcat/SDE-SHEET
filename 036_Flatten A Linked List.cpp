Node* mergeList(Node* a, Node* b)
{
	if(!a)
	{
		b->next = nullptr;
		return b;
	}

	if(!b)
	{
		a->next = nullptr;
		return a;
	}

	Node* merged = nullptr;

	if(a->data < b->data)
	{
		merged = a;
		a->child = mergeList(a->child, b);
	}
	else
	{
		merged = b;
		b->child = mergeList(a,b->child);
	}

	merged->next = nullptr;
	return merged;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here

	if(!head or !head->next)
		return head;
	
	head->next = flattenLinkedList(head->next);

	head = mergeList(head, head->next);

	return head;

}
