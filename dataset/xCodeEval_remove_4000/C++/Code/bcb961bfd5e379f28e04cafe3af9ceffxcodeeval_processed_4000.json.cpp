














































































using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<typename T> using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template<typename T> using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

using st = std::size_t;
using ui = std::uint32_t;
using ii = std::int32_t;
using ul = std::uint64_t;
using ll = std::int64_t;
using ld = long double;
using cd = std::complex<long double>;

using pst = std::pair<std::size_t, std::size_t>;
using pui = std::pair<std::uint32_t, std::uint32_t>;
using pii = std::pair<std::int32_t, std::int32_t>;
using pul = std::pair<std::uint64_t, std::uint64_t>;
using pll = std::pair<std::int64_t, std::int64_t>;
using pld = std::pair<long double, long double>;
using pcd = std::pair<std::complex<long double>, std::complex<long double>>;

using vst = std::vector<std::size_t>;
using vui = std::vector<std::uint32_t>;
using vii = std::vector<std::int32_t>;
using vul = std::vector<std::uint64_t>;
using vll = std::vector<std::int64_t>;
using vld = std::vector<long double>;
using vcd = std::vector<std::complex<long double>>;

using vvst = std::vector<std::vector<std::size_t>>;
using vvui = std::vector<std::vector<std::uint32_t>>;
using vvii = std::vector<std::vector<std::int32_t>>;
using vvul = std::vector<std::vector<std::uint64_t>>;
using vvll = std::vector<std::vector<std::int64_t>>;
using vvld = std::vector<std::vector<long double>>;
using vvcd = std::vector<std::vector<std::complex<long double>>>;

using vpst = std::vector<std::pair<std::size_t, std::size_t>>;
using vpui = std::vector<std::pair<std::uint32_t, std::uint32_t>>;
using vpii = std::vector<std::pair<std::int32_t, std::int32_t>>;
using vpul = std::vector<std::pair<std::uint64_t, std::uint64_t>>;
using vpll = std::vector<std::pair<std::int64_t, std::int64_t>>;
using vpld = std::vector<std::pair<long double, long double>>;
using vpcd = std::vector<std::pair<std::complex<long double>, std::complex<long double>>>;



















template<typename Arg, typename... Args> Arg min(const Arg& first, const Args& ... rest) { return std::min(first, min(rest...)); }

template<typename Arg, typename... Args> Arg max(const Arg& first, const Args& ... rest) { return std::max(first, min(rest...)); }

template<class T> const T& min(const std::vector<T>& elements) { return *std::min_element(elements.begin(), elements.end()); }

template<class T> const T& max(const std::vector<T>& elements) { return *std::max_element(elements.begin(), elements.end()); }













