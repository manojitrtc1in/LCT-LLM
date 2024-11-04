#include <bits/stdc++.h>
#pragma region template
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define rrep(i, n) for (int i = (n)-1; i >= 0; --i)
#define rfor(i, m, n) for (int i = (m); i >= (n); --i)
#define unless(c) if (!(c))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define range_it(a, l, r) (a).begin() + (l), (a).begin() + (r)

using namespace std;
using ll = long long;
using LD = long double;
using VB = vector<bool>;
using VVB = vector<VB>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using VS = vector<string>;
using VD = vector<LD>;
using PII = pair<int, int>;
using VP = vector<PII>;
using PLL = pair<ll, ll>;
using VPL = vector<PLL>;
template <class T> using PQ = priority_queue<T>;
template <class T> using PQS = priority_queue<T, vector<T>, greater<T>>;
constexpr int inf = 1e9;
constexpr long long inf_ll = 1e18, MOD = 1000000007;
constexpr long double PI = 3.14159265358979323846, EPS = 1e-12;



#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#define fwrite_unlocked fwrite
#define fflush_unlocked fflush
#endif
class Input {
	static int gc() {
		return getchar_unlocked();
	}
	template <class T> static void i(T& v) {
		cin >> v;
	}
	static void i(char& v) {
		while (isspace(v = gc()))
			;
	}
	static void i(bool& v) {
		v = in<char>() != '0';
	}
	static void i(string& v) {
		v.clear();
		char c;
		for (i(c); !isspace(c); c = gc())
			v += c;
	}
	static void i(int& v) {
		bool neg = false;
		v = 0;
		char c;
		i(c);
		if (c == '-') {
			neg = true;
			c = gc();
		}
		for (; isdigit(c); c = gc())
			v = v * 10 + (c - '0');
		if (neg) v = -v;
	}
	static void i(long long& v) {
		bool neg = false;
		v = 0;
		char c;
		i(c);
		if (c == '-') {
			neg = true;
			c = gc();
		}
		for (; isdigit(c); c = gc())
			v = v * 10 + (c - '0');
		if (neg) v = -v;
	}
	static void i(double& v) {
		double dp = 1;
		bool neg = false, adp = false;
		v = 0;
		char c;
		i(c);
		if (c == '-') {
			neg = true;
			c = gc();
		}
		for (; isdigit(c) || c == '.'; c = gc()) {
			if (c == '.')
				adp = true;
			else if (adp)
				v += (c - '0') * (dp *= 0.1);
			else
				v = v * 10 + (c - '0');
		}
		if (neg) v = -v;
	}
	static void i(long double& v) {
		long double dp = 1;
		bool neg = false, adp = false;
		v = 0;
		char c;
		i(c);
		if (c == '-') {
			neg = true;
			c = gc();
		}
		for (; isdigit(c) || c == '.'; c = gc()) {
			if (c == '.')
				adp = true;
			else if (adp)
				v += (c - '0') * (dp *= 0.1);
			else
				v = v * 10 + (c - '0');
		}
		if (neg) v = -v;
	}
	template <class T, class U> static void i(pair<T, U>& v) {
		i(v.first);
		i(v.second);
	}
	template <class T> static void i(vector<T>& v) {
		for (auto& e : v)
			i(e);
	}
	template <size_t N = 0, class T> static void input_tuple(T& v) {
		if constexpr (N < tuple_size_v<T>) {
			i(get<N>(v));
			input_tuple<N + 1>(v);
		}
	}
	template <class... T> static void i(tuple<T...>& v) {
		input_tuple(v);
	}
	struct InputV {
		int n, m;
		InputV(int _n) : n(_n), m(0) {}
		InputV(const pair<int, int>& nm) : n(nm.first), m(nm.second) {}
		template <class T> operator vector<T>() {
			vector<T> v(n);
			i(v);
			return v;
		}
		template <class T> operator vector<vector<T>>() {
			vector<vector<T>> v(n, vector<T>(m));
			i(v);
			return v;
		}
	};

public:
	static string read_line() {
		string v;
		char c;
		for (i(c); c != '\n' && c != '\0'; c = gc())
			v += c;
		return v;
	}
	template <class T> static T in() {
		T v;
		i(v);
		return v;
	}
	template <class T> operator T() const {
		return in<T>();
	}
	int operator--(int) const {
		return in<int>() - 1;
	}
	InputV operator[](int n) const {
		return InputV(n);
	}
	InputV operator[](const pair<int, int>& n) const {
		return InputV(n);
	}
	void operator()() const {}
	template <class H, class... T> void operator()(H&& h, T&&... t) const {
		i(h);
		operator()(forward<T>(t)...);
	}

private:
	template <template <class...> class, class...> struct Multiple;
	template <template <class...> class V, class Head, class... Tail> struct Multiple<V, Head, Tail...> {
		template <class... Args> using vec = V<vector<Head>, Args...>;
		using type = typename Multiple<vec, Tail...>::type;
	};
	template <template <class...> class V> struct Multiple<V> { using type = V<>; };
	template <class... T> using multiple_t = typename Multiple<tuple, T...>::type;
	template <size_t N = 0, class T> void in_multiple(T& t) const {
		if constexpr (N < tuple_size_v<T>) {
			auto& vec = get<N>(t);
			using V = typename remove_reference_t<decltype(vec)>::value_type;
			vec.push_back(in<V>());
			in_multiple<N + 1>(t);
		}
	}

public:
	template <class... T> auto multiple(int H) const {
		multiple_t<T...> res;
		while (H--)
			in_multiple(res);
		return res;
	}
} in;
#define input(T) Input::in<T>()
#define INT input(int)
#define LL input(long long)
#define STR input(string)
#define inputs(T, ...) \
	T __VA_ARGS__;     \
	in(__VA_ARGS__)
