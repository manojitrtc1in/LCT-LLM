












using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const LL mod = 1e9 + 7;

  if ((bool)x) printf("YES"); \
  else printf("NO");




int query(int l, int r) {
  cout << "? " << l << ' ' << r << endl;
  fflush(stdout);
  int ret;
  cin >> ret;
  return ret;
}

void solve() {
  int n, t, k;
  cin >> n >> t >> k;
  if (n == 1) {
    cout << "! 1" << endl;
    return;
  }
  int l = 0, r = n;
  while (l + 1 < r) {
    int mid = l + (r - l) / 2;
    if (mid - query(1, mid) < k) l = mid;
    else r = mid;
  }
  cout << "! " << r << endl;
}

int main() {
  int T = 1;
  
  while (T--)
    solve();
  return 0;
}


