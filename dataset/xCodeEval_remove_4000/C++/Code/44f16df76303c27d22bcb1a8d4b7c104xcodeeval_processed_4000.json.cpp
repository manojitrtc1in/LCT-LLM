












typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int MN = 65005;
const int MAXN = 1e6 + 10;
const int INF = 0x3f3f3f3f;






void solve() {
	int n;
	scanf("%d", &n);
	priority_queue<ll> qa, qb;
	ll tmp;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &tmp);
		qa.push(tmp);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &tmp);
		qb.push(tmp);
	}
	while (!qa.empty()) {
		if (qa.top() == qb.top()) {
			qa.pop();
			qb.pop();
		} else if (qa.top() < qb.top()) {
			ll tmp = qb.top();
			qb.pop();
			qb.push(tmp / 2);
		} else if (qa.top() > qb.top()) {
			if (qa.top() % 2) {
				printf("NO\n");
				return;
			} else {
				ll tmp = qa.top();
				qa.pop();
				qa.push(tmp / 2);
			}
		}


	}
	printf("YES\n");
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}



int head[MAXN];
int ver[MAXN];
int nxt[MAXN];
int cnt;
int vis[MAXN];
int rec;
void add(int x, int y) {
	ver[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
}

void dfs(int p) {
	rec++;


	for (int i = head[p]; i; i = nxt[i]) {
		int v = ver[i];
		if (vis[v])
			continue;
		vis[v] = 1;
		dfs(v);
	}
}

void solve() {
	cnt = 0;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		head[i] = 0;
		nxt[i] = 0;
		vis[i] = 0;
	}
	bool flag = false;
	int x, y;
	map<int, int> mp;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &x, &y);
		add(x, y);
		add(y, x);
		mp[x]++;
		mp[y]++;
		if (x == y || mp[x] > 2 || mp[y] > 2)
			flag = true;
	}
	if (flag)
		return void(printf("NO\n"));
	for (int i = 1; i <= n; i++) {
		rec = 0;
		if (!vis[i]) {
			vis[i] = 1;
			dfs(i);


			if (rec % 2) {
				flag = true;
				break;
			}
		}
	}
	if (flag)
		printf("NO\n");
	else
		printf("YES\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}




char s[MAXN];
void solve() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	int p;
	scanf("%d", &p);
	ll sum = 0;
	map<char, int> mp;
	map<char, int> vis;
	for (int i = 1; i <= n; i++) {
		sum += (s[i] - 'a' + 1);
		mp[s[i]]++;
	}
	if (sum <= p)
		printf("%s\n", s + 1);
	else {
		for (char ch = 'z'; ch >= 'a'; ch--) {
			if (!mp[ch])
				continue;
			int tmp = ch - 'a' + 1;
			if (p < sum - tmp * mp[ch]) {
				sum -= tmp * mp[ch];
				mp[ch] = 0;
				vis[ch] = 1;
			} else {
				int l = 1, r = mp[ch];
				while (l <= r) {
					int mid = l + r >> 1;
					if (p < sum - mid * tmp)
						l = mid + 1;
					else
						r = mid - 1;
				}
				mp[ch] -= l;
				vis[ch] = 1;
				break;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (mp[s[i]]) {
				printf("%c", s[i]);
				mp[s[i]]--;
			}
		}
		putchar('\n');
	}
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}




int tra[MAXN];
const int N = 2e5 + 5;



void solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	map<int, int> mp1, mp2;
	int a, b;
	for (int i = 1; i <= n; i++) {
		scanf("%d", tra + i);
		if (!mp1[tra[i]]) {
			mp1[tra[i]] = i;
		}


	}
	for (int i = n; i >= 1; i--) {
		if (!mp2[tra[i]]) {
			mp2[tra[i]] = i;
		}
	}
	while (k--) {
		scanf("%d %d", &a, &b);
		if (mp1[a] == 0 || mp1[b] == 0) {
			printf("NO\n");
			continue;
		}
		if (mp1[a] <= mp2[b]) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}



char s[MAXN];
void solve() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	int day = 0;
	int pos = 1;
	while (pos <= n) {
		day++;
		map<char, int> mp;
		mp[s[pos++]] = 1;
		while (pos <= n && mp[s[pos]]) {
			pos++;
		}
		mp[s[pos]] = 1;
		while (pos <= n && mp[s[pos]]) {
			pos++;
		}
		mp[s[pos]] = 1;
		while (pos <= n && mp[s[pos]]) {
			pos++;
		}
	}
	printf("%d\n", day);
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}





void solve() {
	int n;
	scanf("%d", &n);
	int cnt = 0;
	int tmp = n;
	while (tmp) {
		tmp /= 10;
		cnt++;
	}
	tmp = 1;
	for (int i = 1; i <= cnt - 1; i++) {
		tmp *= 10;
	}
	printf("%d\n", n - tmp);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}




const int N = 5e5 + 5;
int ver[N];
int head[N];
int nxt[N];
int cnt;
int n, m, e;
int mc[N];
int vis[1005];
void add(int x, int y) {
	ver[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
}

bool dfs(int p) {
	for (int i = head[p]; i; i = nxt[i]) {
		int v = ver[i];
		if (!vis[v]) {
			vis[v] = 1;
			if (mc[v] == 0 || dfs(mc[v])) {
				mc[v] = p;
				return true;
			}
		}
	}
	return false;
}

int match() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		if (dfs(i))
			cnt++;
	}
	return cnt;
}

int main() {


	scanf("%d%d%d", &n, &m, &e);
	for (int i = 1; i <= e; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		add(x, n + y);
	}
	printf("%d\n", match());
	return 0;
}




int n, m;
int head[MAXN];
int nxt[MAXN];
int cost[MAXN];
int ver[MAXN];
int color[20005];
int cnt;

void add(int x, int y, int c) {
	ver[++cnt] = y;
	cost[cnt] = c;
	nxt[cnt] = head[x];
	head[x] = cnt;
}

bool dfs(int p, int c, int mid) {
	color[p] = c;
	for (int i = head[p]; i; i = nxt[i]) {
		if (cost[i] <= mid)
			continue;
		int v = ver[i];
		if (color[v]) {
			if (color[p] == color[v])
				return false;
		} else if (!dfs(v, -c, mid))
			return false;
	}
	return true;
}

bool check(int mid) {
	memset(color, 0, sizeof(color));
	for (int i = 1; i <= n; i++) {
		if (!color[i]) {
			if (!dfs(i, 1, mid))
				return false;
		}
	}
	return true;
}

int main() {
	int x, y, c;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &c);
		add(x, y, c);
		add(y, x, c);
	}
	int l = 0, r = INF;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}
	printf("%d\n", l);
	return 0;
}





const int mod = 1e9 + 7;
int a[MAXN];
int b[MAXN];
int pre[MAXN];
int rec[MAXN];
bool vis[MAXN];
void init(int n) {
	for (int i = 1; i <= n; i++) {
		pre[i] = i;
		rec[i] = 1;
		vis[i] = 0;
	}
}

