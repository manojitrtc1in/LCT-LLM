










#include <bits/stdc++.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define dbg(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define fi first
#define se second
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define readRepeatInt int _t; cin >> _t; while (_t--)
#define repeat(i, x) for (int i = 0; i < (x); ++i)
#define repeatRev(i, x) for (int i = (x) - 1; i >= 0; --i)

using ll =  long long;                  using vb = vector<bool>;


using ull = unsigned long long;         using vull = vector<ull>;
using vll = vector<ll>;					using vvll = vector<vll>;
using vi = vector<int>;                 using vvi = vector<vi>;

using pi = pair<int, int>;              using vpi = vector<pi>;
using pll = pair<ll, ll>;               using vpll = vector<pll>;

using si = set<int>;                    using sll = set<ll>;
using usi = unordered_set<int>;         using usll = unordered_set<ll>;
using di = deque<int>;                  using dll = deque<ll>;
using mi = map<int, int>;               using mll = map<ll, ll>;
using umi = unordered_map<int, int>;    using umll = unordered_map<ll, ll>;
using vsi = vector<si>;					using vsll = vector<sll>;

template<typename A, typename B> inline A& maxi(A& a, B b) {return a = max(a, A(b)); }
template<typename A, typename B> inline A& mini(A& a, B b) {return a = min(a, A(b)); }

template <typename T> struct reversion_wrapper {T& iterable; };
template <typename T> reversion_wrapper<T> reverse(T&& iterable) {return {iterable}; }
template <typename T> auto begin(reversion_wrapper<T> w) {return rbegin(w.iterable); }
template <typename T> auto end(reversion_wrapper<T> w) {return rend(w.iterable); }

template<typename Iter> inline ostream& streamByIterators(ostream &os, Iter beg, Iter end) {os << '{'; if (beg != end) {os << *beg; while (++beg != end) os << ", " << *beg; }; return os << '}'; }
template<typename T> inline ostream& operator<<(ostream &os, const vector<T> &v) {return streamByIterators(os, v.begin(), v.end()); }
template<typename T> inline ostream& operator<<(ostream &os, const deque<T> &d) {return streamByIterators(os, d.begin(), d.end()); }
template<typename T> inline ostream& operator<<(ostream &os, const set<T> &s) {return streamByIterators(os, s.begin(), s.end()); }
template<typename T, typename V> inline ostream& operator<<(ostream &os, const map<T, V> &m) {return streamByIterators(os, m.begin(), m.end()); }
template<typename T> inline ostream& operator<<(ostream &os, const unordered_set<T> &s) {return streamByIterators(os, s.begin(), s.end()); }
template<typename T, typename V> inline ostream& operator<<(ostream &os, const unordered_map<T, V> &m) {return streamByIterators(os, m.begin(), m.end()); }
template<typename T, size_t size> inline ostream& operator<<(ostream &os, const array<T, size> &a) {return streamByIterators(os, a.begin(), a.end()); }
template<typename A, typename B> inline ostream& operator<<(ostream &os, const pair<A, B> &p) {return os << '(' << p.first << ", " << p.second << ')'; }
 
template<typename T> inline istream& operator>>(istream &is, vector<T> &v) {for (T& t : v) is >> t; return is; }
template<typename T> inline istream& operator>>(istream &is, deque<T> &d) {for (T& t : d) is >> t; return is;}
template<typename T, size_t size> inline istream& operator>>(istream &is, array<T, size> &a) {for (T& t : a) is >> t; return is; }
template<typename A, typename B> inline istream& operator>>(istream &is, pair<A, B> &p) {return is >> p.first >> p.second; }

template<typename T, typename V> T constexpr myPow(T base, V exp) {T ans(1); while (exp > 0) {if (exp & 1) ans *= base; base *= base; exp >>= 1; } return ans; }
template<typename T, typename V> T constexpr myPowMod(T base, T mod, V exp) {T ans(1); while (exp > 0) {if (exp & 1) ans = (ans * base) % mod; base = (base * base) % mod; exp >>= 1; } return ans; }
template<typename T> inline constexpr T myMod(T val, T mod) {val %= mod; if (val < 0) val += mod; return val; }



template<typename T> pair<T, T> extEuclidean(T a, T b)
{
    pair<T, T> s = {1, 0};
    pair<T, T> r = {a, b};

    while (r.second)
    {
        T q = r.first / r.second;
        r = {r.second, r.first - q * r.second};
        s = {s.second, s.first - q * s.second};
    }

    return {s.first, b ? (r.first - s.first * a) / b : 0};
}

