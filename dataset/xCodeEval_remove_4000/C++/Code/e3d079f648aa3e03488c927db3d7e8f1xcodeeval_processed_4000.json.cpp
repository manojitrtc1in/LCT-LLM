


















using namespace std;
typedef long long       LL;
typedef pair<int, int>  PII;
typedef pair<LL, LL>    PLL;
typedef vector<int>     VI;
typedef vector<LL>      VL;
typedef vector<PII>     VPII;
typedef vector<VI>      VVI;
typedef vector<VPII>    VVPII;












struct _ {_() {ios_base::sync_with_stdio(0);}} _;
template<class A, class B> ostream& operator<<(ostream &o, pair<A, B> t) {o << "(" << t.x << ", " << t.y << ")"; return o;}
template<class T> string tostring(T x, int len = 0, char c = '0') {stringstream ss; ss << x; string r = ss.str(); if(r.length() < len) r = string(len - r.length(), c) + r; return r;}
template<class T> void PV(T a, T b, int n = 0, int w = 0, string s = " ") {int c = 0; while(a != b) {cout << tostring(*a++, w, ' '); if(a != b && (n == 0 || ++c % n)) cout << s; else cout << "\n"; cout.flush();}}
template<class T> inline bool chmin(T &a, T b) {return a > b ? a = b, 1 : 0;}
template<class T> inline bool chmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
const LL linf = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int mod = int(1e9) + 7;
const int N = 5005;

struct SuffixArray {
	string s;
	int r[N], n;
	int WA[N], WB[N], WV[N], WS[N];
	int sa[N], rk[N], height[N], l2[N];
	int minv[25][N];

	

	SuffixArray(string s = "") {if(s.size() > 0) init(s);}

	void init(string s) {
		this->s = s;
		n = s.length();
		for(int i = 0; i < n; i++) r[i] = (int)(s[i]);
		r[n] = 0;
		doit(r, n + 1);
	}

	void doit(int *r, int n, int m = 256) {
		int i, j, p, *x = WA, *y = WB, *t;
		for(i = 0; i < m; i++)  WS[i] = 0;
		for(i = 0; i < n; i++)  WS[x[i] = r[i]]++;
		for(i = 1; i < m; i++)  WS[i] += WS[i - 1];
		for(i = n - 1; i >= 0; i--)  sa[--WS[x[i]]] = i;

		for(j = 1, p = 1; p < n; j *= 2, m = p) {
			for(p = 0, i = n - j; i < n; i++)  y[p++] = i;
			for(i = 0; i < n; i++)  if(sa[i] >= j) y[p++] = sa[i] - j;
			for(i = 0; i < n; i++)  WV[i] = x[y[i]];
			for(i = 0; i < m; i++)  WS[i] = 0;
			for(i = 0; i < n; i++)  WS[WV[i]]++;
			for(i = 1; i < m; i++)  WS[i] += WS[i - 1];
			for(i = n - 1; i >= 0; i--)  sa[--WS[WV[i]]] = y[i];
			t = x, x = y, y = t, p = 1, x[sa[0]] = 0;
			for(i = 1; i < n; i++)
				x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
		}
		calcHeight(n - 1);
		initRMQ(n - 1);
	}

	int cmp(int *r, int a, int b, int l) {
		return r[a] == r[b] && r[a + l] == r[b + l];
	}

	void calcHeight(int n) {
		int i, j, k = 0;
		for(i = 1; i <= n; i++)  rk[sa[i]] = i;
		for(i = 0; i < n; i++) {
			for(k ? k-- : 0, j = sa[rk[i] - 1]; r[i + k] == r[j + k]; k++);
			height[rk[i]] = k;
		}
	}

	void initRMQ(int n) {
		l2[1] = 0;
		for(int i = 2; i <= n; i++) l2[i] = l2[i - 1] + ((i & (i - 1)) == 0);
		for(int i = 1; i <= n; i++) minv[0][i] = height[i];
		for(int i = 1; (1 << i) <= n; i++) {
			for(int j = 1; j + (1 << i) - 1 <= n; j++) {
				minv[i][j] = min(minv[i - 1][j], minv[i - 1][j + (1 << (i - 1))]);
			}
		}
	}

	int lcp(int a, int b) {
		

		

		if(a == b) return n - a;
		a = rk[a];
		b = rk[b];
		if(a > b) swap(a, b);
		int t = l2[b - a];
		return min(minv[t][a + 1], minv[t][b - (1 << t) + 1]);
	}

