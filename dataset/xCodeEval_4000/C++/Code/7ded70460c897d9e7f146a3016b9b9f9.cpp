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
	int n4;
	cin>>n4;
	vector<long long> a(n4);
	vector<int> b(n4);
	int n44 = n4;
	int n = 0;
	while (n44 > 1)
	{
		n++;
		n44/=4;
	}
	n++;
	for (int i = 0; i < n4; i++)
	{
		scanf("%I64d",&a[i]);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n4;)
	{
		for (; i<n44; i++)
		{
			b[i] = n;
		}
		n--;
		n44*=4;
	}
	long long r = 0;
	for (int i =0; i < n4; i++)
	{
		r += a[n4-i-1]*b[i];
	}
	cout<<r<<endl;


}