







using namespace __gnu_pbds;

using namespace std;
typedef long long int ll;














ll T;
ll N, M, K;
ll one = 1;
ll modulo = 1000050131;
map<ll, ll> myMap;
vector<bool> Prime(3 * 1e6, true);
map<ll, ll> id3, Opposite;
vector<int> id22(3 * 1e6, 1);

void Sieve()
{
    Prime[1] = false;
    for (ll i = 2; i * i <= Prime.size(); i++)
    {
        if (Prime[i] != true) 

            continue;
        for (ll j = i * i; j < Prime.size(); j += i)
        {
            if (Prime[j] == true)
                id22[j] = j / i;
            Prime[j] = false;
        }
    }
    ll times = 1;
    for (ll i = 2; i < Prime.size(); i++)
    {
        if (Prime[i] == true)
        {
            id3[i] = times;
            Opposite[times] = i;
            times++;
        }
    }
}
vector<ll> id10(ll Num)
{
    vector<ll> id0;
    for (ll i = 1; i * i <= Num; i++)
    {
        if (Num % i == 0)
        {
            id0.push_back(Num / i);
            if (i != Num / i)
                id0.push_back(i);
        }
    }
    return id0;
}



ll mpow(ll a, ll b, ll mod)
{
    if (b < 0)
        return 1;
    a %= mod;
    ll x = 1;
    while (b > 0)
    {
        if (b & 1)
            x = (x * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return x;
}
ll mpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll x = mpow(a, b / 2);
    x = (x * x) % modulo;
    

    if (b % 2)
    {
        x = (x * a) % modulo;
        

    }
    return x;
}



ll buildMax(ll index, ll low, ll high, vector<ll> &A, vector<ll> &segment)
{
    

    if (low == high)
        return segment[index] = A[low];
    ll mid = low + (high - low) / 2;
    ll left = buildMax(2 * index + 1, low, mid, A, segment);       

    ll right = buildMax(2 * index + 2, mid + 1, high, A, segment); 

    segment[index] = max(left, right);
    return segment[index];
}
ll buildMin(ll index, ll low, ll high, vector<ll> &A, vector<ll> &segment)
{
    

    if (low == high)
        return segment[index] = A[low];
    ll mid = low + (high - low) / 2;
    ll left = buildMin(2 * index + 1, low, mid, A, segment);       

    ll right = buildMin(2 * index + 2, mid + 1, high, A, segment); 

    return segment[index] = min(left, right);
}



ll queryMax(ll index, ll low, ll high, ll l, ll r, vector<ll> &segment)
{
    

    if (r < low || high < l)
        return LONG_LONG_MIN;
    

    if (l <= low && high <= r)
        return segment[index];
    

    ll mid = low + (high - low) / 2;
    ll left = queryMax(2 * index + 1, low, mid, l, r, segment);
    ll right = queryMax(2 * index + 2, mid + 1, high, l, r, segment);
    return max(left, right);
}
ll queryMin(ll index, ll low, ll high, ll l, ll r, vector<ll> &segment)
{
    

    if (r < low || high < l)
        return id12;
    

    if (l <= low && high <= r)
        return segment[index];
    

    ll mid = low + (high - low) / 2;
    ll left = queryMin(2 * index + 1, low, mid, l, r, segment);
    ll right = queryMin(2 * index + 2, mid + 1, high, l, r, segment);
    return min(left, right);
}

void Centroid(ll u, ll prev, vector<ll> &centroid, vector<ll> &sz, vector<vector<ll>> &Graph)
{
    ll N = Graph.size() - 1;
    bool id6 = true;
    for (auto v : Graph[u])
    {
        if (v != prev)
        {
            Centroid(v, u, centroid, sz, Graph);
            if (sz[v] > N / 2)
                id6 = false;
            sz[u] += sz[v];
        }
    }
    if (N - sz[u] > N / 2)
        id6 = false;
    if (id6)
        centroid.push_back(u);
}



ll findParent(ll v, vector<ll> &Parent)
{
    if (Parent[v] == v)
        return v; 

    ll ans = findParent(Parent[v], Parent);
    return Parent[v] = ans; 

}
bool Union(ll u, ll v, vector<ll> &Size, vector<ll> &parent, vector<ll> &rank)
{
    u = findParent(u, parent), v = findParent(v, parent);
    if (u == v)
        return true;
    

    if (rank[u] > rank[v])
    {
        parent[v] = u;
        Size[u] += Size[v];
    }
    else if (rank[u] < rank[v])
    {
        parent[u] = v;
        Size[v] += Size[u];
    }
    else
    {
        rank[u]++;
        parent[v] = u;
        Size[u] += Size[v];
    }
    return false;
}





void id15(ll &Min, ll &next_node, vector<ll> &Weights, vector<bool> &id16, priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> &pq)
{
    while (pq.size() != 0)
    {
        auto x = pq.top();
        pq.pop();
        if (id16[x.second] == false)
        {
            Min = x.first;
            next_node = x.second;
            return;
        }
    }
}
void id13(ll u, vector<bool> &id16, vector<ll> &Weights, vector<vector<pair<ll, ll>>> &Graph, ll &result, priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> &pq)
{
    if (id16[u] == true) 

        return;
    id16[u] = true;
    for (auto x : Graph[u])
    {
        ll v, w;
        v = x.first, w = x.second;
        if (id16[v] == false) 

        {
            if (Weights[v] > w)
                pq.push({w, v});
        }
    }
    ll Min = id12, next_node = -1;
    id15(Min, next_node, Weights, id16, pq);
    

    if (Min == id12)
        return;
    result += Min;
    id13(next_node, id16, Weights, Graph, result, pq);
}
ll MST(vector<vector<pair<ll, ll>>> &Graph)
{
    vector<ll> Weights(Graph.size(), id12);
    Weights[0] = 0;
    vector<bool> id16(Graph.size(), false);
    ll result = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (ll i = 0; i < Graph.size(); i++)
        pq.push({Weights[i], i});
    id13(0, id16, Weights, Graph, result, pq);
    return result;
}
ll finding(ll index, vector<bool> &A)
{
    ll temp = 0;
    for (ll i = 0; i < A.size(); i++)
    {
        if (A[i] == false)
            continue;
        temp++;
        if (temp == index)
        {
            A[i] = false;
            return i;
        }
    }
    return -1;
}



vector<ll> Dijkstra(ll u, vector<vector<pair<ll, ll>>> &Graph)
{
    ll N = Graph.size();
    vector<ll> Weight(N, INT_MAX);
    vector<bool> visited(N, false);
    Weight[u] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, u});
    while (!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        ll w = temp.first, u = temp.second;
        if (visited[u] == true)
            continue;
        visited[u] = true;
        

        for (auto temp1 : Graph[u])
        {
            ll v = temp1.first, dis = temp1.second;
            

            if (visited[v] == false && Weight[v] > w + dis)
            {
                Weight[v] = w + dis;
                pq.push({Weight[v], v});
            }
        }
    }
    return Weight;
}






