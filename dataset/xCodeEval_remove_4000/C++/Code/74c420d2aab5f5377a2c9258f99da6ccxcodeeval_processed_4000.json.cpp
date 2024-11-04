












































































using namespace std;













typedef pair<int,int> P;
typedef vector<vector<P>> Graph;

inline int mul(int a, int b) {
    
      return (int) ((long long) a * b % MOD);
    
      unsigned long long x = (long long) a * b;
      unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
      asm(
        "divl %4; \n\t"
        : "=a" (d), "=d" (m)
        : "d" (xh), "a" (xl), "r" (MOD)
      );
      return m;
}

inline int inv(int a) {
    a %= MOD;
    if (a < 0) a += MOD;
    int b = MOD, u = 0, v = 1;
    while (a) {
      int t = b / a;
      b -= t * a; swap(a, b);
      u -= t * v; swap(u, v);
    }
    assert(b == 1);
    if (u < 0) u += MOD;
    return u;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  

  int n;
  cin >> n;

  vector<int> a(n);
  int mx = 0,mx2 = -1;
  REP(i,n){
    cin >> a[i];
    if(mx2 <= a[i]){
      mx2 = a[i];
      if(mx2 > mx) swap(mx,mx2);
    }
  }

  int sum = accumulate(a.begin(),a.end(),0LL);

  vector<int> ans;
  REP(i,n){
    if(a[i] != mx){
      if(sum-a[i] == mx*2) ans.pb(i+1);
    }
    else if(sum-a[i] == mx2*2) ans.pb(i+1);
  }

  cout << ans.size() << endl;
  REP(i,ans.size()){
    cout << ans[i] << " ";
  }

  return 0;
}