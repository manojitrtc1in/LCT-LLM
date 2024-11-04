











typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int MN = 65005;
const int MAXN = 1e6 + 10;
const int INF = 0x3f3f3f3f;



char s[MAXN];
int black[4500];
int white[4500];
int head[MAXN];
int nxt[MAXN];
int ver[MAXN];
int cnt = 0;
int ans;
inline void add(int x, int y) {
	ver[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
}

void dfs(int p) {
	if (s[p] == 'W')
		white[p]++;
	else
		black[p]++;
	for (int i = head[p]; i; i = nxt[i]) {
		int v = ver[i];
		dfs(v);
		black[p] += black[v];
		white[p] += white[v];
	}
	if (white[p] == black[p])
		ans++;
}

void solve() {
	int n;
	cnt = 0;
	

	for (int i = 1; i <= n; i++) {
		head[i] = 0;
		nxt[i] = 0;
		black[i] = 0;
		white[i] = 0;
	}
	scanf("%d", &n);
	int x;
	for (int i = 2; i <= n; i++) {
		scanf("%d", &x);
		add(x, i);
	}
	ans = 0;
	for (int i = 1; i <= n; i++) {
		scanf(" %c", s + i);
	}
	

	dfs(1);
	printf("%d\n", ans);
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}





int s[MAXN];

void solve() {
	map<int, int> mp;
	int n, k;
	scanf("%d %d", &n, &k);
	

	for (int i = 1; i <= n; i++) {
		scanf("%d", s + i);
		

		mp[s[i]]++;
	}
	int ans1 = 0, ans2 = 0;
	int l, r;
	int len = 0;
	for (auto [e, v] : mp) {
		if (v < k ) {
			len = 0;
			continue;
		}
		if (len == 0) {
			l = e, r = e;
			len = 1;
		} else {
			r++;
			len++;
		}
		if (e != r) {
			l = e, r = e;
			len = 1;
		}
		if (len > ans2 - ans1) {
			ans2 = r;
			ans1 = l;
		}
	}
	if (ans1 == 0 && ans2 == 0) {
		printf("-1\n");
	} else {
		printf("%d %d\n", ans1, ans2);
	}
}


int main() {
	int t ;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}




ll sum[MAXN];
ll s[MAXN];

bool cmp(ll a, ll b) {
	return a > b;
}

void solve() {
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", s + i);
	}
	sort(s + 1, s + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + s[i];
	}
	ll x;
	while (q--) {
		scanf("%lld", &x);
		int cnt = lower_bound(sum + 1, sum + n + 1, x) - sum;
		if (cnt > n) {
			printf("-1\n");
		} else {
			printf("%d\n", cnt);
		}
	}
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}






int s[500][500];
int n, m;

int solve2(int x, int y) {
	int res = s[x][y];
	int tx = x;
	int ty = y;
	while (tx + 1 <= n && ty + 1 <= m && tx + 1 >= 1 && ty + 1 >= 1) {
		tx++;
		ty++;
		res += s[tx][ty];
	}
	tx = x, ty = y;
	while (tx + 1 <= n && ty - 1 <= m && tx + 1 >= 1 && ty - 1 >= 1) {
		tx++;
		ty--;
		res += s[tx][ty];
	}
	tx = x, ty = y;
	while (tx - 1 <= n && ty + 1 <= m && tx - 1 >= 1 && ty + 1 >= 1) {
		tx--;
		ty++;
		res += s[tx][ty];
	}
	tx = x, ty = y;
	while (tx - 1 <= n && ty - 1 <= m && tx - 1 >= 1 && ty - 1 >= 1) {
		tx--;
		ty--;
		res += s[tx][ty];
	}
	return res;
}

void solve() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &s[i][j]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int rec = solve2(i, j);
			ans = max(ans, rec);
		}
	}
	printf("%d\n", ans);
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}





string s[MAXN];

void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	int rec = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			int num = 0;
			for (int k = 0; k < m; k++) {
				num += abs(s[i][k] - s[j][k]);
			}
			rec = min(num, rec);
		}
	}
	printf("%d\n", rec);
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}





int s[MAXN];


void solve() {
	int n;
	scanf("%d", &n);
	int rec = INF;
	for (int i = 1; i <= n; i++) {
		scanf("%d", s + i);
		rec = min(rec, s[i]);
	}
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += s[i] - rec;
	}
	printf("%lld\n", sum);
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}





void solve() {
	string s;
	cin >> s;
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < s.length(); i++) {
		if (i < 3) {
			sum1 += s[i] - '0';
		} else {
			sum2 += s[i] - '0';
		}
	}
	if (sum1 == sum2)
		printf("YES\n");
	else
		printf("NO\n");
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}







ll a[MAXN];
inline void solve() {
	int n, k;
	int b[50] = {0};
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		for (int j = 0; j <= 30; j++) {
			if ((a[i] >> j) & 1) {
				b[j]++;
			}
		}
	}
	int ans = 0;
	for (int i = 30; i >= 0; i--) {
		if (k >= n - b[i]) {
			k -= n - b[i];
			ans |= 1 << i;
		}
	}
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}



