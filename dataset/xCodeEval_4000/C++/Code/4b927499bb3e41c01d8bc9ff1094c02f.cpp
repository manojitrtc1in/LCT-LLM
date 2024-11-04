
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
 
#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
 
#pragma region Macros


#define foa(v, a) for(auto &v : a)
#define REPname(a, b, c, d, e, ...) e
#define REP(...) REPname(__VA_ARGS__, REP3, REP2, REP1, REP0)(__VA_ARGS__)
#define REP0(x) for(int i = 0; i < (x); ++i)
#define REP1(i, x) for(int i = 0; i < (x); ++i)
#define REP2(i, l, r) for(int i = (l); i < (r); ++i)
#define REP3(i, l, r, c) for(int i = (l); i < (r); i += (c))
#define REPSname(a, b, c, ...) c
#define REPS(...) REPSname(__VA_ARGS__, REPS1, REPS0)(__VA_ARGS__)
#define REPS0(x) for(int i = 1; i <= (x); ++i)
#define REPS1(i, x) for(int i = 1; i <= (x); ++i)
#define RREPname(a, b, c, d, e, ...) e
#define RREP(...) RREPname(__VA_ARGS__, RREP3, RREP2, RREP1, RREP0)(__VA_ARGS__)
#define RREP0(x) for(int i = (x)-1; i >= 0; --i)
#define RREP1(i, x) for(int i = (x)-1; i >= 0; --i)
#define RREP2(i, l, r) for(int i = (r)-1; i >= (l); --i)
#define RREP3(i, l, r, c) for(int i = (r)-1; i >= (l); i -= (c))
#define RREPSname(a, b, c, ...) c
#define RREPS(...) RREPSname(__VA_ARGS__, RREPS1, RREPS0)(__VA_ARGS__)
#define RREPS0(x) for(int i = (x); i >= 1; --i)
#define RREPS1(i, x) for(int i = (x); i >= 1; --i)
 


#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define popcnt(x) __builtin_popcountll(x)
template <class T = int>
using V = std::vector<T>;
template <class T = int>
using VV = std::vector<std::vector<T>>;
template <class T = int>
using VVV = std::vector<std::vector<std::vector<T>>>;
template <class T>
using pqup = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using ll = long long;
using ld = long double;


using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;


const int inf = 1e9;
const ll INF = 2e18;



void main_() {
	ll n;
	cin >> n;
	V<ll> p(n);
	REP(i,n) cin >> p[i];
	V<ll> l(n,1),r(n,1);
	REP(i,n-1){
	    if(p[i] < p[i+1]){
	        l[i+1] = l[i] + 1;
	    }
	}
	for(ll i = n-2;i>=0;i--){
	    if(p[i+1] < p[i]){
	        r[i] = r[i+1] + 1;
	    }
	}
	priority_queue<tuple<ll,ll,ll>> PQ;
	map<ll,ll> m;
	REP(i,n){
	    ll mx = max(r[i],l[i]);
	    ll mn = min(r[i],l[i]);
	    if(i != 0 && i != n-1){
	        

	    }
	    PQ.emplace(mx,mn,i);
	    
	}
	auto [x,y,z] = PQ.top();
	PQ.pop();
	if(x == y && x%2==1){
	    ll le = z - l[z] + 1;
	    ll ri = z + r[z] - 1;
	    ll s = 1;
	    ll t = 1;
	    for(ll i = le-1; i >= 0;i--){
	        if(p[i] > p[i+1]) s++;
	        else break;
	    }
	    for(ll i = ri + 1;i < n;i++){
	        if(p[i] > p[i-1]) t++;
	        else break;
	    }
	    if(s >= l[z] - 1 && s >= r[z]){
	        cout << 0 << endl;
	        return ;
	    }
	    if(t >= r[z] - 1 && t >= l[z]){
	        cout << 0 << endl;
	        return ;
	    }
	    if(!PQ.empty()){
	        auto [a,b,c] = PQ.top();
	        if(x > a){
	            cout << 1 << endl;
	        }
	        else{
	            cout << 0 << endl;
	        }
	    }
	    else{
	        cout << 1 << endl;
	    }
	}
	else{
	    cout << 0 << endl;
	}
}
 
int main() {
	int t = 1;
	

	while(t--) main_();
	return 0;
}