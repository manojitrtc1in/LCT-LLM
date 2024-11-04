













































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

multiset <int> VEC;
vector<int> ans;
void delet(int x){
    VEC.erase(VEC.find(x));
}
signed main(){
    

    FAST();
    int n;
    cin>>n;
    int x;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j){
            cin>>x;
            VEC.insert(x);
        }
    if (n==1){
        cout<<*VEC.rbegin();
        return 0;
    }
    ans.push_back(*VEC.rbegin());
    VEC.erase(VEC.find(*VEC.rbegin()));
    n-=1;
    while (n--){
        x=*VEC.rbegin();
        for (int i=0; i<ans.size(); ++i){
                delet(gcd(ans[i], x)),delet(gcd(ans[i], x));
        }
        ans.push_back(*VEC.rbegin());
        VEC.erase(VEC.find(*VEC.rbegin()));
    }
    for (int i:ans)
        cout<<i<<" ";
    return 0;
}

