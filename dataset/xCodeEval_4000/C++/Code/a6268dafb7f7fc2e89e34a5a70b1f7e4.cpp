#ifndef EMBAILEY_TEMPLATE
#define EMBAILEY_TEMPLATE

#include <assert.h>
#include <algorithm>
#include <array>
#include <bitset>
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
#include <vector>

#ifdef _MSC_VER
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
	if (value == 0)
	{
		return 437; 

	}
	int ctr = 0;
#define CTZ_SEGMENT(n) do { if (!(value & ((1ull << (n)) - 1))) { ctr |= (n); value >>= (n); } } while (0)
	CTZ_SEGMENT(1 << 5);
	CTZ_SEGMENT(1 << 4);
	CTZ_SEGMENT(1 << 3);
	CTZ_SEGMENT(1 << 2);
	CTZ_SEGMENT(1 << 1);
	CTZ_SEGMENT(1 << 0);
#undef CTZ_SEGMENT
	return ctr;
}
#endif

#define loop(m, n, i) for (li i = (m); i < (n); i++)
#define rloop(m, n, i) for (li i = (n); i-- > (m);)

#define tCases() li testCaseCount; cin >> testCaseCount; for (li testCaseIndex = 0; testCaseIndex < testCaseCount; testCaseIndex++)




using namespace std;

using bi = bool;
using ci = char;
using uci = unsigned char;
using si = short;
using usi = unsigned short;
using li = int;
using uli = unsigned;
using lli = long long;
using ulli = unsigned long long;
using sf = float;
using df = double;
using ldf = long double;

using pbi = pair<bi, bi>;
using pci = pair<ci, ci>;
using puci = pair<uci, uci>;
using psi = pair<si, si>;
using pusi = pair<usi, usi>;
using pli = pair<li, li>;
using puli = pair<uli, uli>;
using plli = pair<lli, lli>;
using pulli = pair<ulli, ulli>;
using psf = pair<sf, sf>;
using pdf = pair<df, df>;
using pldf = pair<ldf, ldf>;

using vbi = vector<bi>;
using vci = vector<ci>;
using vuci = vector<uci>;
using vsi = vector<si>;
using vusi = vector<usi>;
using vli = vector<li>;
using vuli = vector<uli>;
using vlli = vector<lli>;
using vulli = vector<ulli>;
using vsf = vector<sf>;
using vdf = vector<df>;
using vldf = vector<ldf>;

using vpbi = vector<pbi>;
using vpci = vector<pci>;
using vpuci = vector<puci>;
using vpsi = vector<psi>;
using vpusi = vector<pusi>;
using vpli = vector<pli>;
using vpuli = vector<puli>;
using vplli = vector<plli>;
using vpulli = vector<pulli>;
using vpsf = vector<psf>;
using vpdf = vector<pdf>;
using vpldf = vector<pldf>;

using vvbi = vector<vbi>;
using vvci = vector<vci>;
using vvuci = vector<vuci>;
using vvsi = vector<vsi>;
using vvusi = vector<vusi>;
using vvli = vector<vli>;
using vvuli = vector<vuli>;
using vvlli = vector<vlli>;
using vvulli = vector<vulli>;
using vvsf = vector<vsf>;
using vvdf = vector<vdf>;
using vvldf = vector<vldf>;

using vvpbi = vector<vpbi>;
using vvpci = vector<vpci>;
using vvpuci = vector<vpuci>;
using vvpsi = vector<vpsi>;
using vvpusi = vector<vpusi>;
using vvpli = vector<vpli>;
using vvpuli = vector<vpuli>;
using vvplli = vector<vplli>;
using vvpulli = vector<vpulli>;
using vvpsf = vector<vpsf>;
using vvpdf = vector<vpdf>;
using vvpldf = vector<vpldf>;

using vvvbi = vector<vvbi>;
using vvvci = vector<vvci>;
using vvvuci = vector<vvuci>;
using vvvsi = vector<vvsi>;
using vvvusi = vector<vvusi>;
using vvvli = vector<vvli>;
using vvvuli = vector<vvuli>;
using vvvlli = vector<vvlli>;
using vvvulli = vector<vvulli>;
using vvvsf = vector<vvsf>;
using vvvdf = vector<vvdf>;
using vvvldf = vector<vvldf>;

using vvvpbi = vector<vvpbi>;
using vvvpci = vector<vvpci>;
using vvvpuci = vector<vvpuci>;
using vvvpsi = vector<vvpsi>;
using vvvpusi = vector<vvpusi>;
using vvvpli = vector<vvpli>;
using vvvpuli = vector<vvpuli>;
using vvvplli = vector<vvplli>;
using vvvpulli = vector<vvpulli>;
using vvvpsf = vector<vvpsf>;
using vvvpdf = vector<vvpdf>;
using vvvpldf = vector<vvpldf>;

using l1bi = forward_list<bi>;
using l1ci = forward_list<ci>;
using l1uci = forward_list<uci>;
using l1si = forward_list<si>;
using l1usi = forward_list<usi>;
using l1li = forward_list<li>;
using l1uli = forward_list<uli>;
using l1lli = forward_list<lli>;
using l1ulli = forward_list<ulli>;
using l1sf = forward_list<sf>;
using l1df = forward_list<df>;
using l1ldf = forward_list<ldf>;

