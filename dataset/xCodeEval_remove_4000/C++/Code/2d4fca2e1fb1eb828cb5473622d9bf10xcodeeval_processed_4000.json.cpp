





































typedef long long ll;
typedef long double ld;
using namespace std;


using namespace __gnu_pbds;
typedef  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

double epsilon=(double)1e-9;
const double id4=1e-8;
const double id6=1e-12;
const int N  = int(2e5) + 11;
const ll INF = id3;
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
   int id5{};
   int id0{};
   cin >> n >> m1 >> m2;
   vi id1(n + 1);
   vi id2(n + 1);
   set<int> row[n + 1];
   set<int> col[n + 1];
   set<pair<int, int>> rows{};
   map<int, int> dp[n + 1];
   vp ans{};
   iota(all(id1), 0);
   iota(all(id2), 0);
   for (int i = 0, u, v; i < m1; ++i) {
      cin >> u >> v;
      int p = Find(id1, u);
      int q = Find(id1, v);
      id1[p] = q;
   }
   for (int i = 0, u, v; i < m2; ++i) {
      cin >> u >> v;
      int p = Find(id2, u);
      int q = Find(id2, v);
      id2[p] = q; 
   }
   if (m1 < m2) {
      swap(id1, id2);
   }
   for (int i = 1; i <= n; ++i) {
      int p1 = Find(id1, i);
      int p2 = Find(id2, i);
      dp[p1][p2] = i;
      row[p1].insert(p2);
      col[p2].insert(p1);
   }
   for (int i = 1; i <= n; ++i) {
      if (Find(id1, i) == i) {
         rows.insert(mkp(-row[i].size(), i));
      }
   }
   auto merge_rows = [&](int x, int y) {
      set<int>::iterator it;
      for (it = row[y].begin(); it != row[y].end(); ++it) {
         int c = *it;
         dp[x][c] = dp[y][c];
         row[x].insert(c);
         col[c].erase(y);
         col[c].insert(x);
      }
   };
   auto merge_cols = [&](int x, int y) {
      set<int>::iterator it;
      for (it = col[y].begin(); it != col[y].end(); ++it) {
         int r = *it;
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
