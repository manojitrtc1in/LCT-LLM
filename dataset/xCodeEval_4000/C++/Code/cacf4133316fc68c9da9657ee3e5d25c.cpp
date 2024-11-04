
#include <bits/stdc++.h>
using namespace std;
                                                                                                       
    

    

    

                                                                                                       
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

                                                                                                       
    

    

    

    

    

    

                                                                                                       
    

    

                                                                                                       
    

    

    

    

                                                                                                       
    

                                                                                                       
    

                                                                                                       
    

                                                                                                       


#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
                                                                                                       


template<typename T1, typename T2> 

istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
                                                                                                       
template<typename T> 

istream& operator>>(istream &istream, vector<T> &v)
{
       for (auto &it : v)
       cin >> it;
    return istream;
}
                                                                                                       
template<typename T1, typename T2> 

ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
                                                                                                       
template<typename T> 

ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
                                                                                                       


template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{
    cout << t << " ";
    print(forward<Args>(args)...);
}
                                                                                                       
                                                                                                       
#define   ll               long long          

#define   ull              unsigned long long 

#define   all(v)           v.begin(), v.end() 
#define   rall(v)          v.rbegin(), v.rend() 
#define   rev(v)           reverse(all(v))
#define   rep(i, m, n)     for (ll i = m; i < n; i++)
#define   rrep(i, m, n)    for (ll i = m-1; i >= n; i--)
#define   inp(i, a)        for (auto &i : a) { cin >> i; }
#define   outp(i, a)       for (auto i : a)  { cout << i << " "; } cout << "\n";
#define   deb(x)           cout << #x << " = " << x << "\n";
#define   deb2(x, y)       cout << #x << " = " << x << " , " << #y << " = " << y << "\n";
#define   YES       cout << "YES" << nl;
#define   yes       cout << "YES" << nl;
#define   NO        cout << "NO" << nl;
#define   no        cout << "NO" << nl;
#define   pb        push_back
#define   mp        make_pair
#define   ff        first
#define   ss        second
#define   lb        lower_bound
#define   ub        upper_bound
#define   sz(x)     (ll) ((x).size()) 
typedef   pair      <int, int>          pii;
typedef   pair      <ll, ll>            pl;
typedef   vector    <int>               vi;
typedef   vector    <ll>                vl;
typedef   vector    <pii>               vpii;
typedef   vector    <pl>                vpl;
typedef   vector    <vi>                vvi;
typedef   vector    <vl>                vvl;
#define   PVS       10'000'010  

#define   MOD       1'000'000'007
#define   INF       1'000'000'000'000'000'000
#define   PI        3.14159265358979323846264338327
#define   SET(n)    cout << fixed << setprecision(n)
#define   flush     cin.clear();  cin.sync(); cin.ignore();
#define   get(s)    getline(cin, s)
#define   clr(x)    memset(x, 0, sizeof(x))         // we will use when we declare a global array and we need to reinitialize this with zero in every loop
#define   mst(x,v)  memset(x, v, sizeof(x))         // will be able to set an array with 0 or -1 and string with all types of characters, so remember this
#define   nl        '\n'
#define   endl      '\n'
#define   ret(x)    cout << x << nl;  return;
                                                                                                       






                                                                                                       






                                                                                                       
void binaryPrinter(ll n){ 

    for(int i=10;i>=0;i--){
        if(n&(1<<i))
            cout<<"1";
        else
            cout<<"0";
    }
}
                                                                                                       
ll startposoflastmountain(ll arr[], ll n){
    ll pos=n-1;
                                                                                                       
    while(pos> 0 && arr[pos-1]>=arr[pos])
        --pos;
    while(pos> 0 && arr[pos-1]<=arr[pos])
        --pos;
                                                                                                       
    return pos;
}
                                                                                                       
bool isPrime(ll n){
    if(n<=1)return false;
    if(n<=3)return true;
    if(n%2==0 || n%3==0)return false;
    for(ll i=5;i*i<=n;i+=6){
        if(n%i==0||n%(i+2)==0)return false;
    }
    return true;
}
                                                                                                       




                                                                                                       












                                                                                                       
ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
                                                                                                       
ll BiexpRec(ll a, ll b){ 

    if(b==0)
        return 1;
    ll res=BiexpRec(a,b/2);
    if(b&1)
        return (a*((res*res)%MOD))%MOD;
    else
        return (res*res)%MOD;
}
                                                                                                       
ll BiexpItr(ll a, ll b){ 

    ll ans=1;
    while(b){
        if(b&1){
            ans=(ans*1LL*a)%MOD;
        }
        a=(a*1LL*a)%MOD;
        b>>=1;
    }
    return ans;
}
                                                                                                       
ull BiexpItr_ETF(ull a, ull b, ull m){ 

    a%=m;
    ull ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%m;
        }
        a=(a*a)%m;
        b>>=1;
    }
    return ans;
}
                                                                                                       
