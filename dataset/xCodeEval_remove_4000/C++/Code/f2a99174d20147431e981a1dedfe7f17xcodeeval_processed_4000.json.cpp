












using namespace std;





using namespace tr1;










using namespace __gnu_pbds;


typedef __gnu_pbds::priority_queue<int, greater<int>, pairing_heap_tag> pq_type;


typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> tree_type;



typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef __uint128_t ulll;
typedef __int128_t lll;
std::istream& operator >>(std::istream &src, __uint128_t& tmp) {
	std::istream::sentry s(src);
	if (s) {
		char buffer[128];
		src >> buffer;
		char* ptr = buffer;
		tmp = 0;
		while (*ptr <= '9' && *ptr >= '0') {
			tmp = tmp * 10 + (*ptr - '0');
			++ptr;
		}
		if (buffer[0] == '-') tmp = -tmp;
	}
	return src;
}
std::istream& operator >>(std::istream &src, __int128_t& tmp) {
	std::istream::sentry s(src);
	if (s) {
		char buffer[128];
		src >> buffer;
		char* ptr = buffer;
		if (*ptr == '-') ++ptr;
		tmp = 0;
		while (*ptr <= '9' && *ptr >= '0') {
			tmp = tmp * 10 + (*ptr - '0');
			++ptr;
		}
		if (buffer[0] == '-') tmp = -tmp;
	}
	return src;
}
std::ostream& operator <<(std::ostream &dest, __uint128_t tmp) {
	std::ostream::sentry s(dest);
	if (s) {
		char buffer[128];
		char *d = std::end(buffer);
		do {
			--d;
			*d = "0123456789"[tmp % 10];
			tmp /= 10;
		} while (tmp != 0);
		int len = std::end(buffer) - d;
		if (dest.rdbuf()->sputn(d, len) != len) {
			dest.setstate(std::ios_base::badbit);
		}
	}
	return dest;
}
std::ostream& operator<<(std::ostream &dest, __int128_t value) {
	std::ostream::sentry s(dest);
	if (s) {
		if (value < 0) dest << "-";
		__uint128_t tmp = value < 0 ? -value : value;
		dest << tmp;
	}
	return dest;
}
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef map<string, int> mpsi;
typedef map<double, int> mpdi;
typedef map<int, int> mpii;

const double pi = acos(0.0) * 2.0;
const long double eps = 1e-10;
const int step[8][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 1 }, {
		1, 1 }, { 1, -1 }, { -1, -1 } };

template<class T> inline T abs1(T a) {
	return a < 0 ? -a : a;
}


template <class T> inline T max1(T a, T b) { return b < a ? a : b; }
template <class T> inline T max1(T a, T b, T c) { return max1(max1(a, b), c); }
template <class T> inline T max1(T a, T b, T c, T d) { return max1(max1(a, b, c), d); }
template <class T> inline T max1(T a, T b, T c, T d, T e) { return max1(max1(a, b, c, d), e); }
template <class T> inline T min1(T a, T b) { return a < b ? a : b; }
template <class T> inline T min1(T a, T b, T c) { return min1(min1(a, b), c); }
template <class T> inline T min1(T a, T b, T c, T d) { return min1(min1(a, b, c), d); }
template <class T> inline T min1(T a, T b, T c, T d, T e) { return min1(min1(a, b, c, d), e); }

template<typename t, typename t1>
t min1(t a, t1 b) {
	return a < b ? a : b;
}
template<typename t, typename ... arg>
t min1(t a, arg ... arr) {
	return min1(a, min1(arr...));
}
template<typename t, typename t1>
t max1(t a, t1 b) {
	return a > b ? a : b;
}
template<typename t, typename ... arg>
t max1(t a, arg ... arr) {
	return max1(a, max1(arr...));
}


inline int jud(double a, double b) {
	if (abs(a) < eps && abs(b) < eps)
		return 0;
	else if (abs1(a - b) / max(abs1(a), abs1(b)) < eps) return 0;
	if (a < b) return -1;
	return 1;
}
template<typename t> inline int jud(t a, t b) {
	if (a < b) return -1;
	if (a == b) return 0;
	return 1;
}



template<typename it, typename t1>
inline int RangeFind(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1) {
	if (na == 0) return 0;
	int be = 0, en = na - 1;
	if (*a <= *(a + na - 1)) {
		if (f_lb == 0)
			while (be < en) {
				int mid = (be + en + 1) / 2;
				if (jud(*(a + mid), val) != 1)
					be = mid;
				else
					en = mid - 1;
			}
		else
			while (be < en) {
				int mid = (be + en) / 2;
				if (jud(*(a + mid), val) != -1)
					en = mid;
				else
					be = mid + 1;
			}
		if (f_small && jud(*(a + be), val) == 1) be--;
		if (!f_small && jud(*(a + be), val) == -1) be++;
	} else {
		if (f_lb)
			while (be < en) {
				int mid = (be + en + 1) / 2;
				if (jud(*(a + mid), val) != -1)
					be = mid;
				else
					en = mid - 1;
			}
		else
			while (be < en) {
				int mid = (be + en) / 2;
				if (jud(*(a + mid), val) != 1)
					en = mid;
				else
					be = mid + 1;
			}
		if (!f_small && jud(*(a + be), val) == -1) be--;
		if (f_small && jud(*(a + be), val) == 1) be++;
	}
	return be;
}

