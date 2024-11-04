











































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
const double id0=1000000000;

const int MAXN=1000100;

int cnt[MAXN];

int prevv[3][3];
int nextt[3][3];
int arr1[1001000],arr2[1001000];
signed main(void){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int pr;
    vi V1,V2;
    int x;
    cin>>pr;
    int y=pr;
    arr1[0]=pr;
    for (int i=1; i<n; ++i){
        int x;
        
        cin>>x;arr1[i]=x;
        V1.push_back(-pr+x);
        pr=x;
    }
    cin>>pr;
    arr2[0]=pr;
    for (int i=1; i<n; ++i){
        int x;
        cin>>x;arr2[i]=x;
        V2.push_back(-pr+x);
        pr=x;
    }
    sort(all(V1));
    sort(all(V2));
    for (int i=0; i<V1.size(); ++i){
        if (V1[i]!=V2[i] || arr1[0]!=arr2[0] && arr1[n-1]!=arr2[n-1]){
        cout<<"NO"<<en;
        return 0;
        cout<<V1[i]<<" "<<V2[i]<<en;
    }
    }

        cout<<"YES"<<en;
    return 0;
}
