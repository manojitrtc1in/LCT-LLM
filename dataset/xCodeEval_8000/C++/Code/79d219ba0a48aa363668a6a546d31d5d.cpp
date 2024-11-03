

#include <iostream>

#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <cstdint>
#include <cassert>
#include <complex>

#include <tuple>

using ll = long long int;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vll = std::vector<ll>;
using vvl = std::vector<vll>;
using pi = std::pair<int, int>;
using vpi = std::vector<pi>;

#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < n; i++)
#define rep(i, s, e) for(int i = (s); i <= (e); ++i)
#define repr(i, s, e) for(int i = (s); i >= (e); --i)
#define pb push_back

template<typename T> void mk_unique(T& l) { if (!std::is_sorted(all(l))) std::sort(all(l)); auto it = std::unique(l.begin(), l.end()); auto d = std::distance(l.begin(), it); l.resize(d); }
template<typename T> T &smax(T& l, const T&r) { if(l<r) l=r; return l; }
template<typename T> T &smin(T& l, const T&r) { if(l>r) l=r; return l; }

constexpr int MOD = 1000000007;

namespace io{
class input_reader{
void throw_error(){throw std::runtime_error("No more inputs while reading number");}
template<typename T>
inline void readIntegerValue(T&f){bool positive=true;f=0;char c;
if(!in.get(c))throw_error();
while(c<'0'||c>'9'){if(c=='-')positive=false;if(!in.get(c))throw_error();}
while(c>='0'&&c<='9'){f=(f<<3)+(f<<1)+(c&15);if(!in.get(c))break;}
if(!positive)f*=-1;}
public:
std::istream&in;
explicit input_reader(std::istream&in):in(in){}
inline void read(int&f){readIntegerValue(f);}
inline void read(short&f){readIntegerValue(f);}
inline void read(long int&f){readIntegerValue(f);}
inline void read(long long int&f){readIntegerValue(f);}
inline void read(unsigned int&f){readIntegerValue(f);}
inline void read(unsigned short&f){readIntegerValue(f);}
inline void read(unsigned long int&f){readIntegerValue(f);}
inline void read(unsigned long long int&f){readIntegerValue(f);}
template<typename T>inline void read(std::vector<T>&f){for(auto&i:f)read(i);}
template<typename T,int N>inline void read(std::array<T,N>&res){for(auto&i:res)read(i);}
template<typename T1,typename T2>inline void read(std::pair<T1,T2>&p){in.read(p.first,p.second);}
template<typename T>inline void read(T&f){in>>f;}
template<typename T,typename...Args>inline void read(T&t,Args&...args){read(t),read(args...);}
template<typename T>inline void readArray(int n,T*res){while(n--)read(*(res++));}
template<typename T>inline input_reader&operator>>(T&t){return read(t),*this;}
};
}

namespace io{
class output_writer{
std::ostream&out;
template<typename T>inline void printIntegerHelper(T x){if(x>=10)printIntegerHelper(x/10);out.put(x%10+48);}
template<typename T>inline void printInteger(T x){if(x<0)out.put('-'),x=-x;printIntegerHelper(x);}
template<typename T>inline void printArray(T&ar){bool first=true;for(auto&t:ar)print((first)? first=false,"":" ",t);}
public:
explicit output_writer(std::ostream&out):out(out){}
inline void flush(){out.flush();}
inline void print(){}
inline void print(char x){out.put(x);}
inline void print(short x){printInteger(x);}
inline void print(int x){printInteger(x);}
inline void print(long int x){printInteger(x);}
inline void print(long long int x){printInteger(x);}
inline void print(unsigned short x){printInteger(x);}
inline void print(unsigned int x){printInteger(x);}
inline void print(unsigned long int x){printInteger(x);}
inline void print(unsigned long long int x){printInteger(x);}
template<typename T1>inline void print(const T1&t1){out<<t1;}
template<typename T1>inline void print(const std::vector<T1>&t1){printArray(t1);}
template<typename T1,int N>inline void print(const std::array<T1,N>&t1){printArray(t1);}
template<typename T1,int N,int M>inline void print(const std::array<std::array<T1,M>,N>&t1){for(auto&t:t1)println(t);}
template<typename T1>inline void print(const std::vector<std::vector<T1>>&t1){for(auto&t:t1)println(t);}
template<typename T,typename...Args>inline void print(const T&t,Args...args){print(t),print(args...);}
template<typename...Args>inline void println(Args...args){print(args...),print('\n');}
template<typename T>output_writer&operator<<(const T&t){return print(t),*this;}
};
}

inline ll pow_mod(ll a,ll b,const ll MOD){ll res=1;for(ll i=1;b;b^=b&i,i<<=1,a=(a*a)%MOD)if(b&i)res=(res*a)%MOD;return res;}
inline ll mod_inv(const ll a,const ll MOD){return pow_mod(a,MOD-2,MOD);}
template<typename T>inline T gcd(T a,T b){T t;while(a!=0)t=a,a=b%a,b=t;return b;}
template<typename T>T lcm(const T &a,const T &b) {assert(a!=0&&b!=0);return a/gcd(a,b)*b;}

