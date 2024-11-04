










#ifndef LOCAL

#include <x86intrin.h>

#pragma GCC optimize("fast-math,no-stack-protector,Ofast,omit-frame-pointer,unroll-loops,inline")
#pragma GCC option("arch=native,no-zero-upper,tune=native")
#pragma GCC target("abm,avx,avx2,bmi2,fma,mmx,popcnt,sse,sse2,sse3,sse4,ssse3")

#endif

#ifndef GENERAL_HPP
#define GENERAL_HPP






#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
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
#include <iostream>
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
#include <string>
#include <thread>
#include <tuple>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<typename T> using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

using ui = unsigned int;
using ul = unsigned long long;
using ll = long long;
using ld = long double;
using cd = std::complex<long double>;

using pui = std::pair<unsigned int, unsigned int>;
using pii = std::pair<int, int>;
using pul = std::pair<unsigned long long, unsigned long long>;
using pll = std::pair<long long, long long>;
using pld = std::pair<long double, long double>;
using pcd = std::pair<std::complex<long double>, std::complex<long double>>;

using vui = std::vector<unsigned int>;
using vii = std::vector<int>;
using vul = std::vector<unsigned long long>;
using vll = std::vector<long long>;
using vld = std::vector<long double>;
using vcd = std::vector<std::complex<long double>>;

using vpui = std::vector<std::pair<unsigned int, unsigned int>>;
using vpii = std::vector<std::pair<int, int>>;
using vpul = std::vector<std::pair<unsigned long long, unsigned long long>>;
using vpll = std::vector<std::pair<long long, long long>>;
using vpld = std::vector<std::pair<long double, long double>>;
using vpcd = std::vector<std::pair<std::complex<long double>, std::complex<long double>>>;

#define FOR(i, a, b) for (auto (i) = (a); (i) < (b); ++(i))
#define F0R(i, a) FOR((i), 0, (a))
#define ROF(i, a, b) for (auto (i) = (a); (i) >= (b); --(i))
#define R0F(i, a) ROF((i), (a), 0)
#define ITR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define FSRT(set) std::sort((set).begin(),(set).end())
#define RSRT(set) std::sort((set).rbegin(),(set).rend())
#define CSRT(set, function) std::sort((set).begin(),(set).end(), (function))
#define UNIQUE(set) std::sort((set).begin(), (set).end()), (set).erase(std::unique((set).begin(), (set.end())), (a).end())

#define ALL(set) (set).begin(), (set).end()
#define RALL(set) (set).rbegin(), (set).rend()

