












































































using namespace std;













typedef pair<int,int> P;
typedef vector<vector<P>> Graph;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  

  int n,m;
  cin >> n >> m;

  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<int> b;
  int cnt = 0;
  REP(i,m){
    int x,y,z;
    cin >> x >> y >> z;
    if(x != 1) continue;
    b.pb(y);
    if(y == 1000000000) cnt++;
  }

  if(n == 0){
    cout << cnt<< endl;
    return 0;
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int sum[n+1] = {}; 

  int tmp = 0;
  REP(i,b.size()){
    while(b[i] >= a[tmp] && tmp<n){
      sum[tmp+1] = sum[tmp];
      tmp++;
    }
    if(b[i] < a[tmp])sum[tmp]++;
  }

  while(tmp < n){
    sum[tmp+1] = sum[tmp];
    tmp++;
  }

  sum[n] = b.size()-cnt;

 


  int ans = b.size();
  REP(i,n+1){
    ans = min(ans,b.size()-sum[i]+i);
  }

  cout << ans << endl;

  return 0;
}