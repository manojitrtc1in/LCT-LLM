






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
inline long long id35(long long operand, int index) { return operand &= ~((uint64_t)1 << index); }
inline long long flip_bit(long long operand, int index) { return operand ^= ((uint64_t)1 << index); }
inline long long flip_byte(long long operand, int largest_index) { return operand ^= set_byte(largest_index); }
inline int id36(long long operand) { return operand & (-operand); }
inline bool id40(long long operand) { return operand && !(operand & (operand - 1)); }
inline bool compare(const pair < long long, long long > &pair_one, const pair < long long, long long > &pair_two)
{
    

    if (pair_one.first > pair_two.first)
        return true;
    if (pair_one.first == pair_two.first)
        return pair_one.second < pair_two.second;
    return false;
}

inline long long id17(long long dividend, long long divisor) { return (dividend + divisor - 1) / divisor; }
inline long double logos_b(long long base, long long power) { return log2(power) / log2(base); }
inline long long moduli(long long dividend, long long divisor) { return dividend % divisor >= 0 ? dividend % divisor : dividend % divisor + abs(divisor); }
inline long long id19(long long operand_one, long long operand_two, long long modulo) { return moduli(moduli(operand_one, modulo) + moduli(operand_two, modulo), modulo); }
inline long long id42(long long operand_one, long long operand_two, long long modulo) { return moduli(moduli(operand_one, modulo) - moduli(operand_two, modulo), modulo); }
inline long long id43(long long operand_one, long long operand_two, long long modulo) { return moduli(moduli(operand_one, modulo) * moduli(operand_two, modulo), modulo); }

long long binary_power(long long base, long long power) { long long result = 1; while (power) { if (power & 1) result *= base; base *= base; power >>= 1; } return result; }
long long id0(long long base, long long power, long long modulo) { base = moduli(base, modulo); long long result = 1; while (power) { if (power & 1) result = id43(result, base, modulo); base = id43(base, base, modulo); power >>= 1; } return result; }
long long id10(long long base, long long modulo) { return id0(base, modulo - 2, modulo); }
long long id45(long long operand_one, long long operand_two, long long modulo) { return id43(operand_one, id10(operand_two, modulo), modulo); }

int id26 = (int)1E6;
vector < long long > id33(id26 + 3);
vector < long long > id13(id26 + 3);
vector < long long > id20(id26 + 3);
vector < long long > id47(id26 + 3);
void precalculate()
{
    id47[0] = 1;
    for(int index = 1; index <= id26; index++)
        id47[index] = id43(id47[index - 1], 31, MOD);

    id20[0] = id20[1] = 1;
    for (int index = 2; index <= id26; index++)
        id20[index] = id43(id20[moduli(MOD, index)], moduli((MOD - MOD / index), MOD), MOD);

    id33[0] = id33[1] = 1;
    for(int index = 2; index <= id26; index++)
        id33[index] = id43(id33[index - 1], index, MOD);

    id13[0] = id13[1] = 1;
    for(int index = 2; index <= id26; index++)
        id13[index] = id43(id13[index - 1], id20[index], MOD);
}
bool id27(u64 n, u64 a, u64 d, int s) {
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
        if (id27(n, a, d, r))
            return false;
    }
    return true;
}

