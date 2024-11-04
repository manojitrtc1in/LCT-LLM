



























using namespace std;


using ll = long long;
using ld = long double;
using db = double; 
using str = string; 
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>; 
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;

































template<class T> bool ckmin(T&a, T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, T&b) { bool B = a < b; a = max(a,b); return B; }


const int MOD = 998244353;
const int MX = 3e5+5;
const ll INF = 1e18; 

const ld PI = acos((ld)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; 


int cal(int x,  int n)
{
    if( n == 0)
        return 1;
    if (n % 2 == 0)
     return cal( x,n/2)*cal( x, n/2);
    else
     return x * cal( x, n/2)*cal( x, n/2);
}


long long ncr(long long n,long long r){
if(r==0 || n==r) {
    return 1;
}
return ncr(n-1,r)+ncr(n-1,r-1);
}
bool isPrime(int n){
    if(n%2==0){
        return false;
    }
    for(int i=3;i*i<=n;i+=2){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
ll id1(ll x){
    ll sm=0;
    while(x>0) {
     sm+=x%10;
     x/=10;
    }
    return sm;
}


 

void isFound(int st,int lt,int tosrch){

while (st<=lt)
{
   
    int mid=(st+lt)/2;
    

 

    

    
}
}



void solve(){
int n;
cin>>n;
vector< long long> a(n);
 long long sm=0;
id0(i,n){
cin>>a[i];
sm+=a[i];
}

cout<<abs(sm)<<"\n";
}


int main() {
cin.tie(nullptr);
ios::sync_with_stdio(false); 
int t;
cin>>t;
while (t--)
{
   solve();
}

return 0;
}

