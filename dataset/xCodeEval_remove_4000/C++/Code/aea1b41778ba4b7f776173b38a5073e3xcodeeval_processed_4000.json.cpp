
















































































































































































































































































using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> ii;

int a[MAXN], n, k;

int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x%y);
}

int main() {
	scanf("%d %d", &n, &k);
	FOR(i, n) {
		scanf("%d", &a[i]);
	}
	int g = k;
	FOR(i, n) {
		g = gcd(g, a[i]);
	}
	vi ans;
	FOR(i, k) {
		if (i % g == 0) ans.pb(i);
	}
	printf("%u\n", ans.size());
	for(int i : ans) printf("%d ", i);
	printf("\n");
	return 0;
}