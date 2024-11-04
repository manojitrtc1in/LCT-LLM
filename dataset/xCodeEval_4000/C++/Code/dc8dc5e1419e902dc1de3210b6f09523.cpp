#include <vector>
#include <string>
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
    decltype(auto) find(const Container& container, const T& elem)
    {
	return std::find(container.begin(), container.end(), elem);
    }

    template<class Container, class Condition>
    decltype(auto) find_if(Container& container, Condition condition)
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

    template<class Container, class Func>
    decltype(auto) for_each(Container& container, Func func)
    {
	return std::for_each(container.begin(), container.end(), func);
    }

    template<class Container, class T>
    decltype(auto) equal_range(const Container& container, const T& elem)
    {
	return std::equal_range(container.begin(), container.end(), elem);
    }

    template<class Container, class T, class Compare = std::less<typename Container::value_type>>
    decltype(auto) lower_bound(const Container& container, const T& elem, Compare compare = Compare())
    {
	return std::lower_bound(container.begin(), container.end(), elem, compare);
    }

    template<class Container, class T, class Compare = std::less<typename Container::value_type>>
    decltype(auto) upper_bound(const Container& container, const T& elem, Compare compare = Compare())
    {
	return std::upper_bound(container.begin(), container.end(), elem, compare);
    }

    vector<ll> iota(ll number)
    {
	vector<ll> vec(number);
	std::iota(vec.begin(), vec.end(), 1);
	return vec;
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

    template<class Container, class Func = sum_functor>
    ll reduce(const Container& container, ll init_value = 0, Func func = sum_functor())
    {
	return std::accumulate(container.begin(), container.end(), init_value, func);
    }

    template<class Container, class Func = std::equal_to<typename Container::value_type>>
    decltype(auto) adjacent_find(const Container& container, Func func = Func())
    {
	return std::adjacent_find(container.begin(), container.end(), func);
    }

    template<class Container, class Predicate>
    vector<ll> copy_indexes(const Container& container, Predicate predicate)
    {
	vector<ll> indexes;
	for_in(lsize(container))
	    if (predicate(container[i]))
		indexes.push_back(i);

	return indexes;
    }

    template<class InContainer, class OutContainer, class TransformFunction>
    void transform(const InContainer& in_container, OutContainer& out_container, TransformFunction transform_function)
    {
	if (out_container.capacity() == 0)
	    out_container.reserve(size(in_container));
	std::transform(in_container.begin(), in_container.end(), back_inserter(out_container), transform_function);
    }
}

template <class T>
decltype(auto) read_vector(ll n)
{
    vector<T> res(n);
    for (auto& i : res)
	cin >> i;
    return res;
}

using Graph = vector<vector<ll>>;
using namespace segment_tree_ns;

void debth_first_search(const Graph& graph, ll start_vertex, ll end_vertex)
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
    range_ns::for_each(path_end_start, [](ll& v) { ++v; });
    range_ns::print(path_end_start, " ");
}

using factorization_map = unordered_map<ll, ll>;



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

    

    if (n > 2)
	++ans[n];

    return ans;
};

using namespace range_ns;

template <class Condition>
ll binary_search(ll l, ll r, Condition condition)
{
    while (l <= r)
    {
	ll m = (l + r) / 2;
	if (!condition(m))
	    r = m - 1;
	else
	    l = m + 1;
    }

    return min(l, r);
}

vector<int> z_function(string_view s) {
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

template <class T>
struct pt
{
    pt(T x_, T y_) : x(x_), y(y_) {}
    pt() {}
    T x, y;
};

template <class T>
bool operator== (const pt<T>& lhs, const pt<T>& rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

template <class T>
struct rectangle
{
    rectangle() {}
    rectangle(const pt<T>& p1_, const pt<T>& p2_) : p1(p1_), p2(p2_) {}
    pt<T> p1, p2;
};

using doble_pt = pt<double>;
using ll_pt = pt<ll>;
using double_rectangle = rectangle<double>;
using ll_rectangle = rectangle<ll>;

ll ceil_div(ll n, ll k)
{
    return static_cast<ll>(ceil(static_cast<double>(n) / k));
}

int find_fisrt_occurance(const string& t, const string& p)
{
    auto vec = z_function(p + "#" + t);
    for (int i = 0; i < lsize(t); ++i)
	if (vec[i + lsize(p) + 1] == lsize(p))
	    return i;

    return -1;
}

constexpr ll constexpr_pow(ll a, ll b)
{
    ll ans = 1;
    for_in(b)
	ans *= a;
    return ans;
}

ll MOD = 998244353;

vector<ll> BFS(const Graph& g)
{
    const ll n = lsize(g);
    vector<ll> distance(n, 0);
    vector<bool> visited(n, false);
    ll vertex = 0;
    queue<ll> q;
    visited[vertex] = true;
    q.push(vertex);

    while (!empty(q))
    {
	ll s = q.front();
	q.pop();
	for (ll v : g[s])
	{
	    if (visited[v])
		continue;
	    visited[v] = true;
	    distance[v] = distance[s] + 1;
	    q.push(v);
	}
    }

    return distance;
}

ll gcd(ll a, ll b, ll & x, ll & y)
{
    if (a == 0)
    {
	x = 0; y = 1;
	return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll inverse(ll a, ll m)
{
    ll x, y;
    ll g = gcd(a, m, x, y);
    x = (x % m + m) % m;
    return x;
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

auto sort_by_first = [](const auto& lhs, const auto& rhs)
{
    return get<0>(lhs) < get<0>(rhs);
};

int main(int argc, char** argv)
{
    ll n; 
    cin >> n;
    ll my_balloons, my_weight;
    cin >> my_balloons >> my_weight;
    vector<pair<ll, ll>> participants;
    participants.reserve(n - 1);
    for_in(n - 1)
    {
	ll balloons, weight;
	cin >> balloons >> weight;
	participants.emplace_back(balloons, weight);
    }
    sort(participants, sort_by_first);
    auto it = upper_bound(participants, pair(my_balloons, my_weight), sort_by_first);
    ll place = cend(participants) - it + 1;
    vector<ll> cont;
    cont.reserve(n);
    priority_queue<ll, vector<ll>, greater<ll>> leaders_to_fly_pq(greater<ll>(), move(cont));
    for (auto it_beg = it; it_beg != cend(participants); ++it_beg)
    {
	auto[balloons, weight] = *it_beg;
	leaders_to_fly_pq.push(weight - balloons + 1);
    }
    participants.erase(it, cend(participants));

    while (my_balloons > 0 && !empty(leaders_to_fly_pq))
    {
	ll leader_to_fly = leaders_to_fly_pq.top();
	if (my_balloons >= leader_to_fly)
	{
	    my_balloons -= leader_to_fly;
	    leaders_to_fly_pq.pop();

	    ll i = lsize(participants) - 1;
	    while (i >= 0 && participants[i].first > my_balloons)
	    {
		leaders_to_fly_pq.push(participants[i].second - participants[i].first + 1);
		participants.pop_back();
		--i;
	    }
	    place = min(lsize(leaders_to_fly_pq) + 1, place);
	}
	else
	{
	    my_balloons = 0;
	}
    }

    cout << place;
}