namespace math {
	class mod_int{
		int v;
	public:
		mod_int(int v):v(v%MOD){}
		mod_int(long long int v):v((int)(v%MOD)){}
		mod_int() = default;
		mod_int(const mod_int& o) = default;
		mod_int(mod_int&& o) = default;
		inline mod_int& operator=(const mod_int& o) = default;
		inline mod_int& operator=(mod_int&& o) = default;

		inline mod_int& operator++() { if(v==MOD-1) v=0; else v++; return *this; }
		inline mod_int& operator--() { if(v==0) v=MOD-1; else v--; return *this; }
		inline mod_int operator++(int) { mod_int t = *this; ++(*this); return t; }
		inline mod_int operator--(int) { mod_int t = *this; --(*this); return t; }

		inline bool friend operator<(const mod_int&lhs,const mod_int&rhs) { return lhs.v  <  rhs.v; }
		inline bool friend operator>(const mod_int&lhs,const mod_int&rhs) { return lhs.v  <  rhs.v; }
		inline bool friend operator<=(const mod_int&lhs,const mod_int&rhs) { return lhs.v <= rhs.v; }
		inline bool friend operator>=(const mod_int&lhs,const mod_int&rhs) { return lhs.v <= rhs.v; }
		inline bool friend operator==(const mod_int&lhs,const mod_int&rhs) { return lhs.v == rhs.v; }
		inline bool friend operator!=(const mod_int&lhs,const mod_int&rhs) { return lhs.v != rhs.v; }
		template<typename T> inline bool friend operator<(const mod_int&lhs,const T&rhs) { return  lhs <  mod_int(rhs); }
		template<typename T> inline bool friend operator>(const mod_int&lhs,const T&rhs) { return  lhs >  mod_int(rhs); }
		template<typename T> inline bool friend operator<=(const mod_int&lhs,const T&rhs) { return lhs <= mod_int(rhs); }
		template<typename T> inline bool friend operator>=(const mod_int&lhs,const T&rhs) { return lhs >= mod_int(rhs); }
		template<typename T> inline bool friend operator==(const mod_int&lhs,const T&rhs) { return lhs == mod_int(rhs); }
		template<typename T> inline bool friend operator!=(const mod_int&lhs,const T&rhs) { return lhs != mod_int(rhs); }

		inline mod_int friend operator-(const mod_int&lhs,const mod_int&rhs) { int v=lhs.v-rhs.v; if(v<0) v+=MOD; return {v}; }
		inline mod_int friend operator+(const mod_int&lhs,const mod_int&rhs) { int v=lhs.v+rhs.v; if(v>=MOD) v-=MOD; return {v}; }
		inline mod_int friend operator*(const mod_int&lhs,const mod_int&rhs) { return {(int)((((long long int) lhs.v)*rhs.v)%MOD)}; }
		inline mod_int friend operator/(const mod_int&lhs,const mod_int&rhs) { return {(int)((((long long int) lhs.v)*rhs.inv().v)%MOD)}; }
		inline mod_int friend operator%(const mod_int&lhs,const mod_int&rhs) { return { lhs.v % rhs.v }; }

		template <typename T> inline mod_int friend operator-(const mod_int&lhs,const T&rhs) { return lhs - mod_int(rhs); }
		template <typename T> inline mod_int friend operator+(const mod_int&lhs,const T&rhs) { return lhs + mod_int(rhs); }
		template <typename T> inline mod_int friend operator*(const mod_int&lhs,const T&rhs) { return lhs * mod_int(rhs); }
		template <typename T> inline mod_int friend operator/(const mod_int&lhs,const T&rhs) { return lhs / mod_int(rhs); }
		template <typename T> inline mod_int friend operator%(const mod_int&lhs,const T&rhs) { return {lhs.v % rhs}; }

		template <typename T> inline mod_int& operator-=(const T&rhs) { return *this = *this - rhs; }
		template <typename T> inline mod_int& operator+=(const T&rhs) { return *this = *this + rhs; }
		template <typename T> inline mod_int& operator*=(const T&rhs) { return *this = *this * rhs; }
		template <typename T> inline mod_int& operator/=(const T&rhs) { return *this = *this / rhs; }
		template <typename T> inline mod_int& operator%=(const T&rhs) { return *this = *this % rhs; }

		inline mod_int inv() const { return pow(MOD-2); }
		inline mod_int pow(long long int pw) const { mod_int res = 1, val = v; while(pw) {if(pw&1) res*=val; val*= val; pw>>=1;} return res; }

		inline operator int() const { return v; }

		inline friend std::istream& operator>>(std::istream& in,mod_int&rhs) { in >> rhs.v; rhs.v %= MOD; if(rhs.v<0) rhs.v+=MOD; return in; }
		inline friend std::ostream& operator<<(std::ostream& out,mod_int&rhs) { out << rhs.v; return out; }
	};
}

namespace math {
	mod_int factorial(int n) {
		static std::vector<mod_int> mem;
		static mod_int last;
		if (mem.empty()) last = {1}, mem.push_back(last);
		while (mem.size() <= n) mem.push_back(mem.back() * last++);
		return mem[n];
	}

