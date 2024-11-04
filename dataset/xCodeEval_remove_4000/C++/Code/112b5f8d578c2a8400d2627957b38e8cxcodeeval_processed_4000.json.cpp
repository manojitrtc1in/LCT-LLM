






using namespace std;
using namespace __gnu_pbds;

using u64 = uint64_t;
using u128 = __uint128_t;

typedef tree < long long, null_type, less < long long >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
typedef tree < long long, null_type, less_equal < long long >, rb_tree_tag, tree_order_statistics_node_update > ordered_multiset;
typedef tree < long long, null_type, greater < long long >, rb_tree_tag, tree_order_statistics_node_update > reversed_ordered_set;
typedef tree < long long, null_type, greater_equal < long long >, rb_tree_tag, tree_order_statistics_node_update > reversed_ordered_multiset;







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
inline long long id31(long long operand, int index) { return operand &= ~((uint64_t)1 << index); }
inline long long flip_bit(long long operand, int index) { return operand ^= ((uint64_t)1 << index); }
inline long long flip_byte(long long operand, int largest_index) { return operand ^= set_byte(largest_index); }
inline int id34(long long operand) { return operand & (-operand); }
inline bool id39(long long operand) { return operand && !(operand & (operand - 1)); }
inline bool compare(const pair < long long, long long > &pair_one, const pair < long long, long long > &pair_two)
{
    

    if (pair_one.first > pair_two.first)
        return true;
    if (pair_one.first == pair_two.first)
        return pair_one.second < pair_two.second;
    return false;
}

inline long long id13(long long dividend, long long divisor) { return (dividend + divisor - 1) / divisor; }
inline long double logos_b(long long base, long long power) { return log2(power) / log2(base); }
inline long long moduli(long long dividend, long long divisor) { return dividend % divisor >= 0 ? dividend % divisor : dividend % divisor + abs(divisor); }
inline long long id17(long long operand_one, long long operand_two, long long modulo) { return moduli(moduli(operand_one, modulo) + moduli(operand_two, modulo), modulo); }
inline long long id41(long long operand_one, long long operand_two, long long modulo) { return moduli(moduli(operand_one, modulo) - moduli(operand_two, modulo), modulo); }
inline long long id32(long long operand_one, long long operand_two, long long modulo) { return moduli(moduli(operand_one, modulo) * moduli(operand_two, modulo), modulo); }

long long binary_power(long long base, long long power) { long long result = 1; while (power) { if (power & 1) result *= base; base *= base; power >>= 1; } return result; }
long long id0(long long base, long long power, long long modulo) { base = moduli(base, modulo); long long result = 1; while (power) { if (power & 1) result = id32(result, base, modulo); base = id32(base, base, modulo); power >>= 1; } return result; }
long long id7(long long base, long long modulo) { return id0(base, modulo - 2, modulo); }
long long id36(long long operand_one, long long operand_two, long long modulo) { return id32(operand_one, id7(operand_two, modulo), modulo); }

