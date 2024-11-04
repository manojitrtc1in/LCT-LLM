






using namespace std;








 

 
const ll MOD = 1000000007;


 
const int N = 1005;

int n,k;
int b[N], a[N];
ll c[N];
ll f[N][20005];

void pre_init() {
    
}

void init() {
    
}



void MrUnknown() {
    int tong = 0;
    ll ans = 0;
    f(i,1,n) tong += a[b[i]];
    
    if (k>=tong) {
        f(i,1,n) ans += c[i];
        cout << ans << "\n" ;
        return ;
    }
    
    f(i,0,k) f[0][i] = 0;
    f(j,0,k) {
        f(i,1,n) {
            f[i][j] = f[i-1][j];
            if (j>=a[b[i]]) f[i][j] = max(f[i][j], f[i-1][j-a[b[i]]]+c[i]);
            ans = max(ans,f[i][j]);
        }
    }
    cout << ans << "\n" ;
}

void inp() {
    

    
    cin >> n >> k ;
    f(i,1,n) cin >> b[i] ;
    f(i,1,n) cin >> c[i] ;

    pre_init();

    MrUnknown();
    init();
    
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    


    


    f(i,1,1000) a[i] = i;
    a[1] = 0;
    a[0] = 0;
    f(i,1,1000) {
        for (int j=i;j>=1;j--) {
            int pos = i + i/j;
            if (pos>1e3) break;
            a[pos] = min(a[pos], a[i]+1);
        }
        a[0] = max(a[0], a[i]);
        

        

    }
    

    
    int t; cin>>t; while(t--) 
        inp();
 
}

 


 
