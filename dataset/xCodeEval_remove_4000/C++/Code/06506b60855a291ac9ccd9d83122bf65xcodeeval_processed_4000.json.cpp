














































using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> seti;
typedef pair<double, double> pdd;
typedef long double ld;

const double EPS=0.000000001;
const double id0=1000000000;
const ll INF64=1000000000000000000;
const int INF32=1000000000;



int arr[maxN];

signed main(void){
    

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int  n;
    cin>>n;
    for (int i=1; i<=n; ++i){
        cin>>arr[i];
    }
    for (int i=1; i<=n; ++i){
        if (i!=n){
            while (arr[i]){
                cout<<"P";
                cout<<"R";
                cout<<"L";
                --arr[i];
            }
            cout<<"R";
        }else{
            while (arr[i]){
                cout<<"P";
                cout<<"L";
                cout<<"R";
                --arr[i];
            }
        }
    }
}




