#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <chrono>
#include <map>
#include <random>
#include <unordered_map>
#include <unordered_set>
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
#include <array>
#include <sstream>

using ll = long long;

#ifdef _WIN32
#include <intrin.h>
#define is_windows_t true
#else
#define is_windows_t false
#endif

ll buildin_one_count(ll number)
{
#ifdef _WIN32
    return __popcnt(number);
#else
    return __builtin_popcountl(number);
#endif
}

ll bits_count(ll number)
{
    return static_cast<ll>(log2(number)) + 1;
}

template <class Container>
ll lsize(const Container& container)
{
    return static_cast<ll>(std::size(container));
}

using namespace std;

constexpr ll MOD = 1'000'000'000 + 7;
constexpr ll INF = numeric_limits<ll>::max();

namespace range_ns
{
    class xrange
    {
        class Iterator
        {
        public:
            using iterator_category = std::random_access_iterator_tag;
            using value_type = ll;
            using difference_type = ll;
            using pointer = ll;
            using reference = void;

            Iterator(ll i) : m_i(i) {}
            ll operator++ () { return ++m_i; }
            ll operator*() { return m_i; }
            bool operator!=(const Iterator& it) const { return m_i != it.m_i; }
            bool operator==(const Iterator& it) const { return m_i == it.m_i; }
            difference_type operator-(const Iterator& it) const { return m_i - it.m_i; }
        private:
            ll m_i;
        };

        ll m_begin = 0;
        ll m_end;

    public:
        xrange(ll n) : m_end(n) {}
        xrange(ll l, ll r) : m_begin(l), m_end(r) {}
        size_t size() const { return m_end - m_begin; }
        Iterator begin() const { return Iterator(m_begin); }
        Iterator end() const { return Iterator(m_end); }
    };

    template <typename T, typename = void>
    struct has_push_back : std::false_type {};

    template <typename T>
    struct has_push_back<T, std::void_t<decltype(std::declval<T>().push_back(std::declval<T::value_type>()))>> : std::true_type {};

    template <typename T>
    constexpr bool has_push_back_v = has_push_back<T>::value;

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

    template<class T>
    bool lexicographical_compare(const T& s1, const T& s2)
    {
        return std::lexicographical_compare(
            cbegin(s1), cend(s1),
            cbegin(s2), cend(s2));
    }

    template<class Container, class T>
    decltype(auto) find(Container& container, const T& elem)
    {
        return std::find(container.begin(), container.end(), elem);
    }

    template<class Container, class Condition>
    decltype(auto) find_if(Container& container, Condition condition)
    {
        return std::find_if(container.begin(), container.end(), condition);
    }

    template<class Container, class Condition = std::less<typename Container::value_type>>
    decltype(auto) cmax_element(const Container& container, Condition condition = Condition())
    {
        return std::max_element(container.begin(), container.end(), condition);
    }

    template<class Container, class Condition = std::less<typename Container::value_type>>
    decltype(auto) cmin_element(const Container& container, Condition condition = Condition())
    {
        return std::min_element(container.begin(), container.end(), condition);
    }

    template<class Container, class Condition = std::less<typename Container::value_type>>
    decltype(auto) max_element(Container& container, Condition condition = Condition())
    {
        return std::max_element(container.begin(), container.end(), condition);
    }

    template<class Container, class Condition = std::less<typename Container::value_type>>
    decltype(auto) min_element(Container& container, Condition condition = Condition())
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

    template <class Container>
    void add(Container& res, const Container& container) {
        std::copy(container.begin(), container.end(), back_inserter(res));
    }

