#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <chrono>
#include <map>
#include <random>
#include <unordered_map>
#include <iterator>
#include <fstream>
#include <numeric>
#include <functional>
#include <exception>
#include <set>
#include <queue>
#include <string_view>
#include <stack>
#include <functional>
#include <type_traits>
#include <optional>
#include <iomanip>
#include <cmath>
#include <bitset>

#ifdef _WIN32
#include <intrin.h>
#endif 


using ll = long long;

ll buildin_one_count(ll number)
{
#ifdef _WIN32
	return __popcnt64(number);
#else
	return __builtin_popcountl(number);
#endif 

}

template <class Container>
ll lsize(const Container& container)
{
	return static_cast<ll>(size(container));
}

#define for_in(x) for (ll i = 0; i < x; ++i)
#define for_n(i, x) for (ll i = 0; i < x; ++i)

using namespace std;

constexpr ll MOD = 1'000'000'000 + 7;
constexpr ll INF = numeric_limits<ll>::max();

namespace segment_tree_ns
{
	template <class T, class binary_func>
	class segment_tree
	{
	public:
		segment_tree(const std::vector<T>& elems)
			: tree_(4 * size(elems)), binary_op_(binary_func{}), tree_size_(size(elems))
		{
			static_assert(
				std::is_constructible_v<std::function<T(T, T)>, binary_func>,
				"wrong binary_func arg : it must be convertible to std::function<T(T, T)>");

			build(elems, 1, 0, tree_size_ - 1);
		}

		T get_value(size_t left, size_t right) const
		{
			auto opt_value = get_value_int(1, 0, tree_size_ - 1, left, right);
			if (opt_value.has_value())
				return opt_value.value();

			throw std::runtime_error("logical error : left > right");
		}

		void update(size_t pos, T new_value)
		{
			update_int(1, 0, tree_size_ - 1, pos, new_value);
		}
	private:
		void build(const std::vector<T>& cont, size_t vertex, size_t left, size_t right)
		{
			if (left == right)
			{
				tree_[vertex] = cont[left];
			}
			else
			{
				size_t center = (left + right) / 2;
				build(cont, vertex * 2, left, center);
				build(cont, vertex * 2 + 1, center + 1, right);
				tree_[vertex] = binary_op_(tree_[vertex * 2], tree_[vertex * 2 + 1]);
			}
		}

		std::optional<T> get_value_int(size_t vertex, size_t tree_left, size_t tree_right, size_t left, size_t right) const
		{
			if (left > right)
				return std::nullopt;
			if (left == tree_left && right == tree_right)
				return tree_[vertex];
			size_t center = (tree_left + tree_right) / 2;

			auto first = get_value_int(vertex * 2, tree_left, center, left, std::min(right, center));
			auto second = get_value_int(vertex * 2 + 1, center + 1, tree_right, std::max(left, center + 1), right);
			if (first.has_value() && second.has_value())
				return binary_op_(first.value(), second.value());
			else if (first.has_value())
				return first.value();
			else
				return second.value();
		}

		void update_int(size_t vertex, size_t tree_left, size_t tree_right, size_t pos, T new_value)
		{
			if (tree_left == tree_right)
			{
				tree_[vertex] = new_value;
			}
			else
			{
				size_t center = (tree_left + tree_right) / 2;
				if (pos <= center)
					update_int(vertex * 2, tree_left, center, pos, new_value);
				else
					update_int(vertex * 2 + 1, center + 1, tree_right, pos, new_value);
				tree_[vertex] = binary_op_(tree_[vertex * 2], tree_[vertex * 2 + 1]);
			}
		}
	private:
		std::vector<T> tree_;
		const size_t tree_size_;
		std::function<T(T, T)> binary_op_;
	};

	template <class T>
	using sum_segment_tree = segment_tree<T, std::plus<T>>;

	template <class T>
	struct max_s
	{
		T operator()(T lhs, T rhs) const { return std::max<T>(lhs, rhs); }
	};
	template <class T>
	using max_segment_tree = segment_tree <T, max_s<T>>;

	template <class T>
	struct min_s
	{
		T operator()(T lhs, T rhs) const { return std::min<T>(lhs, rhs); }
	};
	template <class T>
	using min_segment_tree = segment_tree<T, min_s<T>>;
}

using namespace segment_tree_ns;

