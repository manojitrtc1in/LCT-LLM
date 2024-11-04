
    




    
using namespace std;
using namespace __gnu_pbds;
    







    
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;
typedef vector<str> vestr;
typedef vector<int> vei;
typedef vector<vector<int>> veve;
    
    
void solve() {
    int n;
    cin>>n;
    vei a(n);
    f(n) cin>>a[i];
    vei ct(101);
    f(n) ct[a[i]]++;
    f(101) if(ct[i]) cout<<i<<' ';
    f(101) for(int j = 0; j<ct[i]-1; ++j) cout<<i<<' ';
    cout<<'\n';
}
    
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    

    

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        

        solve();
    }
}