#ifndef EMBAILEY_TEMPLATE
#define EMBAILEY_TEMPLATE

#include <assert.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <complex>
#include <chrono>
#include <deque>
#include <forward_list>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string.h>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

#ifdef _MSC_VER
#include <intrin.h>
inline int __builtin_clz(unsigned int value)
{
	return __lzcnt(value);
}
inline int __builtin_clzl(unsigned long int value)
{
	return __lzcnt(value);
}
inline int __builtin_clzll(unsigned long long int value)
{
	return value & 0xffffffff00000000ull ? __lzcnt(static_cast<unsigned long int>(value >> 32)) : 32 + __lzcnt(static_cast<unsigned long int>(value));
}
inline constexpr int __builtin_ctzll(unsigned long long int value);
inline constexpr int __builtin_ctz(unsigned int value)
{
	return __builtin_ctzll(value);
}
inline constexpr int __builtin_ctzl(unsigned long int value)
{
	return __builtin_ctzll(value);
}
inline constexpr int __builtin_ctzll(unsigned long long int value)
{
	assert(value != 0);
	int ctr = 0;
	for (int i = 5; i >= 0; i--)
		if (!(value & ((1ull << i) - 1)))
		{
			ctr |= i;
			value >>= i;
		}
	return ctr;
}
#endif

using namespace std;

template<size_t S, typename... Ts>
struct TupleHashHelper
{
	typedef std::tuple<Ts...> Tup;
	typedef TupleHashHelper<S - 1, Ts...> Helper;
	typedef std::tuple_element_t<S - 1, Tup> T;
	inline constexpr size_t operator()(const Tup& t) const noexcept
	{
		return (size_t)31 * Helper()(t) + std::hash<T>()(std::get<S - 1>(t));
	}
};

template<typename... Ts>
struct TupleHashHelper<0, Ts...>
{
	typedef std::tuple<Ts...> Tup;
	inline constexpr size_t operator()(const Tup&) const noexcept
	{
		return 0;
	}
};

template<typename... Ts>
struct std::hash<tuple<Ts...>>
{
	typedef std::tuple<Ts...> Tup;
	static constexpr size_t S = sizeof...(Ts);
	typedef TupleHashHelper<S, Ts...> Helper;
	inline constexpr size_t operator()(const Tup& t) const noexcept
	{
		return Helper()(t);
	}
};

template<typename T, typename U>
struct std::hash<pair<T, U>>
{
	inline constexpr size_t operator()(const pair<T, U>& p) const noexcept
	{
		return (size_t)31 * hash<T>()(p.first) + hash<U>()(p.second);
	}
};

template<typename T>
struct Vec2
{
	T x, y;

	inline Vec2(T x, T y) :
		x(x), y(y)
	{}

	inline Vec2(const pair<T, T>& xy) :
		Vec2(xy.first, xy.second)
	{}

	inline Vec2(const complex<T>& c) :
		Vec2(c.real(), c.imag())
	{}

	inline Vec2() {}

	inline Vec2 xy()
	{
		return { x, y };
	}

	inline Vec2 yx()
	{
		return { y, x };
	}

	friend Vec2 operator+(const Vec2& a)
	{
		return a;
	}

	friend Vec2 operator-(const Vec2& a)
	{
		return { -a.x, -a.y };
	}

	friend Vec2 operator+(const Vec2& a, const Vec2& b)
	{
		return { a.x + b.x, a.y + b.y };
	}

	friend Vec2 operator-(const Vec2& a, const Vec2& b)
	{
		return { a.x - b.x, a.y - b.y };
	}

	friend Vec2 operator*(const Vec2& a, T b)
	{
		return { a.x * b, a.y * b };
	}

	friend Vec2 operator*(T b, const Vec2& a)
	{
		return { b * a.x, b * a.y };
	}

	friend Vec2 operator/(const Vec2& a, T b)
	{
		return { a.x / b, a.y / b };
	}

	friend Vec2 operator%(const Vec2& a, T b)
	{
		return { a.x % b, a.y % b };
	}

	friend T operator*(const Vec2& a, const Vec2& b)
	{
		return a.x * b.x + a.y * b.y;
	}

	friend T operator^(const Vec2& a, const Vec2& b)
	{
		return a.x * b.y - a.y * b.x;
	}

	friend Vec2& operator+=(Vec2& a, const Vec2& b)
	{
		a.x += b.x;
		a.y += b.y;
		return a;
	}

	friend Vec2& operator-=(Vec2& a, const Vec2& b)
	{
		a.x -= b.x;
		a.y -= b.y;
		return a;
	}

	friend Vec2& operator*=(Vec2& a, const T& b)
	{
		a.x *= b;
		a.y *= b;
		return a;
	}

	friend Vec2& operator/=(Vec2& a, const T& b)
	{
		a.x /= b;
		a.y /= b;
		return a;
	}

	friend Vec2& operator%=(Vec2& a, const T& b)
	{
		a.x %= b;
		a.y %= b;
		return a;
	}

	friend istream& operator>>(istream& a, Vec2& b)
	{
		return a >> b.x >> b.y;
	}

	friend ostream& operator<<(ostream& a, const Vec2& b)
	{
		streamsize w = a.width();
		return a << b.x << ' ' << setw(w) << b.y;
	}

	template<typename U>
	inline operator Vec2<U>()
	{
		return { x, y };
	}

	inline operator pair<T, T>()
	{
		return { x, y };
	}

	inline operator complex<T>()
	{
		return { x, y };
	}

	inline T mag2() const
	{
		return(*this) * (*this);
	}

	friend T mag2(const Vec2& a)
	{
		return a.mag2();
	}

	inline T mag() const
	{
		return sqrt(mag2());
	}

	friend T mag(const Vec2& a)
	{
		return a.mag();
	}

	friend T dist(const Vec2& a, const Vec2& b)
	{
		return mag(a - b);
	}

	inline T arg() const
	{
		return atan2(y, x);
	}

	friend T arg(const Vec2& a)
	{
		return a.arg();
	}

	friend bool operator==(const Vec2& a, const Vec2& b)
	{
		return a.x == b.y && a.y == b.y;
	}

	friend bool operator!=(const Vec2& a, const Vec2& b)
	{
		return a.x != b.x || a.y != b.y;
	}

	inline operator bool() const
	{
		return x || y;
	}

	inline bool operator!() const
	{
		return !x && !y;
	}
};

template<typename T>
struct Vec3
{
	T x, y, z;

	inline Vec3(T x, T y, T z) :
		x(x), y(y), z(z)
	{}

	inline Vec3(const tuple<T, T, T>& xyz) :
		Vec3(get<0>(xyz), get<1>(xyz), get<2>(xyz))
	{}

	inline Vec3() {}

	inline Vec2<T> xy()
	{
		return { x, y };
	}

	inline Vec2<T> yx()
	{
		return { y, x };
	}

	inline Vec2<T> xz()
	{
		return { x, z };
	}

	inline Vec2<T> zx()
	{
		return { z, x };
	}

	inline Vec2<T> yz()
	{
		return { y, z };
	}

	inline Vec2<T> zy()
	{
		return { z, y };
	}

