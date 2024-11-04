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
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;




int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	multiset<int> s;
	for (int i =0; i < n; i++)
	{
		cin>>a[i];
	}
	sort(a.begin(), a.end());
	int r = 0;
	vector<int> h;
	for (int i = 0; i < n/2; i++)
	{
		s.insert(a[i]);
	}
	for (int i = n/2; i < n; i++)
	{
		h.push_back(a[i]);
	}
	for (int i = h.size()-1; i>=0; i--)
	{
		r++;
		if (s.empty()) continue;
		multiset<int>::iterator j = s.upper_bound((h[i])/2);
		if (j != s.begin())
		{
			j--;
			s.erase(j);
		}
	}
	cout<<r+s.size()<<endl;


}