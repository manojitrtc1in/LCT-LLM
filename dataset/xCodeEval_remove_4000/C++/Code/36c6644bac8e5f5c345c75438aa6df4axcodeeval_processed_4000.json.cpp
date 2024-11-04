





using namespace __gnu_pbds;
using namespace std;























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

  

  freopen("input.txt", "r", stdin);
  

  freopen("output.txt", "w", stdout);
  

  freopen("Errors.txt", "w", stderr);

  

  t = 1;
  fo(i, t) solve();
  return 0;
}


