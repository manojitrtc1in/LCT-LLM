

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <math.h>
#include <iomanip>
#include <sstream>
#include <map>
#include <fstream>
#include <algorithm>
using namespace std;




int main()
{
	int n, p, k;
	cin>>n>>p>>k;
	vector<pair<pair<long long, long long>, pair<int,bool> > > ab(n);
	vector<int> r;
	for(int i = 0; i < n; i++)
	{
		ab[i].second.first = i+1;
		ab[i].second.second = false;
		cin>>ab[i].first.second;
		cin>>ab[i].first.first;
		ab[i].first.second = -ab[i].first.second;
	}
	sort(ab.begin(), ab.end());
	for (int i = 0; i < p-k; i++)
	{
	

		ab[i].second.second = true;
	}
	for (int i = 0; i < ab.size(); i++)
	{
		swap(ab[i].first.first, ab[i].first.second);
		ab[i].first.second = -ab[i].first.second;
	}
	sort(ab.begin(), ab.end());
	int a = k;
	pair<long long, long long> mi = make_pair(1000000000,1000000000);
	for (int i = 0; i < ab.size(); i++)
	{
		if (ab[i].second.second == false && a > 0)
		{
			ab[i].second.second = true;
			r.push_back(ab[i].second.first);
			a--;
			if (make_pair(-ab[i].first.second,ab[i].first.first) < mi) mi = make_pair(-ab[i].first.second,ab[i].first.first);
		}
		else if (ab[i].second.second)
		{
			ab[i].second.second = false;
		}	
	}
	for (int i = 0; i < ab.size(); i++)
	{
		swap(ab[i].first.first, ab[i].first.second);
	}
	sort(ab.begin(), ab.end());
	a = p-k;
	for (int i = 0; i < ab.size(); i++)
	{
		if (a > 0)
		{
			if (make_pair(-ab[i].first.first,ab[i].first.second) <= mi && ab[i].second.second == false)
			{
			r.push_back(ab[i].second.first);
			a--;
			}
		}
		else break;
	}
	cout<<r[0];
	for (int i = 1; i < r.size(); i++)
	{
		cout<<" "<<r[i];
	}
	cout<<endl;

}