void rangeUpdate(ll index, ll low, ll high, ll l, ll r, ll val, vector<ll> &segmentTree, vector<ll> &lazy)
{
    

    if (r < low || l > high)
        return;
    

    if (l <= low && high <= r)
    {
        segmentTree[index] += (high - low + 1) * val;
        lazy[index] += val; 

        return;
    }
    ll mid = low + (high - low) / 2;
    

    if (low != high && lazy[index] != 0) 

    {
        ll left = 2 * index + 1, right = 2 * index + 2;
        segmentTree[left] += (mid - low + 1) * lazy[index];
        segmentTree[right] += (high - mid - 1 + 1) * lazy[index];
        lazy[left] += lazy[index];
        lazy[right] += lazy[index];
        lazy[index] = 0;
    }
    

    rangeUpdate(2 * index + 1, low, mid, l, r, val, segmentTree, lazy);
    rangeUpdate(2 * index + 2, mid + 1, high, l, r, val, segmentTree, lazy);
    segmentTree[index] = segmentTree[2 * index + 1] + segmentTree[2 * index + 2];
}
ll queryLazy(ll index, ll low, ll high, ll l, ll r, vector<ll> &segmentTree, vector<ll> &lazy)
{
    

    if (r < low || l > high)
        return 0;
    

    if (l <= low && high <= r)
        return segmentTree[index];
    

    ll mid = low + (high - low) / 2;
    if (low != high && lazy[index] != 0) 

    {
        ll left = 2 * index + 1, right = 2 * index + 2;
        segmentTree[left] += (mid - low + 1) * lazy[index];
        segmentTree[right] += (high - mid - 1 + 1) * lazy[index];
        lazy[left] += lazy[index];
        lazy[right] += lazy[index];
        lazy[index] = 0;
    }
    ll left = queryLazy(2 * index + 1, low, mid, l, r, segmentTree, lazy);
    ll right = queryLazy(2 * index + 2, mid + 1, high, l, r, segmentTree, lazy);
    return left + right;
}