namespace std
{
	template<class Fun> class id4
	{
		Fun fun_;
	public:
		template<class T> explicit id4(T&& fun): fun_(std::forward<T>(fun)) {}

		template<class ...Args> decltype(auto) operator()(Args&& ...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
	};

	template<class Fun> decltype(auto) id7(Fun&& fun) { return id4<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
}


































template<typename T> T id1(const T& u_element)
{
	
	return __builtin_ctzll(u_element);
	
	T result = 0;
	std::is_unsigned<T>::value ? for(T element = u_element; !(element & 1); element >>= 1, ++result) : for(T element = u_element; element % 2 == 0; element /= 2, ++result);
	return result;
	
}






template<typename T> T id3(const T& u_a, const T& u_b)
{
	T a = std::abs(u_a), b = std::abs(u_b);
	while(b) std::swap(a %= b, b);
	return a;
}



template<typename T> std::tuple<T, T, T> id2(const T& u_a, const T& u_b)
{
	T a = std::abs(u_a), b = std::abs(u_b);
	std::pair<T, T> signs{a / u_a, b / u_b};
	T x = 1, y = 0, x1 = 0, y1 = 1;
	while(b)
	{
		T quotient = a / b;
		std::swap(x -= (quotient * x1), x1);
		std::swap(y -= (quotient * y1), y1);
		std::swap(a -= (quotient * b), b);
	}
	return std::make_tuple(x * signs.first, y * signs.second, a);
}



template<typename T> T id0(const T& u_a, const T u_b)
{
	T a = std::abs(u_a), b = std::abs(u_b);
	if(a == 0) return b;
	if(b == 0) return a;
	T shift = id1(a | b);
	a >>= id1(a);
	do
	{
		b >>= id1(b);
		if(a > b) std::swap(a, b);
		b -= a;
	} while(b);
	return a << shift;
}








template<typename T> class Modular
{
public:

	using Type = typename std::decay<decltype(T::value)>::type;

	constexpr Modular() : value{} {}

	template<typename T1> Modular(const T1& element) : value{normalize(element)} { check(); }

	const Type& operator()() const { return value; }

	template<typename T1> explicit operator T1() const { return static_cast<T1>(value); }

	constexpr static Type modulus() { return T::value; }

	template<typename T1> static Type normalize(const T1& element)
	{
		Type result{-modulus() <= element && element < modulus() ? static_cast<Type>(element) : static_cast<Type>(element % modulus())};
		if(result < 0) result += modulus();
		return result;
	}

	Modular& operator+=(const Modular& other)
	{
		if((value += other()) >= modulus()) value -= modulus();
		return *this;
	}

	Modular& operator-=(const Modular& other)
	{
		if((value -= other()) < 0) value += modulus();
		return *this;
	}

	template<typename T1> Modular& operator+=(const T1& other) { return *this += Modular(other); }

	template<typename T1> Modular& operator-=(const T1& other) { return *this -= Modular(other); }

	Modular& operator++()
	{
		if((*this += 1) == modulus()) *this = 0;
		return *this;
	}

	Modular& operator--()
	{
		if((*this -= 1) == -1) *this = modulus() - 1;
		return *this;
	}

	Modular operator++(int)
	{
		Modular result(*this);
		++(*this);
		return result;
	}

	Modular operator--(int)
	{
		Modular result(*this);
		--(*this);
		return result;
	}

	const Modular operator-() const { return Modular(-value); }

	template<typename T1 = T> typename std::enable_if<(sizeof(typename Modular<T1>::Type) >= 8), Modular&>::type& operator*=(const Modular& rhs)
	{
		typename Modular<T1>::Type quotient = static_cast<typename Modular<T1>::Type>(static_cast<long double>(value) * rhs.value / modulus());
		value = normalize(value * rhs.value - quotient * modulus());
		return *this;
	}

	template<typename T1 = T> typename std::enable_if<(sizeof(typename Modular<T1>::Type) < 8), Modular&>::type& operator*=(const Modular& rhs)
	{
		value = normalize<std::int64_t>(static_cast<std::int64_t>(value) * rhs());
		return *this;
	}

	

	Type multiplicative_inverse(const Type& element)
	{
		auto gcd = id2(normalize(element), modulus());
		assert(std::get<2>(gcd) == 1);
		return std::get<0>(gcd);
	}

	

	std::vector<Type> multiplicative_inverses(const Type& bound = modulus())
	{
		assert(bound > 1);
		std::vector<Type> id6(bound);
		id6[0] = 0;
		id6[1] = 1;
		for(std::size_t i = 2; i < bound; ++i) id6[i] = (modulus() - (modulus() / i) * id6[modulus() % i] % modulus()) % modulus();
		return id6;
	}

	Modular& operator/=(const Modular& other) { return *this *= multiplicative_inverse(other()); }

	Modular& operator^=(const Modular& other)
	{
		assert(other() >= 0);
		Modular result(1);
		Type exponent = other();
		while(exponent)
		{
			if(exponent % 2) result *= *this;
			*this *= *this;
			exponent /= 2;
		}
		return *this = result;
	}

	template<typename T1> friend bool operator==(const Modular<T1>& lhs, const Modular<T1>& rhs);

	template<typename T1> friend bool operator<(const Modular<T1>& lhs, const Modular<T1>& rhs);

	template<typename T1> friend bool operator>(const Modular<T1>& lhs, const Modular<T1>& rhs);

	template<typename T1> friend std::istream& operator>>(std::istream& stream, Modular<T1>& element);

private:
	void check() { assert(std::is_integral<Type>::value&& std::is_signed<Type>::value); }

	Type value;
};

template<typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template<typename T1, typename T2> Modular<T1> operator+(const Modular<T1>& lhs, T2 rhs) { return Modular<T1>(lhs) += rhs; }

template<typename T1, typename T2> Modular<T1> operator+(T2 lhs, const Modular<T1>& rhs) { return Modular<T1>(lhs) += rhs; }

template<typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template<typename T1, typename T2> Modular<T1> operator-(const Modular<T1>& lhs, T2 rhs) { return Modular<T1>(lhs) -= rhs; }

template<typename T1, typename T2> Modular<T1> operator-(T2 lhs, const Modular<T1>& rhs) { return Modular<T1>(lhs) -= rhs; }

template<typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template<typename T1, typename T2> Modular<T1> operator*(const Modular<T1>& lhs, T2 rhs) { return Modular<T1>(lhs) *= rhs; }

template<typename T1, typename T2> Modular<T1> operator*(T2 lhs, const Modular<T1>& rhs) { return Modular<T1>(lhs) *= rhs; }

template<typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T1, typename T2> Modular<T1> operator/(const Modular<T1>& lhs, T2 rhs) { return Modular<T1>(lhs) /= rhs; }

template<typename T1, typename T2> Modular<T1> operator/(T2 lhs, const Modular<T1>& rhs) { return Modular<T1>(lhs) /= rhs; }

template<typename T> Modular<T> operator^(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) ^= rhs; }

template<typename T1, typename T2> Modular<T1> operator^(const Modular<T1>& lhs, T2 rhs) { return Modular<T1>(lhs) ^= rhs; }

template<typename T1, typename T2> Modular<T1> operator^(T2 lhs, const Modular<T1>& rhs) { return Modular<T1>(lhs) ^= rhs; }

template<typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs() == rhs(); }