int find(int x) {
	if (pre[x] == x)
		return x;
	return pre[x] = find(pre[x]);
}

bool same(int x, int y) {
	return find(x) == find(y);
}

void solve() {
	map<int, int> mp;
	int n;
	scanf("%d", &n);
	init(n);
	int t;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		a[t] = i;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		b[t] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (same(a[i], b[i]))
			continue;
		int tmp1, tmp2;
		tmp1 = find(a[i]);
		tmp2 = find(b[i]);
		rec[tmp2] += rec[tmp1];
		pre[tmp1] = tmp2;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		if (t != 0)
			vis[find(i)] = 1;
	}
	ll ans = 1;
	for (int i = 1; i <= n; i++) {
		if (pre[i] == i) {
			if (!vis[i] && rec[i] > 1) {
				ans *= 2;
				ans %= mod;
			}
		}
	}
	printf("%lld\n", ans);
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}




char s[MAXN];
void solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	scanf("%s", s + 1);
	int pos1 = 0, pos2;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') {
			if (!pos1)
				pos1 = i;
			cnt++;


		}
	}
	if (cnt == 0)
		return void(printf("0\n"));
	for (int i = n; i >= 1; i--) {
		if (s[i] == '1') {
			pos2 = i;
			break;
		}
	}
	if (cnt == 1) {
		if (n - pos2 <= k)
			printf("1\n");
		else if (pos1 - 1 <= k)
			printf("10\n");
		else
			printf("11\n");
	} else {
		ll ans = cnt * 11;
		if (n - pos2 <= k) {
			ans -= 10;
			k -= (n - pos2);
			if (pos1 - 1 <= k)
				printf("%lld\n", ans - 1);
			else
				printf("%lld\n", ans);
		} else if (pos1 - 1 <= k) {
			printf("%lld\n", ans - 1);
		} else
			printf("%lld\n", ans);
	}
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}





int b[MAXN];
void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", b + i);
	}
	if (n % 2)
		return void(printf("NO\n"));
	sort(b + 1, b + n + 1);
	bool flag = true;
	if (b[1] >= b[n / 2 + 1])
		flag = false;
	for (int i = 2; i <= n / 2; i++) {
		if (b[i] >= b[n / 2 + i - 1])
			flag = false;
	}
	if (flag) {
		printf("YES\n");
		vector<int> v1, v2;
		for (int i = 1; i <= n; i++) {
			if (i <= n / 2)
				v1.push_back(b[i]);
			else
				v2.push_back(b[i]);
		}
		int pos1 = 0, pos2 = 0;
		for (int i = 1; i <= n; i++) {
			if (i % 2)
				printf("%d ", v1[pos1++]);
			else
				printf("%d ", v2[pos2++]);
		}
		putchar('\n');
	} else {
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




using P = pair<int, int>;
int b[MAXN];
int ans[MAXN];
vector<P> v[MAXN];
void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		v[i].clear();
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", b + i);
		int l = i / (b[i] + 1) + 1;
		int r;
		if (!b[i])
			r = n;
		else
			r = i / b[i];
		v[l].push_back(P(r, i));
	}
	priority_queue<P, vector<P>, greater<P> > que;
	for (int i = 1; i <= n; i++) {
		for (auto p : v[i])
			que.push(p);
		ans[que.top().second] = i;
		que.pop();
	}
	for (int i = 1; i <= n; i++) {
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



int n, m;
bool check(int mid, vector<int> &v) {
	ll r = m;
	for (int i = 1; i <= n; i++) {
		if (v[i] < mid)
			r -= v[i] + (mid - v[i]) / 2;
		else
			r -= mid;
	}
	if (r > 0)
		return 1;
	return 0;
}

void solve() {
	scanf("%d %d", &n, &m);
	vector<int> v(n + 1);
	for (int i = 1; i <= m; i++) {
		int x;
		scanf("%d", &x);
		v[x]++;
	}
	int l = 1, r = 2 * m;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid, v))
			l = mid + 1;
		else
			r = mid - 1;
	}
	printf("%d\n", l);
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}




const int mod = 998244353;
char s[25];
int dp[(1 << 8)][(1 << 8)];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		int a = 0;
		for (int j = 1; j <= m; j++) {
			a = (a << 1) | (s[j] == 'o');
		}
		int tmp = 1;
		int x = a >> 8, y = a & 255;
		for (int k = 0; k < (1 << 8); k++) {
			if (!(k & x)) {
				(tmp += dp[k][y]) %= mod;
			}
		}
		(ans += tmp) %= mod;
		for (int k = 0; k < (1 << 8); k++) {
			if (!(k & y)) {
				(dp[x][k] += tmp) %= mod;
			}
		}
	}
	printf("%lld\n", ans % mod);
	return 0;
}





double k[MAXN];
void solve() {
	ll s;
	scanf("%lld", &s);
	ll ans = 0;
	for (int i = 1; i <= 6; i++) {
		scanf("%lf", k + i);
	}
	ans += k[6] + k[5] + k[4] + ceil(k[3] / 4);
	ll rec2 = 5 * k[4];
	if ((int)k[3] % 4 == 1) {
		rec2 += 5;
	} else if ((int)k[3] % 4 == 2) {
		rec2 += 3;
	} else if ((int)k[3] % 4 == 3) {
		rec2 += 1;
	}
	if (k[2] > rec2) {
		ans += ceil((k[2] - rec2) / 9);
	}
	ll used = 6 * 6 * k[6] + 5 * 5 * k[5] + 4 * 4 * k[4] + 3 * 3 * k[3] + 2 * 2 * k[2];
	ll now = 6 * 6 * ans - used;
	if (k[1] > now)
		ans += ceil((k[1] - now) / 36);
	if (ans <= s)
		printf("Yes\n");
	else {
		printf("No\n");
	}
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}





int task[MAXN];
void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	map<int, int> mp;
	for (int i = 1; i <= m; i++) {
		scanf("%d", task + i);
		mp[task[i]]++;
	}
	int cnt = 0;
	vector<int> v;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (mp[i])
			v.push_back(mp[i]);
		else
			cnt++;
	}
	sort(v.begin(), v.end());
	int rec = 0, res = 0;
	for (int i = 0; i < v.size(); i++) {
		v[i] -= ans;
		if (v[i] == 1) {
			ans++;


		} else if (v[i] > 1) {
			v[i] = v[i] > rec ? v[i] - rec : 0;
			if (v[i])
				rec = 0;
			else
				rec -= v[i];
			while (v[i] > 0) {
				if (v[i] > 1) {
					v[i] -= 2;
					if (v[i] > cnt)
						v[i] -= cnt;
					else {
						rec += cnt - v[i];
						v[i] = 0;
					}
					ans += 2;
				} else if (v[i] == 1) {
					rec += cnt;
					if (i != v.size() - 1)
						res++;
					ans++;
					break;
				}
			}
		}
		cnt++;
	}
	printf("%d\n", ans + res);
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}




