  	

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define mp make_pair
#define pb push_back
#define all(n) (n).begin,(n).end
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef vector<int> vi;
const int INF=1e9+7;

int n,m;
int w[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int a[1000005];
int num;
char ss[10000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for(int i=1;i<=12;i++) 
	w[i]+=w[i-1];
	scanf("%d%d",&n,&m);
	gets(ss);
	while(gets(ss))
	{
		int y,m,d,h,mm,s;
		sscanf(ss,"%d-%d-%d %d:%d:%d",&y,&m,&d,&h,&mm,&s);
		int sec=w[m-1]+d-1;
		sec*=86400;
		sec+=h*3600+mm*60+s;
		a[num++]=sec;
	}
	
	int l=0;
	for(int i=0;i<num;i++){
		while(a[i]-a[l]>=n) l++;
		if(i-l+1>=m){
			int s=a[i]%60;
			int m=a[i]%3600/60;
			int h=a[i]%86400/3600;
			int d=a[i]/86400;
			int M=0;
			for(;w[M]<=d;M++);
			d-=w[M-1];
			printf("2012-%02d-%02d %02d:%02d:%02d",M,d+1,h,m,s);
			return 0;
		}
	}
	puts("-1");
	return 0;
}
