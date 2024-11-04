#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <climits>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <cstdio>
#include <bitset>
#include <numeric>
#include <unordered_map>
#include <regex>
#include <cassert>
#include <type_traits>
#include <array>
#include <cassert>
#include <typeinfo>
#include <iomanip>
#include <random>



using namespace std;




 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

#pragma region Macros



#define foa(v, a) for(auto &v : a)
#define REP(i, n) for(int i = 0 ; i < n; i ++)
#define REP2(i, l, r) for(int i = (l); i < (r); ++i)
#define rep(i, N, M) for(ll i=N, i##_len=(M); i<i##_len; ++i)
#define rep_skip(i, N, M, ...) for(ll i=N, i##_len=(M); i<i##_len; i+=(skip))




#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define popcnt(x) __builtin_popcountll(x)



template <class T = int>
using V = std::vector<T>;
template <class T = int>
using VV = std::vector<std::vector<T>>;
template <class T = int>
using VVV = std::vector<std::vector<std::vector<T>>>;
template <class T>
using pqup = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using ll = long long;
using ld = long double;
using int128 = long long int;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
template<typename T>
using pq_greater = priority_queue<T, vector<T>, greater<T>>;



template <class T, class U>
std::istream& operator>>(std::istream& is, std::pair<T, U>& p) {
	is >> p.first >> p.second;
	return is;
}
template <class T>
std::istream& operator>>(std::istream& is, std::vector<T>& v) {
	for (T& i : v) is >> i;
	return is;
}




template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
	os << p.first << " " << p.second;
	return os;
}
template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& a) {
	for (int i = 0; i < int(a.size()); ++i) {
		if (i) os << " ";
		os << a[i];
	}
	return os;
}




template <std::uint_fast64_t Modulus = 1000000007>
class modint
{
	using u64 = std::uint_fast64_t;

public:
	u64 a;

	constexpr modint(const u64 x = 0) noexcept : a(x% Modulus) {}
	

	

	

	

	

	

	

	constexpr u64 value() const noexcept { return a; }
	constexpr modint operator+(const modint rhs) const noexcept {
		return modint(*this) += rhs;
	}
	constexpr modint operator-(const modint rhs) const noexcept {
		return modint(*this) -= rhs;
	}
	constexpr modint operator*(const modint rhs) const noexcept {
		return modint(*this) *= rhs;
	}
	constexpr modint operator/(const modint rhs) const noexcept {
		return modint(*this) /= rhs;
	}
	modint& operator+=(const modint rhs) noexcept {
		a += rhs.a;
		if (a >= Modulus) {
			a -= Modulus;
		}
		return *this;
	}
	modint& operator-=(const modint rhs) noexcept {
		if (a < rhs.a) {
			a += Modulus;
		}
		a -= rhs.a;
		return *this;
	}
	modint& operator*=(const modint rhs) noexcept {
		a = a * rhs.a % Modulus;
		return *this;
	}
	modint& operator/=(modint rhs) noexcept {
		u64 exp = Modulus - 2;
		while (exp) {
			if (exp % 2) {
				*this *= rhs;
			}
			rhs *= rhs;
			exp /= 2;
		}
		return *this;
	}
	modint& operator++() noexcept {
		return *this += modint(1);
	}
	modint& operator++(int) noexcept {
		auto t = *this;
		*this += modint(1);
		return t;
	}
	modint& operator--() noexcept {
		return *this -= modint(1);
	}
	modint& operator--(int) noexcept {
		auto t = *this;
		*this -= modint(1);
		return t;
	}

};
template<uint_fast64_t Modulus>
ostream& operator <<(ostream& o, const modint<Modulus>& t) {
	o << t.value();
	return o;
}

template<uint_fast64_t Modulus>
istream& operator >>(istream& in, modint<Modulus>& t) {
	uint_fast64_t x;
	in >> x;
	t = modint<Modulus>(x);
	return in;
}
template<uint_fast64_t Modulus>
modint<Modulus> POW(modint<Modulus> x, ll n) {
	return modint<Modulus>(POW<Modulus>(x.value(), n));
}



