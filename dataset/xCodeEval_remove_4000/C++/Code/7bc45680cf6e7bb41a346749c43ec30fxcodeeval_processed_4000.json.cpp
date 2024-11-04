
using namespace std;

template<typename T>
struct id0{
	using Type = typename decay<decltype(T::value)>::type;
	static vector<Type> _MOD_INV;
	constexpr id0(): value(){ }
	template<typename U> id0(const U &x){ value = normalize(x); }
	template<typename U> static Type normalize(const U &x){
		Type v;
		if(-mod() <= x && x < mod()) v = static_cast<Type>(x);
		else v = static_cast<Type>(x % mod());
		if(v < 0) v += mod();
		return v;
	}
	const Type& operator()() const{ return value; }
	template<typename U> explicit operator U() const{ return static_cast<U>(value); }
	constexpr static Type mod(){ return T::value; }
	id0 &operator+=(const id0 &otr){ if((value += otr.value) >= mod()) value -= mod(); return *this; }
	id0 &operator-=(const id0 &otr){ if((value -= otr.value) < 0) value += mod(); return *this; }
	template<typename U> id0 &operator+=(const U &otr){ return *this += id0(otr); }
	template<typename U> id0 &operator-=(const U &otr){ return *this -= id0(otr); }
	id0 &operator++(){ return *this += 1; }
	id0 &operator--(){ return *this -= 1; }
	id0 operator++(int){ id0 result(*this); *this += 1; return result; }
	id0 operator--(int){ id0 result(*this); *this -= 1; return result; }
	id0 operator-() const{ return id0(-value); }
	template<typename U = T>
	typename enable_if<is_same<typename id0<U>::Type, int>::value, id0>::type &operator*=(const id0& rhs){
		
		uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
		uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
		asm(
			"divl %4; \n\t"
			: "=a" (d), "=d" (m)
			: "d" (xh), "a" (xl), "r" (mod())
		);
		value = m;
		
		value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
		
		return *this;
	}
	template<typename U = T>
	typename enable_if<is_same<typename id0<U>::Type, int64_t>::value, id0>::type &operator*=(const id0 &rhs){
		int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
		value = normalize(value * rhs.value - q * mod());
		return *this;
	}
	template<typename U = T>
	typename enable_if<!is_integral<typename id0<U>::Type>::value, id0>::type &operator*=(const id0 &rhs){
		value = normalize(value * rhs.value);
		return *this;
	}
	template<typename U>
	id0 &operator^=(U e){
		if(e < 0) *this = 1 / *this, e = -e;
		id0 res = 1;
		for(; e; *this *= *this, e >>= 1) if(e & 1) res *= *this;
		return *this = res;
	}
	template<typename U>
	id0 operator^(U e) const{
		return id0(*this) ^= e;
	}
	id0 &operator/=(const id0 &otr){
		Type a = otr.value, m = mod(), u = 0, v = 1;
		if(a < (int)_MOD_INV.size()) return *this *= _MOD_INV[a];
		while(a){
			Type t = m / a;
			m -= t * a; swap(a, m);
			u -= t * v; swap(u, v);
		}
		assert(m == 1);
		return *this *= u;
	}
	Type value;
};
template<typename T> bool operator==(const id0<T> &lhs, const id0<T> &rhs){ return lhs.value == rhs.value; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(const id0<T>& lhs, U rhs){ return lhs == id0<T>(rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(U lhs, const id0<T> &rhs){ return id0<T>(lhs) == rhs; }
template<typename T> bool operator!=(const id0<T> &lhs, const id0<T> &rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(const id0<T> &lhs, U rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(U lhs, const id0<T> &rhs){ return !(lhs == rhs); }
template<typename T> bool operator<(const id0<T> &lhs, const id0<T> &rhs){ return lhs.value < rhs.value; }
template<typename T> bool operator>(const id0<T> &lhs, const id0<T> &rhs){ return lhs.value > rhs.value; }
template<typename T> bool operator<=(const id0<T> &lhs, const id0<T> &rhs){ return lhs.value <= rhs.value; }
template<typename T> bool operator>=(const id0<T> &lhs, const id0<T> &rhs){ return lhs.value >= rhs.value; }
template<typename T> id0<T> operator+(const id0<T> &lhs, const id0<T> &rhs){ return id0<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id0<T> operator+(const id0<T> &lhs, U rhs){ return id0<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id0<T> operator+(U lhs, const id0<T> &rhs){ return id0<T>(lhs) += rhs; }
template<typename T> id0<T> operator-(const id0<T> &lhs, const id0<T> &rhs){ return id0<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id0<T> operator-(const id0<T>& lhs, U rhs){ return id0<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id0<T> operator-(U lhs, const id0<T> &rhs){ return id0<T>(lhs) -= rhs; }
template<typename T> id0<T> operator*(const id0<T> &lhs, const id0<T> &rhs){ return id0<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id0<T> operator*(const id0<T>& lhs, U rhs){ return id0<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id0<T> operator*(U lhs, const id0<T> &rhs){ return id0<T>(lhs) *= rhs; }
template<typename T> id0<T> operator/(const id0<T> &lhs, const id0<T> &rhs) { return id0<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id0<T> operator/(const id0<T>& lhs, U rhs) { return id0<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id0<T> operator/(U lhs, const id0<T> &rhs) { return id0<T>(lhs) /= rhs; }
template<typename T> istream &operator>>(istream &in, id0<T> &number){
	typename common_type<typename id0<T>::Type, int64_t>::type x;
	in >> x;
	number.value = id0<T>::normalize(x);
	return in;
}
template<typename T> ostream &operator<<(ostream &out, const id0<T> &number){ return out << number(); }
template<typename T> vector<typename id0<T>::Type> id0<T>::_MOD_INV;
template<typename T>
void id2(int SZ){
	auto &inv = T::_MOD_INV;
	if(inv.empty()) inv.assign(2, 1);
	for(; inv.size() <= SZ; ) inv.push_back((T::mod() - 1LL * T::mod() / (int)inv.size() * inv[T::mod() % (int)inv.size()]) % T::mod());
}
template<typename T>
vector<T> id4(T base, int SZ){
	vector<T> res(SZ + 1, 1);
	for(auto i = 1; i <= SZ; ++ i) res[i] = res[i - 1] * base;
	return res;
}

using ModType = int;
struct VarMod{ static ModType value; };
ModType VarMod::value;
ModType &mod = VarMod::value;
using modular = id0<VarMod>;

template<class T>
struct id6{
	int SZ = 0;
	vector<T> inv, fact, invfact;
	id6(){ }
	

	vector<vector<T>> precalc_C(int n, int m) const{
		vector<vector<T>> c(n + 1, vector<T>(m + 1));
		for(auto i = 0; i <= n; ++ i) for(auto j = 0; j <= min(i, m); ++ j) c[i][j] = i && j ? c[i - 1][j - 1] + c[i - 1][j] : 1;
		return c;
	}
	

	id6(int SZ): SZ(SZ), inv(SZ + 1, 1), fact(SZ + 1, 1), invfact(SZ + 1, 1){
		for(auto i = 1; i <= SZ; ++ i) fact[i] = fact[i - 1] * i;
		invfact[SZ] = 1 / fact[SZ];
		for(auto i = SZ - 1; i >= 0; -- i){
			invfact[i] = invfact[i + 1] * (i + 1);
			inv[i + 1] = invfact[i + 1] * fact[i];
		}
	}
	

	T C(int n, int k) const{
		return n < 0 ? C(-n + k - 1, k) * (k & 1 ? -1 : 1) : n < k || k < 0 ? 0 : fact[n] * invfact[k] * invfact[n - k];
	}
	

	T P(int n, int k) const{
		return n < k ? 0 : fact[n] * invfact[n - k];
	}
	

	T H(int n, int k) const{
		return C(n + k - 1, k);
	}
	

	T naive_C(long long n, long long k) const{
		if(n < k) return 0;
		T res = 1;
		k = min(k, n - k);
		for(auto i = n; i > n - k; -- i) res *= i;
		return res * invfact[k];
	}
	

	T naive_P(long long n, int k) const{
		if(n < k) return 0;
		T res = 1;
		for(auto i = n; i > n - k; -- i) res *= i;
		return res;
	}
	

	T naive_H(long long n, int k) const{
		return naive_C(n + k - 1, k);
	}
	

	bool parity_C(long long n, long long k) const{
		return n < k ? 0 : (n & k) == k;
	}
	

	

	T Catalan(int n, int k = 1) const{
		assert(0 <= n && 0 <= k);
		return k ? C(2 * n + k - 1, n) * k * fact[n + k - 1] * invfact[n + k] : !n;
	}
};




template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){
	return out << "{" << p.first << ", " << p.second << "}";
}
template<class Tuple, size_t N> struct TuplePrinter{
	static ostream &print(ostream &out, const Tuple &t){ return TuplePrinter<Tuple, N-1>::print(out, t) << ", " << get<N-1>(t); }
};
template<class Tuple> struct TuplePrinter<Tuple, 1>{
	static ostream &print(ostream &out, const Tuple& t){ return out << get<0>(t); }
};
template<class... Args> ostream &print_tuple(ostream &out, const tuple<Args...> &t){
	return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "{", t) << "}";
}
template<class ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){
	return print_tuple(out, t);
}
template<class T> ostream &operator<<(class enable_if<!is_same<T, string>::value, ostream>::type &out, const T &arr){
	out << "{"; for(auto x: arr) out << x << ", ";
	return out << (arr.empty() ? "" : "\b\b") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, const bitset<S> &b){
	for(auto i = 0; i < S; ++ i) out << b[i];
	return out;
}
ostream &operator<<(ostream &out, const _Bit_reference &bit){
	return out << bool(bit);
}
template<class T, class A, class C>
ostream &operator<<(ostream &out, priority_queue<T, A, C> pq){
	vector<T> a;
	while(!pq.empty()) a.push_back(pq.top()), pq.pop();
	return out << a;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void id5(){ }
template<class Head, class... Tail>
void id5(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; id5(T...); }
void id3(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void id3(Head H, Tail... T){
	for(auto d = 1; ; ++ d){
		if((H * d).value <= 1000000){
			cerr << H * d << "/" << d << ", ";
			break;
		}
		else if((-H * d).value <= 1000000){
			cerr << "-" << -H * d << "/" << d << ", ";
			break;
		}
	}
	id3(T...);
}
enum CODE{ CCRED = 31, CCGREEN = 32, CCYELLOW = 33, CCBLUE = 34, CCDEFAULT = 39 };











int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, id1;
	cin >> n >> m >> id1 >> mod;
	auto C = id6<modular>().precalc_C(n, n);
	vector<modular> fact(n + 1, 1);
	for(auto i = 1; i <= n; ++ i){
		fact[i] = fact[i - 1] * i;
	}
	vector dp(n + 1, vector(n + 1, vector<modular>(n + 1)));
	for(auto j = 0; j <= n; ++ j){
		dp[0][j][0] = 1;
	}
	for(auto i = 1; i <= n; ++ i){
		dp[i][0][0] = fact[i];
		for(auto j = 1; j <= i; ++ j){
			for(auto k = 0; k <= i; ++ k){
				for(auto pos = 0; pos < i; ++ pos){
					for(auto kl = min(k - (j == 1), pos); kl >= 0; -- kl){
						int kr = k - kl - (j == 1);
						dp[i][j][k] += dp[pos][j - 1][kl] * dp[i - 1 - pos][j - 1][kr] * C[i - 1][pos];
					}
				}
				if(k >= 3 && !dp[i][j][k] && !dp[i][j][k - 1] && !dp[i][j][k - 2] && !dp[i][j][k - 3]){
					break;
				}
			}
		}
		for(auto j = i + 1; j <= n; ++ j){
			dp[i][j][0] = fact[i];
		}
		debug(i);
		debug2(dp[i]);
	}
	cout << dp[n][m][id1] << "\n";
	return 0;
}












