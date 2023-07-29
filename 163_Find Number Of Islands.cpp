// Time Complexity -> O(n*m)
// Space Complexity -> O(n*m)

void dfs(int x, int y, int n, int m, int** arr, vector<vector<bool>>& visited)
{
   visited[x][y] = true;

   vector<int> dx = {-1,-1,-1,0,0,+1,+1,+1};
   vector<int> dy = {0,-1,+1,-1,+1,-1,0,+1};

   for(int i = 0; i < 8; ++i)
   {
      int newx = dx[i] + x;
      int newy = dy[i] + y;

      if(newx >= 0 and newy >= 0 and newx < n and newy < m and arr[newx][newy] == 1 and !visited[newx][newy])
      {
         dfs(newx, newy, n, m, arr, visited);
      }
   }
}

int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.

   vector<vector<bool>> visited(n, vector<bool>(m, false));

   int cnt = 0;

   for(int i = 0; i < n; ++i)
   {
      for(int j = 0; j < m; ++j)
      {
         if(arr[i][j] == 1 and !visited[i][j])
         {
            ++cnt;
            dfs(i, j, n, m, arr, visited);
         }
      }
   }

   return cnt;
}
