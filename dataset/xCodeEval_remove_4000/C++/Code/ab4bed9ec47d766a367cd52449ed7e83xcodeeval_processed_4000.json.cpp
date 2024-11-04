
































using namespace std;
typedef long long ll;
using vi = vector<int>;
using pii = pair<ll, ll>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vb=vector<bool>;
using vvi = vector<vi>;


int z1, z2;
int dxtra(int n, vvpii& g, int start, int finish, vi& dist) {
	

	vector<bool>used(n + 1, 0);
	set<pair<int, int>>s;
	dist[start] = 0;
	s.insert({ 0, start });
	while (s.size() > 0) {
		auto it = *s.begin();
		int len = it.first;
		int v = it.second;
		s.erase(*s.begin());
		used[v] = 1;
		for (auto to : g[v]) {
			s.erase({ dist[to.first], to.first });
			dist[to.first] = min(dist[to.first], len + to.second);
			if(!used[to.first] && to.first!=z1 && to.first!=z2)s.insert({dist[to.first], to.first});
		}
	}
	if (dist[finish] == INT_MAX) return -1;
	return dist[finish];
}
inline int xin() {
	int n=0;
	

	scanf("%lld", &n);
	return n;
}
void masIn(int n, int* a) {
	for (int i = 0; i < n; i++) { *a = xin(); a++; }
}
void masIn(vi& a) {
	int n = a.size();
	for (int i = 0; i < n; i++) { a[i] = xin(); }
}



string toBits(int n)
{
	string s = "";
	if (n == 2) return "10";
	while (n != 0)
	{
		char c;
		c = n % 2 + 48;
		s += c;
		n /= 2;
	}
	reverse(s.begin(), s.end());
	return s;
}
unsigned int fact(int n) {
	unsigned int sum = 1;
	for (int i = 1; i <= n; i++)sum *= i;
	return sum;
}
vector<int> id0(int n, vector<vector<pair<int, int>>>& g, int start, int finish)
{
	

	vector<int>dist(n + 1, INT_MAX);
	vector<bool>used(n + 1, false);
	set<pair<int, int>>s;
	int* parent = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		parent[i] = 0;
	}
	dist[start] = 0;
	s.insert({ 0, start });
	int rev = 0;
	while (!s.empty())
	{
		auto it = *s.begin();
		int v = it.second;
		int len = it.first;
		used[v] = 1;

		s.erase(*s.begin());
		for (auto to : g[v])
		{
			s.erase({ dist[to.first], to.first });
			if (dist[to.first] > len + to.second) parent[to.first] = v;
			dist[to.first] = min(dist[to.first], len + to.second);
			if (!used[to.first])
			{
				s.insert({ dist[to.first], to.first });
			}
		}
	}
	vector<int>res(0);
	if (dist[finish] == INT_MAX)
	{
		res.push_back(-1);
		return res;
	}
	for (int i = n; i > start; i = parent[i])
	{
		res.push_back(i);
	}
	res.push_back(start);
	reverse(res.begin(), res.end());
	return res;
}

int safe_move(int x, int n, int step=32) {
	for (int i = 0; i < n;) {
		x = (x << min(step, n-i)) % MOD7;
		i += min(step, n - i);
	}
	return x;
}
int dfs(int& n, vvi& g, vi& a, vb& used, int& v, pair<int, int> excep={0, 0}) {
	int res = a[v - 1];
	used[v] = 1;
	for (auto to : g[v])if (!used[to] && make_pair(v, to)!=excep && make_pair(to, v)!=excep)res += dfs(n, g, a, used, to, excep);
	return res;
}
struct trip {
	int a;
	int b;
	int c;
};

int simple(int x)
{
	if (x == 1 || x % 2 == 0) return 0;
	int k = 2;
	int t = sqrt(x);
	for (int i = 2; i <= t; i++)
	{
		if (x % i == 0)
		{
			k++;
			break;
		}
	}
	return k == 2;
}
int nearf(int a, int b) {
	

	return min(122 - max(a, b) + (min(a, b) - 96), max(a, b) - min(a, b));
}
void near() {
	int n = xin();
	int p = 0;
	for (int i = n-1; i >= 2; i--) {
		if (simple(i) && n%i==0) {
			p = i;
			break;
		}
	}
	

	int mn = INT_MAX;
	for (int i = n - p + 1; i <= n; i++) {
		for (int j = i-1; j >= 2; j--) {
			if (simple(j) && i%j==0) {
				mn = min(mn, i-j+1);
				

				break;
			}
		}
	}
	cout << mn;
}

void exa() {
	int n = xin();
	string s;
	cin >> s;
	int p = n / 2;
	if (n % 2 == 0) p--;
	int res = 0;
	for (int i = p; i < n; i++) {
		if (s[i] != s[p]) break;
		res++;
	}
	for (int i = p - 1; i >= 0; i--) {
		if (s[i] != s[p]) break;
		res++;
	}
	cout << res << endl;
}
void exbb() {
	int n = xin();
	vi a(n);
	int res = (1 << 32) - 1;
	for (int i = 0; i < n; i++) {
		int x = xin();
		if (x != i) res = res & x;
	}
	cout << res << endl;
}
int LIS(vector<int> a) {
	int n = a.size();
	vi d(n+1, INT_MAX);
	d[0] = INT_MIN;
	vi pos(n+1, -1);
	vi pre(n+1, 0);
	int res = 0;
	for (int i = 0; i < n; i++) {
		
		int x = 0;
		for (; x < n && d[x]<a[i]; x++);
		

		

		if (x == 0) continue;
		if (d[x - 1] < a[i] && a[i] < d[x]) {
			d[x] = a[i];
			pos[x] = i;
			pre[x] = pos[x - 1];
			res = max(res, x);
		}
	}
	return res;
}
void exb() {
	int n = xin();
	vi a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int res = 0;
	vi rmas(n, 0);
	sort(a.begin(), a.end());
	int l = 0, r = n - 1;
	for (int i = 0; i < n; i++) {
		rmas[l] = a[i];
		i++;
		if(i<n)rmas[r] = a[i];
		l++;
		r--;
	}
	for (int i = 1; i < n; i++) {
		if (rmas[i] == rmas[i - 1]) res--;
	}
	int rres = res;
	

	int id1 = LIS(rmas);
	reverse(rmas.begin(), rmas.end());
	cout << min(id1, LIS(rmas))<<endl;
}
bool dp(vi& a, int i, int b, int c) {
	if (i == a.size()) {
		if (b == c) return 1;
		return 0;
	}
	return max(dp(a, i + 1, b + a[i], c), dp(a, i + 1, b, c + a[i]));
}
void solve() {
	int n = xin();
	vi a(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 0; i < n; i++) {
		if ((sum - a[i]) / (n - 1) == a[i] && (sum - a[i]) % (n - 1)==0) {
			

			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
}
int32_t main()
{
	int t = xin();
	

	

	

	while (t--) solve();
}





















































