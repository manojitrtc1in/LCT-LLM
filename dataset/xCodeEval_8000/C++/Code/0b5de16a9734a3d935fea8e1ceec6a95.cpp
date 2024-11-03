#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
using namespace std;



vector<pair<int, pair<int,int> > >edges;
long long n,m;
vector<int> p;
vector<long long> sz;
int find(int i)
{
	if (p[i] == i) return i;
	return p[i] = find(p[i]);
}
long long un(int i, int j)
{
	int a,b;
	a = find(i);
	b = find(j);
	long long r = sz[a]*sz[b];
	p[a] = b;
	sz[b] += sz[a];
	return r;
}
bool con(int i, int j)
{
	return find(i) == find(j);
}


int main()
{
	cin>>n>>m;
	vector<int> a(n);
	sz = vector<long long>(n,1);
	p = vector<int>(n,-1);
	for (int i = 0; i < n; i++){
		cin>>a[i];
		p[i] = i;
	}
	
	for (int i = 0; i < m; i++)
	{
		int x,y;
		cin>>x>>y;
		edges.push_back(make_pair(min(a[x-1],a[y-1]), make_pair(x-1,y-1)));
	}
	sort(edges.begin(), edges.end());
	double res = 0.0;
	for (int i = m-1; i>=0; i--)
	{
		if (con(edges[i].second.first, edges[i].second.second)) continue;
		res += ((2.0*edges[i].first)/(n*(n-1.0)))*un(edges[i].second.first, edges[i].second.second);
	}
	cout<<fixed<<setprecision(10)<<res<<endl;
	
}