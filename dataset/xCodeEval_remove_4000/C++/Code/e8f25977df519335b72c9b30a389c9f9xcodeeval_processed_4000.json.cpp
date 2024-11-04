

using namespace std;






mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

	
	

	
	


template <typename T> std::ostream& operator<<(std::ostream& stream, const vector<T>& vec){ for(size_t i = 0; i < vec.size(); i++){stream << vec[i];if(i != vec.size() - 1)stream << ' ';}; return stream; }
template <typename T> std::istream& operator>>(std::istream& stream, vector<T>& vec) { for(T &x : vec)stream >> x;return stream; }
template <typename T,typename U> std::ostream& operator<<(std::ostream& stream, const pair<T,U>& pr){ stream << pr.first << ' ' << pr.second; return stream; }
template <typename T,typename U> std::istream& operator>>(std::istream& stream, pair<T,U>& pr){ stream >> pr.first >> pr.second; return stream; }
template <typename T> void operator+=(vector<T>& vec, const T value) { for(T &x : vec)x += value; }
template <typename T> void operator-=(vector<T>& vec, const T value) { for(T &x : vec)x -= value; }
template <typename T> void operator++(vector<T>& vec) { vec += 1; }
template <typename T> void operator++(vector<T>& vec,T) { vec += 1; }
template <typename T> void operator--(vector<T>& vec) { vec -= 1; }
template <typename T> void operator--(vector<T>& vec,T) { vec -= 1; }
template <typename T> void operator*=(vector<T>& vec, const T value) { for(T &x : vec)x *= value; }
template <typename T> void operator/=(vector<T>& vec, const T value) { for(T &x : vec)x /= value; }
template <typename T,typename U> void operator+=(pair<T,U>& vec, const T value) { vec.first += value;vec.second += value; }
template <typename T,typename U> void operator-=(pair<T,U>& vec, const T value) { vec.first -= value;vec.second -= value; }
template <typename T,typename U> void operator++(pair<T,U>& vec) { vec += 1; } 
template <typename T,typename U> void operator++(pair<T,U>& vec,T) { vec += 1; } 
template <typename T,typename U> void operator--(pair<T,U>& vec) { vec -= 1; } 
template <typename T,typename U> void operator--(pair<T,U>& vec,T) { vec -= 1; } 
template <typename T,typename U> void operator*=(pair<T,U>& vec, const T value) { vec.first *= value;vec.second *= value; } 
template <typename T,typename U> void operator/=(pair<T,U>& vec, const T value) { vec.first /= value;vec.second /= value; } 

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
void id0() { return; }template <typename Head, typename... Tail>void id0(Head &H, Tail & ... T) {H.clear();id0(T...);}
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

		uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
		uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
		asm(
			"divl %4; "
			: "=a" (d), "=d" (m)
			: "d" (xh), "a" (xl), "r" (mod())
		);
		value = m;

		value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));

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
 

void testcase(){
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>> a(n);
	cin >> a;
	vector<Mint> wrong(m+1,0);
	for(int p = 1;p <= m;p++){
		if((ll)p*n > (ll)m)break;
		vector<vector<Mint>> dp(n+1,vector<Mint>((m+p)/p,0));
		vector<pair<int,int>> b = a;
		bool bad = false;
		for(int i = 0; i < n; i++){
			b[i].first = b[i].first + (p - b[i].first%p)%p;
			b[i].second -= b[i].second%p;
			if(b[i].second < b[i].first)bad = true;
		}
		if(bad)continue;
		dp[0][0] = 1;
		for(int i = 1; i <= n; i++){
			vector<Mint> pref(dp[0].size());
			for(int j = 0; j < (int)dp[0].size(); j++){
				pref[j] = dp[i-1][j];
				if(j != 0)pref[j] += pref[j-1];
			}
			auto sum = [&](int x,int y){
				assert(x <= y);
				if(y < 0)return Mint(0);
				ckmax(x,0);
				return pref[y] - (x == 0 ? 0 : pref[x-1]);
			};
			for(int j = 0; j <= m; j += p){
				j /= p;
				dp[i][j] = sum(j - (b[i-1].second/p) , j - (b[i-1].first/p));
				j *= p;
			}
		}
		for(int i = 0; i <= m; i += p){
			wrong[p] += dp[n][i/p];
		}
	}
	vector<Mint> cnt(m+1,0);
	for(int i = m-1; i >= 1; i--){
		cnt[i] = wrong[i];
		for(int j = 2*i; j <= m; j += i){
			cnt[i] -= cnt[j];
		}
	}
	cout << cnt[1] << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt = 1;
	

	while(tt--){
		testcase();
	}
	return 0;
}