#define ini(...) inputs(int, __VA_ARGS__)
#define inl(...) inputs(long long, __VA_ARGS__)
#define ins(...) inputs(string, __VA_ARGS__)



struct BoolStr {
	const char *t, *f;
	BoolStr(const char* _t, const char* _f) : t(_t), f(_f) {}
} Yes("Yes", "No"), yes("yes", "no"), YES("YES", "NO"), Int("1", "0");
struct DivStr {
	const char *d, *l;
	DivStr(const char* _d, const char* _l) : d(_d), l(_l) {}
} spc(" ", "\n"), no_spc("", "\n"), end_line("\n", "\n"), comma(",", "\n"), no_endl(" ", "");
class Output {
	BoolStr B{Yes};
	DivStr D{spc};
	void p(int v) const {
		char buf[12]{};
		if (auto [ptr, e] = to_chars(begin(buf), end(buf), v); e == errc{}) {
			fwrite(buf, sizeof(char), ptr - buf, stdout);
		} else {
			assert(false);
		}
	}
	void p(long long v) const {
		char buf[21]{};
		if (auto [ptr, e] = to_chars(begin(buf), end(buf), v); e == errc{}) {
			fwrite(buf, sizeof(char), ptr - buf, stdout);
		} else {
			assert(false);
		}
	}
	void p(bool v) const {
		p(v ? B.t : B.f);
	}
	void p(char v) const {
		putchar_unlocked(v);
	}
	void p(const char* v) const {
		fwrite_unlocked(v, 1, strlen(v), stdout);
	}
	void p(double v) const {
		printf("%.20f", v);
	}
	void p(long double v) const {
		printf("%.20Lf", v);
	}
	template <class T> void p(const T& v) const {
		cout << v;
	}
	template <class T, class U> void p(const pair<T, U>& v) const {
		p(v.first);
		p(D.d);
		p(v.second);
	}
	template <class T> void p(const vector<T>& v) const {
		rep(i, sz(v)) {
			if (i) p(D.d);
			p(v[i]);
		}
	}
	template <class T> void p(const vector<vector<T>>& v) const {
		rep(i, sz(v)) {
			if (i) p(D.l);
			p(v[i]);
		}
	}

public:
	Output& operator()() {
		p(D.l);
		return *this;
	}
	template <class H> Output& operator()(H&& h) {
		p(h);
		p(D.l);
		return *this;
	}
	template <class H, class... T> Output& operator()(H&& h, T&&... t) {
		p(h);
		p(D.d);
		return operator()(forward<T>(t)...);
	}
	template <class It> Output& range(const It& l, const It& r) {
		for (It i = l; i != r; i++) {
			if (i != l) p(D.d);
			p(*i);
		}
		p(D.l);
		return *this;
	}
	template <class T> Output& range(const T& a) {
		range(a.begin(), a.end());
		return *this;
	}
	template <class... T> void exit(T&&... t) {
		operator()(forward<T>(t)...);
		std::exit(EXIT_SUCCESS);
	}
	Output& flush() {
		fflush_unlocked(stdout);
		return *this;
	}
	Output& set(const BoolStr& b) {
		B = b;
		return *this;
	}
	Output& set(const DivStr& d) {
		D = d;
		return *this;
	}
	Output& set(const char* t, const char* f) {
		B = BoolStr(t, f);
		return *this;
	}
} out;