	mod_int n_choose_k(int n, int k){
		mod_int res =  factorial(n) ;
		mod_int res2 = (factorial(k) * factorial(n-k));
		return res/res2;
	}
}
template<typename T, int dim, int split_size = 10>
class QuadTree_Integers_Node {
	int cnt = 0;
	int mask = (1 << dim) - 1;
	QuadTree_Integers_Node<T, dim> *children[1 << dim] = {0};
	std::vector<std::pair<std::array<T, dim>, int>> *points;
	std::array<std::pair<T, T>, dim> real_ranges;
public:
	const std::array<std::pair<T, T>, dim> ranges;
private:
	static std::array<std::pair<T, T>, dim>
	ranges_for_child(const std::array<std::pair<T, T>, dim> &ranges, int child_idx) {
		std::array<std::pair<T, T>, dim> res;
		for (int i = 0; i < dim; ++i) {
			T mid = (ranges[i].first + ranges[i].second) / 2;
			if ((1 << i) & child_idx) {
				res[i].first = mid + 1;
				res[i].second = ranges[i].second;
			} else {
				res[i].first = ranges[i].first;
				res[i].second = mid;
			}
		}
		return res;
	}

	explicit QuadTree_Integers_Node(const std::array<std::pair<T, T>, dim> &ranges) : ranges(ranges) {
		for (int i = 0; i < dim; ++i) {
			if (ranges[i].first == ranges[i].second)
				mask ^= 1 << i;
			real_ranges[i].first = ranges[i].second;
			real_ranges[i].second = ranges[i].first;
		}
		points = new std::vector<std::pair<std::array<T, dim>, int>>();
	}

	static std::array<std::pair<T, T>, dim> to_array(const std::vector<std::pair<T, T>> &ranges) {
		if (ranges.size() != dim) throw std::runtime_error("ranges size does not match dimensions.");
		std::array<std::pair<T, T>, dim> res;
		fori(i, dim) res[i] = ranges[i];
		return res;
	}

	void add_to_children(const std::array<T, dim> &point) {
		int child_idx = 0;
		for (int i = 0; i < dim; ++i) {
			T mid = (ranges[i].first + ranges[i].second) / 2;
			if (mid < point[i]) child_idx |= 1 << i;
		}
		child_idx &= mask;
		if (!children[child_idx])
			children[child_idx] = new QuadTree_Integers_Node<T, dim>(ranges_for_child(ranges, child_idx));
		children[child_idx]->add(point);
	}

	bool add_to_point_array(const std::array<T, dim> &point) {
		for (auto &i: *points) {
			if (i.first == point)
				return i.second++, true;
		}
		return false;
	}

	void add_to_local(const std::array<T, dim> &point) {
		if (!add_to_point_array(point))
			points->push_back({point, 1});
		if (point.size() > split_size) {
			auto points_tmp = points;
			points = nullptr;
			for (auto &p : *points_tmp)
				add(p.first);
		}
	}

	void update_real_range(const std::array<T, dim> &point) {
		for (int i = 0; i < dim; ++i) {
			if (point[i] < real_ranges[i].first) real_ranges[i].first = point[i];
			if (point[i] > real_ranges[i].second) real_ranges[i].second = point[i];
		}
	}

	int count_children(const std::function<int(std::array<std::pair<T, T>, dim>)> &quad_node_suspect_type_test) {
		int res = 0;
		for (int i = 0; i < (1 << dim); ++i) {
			if (children[i]) {
				res += children[i]->count(quad_node_suspect_type_test);
			}
		}
		return res;
	}

	int count_local(const std::function<int(std::array<std::pair<T, T>, dim>)> &quad_node_suspect_type_test) {
		int res = 0;
		std::array<std::pair<T, T>, dim> point_wrap;
		for (auto &i : *points) {
			for (int j = 0; j < dim; ++j) point_wrap[j].first = point_wrap[j].second = i.first[j];
			if (quad_node_suspect_type_test(point_wrap))
				res += i.second;
		}
		return res;
	}

public :
	QuadTree_Integers_Node(const std::vector<std::pair<T, T>> &ranges) : QuadTree_Integers_Node(to_array(ranges)) {}

	~QuadTree_Integers_Node() { delete points; }

	void add(const std::array<T, dim> &point) {
		if (points) add_to_local(point);
		else add_to_children(point);
		update_real_range(point);
		cnt++;
	}

	

	

	

	

	int count(const std::function<int(std::array<std::pair<T, T>, dim>)> &quad_node_suspect_type_test) {
		if (cnt == 0)
			return 0;
		int suspect_type = quad_node_suspect_type_test(real_ranges);
		if (!suspect_type) return 0;
		if (suspect_type == 2) return cnt;
		if (points) {
			return count_local(quad_node_suspect_type_test);
		} else {
			return count_children(quad_node_suspect_type_test);
		}
	}
};




#define BigIntSize 100
#define BigIntBase 100000
#define BigIntBaseDigits 5

class BigInt {
public:
	std::vector<int> m;
	int l;

	int operator[](int i) const { return m[i]; }

	int &operator[](int i) { return m[i]; }


	BigInt(long long x) : m(BigIntSize) {
		for (l = 1, m[l - 1] = x % BigIntBase, x /= BigIntBase; x; m[l++] = x % BigIntBase, x /= BigIntBase);
	}

	BigInt(int x) : BigInt((long long) x) {}

	BigInt() : BigInt(0) {}