inline void solve() {
	int n;
	scanf("%d", &n);
	string s;
	map<string, int> mp;
	map<char, int> mp1;
	map<char, int> mp2;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		ans += mp1[s[0]]++;
		ans += mp2[s[1]]++;
		ans -= mp[s] * 2;
		mp[s]++;
	}
	printf("%lld\n", ans);
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}



char s[100][100];
inline void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &s[i][j]);
		}
	}
	int rec;
	for (int i = 1; i <= m; i++) {
		for (int j = n; j >= 1; j--) {
			if (s[j][i] == '*') {
				rec = j;
				for (int k = j; k < n; k++) {
					if (s[k + 1][i] != '.') {
						break;
					}
					rec = k + 1;
				}
				s[j][i] = '.';
				s[rec][i] = '*';
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%c", s[i][j]);
		}
		putchar('\n');
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}




ll s[MAXN];
inline void solve() {
	int n;
	scanf("%d", &n);
	map<ll, int> mp;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", s + i);
		sum += s[i];
		mp[sum] = i;
	}
	int t;
	ll cnt = 0;
	bool flag = true;
	sum = 0;
	for (int i = n; i >= 1; i--) {
		sum += s[i];
		

		if (mp[sum]) {
			if (mp[sum] + n - i + 1 > n) {
				break;
			}
			cnt = mp[sum] + n - i + 1;
		}
	}
	printf("%lld\n", cnt);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}




inline void solve() {
	int n;
	scanf("%d", &n);
	int last1;
	int last2;
	scanf("%d %d", &last1, &last2);
	int t;
	bool flag = true;
	for (int i = 3; i <= n; i++) {
		scanf("%d", &t);
		if (flag)
			if (i & 1) {
				if (last1 % 2 != t % 2) {
					flag = false;
				}
			} else {
				if (last2 % 2 != t % 2) {
					flag = false;
				}
			}
	}
	if (flag) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}



inline void solve() {
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;
	if (n == 1 && s[0] != 'W') {
		printf("NO\n");
		return ;
	}
	int cnt = 0;
	char last;
	bool flag = true;
	map<char, int> mp;
	for (int i = 0; i < s.length(); i++) {
		mp[s[i]] = 1;
		if (flag)
			if (s[i] == 'W') {
				if (cnt == 1) {
					flag = false;
				}
				if ((mp['B'] + mp['R']) % 2) {
					flag = false;
				}
				cnt = 0;
				mp['B'] = 0;
				mp['R'] = 0;
			} else {
				cnt++;
			}
	}
	if (cnt == 1 || (mp['B'] + mp['R']) % 2) {
		flag = false;
	}
	if (flag) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}



inline void solve() {
	int n;
	scanf("%d", &n);
	if (n == 2) {
		printf("YES\n");
		return;
	}
	int last1;
	int last2;
	scanf("%d %d", &last1, &last2);
	int t;
	bool flag = true;
	for (int i = 3; i <= n; i++) {
		scanf("%d", &t);
		if (flag)
			if (i & 1) {
				if (last1 % 2 != t % 2) {
					flag = false;
				}
			} else {
				if (last2 % 2 != t % 2) {
					flag = false;
				}
			}
	}
	if (flag) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}




void solve() {
	int n;
	scanf("%d", &n);
	map<int, int> mp;
	int a;
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		if (flag)
			if (++mp[a] >= 3) {
				printf("%d\n", a);
				flag = false;
				

			}
	}
	if (flag)
		printf("-1\n");
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}



int a[MAXN];
inline void solve() {
	int n;
	scanf("%d", &n);
	int t;
	map<int, int> mp;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		if (++mp[t] >= 3) {
			printf("===%d\n", t);
			return;
		}
	}
	printf("======-1\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}



inline void solve() {
	int n;
	scanf("%d", &n);
	if (n <= 1399) {
		printf("Division 4\n");
	} else if (n > 1399 && n <= 1599) {
		printf("Division 3\n");
	} else if (n > 1599 && n <= 1899) {
		printf("Division 2\n");
	} else {
		printf("Division 1\n");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}



int fa[MAXN];
int cnt;
inline bool check(int mid) {
	int res = 0;
	for (int i = 1, j = mid - 1; i <= cnt; i++, j--) {
		res += max(0, fa[i] - j);
	}
	return mid - cnt >= res;
}

inline void solve() {
	int n;
	int t;
	map<int, int> mp;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &t);
		mp[t]++;
	}
	fa[1] = 0;
	cnt = 1;
	for (auto [a, b] : mp) {
		fa[++cnt] = mp[a] - 1;
	}
	sort(fa + 1, fa + cnt + 1, greater<int>());
	int l = 1, r = n;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	printf("%d\n", l);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}




int a[MAXN];
inline void solve() {
	int n;
	scanf("%d", &n);
	map<int, int> mp;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		mp[a[i]]++;
	}
	int maxx = 0;
	for (auto [a, b] : mp) {
		maxx = max(maxx, b);
	}
	if (maxx == n) {
		printf("0\n");
	} else {
		int cnt = 0;
		int t = maxx;
		

		while (t != n) {
			if (t + maxx < n) {
				cnt += 1 + maxx;
				t += maxx;
				maxx = t;
			} else {
				cnt += 1 + n - t;
				break;
			}
		}
		printf("%d\n", cnt);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}




