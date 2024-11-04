















































































































































































































































































using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

vector<int> lc;
vector<int> rc;
int n, l, wmax;

bool check(int i, int j) {
	int xj = lc[j];
	int xi = rc[i];
	if (xi > xj) return false;
	int t1 = xj-xi-l, x1 = xi + xj + l;
	if (abs(x1) <= t1 * 1ll * wmax) return true;
	int t2 = xj-xi, x2 = xi + xj + 2*l;
	if (abs(x2) < t2 * 1ll * wmax) return true;
	int t3 = xj-xi, x3 = xi + xj;
	if (abs(x3) < t3 * 1ll * wmax) return true;
	int t4 = xj-xi + l, x4 = x1;
	if (abs(x4) < t4 * 1ll * wmax) return true;
	return false;
}

int main() {
	scanf("%d %d %d", &n, &l, &wmax);
	FOR1(i, n) {
		int x, v;
		scanf("%d %d", &x, &v);
		if (v == -1) lc.pb(x);
		if (v == 1) rc.pb(x);
	}
	sort(all(lc));
	sort(all(rc));
	ll ans = 0;
	FOR(i, rc.size()) {
		int lo = -1;
		int hi = lc.size();
		while(hi > lo + 1) {
			int j = (hi + lo) / 2;
			if (!check(i, j)) lo = j;
			else hi = j;
		}
		ans += int(lc.size()) - hi;
	}
	printf("%lld\n", ans);
	return 0;
}