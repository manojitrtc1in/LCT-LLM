

#include "bits/stdc++.h"

#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace std;
using namespace __gnu_pbds;

using u64 = uint64_t;
using u128 = __uint128_t;

typedef tree < long long, null_type, less < long long >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
typedef tree < long long, null_type, less_equal < long long >, rb_tree_tag, tree_order_statistics_node_update > ordered_multiset;
typedef tree < long long, null_type, greater < long long >, rb_tree_tag, tree_order_statistics_node_update > reversed_ordered_set;
typedef tree < long long, null_type, greater_equal < long long >, rb_tree_tag, tree_order_statistics_node_update > reversed_ordered_multiset;

#define endl '\n'
#define elif else if
#define size(container) (int)container.size()
#define case(index) cout << "Case #" << index << ": "
#define set_generate(index, largest_index) for(int index = 0; index < ((uint32_t)1 << largest_index); index++)

const long long MOD = (int)1E9+7;

const long double PI = acosl(-1.0);
const long long INF = (long long)1E18;

const int KING[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
const int KNIGHT[8][2] = { {1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1} };
const int BISHOP[28][2] = { {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {-1, -1}, {-2, -2}, {-3, -3}, {-4, -4}, {-5, -5}, {-6, -6}, {-7, -7}, {1, -1}, {2, -2}, {3, -3}, {4, -4}, {5, -5}, {6, -6}, {7, -7}, {-1, 1}, {-2, 2}, {-3, 3}, {-4, 4}, {-5, 5}, {-6, 6}, {-7, 7} };
const int ROCK[28][2] = { {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {-1, 0}, {-2, 0}, {-3, 0}, {-4, 0}, {-5, 0}, {-6, 0}, {-7, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}, {0, -1}, {0, -2}, {0, -3}, {0, -4}, {0, -5}, {0, -6}, {0, -7} };
const int MIRO[10] = { 0, 1, 5, -1, -1, 2, -1, -1, 8, -1 };









inline bool is_set(long long operand, int index) { return operand & ((uint64_t)1 << index); }
inline long long set_bit(long long operand, int index) { return operand |= ((uint64_t)1 << index); }
inline long long set_byte(int largest_index) { return ((uint64_t)1 << largest_index) - 1; }
inline long long dont_set_bit(long long operand, int index) { return operand &= ~((uint64_t)1 << index); }
inline long long flip_bit(long long operand, int index) { return operand ^= ((uint64_t)1 << index); }
inline long long flip_byte(long long operand, int largest_index) { return operand ^= set_byte(largest_index); }
inline int least_significant_set_bit(long long operand) { return operand & (-operand); }
inline bool is_power_of2(long long operand) { return operand && !(operand & (operand - 1)); }
inline bool compare(const pair < long long, long long > &pair_one, const pair < long long, long long > &pair_two)
{
    

    if (pair_one.first > pair_two.first)
        return true;
    if (pair_one.first == pair_two.first)
        return pair_one.second < pair_two.second;
    return false;
}

inline long long ceil_division(long long dividend, long long divisor) { return (dividend + divisor - 1) / divisor; }
inline long double logos_b(long long base, long long power) { return log2(power) / log2(base); }
inline long long moduli(long long dividend, long long divisor) { return dividend % divisor >= 0 ? dividend % divisor : dividend % divisor + abs(divisor); }
inline long long moduli_increment(long long operand_one, long long operand_two, long long modulo) { return moduli(moduli(operand_one, modulo) + moduli(operand_two, modulo), modulo); }
inline long long moduli_decrement(long long operand_one, long long operand_two, long long modulo) { return moduli(moduli(operand_one, modulo) - moduli(operand_two, modulo), modulo); }
inline long long moduli_product(long long operand_one, long long operand_two, long long modulo) { return moduli(moduli(operand_one, modulo) * moduli(operand_two, modulo), modulo); }

long long binary_power(long long base, long long power) { long long result = 1; while (power) { if (power & 1) result *= base; base *= base; power >>= 1; } return result; }
long long moduli_power(long long base, long long power, long long modulo) { base = moduli(base, modulo); long long result = 1; while (power) { if (power & 1) result = moduli_product(result, base, modulo); base = moduli_product(base, base, modulo); power >>= 1; } return result; }
long long inverse_moduli_power(long long base, long long modulo) { return moduli_power(base, modulo - 2, modulo); }
long long moduli_division(long long operand_one, long long operand_two, long long modulo) { return moduli_product(operand_one, inverse_moduli_power(operand_two, modulo), modulo); }

int precalculated_size = (int)1E6;
vector < long long > precalculated_factorial(precalculated_size + 3);
vector < long long > precalculated_inverse_factorial(precalculated_size + 3);
vector < long long > precalculated_inverse_moduli_power(precalculated_size + 3);
vector < long long > precalculated_moduli_power(precalculated_size + 3);
void precalculate()
{
    precalculated_moduli_power[0] = 1;
    for(int index = 1; index <= precalculated_size; index++)
        precalculated_moduli_power[index] = moduli_product(precalculated_moduli_power[index - 1], 31, MOD);

    precalculated_inverse_moduli_power[0] = precalculated_inverse_moduli_power[1] = 1;
    for (int index = 2; index <= precalculated_size; index++)
        precalculated_inverse_moduli_power[index] = moduli_product(precalculated_inverse_moduli_power[moduli(MOD, index)], moduli((MOD - MOD / index), MOD), MOD);

    precalculated_factorial[0] = precalculated_factorial[1] = 1;
    for(int index = 2; index <= precalculated_size; index++)
        precalculated_factorial[index] = moduli_product(precalculated_factorial[index - 1], index, MOD);

    precalculated_inverse_factorial[0] = precalculated_inverse_factorial[1] = 1;
    for(int index = 2; index <= precalculated_size; index++)
        precalculated_inverse_factorial[index] = moduli_product(precalculated_inverse_factorial[index - 1], precalculated_inverse_moduli_power[index], MOD);
}
bool isnt_root(u64 n, u64 a, u64 d, int s) {
    u64 x = moduli_power(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};
bool is_root(u64 n)
{
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (isnt_root(n, a, d, r))
            return false;
    }
    return true;
}
vector < int > lowest_root((int)1E7 + 3);
vector< int > seive(int limit)
{
    lowest_root[1] = 1;
    vector< int > root;
    if (limit <= 1)
        return root;

    for (int index = 2; index <= limit; index++)
        lowest_root[index] = index;
    for (int index = 2; index <= limit; index += 2)
        lowest_root[index] = 2;

    vector<char> is_root(limit, true);
    is_root[0] = is_root[1] = false;
    int largest_index = (int)sqrt(limit);
    for (int index = 3; index <= largest_index; index += 2)
        if (is_root[index])
            for (int signed_index = index * index; signed_index <= limit; signed_index += index + index)
            {
                if (lowest_root[signed_index] == signed_index)
                    lowest_root[signed_index] = index;
                is_root[signed_index] = false;
            }

    root.emplace_back(2);
    for (int index = 3; index <= limit; index += 2)
        if (is_root[index])
            root.emplace_back(index);

    return root;
}
vector < long long > segmented_seive(long long lowest_bound, long long largest_bound)
{
    vector < long long > segmented_raw;

    if (largest_bound <= 1)
        return segmented_raw;

    vector < char > is_prime(largest_bound - lowest_bound + 1, true);
    if (!lowest_bound)
        is_prime[0] = is_prime[1] = false;
    elif (lowest_bound == 1)
        is_prime[0] = false;
    vector < int > raw = seive((int)sqrt(largest_bound));
    for (long long index : raw)
        for (long long signed_index = max(index * index, (lowest_bound + index - 1) / index * index); signed_index <= largest_bound; signed_index += index)
            is_prime[signed_index - lowest_bound] = false;

    for(int index = 0; index < size(is_prime); index++)
        if (is_prime[index])
            segmented_raw.emplace_back(lowest_bound + index);

    return segmented_raw;
}
vector < int > to_seive_root(long long operand)
{
    vector < int > root;
    if(operand <= 9999991)
        while (operand)
        {
            root.push_back(lowest_root[operand]);
            operand /= lowest_root[operand];
        }
    return root;
}
vector < long long > polynomial_rolling_hash(string str, long long base, long long modulo)
{
    vector < long long > hashed_value(size(str) + 3);
    

    char character = 'a';
    hashed_value[0] = moduli_product(str[0] - character + 1, precalculated_moduli_power[0], modulo);
    for(int index = 1; index < size(str); index++)
        hashed_value[index] = moduli_increment(hashed_value[index - 1], moduli_product(str[index] - character + 1, precalculated_moduli_power[index], modulo), modulo);
    return hashed_value;
}



int row_size = (int)1E3, column_size = (int)1E3;
vector < vector < int > > _2dimension_graph(row_size + 3, vector < int > (column_size + 3));
bool valid_path(int new_index_one, int new_index_two)
{
    

    return (new_index_one >= 1 && new_index_one <= row_size && new_index_two >= 1 && new_index_two <= column_size );
}
int flood_fill(int start_row, int start_column, int start_color, int fill_color)
{
    if(!valid_path(start_row, start_column))
        return 0;

    if(_2dimension_graph[start_row][start_column] != start_color)
        return 0;

    int connected_component = 1;

    _2dimension_graph[start_row][start_column] = fill_color;

    for(int index = 0; index < 4; index++)
        connected_component += flood_fill(start_row + KING[index][0], start_column + KING[index][1], start_color, fill_color);
    
    return connected_component;
}



int node_size = (int)1E6;
vector < vector < pair < int, int > > > weighted_graph(node_size + 3);
vector < long long > weighted_path_distance(node_size + 3, INF);
void _0_1bredth_first_search(int start_node)
{
    weighted_path_distance[start_node] = 0;
    deque < int > _0_1queue;
    _0_1queue.push_back(start_node);
    while(!_0_1queue.empty())
    {
        int parent_node = _0_1queue.front();
        _0_1queue.pop_front();
        for(int index = 0; index < size(weighted_graph[parent_node]); index++)
        {
            int weight = weighted_graph[parent_node][index].first, child_node = weighted_graph[parent_node][index].second;
            if(weighted_path_distance[parent_node] + weight < weighted_path_distance[child_node])
            {
                weighted_path_distance[child_node] = weighted_path_distance[parent_node] + weight;
                if(weight)
                    _0_1queue.push_back(child_node);
                else
                    _0_1queue.push_front(child_node);
            }
        }
    }
}

void single_source_shortest_path(int start_node)
{
    weighted_path_distance[start_node] = 0;
    priority_queue < pair < long long, int >, vector < pair < long long, int > >, greater < pair < long long, int > > > weighted_node_queue;
    weighted_node_queue.push( { 0, start_node } );
    while(!weighted_node_queue.empty())
    {
        int parent_node_distance = weighted_node_queue.top().first, parent_node = weighted_node_queue.top().second;
        weighted_node_queue.pop();
        if(parent_node_distance > weighted_path_distance[parent_node])
            continue;
        for(int index = 0; index < size(weighted_graph[parent_node]); index++)
        {
            int child_node = weighted_graph[parent_node][index].first, child_node_distance = weighted_graph[parent_node][index].second;
            if(weighted_path_distance[parent_node] + child_node_distance < weighted_path_distance[child_node])
            {
                weighted_path_distance[child_node] = weighted_path_distance[parent_node] + child_node_distance;
                weighted_node_queue.push( { weighted_path_distance[child_node], child_node } );
            }
        }
    }
}

vector < int > parent(node_size + 3, -1);
bool single_source_negetive_cyclic_shortest_path(int start_node)
{
    weighted_path_distance[start_node] = 0;
    int is_negetive_cyclic_node;
    for(int iteration = 1; iteration <= node_size; iteration++)
    {
        

        for(int parent_node = 1; parent_node <= node_size; parent_node++)
        {
            is_negetive_cyclic_node = -1;
            for(int index = 0; index < size(weighted_graph[parent_node]); index++)
            {
                int child_node_weight = weighted_graph[parent_node][index].first, child_node = weighted_graph[parent_node][index].second;
                if(weighted_path_distance[parent_node] + child_node_weight < weighted_path_distance[child_node])
                {
                    

                    weighted_path_distance[child_node] = max(-INF, weighted_path_distance[parent_node] + child_node_weight);
                    is_negetive_cyclic_node = child_node;
                    parent[child_node] = parent_node;
                }
            }
        }
        if(is_negetive_cyclic_node == -1)
            break;
    }
    if(is_negetive_cyclic_node == -1)
        return false;
    for(int node = 1; node <= node_size; node++)
        is_negetive_cyclic_node = parent[is_negetive_cyclic_node];
    vector < int > negetive_cyclic_path;
    for(int node = is_negetive_cyclic_node; ;node = parent[node])
    {
        negetive_cyclic_path.push_back(node);
        if(node == is_negetive_cyclic_node && size(negetive_cyclic_path) > 1)
            break;
    }
    reverse(negetive_cyclic_path.begin(), negetive_cyclic_path.end());
    return true;
}
vector < bool > is_checked(node_size + 3);
bool single_source_negetive_cyclic_shortest_path_faster(int start_node)
{
    weighted_path_distance[start_node] = 0;
    queue < int > node_queue;
    node_queue.push(start_node);
    is_checked[start_node] = true;
    vector < int > count_checked(node_size + 3);
    while(!node_queue.empty())
    {
        int parent_node = node_queue.front();
        node_queue.pop();
        is_checked[parent_node] = false;
        for(int index = 0; index < size(weighted_graph[parent_node]); index++)
        {
            int child_node = weighted_graph[parent_node][index].first, child_node_distance = weighted_graph[parent_node][index].second;
            if(weighted_path_distance[parent_node] + child_node_distance < weighted_path_distance[child_node])
            {
                weighted_path_distance[child_node] = weighted_path_distance[parent_node] + child_node_distance;
                if(!is_checked[child_node])
                {
                    node_queue.push(child_node);
                    is_checked[child_node] = true;
                    count_checked[child_node]++;
                    if(count_checked[child_node] > node_size)
                        return false;
                }
            }
        }
    }
    return true;
}
vector < vector < long long > > paired_path_distance(4 * (int)1E2 + 3, vector < long long > (4 * (int)1E2 + 3, INF));
void paired_source_shortest_path(int node_size)
{
    for(int intermediate_node = 0; intermediate_node <= node_size; intermediate_node++)
        for(int node_one = 1; node_one <= node_size; node_one++)
            for(int node_two = 1; node_two <= node_size; node_two++)
                if(paired_path_distance[node_one][intermediate_node] != INF && paired_path_distance[intermediate_node][node_two] != INF)
                {
                    

                    if(paired_path_distance[intermediate_node][intermediate_node] < 0)
                        paired_path_distance[node_one][node_two] = -INF;
                    else
                        paired_path_distance[node_one][node_two] = min(paired_path_distance[node_one][node_two], paired_path_distance[node_one][intermediate_node] + paired_path_distance[intermediate_node][node_two]);
                }
}

vector < vector < int > > directed_acyclic_graph(node_size + 3);
vector < int > in_degree(node_size + 3);
vector < int > topological_order;
bool bredth_first_search_topological_sort()
{
    queue < int > topological_queue;
    for(int node = 1; node <= node_size; node++)
        if(!in_degree[node])
            topological_queue.push(node);
    while(!topological_queue.empty())
    {
        int parent_node = topological_queue.front();
        topological_order.push_back(parent_node);
        topological_queue.pop();
        for(int index = 0; index < size(directed_acyclic_graph[parent_node]); index++)
        {
            int child_node = directed_acyclic_graph[parent_node][index];
            in_degree[child_node]--;
            if(!in_degree[child_node])
                topological_queue.push(child_node);
        }
    }
    if(size(topological_order) != node_size)
        return false;
    reverse(topological_order.begin(), topological_order.end());
    return true;
}
void defth_first_search(int start_node)
{
    is_checked[start_node] = true;
    for(int parent_node = 0; parent_node < size(directed_acyclic_graph[start_node]); parent_node++)
    {
        int child_node = directed_acyclic_graph[start_node][parent_node];
        if(!is_checked[child_node])
            defth_first_search(child_node);
    }
    topological_order.push_back(start_node);
}
bool depth_first_search_topological_sort()
{
    for(int node = 1; node <= node_size; node++)
        if(!is_checked[node])
            defth_first_search(node);
    if(size(topological_order) != node_size)
        return false;
    reverse(topological_order.begin(), topological_order.end());
    return true;
}

void solve()
{
    cout << fixed << setprecision(20);
    

    


    int n, q;
    cin >> n >> q;
    int i, a, t[q];
    list<int>l;
    for(i = 0; i < n; ++i)
    {
        cin >> a;
        l.push_back(a);
    }
    for(i = 0; i < q; ++i)
        cin >> t[i];
    list<int>::iterator inc;
    i = 0;
    while(q--)
    {
        inc = find(l.begin(), l.end(), t[i]);
        cout << distance(l.begin(), inc) + 1 << endl;
        l.erase(inc);
        l.push_front(t[i]);
        ++i;
    }
    cout<<endl;
    return;
}
int main()
{
    float start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("error.txt", "w", stderr);
        freopen("output.txt", "w", stdout);
    #endif
    
    

    int t = 1;
    

    for(int index = 1; index <=t; index++){
        

        solve();
    }

    cerr << "Time taken: " << (clock() - start) / CLOCKS_PER_SEC<< " Seconds" << endl;

    return 0;
}