void id4(ll index, ll low, ll high, ll node, ll val, vector<ll> &segmentTree)
{
    

    if (node < low || node > high)
        return;
    

    if (low == high)
    {
        segmentTree[index] = val;
        return;
    }
    ll mid = low + (high - low) / 2;
    

    id4(2 * index + 1, low, mid, node, val, segmentTree);
    id4(2 * index + 2, mid + 1, high, node, val, segmentTree);
    segmentTree[index] = __gcd(segmentTree[2 * index + 1], segmentTree[2 * index + 2]);
}
ll id8(ll index, ll low, ll high, ll l, ll r, vector<ll> &segmentTree)
{
    

    if (r < low || l > high)
        return 0;
    

    if (l <= low && high <= r)
        return segmentTree[index];
    

    ll mid = low + (high - low) / 2;
    ll left = id8(2 * index + 1, low, mid, l, r, segmentTree);
    ll right = id8(2 * index + 2, mid + 1, high, l, r, segmentTree);
    return __gcd(left, right);
}




void id7(ll index, ll low, ll high, ll l, ll r, ll val, vector<ll> &segmentTree, vector<ll> &lazy)
{
    

    if (r < low || l > high)
        return;
    

    if (l <= low && high <= r)
    {
        segmentTree[index] = max(segmentTree[index], val);
        lazy[index] = max(lazy[index], val); 

        return;
    }
    ll mid = low + (high - low) / 2;
    

    ll temp = 0;
    if (low != high && lazy[index] != temp) 

    {
        ll left = 2 * index + 1, right = 2 * index + 2;
        segmentTree[left] = max(segmentTree[left], lazy[index]);
        segmentTree[right] = max(segmentTree[right], lazy[index]);
        lazy[left] = max(lazy[left], lazy[index]);
        lazy[right] = max(lazy[right], lazy[index]);
        lazy[index] = temp;
    }
    

    id7(2 * index + 1, low, mid, l, r, val, segmentTree, lazy);
    id7(2 * index + 2, mid + 1, high, l, r, val, segmentTree, lazy);
    segmentTree[index] = max(segmentTree[2 * index + 1], segmentTree[2 * index + 2]);
}
ll id11(ll index, ll low, ll high, ll l, ll r, vector<ll> &segmentTree, vector<ll> &lazy)
{
    ll temp = 0;
    

    if (r < low || l > high)
        return LONG_LONG_MIN;
    

    if (l <= low && high <= r)
        return segmentTree[index];
    

    ll mid = low + (high - low) / 2;
    if (low != high && lazy[index] != temp) 

    {
        ll left = 2 * index + 1, right = 2 * index + 2;
        segmentTree[left] = max(segmentTree[left], lazy[index]);
        segmentTree[right] = max(segmentTree[right], lazy[index]);
        lazy[left] = max(lazy[left], lazy[index]);
        lazy[right] = max(lazy[left], lazy[index]);
        lazy[index] = temp;
    }
    auto left = id11(2 * index + 1, low, mid, l, r, segmentTree, lazy);
    auto right = id11(2 * index + 2, mid + 1, high, l, r, segmentTree, lazy);
    return max(left, right);
}