	BigInt(const char *s) : BigInt() {
		int i, j, n;
		for (n = 0; s[n] >= '0' && s[n] <= '9'; n++);
		for (l = (n + BigIntBaseDigits - 1) / BigIntBaseDigits, i = 0; i < l; i++)
			for (m[i] = 0, j = 0; j < BigIntBaseDigits; j++)
				if (n - i * BigIntBaseDigits - BigIntBaseDigits + j >= 0)
					m[i] = m[i] * 10 +
						   s[n - i * BigIntBaseDigits -
							 BigIntBaseDigits + j] - '0';
	}


	BigInt(const std::string &s) : BigInt(s.c_str()) {}

	friend std::istream &operator>>(std::istream &stream, BigInt &v) {
		std::string s;
		stream >> s;
		v = s;
		return stream;
	}

	friend std::ostream &operator<<(std::ostream &stream, const BigInt &v) {
		int i;
		for ((stream << v.m[v.l - 1]), i = v.l - 2;
			 i >= 0; (stream << std::setw(BigIntBaseDigits) << std::setfill('0') << v.m[i]), i--);
		return stream;
	}
};

bool operator<(const BigInt &x, const BigInt &y) {
	int i;
	if (x.l != y.l) return x.l < y.l;
	for (i = x.l - 1; i >= 0 && x[i] == y[i]; i--);
	return i >= 0 && x[i] < y[i];
}

bool operator==(const BigInt &x, const BigInt &y) {
	int i;
	if (x.l != y.l) return 0;
	for (i = x.l - 1; i >= 0 && x[i] == y[i]; i--);
	return i < 0;
}

bool operator==(const BigInt &x, const long long y) {
	BigInt yy = y;
	return x == yy;
}


BigInt operator+(BigInt x, BigInt y) {
	int i;
	long long h;
	for (h = 0, i = 0; i < x.l || i < y.l || h; h += (i < x.l) * x[i] + (i < y.l) * y[i], x[i] = h %
																								 BigIntBase, h /= BigIntBase, i++);
	x.l = i;
	return x;
}

BigInt operator-(BigInt x, BigInt y) {
	int i;
	long long h;
	for (h = 0, i = 0;
		 i < x.l; h += x[i] - (i < y.l) * y[i] + BigIntBase, x[i] = h % BigIntBase, h /= BigIntBase, h--, i++);
	for (; x.l > 1 && !x[x.l - 1]; x.l--);
	return x;
}

BigInt operator*(BigInt x, int y) {
	int i;
	long long h;
	for (h = 0, i = 0;
		 i < x.l || h; h += (i < x.l) * (long long) x[i] * y, x[i] = h % BigIntBase, h /= BigIntBase, i++);
	for (x.l = i; x.l > 1 && !x[x.l - 1]; x.l--);
	return x;
}

BigInt operator/(BigInt x, int y) {
	int i;
	long long h;
	for (h = 0, i = x.l - 1; i >= 0; h = h * BigIntBase + x[i], x[i] = h / y, h %= y, i--);
	for (; x.l > 1 && !x[x.l - 1]; x.l--);
	return x;
}

int operator%(BigInt x, int y) {
	int i;
	long long h;
	for (h = 0, i = x.l - 1; i >= 0; h = h * BigIntBase + x[i], h %= y, i--);
	return h;
}

BigInt operator*(const BigInt &x, const BigInt &y) {
	int i, j;
	long long h;
	BigInt z;
	for (h = 0, z.l = x.l + y.l, i = 0; i < z.l; z[i] = h % BigIntBase, h /= BigIntBase, i++)
		for (j = i < x.l - 1 ? i : x.l - 1; j >= 0 && i - j < y.l; h += (long long) x[j] * y[i - j], j--);
	for (; z.l > 1 && !z[z.l - 1]; z.l--);
	return z;
}

BigInt operator/(BigInt x, BigInt y) {
	int i;
	BigInt h, t;
	if (y.l == 1) return x / y[0];
	for (h = 0, i = x.l - 1; i >= 0; h = h - y * x[i], i--)
		for (t = x[i], h = h * BigIntBase + t, x[i] = ((h.l > y.l) * ((long long) h[h.l - 1] * BigIntBase * BigIntBase +
																	  (long long) h[h.l - 2] * BigIntBase +
																	  h[h.l - 3]) + (h.l == y.l) *
																					((long long) h[h.l - 1] *
																					 BigIntBase + h[h.l - 2])) /
													  ((long long) y[y.l - 1] * BigIntBase + y[y.l - 2]);
			 x[i] && h < y * x[i]; x[i]--);
	for (; x.l > 1 && !x[x.l - 1]; x.l--);
	return x;
}

