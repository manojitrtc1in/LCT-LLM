


using namespace std;






















































inline bool id1(long double x){
    long double sr=sqrt(x);
    return ((sr-floor(sr))==0);
}
const string letters = "abcdefghijklmnopqrstuvwxyz";
vec prime;
void sieve(ll n){
    vec ans,isPrime(n+1,0);
        fls(i,2,sqrt(n)+1){
            if(isPrime[i]==0){
                for(ll j=2*i;j<=n;j+=2){
                    isPrime[j]=1;
                }
            }
        }
    fls(i,2,n+1){
        if(isPrime[i]==0)
            ans.pb(i);
    }
    prime=ans;
}
bool inline isPrime(ll n) { 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
    if (n%2 == 0 || n%3 == 0) return false; 
    for (ll i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
    return true; 
}
void id0(ll n, vec tree[]){
    ll a,b;
    vec temptree[n];
    fl(i,n-1){
        ci a>>b;
        a--;b--;
       tree[a].pb(b);
        tree[b].pb(a);
    }
}
string getxor(string a,string b){
    string str="";
    fl(i,a.size()){
        if(a[i]=='1'&&b[i]=='0')
            str+='1';
        else if(a[i]=='0'&&b[i]=='1')
            str+='1';
        else 
            str+='0';
    }
    return str;
}
void showv(vec v){
    fla(i,v)co i<<" ";
}
void showarray(ll a[],ll n){
    for(ll i=0;i<n;i++)
        co a[i]<<" ";
}
ull bincoeff(ll n,ll k){
    if(k>n-k)
        k=n-k;
    ull ans=1;
    fl(i,k){
        ans*=n-i;
        ans/=i+1;
    }
    return ans;
}





void solve(){
    ll n,x,y;
    ci n>>x>>y;
    vec v(n);
    in(v);
    ll op=0;
    fl(i,n){
        int flag=1;
        for(ll j=max(op,i-x);j<=min(n-1,i+y);j++)
            if(i!=j && v[i]>=v[j]){
                flag=0;
                break;
            }
            if(flag){
                co i+1;
                break;
            }
    }
}








vec d;
void template_multiple(){
    ll t;
    cin>>t;
    while(t--){
        solve();
        el;
    }
}
void template_single(){
    solve();
    el;
}
int main()
{
    IOS


    template_single();
    return 0;
}