vector< int > root;
void seive(int limit)
{       
    vector<char> id8(limit, true);
    id8[0] = id8[1] = false;
    int largest_index = (int)sqrt(limit);
    for (int index = 2; index <= largest_index; index++)
        if (id8[index])
            for (int signed_index = index * index; signed_index <= limit; signed_index += index)
                id8[signed_index] = false;

    for (int index = 2; index <= limit; index++)
        if (id8[index])
            root.emplace_back(index);
}
vector < long long > segment_root;
void id5(long long lowest_bound, long long largest_bound)
{
    vector < char > id2(largest_bound - lowest_bound + 1, true);
    if(!lowest_bound)
        id2[0] = id2[1] = false;
    elif(lowest_bound == 1)
        id2[0] = false;
    long long largest_index = (long long)sqrtl(largest_bound);
    for (long long index = 0; index < largest_index; index++)
        for (long long signed_index = max((long long)root[index] * (long long)root[index], (lowest_bound + (long long)root[index] - 1) / (long long)root[index] * (long long)root[index]); signed_index <= largest_bound; signed_index += (long long)root[index])
            id2[signed_index - lowest_bound] = false;

    for(int index = 0; index < size(id2); index++)
        if(id2[index])
            segment_root.emplace_back(lowest_bound + index);
}
vector < long long > root_set;
void id3(long long operand)
{
    if(operand <= 9999991 ? find(root.begin(), root.end(), operand) != root.end() : is_root(operand))
        root_set.push_back(operand);
    else
    {
        int index = 0;
        while (index < size(root) && operand > 1) 
        {
            while (!(operand % (long long)root[index])) 
            { 
                root_set.push_back((long long)root[index]); 
                operand /= (long long)root[index]; 
            }
            index++;
        }
        if (operand > 1) 
            root_set.push_back(operand);
    }
}
long long id30(long long operand_one, long long operand_two, long long modulo) {
    long long result = 0;
    while (operand_two) 
    {
        if (operand_two & 1)
            result = id19(result, operand_one, modulo);
        operand_one = id19(operand_one, operand_one, modulo);
        operand_two >>= 1;
    }
    return result;
}
long long f(long long x, long long c, long long mod) {
    return (id30(x, x, mod) + c) % mod;
}
long long id15(long long n, long long x0=2, long long c=1) {
    long long x = x0;
    long long g = 1;
    long long q = 1;
    long long xs, y;

    int m = 128;
    int l = 1;
    while (g == 1) {
        y = x;
        for (int i = 1; i < l; i++)
            x = f(x, c, n);
        int k = 0;
        while (k < l && g == 1) {
            xs = x;
            for (int i = 0; i < m && i < l - k; i++) {
                x = f(x, c, n);
                q = id30(q, abs(y - x), n);
            }
            g = gcd(q, n);
            k += m;
        }
        l *= 2;
    }
    if (g == n) {
        do {
            xs = f(xs, c, n);
            g = gcd(abs(xs - y), n);
        } while (g == 1);
    }
    return g;
}

vector < long long > id4(string str, long long base, long long modulo)
{
    vector < long long > hashed_value(size(str) + 3);
    

    char character = 'a';
    hashed_value[0] = id43(str[0] - character + 1, id47[0], modulo);
    for(int index = 1; index < size(str); index++)
        hashed_value[index] = id19(hashed_value[index - 1], id43(str[index] - character + 1, id47[index], modulo), modulo);
    return hashed_value;
}



int row_size = (int)1E3, column_size = (int)1E3;
vector < vector < int > > id14(row_size + 3, vector < int > (column_size + 3));
bool valid_path(int id41, int id1)
{
    

    return (id41 >= 1 && id41 <= row_size && id1 >= 1 && id1 <= column_size );
}
int id29(int start_row, int start_column, int start_color, int fill_color)
{
    if(!valid_path(start_row, start_column))
        return 0;

    if(id14[start_row][start_column] != start_color)
        return 0;

    int connected_component = 1;

    id14[start_row][start_column] = fill_color;

    for(int index = 0; index < 4; index++)
        connected_component += id29(start_row + KING[index][0], start_column + KING[index][1], start_color, fill_color);
    
    return connected_component;
}



int node_size = (int)1E6;
vector < vector < pair < int, int > > > weighted_graph(node_size + 3);
vector < long long > id39(node_size + 3, INF);
void id28(int start_node)
{
    id39[start_node] = 0;
    deque < int > id44;
    id44.push_back(start_node);
    while(!id44.empty())
    {
        int parent_node = id44.front();
        id44.pop_front();
        for(int index = 0; index < size(weighted_graph[parent_node]); index++)
        {
            int weight = weighted_graph[parent_node][index].first, child_node = weighted_graph[parent_node][index].second;
            if(id39[parent_node] + weight < id39[child_node])
            {
                id39[child_node] = id39[parent_node] + weight;
                if(weight)
                    id44.push_back(child_node);
                else
                    id44.push_front(child_node);
            }
        }
    }
}

void id37(int start_node)
{
    id39[start_node] = 0;
    priority_queue < pair < long long, int >, vector < pair < long long, int > >, greater < pair < long long, int > > > id7;
    id7.push( { 0, start_node } );
    while(!id7.empty())
    {
        int id25 = id7.top().first, parent_node = id7.top().second;
        id7.pop();
        if(id25 > id39[parent_node])
            continue;
        for(int index = 0; index < size(weighted_graph[parent_node]); index++)
        {
            int child_node = weighted_graph[parent_node][index].first, id46 = weighted_graph[parent_node][index].second;
            if(id39[parent_node] + id46 < id39[child_node])
            {
                id39[child_node] = id39[parent_node] + id46;
                id7.push( { id39[child_node], child_node } );
            }
        }
    }
}