	inline Vec3 xyz()
	{
		return { x, y, z };
	}

	inline Vec3 yxz()
	{
		return { y, x, z };
	}

	inline Vec3 xzy()
	{
		return { x, z, y };
	}

	inline Vec3 zxy()
	{
		return { z, x, y };
	}

	inline Vec3 yzx()
	{
		return { y, z, x };
	}

	inline Vec3 zyx()
	{
		return { z, y, x };
	}

	friend Vec3 operator+(const Vec3& a)
	{
		return a;
	}

	friend Vec3 operator-(const Vec3& a)
	{
		return { -a.x, -a.y, -a.z };
	}

	friend Vec3 operator+(const Vec3& a, const Vec3& b)
	{
		return { a.x + b.x, a.y + b.y, a.z + b.z };
	}

	friend Vec3 operator*(const Vec3& a, T b)
	{
		return { a.x * b, a.y * b, a.z * b };
	}

	friend Vec3 operator*(T b, const Vec3& a)
	{
		return { b * a.x, b * a.y, b * a.z };
	}

	friend Vec3 operator/(const Vec3& a, T b)
	{
		return { a.x / b, a.y / b, a.z / b };
	}

	friend Vec3 operator%(const Vec3& a, T b)
	{
		return { a.x % b, a.y % b, a.z % b };
	}

	friend T operator*(const Vec3& a, const Vec3& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	friend T operator^(const Vec3& a, const Vec3& b)
	{
		return { a.xy() ^ b.xy(), a.zx() ^ b.zx(), a.yz() ^ b.yz() };
	}

	friend Vec3& operator+=(Vec3& a, const Vec3& b)
	{
		a.x += b.x;
		a.y += b.y;
		a.z += b.z;
		return a;
	}

	friend Vec3& operator-=(Vec3& a, const Vec3& b)
	{
		a.x -= b.x;
		a.y -= b.y;
		a.z -= b.z;
		return a;
	}

	friend Vec3& operator*=(Vec3& a, const T& b)
	{
		a.x *= b;
		a.y *= b;
		a.z *= b;
		return a;
	}

	friend Vec3& operator/=(Vec3& a, const T& b)
	{
		a.x /= b;
		a.y /= b;
		a.z /= b;
		return a;
	}

	friend Vec3& operator%=(Vec3& a, const T& b)
	{
		a.x %= b;
		a.y %= b;
		a.z %= b;
		return a;
	}

	friend Vec3& operator^=(Vec3& a, const Vec3& b)
	{
		return a = a ^ b;
	}

	friend istream& operator>>(istream& a, Vec3& b)
	{
		return a >> b.x >> b.y >> b.z;
	}

	friend ostream& operator<<(ostream& a, const Vec3& b)
	{
		streamsize w = a.width();
		return a << b.x << ' ' << setw(w) << b.y << ' ' << setw(w) << b.z;
	}

	template<typename U>
	inline operator Vec3<U>()
	{
		return { x, y, z };
	}

	inline operator tuple<T, T, T>()
	{
		return { x, y, z };
	}

	inline T mag2() const
	{
		return (*this) * (*this);
	}

	friend T mag2(const Vec3& a)
	{
		return a.mag2();
	}

	inline T mag() const
	{
		return sqrt(mag2());
	}

	friend T mag(const Vec3& a)
	{
		return a.mag();
	}

	friend T dist(const Vec3& a, const Vec3& b)
	{
		return mag(a - b);
	}

	friend bool operator==(const Vec3& a, const Vec3& b)
	{
		return a.x == b.x && a.y == b.y && a.z == b.z;
	}

	friend bool operator!=(const Vec3& a, const Vec3& b)
	{
		return a.x != b.x || a.y != b.y || a.z != b.z;
	}

	inline operator bool() const
	{
		return x || y || z;
	}

	inline bool operator!() const
	{
		return !x && !y && !z;
	}
};

template<typename T>
inline constexpr T rup2(T x)
{
	x--;
	for (size_t i = 1; i < 8 * sizeof(T); i *= 2)
		x |= x >> i;
	return x + 1;
}

struct default_layered_indexer
{
	template<typename S>
	inline constexpr S operator()(S l, S i)
	{
		return i;
	}
};





template<typename T, typename Op = plus<T>, typename Idx = default_layered_indexer, typename Alloc = std::allocator<T>>
class segtree
{
public:
	using operation = Op;
	using value_type = typename vector<T, Alloc>::value_type;
	using allocator_type = typename vector<T, Alloc>::allocator_type;
	using size_type = typename vector<T, Alloc>::size_type;
	using difference_type = typename vector<T, Alloc>::difference_type;
	using reference = typename vector<T, Alloc>::reference;
	using const_reference = typename vector<T, Alloc>::const_reference;
	using pointer = typename vector<T, Alloc>::pointer;
	using const_pointer = typename vector<T, Alloc>::const_pointer;
	using const_iterator = typename vector<T, Alloc>::const_iterator;

private:
	static_assert(std::is_invocable_v<Op, T, T, size_type, size_type> || std::is_invocable_v<Op, T, T>);

	vector<vector<T, Alloc>> _layers;
	Op _op;
	Idx _idx;

	inline constexpr T doOp(const T& l, const T& r, size_type ls, size_type rs) const
	{
		if constexpr (std::is_invocable_v<Op, T, T, size_type, size_type>)
			return _op(l, r, ls, rs);
		else
			return _op(l, r);
	}

	inline constexpr size_type doIdx(size_type l, size_type i) const
	{
		assert(0 <= l);
		assert(l < _layers.size());
		assert(0 <= i);
		assert(i < _layers[l].size());
		size_type j = _idx(l, i);
		assert(0 <= j);
		assert(j < _layers[l].size());
		return j;
	}

	inline constexpr size_type layerSize(size_type l)
	{
		assert(0 <= l);
		assert(l < _layers.size());
		return 1 << (_layers.size() - 1 - l);
	}

	inline constexpr size_type nodeSize(size_type l, size_type i)
	{
		size_t ls = layerSize(l);
		assert(0 <= i);
		assert(i < _layers[l].size());
		if (i < _layers[l].size() - 1 || _layers.back().size())
			return ls;
		size_t rem = _layers.back().size() % ls;
		return rem == 0 ? ls : rem;
	}

	inline void update(size_type l, size_type i)
	{
		size_type n = _layers[l + 1].size();
		size_type j = doIdx(l + 1, i * 2), k = doIdx(l + 1, i * 2 + 1);
		assert(l <= _layers.size() - 2);
		assert(j < n);
		if (k < n)
			_layers[l][doIdx(l, i)] = doOp(_layers[l + 1][j], _layers[l + 1][k], nodeSize(l + 1, j), nodeSize(l + 1, k));
		else
			_layers[l][doIdx(l, i)] = _layers[l + 1][j];
	}

	inline void init(vector<T, Alloc>&& leaves)
	{
		_layers.clear();

		size_type n = leaves.size();
		for (size_type s = rup2(n); s > 1; s /= 2)
			_layers.emplace_back((n + s - 1) / s);
		_layers.emplace_back(move(leaves));

		size_type m = (n + 1) / 2;
		for (size_type l = _layers.size() - 1; l-- > 0; n = m, m = (m + 1) / 2)
			for (size_type i = 0; i < m; i++)
				update(l, i);
	}

