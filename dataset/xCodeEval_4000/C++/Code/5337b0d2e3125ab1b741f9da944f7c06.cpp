

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iomanip>
#include <math.h>
#include <bitset>
#include <sstream>
using namespace std;



double abss(double a)
{
	if (a < 0) return -a;
	return a;
}

int main()
{
	int n;
	cin>>n;
	double c;
	int z = 0;
	vector<double> a;
	for (int i=0; i < 2*n ;i++)
	{
		cin>>c;
		double d = c - (int)(c);
		if (d > 0)
		{
			a.push_back(d);
		}
		else z++;
	}
	double res = 0;
	for (int i = 0; i < a.size(); i++)
	{
		res -= a[i];
	}
	res += max(0,n-z);
	double minr = abss(res);
	for (int i = 0; i <= z; i++)
	{
		minr = min(minr,abss(res+i));
	}
	
	cout<<fixed<<setprecision(3)<<minr<<endl;


}