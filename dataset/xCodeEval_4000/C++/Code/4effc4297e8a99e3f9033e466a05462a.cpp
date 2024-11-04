#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;



int main()
{
	int n, m;
	cin>>n>>m;
	int k;
	cin>>k;
	vector<vector<int> > a(n, vector<int> (m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin>>a[i][j];
		}
	}
	vector<pair<int,int> > tmp(m);
	vector<pair<int,int> > res;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < res.size(); j++)
		{
			int c,d;
			c = res[j].first-1;
			d = res[j].second-1;
			if (a[i][c] > a[i][d])
			{
				swap(a[i][c], a[i][d]);
			}
		}
		for (int j = 0; j < m; j++)
		{
			tmp[j].first = a[i][j];
			tmp[j].second = j;
		}
		

		sort(tmp.begin(), tmp.end());
		if (k)
			reverse(tmp.begin(), tmp.end());
		for (int j = 0; j < m; j++)
		{
			while (j > tmp[j].second)
			{
				tmp[j].second = tmp[tmp[j].second].second;
			}
			if (j == tmp[j].second) continue;
			
			if (k)
			{
				res.push_back(make_pair(tmp[j].second+1, j+1));
			}
			else
			{
				res.push_back(make_pair(j+1,tmp[j].second+1));
			}
		}
	}

	cout<<res.size()<<endl;
	for (int i = 0; i < res.size(); i++)
	{
		cout<<res[i].first<<" "<<res[i].second<<endl;
	}


}