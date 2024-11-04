







using namespace __gnu_pbds;

using namespace std;
typedef long long int ll;














ll T;
ll N, M, K;
ll one = 1;
ll modulo = 1000000007;
map<ll, ll> myMap;
vector<bool> Prime(3 * 1e6, true);
map<ll, ll> id6, Opposite;
vector<int> id24(3 * 1e6, 1);

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
                id24[j] = j / i;
            Prime[j] = false;
        }
    }
    ll times = 1;
    for (ll i = 2; i < Prime.size(); i++)
    {
        if (Prime[i] == true)
        {
            id6[i] = times;
            Opposite[times] = i;
            times++;
        }
    }
}

set<ll> id13(ll Num)
{
    set<ll> id0;
    for (ll i = 1; i * i <= Num; i++)
    {
        if (Num % i == 0)
        {
            id0.insert(Num / i);
            id0.insert(i);
        }
    }
    return id0;
}


ll Power(ll a, ll b, ll p)
{
    a %= p;
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return ans;
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
        return id21;
    

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
        return id15;
    

    if (l <= low && high <= r)
        return segment[index];
    

    ll mid = low + (high - low) / 2;
    ll left = queryMin(2 * index + 1, low, mid, l, r, segment);
    ll right = queryMin(2 * index + 2, mid + 1, high, l, r, segment);
    return min(left, right);
}



void isCycle(ll u, vector<bool> &order, vector<bool> &visited, vector<ll> &Parent, vector<vector<ll>> &Graph)
{
    visited[u] = true;
    order[u] = true;
    for (auto v : Graph[u])
    {
        if (visited[v] == false)
        {
            isCycle(v, order, visited, Parent, Graph);
        }
        else if (order[v] == true)
        {
            

        }
    }
    order[u] = false;
}

void Centroid(ll u, ll prev, vector<ll> &centroid, vector<ll> &sz, vector<vector<ll>> &Graph)
{
    ll N = Graph.size() - 1;
    bool id8 = true;
    for (auto v : Graph[u])
    {
        if (v != prev)
        {
            Centroid(v, u, centroid, sz, Graph);
            if (sz[v] > N / 2)
                id8 = false;
            sz[u] += sz[v];
        }
    }
    if (N - sz[u] > N / 2)
        id8 = false;
    if (id8)
        centroid.push_back(u);
}

void BFS(ll N, vector<vector<ll>> &Graph, vector<ll> &newPattern)
{
    

    vector<bool> visited(N + 1, false);
    queue<ll> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        newPattern.push_back(u);
        for (auto v : Graph[u])
        {
            if (visited[v] == true)
                continue;
            visited[v] = true;
            q.push(v);
        }
    }
}

bool id2(pair<ll, ll> i, pair<ll, ll> j)
{
    if (i.second < j.second)
        return true;
    return false;
}

