











































































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
		for (const auto& element : elements)
		{
			if (!first) convert += ", ";
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



template<typename Arg, typename... Args> void inline read(std::istream& in, Arg& first, Args& ... rest);

template<typename T1, typename T2> void inline read(std::istream& in, std::pair<T1, T2>& element);

template<typename T, std::size_t Size> void inline read(std::istream& in, std::array<T, Size>& elements);

template<typename T> void inline read(std::istream& in, double& element);

template<typename T> void inline read(std::istream& in, long double& element);

template<typename T> void inline read(std::istream& in, std::complex<T>& element);

template<typename T> void inline read(std::istream& in, std::tuple<T, T, T, T, T, T>& element);

template<typename T> void inline read(std::istream& in, std::tuple<T, T, T, T, T>& element);

template<typename T> void inline read(std::istream& in, std::tuple<T, T, T, T>& element);

template<typename T> void inline read(std::istream& in, std::tuple<T, T, T>& element);

template<typename T> void inline read(std::istream& in, std::vector<T>& elements);

template<typename T> void inline read(std::istream& in, T& element);

template<typename Arg, typename... Args> void inline read(std::istream& in, Arg& first, Args& ... rest)
{
	read(in, first);
	read(in, rest...);
}

template<typename T1, typename T2> void inline read(std::istream& in, std::pair<T1, T2>& element) { read(in, element.first, element.second); }

template<typename T, std::size_t Size> void inline read(std::istream& in, std::array<T, Size>& elements) { for(auto& element : elements) read(in, element); }

void inline read(std::istream& in, double& element)
{
	std::string convert;
	read(in, convert);
	element = std::stod(convert);
}

void inline read(std::istream& in, long double& element)
{
	std::string convert;
	read(in, convert);
	element = std::stold(convert);
}

template<typename T> void inline read(std::istream& in, std::complex<T>& element)
{
	T first, second;
	read(in, first, second);
	element = std::complex<T>(first, second);
}

template<typename T> void inline read(std::istream& in, std::tuple<T, T, T, T, T, T>& element) { read(in, std::get<0>(element), std::get<1>(element), std::get<2>(element), std::get<3>(element), std::get<4>(element), std::get<5>(element)); }

template<typename T> void inline read(std::istream& in, std::tuple<T, T, T, T, T>& element) { read(in, std::get<0>(element), std::get<1>(element), std::get<2>(element), std::get<3>(element), std::get<4>(element)); }

template<typename T> void inline read(std::istream& in, std::tuple<T, T, T, T>& element) { read(in, std::get<0>(element), std::get<1>(element), std::get<2>(element), std::get<3>(element)); }

template<typename T> void inline read(std::istream& in, std::tuple<T, T, T>& element) { read(in, std::get<0>(element), std::get<1>(element), std::get<2>(element)); }

template<typename T> void inline read(std::istream& in, std::vector<T>& elements) { for(auto& element : elements) read(in, element); }

template<typename T> void inline read(std::istream& in, T& element) { in >> element; }



template<typename Arg, typename... Args> void inline print(std::ostream& out, const Arg& first, const Args& ... rest);

template<typename Arg, typename... Args> void inline prints(std::ostream& out, const Arg& first, const Args& ... rest);

template<typename T> void inline print(std::ostream& out, const T& element);

void inline prints(std::ostream& out);

template<typename Arg, typename... Args> void inline print(std::ostream& out, const Arg& first, const Args& ... rest)
{
	print(out, first);
	print(out, rest...);
}

template<typename Arg, typename... Args> void inline prints(std::ostream& out, const Arg& first, const Args& ... rest)
{
	print(out, first);
	if(sizeof...(rest)) print(out, " ");
	prints(out, rest...);
}

template<typename T> void inline print(std::ostream& out, const T& element) { out << std::to_string(element); }

void inline prints(std::ostream& out) { print(out, '\n'); }

void setIO()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin.exceptions(std::ios::eofbit | std::ios::failbit | std::ios::badbit);

}



