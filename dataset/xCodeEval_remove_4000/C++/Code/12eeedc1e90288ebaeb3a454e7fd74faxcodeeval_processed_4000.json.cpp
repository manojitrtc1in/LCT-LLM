






using namespace std;














	
		
		if(!(condition)) { \
			throw std::runtime_error(std::string() + 
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

template <int mod>
class Zn {
	static_assert(mod > 0, "Mod has to be positive integer");
public:

	
	Zn(): value(0) {
	}

	
	static Zn valueOf(int value) {
		return Zn(value % mod);
	}

	static Zn valueOf(long long value) {
		return Zn(static_cast<int>(value) % mod);
	}

	static Zn rawValueOf(int value) {
		SPCPPL_ASSERT(value >= 0 && value < mod);
		return Zn(value);
	}

	Zn& operator=(int rhs) {
		return *this = Zn::valueOf(rhs);
	}

	Zn& operator=(long long rhs) {
		return *this = Zn::valueOf(rhs);
	}

	Zn& operator+=(const Zn& rhs) {
		value += rhs.value;
		if (value >= mod) {
			value -= mod;
		}
		return *this;
	}

	Zn& operator+=(int rhs) {
		return *this += Zn::valueOf(rhs);
	}

	Zn& operator+=(long long rhs) {
		return *this += Zn::valueOf(rhs);
	}

	Zn& operator-=(const Zn& rhs) {
		value -= rhs.value;
		if (value < 0) {
			value += mod;
		}
		return *this;
	}

	Zn& operator-=(int rhs) {
		return *this -= Zn::valueOf(rhs);
	}

	Zn& operator-=(long long rhs) {
		return *this -= Zn::valueOf(rhs);
	}

	Zn& operator*=(const Zn& rhs) {
		long long result = static_cast<long long>(value) * static_cast<long long>(rhs.value);
		value = static_cast<int>(result % mod);
		return *this;
	}

	Zn& operator*=(int rhs) {
		return *this *= Zn::valueOf(rhs);
	}

	Zn& operator*=(long long rhs) {
		return *this *= Zn::valueOf(rhs);
	}

	Zn operator-() const {
		if (value == 0) {
			return *this;
		}
		else {
			return Zn(mod - value);
		}
	}

	Zn& operator/=(const Zn& rhs) {
		return *this *= rhs.inversed();
	}

	Zn& operator/=(int rhs) {
		return *this /= Zn::valueOf(rhs);
	}

	Zn& operator/=(long long rhs) {
		return *this /= Zn::valueOf(rhs);
	}

	bool operator==(const Zn& rhs) const {
		return value == rhs.value;
	}

	Zn inversed() const {
		SPCPPL_ASSERT(value != 0);

		int x, y;
		int gcd = id1(value, mod, x, y);
		(void) gcd;
		SPCPPL_ASSERT(gcd == 1);

		if (x < 0) {
			x += mod;
		}
		return Zn(x);
	}

	template <int m>
	friend std::ostream& operator<<(std::ostream&, const Zn<m>& zn);

	template <int m>
	friend std::istream& operator>>(std::istream&, Zn<m>& zn);

	int intValue() const {
		return value;
	}

private:
	
	explicit Zn(int value): value(value) {
	}

	int value;
};

template <int m>
bool operator==(const Zn<m>& lhs, int rhs) {
	return lhs == Zn<m>::valueOf(rhs);
}

template <int m>
bool operator==(int lhs, const Zn<m>& rhs) {
	return rhs == lhs;
}
template <int m>
bool operator==(const Zn<m>& lhs, long long rhs) {
	return lhs == Zn<m>::valueOf(rhs);
}

template <int m>
bool operator==(long long lhs, Zn<m>& rhs) {
	return rhs == lhs;
}

template <int m>
bool operator!=(const Zn<m>& lhs, const Zn<m>& rhs) {
	return !(lhs == rhs);
}

template <int m>
bool operator!=(const Zn<m>& lhs, int rhs) {
	return !(lhs == rhs);
}

template <int m>
bool operator!=(int lhs, const Zn<m>& rhs) {
	return !(lhs == rhs);
}

template <int m>
bool operator!=(const Zn<m>& lhs, long long rhs) {
	return !(lhs == rhs);
}

template <int m>
bool operator!=(long long rhs, const Zn<m>& lhs) {
	return !(lhs == rhs);
}

template <int m>
Zn<m> operator+(const Zn<m>& lhs, const Zn<m>& rhs) {
	Zn<m> copy = lhs;
	return copy += rhs;
}

template <int m>
Zn<m> operator+(const Zn<m>& lhs, int rhs) {
	Zn<m> copy = lhs;
	return copy += rhs;
}

template <int m>
Zn<m> operator+(int lhs, const Zn<m>& rhs) {
	return rhs + lhs;
}

template <int m>
Zn<m> operator+(const Zn<m>& lhs, long long rhs) {
	Zn<m> copy = lhs;
	return copy += rhs;
}

template <int m>
Zn<m> operator+(long long lhs, const Zn<m>& rhs) {
	return rhs + lhs;
}

template <int m>
Zn<m> operator-(const Zn<m>& lhs, const Zn<m>& rhs) {
	Zn<m> copy = lhs;
	return copy -= rhs;
}

template <int m>
Zn<m> operator-(const Zn<m>& lhs, int rhs) {
	Zn<m> copy = lhs;
	return copy -= rhs;
}

template <int m>
Zn<m> operator-(int lhs, const Zn<m>& rhs) {
	return Zn<m>::valueOf(lhs) - rhs;
}

template <int m>
Zn<m> operator-(const Zn<m>& lhs, long long rhs) {
	Zn<m> copy = lhs;
	return copy -= rhs;
}

template <int m>
Zn<m> operator-(long lhs, const Zn<m>& rhs) {
	return Zn<m>::valueOf(lhs) - rhs;
}

template <int m>
Zn<m> operator*(const Zn<m>& lhs, const Zn<m>& rhs) {
	Zn<m> copy = lhs;
	return copy *= rhs;
}

template <int m>
Zn<m> operator*(const Zn<m>& lhs, int rhs) {
	Zn<m> copy = lhs;
	return copy *= rhs;
}

template <int m>
Zn<m> operator*(int lhs, const Zn<m>& rhs) {
	return rhs * lhs;
}

template <int m>
Zn<m> operator*(const Zn<m>& lhs, long long rhs) {
	Zn<m> copy = lhs;
	return copy *= rhs;
}

template <int m>
Zn<m> operator*(long long lhs, const Zn<m>& rhs) {
	return rhs * lhs;
}

template <int m>
Zn<m> operator/(const Zn<m>& lhs, const Zn<m>& rhs) {
	Zn<m> copy = lhs;
	return copy /= rhs;
}

template <int m>
Zn<m> operator/(const Zn<m>& lhs, int rhs) {
	Zn<m> copy = lhs;
	return copy /= rhs;
}

template <int m>
Zn<m> operator/(int lhs, const Zn<m>& rhs) {
	return Zn<m>::valueOf(lhs) / rhs;
}

template <int m>
Zn<m> operator/(const Zn<m>& lhs, long long rhs) {
	Zn<m> copy = lhs;
	return copy /= rhs;
}

template <int m>
Zn<m> operator/(long long lhs, const Zn<m>& rhs) {
	return Zn<m>::valueOf(lhs) / rhs;
}

template <int m>
std::ostream& operator<<(std::ostream& stream, const Zn<m>& zn) {
	return stream << zn.value;
}

template <int m>
std::istream& operator>>(std::istream& stream, Zn<m>& zn) {
	long long value;
	stream >> value;
	zn.value = static_cast<int>(value % m);
	return stream;
}

template <int m>
struct impl__IdentityHelper<Zn<m>> {
	static Zn<m> identity() {
		return Zn<m>::valueOf(1);
	}
};











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
class id4 {
	typedef std::reverse_iterator<IntegerIterator<T>> IteratorType;
public:
	id4(T begin, T end): begin_(begin), end_(end) {

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
id4<T> downrange(T from) {
	SPCPPL_ASSERT(from >= 0);
	return id4<T>(from, 0);
}

template <typename T>
id4<T> downrange(T from, T to) {
	SPCPPL_ASSERT(from >= to);
	return id4<T>(from, to);
}

template <typename T>
id4<T> id2(T from) {
	SPCPPL_ASSERT(from >= 0);
	return id4<T>(from + 1, 0);
}

template <typename T>
id4<T> id2(T from, T to) {
	SPCPPL_ASSERT(from >= to);
	return id4<T>(from + 1, to);
}


bool isPrime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return n >= 2;
}

struct Bool {
	 Bool(bool value): value(value) {

	}

	operator bool() const {
		return value;
	}

private:
	bool value;
};

std::vector<Bool> primeMap(std::size_t maxN) {
	std::vector<Bool> prime(maxN + 1, true);

	prime[0] = false;
	prime[1] = false;

	for (std::size_t i = 2; i * i <= maxN; ++i) {
		if (prime[i]) {
			if (i * 1ULL * i <= maxN) {
				for (std::size_t j = i * i; j <= maxN; j += i) {
					prime[j] = false;
				}
			}
		}
	}
	return prime;
}

std::vector<int> id3(int maxN) {
	std::vector<int> result;
	result.reserve(maxN);
	std::vector<Bool> map = primeMap(maxN);
	for (int i: range(maxN + 1)) {
		if (map[i]) {
			result.push_back(i);
		}
	}
	return result;
}

int nextPrime(int n) {
	while (!isPrime(n)) {
		++n;
	}
	return n;
}






typedef std::mt19937 impl__Random;

impl__Random& randomEngine() {
	static std::random_device device;
	static impl__Random engine(device());
	return engine;
}

int randomInteger() {
	std::uniform_int_distribution<int> d;
	return d(randomEngine());
}

int randomInteger(int to) {
	SPCPPL_ASSERT(to > 0);
	std::uniform_int_distribution<int> d(0, to - 1);
	return d(randomEngine());
}

int randomInteger(int from, int to) {
	return from + randomInteger(to - from);
}









class id0 {
public:

	static const int64_t multiplier = 97;

	id0(const std::string& s) {
		ensureLength(s.length());
		for (std::size_t j = 0; j < 2; ++j) {
			hashes[j].resize(s.length() + 1);
			for (std::size_t i: range(s.size())) {
				hashes[j][i + 1] = (hashes[j][i] * multiplier + s[i]) % modules[j];
			}
		}
	}

	int64_t hash(std::size_t from, std::size_t to) const {
		SPCPPL_ASSERT(from <= to);
		return ((oneHash(from, to, 0) << 32LL) | (oneHash(from, to, 1)));
	}

private:

	int64_t oneHash(std::size_t from, std::size_t to, std::size_t index) const {
		int64_t result = hashes[index][to] - hashes[index][from] * powers[index][to - from] % modules[index];
		if (result <= 0) {
			result -= modules[index];
		}
		return result;
	}

	static void ensureLength(std::size_t length) {
		for (std::size_t i = 0; i < 2; ++i) {
			std::vector<int64_t>& powersArray = powers[i];
			powersArray.reserve(length + 1);
			while (powersArray.size() < length + 1) {
				powersArray.push_back(powersArray.back() * multiplier % modules[i]);
			}
		}
	}

	static std::array<std::vector<int64_t>, 2> powers;
	std::array<std::vector<int64_t>, 2> hashes;

	static int64_t randomBigPrime() {
		return nextPrime(randomInteger(1000000000, 2000000000));
	}

	static const std::array<int64_t, 2> modules;
};

std::array<std::vector<int64_t>, 2> id0::powers = {{{1}, {1}}};
const std::array<int64_t, 2> id0::modules = {{randomBigPrime(), randomBigPrime()}};






template <typename Hasher>
class StringHash {
public:
	StringHash(const std::string& s): hasher(s) {

	}

	unsigned long long hash(std::size_t from, std::size_t to) const {
		return hasher.hash(from, to);
	}

	unsigned long long prefixHash(std::size_t to) const {
		return hasher.hash(0, to);
	}

	unsigned long long suffixHash(std::size_t from) const {
		return hasher.hash(from, hasher.size());
	}

	unsigned long long hash() const {
		return hasher.hash(0, hasher.size());
	}

private:
	Hasher hasher;
};




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







class OverflowHasher {
public:
	static const unsigned long long multiplier = 97;

	OverflowHasher(const std::string& s): hashes(s.size() + 1) {
		ensureLength(s.length());
		for (std::size_t i: range(s.size())) {
			hashes[i + 1] = hashes[i] * multiplier + s[i];
		}
	}

	unsigned long long hash(std::size_t from, std::size_t to) const {
		SPCPPL_ASSERT(from <= to);
		return hashes[to] - hashes[from] * powers[to - from];
	}

private:

	static void ensureLength(std::size_t length) {
		powers.reserve(length + 1);
		while (powers.size() < length + 1) {
			powers.push_back(powers.back() * multiplier);
		}
	}

	static std::vector<unsigned long long> powers;
	std::vector<unsigned long long> hashes;
};

std::vector<unsigned long long> OverflowHasher::powers = {1};


using namespace std;

using Z = Zn<1000000007>;
std::array<std::array<Z, 5001>, 5001> dp;
class TaskD {
public:
	StringHash<OverflowHasher>* hasher;

	void fill(const std::string& s) {
		hasher = new StringHash<OverflowHasher>(s);
	}

	int64_t hash(int , int l, int r) {
		return hasher->hash(l, r);
	}

	void solve(std::istream& in, std::ostream& out) {
		int n;
		string s;
		in >> n >> s;
		assert(n <= 5000 && s.size() == n);

		auto dp = make_vector<Z>(n + 1, n + 1, Z());
		

		

		dp[1][0] = Z::rawValueOf(1);

		srand(time(0));
		randomEngine().seed(rand());
		fill(s);


		for (int r: range(1, n)) {
			for (int prev: range(r)) {
				if(dp[r][prev] == Z())
					continue;
				if (n - r < r - prev) {
					dp[n][r] += dp[r][prev];
					continue;
				}
				dp[r + 1][prev] += dp[r][prev];
				if (s[r] == '0')
					continue;
				int cand = 2 * r - prev;
				if (cand > n) {
					continue;
				}
				if (myless(s, prev, r, r, cand)) {
					dp[cand][r] += dp[r][prev];
				}
				else {
					++cand;
					if(cand > n) {
						continue;
					}
					dp[cand][r] += dp[r][prev];
				}
			}
		}
		Z ans;
		for (int i: range(n)) {
			ans += dp[n][i];
		}

		out << ans << "\n";
	}
	bool myless(const std::string& s, int l1, int r1, int l2, int r2) {
		

		

		

		if (hash(0, l1, r1) == hash(0, l2, r2) && hash(1, l1, r1) == hash(1, l2, r2)) {
			return false;
		}
		int l = 0, r = (r1 - l1);
		while(r - l > 1) {
			int m = (r + l) / 2;
			if (hash(0, l1, l1 + m) == hash(0, l2, l2 + m) && hash(1, l1, l1 + m) == hash(1, l2, l2 + m)) {
				l = m;
			} else {
				r = m;
			}
		}

		auto res2 = s[l1 + l] < s[l2 + l];
		return res2;
	}
};



int main() {
	std::ios_base::sync_with_stdio(false);
	TaskD solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(0);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}