#include <iostream>
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
	vector<pair<long long,int> > a(m);
	for (int i =0; i < m ;i++)
	{
		cin>>a[i].second;
		cin>>a[i].first;
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	long long gr = 1;
	long long need = 1;
	while (need <= n)
	{
		gr++;
		if (gr%2 == 0)
		{
			need = gr*((gr-1)/2 + 1);
		}
		else
		{
			need = gr*((gr-1)/2) + 1;
		}
	}


	gr--;
	long long res = 0;
	for (int i = 0; i < gr && i < m; i++)
	{
		res += a[i].first;
	}
	cout<<res<<endl;
	

}