


























































































































































































































































#include <bits/stdc++.h>
#define DEBUG false
#define debugf if (DEBUG) printf
#define MAXN 200309
#define MAXM 900009
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for(int x=0; (x)<int(n); (x)++)
#define FOR1(x,n) for(int x=1; (x)<=int(n); (x)++)
#define REP(x,n) for(int x=int(n)-1; (x)>=0; (x)--)
#define REP1(x,n) for(int x=(n); (x)>0; (x)--)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
#define all(x) x.begin(), x.end()
#define mset(x,y) memset(&x, (y), sizeof(x));
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

ll a[MAXN], prv[MAXN], sum[MAXN], k;
int n;

bool check(ll p, ll s) {
	if (p % s != 0) return false;
	return (p / s == k);
}

int main() {
	scanf("%d %lld", &n, &k);
	prv[0] = 0;
	sum[0] = 0;
	FOR1(i, n) {
		scanf("%lld", &a[i]);
		sum[i] = a[i] + sum[i-1];
		if (a[i] != 1) prv[i] = i;
		else prv[i] = prv[i-1];
	}
	ll ans = 0;
	FOR1(i, n) {
		ll p = 1;
		ll s = 0;
		for(int j = i, cnt = 0; j > 0 && cnt < 70; j--, cnt++) {
			if (p > INFLL/a[j]) break;
			p *= a[j];
			s += a[j];
			if (a[j] == 1) {
				int prvj = j;
				ll prvs = s;
				j = prv[j]+1;
				s = sum[i] - sum[j-1];
				

				if (p%k == 0 && k*s > p && k*prvs <= p) {
					

					ans++;
				}
			}
			

			if(check(p, s)) {
				

				ans++;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}