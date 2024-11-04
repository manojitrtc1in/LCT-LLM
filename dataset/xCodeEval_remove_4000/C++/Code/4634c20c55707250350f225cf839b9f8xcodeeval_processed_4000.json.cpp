







using namespace __gnu_pbds;

using namespace std;
typedef long long ll;






ll T;


ll one = 1;
ll modulo = 1000000007;
map<ll, ll> myMap;
vector<bool> Prime(3 * 1e6, true);
map<ll, ll> id5, Opposite;
vector<int> id21(3 * 1e6, 1);

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
                id21[j] = j / i;
            Prime[j] = false;
        }
    }
    ll times = 1;
    for (ll i = 2; i < Prime.size(); i++)
    {
        if (Prime[i] == true)
        {
            id5[i] = times;
            Opposite[times] = i;
            times++;
        }
    }
}

set<ll> id10(ll Num)
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


ll build(ll index, ll low, ll high, vector<ll> &A, vector<ll> &segment)
{
    

    if (low == high)
    {
        return segment[index] = A[low];
    }
    ll mid = low + (high - low) / 2;
    ll left = build(2 * index + 1, low, mid, A, segment);       

    ll right = build(2 * index + 2, mid + 1, high, A, segment); 

    segment[index] = max(left, right);
    return segment[index];
}

ll build2(ll index, ll low, ll high, vector<ll> &A, vector<ll> &segment)
{
    

    if (low == high)
        return segment[index] = A[low];
    ll mid = low + (high - low) / 2;
    ll left = build2(2 * index + 1, low, mid, A, segment);       

    ll right = build2(2 * index + 2, mid + 1, high, A, segment); 

    return segment[index] = __gcd(left, right);
}


ll query(ll index, ll low, ll high, ll l, ll r, vector<ll> &segment)
{
    

    if (r < low || high < l)
        return INT_MIN;
    

    if (l <= low && high <= r)
        return segment[index];
    

    ll mid = low + (high - low) / 2;
    ll left = query(2 * index + 1, low, mid, l, r, segment);
    ll right = query(2 * index + 2, mid + 1, high, l, r, segment);
    return segment[index] = max(left, right);
}


