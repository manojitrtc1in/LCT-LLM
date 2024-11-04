
using namespace std;
typedef long long int ll;

ll T;
ll N, M, K;
ll one = 1;
ll modulo = 1000000007;
map<ll, ll> myMap;
vector<bool> Prime(3 * 1e6, true);
map<ll, ll> id2, Opposite;
vector<ll> id12(3 * 1e6, 1);
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
                id12[j] = j / i;
            Prime[j] = false;
        }
    }
    ll times = 1;
    for (ll i = 2; i < Prime.size(); i++)
    {
        if (Prime[i] == true)
        {
            id2[i] = times;
            Opposite[times] = i;
            times++;
        }
    }
}
set<ll> id5(ll Num)
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


ll mpow(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    ll x = mpow(a, b / 2, mod);
    x = (x * x) % mod;
    

    if (b % 2)
    {
        x = (x * a) % mod;
        

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
    bool id3 = true;
    for (auto v : Graph[u])
    {
        if (v != prev)
        {
            Centroid(v, u, centroid, sz, Graph);
            if (sz[v] > N / 2)
                id3 = false;
            sz[u] += sz[v];
        }
    }
    if (N - sz[u] > N / 2)
        id3 = false;
    if (id3)
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

bool id1(pair<ll, ll> i, pair<ll, ll> j)
{
    if (i.second < j.second)
        return true;
    return false;
}

bool id4(pair<ll, ll> i, pair<ll, ll> j)
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



void id9(ll &Min, ll &next_node, vector<ll> &Weights, vector<bool> &id10, priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> &pq)
{
    while (pq.size() != 0)
    {
        auto x = pq.top();
        pq.pop();
        if (id10[x.second] == false)
        {
            Min = x.first;
            next_node = x.second;
            return;
        }
    }
}

void id7(ll u, vector<bool> &id10, vector<ll> &Weights, vector<vector<pair<ll, ll>>> &Graph, ll &result, priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> &pq)
{
    if (id10[u] == true) 

        return;
    id10[u] = true;
    for (auto x : Graph[u])
    {
        ll v, w;
        v = x.first, w = x.second;
        if (id10[v] == false) 

        {
            if (Weights[v] > w)
                pq.push({w, v});
        }
    }
    ll Min = id6, next_node = -1;
    id9(Min, next_node, Weights, id10, pq);
    

    if (Min == id6)
        return;
    result += Min;
    id7(next_node, id10, Weights, Graph, result, pq);
}

ll MST(vector<vector<pair<ll, ll>>> &Graph)
{
    vector<ll> Weights(Graph.size(), id6);
    Weights[0] = 0;
    vector<bool> id10(Graph.size(), false);
    ll result = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (ll i = 0; i < Graph.size(); i++)
        pq.push({Weights[i], i});
    id7(0, id10, Weights, Graph, result, pq);
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

bool comparator(pair<ll, ll> &A, pair<ll, ll> &B)
{
    if (A.second < B.second)
        return true;
    return false;
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


void id11(ll N, ll maxN, vector<vector<ll>> &LCA)
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

ll id8(ll node, ll J, ll maxN, vector<vector<ll>> &LCA)
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



ll nCr(ll n, ll r, ll mod)
{
    if (r > n - r)
        r = n - r;
    ll a = 1, b = 1;
    

    for (ll i = r; i > 0; i--)
    {
        a = (a * n) % mod;
        b = (b * r) % mod;
        n--, r--;
    }
    

    b = mpow(b, mod - 2, mod);
    a = ((a % mod) * (b % mod)) % mod;
    return a % mod;
}

bool check(ll num, ll N, ll S)
{
    ll temp = 0;
    ll count = 0;
    while (num > 0 && count < N)
    {
        count++;
        temp += num;
        if (num == 1)
            break;
        num = num / 2 + num % 2;
    }
    

    

    ll remaining = N - count;
    if (remaining > 0)
        temp += remaining;
    if (temp <= S)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    


    ll N, D;
    cin >> N >> D;
    vector<ll> Rank(N, 0), Size(N, 1), Parent(N, -1);
    for (ll i = 0; i < N; i++)
        Parent[i] = i;
    ll ans = 0;
    ll extraConnections = 0;
    for (ll i = 0; i < D; i++)
    {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        

        bool extra = Union(x, y, Size, Parent, Rank);
        if (extra == true)
            extraConnections++;
        set<ll> uniqueParent;
        vector<ll> OurList; 

        priority_queue<ll> xyz;
        for (ll i = 0; i < N; i++)
        {
            ll par = Parent[i];
            if (par == i)
            {
                uniqueParent.insert(par);
                OurList.push_back(-Size[par]);
                xyz.push(Size[par]);
            }
        }
        

        ans = 0;
        ll len = min(extraConnections + 1, ll(xyz.size()));
        for (ll j = 0; j < len; j++)
        {
            

            ll temp = xyz.top();
            xyz.pop();
            ans += temp;
        }
        

        ans -= 1;
        ans = min(ans, N - 1);
        ans = max(ans, 0ll);
        cout << ans << "\n";
    }
    return 0;
}















