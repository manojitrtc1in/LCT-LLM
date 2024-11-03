#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <cstring>
#include <set>
#include <cmath>
#include <numeric>
#include <map>
#include <bitset>
#include <random>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int MN = 65005;
const int MAXN = 1e6 + 10;
const int INF = 0x3f3f3f3f;
const ll IINF = 0x3f3f3f3f3f3f3f3f;
#define IOS ios::sync_with_stdio(false)
#define lowbit(x) ((x)&(-x))
#define endl '\n'

char s[MAXN];
void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	vector<int> row(n * m, 0);
	vector<int> col(m, 0);
	vector<int> ans(n * m, 0);
	int rec = 0, last = -1;
	for (int i = 0; i < m * n; i++) {
		if (s[i] == '1')
			last = i;
		if (i < m ) {
			if (last != -1)
				row[i] = 1;
		} else {
			if (i - last < m)
				row[i] = row[i - m] + 1;
			else
				row[i] = row[i - m];
		}
		ans[i] += row[i];
	}
	for (int i = 0; i < n * m; i++) {
		if (s[i] == '1') {
			if (col[i % m] == 0) {
				col[i % m] = 1;
				rec++;
			}
		}
		ans[i] += rec;
	}
	for (int i = 0; i < n * m; i++) {
		printf("%d ", ans[i]);
	}
	putchar('\n');
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}



#if 0
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	map<int, int> a;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		a[i] = x;
		sum += x;
	}
	int last = 0;
	while (q--) {
		int op, x, y;
		scanf("%d%d", &op, &x);
		if (op == 1) {
			scanf("%d", &y);
			if (a[x]) {
				sum += y - a[x];
				a[x] = y;
			} else {
				sum += y - last;
				a[x] = y;
			}
			printf("%lld\n", sum);
		} else {
			last = x;
			a.clear();
			sum = (ll)x * n;
			printf("%lld\n", sum);
		}
	}
}
#endif


#if 0
char s[MAXN];
int dp[MAXN][3][3][3];
int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", s + 1);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				int g = 0, r = 0, b = 0;
				if (i == 0)
					g++;
				if (i == 1)
					r++;
				if (i == 2)
					b++;
				if (j == 0)
					g++;
				if (j == 1)
					r++;
				if (j == 2)
					b++;
				if (k == 0)
					g++;
				if (k == 1)
					r++;
				if (k == 2)
					b++;
				if (g > r && s[3] == 'G')
					dp[3][i][j][k] = g;
				if (g < r && s[3] == 'R')
					dp[3][i][j][k] = g;
				if (g == r && s[3] == 'B')
					dp[3][i][j][k] = g;
			}
		}
	}
	for (int i = 4; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					if (dp[i - 1][j][k][l] == -1)
						continue;
					int g = 0, r = 0, b = 0;
					if (j == 0)
						g++;
					if (j == 1)
						r++;
					if (j == 2)
						b++;
					if (k == 0)
						g++;
					if (k == 1)
						r++;
					if (k == 2)
						b++;
					for (int p = 0; p < 3; p++) {
						if (p == 0)
							g++;
						if (p == 1)
							r++;
						if (p == 2)
							b++;
						if (g > r && s[i] == 'G')
							dp[i][p][j][k] = max(dp[i][p][j][k], dp[i - 1][j][k][l] + (p == 0));
						if (g < r && s[i] == 'R')
							dp[i][p][j][k] = max(dp[i][p][j][k], dp[i - 1][j][k][l] + (p == 0));
						if (g == r && s[i] == 'B')
							dp[i][p][j][k] = max(dp[i][p][j][k], dp[i - 1][j][k][l] + (p == 0));
						if (p == 0)
							g++;
						if (p == 1)
							r++;
						if (p == 2)
							b++;
					}
				}
			}
		}
	}
	int ans = -1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				ans = max(ans, dp[n][i][j][k]);
			}
		}
	}
	if (ans == -1)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}
#endif

#if 0
int mod3(int x) {
	return (x % 3 + 3) % 3;
}

char s[MAXN];
int dp[3][MAXN][21];
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'W')
			dp[0][i][0] = dp[1][i][0] = dp[2][i][0] = 1;
		else if (s[i] == 'L')
			dp[1][i][0] = dp[2][i][0] = -1;
	}
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j + (1 << i) - 1 <= n; j++) {
			for (int k = 0; k < 3; k++) {
				dp[k][j][i] = dp[k][j][i - 1] + dp[mod3(k + dp[k][j][i - 1])][j + (1 << (i - 1))][i - 1];
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		int l, r, s;
		scanf("%d%d%d", &l, &r, &s);
		int pos = l;
		while (pos <= r) {
			int j = 0;
			while (pos + (1 << j) - 1 <= r) {
				j++;
			}
			j--;
			s += dp[s % 3][pos][j];
			pos += (1 << j);
		}
		printf("%d\n", s);
	}
	return 0;
}
#endif
#if 0
const int mod = 1e9 + 7;

ll q_pow(ll a, ll b) {
	ll rec = 1;
	while (b) {
		if (b & 1)
			rec = rec * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return rec % mod;
}

void solve() {
	ll n, m;
	scanf("%lld", &n, &m);
	ll res = q_pow(2, n);
	ll ans = m * (res - 2 + mod) % mod * q_pow(q_pow(2, mod - 2 n) % mod % mod;
	         printf("%lld", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}
#endif

#if 0
int a[MAXN];
void solve() {
	int n, m;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		if (a[i] >= m)
			cnt1++;
		else
			cnt2++;
	}
	int rec = cnt1 - cnt2;
	if (rec > 0)
		printf("%d\n", rec);
	else
		printf("-1\n");
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}
#endif


#if 0
ll a[MAXN];
int cnt[1005];
void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
		cnt[a[i]]++;
	}
	ll ans = 0;
	for (ll i = 0; i <= 1000; i++) {
		for (ll j = i; j <= 1000; j++) {
			ll add = 0;
			if (i == j)
				add = (cnt[i] + cnt[i] * (cnt[i] - 1ll) / 2ll);
			else
				add = cnt[i] * cnt[j];
			ans += add * abs(i + j - 1000ll);
		}
	}
	printf("%lld\n", ans);
}

int main() {
	int t;


	t = 1;
	while (t--)
		solve();
	return 0;
}
#endif


