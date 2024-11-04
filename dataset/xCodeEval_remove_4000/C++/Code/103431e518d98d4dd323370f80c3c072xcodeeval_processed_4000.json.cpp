


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



