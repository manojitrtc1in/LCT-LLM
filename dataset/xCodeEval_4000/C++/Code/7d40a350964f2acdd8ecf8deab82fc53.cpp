
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <complex>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define f first
#define s second

#define pb push_back
#define pp pop_back
#define mp make_pair

#define sz(x) (int)x.size()
#define sqr(x) ((x) * 1ll * (x))
#define all(x) x.begin(), x.end()


#define Speedforce ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = (int)5e5 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;
using namespace std;

int a[N],sum[N];
int cnt,ans;
int main(){
	Speedforce
    int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum[i%k]+=a[i];
	}
	int mn=(int)1e9,ans;

	for(int i=0;i<k;i++){
		if(mn>sum[i]){
			mn=sum[i];
			ans=i%k+1;
		}
	}
	printf("%d",ans);
	return 0;
}