BigInt operator%(BigInt x, BigInt y) {
	int i;
	BigInt h, t;
	if (y.l == 1) return h = x % y[0];
	for (h = 0, i = x.l - 1; i >= 0; h = h - y * x[i], i--)
		for (t = x[i], h = h * BigIntBase + t, x[i] = ((h.l > y.l) * ((long long) h[h.l - 1] * BigIntBase * BigIntBase +
																	  (long long) h[h.l - 2] * BigIntBase +
																	  h[h.l - 3]) + (h.l == y.l) *
																					((long long) h[h.l - 1] *
																					 BigIntBase + h[h.l - 2])) /
													  ((long long) y[y.l - 1] * BigIntBase + y[y.l - 2]);
			 x[i] && h < y * x[i]; x[i]--);
	return h;
}
namespace numeric {
	namespace primes {
		const long long primes_for_add[59] = {
				1000000000100011, 1003229774283941, 1011001110001111, 1090109110921093, 1111235916285193,
				1181118711931201, 1235711131175321, 1238926361552897, 1301477951890177, 1311753223571113,
				1311870831664661, 1333333333333333, 1391098979592919, 1510553619999637, 1593350922240001,
				1616668118999191, 1680588011350901, 1693182318746371, 1737476797107127, 1867357583296451,
				1889080110806881, 1989530586646177, 1990474529917009, 2035802523820057, 2067078579454279,
				2222226095589337, 2231588810593399, 2345678911111111, 2355457523880889, 2380072466365871,
				2468642135797531, 2744337540964913, 3129313031303131, 3325997869054417, 3391382115599173,
				3733799929399999, 3931520917431241, 3940518300860411, 4444280714420857, 4564564564564561,
				4847464544434241, 5111111111111119, 5944066965503999, 5953474341373129, 5999999999899999,
				6171054912832631, 6241156164232441, 6435616333396997, 6664666366626661, 6735249118018991,
				7897466719774591, 7897897897897897, 8008808808808813, 8690333381690951, 9007199254740847,
				9007199254740881, 9293787934331213, 9949370777987917, 9999999900000001
		};

		const long long primes_for_multiply[200] = {
				1000000007, 1000000009, 1000000021, 1000000033, 1000000087, 1000000093, 1000000097, 1000000103,
				1000000123, 1000000181, 1000000207, 1000000223, 1000000241, 1000000271, 1000000289, 1000000297,
				1000000321, 1000000349, 1000000363, 1000000403, 1000000409, 1000000411, 1000000427, 1000000433,
				1000000439, 1000000447, 1000000453, 1000000459, 1000000483, 1000000513, 1000000531, 1000000579,
				1000000607, 1000000613, 1000000637, 1000000663, 1000000711, 1000000753, 1000000787, 1000000801,
				1000000829, 1000000861, 1000000871, 1000000891, 1000000901, 1000000919, 1000000931, 1000000933,
				1000000993, 1000001011, 1000001021, 1000001053, 1000001087, 1000001099, 1000001137, 1000001161,
				1000001203, 1000001213, 1000001237, 1000001263, 1000001269, 1000001273, 1000001279, 1000001311,
				1000001329, 1000001333, 1000001351, 1000001371, 1000001393, 1000001413, 1000001447, 1000001449,
				1000001491, 1000001501, 1000001531, 1000001537, 1000001539, 1000001581, 1000001617, 1000001621,
				1000001633, 1000001647, 1000001663, 1000001677, 1000001699, 1000001759, 1000001773, 1000001789,
				1000001791, 1000001801, 1000001803, 1000001819, 1000001857, 1000001887, 1000001917, 1000001927,
				1000001957, 1000001963, 1000001969, 1000002043, 1000002089, 1000002103, 1000002139, 1000002149,
				1000002161, 1000002173, 1000002187, 1000002193, 1000002233, 1000002239, 1000002277, 1000002307,
				1000002359, 1000002361, 1000002431, 1000002449, 1000002457, 1000002499, 1000002571, 1000002581,
				1000002607, 1000002631, 1000002637, 1000002649, 1000002667, 1000002727, 1000002791, 1000002803,
				1000002821, 1000002823, 1000002827, 1000002907, 1000002937, 1000002989, 1000003009, 1000003013,
				1000003051, 1000003057, 1000003097, 1000003111, 1000003133, 1000003153, 1000003157, 1000003163,
				1000003211, 1000003241, 1000003247, 1000003253, 1000003267, 1000003271, 1000003273, 1000003283,
				1000003309, 1000003337, 1000003351, 1000003357, 1000003373, 1000003379, 1000003397, 1000003469,
				1000003471, 1000003513, 1000003519, 1000003559, 1000003577, 1000003579, 1000003601, 1000003621,
				1000003643, 1000003651, 1000003663, 1000003679, 1000003709, 1000003747, 1000003751, 1000003769,
				1000003777, 1000003787, 1000003793, 1000003843, 1000003853, 1000003871, 1000003889, 1000003891,
				1000003909, 1000003919, 1000003931, 1000003951, 1000003957, 1000003967, 1000003987, 1000003999,
				1000004023, 1000004059, 1000004099, 1000004119, 1000004123, 1000004207, 1000004233, 1000004249
		};
	}
}



#include <memory>
#include <random>

namespace hashes {
	class hashed_string {
	public:
		const int length;
	private:
		static std::vector<long long> MODS;
		static constexpr int by = 256;
		std::vector<std::shared_ptr<std::vector<long long>>> my_hashes;
		const int shift;

		static long long pow_mod(long long a, long long b, long long MOD) {
			if (b == 0) return 1;
			if (b == 1) return a;
			long long side = 1;
			while (b != 1) {
				if (1 & b) side = side * a % MOD;
				a = a * a % MOD;
				b >>= 1;
			}
			return a * side % MOD;
		}

		long long get_hash(int i) const {
			long long res = (*my_hashes[i])[shift + length];
			if (shift != 0) {
				long long need_to_remove = (*my_hashes[i])[shift] * pow_mod(by, length, MODS[i]) % MODS[i];
				res -= need_to_remove;
				if (res < 0) res += MODS[i];
			}
			return res;
		}

