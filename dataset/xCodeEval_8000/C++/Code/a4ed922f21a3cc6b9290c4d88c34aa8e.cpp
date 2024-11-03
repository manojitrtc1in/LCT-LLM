#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;




int main()
{
	std::ios::sync_with_stdio(false);
	int n,m,q;
	cin>>n>>m>>q;
	int a[45][45];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char ch;
			cin>>ch;
			if (ch == '0')
				a[i+1][j+1] = 1;
		}
	}
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <=m; j++)
		{
			a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
		}
	}
	int s[45][45][45][45] = {0};
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <=m; j++)
		{
			for (int x = i; x <=n; x++)
			{
				for (int y = j; y <=m; y++)
				{
					int ar = (x-i+1)*(y-j+1);
					int z = a[x][y]-a[x][j-1]-a[i-1][y]+a[i-1][j-1];
					if (ar == z)
						s[i][j][x][y] = 1;
					s[i][j][x][y] += s[i][j][x][y-1] + s[i][j][x-1][y] - (s[i][j][x-1][y-1]);
				}
			}
		}
	}
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <=m; j++)
		{
			for (int x = 1; x <=n; x++)
			{
				for (int y = 1; y <=m; y++)
				{
					s[x][y][i][j] += s[x][y-1][i][j] + s[x-1][y][i][j] - (s[x-1][y-1][i][j]);
				}
			}
		}
	}
	while (q--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		long long r = 0;
		r += s[c][d][c][d];
		r -= s[c][b-1][c][d];
		r -= s[a-1][d][c][d];
		r += s[a-1][b-1][c][d];
		cout<<r<<endl;
	}


}