template <class T> struct Step {
	class It {
		T a, b, c;

	public:
		constexpr It() : a(T()), b(T()), c(T()) {}
		constexpr It(T _b, T _c, T _s) : a(_b), b(_c), c(_s) {}
		constexpr It& operator++() {
			--b;
			a += c;
			return *this;
		}
		constexpr It operator++(int) {
			It tmp = *this;
			--b;
			a += c;
			return tmp;
		}
		constexpr const T& operator*() const {
			return a;
		}
		constexpr const T* operator->() const {
			return &a;
		}
		constexpr bool operator==(const It& i) const {
			return b == i.b;
		}
		constexpr bool operator!=(const It& i) const {
			return !(b == i.b);
		}
		constexpr T start() const {
			return a;
		}
		constexpr T size() const {
			return b;
		}
		constexpr T step() const {
			return c;
		}
	};
	constexpr Step(T b, T c, T s) : be(b, c, s) {}
	constexpr It begin() const {
		return be;
	}
	constexpr It end() const {
		return en;
	}
	constexpr T start() const {
		return be.start();
	}
	constexpr T size() const {
		return be.size();
	}
	constexpr T step() const {
		return be.step();
	}
	constexpr T sum() const {
		return start() * size() + step() * (size() * (size() - 1) / 2);
	}
	operator vector<T>() const {
		return to_a();
	}
	auto to_a() const {
		vector<T> res;
		res.reserve(size());
		for (auto i : *this) {
			res.push_back(i);
		}
		return res;
	}
	using value_type = T;
	using iterator = It;

private:
	It be, en;
};
template <class T> inline constexpr auto step(T a) {
	return Step<T>(0, a, 1);
}
template <class T> inline constexpr auto step(T a, T b) {
	return Step<T>(a, b - a, 1);
}
template <class T> inline constexpr auto step(T a, T b, T c) {
	return Step<T>(a, a < b ? (b - a - 1) / c + 1 : 0, c);
}



namespace Ruby {
	template <class F> struct Callable {
		F func;
		Callable(const F& f) : func(f) {}
	};
	template <class T, class F> auto operator|(const T& v, const Callable<F>& c) {
		return c.func(v);
	}

