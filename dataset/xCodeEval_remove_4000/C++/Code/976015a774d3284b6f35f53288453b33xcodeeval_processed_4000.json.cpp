




























































































































































































































































































using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;













ll gcd(ll n, ll n1) {
	while (n != 0 && n1 != 0) {
		if (n > n1) n %= n1;
		else n1 %= n;
	}
	return n + n1;
}

ll lcm(ll n, ll n1) {
	ll nod = gcd(n, n1);
	return (n / nod) * (n1 / nod) * nod;
}


ll binpow(ll n, ll m) {
	if (m == 0)
		return (ll)1;
	if (m % 2 == 1)
		return binpow(n, m - 1) * n;
	else {
		ll b = binpow(n, m / 2);
		return b * b;
	}
}

ll INF = 999999999999999999;

mt19937 gen(time(0));

struct str {
	int f, s, id;
};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), f(n + 1, -1), l(n + 1, -1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		l[a[i]] = i;
		if (f[a[i]] == -1) f[a[i]] = i;
	}
	vector<str> e;
	e.reserve(2 * n);
	for (int i = 1; i <= n; i++) {
		if (f[i] != -1) {
			e.push_back({ 1, f[i], i });
			e.push_back({ 2, l[i], i });
		}
	}
	sort(all(e), [&](str& p, str& p1) {
		if (p.s == p1.s) return p.f < p1.f;
		return p.s < p1.s;
		});
	int mx = -1, smx = -1, fst = -1;
	int cnt = 0;
	for (str& p : e) {
		if (p.f == 2) {
			if (p.s == mx) {
				if(f[p.id] != l[p.id]) cnt++;
				mx = -1;
				fst = -1;
				

			}
			else if(p.s == smx){
				cnt++;
				smx = mx;
			}
		}
		else {
			if (mx == -1) {
				cnt++;
				fst = smx = mx = l[p.id];
			}
			else {
				mx = max(mx, l[p.id]);
			}
		}
	}
	cout << n - cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tt;
	

	tt = 1;
	while (tt--) {
		solve();
	}
	return 0;
}