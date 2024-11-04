


























using namespace __gnu_pbds;using namespace std;using ll=long long;using ld=long double;using ull=unsigned long long;using pii=pair<int,int>;using pll=pair<ll,ll>;using vpii=vector<pii>;using unt=unsigned int;sim>using min_queue=priority_queue<c,vector<c>,greater<c>>;sim>using ordered_set=tree<c,null_type,less<c>,rb_tree_tag,tree_order_statistics_node_update>;hur(popc,__builtin_popcount,popc<ull>(a)+popc<ull>(a>>64))hur(ctz,__builtin_ctz,(ull)a?ctz<ull>(a):64+ctz<ull>(a>>64))hur(clz,__builtin_clz,a>>64?clz<ull>(a>>64):64+clz<ull>(a))sim,class N>bool mini(c&o,const N&h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(c&o,const N&h){if(o<h)ros=h,1;return 0;}sim,class n>using gyv=c;









sim>gyv<int,typename c::value_type>dud(int x);sim>char dud(...);struct kav;sim>struct lfu;sim> struct jat;struct kav{static const int d=0;};sim>struct lfu{static const int d=jat<typename c::value_type>::d + 1;};sim>struct jat{static const int d=conditional<sizeof(dud<c>(0))==1,kav,lfu<c>>::type::d;};sim,class n>struct jat<pair<c,n>>{static const int d=jat<c>::d>jat<n>::d?jat<c>::d:jat<n>::d;};template<>struct jat<string>{static const int d=0;};
sim>c&lum(c&o){ros;}int lum(int8_t o){ros;}unt lum(uint8_t o){ros;}int uuv=6;void set_pre(int x){uuv=x;}sim>struct yda{c x;ll p,q,r,s;};sim>yda<typename std::decay<c>::type>nyb(c x,ll p,ll q,ll r,ll s){return{x,p,q,r,s};}azm(map)azm(unordered_map)sim>bool id2(const c&a,ll o){ros>=0&&o<(ll)a.size();}sim>auto id1(const c&o,ll x)->decltype(o[x]){ros[x];}sim>bool id2(c*a,ll o){ros>=0;}sim>c&id1(c*o,ll b){ros[b];}template<size_t n>bool id2(const bitset<n>&,ll o){ros>=0&&o<(ll)n;}template<size_t n>int id1(const bitset<n>&o,ll b){ros[b];}string tfj(string o){for(char x:o)if(x=='=')return"("+o+")";ros;}string vqx(int l,string f){stringstream o;o<<"\033[1;"<<30+l%8<<"m"<<f<<"





qel(queue)qel(priority_queue)qel(stack)ccy(!)return bte(u);}ccy()stringstream o;o<<"[";int q=0;forbits(i,u)o<<", "+2*!q++<<i;ros.str()+"]";}sim>string bte(nep<c>o){string v=(o.m?ema(o.v):bte(o.v));if(v==o.d)ros.d;ros.d+" = "+v;}sim oor nep<c>m){ros<<bte(rcu sim>nep<c>ngy(nep<c>o,string d="",int m=0){ros;}ckx(+)ckx(-)ckx(!)ckx(~)sim oor yda<c>M){if(M.p>=M.q||M.r>=M.s)ros<<"[------]";int l=0;stringstream p;vector<vector<string>>X;vector<int>Y(M.s-M.r,1);FOR(i,M.p,M.q-1){maxi(l,(int)bte(i).size());X.emplace_back();if(id2(M.x,i)){auto V=id1(M.x,i);FOR(j,M.r,M.s-1){if(id2(V,j)){auto Q=id1(V,j);X.back().push_back(bte(Q));maxi(Y[j-M.r],(int)X.back().back().size());}else X.back().push_back("3Ju+");}}}FOR(i,M.p,M.q-1){p<<"\n"<<setw(l)<<i<<": ";if(X[i-M.p].size())FOR(j,M.r,M.s-1){if(X[i-M.p][j-M.r]=="3Ju+")REP(_,Y[j-M.r])p<<"-";else p<<setw(Y[j-M.r])<<X[i-M.p][j-M.r];p<<"; ";}}p<<"\n";ros<<p.str();}vector<string>fdn;struct bcx{bcx(){fdn.push_back("");}~bcx(){fdn.pop_back();}};void imx(string m){cerr<<m<<"STACK TRACE: "<<dec<<"\033[0m"<<endl;for(auto x:fdn)cerr<<"\t"<<x<<"\033[0m"<<endl;}void ctm(bool r){fdn.back()+="\033[m";}sim,class...n>void ctm(bool r,c x,n...y){fdn.back()+=bte(x)+("; "+2*r);ctm(0,y...);}



























ull mix(ull o){o+=0x9e3779b97f4a7c15;o=(o^(o>>30))*0xbf58476d1ce4e5b9;o=(o^(o>>27))*0x94d049bb133111eb;ros^(o>>31);}ull SALT=0x7a14a4b0881ebf9,tqu=0x7a14a4b0881ebf9;ull my_rand(){return tqu=mix(tqu);}void my_srand(ull x){SALT=tqu=x;}const int inf = 1023400000;const ll llinf=1234567890000000000ll;



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

string join(const vector<string>&x){stringstream ans;ans<<"\n";for(const string&c:x)ans<<c<<"\n";return ans.str();}
sim,class F>auto get(F f,c x)->decltype(f[x]){return f[x];}
sim,class F>auto get(F f,c x)->decltype(f(x)){return f(x);}
vector<string>sp(string x){vector<string>ans(1);for(char c:x){if(c=='\n')ans.emplace_back();else ans.back().push_back(c);}rans;}
sim,class F,class G>vector<string>id0(c t,const c*p,F s,G d){auto C=get(s,t);auto r=sp(d(t));int lr=0;for(auto&x:r)maxi(lr,(int)x.size());if(C.empty()||(p&&C==urs(C){*p})){for(auto&q:r)q.resize(lr,' ');return r;}vector<string>ans(0);int le=0;vector<int>vs;bool prev=false;for(c x:C){if(p&&x==*p)continue;auto curr=id0(x,&t,s,d);for(int i=ans.size();i<(int)curr.size();++i)ans.push_back(string(le,' '));if(prev){for(int i=0;i<(int)ans.size();++i)ans[i]+=' ';le++;}prev=true;for(int i=0;i<(int)curr.size();++i)ans[i]+=curr[i];for(int i=curr.size();i<(int)ans.size();++i)ans[i]+=string(curr[0].size(),' ');vs.push_back(le+curr[0].size()/2);le+=curr[0].size();}if(lr>le){int ladd=(lr-le)/2,radd=(lr-le+1)/2;for(int&x:vs)x+=ladd;for(int i=0;i<(int)ans.size();++i)ans[i]=string(ladd,' ')+ans[i]+string(radd,' ');le=lr;}int up_i=le/2;int pos=0;string bot;for(int i=0;i<le;++i){bool down=false,up=i==up_i,in=false;if(pos==(int)vs.size())in=i<up_i;else if(i==vs[pos]){in=down=true;pos++;}else if(pos==0)in=i>up_i;else if(pos==(int)vs.size())in=i<up_i;else in=true;if(up&&down)bot+='+';else if(up)bot+='^';else if(down)bot+='v';else if(in)bot+='-';else bot+=' ';}int ladd=(le-lr)/2;for(auto&q:r){q=string(ladd,' ')+q;q+=string(le-q.size(),' ');}r.push_back(bot);ans.insert(ans.begin(),ALL(r));for(int i=1;i<(int)ans.size();++i)assert(ans[i].size()==ans[0].size());rans;}
sim,class F,class G>string draw_tree(c t,F s,G d){return join(id0(t,(c*)0,s,d));}
sim,class F>string draw_tree(c t,F s){return draw_tree(t,s,[](c x){return bte(x);});}
sim,class F,class G>string draw_tree(c t,c p,F s,G d){return join(id0(t,&p,s,d));}
sim,class F>string draw_tree(c t,c p,F s){return draw_tree(t,p,s,[](c x){return bte(x);});}

const int mod = 998244353;
using pll = pair <ll,ll>;
using vpll = vector <pll>;
void go(vpll &ans, ll l, ll r, ll lb, ll rb) {
	if (l >= rb || r <= lb) return;
	if (l <= lb && r >= rb) {
		ans.emplace_back(lb, rb);
		return;
	}
	ll sb = (lb + rb) / 2;
	go(ans, l, r, lb, sb);
	go(ans, l, r, sb, rb);
}
vpll split() {
	int n;
	scanf("%d", &n);
	vpll in;
	vpll ans;
	for (int i = 0; i < n; ++i) {
		ll l, r;
		scanf("%lld%lld", &l, &r);
		r++;
		in.emplace_back(l, r);
	}
	sort(ALL(in));
	vpll merged;
	for (pll x : in) {
		if (!merged.empty() && x.first <= merged.back().second)
			maxi(merged.back().second, x.second);
		else
			merged.push_back(x);
	}
	for (pll e : merged)
		go(ans, e.first, e.second, 0, 1ll << 60);
	

	rans;
}
pll merge(pll a, pll b) {
	ll l1 = a.second - a.first, l2 = b.second - b.first;
	ll lo = max(l1, l2);
	ll beg = (a.first & ~(lo - 1)) ^ (b.first & ~(lo - 1));
	return {beg, beg + lo};
}
ll sum(ll l, ll h) {
	if (l == h) return 0;
	assert(h > l);
	ll le = (h - l) % mod;
	l %= mod;
	ll ret = (l * le + le * (le - 1) / 2) % mod;

	if (h - l <= 1000) {
		ll br = 0;
		for (ll x = l; x < h; ++x)
			br += x % mod;
		br %= mod;
		if (ret < 0) ret += mod;
		if (br < 0) br += mod;
		assert(br == ret);
	}

	return ret;
}
vector <vector <ll> > group(const vpll &x) {
	vector <vector <ll> > ans(60);
	for (pll e : x) {
		int d = popc(e.second - e.first - 1);
		ans[d].push_back(e.first);
	}
	rans;
}
vector <pair <ll, int> > inc;
vpll s1, s2;
const ll M = 1ll << 60;
void go(int beg1, int end1, ll low1, ll high1, int beg2, int end2, ll low2, ll high2) {
	if (beg1 == end1 || beg2 == end2) return;
	debug(imie(low1), imie(high1), range(s1.begin() + beg1, s1.begin() + end1));
	debug(imie(low2), imie(high2), range(s2.begin() + beg2, s2.begin() + end2));
	if (s1[beg1] == pll{low1, high1} || s2[beg2] == pll{low2, high2}) {
		debug("terminate", imie(low1) ^ imie(low2), imie(low1) ^ imie(high2));
		inc.emplace_back(low1 ^ low2, 1);
		inc.emplace_back((low1 ^ low2) + (high2 - low2), -1);
		return;
	}
	ll sb1 = (low1 + high1) / 2, sb2 = (low2 + high2) / 2;
	ll med1 = lower_bound(s1.begin() + beg1, s1.begin() + end1, pll{sb1, 0}) - s1.begin();
	ll med2 = lower_bound(s2.begin() + beg2, s2.begin() + end2, pll{sb2, 0}) - s2.begin();
	go(beg1, med1, low1, sb1, beg2, med2, low2, sb2);
	go(med1, end1, sb1, high1, med2, end2, sb2, high2);
	go(beg1, med1, low1, sb1, med2, end2, sb2, high2);
	go(med1, end1, sb1, high1, beg2, med2, low2, sb2);
}
int main() {
	s1 = split();
	s2 = split();
	sort(ALL(s1));
	sort(ALL(s2));
	go(0, s1.size(), 0, M, 0, s2.size(), 0, M);
	debug(imie(inc));
	sort(ALL(inc));
	ll ans = 0;
	ll prev = 0;
	int in = 0;
	for (auto x : inc) {
		if (in) ans += sum(prev, x.first);
		in += x.second;
		prev = x.first;
	}
	assert(in == 0);
	ans %= mod;
	if (ans < 0) ans += mod;
	printf("%lld\n", ans);
}