namespace range_ns
{
	template<class Container>
	void print(const Container& container, const char* sep = "\n")
	{
		std::copy(container.begin(), container.end(), ostream_iterator<typename Container::value_type>(cout, sep));
	}

	template<class Container, class Compare = std::less<typename Container::value_type>>
	void sort(Container& container, Compare compare = Compare())
	{
		std::sort(container.begin(), container.end(), compare);
	}

	template<class Container, class T>
	decltype(auto) find(Container& container, const T& elem)
	{
		return std::find(container.begin(), container.end(), elem);
	}

	template<class Container, class Condition>
	decltype(auto) find_if(const Container& container, Condition condition)
	{
		return std::find_if(container.begin(), container.end(), condition);
	}

	template<class Container, class Condition = std::less<typename Container::value_type>>
	decltype(auto) max_element(Container& container, Condition condition = Condition())
	{
		return std::max_element(container.begin(), container.end(), condition);
	}

	template<class Container, class Condition = std::less<typename Container::value_type>>
	decltype(auto) min_element(const Container& container, Condition condition = Condition())
	{
		return std::min_element(container.begin(), container.end(), condition);
	}

	template<class Container, class Condition = std::less<typename Container::value_type>>
	decltype(auto) minmax_element(const Container& container, Condition condition = Condition())
	{
		return std::minmax_element(container.begin(), container.end(), condition);
	}

	template<class Container, class Condition>
	decltype(auto) any_of(const Container& container, Condition condition)
	{
		return std::any_of(container.begin(), container.end(), condition);
	}

	template<class Container, class Condition>
	decltype(auto) all_of(const Container& container, Condition condition)
	{
		return std::all_of(container.begin(), container.end(), condition);
	}

	template<class Container, class T>
	decltype(auto) count(const Container& container, const T& elem)
	{
		return std::count(container.begin(), container.end(), elem);
	}

	template<class Container, class Condition>
	decltype(auto) count_if(const Container& container, Condition condition)
	{
		return std::count_if(container.begin(), container.end(), condition);
	}

	template<class Container, class T, class Compare = std::less<typename Container::value_type>>
	decltype(auto) equal_range(const Container& container, const T& elem, Compare compare = Compare())
	{
		return std::equal_range(container.begin(), container.end(), elem, compare);
	}

	template<class Container, class T, class Compare = std::less<typename Container::value_type>>
	decltype(auto) lower_bound(const Container& container, const T& elem, Compare compare = Compare())
	{
		return std::lower_bound(container.begin(), container.end(), elem, compare);
	}

	template<class Container, class T>
	decltype(auto) upper_bound(const Container& container, const T& elem)
	{
		return std::upper_bound(container.begin(), container.end(), elem);
	}

	template<class Container, class T>
	void erase_remove(Container& container, const T& elem)
	{
		container.erase(remove(container.begin(), container.end(), elem), container.end());
	}

	template<class Container, class Condition>
	void erase_remove_if(Container& container, Condition condition)
	{
		container.erase(remove_if(container.begin(), container.end(), condition), container.end());
	}

	template<class Container, class Condition>
	Container copy_if(const Container& container, Condition condition)
	{
		Container container_result;
		copy_if(container.begin(), container.end(), back_inserter(container_result), condition);
		return container_result;
	}

	template <class Container>
	void reverse(Container& container)
	{
		std::reverse(begin(container), end(container));
	}

	struct sum_functor
	{
		ll operator()(ll sum, ll value) const { return sum + value; }
	};

	template<class Container, class Func = sum_functor, class T = ll>
	T reduce(const Container& container, T init_value = T(), Func func = sum_functor())
	{
		return std::accumulate(container.begin(), container.end(), init_value, func);
	}

	template<class Container, class Func = std::equal_to<typename Container::value_type>>
	decltype(auto) adjacent_find(const Container& container, Func func = Func())
	{
		return std::adjacent_find(container.begin(), container.end(), func);
	}

	template<class InContainer, class OutContainer, class TransformFunction>
	void transform(const InContainer& in_container, OutContainer& out_container, TransformFunction transform_function)
	{
		if (out_container.capacity() == 0)
			out_container.reserve(size(in_container) + size(out_container));
		std::transform(in_container.begin(), in_container.end(), back_inserter(out_container), transform_function);
	}