template<typename T1, typename T2> bool operator==(const Modular<T1>& lhs, T2 rhs) { return lhs == Modular<T1>(rhs); }

template<typename T1, typename T2> bool operator==(T2 lhs, const Modular<T1>& rhs) { return Modular<T1>(lhs) == rhs; }

template<typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template<typename T1, typename T2> bool operator!=(const Modular<T1>& lhs, T2 rhs) { return !(lhs == rhs); }

template<typename T1, typename T2> bool operator!=(T2 lhs, const Modular<T1>& rhs) { return !(lhs == rhs); }

template<typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs() < rhs(); }

template<typename T1, typename T2> bool operator<(const Modular<T1>& lhs, T2 rhs) { return lhs < Modular<T1>(rhs); }

template<typename T1, typename T2> bool operator<(T2 lhs, const Modular<T1>& rhs) { return Modular<T1>(lhs) < rhs; }

template<typename T> bool operator>(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs() > rhs(); }

template<typename T1, typename T2> bool operator>(const Modular<T1>& lhs, T2 rhs) { return lhs > Modular<T1>(rhs); }

template<typename T1, typename T2> bool operator>(T2 lhs, const Modular<T1>& rhs) { return Modular<T1>(lhs) > rhs; }

template<typename T> bool operator<=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs() > rhs()); }

template<typename T1, typename T2> bool operator<=(const Modular<T1>& lhs, T2 rhs) { return !(lhs > Modular<T1>(rhs)); }

template<typename T1, typename T2> bool operator<=(T2 lhs, const Modular<T1>& rhs) { return !(Modular<T1>(lhs) > rhs); }

template<typename T> bool operator>=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs() < rhs()); }

template<typename T1, typename T2> bool operator>=(const Modular<T1>& lhs, T2 rhs) { return !(lhs < Modular<T1>(rhs)); }

template<typename T1, typename T2> bool operator>=(T2 lhs, const Modular<T1>& rhs) { return !(Modular<T1>(lhs) < rhs); }

namespace std { template<typename T> std::string to_string(const Modular<T>& number) { return std::to_string(number()); }}

template<typename T> std::istream& operator>>(std::istream& stream, Modular<T>& element)
{
	typename Modular<T>::Type value;
	stream >> value;
	element.value = Modular<T>::normalize(value);
	return stream;
}

template<typename T> std::ostream& operator<<(std::ostream& stream, const Modular<T>& element) { return stream << element(); }


using ModulusType = ll;

constexpr ModulusType MOD1 id5((unused)) = static_cast<long long>(1000000007);
constexpr ModulusType MOD2 id5((unused)) = static_cast<long long>(998244353);

