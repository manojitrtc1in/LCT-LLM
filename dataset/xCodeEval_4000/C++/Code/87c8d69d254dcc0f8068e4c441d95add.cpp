#include <iostream>
#include <random>
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
	int n;
	cin>>n;
	vector<vector<bool> > a(n, vector<bool>(100, false));
	vector<int> b(n, 0);
	for (int i = 0; i < n; i++)
	{
		int m;
		cin>>m;
		b[i] = m;
		for (int j = 0; j < m; j++)
		{
			int c;
			cin>>c;
			a[i][c-1] = true;
		}
	}
	for (int i =0; i < n; i++)
	{
		bool ok = true;
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			int rm = b[j];
			for (int k = 0; k < 100; k++)
			{
				if (a[i][k] && a[j][k])
					rm--;
			}
			if (rm <= 0)
			{
				ok = false;
				break;
			}
		}
		if (ok)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}


}