	inline void updateAncestors(size_type idx)
	{
		for (size_type l = _layers.size() - 1, i = idx / 2; l-- > 0; i /= 2)
			update(l, i);
	}

	inline void updateAncestors(size_type first, size_type last)
	{
		assert(first <= last);
		if (first == last)
			return;
		for (size_type l = _layers.size() - 1, i = first / 2, j = last / 2; l-- > 0; i /= 2, j /= 2)
			for (size_type k = i; k <= j; k++)
				update(l, k);
	}

public:
	template<typename... Args>
	inline segtree(const Op& op = Op{}, const Idx& idx = Idx{}, Args&&... args) :
		_op(op),
		_idx(idx)
	{
		init(vector<T, Alloc>(forward<Args>(args)...));
	}

	explicit inline segtree(size_type count, const Op& op = Op{}, const Idx& idx = Idx{}) :
		segtree(op, idx, count)
	{}

	inline segtree(size_type count, const T& value, const Op& op = Op{}, const Idx& idx = Idx{}) :
		segtree(op, idx, count, value)
	{}

	template<typename It>
	inline segtree(It first, It last, const Op& op = Op{}, const Idx& idx = Idx{}) :
		segtree(op, idx, first, last)
	{}

	inline segtree(vector<T>&& leaves, const Op& op = Op{}, const Idx& idx = Idx{}) :
		segtree(op, idx, forward<vector<T>>(leaves))
	{}

	inline segtree(initializer_list<T> init, const Op& op = Op{}, const Idx& idx = Idx{}) :
		segtree(op, idx, init.begin(), init.end())
	{}

	inline bool empty() const
	{
		return _layers.back().empty() == 0;
	}

	inline size_type size() const
	{
		return _layers.back().size();
	}

	inline size_type max_size() const
	{
		return vector<T, Alloc>().max_size();
	}

private:
	struct PointProxy
	{
		friend class segtree;
	private:
		segtree& _st;
		const size_type _i, _j;

		inline PointProxy(segtree& st, size_type i) :
			_st(st),
			_i(i),
			_j(_st.doIdx(_st._layers.size() - 1, i))
		{}

	public:
		inline PointProxy& operator=(T&& arg)
		{
			_st._layers.back()[_j] = forward<T>(arg);
			_st.updateAncestors(_i);
			return *this;
		}

		inline PointProxy& operator+=(T&& arg)
		{
			_st._layers.back()[_j] += forward<T>(arg);
			_st.updateAncestors(_i);
			return *this;
		}

		inline PointProxy& operator-=(T&& arg)
		{
			_st._layers.back()[_j] -= forward<T>(arg);
			_st.updateAncestors(_i);
			return *this;
		}

		inline PointProxy& operator*=(T&& arg)
		{
			_st._layers.back()[_j] *= forward<T>(arg);
			_st.updateAncestors(_i);
			return *this;
		}

		inline PointProxy& operator/=(T&& arg)
		{
			_st._layers.back()[_j] /= forward<T>(arg);
			_st.updateAncestors(_i);
			return *this;
		}

		inline PointProxy& operator%=(T&& arg)
		{
			_st._layers.back()[_j] %= forward<T>(arg);
			_st.updateAncestors(_i);
			return *this;
		}

		inline PointProxy& operator&=(T&& arg)
		{
			_st._layers.back()[_j] &= forward<T>(arg);
			_st.updateAncestors(_i);
			return *this;
		}

		inline PointProxy& operator|=(T&& arg)
		{
			_st._layers.back()[_j] |= forward<T>(arg);
			_st.updateAncestors(_i);
			return *this;
		}

		inline PointProxy& operator^=(T&& arg)
		{
			_st._layers.back()[_j] ^= forward<T>(arg);
			_st.updateAncestors(_i);
			return *this;
		}

		inline PointProxy& operator>>=(T&& arg)
		{
			_st._layers.back()[_j] >>= forward<T>(arg);
			_st.updateAncestors(_i);
			return *this;
		}

		inline PointProxy& operator<<=(T&& arg)
		{
			_st._layers.back()[_j] <<= forward<T>(arg);
			_st.updateAncestors(_i);
			return *this;
		}

		inline PointProxy& operator=(const T& arg)
		{
			_st._layers.back()[_j] = arg;
			_st.updateAncestors(_i);
			return *this;
		}

		inline PointProxy& operator+=(const T& arg)
		{
			_st._layers.back()[_j] += arg;
			_st.updateAncestors(_i);
			return *this;
		}

		inline PointProxy& operator-=(const T& arg)
		{
			_st._layers.back()[_j] -= arg;
			_st.updateAncestors(_i);
			return *this;
		}

		inline PointProxy& operator*=(const T& arg)
		{
			_st._layers.back()[_j] *= arg;
			_st.updateAncestors(_i);
			return *this;
		}

		inline PointProxy& operator/=(const T& arg)
		{
			_st._layers.back()[_j] /= arg;
			_st.updateAncestors(_i);
			return *this;
		}

		inline PointProxy& operator%=(const T& arg)
		{
			_st._layers.back()[_j] %= arg;
			_st.updateAncestors(_i);
			return *this;
		}

		inline PointProxy& operator&=(const T& arg)
		{
			_st._layers.back()[_j] &= arg;
			_st.updateAncestors(_i);
			return *this;
		}

		inline PointProxy& operator|=(const T& arg)
		{
			_st._layers.back()[_j] |= arg;
			_st.updateAncestors(_i);
			return *this;
		}

		inline PointProxy& operator^=(const T& arg)
		{
			_st._layers.back()[_j] ^= arg;
			_st.updateAncestors(_i);
			return *this;
		}

		inline PointProxy& operator>>=(const T& arg)
		{
			_st._layers.back()[_j] >>= arg;
			_st.updateAncestors(_i);
			return *this;
		}

		inline PointProxy& operator<<=(const T& arg)
		{
			_st._layers.back()[_j] <<= arg;
			_st.updateAncestors(_i);
			return *this;
		}

		inline PointProxy& operator++()
		{
			++_st._layers.back()[_j];
			_st.updateAncestors(_i);
			return *this;
		}

		inline PointProxy& operator--()
		{
			--_st._layers.back()[_j];
			_st.updateAncestors(_i);
			return *this;
		}

		inline T operator++(int)
		{
			T ans = _st._layers.back()[_j]++;
			_st.updateAncestors(_i);
			return ans;
		}

		inline T operator--(int)
		{
			T ans = _st._layers.back()[_j]--;
			_st.updateAncestors(_i);
			return ans;
		}

		inline operator const T& () const
		{
			return _st._layers.back()[_j];
		}
	};

public:
	inline PointProxy operator[](size_type i)
	{
		return PointProxy(*this, i);
	}