struct MODULUS { static ModulusType value; };
ModulusType MODULUS::value;
using VariableModulus = Modular<MODULUS>;

struct StaticModulus1 { constexpr static ModulusType value{MOD1}; };
struct StaticModulus2 { constexpr static ModulusType value{MOD2}; };
















namespace std
{

	std::string to_string(const char& element) { return std::string(1, element); }

	std::string to_string(const char *element) { return std::string(element); }

	std::string to_string(const std::string& element) { return element; }

	std::string to_string(const bool& element)
	{

		return element ? "true" : "false";

		return std::string{static_cast<char>('0' + element)};

	}

	template<typename T> std::string to_string(const std::complex<T>& element)
	{
		std::stringstream convert;
		convert << element;
		return convert.str();
	}

	std::string to_string(const std::vector<bool>& elements)
	{
		std::string convert = "{";
		for(const auto& element : elements) convert += static_cast<char>('0' + element);
		return convert + "}";
	}

	template<std::size_t Size> std::string to_string(const std::bitset<Size>& elements)
	{
		std::string convert;
		for(auto i = 0; i < Size; ++i) convert += static_cast<char>('0' + elements[i]);
		return convert;
	}

	template<typename T1, typename T2> std::string to_string(std::pair<T1, T2> element)
	{

		return "(" + std::to_string(element.first) + ", " + std::to_string(element.second) + ")";

		return std::to_string(element.ff) + " " + std::to_string(element.ss);

	}

	template<typename T> std::string to_string(const T& elements)
	{
		std::string convert;
		bool first = true;

		convert += "{";
		for(const auto& element : elements)
		{
			if(!first) convert += ", ";
			first = false;
			convert += std::to_string(element);
		}
		convert += "}";

		for(const auto& element : elements)
		{
			if(!first) convert += " ";
			first = false;
			convert += std::to_string(element);
		}

		return convert;
	}
}



bool inline read(std::istream& in, double& element);

bool inline read(std::istream& in, long double& element);

template<typename Arg, typename... Args> bool inline read(std::istream& in, Arg& first, Args& ... rest);

template<typename T, std::size_t Size> bool inline read(std::istream& in, std::array<T, Size>& elements);

template<typename T1, typename T2> bool inline read(std::istream& in, std::pair<T1, T2>& element);

template<typename T> bool inline read(std::istream& in, T& element);

template<typename T> bool inline read(std::istream& in, std::complex<T>& element);

template<typename T> bool inline read(std::istream& in, std::tuple<T, T, T, T, T, T>& element);

template<typename T> bool inline read(std::istream& in, std::tuple<T, T, T, T, T>& element);

template<typename T> bool inline read(std::istream& in, std::tuple<T, T, T, T>& element);

template<typename T> bool inline read(std::istream& in, std::tuple<T, T, T>& element);

template<typename T> bool inline read(std::istream& in, std::vector<T>& elements);

bool inline read(std::istream& in, double& element)
{
	bool result = true;
	std::string convert;
	result &= read(in, convert);
	element = std::stod(convert);
	return result;
}

bool inline read(std::istream& in, long double& element)
{
	bool result = true;
	std::string convert;
	result &= read(in, convert);
	element = std::stold(convert);
	return result;
}

template<typename Arg, typename... Args> bool inline read(std::istream& in, Arg& first, Args& ... rest)
{
	bool result = true;
	result &= read(in, first);
	result &= read(in, rest...);
	return result;
}

template<typename T, std::size_t Size> bool inline read(std::istream& in, std::array<T, Size>& elements)
{
	bool result = true;
	for(auto& element : elements) result &= read(in, element);
	return result;
}

template<typename T1, typename T2> bool inline read(std::istream& in, std::pair<T1, T2>& element) { return read(in, element.first, element.second); }

template<typename T> bool inline read(std::istream& in, T& element) { return static_cast<bool>(in >> element); }

template<typename T> bool inline read(std::istream& in, std::complex<T>& element)
{
	bool result = true;
	T first, second;
	result &= read(in, first, second);
	element = std::complex<T>(first, second);
	return result;
}

template<typename T> bool inline read(std::istream& in, std::tuple<T, T, T, T, T, T>& element) { return read(in, std::get<0>(element), std::get<1>(element), std::get<2>(element), std::get<3>(element), std::get<4>(element), std::get<5>(element)); }