inline void solve() {
	int n;
	scanf("%d", &n);
	printf("%d 1 1 1\n", n - 3);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}




int n;
ll h[MAXN];
inline void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", h + i);
	}

}


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}




int n;
ll d[MAXN];
const int mod = 32768;
inline void solve() {
	memset(d, 0x3f, sizeof(d));
	queue<ll> q;
	q.push(0);
	d[0] = 0;
	while (!q.empty()) {
		ll t = q.front();
		q.pop();
		ll x = (t + mod - 1) % mod;
		if (d[x] > d[t] + 1) {
			d[x] = d[t] + 1;
			q.push(x);
		}
		if (t % 2 == 0) {
			x = t / 2;
			if (d[x] > d[t] + 1) {
				d[x] = d[t] + 1;
				q.push(x);
			}
			x += mod / 2;
			if (d[x] > d[t] + 1) {
				d[x] = d[t] + 1;
				q.push(x);
			}
		}
	}
	int pp;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &pp);
		printf("%lld ", d[pp]);
	}
}

int main() {
	scanf("%d", &n);
	solve();
	return 0;
}




int a[MAXN];
int b[MAXN];
inline void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", b + i);
	}
	ll ans = 0;
	for (int i = 2; i <= n; i++) {
		ans += min(abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]), abs(a[i] - b[i - 1]) + abs(b[i] - a[i - 1]));
	}
	printf("%lld\n", ans);
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}





int tree[MAXN];
int c[MAXN];
int ans[MAXN];
int n;

inline void update(int pos, int x) {
	for (; pos <= n; pos += lowbit(pos)) {
		tree[pos] += x;
	}
}

inline int query(int pos) {
	int rec = 0;
	for (; pos; pos -= lowbit(pos)) {
		rec += tree[pos];
	}
	return rec;
}

inline void solve() {
	memset(tree, 0, sizeof(tree));
	memset(ans, 0, sizeof(ans));
	scanf("%d", &n);
	ll num = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", c + i);
		num += c[i];
	}
	num /= n;
	for (int i = n; i >= 1; i--) {
		if (num == 0) {
			break;
		}
		if (c[i] + query(i) >= i) {
			ans[i]++;
		}
		update(i - num + 1, -1);
		if (ans[i]) {
			num--;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}





int x[MAXN];
ll n, a, b;
inline void solve() {
	ll d = 0;
	scanf("%lld %lld %lld", &n, &a, &b);
	for (int i = 1; i <= n; i++) {
		scanf("%d", x + i);
		d += x[i];
	}
	ll ans = b * d;
	

	ll t;
	for (int i = 1; i < n; i++) {
		d -= x[i];
		

		t = b * (d - (n - i) * x[i]) + x[i] * (a + b);
		ans = min(ans, t);
	}
	printf("%lld\n", ans);
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}




int  t;
int n, r, b;
inline void solve() {
	int cnt = 1;
	int k = r / (b + 1);
	int res = r % (b + 1);
	for (int i = 1; i <= b + 1; i++) {
		for (int j = 1; j <= k; j++) {
			printf("R");
		}
		if (res-- > 0) {
			printf("R");
		}
		if (i <= b) {
			printf("B");
		}
	}
	printf("\n");
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &r, &b);
		solve();
	}
	return 0;
}




int n;
ll a[MAXN];
ll b[MAXN];
inline void solve() {
	ll ans = 1e18;
	for (int i = 1; i <= n; i++) {
		ll last = 0, tot = 0;
		for (int j = i + 1; j <= n; j++) {
			ll t = ceil((last + 1) * 1.0 / a[j]);
			tot += t;
			last = t * a[j];
		}
		last = 0;
		for (int j = i - 1; j >= 1; j--) {
			ll t = ceil((last + 1) * 1.0 / a[j]);
			tot += t;
			last = t * a[j];
		}
		ans = min(ans, tot);
	}
	printf("%lld\n", ans);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
	}
	solve();
	return 0;
}



ll n, m;
ll s[MAXN];
inline bool solve() {
	for (int i = 1; i <= n; i++) {
		scanf("%lld", s + i);
	}
	sort(s + 1, s + n + 1);
	ll sum = n + s[n] * 2;
	for (int i = n - 1; i > 1; i--) {
		sum += s[i];
	}
	if (m >= sum) {
		return true;
	}
	return false;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld %lld", &n, &m);
		if (solve()) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}
	return 0;
}




int t;
ll n, m;

inline void solve() {
	if (n > m) {
		swap(n, m);
	}
	if (n == 1) {
		if (m > 2) {
			printf("-1\n");
			return ;
		} else {
			printf("%d\n", m - 1);
			return ;
		}
	} else {
		if ((m - n) % 2 == 0) {
			printf("%lld\n", (n - 1) * 2 + (m - n) * 2);
		} else {
			printf("%lld\n", (n - 1) * 2 + (m - n) * 2 - 1);
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld %lld", &n, &m);
		solve();
	}
	return 0;
}

