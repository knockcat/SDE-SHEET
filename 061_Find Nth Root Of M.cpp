int NthRoot(int n, int m) {
  // Write your code here.

  int start = 1, end = m;

  int ans = -1;

  while(start <= end)
  {
    int mid = start + (end - start)/2;

    long long x = 1;

    for(int i = 1; i <= n ; ++i)
    {
      x *= mid;

      if(x > m)
        break;
    }

    if(x == m)
    {
      ans = mid;
      break;
    }
    
    if(x > m)
      end = mid - 1;
    else
      start = mid+1;
  }

  return ans;
}
