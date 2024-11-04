


















using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;














int a[100005];
int main()
{
    




    

ll n;
cin>>n;
while(n--){
        ll s=0;
    ll x;
    cin>>x;
    ll a[x];forn(i,x)cin>>a[i];
     int mi=a[0];
     int b[x];
     for(int i=1;i<x;i++){if(mi>a[i]){mi=a[i];}}
forn(i,x){
s+=a[i]-mi;
}
cout<<s<<endl;
}


}



































































































































































































 	 	  		  		  	 	 	  								 	