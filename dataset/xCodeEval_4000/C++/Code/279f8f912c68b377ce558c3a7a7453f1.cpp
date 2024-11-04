#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")



#include <iostream>
#include <algorithm>


#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>


#include <valarray>
#include <unordered_map>
#include <unordered_set>
#include <array>




#include <sstream>


#include <fstream>


#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <chrono>
#include <random>
#include <numeric>



#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
#define VAR(type, ...)type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T& t) { std::cin >> t; }
template<typename First, typename...Rest>void MACRO_VAR_Scan(First& first, Rest& ...rest) { std::cin >> first; MACRO_VAR_Scan(rest...); }
#define VEC_ROW(type, n, ...)std::vector<type> __VA_ARGS__;MACRO_VEC_ROW_Init(n, __VA_ARGS__); for(int w_=0; w_<n; ++w_){MACRO_VEC_ROW_Scan(w_, __VA_ARGS__);}
template<typename T> void MACRO_VEC_ROW_Init(int n, T& t) { t.resize(n); }
template<typename First, typename...Rest>void MACRO_VEC_ROW_Init(int n, First& first, Rest& ...rest) { first.resize(n); MACRO_VEC_ROW_Init(n, rest...); }
template<typename T> void MACRO_VEC_ROW_Scan(int p, T& t) { std::cin >> t[p]; }
template<typename First, typename...Rest>void MACRO_VEC_ROW_Scan(int p, First& first, Rest& ...rest) { std::cin >> first[p]; MACRO_VEC_ROW_Scan(p, rest...); }
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define MAT(type, c, m, n) std::vector<std::vector<type>> c(m, std::vector<type>(n));for(auto& R:c)for(auto& w:R)std::cin>>w;


#define OUT(dist) std::cout<<(dist);
#define FOUT(n, dist) std::cout<<std::fixed<<std::setprecision(n)<<(dist);
#define SOUT(n, c, dist) std::cout<<std::setw(n)<<std::setfill(c)<<(dist);
#define SP std::cout<<" ";
#define TAB std::cout<<"\t";
#define BR std::cout<<"\n";
#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define ENDL std::cout<<std::endl;
#define FLUSH std::cout<<std::flush;
#define SHOW(dist) {std::cerr << #dist << "\t:" << (dist) << "\n";}
#define SHOWVECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOWVECTOR2(v) {std::cerr << #v << "\t:\n";for(const auto& xxx : v){for(const auto& yyy : xxx){std::cerr << yyy << " ";}std::cerr << "\n";}}
#define SHOWQUEUE(a) {auto tmp(a);std::cerr << #a << "\t:";while(!tmp.empty()){std::cerr << tmp.front() << " ";tmp.pop();}std::cerr << "\n";}


