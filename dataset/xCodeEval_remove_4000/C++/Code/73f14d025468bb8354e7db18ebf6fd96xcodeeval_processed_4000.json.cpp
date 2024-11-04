

















































































































































































































































































using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, k;
int a[MAXN];
int nxt[MAXN], prv[MAXN], dp[MAXN];

int main() {
	while(scanf("%d %d", &n, &k) != EOF) {
		dp[0] = 0;
		FOR1(i, n) {
			dp[i] = (dp[i-1] + (i-1)/(k-1)) % MOD;
		}
		FOR(i, n) scanf("%d", &a[i]);
		stack<int> sp, sn;
		FOR(i, n) {
			while(!sp.empty() && a[sp.top()] < a[i]) sp.pop();
			prv[i] = sp.empty() ? -1 : sp.top();
			sp.push(i);
		}
		REP(i, n) {
			while(!sn.empty() && a[sn.top()] <= a[i]) sn.pop();
			nxt[i] = sn.empty() ? n : sn.top();
			sn.push(i);
		}
		int ans = 0;
		FOR(i, n) {
			int r = nxt[i];
			int l = prv[i];
			int cur = ((dp[r-l-1] - dp[i-l-1] - dp[r-i-1])%MOD + MOD)%MOD;
			cur = (a[i]*1ll*cur)%MOD;
			ans = (ans + cur) % MOD;
		}
		printf("%d\n", ans);
	}
	return 0;
}