#if 0
ll a[MAXN];
const int mod = 998244353;
ll dp[MAXN][10];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 8; j++) {
			(dp[i][(j + a[i]) % 9] += dp[i - 1][j]) %= mod;
			(dp[i][j] += dp[i - 1][j]) %= mod;
		}
	}
	for (int i = 1; i <= 8; i++) {
		printf("%lld ", dp[n][i]);
	}
	printf("%lld", dp[n][0] - 1);
	return 0;
}
#endif


#if 0
int s[105][424];
void solve() {
	int n;
	scanf("%d", &n);
	map<int, int> mp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &s[i][j]);
		}
	}
	int ans = 0;
	mp[1] = 0;
	for (int i = 2; i <= n; i++) {
		bool flag = 0;
		for (int j = 1; j <= 3; j++) {
			if (s[i][j]) {
				flag = 1;
				if (j == 1) {
					ans += 3;
					mp[i] = 3;
				} else if (j == 2) {
					int tmp = 3 - mp[i - 1] - 1;
					ans += tmp >= 0 ? tmp : 0;
					mp[i] = tmp >= 0 ? tmp : 0;
				} else {
					int tmp = 3 - mp[i - 1] - mp[i - 2] - 2;
					ans += tmp > 0 ? tmp : 0;
					mp[i] = tmp >= 0 ? tmp : 0;
				}
				break;
			}
		}
		if (!flag)
			mp[i] = 0;
	}
	printf("%d\n", ans);
}

int main() {
	int t;


	t = 1;
	while (t--)
		solve();
	return 0;
}
#endif

#if 0
void solve() {
	int n, m;
	ll ans = 0;
	scanf("%d%d", &n, &m);
	if (m == 1)
		return void(printf("-1\n"));
	while (n) {
		if (n > m)
			ans += 2, n -= m - 1;
		else {
			ans++;
			break;
		}
	}
	printf("%lld\n", ans);
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}
#endif

#if 0
int va[MAXN];
int vb[MAXN];
void solve() {
	int a, b, n;
	scanf("%d%d%d", &a, &b, &n);
	for (int i = 1; i <= a; i++) {
		scanf("%d", va + i);
	}
	for (int i = 1; i <= b; i++) {
		scanf("%d", vb + i);
	}
	sort(va + 1, va + n + 1, greater());
	sort(vb + 1, vb + n + 1, greater());
	for (int i = 1; i <= a; i++) {
		va[i] += va[i - 1];
	}
	for (int i = 1; i <= b; i++) {
		vb[i] += vb[i - 1];
	}
	int ans = 0;
	for (int i = 0; i <= b && i <= n / 2; i++) {
		if (n - i > a)
			continue;
		ans = max(ans, vb[i] + va[n - i]);
	}
	if (!ans)
		printf("-1\n");
	else
		printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}
#endif

#if 0
int n, q;
struct node {
	int l, r;
	ll sum, lz;
} tr[MAXN];
int head[MAXN], nxt[MAXN], ver[MAXN], cnt;
ll val[MAXN];
int hson[MAXN], tp[MAXN], dep[MAXN], sz[MAXN], dfn[MAXN], in[MAXN], fa[MAXN];

void add(int x, int y) {
	ver[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
}

void dfs1(int q) {
	sz[q] = 1;
	for (int i = head[q]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == fa[q])
			continue;
		fa[v] = q;
		dep[v] = dep[q] + 1;
		dfs1(v);
		sz[q] += sz[v];
		if (sz[hson[q]] < sz[v])
			hson[q] = v;
	}
}

void dfs2(int q, int t) {
	tp[q] = t, dfn[++cnt] = q, in[q] = cnt;
	if (hson[q])
		dfs2(hson[q], t);
	for (int i = head[q]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == fa[q] || v == hson[q])
			continue;
		dfs2(v, v);
	}

}

void push_up(int q) {
	tr[q].sum = tr[q << 1].sum ^ tr[q << 1 | 1].sum;
}

void update(int q, ll c) {
	tr[q].sum += (tr[q].r - tr[q].l + 1) * c;
	tr[q].lz += c;
}

void push_down(int q) {
	if (tr[q].lz) {
		update(q << 1, tr[q].lz);
		update(q << 1 | 1, tr[q].lz);
		tr[q].lz = 0;
	}
}

void build(int q, int l, int r) {
	if (l == r)
		return void(tr[q] = {l, l, val[dfn[l]], 0});
	tr[q] = {l, r, 0, 0};
	int mid = l + r >> 1;
	build(q << 1, l, mid);
	build(q << 1 | 1, mid + 1, r);
	push_up(q);
}

void modify(int q, int l, int r, ll c) {
	if (tr[q].l >= l && tr[q].r <= r) {
		update(q, c);
		return;
	}
	push_down(q);
	int mid = tr[q].l + tr[q].r >> 1;
	if (mid >= l)
		modify(q << 1, l, r, c);
	if (mid < r)
		modify(q << 1 | 1, l, r, c);
	push_up(q);
}

ll query(int q, int l, int r) {
	if (tr[q].l >= l && tr[q].r <= r) {
		return tr[q].sum;
	}
	ll ans = 0;
	push_down(q);
	int mid = tr[q].l + tr[q].r >> 1;
	if (mid >= l)
		ans = query(q << 1, l, r);
	if (mid < r)
		ans ^= query(q << 1 | 1, l, r);
	return ans;
}

ll sum(int x, int y) {
	ll res = 0;
	while (tp[x] != tp[y]) {
		if (dep[tp[x]] < dep[tp[y]])
			swap(x, y);
		res ^= query(1, in[tp[x]], in[x]);
		x = fa[tp[x]];
	}
	if (in[x] > in[y])
		swap(x, y);
	return res ^ query(1, in[x], in[y]);
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", val + i);
	}
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	cnt = 0;
	dfs1(1);
	dfs2(1, 1);
	build(1, 1, n);
	for (int i = 1; i <= q; i++) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int x;
			ll c;
			scanf("%d%lld", &x, &c);
			modify(1, in[x], in[x], c - val[x]);
			val[x] = c;
		} else {
			int x, y;
			scanf("%d%d", &x, &y);
			printf("%lld\n", sum(x, y));
		}
	}
	return 0;
}
#endif