ll query2(ll index, ll low, ll high, ll l, ll r, vector<ll> &segment)
{
    

    if (l <= low && high <= r)
    {
        

        return segment[index];
    }
    

    if (r < low || high < l)
        return 0;
    

    ll mid = low + (high - low) / 2;
    ll left = query2(2 * index + 1, low, mid, l, r, segment);
    ll right = query2(2 * index + 2, mid + 1, high, l, r, segment);
    

    return __gcd(left, right);
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

bool id7(pair<ll, ll> i, pair<ll, ll> j)
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


void DFS(ll u, ll Parent, ll pos, vector<vector<ll>> &Nodes, vector<vector<ll>> &Tree)
{
    Nodes[pos].push_back(u);
    for (auto v : Tree[u])
    {
        if (Parent == v)
            continue;
        DFS(v, u, pos ^ 1, Nodes, Tree);
    }
}

void rangeUpdate(ll index, ll low, ll high, ll l, ll r, ll val, vector<ll> &segmentTree, vector<ll> &lazy)
{
    

    if (r < low || l > high)
        return;
    

    if (l <= low && high <= r)
    {
        segmentTree[index] = (high - low + 1) * val;
        lazy[index] = val; 

        return;
    }
    ll mid = low + (high - low) / 2;
    

    if (low != high && lazy[index] != -1) 

    {
        ll left = 2 * index + 1, right = 2 * index + 2;
        segmentTree[left] = (mid - low + 1) * val;
        segmentTree[right] = (high - mid - 1 + 1) * val;
        lazy[left] = lazy[index];
        lazy[right] = lazy[index];
        lazy[index] = -1;
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
    if (low != high && lazy[index] != -1) 

    {
        ll left = 2 * index + 1, right = 2 * index + 2;
        segmentTree[left] = (mid - low + 1) * lazy[index];
        segmentTree[right] = (high - mid - 1 + 1) * lazy[index];
        lazy[left] = lazy[index];
        lazy[right] = lazy[index];
        lazy[index] = -1;
    }
    ll left = queryLazy(2 * index + 1, low, mid, l, r, segmentTree, lazy);
    ll right = queryLazy(2 * index + 2, mid + 1, high, l, r, segmentTree, lazy);
    return segmentTree[index] = left + right;
}




void id8(ll index, ll low, ll high, ll l, ll r, ll val, vector<ll> &segmentTree, vector<ll> &lazy)
{
    

    if (r < low || high < l)
        return;
    

    if (l <= low && high <= r)
    {
        segmentTree[index] = max(segmentTree[index], val);
        lazy[index] = max(lazy[index], val); 

        return;
    }
    ll mid = low + (high - low) / 2;
    

    ll temp = id18;
    if (low != high && lazy[index] != temp) 

    {
        ll left = 2 * index + 1, right = 2 * index + 2;
        segmentTree[left] = max(segmentTree[left], lazy[index]);
        segmentTree[right] = max(segmentTree[right], lazy[index]);
        lazy[left] = max(lazy[left], lazy[index]);
        lazy[right] = max(lazy[right], lazy[index]);
        lazy[index] = temp;
    }
    

    id8(2 * index + 1, low, mid, l, r, val, segmentTree, lazy);
    id8(2 * index + 2, mid + 1, high, l, r, val, segmentTree, lazy);
    segmentTree[index] = max(segmentTree[2 * index + 1], segmentTree[2 * index + 2]);
}

ll id11(ll index, ll low, ll high, ll l, ll r, vector<ll> &segmentTree, vector<ll> &lazy)
{
    ll temp = id18;
    

    if (r < low || high < l)
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
        lazy[right] = max(lazy[right], lazy[index]);
        lazy[index] = temp;
    }
    auto left = id11(2 * index + 1, low, mid, l, r, segmentTree, lazy);
    auto right = id11(2 * index + 2, mid + 1, high, l, r, segmentTree, lazy);
    return segmentTree[index] = max(left, right);
}



void id19(ll N, ll maxN, vector<vector<ll>> &LCA)
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



vector<ll> fact(3 * 1e5 + 5, 0);

void init_fact()
{
    fact[0] = 1;
    for (ll i = 1; i < 3 * 1e5 + 5; i++)
        fact[i] = (i * fact[i - 1]) % 998244353;
}

ll id20(ll n, ll r, ll mod)
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




ll id17(ll u, vector<ll> &visited, vector<vector<ll>> &Tree)
{
    ll id9 = u;
    for (auto v : Tree[u])
    {
        

        if (visited[v] == -1)
        {
            visited[v] = visited[u] + 1;
            ll temp = id17(v, visited, Tree);
            if (visited[id9] <= visited[temp])
                id9 = temp;
        }
    }
    return id9;
}

ll Diameter(vector<vector<ll>> &Tree)
{
    ll N = Tree.size();
    vector<ll> visited(N, -1);
    visited[0] = 0;
    ll oneEnd = id17(0, visited, Tree);
    visited = vector<ll>(N, -1);
    visited[oneEnd] = 0;
    ll otherEnd = id17(oneEnd, visited, Tree);
    

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

ll rootN;
bool MoComparator(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b)
{
    if (a.first.first / rootN != b.first.first / rootN)
        return a.first.first / rootN < b.first.first / rootN;
    return a.first.second / rootN < b.first.second / rootN;
}

void addMo(ll item, ll &currMax, vector<ll> &Freq, vector<ll> &id4)
{
    ll preF = Freq[item];
    Freq[item]++;
    ll curF = Freq[item];

    id4[preF]--;
    id4[curF]++;
    

    if (curF > currMax)
    {
        currMax = curF;
    }
}

void removeMo(ll item, ll &currMax, vector<ll> &Freq, vector<ll> &id4)
{
    ll preF = Freq[item];
    Freq[item]--;
    ll curF = Freq[item];

    id4[preF]--;
    id4[curF]++;
    

    if (curF < currMax)
    {
        while (id4[currMax] == 0)
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

void DFS2(ll u, vector<bool> &visited, vector<vector<ll>> &Graph)
{
    visited[u] = true;
    for (auto v : Graph[u])
    {
        if (visited[v] == false)
        {
            DFS2(v, visited, Graph);
        }
    }
}

ll ans = 1;
unordered_map<ll, map<ll, ll>> id1, id3;
void solve(ll pos, ll x, ll N)
{
    ll mod = 1e9 + 7;
    for (ll i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            id1[pos][i]++;
            id3[i][id1[pos][i]]++;
            if (id3[i][id1[pos][i]] == N)
                ans = (ans * i) % mod;
            x /= i;
        }
    }
    if (x > 1)
    {
        id1[pos][x]++;
        id3[x][id1[pos][x]]++;
        if (id3[x][id1[pos][x]] == N)
            ans = (ans * x) % mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    T = 1;
    for (ll t = 0; t < T; t++)
    {
        ll n;
        cin >> n;
        vector<ll> h(n), b(n);
        for (ll i = 0; i < n; i++)
            cin >> h[i];
        for (ll i = 0; i < n; i++)
            cin >> b[i];
        stack<ll> s;
        vector<ll> dp(n + 1, -1e18), mx(n + 1, -1e18);
        dp[0] = b[0];
        mx[0] = b[0];
        s.push(0);
        for (ll i = 1; i < n; i++)
        {
            while (s.size() && h[s.top()] > h[i])
            {
                mx[i] = max(mx[s.top()], mx[i]);
                s.pop();
            }
            dp[i] = (s.empty() ? max(mx[i], 0LL) : mx[i]) + b[i];
            if (s.size())
                dp[i] = max(dp[i], dp[s.top()] + max(0ll, b[i]));
            s.push(i);
            mx[i] = max(mx[i], dp[i]);
        }
        cout << dp[n - 1] << '\n';
    }
    return 0;
}













