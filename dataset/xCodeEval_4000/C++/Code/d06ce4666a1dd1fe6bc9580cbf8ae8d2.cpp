

using namespace std;
#include <bits/stdc++.h>
#define ld long double
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#ifdef shivang_ka_laptop
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__);
	#define booga cerr << "booga" << endl;
#else
	#define debug(...) 42;
	#define booga 9;
#endif

template <typename T> std::ostream& operator<<(std::ostream& stream, const vector<T>& vec){ for(size_t i = 0; i < vec.size(); i++){stream << vec[i];if(i != vec.size() - 1)stream << ' ';}; return stream; }
template <typename T> std::istream& operator>>(std::istream& stream, vector<T>& vec) { for(T &x : vec)stream >> x;return stream; }
template <typename T,typename U> std::ostream& operator<<(std::ostream& stream, const pair<T,U>& pr){ stream << pr.first << ' ' << pr.second; return stream; }
template <typename T,typename U> std::istream& operator>>(std::istream& stream, pair<T,U>& pr){ stream >> pr.first >> pr.second; return stream; }
template <typename T, typename U> void operator+=(vector<T>& vec, const U value) { for(T &x : vec)x += value; }
template <typename T, typename U> void operator-=(vector<T>& vec, const U value) { for(T &x : vec)x -= value; }
template <typename T, typename U> void operator*=(vector<T>& vec, const U value) { for(T &x : vec)x *= value; }
template <typename T, typename U> void operator/=(vector<T>& vec, const U value) { for(T &x : vec)x /= value; }
template <typename T> void operator++(vector<T>& vec) { vec += 1; }
template <typename T> void operator++(vector<T>& vec,int) { vec += 1; }
template <typename T> void operator--(vector<T>& vec) { vec -= 1; }
template <typename T> void operator--(vector<T>& vec,int) { vec -= 1; }
template <typename T,typename U, typename V> void operator+=(pair<T,U>& vec, const V value) { vec.first += value;vec.second += value; }
template <typename T,typename U, typename V> void operator-=(pair<T,U>& vec, const V value) { vec.first -= value;vec.second -= value; }
template <typename T,typename U, typename V> void operator*=(pair<T,U>& vec, const V value) { vec.first *= value;vec.second *= value; }
template <typename T,typename U, typename V> void operator/=(pair<T,U>& vec, const V value) { vec.first /= value;vec.second /= value; }
template <typename T,typename U> void operator++(pair<T,U>& vec) { vec += 1; } 
template <typename T,typename U> void operator++(pair<T,U>& vec,int) { vec += 1; } 
template <typename T,typename U> void operator--(pair<T,U>& vec) { vec -= 1; } 
template <typename T,typename U> void operator--(pair<T,U>& vec,int) { vec -= 1; } 

template <typename A, typename B>string to_string(pair<A, B> p);
template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(char c) {string s;s += c;return s; }
string to_string(const char* s) {return to_string((string) s); }
string to_string(bool b) {return (b ? "1" : "0"); }
string to_string(vector<bool> v) {bool first = true;string res = "{";for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) {res += ", ";}first = false;res += to_string(v[i]);}res += "}";return res;}
template <size_t N>string to_string(bitset<N> v) {string res = "";for (size_t i = 0; i < N; i++) {res += static_cast<char>('0' + v[i]);}return res;}
template <typename A>string to_string(A v) {bool first = true;string res = "{";for (const auto &x : v) {if (!first) {res += ", ";}first = false;res += to_string(x);}res += "}";return res;}
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p) {return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";}
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void debug_out() { cerr << endl; } template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {cerr << " " << to_string(H);debug_out(T...);}
void bharo(int N_N) { return; }template <typename Head, typename... Tail>void bharo(int N_N, Head &H, Tail & ... T) {H.resize(N_N);bharo(N_N,T...);}
void safai() { return; }template <typename Head, typename... Tail>void safai(Head &H, Tail & ... T) {H.clear();safai(T...);}

template <typename T>
T inverse(T a, T m) {
	T u = 0, v = 1;
	while (a != 0) {
		T t = m / a;
		m -= t * a; swap(a, m);
		u -= t * v; swap(u, v);
	}
	assert(m == 1);
	return u;
}
 
template <typename T>
class Modular {
 public:
	using Type = typename decay<decltype(T::value)>::type;
	constexpr Modular() : value() {}
	template <typename U>
	Modular(const U& x) {
		value = normalize(x);
	}
	template <typename U>
	static Type normalize(const U& x) {
		Type v;
		if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
		else v = static_cast<Type>(x % mod());
		if (v < 0) v += mod();
		return v;
	}
	const Type& operator()() const { return value; }
	template <typename U>
	explicit operator U() const { return static_cast<U>(value); }
	constexpr static Type mod() { return T::value; }
	Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
	Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
	template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
	template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
	Modular& operator++() { return *this += 1; }
	Modular& operator--() { return *this -= 1; }
	Modular operator++(int) { Modular result(*this); *this += 1; return result; }
	Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
	Modular operator-() const { return Modular(-value); }
	template <typename U = T>
	typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
		uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
		uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
		asm(
			"divl %4; "
			: "=a" (d), "=d" (m)
			: "d" (xh), "a" (xl), "r" (mod())
		);
		value = m;
#else
		value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
		return *this;
	}
	template <typename U = T>
	typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type& operator*=(const Modular& rhs) {
		long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
		value = normalize(value * rhs.value - q * mod());
		return *this;
	}
	template <typename U = T>
	typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
		value = normalize(value * rhs.value);
		return *this;
	}
	Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }
	friend const Type& abs(const Modular& x) { return x.value; }
	template <typename U>
	friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
	template <typename U>
	friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
	template <typename V, typename U>
	friend V& operator>>(V& stream, Modular<U>& number);
	private: Type value;
};
 