class TrieString
{
public:
    class Node
    {
    public:
        bool end;
        Node *next[26];
        Node()
        {
            end = false;
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
        }
    };
    Node *ourTrie;
    TrieString()
    {
        ourTrie = new Node();
        

        ourTrie->end = true;
    }
    void insert(string &word)
    {
        Node *it = ourTrie;
        for (int i = 0; i < word.size(); i++)
        {
            if (it->next[word[i] - 'a'] == NULL)
                it->next[word[i] - 'a'] = new Node();
            it = it->next[word[i] - 'a'];
        }
        it->end = true;
    }
    bool search(string &word)
    {
        Node *it = ourTrie;
        for (int i = 0; i < word.size(); i++)
        {
            if (it->next[word[i] - 'a'] == NULL)
                return false;
            it = it->next[word[i] - 'a'];
        }
        return true;
    }
};







vector<ll> BinaryFunction(ll num)
{
    vector<ll> binary(31, 0);
    for (ll bit = 30; bit >= 0; bit--)
    {
        if ((num & (1 << bit)) != 0)
            binary[bit] = 1;
    }
    return binary;
}
class Trie
{
public:
    class Node
    {
    public:
        Node *next[2];
        int id1;
        

        Node()
        {
            id1 = 0;
            for (int i = 0; i < 2; i++)
                next[i] = NULL;
        }
    };
    Node *ourTrie;
    Trie()
    {
        ourTrie = new Node();
        

    }
    void insert(vector<ll> &binary)
    {
        Node *it = ourTrie;
        for (ll i = 30; i >= 0; i--)
        {
            if (it->next[binary[i]] == NULL)
                it->next[binary[i]] = new Node();
            it = it->next[binary[i]];
            it->id1++;
        }
    }
    vector<ll> solve(ll bit, Node *it, vector<ll> &Final)
    {
        vector<ll> BinaryRep(31, 0);
        if (it == NULL || bit < 0)
            return BinaryRep;
        vector<ll> FinOne(31, 0);
        vector<ll> FinZero(31, 0);
        vector<ll> binZero = solve(bit - 1, it->next[0], FinZero);
        vector<ll> binOne = solve(bit - 1, it->next[1], FinOne);
        

        if (it->next[0] == NULL)
        {
            binOne[bit] = 0;
            FinOne[bit] = 1; 

            for (ll i = 0; i < 31; i++)
                Final[i] += FinOne[i];
            return binOne;
        }
        

        if (it->next[1] == NULL)
        {
            binZero[bit] = 0;
            FinZero[bit] = 0; 

            for (ll i = 0; i < 31; i++)
                Final[i] += FinZero[i];
            return binZero;
        }
        

        binZero[bit] = 1;
        binOne[bit] = 1;
        reverse(binZero.begin(), binZero.end());
        reverse(binOne.begin(), binOne.end());
        

        


        if (binZero <= binOne)
        {
            

            reverse(binZero.begin(), binZero.end());
            binZero[bit] = 1;
            FinZero[bit] = 1; 

            for (ll i = 0; i < 30; i++)
                Final[i] += FinZero[i];
            return binZero;
        }
        else
        {
            

            reverse(binOne.begin(), binOne.end());
            binOne[bit] = 1;
            FinOne[bit] = 0; 

            for (ll i = 0; i < 30; i++)
                Final[i] += FinOne[i];
            return binOne;
        }
    }
};