bool vis[MAXN];
void solve() {
	memset(vis, 0, sizeof(vis));
	int n;
	scanf("%d", &n);
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue;
		vis[i] = 1;
		for (int j = i; j <= n; j *= 2) {
			vis[j] = 1;
			ans.push_back(j);
		}
	}
	printf("2\n");
	for (auto v : ans) {
		printf("%d ", v);
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



int s[4][4];
void solve() {
	int sum = 0;
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= 2; j++) {
			scanf("%d", &s[i][j]);
			sum += s[i][j];
		}
	}
	if (sum == 0)
		printf("0\n");
	else if (sum == 4)
		printf("2\n");
	else
		printf("1\n");
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}





int a[MAXN];
int f[MAXN][2];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		if (i > 1) {
			f[i][0] = max(f[i - 1][0], f[i - 1][1] + a[i - 1] - 1);
			f[i][1] = max(f[i - 1][0] + a[i] - 1, f[i][1] + abs(a[i] - a[i - 1]));
		}
	}
	printf("%d", max(f[n][1], f[n][0]));
	return 0;
}




int k[10];
void solve() {
	int s;
	scanf("%d", &s);
	for (int i = 1; i <= n; i++) {
		scanf("%d", k + i);
	}
	s -= k[6];
	if (s < 0)
		printf("NO\n");
	else {
		s -= k[5];
		if (s < 0)
			printf("NO\n");
		else {
			k[1] = k[1] > 11 * k[5] ? k[1] - 11 * k[5] : 0;
			s -= k[4];
			if (s < 0)
				printf("NO\n");
			else {
				k[2] = k[2] > 5 * k[4] ? k[2] - 5 * k[4] : 0;
				s -= k[3] / 4;
				k[3] %= 4;
				if (k[3]) {

				}
			}
		}
	}
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}






int b[MAXN];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", b + i);
	}

	return 0;
}





string s;
string t[MAXN];
int main() {
	IOS;
	cin.tie(0);
	cin >> s;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
	}
	map<string, int> mp;
	vector<string> ans;
	for (int i = 1; i <= n; i++) {
		if (t[i].length() != s.length()) {
			mp[t[i]] = 0;
			continue;
		}
		int cnt = 0;
		for (int j = 0; j < s.length(); j++) {
			if (t[i][j] == s[j])
				cnt++;
		}
		mp[t[i]] = cnt;
	}
	int mx = 0;
	for (auto k : mp) {
		mx = max(mx, k.second);
	}


	if (mx == 0) {
		sort(t + 1, t + n + 1);
		for (int i = 1; i <= n; i++) {
			cout << t[i] << '\n';
		}
	} else {
		for (int i = 1; i <= n; i++) {
			if (mp[t[i]] == mx)
				ans.push_back(t[i]);
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {


			cout << ans[i] << '\n';
		}
	}
	return 0;
}





int a[MAXN];
void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	if (n % 2)
		printf("NO\n");
	else {
		sort(a + 1, a + n + 1);
		bool flag = true;
		map<int, int> mp;
		if (a[n / 2] == a[n / 2 + 1]) {
			for (int i = 1; i <= n; i++) {
				mp[a[i]]++;
			}
		}
		if (mp[a[n / 2]] > n / 2)
			flag = false;
		if (flag) {
			printf("YES\n");
			vector<int> v1, v2;


			for (int i = 1; i <= n; i++) {
				if (i <= n / 2)
					v1.push_back(a[i]);
				else
					v2.push_back(a[i]);
			}
			int pos1 = 0, pos2 = 0;
			for (int i = 1; i <= n; i++) {
				if (i % 2)
					printf("%d ", v1[pos1++]);
				else
					printf("%d ", v2[pos2++]);
			}
			putchar('\n');
		} else
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





int a[MAXN];
void solve() {
	int n;
	scanf("%d", &n);
	map<int, int> mp;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		mp[a[i]]++;
	}
	bool flag = true;
	for (auto t : mp) {
		if (t.second == 1) {
			flag = false;
			break;
		}
	}
	if (flag) {
		int pos;
		for (int i = 1; i <= n; i++) {
			if (a[i] != a[i - 1]) {
				printf("%d ", i + mp[a[i]] - 1);
			} else {
				printf("%d ", i - 1);
			}
		}
		putchar('\n');
	} else {
		printf("-1\n");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}



void solve() {
	int n;
	scanf("%d", &n);
	set<int> st;
	int a;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		st.insert(a);
	}
	if ((n - st.size()) % 2) {
		printf("%d\n", st.size() - 1);
	} else
		printf("%d\n", st.size());
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}



ll d[MAXN];
ll dp[MAXN];
int q[MAXN];
int head, tail;
int n;
void solve() {
	int k;
	scanf("%d", &k);
	dp[1] = 0;
	head = tail = 1;
	q[head] = 1;
	for (int i = 2; i <= n; i++) {
		if (d[q[head]] > d[i])
			dp[i] = dp[q[head]];
		else
			dp[i] = dp[q[head]] + 1;
		if (head <= tail && i - q[head] >= k)
			head++;
		while (head <= tail && (dp[q[tail]] > dp[i] || (dp[q[tail]] == dp[i] && d[q[tail]] < d[i])))
			tail--;
		q[++tail] = i;
	}
	printf("%lld\n", dp[n]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", d + i);
	}
	int q;
	scanf("%d", &q);
	while (q--)
		solve();
	return 0;
}




int n, k;
ll a[MAXN];
ll dp[MAXN];
int main() {
	scanf("%d %d", &n, &k);
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
		sum += a[i];
	}
	deque<int> q;
	for (int i = 1; i <= n; i++) {
		if (i <= k + 1)
			dp[i] = a[i];
		else
			dp[i] = dp[q.front()] + a[i];
		if (!q.empty() && i - q.front() >= k + 1)
			q.pop_front();
		while (!q.empty() && dp[q.back()] > dp[i])
			q.pop_back();
		q.push_back(i);
	}
	printf("%lld\n", sum - *min_element(dp + n - k, dp + n + 1));
	return 0;
}


int s[1005][1005];
int X[1005][1005], x[1005][1005];
int Y[1005][1005], y[1005][1005];





