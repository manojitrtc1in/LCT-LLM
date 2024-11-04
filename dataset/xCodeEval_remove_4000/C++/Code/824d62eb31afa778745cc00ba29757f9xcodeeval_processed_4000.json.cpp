























 
using namespace std;
 



















 
const ll INF = 1000000000000000000LL;
 







 
void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) { cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}"; }
template <class T>
void _print(vector<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T>
void _print(set<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T>
void _print(multiset<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V>
void _print(map<T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }
 


bool id5(vector<int> &a, vector<int> &b) { return a[1] < b[1]; }
 


struct cmp
{
  bool operator()(const ll &a, const ll &b) { return a > b; }
};
 


ll bexp(ll a, ll b) { ll res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res; }
 


ll id0(ll a, ll b, ll mod) { ll res = 1; while (b > 0) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
 


const int P = 100001;
int prime[P + 1];
void sieve() { prime[0] = 0; prime[1] = 0; for (int i = 2; i <= P; i++) { prime[i] = 1; } for (int i = 2; i * i <= P; i++) { if (prime[i] == 1) { for (int j = i * i; j <= P; j += i) { prime[j] = 0; } } } }
 


ll factorised[P + 1];
void id9() { factorised[0] = 0; factorised[1] = 0; for (int i = 2; i <= P; i++) { factorised[i] = -1; } for (int i = 2; i <= P; i++) { if (factorised[i] == -1) { for (int j = i; j <= P; j += i) { if (factorised[j] == -1) { factorised[j] = i; } } } } }
 


ll id10(ll a, ll b, ll &x, ll &y) { if (b == 0) { x = 1; y = 0; return a; } ll x1, y1; ll d = id10(b, a % b, x1, y1); x = y1; y = x1 - y1 * (a / b); return d; }
 


ll modInverse(ll a, ll m) { ll x, y; ll g = id10(a, m, x, y); ll res = (x % m + m) % m; return res; }
 


ll C(ll n, ll k) { ll res = 1; if (k > n - k) k = n - k; for (int i = 0; i < k; ++i) { res *= (n - i); res /= (i + 1); } return res; }
 


ll CM(ll n, ll k, ll mod) { ll res = 1; if (k > n - k) k = n - k; for (int i = 0; i < k; ++i) { res = (res * (n - i)) % mod; res = (res * modInverse(i + 1, mod)) % mod; } return res % mod; }
 


ll factorial(ll n) { ll res = 1; for (int i = 2; i <= n; i++) res = res * i; return res; }
 


ll id1(ll n, ll m) { ll res = 1; for (int i = 2; i <= n; i++) res = ((res % m) * (i % m)) % m; return res % m; }
 


bool id14(ll n) { if (ceil((double)sqrt(n)) == floor((double)sqrt(n))) { return true; } else { return false; } }
 


vector<ll> id7(ll n) { vector<ll> v; F(2, sqrt(n), i) { if (n % i == 0) { v.push_back(i); v.push_back(n / i); } } if (id14(n) == 1) { v.push_back(sqrt(n)); } if (n != 1) { v.pb(n); } return v; }
 


ll phi1(ll n) { ll result = n; for (int i = 2; i * i <= n; i++) { if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } } if (n > 1) result -= result / n; return result; }
 


ll *phi2 = new ll[100001];
void id16() { for (int i = 1; i <= 100000; i++) { phi2[i] = i; } for (int i = 2; i <= 100000; i++) { if (phi2[i] == i) { phi2[i] = i - 1; for (int j = i * 2; j <= 100000; j += i) { phi2[j] = (phi2[j] * (i - 1)) / i; } } } }
 


void id2(ll mat1[R1][C1], ll mat2[R2][C2]) { ll rslt[R1][C2]; F(0, R1, i) { F(0, C2, j) { rslt[i][j] = 0; F(0, R2, k) { rslt[i][j] = (rslt[i][j] + (mat1[i][k] % MOD * mat2[k][j] % MOD) % MOD) % MOD; } } } F(0, R1, i) { F(0, C2, j) { mat1[i][j] = rslt[i][j]; } } }
 


void id4(ll a[R1][C1], ll m[R2][C2], ll n) { if (n == 0 || n == 1) { return; } id4(a, m, n / 2); id2(a, a); if (n % 2 == 1) { id2(a, m); } }
 


ll calculateMex(unordered_set<ll> Set) { ll Mex = 0; while (Set.find(Mex) != Set.end()) Mex++; return (Mex); }
 


ll id8(ll n) { if (n == 0) return 0; return (n & 1) + id8(n >> 1); }
 


void precision(int a) { cout << setprecision(a) << fixed << endl; }
 


vector<ll> adj[200001];
bool visited[200001];
ll level[200001];
ll par[200001];
 
void dfs(ll node, vector<ll> &vec) { visited[node] = true; vec.pb(node); for (auto x : adj[node]) { if (!visited[x]) { dfs(x, vec); } } }
 
void bfs(ll node) { queue<ll> q; q.push(node); level[node] = 0; visited[node] = true; while (!q.empty()) { ll k = q.front(); q.pop(); for (auto x : adj[k]) { if (!visited[x]) { q.push(x); visited[x] = true; level[x] = 1 + level[k]; par[x] = k; } } } }
 


 
ll parent[100001];
ll sizo[100001];
 
void Make(ll node) { parent[node] = node; sizo[node] = 1; }
 
ll Find(ll node) { if (parent[node] == node) return node; return parent[node] = Find(parent[node]); }
 
void Union(ll u, ll v) { u = Find(u); v = Find(v); if (u != v) { if (sizo[u] < sizo[v]) swap(u, v); parent[v] = u; sizo[u] += sizo[v]; } }
 


 
ll _gcd(ll a, ll b) { if (b == 0) return a; return _gcd(b, a % b); }
 


 


void buildTree(ll *arr, ll *tree, ll start, ll end, ll treeNode)
{
  

  if (start == end)
  {
    tree[treeNode] = arr[end];
    return;
  }
  ll mid = (start + end) >> 1;
  buildTree(arr, tree, start, mid, 2 * treeNode);
  buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);
  tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}
 
void updateTree(ll *arr, ll *tree, ll start, ll end, ll treeNode, ll idx, ll value)
{
  

  if (start == end)
  {
    arr[idx] = value;
    tree[treeNode] = arr[end];
    return;
  }
  ll mid = (start + end) >> 1;
  if (idx <= mid)
  {
    updateTree(arr, tree, start, mid, 2 * treeNode, idx, value);
  }
  else
  {
    updateTree(arr, tree, mid + 1, end, 2 * treeNode + 1, idx, value);
  }
  tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}
 
ll queryTree(ll *tree, ll start, ll end, ll treeNode, ll left, ll right)
{
  

  

  if (left <= start && right >= end)
  {
    

    return tree[treeNode];
  }
  else if (right < start || left > end)
  {
    

    return 0;
  }
  else
  {
    

    ll mid = (start + end) >> 1;
    return queryTree(tree, start, mid, 2 * treeNode, left, right) + queryTree(tree, mid + 1, end, 2 * treeNode + 1, left, right);
  }
}
 
void id12(ll *tree, ll *lazy, ll *arr, ll start, ll end, ll treeNode, ll left, ll right, ll increment)
{
  

  

  if (start > end)
  {
    return;
  }
  if (lazy[treeNode] != 0)
  {
    tree[treeNode] += (end - start + 1) * lazy[treeNode];
    if (start != end)
    {
      lazy[2 * treeNode] += lazy[treeNode];
      lazy[2 * treeNode + 1] += lazy[treeNode];
    }
    lazy[treeNode] = 0;
  }
  if (left <= start && right >= end)
  {
    

    tree[treeNode] += (end - start + 1) * increment;
    if (start != end)
    {
      lazy[2 * treeNode] += increment;
      lazy[2 * treeNode + 1] += increment;
    }
    return;
  }
  else if (right < start || left > end)
  {
    

    return;
  }
  else
  {
    

    ll mid = (start + end) >> 1;
    id12(tree, lazy, arr, start, mid, 2 * treeNode, left, right, increment);
    id12(tree, lazy, arr, mid + 1, end, 2 * treeNode + 1, left, right, increment);
    tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
  }
}
 
ll id6(ll *tree, ll *lazy, ll *arr, ll start, ll end, ll treeNode, ll left, ll right)
{
  

  

  if (start > end)
  {
    return 0;
  }
  if (lazy[treeNode] != 0)
  {
    tree[treeNode] += (end - start + 1) * lazy[treeNode];
    if (start != end)
    {
      lazy[2 * treeNode] += lazy[treeNode];
      lazy[2 * treeNode + 1] += lazy[treeNode];
    }
    lazy[treeNode] = 0;
  }
  if (left <= start && right >= end)
  {
    

    return tree[treeNode];
  }
  else if (right < start || left > end)
  {
    

    return 0;
  }
  else
  {
    

    ll mid = (start + end) >> 1;
    return id6(tree, lazy, arr, start, mid, 2 * treeNode, left, right) + id6(tree, lazy, arr, mid + 1, end, 2 * treeNode + 1, left, right);
  }
}
 


 


 
struct trieNode
{
  trieNode *left;
  trieNode *right;
};

void insert(ll n, trieNode *head) { trieNode *curr = head; for (int i = 31; i >= 0; i--) { ll b = (n >> i) & 1; if (b == 0) { if (!curr->left) { curr->left = new trieNode(); } curr = curr->left; } else { if (!curr->right) { curr->right = new trieNode(); } curr = curr->right; } } }

ll id3(trieNode *head, ll n) { ll value = n; trieNode *curr = head; ll id15 = 0; for (int j = 31; j >= 0; j--) { ll b = (n >> j) & 1; if (b == 0) { if (curr->right) { id15 += bexp(2, j); curr = curr->right; } else { curr = curr->left; } } else { if (curr->left) { id15 += bexp(2, j); curr = curr->left; } else { curr = curr->right; } } } return id15; }



 


 
ll up[200010][64];
ll lvl[200010];

void id11(ll src, ll par) { up[src][0] = par; F(1, 32, i) { if (up[src][i - 1] == -1) up[src][i] = -1; else up[src][i] = up[up[src][i - 1]][i - 1]; } for (auto child : adj[src]) { if (child != par) { id11(child, src); } } }

ll lift_node(ll node, ll id13) { FN(31, 0, i) { if (id13 == 0 || node == -1) { break; } if (id13 >= (1LL << i)) { id13 -= (1LL << i); node = up[node][i]; } } return node; }
 
ll lca(int u, int v) { if (lvl[u] < lvl[v]) { swap(u, v); } u = lift_node(u, lvl[u] - lvl[v]); if (u == v) return u; FN(31, 0, i) { if (up[u][i] != up[v][i]) { u = up[u][i]; v = up[v][i]; } } return lift_node(u, 1); }
 



ll interact(vector<ll> &k){
	cout << "? " << k[0] << ' ' << k[2] << endl;
	int x;
	cin >> x;
	if (x == 1)
	{
		cout << "? " << k[0] << ' ' << k[3] << endl;
		cin >> x;
		if (x == 1) return k[0];
		return k[3];
	}
	else if (x == 2)
	{
		cout << "? " << k[1] << ' ' << k[2] << endl;
		cin >> x;
		if (x == 1) return k[1];
		return k[2];
	}
	else
	{
		cout << "? " << k[1] << ' ' << k[3] << endl;
		cin >> x;
		if (x == 1) return k[1];
		return k[3];
	}
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  

  

  int t;
  t = 1;
  cin>>t;
  while(t--){
    ll n; cin>>n;
    ll ppl = bexp(2,n);
    vector<ll> v;
    F(1,ppl+1,i) v.pb(i);
    while(v.size()>2){
        vector<ll> newv;
		while (!v.empty())
		{
			vector<ll> k(4);
			k[0] = v.back();
			v.pop_back();
			k[1] = v.back();
			v.pop_back();
			k[2] = v.back();
			v.pop_back();
			k[3] = v.back();
			v.pop_back();
			int win = interact(k);
			newv.push_back(win);
		}
        v = newv;
    }
    if(v.size()==2){
		cout << "? " << v[0] << ' ' << v[1] << endl;
		int x;
		cin >> x;
		if (x == 2) v[0] = v[1];
    }
    cout << "! " << v[0] << endl;
  }
}