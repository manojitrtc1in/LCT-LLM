
















































































































































































































































































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