#if 0
char s[MAXN];
int head[MAXN], nxt[MAXN], ver[MAXN], cnt;
void add(int x, int y) {
	ver[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
}
ll dp[MAXN];
const int mod = 1e9 + 7;
ll ans = 0;
char t;

void dfs(int q, int fa) {
	ll mul = 1;
	ll sum = 0;
	for (int i = head[q]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == fa)
			continue;
		dfs(v, q);
		(mul *= (dp[v] + 1)) %= mod;
		(sum += dp[v]) %= mod;
	}
	(dp[q] = (s[q] == t) + mul - 1 + mod) % mod;
	if (s[q] == t) {
		(ans += dp[q]) %= mod;
	} else {
		ans += (dp[q] - sum + mod) % mod;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	t = '1', dfs(1, 0);
	memset(dp, 0, sizeof(dp));
	t = '0', dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}
#endif



#if 0
int head[MAXN], nxt[MAXN], ver[MAXN], cnt;
ll a[MAXN], b[MAXN];
void add(int x, int y) {
	ver[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
}
vector<ll> path;
int ans[MAXN];

void dfs(int q) {
	if (q != 1) {
		auto it = lower_bound(path.begin(), path.end(), a[q]);
		if (it == path.end() || *it > a[q])
			ans[q] = it - path.begin() - 1;
		else
			ans[q] = it - path.begin();
	}
	for (int i = head[q]; i; i = nxt[i]) {
		int v = ver[i];
		a[v] += a[q];
		b[v] += b[q];
		path.push_back(b[v]);
		dfs(v);
		path.pop_back();
	}
}

void solve() {
	int n;
	scanf("%d", &n);
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		head[i] = 0;
	}
	for (int i = 2; i <= n; i++) {
		int x;
		scanf("%d%lld%lld", &x, a + i, b + i);
		add(x, i);
	}
	dfs(1);
	for (int i = 2; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	putchar('\n');
}

int main() {
	int t;
	scanf("%d", &t);
	path.push_back(0);
	while (t--)
		solve();
	return 0;
}
#endif



#if 0
const int mod = 998244353;
int d[MAXN];
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		d[x]++;
		d[y]++;
	}
	int num = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] % 2)
			num++;
	}
	for (int i = 0; i <= k; i += 2) {
		if (i <= num && k - i <= n - num)
			ans =
		}
	return 0;
}
#endif

#if 0
ll a[MAXN];
void solve() {
	int n;
	scanf("%d", &n);
	bool flag = 0;
	ll tmp = 0;
	ll sum = 0;
	bool re = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
		sum += a[i];
		if (a[i] == 0)
			re = 1;
		while (a[i] % 10 != 2 && a[i] % 10 != 0) {
			a[i] += a[i] % 10;
		}
		if (a[i] % 10 == 0) {
			flag = 1;
		}
	}
	if (sum == 0)
		return void(printf("YES\n"));
	if (re)
		return void(printf("NO\n"));
	bool suc = 1;
	if (flag) {
		for (int i = 1; i < n; i++) {
			if (a[i] != a[i + 1]) {
				suc = 0;
				break;
			}
		}
	} else {
		sort(a + 1, a + n + 1);
		for (int i = 1; i < n; i++) {
			if ((a[i + 1] - a[i]) % 20 != 0) {
				suc = 0;
				break;
			}
		}
	}
	if (suc)
		printf("YES\n");
	else
		printf("NO\n");
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}
#endif

#if 0
const int mod = 998244353;
ll a[MAXN];
ll dp[105][105][105][105];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
	}
	ll ans = 0;
	for (int len = 1; len <= n; len++) {
		dp[len][0][0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= len; j++) {
				for (int sum = 0; sum < len; sum++) {
					if (j != 0)
						dp[len][i][j][(sum + a[i]) % len] = (dp[len][i][j][(sum + a[i]) % len] + dp[len][i - 1][j - 1][sum]) % mod;
					dp[len][i][j][sum] = (dp[len][i][j][sum] + dp[len][i - 1][j][sum]) % mod;
				}
			}
		}
		ans = (ans + dp[len][n][len][0]) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}
#endif




#if 0
int cnt[MAXN];
int main() {
	IOS;
	cin.tie(nullptr);
	int n;
	cin >> n;
	map<int, int> yes, no;
	for (int i = 1; i <= 3 * n; i++) {
		int x;
		string s;
		cin >> x >> s;
		cnt[x]++;
		if (s == "YES") {
			yes[x]++;
		} else
			no[x]++;
	}
	vector<int> ans(n);
	bool flag = 0;
	int rec = 0;
	for (int i = 0; i < n; i++) {
		if (yes[i] == 0 && no[i] == 0) {
			printf("-1");
			return 0;
		}
		if (cnt[i] == 1) {
			rec++;
			ans[i] = yes[i] ? 1 : 0;
		} else if (yes[i] == cnt[i]) {
			ans[i] = 1;
		} else if (no[i] == cnt[i]) {
			ans[i] = 0;
		} else if (cnt[i] == 2) {
			printf("-1");
			return 0;
		} else if (yes[i] > no[i]) {
			flag = 1;
			ans[i] = 1;
		} else {
			flag = 1;
			ans[i] = 0;
		}
	}
	if (!flag && rec > 1) {
		printf("-1");
		return 0;
	}
	for (auto t : ans) {
		cout << t;
	}
}
#endif


#if 0
int main() {
	ll n, k;
	n -= k;
	if (n > k)
		printf("%lld", (k + 1) * 2);
	else
		printf("-1");
	return 0;
}
#endif


#if 0
int n, m;
ll a[MAXN];
bool check(int mid) {
	vector<ll> b(n);
	for (int i = 1; i <= n; i++) {
		b[i] = a[i] + (ll)mid * i;
	}
	ll sum = 0;
	sort(b.begin(), b.end());
	for (int i = 0; i < mid; i++) {
		sum += b[i];
	}
	return sum <= m;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	int l = 0, r = n;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	printf("%d", r);
	return 0;
}
#endif


