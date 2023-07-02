// Time complexity -> O(9 ^ K)
// Space complexity -> O(K)

bool isSafe(int row, int col, int curr, int matrix[9][9])
{
    for(int i = 0; i < 9; ++i)
    {
        if(matrix[i][col] == curr)
            return false;
        if(matrix[row][i] == curr)
            return false;
        if(matrix[3*(row/3) + i/3][3*(col/3) + i%3] == curr)
            return false;
    }
    return true;
}


bool isItSudoku(int matrix[9][9]) {
    // Write your code here.

    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            if(matrix[i][j] == 0)
            {
                for(int k = 1; k <= 9; ++k)
                {
                   if(isSafe(i, j, k, matrix))
                   {
                       matrix[i][j] = k;
                       
                       if(isItSudoku(matrix))
                         return true;
                       else 
                        matrix[i][j] = 0;
                   }
                }
                return false;
            }
        }
    }

    return true;
}
