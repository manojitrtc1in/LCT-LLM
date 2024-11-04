    
     
    
    

     
    

     
    

    #ifndef LOCAL
     
    #include <x86intrin.h>
     
    #pragma GCC optimize("fast-math,no-stack-protector,Ofast,omit-frame-pointer,unroll-loops,inline")
    #pragma GCC option("arch=native,no-zero-upper,tune=native")
    #pragma GCC target("abm,bmi2,mmx,popcnt,sse,sse2,sse3,sse4,ssse3")
     
    #endif
     
    #define NDEBUG
     
    #ifndef GENERAL_HPP
    #define GENERAL_HPP
     
    

    

     
    #ifndef MODULAR_HPP
    #define MODULAR_HPP
     
    

    

     
    #ifndef GCD_HPP
    #define GCD_HPP
     
    #ifndef TRAILING_ZEROS
    #define TRAILING_ZEROS
     
    

    

     
    #include <cstdint>
    #include <type_traits>
     
    template<typename T> T trailing_zeros(const T& u_element)
    {
    	#ifdef __GNUG__
    	return __builtin_ctzll(u_element);
    	#else
    	T result = 0;
    	std::is_unsigned<T>::value ? for(T element = u_element; !(element & 1); element >>= 1, ++result) : for(T element = u_element; element % 2 == 0; element /= 2, ++result);
    	return result;
    	#endif
    }
     
    #endif
     
    #include <tuple>
    #include <utility>
     
    

    template<typename T> T euclidian_gcd(const T& u_a, const T& u_b)
    {
    	T a = std::abs(u_a), b = std::abs(u_b);
    	while(b) std::swap(a %= b, b);
    	return a;
    }
     
    

    template<typename T> std::tuple<T, T, T> extended_euclidian_gcd(const T& u_a, const T& u_b)
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
     
    

    template<typename T> T binary_gcd(const T& u_a, const T u_b)
    {
    	T a = std::abs(u_a), b = std::abs(u_b);
    	if(a == 0) return b;
    	if(b == 0) return a;
    	T shift = trailing_zeros(a | b);
    	a >>= trailing_zeros(a);
    	do
    	{
    		b >>= trailing_zeros(b);
    		if(a > b) std::swap(a, b);
    		b -= a;
    	} while(b);
    	return a << shift;
    }
     
    #endif
     
    #include <cassert>
    #include <cstddef>
     
    #include <iostream>
    #include <string>
     
    #include <vector>
     
    

    

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
    		auto gcd = extended_euclidian_gcd(normalize(element), modulus());
    		assert(std::get<2>(gcd) == 1);
    		return std::get<0>(gcd);
    	}
     
    	

    	std::vector<Type> multiplicative_inverses(const Type& bound = modulus())
    	{
    		assert(bound > 1);
    		std::vector<Type> inverses(bound);
    		inverses[0] = 0;
    		inverses[1] = 1;
    		for(std::size_t i = 2; i < bound; ++i) inverses[i] = (modulus() - (modulus() / i) * inverses[modulus() % i] % modulus()) % modulus();
    		return inverses;
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
     
    #endif
     
    #include <algorithm>
    #include <array>
    #include <bitset>
     
    #include <chrono>
    #include <climits>
    #include <cmath>
    #include <complex>
    #include <cstdarg>
     
    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    #include <ctime>
    #include <deque>
    #include <exception>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    #include <ext/rope>
    #include <forward_list>
    #include <fstream>
    #include <functional>
    #include <initializer_list>
    #include <iomanip>
    #include <ios>
     
    #include <iterator>
    #include <limits>
    #include <list>
    #include <map>
    #include <mutex>
    #include <numeric>
    #include <queue>
    #include <random>
    #include <set>
    #include <sstream>
    #include <stack>
    #include <stdexcept>
     
    #include <thread>
     
    #include <typeinfo>
    #include <unordered_map>
    #include <unordered_set>
     
    #include <valarray>
     
     
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
     
    #define FOR(i, a, b) for (auto (i) = (a); (i) < (b); ++(i))
    #define F0R(i, a) FOR((i), 0, (a))
    #define ROF(i, a, b) for (auto (i) = (a); (i) >= (b); --(i))
    #define R0F(i, a) ROF((i), (a), 0)
    #define ITR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
     
    #define FSRT(set) std::sort(std::begin(set), std::end(set))
    #define RSRT(set) std::sort(std::rbegin(set), std::rend(set))
    #define CSRT(set, function) std::sort(std::begin(set), std::end(set), (function))
    #define UNIQUE(set) std::sort(std::begin(set), std::end(set), (set).erase(std::unique(std::begin(set), std::end(set)), (set).end())
    #define CLR(set, element) memset((set), (element), sizeof((set)))
     
    #define ALL(set) std::begin(set), std::end(set)
    #define RALL(set) std::rbegin(set), std::rend(set)
     
    #define sc static_cast
    #define sz(set) static_cast<std::int32_t>((set).size())
     
    template<typename Arg, typename... Args> Arg min(const Arg& first, const Args& ... rest) { return std::min(first, min(rest...)); }
     
    template<typename Arg, typename... Args> Arg max(const Arg& first, const Args& ... rest) { return std::max(first, min(rest...)); }
     
    template<class T> const T& min(const std::vector<T>& elements) { return *std::min_element(elements.begin(), elements.end()); }
     
    template<class T> const T& max(const std::vector<T>& elements) { return *std::max_element(elements.begin(), elements.end()); }
     
    #define mp std::make_pair
    #define mt std::make_tuple
    #define pb push_back
    #define eb emplace_back
    #define ff first
    #define ss second
    #define lb lower_bound
    #define ub upper_bound
     
    #if __cplusplus >= 201402
     
     
    namespace std
    {
    	template<class Fun> class y_combinator_result
    	{
    		Fun fun_;
    	public:
    		template<class T> explicit y_combinator_result(T&& fun): fun_(std::forward<T>(fun)) {}
     
    		template<class ...Args> decltype(auto) operator()(Args&& ...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
    	};
     
    	template<class Fun> decltype(auto) y_combinator(Fun&& fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
    }
     
    #endif
     
    using ModulusType = ll;
     
    constexpr ModulusType MOD1 __attribute__((unused)) = static_cast<long long>(1000000007);
    constexpr ModulusType MOD2 __attribute__((unused)) = static_cast<long long>(998244353);
     
    struct MODULUS { static ModulusType value; };
    ModulusType MODULUS::value;
    using VariableModulus = Modular<MODULUS>;
     
    struct StaticModulus1 { constexpr static ModulusType value{MOD1}; };
    struct StaticModulus2 { constexpr static ModulusType value{MOD2}; };
     
    #endif
    #ifndef IO_HPP
    #define IO_HPP
     
    

    

     
     
     
     
     
     
     
     
     
     
     
     
     
     
    

    namespace std
    {
     
    	std::string to_string(const char& element) { return std::string(1, element); }
     
    	std::string to_string(const char *element) { return std::string(element); }
     
    	std::string to_string(const std::string& element) { return element; }
     
    	std::string to_string(const bool& element)
    	{
    #ifdef LOCAL
    		return element ? "true" : "false";
    #else
    		return std::string{static_cast<char>('0' + element)};
    #endif
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
    #ifdef LOCAL
    		return "(" + std::to_string(element.first) + ", " + std::to_string(element.second) + ")";
    #else
    		return std::to_string(element.ff) + " " + std::to_string(element.ss);
    #endif
    	}
     
    	template<typename T> std::string to_string(const T& elements)
    	{
    		std::string convert;
    		bool first = true;
    #ifdef LOCAL
    		convert += "{";
    		for(const auto& element : elements)
    		{
    			if(!first) convert += ", ";
    			first = false;
    			convert += std::to_string(element);
    		}
    		convert += "}";
    #else
    		for(const auto& element : elements)
    		{
    			if(!first) convert += " ";
    			first = false;
    			convert += std::to_string(element);
    		}
    #endif
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
    #ifdef LOCAL
    	std::cin.exceptions(std::ios::eofbit | std::ios::failbit | std::ios::badbit);
    #endif
    }
     
    #endif
    #ifndef DEBUG_HPP
    #define DEBUG_HPP
     
    

    

     
     
     
     
    

    template<typename Arg, typename... Args> void debug(const Arg& first, const Args& ... rest);
     
    void debug();
     
    template<typename Arg, typename... Args> void debug(const Arg& first, const Args& ... rest)
    {
    	std::cerr << std::to_string(first);
    	if(sizeof...(rest)) std::cerr << ", ";
    	DBG(rest...);
    }
     
    void debug() { std::cerr << "]" << std::endl; }
     
    #ifdef LOCAL
    #define DEBUG(...) std::cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
    #else
    #define DEBUG(...) 0
    #endif
     
    #endif
     
    using namespace std;
     
    constexpr long long MAXN __attribute__((unused)) = static_cast<long long>(2 * 1e5 + 1);
    constexpr long long INF __attribute__((unused)) = static_cast<long long>(1e18 + 1);
    constexpr long double EPS __attribute__((unused)) = static_cast<long double>(1e-7);
     
    

    

     
    class CPresent
    {
    	void output_case(std::ostream& out)
    	{
    		static int _testCase = 0;
    		print(out, "Case ");
    		#ifdef CODE_JAM
    		print(out, '#');
    		#endif
    		print(out, ++_testCase, ": ");
    	}
     
    public:
    	void solve(std::istream& in, std::ostream& out)
    	{
    		#if defined(CODE_JAM) || defined(LIGHT_OJ)
    		output_case(out);
    		#endif
    		ll n, m, w;
    		read(in, n, m, w);
    		vll a(n);
    		read(in, a);
    		auto check = [&n, &m, &w, &a](const ll& mid) -> bool
    		{
    			vll prefix(n + 1, 0);
    			ll total = 0;
    			for(ll i = 0; i < n; ++i)
    			{
    				if(i) prefix[i] += prefix[i - 1];
    				ll difference = mid - (prefix[i] + a[i]);
    				if(difference > 0)
    				{
    					prefix[i] += difference;
    					prefix[min(i + w, n)] -= difference;
    					total += difference;
    				}
    			}
    			return total <= m;
    		};
    		ll l = 1, r = 1e10;
    		while(r - l > 1)
    		{
    			ll mid = l + (r - l) / 2;
    			(check(mid) ? l : r) = mid;
    		}
    		printn(out, l);
    	}
    	

    };
     
    int main()
    {
    	setIO();
    	CPresent solver;
    	std::istream& in(std::cin);
    	std::ostream& out(std::cout);
    	solver.solve(in, out);
    	std::fflush(stdout);
    	return 0;
    }