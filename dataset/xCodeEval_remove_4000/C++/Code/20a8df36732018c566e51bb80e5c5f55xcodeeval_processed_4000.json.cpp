










using namespace std;


using namespace __gnu_pbds;
template <typename T>
using os = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef double ld;

















template <typename T, size_t N> int SIZE(const T (&t)[N]){ return N; } template<typename T> int SIZE(const T &t){ return t.size(); } string to_string(const string s, int x1=0, int x2=1e9){ return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c){ return string({c}); } template<size_t N> string to_string(const bitset<N> &b, int x1=0, int x2=1e9){ string t = ""; for(int id5 = min(x1,SIZE(b)), id4 = min(x2, SIZE(b)-1); id5 <= id4; ++id5){ t += b[id5] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1=0, int x2=1e9, C... coords); int id0 = 0, id1 = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { id0++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; id0--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(id1, ' '); string res = ""; bool first = true; if(id0 == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; id0++; if(e != l){ if(rnk > 1) { res += n_l; id1 = id0; }; } else{ id1 = 0; } res += to_string(*e, coords...); id0--; } res += "]"; if(id0 == 0) res += n_l; return res; } void dbgm(){;} template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgm(T...); }

clock_t time_p=clock();
std::istream& in(std::cin);
std::ostream& ot(std::cout);
ll mod=1e9+7;
void Auriel()
{
 time_p=clock()-time_p;
 cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}
struct custom_hash {
 static uint64_t splittpix64(uint64_t x) {

 x += 0x9e3779b97f4a7c15;
 x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
 x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
 return x ^ (x >> 31);
 }

 size_t operator()(uint64_t x) const {
 static const uint64_t id3 = chrono::steady_clock::now().time_since_epoch().count();
 return splittpix64(x + id3);
 }
};
template <typename R>
void println(R r){
 for(auto i:r)
 cout<<i<<" ";
 cout<<endl;

}
template <typename R>
void print(R r){
 int e=0;
 for(auto i:r)
 cout<<i<<endl;
}
template <typename R>
void id2(R &r){
 for(auto &i:r)
 cin>>i;
}
template <typename... R>
void read(R&... args){
 ((cin>>args),...);
}
template <typename... R>
void write(R&... args){
 ((cout<<args),...);
}
template <typename T>
T inverse(T a, T m) {
 T u = 0, v = 1;
 while (a != 0) {
 T t = m / a;
 m -= t * a;
 swap(a, m);
 u -= t * v;
 swap(u, v);
 }
 assert(m == 1);
 return u;
}

template <typename T>
class Modular {
public:
 using Type = typename decay<decltype(T::value)>::type;

 constexpr Modular() : value() {}
 template <typename U>
 Modular(const U& x) {
 value = normalize(x);
 }

 template <typename U>
 static Type normalize(const U& x) {
 Type v;
 if (-mod() <= x && x < mod())
 v = static_cast<Type>(x);
 else
 v = static_cast<Type>(x % mod());
 if (v < 0) v += mod();
 return v;
 }

 const Type& operator()() const { return value; }
 template <typename U>
 explicit operator U() const {
 return static_cast<U>(value);
 }
 constexpr static Type mod() { return T::value; }

 Modular& operator+=(const Modular& other) {
 if ((value += other.value) >= mod()) value -= mod();
 return *this;
 }
 Modular& operator-=(const Modular& other) {
 if ((value -= other.value) < 0) value += mod();
 return *this;
 }
 template <typename U>
 Modular& operator+=(const U& other) {
 return *this += Modular(other);
 }
 template <typename U>
 Modular& operator-=(const U& other) {
 return *this -= Modular(other);
 }
 Modular& operator++() { return *this += 1; }
 Modular& operator--() { return *this -= 1; }
 Modular operator++(int) {
 Modular result(*this);
 *this += 1;
 return result;
 }
 Modular operator--(int) {
 Modular result(*this);
 *this -= 1;
 return result;
 }
 Modular operator-() const { return Modular(-value); }

