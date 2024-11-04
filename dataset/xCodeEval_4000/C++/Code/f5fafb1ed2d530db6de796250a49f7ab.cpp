#ifdef aimbot
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#endif

#define hur(f, g) template<class c> int f(c a) {if (sizeof(c) == 8) return g##ll(a); else return g(a);}
hur(popc, __builtin_popcount) hur(ctz, __builtin_ctz) hur(clz, __builtin_clz)



#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <ostream>
#include <istream>
#include <typeinfo>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <limits>
#include <fstream>
#include <array>
#include <list>
#include <bitset>
#include <functional>
#include <random>
#include <cstring>
#include <chrono>
#include <complex>

#define random escape__from__random__aetuhoetnuhshe
#define mt make_tuple
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define le(v) ((int)v.size())
#define f(i, n) for (int i = 0; i < (n); i++)
#define rof(i, n) for (int i = ((n) - 1); i >= 0; i--)
#define apply(v, act) for (auto &x : v) { act; }
#define log_(args...) {string s = #args;deque<string> deq;\
string buf = "";int bal = 0;for (char c : s) {\
if (c == '(' || c == '[' || c == '{') {bal++;\
} else if (c == ')' || c == ']' || c == '}') {\
bal--;} else {if (bal == 0) {if (c == ',') {\
deq.pb(buf);buf = "";} else {if (c != ' ') {\
buf += c;}}}}}if (!buf.empty()) {deq.pb(buf);}\
smart_io::precall_print();smart_io::_print(deq, args);}

inline int min(const int &x, const int &y) { return (((y-x)>>(32-1))&(x^y))^x; }
inline int max(const int &x, const int &y) { return (((y-x)>>(32-1))&(x^y))^y; }
inline long long min(const long long &x, const long long &y) { return (((y-x)>>(64-1))&(x^y))^x; }
inline long long max(const long long &x, const long long &y) { return (((y-x)>>(64-1))&(x^y))^y; }

template<class T>
inline bool umax(T &x, const T &y) {
	if (x < y) {
		x = y;
		return true;
	}
	return false;
}

template<class T>
inline bool umin(T &x, const T &y) {
	if (x > y) {
		x = y;
		return true;
	}
	return false;
}


#define print    \
smart_io::precall_print(); \
cout,

#define scan cin,

#ifdef fast_allocator
const int MAXMEM = 200 * 1000 * 1024;
char _memory[MAXMEM];
size_t _ptr = 0;
void* operator new(size_t _x) { _ptr += _x; assert(_ptr < MAXMEM); return _memory + _ptr - _x; }
void operator delete (void*) noexcept {}
#endif

using namespace std;

char string_in_buffer[(int)260];


void fast_scan(int &x) { scanf("%d", &x); }
void fast_scan(long long &x) { scanf("%lld", &x); }
void fast_scan(unsigned long long &x) { scanf("%llu", &x); }
void fast_scan(double &x) { scanf("%lf", &x); }
void fast_scan(long double &x) { scanf("%Lf", &x); }
void fast_scan(char &x) {
	scanf("%c", &x);
	if (x == '\n') {
		fast_scan(x);
	}
}
void fast_scan(string &x) {
	scanf("%s", string_in_buffer);
	x = string(string_in_buffer);
}

template<class TFirst, class TSecond>
void fast_scan(pair<TFirst, TSecond> &p) {
	fast_scan(p.first);
	fast_scan(p.second);
}

template <class T>
void fast_scan(vector<T> &v) {
	for (auto &x : v) fast_scan(x);
}

void fast_print(const int &x) { printf("%d", x); }
void fast_print(const unsigned int &x) { printf("%u", x); }
void fast_print(const long long &x) { printf("%lld", x); }
void fast_print(const unsigned long long &x) { printf("%llu", x); }
void fast_print(const char &x) { printf("%c", x); };






























void fast_print(const double &x) { printf("%.15lf", x); }
void fast_print(const long double &x) { printf("%.15Lf", x); }
void fast_print(const string &x) { printf("%s", x.c_str());}
void fast_print(const char v[]) { fast_print((string)v); }

template<class TFirst, class TSecond>
void fast_print(const pair<TFirst, TSecond> &p) {
	fast_print(p.first);
	fast_print(' ');
	fast_print(p.second);
}

template <class T>
void fast_print(const vector<T> &v) {
	if (v.empty()) return;
	fast_print(v[0]);
	for (int i = 1; i < v.size(); i++) {
		fast_print(' ');
		fast_print(v[i]);
	}
}

template <class T>
void fast_print(const vector<vector<T>> &v) {
	if (v.empty()) return;
	fast_print(v[0]);
	for (int i = 1; i < v.size(); i++) {
		fast_print('\n');
		fast_print(v[i]);
	}
}

template <class T>
void fast_print(const T &v) {
	for (const auto &x : v) {
		fast_print(x);
		fast_print(' ');
	}
}


using namespace std;


namespace smart_io {
	string print_start = "";
	string sep = " ";
	bool first_print = false;
	
