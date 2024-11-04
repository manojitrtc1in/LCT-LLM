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
using namespace std;
#define havetxt 0
#define shuru "input.txt"
#define shuchu "output.txt"
#define inf 0x7fffffff
#define esp 1e-9
#define pb push_back
#define mp make_pair
typedef long long ll;




























ll A[5];
ll B[5];
ll n;

inline int query(ll a[])
{
	cout<<"? "<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3];
	cout<<endl;
	
	fflush(stdout);
	
	int res;
	
	cin>>res;
	
	return res;
}


void fix(ll a[],int k)
{
	ll ki=a[0],ka=a[2];
	if(k%2) ki=a[1],ka=a[3];
	
	while(ki<=ka)
	{
		ll mid=(ki+ka)>>1;
		
		ll b[5];
		
		for(int i=0;i<4;i++)
		{
			b[i]=a[i];
		}
		b[k]=mid;
		
		if(query(b))
		{
			if(k>1) ka=mid-1;
			else ki=mid+1;
		}
		else
		{
			if(k>1) ki=mid+1;
			else ka=mid-1;
		}
	}
	
	if(k>=2) a[k]=ki;
	else a[k]=ka;
}

void f1(ll a[])
{
	fix(a,3);
	fix(a,2);
	fix(a,0);
	fix(a,1);
}

void f2(ll a[])
{
	fix(a,1);
	fix(a,0);
	fix(a,2);
	fix(a,3);
}

int main()
{
	cin>>n;
	
	A[0]=A[1]=1;
	A[2]=A[3]=n;
	
	B[0]=B[1]=1;
	B[2]=B[3]=n;
	
	f1(A);
	f2(B);
	
	cout<<"! ";
	for(int k=0;k<4;k++)
	{
		cout<<A[k]<<' ';
	}
	
	for(int k=0;k<4;k++)
	{
		cout<<B[k]<<' ';
	}
	cout<<endl;
	
	fflush(stdout);
	
	return 0;
}