bool id9(pair<ll, ll> i, pair<ll, ll> j)
{
    if (i.first < j.first)
        return true;
    return false;
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
    {
        

        return true;
    }
    

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





void id18(ll &Min, ll &next_node, vector<ll> &Weights, vector<bool> &id19, priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> &pq)
{
    while (pq.size() != 0)
    {
        auto x = pq.top();
        pq.pop();
        if (id19[x.second] == false)
        {
            Min = x.first;
            next_node = x.second;
            return;
        }
    }
}

void id16(ll u, vector<bool> &id19, vector<ll> &Weights, vector<vector<pair<ll, ll>>> &Graph, ll &result, priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> &pq)
{
    if (id19[u] == true) 

        return;
    id19[u] = true;
    for (auto x : Graph[u])
    {
        ll v, w;
        v = x.first, w = x.second;
        if (id19[v] == false) 

        {
            if (Weights[v] > w)
                pq.push({w, v});
        }
    }
    ll Min = id15, next_node = -1;
    id18(Min, next_node, Weights, id19, pq);
    

    if (Min == id15)
        return;
    result += Min;
    id16(next_node, id19, Weights, Graph, result, pq);
}

ll MST(vector<vector<pair<ll, ll>>> &Graph)
{
    vector<ll> Weights(Graph.size(), id15);
    Weights[0] = 0;
    vector<bool> id19(Graph.size(), false);
    ll result = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (ll i = 0; i < Graph.size(); i++)
        pq.push({Weights[i], i});
    id16(0, id19, Weights, Graph, result, pq);
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
        segmentTree[left] += (mid - low + 1) * val;
        segmentTree[right] += (high - mid - 1 + 1) * val;
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



void id7(ll index, ll low, ll high, ll node, ll val, vector<ll> &segmentTree)
{
    

    if (node < low || node > high)
        return;
    

    if (low == high)
    {
        segmentTree[index] = val;
        return;
    }
    ll mid = low + (high - low) / 2;
    

    id7(2 * index + 1, low, mid, node, val, segmentTree);
    id7(2 * index + 2, mid + 1, high, node, val, segmentTree);
    segmentTree[index] = __gcd(segmentTree[2 * index + 1], segmentTree[2 * index + 2]);
}

ll id11(ll index, ll low, ll high, ll l, ll r, vector<ll> &segmentTree)
{
    

    if (r < low || l > high)
        return 0;
    

    if (l <= low && high <= r)
        return segmentTree[index];
    

    ll mid = low + (high - low) / 2;
    ll left = id11(2 * index + 1, low, mid, l, r, segmentTree);
    ll right = id11(2 * index + 2, mid + 1, high, l, r, segmentTree);
    return __gcd(left, right);
}




void id10(ll index, ll low, ll high, ll l, ll r, ll val, vector<ll> &segmentTree, vector<ll> &lazy)
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
    

    ll temp = id21;
    if (low != high && lazy[index] != temp) 

    {
        ll left = 2 * index + 1, right = 2 * index + 2;
        segmentTree[left] = max(segmentTree[left], lazy[index]);
        segmentTree[right] = max(segmentTree[right], lazy[index]);
        lazy[left] = max(lazy[left], lazy[index]);
        lazy[right] = max(lazy[right], lazy[index]);
        lazy[index] = temp;
    }
    

    id10(2 * index + 1, low, mid, l, r, val, segmentTree, lazy);
    id10(2 * index + 2, mid + 1, high, l, r, val, segmentTree, lazy);
    segmentTree[index] = max(segmentTree[2 * index + 1], segmentTree[2 * index + 2]);
}

ll id14(ll index, ll low, ll high, ll l, ll r, vector<ll> &segmentTree, vector<ll> &lazy)
{
    ll temp = id21;
    

    if (r < low || l > high)
        return temp;
    

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
    auto left = id14(2 * index + 1, low, mid, l, r, segmentTree, lazy);
    auto right = id14(2 * index + 2, mid + 1, high, l, r, segmentTree, lazy);
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
        int id3;
        

        Node()
        {
            id3 = 0;
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
            it->id3++;
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






void id22(ll N, ll maxN, vector<vector<ll>> &LCA)
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

ll id17(ll node, ll J, ll maxN, vector<vector<ll>> &LCA)
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



vector<ll> fact(5 * 1e5 + 5, 0);

void init_fact()
{
    fact[0] = 1;
    for (ll i = 1; i < 5 * 1e5 + 5; i++)
        fact[i] = (i * fact[i - 1]) % 998244353;
}

ll id23(ll n, ll r, ll mod)
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




ll id20(ll u, vector<ll> &visited, vector<vector<ll>> &Tree)
{
    ll id12 = u;
    for (auto v : Tree[u])
    {
        

        if (visited[v] == -1)
        {
            visited[v] = visited[u] + 1;
            ll temp = id20(v, visited, Tree);
            if (visited[id12] <= visited[temp])
                id12 = temp;
        }
    }
    return id12;
}

ll Diameter(vector<vector<ll>> &Tree)
{
    ll N = Tree.size();
    vector<ll> visited(N, -1);
    visited[0] = 0;
    ll oneEnd = id20(0, visited, Tree);
    visited = vector<ll>(N, -1);
    visited[oneEnd] = 0;
    ll otherEnd = id20(oneEnd, visited, Tree);
    

    return visited[otherEnd];
}

bool comparator(vector<ll> &A, vector<ll> &B)
{
    ll N = A.size() - 1;
    if (A[N] > B[N])
        return true;
    else
        return false;
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

void addMo(ll item, ll &currMax, vector<ll> &Freq, vector<ll> &id5)
{
    ll preF = Freq[item];
    Freq[item]++;
    ll curF = Freq[item];

    id5[preF]--;
    id5[curF]++;
    

    if (curF > currMax)
    {
        currMax = curF;
    }
}

void removeMo(ll item, ll &currMax, vector<ll> &Freq, vector<ll> &id5)
{
    ll preF = Freq[item];
    Freq[item]--;
    ll curF = Freq[item];

    id5[preF]--;
    id5[curF]++;
    

    if (curF < currMax)
    {
        while (id5[currMax] == 0)
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

ll ans = 1;
unordered_map<ll, map<ll, ll>> id1, id4;
void solve(ll pos, ll x, ll N)
{
    ll mod = 1e9 + 7;
    for (ll i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            id1[pos][i]++;
            id4[i][id1[pos][i]]++;
            if (id4[i][id1[pos][i]] == N)
                ans = (ans * i) % mod;
            x /= i;
        }
    }
    if (x > 1)
    {
        id1[pos][x]++;
        id4[x][id1[pos][x]]++;
        if (id4[x][id1[pos][x]] == N)
            ans = (ans * x) % mod;
    }
}

bool isPrime(ll N)
{
    if (N == 2 || N == 3)
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    T = 1;
    for (ll t = 0; t < T; t++)
    {
        ll N, Q;
        cin >> N >> Q;
        vector<ll> A(N), SubArray(N, 1);
        for (ll i = 0; i < N; i++)
            cin >> A[i];
        for (ll i = N - 2; i >= 0; i--)
            if (A[i] <= A[i + 1])
                SubArray[i] += SubArray[i + 1];
        vector<ll> segmentTree(4 * (N + 1), 0), Lazy(4 * (N + 1), 0);

        for (ll i = 0; i < N; i++)
            rangeUpdate(0, 0, N - 1, i, i, SubArray[i], segmentTree, Lazy);

        for (ll q = 0; q < Q; q++)
        {
            ll p;
            cin >> p;
            if (p == 1)
            {
                ll x, y;
                cin >> x >> y;
                x--;
                ll change = 0;
                ll prev = queryLazy(0, 0, N - 1, x, x, segmentTree, Lazy);
                if (x != N - 1)
                {
                    

                    if ((A[x] > A[x + 1]) && (y <= A[x + 1]))
                    {
                        ll nxt = queryLazy(0, 0, N - 1, x + 1, x + 1, segmentTree, Lazy);
                        rangeUpdate(0, 0, N - 1, x, x, nxt, segmentTree, Lazy);
                        change = nxt;
                    }
                    

                    else if ((A[x] <= A[x + 1]) && (y > A[x + 1]))
                    {
                        ll nxt = queryLazy(0, 0, N - 1, x + 1, x + 1, segmentTree, Lazy);
                        rangeUpdate(0, 0, N - 1, x, x, -nxt, segmentTree, Lazy);
                        change = -nxt;
                    }
                }
                

                if (x != 0)
                {
                    

                    if ((A[x - 1] > A[x]) && (A[x - 1] <= y))
                    {
                        ll low = 0, high = x - 1;
                        ll start = x;
                        while (low <= high)
                        {
                            ll mid = low + (high - low) / 2;
                            ll val = queryLazy(0, 0, N - 1, mid, mid, segmentTree, Lazy);
                            if (val >= x - mid)
                                start = min(start, mid), high = mid - 1;
                            else
                                low = mid + 1;
                        }
                        

                        ll val = queryLazy(0, 0, N - 1, x, x, segmentTree, Lazy);
                        if (start != x)
                            rangeUpdate(0, 0, N - 1, start, x - 1, val, segmentTree, Lazy);
                    }
                    

                    else if ((A[x - 1] <= A[x]) && (A[x - 1] > y))
                    {
                        ll low = 0, high = x - 1;
                        ll start = x;
                        while (low <= high)
                        {
                            ll mid = low + (high - low) / 2;
                            ll val = queryLazy(0, 0, N - 1, mid, mid, segmentTree, Lazy);
                            if (val >= x - mid + 1)
                                start = min(start, mid), high = mid - 1;
                            else
                                low = mid + 1;
                        }
                        

                        

                        

                        

                        


                        if (start != x)
                            rangeUpdate(0, 0, N - 1, start, x - 1, -(prev), segmentTree, Lazy);
                    }
                    

                    else if ((A[x - 1] <= A[x]) && (A[x - 1] <= y))
                    {
                        ll low = 0, high = x - 1;
                        ll start = x;
                        while (low <= high)
                        {
                            ll mid = low + (high - low) / 2;
                            ll val = queryLazy(0, 0, N - 1, mid, mid, segmentTree, Lazy);
                            if (val >= x - mid + 1)
                                start = min(start, mid), high = mid - 1;
                            else
                                low = mid + 1;
                        }
                        if (start != x)
                            rangeUpdate(0, 0, N - 1, start, x - 1, change, segmentTree, Lazy);
                    }
                }
                A[x] = y;
            }
            else
            {
                ll l, r;
                cin >> l >> r;
                l--, r--;
                ll low = l, high = r;
                ll start = r + 1;
                while (low <= high)
                {
                    ll mid = low + (high - low) / 2;
                    ll val = queryLazy(0, 0, N - 1, mid, mid, segmentTree, Lazy);
                    if (val > r - mid + 1)
                        start = mid, high = mid - 1;
                    else
                        low = mid + 1;
                }
                ll ans = queryLazy(0, 0, N - 1, l, r, segmentTree, Lazy);
                if (start != r + 1)
                {
                    ll cnt = r - start + 1;
                    ll extra = 0;
                    if (r != N - 1)
                    {
                        extra = queryLazy(0, 0, N - 1, r + 1, r + 1, segmentTree, Lazy);
                        ans -= cnt * extra;
                    }
                }
                cout << ans << "\n";
            }
        }
    }
    return 0;
}



























































