#if 0
ll a[MAXN];
ll pre[MAXN];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
		pre[i] = pre[i - 1] + a[i];
	}
	ll ans = n;
	for (int len = 2; len <= n; len++) {
		for (int i = len; i <= n; i++) {
			if ((pre[i] - pre[i - len]) % len == 0)
				ans++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
#endif


#if 0
const int mod = 998244353;
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	vector g(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<ll> dp(n);
	dp[0] = 1;
	for (int i = 0; i < k; i++) {
		int S = 0;
		for (int i = 0; i < n; i++) {
			S = (S + dp[i]) % mod;
		}
		vector<ll> ndp(n);
		for (int i = 0; i < n; i++) {
			ndp[i] = (S + mod - dp[i]) % mod;
			for (int v : g[i]) {
				ndp[i] = (ndp[i] - dp[v] + mod) % mod;
			}
		}
		dp.swap(ndp);
	}
	printf("%lld\n", dp[0]);
	return 0;
}
#endif


#if 0
int n, q;
int job[404][404][404];
const int mod = 998244353;
int solve(int IQ, int EQ, int AQ) {
	int tmp = job[IQ][EQ][AQ];
	int res = 0;
	while (tmp) {
		if (tmp & 1)
			res++;
		tmp >>= 1;
	}
	return res;
}

ll q_pow(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1)
			ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

int main() {
	IOS;
	cin.tie(nullptr);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		while (t--) {
			int a, b, c;
			cin >> a >> b >> c;
			job[a][b][c] |= 1 << i;
		}
	}
	for (int i = 1; i <= 400; i++) {
		for (int j = 1; j <= 400; j++) {
			for (int k = 1; k <= 400; k++) {
				job[i][j][k] |= job[i - 1][j][k] | job[i][j - 1][k] | job[i][j][k - 1];
			}
		}
	}
	int seed;
	cin >> seed;
	std::mt19937 rng(seed);
	std::uniform_int_distribution<> u(1, 400);
	int lastans = 0;
	ll ans = 0;
	for (int i = 1; i <= q; i++) {
		int IQ = (u(rng)^lastans) % 400 + 1; 

		int EQ = (u(rng)^lastans) % 400 + 1; 

		int AQ = (u(rng)^lastans) % 400 + 1; 

		lastans = solve(IQ, EQ, AQ); 

		ans += 1ll * lastans * q_pow(seed, q - i) % mod;
	}
	cout << ans % mod << endl;
	return 0;
}
#endif

#if 0
ll domod(ll x, ll mod) {
	return (x % mod + mod) % mod;
}
ll pow_10[20];

int main() {
	IOS;
	cin.tie(nullptr);
	int n;
	cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	pow_10[0] = 1;
	for (int i = 1; i <= 18; i++) {
		pow_10[i] = pow_10[i - 1] * 10;
	}
	ll res = 0;
	for (ll i = 1; i <= n; i++) {
		ll k = 1;
		while (domod((i - (i - 1)*pow_10[k]), n) >= pow_10[k])
			k++;
		res += k;
	}
	cout << res << endl;
	return 0;
}
#endif


#if 0
int a[MAXN];
int f[255][255];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		a[i] += a[i - 1];
	}
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for (int k = m; k >= 0; k--) {
		for (int i = 1; i <= n; i++) {
			for (int j = k; j <= m; j++) {
				f[i][j] = min(f[i][j], f[i - 1][j - k] + abs(j - a[i]));
			}
		}
	}
	cout << f[n][m] << endl;
	return 0;
}
#endif


#if 0
vector<int> edge[MAXN];
int a[MAXN];
int x, y;
int son[MAXN], path[MAXN];
void dfs1(int q, int fa) {
	for (int v : edge[q]) {
		if (v == fa)
			continue;
		dfs1(v, q);
		son[q] += son[v];
		path[q] |= path[v];
	}
}

int dfs2(int q, int fa) {
	int len = 0;
	for (int v : edge[q]) {
		if (v == fa)
			continue;
		if (!path[v] && son[v])
			len += 1 + dfs2(v, q) + 1;
	}
	return len;
}

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%d%d", &x, &y);
	for (int i = 1; i <= n; i++) {
		son[i] = path[i] = 0;
		edge[i].clear();
	}
	for (int i = 1; i <= k; i++) {
		int u;
		scanf("%d", &u);
		son[u] = 1;
	}
	path[y] = 1;
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs1(x, 0);
	int ans = 0;
	for (int u = 1; u <= n; u++) {
		if (path[u])
			ans += dfs2(u, u);
	}
	printf("%d\n", ans - 1 + count(path + 1, path + n + 1, 1));
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}
#endif


#if 0
void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	map<char, char> mp;
	map<char, int> vis;
	for (auto ch : s) {
		while (ch > 'a' && !vis[ch] && k > 0) {
			vis[ch] = 1;
			ch--;
			k--;
		}
	}
	for (char i = 'a'; i <= 'z'; i++) {
		for (char j = i; j >= 'a'; j--) {
			mp[i] = j;
			if (!vis[j])
				break;
		}
	}
	for (auto ch : s) {
		cout << mp[ch];
	}
	cout << endl;
}

int main() {
	IOS;
	int t;


	cin >> t;
	while (t--)
		solve();
	return 0;
}
#endif



#if 0
int now;
int fa[MAXN];
bool flag[MAXN];
bool vis[MAXN];
vector<int> path[MAXN];
int cnt = 0;
void dfs(int q) {
	path[cnt].push_back(q);
	if (!vis[fa[q]]) {
		vis[fa[q]] = 1;
		dfs(fa[q]);
	}
}

void solve() {
	int n;
	cnt = 0;
	int ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		path[i].clear();
		flag[i] = 0;
		vis[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		fa[i] = x;
		flag[x] = 1;
	}
	if (n == 1)
		return void(printf("1\n1\n1\n\n"));
	for (int i = 1; i <= n; i++) {
		if (!flag[i])
			ans++;
	}
	for (int i = 1; i <= n; i++) {
		if (!flag[i]) {
			now = i;
			cnt++;
			dfs(now);
			reverse(path[cnt].begin(), path[cnt].end());
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= cnt; i++) {
		printf("%d\n", path[i].size());
		for (auto v : path[i]) {
			printf("%d ", v);
		}
		putchar('\n');
	}
	putchar('\n');
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}
#endif




#if 0
ll n;
ll a[MAXN];
int cnt[MAXN];


int main() {
	scanf("%lld", &n);
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);


		sum += a[i];
	}
	for (int i = 0; i < 15; i++) {
		for (int j = 1; j <= n; j++) {
			if ((a[j] >> i) & 1) {
				cnt[i]++;
			}
		}
	}
	int pos = 0;
	for (int i = 15; i >= 0; i--) {
		if (cnt[i]) {
			pos = i;
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = pos; j >= 0; j--) {
			printf("%d", (a[i] >> j) & 1);
		}
		putchar('\n');
	}
	vector<ll> last(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= pos; j++) {
			if (cnt[j]) {
				last[i] += 1 << j;
				cnt[j]--;
			}
		}
	}
	printf("============\n");
	for (int i = 1; i <= n; i++) {
		for (int j = pos; j >= 0; j--) {
			printf("%d", (last[i] >> j) & 1);
		}
		putchar('\n');
	}
	ll sum2 = 0;
	for (int i = 1; i <= n; i++) {
		ll tmp = n * last[i] - sum;
		sum2 += tmp * tmp;
	}
	ll tmp2 = n * n * n;
	ll gcd = __gcd(sum2, tmp2);
	printf("%lld/%lld", sum2 / gcd, tmp2 / gcd);
	return 0;
}
#endif
#if 0
int n, q;
ll seed;
const ll mod = 998244353;
ll a[MAXN];
ll b[MAXN];
ll c[MAXN];

