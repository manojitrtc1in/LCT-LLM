









using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const LL mod = 1e9 + 7;

  if ((bool)x)                                                                 \
    printf("YES");                                                             \
  else                                                                         \
    printf("NO");





namespace IO {
char in[1 << 21]; 

char const *o;

void init_in() {
  o = in;
  in[fread(in, 1, sizeof(in) - 4, stdin)] = 0; 

}

int readInt() {
  unsigned u = 0, s = 0;

  while (*o && *o <= 32)
    ++o; 


  if (*o == '-')
    s = ~s, ++o;
  else if (*o == '+')
    ++o; 


  while (*o >= '0' && *o <= '9')
    u = (u << 3) + (u << 1) + (*o++ - '0'); 


  return static_cast<int>((u ^ s) + !!s);
}
} 



void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(begin(a), end(a));
  LL ans = 0, sum = 0;
  for (int i = 2; i < n; ++i) {
    ans += 1ll * (i - 1) * a[i] - sum;
    sum += a[i - 1];
  }
  cout << -ans << endl;
}

int main() {
  int T = 1;
  cin >> T;
  while (T--)
    solve();
  return 0;
}


