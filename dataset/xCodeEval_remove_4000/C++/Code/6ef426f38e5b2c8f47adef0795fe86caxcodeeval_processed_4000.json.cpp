









using namespace std;
 



 




 

 


const ll mod = 998244353;
 
const int N = 100005;
const ll saved_val = 1000000000;

ll n ;
ll a[N] ;
ll xo[N] ;
ll f[N] ;

void pre_init() {

}
 
void init() {

}


void MrUnknown() {
    xo[0] = 0;
    f(i,1,n) xo[i] = xo[i-1]^a[i];
    map<ll,int> mp;
    f[0] = 0 ;
    f(i,1,n) {
        f[i] = (xo[i]==0);
        

        

        

        if (mp[xo[i]] > 0) {
            f[i] = max(f[i], f[mp[xo[i]]] + 1);
        }
        if (i>1) f[i] = max(f[i], f[i-1] + (a[i]==0));
        mp[xo[i]] = i;
        f[0] = max(f[0], f[i]);
        

    }
    

    mp.clear();
    cout << n - f[0] << "\n" ;
}
 
void inp() {
    

    
    cin >> n ;
    f(i,1,n) cin >> a[i] ;

    pre_init();
    
    MrUnknown();
 
    init();
    
}
 
signed main() 

{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    

    

 
    

 
    int t; cin>>t; while(t--) 
        inp();
 
}

 


 