template<typename T, T modulo> class modBase
{
public:
    T val;

    modBase() : val(0) {}
    modBase(T v)
    {
        if (0 <= v && v < modulo)
            val = v;
        else
            val = myMod(v, modulo);
    }

	using baseType = T;

    static T modValue() {return modulo; }
    T value() const {return val; }

    modBase inverse() const { return extEuclidean(modulo, val).second; }

    modBase operator-() const {modBase ret; if (val) ret.val = modulo - val; return ret; }
    modBase operator+() const {return *this; }

    modBase& operator+=(modBase const& x) {val += x.val; if (val >= modulo) val -= modulo; return *this; }
    modBase& operator-=(modBase const& x) {val -= x.val; if (val < 0) val += modulo; return *this; }
    modBase& operator*=(modBase const& x) {val = myMod(val * x.val, modulo); return *this; }
    modBase& operator/=(modBase const& x) {return (*this) *= x.inverse(); }

    friend modBase operator+(const modBase& a, const modBase& b) {modBase ret(a); return ret += b; }
    friend modBase operator-(const modBase& a, const modBase& b) {modBase ret(a); return ret -= b; }
    friend modBase operator*(const modBase& a, const modBase& b) {modBase ret(a); return ret *= b; }
    friend modBase operator/(const modBase& a, const modBase& b) {modBase ret(a); return ret /= b; }

    modBase& operator++() {return (*this) += 1; }
    modBase operator++(int) {modBase tmp(*this); operator++(); return tmp; }
    modBase& operator--() {return (*this) -= 1; }
    modBase operator--(int) {modBase tmp(*this); operator--(); return tmp; }

    template<typename X> static modBase factorial(X v) {modBase ret(1); for (modBase i(1); --v >= 0 ; ++i) ret *= i; return ret; }

    friend ostream& operator<<(ostream &os, const modBase& m) {return os << m.val; }
    friend bool operator<(const modBase& a, const modBase& b) {return a.val < b.val; }
    friend bool operator==(const modBase& a, const modBase& b) {return a.val == b.val; }
};

template<ll M> using modInteger = modBase<ll, M>;
using mod1e9p7 = modInteger<ll(1e9 + 7)>;
using mod1e9p9 = modInteger<ll(1e9 + 9)>;
using mod998s = modInteger<998244353LL>;
using mods = pair<mod1e9p7, mod1e9p9>;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> dist(ll(0.1e9), ll(0.9e9));   


template<typename A, typename B> pair<A, B> operator+(const pair<A, B>& x, const pair<A, B>& y) {return {x.fi + y.fi, x.se + y.se}; }
template<typename A, typename B> pair<A, B> operator-(const pair<A, B>& x, const pair<A, B>& y) {return {x.fi - y.fi, x.se - y.se}; }
template<typename A, typename B> pair<A, B> operator*(const pair<A, B>& x, const pair<A, B>& y) {return {x.fi * y.fi, x.se * y.se}; }
template<typename A, typename B> pair<A, B> operator/(const pair<A, B>& x, const pair<A, B>& y) {return {x.fi / y.fi, x.se / y.se}; }

template<typename A, typename B> pair<A, B> operator+(const pair<A, B>& x) {return x; }
template<typename A, typename B> pair<A, B> operator-(const pair<A, B>& x) {return {-x.fi, -x.se}; }

template<typename A, typename B, typename C> pair<A, B> operator*(const C& y, const pair<A, B>& x) {return {x.fi * y, x.se * y}; }
template<typename A, typename B, typename C> pair<A, B> operator*(const pair<A, B>& x, const C& y) {return {x.fi * y, x.se * y}; }
template<typename A, typename B, typename C> pair<A, B> operator/(const pair<A, B>& x, const C& y) {return {x.fi / y, x.se / y}; }

template<typename C = string, typename T = mods> struct rollingHash
{
	int l, r;
	T currHash;
	
	const C& obj;
	const vector<T>& salt;
	const T& invSalt;
	
	T hash() {return currHash; }
	
	void rollLeftSide(int v)
	{
		while (l < v)
		{
			currHash = currHash - obj[l] * salt[0];
			currHash = currHash * invSalt;
			++l;
		}
		
		while (l > v)
		{
			--l;
			currHash = currHash * salt[1];
			currHash = currHash + obj[l] * salt[0];
		}
	}
	
	void rollRightSide(int v)
	{
		while (r < v)
		{
			++r;
			currHash = currHash + obj[r] * salt[r - l];
		}
		
		while (r > v)
		{
			currHash = currHash - obj[r] * salt[r - l];
			--r;
		}
	}
	
	void set(int vl, int vr)
	{
		currHash = T();
		l = vr + 1;
		r = vr;
		rollLeftSide(vl);
	}
	
	rollingHash(const C& o, const vector<T>& s, const T& iS) 
		: obj(o), salt(s), invSalt(iS), l(0), r(-1), currHash(T()) {}
		
	rollingHash(const C& o, const vector<T>& s, const T& iS, int vl, int vr) 
		: obj(o), salt(s), invSalt(iS) {set(vl, vr); }
};

