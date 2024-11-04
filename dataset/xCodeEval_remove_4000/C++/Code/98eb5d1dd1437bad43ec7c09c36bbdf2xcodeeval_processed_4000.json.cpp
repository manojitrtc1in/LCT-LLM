









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










	
		
		if(!(condition)) { \
			throw std::runtime_error(std::string() + 
		}
	
		
	




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
class id2 {
	typedef std::reverse_iterator<IntegerIterator<T>> IteratorType;
public:
	id2(T begin, T end): begin_(begin), end_(end) {

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
id2<T> downrange(T from) {
	SPCPPL_ASSERT(from >= 0);
	return id2<T>(from, 0);
}

template <typename T>
id2<T> downrange(T from, T to) {
	SPCPPL_ASSERT(from >= to);
	return id2<T>(from, to);
}

template <typename T>
id2<T> id1(T from) {
	SPCPPL_ASSERT(from >= 0);
	return id2<T>(from + 1, 0);
}

template <typename T>
id2<T> id1(T from, T to) {
	SPCPPL_ASSERT(from >= to);
	return id2<T>(from + 1, to);
}










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
	static void softUp(long long& value, long long mod) {
		if (value < 0) {
			value += mod;
		}
	}

	static void softDown(long long& value, long long mod) {
		if (value >= mod) {
			value -= mod;
		}
	}

	static void hardDown(long long& value, long long mod) {
		value %= mod;
	}

	static void hard(long long& value, long long mod) {
		value %= mod;
		softUp(value, mod);
	}
};

template <>
struct impl__Normalizator<false> {
	static void softUp(long long&, long long) {
	}

	static void softDown(long long&, long long) {
	}

	static void hardDown(long long&, long long) {
	}

	static void hard(long long&, long long) {
	}
};



template <typename T>
T id0(T a, T b, T& x, T& y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	T d = id0(b % a, a, y, x);
	x -= (b / a) * y;
	return d;
}

template <long long mod, bool autoNormalize = true>
class Zn {
	static_assert(mod > 0, "Mod has to be positive integer");
public:

	
	Zn(): value(0) {
	}

	
	static Zn valueOf(long long value) {
		impl__Normalizator<true>::hard(value, mod);
		return Zn(value);
	}

	Zn& operator+=(const Zn& rhs) {
		value += rhs.value;
		impl__Normalizator<autoNormalize>::softDown(value, mod);
		return *this;
	}

	Zn& operator+=(long long rhs) {
		return *this += Zn::valueOf(rhs);
	}

	Zn& operator-=(const Zn& rhs) {
		value -= rhs.value;
		impl__Normalizator<autoNormalize>::softUp(value, mod);
		return *this;
	}

	Zn& operator-=(long long rhs) {
		return *this -= Zn::valueOf(rhs);
	}

	Zn& operator*=(const Zn& rhs) {
		value *= rhs.value;
		impl__Normalizator<autoNormalize>::hardDown(value, mod);
		return *this;
	}

	Zn& operator*=(long long rhs) {
		return *this *= Zn::valueOf(rhs);
	}

	
	void normalize() const {
		long long& value = const_cast<long long&>(this->value);
		impl__Normalizator<!autoNormalize>::hard(value, mod);
	}

	Zn operator-() const {
		Zn result(mod - value);
		impl__Normalizator<autoNormalize>::softDown(result.value, mod);
		return result;
	}

	Zn& operator/=(const Zn& rhs) {
		return *this *= rhs.inversed();
	}

	Zn& operator/=(long long rhs) {
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

		long long x, y;
		long long gcd = id0(value, mod, x, y);
		(void) gcd;
		SPCPPL_ASSERT(gcd == 1);

		impl__Normalizator<autoNormalize>::softUp(x, mod);
		return Zn(x);
	}

	template <long long m, bool aF>
	friend std::ostream& operator<<(std::ostream&, const Zn<m, aF>& zn);

	template <long long m, bool aF>
	friend std::istream& operator>>(std::istream&, Zn<m, aF>& zn);

	long long longValue() const {
		return value;
	}

private:

	
	explicit Zn(long long value): value(value) {
	}

	long long value;
};

template <long long m, bool a>
bool operator==(const Zn<m, a>& lhs, long long rhs) {
	return lhs == Zn<m, a>::valueOf(rhs);
}

template <long long m, bool a>
bool operator==(long long lhs, const Zn<m, a>& rhs) {
	return rhs == lhs;
}

template <long long m, bool a>
bool operator!=(const Zn<m, a>& lhs, const Zn<m, a>& rhs) {
	return !(lhs == rhs);
}

template <long long m, bool a>
bool operator!=(const Zn<m, a>& lhs, long long rhs) {
	return !(lhs == rhs);
}

template <long long m, bool a>
bool operator!=(long long lhs, const Zn<m, a>& rhs) {
	return !(lhs == rhs);
}

template <long long m, bool a>
Zn<m, a> operator+(const Zn<m, a>& lhs, const Zn<m, a>& rhs) {
	Zn<m, a> copy = lhs;
	return copy += rhs;
}

template <long long m, bool a>
Zn<m, a> operator+(const Zn<m, a>& lhs, long long rhs) {
	Zn<m, a> copy = lhs;
	return copy += rhs;
}

template <long long m, bool a>
Zn<m, a> operator+(long long lhs, const Zn<m, a>& rhs) {
	return rhs + lhs;
}

template <long long m, bool a>
Zn<m, a> operator-(const Zn<m, a>& lhs, const Zn<m, a>& rhs) {
	Zn<m, a> copy = lhs;
	return copy -= rhs;
}

template <long long m, bool a>
Zn<m, a> operator-(const Zn<m, a>& lhs, long long rhs) {
	Zn<m, a> copy = lhs;
	return copy -= rhs;
}

template <long long m, bool a>
Zn<m, a> operator-(long long lhs, const Zn<m, a>& rhs) {
	return Zn<m, a>::valueOf(lhs) - rhs;
}

template <long long m, bool a>
Zn<m, a> operator*(const Zn<m, a>& lhs, const Zn<m, a>& rhs) {
	Zn<m, a> copy = lhs;
	return copy *= rhs;
}

template <long long m, bool a>
Zn<m, a> operator*(const Zn<m, a>& lhs, long long rhs) {
	Zn<m, a> copy = lhs;
	return copy *= rhs;
}

template <long long m, bool a>
Zn<m, a> operator*(long long lhs, const Zn<m, a>& rhs) {
	return rhs * lhs;
}

template <long long m, bool a>
Zn<m, a> operator/(const Zn<m, a>& lhs, const Zn<m, a>& rhs) {
	Zn<m, a> copy = lhs;
	return copy /= rhs;
}

template <long long m, bool a>
Zn<m, a> operator/(const Zn<m, a>& lhs, long long rhs) {
	Zn<m, a> copy = lhs;
	return copy /= rhs;
}

template <long long m, bool a>
Zn<m, a> operator/(long long lhs, const Zn<m, a>& rhs) {
	return Zn<m, a>::valueOf(lhs) / rhs;
}

template <long long m, bool a>
std::ostream& operator<<(std::ostream& stream, const Zn<m, a>& zn) {
	zn.normalize();
	return stream << zn.value;
}

template <long long m, bool a>
std::istream& operator>>(std::istream& stream, Zn<m, a>& zn) {
	stream >> zn.value;
	impl__Normalizator<a>::hard(zn.value, m);
	return stream;
}

template <long long m, bool a>
struct impl__IdentityHelper<Zn<m, a>> {
	static Zn<m, a> identity() {
		return Zn<m, a>::valueOf(1);
	}
};




using namespace std;

class TaskE {
public:
	using Z = Zn<1000000007>;

	int values = 16;
	int functions = 1 << values;
	vector<Z> to_submask(vector<Z> input) {
		auto dp = make_vector<Z>(values + 1, functions, Z());
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

	vector<Z> to_supermask(vector<Z> input) {
		auto dp = make_vector<Z>(values + 1, functions, Z());
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

	Z one = Z::valueOf(1);

	vector<Z> from_submask(vector<Z> input) {
		auto dp = make_vector<Z>(values + 1, functions, Z());
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
	vector<Z> from_supermask(vector<Z> input) {
		auto dp = make_vector<Z>(values + 1, functions, Z());
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

	vector<int> lis = {
			43690,
			52428,
			61680,
			65280,
	};
	vector<Z> solve() {
		if(s[pos] == '(') {
			++pos;
			vector<Z> l = solve();
			++pos;
			char op = s[pos];
			++pos;
			++pos;
			vector<Z> r = solve();
			++pos;

			vector<Z> res(functions);

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
			vector<Z> res(functions);
			for (int i: range(4)) {
				int cur = lis[i];
				if (s[pos] == '?' || s[pos] == 'A' + i) {
					res[cur] = one;
				}
				if (s[pos] == '?' || s[pos] == 'a' + i) {
					res[functions - 1 - cur] = one;
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