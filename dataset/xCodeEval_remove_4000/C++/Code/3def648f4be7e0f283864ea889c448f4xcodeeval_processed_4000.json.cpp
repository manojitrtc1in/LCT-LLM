




































using namespace std;


const string nl = "\n";








































const double pi = acos(-1.0);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<unsigned long long int> vi64;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


template<typename T, typename U> inline void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if (x < y) x = y; }



template <typename T> inline void write(T x)
{
	int i = 20;
	char buf[21];
	

	buf[20] = '\n';

	do
	{
		buf[--i] = x % 10 + '0';
		x /= 10;
	} while (x);
	do
	{
		putchar(buf[i]);
	} while (buf[i++] != '\n');
}

template <typename T> inline T readInt()
{
	T n = 0, s = 1;
	char p = getchar();
	if (p == '-')
		s = -1;
	while ((p < '0' || p > '9') && p != EOF && p != '-')
		p = getchar();
	if (p == '-')
		s = -1, p = getchar();
	while (p >= '0' && p <= '9') {
		n = (n << 3) + (n << 1) + (p - '0');
		p = getchar();
	}

	return n * s;
}



mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int64_t random_long(long long l = id2, long long r = id1) {
	uniform_int_distribution<int64_t> generator(l, r);
	return generator(rng);
}
struct custom_hash { 

	static uint64_t splitmix64(uint64_t x) {
		

		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	size_t operator()(uint64_t x) const {
		static const uint64_t id0 =
		    chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + id0);
	}
	template<typename L, typename R>
	size_t operator()(pair<L, R> const& Y) const {
		static const uint64_t id0 =
		    chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(Y.first * 31 + Y.second + id0);
	}
};


const int mod = 1e9 + 7;
template<const int MOD>
struct id3 {
	int x;
	static vector<int> inverse_list ;
	const static int inverse_limit;
	const static bool is_prime;
	id3() {
		x = 0;
	}
	template<typename T>
	id3(const T z) {
		x = (z % MOD);
		if (x < 0) x += MOD;
	}
	id3(const id3<MOD>* z) {
		x = z->x;
	}
	id3(const id3<MOD>& z) {
		x = z.x;
	}
	id3 operator - (const id3<MOD>& m) const {
		id3<MOD> U;
		U.x = x - m.x;
		if (U.x < 0) U.x += MOD;
		return U;
	}
	id3 operator + (const id3<MOD>& m) const {
		id3<MOD> U;
		U.x = x + m.x;
		if (U.x >= MOD) U.x -= MOD;
		return U;
	}
	id3& operator -= (const id3<MOD>& m) {
		x -= m.x;
		if (x < 0) x += MOD;
		return *this;
	}
	id3& operator += (const id3<MOD>& m) {
		x += m.x;
		if (x >= MOD) x -= MOD;
		return *this;
	}
	id3 operator * (const id3<MOD>& m) const {
		id3<MOD> U;
		U.x = (x * 1ull * m.x) % MOD;
		return U;
	}
	id3& operator *= (const id3<MOD>& m) {
		x = (x * 1ull * m.x) % MOD;
		return *this;
	}
	template<typename T>
	friend id3 operator + (const T &l, const id3<MOD>& p) {
		return (id3<MOD>(l) + p);
	}
	template<typename T>
	friend id3 operator - (const T &l, const id3<MOD>& p) {
		return (id3<MOD>(l) - p);
	}
	template<typename T>
	friend id3 operator * (const T &l, const id3<MOD>& p) {
		return (id3<MOD>(l) * p);
	}
	template<typename T>
	friend id3 operator / (const T &l, const id3<MOD>& p) {
		return (id3<MOD>(l) / p);
	}

	int value() const {
		return x;
	}

	id3 operator ^ (const id3<MOD>& cpower) const {
		id3<MOD> ans;
		ans.x = 1;
		id3<MOD> curr(this);
		int power = cpower.x;

		if (curr.x <= 1) {
			if (power == 0) curr.x = 1;
			return curr;
		}
		while ( power > 0) {
			if (power & 1) {
				ans *= curr;
			}
			power >>= 1;
			if (power) curr *= curr;
		}
		return ans;
	}


	id3 operator ^ (long long power) const {
		id3<MOD> ans;
		ans.x = 1;
		id3<MOD> curr(this);
		if (curr.x <= 1) {
			if (power == 0) curr.x = 1;
			return curr;
		}
		

		if (power >= MOD && is_prime) {
			power %= (MOD - 1);
		}

		while ( power > 0) {
			if (power & 1) {
				ans *= curr;
			}
			power >>= 1;
			if (power) curr *= curr;

		}
		return ans;
	}

	id3 operator ^ (int power) const {
		id3<MOD> ans;
		ans.x = 1;
		id3<MOD> curr(this);

		if (curr.x <= 1) {
			if (power == 0) curr.x = 1;
			return curr;
		}
		while ( power > 0) {
			if (power & 1) {
				ans *= curr;
			}
			power >>= 1;
			if (power) curr *= curr;

		}
		return ans;
	}

	template<typename T>
	id3& operator ^= (T power) {
		id3<MOD> res = (*this)^power;
		x = res.x;
		return *this;
	}


	template<typename T>
	id3 pow(T x) {
		return (*this)^x;
	}


	pair<long long, long long> gcd(const int a, const int b) const {
		if (b == 0) return {1, 0};
		pair<long long, long long> c = gcd(b , a % b);
		return { c.second , c.first - (a / b)*c.second};
	}