int main() {
	deque<int> q1, q2;
	int a, b, n;
	scanf("%d %d %d", &a, &b, &n);
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			scanf("%d", &s[i][j]);
		}
	}
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			if (!q1.empty() && j - q1.front() >= n)
				q1.pop_front();
			if (!q2.empty() && j - q2.front() >= n)
				q2.pop_front();
			while (!q1.empty() && s[i][q1.back()] < s[i][j]) {
				q1.pop_back();
			}
			while (!q2.empty() && s[i][q2.back()] > s[i][j]) {
				q2.pop_back();
			}
			q1.push_back(j);
			q2.push_back(j);
			if (j >= n) {
				X[i][j - n + 1] = s[i][q1.front()];
				x[i][j - n + 1] = s[i][q2.front()];
			}
		}
		q1.clear();
		q2.clear();
	}
	for (int i = 1; i <= b - n + 1; i++) {
		for (int j = 1; j <= a; j++) {
			if (!q1.empty() && j - q1.front() >= n)
				q1.pop_front();
			if (!q2.empty() && j - q2.front() >= n)
				q2.pop_front();
			while (!q1.empty() && X[q1.back()][i] < X[j][i])
				q1.pop_back();
			while (!q2.empty() && x[q2.back()][i] > x[j][i])
				q2.pop_back();
			q1.push_back(j);
			q2.push_back(j);
			if (j >= n) {
				Y[j - n + 1][i] = X[q1.front()][i];
				y[j - n + 1][i] = x[q2.front()][i];
			}
		}
		q1.clear();
		q2.clear();
	}
	int ans = INF;
	for (int i = 1; i <= a - n + 1; i++) {
		for (int j = 1; j <= b - n + 1; j++) {
			ans = min(ans, Y[i][j] - y[i][j]);
		}
	}
	printf("%d", ans);
	return 0;
}




int head[MAXN];
int nxt[MAXN];
int cnt;
int cost[MAXN];
int ver[MAXN];
void add(int x, int y, int c) {
	ver[++cnt] = y;
	cost[cnt] = c;
	nxt[cnt] = head[x];
	head[x] = cnt;
}
int b[MAXN];
int w[MAXN];
int dp[MAXN];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int x, y, c;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &x, &y, &c);
		add(y, x, c);
	}
	memset(dp, 0x3f, sizeof(dp));
	memset(b, 0x3f, sizeof(b));
	memset(w, 0x3f, sizeof(w));
	dp[n] = w[n] = b[n] = 0;
	queue<int> que;
	que.push(n);
	while (!que.empty()) {
		int t = que.front();
		que.pop();
		for (int i = head[t]; i; i = nxt[i]) {
			int v = ver[i];
			c = cost[i];
			if (c == 0) {
				if (b[v] <= n)
					continue;
				b[v] = dp[t] + 1;
				if (max(w[v], b[v]) <= n) {
					dp[v] = max(w[v], b[v]);
					que.push(v);
				}
			} else {
				if (w[v] <= n)
					continue;
				w[v] = dp[t] + 1;
				if (max(w[v], b[v]) <= n) {
					dp[v] = max(w[v], b[v]);
					que.push(v);
				}
			}
		}
	}
	if (dp[1] > n)
		printf("-1\n");
	else
		printf("%d\n", dp[1]);
	for (int i = 1; i <= n; i++) {
		if (b[i] > w[i])
			printf("0");
		else
			printf("1");
	}


	return 0;
}







int h[MAXN];
int dp[MAXN];
int main() {
	memset(dp, 0x3f, sizeof(dp));
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", h + i);
	}
	stack<int> s1, s2;
	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		while (!s1.empty() && h[s1.top()] < h[i]) {
			dp[i] = min(dp[i], dp[s1.top()] + 1);
			s1.pop();
		}
		if (!s1.empty())
			dp[i] = min(dp[i], dp[s1.top()] + 1);
		if (!s1.empty() && h[s1.top()] == h[i])
			s1.top() = i;
		else
			s1.push(i);
		while (!s2.empty() && h[s2.top()] > h[i]) {
			dp[i] = min(dp[i], dp[s2.top()] + 1);
			s2.pop();
		}
		if (!s2.empty())
			dp[i] = min(dp[i], dp[s2.top()] + 1);
		if (!s2.empty() && h[s2.top()] == h[i])
			s2.top() = i;
		else
			s2.push(i);
	}
	printf("%d\n", dp[n]);
	return 0;
}





using P = pair<int, int>;
stack<P> st;
int main() {
	int n;
	scanf("%d", &n);
	int t;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		P q(t, 1);
		while (!st.empty() && st.top().first <= t) {
			ans += st.top().second;
			if (st.top().first == t)
				q.second += st.top().second;
			st.pop();
		}
		if (!st.empty())
			ans++;
		st.push(q);
	}
	printf("%lld\n", ans);
	return 0;
}




ll m[MAXN];
ll dpl[MAXN], dpr[MAXN], dp[MAXN];
int nxt[MAXN], last[MAXN];
int top;
int st[MAXN];
int n;
ll ans[MAXN];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", m + i);
	}
	for (int i = 1; i <= n; i++) {
		nxt[i] = n + 1;
		while (top != 0 && m[st[top]] > m[i]) {
			nxt[st[top]] = i;
			top--;
		}
		st[++top] = i;

	}
	top = 0;
	for (int i = n; i >= 1; i--) {
		while (top != 0 && m[st[top]] > m[i]) {
			last[st[top]] = i;
			top--;
		}
		st[++top] = i;
	}
	for (int i = 1; i <= n; i++) {
		dpl[i] = m[i] * (i - last[i]) + dpl[last[i]];
	}
	for (int i = n; i >= 1; i--) {
		dpr[i] = m[i] * (nxt[i] - i) + dpr[nxt[i]];
	}
	ll mx = 0, pos;
	for (int i = 1; i <= n; i++) {
		dp[i] = dpl[i] + dpr[i] - m[i];
		if (dp[i] > mx)
			mx = dp[i], pos = i;
	}
	ans[pos] = m[pos];
	int tmp = pos;
	while (tmp) {
		int tt = tmp;
		while (tmp > last[tt]) {
			ans[tmp] = m[tt];
			tmp--;
		}
	}
	tmp = pos;
	while (tmp <= n) {
		int tt = tmp;
		while (tmp < nxt[tt]) {
			ans[tmp] = m[tt];
			tmp++;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%lld ", ans[i]);
	}
	return 0;
}




int a[MAXN];

void solve() {
	int n, s;
	scanf("%d %d", &n, &s);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		sum += a[i];
	}
	if (sum < s)
		printf("-1\n");
	else {
		int l, r;
		l = r = 1;
		int sum = 0;
		int ans = 0;
		while (l <= r) {
			while (r <= n && sum + a[r] <= s) {
				sum += a[r++];


			}


			if (sum == s)
				ans = max(ans, r - l);
			if (s > n)
				break;
			sum -= a[l++];
		}
		printf("%d\n", n - ans);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}




int a[MAXN];
void solve() {
	int n;
	scanf("%d", &n);
	map<int, vector<int> > mp;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		mp[a[i]].push_back(i);
	}
	int rec = a[1], l = 1, r = 1, ans = 1;
	for (auto [v, e] : mp) {
		int min = 0, k = e[0];
		for (int i = 0; i < e.size(); i++) {
			int j = e[i];
			int cur = i + 1 - (j - i - 1);
			if (cur - 1 < min) {
				min = cur - 1;
				k = j;
			}
			int now = cur - min ;
			if (now > ans) {
				ans = now;
				l = k;
				r = j;
				rec = v;
			}
		}
	}
	printf("%d %d %d\n", rec, l, r);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}





