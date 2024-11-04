

 




 
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long int ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 





 






 



 
const ll MOD = (ll)1000000007;

const ll INF = 1e18;
const int MX = 200005;
const ld PI = 4*atan((ld)1);
 
template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }
 
namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);
 
    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }
 
    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
 
using namespace input;
 
namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);
 
    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        pr(first); pr(rest...); 
    }
 
    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; 

        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) { 
        pr(first); ps(); 

    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); 

    }
}
 
using namespace output;
 
namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); 

        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } 

    }
}
 
using namespace io;
 
template<class T> T invGeneral(T a, T b) {
    a %= b; if (a == 0) return b == 1 ? 0 : -1;
    T x = invGeneral(b,a); 
    return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}
 
template<class T> struct modular {
    T val; 
    explicit operator T() const { return val; }
    modular() { val = 0; }
    modular(const ll& v) { 
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
    friend bool operator<(const modular& a, const modular& b) { return a.val < b.val; }
 
    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
    friend modular pow(modular a, ll p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) { 
        auto i = invGeneral(a.val,MOD); assert(i != -1);
        return i;
    } 

    modular& operator/=(const modular& m) { return (*this) *= inv(m); }
    
    friend modular operator+(modular a, const modular& b) { return a += b; }
    friend modular operator-(modular a, const modular& b) { return a -= b; }
    friend modular operator*(modular a, const modular& b) { return a *= b; }
    
    friend modular operator/(modular a, const modular& b) { return a /= b; }
};
 
typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll expo = ll(rng() % 10000 + 7); 

const ll expo2 = ll(rng() % 10000 + 8);
string t;
long long n;
string rings[200005];
pair<modular<ll>, modular<ll>> csum[200005];
pair<ll, ll> trief[200005][26]; 

unordered_set<ll> id1; 

unordered_set<ll> id4; 

map<ll, ll> snums; 

 map<ll, ll> id3;

pair<modular<ll>, modular<ll>> powa[200005];

pair<modular<ll>, modular<ll>> invpowa[200005];

ll ans1[200005];
ll ans2[200005];


pair<ll, ll> gethash(ll a, ll b){
	return mp(ll((csum[b+1].f-csum[a].f)*(invpowa[a+1].f)), ll((csum[b+1].s-csum[a].s)*(invpowa[a+1].s))); 

	

}
 
bool checkright(ll a, ll b){
	if(id1.find(gethash(a, b).f) == id1.end() || id4.find(gethash(a, b).s) == id4.end()){
		return false;
	}
	return true;
}
 
void prop(ll a, ll b, pair<modular<ll>, modular<ll>> c, ll d){ 

	
	for(int i = 0; i < 26; i++){
		
		
		if(trief[a][i].f == 0) continue;
		trief[a][i].s+=b;
		

		modular<ll> num1 = c.f+(modular<ll>)(i+1)*powa[d].f;
		
		modular<ll> num2 = c.s+(modular<ll>)(i+1)*powa[d].s;
		snums[ll(num1)] += trief[a][i].s;

		id3[ll(num2)] += trief[a][i].s;
		prop(trief[a][i].f, trief[a][i].s, mp(num1, num2),d+1);
		
	}
}
 
int main() {
    setIO();
    

	

	
	cin >> t >> n;
	

	powa[1] = mp(1, 1);
	for(int i = 2; i <= 200004; i++){
	
		powa[i].f = powa[i-1].f*expo;
		invpowa[i].f = 1/powa[i].f;
		
		powa[i].s = powa[i-1].s*expo2;
		invpowa[i].s = 1/powa[i].s;
	}
	
	for(int i = 0; i < t.size(); i++){
		csum[i+1].f = csum[i].f+(modular<ll>)(t[i]-'a'+1)*powa[i+1].f;
		
		csum[i+1].s = csum[i].s+(modular<ll>)(t[i]-'a'+1)*powa[i+1].s;
	}
	ll id2 = 2; 

	
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		rings[i] = s;
		pair<modular<ll>,modular<ll>> id5 = mp(0, 0);
		

		ll id0 = 1;
		for(int i = 0; i < sz(s); i++){
			id5.f+=(modular<ll>)(s[i]-'a'+1)*powa[i+1].f;
			
			id5.s+=(modular<ll>)(s[i]-'a'+1)*powa[i+1].s;
			
			id1.insert((ll)id5.f);
			
			id4.insert((ll)id5.s);
			if(i == sz(s)-1){
				trief[id0][s[i]-'a'].s++;
			}
			if(trief[id0][s[i]-'a'].f == 0){
				trief[id0][s[i]-'a'].f = id2;
				id2++;
				id0 = trief[id0][s[i]-'a'].f;
			}
			else{
				id0 = trief[id0][s[i]-'a'].f;
			}
		}
		
	}
	
	prop(1, 0, mp(0, 0), 1);
	
	

	
	long long ans = 0;
	for(int i = 0; i < t.size()-1; i++){ 

		
		ll lo = i;
		ll hi = t.size()-1;
		while(lo < hi){
			ll mid = (lo+hi)/2+1;
			if(checkright(i+1, mid) == true) lo = mid;
			else hi = mid-1;
		}
		ll rightans;
		if(lo  < i+1) rightans = 0;
		else{
			rightans = min(snums[gethash(i+1, lo).f], id3[gethash(i+1, lo).s]);
			

		}
		ans1[i] = rightans;
		

	}
	

	for(int i = 0; i < 200005; i++){
		csum[i] = mp(0, 0);
	}
	for(int i = 0; i < 200005; i++){
		for(int j = 0; j < 26; j++){
			trief[i][j] = mp(0, 0);
		}
	}
	id1.clear();
	id4.clear();
	snums.clear();
	id3.clear();
	

	
	reverse(t.begin(), t.end());
	
	for(int i = 0; i < t.size(); i++){
		csum[i+1].f = csum[i].f+(modular<ll>)(t[i]-'a'+1)*powa[i+1].f;
		
		csum[i+1].s = csum[i].s+(modular<ll>)(t[i]-'a'+1)*powa[i+1].s;
	}
	id2 = 2; 

	
	for(int i = 0; i < n; i++){
		string s;
		s = rings[i];
		reverse(s.begin(), s.end());
		pair<modular<ll>,modular<ll>> id5 = mp(0, 0);
		

		ll id0 = 1;
		for(int i = 0; i < sz(s); i++){
			id5.f+=(modular<ll>)(s[i]-'a'+1)*powa[i+1].f;
			
			id5.s+=(modular<ll>)(s[i]-'a'+1)*powa[i+1].s;
			id1.insert((ll)id5.f);
			id4.insert((ll)id5.s);
			if(i == sz(s)-1){
				trief[id0][s[i]-'a'].s++;
			}
			if(trief[id0][s[i]-'a'].f == 0){
				trief[id0][s[i]-'a'].f = id2;
				id2++;
				id0 = trief[id0][s[i]-'a'].f;
			}
			else{
				id0 = trief[id0][s[i]-'a'].f;
			}
		}
		
	}
	prop(1, 0, mp(0, 0), 1);
	
	for(int i = 0; i < t.size()-1; i++){ 

		
		ll lo = i;
		ll hi = t.size()-1;
		while(lo < hi){
			ll mid = (lo+hi)/2+1;
			if(checkright(i+1, mid) == true) lo = mid;
			else hi = mid-1;
		}
		ll rightans;
		if(lo  < i+1) rightans = 0;
		else{
			rightans = min(snums[gethash(i+1, lo).f], id3[gethash(i+1, lo).s]);
			

		}
		ans2[i] = rightans;
		

	}
	for(int i = 0; i < t.size(); i++){
		

		ans+=(long long)ans1[i]*(long long)ans2[t.size()-2-i];
	}
	cout << (long long)(ans);
}
 
