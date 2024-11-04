























































 
using namespace std;
 
typedef long long int ll;
typedef double lf;
typedef long double llf;
typedef unsigned long long int ull;
typedef vector<ll> vll;
typedef vector<vector<ll> > v2d;
typedef vector<vector<vector<ll> > > v3d;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef map<ll,ll> mpl;
typedef priority_queue<ll> heap;

typedef priority_queue<ll, vector<ll>, greater<ll> > revheap;

 


 
bool isLetter(char c) { return (c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z');}
bool id12(char c) {return c >= 'A' and c <= 'Z';}
bool id21(char c) {    return c >= 'a' and c <= 'z';}
bool isDigit(char c) {return c >= '0' and c <= '9';}
bool id5(char c) {return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';}
bool id17(char c){    return !id5(c); }
 
Tp void Debug(T v) { for(int i=0; i<(int)v.size(); i++)  cout << v[i] <<" ";   cout<<endl;  }
 
Tp void Input(T &v){ for(int i=0; i<(int)v.size(); i++) cin >> v[i]; }
 
Tp string toString(T n) { ostringstream ost; ost << n; ost.flush(); return ost.str();}
 


string id11(int x) { std::string binary = std::bitset<32>(x).to_string(); return binary;}
string id1(ll x)  {std::string binary = std::bitset<64>(x).to_string(); return binary;}
ll toNumber(string s) {stringstream aa(s);ll mm;aa>>mm; return mm;}
ll id15(string n) { string num = n; ll dec_value = 0; ll base = 1; ll len = num.length(); for (int i = len - 1; i >= 0; i--) { if (num[i] == '1') dec_value += base; base = base * 2; } return dec_value;}
 


 
Tpp T nCr(T n, T r) { if(r > n - r) r = n - r; int  ans = 1,i;for(i = 1; i <= r; i++) { ans *= n - r + i; ans /= i; }  return ans; }
 


ll Binpow(ll a, ll p){ ll ret = 1; while(p>0){ if(p & 1)ret = (1LL * ret * a) ; a = (1LL * a * a) ; p >>= 1LL; } return ret; }
 


template<typename A, typename P>
ll BigMod(A a, P p, ll mod){ ll ret = 1; while(p){ if(p & 1)ret = ( (ret%mod) * (a%mod)) % mod; a = ( (a%mod) * (a%mod)) % mod; p >>= 1LL; } return ret; }
 


Tpp T toBase(T n, T base){T ret= 0LL; while(n){ ret += n % base; ret *= 10LL;  n /= base;} return ret;}
 


 
Tpp  vector<T> Divisor(T value){ vector<T> v; for(int i = 1LL; i * i <= value; ++i){
    if(value % i == 0){v.push_back(i); if(i * i != value) v.push_back(value / i);} } return v;}
 


 
Tpp  bool prime(T n){  if(n==2) return 1; if (n % 2 == 0) return 0; for (T i = 3; i*i <= n; i += 2){if (n % i == 0) return 0;}return 1;}
 


Tpp  void Sieve(T n){bool prime[n+1];memset(prime, true, sizeof(prime));
     for (T p=2; p*p<=n; p++){ if (prime[p] == true){
            for (int i=p*p; i<=n; i += p) prime[i] = false;} } }


 
Tpp   ll sum(std::vector<T> &v){return std::accumulate(all(v), 0);}
Tpp   T minval(std::vector<T> &v){return *std::min_element(all(v));}
Tpp   T maxval(std::vector<T> &v){return *std::max_element(all(v));}
Tpp   void make_unique(std::vector<T> &v){v.resize(unique(all(v)) - v.begin());}
Tpp   void id6(std::vector<T> &v){asort(v);v.resize(unique(all(v)) - v.begin());}
Tpp   int lowerBound(std::vector<T> &v, T x){return v.back() < x ? -1 : lower_bound(all(v), x) - v.begin();}
Tpp   int upperBound(std::vector<T> &v, T x){return v.back() < x ? -1 : upper_bound(all(v), x) - v.begin();}
 
double startTime = clock();
void id4(){ printf("%.6lf\n", ((double)clock() - startTime) / CLOCKS_PER_SEC);}
 
 
 


ll id18(ll decimalvalue, int pos)  { return (decimalvalue | (1 << pos));}    

ll id20(ll decimalvalue, int pos) {return (decimalvalue & ~(1 << pos));}    

ll FlipBit(ll decimalvalue, int pos)     { return (decimalvalue ^ (1 << pos));}    

bool CheckBit(ll decimalvalue, int pos) { return (decimalvalue & (1 << pos)); }
int MSB(ll k)  { return ( 63 - __builtin_clzll(k));}    

int LSB(ll k)  { return __builtin_ffs(k)-1 ;}    

int Totalset(ll decimalvalue)  {return __builtin_popcountll(decimalvalue); }   

 
int id19(ll decimalvalue) { return MSB(decimalvalue) - Totalset(decimalvalue) + 1;}    

bool id8(int i) { return i&&(i&-i)==i; }
 
ll id16(ll n) { return (n * (n - 1)) / 2;}
ll nc3(ll n){ return (n * (n - 1) * (n - 2)) / 6; }
ll arithsum(ll n, ll a = 1, ll d = 1){ return (n * (a + a + (n - 1) * d) ) / 2; }
ll LCM(ll a, ll b){return (a / __gcd(a, b) ) * b;}
ll id3(ll n){return (n*(n+1))/2;}
ll longdivision(string s,ll a){ ll ans=0; ll temp=0; rep(i,0,s.length()){ temp=temp*10+(s[i]-'0');ans+=(temp/a);ans*=10;temp=temp%a;}return (ans/10);}
 
 
const long long int INF=id2;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const double id9=asin(1.0);
const int MOD = 1e9 + 7;
 


Tppp void dvpll(vector<pair<T1,T2> > v) { for(ll i=0;i<v.size();i++){deb(i);deb(v[i].F);deb(v[i].S);cout<<endl;}}
void dpos(vll v,ll pos){ cout<<pos<<"="<<v[pos]<<endl; }
Tppp void dmap(map<T1,T2> m) {ll i=0;for(auto x:m) {deb(i);deb(x.F);deb(x.S);cout<<endl;i++;}}
Tpp void dset(set<T> s) {for(auto x:s) {deb(x);cout<<endl;}}
Tpp void dmset(multiset<T> s) {for(auto x:s) {deb(x);cout<<endl;}}
 
Tpp void dpqueue(priority_queue<T> pq) {while(!pq.empty()){deb(pq.top());pq.pop();}    }
Tpp void dstack(stack<T> st) {while(!st.empty()) {deb(st.top());st.pop();}}
Tpp void dqueue(queue<T> q) {while(!q.empty()){ deb(q.front());q.pop(); }}
 
void dgraph(vector<ll> adj[],ll node){rep(i,0,node+1){deb(i);rep(j,0,adj[i].size()) {cout<<adj[i][j]<<" ";}cout<<endl;}cout<<endl;}
 
Tpp void id10(vector<T> v){for(ll i=0;i<v.size();i++){ cout<<v[i]<<" "; }cout<<endl;}
Tpp void id13(vector<vector<T> >&v,ll n,ll m) {cout<<"2d: "<<endl;for(ll i=0;i<n;i++){for(ll j=0;j<m;j++){cout<<v[i][j]<<" ";}cout<<endl;}}
Tpp void id7(vector<vector<vector<T> > > &v,ll p,ll q,ll r){cout<<"3d: "<<endl;for(ll i=0; i<p; i++){for(ll j=0; j<q; j++){for(ll k=0; k<r; k++){cout<<"v[i="<<i<<"][j="<<j<<"][k="<<k<<"]=";cout<<v[i][j][k]<<endl;}}}}
 
 
 


 
 
 
 


 
Tpp void Rvec(vector<T> &v,ll n){rep(i,0,n){T d;cin>>d;v.pb(d);}}
Tppp void Rvpll(vector<pair<T1,T2> > &v,ll n){rep(i,0,n){T1 a;T2 b;cin>>a>>b;v.pb(mp(a,b));} }
void Rgraph(vector<ll> adj[],ll edge ,ll indexbase ,bool directed ){rep(i,0,edge){ll a,b;cin>>a>>b;if(indexbase==0){a--;b--;}adj[a].pb(b);if(directed==0){adj[b].pb(a);}}}
 
 
 


 


 




 


 






 
 
 


































 
const ll NN=2e5+10;
ll tree[4*NN+1];
ll tp[4*NN+1];
ll arr[NN];


void init(ll n)
{
    for(ll i=0;i<=n;i++)
    {
        arr[i]=0;
    }
    for(ll i=0;i<=4*n+1;i++)
    {
        tree[i]=0;
        tp[i]=0;
    }
 
}
 
void Build(ll node,ll left,ll right)
{
 
    if(left==right)
    {
        tree[node]=arr[left];return;
    }
    ll id0=node*2;
    ll id14=node*2+1;
    ll mid=(left+right)/2;
    Build(id0,left,mid);
    Build(id14,mid+1,right);
    tree[node]=(tree[id0]^tree[id14]);
}
 
ll Query(ll node,ll left,ll right,ll i,ll j)
{
     if(i>right || j<left) return 0;
     if(left>=i && right<=j) return tree[node];
     ll mid=(left+right)/2;
     ll p1=Query(2*node,left,mid,i,j);
     ll p2=Query(2*node+1,mid+1,right,i,j);
     return (p1^p2);
}
 
void Update(ll node,ll left,ll right,ll idx,ll val)
{
     if(idx>right || idx<left) return;
     if(left>=idx && right<=idx)
     {
         tree[node]=val;
         return;
     }
     ll mid=(left+right)/2;
     Update(node*2,left,mid,idx,val);
     Update(node*2+1,mid+1,right,idx,val);
     tree[node]=(tree[2*node]^tree[2*node+1]);
 
}
 
void debugarr(ll n)
{
    cout<<"haire:";
    for(ll i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
 
 
 
 
void Build2(ll node,ll left,ll right)
{
 
    if(left==right)
    {
        tp[node]=arr[left];return;
    }
    ll id0=node*2;
    ll id14=node*2+1;
    ll mid=(left+right)/2;
    Build2(id0,left,mid);
    Build2(id14,mid+1,right);
    tp[node]=(tp[id0]+tp[id14]);
}
 
ll Query2(ll node,ll left,ll right,ll i,ll j)
{
     if(i>right || j<left) return 0;
     if(left>=i && right<=j) return tp[node];
     ll mid=(left+right)/2;
     ll p1=Query2(2*node,left,mid,i,j);
     ll p2=Query2(2*node+1,mid+1,right,i,j);
     return (p1+p2);
}
 
void Update2(ll node,ll left,ll right,ll idx,ll val)
{
     if(idx>right || idx<left) return;
     if(left>=idx && right<=idx)
     {
         tp[node]=val;
         return;
     }
     ll mid=(left+right)/2;
     Update2(node*2,left,mid,idx,val);
     Update2(node*2+1,mid+1,right,idx,val);
     tp[node]=(tp[2*node]+tp[2*node+1]);
 
}
 
 
 
 
int main()
{
    FF;
 
 
        ll n,q;cin>>n>>q;
        vll v;
        init(n+5);
        const ll PS=2;
        map<ll,vector<ll>[PS] > mm;
 
        ll s=0;
 
        

 
        vll pref(n+2,0);
        pref[0]=0;
        rep(i,0,n)
        {
            cin>>arr[i+1];
            s^=arr[i+1];
            pref[i+1]=s;
            ll par=(i+1)%2;
            mm[s][par].pb(i+1);
        }
        Build(1,1,n);
        Build2(1,1,n);
 
        rep(i,0,q)
        {
            ll left,right;cin>>left>>right;
            

            ll dif=(right-left+1);
            ll ff=Query2(1,1,n,left,right);
            if(dif%2==1)
            {
                ll ff=Query2(1,1,n,left,right);
                

                if(ff==0)
                {
                    cout<<"0\n";
                }
                else if(Query(1,1,n,left,right)==0)
                {
                    cout<<"1\n";
                }
                else cout<<"-1\n";
            }
            else
            {
 
                ll val1=Query(1,1,n,left,right);
                

 
 
 
                if(ff==0) {cout<<"0\n";continue;}
                

                if(val1==0)
                {
 
 
 
                    ll par=(left)%2;
 
 
                    ll sizere=mm[pref[left-1]][par].size();
 
                    ll posi=upper_bound(all(mm[pref[left-1]][par]),(left))-mm[pref[left-1]][par].begin();
                    
                    

 
                    if(arr[left]==0 || arr[right]==0)
                    {
                        cout<<"1\n";continue;
                    }
                    else if(sizere==posi) {cout<<"-1\n";continue;}
                    ll pos=mm[pref[left-1]][par][posi];
                    if(pos>right) cout<<"-1\n";
                    else cout<<"2\n";
                }
                else cout<<"-1\n";
            }
 
        }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
    return 0;
}
 