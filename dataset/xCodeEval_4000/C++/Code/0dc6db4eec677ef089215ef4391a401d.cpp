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




vector<int> g;
vector<vector<int> > t;
vector<int> in;
vector<int> r;
void dfs(int i, int p, int odd, int ev, int d)
{
	if (d%2==0)
	{
		in[i] += (ev%2);
		in[i]%=2;
		if (g[i] == in[i])
		{
			for (int j=0; j < t[i].size(); j++)
			{
				if (t[i][j] == p) continue;
				dfs(t[i][j], i, odd,ev,d+1);
			}
		}
		else
		{
			r.push_back(i+1);
			for (int j=0; j < t[i].size(); j++)
			{
				if (t[i][j] == p) continue;
				dfs(t[i][j], i, odd, ev+1, d+1);
			}
		}
	}
	else
	{
		in[i] += (odd%2);
		in[i]%=2;
		if (g[i] == in[i])
		{
			for (int j=0; j < t[i].size(); j++)
			{
				if (t[i][j] == p) continue;
				dfs(t[i][j], i, odd, ev, d+1);
			}
		}
		else
		{
			r.push_back(i+1);
			for (int j=0; j < t[i].size(); j++)
			{
				if (t[i][j] == p) continue;
				dfs(t[i][j], i, odd+1, ev, d+1);
			}
		}
	}
}

int main()
{
	int n;
	cin>>n;
	t = vector<vector<int> > (n);
	g = vector<int> (n);
	in = vector<int> (n);
	for (int i = 0; i < n-1; i++)
	{
		int a,b;
		cin>>a>>b;
		t[a-1].push_back(b-1);
		t[b-1].push_back(a-1);
	}
	for (int i = 0; i < n; i++) cin>>in[i];
	for (int i = 0; i < n; i++) cin>>g[i];
	dfs(0,0,0,0,0);
	cout<<r.size()<<endl;
	for (int i = 0; i < r.size(); i++)
	{
		cout<<r[i]<<endl;
	}
}