


using namespace std;
typedef long long ll;












typedef pair<int,int>pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<vi> vvi;

int main() {
   
    ll T = 1;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        if(n==0){
            continue;
        }
        ll c=1;
        for(int i=2*n;c<=n;i+=2){
            cout<<i<<" ";
            c++;
        }
        cout<<endl;

    }
    return 0;
}