ull sppow_abc(ull a,ull b,ull c,ull m){ 

    return BiexpItr_ETF(a,BiexpItr_ETF(b,c,m-1),m);
    

}
                                                                                                       
ull longBiexpMulitr(ull a, ull b){ 

    ull ans=0;
    while(b){
        if(b&1){
            ans=(ans+a)%MOD;
        }
        a=(a+a)%MOD;
        b>>=1;
    }
    return ans;
}
                                                                                                       
ull longBiexpItr(ull a, ull b){ 

    ull ans=1;
    while(b){
        if(b&1){
            ans=longBiexpMulitr(ans,a);
        }
        a=longBiexpMulitr(a,a);
        b>>=1;
    }
    return ans;
}
                                                                                                       
void simple_prime_factorisation_printer(ll n){
    for(ll i=2;i*i<=n;i++){
        while((n%i)==0){
            cout<<i<<" ";
            n/=i;
        }
    }
                                                                                                       
    if(n>1){
        cout<<n<<" ";
    }
    cout<<endl;
}
                                                                                                       




                                                                                                       
































                                                                                                       






                                                                                                       


















                                                                                                       
ull adividesbmodm(ull a, ull b, ull m){ 

    return ( (a%m) * (BiexpItr_ETF(b,m-2,m)) ) % m;
}
                                                                                                       












                                                                                                       










                                                                                                       
void recursiveSubsetPrinter(string &s, string temp, ll i){ 

    if(i<s.length()){
        temp+=s[i];
        cout<<temp<<endl;
    }
    else{
        return;
    }
                                                                                                       
    recursiveSubsetPrinter(s, temp, i+1);
    temp.pop_back();
    recursiveSubsetPrinter(s, temp, i+1);
}
                                                                                                       
vvl allSubsetsofArr; 
void bitmaskingArraySubsetGenerator(ll a[], ll n){
    ll i, j, k;
    vl temp;
    rep(i,1,(1<<n)){
        temp.clear();
        k=0; j=i;
        while(j>0){
            if((j&(1))==1){
                temp.pb(a[k]);
            }
            ++k;
            j>>=1;
        }
        allSubsetsofArr.pb(temp);
    }
}
                                                                                                       
ll count_max_power_of_2_greaterthan_n( ll n ){ 

    if(n==1)return 0;
    ll res = 0, ans = 1;
    for (ll i = 1; i <=100; i++){
        ans = ans*2;
        if (ans >= n){
            res = i;
            return res;
        }
    }
    return res;
}
                                                                                                       
















                                                                                                       
ll calc_max_alternating_sum_of_subsequence(const vector<ll> &a){
   ll n = a.size();
   vector<ll> d1(n+1), d2(n+1);
   d1[0] = -static_cast<int64_t>(1e18);
   d2[0] = 0;
   for (ll i = 0; i < n; ++i){
       d1[i+1] = max(d1[i], d2[i] + a[i]);
       d2[i+1] = max(d2[i], d1[i] - a[i]);
   }
   return max(d1.back(), d2.back());
}
                                                                                                       
ll pair_diff_k_fun(ll n, ll k, vector <ll> a){ 

    vector <ll> s(n+1);
    rep(i,0,n)
        s[i+1]=s[i]+a[i];
    map <ll,ll> m;
    ll ans=0;
    rep(r,1,n+1){
        m[s[r-1]]++; 

                     

        ans += m[s[r]-k];
    }
    return ans;
}
                                                                                                       




ll findPairs(ll arr[],ll n,ll x)
{
   ll l = 0, r = n-1;
   ll result = 0;
   while (l < r)
   {
        

        

        

        

        if (arr[l] + arr[r] <= x)
        {
            result += (r - l);
            l++;
        }
        

        else
            r--;
    }
    return result;
}
                                                                                                       
void presolve(){
                                                                                                       
}
                                                                                                       
void Solve(){
    ll n,x;
    cin>>n>>x;
    ll a[n];
    ll ans=0;

    ll minv=1e18;
    ll maxv=0;
    rep(i,0,n){
        cin>>a[i];
        if(i){
            ans+=abs(a[i]-a[i-1]);
        }
        minv=min(minv,a[i]);
        maxv=max(maxv,a[i]);
    }



    ans+=(min(2*(minv-1),min(a[0],a[n-1])-1));
    if(x>=maxv)
    ans+=(min(2*(x-maxv),x-max(a[0],a[n-1])));



    ret(ans)


    




    
                                                                                                       
                                                                                                       
                                                                                                       
}
                                                                                                       
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
                                                                                                       
    auto start=chrono::high_resolution_clock::now();
                                                                                                       
    

    

    

    

                                                                                                       
    

    

    

                                                                                                       
    

                                                                                                       
    ull T=1;
    cin>>T;
                                                                                                       
    rep(i,1,T+1){
        

        Solve();
        

    }
                                                                                                       
    auto stop=chrono::high_resolution_clock::now(); 
    auto duration=chrono::duration_cast<chrono::microseconds>(stop-start); 
    

    return 0; 
                                                                                                       
}