 template <typename U = T>
 typename enable_if<is_same<typename Modular<U>::Type, int>::value,
 Modular>::type&
 operator*=(const Modular& rhs) {

 uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
 uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x),
 d, m;
 asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(mod()));
 value = m;

 value = normalize(static_cast<int64_t>(value) *
 static_cast<int64_t>(rhs.value));

 return *this;
 }
 template <typename U = T>
 typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value,
 Modular>::type&
 operator*=(const Modular& rhs) {
 int64_t q = static_cast<int64_t>(static_cast<long double>(value) *
 rhs.value / mod());
 value = normalize(value * rhs.value - q * mod());
 return *this;
 }
 template <typename U = T>
 typename enable_if<!is_integral<typename Modular<U>::Type>::value,
 Modular>::type&
 operator*=(const Modular& rhs) {
 value = normalize(value * rhs.value);
 return *this;
 }

 Modular& operator/=(const Modular& other) {
 return *this *= Modular(inverse(other.value, mod()));
 }

 template <typename U>
 friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

 template <typename U>
 friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

 template <typename U>
 friend std::istream& operator>>(std::istream& stream, Modular<U>& number);

private:
 Type value;
};

template <typename T>
bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) {
 return lhs.value == rhs.value;
}
template <typename T, typename U>
bool operator==(const Modular<T>& lhs, U rhs) {
 return lhs == Modular<T>(rhs);
}
template <typename T, typename U>
bool operator==(U lhs, const Modular<T>& rhs) {
 return Modular<T>(lhs) == rhs;
}

template <typename T>
bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) {
 return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(const Modular<T>& lhs, U rhs) {
 return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(U lhs, const Modular<T>& rhs) {
 return !(lhs == rhs);
}

template <typename T>
bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) {
 return lhs.value < rhs.value;
}

template <typename T>
Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) {
 return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(const Modular<T>& lhs, U rhs) {
 return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T>& rhs) {
 return Modular<T>(lhs) += rhs;
}

template <typename T>
Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) {
 return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(const Modular<T>& lhs, U rhs) {
 return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T>& rhs) {
 return Modular<T>(lhs) -= rhs;
}

template <typename T>
Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) {
 return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(const Modular<T>& lhs, U rhs) {
 return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T>& rhs) {
 return Modular<T>(lhs) *= rhs;
}

template <typename T>
Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) {
 return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(const Modular<T>& lhs, U rhs) {
 return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T>& rhs) {
 return Modular<T>(lhs) /= rhs;
}

template <typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
 assert(b >= 0);
 Modular<T> x = a, res = 1;
 U p = b;
 while (p > 0) {
 if (p & 1) res *= x;
 x *= x;
 p >>= 1;
 }
 return res;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
 return stream << number();
}

template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
 typename common_type<typename Modular<T>::Type, int64_t>::type x;
 stream >> x;
 number.value = Modular<T>::normalize(x);
 return stream;
}




struct LCA {
 vector<int> height, euler, first, segtree;
 vector<bool> visited;
 int n;

 LCA(vector<vector<int>> &adj, int root = 0) {
 n = adj.size();
 height.resize(n);
 first.resize(n);
 euler.reserve(n * 2);
 visited.assign(n, false);
 dfs(adj, root);
 int m = euler.size();
 segtree.resize(m * 4);
 build(1, 0, m - 1);
 }

 void dfs(vector<vector<int>> &adj, int node, int h = 0) {
 visited[node] = true;
 height[node] = h;
 first[node] = euler.size();
 euler.push_back(node);
 for (auto to : adj[node]) {
 if (!visited[to]) {
 dfs(adj, to, h + 1);
 euler.push_back(node);
 }
 }
 }

 void build(int node, int b, int e) {
 if (b == e) {
 segtree[node] = euler[b];
 } else {
 int mid = (b + e) / 2;
 build(node << 1, b, mid);
 build(node << 1 | 1, mid + 1, e);
 int l = segtree[node << 1], r = segtree[node << 1 | 1];
 segtree[node] = (height[l] < height[r]) ? l : r;
 }
 }

 int query(int node, int b, int e, int L, int R) {
 if (b > R || e < L)
 return -1;
 if (b >= L && e <= R)
 return segtree[node];
 int mid = (b + e) >> 1;

 int left = query(node << 1, b, mid, L, R);
 int right = query(node << 1 | 1, mid + 1, e, L, R);
 if (left == -1) return right;
 if (right == -1) return left;
 return height[left] < height[right] ? left : right;
 }

 int lca(int u, int v) {
 int left = first[u], right = first[v];
 if (left > right)
 swap(left, right);
 return query(1, 0, euler.size() - 1, left, right);
 }
};