template<typename T, T MOD = 1000000007>
class Mint {
public:
	T v;
	Mint() :v(0) {}
	Mint(signed v) :v(v) {}
	Mint(long long t) { v = t % MOD; if (v < 0) v += MOD; }

	Mint inv() { return pow(MOD - 2); }

	Mint& operator+=(Mint a) { v += a.v; if (v >= MOD)v -= MOD; return *this; }
	Mint& operator-=(Mint a) { v += MOD - a.v; if (v >= MOD)v -= MOD; return *this; }
	Mint& operator*=(Mint a) { v = 1LL * v * a.v % MOD; return *this; }
	Mint& operator/=(Mint a) { return (*this) *= a.inv(); }

	Mint operator+(Mint a) const { return Mint(v) += a; };
	Mint operator-(Mint a) const { return Mint(v) -= a; };
	Mint operator*(Mint a) const { return Mint(v) *= a; };
	Mint operator/(Mint a) const { return Mint(v) /= a; };

	Mint operator-() { return v ? MOD - v : v; }

	bool operator==(const Mint a)const { return v == a.v; }
	bool operator!=(const Mint a)const { return v != a.v; }
	bool operator <(const Mint a)const { return v < a.v; }

	static Mint pow(Mint v, long long k) {
		Mint res(1), tmp(v);
		while (k) {
			if (k & 1) res *= tmp;
			tmp *= tmp;
			k >>= 1;
		}
		return res;
	}

	

	static T log(Mint a, Mint b) {
		const T sq = 40000;
		unordered_map<T, T> dp;
		dp.reserve(sq);
		Mint res(1);
		for (ll r = 0; r < sq; r++) {
			if (!dp.count(res)) dp[res] = r;
			res *= a;
		}
		Mint p = pow(a.inv(), sq);
		res = b;
		for (ll q = 0; q <= MOD / sq + 1; q++) {
			if (dp.count(res)) {
				T idx = q * sq + dp[res];
				if (idx > 0) return idx;
			}
			res *= p;
		}
		return T(-1);
	}

	static vector<Mint> fact, finv, invs;

	static void init(ll n) {
		if (n + 1 <= (signed)fact.size()) return;
		fact.assign(n + 1, 1);
		finv.assign(n + 1, 1);
		invs.assign(n + 1, 1);

		for (ll i = 1; i <= n; i++) fact[i] = fact[i - 1] * Mint(i);
		finv[n] = Mint(1) / fact[n];
		for (ll i = n; i >= 1; i--) finv[i - 1] = finv[i] * Mint(i);
		for (ll i = 1; i <= n; i++) invs[i] = finv[i] * fact[i - 1];
	}

	static Mint comb(long long n, ll k) {
		Mint res(1);
		for (ll i = 0; i < k; i++) {
			res *= Mint(n - i);
			res /= Mint(i + 1);
		}
		return res;
	}

	static Mint C(ll n, ll k) {
		if (n < k || k < 0) return Mint(0);
		init(n);
		return fact[n] * finv[n - k] * finv[k];
	}

	static Mint P(ll n, ll k) {
		if (n < k || k < 0) return Mint(0);
		init(n);
		return fact[n] * finv[n - k];
	}

	static Mint H(ll n, ll k) {
		if (n < 0 || k < 0) return Mint(0);
		if (!n && !k) return Mint(1);
		init(n + k - 1);
		return C(n + k - 1, k);
	}

	static Mint S(ll n, ll k) {
		Mint res;
		init(k);
		for (ll i = 1; i <= k; i++) {
			Mint tmp = C(k, i) * Mint(i).pow(n);
			if ((k - i) & 1) res -= tmp;
			else res += tmp;
		}
		return res *= finv[k];
	}

	static vector<vector<Mint> > D(ll n, ll m) {
		vector<vector<Mint> > dp(n + 1, vector<Mint>(m + 1, 0));
		dp[0][0] = Mint(1);
		for (ll i = 0; i <= n; i++) {
			for (ll j = 1; j <= m; j++) {
				if (i - j >= 0) dp[i][j] = dp[i][j - 1] + dp[i - j][j];
				else dp[i][j] = dp[i][j - 1];
			}
		}
		return dp;
	}

