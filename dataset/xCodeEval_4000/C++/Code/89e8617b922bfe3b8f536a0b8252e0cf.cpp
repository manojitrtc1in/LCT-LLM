#include <iostream>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



int main()
{
	int n, m;
	cin>>n>>m;
	vector<pair<int,int> > a(m+1, make_pair(0,0));
	vector<pair<int,int> > b(m+1, make_pair(0,0));
	for (int i = 0; i < n; i++)
	{
		int c;
		cin>>c;
		a[c].first++;
		a[c].second =c;
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	b = a;
	vector<pair<int,int> > r(n);
	int res = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (a[i].first)
			{
				if (b[(j+i)%m].first)
				{
					int c = min(a[i].first, b[(j+i)%m].first);
					for (int k = 0; k < c; k++)
					{
						r[res].first = a[i].second;
						r[res].second = b[(j+i)%m].second;
						res++;
						a[i].first--;
						b[(i+j)%m].first--;
					}
				}
			}
		}
	}
	cout<<res<<endl;
	for (int i = 0;i < res; i++)
	{
		cout<<r[i].first<<" "<<r[i].second<<endl;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < b[i].first; j++)
		{
			cout<<b[i].second<<" "<<b[i].second<<endl;
		}
	}


}