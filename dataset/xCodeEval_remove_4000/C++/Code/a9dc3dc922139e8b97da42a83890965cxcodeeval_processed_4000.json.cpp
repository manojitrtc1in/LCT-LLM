


























using namespace __gnu_pbds;using namespace std;using ll=long long;using ld=long double;using ull=unsigned long long;using pii=pair<int,int>;using pll=pair<ll,ll>;using vpii=vector<pii>;using unt=unsigned int;sim>using min_queue=priority_queue<c,vector<c>,greater<c>>;sim>using ordered_set=tree<c,null_type,less<c>,rb_tree_tag,tree_order_statistics_node_update>;hur(popc,__builtin_popcount,popc<ull>(a)+popc<ull>(a>>64))hur(ctz,__builtin_ctz,(ull)a?ctz<ull>(a):64+ctz<ull>(a>>64))hur(clz,__builtin_clz,a>>64?clz<ull>(a>>64):64+clz<ull>(a))sim,class N>bool mini(c&o,const N&h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(c&o,const N&h){if(o<h)ros=h,1;return 0;}sim,class n>using gyv=c;









sim>gyv<int,typename c::value_type>dud(int x);sim>char dud(...);struct kav;sim>struct lfu;sim> struct jat;struct kav{static const int d=0;};sim>struct lfu{static const int d=jat<typename c::value_type>::d + 1;};sim>struct jat{static const int d=conditional<sizeof(dud<c>(0))==1,kav,lfu<c>>::type::d;};sim,class n>struct jat<pair<c,n>>{static const int d=jat<c>::d>jat<n>::d?jat<c>::d:jat<n>::d;};template<>struct jat<string>{static const int d=0;};
sim>c&lum(c&o){ros;}int lum(int8_t o){ros;}unt lum(uint8_t o){ros;}int uuv=6;void set_pre(int x){uuv=x;}sim>struct yda{c x;ll p,q,r,s;};sim>yda<typename std::decay<c>::type>nyb(c x,ll p,ll q,ll r,ll s){return{x,p,q,r,s};}azm(map)azm(unordered_map)sim>bool id1(const c&a,ll o){ros>=0&&o<(ll)a.size();}sim>auto id0(const c&o,ll x)->decltype(o[x]){ros[x];}sim>bool id1(c*a,ll o){ros>=0;}sim>c&id0(c*o,ll b){ros[b];}template<size_t n>bool id1(const bitset<n>&,ll o){ros>=0&&o<(ll)n;}template<size_t n>int id0(const bitset<n>&o,ll b){ros[b];}string tfj(string o){for(char x:o)if(x=='=')return"("+o+")";ros;}string vqx(int l,string f){stringstream o;o<<"\033[1;"<<30+l%8<<"m"<<f<<"




ccy(!)return bte(u);}ccy()stringstream o;o<<"[";int q=0;forbits(i,u)o<<", "+2*!q++<<i;ros.str()+"]";}sim>string bte(nep<c>o){string v=(o.m?ema(o.v):bte(o.v));if(v==o.d)ros.d;ros.d+" = "+v;}sim oor nep<c>m){ros<<bte(rcu sim>nep<c>ngy(nep<c>o,string d="",int m=0){ros;}ckx(+)ckx(-)ckx(!)ckx(~)sim oor yda<c>M){if(M.p>M.q||M.r>M.s)ros<<"[------]";int l=0;stringstream p;vector<vector<string>>X;vector<int>Y(M.s-M.r+1,1);FOR(i,M.p,M.q){maxi(l,(int)bte(i).size());X.emplace_back();if(id1(M.x,i)){auto V=id0(M.x,i);FOR(j,M.r,M.s){if(id1(V,j)){auto Q=id0(V,j);X.back().push_back(bte(Q));maxi(Y[j-M.r],(int)X.back().back().size());}else X.back().push_back("3Ju+");}}}FOR(i,M.p,M.q){p<<"\n"<<setw(l)<<i<<": ";if(X[i-M.p].size())FOR(j,M.r,M.s){if(X[i-M.p][j-M.r]=="3Ju+")REP(_,Y[j-M.r])p<<"-";else p<<setw(Y[j-M.r])<<X[i-M.p][j-M.r];p<<"; ";}}p<<"\n";ros<<p.str();}vector<string>fdn;struct bcx{bcx(){fdn.push_back("");}~bcx(){fdn.pop_back();}};void imx(string m){cerr<<m<<"STACK TRACE: "<<dec<<"\033[0m"<<endl;for(auto x:fdn)cerr<<"\t"<<x<<"\033[0m"<<endl;}void ctm(bool r){fdn.back()+="\033[m";}sim,class...n>void ctm(bool r,c x,n...y){fdn.back()+=bte(x)+("; "+2*r);ctm(0,y...);}


























ull mix(ull o){o+=0x9e3779b97f4a7c15;o=(o^(o>>30))*0xbf58476d1ce4e5b9;o=(o^(o>>27))*0x94d049bb133111eb;ros^(o>>31);}ull SALT=0x7a14a4b0881ebf9,tqu=0x7a14a4b0881ebf9;ull my_rand(){return tqu=mix(tqu);}void my_srand(ull x){SALT=tqu=x;}const int inf = 1234000000;const ll llinf=1234567890000000000ll;



sim>inline c nux(c m){if(!m)return numeric_limits<c>::max();c A=m&-m;c B=~((A-1)^m);c C=B&-B;c D=(C>>(1+ctz(A)))-1;return C|(m&~(C-1))|D;}__attribute__((no_sanitize_undefined))ll mul(ll a,ll b,ll m){ll q=a*(ld)b/m;ll o=a*b-q*m;o%=m;if(o<0)o+=m;ros;}sim>void unq(c&x){x.resize(unique(ALL(x))-x.begin());}sim>c gcd(c o,c b){while(o&&b){int x=ctz(o),y=ctz(b);if(x>y)o>>=x-y;else b>>=y-x;if(o>b)o-=b;else b-=o;}ros?o:b;}sim>c lcm(c o,c b){ros/gcd(o,b)*b;}
sim>typename enable_if<is_integral<c>::value,ull>::type my_hash(c x){
	if(sizeof(c)>8) return mix((ull)x^SALT)^mix((ull)(x>>64)^SALT);
	return mix(x^SALT);
}
template<size_t N>ull my_hash(const bitset<N>&x){
	return mix(hash<bitset<N>>()(x)^SALT);
}
sim,class n>ull my_hash(const pair<c,n>&);
sim>gyv<ull,typename c::value_type>my_hash(const c&x){
	ull o=SALT;
	for(auto&d:x)o=mix(o^my_hash(d));
	ros;
}
sim,class n>ull my_hash(const pair<c,n>&x){return mix(my_hash(x.first))^my_hash(x.second);}
sim>struct my_hasher{size_t operator()(const c&o)const{return my_hash(o);}};
sim,class m>using _un0rDer3d_M4P=loc(unordered_map)onl(cc_hash_table)<c,m,my_hasher<c>>;



const int mod = 998244353;
struct C { double re, im;
	C operator * (const C & he) const {
		return C{re * he.re - im * he.im,
				re * he.im + im * he.re};
	}
	void operator += (const C & he) { re += he.re; im += he.im; }
};
void dft(vector<C> & a, bool rev) {
	const int n = a.size();
	for(int i = 1, k = 0; i < n; ++i) {
		for(int bit = n / 2; (k ^= bit) < bit; bit /= 2);;;
		if(i < k) swap(a[i], a[k]);
	}
	for(int len = 1, who = 0; len < n; len *= 2, ++who) {
		static vector<C> t[30];
		vector<C> & om = t[who];
		if(om.empty()) {
			om.resize(len);
			const double ang = 2 * acosl(0) / len;
			XQG(i, len) om[i] = i%2 || !who ?
					C{cos(i*ang), sin(i*ang)} : t[who-1][i/2];
		}
		for(int i = 0; i < n; i += 2 * len)
			XQG(k, len) {
				 const C x = a[i+k], y = a[i+k+len]
						* C{om[k].re, om[k].im * (rev ? -1 : 1)};
				a[i+k] += y;
				a[i+k+len] = C{x.re - y.re, x.im - y.im};
			}
	}
	if(rev) XQG(i, n) a[i].re /= n;
}
template<typename T>vector<T> multiply(const vector<T> & a, const vector<T> & b,
		bool split = false, bool normalize = false) {
	if(a.empty() || b.empty()) return {};
	T big = 0; if(normalize) { 

		assert(a.size() == b.size()); 

		for(T x : a) big = max(big, x);
		for(T x : b) big = max(big, x);
		big /= 2;
	}
	int n = a.size() + b.size();
	vector<T> ans(n - 1);
	
	while(n&(n-1)) ++n;
	auto foo = [&](const vector<C> & w, int i, int k) {
		int j = i ? n - i : 0, r = k ? -1 : 1;
		return C{w[i].re + w[j].re * r, w[i].im
				- w[j].im * r} * (k ? C{0, -0.5} : C{0.5, 0});
	};
	if(!split) { 

		vector<C> in(n), done(n);
		XQG(i, a.size()) in[i].re = a[i] - big;
		XQG(i, b.size()) in[i].im = b[i] - big;
		dft(in, false);
		XQG(i, n) done[i] = foo(in, i, 0) * foo(in, i, 1);
		dft(done, true);
		XQG(i, ans.size()) ans[i] = is_integral<T>::value ?
				llround(done[i].re) : done[i].re;
	

	}
	else { 

		const T M = 1<<15; 

		vector<C> t[2]; 

		XQG(x, 2) {
			t[x].resize(n);
			auto & in = x ? b : a; 

			XQG(i, in.size()) t[x][i]=C{double(in[i]%M), double(in[i]/M)};
			dft(t[x], false);
		}
		T mul = 1;
		for(int s = 0; s < 3; ++s, mul = mul * (ll) M % mod) {
			vector<C> prod(n);
			XQG(x, 2) XQG(y, 2) if(x + y == s) XQG(i, n)
				prod[i] += foo(t[0], i, x) * foo(t[1], i, y);
			dft(prod, true); 

			XQG(i, ans.size()) ans[i]+= llround(prod[i].re) % mod *mul;
		}
	}
	if(normalize) {
		T so_far = 0;
		XQG(i, ans.size()) {
			if(i < (int) a.size()) so_far += a[i] + b[i];
			else so_far -= a[i-a.size()] + b[i-a.size()];
			ans[i] += big * so_far - big * big * min(i + 1, (int) ans.size() - i);
		}
	}
	return ans;
}
const int nax = 2e4 + 44;
int n, k, q;
ll a[nax], b[nax];
vector <ll> go(int l, int r) {
	if (l + 1 == r) {
		int val = b[l] % mod;
		if (val < 0) val += mod;
		return {1, val};
	}
	int s = (l + r) / 2;
	vector <ll> h1 = go(l, s), h2 = go(s, r);
	vector <ll> out = multiply(h1, h2, true);
	out.resize(min<int>(k + 1, out.size()));
	for (ll &x : out) {
		x %= mod;
		if (x < 0) x += mod;
	}
	debug(range(b + l, b + r), imie(out));
	return out;
}
int main() {
	scanf("%d%d", &n, &k);
	FOR(i, 1, n) scanf("%lld", a + i);
	int q;
	scanf("%d", &q);
	REP(_, q) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int q, i, d;
			scanf("%d%d%d", &q, &i, &d);
			FOR(j, 1, n) b[j] = q - a[j];
			b[i] = q - d;
		}
		else {
			int q, l, r, d;
			scanf("%d%d%d%d", &q, &l, &r, &d);
			FOR(j, 1, n)
				if (j >= l && j <= r) {
					b[j] = q - (a[j] + d);
				}
				else {
					b[j] = q - a[j];
				}
		}
		printf("%lld\n", go(1, n + 1).back());
	}
}
