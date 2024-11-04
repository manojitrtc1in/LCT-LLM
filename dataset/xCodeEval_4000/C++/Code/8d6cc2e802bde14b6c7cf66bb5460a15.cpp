#include <numeric>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double


#define ar array

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define vt vector
#define vi vector<int>
#define vll vector<long long>
#define vld vector<ld>
#define vs vector<string>
#define vvl vector<vector<long long>>
#define vvi vector<vector<int>>

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
#define NUM 1000000007

#define pb push_back
#define mp make_pair

#define pb push_back
#define fi first
#define se second

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)

#define printcase(x) print("Case #" + to_string(test_case_num) + ":",x); return
#define printret(x) {print(x); return;}



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
#ifdef _DEBUG
	#define dbg(...) write("LINE(", __LINE__, ") -> [" , #__VA_ARGS__ ,"]: ["); DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

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

#define VECTOR_MULT_ll(v) (accumulate(all((v)), (ll)1, multiplies<ll>()))

#define VECTOR_MULT_ll_i(v,i) (accumulate((v).begin(), (v).begin()+(i), (ll)1, multiplies<ll>()))


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

long long mod_binpow(long long a, long long b, ll p) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%p;
        a = (a * a) %p;
        b >>= 1;
    }
    return res % p;
}

ll mod_inverse_prime(ll a, ll p){
	return mod_binpow(a,p-2,p) % p;
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
T gcd_array (vt<T> & arr) 
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
T gcd_set (set<T> & arr) 
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
      for(int i = 0; i < graph[v].size(); i++){
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
bool is_valley(vll &a, ll i){
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
	

	return (fact[n]*mod_inverse_prime((fact[k]*fact[n-k])%p,p))%p;
}


void solve(int test_case_num) {
	string s; read(s);
	int n = s.size();
	int num = 10;
	

	if(n == 1){
		print(1, s[0]);
		return;
	}
	vt<pair<int,string>> res;
	

	int idx = n-1;
	while(idx >= 1 && s[idx]==s[idx-1]){
		idx-=2;
	}
	string last_char;
	

	if(idx >= 0){
		last_char += s[idx];
	}
	string last_two(last_char);
	

	FOR(i,n-1,max<int>(-1,idx-1),-1){
		if((n-i) %2){
			res.pb(mp(1,string(1,s[i])));
		} else {
			res.pb(mp(0,""));
		}
	}
	int old_idx = idx;
	idx--;
	while(idx >= 1 && s[idx] == s[idx-1] && s[idx] >= last_char[0]){
		idx-=2;
	}
	string penul;
	if(idx >= 0){
		penul += s[idx];
	}
	last_two = penul + last_char;
	FOR(i,old_idx-1,max<int>(-1,idx-1),-1){
		if((old_idx - i)%2){
			res.pb(mp(2,string(1,s[i])+last_char));
		} else {
			res.pb(mp(1,string(last_char)));
		}
	}
	string med;
	int new_old_idx = idx;
	char last = s[idx];
	char before_last = last_char[0];
	if(last == before_last) before_last = 0;
	idx--;
	int len_med = 0;
	

	while(idx >= 0){
			dbg(s[idx],last,before_last);
		if(idx >= 1 && s[idx] == s[idx-1] && (s[idx] > last || s[idx] == last && last > before_last)){
			if(len_med + 1 + last_two.size() > num){
				res.pb(mp(len_med+1+last_two.size(), s[idx] + med.substr(0,4) + "..." + last_two));
			} else {
				res.pb(mp(len_med+1+last_two.size(), s[idx] + med  + last_two));
			}
			if(len_med + last_two.size() > num){
				res.pb(mp(len_med +last_two.size(), med.substr(0,5) + "..." + last_two));
			} else {
				res.pb(mp(len_med +last_two.size(), med + last_two));
			}
			idx-=2;
		} else {
			med = s[idx] + med;
			if(last != s[idx]){
				before_last = last;
			}
			last = s[idx];
			dbg(before_last,last);
			len_med++;
			if(len_med + last_two.size() > num){
				med = med.substr(0,5);
			}
			

			if(len_med + last_two.size() > num){
				res.pb(mp(len_med +last_two.size(), med + "..." + last_two));
			} else {
				res.pb(mp(len_med +last_two.size(), med + last_two));
			}
			idx--;
		}
	}

	reverse(all(res));
	FOR(res.size()){
		print(res[i].fi,res[i].se);
	}


}


int main() {
	bool real = true;
	#ifdef _DEBUG
		real = false;
		freopen("q1.input", "r", stdin);
	#endif
	if(real){
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
	int t = 1;
	

	FOR(t){
		

		solve(i+1);
	}

	return 0;
}