using l1pbi = forward_list<pbi>;
using l1pci = forward_list<pci>;
using l1puci = forward_list<puci>;
using l1psi = forward_list<psi>;
using l1pusi = forward_list<pusi>;
using l1pli = forward_list<pli>;
using l1puli = forward_list<puli>;
using l1plli = forward_list<plli>;
using l1pulli = forward_list<pulli>;
using l1psf = forward_list<psf>;
using l1pdf = forward_list<pdf>;
using l1pldf = forward_list<pldf>;

using l2bi = list<bi>;
using l2ci = list<ci>;
using l2uci = list<uci>;
using l2si = list<si>;
using l2usi = list<usi>;
using l2li = list<li>;
using l2uli = list<uli>;
using l2lli = list<lli>;
using l2ulli = list<ulli>;
using l2sf = list<sf>;
using l2df = list<df>;
using l2ldf = list<ldf>;

using l2pbi = list<pbi>;
using l2pci = list<pci>;
using l2puci = list<puci>;
using l2psi = list<psi>;
using l2pusi = list<pusi>;
using l2pli = list<pli>;
using l2puli = list<puli>;
using l2plli = list<plli>;
using l2pulli = list<pulli>;
using l2psf = list<psf>;
using l2pdf = list<pdf>;
using l2pldf = list<pldf>;

template<typename Pred = less<bi>> using sbi = set<bi, Pred>;
template<typename Pred = less<ci>> using sci = set<ci, Pred>;
template<typename Pred = less<uci>> using suci = set<uci, Pred>;
template<typename Pred = less<si>> using ssi = set<si, Pred>;
template<typename Pred = less<usi>> using susi = set<usi, Pred>;
template<typename Pred = less<li>> using sli = set<li, Pred>;
template<typename Pred = less<uli>> using suli = set<uli, Pred>;
template<typename Pred = less<lli>> using slli = set<lli, Pred>;
template<typename Pred = less<ulli>> using sulli = set<ulli, Pred>;
template<typename Pred = less<sf>> using ssf = set<sf, Pred>;
template<typename Pred = less<df>> using sdf = set<df, Pred>;
template<typename Pred = less<ldf>> using sldf = set<ldf, Pred>;

template<typename Pred = less<pbi>> using spbi = set<pbi, Pred>;
template<typename Pred = less<pci>> using spci = set<pci, Pred>;
template<typename Pred = less<puci>> using spuci = set<puci, Pred>;
template<typename Pred = less<psi>> using spsi = set<psi, Pred>;
template<typename Pred = less<pusi>> using spusi = set<pusi, Pred>;
template<typename Pred = less<pli>> using spli = set<pli, Pred>;
template<typename Pred = less<puli>> using spuli = set<puli, Pred>;
template<typename Pred = less<plli>> using splli = set<plli, Pred>;
template<typename Pred = less<pulli>> using spulli = set<pulli, Pred>;
template<typename Pred = less<psf>> using spsf = set<psf, Pred>;
template<typename Pred = less<pdf>> using spdf = set<pdf, Pred>;
template<typename Pred = less<pldf>> using spldf = set<pldf, Pred>;

template<typename Pred = less<bi>> using msbi = multiset<bi, Pred>;
template<typename Pred = less<ci>> using msci = multiset<ci, Pred>;
template<typename Pred = less<uci>> using msuci = multiset<uci, Pred>;
template<typename Pred = less<si>> using mssi = multiset<si, Pred>;
template<typename Pred = less<usi>> using msusi = multiset<usi, Pred>;
template<typename Pred = less<li>> using msli = multiset<li, Pred>;
template<typename Pred = less<uli>> using msuli = multiset<uli, Pred>;
template<typename Pred = less<lli>> using mslli = multiset<lli, Pred>;
template<typename Pred = less<ulli>> using msulli = multiset<ulli, Pred>;
template<typename Pred = less<sf>> using mssf = multiset<sf, Pred>;
template<typename Pred = less<df>> using msdf = multiset<df, Pred>;
template<typename Pred = less<ldf>> using msldf = multiset<ldf, Pred>;

template<typename Pred = less<pbi>> using mspbi = multiset<pbi, Pred>;
template<typename Pred = less<pci>> using mspci = multiset<pci, Pred>;
template<typename Pred = less<puci>> using mspuci = multiset<puci, Pred>;
template<typename Pred = less<psi>> using mspsi = multiset<psi, Pred>;
template<typename Pred = less<pusi>> using mspusi = multiset<pusi, Pred>;
template<typename Pred = less<pli>> using mspli = multiset<pli, Pred>;
template<typename Pred = less<puli>> using mspuli = multiset<puli, Pred>;
template<typename Pred = less<plli>> using msplli = multiset<plli, Pred>;
template<typename Pred = less<pulli>> using mspulli = multiset<pulli, Pred>;
template<typename Pred = less<psf>> using mspsf = multiset<psf, Pred>;
template<typename Pred = less<pdf>> using mspdf = multiset<pdf, Pred>;
template<typename Pred = less<pldf>> using mspldf = multiset<pldf, Pred>;

using usbi = unordered_set<bi>;
using usci = unordered_set<ci>;
using usuci = unordered_set<uci>;
using ussi = unordered_set<si>;
using ususi = unordered_set<usi>;
using usli = unordered_set<li>;
using usuli = unordered_set<uli>;
using uslli = unordered_set<lli>;
using usulli = unordered_set<ulli>;
using ussf = unordered_set<sf>;
using usdf = unordered_set<df>;
using usldf = unordered_set<ldf>;

