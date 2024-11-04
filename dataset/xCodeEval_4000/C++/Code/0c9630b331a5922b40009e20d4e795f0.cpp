#include			  <algorithm>
#include			   <iostream>
#include				<cstring>
#include				<stdio.h>
#include				 <string>
#include			     <vector>
#include				 <time.h>
#include				  <queue>
#include				  <cmath>
#include				    <map>
#include				    <set>
#include <fstream>
using	namespace	    	 std;
typedef	long long    		  vt;
typedef unsigned long long   vt2;
typedef	pair<vt, vt>		     PVV;
typedef	pair<char, vt>	     PCV;
typedef	pair<string, vt>     PSV;
typedef	map<vt, vt>			 MVV;
typedef map<char, vt>	     MCV;
typedef map<string, vt>	     MSV;
#define fi(x,y) for(int i=x;i<y;i++)
#define fj(x,y) for(int j=x;j<y;j++)
#define fk(x,y) for(int k=x;k<y;k++)
const int MAXN = (1 << 18) + 99, INF = 0x3f3f3f3f;
vt HASHprime = 13331;



int vis[MAXN];
int main()
{
	int n, x;
	cin >> n >> x;
	fi(0, 1 << n)
	{
		if (!vis[i])
			vis[i ^ x] = 1;
	}
	int k = 0;
	vector<int> v;
	fi(1, 1 << n)
	{
		if (!vis[i])
		{
			v.push_back(i ^ k);
			k = i;
		}
	}
	cout << v.size() << endl;
	for (auto& it : v)
		cout << it << " ";
	return 0;
}