	inline const T& operator[](size_type i) const
	{
		_layers.back()[doIdx(_layers.size() - 1, i)];
	}

private:
	inline T query(size_type first, size_type last, size_type nfirst, size_type nlast, size_type l, size_type i, size_type p2)
	{
		assert(0 <= nfirst);
		assert(nfirst <= first);
		assert(first < last);
		assert(last <= nlast);
		assert(nlast <= size());
		assert(0 <= l);
		assert(l < _layers.size());
		assert(0 <= i);
		assert(i < _layers[l].size());

		if (first == nfirst && last == nlast)
			return _layers[l][doIdx(l, i)];

		size_type j = i * 2, k = i * 2 + 1;
		size_type mid = nfirst + p2 / 2;
		bool gol = first < mid;
		bool gor = mid < last;

		assert(l + 1 < _layers.size());
		assert(!gol || j < _layers[l + 1].size());
		assert(!gor || k < _layers[l + 1].size());
		assert(gol || gor);

		size_type first1 = first, last1 = min(last, mid), first2 = max(first, mid), last2 = last;
		if (gol && gor)
		{
			T la = query(first1, last1, nfirst, mid, l + 1, j, p2 / 2);
			T ra = query(first2, last2, mid, nlast, l + 1, k, p2 / 2);
			return doOp(la, ra, last1 - first1, last2 - first2);
		}
		else if (gol)
			return query(first1, last1, nfirst, min(nlast, mid), l + 1, j, p2 / 2);
		else 

			return query(first2, last2, mid, nlast, l + 1, k, p2 / 2);
	}

public:
	inline T operator()(size_type first, size_type last)
	{
		if (first == last)
			return T{};
		return query(first, last, 0, size(), 0, 0, 1 << (_layers.size() - 1));
	}

	inline const vector<vector<T, Alloc>>& layers() const
	{
		return _layers;
	}

	inline Op& op()
	{
		return _op;
	}

	inline const Op& op() const
	{
		return _op;
	}

	inline Idx& idx()
	{
		return _idx;
	}

	inline const Idx& idx() const
	{
		return _idx;
	}