using namespace std;

constexpr long long MAXN id1((unused)) = static_cast<long long>(2 * 1e5 + 1);
constexpr long long INF id1((unused)) = static_cast<long long>(1e18 + 1);
constexpr long long MOD id1((unused)) = static_cast<long long>(1e9 + 7);
constexpr long double EPS id1((unused)) = static_cast<long double>(1e-7);














template<class Edge> class Graph
{
	std::vector<std::vector<Edge>> graph;
public:
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






















struct BiEdge
{
	static constexpr bool reversable = true;
	std::size_t to;
public:
	BiEdge(const std::size_t& u_to) : to{u_to} {}
};




template<typename T> struct id0 : public BiEdge
{
	static constexpr bool reversable = true;
	T weight;

	id0(const std::size_t& u_to, const T& u_weight) : BiEdge{u_to}, weight{u_weight} {}
};


















template<typename Edge, typename T> std::pair<std::vector<T>, std::vector<std::size_t>> dijkstra(const Graph<Edge>& graph, const std::size_t& source, std::vector<T>& costs, std::vector<std::size_t>& parent)
{
	std::priority_queue<std::pair<T, std::size_t>, std::vector<std::pair<T, std::size_t>>, std::greater<std::pair<T, std::size_t>>> next;
	std::vector<bool> visited(graph.size(), false);
	costs[source] = 0;
	parent[source] = source;
	next.emplace(costs[source], source);
	while(!next.empty())
	{
		std::size_t top = next.top().second;
		next.pop();
		if(!visited[top])
		{
			visited[top] = true;
			for(const auto& neighbor : graph[top])
				if(!visited[neighbor.to] && costs[neighbor.to] > costs[top] + neighbor.weight)
				{
					costs[neighbor.to] = costs[top] + neighbor.weight;
					parent[neighbor.to] = top;
					next.emplace(costs[neighbor.to], neighbor.to);
				}
		}
	}
	return std::make_pair(costs, parent);
}

template<typename Edge, typename T> std::pair<std::vector<T>, std::vector<std::size_t>> dijkstra(const Graph<Edge>& graph, const std::size_t& source)
{
	std::vector<T> costs(graph.size(), std::numeric_limits<T>::max());
	std::vector<std::size_t> parent(graph.size(), std::numeric_limits<std::size_t>::max());
	std::priority_queue<std::pair<T, std::size_t>, std::vector<std::pair<T, std::size_t>>, std::greater<std::pair<T, std::size_t>>> next;
	std::vector<bool> visited(graph.size(), false);
	costs[source] = 0;
	parent[source] = source;
	next.emplace(costs[source], source);
	while(!next.empty())
	{
		std::size_t top = next.top().second;
		next.pop();
		if(!visited[top])
		{
			visited[top] = true;
			for(const auto& neighbor : graph[top])
				if(!visited[neighbor.to] && costs[neighbor.to] > costs[top] + neighbor.weight)
				{
					costs[neighbor.to] = costs[top] + neighbor.weight;
					parent[neighbor.to] = top;
					next.emplace(costs[neighbor.to], neighbor.to);
				}
		}
	}
	return std::make_pair(costs, parent);
}



class CDijkstra
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		std::size_t n, m;
		read(in, n, m);
		Graph<id0<ll>> graph(n);
		for(std::size_t i = 0; i < m; ++i)
		{
			std::size_t a, b;
			ll w;
			read(in, a, b, w);
			graph.addEdge(a - 1, b - 1, w);
		}
		auto result = dijkstra<id0<ll>, ll>(graph, 0);
		if(result.ff[n - 1] == numeric_limits<ll>::max()) cout << -1 << '\n';
		else
		{
			vector<std::size_t> finals{n};
			std::size_t i = n - 1;
			while(i != result.ss[i])
			{
				i = result.ss[i];
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