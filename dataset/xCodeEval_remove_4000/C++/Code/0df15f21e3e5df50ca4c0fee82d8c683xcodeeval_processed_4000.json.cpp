



 




































using namespace std;
char nl = '\n', sp = ' ';
int mod = 1e9 + 7;
template<class T> bool ckmin(T& a, const T& b) { return b > a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


vi primes;
void fp(){
    for(int i = 2; i < (1 << 15); i++){
        bool flg = 1;
        for(int j = 0; j < (int)primes.size(); j++)if(i % primes[j] == 0){flg = 0; break ;}
        if(flg)primes.pb(i);
    }
}

bool ifP(int x){
    int n = primes.size();
    rep(i, n){
        if(x == primes[i])return 1;
        if(x % primes[i] == 0)return 0;
    }
    return 1;
}
long long binpow(long long a, long long b, long long m = 1e9 + 7) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int inv(int a, int mod = 1e9 + 7){
    return binpow(a, mod-2, mod);
}

void solve(){
    int n;
    cin >> n;

    vi v(n); take(v);
    int mx = *max_element(all(v));
    int mxn = 1;
    while(mxn < mx) mxn <<= 1;
    if(mx == mxn) mxn *= 2;
    vector<vector<int>> dp1(n + 1, vector<int>(mxn + 1, 0));
    

    for(int i = 0; i <= mxn; i++)
        dp1[0][i] =  (v[0] != i);

    for(int i = 1; i < n; i++){
        for(int j = 0; j < mxn; j++){
            if(j == v[i]){
                

                dp1[i][j] = dp1[i - 1][0];
                continue;
            }
            dp1[i][j] = min(dp1[i - 1][0], dp1[i - 1][j ^ v[i]]) + 1;
            
        }
    }
    

    cout << dp1[n - 1][0] << nl;
    
   

}

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;   
}