	static Mint B(ll n, ll k) {
		Mint res;
		for (ll j = 1; j <= k; j++) res += S(n, j);
		return res;
	}

	static Mint montmort(ll n) {
		Mint res;
		init(n);
		for (ll k = 2; k <= n; k++) {
			if (k & 1) res -= finv[k];
			else res += finv[k];
		}
		return res *= fact[n];
	}

	static Mint LagrangePolynomial(vector<Mint>& y, Mint t) {
		ll n = y.size() - 1;
		if (t.v <= n) return y[t.v];
		init(n + 1);
		Mint num(1);
		for (ll i = 0; i <= n; i++) num *= t - Mint(i);
		Mint res;
		for (ll i = 0; i <= n; i++) {
			Mint tmp = y[i] * num / (t - Mint(i)) * finv[i] * finv[n - i];
			if ((n - i) & 1) res -= tmp;
			else res += tmp;
		}
		return res;
	}
};

template<typename T, T MOD = 1000000007>
ostream& operator <<(ostream& o, class Mint<T>& t) {
	o << t.v;
	return o;
}
template<typename T, T MOD = 1000000007>
istream& operator >>(istream& in, class Mint<T>& t) {
	in >> t.v;
	return in;
}



class Combination {
	

	

	


	ll MAX, MOD;
	vll fac;
	vll finv;
	vll inv;
public:
	Combination(ll MAX = 210000, ll MOD = 1000000007)
		:MOD(MOD), MAX(max(MAX, 2LL)), fac(vll(MAX + 1LL)), finv(vll(MAX + 1LL)), inv(vll(MAX + 1LL)) {
		fac[0] = fac[1] = 1;
		finv[0] = finv[1] = 1;
		inv[1] = 1;
		pre_process(2LL, MAX + 1);
	}

	ll get(ll n, ll k) {
		if (MAX < n)
			pre_process(MAX + 1, n + 1);

		if (n < k)return 0;
		if (n < 0 || k < 0)return 0;
		return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
	}
private:
	void pre_process(ll m, ll n) {
		if (MAX < n) {
			fac.resize(n); inv.resize(n); finv.resize(n);
		}
		rep(i, m, n) {
			fac[i] = fac[i - 1] * i % MOD;
			inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
			finv[i] = finv[i - 1] * inv[i] % MOD;
		}
	}
};



namespace scanner {
	void scan(int& a) { std::cin >> a; }
	void scan(long long& a) { std::scanf("%lld", &a); }
	void scan(std::string& a) { std::cin >> a; }
	void scan(char& a) { std::cin >> a; }
	void scan(char a[]) { std::scanf("%s", a); }
	void scan(double& a) { std::cin >> a; }
	void scan(long double& a) { std::cin >> a; }
	template <class T, class U>
	void scan(std::pair<T, U>& p) { std::cin >> p; }
	template <class T>
	void scan(std::vector<T>& a) { std::cin >> a; }
	void INPUT() {}
	template <class Head, class... Tail>
	void INPUT(Head& head, Tail &... tail) {
		scan(head);
		INPUT(tail...);
	}
}  

#define VEC(type, name, size)     \
	std::vector<type> name(size); \
	scanner::INPUT(name)
#define VVEC(type, name, h, w)                                    \
	std::vector<std::vector<type>> name(h, std::vector<type>(w)); \
	scanner::INPUT(name)
#define INT(...)     \
	int __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define LL(...)            \
	long long __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define STR(...)             \
	std::string __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define CHAR(...)     \
	char __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define DOUBLE(...)     \
	double __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define LD(...)              \
	long double __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)



