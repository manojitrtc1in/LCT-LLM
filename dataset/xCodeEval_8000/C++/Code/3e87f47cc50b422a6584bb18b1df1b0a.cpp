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
	cin.sync_with_stdio(false);
	string s;
	cin>>s;
	int n = s.size();
	vector<vector<int> > a(n, vector<int>(27, n));
	for (int i = s.size()-1; i >= 0; i--)
	{
		if (i < s.size() -1)
		{
			for (int j = 0; j <= 26; j++)
			{
				a[i][j] = a[i+1][j];
			}
		}
		a[i][s[i]-'a'] = i;
	}

	int mx = 0;
	for (int i = 0; i <= 26; i++) if (a[0][i] < n) mx++;
	cout<<mx<<endl;
	vector<int> al(27);
	vector<long long> t(mx);
	for (int j = 0; j < n; j++)
	{
		al = a[j];
		sort(al.begin(), al.end());
		for (int i = 0; i < mx; i++) t[i] += (long long)(al[i+1]-al[i]);
	}
	for (int i = 0; i < mx; i++) cout<<t[i]<<endl;


}