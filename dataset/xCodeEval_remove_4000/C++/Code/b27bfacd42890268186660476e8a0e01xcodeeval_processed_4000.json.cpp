







using namespace __gnu_pbds;

using namespace std;
typedef long long int ll;






ll T;
ll N, M, K;
ll one = 1;
ll modulo = 1000000007;
map<ll, ll> myMap;
vector<bool> Prime(3 * 1e6, true);
map<ll, ll> id3, Opposite;
vector<int> id16(3 * 1e6, 1);

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
                id16[j] = j / i;
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

set<ll> id7(ll Num)
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
    bool id4 = true;
    for (auto v : Graph[u])
    {
        if (v != prev)
        {
            Centroid(v, u, centroid, sz, Graph);
            if (sz[v] > N / 2)
                id4 = false;
            sz[u] += sz[v];
        }
    }
    if (N - sz[u] > N / 2)
        id4 = false;
    if (id4)
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

bool id1(pair<ll, ll> i, pair<ll, ll> j)
{
    if (i.second < j.second)
        return true;
    return false;
}

bool id5(pair<ll, ll> i, pair<ll, ll> j)
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



void id11(ll &Min, ll &next_node, vector<ll> &Weights, vector<bool> &id12, priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> &pq)
{
    while (pq.size() != 0)
    {
        auto x = pq.top();
        pq.pop();
        if (id12[x.second] == false)
        {
            Min = x.first;
            next_node = x.second;
            return;
        }
    }
}

void id9(ll u, vector<bool> &id12, vector<ll> &Weights, vector<vector<pair<ll, ll>>> &Graph, ll &result, priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> &pq)
{
    if (id12[u] == true) 

        return;
    id12[u] = true;
    for (auto x : Graph[u])
    {
        ll v, w;
        v = x.first, w = x.second;
        if (id12[v] == false) 

        {
            if (Weights[v] > w)
                pq.push({w, v});
        }
    }
    ll Min = id8, next_node = -1;
    id11(Min, next_node, Weights, id12, pq);
    

    if (Min == id8)
        return;
    result += Min;
    id9(next_node, id12, Weights, Graph, result, pq);
}

ll MST(vector<vector<pair<ll, ll>>> &Graph)
{
    vector<ll> Weights(Graph.size(), id8);
    Weights[0] = 0;
    vector<bool> id12(Graph.size(), false);
    ll result = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (ll i = 0; i < Graph.size(); i++)
        pq.push({Weights[i], i});
    id9(0, id12, Weights, Graph, result, pq);
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

bool DFS(ll u, vector<ll> &Parent, vector<bool> &Cycle, vector<vector<ll>> &Tree)
{
    for (auto v : Tree[u])
    {
        if (Parent[u] == v)
            continue;
        

        if (Parent[v] == -1)
        {
            Parent[v] = u;
            bool temp = DFS(v, Parent, Cycle, Tree);
            if (temp == true)
                return true;
        }
        

        else if (Parent[v] != -1)
        {
            

            ll parent = u;
            while (parent != v)
            {
                Cycle[parent] = true;
                parent = Parent[parent];
            }
            Cycle[v] = true;
            return true;
        }
    }
    return false;
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


void id14(ll N, ll maxN, vector<vector<ll>> &LCA)
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

ll id10(ll node, ll J, ll maxN, vector<vector<ll>> &LCA)
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

ll id15(ll n, ll r, ll mod)
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




ll id13(ll u, vector<ll> &visited, vector<vector<ll>> &Tree)
{
    ll id6 = u;
    for (auto v : Tree[u])
    {
        

        if (visited[v] == -1)
        {
            visited[v] = visited[u] + 1;
            ll temp = id13(v, visited, Tree);
            if (visited[id6] <= visited[temp])
                id6 = temp;
        }
    }
    return id6;
}

ll Diameter(vector<vector<ll>> &Tree)
{
    ll N = Tree.size();
    vector<ll> visited(N, -1);
    visited[0] = 0;
    ll oneEnd = id13(0, visited, Tree);
    visited = vector<ll>(N, -1);
    visited[oneEnd] = 0;
    ll otherEnd = id13(oneEnd, visited, Tree);
    

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

ll solve(string &S, ll k)
{
    ll mod = 998244353;
    ll cnt = 0;
    ll j = 0, i = 0, ans = 0;
    for (i = 0; i < S.size(); i++)
    {
        if (S[i] != '1')
            continue;
        cnt++;
        if (cnt > k)
        {
            ans = (ans + id15(i - j, k, mod)) % mod;
            while (cnt > k)
            {
                if (S[j] == '1')
                    cnt--;
                j++;
            }
        }
    }
    if (cnt == k)
        ans = (ans + id15(i - j, k, mod)) % mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    T = 1;
    for (ll t = 0; t < T; t++)
    {
        ll mod = 998244353;
        ll n;
        cin >> n;
        ll k;
        cin >> k;
        string S;
        cin >> S;

        init_fact();
        ll cnt = 0;
        for (ll i = 0; i < S.size(); i++)
            if (S[i] == '1')
                cnt++;
        if (!k || cnt < k)
        {
            cout << "1\n";
            continue;
        }
        ll ans = solve(S, k);

        while (S.size())
        {
            if (S.back() == '1')
            {
                S.pop_back();
                break;
            }
            S.pop_back();
        }
        reverse(S.begin(), S.end());
        while (S.size())
        {
            if (S.back() == '1')
            {
                S.pop_back();
                break;
            }
            S.pop_back();
        }
        reverse(S.begin(), S.end());
        ll temp = solve(S, k - 1);
        ans = (ans - temp + mod) % mod;
        cout << ans << "\n";
    }
    return 0;
}