ll solve(ll IQ, ll EQ, ll AQ) {
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (IQ >= a[i] && EQ >= b[i] && AQ >= c[i])
			ans++;
	}
	return ans;
}

ll q_pow(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1)
			ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		int t;
		scanf("%d", &t);
		for (int i = 1; i <= t; i++) {

		}
	}
	scanf("%d", &seed);
	std::mt19937 rng(seed);
	std::uniform_int_distribution<> u(1, 400);
	ll lastans = 0;
	for (int i = 1; i <= q; i++) {
		ll IQ = (u(rng)^lastans) % 400 + 1; 

		ll EQ = (u(rng)^lastans) % 400 + 1; 

		ll AQ = (u(rng)^lastans) % 400 + 1; 

		ll tmp = solve(IQ, EQ, AQ); 

		lastans += tmp * q_pow(seed, q - i) % mod;
	}
	printf("%lld\n", lastans);
	return 0;
}
#endif


#if 0
int n, m;
struct node {
	int l, r;
	ll sum, lz;
} tr[MAXN];
int head[MAXN], nxt[MAXN], ver[MAXN], cnt;
int sz[MAXN], fa[MAXN], in[MAXN], dfn[MAXN], tp[MAXN], dep[MAXN], hson[MAXN];

void add(int x, int y) {
	ver[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
}

void dfs1(int q) {
	sz[q] = 1, dep[q] = dep[fa[q]] + 1;
	for (int i = head[q]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == fa[q])
			continue;
		fa[v] = q;
		dfs1(v);
		sz[q] += sz[v];
		if (sz[hson[q]] < sz[v])
			hson[q] = v;
	}
}

void dfs2(int q, int t) {
	tp[q] = t, in[q] = ++cnt, dfn[cnt] = q;
	if (hson[q])
		dfs2(hson[q], t);
	for (int i = head[q]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == fa[q] || v == hson[q])
			continue;
		dfs2(v, v);
	}
}

inline void update(int q, int c) {
	tr[q].sum += (tr[q].r - tr[q].l + 1) * c;
	tr[q].lz += c;
}

inline void push_up(int q) {
	tr[q].sum = tr[q << 1].sum + tr[q << 1 | 1].sum;
}

inline void push_down(int q) {
	if (tr[q].lz) {
		update(q << 1, tr[q].lz);
		update(q << 1 | 1, tr[q].lz);
		tr[q].lz = 0;
	}
}

void build(int q, int l, int r) {
	tr[q] = {l, r, 0, 0};
	if (l == r)
		return;
	int mid = l + r >> 1;
	build(q << 1, l, mid);
	build(q << 1 | 1, mid + 1, r);
	push_up(q);
}

void update(int q, int l, int r, ll c) {
	if (tr[q].l >= l && tr[q].r <= r) {
		update(q, c);
		return;
	}
	push_down(q);
	int mid = tr[q].l + tr[q].r >> 1;
	if (mid >= l)
		update(q << 1, l, r, c);
	if (mid < r)
		update(q << 1 | 1, l, r, c);
	push_up(q);
}

ll query(int q, int l, int r) {
	if (tr[q].l >= l && tr[q].r <= r)
		return tr[q].sum;
	push_down(q);
	ll res = 0;
	int mid = tr[q].l + tr[q].r >> 1;
	if (mid >= l)
		res = query(q << 1, l, r);
	if (mid < r)
		res += query(q << 1 | 1, l, r);
	return res;
}

inline void updates(int x, int y) {
	while (tp[x] != tp[y]) {
		if (dep[tp[x]] < dep[tp[y]])
			swap(x, y);
		update(1, in[tp[x]], in[x], 1);
		x = fa[tp[x]];
	}
	if (in[x] > in[y])
		swap(x, y);
	update(1, in[x], in[y], 1);
	update(1, in[x], in[x], -1);
}

ll sum(int x, int y) {
	ll res = 0;
	while (tp[x] != tp[y]) {
		if (dep[tp[x]] < dep[tp[y]])
			swap(x, y);
		res += query(1, in[tp[x]], in[x]);
		x = fa[tp[x]];
	}
	if (in[x] > in[y])
		swap(x, y);
	return res + query(1, in[x], in[y]) - query(1, in[x], in[x]);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	cnt = 0;
	dfs1(1);
	dfs2(1, 1);
	build(1, 1, n);
	while (m--) {
		char op;
		int u, v;
		scanf(" %c %d %d", &op, &u, &v);
		if (op == 'P') {
			updates(u, v);
		} else {
			printf("%lld\n", sum(u, v));
		}
	}
	return 0;
}
#endif


#if 0
int head[MAXN], nxt[MAXN], ver[MAXN], cnt;
struct node {
	int l, r;
	ll sum, lz;
} tr[MAXN];
int root, n, m, mod;
int sz[MAXN],  fa[MAXN], dep[MAXN], hson[MAXN], tp[MAXN], rk[MAXN], id[MAXN];
ll val[MAXN];

void add(int x, int y) {
	ver[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
}

void dfs1(int x) {
	sz[x] = 1, dep[x] = dep[fa[x]] + 1;
	for (int i = head[x]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == fa[x])
			continue;
		fa[v] = x;
		dfs1(v);
		sz[x] += sz[v];
		if (sz[hson[x]] < sz[v])
			hson[x] = v;
	}
}

void dfs2(int q, int t) {
	tp[q] = t, id[q] = ++cnt, rk[cnt] = q;
	if (hson[q])
		dfs2(hson[q], t);
	for (int i = head[q]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == fa[q] || v == hson[q])
			continue;
		dfs2(v, v);
	}
}

inline void push_up(int q) {
	tr[q].sum = tr[q << 1].sum + tr[q << 1 | 1].sum;
	tr[q].sum %= mod;
}

inline void update(int q, ll c) {
	tr[q].sum += (tr[q].r - tr[q].l + 1) * c;
	tr[q].sum %= mod;
	tr[q].lz += c;
	tr[q].lz %= mod;
}

