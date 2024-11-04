



















using namespace std;
 





 


using namespace __gnu_pbds;
 
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 







 
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}




 



 



 









 



 
 
 
template<class T> bool umin(T& a, const T& b) {
	return b<a?a=b, 1:0;
}
template<class T> bool umax(T& a, const T& b) { 
	return a<b?a=b, 1:0;
} 
 
ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while(lb<rb) {
		ll mb=(lb+rb)/2;
		f(mb)?rb=mb:lb=mb+1; 
	} 
	return lb;
}
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while(lb<rb) {
		ll mb=(lb+rb+1)/2;
		f(mb)?lb=mb:rb=mb-1; 
	} 
	return lb;
}
 
template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
	cin >> x;
}
void read(double& d) {
	string t;
	read(t);
	d=stod(t);
}
void read(long double& d) {
	string t;
	read(t);
	d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(vt<A>& x) {
	EACH(a, x)
		read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
	EACH(a, x)
		read(a);
}
 
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
string to_string(vt<bool> v) {
	string res;
	FOR(sz(v))
		res+=char('0'+v[i]);
	return res;
}
 
template<size_t S> string to_string(bitset<S> b) {
	string res;
	FOR(S)
		res+=char('0'+b[i]);
	return res;
}
template<class T> string to_string(T v) {
	bool f=1;
	string res;
	EACH(x, v) {
		if(!f)
			res+=' ';
		f=0;
		res+=to_string(x);
	}
	return res;
}
 
template<class A> void write(A x) {
	cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) { 
	write(h);
	write(t...);
}
void print() {
	write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}
 
void DBG() {
	print("]");
}
template<class H, class... T> void DBG(H h, T... t) {
	write(to_string(h));
	if(sizeof...(t))
		write(", ");
	DBG(t...);
}

	



 
template<class T> void offset(ll o, T& x) {
	x+=o;
}
template<class T> void offset(ll o, vt<T>& x) {
	EACH(a, x)
		offset(o, a);
}
template<class T, size_t S> void offset(ll o, ar<T, S>& x) {
	EACH(a, x)
		offset(o, a);
}
 
mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {
	return uniform_int_distribution<ll>(a, b)(mt_rng);
}
 
template<class T, class U> void vti(vt<T> &v, U x, size_t n) {
	v=vt<T>(n, x);
}
template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
	v=vt<T>(n);
	EACH(a, v)
		vti(a, x, m);
}
 
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
 

 

 
 
long long binpow(long long a, long long b) {
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}
 
long long id2(long long a, long long b, ll p) {
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = (res * a)%p;
		a = (a * a) %p;
		b >>= 1;
	}
	return res % p;
}
 
ll id5(ll a, ll p){
	return id2(a,p-2,p) % p;
}
 

ll mod_inverse(ll a, ll b){
 return 1<a ? b - mod_inverse(b%a,a)*b/a : 1;
}
 
bool ok_indexes(int n,int m,int i,int j){
	return (i>= 0 && i < n && j >= 0 && j < m);
}
bool backtrack(vt<pair<int,int>>& a,int n, int m,int x,int y,int idx, vt<vt<bool>>& vis){
	

	a[idx] = mp(x+1,y+1);
	

	vis[x][y] = true;
	if (idx == n*m-1){
		return true;
	}
	int di,dj;
	FOR(4){
		tie(di,dj) = mp(d4i[i], d4j[i]);
		

		if (ok_indexes(n,m,x+di,y+dj) && !vis[x+di][y+dj]){
			bool good = backtrack(a,n,m,x+di,y+dj, idx+1,vis);
			if (good) return good;
		}
	}
	

	vis[x][y] = false;
	return false;
 
}
 
 




 






 


































 
 
 
 
ll gcd (ll a, ll b) {
	return b ? gcd (b, a % b) : a;
}
ull gcd (ull a, ull b) {
	return b ? gcd (b, a % b) : a;
}
template <typename T>
T id0 (vt<T> & arr) 
{ 
	T n = arr.size();
	T result = arr[0]; 
	for (T i = 1; i < n; i++) 
	{ 
		result = gcd(arr[i], result); 
		if(result == 1) 
		{ 
		return 1; 
		} 
	} 
	return result; 
} 
 
template <typename T>
T id7 (set<T> & arr) 
{ 
	T n = arr.size();
	T result = *arr.begin();
	auto iter = next(arr.begin());
	while(iter != arr.end()){ 
		result = gcd(*iter, result); 
		if(result == 1){ 
			return 1; 
		} 
		iter++;
	} 
	return result; 
} 
 
 
ll longlog(ld base, ld x) {
	return (ll)(log(x) / log(base));
}








 
