int id23 = (int)1E6;
vector < long long > id29(id23 + 3);
vector < long long > id10(id23 + 3);
vector < long long > id16(id23 + 3);
vector < long long > id44(id23 + 3);
void precalculate()
{
    id44[0] = 1;
    for(int index = 1; index <= id23; index++)
        id44[index] = id32(id44[index - 1], 31, MOD);

    id16[0] = id16[1] = 1;
    for (int index = 2; index <= id23; index++)
        id16[index] = id32(id16[moduli(MOD, index)], moduli((MOD - MOD / index), MOD), MOD);

    id29[0] = id29[1] = 1;
    for(int index = 2; index <= id23; index++)
        id29[index] = id32(id29[index - 1], index, MOD);

    id10[0] = id10[1] = 1;
    for(int index = 2; index <= id23; index++)
        id10[index] = id32(id10[index - 1], id16[index], MOD);
}
bool id24(u64 n, u64 a, u64 d, int s) {
    u64 x = id0(a, d, n);
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
        if (id24(n, a, d, r))
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
vector < long long > id3(long long lowest_bound, long long largest_bound)
{
    vector < long long > id33;

    if (largest_bound <= 1)
        return id33;

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
            id33.emplace_back(lowest_bound + index);

    return id33;
}
vector < int > id15(long long operand)
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
vector < long long > id2(string str, long long base, long long modulo)
{
    vector < long long > hashed_value(size(str) + 3);
    

    char character = 'a';
    hashed_value[0] = id32(str[0] - character + 1, id44[0], modulo);
    for(int index = 1; index < size(str); index++)
        hashed_value[index] = id17(hashed_value[index - 1], id32(str[index] - character + 1, id44[index], modulo), modulo);
    return hashed_value;
}



int row_size = (int)1E3, column_size = (int)1E3;
vector < vector < int > > id11(row_size + 3, vector < int > (column_size + 3));
bool valid_path(int id40, int id1)
{
    

    return (id40 >= 1 && id40 <= row_size && id1 >= 1 && id1 <= column_size );
}
int id26(int start_row, int start_column, int start_color, int fill_color)
{
    if(!valid_path(start_row, start_column))
        return 0;

    if(id11[start_row][start_column] != start_color)
        return 0;

    int connected_component = 1;

    id11[start_row][start_column] = fill_color;

    for(int index = 0; index < 4; index++)
        connected_component += id26(start_row + KING[index][0], start_column + KING[index][1], start_color, fill_color);
    
    return connected_component;
}



int node_size = (int)1E6;
vector < vector < pair < int, int > > > weighted_graph(node_size + 3);
vector < long long > id38(node_size + 3, INF);
void id25(int start_node)
{
    id38[start_node] = 0;
    deque < int > id42;
    id42.push_back(start_node);
    while(!id42.empty())
    {
        int parent_node = id42.front();
        id42.pop_front();
        for(int index = 0; index < size(weighted_graph[parent_node]); index++)
        {
            int weight = weighted_graph[parent_node][index].first, child_node = weighted_graph[parent_node][index].second;
            if(id38[parent_node] + weight < id38[child_node])
            {
                id38[child_node] = id38[parent_node] + weight;
                if(weight)
                    id42.push_back(child_node);
                else
                    id42.push_front(child_node);
            }
        }
    }
}

void id35(int start_node)
{
    id38[start_node] = 0;
    priority_queue < pair < long long, int >, vector < pair < long long, int > >, greater < pair < long long, int > > > id5;
    id5.push( { 0, start_node } );
    while(!id5.empty())
    {
        int id22 = id5.top().first, parent_node = id5.top().second;
        id5.pop();
        if(id22 > id38[parent_node])
            continue;
        for(int index = 0; index < size(weighted_graph[parent_node]); index++)
        {
            int child_node = weighted_graph[parent_node][index].first, id43 = weighted_graph[parent_node][index].second;
            if(id38[parent_node] + id43 < id38[child_node])
            {
                id38[child_node] = id38[parent_node] + id43;
                id5.push( { id38[child_node], child_node } );
            }
        }
    }
}

vector < int > parent(node_size + 3, -1);
bool id30(int start_node)
{
    id38[start_node] = 0;
    int id12;
    for(int iteration = 1; iteration <= node_size; iteration++)
    {
        

        for(int parent_node = 1; parent_node <= node_size; parent_node++)
        {
            id12 = -1;
            for(int index = 0; index < size(weighted_graph[parent_node]); index++)
            {
                int id18 = weighted_graph[parent_node][index].first, child_node = weighted_graph[parent_node][index].second;
                if(id38[parent_node] + id18 < id38[child_node])
                {
                    

                    id38[child_node] = max(-INF, id38[parent_node] + id18);
                    id12 = child_node;
                    parent[child_node] = parent_node;
                }
            }
        }
        if(id12 == -1)
            break;
    }
    if(id12 == -1)
        return false;
    for(int node = 1; node <= node_size; node++)
        id12 = parent[id12];
    vector < int > id6;
    for(int node = id12; ;node = parent[node])
    {
        id6.push_back(node);
        if(node == id12 && size(id6) > 1)
            break;
    }
    reverse(id6.begin(), id6.end());
    return true;
}
vector < bool > is_checked(node_size + 3);
bool id9(int start_node)
{
    id38[start_node] = 0;
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
            int child_node = weighted_graph[parent_node][index].first, id43 = weighted_graph[parent_node][index].second;
            if(id38[parent_node] + id43 < id38[child_node])
            {
                id38[child_node] = id38[parent_node] + id43;
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
vector < vector < long long > > id14(4 * (int)1E2 + 3, vector < long long > (4 * (int)1E2 + 3, INF));
void id20(int node_size)
{
    for(int id28 = 0; id28 <= node_size; id28++)
        for(int node_one = 1; node_one <= node_size; node_one++)
            for(int node_two = 1; node_two <= node_size; node_two++)
                if(id14[node_one][id28] != INF && id14[id28][node_two] != INF)
                {
                    

                    if(id14[id28][id28] < 0)
                        id14[node_one][node_two] = -INF;
                    else
                        id14[node_one][node_two] = min(id14[node_one][node_two], id14[node_one][id28] + id14[id28][node_two]);
                }
}

vector < vector < int > > id27(node_size + 3);
vector < int > in_degree(node_size + 3);
vector < int > id19;
bool id4()
{
    queue < int > id8;
    for(int node = 1; node <= node_size; node++)
        if(!in_degree[node])
            id8.push(node);
    while(!id8.empty())
    {
        int parent_node = id8.front();
        id19.push_back(parent_node);
        id8.pop();
        for(int index = 0; index < size(id27[parent_node]); index++)
        {
            int child_node = id27[parent_node][index];
            in_degree[child_node]--;
            if(!in_degree[child_node])
                id8.push(child_node);
        }
    }
    if(size(id19) != node_size)
        return false;
    reverse(id19.begin(), id19.end());
    return true;
}
void id21(int start_node)
{
    is_checked[start_node] = true;
    for(int parent_node = 0; parent_node < size(id27[start_node]); parent_node++)
    {
        int child_node = id27[start_node][parent_node];
        if(!is_checked[child_node])
            id21(child_node);
    }
    id19.push_back(start_node);
}
bool id37()
{
    for(int node = 1; node <= node_size; node++)
        if(!is_checked[node])
            id21(node);
    if(size(id19) != node_size)
        return false;
    reverse(id19.begin(), id19.end());
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

    
        freopen("input.txt", "r", stdin);
        freopen("error.txt", "w", stderr);
        freopen("output.txt", "w", stdout);
    
    
    

    int t = 1;
    

    for(int index = 1; index <=t; index++){
        

        solve();
    }

    cerr << "Time taken: " << (clock() - start) / CLOCKS_PER_SEC<< " Seconds" << endl;

    return 0;
}

