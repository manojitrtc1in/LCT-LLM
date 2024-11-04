

#ifndef JulesIMF_ONCE_INCLUDED_
#define JulesIMF_ONCE_INCLUDED_
#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <ccomplex>
#include <functional>
#include <fstream>
#include <numeric>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>
#include <ostream>
#include <sstream>
#include <random>


#define vsegda_prav72 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

#ifdef JulesIMF_LOCAL_
#define test freopen("Test", "r", stdin) 

#else
#define test ;
#define __int64 long long
#endif
#ifdef JulesIMF_LOCAL_
#define outcry freopen("Outcry", "w", stdout) 

#define debug(...) cout << "[" << #__VA_ARGS__ << "] == "; ___debug(__VA_ARGS__);
#else
#define outcry ;
#define debug(...) ;
#endif
#define no cout << "No\n" 

#define nocont {cout << "No\n"; continue;} 

#define noret {cout << "No\n"; return 0;} 

#define yes cout << "Yes\n" 

#define fort() int number_of_tests; cin >> number_of_tests; \
for (int current_test_iterator = 0; current_test_iterator < number_of_tests; current_test_iterator++) 

#define forn(__i,__n) for(int __i = 0; __i < (__n); __i++) 

#define rforn(__i,__n) for(int __i = (__n)-1; __i >=0; __i--) 

#define llforn(__i,__n) for(__int64 __i = 0; __i < (__n); __i++) 

#define llrforn(__i,__n) for(__int64 __i = (__n)-1; __i >=0; __i--) 

#define aread(__a, __n) for(int read_iterator = 0; read_iterator < __n; read_iterator++) cin >> __a[read_iterator]; 

#define anew(__t, __a, __n) __t* __a = new __t[__n]; for(int read_iterator = 0; read_iterator < __n; read_iterator++) cin >> __a[read_iterator]; 

#define mp make_pair 

#define mtup make_tuple 

#define pb push_back 

#define bgn begin() 

#define ed end() 

#define fst first 

#define snd second 

#define X real() 

#define Y imag() 

#define llcast(__v) static_cast<__int64>(__v) 

#define itall(__v) __v.begin(), __v.end() 

#define ritall(__v) __v.rbegin(), __v.rend() 

#define outn(__s) cout << (__s) << "\n" 

#define outs(__s) cout << (__s) << " " 

#define acnt cout << "\t" 

#define nl cout << "\n" 

#define adel(__a) delete[] __a 

#define ainit(__a, __n, __v) forn(init_iterator, __n) __a[init_iterator] = (__v); 

#define bounds(__a, __l, __r) ((((__a)>=(__l))&&((__a)<(__r)))?true:false) 

#define liesin(__l, __r, __L, __R) ((((__l)>=(__L))&&((__l)<(__R))&&((__r)>(__L))&&((__r)<=(__R)))?true:false) 

#define belongto(__a, __s) ((__s.find(__a)!=__s.end())?true:false) 

#define mswap(__a, __b) if(__a > __b) swap(__a,__b); 

#ifdef JulesIMF_LOCAL_
#define timers auto time_start_value = chrono::high_resolution_clock::now(); 

#define shelt cout << "\nTime elapsed:  " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - time_start_value).count() << " ms\n"; 

#define newtimer(__v) auto __v = chrono::high_resolution_clock::now(); 

#define showtimer(__v) cout << "\nTime elapsed:  " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - __v).count() << " ms\n"; 

#else
#define timers ;
#define shelt ;
#define newtimer ;
#define showtimer ;
#endif


using namespace std;
using ll = __int64;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vsi = vector<set<int>>;
using vsll = vector<set<ll>>;
using vs = vector<string>;
using si = set<int>;
using spii = set<pii>;
using sll = set<ll>;
using spll = set<pll>;
using ss = set<string>;
using mii = map<int, int>;
using msi = map<string, int>;
using mci = map<char, int>;
using qi = queue<int>;
using qpii = queue<pii>;
using qll = queue<ll>;
using sti = stack<int>;
using stpii = stack<pii>;
using stll = stack<ll>;
using li = list<int>;
using ti = tuple<int, int, int>;
using vti = vector<ti>;
using comi = complex<int>;


constexpr const ll INFLL = 1e18;
constexpr const int MAXN = 2e5;
constexpr const int INF = 1e9;
constexpr const ll kek = 998244353;
constexpr const ll mod7 = 1e9 + 7;
constexpr const ll mod9 = 1e9 + 9;
constexpr const ld PI = 3.14159265358;


template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) { for (auto& a : v) cout << a << ' '; return os; }
template<typename T>
istream& operator>>(istream& is, vector<T>& v) { T val; cin >> val; v.push_back(val);  return is; }
template<typename T>
void print(T a) {
    cout << a << endl;
}
template<typename T, typename... Args>
void print(T a, Args... b) { 

    cout << a << " ";
    print(b...);
}
template<typename T>
void _debug(T a) {
    if (typeid(a) == typeid(char)) cout << '\'';
    if (typeid(a) == typeid(string)) cout << '\"';
    cout << a;
    if (typeid(a) == typeid(char)) cout << '\'';
    if (typeid(a) == typeid(string)) cout << '\"';
    cout << "]" << endl;
}
template<typename T, typename... Args>
void _debug(T a, Args... b) {
    if (typeid(a) == typeid(char)) cout << '\'';
    if (typeid(a) == typeid(string)) cout << '\"';
    cout << a;
    if (typeid(a) == typeid(char)) cout << '\'';
    if (typeid(a) == typeid(string)) cout << '\"';
    cout << ",\t";
    _debug(b...);
}
template<typename... Args>
void ___debug(Args... b) {
    cout << '[';
    _debug(b...);
}
template<typename T>
int popcount(T g) { int ans = 0; while (g != 0) { ans += (g & (T(1))); g >>= 1; } return ans; }



#ifdef JulesIMF_LOCAL_
#include "DefaultTemplate.h"
#endif
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

		value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));

		return *this;
	}
	template <typename U = T>
	typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
		int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
		value = normalize(value * rhs.value - q * mod());
		return *this;
	}
	template <typename U = T>
	typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
		value = normalize(value * rhs.value);
		return *this;
	}

	Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

	template <typename U>
	friend const Modular<U>& abs(const Modular<U>& v) { return v; }

	template <typename U>
	friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

	template <typename U>
	friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

	template <typename U>
	friend std::istream& operator>>(std::istream& stream, Modular<U>& number);

private:
	Type value;
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

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
	return stream << number();
}

template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
	typename common_type<typename Modular<T>::Type, int64_t>::type x;
	stream >> x;
	number.value = Modular<T>::normalize(x);
	return stream;
}


constexpr int md = kek;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

int main() {
    vsegda_prav72;

    int n;
    int k;
	cin >> n >> k;
    ll max = 0;
    if (k == 1) {
        print(n, 1);
        return 0;
    }

    Mint ans = 1;
	ll ma = 0;
	ll t;
	vi v;
	v.reserve(k);
	forn(i, n) {
		cin >> t;
		if (t > n - k) {
			v.push_back(i);
			ma += t;
		}
	}

	forn(i, k - 1) {
		ans *= (v[i + 1] - v[i]);
	}

	print(ma, ans);

    

    

    

}
#endif