class Solution {
public:
   

   int best;
   int node;
   int dfs(int v, bool* visited, vvi& graph, int c = 0){
	  visited[v] = true;
	  int ans = 0;
	  for(int i = 0; i < sz(graph[v]); i++){
		 if(!visited[graph[v][i]])ans = max(ans,dfs(graph[v][i], visited, graph, c+1));
	  }
	  if(c > best){
		 best = c;
		 node = v ;
	  }
	  visited[v] = false;
	  return max(c,ans);
   }
   int treeDiameter(vvi & graph, int n) {
	  bool* visited = new bool[n]();
	  best = 0;
	  node = 0;
	  dfs(0, visited, graph);
	  bool* visited2 = new bool[n]();
	  return dfs(node, visited2, graph);
   }
};
 
int dfs2(int v, int parent, int b, int dist, vvi &adj){
	

	fflush(0);
	if(v == b) return dist;
	EACH(u,adj[v]){
		if (u == parent) continue;
		int res = dfs2(u,v,b,dist+1,adj);
		if(res != -1) return res;
	}
	return -1;
}
 
 
 
 
 
 
int clz(int N) {
	return N ? 32 - __builtin_clz(N): -1;
}
int clz(unsigned long long N) {
	return N ? 64 - __builtin_clzll(N): -1;
}
bool is_peak(vll &a, ll i){
	ll n = a.size();
	dbg(n,i);
	if(i <= -1 or i >= n) return false;
	if(n == 1) return true;
	if(i == 0 && a[i] > a[i+1]) return true;
	if(i == n-1 && a[i] > a[i-1]) return true;
	if(a[i] > a[i-1] && a[i] > a[i+1]) return true;
	return false;
}
bool id1(vll &a, ll i){
	ll n = a.size();
	if(n==1) return false;
	if(i <= -1 or i >= n) return false;
	if(i == n-1 || i == 0) return false;
	if(a[i] < a[i-1] && a[i] < a[i+1]) return true;
	return false;
	
}
ll choose(vll &fact, ll n, ll k, ll p){
	if(n < 0) return 0;
	if(k > n) return 0;
	if(k==n) return 1;
	

	return (fact[n]*id5((fact[k]*fact[n-k])%p,p))%p;
}
 
ld dist(ld x1, ld y1, ld x2, ld y2){
	return sqrt((y2-y1)*(y2-y1) + (x2-x1)*(x2-x1));
}
 
















 


















 













bool id8(const pair<ll,ll> &a, 
              const pair<ll,ll> &b) 
{ 
    return (a.second < b.second); 
} 
 
const ll INF = 100000000000000;
vt<vt<pll>> adj;
void dijkstra(ll s, vector<ll> & d, vector<ll> &cur_ind) {
    ll n = adj.size();
    d.assign(n, INF);
 
    d[s] = 0;
    set<pair<ll, ll>> q;
    q.insert({0, s});
    while (!q.empty()) {
        ll v = q.begin()->second;
        q.erase(q.begin());
 
        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;
 
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }
}
 
 
vll id3(ll n) {
    vll factorization;
    for (ll d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}
 
ll solve_rec(ll cur_res, ll n){
	if(n==1) return cur_res;
	cur_res++;
	

	ll x= -1;
	ll max_opt = -1;
	for(ll d = 2; d*d <= n; d++){
		if(n%d == 0){
			x = d;
			

			break;
		}
	}	
	

	if(x  == -1 || n == 4){
		return cur_res;
	}
	

	return solve_rec(cur_res, n/x-1);
}
int C = 5*100000;
vi twos(C);
void id4(){
	twos[0]=1;
	FOR(i,1,C){
		twos[i] = (twos[i-1] * 2) % NUM;
	}
}
 
bool test_cases=1; 

void solve(int id6, int total) {
	int n; read(n);
	vi a(2*n); read(a);
	int odds = 0;
	FOR(2*n){
		if(a[i] % 2) 
			odds++;
	}
	if(odds == n) 
		{printret("Yes");}
	else
		printret("No");
 
}
 
 
 
 
 
 
int main() {
	bool real = true;
	
		real = false;
		freopen("q1.input", "r", stdin);
	
	if(real){
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
	int t = 1;
	if(test_cases) read(t);
	FOR(t){
		

		solve(i+1,t);
	}
 
	return 0;
}
 
 		    	    				  		    	 		 		