









using namespace atcoder;















































using namespace std;





















template <typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template <typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
std::random_device rd;
std::mt19937 mt(rd());
constexpr ll MOD = 1e9 + 7;
constexpr int MAX = 500050;
const double pi = acos(-1);
constexpr double EPS = 1e-8;
constexpr ll LINF = 1e17 + 1;




const int mod = 1000000007;


struct mint {
	ll x; 

	mint(ll x = 0) :x((x%mod + mod) % mod) {}
	mint operator-() const { return mint(-x); }
	mint& operator+=(const mint a) {
		if ((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += mod - a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
	mint operator+(const mint a) const { return mint(*this) += a; }
	mint operator-(const mint a) const { return mint(*this) -= a; }
	mint operator*(const mint a) const { return mint(*this) *= a; }
	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1) a *= *this;
		return a;
	}

	

	mint inv() const { return pow(mod - 2); }
	mint& operator/=(const mint a) { return *this *= a.inv(); }
	mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }




class FastIO {
	static const int rdata_sz = (1 << 25), wdata_sz = (1 << 25);
	char rdata[rdata_sz], wdata[wdata_sz], *rb, *wb;
	char tmp_s[20];

public:
	FastIO() {
		fread(rdata, 1, rdata_sz, stdin);
		rb = rdata; wb = wdata;
	}
	~FastIO() {
		fwrite(wdata, 1, wb - wdata, stdout);
	}

	template<typename T>
	inline void read_i(T &x) {
		bool neg = false;
		x = 0;
		while ((*rb < '0' || *rb > '9') && *rb != '-') ++rb;
		if (*rb == '-') {
			neg = true;
			++rb;
		}
		while ('0' <= *rb && *rb <= '9') {
			x = 10 * x + (*rb - '0');
			++rb;
		}
		if (neg) x = -x;
	}


