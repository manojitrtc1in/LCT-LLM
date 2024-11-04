











































using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> seti;
typedef pair<double, double> pdd;


const double EPS=0.000000001;
const ll INF64=1000000000000000000;
const int INF32=2000000000;
const double id2=1000000000;

int arr[200100];

vector<int> VEC;

int f(int pos){
    if (VEC.back()<pos) return VEC.size();
    if (VEC.front()>pos) return 0;
    int l=0,r=VEC.size()-1;
    while (l+1<r){
        int m=(l+r)>>1;
        if (VEC[m]>pos) r=m;
        else l=m;
    }
    return l+1;
}

int fact[200200];

int rfact[200200];

int binpow(int a,int b){
    int res=1;
    while (b){
        if (b%2) res*=a;
        res%=MOD;
        a*=a;
        a%=MOD;
        b/=2;
    }
    return res;
}

void build(){
    fact[0]=1;
    rfact[0]=1;
    for (int i=1; i<=200000; ++i){
        fact[i]=fact[i-1]*i;
        fact[i]%=MOD;
        rfact[i]=binpow(fact[i], MOD-2);
    }
}

int tree[800800];

void update(int v,int l,int r,int pos){
    
    if (l==r){
        tree[v]+=1;
        return;
    }
    int m=(l+r)/2;
    if (pos<=m)
        update(v*2, l, m, pos);
    else
        update(v*2+1, m+1, r, pos);
    tree[v]=tree[v*2]+tree[v*2+1];
}

int q(int v,int l,int r,int L,int R){
    if (l==L && r==R)
        return tree[v];
    int m=(l+r)>>1;
    if (R<=m)
        return q(v*2,l,m,L,R);
    elif (L>m)
        return q(v*2+1, m+1, r, L, R);
    else
        return q(v*2,l,m,L,m)+q(v*2+1,m+1,r,m+1,R);
    
}

signed main(void){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    set <int> SET;
    for (int i=1; i<=n; ++i){
        SET.insert(i);
    }
    int id1=0;
    for (int i=1; i <= n; ++i){
        int x;
        cin >> x;
        SET.erase(x);
        arr[i] = x;
        if (x == -1) ++id1;
    }
    for (int i:SET) VEC.push_back(i);
    int cnt=0;
    build();
    int ans=0;
    
    int help=0;
    
    for (int i=1; i<=n; ++i){
        if (arr[i]==-1) continue;
        int x=q(1, 1, n, arr[i], n);
        help+=x;
        help%=MOD;
        update(1,1,n,arr[i]);
    }
    
    

    
    if (id1!=0){
        for (int i=1; i<=n; ++i){
            if (arr[i]==-1){
                ++cnt;
                continue;
            }
            int id0=f(arr[i]);
            int a=cnt,b=id1-a;
            int l=id0,r=VEC.size()-id0;
            

            ans+=((b*l%MOD)*fact[id1-1])%MOD;
            ans%=MOD;
            ans+=((a*r%MOD)*fact[id1-1])%MOD;
            ans%=MOD;
        }
    }
    
    

    ans+=(fact[id1]*help);
    
    ans%=MOD;
    
    
    
    ans%=MOD;
    
    ans*=rfact[id1];
    
    ans%=MOD;
    
    ans+=((((id1)*(id1-1)/2)%MOD)*binpow(2, MOD-2))%MOD;
    
    ans%=MOD;
    
    cout<<ans<<en;
    return 0;
}
