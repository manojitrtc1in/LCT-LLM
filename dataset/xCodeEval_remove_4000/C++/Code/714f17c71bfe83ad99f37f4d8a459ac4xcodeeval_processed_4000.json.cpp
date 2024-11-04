





using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<db,db> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;


























const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

























int clearbit(int mask,int bit){
    return mask & ~(1<<bit);
}
int togglebit(int mask,int bit){
    return mask ^ (1<<bit);
}
int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}
int botbit(signed a){
	return a==0?32:__builtin_ctz(a);
}
int botbit(ll a){
	return a==0?64:__builtin_ctzll(a);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
bool id0(int i){
	return i&&(i&-i)==i;
}


void yes(bool ex=true){
	
	cout<<"YES"<<"\n";
	
	cout<<"Yes"<<"\n";
	
	if(ex)exit(0);
}
void no(bool ex=true){
	
	cout<<"NO"<<"\n";
	
	cout<<"No"<<"\n";
	
	if(ex)exit(0);
}
void possible(bool ex=true){
	
	cout<<"POSSIBLE"<<"\n";
	
	cout<<"Possible"<<"\n";
	
	if(ex)exit(0);
}
void impossible(bool ex=true){
	
	cout<<"IMPOSSIBLE"<<"\n";
	
	cout<<"Impossible"<<"\n";
	
	if(ex)exit(0);
}
template<typename T> bool checkbit(T mask, T bit){
    return mask & (((T)1)<<bit);
}
template<typename T> T setbit(T mask, T bit){
    return mask | (((T)1)<<bit);
}

template <typename T> T BigMod (T b,T p,T m){
    if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;
}
template <typename T> T ModInv (T b,T m){
    return BigMod(b,m-2,m);
}
template <typename T> T POW(T B,T P){
    if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));
}
template <typename T> T Bigmod(T b,T p,T m){
    if(p==0) return 1; else if (!(p&1)) return SQR(Bigmod(b,p/2,m)) % m;else return ((b % m) * Bigmod(b,p-1,m)) % m;
}
template <typename T> T Dis(T x1,T y1,T x2, T y2){
    return sqrt( SQR(x1-x2) + SQR(y1-y2) );
}
template <typename T> T Angle(T x1,T y1,T x2, T y2){
    return atan( double(y1-y2) / double(x1-x2));
}
template <typename T> T DIFF(T a,T b) {
    T d = a-b;if(d<0)return -d;else return d;
}
template <typename T> T ABS(T a) {
    if(a<0)return -a;else return a;
}
template <typename T> T id1(T a,T b,T &x,T &y) {
    if(a<0){T d=id1(-a,b,x,y);x=-x;return d;}
    if(b<0){T d=id1(a,-b,x,y);y=-y;return d;}
    if(b==0){x=1;y=0;return a;}
    else{T d=id1(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}
}
template <typename T> T gcd(T a,T b){
    if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);
}
template <typename T> T lcm(T a,T b) {
    if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));
}

template<class t>
int lwb(const vector<t>&v,const t&a){
	return lower_bound(all(v),a)-v.begin();
}

template<typename A, typename B>
class Dijkstra {
public:
    vector<vector<pair<int, A>>> vertexs;
    vector<int>par;
    B Cost_Function;
    Dijkstra(int n, B cost) : Cost_Function(cost) {
        vertexs = vector<vector<pair<int, A>>>(n, vector<pair<int, A>>{});
        par = vector<int>(n);
    }
    ~Dijkstra() {
        vertexs.clear();
    }
    void add_edge(int a, int b, A c) {
        vertexs[a].push_back(make_pair(b, c));
    }
    void clr(){par.clear(); }
    vector<ll> build_result(int StartPoint) {
        vector<ll> dist(vertexs.size(), 2e18);
        dist[StartPoint] = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> next;
        next.push(make_pair(0, StartPoint));
        while (next.empty() == false) {
            pair<ll, int> now = next.top();
            next.pop();
            if (dist[now.second] != now.first) continue;
            for (auto x : vertexs[now.second]) {
                ll now_cost = now.first + x.second;

                if (dist[x.first] > now_cost) {
                    dist[x.first] = now_cost;
                    par[x.first] = now.second;
                    next.push(make_pair(now_cost, x.first));
                }
            }
        }
        return dist;
    }
};

