#pragma once

#ifndef PRE


#if 0
#define REALGCC
#endif
#ifdef REALGCC
#include <bits/extc++.h>
#else
#if 0
#include <algorithm>
#include <cassert>
#include <chrono>
#include <climits>
#include <complex>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#endif
#ifndef DEBUG
#define NDEBUG
#endif




#include <algorithm>
#include <bitset>


#define __cplusplus -1UL
#include <bit>
#define __cplusplus 201703L


#include <cassert>
#include <chrono>
#include <climits>
#include <complex>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <thread>
#include <type_traits>
#include <unordered_set>
#include <utility>
#include <vector>
#endif
#if __has_include(<source_location>)
#include <source_location>
#else
#include <experimental/source_location>
#endif
#include <experimental/iterator>
#endif 

#define PRE 1
# 1 "a.cpp"
# 1 "/home/ram/OmniTemplate/tools/../src/core/main.hpp" 1


       
# 1 "/home/ram/OmniTemplate/tools/../src/core/all.hpp" 1
       




































































#define fo(i,...) for ([[maybe_unused]] const auto i : ra{__VA_ARGS__})
#define fr(i,...) for ([[maybe_unused]] const auto i : rev(ra{__VA_ARGS__}))
#define al(v) begin(v), end(v)
bool debug_mode = false;


#define rel_assert(...) s
#define WARN(msg) [[deprecated(msg)]] auto warn = []() { rel_assert(msg); }; warn();


#define TODO(msg) WARN("TODO: " msg)
#define paste2(x,y) x ##y
#define paste(x,y) paste2(x, y)
#define lets_count lets_add paste(_l, __COUNTER__)
#define let(a,...) using a = __VA_ARGS__; lets_count{#__VA_ARGS__, #a};


#define import(a) using namespace a; lets_count{#a "::", ""};



#define cerr() if (false) cerr



using namespace std;
vector<pair<string, string>> lets{
    {"__debug::", ""}, {"const ", ""}, {"__cxx11::basic_string<char>", "string"}};
struct lets_add {
	lets_add(const string &a, const string &b) { lets.push_back({a, b}); }
};




using std::priority_queue;
import(std);


using experimental::make_ostream_joiner;
using experimental::ostream_joiner;
using experimental::source_location;
import(chrono);
import(literals);
import(placeholders) let(ull, unsigned long long);


let(ll, long long);
let(ld, long double);
let(pr, pair<ll, ll>);
let(com, complex<double>);
let(point, complex<ll>);
let(ull, unsigned long long);
template <typename T, typename Comp> using prio_queue_t = std::priority_queue<T, vector<T>, Comp>;
let(clock_, high_resolution_clock);
import(this_thread);






constexpr auto inf = ll(numeric_limits<ll>::max()) / 8; 
const auto delim = ", "s;				
constexpr auto tau = 2 * 3.1415926535897932384626433L;	

# 1 "/home/ram/OmniTemplate/tools/../src/core/debug.hpp" 1
       
# 1 "/home/ram/OmniTemplate/tools/../src/core/operations.hpp" 1
       
# 1 "/home/ram/OmniTemplate/tools/../src/core/range.hpp" 1
       

template <typename T> struct it_base {
	using value_type = T;
	using pointer = T *;
	using reference = T &;
	using difference_type = ll;
};
template <typename T> struct int_it : it_base<T> {
	using iterator_category = random_access_iterator_tag;
	T x, m;
	template <typename Integer> int_it(Integer x_, T m_ = 1) : x(x_), m(m_) {}
	int_it() {}
	auto &operator*() const {
		static T x_stat;
		return x_stat = x;
	}
	explicit operator auto() const { return x; }
	int_it operator+(ll y) const { return x + m * y; }
	int_it operator-(ll y) const { return x - m * y; }
	ll operator-(int_it<T> const &y) const { return (x - y.x) / m; }
	int_it operator++() { return x += m; }
	int_it operator--() { return x -= m; }
	int_it operator--(int) {
		auto ret = x;
		--x;
		return ret;
	}
	int_it operator++(int) {
		auto ret = x;
		++x;
		return ret;
	}
};
#define bin(op,Tp) auto operator op(Tp const &a, Tp const &b) { return a.x op b.x; }

