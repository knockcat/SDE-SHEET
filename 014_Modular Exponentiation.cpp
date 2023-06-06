#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	// Write your code here.

	long res = 1;
	long mod = m;

	x %= mod;
			
	while(n > 0)
	{
		if(n & 1)
			res = (((res % mod)* x)% mod)%mod;
		
		x = (((x%mod)*x)%mod)%mod;

		n >>= 1;
	}

	return res % mod ;
	
}