namespace debugger {
	template <class T>
	void view(const std::vector<Mint<T>>& a) {
		std::cerr << "{ ";
		for (const auto& v : a) {
			std::cerr << v.v << ", ";
		}
		std::cerr << "\b\b }";
	}
	template <class T>
	void view(const std::vector<T>& a) {
		std::cerr << "{ ";
		for (const auto& v : a) {
			std::cerr << v << ", ";
		}
		std::cerr << "\b\b }";
	}
	template <class T>
	void view(const std::vector<std::vector<T>>& a) {
		std::cerr << "{\n";
		for (const auto& v : a) {
			std::cerr << "\t";
			view(v);
			std::cerr << "\n";
		}
		std::cerr << "}";
	}
	template <class T>
	void view(const std::vector<std::vector<Mint<T>>>& a) {
		std::cerr << "{\n";
		for (const auto& v : a) {
			std::cerr << "\t";
			view(v);
			std::cerr << "\n";
		}
		std::cerr << "}";
	}
	template <class T, class U>
	void view(const std::vector<std::pair<T, U>>& a) {
		std::cerr << "{\n";
		for (const auto& p : a) std::cerr << "\t(" << p.first << ", " << p.second << ")\n";
		std::cerr << "}";
	}
	template <class T, class U>
	void view(const std::map<T, U>& m) {
		std::cerr << "{\n";
		for (const auto& p : m) std::cerr << "\t[" << p.first << "] : " << p.second << "\n";
		std::cerr << "}";
	}
	template <class T, class U>
	void view(const std::pair<T, U>& p) { std::cerr << "(" << p.first << ", " << p.second << ")"; }
	template <class T>
	void view(const std::set<T>& a) {
		std::cerr << "{ ";
		for (const auto& v : a) {
			std::cerr << v << ", ";
		}
		std::cerr << "\b\b }";
	}
	template <class T>
	void view(const std::set<std::set<T>>& a) {
		std::cerr << "{\n";
		for (const auto& v : a) {
			std::cerr << "\t";
			view(v);
			std::cerr << "\n";
		}
		std::cerr << "}";
	}
	template <class T>
	void view(const T& e) { std::cerr << e; }
}  



void solve(vector<ll>& arr, int i, vector<ll>& arr2) {
	if (i < 0)
		return;

	int step = arr[i];

	if (step == 0) {
		solve(arr, i - 1, arr2);
	}
	else {

	}

}


bool solve() {

	LL(K);

	VEC(ll, t, K);

	for (int i = 0; i < t.size() - 1; ++i) {
		for (int j = i + 1; j < t.size(); ++j) {
			


			for (int w = 0; w < t.size() - 1; ++w) {
				for (int y = 0; y < t.size(); ++y) {
					if (w != i and w != j and y != i and y != j) {
						

						

						if ((t[i] + t[j]) == (t[w] + t[y])) {
							cout << "YES" << endl;
							

							cout << i + 1 << " " << j + 1 << " " << w + 1 << " " << y + 1 << endl;
							return true;
						}
					}
				}
			}
		}
	}

	return false;
}
struct str {
	int x;
	int y;
};

int main()
{
#if 0
	map<ll, list<pair<ll, ll>>> m;
#endif
	

	pll vis[5000001];
	ll k;
	LL(N);
	VEC(ll, arr, N);
	for (ll i = 1; i <= 5000000; i++)
		vis[i] = { -1, -1 };
	for (ll i = 0; i < N - 1; ++i) {
		for (ll j = i + 1; j < N; ++j) {
#if 0
			for (auto const& p : m[arr[i] + arr[j]]) {
				if (p.first != i and p.first != j and p.second != i and p.second != j) {
					cout << "YES" << endl;
					cout << p.first + 1 << " " << p.second + 1 << " " << i + 1 << " " << j + 1 << endl;
					return 0;
				}
			}
			m[arr[i] + arr[j]].push_back(make_pair(i, j));
#endif
#if 0
			for (auto it : vis[arr[j] + arr[i]])
				if (it.x != j && it.y != i && it.y != j && it.x != i)
				{
					puts("YES");
					printf("%d %d %d %d", it.x + 1, it.y + 1, j + 1, i + 1);
					return 0;
				}
			vis[arr[j] + arr[i]].push_back({ j,i });
#endif
			k = arr[i] + arr[j];
			if (vis[k].first != -1)
			{
				pll p = vis[k];
				if (p.first != i && p.first != j && p.se != i && p.se != j)
				{
					cout << "YES" << endl;
					cout << p.first + 1 << " " << p.se + 1 << " " << i + 1 << " " << j + 1 << endl;
					return 0;
				}
			}
			else
				vis[k] = { i, j };
		}
	}
	cout << "NO" << endl;
}