template <typename T> bin(==, int_it<T>);
template <typename T> bin(<, int_it<T>);

template <typename T> struct range {
	T bg, ed;
	explicit range(T ed_) : range(0LL, ed_) {}
	range(T const &bg_, T const &ed_)
	    

	    : bg(bg_), ed(ed_) {}
	auto begin() const { return bg; }
	auto end() const { return ed; }
	explicit operator ll() { return ed - bg; }
};
template <typename T> auto operator<(range<T> const &a, range<T> const &b) {
	return a.bg == b.bg ? a.ed > b.ed : a.bg < b.bg;
}
template <typename T> auto operator&(range<T> const &a, range<T> const &b) {
	return range<T>{max(a.bg, b.bg), min(a.ed, b.ed)};
}
template <typename Range> auto rev(const Range &r) {
	using rev_it = reverse_iterator<decltype(begin(r))>;
	return range{rev_it{end(r)}, rev_it{begin(r)}};
}
using ra = range<int_it<ll>>;
template <typename T> int_it<T> operator+(int_it<T> const &a, int_it<T> const &b) {
	return a.x + b.x;
}
template <typename T> int_it<T> operator-(int_it<T> const &a) { return -a.x; }
enum isect { null, dis, over, cont, eq };
template <typename T1, typename T2> auto intersect(const T1 &a, const T2 &b) {
	if (a == b) {
		return isect::eq;
	}
	if (a[1] <= b[0]) {
		return isect::dis;
	}
	if (a[0] <= b[0] && b[1] <= a[1]) {
		return isect::cont;
	}
	if (a[0] <= b[0] && a[1] <= b[1]) {
		return isect::over;
	}
	return isect::null;
}
template <typename T> auto operator^(range<T> const &a, range<T> const &b) {
	return max(intersect(a, b), intersect(b, a));
}
auto filter(vector<ra> &v) {
	sort(al(v));
	vector<ra> sg;
	for (const auto &p : v) {
		if (sg.empty() || sg.back().ed < p.ed) {
			sg.push_back(p);
		}
	}
}
# 3 "/home/ram/OmniTemplate/tools/../src/core/operations.hpp" 2


#define aug(op) template <typename T1, typename T2> auto operator op ##=(T1 &a, const T2 &b) { return a = a op b; }



aug(+);
aug(-);
aug(*);
aug(/);
template <typename T> enable_if_t<is_floating_point_v<T>, T> invert(multiplies<>, const T &x) {
	return 1 / x;
}
template <typename Group> Group operator/(Group const &a, Group const &b) {
	return a * invert(multiplies{}, b);
}
template <typename T1, typename T2> auto constexpr operator-(const T1 &a, const T2 &b) {
	return a + -b;
}
template <typename T1, typename T2> auto constexpr operator!=(const T1 &a, const T2 &b) {
	return !(a == b);
}
template <typename T1, typename T2> auto operator<=(const T1 &a, const T2 &b) { return !(b < a); }
template <typename T1, typename T2> auto operator>=(const T1 &a, const T2 &b) { return b <= a; }
template <typename T1, typename T2> auto operator>(const T1 &a, const T2 &b) { return b < a; }
unordered_map<ll, ll> operator+(unordered_map<ll, ll> a, unordered_map<ll, ll> const &b) {
	for (const auto &p : b) {
		a[p.first] += p.second;
	}
	return a;
}