	int maxCommonPrefix(int a) {
		

		int res = 0;
		if(rk[a] > 1) chmax(res, height[rk[a]]);
		if(rk[a] < n) chmax(res, height[rk[a] + 1]);
		return res;
	}

	void output() {
		for(int i = 1; i <= n; i++) {
			cout << i << " " << suffix(sa[i]) << endl;
		}
	}

	string suffix(int k)    {return s.substr(k);}
} SA;

struct BigInteger {
	static const int B = 1e9; 

	static const int dB = 9;  


	vector<int> a;
	int sign;

	BigInteger() : sign(1) {}
	BigInteger(LL v) {*this = v;}
	BigInteger(const string &s) {read(s);}

	void operator = (LL v) {
		if(v < 0) sign = -1, v = -v;
		else sign = 1;
		a.clear();
		if(v == 0) a.push_back(0);
		for(; v > 0; v = v / B) a.push_back(v % B);
	}

	BigInteger operator + (const BigInteger &v) const {
		if(sign != v.sign) return *this - (-v);
		BigInteger res = v;
		res.a.resize(max(a.size(), v.a.size()) + 1, 0);
		for(int i = 0, carry = 0; i < res.a.size(); i++) {
			res.a[i] += carry + (i < a.size() ? a[i] : 0);
			carry = res.a[i] >= B;
			res.a[i] -= carry * B;
		}
		res.trim();
		return res;
	}

	BigInteger operator - (const BigInteger &v) const {
		if(sign != v.sign) return *this + (-v);
		if(abs() < v.abs()) return -(v - *this);
		BigInteger res = *this;
		for(int i = 0, carry = 0; i < v.a.size() || carry; ++i) {
			res.a[i] -= carry + (i < v.a.size() ? v.a[i] : 0);
			carry = res.a[i] < 0;
			res.a[i] += carry * B;
		}
		res.trim();
		return res;
	}

	void operator *= (int v) {
		if(v < 0) sign = -sign, v = -v;
		a.resize(a.size() + 2, 0);
		for(int i = 0, carry = 0; i < a.size(); i++) {
			LL cur = a[i] * (LL) v + carry;
			carry = cur / B;
			a[i] = cur % B;

		}
		trim();
	}

	BigInteger operator * (int v) const {
		BigInteger res = *this;
		res *= v;
		return res;
	}

	friend pair<BigInteger, BigInteger> divmod(const BigInteger &a1, const BigInteger &b1) {
		int norm = B / (b1.a.back() + 1);
		BigInteger a = a1.abs() * norm;
		BigInteger b = b1.abs() * norm;
		BigInteger q, r;
		q.a.resize(a.a.size());

		for(int i = a.a.size() - 1; i >= 0; i--) {
			r *= B;
			r += a.a[i];
			int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
			int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
			int d = ((long long) B * s1 + s2) / b.a.back();
			r -= b * d;
			while(r < 0)
				r += b, --d;
			q.a[i] = d;
		}

		q.sign = a1.sign * b1.sign;
		r.sign = a1.sign;
		q.trim();
		r.trim();
		return make_pair(q, r / norm);
	}

	BigInteger operator / (const BigInteger &v) const {
		return divmod(*this, v).x;
	}

	BigInteger operator % (const BigInteger &v) const {
		return divmod(*this, v).y;
	}

	void operator /= (int v) {
		if(v < 0) sign = -sign, v = -v;
		for(int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
			LL cur = a[i] + rem * (LL) B;
			a[i] = cur / v;
			rem = cur % v;
		}
		trim();
	}

	BigInteger operator / (int v) const {
		BigInteger res = *this;
		res /= v;
		return res;
	}

	int operator % (int v) const {
		if(v < 0) v = -v;
		int m = 0;
		for(int i = a.size() - 1; i >= 0; --i)
			m = (a[i] + m * (long long) B) % v;
		return m * sign;
	}

	void operator += (const BigInteger &v) {*this = *this + v;}
	void operator -= (const BigInteger &v) {*this = *this - v;}
	void operator *= (const BigInteger &v) {*this = *this * v;}
	void operator /= (const BigInteger &v) {*this = *this / v;}

	bool operator < (const BigInteger &v) const {
		if(sign != v.sign) return sign < v.sign;
		if(a.size() != v.a.size()) return a.size() * sign < v.a.size() * v.sign;
		for(int i = (int) a.size() - 1; i >= 0; i--)
			if(a[i] != v.a[i]) return a[i] * sign < v.a[i] * sign;
		return false;
	}

