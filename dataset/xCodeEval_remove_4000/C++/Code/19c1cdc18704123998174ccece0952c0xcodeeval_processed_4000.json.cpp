


























using namespace __gnu_pbds;using namespace std;using ll=long long;using ld=long double;using ull=unsigned long long;using pii=pair<int,int>;using pll=pair<ll,ll>;using vpii=vector<pii>;using unt=unsigned int;sim>using min_queue=priority_queue<c,vector<c>,greater<c>>;sim>using ordered_set=tree<c,null_type,less<c>,rb_tree_tag,tree_order_statistics_node_update>;hur(popc,__builtin_popcount,popc<ull>(a)+popc<ull>(a>>64))hur(ctz,__builtin_ctz,(ull)a?ctz<ull>(a):64+ctz<ull>(a>>64))hur(clz,__builtin_clz,a>>64?clz<ull>(a>>64):64+clz<ull>(a))sim,class N>bool mini(c&o,const N&h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(c&o,const N&h){if(o<h)ros=h,1;return 0;}sim,class n>using gyv=c;









sim>gyv<int,typename c::value_type>dud(int x);sim>char dud(...);struct kav;sim>struct lfu;sim> struct jat;struct kav{static const int d=0;};sim>struct lfu{static const int d=jat<typename c::value_type>::d + 1;};sim>struct jat{static const int d=conditional<sizeof(dud<c>(0))==1,kav,lfu<c>>::type::d;};sim,class n>struct jat<pair<c,n>>{static const int d=jat<c>::d>jat<n>::d?jat<c>::d:jat<n>::d;};template<>struct jat<string>{static const int d=0;};
sim>c&lum(c&o){ros;}int lum(int8_t o){ros;}unt lum(uint8_t o){ros;}int uuv=6;void set_pre(int x){uuv=x;}sim>struct yda{c x;ll p,q,r,s;};sim>yda<typename std::decay<c>::type>nyb(c x,ll p,ll q,ll r,ll s){return{x,p,q,r,s};}azm(map)azm(unordered_map)sim>bool id2(const c&a,ll o){ros>=0&&o<(ll)a.size();}sim>auto id1(const c&o,ll x)->decltype(o[x]){ros[x];}sim>bool id2(c*a,ll o){ros>=0;}sim>c&id1(c*o,ll b){ros[b];}template<size_t n>bool id2(const bitset<n>&,ll o){ros>=0&&o<(ll)n;}template<size_t n>int id1(const bitset<n>&o,ll b){ros[b];}string tfj(string o){for(char x:o)if(x=='=')return"("+o+")";ros;}string vqx(int l,string f){stringstream o;o<<"\033[1;"<<30+l%8<<"m"<<f<<"




ccy(!)return bte(u);}ccy()stringstream o;o<<"[";int q=0;forbits(i,u)o<<", "+2*!q++<<i;ros.str()+"]";}sim>string bte(nep<c>o){string v=(o.m?ema(o.v):bte(o.v));if(v==o.d)ros.d;ros.d+" = "+v;}sim oor nep<c>m){ros<<bte(rcu sim>nep<c>ngy(nep<c>o,string d="",int m=0){ros;}ckx(+)ckx(-)ckx(!)ckx(~)sim oor yda<c>M){if(M.p>M.q||M.r>M.s)ros<<"[------]";int l=0;stringstream p;vector<vector<string>>X;vector<int>Y(M.s-M.r+1,1);FOR(i,M.p,M.q){maxi(l,(int)bte(i).size());X.emplace_back();if(id2(M.x,i)){auto V=id1(M.x,i);FOR(j,M.r,M.s){if(id2(V,j)){auto Q=id1(V,j);X.back().push_back(bte(Q));maxi(Y[j-M.r],(int)X.back().back().size());}else X.back().push_back("3Ju+");}}}FOR(i,M.p,M.q){p<<"\n"<<setw(l)<<i<<": ";if(X[i-M.p].size())FOR(j,M.r,M.s){if(X[i-M.p][j-M.r]=="3Ju+")REP(_,Y[j-M.r])p<<"-";else p<<setw(Y[j-M.r])<<X[i-M.p][j-M.r];p<<"; ";}}p<<"\n";ros<<p.str();}vector<string>fdn;struct bcx{bcx(){fdn.push_back("");}~bcx(){fdn.pop_back();}};void imx(string m){cerr<<m<<"STACK TRACE: "<<dec<<"\033[0m"<<endl;for(auto x:fdn)cerr<<"\t"<<x<<"\033[0m"<<endl;}void ctm(bool r){fdn.back()+="\033[m";}sim,class...n>void ctm(bool r,c x,n...y){fdn.back()+=bte(x)+("; "+2*r);ctm(0,y...);}


























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


const int nax = 1e5 + 44, tax = 1.2 * 1e6 + 44, log = 21, mod = 1e9 + 7;
vector <pii> graf[nax];
int jump[tax][log];
char let[tax];
int dep[tax];
int down[tax][10];
ll val[tax];
int first_free = 1;
int go(int x, int dig) {
	if (down[x][dig] != -1) return down[x][dig];
	int ret = down[x][dig] = first_free;
	assert(ret < tax);
	first_free++;
	let[ret] = dig;
	jump[ret][0] = x;
	dep[ret] = dep[x] + 1;
	val[ret] = (val[x] * 10 + dig) % mod;
	FOR(i, 1, log - 1)
		jump[ret][i] = jump[jump[ret][i - 1]][i - 1];
	return ret;
}
bool is_less(int x, int y) {


	if (dep[x] != dep[y]) return dep[x] < dep[y];
	if (x == y) return false;
	FORD(i, log - 1, 0) {
		int xx = jump[x][i], yy = jump[y][i];
		if (xx != yy) {
			x = xx;
			y = yy;
		}
	}
	return let[x] < let[y];
}
int shortest[nax];
struct my_cmp {
	bool operator()(pii a, pii b) const {
		if (a.first != b.first)
			return is_less(a.first, b.first);
		return a.second < b.second;
	}
};
set <pii, my_cmp> kol;
string get(int v) {
	assert(v != -1);
	onl(return "");
	string ans;
	while (v != 0) {
		ans.push_back('0' + let[v]);
		v = jump[v][0];
	}
	reverse(ALL(ans));
	rans;
}
void update(int x, int val) {
	debug(imie(x), get(val));
	if (shortest[x] == -1 || is_less(val, shortest[x])) {
		if (shortest[x] != -1)
			kol.erase({shortest[x], x});
		shortest[x] = val;
		kol.insert({shortest[x], x});
	}
}
void id0() {
	vector <int> ord;
	REP(i, first_free) ord.push_back(i);
	sort(ALL(ord), is_less);
	REP(i, first_free) REP(j, i) assert(is_less(ord[j], ord[i]));
}
int main() {
	memset(down, -1, sizeof(down));
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 1, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		graf[x].emplace_back(y, i);
		graf[y].emplace_back(x, i);
	}
	memset(shortest, -1, sizeof(shortest));
	update(1, 0);
	debug(imie(kol));
	while (!kol.empty()) {
		pii f = *kol.begin();
		kol.erase(kol.begin());
		debug(get(f.first), imie(f.second));
		int wh = f.second;
		for (pii x : graf[wh]) {
			int to = f.first;
			vector <int> digs;
			int v = x.second;
			while (v) {
				digs.push_back(v % 10);
				v /= 10;
			}
			reverse(ALL(digs));
			debug(imie(digs));
			for (int d : digs) to = go(to, d);
			update(x.first, to);
		}
	}
	FOR(i, 2, n) {
		debug(i, get(shortest[i]));
		printf("%lld\n", val[shortest[i]]);
	}
	loc(id0());
}