


























using namespace __gnu_pbds;using namespace std;using ll=long long;using ld=long double;using ull=unsigned long long;using pii=pair<int,int>;using pll=pair<ll,ll>;using vpii=vector<pii>;using unt=unsigned int;sim>using min_queue=priority_queue<c,vector<c>,greater<c>>;sim>using ordered_set=tree<c,null_type,less<c>,rb_tree_tag,tree_order_statistics_node_update>;hur(popc,__builtin_popcount,popc<ull>(a)+popc<ull>(a>>64))hur(ctz,__builtin_ctz,(ull)a?ctz<ull>(a):64+ctz<ull>(a>>64))hur(clz,__builtin_clz,a>>64?clz<ull>(a>>64):64+clz<ull>(a))sim,class N>bool mini(c&o,const N&h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(c&o,const N&h){if(o<h)ros=h,1;return 0;}









sim>c&lum(c&o){ros;}int lum(int8_t o){ros;}unt lum(uint8_t o){ros;}int uuv=6;void set_pre(int x){uuv=x;}sim>struct yda{c x;ll p,q,r,s;};sim>yda<typename std::decay<c>::type>nyb(c x,ll p,ll q,ll r,ll s){return{x,p,q,r,s};}azm(map)azm(unordered_map)sim>bool id1(const c&a,ll o){cerr<<"o="<<o<<";a.size()="<<a.size()<<endl;ros>=0&&o<(ll)a.size();}sim>auto id0(const c&o,ll x)->decltype(o[x]){ros[x];}sim>bool id1(c*a,ll o){ros>=0;}sim>c&id0(c*o,ll b){ros[b];}template<size_t n>bool id1(const bitset<n>&,ll o){ros>=0&&o<(ll)n;}template<size_t n>int id0(const bitset<n>&o,ll b){ros[b];}string tfj(string o){for(char x:o)if(x=='=')return"("+o+")";ros;}string vqx(int l,string f){stringstream o;o<<"\033[1;"<<30+l%8<<"m"<<f<<"




ccy(!)return bte(u);}ccy()stringstream o;o<<"[";int q=0;forbits(i,u)o<<", "+2*!q++<<i;ros.str()+"]";}sim>string bte(nep<c>o){string v=(o.m?ema(o.v):bte(o.v));if(v==o.d)ros.d;ros.d+" = "+v;}sim oor nep<c>m){ros<<bte(rcu sim>nep<c>ngy(nep<c>o,string d="",int m=0){ros;}ckx(+)ckx(-)ckx(!)ckx(~)sim oor yda<c>M){if(M.p>M.q||M.r>M.s)ros<<"[------]";int l=0;stringstream p;vector<vector<string>>X;vector<int>Y(M.s-M.r+1,1);FOR(i,M.p,M.q){maxi(l,(int)bte(i).size());X.emplace_back();if(id1(M.x,i)){auto V=id0(M.x,i);FOR(j,M.r,M.s){if(id1(V,j)){auto Q=id0(V,j);X.back().push_back(bte(Q));maxi(Y[j-M.r],(int)X.back().back().size());}else X.back().push_back("3Ju+");}}}FOR(i,M.p,M.q){p<<"\n"<<setw(l)<<i<<": ";if(X[i-M.p].size())FOR(j,M.r,M.s){if(X[i-M.p][j-M.r]=="3Ju+")REP(_,Y[j-M.r])p<<"-";else p<<setw(Y[j-M.r])<<X[i-M.p][j-M.r];p<<"; ";}}p<<"\n";ros<<p.str();}vector<string>fdn;struct bcx{bcx(){fdn.push_back("");}~bcx(){fdn.pop_back();}};void imx(string m){cerr<<m<<"STACK TRACE: "<<dec<<"\033[0m"<<endl;for(auto x:fdn)cerr<<"\t"<<x<<"\033[0m"<<endl;}void ctm(bool r){fdn.back()+="\033[m";}sim,class...n>void ctm(bool r,c x,n...y){fdn.back()+=bte(x)+("; "+2*r);ctm(0,y...);}
























ull mix(ull o){o+=0x9e3779b97f4a7c15;o=(o^(o>>30))*0xbf58476d1ce4e5b9;o=(o^(o>>27))*0x94d049bb133111eb;ros^(o>>31);}ull SALT=0x7a14a4b0881ebf9,tqu=0x7a14a4b0881ebf9;ull my_rand(){return tqu=mix(tqu);}void my_srand(ull x){SALT=tqu=x;}const int inf = 1234000000;const ll llinf=1234567890000000000ll;



sim>inline c nux(c m){if(!m)return numeric_limits<c>::max();c A=m&-m;c B=~((A-1)^m);c C=B&-B;c D=(C>>(1+ctz(A)))-1;return C|(m&~(C-1))|D;}ll mul(ll a,ll b,ll m){ll q=a*(ld)b/m;ll o=a*b-q*m;o%=m;if(o<0)o+=m;ros;}sim>void unq(c&x){x.resize(unique(ALL(x))-x.begin());}sim>c gcd(c o,c b){while(o&&b){int x=ctz(o),y=ctz(b);if(x>y)o>>=x-y;else b>>=y-x;if(o>b)o-=b;else b-=o;}ros?o:b;}sim>c lcm(c o,c b){ros/gcd(o,b)*b;}
sim>typename enable_if<is_integral<c>::value,ull>::type my_hash(c x){
	if(sizeof(c)>8) return mix((ull)x^SALT)^mix((ull)(x>>64)^SALT);
	return mix(x^SALT);
}
template<size_t N>ull my_hash(const bitset<N>&x){
	return mix(hash<bitset<N>>()(x)^SALT);
}
sim,class n>using gyv=c;
sim,class n>ull my_hash(const pair<c,n>&);
sim>gyv<ull,typename c::value_type>my_hash(const c&x){
	ull o=SALT;
	for(auto&d:x)o=mix(o^my_hash(d));
	ros;
}
sim,class n>ull my_hash(const pair<c,n>&x){return mix(my_hash(x.first))^my_hash(x.second);}
sim>struct my_hasher{size_t operator()(const c&o)const{return my_hash(o);}};
sim,class m>using id2=loc(unordered_map)onl(cc_hash_table)<c,m,my_hasher<c>>;

const int nax = 1e3 + 44;
vector <int> graf[nax];
int siz[nax];
int dep[nax];
void dfs1(int x, int y = -1, int d = 0) {
	siz[x] = 1;
	dep[x] = d;
	for (int v : graf[x])
		if (v != y) {
			dfs1(v, x, d + 1);
			siz[x] += siz[v];
		}
}
vector <pair <pii, int> > ans;
deque <int> ava;
void dfs2(int x, int y, int d) {
	int t = ava.front();
	debug("pop ", imie(t));
	ava.pop_front();
	assert(t > d);
	ans.emplace_back(make_pair(x, y), t - d);
	debug(imie(x), imie(y), imie(d), imie(ans.back()));
	for (int v : graf[x]) if (v != y) dfs2(v, x, t);
}
int n;
vpii graf2[nax];
set <int> seen;
void dfs3(int x, int y = -1, int d = 0) {
	seen.insert(d);
	for (pii e : graf2[x]) if (e.first != y) dfs3(e.first, x, d + e.second);
}
void test_ans() {
	for (auto x : ans) {
		graf2[x.first.first].emplace_back(x.first.second, x.second);
		graf2[x.first.second].emplace_back(x.first.first, x.second);
	}
	FOR(i, 1, n) dfs3(i);
	debug(imie(seen));
	FOR(i, 1, n * n * 2 / 9) assert(seen.count(i));
}
int main() {
	scanf("%d", &n);
	if (n == 1) return 0;
	debug(imie(n * n * 2 / 9));
	REP(_, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	dfs1(1);
	int M = n * 2 / 3;
	FOR(i, 1, n) {
		vector <pii> sizes = {{1, i}};
		int p = -1;
		for (int v : graf[i]) {
			if (dep[v] == dep[i] + 1) {
				sizes.emplace_back(siz[v], v);
			}
			else {
				p = v;
			}
		}
		if (i != 1) sizes.emplace_back(n - siz[i], p);
		debug(imie(i), imie(sizes));
		bool good = true;
		for (pii x : sizes) {
			if (x.first > M)
				good = false;
		}
		if (good) {
			vpii v1, v2;
			sort(sizes.rbegin(), sizes.rend());
			int sum1 = 0, sum2 = 0;
			int whme = 0;
			debug(imie(sizes));
			for (pii c : sizes) {
				if (sum1 + c.first > M) {
					v2.push_back(c);
					sum2 += c.first;
					if (c.second == i) whme = 2;
				}
				else {
					v1.push_back(c);
					sum1 += c.first;
					if (c.second == i) whme = 1;
				}
				assert(sum1 <= M && sum2 <= M);
				debug(imie(sum1), imie(sum2));
			}
			assert(sum1 * sum2 >= n * n * 2 / 9);
			assert(whme != 0);
			if (whme == 2) {
				debug("swap");
				swap(v1, v2);
				swap(sum1, sum2);
			}
			FOR(j, 1, sum1 - 1) ava.push_back(j);
			debug(imie(ava));
			debug(imie(v1), imie(v2));
			for (pii x : v1) if (x.second != i) dfs2(x.second, i, 0);
			assert(ava.empty());
			REP(j, sum2) ava.push_back(1 + j * sum1);
			debug(imie(ava));
			for (pii x : v2) dfs2(x.second, i, 0);
			assert(ava.empty());
			for (auto x : ans) printf("%d %d %d\n", FS(x.first), x.second);
			loc(test_ans());
			return 0;
		}
		else
			debug("err");
	}
	assert(false);
}