ll a[MAXN];
int b[MAXN];
void solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%lld", a + i);
	for (int i = 1; i <= n; i++) {
		b[i] = 0;
		if (a[i] < 2 * a[i + 1])
			b[i]++;
	}
	int tot = 0;
	for (int i = 1; i <= k; i++) {
		tot += b[i];
	}
	int ans = 0;
	if (tot == k)
		ans++;
	for (int i = k + 1; i < n; i++) {
		tot += b[i];
		tot -= b[i - k];
		if (tot == k)
			ans++;
	}
	printf("%d\n", ans);
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}





void solve() {
	int n;
	scanf("%d", &n);
	int a;
	map<int, int> mp;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		if (mp[a % 10] < 3) {
			mp[a % 10]++;
			v.push_back(a % 10);
		}
	}
	bool flag = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			for (int k = j + 1; k < v.size(); k++) {
				if ((v[i] + v[j] + v[k]) % 10 == 3) {
					flag = 1;
					break;
				}
			}
		}
	}
	if (flag)
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





ll s[MAXN];
ll pre[MAXN];
void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", s + i);
		pre[i] = pre[i - 1] + s[i];
	}
	if (pre[n] != 0)
		return void(printf("No\n"));
	bool flag = 1;
	for (int i = 1; i <= n; i++) {
		if (pre[i] < 0) {
			flag = 0;
			break;
		}
	}
	bool visit_zero = 0;
	for (int i = 1; i <= n; i++) {
		if (pre[i] == 0)
			visit_zero = 1;
		else if (visit_zero) {
			flag = 0;
			break;
		}
	}
	if (flag)
		printf("Yes\n");
	else
		printf("No\n");
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}




char s[MAXN];
void solve() {
	int n;
	scanf("%d", &n);
	scanf("%s", s + 1);
	ll ans = n;
	for (int i = 2; i <= n; i++) {
		if (s[i] != s[i - 1])
			ans += i - 1;
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





using P = pair<int, int>;
int a[MAXN];
void solve() {
	int n;
	scanf("%d", &n);
	P t1 = {INF, 0}, t2 = {INF, 0};
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	if (n % 2)
		printf("Mike\n");
	else {
		for (int i = 1; i <= n; i++) {
			if (i % 2) {
				if (t1.first > a[i])
					t1 = {a[i], i};
			} else {
				if (t2.first > a[i])
					t2 = {a[i], i};
			}
		}
		if (t1 > t2)
			printf("Mike\n");
		else if (t1 < t2)
			printf("Joe\n");
		else {
			if (t1.second < t2.second)
				printf("Joe\n");
			else
				printf("Mike\n");
		}
	}
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}




using P = pair<ll, ll>;
ll a[MAXN];
ll b[MAXN];
void solve() {
	int n1, n2, m;
	scanf("%d %d", &n1, &m);
	for (int i = 1; i <= n1; i++)
		scanf("%lld", a + i);
	scanf("%d", &n2);
	for (int i = 1; i <= n2; i++)
		scanf("%lld", b + i);
	vector<P> v1, v2;
	for (int i = 1; i <= n1; i++) {
		ll tmp = a[i], cnt = 1;
		while (tmp % m == 0) {
			tmp /= m;
			cnt *= m;
		}
		if (!v1.empty() && v1.back().first == tmp)
			v1.back().second += cnt;
		else
			v1.push_back(P(tmp, cnt));
	}
	for (int i = 1; i <= n2; i++) {
		ll tmp = b[i], cnt = 1;
		while (tmp % m == 0) {
			tmp /= m;
			cnt *= m;
		}
		if (!v2.empty() && v2.back().first == tmp)
			v2.back().second += cnt;
		else
			v2.push_back(P(tmp, cnt));
	}
	if (v1 == v2)
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



void solve() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	bool flag = true;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'b')
			cnt1++;
		if (t[i] == 'b')
			cnt2++;
	}
	if (cnt1 != cnt2)
		return void(cout << "NO\n");
	for (int i = 0, j = 0; i < s.length(); i++) {
		if (s[i] == 'b')
			continue;
		while (t[j] == 'b') {
			j++;
		}


		if (s[i] != t[j] || (s[i] == 'a' && j < i) || (s[i] == 'c' && j > i)) {
			flag = false;
			break;
		}
		j++;
	}
	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main() {
	int t;
	IOS;
	cin.tie(nullptr);
	cin >> t;


	while (t--)
		solve();
	return 0;
}



int n, q;
ll a[MAXN];
ll pre[MAXN];
void solve() {
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%lld\n", pre[n - x + y] - pre[n - x]);
}

int main() {


	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}
	while (q--)
		solve();
	return 0;
}



int a[MAXN];


void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		sum += a[i];
	}
	printf("%d\n", m >= sum ? 0 : sum - m);
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}




int n, k;
int head[MAXN];
int ver[MAXN];
int nxt[MAXN];
int cost[MAXN];
int cnt;
int dep[MAXN];
int dp[MAXN][21];
void add(int x, int y) {
	ver[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
}

void dfs1(int p, int fa) {
	for (int i = head[p]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == fa)
			continue;


		dfs1(v, p);
		for (int j = 1; j <= k; j++) {
			dp[p][j] += dp[v][j - 1];
		}
	}
}

void dfs2(int p, int fa) {
	for (int i = head[p]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == fa)
			continue;
		for (int j = k; j >= 2; j--) {
			dp[v][j] += dp[p][j - 1] - dp[v][j - 2];
		}
		dp[v][1] += cost[p];
		dfs2(v, p);
	}
}

int main() {
	scanf("%d %d", &n, &k);
	int x, y;
	for (int i = 1; i <= n - 1; i++) {
		scanf("%d %d", &x, &y);
		add(x, y);
		add(y, x);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", cost + i);
		dp[i][0] = cost[i];
	}
	dfs1(1, 0);
	dfs2(1, 0);
	for (int i = 1; i <= n; i++) {
		int ans = 0;
		for (int j = 0; j <= k; j++) {
			ans += dp[i][j];
		}
		printf("%d\n", ans);
	}
	return 0;
}



string s[MAXN];
const int base = 131;
ull st[MAXN];

string rev(string x) {
	reverse(x.begin(), x.end());
	return x;
}

void solve() {
	int n;
	scanf("%d", &n);
	map<string, int> mp;
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		if (s[i].length() == 1)
			flag = true;
	}
	if (flag)
		return void(printf("YES\n"));
	for (int i = 1; i <= n; i++) {
		mp[s[i]]++;
		string tmp = rev(s[i]);
		if (mp[tmp]) {
			flag = true;
			break;
		}
		if (s[i].length() == 2)
			for (char j = 'a'; j <= 'z'; j++) {
				if (mp[tmp + j]) {
					flag = true;
					break;
				}
			} else {
			string tmp1 = tmp.substr(0, 2);
			if (mp[tmp1])
				flag = true;
		}
		if (flag)
			break;
	}
	if (flag)
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



