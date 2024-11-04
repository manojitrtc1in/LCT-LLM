













































using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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
bool id1(ll &__1){ll __2=sqrt(__1); return __2*__2==__1;};
bool iss_prime(ll __1){for (int i=2; i*i<=__1; ++i) if (!(__1%i)) return 0; return 1;}
int gcd(int __1,int __2){ while (__1 && __2) if (__1>__2)  __1=__1%__2; else __2=__2%__1; return __1+__2;}
int lcm(int &__1,int &__2){ return __1*__2/(gcd(__1, __2));}

int iss[200100];
signed main(){
    FAST();
    int n,m;
    cin>>n>>m;
    for ( int i=1; i<=m; ++i){
        int k;
        cin>>k;
        bool flag=1;
        for (int j=0; j<k; ++j){
            int x;
            cin>>x;
            if (x<0){
                if (iss[-x]==i)
                    flag=0;
                else
                    iss[-x+n]=i;
            }else{
                if (iss[x+n]==i)
                    flag=0;
                else
                    iss[x]=i;
            }
        }
        if (flag){
            cout<<"YES"<<en;
            return 0;
        }
    }
    cout<<"NO"<<en;
    return 0;
}