using uspbi = unordered_set<pbi>;
using uspci = unordered_set<pci>;
using uspuci = unordered_set<puci>;
using uspsi = unordered_set<psi>;
using uspusi = unordered_set<pusi>;
using uspli = unordered_set<pli>;
using uspuli = unordered_set<puli>;
using usplli = unordered_set<plli>;
using uspulli = unordered_set<pulli>;
using uspsf = unordered_set<psf>;
using uspdf = unordered_set<pdf>;
using uspldf = unordered_set<pldf>;

using umsbi = unordered_multiset<bi>;
using umsci = unordered_multiset<ci>;
using umsuci = unordered_multiset<uci>;
using umssi = unordered_multiset<si>;
using umsusi = unordered_multiset<usi>;
using umsli = unordered_multiset<li>;
using umsuli = unordered_multiset<uli>;
using umslli = unordered_multiset<lli>;
using umsulli = unordered_multiset<ulli>;
using umssf = unordered_multiset<sf>;
using umsdf = unordered_multiset<df>;
using umsldf = unordered_multiset<ldf>;

using umspbi = unordered_multiset<pbi>;
using umspci = unordered_multiset<pci>;
using umspuci = unordered_multiset<puci>;
using umspsi = unordered_multiset<psi>;
using umspusi = unordered_multiset<pusi>;
using umspli = unordered_multiset<pli>;
using umspuli = unordered_multiset<puli>;
using umsplli = unordered_multiset<plli>;
using umspulli = unordered_multiset<pulli>;
using umspsf = unordered_multiset<psf>;
using umspdf = unordered_multiset<pdf>;
using umspldf = unordered_multiset<pldf>;

using stbi = stack<bi>;
using stci = stack<ci>;
using stuci = stack<uci>;
using stsi = stack<si>;
using stusi = stack<usi>;
using stli = stack<li>;
using stuli = stack<uli>;
using stlli = stack<lli>;
using stulli = stack<ulli>;
using stsf = stack<sf>;
using stdf = stack<df>;
using stldf = stack<ldf>;

using stpbi = stack<pbi>;
using stpci = stack<pci>;
using stpuci = stack<puci>;
using stpsi = stack<psi>;
using stpusi = stack<pusi>;
using stpli = stack<pli>;
using stpuli = stack<puli>;
using stplli = stack<plli>;
using stpulli = stack<pulli>;
using stpsf = stack<psf>;
using stpdf = stack<pdf>;
using stpldf = stack<pldf>;

using qbi = queue<bi>;
using qci = queue<ci>;
using quci = queue<uci>;
using qsi = queue<si>;
using qusi = queue<usi>;
using qli = queue<li>;
using quli = queue<uli>;
using qlli = queue<lli>;
using qulli = queue<ulli>;
using qsf = queue<sf>;
using qdf = queue<df>;
using qldf = queue<ldf>;

using qpbi = queue<pbi>;
using qpci = queue<pci>;
using qpuci = queue<puci>;
using qpsi = queue<psi>;
using qpusi = queue<pusi>;
using qpli = queue<pli>;
using qpuli = queue<puli>;
using qplli = queue<plli>;
using qpulli = queue<pulli>;
using qpsf = queue<psf>;
using qpdf = queue<pdf>;
using qpldf = queue<pldf>;

using dbi = deque<bi>;
using dci = deque<ci>;
using duci = deque<uci>;
using dsi = deque<si>;
using dusi = deque<usi>;
using dli = deque<li>;
using duli = deque<uli>;
using dlli = deque<lli>;
using dulli = deque<ulli>;
using dsf = deque<sf>;
using ddf = deque<df>;
using dldf = deque<ldf>;

using dpbi = deque<pbi>;
using dpci = deque<pci>;
using dpuci = deque<puci>;
using dpsi = deque<psi>;
using dpusi = deque<pusi>;
using dpli = deque<pli>;
using dpuli = deque<puli>;
using dplli = deque<plli>;
using dpulli = deque<pulli>;
using dpsf = deque<psf>;
using dpdf = deque<pdf>;
using dpldf = deque<pldf>;

using pqbi = priority_queue<bi>;
using pqci = priority_queue<ci>;
using pquci = priority_queue<uci>;
using pqsi = priority_queue<si>;
using pqusi = priority_queue<usi>;
using pqli = priority_queue<li>;
using pquli = priority_queue<uli>;
using pqlli = priority_queue<lli>;
using pqulli = priority_queue<ulli>;
using pqsf = priority_queue<sf>;
using pqdf = priority_queue<df>;
using pqldf = priority_queue<ldf>;

using pqpbi = priority_queue<pbi>;
using pqpci = priority_queue<pci>;
using pqpuci = priority_queue<puci>;
using pqpsi = priority_queue<psi>;
using pqpusi = priority_queue<pusi>;
using pqpli = priority_queue<pli>;
using pqpuli = priority_queue<puli>;
using pqplli = priority_queue<plli>;
using pqpulli = priority_queue<pulli>;
using pqpsf = priority_queue<psf>;
using pqpdf = priority_queue<pdf>;
using pqpldf = priority_queue<pldf>;




template<class T, class Container = vector<T>>
using max_heap = priority_queue<T, Container, less<T>>;

template<class T, class Container = vector<T>>
using min_heap = priority_queue<T, Container, greater<T>>;

