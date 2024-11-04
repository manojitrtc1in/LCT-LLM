#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef  long double ldb;
typedef long long ll;
typedef double dbl;
const int inf = 1e9+7;
const ll llinf = 1e18+7;
const dbl eps = 1e-15;
const int mod = 1e9+7;
#define speed ios::sync_with_stdio(false)
#define lop(i,n) for (int i=0;i<int(n);i++)
#define rng(i,a,b) for (int i=a;i<int(b);i++)
#define pb(x) push_back(x)
#define sz(x) sizeof(x)
#define CLEAR(x,a) memset(x,a,sz(x))










int n,a[100001];
int ans,c;
int main(){
speed;
cin>>n;
for(int i=0;i<n;i++){
			cin>>c;
			a[c]=a[c-1]+1;
			ans=max(ans,a[c]);
		}
cout<<(n-ans);
return 0;
}






