void id17(ll u, vector<bool> &Visited, vector<ll> &Depth, vector<vector<ll>> &Parent, vector<vector<ll>> &Tree)
{
    Visited[u] = true;
    for (auto v : Tree[u])
    {
        if (Visited[v] == false)
        {
            Parent[v][0] = u;
            Depth[v] = Depth[u] + 1;
            id17(v, Visited, Depth, Parent, Tree);
        }
    }
}
void id20(ll N, ll maxN, vector<vector<ll>> &LCA)
{
    

    for (ll j = 1; j <= maxN; j++) 

    {
        for (ll i = 0; i < N; i++)
        {
            if (LCA[i][j - 1] != -1)
            {
                ll parent = LCA[i][j - 1];
                LCA[i][j] = LCA[parent][j - 1];
            }
        }
    }
}
ll id14(ll node, ll J, ll maxN, vector<vector<ll>> &LCA)
{
    for (ll x = 0; x <= maxN; x++)
    {
        if ((J & (one << x)) != 0)
        {
            node = LCA[node][x];
        }
    }
    return node;
}
pair<ll, ll> id5(ll a, ll b, vector<ll> &Depth, vector<vector<ll>> &Parent)
{
    ll N = Depth.size();
    if (Depth[a] > Depth[b])
        swap(a, b);
    ll maxN = log2(N);
    ll distance = 0;
    for (ll i = maxN; i >= 0; i--)
        if (Parent[b][i] != -1 && Depth[Parent[b][i]] >= Depth[a])
            b = Parent[b][i], distance += (1ll << i);
    

    

    if (a == b)
        return {a, distance};
    for (ll i = maxN; i >= 0; i--)
    {
        if (Parent[a][i] != Parent[b][i] && Parent[a][i] != -1)
        {
            a = Parent[a][i];
            b = Parent[b][i];
            distance += (1ll << (i + 1));
        }
    }
    return {Parent[a][0], distance + 2};
}





vector<ll> fact(5 * 1e5 + 5, 0);
void init_fact()
{
    fact[0] = 1;
    for (ll i = 1; i < 5 * 1e5 + 5; i++)
        fact[i] = (i * fact[i - 1]) % 998244353;
}
ll id21(ll n, ll r, ll mod)
{
    if (n < r || r < 0)
        return 0;
    ll ans = fact[n];
    ll denom = (fact[r] * fact[n - r]) % mod;
    ll mod_inv = mpow(denom, mod - 2, mod);
    ans = (ans * mod_inv) % mod;
    return ans;
}





