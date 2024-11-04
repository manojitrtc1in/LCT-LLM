


 

  

 

 

 

 

 


 

 

 

  

   



using namespace std;





















typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef pair < long long , long long > pll;
typedef vector < ll > vll;
typedef vector < vll > vvll;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < pii > vpii;
typedef pair < pii , pii > ppiipii;
typedef long double ld;
typedef map < int , int > mii;
typedef map < ll , ll > mll;
typedef set < int > si;
typedef set < ull > sull;
typedef set < string > ss;
typedef set < pii > spii;
typedef multiset < int > msi;
typedef map < pii , int > mpiii;
typedef map < int , pii > mipii;
typedef vector < pair < int , pair < int , int > > > vpipii;

const int maxn = int(1.5 * 1e7);
const int inf = ~0U >> 1;
const ll ll_inf = 1e18 + 420;
const double eps = 1e-4;
const int N = 1e6 + 7;
const int MAX = 1e5 + 9;
const int MOD = 998244353;
const ld pi = 3.14159265359;

int n;
ll a[N],dp[MAX][210][2],ans,p[210][2];

main(void){
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    
    if(a[1] == -1){
        for(int i = 1;i <= 200;++i){
            dp[1][i][0] = 1;
            

        }
    }
    else{
        dp[1][a[1]][0] = 1;
        

    }
    for(int j = 1;j <= 200;++j){
        p[j][1] = (p[j - 1][1] +  dp[1][j][1]) % MOD;
        p[j][0] = (p[j - 1][0] +  dp[1][j][0]) % MOD;
    }
    for(int i = 2;i <= n;++i){
        for(int x = 1;x <= 200;++x){
            if(a[i] != -1 && a[i] != x){
                continue;
            }
            dp[i][x][0] = (p[x - 1][1] + p[x - 1][0]) % MOD;
            dp[i][x][1] = (p[200][1] - p[x - 1][1] + MOD + dp[i - 1][x][0]) % MOD;
        }
        p[0][0] = p[0][1] = 0;
        for(int j = 1;j <= 200;++j){
            p[j][1] = (p[j - 1][1] +  dp[i][j][1]) % MOD;
            p[j][0] = (p[j - 1][0] +  dp[i][j][0]) % MOD;
        }
    }
    for(int i = 1;i <= 200;++i){
        ans = (ans + dp[n][i][1]) % MOD;
    }
    cout << ans;
}