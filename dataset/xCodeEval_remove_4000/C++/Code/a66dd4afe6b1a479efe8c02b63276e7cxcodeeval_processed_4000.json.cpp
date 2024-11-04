


















namespace CPTH{class HLD{public:HLD(size_t size=0);void init(size_t size);void addEdge(size_t u,size_t v);void build(size_t root=1);size_t lca(size_t u,size_t v)const;size_t id(size_t u)const;size_t atId(size_t x)const;size_t top(size_t u)const;size_t size(size_t u)const;size_t depth(size_t u)const;size_t bottom(size_t u)const;size_t parent(size_t u)const;size_t heavyChild(size_t u)const;std::vector<size_t>children(size_t u)const;std::pair<size_t,size_t>subtree(size_t u)const;std::vector<std::pair<size_t,size_t>>path(size_t u,size_t v)const;private:void dfs1(size_t u);void dfs2(size_t u);void validate(size_t u)const;void reset();private:bool built;size_t n,id0;std::vector<std::vector<size_t>>g;std::vector<size_t>pa,heavy,dep,siz,tp,bt,dfn,rdfn,exi;};HLD::HLD(size_t size){init(size);}void HLD::init(size_t size){assert(size<g.max_size());assert(size<pa.max_size());n=size;g.clear();g.resize(n+1);reset();}void HLD::addEdge(size_t u,size_t v){validate(u);validate(v);g[u].push_back(v);g[v].push_back(u);}void HLD::build(size_t root){if(built){if(root==atId(1))return;reset();}assert(n>=1);validate(root);dfs1(root);tp[root]=root;dfs2(root);assert(id0==n);built=true;}size_t HLD::lca(size_t u,size_t v)const{assert(built);validate(u);validate(v);while(tp[u]!=tp[v]){if(dep[tp[u]]>dep[tp[v]])u=pa[tp[u]];else v=pa[tp[v]];}return dep[u]<dep[v]?u:v;}size_t HLD::id(size_t u)const{assert(built);validate(u);return dfn[u];}size_t HLD::atId(size_t x)const{assert(built);validate(x);return rdfn[x];}size_t HLD::top(size_t u)const{assert(built);validate(u);return tp[u];}size_t HLD::size(size_t u)const{assert(built);validate(u);return siz[u];}size_t HLD::depth(size_t u)const{assert(built);validate(u);return dep[u];}size_t HLD::bottom(size_t u)const{assert(built);validate(u);return bt[tp[u]];}size_t HLD::parent(size_t u)const{assert(built);validate(u);return pa[u];}size_t HLD::heavyChild(size_t u)const{assert(built);validate(u);return heavy[u];}std::vector<size_t>HLD::children(size_t u)const{auto ret=g[u];if(pa[u])ret.erase(std::find(ret.begin(),ret.end(),pa[u]));return ret;}std::pair<size_t,size_t>HLD::subtree(size_t u)const{assert(built);validate(u);return{dfn[u],exi[u]};}std::vector<std::pair<size_t,size_t>>HLD::path(size_t u,size_t v)const{assert(built);validate(u);validate(v);std::vector<std::pair<size_t,size_t>>res;while(tp[u]!=tp[v]){if(dep[tp[u]]>dep[tp[v]]){res.emplace_back(dfn[tp[u]],dfn[u]);u=pa[tp[u]];}else{res.emplace_back(dfn[tp[v]],dfn[v]);v=pa[tp[v]];}}if(dep[u]>dep[v])std::swap(u,v);res.emplace_back(dfn[u],dfn[v]);return res;}void HLD::dfs1(size_t u){assert(siz[u]==0);siz[u]=1;for(auto v:g[u]){if(v==pa[u])continue;dep[v]=dep[u]+1;pa[v]=u;dfs1(v);siz[u]+=siz[v];if(siz[v]>siz[heavy[u]])heavy[u]=v;}}void HLD::dfs2(size_t u){bt[tp[u]]=u;dfn[u]=++id0;rdfn[dfn[u]]=u;if(heavy[u]){tp[heavy[u]]=tp[u];dfs2(heavy[u]);for(auto v:g[u]){if(v==pa[u]||v==heavy[u])continue;tp[v]=v;dfs2(v);}}exi[u]=id0;}void HLD::validate(size_t u)const{assert(u>=1);assert(u<=n);}void HLD::reset(){built=false;id0=0;pa.assign(n+1,0);heavy=dep=siz=tp=bt=dfn=rdfn=exi=pa;}}


																																																	
																																																	
																																																	
																																																	





																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	using namespace std;typedef long long ll;typedef vector<ll>vll;typedef vector<vll>vvll;typedef vvll v2ll;typedef vector<v2ll>v3ll;typedef vector<v3ll>v4ll;typedef unsigned long long ull;typedef vector<ull>vull;typedef vector<vull>vvull;typedef vvull v2ull;typedef vector<v2ull>v3ull;typedef vector<v3ull>v4ull;typedef long double ld;typedef vector<ld>vld;typedef vector<vld>vvld;typedef vvld v2ld;typedef vector<v2ld>v3ld;typedef vector<v3ld>v4ld;typedef pair<int,int>pii;typedef vector<int>vi;typedef vector<vi>vvi;typedef vvi v2i;typedef vector<vvi>v3i;typedef vector<v3i>v4i;typedef vector<bool>vb;typedef vector<vb>vvb;typedef vvb v2b;typedef vector<vvb>v3b;typedef vector<v3b>v4b;typedef vector<pii>vpii;typedef vector<vpii>vvpii;typedef vvpii v2pii;typedef vector<vvpii>v3pii;typedef vector<v3pii>v4pii;typedef vector<double>vd;typedef vector<vd>vvd;typedef vvd v2d;typedef vector<v2d>v3d;typedef vector<v3d>v4d;const double inf=1e121;const double eps=1e-10;mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());int randint(int l,int r){int out=rng()%(r-l+1)+l;return out>=l?out:out+r-l+1;}template<typename A,typename B>string to_string(pair<A,B>p);template<typename A,typename B,typename C>string to_string(tuple<A,B,C>p);template<typename A,typename B,typename C,typename D>string to_string(tuple<A,B,C,D>p);string to_string(const string&s){return'"'+s+'"';}string to_string(const char*s){return to_string((string)s);}string to_string(bool b){return(b?"true":"false");}string to_string(vector<bool>v){bool first=true;string res="{";for(int i=0;i<static_cast<int>(v.size());i++){if(!first){res+=", ";}first=false;res+=to_string(v[i]);}res+="}";return res;}template<size_t N>string to_string(bitset<N>v){string res="";for(size_t i=0;i<N;i++){res+=static_cast<char>('0'+v[i]);}return res;}template<typename A>string to_string(A v){bool first=true;string res="{";for(const auto&x:v){if(!first){res+=", ";}first=false;res+=to_string(x);}res+="}";return res;}template<typename A,typename B>string to_string(pair<A,B>p){return"("+to_string(p.first)+", "+to_string(p.second)+")";}template<typename A,typename B,typename C>string to_string(tuple<A,B,C>p){return"("+to_string(get<0>(p))+", "+to_string(get<1>(p))+", "+to_string(get<2>(p))+")";}template<typename A,typename B,typename C,typename D>string to_string(tuple<A,B,C,D>p){return"("+to_string(get<0>(p))+", "+to_string(get<1>(p))+", "+to_string(get<2>(p))+", "+to_string(get<3>(p))+")";}template<typename A,typename B,typename C,typename D,typename E>string to_string(tuple<A,B,C,D,E>p){return"("+to_string(get<0>(p))+", "+to_string(get<1>(p))+", "+to_string(get<2>(p))+", "+to_string(get<3>(p))+","+to_string(get<4>(p))+")";}void debug_out(){cerr<<endl;}template<typename Head,typename...Tail>void debug_out(Head H,Tail...T){cerr<<" "<<to_string(H);debug_out(T...);}template<typename T>struct is_pair{static const bool value=false;};template<typename T,typename U>struct is_pair<std::pair<T,U>>{static const bool value=true;};
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	const int INF=0x3f3f3f3f3f3f3f3fll;
																																																	
																																																	const int INF=0x3f3f3f3f;
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	ll read(){ll x;cin>>x;return x;}template<typename T>void read(T&x){cin>>x;}template<typename T>void write(const T&x){cout<<x;}void write(double x){cout<<fixed<<setprecision(12)<<x;}
																																																	
																																																	
																																																	
																																																	
																																																	template<typename T>typename enable_if<!is_integral<T>::value&&!is_pair<T>::value,void>::type read(T&x){cin>>x;}ll read(){char c;ll out=0,f=1;for(c=getchar();!isdigit(c)&&c!='-';c=getchar()){}if(c=='-'){f=-1;c=getchar();}for(;isdigit(c);c=getchar())out=(out<<3)+(out<<1)+c-'0';return out*f;}template<typename T>typename enable_if<is_integral<T>::value,T>::type read(T&x){char c;T f=1;x=0;for(c=getchar();!isdigit(c)&&c!='-';c=getchar()){}if(c=='-'){f=-1;c=getchar();}for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';return x*=f;}char read(char&x){for(x=getchar();isspace(x);x=getchar()){}return x;}double read(double&x){scanf("%lf",&x);return x;}template<typename T>typename enable_if<!is_integral<T>::value&&!is_pair<T>::value,void>::type write(const T&x){cout<<x;}template<typename T>typename enable_if<is_integral<T>::value,void>::type write(const T&x){if(x<0){putchar('-');write(-x);return;}if(x>9)write(x/10);putchar(x%10+'0');}void write(char x){putchar(x);}void write(double x){printf("%.12lf",x);}void write(ld x){cout<<fixed<<setprecision(12)<<x;}
																																																	
																																																	template<typename T>typename enable_if<is_pair<T>::value,void>::type read(T&x){read(x.fi);read(x.se);}template<typename T>typename enable_if<is_pair<T>::value,void>::type write(const T&x){write(x.fi);sp;write(x.se);}template<typename T,typename...Args>void read(T&x,Args&...args){read(x);read(args...);}template<typename OutputIt,typename=typename enable_if<is_same<output_iterator_tag,typename iterator_traits<OutputIt>::iterator_category>::value||(is_base_of<forward_iterator_tag,typename iterator_traits<OutputIt>::iterator_category>::value&&!is_const<OutputIt>::value)>::type>void read(OutputIt __first,OutputIt __last){for(;__first!=__last;++__first)read(*__first);}template<typename InputIt,typename=typename enable_if<is_base_of<input_iterator_tag,typename iterator_traits<InputIt>::iterator_category>::value>::type>void wts(InputIt __first,InputIt __last){bool isFirst=true;for(;__first!=__last;++__first){if(isFirst)isFirst=false;else sp;write(*__first);}br;}template<typename InputIt,typename=typename enable_if<is_base_of<input_iterator_tag,typename iterator_traits<InputIt>::iterator_category>::value>::type>void wtb(InputIt __first,InputIt __last){for(;__first!=__last;++__first){write(*__first);br;}}template<typename T>void wts(const T&x){write(x);sp;}template<typename T>void wtb(const T&x){write(x);br;}template<typename T>void wte(const T&x){write(x);exit(0);}template<typename T,typename...Args>void wts(const T&x,Args...args){wts(x);wts(args...);}template<typename T,typename...Args>void wtb(const T&x,Args...args){wts(x);wtb(args...);}template<typename T,typename...Args>void wte(const T&x,Args...args){wts(x);wte(args...);}template<typename T1,typename T2>inline bool up(T1&x,const T2&y){return x<y?x=y,1:0;}template<typename T1,typename T2>inline bool dn(T1&x,const T2&y){return y<x?x=y,1:0;}template<typename T1,typename T2,typename T3>inline bool inRange(const T1&x,const T2&l,const T3&r){return!(x<l)&&!(r<x);}template<typename T1,typename T2>inline auto id2(const T1&x,const T2&y)->decltype(x<y?x:y){return x<y?x:y;}template<typename T1,typename T2>inline auto id1(const T1&x,const T2&y)->decltype(x<y?y:x){return x<y?y:x;}template<typename T1,typename T2,typename T3>inline T1&madd(T1&x,const T2&y,const T3&modulo){return x=(ll)(x+y+modulo)%modulo;}template<typename T1,typename T2,typename T3>inline T1&mmul(T1&x,const T2&y,const T3&modulo){return x=(ll)x*y%modulo;}inline int modadd(int x,int y,int modulo){return x+y>=modulo?x+y-modulo:x+y;}inline int isinf(int x){return x<INF?x:-1;}inline void yesno(bool x){wtb(x?"Yes":"No");}





signed main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	int n, m;
	
	read(n, m);
	
	CPTH::HLD hld(n);
	For (i, 2, n) hld.addEdge(read(), i);
	hld.build();
	
	vi t(n + 1);
	read(BE1(t));
	
	const int B = sqrt(n) * 2;
	
	int ans = 0;
	
	vi w(n + 1), vac(n + 1);
	
	For (i, 1, n) w[i] = -t[i];
	
	for (int l = 0; l < m; l += B)
	{
		vi q(min(B, m - l));
		read(BE(q));
		
		vi a;
		a.reserve(q.size() * 2);
		for (auto x : q) a.pb(abs(x));
		a.pb(1);
		sort(BE(a), [&](int x, int y) { return hld.id(x) < hld.id(y); });
		For (i, 1, a.size() - 1) a.pb(hld.lca(a[i - 1], a[i]));
		sort(BE(a), [&](int x, int y) { return hld.id(x) < hld.id(y); });
		a.resize(unique(BE(a)) - a.begin());
		
		stack<int> stk;
		vvi g(n + 1);
		vi pa(n + 1);
		vb inv(n + 1);
		
		for (auto u : a)
		{
			inv[u] = true;
			if (u == 1)
			{
				stk.push(u);
				continue;
			}
			while (!inRange(hld.id(u), hld.subtree(stk.top()).fi, hld.subtree(stk.top()).se)) stk.pop();
			g[stk.top()].pb(u);
			pa[u] = stk.top();
			stk.push(u);
		}
		
		vpii bucket;
		bucket.reserve(n);
		
		for (auto u : a)
		{
			if (u == 1) continue;
			for (int x = hld.parent(u); !inv[x]; x = hld.parent(x)) if (!vac[x]) bucket.eb(x, u);
		}
		
		sort(BE(bucket), [&](pii x, pii y) { return w[x.fi] < w[y.fi]; });
		
		vvpii cnt(n + 1);
		vi delta(n + 1), p(n + 1, 0);
		for (auto x : bucket)
		{
			if (cnt[x.se].empty() || cnt[x.se].back().fi != w[x.fi])
			{
				cnt[x.se].eb(w[x.fi], 0);
				if (w[x.fi] <= 0) p[x.se] = cnt[x.se].size();
			}
			++cnt[x.se].back().se;
		}
		
		for (auto u : q)
		{
			if (u > 0)
			{
				if (w[u] > 0) --ans;
				for (int x = u; x != 1; x = pa[x])
				{
					++delta[x];
					if (p[x] && cnt[x][p[x] - 1].fi + delta[x] > 0)
					{
						ans += cnt[x][--p[x]].se;
					}
					++w[pa[x]];
					if (!vac[pa[x]] && w[pa[x]] == 1) ++ans;
				}
			}
			else
			{
				u = -u;
				if (w[u] > 0) ++ans;
				for (int x = u; x != 1; x = pa[x])
				{
					--delta[x];
					if (p[x] < (int)cnt[x].size() && cnt[x][p[x]].fi + delta[x] <= 0)
					{
						ans -= cnt[x][p[x]++].se;
					}
					--w[pa[x]];
					if (!vac[pa[x]] && w[pa[x]] == 0) --ans;
				}
			}
			vac[u] ^= 1;
			wts(ans);
		}
		
		for (auto u : a)
		{
			if (u == 1) continue;
			for (int x = hld.parent(u); !inv[x]; x = hld.parent(x))
			{
				w[x] += delta[u];
			}
		}
	}
	
	return 0;
}
