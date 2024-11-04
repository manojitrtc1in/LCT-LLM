

























using namespace __gnu_pbds;using namespace std;using ll=long long;using ld=long double;using ull=unsigned long long;using pii=pair<int,int>;using pll=pair<ll,ll>;using vpii=vector<pii>;using unt=unsigned int;sim>using min_queue=priority_queue<c,vector<c>,greater<c>>;sim>using ordered_set=tree<c,null_type,less<c>,rb_tree_tag,tree_order_statistics_node_update>;hur(popc,__builtin_popcount)hur(ctz,__builtin_ctz)hur(clz,__builtin_clz)sim,class N>bool mini(c&o,const N&h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(c&o,const N&h){if(o<h)ros=h,1;return 0;}











int uuv=6;void set_pre(int x){uuv=x;}sim>struct yda{c x;ll p,q,r,s;};sim>yda<typename std::decay<c>::type>nyb(c x,ll p,ll q,ll r,ll s){return{x,p,q,r,s};}azm(map)azm(unordered_map)sim>yvd(vector<c>)sim>yvd(deque<c>)sim,size_t N>yvd(array<c,N>)yvd(string)sim>pair<bool,typename std::decay<c>::type>emz(c*a,ll b){return {1,a[b]};}template<size_t n>pair<bool,bool>emz(bitset<n>a,ll b){if(b>=0&&b<(ll)n)return{1,a[b]};return{0,0};}string tfj(string o){for(char x:o)if(x=='=')return "("+o+")";ros;}string vqx(int l,string f){stringstream o;o<<"\033[1;"<<30+l%8<<"m"<<f<<"




ccy(!)return bte(u);}ccy()stringstream o;o<<"[";int q=0;forbits(i,u)o<<", "+2*!q++<<i;ros.str()+"]";}sim>string bte(nep<c>o){string v=(o.m?ema(o.v):bte(o.v));if(v==o.d)ros.d;ros.d+" = "+v;}sim oor nep<c>m){ros<<bte(rcu sim>nep<c>ngy(nep<c>o,string d="",int m=0){ros;}ckx(+)ckx(-)ckx(!)ckx(~)sim oor yda<c>M){if(M.p>M.q||M.r>M.s)ros<<"[------]";int l=0;stringstream p;vector<vector<string>>X;vector<int>Y(M.s-M.r+1,1);FOR(i,M.p,M.q){maxi(l,(int)bte(i).size());auto V=emz(M.x,i);X.emplace_back();if(V.first)FOR(j,M.r,M.s){auto Q=emz(V.second,j);if(Q.first){X.back().push_back(bte(Q.second));maxi(Y[j-M.r],(int)X.back().back().size());}else X.back().push_back("3Ju+");}}FOR(i,M.p,M.q){p<<"\n"<<setw(l)<<i<<": ";if(X[i-M.p].size())FOR(j,M.r,M.s){if(X[i-M.p][j-M.r]=="3Ju+")REP(_,Y[j-M.r])p<<"-";else p<<setw(Y[j-M.r])<<X[i-M.p][j-M.r];p<<"; ";}}p<<"\n";ros<<p.str();}vector<string>fdn;struct bcx{bcx(){fdn.push_back("");}~bcx(){fdn.pop_back();}};void imx(string m){cerr<<m<<"STACK TRACE: "<<dec<<"\033[0m"<<endl;for(auto x:fdn)cerr<<"\t"<<x<<"\033[0m"<<endl;}void ctm(bool r){fdn.back()+="\033[m";}sim,class...n>void ctm(bool r,c x,n...y){fdn.back()+=bte(x)+("; "+2*r);ctm(0,y...);}

























clp(+)clp(-)clp(*)clp(/)clp(%)clp(^)clp(|)clp(>>)clp(<<)clp(&)pcg(&&)pcg(||)syd(-)syd(+)syd(~)syd(!)ull mix(ull o){o+=0x9e3779b97f4a7c15;o=(o^(o>>30))*0xbf58476d1ce4e5b9;o=(o^(o>>27))*0x94d049bb133111eb;ros^(o>>31);}namespace std{sim,class n>struct hash<pair<c,n>>{size_t operator()(const pair<c,n>&o)const{return mix(hash<typename decay<c>::type>()(o.first))^hash<typename decay<n>::type>()(o.second);}};sim>muu(vector<c>)sim>muu(list<c>)sim>muu(set<c>)sim,class n>muu(map<c,n>)sim,size_t N>muu(array<c,N>)sim>muu(deque<c>)}







sim,class m>using id0=cc_hash_table<c,m,hash<c>>;




void fre(string c) {

freopen((c+".in").c_str(),"r",stdin);freopen((c+".out").c_str(),"w",stdout);

} const int mod = 119 << 23 | 1;
ll inv(ll b){assert(b);int e=mod-2;ll o=1;while(e){if(e&1)o=o*b%mod;b=b*b%mod;e>>=1;}ros;}struct zet_p{int v;loc(ld w;)sim=int,typename=typename enable_if<is_integral<c>::value>::type>zet_p(c r=0):v(r%mod)loc(,w(r)){}loc(sim>zet_p(c a,ld b):v(a%mod),w(b){})rer(+,+y.v)rer(-,-y.v)rer(*,*1ll*y.v)rer(/,*inv(y.v))int get()const{return((unt)v+mod)%mod;}zet_p operator-()const{return zet_p(-v loc(,-w));}bool operator==(zet_p y)const{return(v-y.v)%mod==0;}};ycc(+)ycc(-)ycc(*)ycc(/)sim>bool operator==(c a,zet_p b){return zet_p(a)==b;}loc(ostream&operator<<(ostream&o,zet_p y){ros<<"["<<y.get()<<"~"<<y.w<<"]";})ull tqu=0x7a14a4b0881ebf9;ull my_rand(){return tqu=mix(tqu);}void my_srand(ull x){tqu=x;}



vector <int> in;
const int nax = 1100;
vector <int> occs[nax];
bool did[nax][nax];
zet_p dp[nax][nax];
zet_p go(int l, int r) {
	if (l == r) return 1;
	if (did[l][r]) return dp[l][r];
	pii mm = {nax, nax};
	for (int i = l; i < r; ++i) {
		mini(mm, pii{in[i], i});
	}
	int v = mm.first;
	zet_p ans = 0;
	if (l <= occs[v][0] && occs[v].back() < r) {
		zet_p lsum = 0, rsum = 0, mid = 1;
		for (int i = l; i <= occs[v][0]; ++i)
			lsum += go(l, i) * go(i, occs[v][0]);
		for (int i = occs[v].back() + 1; i <= r; ++i)
			rsum += go(occs[v].back() + 1, i) * go(i, r);
		int len = occs[v].size();
		REP(i, len - 1)
			mid *= go(occs[v][i] + 1, occs[v][i + 1]);
		debug(imie(lsum) * imie(rsum) * imie(mid));
		ans = lsum * rsum * mid;
	}
	else {
		debug("error ", arr(occs, v), imie(l), imie(r));
	}
	did[l][r] = 1;
	debug(range(in.begin() + l, in.begin() + r), imie(ans));
	dp[l][r] = ans;
	rans;
}
int main() {
	debug(imie(mod));
	int n, m;
	scanf("%d%d", &n, &m);
	int prev = -1;
	REP(i, m) {
		int x;
		scanf("%d", &x);
		if (prev != x) {
			in.push_back(x);
			prev = x;
		}
	}
	debug(imie(in));
	if ((int)in.size() > 2 * n) {
		return 0 * printf("0\n");
	}
	m = in.size();
	REP(i, m) occs[in[i]].push_back(i);
	printf("%d\n", go(0, m).get());
	return 0;
}