		hashed_string(std::vector<std::shared_ptr<std::vector<long long int>>> my_hashes, int pos, int n) :
				length(n), my_hashes(my_hashes), shift(pos){}

		static bool was_shuffled;

		static inline int min(int a, int b) { return a < b ? a : b; }

	public:
		hashed_string(std::string &s, int number_of_hashes = 2) : length(s.size()), shift(0) {
			if (!was_shuffled)
				was_shuffled = true, std::shuffle(MODS.begin(), MODS.end(), std::default_random_engine(0));
			my_hashes.reserve(number_of_hashes);
			for (int i = 0; i < number_of_hashes; ++i) {
				my_hashes.push_back(std::make_shared<std::vector<long long>>(length + 1));
				auto &hs = *(my_hashes[i]);
				for (int j = 0; j < length; j++) hs[j + 1] = (hs[j] * by + s[j]) % MODS[i];
			}
		}

		hashed_string substr(int pos, int n = -1) const {
			if (n == -1) n = length - pos;
			return hashed_string(my_hashes, pos + shift, n);
		}

		bool operator==(const hashed_string &lhs) const {
			if (length != lhs.length) return false;
			int max_number_of_hashes = min(my_hashes.size(), lhs.my_hashes.size());
			for (int i = 0; i < max_number_of_hashes; ++i)
				if (get_hash(i) != lhs.get_hash(i)) return false;
			return true;
		}

		bool operator!=(const hashed_string &lhs) const {
			return !(*this == lhs);
		}
	};

	bool hashed_string::was_shuffled = false;
	std::vector<long long> hashed_string::MODS = {
			1000000007, 1000000009, 1000000021, 1000000033, 1000000087, 1000000093, 1000000097, 1000000103,
			1000000123, 1000000181, 1000000207, 1000000223, 1000000241, 1000000271, 1000000289, 1000000297,
			1000000321, 1000000349, 1000000363, 1000000403, 1000000409, 1000000411, 1000000427, 1000000433,
			1000000439, 1000000447, 1000000453, 1000000459, 1000000483, 1000000513, 1000000531, 1000000579,
			1000000607, 1000000613, 1000000637, 1000000663, 1000000711, 1000000753, 1000000787, 1000000801,
			1000000829, 1000000861, 1000000871, 1000000891, 1000000901, 1000000919, 1000000931, 1000000933,
			1000000993, 1000001011, 1000001021, 1000001053, 1000001087, 1000001099, 1000001137, 1000001161,
			1000001203, 1000001213, 1000001237, 1000001263, 1000001269, 1000001273, 1000001279, 1000001311,
			1000001329, 1000001333, 1000001351, 1000001371, 1000001393, 1000001413, 1000001447, 1000001449,
			1000001491, 1000001501, 1000001531, 1000001537, 1000001539, 1000001581, 1000001617, 1000001621,
			1000001633, 1000001647, 1000001663, 1000001677, 1000001699, 1000001759, 1000001773, 1000001789,
			1000001791, 1000001801, 1000001803, 1000001819, 1000001857, 1000001887, 1000001917, 1000001927,
			1000001957, 1000001963, 1000001969, 1000002043, 1000002089, 1000002103, 1000002139, 1000002149,
			1000002161, 1000002173, 1000002187, 1000002193, 1000002233, 1000002239, 1000002277, 1000002307,
			1000002359, 1000002361, 1000002431, 1000002449, 1000002457, 1000002499, 1000002571, 1000002581,
			1000002607, 1000002631, 1000002637, 1000002649, 1000002667, 1000002727, 1000002791, 1000002803,
			1000002821, 1000002823, 1000002827, 1000002907, 1000002937, 1000002989, 1000003009, 1000003013,
			1000003051, 1000003057, 1000003097, 1000003111, 1000003133, 1000003153, 1000003157, 1000003163,
			1000003211, 1000003241, 1000003247, 1000003253, 1000003267, 1000003271, 1000003273, 1000003283,
			1000003309, 1000003337, 1000003351, 1000003357, 1000003373, 1000003379, 1000003397, 1000003469,
			1000003471, 1000003513, 1000003519, 1000003559, 1000003577, 1000003579, 1000003601, 1000003621,
			1000003643, 1000003651, 1000003663, 1000003679, 1000003709, 1000003747, 1000003751, 1000003769,
			1000003777, 1000003787, 1000003793, 1000003843, 1000003853, 1000003871, 1000003889, 1000003891,
			1000003909, 1000003919, 1000003931, 1000003951, 1000003957, 1000003967, 1000003987, 1000003999,
			1000004023, 1000004059, 1000004099, 1000004119, 1000004123, 1000004207, 1000004233, 1000004249
	};
}


#include <stack>



namespace graphs {
	namespace scc {
		using namespace std;

		struct scc_results {
			vector<vector<int>> new_graph;
			vector<int> old_nodes_to_new_nodes;
			vector<vector<int>> new_nodes_to_list_of_old_nodes;
		};

		namespace {
			class tarjan_helper {
				struct metadata {
					int time_found = -1, lowlink = -1;
					bool on_stack = false;
				};
				const vector<vector<int>> &g;
				scc_results &res;

