

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iomanip>
#include <math.h>
#include <bitset>
#include <sstream>
using namespace std;






int main()
{
	int n,l,r,q1,q2;
	cin>>n>>l>>r>>q1>>q2;
	vector<int> a(n+1);
	vector<long long> s(n+1,0); 
	for (int i = 1; i <= n; i++)
	{
		cin>>a[i];
		s[i] += a[i];
		s[i] += s[i-1];
	}
	long long res = 100000000000;
	for (int i = 0; i <= n; i++)
	{
		long long c =0 ;
		c = s[i]*l + (s[n]-s[i])*r;
		if (abs(n-i-i) > 1)
		if (i >= (n)/2)
		{
			c += ((i - (n-i)) - 1)*q1;
		}
		else
		{
			c += (((n-i)- i)-1)*q2;
		}
		res = min(res,c);
	}
	cout<<res<<endl;
}