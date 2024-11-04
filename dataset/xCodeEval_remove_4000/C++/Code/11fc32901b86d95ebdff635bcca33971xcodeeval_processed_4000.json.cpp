


















































using namespace std;

template<class A, class B, class C> struct Triple { A first; B second; C third;
    bool operator<(const Triple& t) const { if (fi != t.fi) return fi < fi.st; if (se != t.se) return se < t.se; return th < t.th; } };

int gcd(int a,int b){
    while (a && b)
        if (a>b) a=a%b; else b=b%a;
    return a+b;
}


typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> seti;
typedef long double ld;
typedef pair<ld, ld> pdd;
typedef Triple<int, int, int> TIII;


const double EPS=0.000000001;
const double id0=1000000000;
const ll INF64=1000000000000000000;
const int INF32=1000000000;



int arr[maxN];

map <string,int> MAP;

signed main(void){
    

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    if (k==1){
        cout<<1;
        for (int i=1; i<n; ++i) cout<<0;
        return 0;
    }
    if (k==n){
        for (int i=1; i<=k; ++i) cout<<1;
        cout<<en;
        return 0;
    }
    vector<int> VEC;
    int sz=(n-k)/2;
    VEC.push_back(1);
    for (int i=1; i<=sz; ++i) VEC.push_back(0);
    vi ANS;
    int q=0;
    while (ANS.size()<n){
        ANS.push_back(VEC[q]);
        ++q;
        q%=VEC.size();
    }
    for (int i:ANS) cout<<i; cout<<en;
    return 0;
}




