
    




    
using namespace std;
using namespace __gnu_pbds;
    







    
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;
typedef vector<str> vestr;
typedef vector<int> vei;
typedef vector<vector<int>> veve;

int gcd(int a, int b){
    if(b>a) swap(a, b);
    if(!b) return a;
    return gcd(b, a%b);
}
    
void solve() {
    int n;
    cin>>n;
    vei a(n), b(n);
    f(n) cin>>a[i]>>b[i];
    vector<pair<int, int>> gt(n);
    for(int i = 0; i<n; ++i){
        gt[i] = {a[i]-b[i], b[i]};
    }
    sort(rall(gt));
    vector<int> dp(n+1);
    for(int i = 0; i<n; ++i) dp[i+1] = dp[i]+gt[i].first;
    int r = -1;
    f(n){
        if(gt[i].first>=0) r = i; 
    }
    vector<int> dp2(n+1);
    reverse(all(gt));
    for(int i = 0; i<n; ++i) dp2[i+1] = dp2[i]-gt[i].first;
    int r2 = -1;
    f(n){
        if(gt[i].first<=0) r2 = i; 
    }
    int ans = 0;
    f(n) ans+=b[i];
    int ans2 = 0;
    f(n) ans2+=a[i];
    int m;
    cin>>m;
    f(m){
        int x, y;
        cin>>x>>y;
        if(max(x, y)*max(x, y)<n){
            int tmpans = -1;
            int lcm = x*y/gcd(x, y);
            int ctt = lcm/x;
            for(int i = 0; i<=y*x; i+=x){
                if((n-i)%y==0){
                    if(i>=r){
                        tmpans = max(tmpans, ans+dp[i]);
                        continue;
                    }
                    int k = i, b = (n-i);
                    int L = 0, R = n+1;
                    while(R-L>1){
                        int m = (R+L)/2;
                        k = i+m*lcm;
                        if(k>r) R = m;
                        else L = m;
                    }
                    tmpans = max(tmpans, ans+dp[i+L*lcm]);
                    ++L;
                    if(i+L*lcm<=n) tmpans = max(tmpans, ans+dp[i+L*lcm]);
                    

                }
            }
            swap(x, y);
            ctt = lcm/x;
            swap(dp, dp2);
            swap(r, r2);
            swap(ans, ans2);
            for(int i = 0; i<=y*x; i+=x){
                if((n-i)%y==0){
                    if(i>=r){
                        tmpans = max(tmpans, ans+dp[i]);
                        continue;
                    }
                    int k = i, b = (n-i);
                    int L = 0, R = n+1;
                    while(R-L>1){
                        int m = (R+L)/2;
                        k = i+m*lcm;
                        if(k>r) R = m;
                        else L = m;
                    }
                    tmpans = max(tmpans, ans+dp[i+L*lcm]);
                    ++L;
                    if(i+L*lcm<=n) tmpans = max(tmpans, ans+dp[i+L*lcm]);
                    

                }
            }
            swap(ans, ans2);
            swap(dp, dp2);
            swap(r, r2);
            cout<<tmpans<<'\n';
        }
        else{
            if(x>y){
                int tmpans = -1;
                for(int i = 0; i<=n; i+=x){
                    if((n-i)%y==0){
                        tmpans = max(tmpans, ans+dp[i]);
                        

                    }
                }cout<<tmpans<<'\n';
            }
            else{
                int tmpans = -1;
                for(int i = 0; i<=n; i+=y){
                    if((n-i)%x==0){
                        tmpans = max(tmpans, ans+dp[n-i]);
                        

                    }
                }cout<<tmpans<<'\n';
            }
        }
    }
}
    
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    

    

    int tc = 1;
    

    for (int t = 1; t <= tc; t++) {
        

        solve();
    }
}   