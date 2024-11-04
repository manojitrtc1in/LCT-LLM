#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iomanip>
#include <math.h>
#include <bitset>
#include <sstream>
using namespace std;


#define PI 3.14159265











int main()
{
	int n, d;
	cin>>n>>d;
	vector<long long> a(n);
	for (int i=0; i < n; i++)
	{
		cin>>a[i];
	}
	int r = 0;
	for (int i=0; i < n; i++)
	{
		for (int j=i+1; j < n; j++)
		{
			if (abs(a[i]-a[j]) <= d) r++;
		}
	}
	cout<<r*2<<endl;
}