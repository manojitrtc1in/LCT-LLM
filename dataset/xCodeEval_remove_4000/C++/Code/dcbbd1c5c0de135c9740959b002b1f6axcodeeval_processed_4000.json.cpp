

















	
		
		if(!(condition)) { \
			throw std::runtime_error(std::string() + 
		}
	
		
	




template <typename T>
class IntegerIterator {
public:
	using value_type = T;
	using difference_type = std::ptrdiff_t;
	using pointer = T*;
	using reference = T;
	using iterator_category = std::input_iterator_tag;

	explicit IntegerIterator(T value): value(value) {

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

	bool operator==(IntegerIterator rhs) const {
		return value == rhs.value;
	}

	bool operator!=(IntegerIterator rhs) const {
		return !(*this == rhs);
	}

private:
	T value;
};

template <typename T>
class IntegerRange {
public:
	IntegerRange(T begin, T end): begin_(begin), end_(end) {
		SPCPPL_ASSERT(begin <= end);
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
class id5 {
	using IteratorType = std::reverse_iterator<IntegerIterator<T>>;
public:
	id5(T begin, T end): begin_(begin), end_(end) {
		SPCPPL_ASSERT(begin >= end);
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
	return IntegerRange<T>(0, to);
}

template <typename T>
IntegerRange<T> range(T from, T to) {
	return IntegerRange<T>(from, to);
}

template <typename T>
IntegerRange<T> inclusiveRange(T to) {
	return IntegerRange<T>(0, to + 1);
}

template <typename T>
IntegerRange<T> inclusiveRange(T from, T to) {
	return IntegerRange<T>(from, to + 1);
}

template <typename T>
id5<T> downrange(T from) {
	return id5<T>(from, 0);
}

template <typename T>
id5<T> downrange(T from, T to) {
	return id5<T>(from, to);
}

template <typename T>
id5<T> id2(T from) {
	return id5<T>(from + 1, 0);
}

template <typename T>
id5<T> id2(T from, T to) {
	return id5<T>(from + 1, to);
}










template <bool b, typename T = void>


using enable_if_t = typename std::enable_if<b, T>::type;













template <bool... Bools>
struct Disjunction : std::false_type {
};

template <bool First, bool... Others>


struct Disjunction<First, Others...> : std::integral_constant<bool, First || Disjunction<Others...>::value> {

};


template <bool... Bools>
constexpr bool id3 = Disjunction<Bools...>::value;

static_assert(!id3<>, "");
static_assert(!id3<false, false>, "");
static_assert(id3<true>, "");
static_assert(id3<false, true>, "");
static_assert(id3<true, false>, "");
static_assert(id3<false, false, true, true>, "");


template <typename T, typename... Types>




using IsOneOf = Disjunction<std::is_same<T, Types>::value...>;








template <typename T>
using IsSaneInteger = std::integral_constant<
		bool,
		std::is_integral<T>::value && !IsOneOf<typename std::remove_cv<T>::type, char, signed char, unsigned char, bool, char16_t, char32_t, wchar_t>::value
>;






template <typename T, typename = std::true_type>
struct IdentityHelper;

template <typename T>
struct IdentityHelper<T, typename std::is_arithmetic<T>::type> {
	static T identity() {
		return 1;
	}
};

template <typename T>
T identity() {
	return IdentityHelper<T>::identity();
}




template <typename T>
T id1(T a, T b, T& x, T& y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	T d = id1(b % a, a, y, x);
	x -= (b / a) * y;
	return d;
}

template <typename T>
class Zn {
public:
	Zn(): value(0) {
	}

	
	template <typename U>
	static Zn valueOf(U value) {
		int x = static_cast<int>(value % mod());
		if (x < 0) {
			x += mod();
		}
		return Zn(x);
	}

	static Zn rawValueOf(int value) {
		SPCPPL_ASSERT(value >= 0 && value < mod());
		return Zn(value);
	}

	template <typename U>
	Zn& operator=(U rhs) {
		return *this = Zn::valueOf(rhs);
	}


	Zn& operator+=(const Zn& rhs) {
		value += rhs.value;
		if (value >= mod()) {
			value -= mod();
		}
		return *this;
	}

	template <typename U>
	Zn& operator+=(U rhs) {
		return *this += Zn::valueOf(rhs);
	}

	Zn& operator-=(const Zn& rhs) {
		value -= rhs.value;
		if (value < 0) {
			value += mod();
		}
		return *this;
	}

	template <typename U>
	Zn& operator-=(U rhs) {
		return *this -= Zn::valueOf(rhs);
	}

	Zn& operator*=(const Zn& rhs) {
		long long result = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
		value = static_cast<int>(result % mod());
		return *this;
	}

	template <typename U>
	Zn& operator*=(U rhs) {
		return *this *= Zn::valueOf(rhs);
	}

	Zn operator-() const {
		if (value == 0) {
			return *this;
		}
		else {
			return Zn(mod() - value);
		}
	}

	Zn& operator/=(const Zn& rhs) {
		return *this *= rhs.inversed();
	}

	template <typename U>
	Zn& operator/=(U rhs) {
		return *this /= Zn::valueOf(rhs);
	}

	Zn inversed() const {
		SPCPPL_ASSERT(value != 0);

		int x, y;
		int gcd = id1(value, mod(), x, y);
		(void) gcd;
		SPCPPL_ASSERT(gcd == 1);

		if (x < 0) {
			x += mod();
		}
		return Zn(x);
	}

	template <typename U>
	friend std::ostream& operator<<(std::ostream&, const Zn<U>& zn);

	template <typename U>
	friend std::istream& operator>>(std::istream&, Zn<U>& zn);

	template <typename U>
	friend bool operator==(const Zn<U>& lhs, const Zn<U>& rhs);

	int intValue() const {
		return value;
	}

private:
	
	explicit Zn(int value): value(value) {
	}

	int value;

	constexpr static int mod() {
		return T::value;
	}

	template <int N = T::value>
	static constexpr bool id4(int) {
		return N > 0 && N <= (1 << 30);
	}
	static constexpr bool id4(...) {
		return true;
	}
	static_assert(
			std::is_same<typename std::decay<decltype(T::value)>::type, int>::value,
			"T::value must be int"
	);
	static_assert(id4(0), "Mod has to be positive integer up to 1 << 30");
};

template <typename T>
bool operator==(const Zn<T>& lhs, const Zn<T>& rhs) {
	return lhs.value == rhs.value;
}

template <typename T, typename U>
bool operator==(const Zn<T>& lhs, U rhs) {
	return lhs == Zn<T>::valueOf(rhs);
}

template <typename T, typename U>
bool operator==(U lhs, const Zn<T>& rhs) {
	return rhs == lhs;
}

template <typename T>
bool operator!=(const Zn<T>& lhs, const Zn<T>& rhs) {
	return !(lhs == rhs);
}

template <typename T, typename U>
bool operator!=(const Zn<T>& lhs, U rhs) {
	return !(lhs == rhs);
}

template <typename T, typename U>
bool operator!=(U lhs, const Zn<T>& rhs) {
	return !(lhs == rhs);
}

template <typename T>
Zn<T> operator+(const Zn<T>& lhs, const Zn<T>& rhs) {
	Zn<T> copy = lhs;
	return copy += rhs;
}

template <typename T, typename U>
Zn<T> operator+(const Zn<T>& lhs, U rhs) {
	Zn<T> copy = lhs;
	return copy += rhs;
}

template <typename T, typename U>
Zn<T> operator+(U lhs, const Zn<T>& rhs) {
	return rhs + lhs;
}

template <typename T>
Zn<T> operator-(const Zn<T>& lhs, const Zn<T>& rhs) {
	Zn<T> copy = lhs;
	return copy -= rhs;
}

template <typename T, typename U>
Zn<T> operator-(const Zn<T>& lhs, U rhs) {
	Zn<T> copy = lhs;
	return copy -= rhs;
}

template <typename T, typename U>
Zn<T> operator-(U lhs, const Zn<T>& rhs) {
	return Zn<T>::valueOf(lhs) - rhs;
}

template <typename T>
Zn<T> operator*(const Zn<T>& lhs, const Zn<T>& rhs) {
	Zn<T> copy = lhs;
	return copy *= rhs;
}

template <typename T, typename U>
Zn<T> operator*(const Zn<T>& lhs, U rhs) {
	Zn<T> copy = lhs;
	return copy *= rhs;
}

template <typename T, typename U>
Zn<T> operator*(U lhs, const Zn<T>& rhs) {
	return rhs * lhs;
}

template <typename T>
Zn<T> operator/(const Zn<T>& lhs, const Zn<T>& rhs) {
	Zn<T> copy = lhs;
	return copy /= rhs;
}

template <typename T, typename U>
Zn<T> operator/(const Zn<T>& lhs, U rhs) {
	Zn<T> copy = lhs;
	return copy /= rhs;
}

template <typename T, typename U>
Zn<T> operator/(U lhs, const Zn<T>& rhs) {
	return Zn<T>::valueOf(lhs) / rhs;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Zn<T>& zn) {
	return stream << zn.value;
}

template <typename T>
std::istream& operator>>(std::istream& stream, Zn<T>& zn) {
	int64_t value;
	stream >> value;
	zn.value = static_cast<int>(value % T::value);
	return stream;
}

template <typename T>
struct IdentityHelper<Zn<T>> {
	static Zn<T> identity() {
		return Zn<T>::valueOf(1);
	}
};

template <int m>
using ZnConst = Zn<std::integral_constant<int, m>>;

using Zn7 = ZnConst<1000000007>;






template <typename T, std::size_t N>
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










using namespace std;

class D1KrasivayaSkobochnayaPosledovatelnostProstayaVersiya {
public:
	static constexpr int kStressCount = 0;
	static void generateTest(std::ostream& test) {
	}
	void solve(std::istream& in, std::ostream& out) {
		

		


		using Z = ZnConst<998244353>;
		string s;
		in >> s;
		int n = s.size();

		auto dpL = make_vector<Z>(n + 1, n + 1, Z());
		auto id0 = make_vector<Z>(n + 1, n + 1, Z());

		dpL[0][0] = 1;

		for (int i: range(n)) {
			for (int k: inclusiveRange(i)) {
				if (s[i] != ')') {
					dpL[i + 1][k + 1] += dpL[i][k];
					id0[i + 1][k + 1] += dpL[i][k];
				}
				if (s[i] != '(') {
					dpL[i + 1][k] += dpL[i][k];
				}
			}
		}


		reverse(s.begin(), s.end());

		for (char& c: s) {
			if (c == '(') {
				c = ')';
			} else if (c == ')') {
				c = '(';
			}
		}

		auto dpR = make_vector<Z>(n + 1, n + 1, Z());

		dpR[0][0] = 1;

		for (int i: range(n)) {
			for (int k: inclusiveRange(i)) {
				if (s[i] != ')') {
					dpR[i + 1][k + 1] += dpR[i][k];
					

				}
				if (s[i] != '(') {
					dpR[i + 1][k] += dpR[i][k];
				}
			}
		}

		int x;
		for (int i: inclusiveRange(n)) {
			for (int j: downrange(n)) {
				dpR[i][j] += dpR[i][j + 1];
			}
		}

		Z ans;
		for (int i: range(n)) {
			for (int j: range(n)) {
				

				ans += id0[i][j] * dpR[n - i][j];
			}
		}

		out << ans << "\n";
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	D1KrasivayaSkobochnayaPosledovatelnostProstayaVersiya solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(nullptr);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}
