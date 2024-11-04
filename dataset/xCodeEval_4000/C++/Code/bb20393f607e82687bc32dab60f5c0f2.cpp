#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define PB push_back
ll T;
ll N, M, K;
ll one = 1;
ll modulo = 1000000007;
map<ll, ll> myMap;
vector<bool> Prime(3 * 1e6, true);
map<ll, ll> PrimeIndexing, Opposite;
vector<ll> GreatestDivisor(3 * 1e6, 1);
void Sieve()
{
    for (ll i = 2; i * i <= Prime.size(); i++)
    {
        if (Prime[i] != true) 

            continue;
        for (ll j = i * i; j < Prime.size(); j += i)
        {
            if (Prime[j] == true)
                GreatestDivisor[j] = j / i;
            Prime[j] = false;
        }
    }
    ll times = 1;
    for (ll i = 2; i < Prime.size(); i++)
    {
        if (Prime[i] == true)
        {
            PrimeIndexing[i] = times;
            Opposite[times] = i;
            times++;
        }
    }
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
    ll fullSize = high - low + 1;
    ll left = build(2 * index + 1, low, mid, A, segment);       

    ll right = build(2 * index + 2, mid + 1, high, A, segment); 

    ll power = log2(fullSize);
    if (power % 2 == 0) 

        segment[index] = left ^ right;
    else
        segment[index] = left | right;
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


ll query(ll index, ll low, ll high, ll p, ll b, vector<ll> &segment)
{
    

    if (p < low || high < p)
        return segment[index];
    

    if (low == high && low == p)
        return segment[index] = b;
    

    ll mid = low + (high - low) / 2;
    ll fullSize = high - low + 1;
    ll power = log2(fullSize);
    ll left = query(2 * index + 1, low, mid, p, b, segment);
    ll right = query(2 * index + 2, mid + 1, high, p, b, segment);
    if (power % 2 == 0) 

        return segment[index] = left ^ right;
    else
        return segment[index] = left | right;
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



bool isCycle(ll u, vector<bool> &order, vector<bool> &visited, vector<vector<ll>> &Graph)
{
    visited[u] = true;
    order[u] = true;
    for (auto v : Graph[u])
    {
        if (visited[v] == false)
        {
            bool temp = isCycle(v, order, visited, Graph);
            if (temp == true)
                return true;
        }
        else if (order[v] == true)
        {
            return true;
        }
    }
    order[u] = false;
    return false;
}

void Centroid(ll u, ll prev, vector<ll> &centroid, vector<ll> &sz, vector<vector<ll>> &Graph)
{
    ll N = Graph.size() - 1;
    bool is_Centroid = true;
    for (auto v : Graph[u])
    {
        if (v != prev)
        {
            Centroid(v, u, centroid, sz, Graph);
            if (sz[v] > N / 2)
                is_Centroid = false;
            sz[u] += sz[v];
        }
    }
    if (N - sz[u] > N / 2)
        is_Centroid = false;
    if (is_Centroid)
        centroid.push_back(u);
}

void DFS1(ll u, vector<bool> &visited, vector<ll> &DP1, vector<ll> &DP2, vector<ll> &A, vector<vector<ll>> &Tree)
{
    visited[u] = true;
    DP2[u] = DP1[u];
    for (auto v : Tree[u])
    {
        if (visited[v] == false) 

        {
            ll child = DP1[v];                     

            ll Without = DP1[u] - max(0ll, child); 

            DP1[v] += max(0ll, Without);
            DFS1(v, visited, DP1, DP2, A, Tree);
        }
    }
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

bool comparatorEnd(pair<ll, ll> i, pair<ll, ll> j)
{
    if (i.second < j.second)
        return true;
    return false;
}

bool comparatorFirst(pair<ll, ll> i, pair<ll, ll> j)
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
    return ans;
}

void Union(ll u, ll v, ll &ans, vector<ll> &Size, vector<ll> &parent, vector<ll> &rank)
{
    

    u = findParent(u, parent), v = findParent(v, parent);
    if (u == v)
    {
        return;
    }
    ans += ((Size[u] + Size[v]) * (Size[u] + Size[v] - 1) / 2) - (Size[u] * (Size[u] - 1) / 2) - (Size[v] * (Size[v] - 1) / 2);
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
    

}



void selectMinVertex(ll &Min, ll &next_node, vector<ll> &Weights, vector<bool> &setMST, priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> &pq)
{
    while (pq.size() != 0)
    {
        auto x = pq.top();
        pq.pop();
        if (setMST[x.second] == false)
        {
            Min = x.first;
            next_node = x.second;
            return;
        }
    }
}

void MSThelper(ll u, vector<bool> &setMST, vector<ll> &Weights, vector<vector<pair<ll, ll>>> &Graph, ll &result, priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> &pq)
{
    if (setMST[u] == true) 

        return;
    setMST[u] = true;
    for (auto x : Graph[u])
    {
        ll v, w;
        v = x.first, w = x.second;
        if (setMST[v] == false) 

        {
            if (Weights[v] > w)
                pq.push({w, v});
        }
    }
    ll Min = LONG_LONG_MAX, next_node = -1;
    selectMinVertex(Min, next_node, Weights, setMST, pq);
    

    if (Min == LONG_LONG_MAX)
        return;
    result += Min;
    MSThelper(next_node, setMST, Weights, Graph, result, pq);
}

ll MST(vector<vector<pair<ll, ll>>> &Graph)
{
    vector<ll> Weights(Graph.size(), LONG_LONG_MAX);
    Weights[0] = 0;
    vector<bool> setMST(Graph.size(), false);
    ll result = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (ll i = 0; i < Graph.size(); i++)
        pq.push({Weights[i], i});
    MSThelper(0, setMST, Weights, Graph, result, pq);
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

void DFS(ll u, vector<ll> &Parent, vector<ll> &Height, vector<vector<ll>> &Tree)
{
    for (auto v : Tree[u])
    {
        if (Parent[u] != v)
        {
            Parent[v] = u;
            Height[v] = Height[u] + 1;
            DFS(v, Parent, Height, Tree);
        }
    }
}

bool DFSChecker(ll u, ll &blockCount, vector<bool> &Blocked, vector<ll> &Parent, vector<vector<ll>> &Tree)
{
    

    if (u != 0 && Tree[u].size() == 1)
        return true;
    

    for (auto v : Tree[u])
    {
        if (v == Parent[u])
            continue;
        

        if (Blocked[v] == false)
        {
            bool tempResult = DFSChecker(v, blockCount, Blocked, Parent, Tree);
            if (tempResult == true)
                return true;
        }
        if (Blocked[v] == true)
        {
            blockCount++;
        }
    }
    return false;
}

bool comparator(pair<ll, ll> &A, pair<ll, ll> &B)
{
    if (A.second < B.second)
        return true;
    return false;
}

ll solve(vector<ll> &A, vector<ll> &B)
{
    ll N = A.size(), M = B.size(), ans = 0;
    vector<ll> Prefix(M, 0);
    map<ll, ll> myMap;
    for (auto x : A)
        myMap[x]++;
    for (ll i = 0; i < M; i++)
    {
        if (myMap.find(B[i]) != myMap.end())
            Prefix[i]++;
        if (i != 0)
            Prefix[i] += Prefix[i - 1];
    }
    for (ll i = 0; i < M; i++)
    {
        ll boxes = upper_bound(A.begin(), A.end(), B[i]) - A.begin();
        ll left_B = B[i] - boxes + 1;
        

        ll index3 = lower_bound(B.begin(), B.end(), left_B) - B.begin();
        ll temp = i - index3 + 1 + (Prefix[M - 1] - Prefix[i]);
        ans = max(ans, temp);
    }
    if (M > 0)
        ans = max(ans, Prefix[M - 1]);
    return ans;
}

void rangeUpdate(ll index, ll low, ll high, ll l, ll r, ll val, vector<ll> &segmentTree, vector<ll> &lazy)
{
    if (lazy[index] != -1) 

    {
        if (segmentTree[index] == -1)
            segmentTree[index] = lazy[index];
        else
            segmentTree[index] = (segmentTree[index] & lazy[index]);
        if (low != high)
        {
            lazy[2 * index + 1] = lazy[2 * index + 1] == -1 ? lazy[index] : (lazy[2 * index + 1] & lazy[index]);
            lazy[2 * index + 2] = lazy[2 * index + 2] == -1 ? lazy[index] : (lazy[2 * index + 2] & lazy[index]);
        }
        lazy[index] = -1;
    }
    

    if (r < low || l > high)
        return;
    if (l <= low && high <= r) 

    {
        if (segmentTree[index] != -1)
            segmentTree[index] = (segmentTree[index] & val);
        else
            segmentTree[index] = val;
        if (low != high) 

        {
            ll left = 2 * index + 1, right = 2 * index + 2;
            lazy[left] = lazy[left] == -1 ? val : (lazy[left] & val);
            lazy[right] = lazy[right] == -1 ? val : (lazy[right] & val);
        }
        return;
    }
    ll mid = low + (high - low) / 2;
    

    rangeUpdate(2 * index + 1, low, mid, l, r, val, segmentTree, lazy);
    rangeUpdate(2 * index + 2, mid + 1, high, l, r, val, segmentTree, lazy);
    segmentTree[index] = (segmentTree[2 * index + 1] & segmentTree[2 * index + 2]);
}

ll queryLazy(ll index, ll low, ll high, ll item, vector<ll> &segmentTree, vector<ll> &lazy)
{
    if (lazy[index] != -1) 

    {
        if (segmentTree[index] == -1)
            segmentTree[index] = lazy[index];
        else
            segmentTree[index] = (segmentTree[index] & lazy[index]);
        if (low != high)
        {
            lazy[2 * index + 1] = lazy[2 * index + 1] == -1 ? lazy[index] : (lazy[2 * index + 1] & lazy[index]);
            lazy[2 * index + 2] = lazy[2 * index + 2] == -1 ? lazy[index] : (lazy[2 * index + 2] & lazy[index]);
        }
        lazy[index] = -1;
    }
    

    if (item < low || item > high)
        return -1;
    if (low == high && low == item)
        return segmentTree[index];
    ll mid = low + (high - low) / 2;
    ll left = queryLazy(2 * index + 1, low, mid, item, segmentTree, lazy);
    ll right = queryLazy(2 * index + 2, mid + 1, high, item, segmentTree, lazy);
    if (left == -1)
        return right;
    if (right == -1)
        return left;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (ll t = 0; t < T; t++)
    {
        cin >> N >> K;
        vector<ll> A(K);
        for (ll i = 0; i < K; i++)
        {
            cin >> A[i];
            A[i]--;
        }
        vector<vector<ll>> Tree(N);
        for (ll i = 0; i < N - 1; i++)
        {
            ll u, v;
            cin >> u >> v;
            u--, v--;
            Tree[u].push_back(v);
            Tree[v].push_back(u);
        }
        ll maxN = log(N);
        vector<ll> Parent(N, -1), Height(N, 1);
        vector<vector<ll>> LCA(N, vector<ll>(maxN + 1, -1));
        DFS(0, Parent, Height, Tree);
        for (ll i = 0; i < N; i++)
            LCA[i][0] = Parent[i];
        

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
        vector<bool> Blocked(N, false); 

        for (ll i = 0; i < K; i++)
        {
            ll x = Height[A[i]];
            ll times = (x - 1) / 2;
            

            ll node = A[i];
            Blocked[node] = true;
            for (ll x = 0; x <= maxN; x++)
            {
                if ((times & (one << x)) != 0)
                {
                    node = LCA[node][x];
                    if (node != -1)
                        Blocked[node] = true;
                }
            }
            

            

            

            

            

            if (node != -1)
                Blocked[node] = true;
        }
        if (Blocked[0] == true)
        {
            cout << 1 << "\n";
            continue;
        }
        ll blockCount = 0;
        bool temp = DFSChecker(0, blockCount, Blocked, Parent, Tree);
        if (temp == false)
            cout << blockCount << "\n";
        else
            cout << -1 << "\n";
    }
    return 0;
}