	inline string debug_dump(int w) const
	{
		stringstream ans;
		string sp(w, ' ');
		for (int l = 0; l < _layers.size(); l++)
		{
			for (int i = 0; i < _layers[l].size(); i++)
			{
				ans << setw(w) << _layers[l][doIdx(l, i)];
				for (int j = 1; j < nodeSize(l, i); j++)
					ans << sp;
			}
			ans << endl;
		}
		return ans.str();
	}
};

using bl = bool;
using i8 = int8_t;
using u8 = uint8_t;
using i16 = int16_t;
using u16 = uint16_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f32 = float;
using f64 = double;
using str8 = string;
using pbl = pair<bl, bl>;
using pi8 = pair<i8, i8>;
using pu8 = pair<u8, u8>;
using pi16 = pair<i16, i16>;
using pu16 = pair<u16, u16>;
using pi32 = pair<i32, i32>;
using pu32 = pair<u32, u32>;
using pi64 = pair<i64, i64>;
using pu64 = pair<u64, u64>;
using pf32 = pair<f32, f32>;
using pf64 = pair<f64, f64>;
using pstr8 = pair<str8, str8>;

using vbl = vector<bl>;
using vi8 = vector<i8>;
using vu8 = vector<u8>;
using vi16 = vector<i16>;
using vu16 = vector<u16>;
using vi32 = vector<i32>;
using vu32 = vector<u32>;
using vi64 = vector<i64>;
using vu64 = vector<u64>;
using vf32 = vector<f32>;
using vf64 = vector<f64>;
using vstr8 = vector<str8>;
using vpbl = vector<pbl>;
using vpi8 = vector<pi8>;
using vpu8 = vector<pu8>;
using vpi16 = vector<pi16>;
using vpu16 = vector<pu16>;
using vpi32 = vector<pi32>;
using vpu32 = vector<pu32>;
using vpi64 = vector<pi64>;
using vpu64 = vector<pu64>;
using vpf32 = vector<pf32>;
using vpf64 = vector<pf64>;
using vpstr8 = vector<pstr8>;

using vvbl = vector<vector<bl>>;
using vvi8 = vector<vi8>;
using vvu8 = vector<vu8>;
using vvi16 = vector<vi16>;
using vvu16 = vector<vu16>;
using vvi32 = vector<vi32>;
using vvu32 = vector<vu32>;
using vvi64 = vector<vi64>;
using vvu64 = vector<vu64>;
using vvf32 = vector<vf32>;
using vvf64 = vector<vf64>;
using vvstr8 = vector<str8>;
using vvpbl = vector<vpbl>;
using vvpi8 = vector<vpi8>;
using vvpu8 = vector<vpu8>;
using vvpi16 = vector<vpi16>;
using vvpu16 = vector<vpu16>;
using vvpi32 = vector<vpi32>;
using vvpu32 = vector<vpu32>;
using vvpi64 = vector<vpi64>;
using vvpu64 = vector<vpu64>;
using vvpf32 = vector<vpf32>;
using vvpf64 = vector<vpf64>;
using vvpstr8 = vector<vpstr8>;

using vvvbl = vector<vvbl>;
using vvvi8 = vector<vvi8>;
using vvvu8 = vector<vvu8>;
using vvvi16 = vector<vvi16>;
using vvvu16 = vector<vvu16>;
using vvvi32 = vector<vvi32>;
using vvvu32 = vector<vvu32>;
using vvvi64 = vector<vvi64>;
using vvvu64 = vector<vvu64>;
using vvvf32 = vector<vvf32>;
using vvvf64 = vector<vvf64>;
using vvvstr8 = vector<vvstr8>;
using vvvpbl = vector<vvpbl>;
using vvvpi8 = vector<vvpi8>;
using vvvpu8 = vector<vvpu8>;
using vvvpi16 = vector<vvpi16>;
using vvvpu16 = vector<vvpu16>;
using vvvpi32 = vector<vvpi32>;
using vvvpu32 = vector<vvpu32>;
using vvvpi64 = vector<vvpi64>;
using vvvpu64 = vector<vvpu64>;
using vvvpf32 = vector<vvpf32>;
using vvvpf64 = vector<vvpf64>;
using vvvpstr8 = vector<vvpstr8>;

using vvvvbl = vector<vvvbl>;
using vvvvi8 = vector<vvvi8>;
using vvvvu8 = vector<vvvu8>;
using vvvvi16 = vector<vvvi16>;
using vvvvu16 = vector<vvvu16>;
using vvvvi32 = vector<vvvi32>;
using vvvvu32 = vector<vvvu32>;
using vvvvi64 = vector<vvvi64>;
using vvvvu64 = vector<vvvu64>;
using vvvvf32 = vector<vvvf32>;
using vvvvf64 = vector<vvvf64>;
using vvvvstr8 = vector<vvvstr8>;
using vvvvpbl = vector<vvvpbl>;
using vvvvpi8 = vector<vvvpi8>;
using vvvvpu8 = vector<vvvpu8>;
using vvvvpi16 = vector<vvvpi16>;
using vvvvpu16 = vector<vvvpu16>;
using vvvvpi32 = vector<vvvpi32>;
using vvvvpu32 = vector<vvvpu32>;
using vvvvpi64 = vector<vvvpi64>;
using vvvvpu64 = vector<vvvpu64>;
using vvvvpf32 = vector<vvvpf32>;
using vvvvpf64 = vector<vvvpf64>;
using vvvvpstr8 = vector<vvvpstr8>;

using lbl = list<bl>;
using li8 = list<i8>;
using lu8 = list<u8>;
using li16 = list<i16>;
using lu16 = list<u16>;
using li32 = list<i32>;
using lu32 = list<u32>;
using li64 = list<i64>;
using lu64 = list<u64>;
using lf32 = list<f32>;
using lf64 = list<f64>;
using lstr8 = list<str8>;
using lpbl = list<pbl>;
using lpi8 = list<pi8>;
using lpu8 = list<pu8>;
using lpi16 = list<pi16>;
using lpu16 = list<pu16>;
using lpi32 = list<pi32>;
using lpu32 = list<pu32>;
using lpi64 = list<pi64>;
using lpu64 = list<pu64>;
using lpf32 = list<pf32>;
using lpf64 = list<pf64>;
using lpstr8 = list<pstr8>;

using sbl = set<bl>;
using si8 = set<i8>;
using su8 = set<u8>;
using si16 = set<i16>;
using su16 = set<u16>;
using si32 = set<i32>;
using su32 = set<u32>;
using si64 = set<i64>;
using su64 = set<u64>;
using sf32 = set<f32>;
using sf64 = set<f64>;
using sstr8 = set<str8>;
using spbl = set<pbl>;
using spi8 = set<pi8>;
using spu8 = set<pu8>;
using spi16 = set<pi16>;
using spu16 = set<pu16>;
using spi32 = set<pi32>;
using spu32 = set<pu32>;
using spi64 = set<pi64>;
using spu64 = set<pu64>;
using spf32 = set<pf32>;
using spf64 = set<pf64>;
using spstr8 = set<pstr8>;

template<typename Pred = less<bl>> using Sbl = set<bl, Pred>;
template<typename Pred = less<i8>> using Si8 = set<i8, Pred>;
template<typename Pred = less<u8>> using Su8 = set<u8, Pred>;
template<typename Pred = less<i16>> using Si16 = set<i16, Pred>;
template<typename Pred = less<u16>> using Su16 = set<u16, Pred>;
template<typename Pred = less<i32>> using Si32 = set<i32, Pred>;
template<typename Pred = less<u32>> using Su32 = set<u32, Pred>;
template<typename Pred = less<i64>> using Si64 = set<i64, Pred>;
template<typename Pred = less<u64>> using Su64 = set<u64, Pred>;
template<typename Pred = less<f32>> using Sf32 = set<f32, Pred>;
template<typename Pred = less<f64>> using Sf64 = set<f64, Pred>;
template<typename Pred = less<str8>> using Sstr8 = set<str8, Pred>;
template<typename Pred = less<pbl>> using Spbl = set<pbl, Pred>;
template<typename Pred = less<pi8>> using Spi8 = set<pi8, Pred>;
template<typename Pred = less<pu8>> using Spu8 = set<pu8, Pred>;
template<typename Pred = less<pi16>> using Spi16 = set<pi16, Pred>;
template<typename Pred = less<pu16>> using Spu16 = set<pu16, Pred>;
template<typename Pred = less<pi32>> using Spi32 = set<pi32, Pred>;
template<typename Pred = less<pu32>> using Spu32 = set<pu32, Pred>;
template<typename Pred = less<pi64>> using Spi64 = set<pi64, Pred>;
template<typename Pred = less<pu64>> using Spu64 = set<pu64, Pred>;
template<typename Pred = less<pf32>> using Spf32 = set<pf32, Pred>;
template<typename Pred = less<pf64>> using Spf64 = set<pf64, Pred>;
template<typename Pred = less<pstr8>> using Spstr8 = set<pstr8, Pred>;

using msbl = multiset<bl>;
using msi8 = multiset<i8>;
using msu8 = multiset<u8>;
using msi16 = multiset<i16>;
using msu16 = multiset<u16>;
using msi32 = multiset<i32>;
using msu32 = multiset<u32>;
using msi64 = multiset<i64>;
using msu64 = multiset<u64>;
using msf32 = multiset<f32>;
using msf64 = multiset<f64>;
using msstr8 = multiset<str8>;
using mspbl = multiset<pbl>;
using mspi8 = multiset<pi8>;
using mspu8 = multiset<pu8>;
using mspi16 = multiset<pi16>;
using mspu16 = multiset<pu16>;
using mspi32 = multiset<pi32>;
using mspu32 = multiset<pu32>;
using mspi64 = multiset<pi64>;
using mspu64 = multiset<pu64>;
using mspf32 = multiset<pf32>;
using mspf64 = multiset<pf64>;
using mspstr8 = multiset<pstr8>;

template<typename Pred = less<bl>> using MSbl = multiset<bl, Pred>;
template<typename Pred = less<i8>> using MSi8 = multiset<i8, Pred>;
template<typename Pred = less<u8>> using MSu8 = multiset<u8, Pred>;
template<typename Pred = less<i16>> using MSi16 = multiset<i16, Pred>;
template<typename Pred = less<u16>> using MSu16 = multiset<u16, Pred>;
template<typename Pred = less<i32>> using MSi32 = multiset<i32, Pred>;
template<typename Pred = less<u32>> using MSu32 = multiset<u32, Pred>;
template<typename Pred = less<i64>> using MSi64 = multiset<i64, Pred>;
template<typename Pred = less<u64>> using MSu64 = multiset<u64, Pred>;
template<typename Pred = less<f32>> using MSf32 = multiset<f32, Pred>;
template<typename Pred = less<f64>> using MSf64 = multiset<f64, Pred>;
template<typename Pred = less<str8>> using MSstr8 = multiset<str8, Pred>;
template<typename Pred = less<pbl>> using MSpbl = multiset<pbl, Pred>;
template<typename Pred = less<pi8>> using MSpi8 = multiset<pi8, Pred>;
template<typename Pred = less<pu8>> using MSpu8 = multiset<pu8, Pred>;
template<typename Pred = less<pi16>> using MSpi16 = multiset<pi16, Pred>;
template<typename Pred = less<pu16>> using MSpu16 = multiset<pu16, Pred>;
template<typename Pred = less<pi32>> using MSpi32 = multiset<pi32, Pred>;
template<typename Pred = less<pu32>> using MSpu32 = multiset<pu32, Pred>;
template<typename Pred = less<pi64>> using MSpi64 = multiset<pi64, Pred>;
template<typename Pred = less<pu64>> using MSpu64 = multiset<pu64, Pred>;
template<typename Pred = less<pf32>> using MSpf32 = multiset<pf32, Pred>;
template<typename Pred = less<pf64>> using MSpf64 = multiset<pf64, Pred>;
template<typename Pred = less<pstr8>> using MSpstr8 = multiset<pstr8, Pred>;

using usbl = unordered_set<bl>;
using usi8 = unordered_set<i8>;
using usu8 = unordered_set<u8>;
using usi16 = unordered_set<i16>;
using usu16 = unordered_set<u16>;
using usi32 = unordered_set<i32>;
using usu32 = unordered_set<u32>;
using usi64 = unordered_set<i64>;
using usu64 = unordered_set<u64>;
using usf32 = unordered_set<f32>;
using usf64 = unordered_set<f64>;
using usstr8 = unordered_set<str8>;
using uspbl = unordered_set<pbl>;
using uspi8 = unordered_set<pi8>;
using uspu8 = unordered_set<pu8>;
using uspi16 = unordered_set<pi16>;
using uspu16 = unordered_set<pu16>;
using uspi32 = unordered_set<pi32>;
using uspu32 = unordered_set<pu32>;
using uspi64 = unordered_set<pi64>;
using uspu64 = unordered_set<pu64>;
using uspf32 = unordered_set<pf32>;
using uspf64 = unordered_set<pf64>;
using uspstr8 = unordered_set<pstr8>;

template<typename Hasher = hash<bl>, typename Keyeq = equal_to<bl>> using USbl = unordered_set<bl, Hasher, Keyeq>;
template<typename Hasher = hash<i8>, typename Keyeq = equal_to<i8>> using USi8 = unordered_set<i8, Hasher, Keyeq>;
template<typename Hasher = hash<u8>, typename Keyeq = equal_to<u8>> using USu8 = unordered_set<u8, Hasher, Keyeq>;
template<typename Hasher = hash<i16>, typename Keyeq = equal_to<i16>> using USi16 = unordered_set<i16, Hasher, Keyeq>;
template<typename Hasher = hash<u16>, typename Keyeq = equal_to<u16>> using USu16 = unordered_set<u16, Hasher, Keyeq>;
template<typename Hasher = hash<i32>, typename Keyeq = equal_to<i32>> using USi32 = unordered_set<i32, Hasher, Keyeq>;
template<typename Hasher = hash<u32>, typename Keyeq = equal_to<u32>> using USu32 = unordered_set<u32, Hasher, Keyeq>;
template<typename Hasher = hash<i64>, typename Keyeq = equal_to<i64>> using USi64 = unordered_set<i64, Hasher, Keyeq>;
template<typename Hasher = hash<u64>, typename Keyeq = equal_to<u64>> using USu64 = unordered_set<u64, Hasher, Keyeq>;
template<typename Hasher = hash<f32>, typename Keyeq = equal_to<f32>> using USf32 = unordered_set<f32, Hasher, Keyeq>;
template<typename Hasher = hash<f64>, typename Keyeq = equal_to<f64>> using USf64 = unordered_set<f64, Hasher, Keyeq>;
template<typename Hasher = hash<str8>, typename Keyeq = equal_to<str8>> using USstr8 = unordered_set<str8, Hasher, Keyeq>;
template<typename Hasher = hash<pbl>, typename Keyeq = equal_to<pbl>> using USpbl = unordered_set<pbl, Hasher, Keyeq>;
template<typename Hasher = hash<pi8>, typename Keyeq = equal_to<pi8>> using USpi8 = unordered_set<pi8, Hasher, Keyeq>;
template<typename Hasher = hash<pu8>, typename Keyeq = equal_to<pu8>> using USpu8 = unordered_set<pu8, Hasher, Keyeq>;
template<typename Hasher = hash<pi16>, typename Keyeq = equal_to<pi16>> using USpi16 = unordered_set<pi16, Hasher, Keyeq>;
template<typename Hasher = hash<pu16>, typename Keyeq = equal_to<pu16>> using USpu16 = unordered_set<pu16, Hasher, Keyeq>;
template<typename Hasher = hash<pi32>, typename Keyeq = equal_to<pi32>> using USpi32 = unordered_set<pi32, Hasher, Keyeq>;
template<typename Hasher = hash<pu32>, typename Keyeq = equal_to<pu32>> using USpu32 = unordered_set<pu32, Hasher, Keyeq>;
template<typename Hasher = hash<pi64>, typename Keyeq = equal_to<pi64>> using USpi64 = unordered_set<pi64, Hasher, Keyeq>;
template<typename Hasher = hash<pu64>, typename Keyeq = equal_to<pu64>> using USpu64 = unordered_set<pu64, Hasher, Keyeq>;
template<typename Hasher = hash<pf32>, typename Keyeq = equal_to<pf32>> using USpf32 = unordered_set<pf32, Hasher, Keyeq>;
template<typename Hasher = hash<pf64>, typename Keyeq = equal_to<pf64>> using USpf64 = unordered_set<pf64, Hasher, Keyeq>;
template<typename Hasher = hash<pstr8>, typename Keyeq = equal_to<pstr8>> using USpstr8 = unordered_set<pstr8, Hasher, Keyeq>;

using umsbl = unordered_multiset<bl>;
using umsi8 = unordered_multiset<i8>;
using umsu8 = unordered_multiset<u8>;
using umsi16 = unordered_multiset<i16>;
using umsu16 = unordered_multiset<u16>;
using umsi32 = unordered_multiset<i32>;
using umsu32 = unordered_multiset<u32>;
using umsi64 = unordered_multiset<i64>;
using umsu64 = unordered_multiset<u64>;
using umsf32 = unordered_multiset<f32>;
using umsf64 = unordered_multiset<f64>;
using umsstr8 = unordered_multiset<str8>;
using umspbl = unordered_multiset<pbl>;
using umspi8 = unordered_multiset<pi8>;
using umspu8 = unordered_multiset<pu8>;
using umspi16 = unordered_multiset<pi16>;
using umspu16 = unordered_multiset<pu16>;
using umspi32 = unordered_multiset<pi32>;
using umspu32 = unordered_multiset<pu32>;
using umspi64 = unordered_multiset<pi64>;
using umspu64 = unordered_multiset<pu64>;
using umspf32 = unordered_multiset<pf32>;
using umspf64 = unordered_multiset<pf64>;
using umspstr8 = unordered_multiset<pstr8>;

template<typename Hasher = hash<bl>, typename Keyeq = equal_to<bl>> using UMSbl = unordered_multiset<bl, Hasher, Keyeq>;
template<typename Hasher = hash<i8>, typename Keyeq = equal_to<i8>> using UMSi8 = unordered_multiset<i8, Hasher, Keyeq>;
template<typename Hasher = hash<u8>, typename Keyeq = equal_to<u8>> using UMSu8 = unordered_multiset<u8, Hasher, Keyeq>;
template<typename Hasher = hash<i16>, typename Keyeq = equal_to<i16>> using UMSi16 = unordered_multiset<i16, Hasher, Keyeq>;
template<typename Hasher = hash<u16>, typename Keyeq = equal_to<u16>> using UMSu16 = unordered_multiset<u16, Hasher, Keyeq>;
template<typename Hasher = hash<i32>, typename Keyeq = equal_to<i32>> using UMSi32 = unordered_multiset<i32, Hasher, Keyeq>;
template<typename Hasher = hash<u32>, typename Keyeq = equal_to<u32>> using UMSu32 = unordered_multiset<u32, Hasher, Keyeq>;
template<typename Hasher = hash<i64>, typename Keyeq = equal_to<i64>> using UMSi64 = unordered_multiset<i64, Hasher, Keyeq>;
template<typename Hasher = hash<u64>, typename Keyeq = equal_to<u64>> using UMSu64 = unordered_multiset<u64, Hasher, Keyeq>;
template<typename Hasher = hash<f32>, typename Keyeq = equal_to<f32>> using UMSf32 = unordered_multiset<f32, Hasher, Keyeq>;
template<typename Hasher = hash<f64>, typename Keyeq = equal_to<f64>> using UMSf64 = unordered_multiset<f64, Hasher, Keyeq>;
template<typename Hasher = hash<str8>, typename Keyeq = equal_to<str8>> using UMSstr8 = unordered_multiset<str8, Hasher, Keyeq>;
template<typename Hasher = hash<pbl>, typename Keyeq = equal_to<pbl>> using UMSpbl = unordered_multiset<pbl, Hasher, Keyeq>;
template<typename Hasher = hash<pi8>, typename Keyeq = equal_to<pi8>> using UMSpi8 = unordered_multiset<pi8, Hasher, Keyeq>;
template<typename Hasher = hash<pu8>, typename Keyeq = equal_to<pu8>> using UMSpu8 = unordered_multiset<pu8, Hasher, Keyeq>;
template<typename Hasher = hash<pi16>, typename Keyeq = equal_to<pi16>> using UMSpi16 = unordered_multiset<pi16, Hasher, Keyeq>;
template<typename Hasher = hash<pu16>, typename Keyeq = equal_to<pu16>> using UMSpu16 = unordered_multiset<pu16, Hasher, Keyeq>;
template<typename Hasher = hash<pi32>, typename Keyeq = equal_to<pi32>> using UMSpi32 = unordered_multiset<pi32, Hasher, Keyeq>;
template<typename Hasher = hash<pu32>, typename Keyeq = equal_to<pu32>> using UMSpu32 = unordered_multiset<pu32, Hasher, Keyeq>;
template<typename Hasher = hash<pi64>, typename Keyeq = equal_to<pi64>> using UMSpi64 = unordered_multiset<pi64, Hasher, Keyeq>;
template<typename Hasher = hash<pu64>, typename Keyeq = equal_to<pu64>> using UMSpu64 = unordered_multiset<pu64, Hasher, Keyeq>;
template<typename Hasher = hash<pf32>, typename Keyeq = equal_to<pf32>> using UMSpf32 = unordered_multiset<pf32, Hasher, Keyeq>;
template<typename Hasher = hash<pf64>, typename Keyeq = equal_to<pf64>> using UMSpf64 = unordered_multiset<pf64, Hasher, Keyeq>;
template<typename Hasher = hash<pstr8>, typename Keyeq = equal_to<pstr8>> using UMSpstr8 = unordered_multiset<pstr8, Hasher, Keyeq>;

using stbl = stack<bl>;
using sti8 = stack<i8>;
using stu8 = stack<u8>;
using sti16 = stack<i16>;
using stu16 = stack<u16>;
using sti32 = stack<i32>;
using stu32 = stack<u32>;
using sti64 = stack<i64>;
using stu64 = stack<u64>;
using stf32 = stack<f32>;
using stf64 = stack<f64>;
using ststr8 = stack<str8>;
using stpbl = stack<pbl>;
using stpi8 = stack<pi8>;
using stpu8 = stack<pu8>;
using stpi16 = stack<pi16>;
using stpu16 = stack<pu16>;
using stpi32 = stack<pi32>;
using stpu32 = stack<pu32>;
using stpi64 = stack<pi64>;
using stpu64 = stack<pu64>;
using stpf32 = stack<pf32>;
using stpf64 = stack<pf64>;
using stpstr8 = stack<pstr8>;

using dbl = deque<bl>;
using di8 = deque<i8>;
using du8 = deque<u8>;
using di16 = deque<i16>;
using du16 = deque<u16>;
using di32 = deque<i32>;
using du32 = deque<u32>;
using di64 = deque<i64>;
using du64 = deque<u64>;
using df32 = deque<f32>;
using df64 = deque<f64>;
using dstr8 = deque<str8>;
using dpbl = deque<pbl>;
using dpi8 = deque<pi8>;
using dpu8 = deque<pu8>;
using dpi16 = deque<pi16>;
using dpu16 = deque<pu16>;
using dpi32 = deque<pi32>;
using dpu32 = deque<pu32>;
using dpi64 = deque<pi64>;
using dpu64 = deque<pu64>;
using dpf32 = deque<pf32>;
using dpf64 = deque<pf64>;
using dpstr8 = deque<pstr8>;

using qbl = queue<bl>;
using qi8 = queue<i8>;
using qu8 = queue<u8>;
using qi16 = queue<i16>;
using qu16 = queue<u16>;
using qi32 = queue<i32>;
using qu32 = queue<u32>;
using qi64 = queue<i64>;
using qu64 = queue<u64>;
using qf32 = queue<f32>;
using qf64 = queue<f64>;
using qstr8 = queue<str8>;
using qpbl = queue<pbl>;
using qpi8 = queue<pi8>;
using qpu8 = queue<pu8>;
using qpi16 = queue<pi16>;
using qpu16 = queue<pu16>;
using qpi32 = queue<pi32>;
using qpu32 = queue<pu32>;
using qpi64 = queue<pi64>;
using qpu64 = queue<pu64>;
using qpf32 = queue<pf32>;
using qpf64 = queue<pf64>;
using qpstr8 = queue<pstr8>;

using pqbl = priority_queue<bl>;
using pqi8 = priority_queue<i8>;
using pqu8 = priority_queue<u8>;
using pqi16 = priority_queue<i16>;
using pqu16 = priority_queue<u16>;
using pqi32 = priority_queue<i32>;
using pqu32 = priority_queue<u32>;
using pqi64 = priority_queue<i64>;
using pqu64 = priority_queue<u64>;
using pqf32 = priority_queue<f32>;
using pqf64 = priority_queue<f64>;
using pqstr8 = priority_queue<str8>;
using pqpbl = priority_queue<pbl>;
using pqpi8 = priority_queue<pi8>;
using pqpu8 = priority_queue<pu8>;
using pqpi16 = priority_queue<pi16>;
using pqpu16 = priority_queue<pu16>;
using pqpi32 = priority_queue<pi32>;
using pqpu32 = priority_queue<pu32>;
using pqpi64 = priority_queue<pi64>;
using pqpu64 = priority_queue<pu64>;
using pqpf32 = priority_queue<pf32>;
using pqpf64 = priority_queue<pf64>;
using pqpstr8 = priority_queue<pstr8>;

template<typename Pred = less<bl>> using PQbl = priority_queue<bl, vector<bl>, Pred>;
template<typename Pred = less<i8>> using PQi8 = priority_queue<i8, vector<i8>, Pred>;
template<typename Pred = less<u8>> using PQu8 = priority_queue<u8, vector<u8>, Pred>;
template<typename Pred = less<i16>> using PQi16 = priority_queue<i16, vector<i16>, Pred>;
template<typename Pred = less<u16>> using PQu16 = priority_queue<u16, vector<u16>, Pred>;
template<typename Pred = less<i32>> using PQi32 = priority_queue<i32, vector<i32>, Pred>;
template<typename Pred = less<u32>> using PQu32 = priority_queue<u32, vector<u32>, Pred>;
template<typename Pred = less<i64>> using PQi64 = priority_queue<i64, vector<i64>, Pred>;
template<typename Pred = less<u64>> using PQu64 = priority_queue<u64, vector<u64>, Pred>;
template<typename Pred = less<f32>> using PQf32 = priority_queue<f32, vector<f32>, Pred>;
template<typename Pred = less<f64>> using PQf64 = priority_queue<f64, vector<f64>, Pred>;
template<typename Pred = less<str8>> using PQstr8 = priority_queue<str8, vector<str8>, Pred>;
template<typename Pred = less<pbl>> using PQpbl = priority_queue<pbl, vector<pbl>, Pred>;
template<typename Pred = less<pi8>> using PQpi8 = priority_queue<pi8, vector<pi8>, Pred>;
template<typename Pred = less<pu8>> using PQpu8 = priority_queue<pu8, vector<pu8>, Pred>;
template<typename Pred = less<pi16>> using PQpi16 = priority_queue<pi16, vector<pi16>, Pred>;
template<typename Pred = less<pu16>> using PQpu16 = priority_queue<pu16, vector<pu16>, Pred>;
template<typename Pred = less<pi32>> using PQpi32 = priority_queue<pi32, vector<pi32>, Pred>;
template<typename Pred = less<pu32>> using PQpu32 = priority_queue<pu32, vector<pu32>, Pred>;
template<typename Pred = less<pi64>> using PQpi64 = priority_queue<pi64, vector<pi64>, Pred>;
template<typename Pred = less<pu64>> using PQpu64 = priority_queue<pu64, vector<pu64>, Pred>;
template<typename Pred = less<pf32>> using PQpf32 = priority_queue<pf32, vector<pf32>, Pred>;
template<typename Pred = less<pf64>> using PQpf64 = priority_queue<pf64, vector<pf64>, Pred>;
template<typename Pred = less<pstr8>> using PQpstr8 = priority_queue<pstr8, vector<pstr8>, Pred>;




template<typename T>
constexpr T MIN = numeric_limits<T>::min();
template<typename T>
constexpr T MAX = numeric_limits<T>::max();
template<typename T>
constexpr T INF = numeric_limits<T>::inf();

#define ALL(c) (c).begin(), (c).end()
#define CALL(c) (c).cbegin(), (c).cend()
#define RALL(c) (c).rbegin(), (c).rend()
#define CRALL(c) (c).crbegin(), (c).crend()

template<typename T>
inline constexpr T gcd(T l, T r)
{
	if ((l && r) == 0)
		return l | r;
	int s = __builtin_ctz(l | r);
	l >>= __builtin_ctz(l);
	do
	{
		r >>= __builtin_ctz(r);
		if (l > r)
		{
			swap(l, r);
		}
		r -= l;
	} while (r);
	return l << s;
}

template<typename It>
inline constexpr typename iterator_traits<It>::value_type gcd(It first, It last)
{
	typedef typename iterator_traits<It>::value_type T;
	return accumulate(first, last, (T)0, gcd<T>);
}

template<typename T>
inline constexpr T gcd(initializer_list<T> args)
{
	return gcd(args.begin(), args.end());
}

template<typename T>
inline constexpr T lcm(T l, T r)
{
	return (l | r) ? l / gcd(l, r) * r : 0;
}

template<typename It>
inline constexpr typename iterator_traits<It>::value_type lcm(It first, It last)
{
	typedef typename iterator_traits<It>::value_type T;
	return accumulate(first, last, (T)1, lcm<T>);
}

template<typename T>
inline constexpr T lcm(initializer_list<T> args)
{
	return lcm(args.begin(), args.end());
}

template<typename T>
inline constexpr T safe_avg(T l, T r)
{
	return l / 2 + r / 2 + (l % 2 + r % 2) / 2;
}

template<typename T>
inline constexpr T safe_avg(initializer_list<T> args)
{
	size_t n = args.size();
	T ans = 0;
	T mod = 0;
	for (T a : args)
	{
		ans += a / n;
		mod += a % n;
		if (mod > n)
		{
			mod -= n;
			ans++;
		}
		else if (mod < n)
		{
			mod += n;
			ans--;
		}
		return ans + mod / n;
	}
}




template<typename T>
struct std::hash<Vec2<T>>
{
	inline size_t operator()(const Vec2<T>& v) const noexcept
	{
		hash<T> tHash;
		return (size_t)31 * tHash(v.x) + tHash(v.y);
	}
};

template<typename T>
struct std::hash<Vec3<T>>
{
	inline size_t operator()(const Vec3<T>& v) const noexcept
	{
		hash<T> tHash;
		return (size_t)31 * ((size_t)31 * tHash(v.x) + tHash(v.y)) + tHash(v.z);
	}
};

#define PRECOMP false
#define TEST_CASES 1
#define PRINT_TCASE false

#if PRECOMP
void pre();
#endif
void go();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#if PRECOMP
	pre();
#endif
#if TEST_CASES
	i32 t;
	cin >> t;
	for (i32 tt = 1; tt <= t; tt++)
	{
#if PRINT_TCASE
		cout << "Case #" << tt << ": ";
#endif
#endif
		go();
#if TEST_CASES
	}
#endif
}

