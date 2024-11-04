



















using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;


struct BIT {
	int n;
	vector<int> v;

	BIT(int _n) : n(_n), v(_n + 1, 0) {}

	int lowbit(int x) { return x & (-x); }

	void add(int i, int k) {
		while (i <= n) {
			v[i] += k;
			i += lowbit(i);
		}
	}

	int getSum(int i) {
		int res = 0;
		while (i > 0) {
			res += v[i];
			i -= lowbit(i);
		}
		return res;
	}

	int getSum(int l, int r) {
		return getSum(r) - getSum(l - 1);
	}
};
 
const ll base = 1e9 + 7;
 
ll pw(ll a, ll b) {
    ll t = a, r = 1;
    while (b) {
        if (b & 1) r = (r * t) % base;
        t = (t * t) % base;
        b >>= 1;
    }
    return r;
}
 
ll inv(ll x) {
    return pw(x, base - 2);
}
 
const int maxn = 1e6 + 42;
 
ll F[maxn], RF[maxn];
 
ll fact(ll n) {
    return F[n] ? F[n] : F[n] = n ? n * fact(n - 1) % base : 1;
}
ll rfact(ll n) {
    return RF[n] ? RF[n] : RF[n] = inv(fact(n));
}
 
ll nCr(ll n, ll r) {
    return fact(n) * rfact(r) % base * rfact(n - r) % base;
}
 
ll fuck(string s) {
	ll n = s.size();
	ll res = 0;
	stack<ll> st;
	for (ll i = 0; i < n; ++i) {
		if (s[i] == '0') {
			while (st.size()) st.pop();
		}
		else {
			ll p = !st.size() ? 0 : st.top() + 1;
			res += i - p + 1;
			st.push(i);
		}
	}
	return res;
}

void solve() {
    ll T = 1;
    cin >> T;

    for (ll ii = 0; ii < T; ++ii) {
		ll n;
		cin >> n;
		string s;
		cin >> s;
		stack<ll> st;
		ll res = 0;

		res += fuck(s);
		for (auto& c : s) c = '0' + (!(c - '0'));
		res += fuck(s);

		cout << res << endl;
	}
}

int main() {
	solve();
    return 0;
}












































































































































































