template <typename T> auto operator|(unordered_set<T> const &a, unordered_set<T> const &b) {
	const auto &[sm, bg] = minmax(a, b);
	auto ret = bg;
	ret.insert(al(sm));
	return ret;
};
template <typename T> auto operator&(unordered_set<T> const &a, unordered_set<T> const &b) {
	const auto &[sm, bg] = minmax(a, b);
	unordered_set<T> ret;
	for (const auto &x : sm) {
		if (bg.count(x)) {
			ret.insert(x);
		}
	}
	return ret;
}
template <typename T>
auto sub_set(unordered_set<T> const &a, unordered_set<T> const &b, unordered_set<T> &ret) {
	for (const auto &x : a) {
		if (!b.count(x)) {
			ret.insert(x);
		}
	}
	return ret;
}
template <typename T> auto operator-(unordered_set<T> const &a, unordered_set<T> const &b) {
	unordered_set<T> ret;
	return sub_set(a, b, ret);
}
template <typename T> auto operator^(unordered_set<T> const &a, unordered_set<T> const &b) {
	unordered_set<T> ret = a - b;
	sub_set(b, a, ret);
	return ret;
}
template <typename T> auto operator*(vector<T> a, vector<T> b) {
	assert(a.size() == b.size());
	vector<T> c(a.size());
	fo(i, a.size()) { c[i] = a[i] * b[i]; }
	return c;
}
template <typename Iterator>
auto operator+(Iterator it,
	       enable_if_t<!is_same<typename iterator_traits<decltype(it)>::iterator_category,
				    random_access_iterator_tag>::value,
			   ll>
		   n) {
	advance(it, n);
	return it;
}

#define FUNCTOR(name,func) struct name { template <typename... Ts> decltype(auto) operator()(Ts &&...args) const { return (func)(forward<decltype(args)>(args)...); } }





FUNCTOR(Max, max);
FUNCTOR(Min, min);
template <typename T, typename = enable_if_t<is_arithmetic_v<T>>> T identity(plus<>, T) {
	return 0;
}
template <typename T, typename = enable_if_t<is_arithmetic_v<T>>> T identity(multiplies<>, T) {
	return 1;
}
template <typename T, typename = enable_if_t<is_integral_v<T>>> T identity(bit_xor<>, T) {
	return {};
}
ll identity(Max, ll) { return -inf; }
ll identity(Min, ll) { return inf; }






# 3 "/home/ram/OmniTemplate/tools/../src/core/debug.hpp" 2






#define dbg(x) (x)


namespace debug_tools {
template <typename T> auto type_name([[maybe_unused]] T const &v) {
	
	string s = __PRETTY_FUNCTION__, tar = "T = ";
	auto st = s.find(tar) + tar.size();
	return s.substr(st, s.find("]", st) - st);
}
auto replace(string s, const string &a, const string &b) {
	
	

	ll loc;
	while ((loc = s.find(a)) != string::npos) {
		s = s.substr(0, loc) + b + s.substr(loc + a.size());
	}
	return s;
}
template <typename T> auto simple_tp([[maybe_unused]] const T &v) {
	
	auto s = type_name(v);
	for (const auto &p : lets) {
		s = replace(s, p.first, p.second);
	}
	return s;
}
constexpr auto light_purple_color = "\e[1;35m"sv;
constexpr auto green_color = "\e[1;32m"sv;
constexpr auto red_color = "\e[91m"sv;
constexpr auto reset_color = "\e[0m"sv;
ll depth = -1;
template <typename T>
auto debug(const T &x, const string &name,
	   source_location const &loc = source_location::current()) {
	
	if (debug_mode) {
		fo(i, depth) { cerr << "\t"; }
		cerr << red_color << loc.function_name() << ":" << loc.line() << " " << name
		     << " = " << x << reset_color << endl;
	}
	--depth;
	return x;
}
} 

using namespace debug_tools;
# 134 "/home/ram/OmniTemplate/tools/../src/core/all.hpp" 2
# 1 "/home/ram/OmniTemplate/tools/../src/core/io.hpp" 1
       