inline void push_down(int q) {
	if (tr[q].lz) {
		update(q << 1, tr[q].lz);
		update(q << 1 | 1, tr[q].lz);
		tr[q].lz = 0;
	}
}

void build(int q, int l, int r) {
	if (l == r) {
		return void(tr[q] = {l, l, val[rk[l]], 0});
	}
	tr[q] = {l, r, 0, 0};
	int mid = l + r >> 1;
	build(q << 1, l, mid);
	build(q << 1 | 1, mid + 1, r);
	push_up(q);
}

void update(int q, int l, int r, ll c) {
	if (tr[q].l >= l && tr[q].r <= r) {
		update(q, c);
		return;
	}
	push_down(q);
	int mid = tr[q].l + tr[q].r >> 1;
	if (mid >= l)
		update(q << 1, l, r, c);
	if (mid < r)
		update(q << 1 | 1, l, r, c);
	push_up(q);
}

ll query(int q, int l, int r) {
	if (tr[q].l >= l && tr[q].r <= r)
		return tr[q].sum;
	push_down(q);
	ll ans = 0;
	int mid = tr[q].l + tr[q].r >> 1;
	if (mid >= l)
		ans = query(q << 1, l, r);
	if (mid < r)
		ans += query(q << 1 | 1, l, r);
	return ans % mod;
}

inline ll sum(int x, int y) {
	ll ret = 0;
	while (tp[x] != tp[y]) {
		if (dep[tp[x]] < dep[tp[y]])
			swap(x, y);
		ret += query(1, id[tp[x]], id[x]);
		ret %= mod;
		x = fa[tp[x]];
	}
	if (id[x] > id[y])
		swap(x, y);
	return (ret + query(1, id[x], id[y])) % mod;
}

inline void updates(int x, int y, ll c) {
	while (tp[x] != tp[y]) {
		if (dep[tp[x]] < dep[tp[y]])
			swap(x, y);
		update(1, id[tp[x]], id[x], c);
		x = fa[tp[x]];
	}
	if (id[x] > id[y])
		swap(x, y);
	update(1, id[x], id[y], c);
}

int main() {
	scanf("%d%d%d%d", &n, &m, &root, &mod);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", val + i);
	}
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs1(root);
	cnt = 0;
	dfs2(root, root);
	build(1, 1, n);
	while (m--) {
		int op, x, y;
		ll c;
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d%lld", &x, &y, &c);
			updates(x, y, c);
		} else if (op == 2) {
			scanf("%d%d", &x, &y);
			printf("%lld\n", sum(x, y));
		} else if (op == 3) {
			scanf("%d%lld", &x, &c);
			update(1, id[x], id[x] + sz[x] - 1, c);
		} else {
			scanf("%d", &x);
			printf("%lld\n", query(1, id[x], id[x] + sz[x] - 1));
		}
	}
	return 0;
}
#endif

#if 0
map<int, int> mp[MAXN];
int calc(int i) {
	if (mp[i].upper_bound(i) == mp[i].end())
		return 1;
	return 0;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		mp[x][y]++;
		mp[y][x]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (mp[i].upper_bound(i) == mp[i].end())
			ans++;
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int op, x, y;
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d", &x, &y);
			ans -= calc(x) + calc(y);
			mp[x][y]++;
			mp[y][x]++;
			ans += calc(x) + calc(y);
		} else if (op == 2) {
			scanf("%d%d", &x, &y);
			ans -= calc(x) + calc(y);
			mp[x].erase(y);
			mp[y].erase(x);
			ans += calc(x) + calc(y);
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}
#endif


#if 0
ll a[MAXN];
ll st[MAXN][21];
int Log2[MAXN];
ll query(int l, int r) {
	int k = Log2[r - l + 1];
	return __gcd(st[l][k], st[r - (1 << k) + 1][k]);
}
int n;

bool check(int mid) {
	for (int i = mid; i <= n; i++) {
		if (query(i - mid + 1, i) > 1)
			return 1;
	}
	return 0;
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
		if (i >= 2)
			Log2[i] = Log2[i >> 1] + 1;
	}
	if (n == 1)
		return void(printf("1\n"));
	n--;
	for (int i = 1; i <= n; i++) {
		st[i][0] = abs(a[i + 1] - a[i]);
	}
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j + (1 << i) - 1 <= n; j++) {
			st[j][i] = __gcd(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
		}
	}
	int l = 1, r = n;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	printf("%d\n", r + 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}
#endif




#if 0
using P = pair<int, int>;
vector<P> Q[MAXN];
int n, m;
int col[MAXN];
int head[MAXN], nxt[MAXN], ver[MAXN], cnt;
void add(int x, int y) {
	ver[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
}
int HH;
int rec[MAXN][26];
int hson[MAXN];
int sz[MAXN];
int ans[MAXN];

void dfs(int q) {
	sz[q] = 1;
	for (int i = head[q]; i; i = nxt[i]) {
		int v = ver[i];
		dfs(v);
		sz[q] += sz[v];
		if (sz[v] > sz[hson[q]])
			hson[q] = v;
	}
}

void calc(int q, int val, int dep) {
	rec[dep][col[q]] += val;
	for (int i = head[q]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == HH)
			continue;
		calc(v, val, dep + 1);
	}
}