ll st[200005]={0},ft[200005]={0},parent[200005],tt=0,level[200005]={0},fans=0;
ll binexp(ll a,ll b,ll m)
{
 ll ans=1;
 while(b)
 {
 if(b&1)
 ans=(ans*a)%m;
 b/=2;
 a=(a*a)%m;
 }
 return ans;
}
ll dp[50001][501]={0};
void dfs(vector<ll> graph[],ll start,ll *visit){
 visit[start]=1;
 

 st[start]=tt;
 tt++;
 dp[start][0]=1;
 for(auto child:graph[start]){
 if(!visit[child]){
 

 parent[child]=start;
 

 dfs(graph, child, visit);
 rep(i,1,501){
 dp[start][i]+=dp[child][i-1];
 }
 }


 }
 ft[start]=tt;

}
ll depth[200005];
void make_set(int v) {
 parent[v] = v;
 depth[v] = 0;
}
int find_set(int v) {
 if (v == parent[v])
 return v;
 return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
 a = find_set(a);
 b = find_set(b);
 if (a != b) {
 if (depth[a] < depth[b])
 swap(a, b);
 parent[b] = a;
 if (depth[a] == depth[b])
 depth[a]++;
 }
}
void id7(vector<pair<ll,ll> > graph[],ll start,ll *visit,ll *cost){
 cost[start]=0;
 

 multiset<pair<ll,ll> > ms;
 ms.insert({0,start});
 while(ms.size()!=0){
 pair<ll,ll> p=*ms.begin();
 ms.erase(ms.begin());
 ll x=p.second; 

 if(visit[x]==1)
 continue;
 visit[x]=1;
 for(int i=0;i<graph[x].size();i++){
 ll e=graph[x][i].first; ll w=graph[x][i].second;
 if(cost[x]+w<cost[e]) {
 cost[e] = w + cost[x];
 ms.insert({cost[e],e});

 }

 }
 }
}
int id6(vector<ll> graph[],ll *visit,ll *level,ll start,ll k,ll n){
 queue<ll> q;
 ll pans=0;
 ll nvisit[n+1]; memset(nvisit,0,sizeof(nvisit));
 

 q.push(start);
 level[start]=0;
 visit[start]=1;
 while(q.size()!=0){
 ll p=q.front();
 q.pop();
 visit[p]=1;
 ll cnt=0; ll tans=0;
 for(auto it=graph[p].begin();it!=graph[p].end();it++){
 if(visit[*it]==1) continue;
 if(visit[(*it)]!=1){
 q.push((*it));
 level[*it]=level[p]+1;
 ll par=parent[*it];
 auto child=*it;

 if(par!=child&&parent[par]!=child){
 if(k-2>=0){
 tans+=dp[child][k-2];
 cnt++;
 }
 

 

 }


 }
 }
 if(cnt!=0)
 pans+=(tans/2 );
 dbgm(cnt);

 }
 return pans;
}
constexpr ll md = 1e18;

using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
ll final_ans=0;
void dfs1(vector<ll> graph[],ll start,ll *visit,ll k){
 visit[start]=1;
 

 st[start]=tt;
 tt++;
 

 for(auto child:graph[start]){
 if(!visit[child]){
 

 parent[child]=start;
 

 dfs1(graph, child, visit,k);
 rep(i,1,501){

 if(k-i-1>=0&&i-1>=0){
 assert((dp[child][i-1]*(dp[start][k-i]-dp[child][k-i-1]))>=0);
 final_ans+=(dp[child][i-1]*(dp[start][k-i]-dp[child][k-i-1]));
 }
 }

 }


 }
 ft[start]=tt;

 }
int main() {
 ios
 ll n,k; in>>n>>k; ll m=n-1; vi graph[n+1];
 while(m--){
 ll x,y; in>>x>>y;
 graph[x].pb(y);
 graph[y].pb(x);
 }
 ll ans=0; ll visit[n+1]; memset(visit,0,sizeof(visit));
 dfs(graph,1,visit);
 rep(i,1,n+1){
 ans+=dp[i][k];
 }
 memset(visit,0,sizeof(visit));
 ll pans=0;
 

 

 

 

 

 

 

 

 

 

 

 dfs1(graph,1,visit,k);
 ot<<ans+(final_ans)/2<<el;
 

 

 

 

 

 

 





}

