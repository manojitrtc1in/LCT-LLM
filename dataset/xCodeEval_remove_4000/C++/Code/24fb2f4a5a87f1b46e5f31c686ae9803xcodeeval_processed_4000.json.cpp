


























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

const int nax = 43, snax = 20;
bool matr[nax][nax];
int u[nax];
int col[nax];
int find(int x) {
	if (u[x] == x) return x;
	return u[x] = find(u[x]);
}
int n, m;
bool dfs(int x, int c) {
	if (col[x] == c) return true;
	if (col[x] != 0) return false;
	col[x] = c;
	REP(i, n) if (matr[x][i] && !dfs(i, c ^ 3)) return false;
	return true;
}
void onion(int a, int b) {
	u[find(a)] = find(b);
}
int h1_matr[snax], h2_matr[snax], bet_matr[snax];
int iso1[1 << snax], iso2[1 << snax];
void run(int iso[], int adj[], int siz) {
	iso[0] = 1;
	FOR(m, 1, (1 << siz) - 1) {
		int b = ctz(m);
		iso[m] = iso[m ^ (1 << b)] && (adj[b] & m) == 0;
	}
}
int deg[nax];
int main() {
	REP(i, nax) u[i] = i;
	scanf("%d%d", &n, &m);
	if (m < 3) return 0 * printf("0\n");
	int h1 = n / 2, h2 = n - h1;
	REP(_, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		deg[a]++;
		deg[b]++;
		if (a > b) swap(a, b);
		onion(a, b);
		matr[a][b] = matr[b][a] = 1;
		if (a < h1 && b < h1) {
			h1_matr[a] |= 1 << b;
			h1_matr[b] |= 1 << a;
		}
		else if (a >= h1 && b >= h1) {
			int aa = a - h1, bb = b - h1;
			h2_matr[aa] |= (1 << bb);
			h2_matr[bb] |= (1 << aa);
		}
		else {
			assert(a < h1 && b >= h1);
			bet_matr[b - h1] |= 1 << a;
		}
	}
	int coms = 0;
	REP(i, n) if (find(i) == i) coms++;
	debug(imie(coms));
	bool bip = true;
	REP(i, n) if (col[i] == 0 && !dfs(i, 1)) bip = false;
	debug(imie(bip));
	run(iso1, h1_matr, h1);
	run(iso2, h2_matr, h2);
	REP(i, h1) REP(m, (1 << h1))
		if (m >> i & 1)
			iso1[m] += iso1[m ^ (1 << i)];
	ll isos = 0;
	int zeros = 0;
	REP(i, n) if (deg[i] == 0) zeros++;
	REP(m, (1 << h2)) {
		if (!iso2[m]) continue;
		int poss = (1 << h1) - 1;
		forbits(i, m)
			poss &= ~bet_matr[i];
		isos += iso1[poss];
	}
	debug(imie(isos));
	debug(imie(zeros));
	ll ans = (1ll << n);
	ans -= 2 * isos;
	ans -= (1ll << coms);
	ans += 2ll << zeros;
	if (bip) ans += (1ll << coms);
	printf("%lld\n", ans);
}
