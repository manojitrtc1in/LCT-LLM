#include <bits/stdc++.h>
#define pb push_back
#define mod 1000000007
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define np next_permutation
#define lp(i,n) for(int i = 0; i < n; i++)
#define lps(i,j,n) for(int i = j; i < n; i++)
#define vii vector<vi>
#define vb vector<bool>
#define pr pair<int,int>
#define vl vector<ll>
#define vs vector<string>
#define us unordered_map<int, int>
#define Mpq priority_queue<int>
#define mpq priority_queue<int,vi,greater<int>> 
#define eb emplace_back
#define pr pair<int,int>
#define prl pair<ll,ll>
#define vp vector<pr>
#define vpl vector<prl>
#define mkp make_pair
#define vi vector<int>
#define vii vector<vi>
#define Max(a,b) a=max(a,b)
#define Min(a,b) a=min(a,b)
#define ull unsigned long long
#define prr pair<ll,int>
#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
typedef long long ll;
typedef long double ld;
using namespace std;
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

double epsilon=(double)1e-9;
const double errorEpsilon=1e-8;
const double relErrorEpsilon=1e-12;
const int N  = int(2e5) + 11;
const ll INF = INT64_MAX;
const int K  = 30;



const double pi = acos(-1);








































































































































































































































void build(vl& t, int n) {
   for (int i = n - 1; i > 0; --i) {
      t[i] = min(t[i << 1], t[i << 1 | 1]);
   }
}

void update(vl& t, ll p, ll value, int n) {
   for (t[p += n] = value; p > 1; p >>= 1) {
      t[p >> 1] = min(t[p],  t[p ^ 1]);
   }
}

ll query(vl& t, int l, int r, int n) {  

  ll res = INT_MAX;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = min(res, t[l++]);
    if (r & 1) res = min(res, t[--r]);
  }
  return res;
}


























































































































































































































































































































































int Find(vi& dsu, int u) {
   if (dsu[u] != u) 
      dsu[u] = Find(dsu, dsu[u]);
   return dsu[u];
}

void Union(vi &dsu, vi &sz, int u, int v, int& ncc) {
   u = Find(dsu, u), v = Find(dsu, v);
   if (u == v) return;
   if (sz[u] > sz[v]) swap(u, v);
   dsu[u] = v;
   sz[v] += sz[u];
   --ncc;
}

void solve() {
   int n{};
   int m1{};
   int m2{};
   int ncc1{};
   int ncc2{};
   cin >> n >> m1 >> m2;
   vi dsu1(n + 1);
   vi dsu2(n + 1);
   set<int> row[n + 1];
   set<int> col[n + 1];
   set<pair<int, int>> rows{};
   map<int, int> dp[n + 1];
   vp ans{};
   iota(all(dsu1), 0);
   iota(all(dsu2), 0);
   for (int i = 0, u, v; i < m1; ++i) {
      cin >> u >> v;
      int p = Find(dsu1, u);
      int q = Find(dsu1, v);
      dsu1[p] = q;
   }
   for (int i = 0, u, v; i < m2; ++i) {
      cin >> u >> v;
      int p = Find(dsu2, u);
      int q = Find(dsu2, v);
      dsu2[p] = q; 
   }
   if (m1 < m2) {
      swap(dsu1, dsu2);
   }
   for (int i = 1; i <= n; ++i) {
      int p1 = Find(dsu1, i);
      int p2 = Find(dsu2, i);
      dp[p1][p2] = i;
      row[p1].insert(p2);
      col[p2].insert(p1);
   }
   for (int i = 1; i <= n; ++i) {
      if (Find(dsu1, i) == i) {
         rows.insert(mkp(-row[i].size(), i));
      }
   }
   auto merge_rows = [&](int x, int y) {
      for (int c: row[y]) {
         dp[x][c] = dp[y][c];
         row[x].insert(c);
         col[c].erase(y);
         col[c].insert(x);
      }
   };
   auto merge_cols = [&](int x, int y) {
      for (int r: col[y]) {
         dp[r][x] = dp[r][y];
         col[x].insert(r);
         row[r].erase(y);
         row[r].insert(x);
      }
   };
   while (rows.size() > 1) {
      int x = rows.begin() -> S;
      rows.erase(rows.begin());
      int y = rows.begin() -> S;
      rows.erase(rows.begin());
      if (row[x].size() < row[y].size()) {
         swap(x, y);
      }
      auto it = row[x].begin(); 
      int a = *it;
      int b = *row[y].begin();
      if (a == b) {
         a = *(++it);
      }
      ans.eb(dp[x][a], dp[y][b]);
      if (col[a].size() < col[b].size()) {
         swap(a, b);
      }
      merge_rows(x, y);
      merge_cols(a, b);
      rows.insert(mkp(-row[x].size(), x));
   }
   cout << ans.size() << "\n";
   for (auto [x, y]: ans) cout << x << " " << y << "\n";
}

int main(){
   

   

   

   

 
   ios_base::sync_with_stdio(0);  
   cin.tie(nullptr);
   
   

   

   

   

   

   

   

   int t = 1;
   

   for (int i = 0; i < t; ++i) {
      

      solve();
   } 
}
