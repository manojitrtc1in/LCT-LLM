

















































































































































































































































































using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, x[MAXN], in[MAXN];
ll a[MAXN], b[MAXN], t;
ll mn[MAXN], mx[MAXN];

int main() {
	bool ok = true;
	scanf("%d %lld", &n, &t);
	FOR1(i, n) {
		scanf("%lld", &a[i]);
		mn[i] = a[i]+t;
		mx[i] = 3*(1e+18);
		in[i] = 0;
	}
	FOR1(i, n) {
		scanf("%d", &x[i]);
		if (x[i] < i) ok = false;
		if (x[i] < n) mx[x[i]] = min(mx[x[i]], a[x[i]+1]+t-1);
		in[x[i]]++;
	}
	REP1(i, n) {
		if (i < n) in[i] += in[i+1];
		if (n-i+1 < in[i]) mn[i-1] = max(mn[i-1], a[i]+t);
	}
	FOR1(i, n) {
		if (i == 1) continue;
		mn[i] = max(mn[i], mn[i-1]+1);
	}
	REP1(i, n) {
		if (i == n) continue;
		mx[i] = min(mx[i], mx[i+1]-1);
	}
	FOR1(i, n) {
		if (mx[i] < mn[i]) ok = false;
		

	}
	if (ok) {
		printf("Yes\n");
		FOR1(i, n) printf("%lld ", (mx[i] + mn[i]) / 2);
		printf("\n");
	}
	else printf("No\n");
	return 0;
}