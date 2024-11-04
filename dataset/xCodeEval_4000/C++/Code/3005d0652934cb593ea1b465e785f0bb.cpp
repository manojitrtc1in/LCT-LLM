


























































































































































































































































#include <bits/stdc++.h>
#define DEBUG false
#define debugf if (DEBUG) printf
#define MAXN 200309
#define MAXM 509
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

const ll neutral = 0;
ll comp(ll a, ll b) {
	return a+b;
}

class SegmentTree {
	vector<ll> a;
	int n;
public:
	SegmentTree() {}
	SegmentTree(ll* st, ll* en) {
		int sz = int(en-st);
		for (n = 1; n < sz; n <<= 1);
		a.assign(n << 1, neutral);
		for(int i=0; i<sz; i++) a[i+n] = st[i];
		for(int i=n+sz-1; i; i--)
			a[i>>1] = comp(a[i>>1], a[i]);
	}
	void update(int i, ll x) {
		a[i+n] = x; 

		for (i += n, i >>= 1; i; i >>= 1)
			a[i] = comp(a[i<<1], a[1+(i<<1)]);
	}
	ll query(int l, int r) {
		if (l > r) return neutral;
		ll ans = neutral;
		for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ans = comp(ans, a[l++]);
			if (r & 1) ans = comp(ans, a[--r]);
		}
		return ans;
	}
};

set<ii> bit[60];
ll a[MAXN];

int getBit(ll x) {
	int ans = 0, cnt = 0;
	while(x > 0) {
		cnt++;
		if (x & 1) ans = cnt;
		x >>= 1;
	}
	return ans;
}

SegmentTree st;

int getZero() {
	FOR(b, 60) {
		if (bit[b].size() >= 1u) {
			int i = bit[b].begin()->fi;
			if (st.query(0, i-1) == a[i]) return i+1;
		}
		if (bit[b].size() >= 2u) {
			int i = (++bit[b].begin())->fi;
			if (st.query(0, i-1) == a[i]) return i+1;
		}
	}
	return -1;
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	FOR(i, n) {
		scanf("%lld", &a[i]);
		bit[getBit(a[i])].insert(ii(i, a[i]));
	}
	st = SegmentTree(a, a+n);
	FOR(j, q) {
		int i;
		ll x;
		scanf("%d %lld", &i, &x);
		i--;
		bit[getBit(a[i])].erase(ii(i, a[i]));
		a[i] = x;
		st.update(i, x);
		bit[getBit(a[i])].insert(ii(i, a[i]));
		printf("%d\n", getZero());
	}
	return 0;
}