struct rin {
	istream &in;
	rin(istream &in_) : in(in_) {}
	auto &operator<<(const char *) { return *this; }
	auto &operator<<(string const &s) {
		if (s.empty()) {
			in >> const_cast<string &>(s);
		}
		return *this;
	}
	template <typename T> rin &operator>>(T &x) { return *this << x; }
};
template <typename R, typename T>
auto operator<<(R &r, const T &x)
    -> decltype(r.in >> const_cast<T &>(x), declval<enable_if_t<is_same<R, rin>::value, rin &>>()) {
	r.in >> const_cast<T &>(x);
	return r;
}
template <typename Stream, typename T>
enable_if_t<is_same<T, istream>::value, rin> operator>>(Stream &is, T &x) {
	rin r{is};
	return r >> x;
}
template <typename Stream, typename Tuple, auto size = std::tuple_size<Tuple>::value> auto& operator<<(Stream &os, const Tuple& tuple) {
	os << simple_tp(tuple) << "{";
	apply(
	    [&](auto &f, auto &... x) {
		    os << f;
		    ((os << delim << x), ...);
	    },
	    tuple);
	return os << "}";
}
template <typename T1, typename... Ts> auto print(const T1 &arg1, const Ts &... args) {
	
	cout << arg1;
	((cout << " " << args), ...);
	cout << endl;
}
namespace std {




template <typename Stream, typename Container>
auto operator<<(Stream &os, const Container &v)
    -> enable_if_t<is_same_v<Stream, ostream>, decltype(begin(v), declval<decltype(os)>())> {
	auto ed = begin(v);
	auto big = v.size() > 20;
	if (big) {
		advance(ed, 20);
	} else {
		ed = end(v);
	}
	os << simple_tp(v) << "{";
	copy(begin(v), ed, make_ostream_joiner(os, delim));
	if (big) {
		os << delim << "...";
	}
	return os << "}";
}
template <typename T>
auto operator<<(rin &os, const T &v) -> decltype(begin(v), declval<decltype(os)>()) {
	for (const auto &elem : v) {
		os << elem;
	}
	return os;
}
template <typename Stream, typename T> auto &operator<<(Stream &os, optional<T> const &opt) {
	return opt ? (os << *opt) : (os << "nullopt");
}


rin rin_cin{cin};
auto &orig_cin = cin;
auto &orig_cerr = cerr;
#define cin rin_cin
} 

# 135 "/home/ram/OmniTemplate/tools/../src/core/all.hpp" 2


# 1 "/home/ram/OmniTemplate/tools/../src/core/utility.hpp" 1
       