void solve() {
	int l, r, k;
	scanf("%d %d %d", &l, &r, &k);
	if (l == 1 && r == 1)
		return void(printf("NO\n"));
	if (k == r - l || r == l)
		return void(printf("YES\n"));
	int cnt;
	bool flag = false;
	if (l % 2 && r % 2) {
		cnt = (r - l) / 2 + 1;
	} else if (l % 2) {
		cnt = (r - l + 1) / 2;
	} else if (r % 2) {
		cnt = (r - l + 1) / 2;
	} else {
		cnt = (r - l) / 2;
	}
	if (cnt <= k)
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





struct node {
	int a, b;
} s[MAXN];

bool cmp(node a, node b) {
	return a.a < b.a;
}

void solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &s[i].a);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &s[i].b);
	}
	sort(s + 1, s + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		if (k >= s[i].a)
			k += s[i].b;
		else
			break;
	}
	printf("%d\n", k);
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}





int a[MAXN];
int pos[MAXN];
const int mod = 1e9 + 7;
void solve() {
	int n;
	ll ans = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		pos[a[i]] = i;
	}
	int mx = -INF, mn = INF;
	for (int i = 0; i < n; i++) {
		if (pos[i] > mn && pos[i] < mx) {
			ans *= (mx - mn + 1 - i);
			ans %= mod;
		}
		mn = min(mn, pos[i]);
		mx = max(mx, pos[i]);
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




struct MEX {
	int cot[MAXN];
	vector<int> res;
	int id = 0;
	void add(int x) {
		cot[x]++;
		res.push_back(x);
	}
	int mex() {
		while (cot[id])
			id++;
		return id;
	}
	void clear() {
		for (int v : res) {
			cot[v]--;
		}
		id = 0;
		res.clear();
	}
};
MEX now, t;
int a[MAXN];
int last[MAXN];

void solve() {
	now.clear();
	t.clear();
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (int i = n; i >= 1; i--) {
		t.add(a[i]);
		last[i] = t.mex();
	}
	vector<int> ans;
	int mx = last[1];
	for (int i = 1; i <= n; i++) {
		now.add(a[i]);
		if (mx == now.mex()) {
			ans.push_back(mx);
			mx = last[i + 1];
			now.clear();
		}
	}
	printf("%d\n", ans.size());
	for (int v : ans) {
		printf("%d ", v);
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



struct MEX {
	set<int> st;
	multiset<int> mst;
	int cot[MAXN];
	void init() {
		for (int i = 0; i < 2e5 + 5; i++)
			st.insert(i);
	}
	void add(int x) {
		if (cot[x] == 0) {
			st.erase(x);
		}
		cot[x]++;
		mst.insert(x);
	}
	void del(int x) {
		if (cot[x] == 1) {
			st.insert(x);
		}
		cot[x]--;
		mst.erase(mst.find(x));
	}
	int mex() {
		return *st.begin();
	}
	int size() {
		return mst.size();
	}
	void clear() {
		while (mst.size()) {
			del(*mst.begin());
		}
	}
};
MEX now, last;
int a[MAXN];

void solve() {
	now.clear();
	last.clear();
	int n;
	vector<int> ans;
	scanf("%d", &n);


	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		last.add(a[i]);
	}
	int mx = last.mex();
	for (int i = 1; i <= n; i++) {
		now.add(a[i]);
		last.del(a[i]);
		if (now.mex() == mx) {
			ans.push_back(mx);
			now.clear();
			mx = last.mex();
		}
	}
	printf("%d\n", ans.size());
	for (int v : ans) {
		printf("%d ", v);
	}
	putchar('\n');
}


int main() {
	now.init();
	last.init();
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}



void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	string s[2];
	if (n == 2 && m == 2) {
		printf("0 1\n1 0\n");
		return ;
	}
	s[0] = "1 0", s[1] = "0 1";
	int cnt = 0;
	if ((m / 2) % 2 == 0)

		for (int i = 1; i <= n; i++) {
			if (i % 2)
				cnt ^= 1;
			for (int j = 1; j <= m / 2; j++) {
				cout << s[cnt] << " ";
				cnt ^= 1;
			}
			cnt ^= 1;
			putchar('\n');

		} else {
		for (int i = 1; i <= n; i++) {
			if (i % 2)
				cnt ^= 1;
			for (int j = 1; j <= m / 2; j++) {
				cout << s[cnt] << " ";
				cnt ^= 1;
			}
			putchar('\n');
		}
	}
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}




void solve() {
	int n;
	scanf("%d", &n);
	if (n % 2)
		printf("-1\n");
	else
		printf("%d 0 0\n", n / 2);
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}







int n, m;
int head[MAXN];
int ver[MAXN];
int nxt[MAXN];
int cost[MAXN];
int cnt;
int rec;
int mid;
void add(int x, int y, int c) {
	ver[++cnt] = y;
	cost[cnt] = c;
	nxt[cnt] = head[x];
	head[x] = cnt;
}

int dfs(int p, int fa) {
	int ret = 0, x;
	multiset<int> s;
	multiset<int>::iterator it;
	for (int i = head[p]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == fa)
			continue;
		x = cost[i] + dfs(v, p);
		if (x >= mid)
			rec++;
		else
			s.insert(x);
	}

	while (!s.empty()) {
		it = s.begin();
		x = *it;
		s.erase(it);
		it = s.lower_bound(mid - x);
		if (it != s.end()) {
			rec++;
			s.erase(it);
		} else
			ret = max(ret, x);
	}
	return ret;
}
int dp[MAXN][2];
int mx = 0;

void dfs1(int p, int fa) {
	for (int i = head[p]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == fa)
			continue;
		dfs(v, p);
		int c = cost[i];
		if (dp[p][0] < dp[v][0] + c)
			dp[p][1] = dp[p][0], dp[p][0] = dp[v][0] + c;
		else if (dp[p][1] < dp[v][0] + c)
			dp[p][1] = dp[v][0] + c;
	}
	mx = max(mx, dp[p][1] + dp[p][0]);
}


int main() {
	scanf("%d %d", &n, &m);
	int x, y, c;
	for (int i = 1; i <= n - 1; i++) {
		scanf("%d %d %d", &x, &y, &c);
		add(x, y, c);
		add(y, x, c);
	}
	dfs1(1, 0);
	int l = 1, r = mx;

	while (l <= r) {
		mid = l + r >> 1;
		rec = 0;
		dfs(1, 0);
		if (rec >= m)
			l = mid + 1;
		else
			r = mid - 1;
	}
	printf("%d", r);
	return 0;
}





int n, m;
int head[MAXN];
int nxt[MAXN];
int ver[MAXN];
int cnt;
int dep[MAXN];
int LOG2[MAXN];
int fafa[MAXN][20];
void add(int x, int y) {
	ver[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
}

void dfs(int p, int fa) {
	fafa[p][0] = fa;
	for (int i = 1; i <= LOG2[dep[p]]; i++) {
		fafa[p][i] = fafa[fafa[p][i - 1]][i - 1];
	}

	for (int i = head[p]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == fa)
			continue;
		dep[v] = dep[p] + 1;
		dfs(v, p);
	}
}

