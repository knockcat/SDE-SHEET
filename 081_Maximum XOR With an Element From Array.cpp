// Time Complexity -> O(Q*32 + N*32)
// Space Complexity -> O(N * 32)

// O(Q*32 + N*32)  // trie take O(32) insert also take O(32)

#include<bits/stdc++.h>

class Node
{
	private:
		Node* links[2] = {nullptr};
	public:
		bool containsKey(int bit)
		{
			return links[bit] != nullptr;
		}

		void put(int bit, Node* node)
		{
			links[bit] = node;
		}

		Node* get(int bit)
		{
			return links[bit];
		}
};

class BitTrie{

	private:
		Node* root;
	public:
		BitTrie()
		{
			root = new Node();
		}

		void insert(int num)
		{
			Node* temp = root;

			for(int i = 31; i >= 0; --i)
			{
				int bit = (num >> i) & 1;

				if(!temp->containsKey(bit))
					temp->put(bit, new Node());
				temp = temp->get(bit);
			}
		}

		int getMax(int num)
		{
			Node* temp = root;

			int maxNum = 0;

			for(int i = 31; i >= 0; --i)
			{
				int bit = (num >> i) & 1;

				if(temp->containsKey(1-bit))
				{
					temp = temp->get(1-bit);
					maxNum |= (1 << i);
				}
				else
					temp = temp->get(bit);
			}

			return maxNum;
		}
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.

	int n = arr.size();

	vector<pair<int, pair<int,int> > > here;

	int k = queries.size();

	for(int i = 0; i < k; ++i)
	{
		here.push_back({queries[i][1],{queries[i][0], i}});
	}

	vector<int> ans(k);

	sort(arr.begin(), arr.end());

	sort(here.begin(), here.end());

	int cur = 0;

	BitTrie *trie = new BitTrie();

	for(int i = 0; i < k; ++i)
	{
		int lim = here[i].first;
		int val = here[i].second.first;
		int idx = here[i].second.second;

		for(int j = cur; j < n; ++j )
		{
			if(arr[j] <= lim)
			{
				trie->insert(arr[j]);
				++cur;
			}
			else
				break;
		}

		if(cur == 0)
			ans[idx] =  -1;
		else
			ans[idx] = trie->getMax(val);
	}

	return ans;
}
