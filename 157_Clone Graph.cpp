// Time Complexity -> O(n + m) , n vertices and m edges
// Space Complexity -> O(n)

graphNode* clone(graphNode* node, unordered_map<int,graphNode*>& mp)
{
	graphNode* newNode = new graphNode(node->data);

	mp.insert({node->data, newNode});

	for(auto itr : node->neighbours)
	{
		if(mp.find(itr->data) == mp.end())
		{
			graphNode* curNode = clone(itr, mp);

			newNode->neighbours.push_back(curNode);
		}
		else
			newNode->neighbours.push_back(mp[itr->data]);
	}

	return newNode;
}


graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.

	if(!node)
		return nullptr;
	
	unordered_map<int, graphNode*> mp;

	return clone(node, mp);
}
