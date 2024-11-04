


























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


const int A = 26;
const int nax = 1 << 19;
int down[nax][A];
int node[nax];
int trie[nax][A];
int par[nax];
int jump[nax];
int to[nax][A];
vpii queries[nax];
int ans[nax];
char curr[nax];
int tree[nax];
void add(int p, int v) {
	while (p < nax) {
		tree[p] += v;
		p += p & -p;
	}
}
int get(int p) {
	int ans = 0;
	while (p) {
		ans += tree[p];
		p -= p & -p;
	}
	rans;
}
int read(int l, int r) {
	return get(r - 1) - get(l - 1);
}
struct get_str {
	int (*t)[A];
	string operator[](int x) {
		string o;
		if (x == -1) return "-1";
		int turns = 0;
		while (x) {
			turns++;
			assert(turns < nax);
			int go = -1;
			REP(i, x) REP(j, A) {
				if (t[i][j] == x) {
					assert(go == -1);
					go = i;
					o.push_back(j + 'a');
				}
			}
			assert(go != -1);
			x = go;
		}
		reverse(ALL(o));
		ros;
	}
};
get_str ins = {down}, que = {trie};
int l[nax], r[nax];
vector <int> jump_rev[nax];
void dfs1(int x) {
	static int timer = 1;
	l[x] = timer++;
	for (int c : jump_rev[x]) dfs1(c);
	r[x] = timer;
}
void dfs2(int x, int state) {
	add(l[state], 1);
	for (pii q : queries[x])
		ans[q.second] = read(l[q.first], r[q.first]);
	REP(j, A) if (down[x][j] != -1) dfs2(down[x][j], to[state][j]);
	add(l[state], -1);
}
int main() {
	memset(down, -1, sizeof(down));
	memset(trie, -1, sizeof(trie));
	int n;
	scanf("%d", &n);
	FOR(i, 1, n) {
		int t;
		scanf("%d", &t);
		int p = -1;
		if (t == 1) p = 0;
		else scanf("%d", &p);
		p = node[p];
		char c;
		scanf(" %c", &c);
		if (down[p][c - 'a'] == -1) {
			down[p][c - 'a'] = i;
			node[i] = i;
		}
		else
			node[i] = down[p][c - 'a'];
	}
	int q;
	scanf("%d", &q);
	int first_free = 1;
	REP(i, q) {
		int v;
		scanf("%d%s", &v, curr);
		int p = 0;
		for (int j = 0; curr[j]; ++j) {
			int c = curr[j] - 'a';
			if (trie[p][c] == -1) {
				trie[p][c] = first_free;
				par[first_free] = p;
				first_free++;
			}
			p = trie[p][c];
		}
		queries[node[v]].emplace_back(p, i);
	}
	queue <int> wh;
	REP(i, A) if (trie[0][i] != -1) wh.push(trie[0][i]);
	while (!wh.empty()) {
		int i = wh.front();
		wh.pop();
		int c = -1;
		REP(j, A) if (trie[par[i]][j] == i) {
			c = j;
			break;
		}
		int p = jump[par[i]];
		while (p && trie[p][c] == -1)
			p = jump[p];
		if (trie[p][c] == -1 || trie[p][c] == i) jump[i] = p;
		else jump[i] = trie[p][c];
		debug(imie(c), imie(que)[imie(i)], imie(que)[arr(jump, i)]);
		REP(j, A) if (trie[i][j] != -1) wh.push(trie[i][j]);
	}
	FOR(i, 1, first_free - 1) jump_rev[jump[i]].push_back(i);
	wh.push(0);
	while (!wh.empty()) {
		int i = wh.front();
		wh.pop();
		REP(c, A) {
			if (trie[i][c] != -1) to[i][c] = trie[i][c];
			else if (i) to[i][c] = to[jump[i]][c];
			if (to[i][c])
				debug(imie(que)[imie(i)], (char)(c + 'a'), imie(que)[to[i][c]]);
		}
		REP(j, A) if (trie[i][j] != -1) wh.push(trie[i][j]);
	}
	dfs1(0);
	dfs2(0, 0);
	REP(i, q) printf("%d\n", ans[i]);
}