void dsu(int q, int op, int dep) {
	for (int i = head[q]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == hson[q])
			continue;
		dsu(v, 0, dep + 1);
	}
	if (hson[q])
		dsu(hson[q], 1, dep + 1), HH = hson[q];
	calc(q, 1, dep);
	for (auto i : Q[q]) {
		int b = i.first, id = i.second, res = 0;
		for (int i = 0; i < 26; i++) {
			if (rec[b][i] & 1)
				res++;
		}
		if (res <= 1)
			ans[id] = 1;
	}
	HH = 0;
	if (!op)
		calc(q, -1, dep);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; i++) {
		int y;
		scanf("%d", &y);
		add(y, i);
	}
	for (int i = 1; i <= n; i++) {
		char ch;
		scanf(" %c", &ch);
		col[i] = ch - 'a';
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		Q[a].push_back(P(b, i));
	}
	dfs(1);
	dsu(1, 0, 1);
	for (int i = 1; i <= m; i++) {
		if (ans[i])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
#endif


#if 0
ll a[MAXN];
void solve() {
	ll n, m;
	int k;
	scanf("%lld%lld%d", &n, &m, &k);
	for (int i = 1; i <= k; i++) {
		scanf("%lld", a + i);
	}
	sort(a + 1, a + k + 1);
	auto check = [&]() {
		if ((n & 1) && a[k] < 3 * m)
			return false;
		ll sum = 0;
		for (int i = 1; i <= k; i++) {
			ll t = a[i] / m;
			if (t >= 2)
				sum += t;
		}
		return sum >= n;
	};
	if (check()) {
		printf("YES\n");
	} else {
		swap(n, m);
		if (check())
			printf("YES\n");
		else
			printf("NO\n");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}
#endif


#if 0
int head[MAXN], nxt[MAXN], ver[MAXN], cnt;
int c[MAXN];
int sz[MAXN];
int hson[MAXN];
int HH;
ll ans[MAXN];
int rec[MAXN];
int n, ma;
ll res;
void add(int x, int y) {
	ver[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
}

void dfs(int u, int fa) {
	sz[u] = 1;
	for (int i = head[u]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == fa)
			continue;
		dfs(v, u);
		sz[u] += sz[v];
		if (sz[v] > sz[hson[u]])
			hson[u] = v;
	}
}

void calc(int u, int fa, int val) {
	if (val == 1) {
		rec[c[u]]++;
		if (rec[c[u]] > ma)
			ma = rec[c[u]], res = c[u];
		else if (ma == rec[c[u]])
			res += c[u];
	} else
		rec[c[u]]--;
	for (int i = head[u]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == fa || v == HH)
			continue;
		calc(v, u, val);
	}
}

void dsu(int u, int fa, int op) {
	for (int i = head[u]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == fa || v == hson[u])
			continue;
		dsu(v, u, 0);
	}
	if (hson[u])
		dsu(hson[u], u, 1), HH = hson[u];
	calc(u, fa, 1);
	ans[u] = res;
	HH = 0;
	if (!op)
		calc(u, fa, -1), ma = 0, res = 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", c + i);
	}
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs(1, 0);
	dsu(1, 0, 0);
	for (int i = 1; i <= n; i++) {
		printf("%lld ", ans[i]);
	}
	return 0;
}
#endif


#if 0
int mx = 0;
int head[MAXN], nxt[MAXN], cost[MAXN], ver[MAXN], cnt;
void add(int x, int y, int c) {
	ver[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
	cost[cnt] = c;
}
int dis[MAXN];
int vis[MAXN];

void SPFA() {
	queue<int> que;
	memset(dis, -0x3f, sizeof(dis));
	dis[0] = 0;
	que.push(0);
	while (!que.empty()) {
		int t = que.front();
		que.pop();
		vis[t] = 0;
		for (int i = head[t]; i; i = nxt[i]) {
			int v = ver[i], c = cost[i];
			if (dis[v] < dis[t] + c) {
				dis[v] = dis[t] + c;
				if (!vis[v])
					que.push(v), vis[v] = 1;
			}
		}
	}
	printf("%d\n", dis[mx + 1]);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		mx = max(mx, b);
		add(a, b + 1, c);
	}
	for (int i = 1; i <= mx + 1; i++) {
		add(i - 1, i, 0);
		add(i, i - 1, -1);
	}
	SPFA();
	return 0;
}
#endif



#if 0
int n, m;
int ans;
int col[MAXN];
int now[MAXN];
vector<int> g[MAXN];

void merge(int x, int y) {
	for (int i : g[x]) {
		if (col[i - 1] == y)
			ans--;
		if (col[i + 1] == y)
			ans--;
	}
	for (int i : g[x])
		col[i] = y;
	for (int i : g[x])
		g[y].push_back(i);
	g[x].clear();
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", col + i);
		now[col[i]] = col[i];
		if (col[i] != col[i - 1])
			ans++;
		g[col[i]].push_back(i);
	}
	while (m--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (x == y)
				continue;
			if (g[now[x]].size() > g[now[y]].size()) {
				swap(now[x], now[y]);
			}
			merge(now[x], now[y]);
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}
#endif

#if 0
int n, m;
int a[MAXN];
int ans = 0;
int now[MAXN];
vector<int> g[MAXN];

void merge(int x, int y) {
	for (int i : g[x]) {
		if (a[i - 1] == y)
			ans--;
		if (a[i - 1] == y)
			ans--;
	}
	for (int i : g[x]) {
		a[i] = y;
	}
	for (int i : g[x]) {
		g[y].push_back(i);
	}
	g[x].clear();
}

int main() {
	IOS;
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		now[a[i]] = a[i];
		if (a[i] != a[i - 1])
			ans++;
		g[a[i]].push_back(i);
	}
	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int x, y;
			cin >> x >> y;
			if (x == y)
				continue;
			if (g[now[x]].size() > g[now[y]].size()) {
				swap(now[x], now[y]);
			}
			merge(now[x], now[y]);
		} else {
			cout << ans << endl;
		}
	}
}
#endif


#if 0
ll a[MAXN];
ll pre[MAXN];
int main() {
	int n;
	ll k;
	scanf("%d%lld", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
		pre[i] = pre[i - 1] + a[i];
	}
	map<ll, int> mp;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (pre[i] == k)
			ans++;
		if (mp[pre[i] - k])
			ans += mp[pre[i] - k];
		mp[pre[i]]++;
	}
	printf("%lld\n", ans);
	return 0;
}
#endif


#if 0
int Log2[MAXN];
int dep1[MAXN], dep2[MAXN];
int a[MAXN], b[MAXN];
int fat1[MAXN][31], fat2[MAXN][31];
vector<int> edge1[MAXN], edge2[MAXN];
int dfn1[MAXN], dfn2[MAXN], id;
void dfs1(int q, int fa) {
	fat1[q][0] = fa;
	dfn1[q] = ++id;
	for (int i = 1; i <= Log2[dep1[q]]; i++) {
		fat1[q][i] = fat1[fat1[q][i - 1]][i - 1];
	}
	for (int v : edge1[q]) {
		if (v == fa)
			continue;
		dep1[v] = dep1[q] + 1;
		dfs1(v, q);
	}
}

void dfs2(int q, int fa) {
	fat2[q][0] = fa;
	dfn2[q] = ++id;
	for (int i = 1; i <= Log2[dep2[q]]; i++) {
		fat2[q][i] = fat2[fat2[q][i - 1]][i - 1];
	}
	for (int v : edge2[q]) {
		if (v == fa)
			continue;
		dep2[v] = dep2[q] + 1;
		dfs2(v, q);
	}
}

