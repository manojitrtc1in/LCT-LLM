





































typedef long long ll;
typedef long double ld;
using namespace std;


using namespace __gnu_pbds;
typedef  tree<pair<ll,ll>, null_type, less_equal<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

double epsilon=(double)1e-9;
const double id1=1e-8;
const double id2=1e-12;
const int N  = int(2e5);
const ll INF = id0;
const int K  = 30;



const double pi = acos(-1);








































































































































































































































void build(vl& t, int n) {
   for (int i = n - 1; i > 0; --i) {
      t[i] = max(t[i << 1],  t[i << 1 | 1]);
   }
}

void update(vl& t, ll p, ll value, int n) {
   for (t[p += n] = value; p > 1; p >>= 1) {
      t[p >> 1] = max(t[p],  t[p ^ 1]);
   }
}

ll query(vl& t, int l, int r, int n) {  

  ll res = 0LL;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = max(res, t[l++]);
    if (r & 1) res = max(res, t[--r]);
  }
  return res;
}
















































































































































































































































































































































































































































































void solve() {
   int n{};
   int m{};
   cin >> n >> m;
   vi d(n + 1, -1);
   vi ans(n + 1);
   vb vis(n + 1, false);
   vi g[n + 1];
   vi arr[n + 1];

   for (int i = 0; i < m; ++i) {
      int u{};
      int v{};
      cin >> u >> v;
      g[u].eb(v);
   }
   int depth{};
   queue<int> q{};
   q.push(1);
   d[1] = 0;
   while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v: g[u]) {
         if (d[v] == -1) {
            d[v] = d[u] + 1;
            depth = max(d[v], depth); 
            arr[d[v]].eb(v);
            q.push(v);
         }
      }
   }
   for (int i = 1; i <= n; ++i) ans[i] = d[i];
   for (int dis = depth; dis >= 0; --dis) {
      

      for (int u: arr[dis]) {
         for (int v: g[u]) {
            if (d[u] >= d[v]) {
               ans[u] = min(ans[u], d[v]);
            } else {
               ans[u] = min(ans[u], ans[v]);
            }
         }
      }
   }
   for (int i = 1; i <= n; ++i) {
      cout << ans[i] << " \n"[i == n];
   }
}



int main(){
   

   

   

   


   ios_base::sync_with_stdio(0);  
   cin.tie(nullptr);
   
   

   

   

   

   

   int t = 1;
   cin >> t;
   for (int i = 0; i < t; ++i) {
      

      solve();
   } 
}