	bool operator > (const BigInteger &v) const {return v < *this;}
	bool operator <= (const BigInteger &v) const {return !(v < *this);}
	bool operator >= (const BigInteger &v) const {return !(*this < v);}
	bool operator == (const BigInteger &v) const {return !(*this < v) && !(v < *this);}
	bool operator != (const BigInteger &v) const {return *this < v || v < *this;}

	void trim() {
		while(!a.empty() && a.back() == 0) a.pop_back();
		if(a.empty()) {sign = 1; a.pb(0);}
	}

	bool isZero() const {return a.empty() || (a.size() == 1 && !a[0]);}

	BigInteger operator - () const {BigInteger res = *this; res.sign = -sign; return res;}

	BigInteger abs() const {if(sign > 0) return *this; else return -*this;}

	LL longValue() const {
		LL res = 0;
		for(int i = (int) a.size() - 1; i >= 0; i--) res = res * B + a[i];
		return res * sign;
	}

	friend BigInteger gcd(const BigInteger &a, const BigInteger &b) {return b.isZero() ? a : gcd(b, a % b);}
	friend BigInteger lcm(const BigInteger &a, const BigInteger &b) {return a / gcd(a, b) * b;}

	void read(const string &s) {
		assert(s.length() > 0);
		sign = 1, a.clear();
		int start = 0;
		if(s[0] == '-' || s[0] == '+') { if(s[0] == '-') sign = -1; start = 1;}
		for(int i = s.length() - 1; i >= start; i -= dB) {
			int x = 0;
			for(int j = max(i - dB + 1, start); j <= i; j++) x = x * 10 + s[j] - '0';
			a.pb(x);
		}
		trim();
	}

	string tostring() const {
		stringstream stream;
		if(this->sign == -1) stream << '-';
		stream << (a.empty() ? 0 : a.back());
		for(int i = (int) a.size() - 2; i >= 0; --i)
			stream << setw(dB) << setfill('0') << a[i];
		string res;
		stream >> res;
		return res;
	}

	friend istream& operator >> (istream &stream, BigInteger &v) {string s; stream >> s; v.read(s); return stream;}
	friend ostream& operator << (ostream &stream, const BigInteger &v) {stream << v.tostring(); return stream;}

	BigInteger operator * (const BigInteger &v) const {
		BigInteger res;
		res.sign = sign * v.sign;
		res.a.resize(a.size() + v.a.size());
		for(int i = 0; i < a.size(); ++i) {
			if(a[i] == 0) continue;
			for(int j = 0, carry = 0; j < v.a.size() || carry; ++j) {
				LL cur = res.a[i + j] + (LL) a[i] * (j < v.a.size() ? v.a[j] : 0) + carry;
				carry  = cur / B;
				res.a[i + j] = cur % B;
			}
		}
		res.trim();
		return res;
	}
};

int dp[N][N];
int sum[N][N];
int step[N][N];
int minv[N][N];

string s;
int d[N];
int n;

void add(int &a, int b = 0) {
	a += b;
	if(a >= mod) a -= mod;
}

int main() {
	cin >> s;
	n = s.length();

	for(int i = 0; i < n; i++) d[i] = s[i] - '0';

	SA.init(s);

	MM(minv, 0x3f);
	MM(step, 0x3f);

	for(int i = 1; i <= n; i++) {
		dp[i][i] = 1;
		step[i][i] = 1;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < i; j++) {
			if(s[i - j] == '0') continue;
			int mx = min(j - 1, i - j);
			dp[i][j] = sum[i - j][mx];
			step[i][j] = minv[i - j][mx];
			int L1 = i - 1 - j - j + 1;
			int R1 = i - 1 - j;
			int L2 = R1 + 1;
			int R2 = i - 1;
			if(L1 < 0) continue;
			int equal = SA.lcp(L1, L2) >= j;
			if(SA.rk[L1] <= SA.rk[L2] || SA.lcp(L1, L2) >= j) {
				add(dp[i][j], dp[i - j][j]);
				chmin(step[i][j], step[i - j][j] + 1);
			}
		}
		for(int j = 1; j <= i; j++) {
			add(sum[i][j], sum[i][j - 1] + dp[i][j]);
			minv[i][j] = min(minv[i][j - 1], step[i][j] + 1);
		}
	}

	int cnt = 0;
	for(int i = 1; i <= n; i++) add(cnt, dp[n][i]);

	BigInteger res = string(10000, '9'), cur = 0, p2 = 1;
	for(int i = 1; i <= n; i++) {
		cur += p2 * d[n - i];
		if(step[n][i] != inf) chmin(res, cur + step[n][i]);
		p2 *= 2;
	}
	res = res % mod;
	cout << cnt << endl;
	cout << res << endl;
	return 0;
}