				const int n;
				vector<metadata> nodes;

				int cur_time = 0;
				stack<int> S;

				void visit(int i) {
					nodes[i].time_found = nodes[i].lowlink = cur_time++;
					S.push(i);
					nodes[i].on_stack = true;
					for (int j : g[i]) {
						if (nodes[j].time_found == -1) {
							visit(j);
							nodes[i].lowlink = min(nodes[i].lowlink, nodes[j].lowlink);
						} else if (nodes[j].on_stack)
							nodes[i].lowlink = min(nodes[i].lowlink, nodes[j].lowlink);
					}
					if (nodes[i].lowlink == nodes[i].time_found) {
						vector<int> new_cc;
						do {
							int j = S.top();
							S.pop();
							new_cc.push_back(j);
						} while (new_cc.back() != i);
						res.new_nodes_to_list_of_old_nodes.push_back(new_cc);
					}
				}

			public:

				tarjan_helper(vector<vector<int>> &g, scc_results &res) : g(g), res(res), n(g.size()),
																		  nodes(g.size(), metadata()) {
					for (int i = 0; i < n; i++) {
						if (nodes[i].time_found == -1)
							visit(i);
					}
					int new_n = res.new_nodes_to_list_of_old_nodes.size();
					res.old_nodes_to_new_nodes.resize(n);
					for (int i = 0; i < new_n; ++i)
						for (int j : res.new_nodes_to_list_of_old_nodes[i])
							res.old_nodes_to_new_nodes[j] = i;
					std::unordered_set<int> edges;
					res.new_graph.clear(), res.new_graph.resize(new_n);
					for (int i = 0; i < new_n; ++i) {
						edges.clear();
						for (int j : res.new_nodes_to_list_of_old_nodes[i])
							edges.insert(g[j].begin(), g[j].end());
						res.new_graph[i].insert(res.new_graph[i].end(), edges.begin(), edges.end());
					}
				}
			};
		}

		void tarjan_scc(vector<vector<int>> &g, scc_results &res) {
			tarjan_helper(g, res);
		}
	}
}

namespace geometry {
	inline bool is_zero(int x) { return x == 0; }
	inline bool is_zero(long x) { return x == 0; }
	inline bool is_zero(float x) { return abs(x) <= 1e-6; }
	inline bool is_zero(double x) { return abs(x) <= 1e-6; }
	inline bool is_equal(int x,int y) { return x == y; }
	inline bool is_equal(long x,long y) { return x == y; }
	inline bool is_equal(float x,float y) { return is_zero(x-y); }
	inline bool is_equal(double x,double y) { return is_zero(x-y); }
}
namespace geometry {
	namespace d2 {
		template<typename T>
		struct point;
		template<typename T>
		struct line;

		template<typename T>
		struct line {
			typedef std::pair<T, T> slope;
			

			T a, b, c;

			template<typename T1 = double>
			inline T1 get_x(const T &y) const {
				T1 res = b * y + c;
				return -res / a;
			}

			template<typename T1 = double>
			inline T1 get_y(const T &x) const {
				T1 res = a * x + c;
				return -res / b;
			}

			template<typename T1>
			inline bool contains(const point<T1> &p) const { return is_zero(a * p.x + b * p.y + c); }

			inline slope get_slope() const {
				T g = gcd(a, b);
				return {a / g, b / g};
			}

			inline friend bool operator<(const line<T> &lhs, const line<T> &rhs) {
				return lhs.as_pair() < rhs.as_pair();
			};

			inline friend bool operator==(const line<T> &lhs, const line<T> &rhs) {
				return is_equal(lhs.a, rhs.a) && is_equal(lhs.b, rhs.b) && is_equal(lhs.c, rhs.c);
			};

			inline friend bool operator!=(const line<T> &lhs, const line<T> &rhs) { return !(lhs == rhs); };
		private:
			inline std::pair<std::pair<T, T>, T> as_pair() const { return {{a, b}, c}; }
		};

		template<typename T>
		struct point {
			T x, y;

			inline friend point<T> operator+(const point<T> &lhs, const point<T> &rhs) {
				return {lhs.x + rhs.x, lhs.y + rhs.y};
			}

			inline friend point<T> operator-(const point<T> &lhs, const point<T> &rhs) {
				return {lhs.x - rhs.x, lhs.y - rhs.y};
			}

			inline friend point<T> &operator+=(const point<T> &lhs, const point<T> &rhs) { return lhs = lhs + rhs; }

			inline friend point<T> &operator-=(const point<T> &lhs, const point<T> &rhs) { return lhs = lhs - rhs; }

			inline friend point<T> operator+(const point<T> &lhs, const T &rhs) { return {lhs.x + rhs, lhs.y + rhs}; }

			inline friend point<T> operator-(const point<T> &lhs, const T &rhs) { return {lhs.x - rhs, lhs.y - rhs}; }

			inline friend point<T> operator*(const point<T> &lhs, const T &rhs) { return {lhs.x * rhs, lhs.y * rhs}; }

			inline friend point<T> operator/(const point<T> &lhs, const T &rhs) { return {lhs.x / rhs, lhs.y / rhs}; }

			inline friend point<T> &operator+=(const point<T> &lhs, const T &rhs) { return lhs = lhs + rhs; }

