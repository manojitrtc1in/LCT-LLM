
















































































































































































































































































using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> ii;

int di[MAXN];
ll pascal[MAXN][4];

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x%y);
}

void preprocess() {
	mset(di, 0);
	for(int i = 1; i < MAXN; i++) {
		for(int j = i; j < MAXN; j += i) {
			di[j]++;
		}
	}
	FOR(n, MAXN) FOR(k, 4) {
		if (k > n) pascal[n][k] = 0;
		else if (k == n || k == 0) pascal[n][k] = 1;
		else pascal[n][k] = pascal[n-1][k] + pascal[n-1][k-1];
	}
}

int common(int A, int B) {
	return di[gcd(A, B)];
}

int common(int A, int B, int C) {
	return di[gcd(A, gcd(B, C))];
}

ll solve(int A, int B, int C) {
	ll a[8];
	a[7] = common(A, B, C);
	a[1|2] = common(A, B) - a[7];
	a[2|4] = common(B, C) - a[7];
	a[4|1] = common(C, A) - a[7];
	a[1] = di[A] - a[1|2] - a[1|4] - a[7];
	a[2] = di[B] - a[2|1] - a[2|4] - a[7];
	a[4] = di[C] - a[4|1] - a[4|2] - a[7];
	ll ans = 0;
	FOR1(m1, 7) FOR1(m2, m1) FOR1(m3, m2) {
		if (__builtin_popcount(m1|m2) < 2) continue;
		if (__builtin_popcount(m2|m3) < 2) continue;
		if (__builtin_popcount(m3|m1) < 2) continue;
		if (__builtin_popcount(m1|m2|m3) < 3) continue;
		if (m1 == m2 && m2 == m3) {
			ans += pascal[a[m1]+2][3];
		}
		else if (m1 == m2) {
			ans += pascal[a[m1]+1][2]*a[m3];
		}
		else if (m2 == m3) {
			ans += pascal[a[m2]+1][2]*a[m1];
		}
		else if (m3 == m1) {
			ans += pascal[a[m3]+1][2]*a[m2];
		}
		else {
			ans += a[m1]*a[m2]*a[m3];
		}
	}
	return ans;
}

int main() {
	preprocess();
	int A, B, C, t;
	scanf("%d", &t);
	while(t --> 0) {
		scanf("%d %d %d", &A, &B, &C);
		printf("%lld\n", solve(A, B, C));
	}
	return 0;
}