#define MIN(T) (numeric_limits<T>::min())
#define MAX(T) (numeric_limits<T>::max())
#define INF(T) (numeric_limits<T>::infinity())





#define ALL(c) (c).begin(), (c).end()
#define CALL(c) (c).cbegin(), (c).cend()
#define RALL(c) (c).rbegin(), (c).rend()
#define CRALL(c) (c).crbegin(), (c).crend()

#define CONTAINS(c, x) ((c).find(x) != (c).end())

template<size_t I>
struct TupleReadHelper
{
	template<typename... Ts>
	static inline void read(tuple<Ts...>& c, istream& strm);
	template<typename... Ts>
	static inline void read(tuple<Ts&...>&& c, istream& strm);
};

template<>
struct TupleReadHelper<0>
{
	template<typename... Ts>
	static inline void read(tuple<Ts...>& c, istream& strm) {}
	template<typename... Ts>
	static inline void read(tuple<Ts&...>&& c, istream& strm) {}
};

template<size_t I>
struct TupleReadNHelper
{
	template<typename... Ts>
	static inline void read(tuple<Ts...>& t, istream& strm);
	template<typename... Ts, typename... S>
	static inline void read(tuple<Ts...>& t, istream& strm, size_t n, S... s);
};

template<>
struct TupleReadNHelper<0>
{
	template<typename... Ts, typename... S>
	static inline void read(tuple<Ts...>&, istream& strm, S...) {}
};

template<typename Iter>
inline void read_rng(Iter first, Iter last);
template<typename Iter>
inline void read_rng(Iter first, Iter last, istream& strm);

template<typename T>
inline void read(T& t, istream& strm)
{
	strm >> t;
}

template<typename T, typename U>
inline void read(pair<T, U>& c, istream& strm)
{
	read(c.first, strm);
	read(c.second, strm);
}

template<typename... Ts>
inline void read(tuple<Ts...>& c, istream& strm)
{
	TupleReadHelper<tuple_size<tuple<Ts...>>::value>::read(c, strm);
}

template<typename... Ts>
inline void read(tuple<Ts&...>&& c, istream& strm)
{
	TupleReadHelper<tuple_size<tuple<Ts...>>::value>::read(c, strm);
}

template<typename T, size_t Size>
inline void read(array<T, Size>& c, istream& strm)
{
	read_rng(ALL(c), strm);
}

template<typename T, typename Alloc>
inline void read(vector<T, Alloc>& c, istream& strm)
{
	read_rng(ALL(c), strm);
}

template<typename T, typename Alloc>
inline void read(deque<T, Alloc>& c, istream& strm)
{
	read_rng(ALL(c), strm);
}

template<typename T, typename Alloc>
inline void read(list<T, Alloc>& c, istream& strm)
{
	read_rng(ALL(c), strm);
}

template<typename T, typename Alloc>
inline void read(forward_list<T, Alloc>& c, istream& strm)
{
	read_rng(ALL(c), strm);
}

template<typename T>
inline void read(T t)
{
	read(t, cin);
}

template<size_t I>
template<typename... Ts>
inline void TupleReadHelper<I>::read(tuple<Ts...>& c, istream& strm)
{
	TupleReadHelper<I - 1>::read(c, strm);
	::read(get<I - 1>(c), strm);
}

template<size_t I>
template<typename... Ts>
inline void TupleReadHelper<I>::read(tuple<Ts&...>&& c, istream& strm)
{
	TupleReadHelper<I - 1>::read(c, strm);
	::read(get<I - 1>(c), strm);
}

template<typename T>
inline T readr(istream& strm)
{
	T t;
	::read(t, strm);
	return t;
}

template<typename T>
inline T readr()
{
	return readr<T>(cin);
}

template<typename Iter>
inline void read_rng(Iter first, Iter last, istream& strm)
{
	while (first != last)
		read(*(first++), strm);
}

template<typename T>
struct ReadNHelper
{
	static inline T read(istream& strm)
	{
		return ::readr<T>();
	}

	template<typename... S>
	static inline T read(istream& strm, size_t n, S... s)
	{
		return ReadNHelper<T>::read(strm, s...);
	}
};

template<typename T, typename U>
struct ReadNHelper<pair<T, U>>
{
	static inline pair<T, U> read(istream& strm)
	{
		pair<T, U> c;
		c.first = ReadNHelper<T>::read(strm);
		c.second = ReadNHelper<U>::read(strm);
		return c;
	}

	template<typename... S>
	static inline pair<T, U> read(istream& strm, size_t n, S... s)
	{
		pair<T, U> c;
		c.first = ReadNHelper<T>::read(strm, s...);
		c.second = ReadNHelper<U>::read(strm, s...);
		return c;
	}
};

template<typename... Ts>
struct ReadNHelper<tuple<Ts...>>
{
	static inline tuple<Ts...> read(istream& strm)
	{
		tuple<Ts...> c;
		TupleReadNHelper<tuple_size<tuple<Ts...>>::value>::read(c, strm);
		return c;
	}

	template<typename... S>
	static inline tuple<Ts...> read(istream& strm, size_t n, S... s)
	{
		tuple<Ts...> c;
		TupleReadNHelper<tuple_size<tuple<Ts...>>::value>::read(c, strm, n, s...);
		return c;
	}
};

