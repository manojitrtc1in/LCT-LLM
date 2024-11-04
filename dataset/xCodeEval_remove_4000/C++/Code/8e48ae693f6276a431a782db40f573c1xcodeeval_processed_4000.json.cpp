















































































































































































































































































using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

vector<ii> lc;
vector<ii> rc;
int n, l, wmax;

int check(int i, int j) {
	int xj = lc[j].first;
	int xi = rc[i].first;
	if (xi > xj) return -1;
	int t1 = xj-xi-l, x1 = xi + xj + l;
	if (abs(x1) <= t1 * 1ll * wmax) return 0;
	int t2 = xj-xi, x2 = xi + xj + 2*l;
	if (abs(x2) < t2 * 1ll * wmax) return 0;
	int t3 = xj-xi, x3 = xi + xj;
	if (abs(x3) < t3 * 1ll * wmax) return 0;
	int t4 = xj-xi + l, x4 = x1;
	if (abs(x4) < t4 * 1ll * wmax) return 0;
	return -1;
}

void brute() {
	FOR(i, rc.size()) FOR(j, lc.size()) {
		printf("check(%d, %d) = %d\n", rc[i].second, lc[j].second, check(i, j));
	}
}

int main() {
	scanf("%d %d %d", &n, &l, &wmax);
	FOR1(i, n) {
		int x, v;
		scanf("%d %d", &x, &v);
		if (v == -1) lc.pb(ii(x, i));
		if (v == 1) rc.pb(ii(x, i));
	}
	sort(all(lc));
	sort(all(rc));
	

	ll ans = 0;
	FOR(i, rc.size()) {
		int lb, ub;
		int lo = -1;
		int hi = lc.size();
		while(hi > lo + 1) {
			int j = (hi + lo) / 2;
			if (check(i, j) < 0) lo = j;
			else hi = j;
		}
		lb = hi;
		lo = -1;
		hi = lc.size();
		while(hi > lo + 1) {
			int j = (hi + lo) / 2;
			if (check(i, j) > 0) hi = j;
			else lo = j;
		}
		ub = hi;
		ans += ub - lb;
		

	}
	printf("%lld\n", ans);
	return 0;
}