#include <iostream>
#include <fstream>

#include <iostream>
#include <vector>
#include <array>

#include <type_traits>

template <typename T, size_t N>
struct MakeVector {
	template <
			typename... Args,
			typename R = std::vector<decltype(MakeVector<T, N - 1>::make_vector(std::declval<Args>()...))>
	>
	static R make_vector(std::size_t first, Args... sizes) {
		auto inner = MakeVector<T, N - 1>::make_vector(sizes...);
		return R(first, inner);
	}
};

template <typename T>
struct MakeVector<T, 1> {
	
	template <typename R = std::vector<T>>
	static R make_vector(std::size_t size, const T& value) {
		return R(size, value);
	}
};

template <typename T, typename... Args>
auto make_vector(Args... args) -> decltype(MakeVector<T, sizeof...(Args) - 1>::make_vector(args...)) {
	return MakeVector<T, sizeof...(Args) - 1>::make_vector(args...);
}



#include <iterator>


#include <string>
#include <stdexcept>

#ifndef SPCPPL_ASSERT
	#ifdef SPCPPL_DEBUG
		#define SPCPPL_ASSERT(condition) \
        if(!(condition)) { \
            throw std::runtime_error(std::string() + #condition + " in line " + std::to_string(__LINE__) + " in " + __PRETTY_FUNCTION__); \
        }
	#else
		#define SPCPPL_ASSERT(condition)
	#endif
#endif



template <typename T>
class IntegerIterator: public std::iterator<std::input_iterator_tag, T, std::ptrdiff_t, T*, T> {
public:
	explicit IntegerIterator(int value): value(value) {

	}

	IntegerIterator& operator++() {
		++value;
		return *this;
	}

	IntegerIterator operator++(int) {
		IntegerIterator copy = *this;
		++value;
		return copy;
	}

	IntegerIterator& operator--() {
		--value;
		return *this;
	}

	IntegerIterator operator--(int) {
		IntegerIterator copy = *this;
		--value;
		return copy;
	}

	T operator*() const {
		return value;
	}

	bool operator==(IntegerIterator rhs) {
		return value == rhs.value;
	}

	bool operator!=(IntegerIterator rhs) {
		return !(*this == rhs);
	}

private:
	T value;
};

template <typename T>
class IntegerRange {
public:
	IntegerRange(T begin, T end): begin_(begin), end_(end) {

	}

	IntegerIterator<T> begin() const {
		return IntegerIterator<T>(begin_);
	}

	IntegerIterator<T> end() const {
		return IntegerIterator<T>(end_);
	}

private:
	T begin_;
	T end_;
};

template <typename T>
class ReversedIntegerRange {
	typedef std::reverse_iterator<IntegerIterator<T>> IteratorType;
public:
	ReversedIntegerRange(T begin, T end): begin_(begin), end_(end) {

	}

	IteratorType begin() const {
		return IteratorType(IntegerIterator<T>(begin_));
	}

	IteratorType end() const {
		return IteratorType(IntegerIterator<T>(end_));
	}

private:
	T begin_;
	T end_;
};

template <typename T>
IntegerRange<T> range(T to) {
	SPCPPL_ASSERT(to >= 0);
	return IntegerRange<T>(0, to);
}

template <typename T>
IntegerRange<T> range(T from, T to) {
	SPCPPL_ASSERT(from <= to);
	return IntegerRange<T>(from, to);
}

template <typename T>
IntegerRange<T> inclusiveRange(T to) {
	SPCPPL_ASSERT(to >= 0);
	return IntegerRange<T>(0, to + 1);
}

template <typename T>
IntegerRange<T> inclusiveRange(T from, T to) {
	SPCPPL_ASSERT(from <= to);
	return IntegerRange<T>(from, to + 1);
}

template <typename T>
ReversedIntegerRange<T> downrange(T from) {
	SPCPPL_ASSERT(from >= 0);
	return ReversedIntegerRange<T>(from, 0);
}

template <typename T>
ReversedIntegerRange<T> downrange(T from, T to) {
	SPCPPL_ASSERT(from >= to);
	return ReversedIntegerRange<T>(from, to);
}

template <typename T>
ReversedIntegerRange<T> inclusiveDownrange(T from) {
	SPCPPL_ASSERT(from >= 0);
	return ReversedIntegerRange<T>(from + 1, 0);
}

template <typename T>
ReversedIntegerRange<T> inclusiveDownrange(T from, T to) {
	SPCPPL_ASSERT(from >= to);
	return ReversedIntegerRange<T>(from + 1, to);
}




#include <assert.h>





template <typename T>
T identity();



template <typename T, typename Enable = std::true_type>
struct impl__IdentityHelper {
};

template <typename T>
struct impl__SampleIdentityHelper {
	static T identity(const T&) {
		return ::identity<T>();
	}
};

template <typename T>
struct impl__IdentityHelper<T, typename std::is_arithmetic<T>::type> {
	static T identity() {
		return 1;
	}
};

template <typename T>
T identity(const T& sample) {
	return impl__SampleIdentityHelper<T>::identity(sample);
}

template <typename T>
T identity() {
	return impl__IdentityHelper<T>::identity();
}





template <bool normalize>
struct impl__Normalizator {

};

template <>
struct impl__Normalizator<true> {
	static void softUp(int& value, int mod) {
		if (value < 0) {
			value += mod;
		}
	}

	static void softDown(int& value, int mod) {
		if (value >= mod) {
			value -= mod;
		}
	}

	static void hardDown(int& value, int mod) {
		value %= mod;
	}

	static void hard(int& value, int mod) {
		value %= mod;
		softUp(value, mod);
	}
};

template <>
struct impl__Normalizator<false> {
	static void softUp(int&, int) {
	}

	static void softDown(int&, int) {
	}

	static void hardDown(int&, int) {
	}

	static void hard(int&, int) {
	}
};



template <typename T>
T extendedGcd(T a, T b, T& x, T& y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	T d = extendedGcd(b % a, a, y, x);
	x -= (b / a) * y;
	return d;
}

template <int mod, bool autoNormalize = true>
class Zn {
	static_assert(mod > 0, "Mod has to be positive integer");
public:

	
	Zn(): value(0) {
	}

	
	static Zn valueOf(int value) {
		impl__Normalizator<true>::hard(value, mod);
		return Zn(value);
	}

	Zn& operator+=(const Zn& rhs) {
		value += rhs.value;
		impl__Normalizator<autoNormalize>::softDown(value, mod);
		return *this;
	}

	Zn& operator+=(int rhs) {
		return *this += Zn::valueOf(rhs);
	}

	Zn& operator-=(const Zn& rhs) {
		value -= rhs.value;
		impl__Normalizator<autoNormalize>::softUp(value, mod);
		return *this;
	}

	Zn& operator-=(int rhs) {
		return *this -= Zn::valueOf(rhs);
	}

	Zn& operator*=(const Zn& rhs) {
		value = (int) ((1LL * value * rhs.value) % mod);
		return *this;
	}

	Zn& operator*=(int rhs) {
		return *this *= Zn::valueOf(rhs);
	}

	
	void normalize() const {
		int& value = const_cast<int&>(this->value);
		impl__Normalizator<!autoNormalize>::hard(value, mod);
	}

	Zn operator-() const {
		Zn Z_1D(mod - value);
		impl__Normalizator<autoNormalize>::softDown(Z_1D.value, mod);
		return Z_1D;
	}

	Zn& operator/=(const Zn& rhs) {
		return *this *= rhs.inversed();
	}

	Zn& operator/=(int rhs) {
		return *this /= Zn::valueOf(rhs);
	}

	bool operator==(const Zn& rhs) const {
		normalize();
		rhs.normalize();
		return value == rhs.value;
	}

	Zn inversed() const {
		SPCPPL_ASSERT(value != 0);
		normalize();

		int x, y;
		int gcd = extendedGcd(value, mod, x, y);
		(void) gcd;
		SPCPPL_ASSERT(gcd == 1);

		impl__Normalizator<autoNormalize>::softUp(x, mod);
		return Zn(x);
	}

	template <int m, bool aF>
	friend std::ostream& operator<<(std::ostream&, const Zn<m, aF>& zn);

	template <int m, bool aF>
	friend std::istream& operator>>(std::istream&, Zn<m, aF>& zn);

	int longValue() const {
		return value;
	}

private:

	
	explicit Zn(int value): value(value) {
	}

	int value;
};

template <int m, bool a>
bool operator==(const Zn<m, a>& lhs, int rhs) {
	return lhs == Zn<m, a>::valueOf(rhs);
}

template <int m, bool a>
bool operator==(int lhs, const Zn<m, a>& rhs) {
	return rhs == lhs;
}

template <int m, bool a>
bool operator!=(const Zn<m, a>& lhs, const Zn<m, a>& rhs) {
	return !(lhs == rhs);
}

template <int m, bool a>
bool operator!=(const Zn<m, a>& lhs, int rhs) {
	return !(lhs == rhs);
}

template <int m, bool a>
bool operator!=(int lhs, const Zn<m, a>& rhs) {
	return !(lhs == rhs);
}

template <int m, bool a>
Zn<m, a> operator+(const Zn<m, a>& lhs, const Zn<m, a>& rhs) {
	Zn<m, a> copy = lhs;
	return copy += rhs;
}

template <int m, bool a>
Zn<m, a> operator+(const Zn<m, a>& lhs, int rhs) {
	Zn<m, a> copy = lhs;
	return copy += rhs;
}

template <int m, bool a>
Zn<m, a> operator+(int lhs, const Zn<m, a>& rhs) {
	return rhs + lhs;
}

template <int m, bool a>
Zn<m, a> operator-(const Zn<m, a>& lhs, const Zn<m, a>& rhs) {
	Zn<m, a> copy = lhs;
	return copy -= rhs;
}

template <int m, bool a>
Zn<m, a> operator-(const Zn<m, a>& lhs, int rhs) {
	Zn<m, a> copy = lhs;
	return copy -= rhs;
}

template <int m, bool a>
Zn<m, a> operator-(int lhs, const Zn<m, a>& rhs) {
	return Zn<m, a>::valueOf(lhs) - rhs;
}

template <int m, bool a>
Zn<m, a> operator*(const Zn<m, a>& lhs, const Zn<m, a>& rhs) {
	Zn<m, a> copy = lhs;
	return copy *= rhs;
}

template <int m, bool a>
Zn<m, a> operator*(const Zn<m, a>& lhs, int rhs) {
	Zn<m, a> copy = lhs;
	return copy *= rhs;
}

template <int m, bool a>
Zn<m, a> operator*(int lhs, const Zn<m, a>& rhs) {
	return rhs * lhs;
}

template <int m, bool a>
Zn<m, a> operator/(const Zn<m, a>& lhs, const Zn<m, a>& rhs) {
	Zn<m, a> copy = lhs;
	return copy /= rhs;
}

template <int m, bool a>
Zn<m, a> operator/(const Zn<m, a>& lhs, int rhs) {
	Zn<m, a> copy = lhs;
	return copy /= rhs;
}

template <int m, bool a>
Zn<m, a> operator/(int lhs, const Zn<m, a>& rhs) {
	return Zn<m, a>::valueOf(lhs) / rhs;
}

template <int m, bool a>
std::ostream& operator<<(std::ostream& stream, const Zn<m, a>& zn) {
	zn.normalize();
	return stream << zn.value;
}

template <int m, bool a>
std::istream& operator>>(std::istream& stream, Zn<m, a>& zn) {
	stream >> zn.value;
	impl__Normalizator<a>::hard(zn.value, m);
	return stream;
}

template <int m, bool a>
struct impl__IdentityHelper<Zn<m, a>> {
	static Zn<m, a> identity() {
		return Zn<m, a>::valueOf(1);
	}
};




using namespace std;

class TaskE {
public:
	using Z = Zn<1000000007>;

	constexpr static int values = 16;
	constexpr static int functions = 1 << values;

	using Z_1D = std::array<Z, functions>;
	using Z_2D = std::array<std::array<Z, functions>, values + 1>;

	Z_1D to_submask(const Z_1D& input) {
		Z_2D dp;
		dp[0] = input;
		for (int i: range(values)) {
			for (int j: range(functions)) {
				if (j & (1 << i))
					dp[i + 1][j] += dp[i][j];
				else {
					dp[i + 1][j] += dp[i][j];
					dp[i + 1][j ^ (1 << i)] += dp[i][j];
				}
			}
		}
		return dp.back();
	}

	Z_1D to_supermask(const Z_1D& input) {
		Z_2D dp;
		dp[0] = input;
		for (int i: range(values)) {
			for (int j: range(functions)) {
				if (!(j & (1 << i)))
					dp[i + 1][j] += dp[i][j];
				else {
					dp[i + 1][j] += dp[i][j];
					dp[i + 1][j ^ (1 << i)] += dp[i][j];
				}
			}
		}
		return dp.back();
	}

	Z_1D from_submask(const Z_1D& input) {
		Z_2D dp;
		dp[0] = input;
		for (int i: range(values)) {
			for (int j: range(functions)) {
				if (j & (1 << i))
					dp[i + 1][j] += dp[i][j];
				else {
					dp[i + 1][j] += dp[i][j];
					dp[i + 1][j ^ (1 << i)] -= dp[i][j];
				}
			}
		}
		return dp.back();
	}
	Z_1D from_supermask(const Z_1D& input) {
		Z_2D dp;
		dp[0] = input;
		for (int i: range(values)) {
			for (int j: range(functions)) {
				if (!(j & (1 << i)))
					dp[i + 1][j] += dp[i][j];
				else {
					dp[i + 1][j] += dp[i][j];
					dp[i + 1][j ^ (1 << i)] -= dp[i][j];
				}
			}
		}
		return dp.back();
	}

	string s;

	int pos;


	Z_1D solve() {
		if(s[pos] == '(') {
			++pos;
			auto l = solve();
			assert(s[pos] == ')');
			++pos;
			char op = s[pos];
			++pos;
			assert(s[pos] == '(');
			++pos;
			auto r = solve();
			assert(s[pos] == ')');
			++pos;

			Z_1D res;

			if (op == '?' || op == '|') {
				auto L = to_submask(l);
				auto R = to_submask(r);
				for (int i: range(functions)) {
					L[i] *= R[i];
				}
				L = from_submask(L);
				for (int i: range(functions)) {
					res[i] += L[i];
				}
			}
			if (op == '?' || op == '&') {
				auto L = to_supermask(l);
				auto R = to_supermask(r);
				for (int i: range(functions)) {
					L[i] *= R[i];
				}
				L = from_supermask(L);
				for (int i: range(functions)) {
					res[i] += L[i];
				}
			}
			return res;
		}
		else {
			Z_1D res;
			for (int i: range(4)) {
				int cur = 0;
				for (int j: range(values)) {
					if(j & (1 << i)) {
						cur ^= 1 << j;
					}
				}
				if (s[pos] == '?' || s[pos] == 'A' + i) {
					res[cur] += 1;
				}
				if (s[pos] == '?' || s[pos] == 'a' + i) {
					res[functions - 1 - cur] += 1;
				}
			}
			++pos;
			return res;
		}
	}
	void solve(std::istream& in, std::ostream& out) {


		in >> s;
		pos = 0;

		int n;
		in >> n;
		auto res = solve();


		vector<pair<int, int>> queries(n);

		for (int i = 0; i < n; ++i) {
			int a, b, c, d, r;
			in >> a >> b >> c >> d >> r;
			queries[i] = make_pair(a + 2 * b + 4 * c + 8 * d, r);
		}

		Z ans;
		for (int i: range(functions)) {
			bool ok = true;
			for (auto q: queries) {
				int val = (i >> q.first) & 1;
				if(val != q.second) {
					ok = false;
					break;
				}
			}
			if(ok)
				ans += res[i];
		}

		out << ans;
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	TaskE solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(0);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}