#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here

    int top = 0, bottom =m-1 , right = n-1, left = 0;

    while(top < bottom and left < right)
    {
        int temp = mat[top][left];
        int temp2 = 0;

        for(int i = left + 1; i <= bottom; ++i)
        {
            temp2 = mat[top][i];
            mat[top][i] = temp;
            temp = temp2;
        }
        

        for(int i = top +  1; i <= right; ++i)
        {
            temp2 = mat[i][bottom];
            mat[i][bottom] = temp;
            temp = temp2;
        }


        for(int i = bottom-1; i>=left; --i)
        {
            temp2 = mat[right][i];
            mat[right][i] = temp;
            temp = temp2;
        }


        for(int i = right-1; i > top; --i)
        {
            temp2 = mat[i][left];
            mat[i][left] = temp;
            temp = temp2;
        }

        mat[top][left] = temp;

        ++top;
        --right;
        --bottom;
        ++left;
    }

    

}
