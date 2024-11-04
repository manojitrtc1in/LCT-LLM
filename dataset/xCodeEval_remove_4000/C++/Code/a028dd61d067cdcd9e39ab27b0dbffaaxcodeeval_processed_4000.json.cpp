
























































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
bool id11(char c) {return c >= 'A' and c <= 'Z';}
bool id19(char c) {    return c >= 'a' and c <= 'z';}
bool isDigit(char c) {return c >= '0' and c <= '9';}
bool id4(char c) {return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';}
bool id15(char c){    return !id4(c); }

Tp void Debug(T v) { for(int i=0; i<(int)v.size(); i++)  cout << v[i] <<" ";   cout<<endl;  }

Tp void Input(T &v){ for(int i=0; i<(int)v.size(); i++) cin >> v[i]; }

Tp string toString(T n) { ostringstream ost; ost << n; ost.flush(); return ost.str();}



string id10(int x) { std::string binary = std::bitset<32>(x).to_string(); return binary;}
string id0(ll x)  {std::string binary = std::bitset<64>(x).to_string(); return binary;}
ll toNumber(string s) {stringstream aa(s);ll mm;aa>>mm; return mm;}
ll id13(string n) { string num = n; ll dec_value = 0; ll base = 1; ll len = num.length(); for (int i = len - 1; i >= 0; i--) { if (num[i] == '1') dec_value += base; base = base * 2; } return dec_value;}




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
Tpp   void id5(std::vector<T> &v){asort(v);v.resize(unique(all(v)) - v.begin());}
Tpp   int lowerBound(std::vector<T> &v, T x){return v.back() < x ? -1 : lower_bound(all(v), x) - v.begin();}
Tpp   int upperBound(std::vector<T> &v, T x){return v.back() < x ? -1 : upper_bound(all(v), x) - v.begin();}

double startTime = clock();
void id3(){ printf("%.6lf\n", ((double)clock() - startTime) / CLOCKS_PER_SEC);}





ll id16(ll decimalvalue, int pos)  { return (decimalvalue | (1 << pos));}    

ll id18(ll decimalvalue, int pos) {return (decimalvalue & ~(1 << pos));}    

ll FlipBit(ll decimalvalue, int pos)     { return (decimalvalue ^ (1 << pos));}    

bool CheckBit(ll decimalvalue, int pos) { return (decimalvalue & (1 << pos)); }
int MSB(ll k)  { return ( 63 - __builtin_clzll(k));}    

int LSB(ll k)  { return __builtin_ffs(k)-1 ;}    

int Totalset(ll decimalvalue)  {return __builtin_popcountll(decimalvalue); }   


int id17(ll decimalvalue) { return MSB(decimalvalue) - Totalset(decimalvalue) + 1;}    

bool id7(int i) { return i&&(i&-i)==i; }

ll id14(ll n) { return (n * (n - 1)) / 2;}
ll nc3(ll n){ return (n * (n - 1) * (n - 2)) / 6; }
ll arithsum(ll n, ll a = 1, ll d = 1){ return (n * (a + a + (n - 1) * d) ) / 2; }
ll LCM(ll a, ll b){return (a / __gcd(a, b) ) * b;}
ll id2(ll n){return (n*(n+1))/2;}
ll longdivision(string s,ll a){ ll ans=0; ll temp=0; rep(i,0,s.length()){ temp=temp*10+(s[i]-'0');ans+=(temp/a);ans*=10;temp=temp%a;}return (ans/10);}


const long long int INF=id1;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const double id8=asin(1.0);
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

Tpp void id9(vector<T> v){for(ll i=0;i<v.size();i++){ cout<<v[i]<<" "; }cout<<endl;}
Tpp void id12(vector<vector<T> >&v,ll n,ll m) {cout<<"2d: "<<endl;for(ll i=0;i<n;i++){for(ll j=0;j<m;j++){cout<<v[i][j]<<" ";}cout<<endl;}}
Tpp void id6(vector<vector<vector<T> > > &v,ll p,ll q,ll r){cout<<"3d: "<<endl;for(ll i=0; i<p; i++){for(ll j=0; j<q; j++){for(ll k=0; k<r; k++){cout<<"v[i="<<i<<"][j="<<j<<"][k="<<k<<"]=";cout<<v[i][j][k]<<endl;}}}}












Tpp void Rvec(vector<T> &v,ll n){rep(i,0,n){T d;cin>>d;v.pb(d);}}
Tppp void Rvpll(vector<pair<T1,T2> > &v,ll n){rep(i,0,n){T1 a;T2 b;cin>>a>>b;v.pb(mp(a,b));} }
void Rgraph(vector<ll> adj[],ll edge ,ll indexbase ,bool directed ){rep(i,0,edge){ll a,b;cin>>a>>b;if(indexbase==0){a--;b--;}adj[a].pb(b);if(directed==0){adj[b].pb(a);}}}






























































int main()
{
    FF;
    ll tc;cin>>tc;
    while(tc--)
    {
        ll n;cin>>n;
        ll odd=0;
        rep(i,0,n)
        {
            ll d;cin>>d;
            if(d&1) odd++;
        }
        ll even=n-odd;
        ll pabe=Ceil(odd*0.5);
        

        if(pabe%2==1 && odd/2!=pabe)
        {
            if(even%2==0)
            {
                cout<<"Bob\n";
            }
            else
            {
                cout<<"Alice\n";
            }continue;
        }

        if(odd%2==0)
        {
            if((odd/2)%2==1)
            {
                cout<<"Bob\n";
            }
            else
            {
                cout<<"Alice\n";
            }
            continue;
        }
        cout<<"Alice\n";
    }














    return 0;
}