template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }
template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }
template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
 
template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
	assert(b >= 0);
	Modular<T> x = a, res = 1;
	U p = b;
	while (p > 0) {
		if (p & 1) res *= x;
		x *= x;
		p >>= 1;
	}
	return res;
}
 
template <typename T>
bool IsZero(const Modular<T>& number) {
	return number() == 0;
}
 
template <typename T>
string to_string(const Modular<T>& number) {
	return to_string(number());
}
 


template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
	return stream << number();
}
 


template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
	typename common_type<typename Modular<T>::Type, long long>::type x;
	stream >> x;
	number.value = Modular<T>::normalize(x);
	return stream;
}
 



 








 


constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

Mint power(int x,const long long int y){
	return power(Mint(x),y);
}

vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);


const int MXN = 1e6;

void prep(){ 

	fact.resize(MXN);
	inv_fact.resize(MXN);
	fact[0] = 1;
	for(int i = 1; i < MXN; i++){
		fact[i] = fact[i-1]*i;
	}
	inv_fact[MXN-1] = power(fact[MXN-1],md-2);
	for(int i = MXN-2; i >= 0; i--){
		inv_fact[i] = inv_fact[i+1]*(i+1);
	}
}
 

Mint C(int n, int k) {
	if (k < 0 || k > n) {
		return 0;
	}
	while ((int) fact.size() < n + 1) {
		fact.push_back(fact.back() * (int) fact.size());
		inv_fact.push_back(1 / fact.back());
	}
	return fact[n] * inv_fact[k] * inv_fact[n - k];
}

int dis(pair<int,int> p1,pair<int,int> p2){
	return abs(p1.first-p2.first)+ abs(p1.second-p2.second);
}

void testcase(){
	int n;
	cin >> n;
	vector<pair<int,int>> a(n);
	cin >> a;
	vector<int> cnt(n,0);
	vector<vector<int>> graph(n);
	vector<vector<bool>> adj(n,vector<bool>(n,false));
	for(int i = 0; i < n; i++){
		int sml = 1e9;
		for(int j = 0; j < n; j++){
			if(i == j)continue;
			ckmin(sml,dis(a[i],a[j]));
		}
		for(int j = 0; j < n; j++){
			if(dis(a[i],a[j]) == sml){
				graph[i].push_back(j);
				adj[i][j] = true;
			}
		}
	}
	vector<vector<int>> col;
	vector<bool> done(n,false);
	for(int i = 0; i < n; i++){
		if(done[i])continue;
		vector<int> here;
		vector<bool> vis(n,false);
		function<void(int)> dfs = [&](int x){
			if(vis[x])return;
			here.push_back(x);
			vis[x] = true;
			for(int y : graph[x]){
				dfs(y);
			}
		}; dfs(i);
		int m = here.size();
		bool ok = true;
		for(int j = 0; j < m; j++){
			for(int k = 0; k < m; k++){
				if(j == k)continue;
				if(!adj[here[j]][here[k]]){
					ok = false;
				}
			}
		}
		if(ok){
			col.push_back(here);
			for(int x : here){
				done[x] = true;
			}
		}
		else{
			col.push_back({i});
		}
	}
	
	vector<vector<Mint>> dp(col.size(),vector<Mint>(n+1));
	for(int cc = 1;cc <= n;cc++){
		dp[col.size()-1][cc] += cc;
		
		if(col.back().size() != 1)dp[col.size()-1][cc] += fact[col.back().size()]*C(cc,col.back().size());
	}
	for(int i = col.size()-2; i >= 0; i--){
		for(int cc = 1;cc <= n;cc++){
			

			dp[i][cc] += cc*dp[i+1][cc-1];
		}
		for(int cc = col[i].size();cc <= n;cc++){
			

			if(col[i].size() != 1)dp[i][cc] += fact[col[i].size()]*C(cc,col[i].size())*dp[i+1][cc-col[i].size()];
		}
	}
	cout << dp[0][n];
}

int32_t main(){
	prep();
	ios::sync_with_stdio(false);
	cin.tie(0);
	prep();
	int tt = 1;
	

	while(tt--){
		testcase();
	}
	return (0-0);
}
