












using namespace std;



const int MOD = 1000000007;

void modify(vector<int>& t, int n, int p, int value) {  

  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(vector<int>& t, int n, int l, int r) {  

  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}



void solve() {
  int n, m; cin >> n >> m;
  string str; cin >> str;
  vector<int> ans(n * m);
  vector<int> t(2 * m);
  for (int i = 0; i < n * m; ++i) {
    if (str[i] == '1') modify(t, m, i % m, 1);
    ans[i] = query(t, m, 0, m);
  }
  t = vector<int>(m);
  int first = -1, len0 = 0;
  for (int i = 0; i < n * m; ++i) {
    if (str[i] == '0' && first < 0) continue;
    else if (str[i] == '1' && first < 0) first = i;
    if (str[i] == '0') ++len0;
    else len0 = 0;
    if (len0 >= m) ++t[(i - m + 1 - first) % m];
    int dist = i - first;
    int rows = dist / m + 1;
    rows -= t[(dist + 1) % m];
    ans[i] += rows;
  }

  for (int num : ans) cout << num << ' ';
  cout << '\n';
}

int main() {
  

  

  int t; cin >> t;
  for (int i = 0; i < t; ++i) solve();


  return 0;
}