	void precall_print() {
		fast_print(print_start);
		print_start = "\n";
		first_print = true;
	}
	
	void _print(deque<string>) {}
	template<class T, class... Args>
	void _print(deque<string> names, T elem, Args... args) {
		if (!first_print) {
			fast_print("\n");
		} else {
			first_print = false;
		}
		fast_print(names.front());
		fast_print(" = ");
		fast_print(elem);
		names.pop_front();
		_print(names, args...);
	}
} 



template <class T>
ostream &operator,(ostream &os, const T &object) {
	if (!smart_io::first_print) {
		fast_print(smart_io::sep);
	} else {
		smart_io::first_print = false;
	}
	fast_print(object);
	return os;
}

template <class T>
istream &operator,(istream &is, T &object) {
	fast_scan(object);
	return is;
}

namespace random {
	using namespace std::chrono;
	mt19937 rng(duration_cast< milliseconds >(
											  system_clock::now().time_since_epoch()
											  ).count());
	uniform_real_distribution<> prob_dist(0.0, 1.0);
};

namespace typedefs {
	typedef long long ll;
	typedef unsigned long long ull;
	typedef pair<int, int> pii;
	typedef long double ld;
}

namespace numbers_operation {
	template<class T>
	inline T floor_mod(T a, const T &b) {
		a %= b;	
		if (a < 0) a += b;
		return a;
	}
}

using namespace numbers_operation;
using namespace typedefs;
using namespace random;



const ll MOD = 998244353;
template<ll MOD>
struct Ring {
	ll value = 0;
	Ring() {}
	Ring(int _value) {
		value = _value;
		value = floor_mod(value, MOD);
	}
	Ring(ll _value) {
		value = _value;
		value = floor_mod(value, MOD);
	}
	Ring pow(ll p) const {
		Ring r = 1;
		Ring x; x.value = value;
		while (p) {
			if (p & 1) r *= x;
			x *= x;
			p /= 2;
		}
		return r;
	}
	Ring inv() const {
		return pow(MOD - 2);
	}
	void operator*=(const Ring<MOD> &b) {
		value *= b.value;
		value = floor_mod(value, MOD);
	}
	friend Ring operator*(Ring<MOD> a, const Ring<MOD> &b) {
		a *= b;
		return a;
	}
	void operator+=(const Ring<MOD> &b) {
		value += b.value;
		value -= (value >= MOD) * MOD;
	}
	friend Ring operator+(Ring a, const Ring &b) {
		a += b;
		return a;
	}
	void operator-=(const Ring<MOD> &b) {
		value -= b.value;
		value += (value < 0) ? MOD : 0;
	}
	friend Ring operator-(Ring a, const Ring &b) {
		a -= b;
		return a;
	}
	void operator/=(const Ring<MOD> &b) {
		(*this) *= b.inv();	
	}
	friend Ring operator/(Ring a, const Ring &b) {
		a /= b;
		return a;
	}
	bool operator==(const Ring<MOD> &b) {
		return value == b.value;
	}
	bool operator!=(const Ring<MOD> &b) {
		return value != b.value;
	}
	friend void fast_print(const Ring<MOD> &b) {
		fast_print(b.value);
	}
};
typedef Ring<MOD> num;
namespace GF {
  constexpr long long p=998244353;

  long long ADD(long long a,long long b) {
    return a+b>=p?a+b-p:a+b;
  }

  std::vector<long long> trim(std::vector<long long> a,int n) {
    std::vector<long long> b(n,0);
    for (int i=0;i<std::min(n,(int)a.size());++i) b[i]=a[i];
    return b;
  }

  std::vector<long long> shift(std::vector<long long> a,int shift) {
    std::vector<long long> b(a.size(),0);
    for (int i=0;i<(int)a.size();++i) b[i]=(0<=i-shift&&i-shift<(int)a.size())?a[i-shift]:0;
    return b;
  }

  long long pow_mod(long long a,long long n) {
    return n==0?1:(pow_mod(a*a%p,n/2)*(n%2==1?a:1))%p;
  }

  long long inv(long long a) {
    return pow_mod(a,p-2);
  }

  std::vector<long long> add(std::vector<long long> a,std::vector<long long> b) {
    int n=std::max(a.size(),b.size());
    std::vector<long long> c(n);
    a.resize(n);b.resize(n);
    for (int i=0;i<n;++i) c[i]=ADD(a[i],b[i]);
    return c;
  }

  std::vector<long long> subtract(std::vector<long long> a,std::vector<long long> b) {
    int n=std::max(a.size(),b.size());
    std::vector<long long> c(n);
    a.resize(n);b.resize(n);
    for (int i=0;i<n;++i) c[i]=ADD(a[i],p-b[i]);
    return c;
  }

