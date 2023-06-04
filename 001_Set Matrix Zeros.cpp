#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.

	int n = matrix.size(), m = matrix[0].size();

	vector<int> row(n,0), col(m, 0);

	for(int i = 0; i < n; ++i)
	{
		for(int j =0 ; j < m;++j)
		{
			if(matrix[i][j] == 0)
				row[i] = col[j] = 1;
		}
	}

	for(int i =0 ; i < n; ++i)
	{
		for(int j =0 ; j < m; ++j)
		{
			if(row[i] == 1 or col[j] == 1)
				matrix[i][j] = 0;
		}
	}
}
