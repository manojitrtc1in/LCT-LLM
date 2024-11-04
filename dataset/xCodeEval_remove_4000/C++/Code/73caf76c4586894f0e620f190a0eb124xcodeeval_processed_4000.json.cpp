




































  int T;         \
  std::cin >> T; \
  while (T--)









using ll = int64_t;
using ull = uint64_t;
using pii = std::pair<int, int>;
using tiii = std::tuple<int, int, int>;


using namespace std::string_literals;


















































































































































































































































































































































































































































void solution() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  std::vector<int> preMin(n + 1, 1e9 + 7);
  for (int i = 1; i <= n; ++i) preMin[i] = std::min(preMin[i - 1], a[i]);
  std::set<int, std::less<int>> head0, head;
  for (int i = 1; i <= n; ++i)
    if (preMin[i] < preMin[i - 1]) head0.insert(i);
  for (int i = 1; i <= n; ++i)
    if (head.empty() || a[i] < a[*head.rbegin()]) head.insert(i);
  assert(head0 == head);
  std::cerr << "array: ";
  for (int i = 1; i <= n; ++i) std::cerr << a[i] << " \n"[i == n];
  std::cerr << "preMin: ";
  for (int i = 1; i <= n; ++i) std::cerr << preMin[i] << " \n"[i == n];
  std::cerr << "heads: ";
  for (auto h : head) std::cerr << h << " \n"[h == *head.rbegin()];

  std::vector<int> ans(m + 1);
  for (int i = 1; i <= m; ++i) {
    int k, d;
    std::cin >> k >> d;
    a[k] -= d;
    if (a[k] < 0) a[k] = 0;
    auto brute = [&]() {
      int ans = 0;
      for (int j = 1; j <= n; ++j) {
        int k = j;
        while (k + 1 <= n && a[k + 1] >= a[j]) ++k;
        ++ans;
        j = k;
      }
      return ans;
    };
    auto std = [&]() {
      auto it = head.upper_bound(k);
      if (it != head.begin()) {
        it = std::prev(it);
        if (a[k] < a[*it]) head.insert(k);
        if (*it == k) assert(head.count(k));
      } else {
        head.insert(k);
      }
      while (true) {
        it = head.upper_bound(k);
        if (it == head.end()) break;
        if (a[*it] >= a[k])
          head.erase(it);
        else
          break;
      }
      return int(head.size());
    };
    

    

    ans[i] = (1ll * n * m < 1ll * 50000 * 50000) ? brute() : std();
  }
  for (int i = 1; i <= m; ++i) std::cout << ans[i] << " \n"[i == m];
}



signed main() {

  logs(std::string_view(__FILE__).substr(
      std::string_view(__FILE__).rfind("\\") + 1));
  freopen("testdata.in", "r", stdin);
  



  freopen("testdata.log", "w", stderr);

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  MT solution();

  std::clog << "\ntime: " << std::fixed << std::setprecision(3)
            << clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";

}








