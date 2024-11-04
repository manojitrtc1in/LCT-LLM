#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>


using namespace __gnu_pbds;
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set    tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update>


#define fo(i,n)        for (int i=0;i<n;i++)
#define fo1(i, n)      for (int i = 1; i < n; i++)
#define MAX(a,b)       (a>b) ? a : b
#define MIN(a,b)       (a>b) ? b : a
#define fi             first
#define se             second
#define pb             push_back
#define mp             make_pair
#define all(v)         v.begin(), v.end()
#define uniq(v)        v.resize(unique(all(v)) - v.begin())
#define sz(v)          (long long)v.size()
#define pii            pair<int, int>

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



int n,  m, y, e, t, k, q, u1, u2,  w, c, d, x, mx_ind;



void solve() {
  cin >> n >> m;
  int store[1005][1005];
  int vis[1005][1005];
  fo(i, n) {
    fo(j, m) {
      cin >> store[i][j];
      vis[i][j] = 0;
    }
  }
  queue<array<int, 3>> q;
  

  fo(i, n) {
    fo(j, m) {
      if (i + 1 < n && j + 1 < m) {
        if (store[i][j] == store[i + 1][j] && store[i][j] == store[i][j + 1] && store[i][j] == store[i + 1][j + 1]) {
          q.push({i, j, store[i][j]});
          vis[i][j] = 1; vis[i + 1][j] = 1;
          vis[i][j + 1] = 1; vis[i + 1][j + 1] = 1;
          

        }
      }
    }
  }
  vector<array<int, 3>> ans;
  int mov[8][4][2] = {
    {{0, -1}, { -1, -1}, { -1, 0}, {0, 0}},
    {{ -1, 0}, { -1, 1}, {0, 0}, {0, 1}},
    {{ -1, 1}, { -1, 2}, {0, 2}, {0, 1}},
    {{0, 2}, {1, 2}, {0, 1}, {1, 1}},
    {{1, 2}, {2, 2}, {2, 1}, {1, 1}},
    {{2, 1}, {2, 0}, {1, 0}, {1, 1}},
    {{2, 0}, {2, -1}, {1, -1}, {1, 0}},
    {{0, -1}, {1, -1}, {0, 0}, {1, 0}}
  };
  int strt[8][2] = {
    { -1, -1},
    { -1, 0},
    { -1, 1},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1}
  };
  while (!q.empty()) {
    auto v = q.front();
    

    q.pop();
    ans.pb({v[0] + 1, v[1] + 1, v[2]});
    int x = v[0], y = v[1];
    fo(l, 8) {
      int np = 0;
      fo(i, 4) {
        int nx = x + mov[l][i][0], ny = y + mov[l][i][1];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) np = 1;
      }
      

      if (!np) {
        set<int> col;
        fo(i, 4) {
          int nx = x + mov[l][i][0], ny = y + mov[l][i][1];
          if (!vis[nx][ny]) col.insert(store[nx][ny]);
        }
        


        int sze = sz(col);
        if (sze != 1) continue;
        else {
          int sx = x + strt[l][0], sy = y + strt[l][1];
          

          

          

          q.push({sx, sy, *col.begin()});
          

          

          fo(i, 4) {
            int nx = x + mov[l][i][0], ny = y + mov[l][i][1];
            vis[nx][ny] = 1;
          }

        }
      }
    }
  }
  

  fo(i, n) {
    fo(j, m) {
      if (!vis[i][j]) {
        cout << -1 << endl;
        return;
      }
    }
  }
  reverse(all(ans));
  cout << sz(ans) << endl;
  for (auto it : ans) {
    cout << it[0] << " " << it[1] << " " << it[2] << "\n";
  }
  return;
}

signed main()
{ tezi
# ifndef ONLINE_JUDGE
  

  freopen("input.txt", "r", stdin);
  

  freopen("output.txt", "w", stdout);
  

  freopen("Errors.txt", "w", stderr);
# endif
  

  t = 1;
  fo(i, t) solve();
  return 0;
}


