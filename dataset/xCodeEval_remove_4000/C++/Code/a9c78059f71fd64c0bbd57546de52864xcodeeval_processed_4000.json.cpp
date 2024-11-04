













































using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const double EPS=0.000000001;
const ll INF64=1000000000000000000;
const int INF32=2000000000;


bool iss_ll(ll &__1,ll &__2){ return INF64/__1>=__2;}
bool id0(ll &__1){ll __2=sqrt(__1); return __2*__2==__1;};
bool iss_prime(ll __1){for (int i=2; i*i<=__1; ++i) if (!(__1%i)) return 0; return 1;}
int gcd(int __1,int __2){ while (__1 && __2) if (__1>__2)  __1=__1%__2; else __2=__2%__1; return __1+__2;}
int lcm(int &__1,int &__2){ return __1*__2/(gcd(__1, __2));}

bool iss(pii a,pii b,pii c,pii point){
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

int cnt[300100];
int pref[300100];
int cnttt[2];
int ST[1010300][20];
int logg[3003000];
int query(int l,int r){
    if (l==r)
        return cnt[l];
    int lenn=r-l+1;
    return max(ST[l][logg[lenn]],ST[r-(1<<logg[lenn])+1][logg[lenn]]);
}
void build (int n){
    for (int i=1; i<=n; ++i)
        ST[i][0]=cnt[i];
    for (int len=1; len<19; ++len){
        for (int i=1; i<=n; ++i)
            ST[i][len]=max(ST[i][len-1],ST[i+(1<<(len-1))][len-1]);
    }
}
signed main(){
    FAST();
    int n;
    cin>>n;
    for (int i=1; i<=n; ++i){
        int x;
        cin>>x;
        while (x){
            cnt[i]+=(x%2);
            x/=2;
        }
        pref[i]=pref[i-1]+cnt[i];
    }
    logg[2]=1;
    for (int i=1; i<29; ++i){
        for (int j=(1<<(i)); j<min((1<<(i+1)),300001); ++j)
            logg[j]=i;
    }
    

    build(n);
    int ans=0;
    for (int len=1; len<=min(n,64ll); ++len){
        for (int i=len; i<=n; ++i){
            if ((pref[i]-pref[i-len])%2==0 && query(i-len+1, i)>(pref[i]-pref[i-len])/2){
                --ans;
            }
        }
    }
    

    

    int sum=0;
    cnttt[0]=1;
    for (int i=1; i<=n; ++i){
        sum+=cnt[i];
        ans+=cnttt[sum%2];
        cnttt[sum%2]++;
    }
    cout<<ans<<en;
    return 0;
}