int lca1(int x, int y) {
	if (dep1[x] < dep1[y])
		swap(x, y);
	while (dep1[x] != dep1[y]) {
		x = fat1[x][Log2[dep1[x] - dep1[y]]];
	}
	if (x == y)
		return x;
	for (int i = Log2[dep1[x]]; i >= 0; i--) {
		if (fat1[x][i] != fat1[y][i]) {
			x = fat1[x][i], y = fat1[y][i];
		}
	}
	return fat1[x][0];
}

int lca2(int x, int y) {
	if (dep2[x] < dep2[y])
		swap(x, y);
	while (dep2[x] != dep2[y]) {
		x = fat2[x][Log2[dep2[x] - dep2[y]]];
	}
	if (x == y)
		return x;
	for (int i = Log2[dep2[x]]; i >= 0; i--) {
		if (fat2[x][i] != fat2[y][i]) {
			x = fat2[x][i], y = fat2[y][i];
		}
	}
	return fat2[x][0];
}

bool cmp1(int a, int b) {
	return dfn1[a] < dfn1[b];
}

bool cmp2(int a, int b) {
	return dfn2[a] < dfn2[b];
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> rec1(k), rec2(k);
	for (int i = 2; i <= n; i++) {
		Log2[i] = Log2[i / 2] + 1;
	}
	for (int i = 0; i < k; i++) {
		scanf("%d", &rec1[i]);
		rec2[i] = rec1[i];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 2; i <= n; i++) {
		int x;
		scanf("%d", &x);
		edge1[x].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", b + i);
	}
	for (int i = 2; i <= n; i++) {
		int x;
		scanf("%d", &x);
		edge2[x].push_back(i);
	}
	dfs1(1, 0);
	id = 0;
	dfs2(1, 0);
	sort(rec1.begin(), rec1.end(), cmp1);
	sort(rec2.begin(), rec2.end(), cmp2);
	int ans = 0;
	for (int i = 0; i < k; i++) {
		int xa = rec1[0], ya = rec1[k - 1], xb = rec2[0], yb = rec2[k - 1];
		if (i == 0)
			xa = rec1[1];
		else if (i == k - 1)
			ya = rec1[k - 2];
		if (xb == rec1[i])
			xb = rec2[1];
		else if (yb == rec1[i])
			yb = rec2[k - 2];
		int xlca = lca1(xa, ya), ylca = lca2(xb, yb);
		if (a[xlca] > b[ylca])
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}
#endif
#if 0

struct node {
	int l, r;
	ll ma, lz;
} tr[MAXN];
ll v[MAXN], sum[MAXN];
int head[MAXN], nxt[MAXN], ver[MAXN], cnt;
int in[MAXN], out[MAXN], dfn[MAXN], id;

void add(int x, int y) {
	ver[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
}

void dfs(int p, int fa) {
	in[p] = ++id;
	dfn[id] = p;
	for (int i = head[p]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == fa)
			continue;
		sum[v] += sum[p];
		dfs(v, p);
	}
	out[p] = id;
}

void update(int q, ll x) {
	tr[q].ma += x;
	tr[q].lz += x;
	return;
}

void push_up(int q) {
	tr[q].ma = max(tr[q << 1].ma, tr[q << 1 | 1].ma);
}

void push_down(int q) {
	if (tr[q].lz) {
		update(q << 1, tr[q].lz);
		update(q << 1 | 1, tr[q].lz);
		tr[q].lz = 0;
	}
}

void build(int q, int l, int r) {
	if (l == r) {
		return void(tr[q] = {l, l, sum[dfn[l]], 0});
	}
	tr[q] = {l, r, 0, 0};
	int mid = l + r >> 1;
	build(q << 1, l, mid);
	build(q << 1 | 1, mid + 1, r);
	push_up(q);
}

void update(int q, int l, int r, ll x) {
	if (tr[q].l >= l && tr[q].r <= r) {
		update(q, x);
		return;
	}
	push_down(q);
	int mid = tr[q].l + tr[q].r >> 1;
	if (mid >= l)
		update(q << 1, l, r, x);
	if (mid < r)
		update(q << 1 | 1, l, r, x);
	push_up(q);
}

ll query(int q, int l, int r) {
	if (tr[q].l >= l && tr[q].r <= r) {
		return tr[q].ma;
	}
	push_down(q);
	ll ans = -IINF;
	int mid = tr[q].l + tr[q].r >> 1;
	if (mid >= l)
		ans = query(q << 1, l, r);
	if (mid < r)
		ans = max(ans, query(q << 1 | 1, l, r));
	return ans;
}

void solve() {
	cnt = 0;
	id = -1;
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		head[i] = 0;
	}
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld", v + i), sum[i] = v[i];
	}
	dfs(0, -1);
	build(1, 0, n - 1);
	while (m--) {
		int op, x, y;
		scanf("%d%d", &op, &x);
		if (op == 0) {
			scanf("%d", &y);
			update(1, in[x], out[x], y - v[x]);
			v[x] = y;
		} else {
			printf("%lld\n", query(1, in[x], out[x]));
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	int kk = 0;
	while (t--) {
		printf("Case #%d:\n", ++kk);
		solve();
	}
	return 0;
}
#endif
#if 0
int n;
int head[MAXN], nxt[MAXN], ver[MAXN], cnt;

void add(int x, int y) {
	ver[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
}
int in[MAXN], out[MAXN], id;

void dfsn(int p, int fa) {
	in[p] = ++id;
	for (int i = head[p]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == fa)
			continue;
		dfsn(v, p);
	}
	out[p] = id;
}
int tr[MAXN];

void update(int pos, int x) {
	for (int i = pos; i <= n; i += lowbit(i))
		tr[i] += x;
}

int query(int pos) {
	int rec = 0;
	for (int i = pos; i; i -= lowbit(i))
		rec += tr[i];
	return rec;
}

int query(int l, int r) {
	return query(r) - query(l - 1);
}
bool change[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfsn(1, 0);
	for (int i = 1; i <= n; i++) {
		update(i, 1);
		change[i] = 1;
	}
	int m;
	scanf("%d", &m);
	while (m--) {
		char ch;
		int x;
		scanf(" %c %d", &ch, &x);
		if (ch == 'C') {
			if (change[in[x]])
				update(in[x], -1), change[in[x]] = 0;
			else
				update(in[x], 1), change[in[x]] = 1;
		} else {
			printf("%d\n", query(in[x], out[x]));
		}
	}
	return 0;
}
#endif

