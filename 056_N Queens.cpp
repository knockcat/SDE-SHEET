// Time Complexity -> O(N!)
// Space Complexity -> O(N^2)


bool isSafe(int row, int col, int n, vector<vector<int>>& board)
{
    int dupRow = row;
    int dupCol = col;

    while(dupRow >= 0 and dupCol >= 0)
    {
        if(board[dupRow][dupCol] == 1)
            return false;
        --dupRow;
        --dupCol;
    }

    dupRow = row;
    dupCol = col;

    while(dupCol >= 0)
    {
        if(board[dupRow][dupCol] == 1)
            return false;
        --dupCol;
    }

    dupCol = col;
    dupRow = row;

    while(dupRow < n and dupCol >= 0)
    {
        if(board[dupRow][dupCol] == 1)
            return false;
        --dupCol;
        ++dupRow;
    }

    return true;
}

void helper(int col, int n, vector<vector<int>>&board, vector<vector<int>>& ans)
{
    if(col == n)
    {
        vector<int> curr;

        for(auto itr : board)
        {
            for(auto x : itr)
            {
               curr.push_back(x);
            }
        }

        ans.push_back(curr);

        return;
    }

    for(int row = 0; row < n; ++row)
    {
        if(isSafe(row, col, n, board))
        {
            board[row][col] = 1;
            helper(col+1, n, board, ans);
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.

    vector<vector<int>> ans;

    vector<vector<int>> board(n, vector<int>(n,0));

    helper(0, n, board, ans);


    return ans;
}


// Time Complexity -> O(N!)
// Space Complexity -> O(N^2)

void helper(int col, int n, vector<vector<int>>&board, vector<int>&leftRow, vector<int>& upperDiag, vector<int>& lowerDiag, vector<vector<int>>& ans)
{
    if(col == n)
    {
        vector<int> curr;

        for(auto itr : board)
        {
            for(auto x : itr)
            {
               curr.push_back(x);
            }
        }

        ans.push_back(curr);

        return;
    }

    for(int row = 0; row < n; ++row)
    {
        if(!leftRow[row] and !lowerDiag[row + col] and !upperDiag[n-1 + (col-row)])
        {
            board[row][col] = 1;
            leftRow[row] = 1;
            lowerDiag[row + col] = 1;
            upperDiag[n-1 + (col - row)] = 1;

            helper(col+1, n, board, leftRow, upperDiag, lowerDiag, ans);

            board[row][col] = 0;
            leftRow[row] = 0;
            lowerDiag[row + col] = 0;
            upperDiag[n-1 + (col - row)] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.

    vector<vector<int>> ans;

    vector<vector<int>> board(n, vector<int>(n,0));

    vector<int> leftRow(n,0), lowerDiag(2*n-1,0), upperDiag(2*n-1, 0);

    helper(0, n, board, leftRow, lowerDiag, upperDiag, ans);


    return ans;
}
