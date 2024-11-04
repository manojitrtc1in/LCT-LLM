


#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
using namespace std;



vector<vector<int> > g;
vector<bool> taken;
vector< vector<int> > teams;
void dfs(int u, int x)
{
	taken[u] = true;
	teams[x].push_back(u);
	for (int i=0; i < g[u].size(); i++)
	{
		if (!taken[g[u][i]])
		{
			dfs(g[u][i], x);
		}
	}
}

int main()
{
	int n, m;
	cin>>n>>m;

	taken = vector<bool> (n+1);
	g = vector< vector<int> > (n+1);
	teams = vector<vector<int> > (n+1);
	int a, b;
	for (int i=0; i < m; i++)
	{
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i=1; i <= n; i++)
	{
		if (!taken[i])
			dfs(i, i);
	}
	for (int i=0; i <=n; i++)
	{
		taken[i] = false;
	}
	vector<pair<int, vector<int> > > res, res2, res3;
	int cur;
	bool put = false, ok = true;
	for (int i=1; i <= n; i++)
	{
		if (!taken[i])
		{
			taken[i] = true;
			if (teams[i].empty())
				continue;
			if (teams[i].size() == 1)
			{
				res.push_back(make_pair(1, teams[i]));
			}
			else if (teams[i].size() == 2)
			{
				res2.push_back(make_pair(2, teams[i]));
			}
			else
			{
				if (teams[i].size() > 3) ok = false;
				res3.push_back(make_pair(teams[i].size(), teams[i]));
			}
		}	
	}
	if (res2.size() > res.size()) ok = false;
	else
	{
		int count = 0;
		for (count = 0; count < res2.size(); count++)
		{
			res3.push_back(make_pair(3,vector<int>()));
			res3[res3.size()-1].second.push_back(res2[count].second[0]);
			res3[res3.size()-1].second.push_back(res2[count].second[1]);
			res3[res3.size()-1].second.push_back(res[count].second[0]);
		}
		int sz = res.size() - count;
	

		if (sz % 3 != 0)
		{
			ok = false;
		}
		else
		for (int i = 0; i < sz-2; i += 3)
		{
			

			res3.push_back(make_pair(3,vector<int>(3)));
			res3[res3.size()-1].second[0] = (res[count+i].second[0]);
			

			res3[res3.size()-1].second[1] = (res[count+i+1].second[0]);
			

			res3[res3.size()-1].second[2] = (res[count+i+2].second[0]);
		}
		
	}
	
	if (!ok) cout<<-1<<endl;
	else
	{
		

		for (int i=0; i < res3.size(); i++)
		{	

			cout<<res3[i].second[0]<<" "<<res3[i].second[1]<<" "<<res3[i].second[2]<<endl;
		}
	}
}