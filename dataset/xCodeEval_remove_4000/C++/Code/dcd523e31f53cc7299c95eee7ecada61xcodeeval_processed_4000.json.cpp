

































using namespace std;


















typedef struct vector<ll> vll;
typedef struct vector<ld> vld;
typedef struct vector<vll> vvll;
typedef struct vector<vld> vvld;
typedef struct pair<ll, ll> ii;
const int MOD = 1e9 + 7;
const int MX = 1e5 + 7;
const long double PI = 3.141592653589793238462643383279;
struct defaut {
	ll cnt = 0;
};

int dem(ll x) {
	int cnt = 0;
	if (x == 1)return 0;
	while (x % 2 == 0) cnt++, x /= 2;
	for (int i = 3; i * i <= x; i += 2) {
		while (x % i == 0 and x > 1) cnt++, x /= i;
	}
	if (x > 1) cnt++;
	return cnt;
}

void solve(ll testcase) {
	ll n, m; cin >> n >> m;
	string s, st; cin >> s;
	vll a;
	st = '0' + s + '0';
	for (int i = 0; i < m; i++) {
		a.clear();
		for (int j = 1; j < sz(st) - 1; j++) {
			if (st[j] == '0')
				if (st[j - 1] == '0' and st[j + 1] == '1') a.push_back(j);
				else if (st[j - 1] == '1' and st[j + 1] == '0') a.push_back(j);
		}
		if (a.empty()) break;
		else {
			for (auto x : a) st[x] = '1';
		}
	}
	s = st.substr(1, n);
	cout << s << nl;
}

int main() {
	NDC;
	ll tc; ll i = 0;
	cin >> tc; for (i = 1; i <= tc; i++)
		solve(i);
	return 0;
}

