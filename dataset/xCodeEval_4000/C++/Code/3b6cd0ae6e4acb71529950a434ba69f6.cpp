








#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const LL mod = 1e9 + 7;
#define printb(x) \
  if ((bool)x) printf("YES"); \
  else printf("NO");
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define MX 105

int a[MX];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a, a + n);
  int i = 0;
  while (i < n && a[i] == a[0]) ++i;
  cout << n - i << endl;
}

int main() {
  int T = 1;
  cin >> T;
  while (T--)
    solve();
  return 0;
}

