#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
#define havetxt 0
#define shuru "input.txt"
#define shuchu "output.txt"
#define inf 0x7fffffff
#define esp 1e-9
#define pb push_back
#define mp make_pair
typedef long long ll;




























int a[222222];
int c[222222];
int b[444444];
int gc[222222];
ll ans;
int mx[222222];
int n;

inline mygcd(int a,int b)
{
	if(a%b==0)
	{
		return b;
	}
	return mygcd(b,a%b);
}

int main()
{
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	
	for(int i=1;i<n;i++)
	{
		gc[i]=mygcd(i,n);
	}
	
	for(int k=1;k<n;k++)
	{
		if(n%k) continue;
		
		for(int i=1;i<n;i++)
		{
			c[i]=c[i-1]+(gc[i]==k);
		}
		
		for(int i=0;i<k;i++)
		{
			mx[i]=-1;
		}
		
		for(int i=0;i<n;i++)
		{
			mx[i%k]=max(mx[i%k],a[i]);
		}
		
		for(int i=0;i<n;i++)
		{
			if(a[i]==mx[i%k])
			{
				b[i]=1;
			}
			else
			{
				b[i]=0;
			}
			
			b[i+n]=b[i];
		}
		
		for(int i=2*n-2;i>=0;i--)
		{
			if(b[i])
			{
				b[i]+=b[i+1];
			}
		}
		
		for(int i=0;i<n;i++)
		{
			ans+=c[min(n-1,b[i])];
		}
	}
	
	printf("%I64d\n",ans);
	
	return 0;
}