	struct Sort_impl {
		template <class F> auto operator()(F&& f) {
			return Callable([&](auto v) {
				sort(begin(v), end(v), f);
				return v;
			});
		}
		template <class T> friend auto operator|(T v, [[maybe_unused]] const Sort_impl& c) {
			sort(begin(v), end(v));
			return v;
		}
	} Sort;
	struct SortBy_impl {
		template <class F> auto operator()(F&& f) {
			return Callable([&](auto v) {
				sort(begin(v), end(v), [&](const auto& i, const auto& j) {
					return f(i) < f(j);
				});
				return v;
			});
		}
	} SortBy;
	struct RSort_impl {
		template <class F> auto operator()(F&& f) {
			return Callable([&](auto v) {
				sort(rbegin(v), rend(v), f);
				return v;
			});
		}
		template <class T> friend auto operator|(T v, [[maybe_unused]] const RSort_impl& c) {
			sort(rbegin(v), rend(v));
			return v;
		}
	} RSort;
	struct RSortBy_impl {
		template <class F> auto operator()(F&& f) {
			return Callable([&](auto v) {
				sort(begin(v), end(v), [&](const auto& i, const auto& j) {
					return f(i) > f(j);
				});
				return v;
			});
		}
	} RSortBy;
	struct Reverse_impl {
		template <class T> friend auto operator|(T v, const Reverse_impl& c) {
			reverse(begin(v), end(v));
			return v;
		}
	} Reverse;
	struct Unique_impl {
		template <class T> friend auto operator|(T v, const Unique_impl& c) {
			v.erase(unique(begin(v), end(v), end(v)));
			return v;
		}
	} Unique;
	struct Uniq_impl {
		template <class T> friend auto operator|(T v, const Uniq_impl& c) {
			sort(begin(v), end(v));
			v.erase(unique(begin(v), end(v), end(v)));
			return v;
		}
	} Uniq;
	struct Rotate_impl {
		auto operator()(int&& left) {
			return Callable([&](auto v) {
				int s = static_cast<int>(size(v));
				assert(-s <= left && left <= s);
				if (0 <= left) {
					rotate(begin(v), begin(v) + left, end(v));
				} else {
					rotate(begin(v), end(v) + left, end(v));
				}
				return v;
			});
		}
	} Rotate;
	struct Max_impl {
		template <class F> auto operator()(F&& f) {
			return Callable([&](auto v) {
				return *max_element(begin(v), end(v), f);
			});
		}
		template <class T> friend auto operator|(T v, const Max_impl& c) {
			return *max_element(begin(v), end(v));
		}
	} Max;
	struct Min_impl {
		template <class F> auto operator()(F&& f) {
			return Callable([&](auto v) {
				return *min_element(begin(v), end(v), f);
			});
		}
		template <class T> friend auto operator|(T v, const Min_impl& c) {
			return *min_element(begin(v), end(v));
		}
	} Min;
	struct MaxPos_impl {
		template <class T> friend auto operator|(T v, const MaxPos_impl& c) {
			return max_element(begin(v), end(v)) - begin(v);
		}
	} MaxPos;
	struct MinPos_impl {
		template <class T> friend auto operator|(T v, const MinPos_impl& c) {
			return min_element(begin(v), end(v)) - begin(v);
		}
	} MinPos;
	struct MaxBy_impl {
		template <class F> auto operator()(F&& f) {
			return Callable([&](auto v) {
				auto max_it = begin(v);
				auto max_val = f(*max_it);
				for (auto it = next(begin(v)); it != end(v); ++it) {
					if (auto val = f(*it); max_val < val) {
						max_it = it;
						max_val = val;
					}
				}
				return *max_it;
			});
		}
	} MaxBy;
	struct MinBy_impl {
		template <class F> auto operator()(F&& f) {
			return Callable([&](auto v) {
				auto min_it = begin(v);
				auto min_val = f(*min_it);
				for (auto it = next(begin(v)); it != end(v); ++it) {
					if (auto val = f(*it); min_val > val) {
						min_it = it;
						min_val = val;
					}
				}
				return *min_it;
			});
		}
	} MinBy;
	struct MaxOf_impl {
		template <class F> auto operator()(F&& f) {
			return Callable([&](auto v) {
				auto max_val = f(*begin(v));
				for (auto it = next(begin(v)); it != end(v); ++it) {
					if (auto val = f(*it); max_val < val) {
						max_val = val;
					}
				}
				return max_val;
			});
		}
	} MaxOf;
	struct MinOf_impl {
		template <class F> auto operator()(F&& f) {
			return Callable([&](auto v) {
				auto min_val = f(*begin(v));
				for (auto it = next(begin(v)); it != end(v); ++it) {
					if (auto val = f(*it); min_val > val) {
						min_val = val;
					}
				}
				return min_val;
			});
		}
	} MinOf;
	struct Count_impl {
		template <class V> auto operator()(const V& val) {
			return Callable([&](auto v) {
				return count(begin(v), end(v), val);
			});
		}
	} Count;
	struct CountIf_impl {
		template <class F> auto operator()(const F& f) {
			return Callable([&](auto v) {
				return count_if(begin(v), end(v), f);
			});
		}
	} CountIf;
	struct Index_impl {
		template <class V> auto operator()(const V& val) {
			return Callable([&](auto v) -> optional<int> {
				auto res = find(begin(v), end(v), val);
				return res != end(v) ? optional(res - begin(v)) : nullopt;
			});
		}
	} Index;
	struct IndexIf_impl {
		template <class F> auto operator()(const F& f) {
			return Callable([&](auto v) -> optional<int> {
				auto res = find_if(begin(v), end(v), f);
				return res != end(v) ? optional(res - begin(v)) : nullopt;
			});
		}
	} IndexIf;
	struct FindIf_impl {
		template <class F> auto operator()(const F& f) {
			return Callable([&](auto v) -> optional<typename decltype(v)::value_type> {
				auto res = find_if(begin(v), end(v), f);
				return res != end(v) ? optional(*res) : nullopt;
			});
		}
	} FindIf;
	struct Sum_impl {
		template <class F> auto operator()(F&& f) {
			return Callable([&](auto v) {
				return accumulate(next(begin(v)), end(v), f(*begin(v)), [&](const auto& a, const auto& b) {
					return a + f(b);
				});
			});
		}
		template <class T> friend auto operator|(T v, const Sum_impl& c) {
			return accumulate(begin(v), end(v), typename T::value_type());
		}
	} Sum;
	struct Includes {
		template <class V> auto operator()(const V& val) {
			return Callable([&](auto v) {
				return find(begin(v), end(v), val) != end(v);
			});
		}
	} Includes;
	struct IncludesIf_impl {
		template <class F> auto operator()(const F& f) {
			return Callable([&](auto v) {
				return find_if(begin(v), end(v), f) != end(v);
			});
		}
	} IncludesIf;
	struct RemoveIf_impl {
		template <class F> auto operator()(const F& f) {
			return Callable([&](auto v) {
				v.erase(remove_if(begin(v), end(v), f), end(v));
				return v;
			});
		}
	} RemoveIf;
	struct Each_impl {
		template <class F> auto operator()(F&& f) {
			return Callable([&](auto v) {
				for (const auto& i : v) {
					f(i);
				}
			});
		}
	} Each;
	struct Select_impl {
		template <class F> auto operator()(F&& f) {
			return Callable([&](auto v) {
				using value_type = typename decltype(v)::value_type;
				vector<value_type> res;
				for (const auto& i : v) {
					if (f(i)) res.push_back(i);
				}
				return res;
			});
		}
	} Select;
	struct Map_impl {
		template <class F> auto operator()(F&& f) {
			return Callable([&](auto v) {
				using result_type = invoke_result_t<F, typename decltype(v)::value_type>;
				vector<result_type> res;
				res.reserve(size(v));
				for (const auto& i : v) {
					res.push_back(f(i));
				}
				return res;
			});
		}
	} Map;
	struct Indexed_impl {
		template <class T> friend auto operator|(const T& v, Indexed_impl& c) {
			using value_type = typename T::value_type;
			vector<pair<value_type, int>> res;
			res.reserve(size(v));
			int index = 0;
			for (const auto& i : v) {
				res.emplace_back(i, index++);
			}
			return res;
		}
	} Indexed;
	struct AllOf_impl {
		template <class F> auto operator()(F&& f) {
			return Callable([&](auto v) {
				for (const auto& i : v) {
					if (!f(i)) return false;
				}
				return true;
			});
		}
	} AllOf;
	struct AnyOf_impl {
		template <class F> auto operator()(F&& f) {
			return Callable([&](auto v) {
				for (const auto& i : v) {
					if (f(i)) return true;
				}
				return false;
			});
		}
	} AnyOf;
	struct NoneOf_impl {
		template <class F> auto operator()(F&& f) {
			return Callable([&](auto v) {
				for (const auto& i : v) {
					if (f(i)) return false;
				}
				return true;
			});
		}
	} NoneOf;