template<typename T, size_t Size>
struct ReadNHelper<array<T, Size>>
{
	static inline array<T, Size> read(istream& strm)
	{
		array<T, Size> c;
		for (size_t i = Size; i--;) c[i] = ReadNHelper<T>::read(strm);
		return c;
	}

	template<typename... S>
	static inline array<T, Size> read(istream& strm, size_t n, S... s)
	{
		array<T, Size> c;
		for (size_t i = Size; i--;) c[i] = ReadNHelper<T>::read(strm, s...);
		return c;
	}
};

template<typename T, typename Alloc>
struct ReadNHelper<vector<T, Alloc>>
{
	static inline vector<T, Alloc> read(istream& strm)
	{
		

	}

	template<typename... S>
	static inline vector<T, Alloc> read(istream& strm, size_t n, S... s)
	{
		vector<T, Alloc> c;
		c.reserve(n);
		while (n--) c.push_back(ReadNHelper<T>::read(strm, s...));
		return c;
	}
};

template<typename T, typename Alloc>
struct ReadNHelper<deque<T, Alloc>>
{
	static inline deque<T, Alloc> read(istream& strm)
	{
		

	}

	template<typename... S>
	static inline deque<T, Alloc> read(istream& strm, size_t n, S... s)
	{
		deque<T, Alloc> c;
		while (n--) c.push_back(ReadNHelper<T>::read(strm, s...));
		return c;
	}
};

template<typename T, typename Alloc>
struct ReadNHelper<list<T, Alloc>>
{
	static inline list<T, Alloc> read(istream& strm)
	{
		

	}

	template<typename... S>
	static inline list<T, Alloc> read(istream& strm, size_t n, S... s)
	{
		list<T, Alloc> c;
		while (n--) c.push_back(ReadNHelper<T>::read(strm, s...));
		return c;
	}
};

template<typename T, typename Alloc>
struct ReadNHelper<forward_list<T, Alloc>>
{
	static inline forward_list<T, Alloc> read(istream& strm)
	{
		

	}

	template<typename... S>
	static inline forward_list<T, Alloc> read(istream& strm, size_t n, S... s)
	{
		forward_list<T, Alloc> c;
		typename forward_list<T, Alloc>::const_iterator itr = c.cbefore_begin();
		while (n--)
		{
			c.insert_after(itr, ReadNHelper<T>::read(strm, s...));
			itr++;
		}
		return c;
	}
};

template<typename T, typename Pr, typename Alloc>
struct ReadNHelper<set<T, Pr, Alloc>>
{
	static inline set<T, Pr, Alloc> read(istream& strm)
	{
		

	}

	template<typename... S>
	static inline set<T, Pr, Alloc> read(istream& strm, size_t n, S... s)
	{
		set<T, Pr, Alloc> c;
		while (n--) c.insert(ReadNHelper<T>::read(strm, s...));
		return c;
	}
};

template<typename T, typename Pr, typename Alloc>
struct ReadNHelper<multiset<T, Pr, Alloc>>
{
	static inline multiset<T, Pr, Alloc> read(istream& strm)
	{
		

	}

	template<typename... S>
	static inline multiset<T, Pr, Alloc> read(istream& strm, size_t n, S... s)
	{
		multiset<T, Pr, Alloc> c;
		while (n--) c.insert(ReadNHelper<T>::read(strm, s...));
		return c;
	}
};

template<typename T, typename Hash, typename Eq, typename Alloc>
struct ReadNHelper<unordered_set<T, Hash, Eq, Alloc>>
{
	static inline unordered_set<T, Hash, Eq, Alloc> read(istream& strm)
	{
		

	}

	template<typename... S>
	static inline unordered_set<T, Hash, Eq, Alloc> read(istream& strm, size_t n, S... s)
	{
		unordered_set<T, Hash, Eq, Alloc> c;
		while (n--) c.insert(ReadNHelper<T>::read(strm, s...));
		return c;
	}
};

template<typename T, typename Hash, typename Eq, typename Alloc>
struct ReadNHelper<unordered_multiset<T, Hash, Eq, Alloc>>
{
	static inline unordered_multiset<T, Hash, Eq, Alloc> read(istream& strm)
	{
		

	}

	template<typename... S>
	static inline unordered_multiset<T, Hash, Eq, Alloc> read(istream& strm, size_t n, S... s)
	{
		unordered_multiset<T, Hash, Eq, Alloc> c;
		while (n--) c.insert(ReadNHelper<T>::read(strm, s...));
		return c;
	}
};

template<typename K, typename V, typename Pr, typename Alloc>
struct ReadNHelper<map<K, V, Pr, Alloc>>
{
	static inline map<K, V, Pr, Alloc> read(istream& strm)
	{
		

	}

	template<typename... S>
	static inline map<K, V, Pr, Alloc> read(istream& strm, size_t n, S... s)
	{
		map<K, V, Pr, Alloc> c;
		while (n--) c.insert(ReadNHelper<pair<K, V>>::read(strm, s...));
		return c;
	}
};

template<typename K, typename V, typename Pr, typename Alloc>
struct ReadNHelper<multimap<K, V, Pr, Alloc>>
{
	static inline multimap<K, V, Pr, Alloc> read(istream& strm)
	{
		

	}

	template<typename... S>
	static inline multimap<K, V, Pr, Alloc> read(istream& strm, size_t n, S... s)
	{
		multimap<K, V, Pr, Alloc> c;
		while (n--) c.insert(ReadNHelper<pair<K, V>>::read(strm, s...));
		return c;
	}
};

