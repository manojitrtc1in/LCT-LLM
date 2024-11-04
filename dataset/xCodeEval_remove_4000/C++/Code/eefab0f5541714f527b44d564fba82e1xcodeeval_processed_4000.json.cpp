


















































using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> seti;

const double EPS=0.000000001;
const ll INF64=1000000000000000000;
const int INF32=2000000000;

bool id0(pii a,pii b,pii c,pii point){
    int x1=a.first,x2=b.first,x3=c.first,x0=point.first;
    int y1=a.second,y2=b.second,y3=c.second,y0=point.second;
    int aa=(x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0);
    int bb=(x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0);
    int cc=(x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0);
    if (aa==0 || bb==0 || cc==0) return 1;
    if (aa>=0 && bb>=0 && cc>=0) return 1;
    if (aa<=0 && bb<=0 && cc<=0) return 1;
    return 0;
}

bool iss_ll(ll &__1,ll &__2){ return INF64/__1>=__2;}
bool equal(double _1,double _2){ return (abs(_1-_2)<EPS);}
bool id1(int __1){ll __2=sqrt(__1); return __2*__2==__1;};
bool iss_prime(ll __1){for (int i=2; i*i<=__1; ++i) if (!(__1%i)) return 0; return 1;}
int gcd(int __1,int __2){ while (__1 && __2) if (__1>__2)  __1=__1%__2; else __2=__2%__1; return __1+__2;}
int lcm(int &__1,int &__2){ return __1*__2/(gcd(__1, __2));}
int sq_cube(ll x){if (x==0) return 0;int l=0,r=2e6;while (l+1<r){int m=(l+r)/2;if (m*m*m>x) r=m;else l=m;}return l;}

bool iss(int n,int k){
    if (n>30)return 1;
    int cnt=1;
    for (int i=1; i<=n*2; ++i)
        cnt*=2;
    if ((cnt-1)/3<k) return 0;
    return 1;
}

int id2(int n){
    if (n==0) return 0;
    if (n>31) return INF64;
    int cnt=1;
    for (int i=1; i<=n*2; ++i)
        cnt*=2;
    return  ((cnt-1)/3);
}

int umn(int x,int y){
    if (x==0 ||y==0) return 0;
    if (INF64/x<=y) return INF64;
    return x*y;
}

int cntt(int x,int n,int kk){
    int ans=0;
    int k=1;
    int can=0;
    int i1=1;
    for (int i=n-1; i>=x; --i){
        if (can<INF64)
            can+=umn(id2(i),i1);
        i1=umn(i1,2);
        i1+=3;
        ans+=k;
        k=umn(k, 2);
        k++;
        if (ans>INF64) return 0;
    }
   

    

    if (ans<=kk && ans+can>=kk) return 1;
    return 0;
}

void solve(){
    int n,k;
    cin>>n>>k;
    if (!iss(n,k)){
        cout<<"NO"<<en;
        return;
    }
    int ans=n;
    while ((!cntt(ans, n,k)) && ans>=0){
        

        --ans;
        

    }
    if (ans<0){
        cout<<"NO"<<en;
        return;
    }
    cout<<"YES "<<ans<<en;
}

signed main(signed argc, const char * argv[]){
    FAST();
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}