	template <class T> auto operator*(const vector<T>& a, size_t n) {
		T res;
		for (size_t i = 0; i < n; ++i) {
			res.insert(res.end(), a.begin(), a.end());
		}
		return res;
	}
	auto operator*(string a, size_t n) {
		string res;
		for (size_t i = 0; i < n; ++i) {
			res += a;
		}
		return res;
	}
	template <class T, class U> auto& operator<<(vector<T>& a, const U& b) {
		a.insert(a.end(), all(b));
		return a;
	}
	template <class T> auto& operator<<(string& a, const T& b) {
		a.insert(a.end(), all(b));
		return a;
	}
	template <class T, class U> auto operator+(vector<T> a, const U& b) {
		a << b;
		return a;
	}
	template <class T> auto operator+(string a, const T& b) {
		a << b;
		return a;
	}
}  

using namespace Ruby;



template <class T, class U> inline int Lower(const T& a, const U& v) {
	return lower_bound(all(a), v) - a.begin();
}
template <class T, class U> inline int Upper(const T& a, const U& v) {
	return upper_bound(all(a), v) - a.begin();
}
template <class T> inline auto Slice(const T& v, size_t i, size_t len) {
	return i < v.size() ? T(v.begin() + i, v.begin() + min(i + len, v.size())) : T();
}
template <class T> inline T Ceil(T n, T m) {
	return (n + m - 1) / m;
}
template <class T> inline T Ceil2(T n, T m) {
	return Ceil(n, m) * m;
}
template <class T> inline T Tri(T n) {
	return (n & 1) ? (n + 1) / 2 * n : n / 2 * (n + 1);
}
template <class T> inline T nC2(T n) {
	return (n & 1) ? (n - 1) / 2 * n : n / 2 * (n - 1);
}
template <class T> inline T Mid(const T& l, const T& r) {
	return l + (r - l) / 2;
}
template <class T> inline bool chmax(T& a, const T& b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
template <class T> inline bool chmin(T& a, const T& b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template <class T> inline bool inRange(const T& v, const T& min, const T& max) {
	return min <= v && v < max;
}
template <class T> inline bool isSquere(T n) {
	T s = sqrt(n);
	return s * s == n || (s + 1) * (s + 1) == n;
}
template <class T = long long> inline T BIT(int b) {
	return T(1) << b;
}
template <class T, class U = typename T::value_type> inline U Gcdv(const T& v) {
	return accumulate(next(v.begin()), v.end(), U(*v.begin()), gcd<U, U>);
}
template <class T, class U = typename T::value_type> inline U Lcmv(const T& v) {
	return accumulate(next(v.begin()), v.end(), U(*v.begin()), lcm<U, U>);
}
template <class T> inline T Pow(T a, T n) {
	T r = 1;
	while (n > 0) {
		if (n & 1) r *= a;
		a *= a;
		n /= 2;
	}
	return r;
}
template <class T> inline T Powmod(T a, T n, T m = MOD) {
	T r = 1;
	while (n > 0) {
		if (n & 1)
			r = r * a % m, n--;
		else
			a = a * a % m, n /= 2;
	}
	return r;
}



#if __has_include("dump.hpp")
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif
#pragma endregion




int main() {
	ins(s, t);
	int n = sz(s), m = sz(t);

	VI front(m), back(m);
	int pos = 0;
	rep(i, m) {
		front[i] = s.find(t[i], pos);
		pos = front[i] + 1;
	}
	pos = n - 1;
	rrep(i, m) {
		back[i] = s.rfind(t[i], pos);
		pos = back[i] - 1;
	}

	int ans = max(back.front(), n - 1 - front.back());
	rep(i, m - 1) {
		chmax(ans, back[i + 1] - front[i] - 1);
	}
	out(ans);
}