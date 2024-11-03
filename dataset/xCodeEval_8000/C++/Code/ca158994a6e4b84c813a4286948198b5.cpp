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



int main()
{
	int n,m;
	cin>>n>>m;
	vector<double> x(n);
	for (int i = 0; i < n; i++) cin>>x[i];
	double mx = 0.0;
	for (int i = 0; i < m; i++)
	{
		int a,b;
		double c;
		cin>>a>>b>>c;
		mx = max(mx, (x[a-1]+x[b-1]) / c);
	}
	cout<<fixed<<setprecision(15)<<mx<<endl;
}