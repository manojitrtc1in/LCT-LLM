

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



inline bool isPerfectSquare(long double x){
    long double sr=sqrt(x);
    return ((sr-floor(sr))==0);
}
const string letters = "abcdefghijklmnopqrstuvwxyz";

vec prime;
void sieve(ll n){
    vec ans,isPrime(n+1,0);
    fls(i,2,sqrt(n)+1){
        ans.pb(pow(2,i)-1);
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
auto isz=[](const auto& c){return int(c.size());};
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
ll modbig(string num, ll a) 
{ 
    ll res = 0; 
    for (ll i = 0; i < num.length(); i++) 
         res = (res*10 + (int)num[i] - '0') %a;   
    return res; 
} 
ll countset(string a){
    ll count=0;
    fl(i,a.size()){
        if(a[i]=='1')
            count++;
    }
    return count;
}
void  showv(vec a){
    fla(i,a)co i<<" ";el;
}





void solve()
{
    string s;
    ci s;
    ll cnt=0,sum=0,cnt0=0;
    fla(i,s){
        int oo=i-'0';
        if(oo==0)
            cnt0++;
        if(oo%2==0)
            cnt++;
        sum+=oo;
    }
    if(cnt>=2 && cnt0>0 && sum%3==0)
        co "red";
    else
        co "cyan";
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
    template_multiple();


    return 0;
}