	template <class Container>
	decltype(auto) enumerate(const Container& container)
	{
		using return_type = vector<pair<typename Container::value_type, ll>>;
		return_type out_container;
		const ll n = lsize(container);
		out_container.reserve(n);
		for_in(n)
			out_container.emplace_back(container[i], i);

		return out_container;
	}

	template <class Container, class PredicateCompare = equal_to<typename Container::value_type>>
	void erase_unique(Container& container, PredicateCompare compare = PredicateCompare())
	{
		container.erase(
			std::unique(
				begin(container),
				end(container),
				compare),
			end(container));
	}

	template <class Container, class SearchT>
	decltype(auto) search(Container& container, const SearchT& to_search)
	{
		return std::search(
			begin(container),
			end(container),
			begin(to_search),
			end(to_search)
		);
	}

	template <class Container, class Compare = std::less<typename Container::value_type>>
	bool binary_search(const Container& container, typename Container::value_type& elem, Compare compare = Compare())
	{
		return std::binary_search(cbegin(container), cend(container), elem);
	}
}

using namespace range_ns;

auto sort_by_first = [](const auto& lhs, const auto& rhs)
{
	return get<0>(lhs) < get<0>(rhs);
};

auto sort_by_second = [](const auto& lhs, const auto& rhs)
{
	return get<1>(lhs) < get<1>(rhs);
};

template <class T>
decltype(auto) read_vector(ll n)
{
	vector<T> res(n);
	for (auto& i : res)
		cin >> i;
	return res;
}

using factorization_map = unordered_map<ll, ll>;

// factorize
factorization_map factorize(ll n)
{
	factorization_map ans;

	while (n % 2 == 0)
	{
		++ans[2];
		n = n / 2;
	}

	for (ll i = 3; i <= sqrt(n); i = i + 2)
	{
		while (n % i == 0)
		{
			++ans[i];
			n = n / i;
		}
	}

	// n is prime
	if (n > 2)
		++ans[n];

	return ans;
};

ll ceil_div(ll n, ll k)
{
	return static_cast<ll>(ceil(static_cast<double>(n) / k));
}

using graph = vector<vector<ll>>;
using weight_graph = vector<vector<pair<ll, ll>>>;

ll bfs(const graph& g, ll vertex, ll value, vector<bool>& visited, ll& count)
{
	visited[vertex] = true;
	stack<ll> q;
	q.push(vertex);

	while (!empty(q))
	{
		ll s = q.top();
		q.pop();
		for (ll v : g[s])
		{
			if (visited[v])
				continue;

			visited[v] = true;
			q.push(v);
		}
	}

	return 0;
}

void debth_first_search(const graph& graph, ll start_vertex, ll end_vertex)
{
	stack<ll> vertex_stack;
	vertex_stack.push(start_vertex);
	vector<bool> visited(size(graph), false);
	visited[start_vertex] = true;

	vector<ll> path(size(graph), -1);
	while (!vertex_stack.empty())
	{
		ll vertex = vertex_stack.top();
		vertex_stack.pop();

		for (ll v : graph[vertex])
			if (!visited[v])
			{
				visited[v] = true;
				vertex_stack.push(v);
				path[v] = vertex;
			}
	}

	vector<ll> path_end_start = { end_vertex };
	ll vertex = -1;
	while (vertex != start_vertex)
	{
		vertex = path[path_end_start.back()];
		path_end_start.push_back(vertex);
	}

	range_ns::reverse(path_end_start);
}

vector<ll> topological_sort(const graph& g)
{
	ll n = lsize(g);
	vector<bool> used(n, false);
	vector<ll> ans;
	ans.reserve(n);

	function<void(ll)> topological_sort_dfs;
	topological_sort_dfs = [&g, &used, &ans, &topological_sort_dfs](ll v)
	{
		used[v] = true;
		for (ll vertex : g[v])
			if (!used[vertex])
				topological_sort_dfs(vertex);
		ans.push_back(v);
	};

	for (int i = 0; i < n; ++i)
		if (!used[i])
			topological_sort_dfs(i);

	reverse(ans);
	return ans;
}

class disjoint_set_union
{
public:
	disjoint_set_union(ll n) : rank(vector<ll>(n, -1)), parent(vector<ll>(n, -1)) {}