namespace utility {

template <typename T> struct [[nodiscard]] with {
	T old; 

	T &v;  

	template <typename Tp> with(const Tp new_, T &v_) : old(v_), v(v_) { v = new_; }
	~with() { v = old; }
};

template <typename Func> struct fix {
	Func func;
	fix(const Func &func_) : func(func_) {}
	template <typename... Args> decltype(auto) operator()(Args &&... args) const {
		return func(*this, forward<Args>(args)...);
	}
};
#define LAMBDA_IMPL(f) (auto &&...args) -> decltype(auto) { return f(forward<decltype(args)>(args)...); }
#define LAMBDA(f) [&] LAMBDA_IMPL(f)
#define LAMBDA_THIS(f) [&, this] LAMBDA_IMPL(f)
#define DEFINE_FUNC_EQ(func) template <typename T> void func ##_eq(T &x, const T &y) { x = func(x, y); }


DEFINE_FUNC_EQ(min);

DEFINE_FUNC_EQ(max);

template <typename T> auto cache(const T &f) {
	T ch;
	return [=](const auto &arg) mutable {
		if (ch.find(arg) == end(ch)) {
			return ch[arg] = f(arg);
		}
		return ch[arg];
	};
}

template <typename Eq = equal_to<>, typename T = less<>, typename Cont>
[[nodiscard]] auto uniq(Cont v, Eq const &up = Eq{}, T const &sp = T{}) {
	sort(al(v), sp);
	v.resize(unique(al(v), up) - begin(v));
	return v;
}

template <typename Compare = less<>, typename Func>
auto key_compare(const Func &func, const Compare &compare = {}) {
	return [=](auto &&... args) -> decltype(auto) {
		return compare(func(forward<decltype(args)>(args))...);
	};
}
template <typename T> auto prev_less(const T &v) {
	ll n = v.size();
	vector<ll> l(n, -1);
	stack<ll> s;
	fo(i, n) {
		while (s.size() && !(s.top() < v[i])) {
			s.pop();
		}
		if (s.size()) {
			l[i] = s.top();
		}
		s.push(v[i]);
	}
	return l;
}

ll bit_ceil(ll x) {
	if (x <= 1) {
		return 1;
	}
	return 1LL << (sizeof(ll) * CHAR_BIT - __builtin_clzll(x - 1));
}



ll power_ceil(const ll x, const ll base) {
	ll pw = 1;
	for (; pw < x; pw *= base)
		;
	return pw;
}

ll log_ceil(const ll x, const ll base) {
	ll pw = 1, cnt = 0;
	for (; pw < x; pw *= base, ++cnt)
		;
	return cnt;
}

[[nodiscard]] ll next_comb(ll x) {
	ll tz = __builtin_ctzll(x);
	ll y = x + (ll{1} << tz);
	const auto ret = y | (y ^ x) >> (2 + tz);
	assert(ret > x);
	assert(__builtin_popcountll(ret) == __builtin_popcountll(x));
	return ret;
}

class IdentityFunctor {
      public:
	template <typename T> decltype(auto) operator()(T &&x) const { return std::forward<T>(x); }
};


template <typename T, typename Func = IdentityFunctor>
void sort2(T &a, T &b, const Func &func = {}) {
	if (func(a) > func(b)) {
		swap(a, b);
	}
}

template <typename Iter, typename Proj>
void counting_sort(Iter a, Iter b, const Proj &proj, const ll proj_size) {
	range rang{a, b};
	vector<ll> count(proj_size);
	for (const auto &x : rang) {
		++count[proj(x)];
	}
	ll sum = 0;
	for (auto &cnt : count) {
		const auto old_cnt = cnt;
		cnt = sum;
		sum += old_cnt;
	}
	vector<typename Iter::value_type> output(b - a);
	for (const auto &x : rang) {
		output[count[proj(x)]] = x;
		++count[proj(x)];
	}
	move(al(output), a);
}

template <typename Cont> ll ssize(const Cont &cont) { return size(cont); }



template <typename T> struct ar { using type = T; };
template <typename T> using ar_t = typename ar<T>::type;
template <typename T, ll n> struct ar<T[n]> { using type = array<ar_t<T>, n>; };

struct random_device_patch {
	unsigned int operator()() { return clock_::now().time_since_epoch().count(); }
	double entropy() { return 0.0; }
};
struct Empty {};
#define USE_RANDOM_DEVICE_PATCH 

using random_device = random_device_patch;

default_random_engine reng{random_device{}()};
template <typename Compare = less<>> class chained_compare {
      public:
	chained_compare(const Compare &comp_ = {}) : comp{comp_} {}
	template <typename T1, typename T2, typename... Ts>
	bool operator()(const T1 &arg1, const T2 &arg2, const Ts &...args) {
		return comp(arg1, arg2) && (*this)(arg2, args...);
	}
	template <typename T1> bool operator()(const T1 &arg1) { return true; }

      private:
	Compare comp;
};

template <typename T> bool valid_idx(const vector<T> &vec, const size_t idx) {
	return idx < vec.size();
}
template <typename InputIt> auto iterator_identity() {
	return identity(plus<>{}, typename InputIt::value_type{});
};
template <typename InputIt> decltype(auto) accumulate(InputIt a, InputIt b) {
	return accumulate(a, b, iterator_identity<InputIt>());
}
template <typename InputIt> decltype(auto) inner_product(InputIt a, InputIt b, InputIt c) {
	return inner_product(a, b, c, iterator_identity<InputIt>());
}
template <typename InputIt, typename Op = plus<>> auto get_partial_sum(InputIt a, InputIt b, const Op& op = {}) {
	vector sums(distance(a, b) + 1, identity(op, typename InputIt::value_type{}));
	partial_sum(a, b, begin(sums) + 1, op);
	return sums;
}
template <typename... Ts> decltype(auto) read(Ts &...args) { return (std::cin >> ... >> args); }
} 