vector < int > parent(node_size + 3, -1);
bool id34(int start_node)
{
    id39[start_node] = 0;
    int id16;
    for(int iteration = 1; iteration <= node_size; iteration++)
    {
        

        for(int parent_node = 1; parent_node <= node_size; parent_node++)
        {
            id16 = -1;
            for(int index = 0; index < size(weighted_graph[parent_node]); index++)
            {
                int id21 = weighted_graph[parent_node][index].first, child_node = weighted_graph[parent_node][index].second;
                if(id39[parent_node] + id21 < id39[child_node])
                {
                    

                    id39[child_node] = max(-INF, id39[parent_node] + id21);
                    id16 = child_node;
                    parent[child_node] = parent_node;
                }
            }
        }
        if(id16 == -1)
            break;
    }
    if(id16 == -1)
        return false;
    for(int node = 1; node <= node_size; node++)
        id16 = parent[id16];
    vector < int > id9;
    for(int node = id16; ;node = parent[node])
    {
        id9.push_back(node);
        if(node == id16 && size(id9) > 1)
            break;
    }
    reverse(id9.begin(), id9.end());
    return true;
}
vector < bool > is_checked(node_size + 3);
bool id12(int start_node)
{
    id39[start_node] = 0;
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
            int child_node = weighted_graph[parent_node][index].first, id46 = weighted_graph[parent_node][index].second;
            if(id39[parent_node] + id46 < id39[child_node])
            {
                id39[child_node] = id39[parent_node] + id46;
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
vector < vector < long long > > id18(4 * (int)1E2 + 3, vector < long long > (4 * (int)1E2 + 3, INF));
void id23(int node_size)
{
    for(int id32 = 0; id32 <= node_size; id32++)
        for(int node_one = 1; node_one <= node_size; node_one++)
            for(int node_two = 1; node_two <= node_size; node_two++)
                if(id18[node_one][id32] != INF && id18[id32][node_two] != INF)
                {
                    

                    if(id18[id32][id32] < 0)
                        id18[node_one][node_two] = -INF;
                    else
                        id18[node_one][node_two] = min(id18[node_one][node_two], id18[node_one][id32] + id18[id32][node_two]);
                }
}

vector < vector < int > > id31(node_size + 3);
vector < int > in_degree(node_size + 3);
vector < int > id22;
bool id6()
{
    queue < int > id11;
    for(int node = 1; node <= node_size; node++)
        if(!in_degree[node])
            id11.push(node);
    while(!id11.empty())
    {
        int parent_node = id11.front();
        id22.push_back(parent_node);
        id11.pop();
        for(int index = 0; index < size(id31[parent_node]); index++)
        {
            int child_node = id31[parent_node][index];
            in_degree[child_node]--;
            if(!in_degree[child_node])
                id11.push(child_node);
        }
    }
    if(size(id22) != node_size)
        return false;
    reverse(id22.begin(), id22.end());
    return true;
}
void id24(int start_node)
{
    is_checked[start_node] = true;
    for(int parent_node = 0; parent_node < size(id31[start_node]); parent_node++)
    {
        int child_node = id31[start_node][parent_node];
        if(!is_checked[child_node])
            id24(child_node);
    }
    id22.push_back(start_node);
}
bool id38()
{
    for(int node = 1; node <= node_size; node++)
        if(!is_checked[node])
            id24(node);
    if(size(id22) != node_size)
        return false;
    reverse(id22.begin(), id22.end());
    return true;
}

void solve()
{
    cout << fixed << setprecision(20);
    

    


    int q;
    cin>>q;
    map<char,long long>ms,mt;
    ms['a']++;
    mt['a']++;
    while(q--){
        int d,k;
        cin>>d>>k;
        string x;
        cin>>x;
        if(d==1){
            for(int i=0;i<size(x);i++)
                ms[x[i]]+=k;
        }
        else{
            for(int i=0;i<size(x);i++)
                mt[x[i]]+=k;
        }
        auto it=ms.end(),it1=mt.end();
        it--;
        it1--;
        if(it1->first!='a')
            cout<<"YES";
        else{
            if(it->first=='a'){
                if(ms['a']<mt['a'])
                    cout<<"YES";
                else
                    cout<<"NO";
            }
            else
                cout<<"NO";
        }
        cout<<endl;
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
    cin >> t;
    for(int index = 1; index <=t; index++){
        

        solve();
    }

    cerr << "Time taken: " << (clock() - start) / CLOCKS_PER_SEC<< " Seconds" << endl;

    return 0;
}