template<typename T> bool inline read(std::istream& in, std::tuple<T, T, T, T, T>& element) { return read(in, std::get<0>(element), std::get<1>(element), std::get<2>(element), std::get<3>(element), std::get<4>(element)); }

template<typename T> bool inline read(std::istream& in, std::tuple<T, T, T, T>& element) { return read(in, std::get<0>(element), std::get<1>(element), std::get<2>(element), std::get<3>(element)); }

template<typename T> bool inline read(std::istream& in, std::tuple<T, T, T>& element) { return read(in, std::get<0>(element), std::get<1>(element), std::get<2>(element)); }

template<typename T> bool inline read(std::istream& in, std::vector<T>& elements)
{
	bool result = true;
	for(auto& element : elements) result &= read(in, element);
	return result;
}



template<typename Arg, typename... Args> void inline print(std::ostream& out, const Arg& first, const Args& ... rest);

template<typename Arg, typename... Args> void inline printn(std::ostream& out, const Arg& first, const Args& ... rest);

template<typename Arg, typename... Args> void inline prints(std::ostream& out, const Arg& first, const Args& ... rest);

template<typename T> void inline print(std::ostream& out, const T& element);

void inline printn(std::ostream& out);

void inline prints(std::ostream& out);

template<typename Arg, typename... Args> void inline print(std::ostream& out, const Arg& first, const Args& ... rest)
{
	print(out, first);
	print(out, rest...);
}

template<typename Arg, typename... Args> void inline printn(std::ostream& out, const Arg& first, const Args& ... rest)
{
	print(out, first);
	if(sizeof...(rest)) prints(out);
	printn(out, rest...);
}

template<typename Arg, typename... Args> void inline prints(std::ostream& out, const Arg& first, const Args& ... rest)
{
	print(out, first);
	if(sizeof...(rest)) print(out, " ");
	prints(out, rest...);
}

template<typename T> void inline print(std::ostream& out, const T& element) { out << std::to_string(element); }

void inline printn(std::ostream& out) { print(out, '\n'); }

void inline prints(std::ostream& out) { print(out, '\n'); }

void setIO()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin.exceptions(std::ios::eofbit | std::ios::failbit | std::ios::badbit);

}















template<typename Arg, typename... Args> void debug(const Arg& first, const Args& ... rest);

void debug();

template<typename Arg, typename... Args> void debug(const Arg& first, const Args& ... rest)
{
	std::cerr << std::to_string(first);
	if(sizeof...(rest)) std::cerr << ", ";
	debug(rest...);
}

void debug() { std::cerr << "]" << std::endl; }









using namespace std;

constexpr long long MAXN id5((unused)) = static_cast<long long>(2 * 1e5 + 1);
constexpr long long INF id5((unused)) = static_cast<long long>(1e18 + 1);
constexpr long double EPS id5((unused)) = static_cast<long double>(1e-7);








class AMultiplesOfLength
{
	void output_case(std::ostream& out)
	{
		static std::int32_t _testCase = 0;
		print(out, "Case ");
		
		print(out, '
		
		print(out, ++_testCase, ": ");
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		
		output_case(out);
		
		ll n;
		read(in, n);
		vll a(n), change(n, 0);
		read(in, a);
		if(n == 1)
		{
			prints(out, 1, 1);
			printn(out, -a.front());
			prints(out, 1, 1);
			printn(out, 0);
			prints(out, 1, 1);
			printn(out, 0);
		}
		else
		{
			for(ll i = 0; i < n; a[i] *= -1, ++i)
				if(a[i] % n != 0)
				{
					change[i] += (n - 1) * a[i];
					a[i] += (a[i] * (n - 1));
				}
			prints(out, 1, n - 1);
			printn(out, vll(change.begin(), prev(change.end())));
			for(ll i = 0; i < n - 1; ++i) change[i] = 0;
			prints(out, 2, n);
			printn(out, vll(next(change.begin()), change.end()));
			prints(out, 1, n);
			printn(out, a);
		}
	}
	

};

int main()
{
	
	setIO();
	
	AMultiplesOfLength solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	std::fflush(stdout);
	return 0;
}