template<typename K, typename V, typename Hash, typename Eq, typename Alloc>
struct ReadNHelper<unordered_map<K, V, Hash, Eq, Alloc>>
{
	static inline unordered_map<K, V, Hash, Eq, Alloc> read(istream& strm)
	{
		

	}

	template<typename... S>
	static inline unordered_map<K, V, Hash, Eq, Alloc> read(istream& strm, size_t n, S... s)
	{
		unordered_map<K, V, Hash, Eq, Alloc> c;
		while (n--) c.insert(ReadNHelper<pair<K, V>>::read(strm, s...));
		return c;
	}
};

template<typename K, typename V, typename Hash, typename Eq, typename Alloc>
struct ReadNHelper<unordered_multimap<K, V, Hash, Eq, Alloc>>
{
	static inline unordered_multimap<K, V, Hash, Eq, Alloc> read(istream& strm)
	{
		

	}

	template<typename... S>
	static inline unordered_multimap<K, V, Hash, Eq, Alloc> read(istream& strm, size_t n, S... s)
	{
		unordered_multimap<K, V, Hash, Eq, Alloc> c;
		while (n--) c.insert(ReadNHelper<pair<K, V>>::read(strm, s...));
		return c;
	}
};

template<typename T>
inline T read_n()
{
	return ReadNHelper<T>::read(cin);
}

template<typename T, typename... S>
inline T read_n(size_t size0, S... sizes)
{
	return ReadNHelper<T>::read(std::cin, size0, sizes...);
}

template<typename T, typename... S>
inline T read_n(istream& strm, S... sizes)
{
	return ReadNHelper<T>::read(strm, sizes...);
}

template<size_t I>
template<typename... Ts>
inline void TupleReadNHelper<I>::read(tuple<Ts...>& t, istream& strm)
{
	TupleReadNHelper<I - 1>::read(t, strm);
	typedef typename tuple_element<I - 1, tuple<Ts...>>::type Type;
	get<I - 1>(t) = ReadNHelper<Type>::read(strm);
}

template<size_t I>
template<typename... Ts, typename... S>
inline void TupleReadNHelper<I>::read(tuple<Ts...>& t, istream& strm, size_t n, S... s)
{
	TupleReadNHelper<I - 1>::read(t, strm, n, s...);
	typedef typename tuple_element<I - 1, tuple<Ts...>>::type Type;
	get<I - 1>(t) = ReadNHelper<Type>::read(strm, s...);
}

template<size_t Depth, size_t I>
struct TupleWriteHelper
{
	template<typename... Ts, typename Delim0, typename... Delims>
	static inline void write(const tuple<Ts...>& c, ostream& strm, const tuple<Delim0, Delims...>& delims);
	template<typename... Ts>
	static inline void write(const tuple<Ts...>& c, ostream& strm);
	template<typename... Ts, typename Delim0, typename... Delims>
	static inline void write(tuple<Ts&...>&& c, ostream& strm, const tuple<Delim0, Delims...>& delims);
	template<typename... Ts>
	static inline void write(tuple<Ts&...>&& c, ostream& strm);
};

template<size_t Depth>
struct TupleWriteHelper<Depth, 0>
{
	template<typename... Ts, typename Delim0, typename... Delims>
	static inline void write(const tuple<Ts...>& c, ostream& strm, const tuple<Delim0, Delims...>& delims) {}
	template<typename... Ts>
	static inline void write(const tuple<Ts...>& c, ostream& strm) {}
};

template<size_t Depth = 0, typename Iter, typename Delim0, typename... Delims>
inline void write_rng(Iter first, Iter last, ostream& strm, const tuple<Delim0, Delims...>& delims);

template<typename Iter>
inline void write_rng(Iter first, Iter last, ostream& strm);

template<typename T>
inline void write(const T& t, ostream& strm)
{
	strm << t;
}

template<size_t Depth, typename T, typename Delim0, typename... Delims>
inline void writetd(const T& t, ostream& strm, const tuple<Delim0, Delims...>&)
{
	write(t, strm);
}




template<typename T, typename U>
inline void write(const pair<T, U>& c, ostream& strm)
{
	write(c.first, strm);
	write(c.second, strm);
}

template<size_t Depth, typename T, typename U, typename Delim0, typename... Delims>
inline void writetd(const pair<T, U>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	constexpr bool hasDelim = Depth < tuple_size<tuple<Delim0, Delims...>>::value;
	constexpr size_t safeDepth = hasDelim ? Depth : 0;
	if (hasDelim)
	{
		writetd<Depth + 1>(c.first, strm, delims);
		write(get<safeDepth>(delims), strm);
		writetd<Depth + 1>(c.second, strm, delims);
	}
	else
	{
		write(c.first, strm);
		write(c.second, strm);
	}
}

template<typename... Ts>
inline void write(const tuple<Ts...>& c, ostream& strm)
{
	TupleWriteHelper<0, tuple_size<tuple<Ts...>>::value>::write(c);
}

template<size_t Depth, typename... Ts, typename Delim0, typename... Delims>
inline void writetd(const tuple<Ts...>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	TupleWriteHelper<Depth, tuple_size<tuple<Ts...>>::value>::write(c, strm, delims);
}

template<typename... Ts>
inline void write(tuple<Ts&...>&& c, ostream& strm)
{
	TupleWriteHelper<0, tuple_size<tuple<Ts...>>::value>::write(c);
}

