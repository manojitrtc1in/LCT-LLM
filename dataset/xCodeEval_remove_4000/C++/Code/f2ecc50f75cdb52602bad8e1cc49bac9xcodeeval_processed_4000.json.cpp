


























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

const int nax = 1e5 + 144;
vpii graf[nax];
const int mod = 1e9 + 7, mod2 = 1034766697;
using num = pii;
num operator*(num a, num b) {
	return {a.first * 1ll * b.first % mod, a.second * 1ll * b.second % mod2};
}
num half(num a) {
	if (a.first % 2) a.first += mod;
	if (a.second % 2) a.second += mod2;
	return {a.first / 2, a.second / 2};
}
num operator+(num a, num b) {
	return {(a.first + b.first) % mod, (a.second + b.second) % mod2};
}
num operator-(num a, num b) {
	return {(a.first - b.first) % mod, (a.second - b.second) % mod2};
}
vector <num> bru_mul(const vector <num> &a, const vector <num> &b) {
	vector <num> ans(a.size());
	REP(i, a.size()) REP(j, b.size())
		ans[i ^ j] = ans[i ^ j] + a[i] * b[j];
	rans;
}
vector <num> mul(const vector <num> &a, const vector <num> &b) {
	assert(a.size() == b.size());
	int n = a.size();
	assert(!a.empty());
	if (n == 1)
		return {a[0] * b[0]};
	assert(n % 2 == 0);
	vector <num> h1(n / 2), h2(n / 2);
	{
		vector <num> sua(n / 2), sub(n / 2);
		REP(i, n / 2) sua[i] = a[i] + a[i + n / 2];
		REP(i, n / 2) sub[i] = b[i] + b[i + n / 2];
		h1 = mul(sua, sub);
	}
	{
		vector <num> sua(n / 2), sub(n / 2);
		REP(i, n / 2) sua[i] = a[i] - a[i + n / 2];
		REP(i, n / 2) sub[i] = b[i] - b[i + n / 2];
		h2 = mul(sua, sub);
	}
	vector <num> ans(n);
	REP(i, n / 2)
		ans[i] = half(h1[i] + h2[i]);
	REP(i, n / 2)
		ans[i + n / 2] = half(h1[i] - h2[i]);
	loc(
		auto brans = bru_mul(a, b);
		bool err = false;
		REP(i, n) {
			auto d = ans[i] - brans[i];
			if (d != make_pair(0, 0)) err = true;
		}
		if (err) {
			debug(imie(a), imie(b));
			debug(imie(brans), imie(ans));
			assert(false);
		}
	);
	rans;
}
int dep[nax];
int u[nax];
int up[nax], par[nax];
int find(int x) {
	if (u[x] == x) return x;
	return u[x] = find(u[x]);
}
num make_num(int x) {
	return {x % mod, x % mod2};
}
void onion(int a, int b) {
	u[find(a)] = find(b);
}
void dfs(int x, int y = -1, int d = 0) {
	dep[x] = d;
	for (pii e : graf[x])
		if (e.first != y) {
			up[e.first] = e.second;
			par[e.first] = x;
			dfs(e.first, x, d + 1);
		}
}
const int vax = 1 << 17;
num ans[vax], curr[vax];
void trans(num tab[]) {
	REP(i, 17)
		REP(j, vax) {
			if (j >> i & 1) {
				int b = j, a = j ^ (1 << i);
				num s = tab[a] + tab[b], d = tab[a] - tab[b];
				tab[a] = s;
				tab[b] = d;
			}
		}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 1, n) u[i] = i;
	int total = 0;
	vector <pair <pii, int> > extra;
	REP(_, m) {
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		total ^= w;
		if (find(x) == find(y))
			extra.emplace_back(make_pair(x, y), w);
		else {
			graf[x].emplace_back(y, w);
			graf[y].emplace_back(x, w);
			onion(x, y);
		}
	}
	dfs(1);
	ans[0] = make_num(1);
	trans(ans);
	for (auto x : extra) {
		vector <int> on = {x.second};
		int a = x.first.first, b = x.first.second;
		while (a != b) {
			if (dep[a] < dep[b]) swap(a, b);
			on.push_back(up[a]);
			a = par[a];
		}
		debug(imie(x), imie(on));
		memset(curr, 0, sizeof(curr));
		for (int v : on) {
			curr[v] = curr[v] + make_num(1);
		}
		trans(curr);
		REP(i, vax) ans[i] = ans[i] * curr[i];
	}
	trans(ans);
	pii tot = {(int)1e9, 0};
	REP(i, vax) {
		if (ans[i] != make_num(0)) {
			debug(arr(ans, i));
			mini(tot, pii{total ^ i, ans[i].first});
		}
	}
	REP(_, 17) {
		if (tot.second % 2) tot.second += mod;
		tot.second /= 2;	
	}
	debug(imie(tot));
	printf("%d %d\n", FS(tot));
_Exit(0);
}
                       