int lca(int x, int y) {
	if (dep[x] < dep[y])
		swap(x, y);
	while (dep[x] != dep[y]) {
		x = fafa[x][LOG2[dep[x] - dep[y]]];
	}
	if (x == y)
		return x;

	for (int i = LOG2[dep[x]]; i >= 0; i--) {
		if (fafa[x][i] != fafa[y][i])
			x = fafa[x][i], y = fafa[y][i];
	}
	return fafa[x][0];
}

void solve() {
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	int tmp1 = lca(x, y);
	int tmp2 = lca(y, z);
	int tmp3 = lca(x, z);


	if (tmp1 == tmp2 && tmp1 == tmp3 && tmp2 == tmp3) {
		printf("%d %d\n", tmp1, dep[x] + dep[y] + dep[z] - 3 * dep[tmp1]);

	} else if (tmp1 == tmp2 && tmp1 != tmp3) {
		printf("%d %d\n", tmp3, dep[x] + dep[z] - 2 * dep[tmp3] + dep[tmp3] + dep[y] - 2 * dep[tmp1]);

	} else if (tmp1 == tmp3 && tmp1 != tmp2) {
		printf("%d %d\n", tmp2, dep[y] + dep[z] - 2 * dep[tmp2] + dep[tmp2] + dep[x] - 2 * dep[tmp1]);

	} else if (tmp2 == tmp3 && tmp1 != tmp2) {
		printf("%d %d\n", tmp1, dep[x] + dep[y] - 2 * dep[tmp1] + dep[tmp1] + dep[z] - 2 * dep[tmp2]);
	}
}


int main() {
	scanf("%d %d", &n, &m);
	for (int i = 2; i <= n; i++) {
		LOG2[i] = LOG2[i / 2] + 1;
	}
	dep[1] = 0;
	int x, y;

	for (int i = 1; i <= n - 1; i++) {
		scanf("%d %d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs(1, 0);
	while (m--)
		solve();
	return 0;
}





int n, m;
int head[MAXN];
int nxt[MAXN];
int ver[MAXN];
ll cost[MAXN];
ll dis[MAXN];
int last[MAXN];
int cnt;
void add(int x, int y, ll c) {
	ver[++cnt] = y;
	nxt[cnt] = head[x];
	cost[cnt] = c;
	head[x] = cnt;
}
ll ans;
ll maxlen;
int recv, recu;
bool vis[MAXN];

void dfs(int p, ll rec, int fa) {
	if (maxlen < rec)
		maxlen = rec, recv = p;
	for (int i = head[p]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == fa)
			continue;


		dfs(v, rec + cost[i], p);
	}
}

void dfs1(int p, int fa) {
	last[p] = fa;
	if (maxlen < dis[p])
		maxlen = dis[p], recu = p;
	for (int i = head[p]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == fa)
			continue;
		dis[v] = dis[p] + cost[i];
		dfs1(v, p);
	}
}
ll mxx[MAXN];
ll mx;

void dfs2(int p, ll rec, int fa) {
	mx = max(mx, rec);
	for (int i = head[p]; i; i = nxt[i]) {
		int v = ver[i];
		if (vis[v] || v == fa)
			continue;
		dfs2(v, rec + cost[i], p);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	int x, y;
	ll c;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %lld", &x, &y, &c);
		add(x, y, c);
		add(y, x, c);
	}
	dfs(1, 0, 0);
	maxlen = 0;
	dfs1(recv, 0);
	ll tmp = 0;

	for (int i = recu; i; i = last[i]) {
		vis[i] = 1;
	}

	for (int i = recu; i; i = last[i]) {
		mx = 0;
		dfs2(i, 0, 0);
		mxx[i] = mx;
	}
	mx = 0;

	for (int i = recu; i; i = last[i]) {
		tmp = min(dis[i], maxlen - dis[i]);
		mx = max(mx, mxx[i] + tmp);
	}
	printf("%lld\n", mx + maxlen);
	return 0;
}






int n;
int ver[MAXN];
int head[MAXN];
int nxt[MAXN];
ll cost[MAXN];
int last[MAXN];
int nxxt[MAXN];
ll dis[MAXN], mmm[MAXN], op;
bool vis[MAXN];
int u, v;
int cnt;
void add(int x, int y, ll c) {
	ver[++cnt] = y;
	cost[cnt] = c;
	nxt[cnt] = head[x];
	head[x] = cnt;
}

void dfs1(int o, ll p, int q) {
	if (p > op)
		op = p, u = o;
	for (int i = head[o]; i; i = nxt[i]) {
		if (ver[i] == q)
			continue;
		dfs1(ver[i], p + cost[i], o);
	}
}

void dfs2(int o, ll p, int q) {
	last[o] = q;
	dis[o] = p;
	if (p > op)
		op = p, v = o;
	for (int i = head[o]; i; i = nxt[i]) {
		if (ver[i] == q)
			continue;
		dfs2(ver[i], p + cost[i], o);
	}
}

void dfs(int o, ll p, int q) {
	if (p > op)
		op = p;
	for (int i = head[o]; i; i = nxt[i]) {
		if (vis[ver[i]] || ver[i] == q)
			continue;
		dfs(ver[i], p + cost[i], o);
	}
}

int main() {
	scanf("%d", &n);
	int x, y;
	ll c;
	for (int i = 1; i <= n - 1; i++) {
		scanf("%d %d %lld", &x, &y, &c);
		add(x, y, c);
		add(y, x, c);
	}
	dfs1(1, 0, 0);
	op = 0;
	dfs2(u, 0, 0);
	ll distance = dis[v];
	printf("%lld\n", distance);

	for (int i = v; i; i = last[i]) {
		vis[i] = 1;
	}

	for (int i = v; i; i = last[i]) {
		op = 0;
		dfs(i, 0, 0);
		mmm[i] = op;
	}

	for (int i = last[v], j = v; i; i = last[i]) {
		nxxt[i] = j, j = i;
	}
	int tmp;

	for (int i = u; i; i = nxxt[i]) {
		if (dis[v] - dis[i] == mmm[i]) {
			tmp = i;
			break;
		}
	}
	int ans = 0;

	for (int i = tmp; i; i = last[i]) {
		if (dis[i] == mmm[i])
			break;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}





const int N = (int) 3e3 + 5;


bitset<N> s[N];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		reverse(str.begin(), str.end());
		s[i] = bitset<N>(str);
	}
	ll res = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (s[i][j] == 1) {
				res += (s[i] & s[j]).count();
			}
		}
	}
	printf("%lld", res / 3);
	return 0;
}