#define ALL(a) (a).begin(),(a).end()
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define RFOR(w, a, n) for(int w=(n)-1;w>=(a);--w)
#define REP(w, n) for(int w=0;w<int(n);++w)
#define RREP(w, n) for(int w=int(n)-1;w>=0;--w)
#define IN(a, x, b) (a<=x && x<b)
template<class T> inline T CHMAX(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T CHMIN(T& a, const T b) { return a = (a > b) ? b : a; }
#define EXCEPTION(msg) throw std::string("Exception : " msg " [ in ") + __func__ + " : " + std::to_string(__LINE__) + " lines ]"
#define TRY(cond, msg) try {if (cond) EXCEPTION(msg);}catch (std::string s) {std::cerr << s << std::endl;}
void CHECKTIME(std::function<void()> f) { auto start = std::chrono::system_clock::now(); f(); auto end = std::chrono::system_clock::now(); auto res = std::chrono::duration_cast<std::chrono::nanoseconds>((end - start)).count(); std::cerr << res / (1.0e9) << "s\n"; }


template<class T> using V = std::vector<T>;
template<class T> using VV = V<V<T>>;

template<typename S, typename T>
std::ostream& operator<<(std::ostream & os, std::pair<S, T> p) {
	os << "(" << p.first << ", " << p.second << ")"; return os;
}

#define random_shuffle "USE std::shuffle!";



#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PAIR = std::pair<int, int>;
using PAIRLL = std::pair<ll, ll>;
constexpr int INFINT = (1 << 30) - 1;                    

constexpr int INFINT_LIM = (1LL << 31) - 1;              

constexpr ll INFLL = 1LL << 60;                          

constexpr ll INFLL_LIM = (1LL << 62) - 1 + (1LL << 62);  

constexpr double EPS = 1e-10;
constexpr int MOD = 1000000007;
constexpr double PI = 3.141592653589793238462643383279;
template<class T, size_t N> void FILL(T(&a)[N], const T & val) { for (auto& x : a) x = val; }
template<class ARY, size_t N, size_t M, class T> void FILL(ARY(&a)[N][M], const T & val) { for (auto& b : a) FILL(b, val); }
template<class T> void FILL(std::vector<T> & a, const T & val) { for (auto& x : a) x = val; }
template<class ARY, class T> void FILL(std::vector<std::vector<ARY>> & a, const T & val) { for (auto& b : a) FILL(b, val); }



class SAIS {
private:
	const signed n;
	std::vector<bool> t;
	std::vector<signed> p1;

	void constructSA(const std::vector<signed>& s, signed K) {
		std::vector<signed> B(K, 0);
		std::vector<signed> start(K + 1, 0);
		std::vector<signed> LMS(n, -1);
		std::vector<signed> tmp(n, -1);

		auto inducedSort = [&](std::vector<signed> & a) {
			std::vector<signed> l(K), r(K);
			for (signed i = 0; i < K; ++i) l[i] = start[i], r[i] = start[i + 1] - 1;

			for (const auto& i : a) {
				if (i > 0 && !t[i - 1]) a[l[s[i - 1]]++] = i - 1;
			}

			for (signed ti = n - 1; ti >= 0; --ti) {
				signed i = a[ti];
				if (i > 0 && t[i - 1]) a[r[s[i - 1]]--] = i - 1;
			}
		};

		{ 

			t[n - 1] = true;
			for (signed i = n - 2; i >= 0; --i) {
				if (s[i] == s[i + 1]) t[i] = t[i + 1];
				else t[i] = (s[i] < s[i + 1]);
			}
		}
		{ 

			for (signed i = 0; i < n; ++i) {
				if (i > 0 && !t[i - 1] && t[i]) LMS[i] = p1.size(), p1.emplace_back(i);
				++B[s[i]];
			}
			for (signed i = 0; i < K; ++i) start[i + 1] = start[i] + B[i];
		}
		{ 

			std::vector<signed> r(K);
			for (signed i = 0; i < K; ++i) r[i] = start[i + 1] - 1;
			for (signed i : p1) tmp[r[s[i]]--] = i;

			inducedSort(tmp);
		}
		std::vector<signed> s1(p1.size());
		bool conti = false;
		signed K1 = 0;
		{ 

			std::vector<signed> t1(p1.size()), t2(p1.size(), 0);
			signed p = 0;
			for (signed ti = 0; ti < n; ++ti) {
				signed i = tmp[ti];
				if (LMS[i] != -1) t1[p++] = i;
			}

			

			for (signed si = 1; si < t2.size(); ++si) {
				signed i = t1[si - 1], j = t1[si];
				if (s[i] != s[j]) {
					t2[si] = t2[si - 1] + 1;
					continue;
				}
				++i; ++j;
				while (LMS[i] == -1 && LMS[j] == -1 && s[i] == s[j]) ++i, ++j;
				if (LMS[i] != -1 && LMS[j] != -1) {
					t2[si] = t2[si - 1];
					conti = true;
				}
				else {
					t2[si] = t2[si - 1] + 1;
				}
			}
			K1 = t2.back() + 1;

			

			for (signed i = 0; i < t1.size(); ++i) s1[LMS[t1[i]]] = t2[i];
		}
		std::vector<signed> sa1;
		{ 

			if (conti) {
				sa1 = SAIS(s1, K1).sa;
			}
			else {
				sa1.resize(s1.size());
				for (signed i = 0; i < s1.size(); ++i) sa1[s1[i]] = i;
			}
		}
		{ 

			sa.resize(n, -1);
			std::vector<signed> r(K);
			for (signed i = 0; i < K; ++i) r[i] = start[i + 1] - 1;
			for (signed pi = static_cast<signed>(p1.size()) - 1; pi >= 0; --pi) {
				signed i = p1[sa1[pi]];
				sa[r[s[i]]--] = i;
			}

			inducedSort(sa);
		}
	}

	void constructLCP(const std::vector<signed> & s) {
		const signed n = s.size() - 1;
		lcp.resize(n + 1);
		std::vector<signed> rank(n + 1);
		for (signed i = 0; i <= n; ++i) rank[sa[i]] = i;

		signed h = 0;
		lcp[0] = 0;
		for (signed i = 0; i < n; ++i) {
			signed j = sa[rank[i] - 1];
			if (h > 0) --h;
			for (; j + h < n && i + h < n; ++h) if (s[j + h] != s[i + h]) break;
			lcp[rank[i] - 1] = h;
		}
	}
	
	SAIS(std::vector<signed> s, int k) : n(s.size()), t(n) {
		constructSA(s, k); constructLCP(s);
	}
public:
	std::string str;
	std::vector<signed> sa;
	std::vector<signed> lcp;

	SAIS(const std::string & s_) : str(s_), n(s_.size() + 1), t(n) {
		signed k = 0;
		std::vector<signed> s(n);
		{ 

			std::vector<signed> used(256, -1);
			used[0] = 0; s[n - 1] = 0;
			for (signed i = 0; i < n - 1; ++i) used[s_[i]] = 0;
			for (signed i = 0; i < 256; ++i) if (used[i] != -1) used[i] = k++;
			for (signed i = 0; i < n - 1; ++i) s[i] = used[s_[i]];
		}
		constructSA(s, k);
		constructLCP(s);
	}

	void debug_show() const {
		std::cerr << "idx  " << " sa  " << "LCP  " << "suffix\n";
		for (int i = 0; i < n; ++i) {
			std::cerr << std::setw(3) << std::setfill(' ') << i << "  ";
			std::cerr << std::setw(3) << std::setfill(' ') << sa[i] << "  ";
			std::cerr << std::setw(3) << std::setfill(' ') << lcp[i] << "  ";
			std::cerr << str.substr(sa[i]) << "\n";
		}
	}
};

PAIR solve() {
	VAR(int, n, m, k);
	VAR(std::string, s, t);

	

	auto S = s + "$" + t + "~";
	SAIS SS(S);
	std::vector<int> miS(std::max(m, k), INFINT);

	int baseS = 0;
	while (SS.sa[baseS] != n + 1) ++baseS;
	{ 

		if (SS.lcp[baseS] == m) {
			int idx = SS.sa[baseS + 1];
			while (idx + k + k > n) --idx;
			return PAIR(idx, idx + k);
		}
		if (SS.lcp[baseS - 1] == m) {
			int idx = SS.sa[baseS - 1];
			while (idx + k + k > n) --idx;
			return PAIR(idx, idx + k);
		}
	}
	{ 

		int p = baseS - 1;
		int mi = k;
		while (p >= 0 && SS.lcp[p] != 0) {
			CHMIN(mi, (int)SS.lcp[p]);
			if (IN(0, SS.sa[p], n)) {
				int idx = SS.sa[p] + mi - k;
				if (IN(0, idx, n - m + 1)) {
					if (mi >= m) {
						idx = SS.sa[p];
						while (idx + k + k > n) --idx;
						return PAIR(idx, idx + k);
					}
					CHMIN(miS[mi], idx);
				}
			}
			--p;
		}
	}
	{ 

		int p = baseS + 1;
		int mi = k;
		int sz = SS.lcp.size();
		while (p < sz && SS.lcp[p - 1] != 0) {
			CHMIN(mi, (int)SS.lcp[p - 1]);
			if (IN(0, SS.sa[p], n)) {
				int idx = SS.sa[p] + mi - k;
				if (IN(0, idx, n - m + 1)) {
					if (mi >= m) {
						idx = SS.sa[p];
						while (idx + k + k > n) --idx;
						return PAIR(idx, idx + k);
					}
					CHMIN(miS[mi], idx);
				}
			}
			++p;
		}
	}
	RFOR(i, 1, miS.size()) {
		if (miS[i] == INFINT) continue;
		int t = miS[i] - 1;
		if (t < 0) continue;
		CHMIN(miS[i - 1], t);
	}

	

	std::reverse(ALL(s));
	std::reverse(ALL(t));
	auto T = s + "$" + t + "~";
	SAIS TT(T);
	std::vector<int> miT(std::max(m, k), INFINT);

	int baseT = 0;
	while (TT.sa[baseT] != n + 1) ++baseT;
	{ 

		int p = baseT - 1;
		int mi = k;
		while (p >= 0 && TT.lcp[p] != 0) {
			CHMIN(mi, (int)TT.lcp[p]);
			if (IN(0, TT.sa[p], n)) {
				int idx = TT.sa[p] + mi - k;
				if (IN(0, idx, n - m + 1)) {
					CHMIN(miT[mi], idx);
				}
			}
			--p;
		}
	}
	{ 

		int p = baseT + 1;
		int mi = k;
		int sz = TT.lcp.size();
		while (p < sz && TT.lcp[p - 1] != 0) {
			CHMIN(mi, (int)TT.lcp[p - 1]);
			if (IN(0, TT.sa[p], n)) {
				int idx = TT.sa[p] + mi - k;
				if (IN(0, idx, n - m + 1)) {
					CHMIN(miT[mi], idx);
				}
			}
			++p;
		}
	}
	RFOR(i, 1, miT.size()) {
		if (miT[i] == INFINT) continue;
		int t = miT[i] - 1;
		if (t < 0) continue;
		CHMIN(miT[i - 1], t);
	}

	FOR(i, 1, m) { 

		int j = m - i; 

		if (miS[i] == INFINT || miT[j] == INFINT) continue;
		int ss = miS[i], tt = (n - miT[j] - 1) - k + 1;
		if (ss + k - 1 < tt) {
			return PAIR(ss, tt);
		}
	}

	return PAIR(-1, -1);
}

signed main() {
	INIT;

	auto p(solve());

	if (p.first == -1) {
		OUT("No")BR;
	}
	else {
		OUT("Yes")BR;
		OUT(p.first + 1)SP OUT(p.second + 1)BR;
	}

	return 0;
}