#define mp std::make_pair
#define mt std::make_tuple
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound

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
		for (const auto& element : elements)
		{
			if (!first) convert += ", ";
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



template<typename Arg, typename... Args> void read(std::istream& in, Arg& first, Args& ... rest);

template<typename T1, typename T2> void read(std::istream& in, std::pair<T1, T2>& element);

template<typename T, std::size_t Size> void read(std::istream& in, std::array<T, Size>& elements);

template<typename T> void read(std::istream& in, double& element);

template<typename T> void read(std::istream& in, long double& element);

template<typename T> void read(std::istream& in, std::complex<T>& element);

template<typename T> void read(std::istream& in, std::tuple<T, T, T, T, T, T>& element);

template<typename T> void read(std::istream& in, std::tuple<T, T, T, T, T>& element);

template<typename T> void read(std::istream& in, std::tuple<T, T, T, T>& element);

template<typename T> void read(std::istream& in, std::tuple<T, T, T>& element);

template<typename T> void read(std::istream& in, std::vector<T>& elements);

template<typename T> void read(std::istream& in, T& element);

template<typename Arg, typename... Args> void read(std::istream& in, Arg& first, Args& ... rest)
{
	read(in, first);
	read(in, rest...);
}

template<typename T1, typename T2> void read(std::istream& in, std::pair<T1, T2>& element) { read(in, element.first, element.second); }

template<typename T, std::size_t Size> void read(std::istream& in, std::array<T, Size>& elements) { for(auto& element : elements) read(in, element); }

void read(std::istream& in, double& element)
{
	std::string convert;
	read(in, convert);
	element = std::stod(convert);
}

void read(std::istream& in, long double& element)
{
	std::string convert;
	read(in, convert);
	element = std::stold(convert);
}

template<typename T> void read(std::istream& in, std::complex<T>& element)
{
	T first, second;
	read(in, first, second);
	element = std::complex<T>(first, second);
}

template<typename T> void read(std::istream& in, std::tuple<T, T, T, T, T, T>& element) { read(in, std::get<0>(element), std::get<1>(element), std::get<2>(element), std::get<3>(element), std::get<4>(element), std::get<5>(element)); }

template<typename T> void read(std::istream& in, std::tuple<T, T, T, T, T>& element) { read(in, std::get<0>(element), std::get<1>(element), std::get<2>(element), std::get<3>(element), std::get<4>(element)); }

template<typename T> void read(std::istream& in, std::tuple<T, T, T, T>& element) { read(in, std::get<0>(element), std::get<1>(element), std::get<2>(element), std::get<3>(element)); }

template<typename T> void read(std::istream& in, std::tuple<T, T, T>& element) { read(in, std::get<0>(element), std::get<1>(element), std::get<2>(element)); }

template<typename T> void read(std::istream& in, std::vector<T>& elements) { for(auto& element : elements) read(in, element); }

template<typename T> void read(std::istream& in, T& element) { in >> element; }



template<typename Arg, typename... Args> void print(std::ostream& out, const Arg& first, const Args& ... rest);

template<typename Arg, typename... Args> void prints(std::ostream& out, const Arg& first, const Args& ... rest);

template<typename T> void print(std::ostream& out, const T& element);

void prints(std::ostream& out);

template<typename Arg, typename... Args> void print(std::ostream& out, const Arg& first, const Args& ... rest)
{
	print(out, first);
	print(out, rest...);
}

template<typename Arg, typename... Args> void prints(std::ostream& out, const Arg& first, const Args& ... rest)
{
	print(out, first);
	if(sizeof...(rest)) print(out, " ");
	prints(out, rest...);
}

template<typename T> void print(std::ostream& out, const T& element) { out << std::to_string(element); }

void prints(std::ostream& out) { print(out, '\n'); }

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

using namespace std;

constexpr long long MAXN __attribute__((unused)) = static_cast<long long>(2 * 1e5 + 1);
constexpr long long INF __attribute__((unused)) = static_cast<long long>(1e18 + 1);
constexpr long long MOD __attribute__((unused)) = static_cast<long long>(1e9 + 7);
constexpr long double EPS __attribute__((unused)) = static_cast<long double>(1e-7);

#ifndef GRAPH_HPP
#define GRAPH_HPP








#include <cstddef>


template<class Edge> class Graph
{
	std::vector<std::vector<Edge>> graph;
public:
	Graph() = default;

	Graph(const std::size_t& N) : graph{N, std::vector<Edge>()} {}

	template<typename...Args> void addEdge(const std::size_t& from, const std::size_t& to, Args& ... args)
	{
		graph[from].emplace_back(to, args...);
		if(Edge::reversable) graph[to].emplace_back(from, args...);
	}

	void extend() { graph.emplace_back(); }

	std::size_t size() const noexcept { return graph.size(); }

	bool empty() const noexcept { return graph.empty(); }

	template<typename InputIterator> void assign(InputIterator first, InputIterator last) { graph.assign(first, last); }

	void assign(const std::size_t& N, const std::vector<Edge>& value) { graph.assign(N, value); }

	void assign(const std::initializer_list<std::vector<Edge>>& elements) { graph.assign(elements); }

	auto begin() noexcept { return graph.begin(); }

	auto begin() const noexcept { return graph.begin(); }

	auto end() noexcept { return graph.end(); }

	auto end() const noexcept { return graph.end(); }

	auto rbegin() noexcept { return graph.rbegin(); }

	auto rbegin() const noexcept { return graph.rbegin(); }

	auto rend() noexcept { return graph.rend(); }

	auto rend() const noexcept { return graph.rend(); }

	auto cbegin() const noexcept { return graph.cbegin(); }

	auto cend() const noexcept { return graph.cend(); }

	auto crbegin() const noexcept { return graph.crbegin(); }

	auto crend() const noexcept { return graph.crend(); }

	auto& operator[](const std::size_t& at) { return graph[at]; }

	const auto& operator[](const std::size_t& at) const { return graph[at]; }

	auto& at(const std::size_t& at) { return graph.at(at); };

	const auto& at(const std::size_t& at) const { return graph.at(at); };

	auto& front() { return graph.front(); }

	const auto& front() const { return graph.front(); }

	auto& back() { return graph.back(); }

	const auto& back() const { return graph.back(); }

	void clear() noexcept { graph.clear(); }

	void resize(const std::size_t& N) { graph.resize(N); };

	void resize(const std::size_t& N, const std::vector<Edge>& value) { graph.resize(N, value); };
};

#endif
#ifndef WEIGHTED_BI_EDGE_HPP
#define WEIGHTED_BI_EDGE_HPP







#ifndef BI_EDGE_HPP
#define BI_EDGE_HPP









struct BiEdge
{
	static constexpr bool reversable = true;
	std::size_t to;
public:
	BiEdge(const std::size_t& u_to) : to{u_to} {}
};

#endif


template<typename T> struct WeightedBiEdge : public BiEdge
{
	static constexpr bool reversable = true;
	T weight;

	WeightedBiEdge(const std::size_t& u_to, const T& u_weight) : BiEdge{u_to}, weight{u_weight} {}
};

#endif


#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP











template<class Edge, class T> class Dijkstra
{
	Graph<Edge> m_graph;
	std::vector<T> m_costs;
	std::vector<std::size_t> m_parents;
	std::vector<bool> m_visited;
	std::priority_queue<std::pair<T, std::size_t>, std::vector<std::pair<T, std::size_t>>, std::greater<std::pair<T, std::size_t>>> m_next;
public:
	explicit Dijkstra(const Graph<Edge>& graph) : m_graph{graph} { reset(); }

	void explore(const std::size_t& source, const bool& clear = false)
	{
		if(clear) reset();
		m_costs[source] = 0;
		m_parents[source] = source;
		m_next.emplace(m_costs[source], source);
		while(!m_next.empty())
		{
			std::size_t top = m_next.top().second;
			m_next.pop();
			if(m_visited[top]) continue;
			m_visited[top] = true;
			for(const auto& neighbor : m_graph[top])
				if(!m_visited[neighbor.to] && m_costs[neighbor.to] > m_costs[top] + neighbor.weight)
				{
					m_costs[neighbor.to] = m_costs[top] + neighbor.weight;
					m_parents[neighbor.to] = top;
					m_next.emplace(m_costs[neighbor.to], neighbor.to);
				}
		}
	}

	void reset()
	{
		m_costs.assign(m_graph.size(), std::numeric_limits<T>::max());
		m_parents.assign(m_graph.size(), std::numeric_limits<std::size_t>::max());
		m_visited.assign(m_graph.size(), false);
	}

	std::vector<T> costs() const { return m_costs; }

	std::vector<std::size_t> parents() const { return m_parents; }

	std::vector<bool> visited() const { return m_visited; }
};

#endif

class CDijkstra
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		std::size_t n, m;
		read(in, n, m);
		Graph<WeightedBiEdge<ll>> graph(n);
		for(std::size_t i = 0; i < m; ++i)
		{
			std::size_t a, b;
			ll w;
			read(in, a, b, w);
			graph.addEdge(a - 1, b - 1, w);
		}
		Dijkstra<WeightedBiEdge<ll>, ll> dijkstra(graph);
		dijkstra.explore(0);
		auto final = dijkstra.costs()[n - 1];
		if(final == numeric_limits<ll>::max()) cout << -1 << '\n';
		else
		{
			vector<std::size_t> finals{n};
			std::size_t i = n - 1;
			auto parents = dijkstra.parents();
			while(i != parents[i])
			{
				i = parents[i];
				finals.pb(i + 1);
			}
			reverse(ALL(finals));
			prints(out, finals);
		}
	}
};

int main()
{
	setIO();
	CDijkstra solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	std::fflush(stdout);
	return 0;
}