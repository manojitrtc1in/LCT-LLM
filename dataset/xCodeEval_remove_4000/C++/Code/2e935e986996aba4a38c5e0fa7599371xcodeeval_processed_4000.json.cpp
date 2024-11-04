





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



int n,  m, y, e, t, k, q, u1, u2,  w, c, d, x, ans;
const int mx = 400005, mod = 998244353, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;
vector<int> prime;
vector<int> spf(10000005, INF);
map<int, int> prime_factor;
vector<int> fact(1005, 1);

int setBit(int n) {
  int count = 0;
  while (n) {n = n & (n - 1); count += 1;}
  return count;
}

int fme(int a, int b) {
  int rest = 1;
  while (b) {
    if (b & 1) rest = ((int)1 * rest * a + mod) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return rest;
}

int modinv(int a) {return fme(a, mod - 2);}

int binomial(int n, int r) {return (fact[n] * modinv(fact[r]) % mod * modinv(fact[n - r]) % mod) % mod;} 


int btod(string s) {
  int len = s.length(), cur = 0, ind = 0;
  for (int i = (len - 1); i >= 0; i--) {
    if (s[i] == '1') cur += pow(2, ind);
    ind++;
  }
  return cur;
}

int id0(int a, int b) {
  if (b > a) swap(a, b);
  if (b == 0) {
    x = 1; y = 0;
    return a;
  }
  int gcd = id0(b, a % b);
  int lastx = x, lasty = y;
  x = lasty;
  y = lastx - (a / b) * lasty;
  return gcd;
}

void sieve(int mx) { 

  vector<int> v(mx, 1);
  v[0] = 0, v[1] = 0;
  for (int i = 2; i < mx; i++) {
    if (v[i]) {
      for (int j = i * i; j < mx; j += i) v[j] = 0;
    }
  }
  for (int i = 2; i < mx; i++) {
    if (v[i]) prime.pb(i);
  }
  return;
}

void SPF(int mx) { 

  spf[1] = 1;
  for (int i = 2; i < mx; i ++) {
    if (spf[i] == INF) {
      spf[i] = i;
      for (int j = i * i; j < mx; j += i) spf[j] = min(spf[j], i);
    }
  }
}

void id1(int num) { 

  while (num > 1) {
    prime_factor[spf[num]]++;
    num /= spf[num];
  }
  return;
}

int checkPrime(int num) {
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) return 0;
  }
  return 1;
}

void solve() {
  int x, d; cin >> x >> d;
  int cnt = 0;
  while (x % d == 0) {
    x /= d;
    cnt++;
  }
  if (cnt == 1) cout << "NO" << nl;
  else if (cnt == 2) {
    int ret = checkPrime(x);
    if (ret) cout << "NO" << nl;
    else cout << "YES" << nl;
  }
  else {
    int ret1 = checkPrime(x), ret2 = checkPrime(d);
    if (!ret1) cout << "YES" << nl;
    else if (!ret2) {
      int p;
      for (int i = 2; i * i <= d; i++) {
        if (d % i == 0) {
          p = i;
          break;
        }
      }
      int dd = d, cnt2 = 0;
      while (dd % p == 0) {
        dd /= p;
        cnt2++;
      }
      

      if (dd > 1) cout << "YES" << nl;
      else {
        if (p != x) {
          if (cnt2 == 1) cout << "NO" << nl;
          else cout << "YES" << nl;
        }
        else {
          if (cnt2 > 2) cout << "YES" << nl;
          else {
            if (cnt == 3) cout << "NO" << nl;
            else cout << "YES" << nl;
          }
        }
      }
    }
    else cout << "NO" << nl;
  }
  return;
}

signed main()
{ tezi

  

  freopen("input.txt", "r", stdin);
  

  freopen("output.txt", "w", stdout);
  

  freopen("Errors.txt", "w", stderr);

  cin >> t;
  

  fo(i, t) solve();
  return 0;
}


