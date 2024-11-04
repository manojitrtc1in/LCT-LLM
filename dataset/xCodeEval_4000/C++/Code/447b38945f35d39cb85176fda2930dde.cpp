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
typedef  tree<pair<ll,ll>, null_type, less_equal<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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
