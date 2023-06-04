#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here

   int zero = 0, start = 0, end = n-1;

   while(start <= end)
   {
      if(arr[start] == 0)
      {
         swap(arr[start++], arr[zero++]);
      }
      else if(arr[start] == 2)
      {
         swap(arr[start], arr[end--]);
      }
      else
         ++start;
   }
}
