













































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

int cnt[10000100];
set <pii> countt;


signed main()
{
    

    FAST();
    int n,m;
    cin>>n>>m;
    int sum=0;
    int x;
    for (int i=0; i<n; ++i){
        cin>>x;
        sum+=x;
        cnt[x]++;
    }
    if (sum<m){
        cout<<-1<<en;
        return 0;
    }
    int CNT=0;
    

    for (int i=10000000; i>0; --i){
        

        if (cnt[i]){
            

            CNT+=cnt[i];
        }
    }
    

    int pos=0;
    for (pos=0; pos<10000001; ++pos) if (cnt[pos]) break;
    for (int i=10000000; i>1; --i){
        if (cnt[i]){
            if (CNT<m){
                if (cnt[i]>=m-CNT){
                    cnt[i]-=(m-CNT);
                    cnt[i/2]+=(m-CNT);
                    cnt[i/2+i%2]+=(m-CNT);
                    CNT+=(m-CNT);
                }else{
                    cnt[i/2]+=cnt[i];
                    cnt[i/2+i%2]+=cnt[i];
                    CNT+=cnt[i];
                    cnt[i]=0;
                }
            }
        }
        if (CNT>=m) break;
    }
    int newcnt=0;
    for (pos=10000000; pos>0; --pos){
        newcnt+=cnt[pos];
        if (newcnt>=m) break;
    }
    cnt[pos]-=(newcnt-CNT);
    for (int i=10000000; i>1; --i){
        if (pos>=i/2) break;
        if (cnt[i]){
            if (i/2>pos){
                for (pos; pos<i/2; ++pos){
                    if (cnt[pos]>cnt[i]){
                        cnt[pos]-=cnt[i];
                        cnt[i/2]+=cnt[pos];
                        cnt[i/2+i%2]+=cnt[pos];
                        cnt[i]=0;
                        break;
                    }else{
                        cnt[i]-=cnt[pos];
                        cnt[i/2]+=cnt[pos];
                        cnt[i/2+i%2]+=cnt[pos];
                        cnt[pos]=0;
                    }
                }
                while (pos<=10000000 && cnt[pos]==0) ++pos;
            }
        }
    }
    cout<<pos<<en;
    return 0;
}