			inline friend point<T> &operator-=(const point<T> &lhs, const T &rhs) { return lhs = lhs - rhs; }

			inline friend point<T> &operator*=(const point<T> &lhs, const T &rhs) { return lhs = lhs * rhs; }

			inline friend point<T> &operator/=(const point<T> &lhs, const T &rhs) { return lhs = lhs / rhs; }

			inline friend bool operator<(const point<T> &lhs, const point<T> &rhs) {
				return lhs.as_pair() < rhs.as_pair();
			};

			inline friend bool operator==(const point<T> &lhs, const point<T> &rhs) {
				return is_equal(lhs.x, rhs.x) && is_equal(lhs.y, rhs.y);
			};

			inline friend bool operator!=(const point<T> &lhs, const point<T> &rhs) { return !(lhs == rhs); };

			inline static line<T> get_line(const point<T> &lhs, const point<T> &rhs) {
				

				

				

				

				T a = lhs.y - rhs.y,
						b = lhs.x - rhs.x;
				assert(a != 0 || b != 0);
				T c = b * rhs.y - a * rhs.x;
				b *= -1;
				T g = gcd(gcd(std::abs(a), std::abs(b)), std::abs(c));
				if (a < 0 || (a == 0 && b < 0)) g *= -1;
				line<T> l = {a / g, b / g, c / g};
				assert(l.contains(lhs) && l.contains(rhs));
				return l;
			}

		private:
			template<typename T1>
			static inline T1 gcd(T1 a, T1 b) {
				T t;
				while (a != 0)t = a, a = b % a, b = t;
				return b;
			}

			inline std::pair<T, T> as_pair() const { return {x, y}; }
		};

		template<typename T>
		std::istream &operator>>(std::istream &in, point<T> &lhs) {
			in >> lhs.x >> lhs.y;
			return in;
		}

	}
}

using mi = math::mod_int;


using namespace std;

struct node {
    int ind;
    int l, m, r;
    int dif;
    int ma;
};

node nodes[2100000];

void update_down(int i) {
    if (nodes[i].l == nodes[i].r) {
        return;
    }
    int dif = nodes[i].dif;
    if (dif != 0) {
        nodes[i * 2].ma += dif;
        nodes[i * 2].dif += dif;
        nodes[i * 2 + 1].ma += dif;
        nodes[i * 2 + 1].dif += dif;
        nodes[i].dif = 0;
    }
}

void init(int i, int l, int r, vi &pre) {
    nodes[i].ind = i;
    nodes[i].l = l;
    nodes[i].r = r;
    int m = l + r;
    m /= 2;
    nodes[i].m = m;

    if (l != r) {
        init(i * 2, l, m, pre);
        init(i * 2 + 1, m + 1, r, pre);
        nodes[i].ma = max(nodes[i * 2].ma, nodes[i * 2 + 1].ma);
    } else {
        nodes[i].ma = pre[l];
    }
}

void add(int ind, const int l1, const int r1, const int v) {
    if (l1 > nodes[ind].r || r1 < nodes[ind].l) return;
    if (l1 <= nodes[ind].l && r1 >= nodes[ind].r) {
        nodes[ind].dif += v;
        nodes[ind].ma += v;
    } else {
        update_down(ind);
        if (r1 > nodes[ind].m) {
            add(ind * 2 + 1, l1, r1, v);
        }
        if (l1 <= nodes[ind].m) {
            add(ind * 2, l1, r1, v);
        }
        nodes[ind].ma = max(nodes[ind * 2].ma, nodes[ind * 2 + 1].ma);
    }
}

int max_index_positive(int ind) {
    if (nodes[ind].ma > 0) {
        if (nodes[ind].l == nodes[ind].r) {
            return nodes[ind].l;
        } else {
            update_down(ind);
            if (nodes[ind * 2 + 1].ma > 0) return max_index_positive(ind * 2 + 1);
            return max_index_positive(ind * 2);
        }
    } else {
        return -1;
    }
}

class CSergeAndDiningRoom {
    class Solver {
    public:
        io::input_reader in;
        io::output_writer out;

        Solver(std::istream &in, std::ostream &out) : in(in), out(out) {}

        void solve() {
            int n, m;
            in.read(n, m);
            vi a(n);
            in >> a;
            vi b(m);
            in >> b;

            {
                vi pre(1000101);
                fori(i, n) pre[a[i]] += 1;
                fori(i, m) pre[b[i]] += -1;
                repr(i, 1000100 - 1, 0) pre[i] += pre[i + 1];

                init(1, 0, 1000100, pre);
            }

            int q;
            in >> q;
            fori(i__, q) {
                int ty, i, x;
                in.read(ty, i, x);
                i--;
                int change;
                int old;
                if (ty == 1) {
                    old = a[i];
                    a[i] = x;
                    change = 1;
                } else {
                    old = b[i];
                    b[i] = x;
                    change = -1;
                }
                if (old < x) {
                    add(1, old + 1, x, change);
                } else if (old > x) {
                    add(1, x + 1, old, -change);
                }
                out.println(max_index_positive(1));
            }
        }
    };

public:
    void solve(std::istream &in, std::ostream &out) {
        Solver(in, out).solve();
    }
};

int main() {
	std::ios_base::sync_with_stdio(false), cin.tie(0);
	CSergeAndDiningRoom solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