	void union_sets(ll a, ll b)
	{
		if (!in_set(a))
			make_set(a);
		if (!in_set(b))
			make_set(b);

		a = find_set(a);
		b = find_set(b);
		if (a != b)
		{
			if (rank[a] < rank[b])
				swap(a, b);
			parent[b] = a;
			if (rank[a] == rank[b])
				++rank[a];
		}
	}

	bool in_different_sets(ll a, ll b)
	{
		return !in_set(a) || !in_set(b) || find_set(a) != find_set(b);
	}

private:
	void make_set(ll v)
	{
		parent[v] = v;
		rank[v] = 0;
	}

	ll find_set(ll v)
	{
		if (v == parent[v])
			return v;
		return parent[v] = find_set(parent[v]);
	}

	bool in_set(ll v) const
	{
		return rank[v] != -1;
	}

private:
	vector<ll> rank;
	vector<ll> parent;
};

using weight_edge = tuple<ll, ll, ll>;
using mst_pair = pair<ll, vector<pair<ll, ll>>>;

weight_graph minimum_spanning_tree_kruskal(vector<weight_edge>& weight_edges, ll n)
{
	weight_graph g(n);
	sort(weight_edges, sort_by_first);
	disjoint_set_union dsu(n);

	for (auto[weight, i, j] : weight_edges)
	{
		if (dsu.in_different_sets(i, j))
		{
			g[i].emplace_back(weight, j);
			g[j].emplace_back(weight, i);
			dsu.union_sets(i, j);
		}
	}

	return g;
}

weight_graph minimum_spanning_tree_prim(const weight_graph& g)
{
	const ll n = lsize(g);
	weight_graph mst(n);
	vector<bool> processed(n, false);

	priority_queue<tuple<ll, ll, ll>> pq_edges;
	pq_edges.emplace(0, 0, -1);

	while (!empty(pq_edges))
	{
		auto[weight, vertex, from] = pq_edges.top();
		pq_edges.pop();
		if (processed[vertex])
			continue;
		processed[vertex] = true;
		if (from != -1)
		{
			mst[vertex].emplace_back(-weight, from);
			mst[from].emplace_back(-weight, vertex);
		}
		for (auto[weight, to] : g[vertex])
			pq_edges.emplace(-weight, to, vertex);
	}

	return mst;
}

class least_common_ancestor
{
public:
	least_common_ancestor(const weight_graph& g)
	{
		try
		{
			const ll n = lsize(g);
			m_pre_processing.resize(n);
			ll log_n = static_cast<ll>(ceil(log2(n))) + 1;
			for (auto& v : m_pre_processing)
				v.resize(log_n);
			m_vertex_depths.resize(n);

			vector<bool> visited(n);
			visited[0] = true;
			stack<ll> q;
			q.push(0);

			while (!empty(q))
			{
				ll s = q.top();
				q.pop();
				for (auto[weight, v] : g[s])
				{
					if (visited[v])
						continue;

					m_vertex_depths[v] = m_vertex_depths[s] + 1;
					m_pre_processing[v][0] = { weight, s };
					visited[v] = true;
					q.push(v);
				}
			}

			for (ll j = 1; j < log_n; ++j)
			{
				for (ll i = 0; i < n; ++i)
				{
					auto[weight, ancestor] = m_pre_processing[i][j - 1];
					m_pre_processing[i][j].first = max(weight, m_pre_processing[ancestor][j - 1].first);
					m_pre_processing[i][j].second = m_pre_processing[ancestor][j - 1].second;
				}
			}
		}
		catch (exception& ex)
		{
			cout << ex.what();
		}
	}

	pair<ll, ll> get(ll i, ll j)
	{
		try
		{
			if (m_vertex_depths[i] > m_vertex_depths[j])
				swap(i, j);

			ll max_weight = -INF;
			while (m_vertex_depths[j] != m_vertex_depths[i])
			{
				ll previous_up = 0, up = 0;
				while (m_vertex_depths[m_pre_processing[j][up].second] > m_vertex_depths[i])
					previous_up = up++;

				auto[weight, ancestor] = m_pre_processing[j][previous_up];
				j = ancestor;
				max_weight = max(max_weight, weight);
			}

			// now i and j on the same height
			while (m_pre_processing[i][0].second != m_pre_processing[j][0].second)
			{
				ll previous_up = 0, up = 0;
				while (m_pre_processing[i][up].second != m_pre_processing[j][up].second)
					previous_up = up++;

				max_weight = max(max_weight, max(m_pre_processing[i][previous_up].first, m_pre_processing[j][previous_up].first));
				i = m_pre_processing[i][previous_up].second;
				j = m_pre_processing[j][previous_up].second;
			}

			if (i != j)
				max_weight = max(max_weight, max(m_pre_processing[i][0].first, m_pre_processing[j][0].first));
			return pair(max_weight, m_pre_processing[i][0].second);
		}
		catch (exception& ex)
		{
			cout << ex.what();
			return { -1, -1 };
		}
	}

private:
	using weight_ancestor_pair = pair<ll, ll>;
	vector<vector<weight_ancestor_pair>> m_pre_processing;
	vector<ll> m_vertex_depths;
};