ll bitSum(vector<ll> &BITree, ll index)
{
    ll sum = 0;
    index = index + 1;
    while (index > 0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}
void bitUpdate(vector<ll> &BITree, ll index, ll val)
{
    index = index + 1;
    while (index <= BITree.size())
    {
        BITree[index] += val;
        index += index & (-index);
    }
}





ll id18(ll u, vector<ll> &visited, vector<vector<ll>> &Tree)
{
    ll id9 = u;
    for (auto v : Tree[u])
    {
        

        if (visited[v] == -1)
        {
            visited[v] = visited[u] + 1;
            ll temp = id18(v, visited, Tree);
            if (visited[id9] <= visited[temp])
                id9 = temp;
        }
    }
    return id9;
}
pair<ll, pair<ll, ll>> Diameter(vector<vector<ll>> &Tree)
{
    ll N = Tree.size();
    vector<ll> visited(N, -1);
    visited[0] = 0;
    ll oneEnd = id18(0, visited, Tree);
    visited = vector<ll>(N, -1);
    visited[oneEnd] = 0;
    ll otherEnd = id18(oneEnd, visited, Tree);
    

    

    return {visited[otherEnd], {oneEnd, otherEnd}};
}





void PrefixFunction(string &S, vector<ll> &Pi)
{
    ll j = 0;
    for (ll i = 1; i < S.size(); i++)
    {
        while (j > 0 && S[i] != S[j])
            j = Pi[j - 1];
        if (S[i] == S[j])
            j++;
        Pi[i] = j;
    }
}





ll rootN;
bool MoComparator(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b)
{
    if (a.first.first / rootN != b.first.first / rootN)
        return a.first.first / rootN < b.first.first / rootN;
    return a.first.second / rootN < b.first.second / rootN;
}
void addMo(ll item, ll &currMax, vector<ll> &Freq, vector<ll> &id2)
{
    ll preF = Freq[item];
    Freq[item]++;
    ll curF = Freq[item];

    id2[preF]--;
    id2[curF]++;
    

    if (curF > currMax)
    {
        currMax = curF;
    }
}
void removeMo(ll item, ll &currMax, vector<ll> &Freq, vector<ll> &id2)
{
    ll preF = Freq[item];
    Freq[item]--;
    ll curF = Freq[item];

    id2[preF]--;
    id2[curF]++;
    

    if (curF < currMax)
    {
        while (id2[currMax] == 0)
            currMax--;
    }
}



void DFS1(ll u, vector<vector<ll>> &mySet, vector<ll> &Color, vector<vector<ll>> &Graph)
{
    

    Color[u] = 1;
    for (auto v : Graph[u])
    {
        

        if (Color[v] == 0)
            DFS1(v, mySet, Color, Graph);
        

        else if (Color[v] == 1)
            mySet[0].push_back(v);
        

        else if (Color[v] == 2)
            mySet[1].push_back(v);
    }
    

    Color[u] = 2;
}

bool isPrime(ll N)
{
    if (N == 2 || (N == 3 || N == 1))
        return true;
    for (ll i = 2; i * i <= N; i++)
        if (N % i == 0)
            return false;
    return true;
}

void BFS(ll u, vector<ll> &Distance, vector<vector<ll>> &Graph)
{
    ll N = Distance.size();
    Distance[u] = 0;
    queue<ll> myQueue;
    myQueue.push(u);
    while (!myQueue.empty())
    {
        ll u = myQueue.front();
        myQueue.pop();
        for (auto v : Graph[u])
        {
            if (Distance[v] == -1)
            {
                Distance[v] = Distance[u] + 1;
                myQueue.push(v);
            }
        }
    }
}

void DFS(ll u, vector<bool> &visited, vector<vector<pair<ll, ll>>> &DP, vector<vector<ll>> &Tree)
{
    visited[u] = true;
    

    DP[u][1] = {1ll, Tree[u].size()};
    

    DP[u][0] = {0ll, 1ll};
    for (auto v : Tree[u])
    {
        if (visited[v] == true)
            continue;
        DFS(v, visited, DP, Tree);
        

        DP[u][1].first += DP[v][0].first;
        DP[u][1].second += DP[v][0].second;
        

        

        if (DP[v][1].first > DP[v][0].first)
        {
            DP[u][0].first += DP[v][1].first;
            DP[u][0].second += DP[v][1].second;
        }
        

        else if (DP[v][1].first < DP[v][0].first)
        {
            DP[u][0].first += DP[v][0].first;
            DP[u][0].second += DP[v][0].second;
        }
        else if (DP[v][1].second < DP[v][0].second)
        {
            DP[u][0].first += DP[v][1].first;
            DP[u][0].second += DP[v][1].second;
        }
        else
        {
            DP[u][0].first += DP[v][0].first;
            DP[u][0].second += DP[v][0].second;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    

    for (ll t = 0; t < T; t++)
    {
        ll N, C;
        cin >> N >> C;
        vector<ll> A(N);
        vector<ll> Mark(C + 10, 0);
        for (ll i = 0; i < N; i++)
            cin >> A[i], Mark[A[i]]++;
        for (ll i = 1; i <= C; i++)
            Mark[i] += Mark[i - 1];
        ll possible = 1;

        for (ll i = 1; i <= C; i++)
        {
            if (Mark[i] - Mark[i - 1] <= 0)
                continue;
            for (ll j = i; j <= C; j += i)
            {
                ll low = j;
                ll high = j + i - 1;
                high = min(high, C);
                ll id19 = j / i;
                ll found1 = 0;
                ll found2 = 0;
                if (Mark[id19] - Mark[id19 - 1] > 0)
                    found1 = 1;
                if (Mark[high] - Mark[low - 1] > 0)
                    found2 = 1;
                if (found2 == 1 && found1 == 0)
                {
                    possible = 0;
                    

                    

                    

                    

                }
            }
            if (possible == 0)
                break;
        }
        if (Mark[1] - Mark[0] < 0)
            possible = 0;
        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        if (possible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}