string to_string(char c) {
	return string(1, c);
}
string to_string(bool b) {
	return b?"true":"false";
}
string to_string(const char* s) {
	return string(s);
}
string to_string(string s) {
	return s;
}

void DBG() {
	cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	DBG(t...);
}







const ll MOD = 998244353;

ll domd(ll x) {
    return x - (MOD*(x/MOD));
}
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
ll rev(ll x) {
	return bin_pow(x, MOD - 2);
}




const ll nax=300050;
ll n,w,m;
ll ar[nax];
struct node{
    ll rpln,rnlp;
    ll po,ne;
};
node tr[nax*4];


























































void bld(ll aT,ll l,ll r){
    if(l==r){
        tr[aT].rpln=0;
        tr[aT].rnlp=0;
        tr[aT].po=ar[l];
        tr[aT].ne=-ar[l];
        return;
    }
    ll mid=(l+r)>>1;
    ll L=aT*2,R=(aT*2)+1;
    bld(L,l,mid);
    bld(R,mid+1,r);
    tr[aT].rnlp=max(tr[L].po+tr[R].ne,max(max(tr[L].rnlp,tr[R].rnlp),tr[L].rnlp+tr[R].rnlp));
    tr[aT].po=max(tr[L].rnlp+tr[R].po,max(tr[L].po+tr[R].rpln,max(tr[L].po,tr[R].po)));
    tr[aT].ne=max(tr[L].rpln+tr[R].ne,max(tr[L].ne+tr[R].rnlp,max(tr[L].ne,tr[R].ne)));
    tr[aT].rpln=max(tr[L].ne+tr[R].po,max(max(tr[L].rpln,tr[R].rpln),tr[L].rpln+tr[R].rpln));
}
void upd(ll aT,ll l,ll r,ll p,ll u){
    if(l==r){
        ar[l]+=u;
        tr[aT].rpln=0;
        tr[aT].rnlp=0;
        tr[aT].po=ar[l];
        tr[aT].ne=-ar[l];
        return;
    }ll mid=(l+r)>>1;
    ll L=aT*2,R=(aT*2)+1;
    if(p<=mid) upd(aT*2,l,mid,p,u);
    else upd((aT*2)+1,mid+1,r,p,u);
    tr[aT].rnlp=max(tr[L].po+tr[R].ne,max(max(tr[L].rnlp,tr[R].rnlp),tr[L].rnlp+tr[R].rnlp));
    tr[aT].po=max(tr[L].rnlp+tr[R].po,max(tr[L].po+tr[R].rpln,max(tr[L].po,tr[R].po)));
    tr[aT].ne=max(tr[L].rpln+tr[R].ne,max(tr[L].ne+tr[R].rnlp,max(tr[L].ne,tr[R].ne)));
    tr[aT].rpln=max(tr[L].ne+tr[R].po,max(max(tr[L].rpln,tr[R].rpln),tr[L].rpln+tr[R].rpln));
}
ll dpt[2][1000];
ll dp(){
    ll i,j,k;
    for(i=0;i<2;i++)FOR(j,0,n+5)dpt[i][j]=0;
    for(i=n;i>=1;i--){
        dpt[0][i]=max(ar[i]+dpt[1][i+1],dpt[0][i+1]);
        dpt[1][i]=max(dpt[0][i+1]-ar[i],dpt[1][i+1]);
    }return dpt[0][1];
}
void solve()
{
    ll a,b,c,q,j,k,l,mx=0,i;
    ll hn,hm,gc,sx,sy,ex=1,ey=-1;
    scll(n,q);
    FOR(i,1,n+1)scl(ar[i]);
    

    bld(1,1,n);
    hm=max(max(tr[1].rnlp,tr[1].rpln),max(tr[1].po,tr[1].ne));
    cout<<hm<<'\n';
    while(q--){
        scll(a,b);
        sx=ar[b]-ar[a];
        sy=ar[a]-ar[b];
        upd(1,1,n,a,sx);
        upd(1,1,n,b,sy);
        hm=max(max(tr[1].rnlp,tr[1].rpln),max(tr[1].po,tr[1].ne));
        cout<<hm<<'\n';
    }
}
int main()
{
    

    
    READ;
    WRITE;
    

    clock_t tStart = clock();
    ll t=1,mex=1;
    cin>>t;
    while(t--){
        solve();
    }
    

    return 0;
}
