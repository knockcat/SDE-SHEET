Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.

	if(!head)
		return head;
	
	Node* dummy = new Node(0);

	dummy->next = head;

	Node* prev = dummy, *nex = dummy, *curr = dummy;

	int cnt = 0;

	while(head)
	{
		++cnt;
		head = head->next;
	}

	int j = 0;

	while(j < n and cnt > 0)
	{
		if(b[j] == 0)
		{
			++j;
			continue;
		}

		curr = prev->next;
		nex = curr->next;

		for(int i = 1; i < min(b[j], cnt); ++i)
		{
			curr->next = nex->next;
			nex->next = prev->next;
			prev->next = nex;
			nex = curr->next;
		}
		prev = curr;
		cnt -= min(b[j],cnt);

		++j;
	}

	return dummy->next;
}