using namespace utility;
# 138 "/home/ram/OmniTemplate/tools/../src/core/all.hpp" 2
# 4 "/home/ram/OmniTemplate/tools/../src/core/main.hpp" 2
# 1 "/home/ram/OmniTemplate/tools/../src/core/time.hpp" 1
       

namespace time_tools {
struct timer {
	
	decltype(clock_::now()) t1;
	timer() : t1(clock_::now()) {}
	~timer() {
		cerr << "Time duration: " << duration<ld>(clock_::now() - t1).count() << " s"
		     << endl;
	}
};
template <typename Func> void bench(Func a) {
	timer _t;
	decltype(a) ans = 0;
	for (decltype(a) i = 0; i < a; ++i) {
		for (decltype(a) j = 1; j < a; ++j) {
			ans += ((-i) % (j));
		}
	}
	

	const auto volatile _unused = ans;
}
} 

using namespace time_tools;
# 5 "/home/ram/OmniTemplate/tools/../src/core/main.hpp" 2

string yesno(const bool b) { return b ? "Yes" : "No"; }

struct set_multitest {
	inline static bool multitest{};
	explicit set_multitest(const bool val = true) { multitest = val; }
};
extern void main2();
int main(int argc, char *argv[]) {



	fo(i, argc) {
		if (argv[i] == "-q"s) {
			debug_mode = false;
		}
	}
	ios::sync_with_stdio(false);
	if (!debug_mode) {
		cerr.rdbuf(nullptr);
	}
	for (ios &os : initializer_list<reference_wrapper<ios>>{orig_cin, cout, orig_cerr, clog}) {
		fixed(os);
		if (os.rdbuf()) {
			os.exceptions(ios::failbit | ios::badbit | ios::eofbit);
		}
		os.precision(false ? numeric_limits<ld>::max_digits10 : 5);
	}
	cout.precision(numeric_limits<ld>::max_digits10);
	timer _t;
	if (set_multitest::multitest) {
		ll t;
		cin >> t;
		fo(i, t) {
			if(debug_mode){
				cerr << light_purple_color << "=== Test case #" << 1 + i << " ===" << reset_color << endl;
			}
			main2();
		}
	} else {
		main2();
	}
}
# 2 "a.cpp" 2
# 1 "/home/ram/OmniTemplate/tools/../src/utility/abbrev.hpp" 1
       


#define I(...) ll __VA_ARGS__; read(__VA_ARGS__)


#define pb push_back
#define vc vector
#define endl '\n'
let(vl, vector<ll>);
let(bt, bitset<numeric_limits<ll>::digits>);
let(um, unordered_map<ll, ll>);
let(ar2, array<ll,2>);
# 3 "a.cpp" 2
set_multitest _{true};
void main2(){
	I(a);I(b);
	const ll sz = 3e5+10;
	set<ll> s;
	fo(_z,0,2){
		ll lo = (a+b)/2;
		ll hi = (a+b+1)/2;
		ll st = a+b - (min(hi,b)+min(lo,a));
		ll ed = min(hi,a)+min(lo,b);
		dbg(st);dbg(ed);
		for(ll i = st; i <= ed; i+=2){
			s.insert(i);
		}
		swap(a,b);
	}
	
	cout<<s.size()<<endl;
	for(auto x:s){
		cout<<x<<" ";
	}
	cout<<endl;
}
	
