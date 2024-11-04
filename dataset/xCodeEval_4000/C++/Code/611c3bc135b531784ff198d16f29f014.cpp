#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "stdio.h"
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
using namespace std;




int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<bool> a(n, false);
	int kk;
	for (int i = 0; i < k; i++) {cin>>kk;a[kk-1] = true;}
	if (k == n) cout<<-1<<endl;
	else
	{
		if ((n*(n-1))/2 - k+1 < m)
		{
			cout<<-1<<endl;
			return 0;
		}
		int c = -1;
		int d = -1;
		for (int i = 0; i < n; i++)
		{
			if (a[i]) c = i;
			else d =i;
		}
		int rem = m;
		for (int i = 0; i < n; i++)
		{
			if (i == d) continue;
			rem--;
			cout<<i+1<<" "<<d+1<<endl;
		}
		for (int i = 0; i < n; i++)
		{
			if (i==d) continue;
			if (i == c) continue;
			if (rem == 0) break;
			for (int j= 0; j < i; j++)
			{
				if (!a[i] && j == c) {
				rem--;
				cout<<i+1<<" "<<j+1<<endl;
				}
			}
			for (int j= i+1; j < n; j++)
			{
				if (j == d) continue;
				if (rem==0) break;
				if (a[i] && j == c) continue;
				rem--;
				cout<<i+1<<" "<<j+1<<endl;
			}
		}
	}
}