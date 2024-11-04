















































































































































































































































































using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

vi st[4*MAXN];
int n, q, p;

void update(int k, int a, int b, int l, int r, int x) {
	if (l > b || r < a) return;
	if (l >= a && r <= b) {
		

		st[k].pb(x);
		return;
	}
	int m = (l + r) / 2;
	update(2*k, a, b, l, m, x);
	update(2*k+1, a, b, m+1, r, x);
}

bitset<MAXN> pos[4*MAXN];

void relax(int i) {
	pos[i][0] = true;
	for(int x : st[i]) {
		pos[i] |= (pos[i]<<x);
		
	}
	st[i].clear();
}

void solve() {
	for(int i = p+n-1, j; i > 1; i--) {
		j = i>>1;
		relax(i);
		
		pos[j] |= pos[i];
	}
}

int main() {
	scanf("%d %d", &n, &q);
	for(p = 1; p < n; p <<= 1);
	FOR(i, 4*MAXN) pos[i].reset();
	FOR(i, q) {
		int l, r, x;
		scanf("%d %d %d", &l, &r, &x);
		update(1, l-1, r-1, 0, n-1, x);
	}
	solve();
	relax(1);
	vi ans;
	FOR1(i, n) {
		if (pos[1][i]) ans.pb(i);
	}
	printf("%u\n", ans.size());
	for(int x : ans) {
		printf("%d ", x);
	}
	printf("\n");
	return 0;
}