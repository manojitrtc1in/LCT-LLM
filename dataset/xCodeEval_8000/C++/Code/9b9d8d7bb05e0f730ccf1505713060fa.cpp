#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iomanip>
#include <math.h>
#include <bitset>
#include <sstream>
using namespace std;


#define PI 3.14159265





long long mod(long long a, long long m)
{
	if (a <0) return (a+m)%m;
	else return a%m;
}

long long pow1(long long a, long long p, long long m)
{
	if (p == 0)
	{
		return 1;
	}
	if (p%2==0)
	{
		long long r = pow1(a,p/2,m);
		return (r*r)%m;
	}
	else
	{
		return (a*pow1(a,p-1,m))%m;
	}
}



long long dp[3005][2];
int a[3005][3];
int n;

long long sol(int i, int p)
{
	if (i == n) return 0;
	if (dp[i][p] != -1) return dp[i][p];
	if (p == 1)
	{
		long long r = 0;
		r = a[i][1] + sol(i+1,1);
		if (i < n-1) r = max(r,a[i][2] + sol(i+1,0));
		return dp[i][p] = r;
	}
	else
	{
		long long r = 0;
		r = a[i][0] + sol(i+1,1);
		if (i < n-1) r = max(r,a[i][1] + sol(i+1,0));
		return dp[i][p] = r;
	}
}

int main()
{
	cin>>n;
	for (int k = 0; k < 3; k++)for (int i = 0; i < n; i++)
	{
		cin>>a[i][k];
	}
	for (int i=0; i< n; i++)
	{
		for (int j = 0; j <= 1; j++)
		{
			dp[i][j] = -1;
		}
	}
	long long r = sol(0,0);
	cout<<r<<endl;


}