
 













using namespace std;
const int N = int(1e5) + 1, mod = 998244353, inf = int(1e9);
const long long INF = 9223372036854775807;
const double long PI = 3.14159265358979323846;
 
void init_code() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
}
 
void id0() {
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);	
}

vector<ll> tmin;
vector<ll> tmax;
int k;


void build() {
	for (int i = k - 1; i > 0; i--) {
		tmin[i] = min(tmin[i << 1], tmin[i << 1 | 1]);

		tmax[i] = max(tmax[i << 1], tmax[i << 1 | 1]);
	}
}

ll querymin(int l, int r) {
	ll res = 1e18;
	for (l += k, r += k; l <= r; l >>= 1, r >>= 1) {
		if (l & 1) res = min(res, tmin[l++]);
		if (!(r & 1)) res = min(res, tmin[r--]);
	}
	return res;
}

ll querymax(int l, int r) {
	ll res = -1e18;
	for (l += k, r += k; l <= r; l >>= 1, r >>= 1) {
		if (l & 1) res = max(res, tmax[l++]);
		if (!(r & 1)) res = max(res, tmax[r--]);
	}
	return res;
}

void solve() {
	int n, pos; cin >> n >> pos;
	vector<ll> a(n + 2);
	k = n + 2;
	tmin.clear();
	tmax.clear();
	tmin.resize(2 * k);
	tmax.resize(2 * k);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<ll> pref(n + 2);
	pref[pos] = a[pos];
	for (int i = pos + 1; i < k; i++) {
		pref[i] = pref[i - 1] + a[i];
	}

	for (int i = 0; i < k; i++) {
		tmin[i + k] = pref[i];
		tmax[i + k] = pref[i];
	}
	build();
	ll sum = 0;
	int ans = 1;
	int j = pos;
	for (int i = pos; i >= 1; i--) {
		sum += a[i];
		if (sum < 0) ans = 0;
		int l = j, r = n + 2;
		while (r - l > 1) {
			int m = (r + l) / 2;
			if (sum + querymin(j, m) - pref[j] >= 0) {
				l = m;
			} else {
				r = m;
			}
		}
		if (l == n + 1) break;
		r = l;
		l = j - 1;
		ll mx = querymax(j, r);
		while (r - l > 1) {
			int m = (r + l) / 2;
			if (querymax(j, m) == mx) {
				r = m;
			} else {
				l = m;
			}
		}
		sum = sum + mx - pref[j];
		j = r;
	}
	if (ans) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}



int main() {
	init_code();
	fast_io;
	int tt;
	cin >> tt;
	for (int i = 1; i <= tt; i++) {
		solve();
	}
}