int ver[MAXN];
int head[MAXN];
int nxt[MAXN];
int cnt;
int in[MAXN];
int tuop[MAXN];
int cnt1;
void add(int x, int y) {
	ver[++cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
	in[y]++;
}
int n, m;
const int N = 3e4 + 5;
bitset<N> rec[N];

void topsort() {
	queue<int> q;
	map<int, int> mp;
	for (int i = 1; i <= n; i++) {
		if (in[i])
			continue;
		q.push(i);
	}

	while (!q.empty()) {
		int t = q.front();
		q.pop();
		tuop[++cnt1] = t;
		for (int i = head[t]; i; i = nxt[i]) {
			int v = ver[i];
			in[v]--;
			if (!in[v])
				q.push(v);
		}
	}
}


int main() {
	scanf("%d %d", &n, &m);
	int x, y;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		add(x, y);
	}
	topsort();

	for (int i = n; i >= 1; i--) {
		int j = tuop[i];
		rec[j][j] = 1;
		for (int k = head[j]; k; k = nxt[k]) {
			int v = ver[k];
			rec[j] |= rec[v];
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d\n", rec[i].count());
	}
	return 0;
}




int main() {
	ll n, q, x, sum = 0;
	scanf("%lld %lld %lld", &n, &q, &x);
	vector<ll> w(n * 2), to(n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &w[i]);
		sum += w[i];
		w[n + i] = w[i];
	}
	ll now = 0;
	ll y = x % sum;

	for (int l = 0, r = -1; l < n; l++) {
		while (r + 1 < 2 * n && now < y) {
			now += w[r + 1];
			r++;
		}
		to[l] = r;
		now -= w[l];
	}

	for (int i = 1; i < 2 * n; i++) {
		w[i] += w[i - 1];
	}
	vector<pair<ll, ll> > seq, seq2;
	set<int> pos;
	ll start = 0;
	ll add = x / sum * n;

	while (1) {
		seq.push_back({start, add + to[start] - start + 1});
		start = (to[start] % n + 1) % n;
		if (pos.find(start) != pos.end()) {
			for (int j = 0; j < (int)seq.size(); j++) {
				if (seq[j].first == start) {
					for (int k = j; k < (int)seq.size(); k++) {
						seq2.push_back(seq[k]);
					}
					break;
				}
			}
			break;
		}
		pos.insert(start);
	}

	for (int i = 0; i < q; i++) {
		ll k;
		scanf("%lld", &k);
		k--;
		if (k < seq.size()) {
			printf("%lld\n", seq[k].second);
		} else {
			k -= (ll)seq.size();
			k %= (ll)seq2.size();
			printf("%lld\n", seq2[k].second);
		}
	}
	return 0;
}




int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	long long ans = (long long) 4e18;
	long long sum = 0;

	for (int i = 0; i < n && i < x; i++) {
		sum += a[i] + b[i];
		long long cur = sum + (long long) b[i] * (x - i - 1);
		ans = min(ans, cur);
	}
	cout << ans << '\n';
	return 0;
}





ll a[MAXN];
ll b[MAXN];

int main() {
	int n, x;
	scanf("%d %d", &n, &x);
	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld", a + i, b + i);
	}

	return 0;
}



char s[MAXN];
int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	scanf("%s", s + 1);
	int t, x;
	int tmp = 0;
	for (int i = 1; i <= q; i++) {
		scanf("%d %d", &t, &x);
		if (t == 1) {
			tmp += x;
		} else {
			tmp %= n;
			if (x > tmp)
				printf("%c\n", s[x - tmp]);
			else {
				printf("%c\n", s[n - tmp + x]);
			}
		}
	}
	return 0;
}




string s;
int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	cin >> s;
	int t, x;
	for (int i = 1; i <= q; i++) {
		scanf("%d %d", &t, &x);
		if (t == 1) {
			int len = s.length();
			string tmp = s.substr(len - x, x);
			s.erase(len - x, x);
			s.insert(0, tmp);
		} else {
			cout << s[x - 1] << endl;
		}
	}
	return 0;
}






int n;
int a[500][500];














int go[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int main() {
	scanf("%d", &n);
	vector<P> v;
	int mx = 0;
	char s[50];
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		for (int j = 1; j <= n; j++) {
			a[i][j] = s[j] - '0';
			mx = max(mx, a[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == mx)
				v.push_back(P(i, j));
		}
	}
	ll ans = 0;

	for (auto e : v) {
		for (int i = 0; i < 8; i++) {
			ll tmp = mx;
			int t = n - 1;
			int x = e.first, y = e.second;
			while (t--) {
				x = x + go[i][0];
				y = y + go[i][1];
				if (x > n)
					x = 1;
				else if (x < 1)
					x = n;
				if (y > n)
					y = 1;
				else if (y < 1)
					y = n;
				tmp *= 10;
				tmp += a[x][y];
			}
			ans = max(ans, tmp);
		}
	}
	printf("%lld\n", ans);
	return 0;
}




int n, m;
int ver[MAXN];
int cost[MAXN];
int nxt[MAXN];
int dis[MAXN];
int head[MAXN];
int cnt;
int dp[MAXN][2];
void add(int x, int y, int c) {
	ver[++cnt] = y;
	cost[cnt] = c;
	nxt[cnt] = head[x];
	head[x] = cnt;
}
int ans;

void dfs(int q, int fa = -1) {
	for (int i = head[q]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == fa)
			continue;
		dfs(v, q);
		if (dp[q][0] < dp[v][0] + cost[i])
			dp[q][1] = dp[q][0], dp[q][0] = dp[v][0] + cost[i];
		else if (dp[q][1] < dp[v][0] + cost[i])
			dp[q][1] = dp[v][0] + cost[i];
	}
	ans = max(ans, dp[q][0] + dp[q][1]);
}

int main() {
	char ch;
	scanf("%d %d", &n, &m);
	int x, y, c;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d %c", &x, &y, &c, &ch);
		add(x, y, c);
		add(y, x, c);
	}
	dfs(1);
	printf("%d", ans);
}





int n, m;
int ver[MAXN];
int cost[MAXN];
int nxt[MAXN];
int dis[MAXN];
int head[MAXN];
int cnt;
void add(int x, int y, int c) {
	ver[++cnt] = y;
	cost[cnt] = c;
	nxt[cnt] = head[x];
	head[x] = cnt;
}

void dfs(int q, int fa = -1) {
	for (int i = head[q]; i; i = nxt[i]) {
		int v = ver[i];
		if (v == fa)
			continue;
		dis[v] = dis[q] + cost[i];
		dfs(v, q);
	}
}

int main() {
	char ch;
	scanf("%d %d", &n, &m);
	int x, y, c;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d %c", &x, &y, &c, &ch);
		add(x, y, c);
		add(y, x, c);
	}
	dfs(1);
	int maxlen = 0, tmp, ans = 0;

	for (int i = 1; i <= n; i++) {
		if (maxlen < dis[i])
			maxlen = dis[i], tmp = i;
		dis[i] = 0;
	}
	dfs(tmp);

	for (int i = 1; i <= n; i++) {
		ans = max(ans, dis[i]);
	}
	printf("%d", ans);
	return 0;
}


