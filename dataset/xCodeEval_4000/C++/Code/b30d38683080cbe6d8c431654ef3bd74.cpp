
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
#include <string>
#define fi first
#define se second

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

const int N = (int)10e6 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;
using namespace std;

int e,d,n,m;
int a[N],b[N];
int main(){
	Speedforce
     cin>>e>>d>>n>>m;
     for(int i=1;i<=e;i++){
          cin>>a[i];
     }
     for(int i=1;i<=d;i++){
          cin>>b[i];
     }
     sort(a+1,a+e+1);
     sort(b+1,b+d+1);
     if(a[n]<b[d-m+1]){
          return cout<<"YES",0;
     }
     return cout<<"NO",0;
}