#endif

const string haha = "haha";

struct entry
{
	i64 ct = 0;
	string beg, end;

	inline entry() = default;

	inline entry(i64 ct, const string& beg, const string& end) :
		ct(ct),
		beg(beg),
		end(end)
	{}

	inline entry(const std::string& val)
	{
		int n = val.size();
		

		for (int i = 0; i < n - 3; i++)
			ct += val.substr(i, 4) == haha;
		int n3 = min(3, n);
		beg = val.substr(0, n3);
		end = val.substr(n - n3, n3);
	}

	friend entry operator+(const entry& l, const entry& r)
	{
		string beg = l.beg, end = r.end;
		if (beg.size() < 3)
		{
			int len = min(3 - beg.size(), r.beg.size());
			beg += r.beg.substr(0, len);
		}
		if (end.size() < 3)
		{
			int len = min(3 - end.size(), l.end.size());
			end = l.end.substr(l.end.size() - len, len) + end;
		}
		i64 ct = l.ct + r.ct;

		int st = max(1, 4 - (int)l.end.size()), ed = min(3, (int)r.beg.size());
		for (int i = st; i <= ed; i++)
			if (l.end.substr(l.end.size() - (4 - i), 4 - i) + r.beg.substr(0, i) == haha)
				ct++;

		return entry(ct, beg, end);
	}
};
unordered_map<string, entry> vars;

void go()
{
	vars.clear();
	int n;
	cin >> n;
	string var, eq, a, b, op;
	for (int i = 0; i < n; i++)
	{
		cin >> var >> eq;
		if (eq == ":=")
		{
			cin >> a;
			vars[var] = entry(a);
		}
		else
		{
			cin >> a >> op >> b;
			entry e = vars[a] + vars[b];
			vars[var] = e;
		}
	}

	cout << vars[var].ct << endl;
}