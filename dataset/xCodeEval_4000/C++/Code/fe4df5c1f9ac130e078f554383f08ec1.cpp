

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






vector<long long> dp;
vector<long long> a;
int main()
{
	string s;
	cin>>s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'F') a.push_back(i);
	}
	dp = vector<long long> (a.size(),0);
	if (dp.size() > 0) dp[0] = a[0];
	for (int i = 1; i < a.size(); i++)
	{
		if (a[i]-i == 0) dp[i] = 0;
		else if (a[i]-i <= dp[i-1])
			dp[i] = dp[i-1]+1;
		else dp[i] = a[i]-i;
	}
	if (dp.size() > 0)
		cout<<dp[a.size()-1]<<endl;
	else cout<<0<<endl;
}