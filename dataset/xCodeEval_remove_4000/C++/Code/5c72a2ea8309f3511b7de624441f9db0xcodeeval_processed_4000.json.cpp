



using namespace std;

typedef long long ll;


int _;

























































































































































































































































































































	

	

	

		

	



















  

  





  

  

  

    

    

    

    

  

  

    

    

    

          

    



    



    

    

    

    

  

  

  

  

  

  

  


















































































































































const int mod = 998244353;
int add(int x, int y){ x += y; while(x >= mod){x -= mod;}while(x < 0){x += mod;}return x;}
int sub(int x, int y){return add(x, mod - y);}
int mul(int x, int y){return 1ll * x * y % mod;}
int binpow(int x, int y){int res = 1;while(y > 0){if(y & 1){res = mul(res, x);}x = mul(x, x);y >>= 1;}return res;}
int inv(int x){return binpow(x, mod - 2);}
int divide(int x, int y){return mul(x, inv(y));}
int n = 12;
int f[(1 << 12) + 10][12][12][13];
int s[13][12][12];
int dp[13][23][12][12];
int Inv[23];

int all(int x){
    return (1 << x) - 1;
}


void init(){
    Inv[0] = Inv[1] = 1;
    for(int i = 2; i <= 22; i++){
        Inv[i] = inv(i);
    }

    for(int n = 2; n <= 12; n++){
        

        for(int i = 0; i <= all(n); i++){
            for(int j = 0; j <= 11; j++){
                for(int k = 0; k <= 11; k++){
                    for(int l = 0; l <= n; l++){
                        

                        f[i][j][k][l] = 0;
                    }
                }
            }
        }

        f[0][0][0][0] = 1;
        for(int o = 1; o <= n; o++){
            for(int S = 0; S <= all(n); S++){
                for(int c1 = 0; c1 <= 11; c1++){
                    for(int c2 = 0; c2 <= 11; c2++){
                        for(int lst = 0; lst <= n; lst++){
                            if(f[S][c1][c2][lst] && __builtin_popcount(S) + 1 == o){
                                int mx = 0;
                                for(int i = 1; i <= n; i++){
                                    if((S >> (i-1)) & 1){
                                        mx = max(mx, i);
                                    }
                                }
                                for(int j = 1; j <= n; j++){
                                    if(!((S>>(j-1))&1)){
                                        if(max(mx, j) > o || o == n){
                                            int t1 = c1 +  __builtin_popcount((all(n) - all(j))&S);
                                            int t2 = c2 + (lst > j);
                                            if(t1 <= 11 && t2 <= 11){
                                                f[(S | (1 << (j-1)))][t1][t2][j] = add(f[(S | (1 << (j-1)))][t1][t2][j], f[S][c1][c2][lst]);
                                            }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for(int i = 1; i <= 11; i++){
        for(int j = 1; j <= 11; j++){
            for(int k = 1; k <= n; k++){
                s[n][i][j] = add(s[n][i][j], f[all(n)][i][j][k]);
            }
        }
    }

}
    dp[0][0][0][0] = 1;
    for(int a = 0; a <= 11; a++){
        for(int b = 0; b <= 22; b++){
            for(int c = 0; c <= 11; c++){
                for(int d = 0; d <= 11; d++){
                    if(dp[a][b][c][d]){
                        for(int n = 2; n <= 12; n++){
                            for(int i = 1; i <= 11; i++){
                                for(int j = 1; j <= 11; j++){
                                    if(c + i <= 11 && d + j <= 11){
                                        dp[a+1][b+n][c+i][d+j] = add(dp[a+1][b+n][c+i][d+j], 1ll*dp[a][b][c][d]*s[n][i][j]%mod);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

}

void solve(){
    int x, y, z;
    cin >> x >> y >> z;
    int ans = 0;
    for(int i = 2; i <= min(22, x); i++){
        ll now = 1ll * x - i + 1;

        for(int j = 1; j <= 11; j++){
            ans = add(ans, 1ll*dp[j][i][y][z]*now%mod);
            now = 1ll * now * (1ll * x - i + j + 1) % mod * Inv[j+1] % mod;
        }
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    init();
    cin >> _;
    while(_--)
        solve();
    return 0;
}