	inline void init_inverse_list() const {

		vector<int>& dp = id3<MOD>::inverse_list;
		dp.resize(id3<MOD>::inverse_limit + 1);
		int n = id3<MOD>::inverse_limit;
		dp[0] = 1;
		if (n > 1) dp[1] = 1;
		for (int i = 2; i <= n; ++i) {
			dp[i] = (dp[MOD % i] * 1ull * (MOD - MOD / i)) % MOD;
		}

	}
	id3<MOD> get_inv() const {
		if (id3<MOD>::inverse_list.size()
		        < id3<MOD>::inverse_limit + 1) init_inverse_list();

		if (this->x <= id3<MOD>::inverse_limit) {
			return id3<MOD>::inverse_list[this->x];
		}
		pair<long long, long long> G = gcd(this->x, MOD);
		return id3<MOD>(G.first);
	}
	id3<MOD> operator - () const {
		id3<MOD> v(0);
		v -= (*this);
		return v;
	}
	id3 operator / (const id3<MOD>& m) const {
		id3<MOD> U(this);
		U *= m.get_inv();
		return U;
	}
	id3& operator /= (const id3<MOD>& m) {
		(*this) *= m.get_inv();
		return *this;
	}
	bool operator==(const id3<MOD>& m) const {
		return x == m.x;
	}

	bool operator < (const id3<MOD>& m) const {
		return x < m.x;
	}


	template<typename T>
	bool operator == (const T& m) const {
		return (*this) == (id3<MOD>(m));
	}

	template<typename T>
	bool operator < (const T& m) const {
		return x < (id3<MOD>(m)).x;
	}
	template<typename T>
	bool operator > (const T& m) const {
		return x > (id3<MOD>(m)).x;
	}
	template<typename T>
	friend bool operator == (const T& x, const id3<MOD>& m) {
		return (id3<MOD>(x)).x == m.x;
	}
	template<typename T>
	friend bool operator < (const T& x, const id3<MOD>& m) {
		return (id3<MOD>(x)).x < m.x;
	}
	template<typename T>
	friend bool operator > (const T& x, const id3<MOD>& m) {
		return (id3<MOD>(x)).x > m.x;
	}

	friend istream& operator >> (istream& is, id3<MOD>& p) {
		int64_t val;
		is >> val;
		p.x = (val % MOD);
		if (p.x < 0) p.x += MOD;
		return is;
	}
	friend ostream& operator << (ostream& os, const id3<MOD>& p)
	{return os << p.x;}



};



using mint = id3<mod>;
template<const int MOD>
vector<int> id3<MOD>::inverse_list ;
template<const int MOD>
const int id3<MOD>::inverse_limit = -1;
template<const int MOD>
const bool id3<MOD>::is_prime = true;
template<>   

const int id3<mod>::inverse_limit = 1000;











class Debugger
{
public:
	Debugger(const std::string& _separator = " - ") :
		first(true), separator(_separator) {}

	template<typename ObjectType> Debugger& operator , (const ObjectType& v)
	{
		if (!first)
std: cerr << separator;
		std::cerr << v;
		first = false;
		return *this;
	}
~Debugger() {  std: cerr << nl;}

private:
	bool first;
	std::string separator;
};



























clock_t time_req;



const int NMAX = 3e5;
int n, m;





void solve()
{
	inp(n);
	vector<uint64> a(n), b(n);

	inpv(a, n);
	inpv(b, n);

	vector<uint64> pref_sum(n);

	lp(i, n) {
		if (i == 0)
			pref_sum[i] = a[i] * b[i];
		else
			pref_sum[i] = a[i] * b[i] + pref_sum[i - 1];
	}

	uint64 max_sum = pref_sum[n - 1], rev_sum;
	int left, right;

	lp(i, n - 1) {

		left = i - 1;
		right = i;
		rev_sum = 0;

		while (left >= 0 and right < n) {
			rev_sum += a[left] * b[right] + a[right] * b[left];

			uint64 new_sum = pref_sum[n - 1] - (pref_sum[right] - pref_sum[left] + a[left] * b[left]) + rev_sum;

			if (new_sum > max_sum) {
				max_sum = new_sum;
			}

			left--;
			right++;
		}

		left = i;
		right = i + 1;
		rev_sum = 0;

		while (left >= 0 and right < n) {
			rev_sum += a[left] * b[right] + a[right] * b[left];
			uint64 new_sum = pref_sum[n - 1] - (pref_sum[right] - pref_sum[left] + a[left] * b[left]) + rev_sum;

			if (new_sum > max_sum) {
				max_sum = new_sum;
			}

			left--;
			right++;
		}

		left = i - 1;
		right = i + 1;
		rev_sum = a[i] * b[i];

		while (left >= 0 and right < n) {
			rev_sum += a[left] * b[right] + a[right] * b[left];
			uint64 new_sum = pref_sum[n - 1] - (pref_sum[right] - pref_sum[left] + a[left] * b[left]) + rev_sum;

			if (new_sum > max_sum) {
				max_sum = new_sum;
			}

			left--;
			right++;
		}
	}

	out(max_sum);

	return;
}


int main()
{

	freopen("../IO/input.txt", "r", stdin);
	freopen("../IO/output.txt", "w", stdout);
	freopen("../IO/log.txt", "w", stderr);


	std::ios::sync_with_stdio(false);
	cin.tie(0);


	clk_start();

	solve();

	clk_end();

	return 0;
}

