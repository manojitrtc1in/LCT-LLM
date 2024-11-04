

#include<bits/stdc++.h>
using namespace std;



#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);



#define ull unsigned long long
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mk make_pair 
#define F first
#define S second
#define s(t) t.size() 
#define ll long long 
#define ull unsigned long long
#define co cout<<
#define ci cin>>
#define el cout<<endl 
#define work cout<<"working"<<endl
#define sortd(v) sort(all(v),greater<ll>())
#define sorta(v) sort(all(v))



#define mod 1000000007
#define primemod 998244353
#define pi acos(-1.0)



#define vec vector<ll>
#define vecs vector<string>
#define vecvec vector<vec>
#define vec2d(v,n,m) vecvec v(n,vec (m,0))
#define st set<ll>
#define stack stack<ll>
#define uset unordered_set<ll>
#define ump unordered_map<ll,ll>
#define mp map<ll,ll>
#define clr(x) x.clear()
#define all(v) v.begin(),v.end()



#define fl(i,n) for(ll i=0;i<n;i++)
#define fls(i,x,n) for(ll i=x;i<n;i++)
#define flr(i,n)  for(ll i=n-1;i>=0;i--)
#define fla(i,v)  for(auto i:v)    
#define in(v) for(auto &i:v){cin>>i;}


inline bool isPerfectSquare(long double x){
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
void maketree(ll n, vec tree[]){
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



