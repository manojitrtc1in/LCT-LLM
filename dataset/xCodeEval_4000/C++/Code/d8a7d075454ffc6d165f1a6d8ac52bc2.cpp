


























































































































































































































































#include <bits/stdc++.h>
#define DEBUG false
#define debugf if (DEBUG) printf
#define MAXN 200309
#define MAXM 900009
#define ALFA 256
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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> ii;

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x%y);
}

int n, m;

int main() {
	vector<ii> ans;
	scanf("%d %d", &n, &m);
	if (m < n-1) {
		printf("Impossible\n");
		return 0;
	}
	for(int u = 1; u <= n && m > 0; u++) {
		for(int v = u+1; v <= n && m > 0; v++) {
			if (gcd(u, v) == 1) {
				m--;
				ans.pb({u, v});
			}
		}
	}
	if (m > 0) {
		printf("Impossible\n");
		return 0;
	}
	else {
		printf("Possible\n");
		for(auto p : ans) printf("%d %d\n", p.fi, p.se);
	}
	return 0;
}