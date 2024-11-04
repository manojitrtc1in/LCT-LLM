









































typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = (int)10e6 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;
using namespace std;

int e,d,n,m;
int a[N],b[N];
int main(){
	Speedforce
     cin>>e>>d>>n>>m;
     for(int i=1;i<=e;i++){
          cin>>a[i];
     }
     for(int i=1;i<=d;i++){
          cin>>b[i];
     }
     sort(a+1,a+e+1);
     sort(b+1,b+d+1);
     if(a[n]<b[d-m+1]){
          return cout<<"YES",0;
     }
     return cout<<"NO",0;
}