template<class T> inline T lowb(T num) { return num & (-num); }

inline int bitnum(ui nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(ull nValue) { return __builtin_popcountll(nValue); }
inline int bitnum(ll nValue) { return __builtin_popcountll(nValue); }
inline int id0(ui a) { if (a == 0) return 0; return 32 - __builtin_clz(a); }
inline int id0(int a) { if (a == 0) return 0; return 32 - __builtin_clz(a); }
inline int id0(ull a) { if (a == 0) return 0; return 64 - __builtin_clzll(a); }
inline int id0(ll a) { if (a == 0) return 0; return 64 - __builtin_clzll(a); }



long long pow(long long n, long long m, long long mod = 0) {
	if (m < 0) return 0;
	long long ans = 1;
	long long k = n;
	while (m) {
		if (m & 1) {
			ans *= k;
			if (mod) ans %= mod;
		}
		k *= k;
		if (mod) k %= mod;
		m >>= 1;
	}
	return ans;
}


template<class t1, class t2>
inline void add(t1 &a, t2 b, int mod = -1) {
	if (mod == -1) mod = MOD;
	a += b;
	while (a >= mod) a -= mod;
	while (a < 0) a += mod;
}
template<class t>
void output1(t arr) {
	for (int i = 0; i < (int) arr.size(); i++) cerr << arr[i] << ' ';
	cerr << endl;
}
template<class t>
void output2(t arr) {
	for (int i = 0; i < (int) arr.size(); i++) output1(arr[i]);
}




const int mod = MOD;
const int maxn = 1210;
ll orig[maxn], pow2[maxn];
ll pos[maxn], lpos, neg[maxn], lneg;
pll loc[maxn];
ll dp1[maxn][maxn], dp2[maxn][maxn][2][2];
ll dp_pos[maxn], dp_neg[maxn];
ll addto_dp1_pos[maxn][maxn], addto_dp1_neg[maxn][maxn];
int n, k;

inline int Sgn(int num) {
	return num >= 0 ? 1 : -1;
}

int main() {




	ios_base::sync_with_stdio(0);


	freopen("input.txt", "r", stdin);



	pow2[0] = 1;
	for (int i = 1; i < maxn; i++) pow2[i] = pow2[i - 1] * 2 % mod;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", orig + i);
	}
	sort(orig, orig + n, [&](const int &a, const int &b) {
		return abs(a) < abs(b);
	});
	pos[lpos++] = neg[lneg++] = -1;
	for (int i = 0; i < n; i++) {
		loc[i] = mpr(lpos - 1, lneg - 1);
		if (orig[i] >= 0) {
			loc[i].first++;
			pos[lpos++] = i;
		} else {
			loc[i].second++;
			neg[lneg++] = i;
		}
 	}

	for (int i = 1; i < lpos; i++) for (int j = i + 1; j < lpos; j++) {
		int l = 1, r = lneg - 1;
		int min_neg = loc[pos[i]].second + 1;
		if (min_neg >= lneg) continue;
		for (; l < lneg && neg[l] < pos[j]; l++) {
			while (r > l && orig[pos[i]] * orig[pos[j]] < orig[neg[l]] * orig[neg[r]]) r--;
			if (l >= r) {
				addto_dp1_neg[j][max(l + 1, min_neg)] += pow2[l + i - 2] * (-orig[neg[l]]);
				addto_dp1_neg[j][max(l + 1, min_neg)] %= mod;
				continue;
			}

			addto_dp1_pos[j][max(l + 1, min_neg)] += pow2[l + i - 2] * orig[pos[i]] % mod * orig[pos[j]];
			addto_dp1_pos[j][max(l + 1, min_neg)] %= mod;
			addto_dp1_pos[j][max(r + 1, min_neg)] -= pow2[l + i - 2] * orig[pos[i]] % mod * orig[pos[j]];
			addto_dp1_pos[j][max(r + 1, min_neg)] %= mod;

			addto_dp1_neg[j][max(r + 1, min_neg)] += pow2[l + i - 2] * (-orig[neg[l]]);
			addto_dp1_neg[j][max(r + 1, min_neg)] %= mod;
		}
	}
	for (int i = 1; i < lpos; i++) for (int j = i + 1; j < lpos; j++) {
		int min_neg = loc[pos[i]].second + 1;
		if (min_neg >= lneg) continue;
		addto_dp1_pos[j][min_neg] += pow2[i - 1] * orig[pos[i]] % mod * orig[pos[j]];
		addto_dp1_pos[j][min_neg] %= mod;
	}
	for (int i = 1; i < lneg; i++) for (int j = loc[neg[i]].first + 1; j < lpos; j++) {
		addto_dp1_neg[j][i + 1] += pow2[i - 1] * (-orig[neg[i]]);
		addto_dp1_neg[j][i + 1] %= mod;
	}

	for (int i = 0; i < lpos; i++) for (int j = 1; j < lneg; j++) {
		addto_dp1_pos[i][j] += addto_dp1_pos[i][j - 1];
		addto_dp1_pos[i][j] %= mod;
		addto_dp1_neg[i][j] += addto_dp1_neg[i][j - 1];
		addto_dp1_neg[i][j] %= mod;
	}

	for (int i = 0; i < lpos; i++) for (int j = 0; j < lneg; j++) {
		dp1[i][j] += addto_dp1_neg[i][j] * (-orig[neg[j]]);
		dp1[i][j] += addto_dp1_pos[i][j];
		dp1[i][j] %= mod;
	}

	ll ans = 0;
	dp2[0][n][0][0] = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int remain = k % 2; remain >= 0; remain--)
			for (int rk = min(k / 2, (n - i - 1 - remain) / 2); rk >= 0; rk--)
				for (int occ = i + 1; occ <= n; occ++) for (int yu = 1; yu >= 0; yu--) if (dp2[rk][occ][remain][yu]) {
					auto upd = [&](ll& dp_node, ll multi) {
						dp_node += dp2[rk][occ][remain][yu] * multi;
						dp_node %= mod;
					};
					if (yu) {
						if (Sgn(orig[occ]) != Sgn(orig[i])) {
							upd(dp2[rk + 1][occ][remain][0], abs(orig[i]));
						}
						continue;
					}
					if (orig[i] >= 0) {
						if (remain < k % 2) {
							upd(dp2[rk][occ][k % 2][0], abs(orig[i]));
						} else {
							if (occ == n) {
								upd(dp2[rk][i][k % 2][0], 1);
							} else if (orig[occ] < 0) {
								if (rk == k / 2 - 1) {
									ans += dp2[rk][occ][remain][yu] * dp1[loc[i].first][loc[occ].second];
									ans %= mod;
								}
								upd(dp2[rk][occ][k % 2][1], abs(orig[i]));
								upd(dp2[rk][i][k % 2][1], abs(orig[occ]));
							} else {
								upd(dp2[rk + 1][n][k % 2][0], abs(orig[i]) * abs(orig[occ]) % mod);
							}
						}
					} else {
						if (occ == n) {
							upd(dp2[rk][i][remain][0], 1);
						} else if (orig[occ] >= 0) {
							if (rk == k / 2 - 1) {
								ans += dp2[rk][occ][remain][yu] * dp1[loc[occ].first][loc[i].second];
								ans %= mod;
							}
							upd(dp2[rk][occ][remain][1], abs(orig[i]));
							upd(dp2[rk][i][remain][1], abs(orig[occ]));
						} else {
							upd(dp2[rk + 1][n][remain][0], abs(orig[i]) * abs(orig[occ]) % mod);
						}
 					}
				}

		

		ans += dp2[k / 2][n][k % 2][0] * pow2[i];
		ans %= mod;
		dp2[k / 2][n][k % 2][0] = 0;
		

		if (k % 2) {
			for (int occ = 1; occ <= loc[i].first - bool(orig[i] >= 0); occ++) {
				ans += pow2[occ - 1] * pow2[max(loc[i].second - (k != 1), 0ll)] % mod * orig[pos[occ]] % mod * dp2[k / 2][n][0][0];
				ans %= mod;
			}
		}
		dp2[k / 2][n][0][0] = 0;
	}

	dp_neg[0] = 1;
	for (int i = 1; i < lneg; i++) {
		for (int j = i - 1; j >= 0; j--) if (dp_neg[j]) {
			dp_neg[j + 1] += dp_neg[j] * (j >= k ? 1 : abs(orig[neg[i]]));
			dp_neg[j + 1] %= mod;
		}
	}
	dp_pos[0] = 1;
	for (int i = lpos - 1; i >= 1; i--) {
		for (int j = lpos - 1 - i; j >= 0; j--) if (dp_pos[j]) {
			dp_pos[j + 1] += dp_pos[j] * (j >= k ? 1 : orig[pos[i]]);
			dp_pos[j + 1] %= mod;
		}
	}
	for (int j = 1; j <= k; j += 2) {
		ans -= dp_neg[j] * dp_pos[k - j];
		ans %= mod;
	}
	if (k % 2) {
		for (int j = k + 1; j < lneg; j++) {
			ans -= dp_neg[j];
		}
	}
	ans %= mod;
	ans += mod;
	ans %= mod;

	cout << ans << endl;


	return 0;
}