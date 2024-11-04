

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fora(i,a,b) for(ll i=a;i<=b;i++)
#define rep(i,n) for(ll i=0;i<n;i++)
#define ford(i,a,b) for(ll i=a;i>=b;i--)
#define ff first
#define ss second
#define fix(f,n) std::fixed<<std::setprecision(n)<<f
#define pb push_back
#define pob pop_back
#define mp(x,y) make_pair(x,y)
#define all(a) (a).begin(),(a).end()

#define MOD 1000000007
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