vector<ll> dijkstra(const weight_graph& g, ll v)
{
	const ll n = lsize(g);
	vector<ll> distances(n, INF);
	vector<bool> processed(n, false);

	priority_queue<pair<ll, ll>> pq_edges;
	pq_edges.emplace(0, v);
	while (!empty(pq_edges))
	{
		ll vertex = pq_edges.top().second;
		pq_edges.pop();
		if (processed[vertex])
			continue;
		processed[vertex] = true;
		for (auto[weight, to] : g[vertex])
		{
			if (distances[vertex] + weight < distances[to])
			{
				distances[to] = distances[vertex] + weight;
				pq_edges.emplace(-distances[to], to);
			}
		}
	}

	return distances;
}

bool cycle_exist_in_oriented_graph(const graph& g)
{
	enum class vertex_state
	{
		not_processed,
		is_processing,
		processed
	};

	const ll n = lsize(g);
	vector<vertex_state> states(n, vertex_state::not_processed);
	function<bool(ll)> dfs;
	dfs = [&dfs, &g, &states](ll vertex) -> bool
	{
		if (states[vertex] == vertex_state::is_processing)
			return true;
		else if (states[vertex] == vertex_state::processed)
			return false;

		states[vertex] = vertex_state::is_processing;
		for (ll v : g[vertex])
			if (dfs(v))
				return true;
		states[vertex] = vertex_state::processed;
		return false;
	};

	for_in(n)
		if (dfs(i))
			return true;
	return false;
}

graph read_graph(ll n, ll m, bool is_oriented = false)
{
	graph g(n);
	for_n(k, m)
	{
		ll i, j;
		cin >> i >> j;
		--i;
		--j;
		g[i].push_back(j);
		if (!is_oriented)
			g[j].push_back(i);
	}

	return g;
}

ll bin_pow_mod(ll a, ll b)
{
	if (b == 0)
		return 1;

	if (b % 2)
	{
		return (a * bin_pow_mod(a, b - 1)) % MOD;
	}
	else
	{
		ll tmp = bin_pow_mod(a, b / 2);
		return (tmp * tmp) % MOD;
	}
}

vector<int> z_function(string_view s)
{
	int n = (int)s.length();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}

int find_fisrt_occurance(const string& t, const string& p)
{
	auto vec = z_function(p + "#" + t);
	for (int i = 0; i < lsize(t); ++i)
		if (vec[i + lsize(p) + 1] == lsize(p))
			return i;

	return -1;
}

ll count_distinct_subsequnces(string_view s)
{
	vector<ll> dp_alphabet(26);
	for_in(lsize(s))
		dp_alphabet[s[i] - 'a'] = (1 + reduce(dp_alphabet)) % MOD;
	return (1 + reduce(dp_alphabet)) % MOD;
};

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m;
	cin >> n >> m;
	auto g = read_graph(n, m);
	vector<bool> visited(n, false);
	vector<ll> ans;
	ans.reserve(n);
	function<void(ll)> dfs;
	set<ll> candidates;
	dfs = [&dfs, &g, &visited, &ans, &candidates](ll vertex)
	{
		if (visited[vertex])
			return;
		visited[vertex] = true;
		ans.push_back(vertex + 1);
		for (ll v : g[vertex])
		{
			if (!visited[v])
				candidates.insert(v);
		}

		if (empty(candidates))
			return;
		ll to_v = *begin(candidates);
		candidates.erase(begin(candidates));
		dfs(to_v);

	};
	dfs(0);
	print(ans, " ");
	return 0;
}