	template<typename T>
	inline void id0(T x) {
		if (x == 0) { pc('0'); pc('\n'); return; }
		if (x < 0) { pc('-'); x = -x; }
		char *t = tmp_s;
		while (x) {
			T y = x / 10;
			*(t++) = (x - y * 10) + '0';
			x = y;
		}
		while (t != tmp_s) pc(*(--t));
		pc('\n');
	}

};
FastIO io;

struct IO {
	static constexpr size_t buf_size = 1 << 18;
	char buf_in[buf_size], buf_out[buf_size];
	size_t pt_in = 0, pt_out = 0, tail_in = 0;
	char strs[10000 * 4];
	inline size_t num_digits(long long x) {
		if (x >= (long long)1e9) {
			if (x >= (long long)1e18) return 19;
			if (x >= (long long)1e17) return 18;
			if (x >= (long long)1e16) return 17;
			if (x >= (long long)1e15) return 16;
			if (x >= (long long)1e14) return 15;
			if (x >= (long long)1e13) return 14;
			if (x >= (long long)1e12) return 13;
			if (x >= (long long)1e11) return 12;
			if (x >= (long long)1e10) return 11;
			return 10;
		}
		else {
			if (x >= (long long)1e8) return 9;
			if (x >= (long long)1e7) return 8;
			if (x >= (long long)1e6) return 7;
			if (x >= (long long)1e5) return 6;
			if (x >= (long long)1e4) return 5;
			if (x >= (long long)1e3) return 4;
			if (x >= (long long)1e2) return 3;
			if (x >= (long long)1e1) return 2;
			return 1;
		}
	}
	IO() {
		load();
		for (int i = 0; i < 10000; ++i) {
			int j = i;
			for (int t = 3; t >= 0; --t) {
				strs[i * 4 + t] = j % 10 + '0';
				j /= 10;
			}
		}
	}
	~IO() { flush(); }
	inline void load() {
		memcpy(buf_in, buf_in + pt_in, tail_in - pt_in);
		size_t width = tail_in - pt_in;
		tail_in = width + fread(buf_in + width, 1, buf_size - width, stdin);
		pt_in = 0;
	}
	inline void flush() {
		fwrite(buf_out, 1, pt_out, stdout);
		pt_out = 0;
	}
	inline void read(char& c) { c = buf_in[pt_in++]; }
	template <class T>
	inline void read(T& x) {
		if (pt_in + 32 > tail_in) load();
		char c;
		do {
			read(c);
		} while (c < '0');
		bool minus = 0;
		if (c == '-') {
			minus = 1;
			read(c);
		}
		x = 0;
		while (c >= '0') {
			x = x * 10 + (c & 15);
			read(c);
		}
		if (minus) x = -x;
	}
	inline void write(char c) { buf_out[pt_out++] = c; }
	template <class T>
	inline void write(T x) {
		if (pt_out > buf_size - 32) flush();
		if (x < 0) {
			write('-');
			x = -x;
		}
		size_t digits = num_digits(x);
		int i;
		for (i = pt_out + digits - 4; i >(int)pt_out; i -= 4) {
			memcpy(buf_out + i, strs + (x % 10000) * 4, 4);
			x /= 10000;
		}
		memcpy(buf_out + pt_out, strs + x * 4 + (pt_out - i), 4 + i - pt_out);
		pt_out += digits;
	}
	inline void write(const char* s) {
		if (pt_out > buf_size - 32) flush();
		for (int i = 0; s[i] != 0; ++i) write(s[i]);
	}
	template <class T>
	inline void writeln(T x) {
		write(x);
		write('\n');
	}
} io2;
ll dp[65][2][2][2];

vector<int>to0[2][2][2],to1[2][2][2];























































































void solve() {
	ll t;
	io.read_i(t);
	

	

	

	REP(i, 61)REP(j, 2)REP(k, 2)REP(l, 2)dp[i][j][k][l] = 0;
	dp[0][0][0][0] = 1;
	REP(i, 60) {
		bool f2 = t >> i & 1;
		if (f2) {
			dp[i + 1][0][0][0] += dp[i][0][0][0];
			dp[i + 1][1][0][0] += dp[i][0][0][0];
			dp[i + 1][0][1][0] += dp[i][0][0][0];
			dp[i + 1][1][1][0] += dp[i][0][0][0];
			dp[i + 1][0][1][0] += dp[i][0][0][1];
			dp[i + 1][1][1][0] += dp[i][0][0][1];
			dp[i + 1][0][0][1] += dp[i][0][0][1];
			dp[i + 1][1][0][1] += dp[i][0][0][1];
			dp[i + 1][1][0][0] += dp[i][0][1][0];
			dp[i + 1][0][1][0] += dp[i][0][1][0];
			dp[i + 1][1][1][0] += dp[i][0][1][0];
			dp[i + 1][0][0][1] += dp[i][0][1][0];
			dp[i + 1][1][1][0] += dp[i][0][1][1];
			dp[i + 1][0][0][1] += dp[i][0][1][1];
			dp[i + 1][1][0][1] += dp[i][0][1][1];
			dp[i + 1][0][1][1] += dp[i][0][1][1];
			dp[i + 1][0][0][0] += dp[i][1][0][0];
			dp[i + 1][1][0][0] += dp[i][1][0][0];
			dp[i + 1][0][1][0] += dp[i][1][0][0];
			dp[i + 1][1][1][0] += dp[i][1][0][0];
			dp[i + 1][0][1][0] += dp[i][1][0][1];
			dp[i + 1][1][1][0] += dp[i][1][0][1];
			dp[i + 1][0][0][1] += dp[i][1][0][1];
			dp[i + 1][1][0][1] += dp[i][1][0][1];
			dp[i + 1][1][0][0] += dp[i][1][1][0];
			dp[i + 1][0][1][0] += dp[i][1][1][0];
			dp[i + 1][1][1][0] += dp[i][1][1][0];
			dp[i + 1][0][0][1] += dp[i][1][1][0];
			dp[i + 1][1][1][0] += dp[i][1][1][1];
			dp[i + 1][0][0][1] += dp[i][1][1][1];
			dp[i + 1][1][0][1] += dp[i][1][1][1];
			dp[i + 1][0][1][1] += dp[i][1][1][1];
		}
		else {
			dp[i + 1][0][0][0] += dp[i][0][0][0];
			dp[i + 1][1][0][0] += dp[i][0][0][0];
			dp[i + 1][0][1][0] += dp[i][0][0][0];
			dp[i + 1][1][1][0] += dp[i][0][0][0];
			dp[i + 1][0][1][0] += dp[i][0][0][1];
			dp[i + 1][1][1][0] += dp[i][0][0][1];
			dp[i + 1][0][0][1] += dp[i][0][0][1];
			dp[i + 1][1][0][1] += dp[i][0][0][1];
			dp[i + 1][1][0][0] += dp[i][0][1][0];
			dp[i + 1][0][1][0] += dp[i][0][1][0];
			dp[i + 1][1][1][0] += dp[i][0][1][0];
			dp[i + 1][0][0][1] += dp[i][0][1][0];
			dp[i + 1][1][1][0] += dp[i][0][1][1];
			dp[i + 1][0][0][1] += dp[i][0][1][1];
			dp[i + 1][1][0][1] += dp[i][0][1][1];
			dp[i + 1][0][1][1] += dp[i][0][1][1];
			dp[i + 1][1][0][0] += dp[i][1][0][0];
			dp[i + 1][0][1][0] += dp[i][1][0][0];
			dp[i + 1][1][1][0] += dp[i][1][0][0];
			dp[i + 1][0][0][1] += dp[i][1][0][0];
			dp[i + 1][1][1][0] += dp[i][1][0][1];
			dp[i + 1][0][0][1] += dp[i][1][0][1];
			dp[i + 1][1][0][1] += dp[i][1][0][1];
			dp[i + 1][0][1][1] += dp[i][1][0][1];
			dp[i + 1][0][1][0] += dp[i][1][1][0];
			dp[i + 1][1][1][0] += dp[i][1][1][0];
			dp[i + 1][0][0][1] += dp[i][1][1][0];
			dp[i + 1][1][0][1] += dp[i][1][1][0];
			dp[i + 1][0][0][1] += dp[i][1][1][1];
			dp[i + 1][1][0][1] += dp[i][1][1][1];
			dp[i + 1][0][1][1] += dp[i][1][1][1];
			dp[i + 1][1][1][1] += dp[i][1][1][1];
			

			

			

			

			

		}
		REP(j, 2)REP(k, 2)REP(l, 2)dp[i + 1][j][k][l] %= MOD;
			

			


			


			

			

			

			

			

			

	}
	

	io2.writeln(dp[60][0][0][0]);
	

}





signed main() {
	

	int q;
	io.read_i(q);
	while (q--)
	solve();

}