  void fft(std::vector<long long> &a,long long g) {
    int n=a.size();
    g=pow_mod(g,(p-1)/n);
    {
      int i=0;
      for (int j=0;j<n;++j) {
        if (i>j) std::swap(a[i],a[j]);
        for (int k=n/2;k>(i^=k);k/=2) ;
      }
    }
    for (int len=1;len<=n/2;len*=2) {
      long mul=pow_mod(g,n/(2*len));
      for (int src=0;src<n;src+=2*len) {
        long long x=1;
        for (int pos=src;pos<src+len;++pos) {
          long long A=a[pos];
          long long B=a[pos+len]*x%p;
          a[pos]=ADD(A,B);
          a[pos+len]=ADD(A,p-B);
          x=x*mul%p;
        }
      }
    }
  }

  std::vector<long long> mul(std::vector<long long> a,std::vector<long long> b) {
    long long g=3;
    int n=1;
    while (n<(int)(a.size()+b.size()-1)) n*=2;
    a.resize(n);
    b.resize(n);
    fft(a,g);
    fft(b,g);
    long long inv_n=inv(n);
    for (int i=0;i<n;++i) a[i]=a[i]*b[i]%p*inv_n%p;
    fft(a,inv(g));
    return a;
  }

  std::vector<long long> mul(std::vector<long long> a,long long b) {
    int n=a.size();
    std::vector<long long> c(n);
    for (int i=0;i<n;++i) c[i]=a[i]*b%p;
    return c;
  }

  std::vector<long long> inv(std::vector<long long> a) {
    int n=a.size();
    std::vector<long long> b={inv(a[0])};
    for (int len=1;len<n;len*=2) {
      b=subtract(mul(b,2),trim(mul(mul(b,b),trim(a,2*len)),2*len));
    }
    return b;
  }

  std::vector<long long> differentiate(std::vector<long long> a) {
    int n=a.size();
    std::vector<long long> b(n,0);
    for (int i=0;i+1<n;++i) b[i]=(i+1)*a[i+1]%p;
    return b;
  }

  std::vector<long long> integrate(std::vector<long long> a) {
    int n=a.size();
    std::vector<long long> b(n,0);
    for (int i=1;i<n;++i) b[i]=inv(i)*a[i-1]%p;
    return b;
  }

  std::vector<long long> log(std::vector<long long> a) {
    assert(a[0]==1);
    return integrate(mul(differentiate(a),inv(a)));
  }

  std::vector<long long> exp(std::vector<long long> a) {
    assert(a[0]==0);
    int n=a.size();
    std::vector<long long> b={1};
    for (int len=1;len<n;len*=2) {
      std::vector<long long> tmp=subtract(trim(a,2*len),log(trim(b,2*len)));
      ++tmp[0];
      b=trim(mul(b,tmp),2*len);
    }
    return b;
  }

  std::vector<long long> pow(std::vector<long long> a,int n) {
    assert(n>=1);
    int s=0;
    while (s<(int)a.size() && a[s]==0) ++s;
    if (s==(int)a.size()) return a;
    a=shift(a,-s);
    long long b=inv(a[0]);
    for (int i=0;i<(int)a.size();++i) a[i]=b*a[i]%p;
    a=log(a);
    for (int i=0;i<(int)a.size();++i) a[i]=n%p*a[i]%p;
    a=exp(a);
    b=pow_mod(inv(b),n%(p-1));
    for (int i=0;i<(int)a.size();++i) a[i]=b*a[i]%p;
    a=shift(a,s*n);
    return a;
  }

  std::vector<long long> pow_exact(std::vector<long long> a,int n) {
    std::vector<long long> b={1};
    for (int i=0;i<n;++i) b=trim(mul(b,a),a.size());
    return b;
  }
};



vector<num> fact((int)3e5 + 100);
vector<num> rfact((int)3e5 + 100);
void solve() {
	int n;
	scan n;

	auto binom = [&](int n, int k) {
		return fact[n] * rfact[n - k] * rfact[k];
	};
	vector<num> dp(n + 1);
	dp[0] = 1;
	for (int k = 1; k <= n; k++) {
		for (int x : {1, 2}) {
			if (k - x >= 0) {
				dp[k] += dp[k - x] * binom(k - 1, x - 1) * fact[x - 1];
			}
		}
	}
	

	

	vector<ll> P(n + 10);
	P[0] = 1;
	P[1] = GF::p - (fact[0] / fact[1]).value;
	P[2] = GF::p - (fact[1] / fact[2]).value;
	

	vector<num> S(n + 2);
	S[0] = 1;
	for (int i = 2; i <= n; i++) {
		S[i] = num(i - 1) * S[i - 2];
	}
	

	num rez = 0;
	for (int k = 0; 4 * k <= n; k++) {
		rez += binom(n - 2 * k, 2 * k)
					* S[2 * k]
					* fact[2].pow(k)
					* num(dp[n - 4 * k]);
	}
	

	print rez;
	

	

}

signed main(signed argc, char *argv[]) {
	fact[0] = 1;
	for (int i = 1; i < 3e5 + 10; i++) {
		fact[i] = num(i) * fact[i - 1];
		rfact[i] = fact[i].inv();
	}
	rfact[0] = 1;
	

	int tests;
	scan tests;
	f(test, tests) {
		solve();
	}
	return 0;
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

}