size_t hash_combine(size_t lhs, size_t rhs) 
{
	lhs ^= rhs + 0x9e3779b9 + (lhs << 6) + (lhs >> 2);
	return lhs;
}

template<>
struct std::hash<array<ll, 4>> {
    std::size_t operator()(const array<ll, 4>& a) const {
        return hash_combine(hash_combine(a[0], a[1]), hash_combine(a[2], a[3]));
    }
};

int32_t main()
{
    fastIO;
    
    ll ans = 0;
    
	int n, slen = -1;
    cin >> n;
    
    unordered_map<ll, vector<string>> cc;
    
    vector<mods> salt;
    salt.emplace_back(1, 1);
    salt.emplace_back(dist(rng), dist(rng));
    mods invSalt = salt[0] / salt[1];
    
    hash<string> hasher;
    
	repeat(_, n)
	{
		string s, t;
		cin >> s;
		
		t = s;
		sort(all(t));
		
		if (slen == -1)
			slen = t.size();
		
		ll hs = hasher(t);
		
		cc[hs].push_back(string());
		swap(s, cc[hs].back());
	}
    
    while (salt.size() < slen + 5)
    	salt.push_back(salt[1] * salt.back());
	
	for (auto& [_, strs] : cc)
	{
		int k = strs.size();
		ans += 1337L * ll(k) * ll(n - k);
		
		vvi sortedFrom(k, vi(slen));
		
		repeat(i, k)
		{
			string& str = strs[i];
			vi& dp = sortedFrom[i];
			
			for (int j = 1; j < slen; ++j)
			{
				if (str[j] >= str[j-1])
					dp[j] = dp[j - 1];
				else
					dp[j] = j;
			}
		}

		#define sorted(i) (sortedFrom[i][slen-1] == 0)
		#define subSorted(i, j, k) (sortedFrom[i][k] <= j)

		if (k < 10000) 

		{
			repeat(i, k)
				repeat(j, i)
				{
					if (sorted(i) || sorted(j))
					{
						ans += 2;
						continue;
					}
					
					int l = 0, r = slen - 1;
					
					while (strs[i][l] == strs[j][l])
						++l;
					while (strs[i][r] == strs[j][r])
						--r;
						
					if (subSorted(i, l, r) || subSorted(j, l, r))
						ans += 2;
					else
						ans += 4;
				}
		}
		else 

		{			
			unordered_set<array<ll, 4>> hashes;
			repeat(ind, k)
			{				
				rollingHash left(strs[ind], salt, invSalt);
				
				for (int i = 0; i < slen; ++i)
				{					
					left.rollRightSide(i - 1);
					
					rollingHash right(strs[ind], salt, invSalt, slen, slen - 1);
					
					for (int j = slen - 1; j > i; --j)
					{						
						right.rollLeftSide(j + 1);
												
						if (sortedFrom[ind][j] == i && (j+1 == slen || sortedFrom[ind][j+1] == j+1))
						{
							array<ll, 4> comb = {left.currHash.fi.val, left.currHash.se.val, right.currHash.fi.val, right.currHash.se.val};
							hashes.insert(comb);
						}
					}
				}
			}
			
			ll matches = 0;
			
			repeat(ind, k)
			{
				ll matchesCurr = 0;
				
				rollingHash left(strs[ind], salt, invSalt);
				
				for (int i = 0; i < slen; ++i)
				{
					left.rollRightSide(i - 1);
					
					rollingHash right(strs[ind], salt, invSalt, slen, slen - 1);
					
					for (int j = slen - 1; j > i; --j)
					{
						right.rollLeftSide(j + 1);
						
						if (sortedFrom[ind][j] == i && (j+1 == slen || sortedFrom[ind][j+1] == j+1))
							continue;
						
						array<ll, 4> comb = {left.currHash.fi.val, left.currHash.se.val, right.currHash.fi.val, right.currHash.se.val};
						matchesCurr += hashes.count(comb);
					}
				}
				
				matches += matchesCurr;
			}
			
			ans += 2 * (ll(k)*ll(k - 1) - matches);
		}
	}
	
	cout << ans / 2;

    return 0;
}