template<size_t Depth, typename... Ts, typename Delim0, typename... Delims>
inline void writetd(tuple<Ts&...>&& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	TupleWriteHelper<Depth, tuple_size<tuple<Ts...>>::value>::write(c, delims);
}

template<typename T>
inline void write(const initializer_list<T>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename T, typename Delim0, typename... Delims>
inline void writetd(const initializer_list<T>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename T, size_t Size>
inline void write(const array<T, Size>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename T, size_t Size, typename Delim0, typename... Delims>
inline void writetd(const array<T, Size>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename T, typename Alloc>
inline void write(const vector<T, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename T, typename Alloc, typename Delim0, typename... Delims>
inline void writetd(const vector<T, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename T, typename Alloc>
inline void write(const deque<T, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename T, typename Alloc, typename Delim0, typename... Delims>
inline void writetd(const deque<T, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename T, typename Alloc>
inline void write(const list<T, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename T, typename Alloc, typename Delim0, typename... Delims>
inline void writetd(const list<T, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename T, typename Alloc>
inline void write(const forward_list<T, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename T, typename Alloc, typename Delim0, typename... Delims>
inline void writetd(const forward_list<T, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename T, typename Pr, typename Alloc>
inline void write(const set<T, Pr, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename T, typename Pr, typename Alloc, typename Delim0, typename... Delims>
inline void writetd(const set<T, Pr, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename T, typename Pr, typename Alloc>
inline void write(const multiset<T, Pr, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename T, typename Pr, typename Alloc, typename Delim0, typename... Delims>
inline void writetd(const multiset<T, Pr, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename T, typename Hash, typename Eq, typename Alloc>
inline void write(const unordered_set<T, Hash, Eq, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename T, typename Hash, typename Eq, typename Alloc, typename Delim0, typename... Delims>
inline void writetd(const unordered_set<T, Hash, Eq, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename T, typename Hash, typename Eq, typename Alloc>
inline void write(const unordered_multiset<T, Hash, Eq, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename T, typename Hash, typename Eq, typename Alloc, typename Delim0, typename... Delims>
inline void writetd(const unordered_multiset<T, Hash, Eq, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename K, typename V, typename Pr, typename Alloc>
inline void write(const map<K, V, Pr, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename K, typename V, typename Pr, typename Alloc, typename Delim0, typename... Delims>
inline void writetd(const map<K, V, Pr, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename K, typename V, typename Pr, typename Alloc>
inline void write(const multimap<K, V, Pr, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename K, typename V, typename Pr, typename Alloc, typename Delim0, typename... Delims>
inline void writetd(const multimap<K, V, Pr, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename K, typename V, typename Hash, typename Eq, typename Alloc>
inline void write(const unordered_map<K, V, Hash, Eq, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename K, typename V, typename Hash, typename Eq, typename Alloc, typename Delim0, typename... Delims>
inline void writetd(const unordered_map<K, V, Hash, Eq, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<typename K, typename V, typename Hash, typename Eq, typename Alloc>
inline void write(const unordered_multimap<K, V, Hash, Eq, Alloc>& c, ostream& strm)
{
	write_rng(ALL(c), strm);
}

template<size_t Depth, typename K, typename V, typename Hash, typename Eq, typename Alloc, typename Delim0, typename... Delims>
inline void writetd(const unordered_multimap<K, V, Hash, Eq, Alloc>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), strm, delims);
}

template<size_t Depth, size_t I>
template<typename... Ts, typename Delim0, typename... Delims>
inline void TupleWriteHelper<Depth, I>::write(const tuple<Ts...>& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	constexpr bool hasDelim = Depth < tuple_size<tuple<Delim0, Delims...>>::value;
	constexpr size_t safeDepth = hasDelim ? Depth : 0;
	TupleWriteHelper<Depth, I - 1>::write(c, strm, delims);
	writetd<Depth + 1>(get<I - 1>(c), strm, delims);
	if (hasDelim && I < tuple_size<tuple<Ts...>>::value) ::write(get<safeDepth>(delims), strm);
}

template<size_t Depth, size_t I>
template<typename... Ts>
inline void TupleWriteHelper<Depth, I>::write(const tuple<Ts...>& c, ostream& strm)
{
	TupleWriteHelper<Depth, I - 1>::write(c, strm);
	::write(get<I - 1>(c), strm);
}

template<size_t Depth, size_t I>
template<typename... Ts, typename Delim0, typename... Delims>
inline void TupleWriteHelper<Depth, I>::write(tuple<Ts&...>&& c, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	constexpr bool hasDelim = Depth < tuple_size<tuple<Delim0, Delims...>>::value;
	constexpr size_t safeDepth = hasDelim ? Depth : 0;
	TupleWriteHelper<Depth, I - 1>::write(c, strm, delims);
	writetd<Depth + 1>(get<I - 1>(c), strm, delims);
	if (hasDelim && I < tuple_size<tuple<Ts...>>::value) ::write(get<safeDepth>(delims), strm);
}

template<size_t Depth, size_t I>
template<typename... Ts>
inline void TupleWriteHelper<Depth, I>::write(tuple<Ts&...>&& c, ostream& strm)
{
	TupleWriteHelper<Depth, I - 1>::write(c, strm);
	::write(get<I - 1>(c), strm);
}

template<size_t Depth, typename Iter, typename Delim0, typename... Delims>
inline void write_rng(Iter first, Iter last, ostream& strm, const tuple<Delim0, Delims...>& delims)
{
	if (first == last) return;
	constexpr bool hasDelim = Depth < tuple_size<tuple<Delim0, Delims...>>::value;
	constexpr size_t safeDepth = hasDelim ? Depth : 0;
	if (hasDelim)
	{
		for (;;)
		{
			writetd<Depth + 1>(*(first++), strm, delims);
			if (first == last) break;
			write(get<safeDepth>(delims), strm);
		}
	}
	else
	{
		do
			write(*(first++), strm);
		while (first != last);
	}
}

template<typename Iter>
inline void write_rng(Iter first, Iter last, ostream& strm)
{
	while (first != last) write(*(first++), strm);
}

template<typename T>
inline void write(const T& t)
{
	write(t, cout);
}

template<typename T, typename Delim0, typename... Delims>
inline void writed(const T& t, const Delim0& delim0, const Delims&... delims)
{
	writetd<0>(t, cout, tie(delim0, delims...));
}

template<typename T, typename Delim0, typename... Delims>
inline void writed(const T& t, ostream& strm, const Delim0& delim0, const Delims&... delims)
{
	writetd<0>(t, strm, tie(delim0, delims...));
}

template<typename T>
inline constexpr T gcd(T l, T r)
{
	if (!(l && r))
	{
		return l | r;
	}
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

template<typename Iter>
inline constexpr typename iterator_traits<Iter>::value_type gcd(Iter first, Iter last)
{
	using T = typename iterator_traits<Iter>::value_type;
	return accumulate(first, last, (T)0, gcd<T>);
}

template<typename T>
inline constexpr T gcd(initializer_list<T> args)
{
	return accumulate(ALL(args), (T)0, gcd<T>);
}

template<typename T>
inline constexpr T lcm(T l, T r) 

{
	return l / gcd(l, r) * r;
}

template<typename Iter>
inline constexpr typename iterator_traits<Iter>::value_type lcm(Iter first, Iter last)
{
	using T = typename iterator_traits<Iter>::value_type;
	return accumulate(first, last, (T)1, lcm<T>);
}

template<typename T>
inline constexpr T lcm(initializer_list<T> args) 

{
	return accumulate(ALL(args), (T)1, lcm<T>);
}

template<typename T>
inline int& argmin(int& a, int& b, vector<T>& V)
{
	return V[b] < V[a] ? b : a;
}

template<typename T>
inline int& argmax(int& a, int& b, vector<T>& V)
{
	return V[a] < V[b] ? b : a;
}

template<typename T>
inline pair<int&, int&> argminmax(int& a, int& b, vector<T>& V)
{
	return V[b] < V[a] ? tie(b, a) : tie(a, b);
}

template<typename T>
inline const int& argmin(const int& a, const int& b, const vector<T>& V)
{
	return V[b] < V[a] ? b : a;
}

template<typename T>
inline const int& argmax(const int& a, const int& b, const vector<T>& V)
{
	return V[a] < V[b] ? b : a;
}

template<typename T>
inline pair<const int&, const int&> argminmax(const int& a, const int& b, const vector<T>& V)
{
	return V[b] < V[a] ? tie(b, a) : tie(a, b);
}

template<size_t S, typename... Ts>
struct TupleHashHelper
{
	typedef std::tuple<Ts...> Tup;
	typedef TupleHashHelper<S - 1, Ts...> Helper;
	typedef std::tuple_element_t<S - 1, Tup> T;
	inline constexpr size_t operator()(const Tup& t) const noexcept
	{
		return 31 * Helper()(t) + std::hash<T>()(std::get<S - 1>(t));
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
struct std::hash<std::tuple<Ts...>>
{
	typedef std::tuple<Ts...> Tup;
	static constexpr size_t S = sizeof...(Ts);
	typedef TupleHashHelper<S, Ts...> Helper;
	inline constexpr size_t operator()(const std::tuple<Ts...>& t) const noexcept
	{
		return Helper()(t);
	}
};

void go();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	

	

	

	

	

	go();
	


	return 0;
}






#endif

constexpr int64_t MOD = 1e9 + 7;

int64_t modpow2(int64_t x)
{
	if (x <= 62)
		return (((int64_t)1) << x) % MOD;
	int64_t ans = modpow2(x / 2);
	return ans * ans % MOD * (((int64_t)1) << (x % 2)) % MOD;
}

void go()
{
	int n;
	cin >> n;
	vlli A(n);
	for (int64_t& a : A)
		cin >> a;

	vlli C(30, 0);
	int64_t oddct = 0;
	for (int64_t a : A)
	{
		int c = 0;
		for (; a % 2 == 0; a /= 2)
			c++;
		if (c == 0)
			oddct++;
		else
			C[c - 1]++;
	}

	int64_t suffix = n - oddct;
	int64_t ans = (modpow2(oddct) + MOD - 1) % MOD * modpow2(suffix) % MOD;

	for (int i = 0; i < 30; i++)
	{
		int64_t c = C[i];
		if (c == 0)
			continue;
		suffix -= c;
		int64_t cur = (modpow2(c - 1) + MOD - 1) % MOD * modpow2(suffix) % MOD;
		ans = (ans + cur) % MOD;
	}

	cout << ans;
}