    template<class ContainerOut, class Container, class Condition>
    ContainerOut copy_if(const Container& container, Condition condition)
    {
        ContainerOut container_result;
        if constexpr (has_push_back_v<ContainerOut>)
        {
            container_result.reserve(size(container));
            std::copy_if(container.begin(), container.end(), back_inserter(container_result), condition);
        }
        else
        {
            std::copy_if(container.begin(), container.end(), inserter(container_result, end(container_result)), condition);
        }
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

    template <class Container>
    Container partial_sum(const Container& i_container)
    {
        Container o_container;
        o_container.reserve(size(i_container));
        std::partial_sum(cbegin(i_container), cend(i_container), std::back_inserter(o_container));
        return o_container;
    }

    template <class Container, class Func>
    vector<ll> partial_sum(const Container& i_container, Func i_func)
    {
        if (empty(i_container))
            return vector<ll>();
        vector<ll> o_container(size(i_container));
        o_container[0] = i_func(i_container[0]);
        for (ll i : xrange(1, size(i_container)))
            o_container[i] = o_container[i - 1] + i_func(i_container[i]);
        return o_container;
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

ll ceil_div(ll n, ll k)
{
    double ans = static_cast<double>(n) / k;
    bool negative = ans < 0;
    ans = ceil(abs(ans));
    ll ll_ans = static_cast<ll>(ans) * (negative ? -1 : 1);
    return ll_ans;
}

using graph = vector<vector<ll>>;
using weight_graph = vector<vector<pair<ll, ll>>>;

class disjoint_set_union
{
public:
    disjoint_set_union(ll n) : m_parent(vector<ll>(n, -1)), m_unions(vector<vector<ll>>(n))
    {
        for (ll i : xrange(n))
        {
            make_set(i);
            m_unions[i].push_back(i);
        }
    }

    void union_sets(ll a, ll b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (lsize(m_unions[a]) < lsize(m_unions[b]))
                swap(a, b);

            auto& unions_a = m_unions[m_parent[a]];
            auto& unions_b = m_unions[m_parent[b]];
            unions_a.insert(end(unions_a), cbegin(unions_b), cend(unions_b));
            vector<ll>().swap(unions_b);

            m_parent[b] = a;
        }
    }

    bool in_different_sets(ll a, ll b)
    {
        return find_set(a) != find_set(b);
    }

    const vector<ll>& get_union() const
    {
        return *find_if(m_unions, [](const auto& vec) { return !empty(vec); });
    }

private:
    void make_set(ll v)
    {
        m_parent[v] = v;
    }

    ll find_set(ll v)
    {
        if (v == m_parent[v])
            return v;
        return m_parent[v] = find_set(m_parent[v]);
    }

private:
    vector<ll> m_parent;
    vector<vector<ll>> m_unions;
};

using weight_edge = tuple<ll, ll, ll>;
using mst_pair = pair<ll, vector<pair<ll, ll>>>;

ll minimum_spanning_tree_kruskal(vector<weight_edge>& weight_edges, ll n)
{
    sort(weight_edges, sort_by_first);
    disjoint_set_union dsu(n);
    ll ans = 0;
    for (auto [weight, i, j] : weight_edges)
    {
        if (dsu.in_different_sets(i, j))
        {
            ans |= weight;
            dsu.union_sets(i, j);
        }
    }

    return ans;
}

ll minimum_spanning_tree_prim(const weight_graph& g)
{
    const ll n = lsize(g);
    ll ans = 0;
    vector<bool> processed(n, false);

    priority_queue<tuple<ll, ll, ll>> pq_edges;
    pq_edges.emplace(0, 0, -1);

    while (!empty(pq_edges))
    {
        auto [weight, vertex, from] = pq_edges.top();
        pq_edges.pop();
        if (processed[vertex])
            continue;
        processed[vertex] = true;
        if (from != -1) {
            ans = ans | (-weight);
        }
        for (auto [weight, to] : g[vertex])
            pq_edges.emplace(-weight, to, vertex);
    }

    return ans;
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
                for (auto [weight, v] : g[s])
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
                    auto [weight, ancestor] = m_pre_processing[i][j - 1];
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

                auto [weight, ancestor] = m_pre_processing[j][previous_up];
                j = ancestor;
                max_weight = max(max_weight, weight);
            }

            

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
        for (auto [weight, to] : g[vertex])
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

    for (ll i : xrange(n))
        if (dfs(i))
            return true;
    return false;
}

graph read_graph(ll n, ll m, bool is_oriented = false)
{
    graph g(n);
    for (ll k : xrange(m))
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
    if (a == 0)
        return 0;

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

template<class T>
int isize(const T& i_cont)
{
    return static_cast<int>(size(i_cont));
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    auto v = read_vector<ll>(n);
    ll m;
    cin >> m;
    auto queries = read_vector<ll>(m);
    map<ll, ll> timeToTubes;
    const ll sum = reduce(v);
    ll currentSum = 0;
    ll maxVal = 0;
    for (ll i = 0; i < n; ++i) {
        currentSum += v[i];
        maxVal = max(maxVal, ceil_div(currentSum, i + 1));
        timeToTubes.emplace(max(maxVal, ceil_div(sum, i + 1)), i + 1); 
    }

    vector<ll> ans;
    for (const auto q : queries) {
        auto it = timeToTubes.upper_bound(q);
        if (it != begin(timeToTubes)) {
            it = prev(it);
        }
        if (it == begin(timeToTubes) && it->first > q) {
            ans.push_back(-1);
        }
        else {
            ans.push_back(it->second);
        }
    }
    for (const auto v : ans) {
        cout << v << "\n";
    }

    return 0;
}