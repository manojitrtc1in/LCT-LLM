





































typedef long long ll;
typedef long double ld;
using namespace std;


using namespace __gnu_pbds;
typedef  tree<pair<ll,ll>, null_type, less_equal<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

double epsilon=(double)1e-9;
const double id1=1e-8;
const double id2=1e-12;
const int N  = int(2e5) + 11;
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
   cin >> n;
   vector<vector<int>> r(n, vector<int>(5));
   vector<vector<int>> arr[32];
   vector<vector<int>> mark(32, vector<int>(n, -1));
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 5; ++j) {
         cin >> r[i][j];
      }
   }
   int winner = 0;
   for (int i = 1; i < n; ++i) {
      int cnt{};
      for (int j = 0; j < 5; ++j) {
         if (r[i][j] < r[winner][j]) {
            ++cnt;
         }
      }
      if (cnt >= 3) winner = i;
   }
   for (int i = 0; i < n; ++i) {
      if (i == winner) continue;
      int cnt{};
      for (int j = 0; j < 5; ++j) {
         if (r[winner][j] < r[i][j]) {
            ++cnt;
         }
      }
      if (cnt < 3) {
         cout << -1 << "\n";
         return;
      }
   }
   cout << winner + 1 << "\n";
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
