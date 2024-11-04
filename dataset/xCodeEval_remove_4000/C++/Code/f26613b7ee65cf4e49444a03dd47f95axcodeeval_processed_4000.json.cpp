



















namespace CPTH{template<typename valueType,typename modType>struct SegmentTreeNode{size_t id;long long left,right;valueType val;modType mod;};template<typename valueType,typename modType,bool id2=false>class SegmentTree{public:SegmentTree()=default;SegmentTree(const std::vector<valueType>&_initValue,std::function<valueType(const valueType&,const valueType&)>_merge,std::function<void(SegmentTreeNode<valueType,modType>&,const modType&)>_update,long long _startPoint=1,const valueType&_valueZero=valueType(),const modType&_modZero=modType());void init(const std::vector<valueType>&_initValue,std::function<valueType(const valueType&,const valueType&)>_merge,std::function<void(SegmentTreeNode<valueType,modType>&,const modType&)>_update,long long _startPoint=1,const valueType&_valueZero=valueType(),const modType&_modZero=modType());void modify(long long l,long long r,const modType&mod);void modify(long long p,const modType&mod);valueType query(long long l,long long r);valueType query(long long p);private:void pushup(size_t cur);void pushdown(size_t cur);void build(size_t cur,long long l,long long r,const std::vector<valueType>&initValue);void m_init(const std::vector<valueType>&_initValue,std::function<valueType(const valueType&,const valueType&)>_merge,std::function<void(SegmentTreeNode<valueType,modType>&,const modType&)>_update,const valueType&_valueZero,const modType&_modZero);void modify(size_t cur,long long l,long long r,long long L,long long R,const modType&mod);valueType query(size_t cur,long long l,long long r,long long L,long long R);std::function<valueType(const valueType&,const valueType&)>merge;std::function<void(SegmentTreeNode<valueType,modType>&,const modType&)>update;std::vector<SegmentTreeNode<valueType,modType>>nodes;long long leftRange=0,rightRange=0;valueType valueZero;modType modZero;};template<typename valueType,typename modType,bool id2>SegmentTree<valueType,modType,id2>::SegmentTree(const std::vector<valueType>&_initValue,std::function<valueType(const valueType&,const valueType&)>_merge,std::function<void(SegmentTreeNode<valueType,modType>&,const modType&)>_update,long long _startPoint,const valueType&_valueZero,const modType&_modZero){init(_initValue,_merge,_update,_startPoint,_valueZero,_modZero);}template<typename valueType,typename modType,bool id2>void SegmentTree<valueType,modType,id2>::init(const std::vector<valueType>&_initValue,std::function<valueType(const valueType&,const valueType&)>_merge,std::function<void(SegmentTreeNode<valueType,modType>&,const modType&)>_update,long long _startPoint,const valueType&_valueZero,const modType&_modZero){assert(_startPoint>=LLONG_MIN/2);assert(_startPoint<=LLONG_MAX/2-(long long)_initValue.size());leftRange=_startPoint;rightRange=_startPoint+_initValue.size();m_init(_initValue,_merge,_update,_valueZero,_modZero);}template<typename valueType,typename modType,bool id2>void SegmentTree<valueType,modType,id2>::modify(long long l,long long r,const modType&mod){assert(!id2);modify(1,leftRange,rightRange,l,r,mod);}template<typename valueType,typename modType,bool id2>void SegmentTree<valueType,modType,id2>::modify(long long p,const modType&mod){assert(p<LLONG_MAX);modify(1,leftRange,rightRange,p,p+1,mod);}template<typename valueType,typename modType,bool id2>valueType SegmentTree<valueType,modType,id2>::query(long long l,long long r){return query(1,leftRange,rightRange,l,r);}template<typename valueType,typename modType,bool id2>valueType SegmentTree<valueType,modType,id2>::query(long long p){return query(p,p+1);}template<typename valueType,typename modType,bool id2>void SegmentTree<valueType,modType,id2>::pushup(size_t cur){nodes[cur].val=merge(nodes[cur<<1].val,nodes[cur<<1|1].val);}template<typename valueType,typename modType,bool id2>void SegmentTree<valueType,modType,id2>::pushdown(size_t cur){update(nodes[cur<<1],nodes[cur].mod);update(nodes[cur<<1|1],nodes[cur].mod);nodes[cur].mod=modZero;}template<typename valueType,typename modType,bool id2>void SegmentTree<valueType,modType,id2>::build(size_t cur,long long l,long long r,const std::vector<valueType>&initValue){nodes[cur].id=cur;nodes[cur].left=l;nodes[cur].right=r;nodes[cur].mod=modZero;if(l==r-1)nodes[cur].val=initValue[l-leftRange];else{build(cur<<1,l,(l+r)>>1,initValue);build(cur<<1|1,(l+r)>>1,r,initValue);pushup(cur);}}template<typename valueType,typename modType,bool id2>void SegmentTree<valueType,modType,id2>::m_init(const std::vector<valueType>&_initValue,std::function<valueType(const valueType&,const valueType&)>_merge,std::function<void(SegmentTreeNode<valueType,modType>&,const modType&)>_update,const valueType&_valueZero,const modType&_modZero){merge=_merge;update=_update;valueZero=_valueZero;modZero=_modZero;nodes.resize((rightRange-leftRange)<<2);build(1,leftRange,rightRange,_initValue);}template<typename valueType,typename modType,bool id2>void SegmentTree<valueType,modType,id2>::modify(size_t cur,long long l,long long r,long long L,long long R,const modType&mod){if(l>=R||r<=L)return;if(L<=l&&r<=R)update(nodes[cur],mod);else{if(!id2)pushdown(cur);modify(cur<<1,l,(l+r)>>1,L,R,mod);modify(cur<<1|1,(l+r)>>1,r,L,R,mod);pushup(cur);}}template<typename valueType,typename modType,bool id2>valueType SegmentTree<valueType,modType,id2>::query(size_t cur,long long l,long long r,long long L,long long R){if(l>=R||r<=L)return valueZero;if(L<=l&&r<=R)return nodes[cur].val;if(!id2)pushdown(cur);return merge(query(cur<<1,l,(l+r)>>1,L,R),query(cur<<1|1,(l+r)>>1,r,L,R));}}


																																																	
																																																	
																																																	
																																																	






																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	using namespace std;typedef long long ll;typedef vector<ll>vll;typedef vector<vll>vvll;typedef vvll v2ll;typedef vector<v2ll>v3ll;typedef vector<v3ll>v4ll;typedef unsigned long long ull;typedef vector<ull>vull;typedef vector<vull>vvull;typedef vvull v2ull;typedef vector<v2ull>v3ull;typedef vector<v3ull>v4ull;typedef long double ld;typedef vector<ld>vld;typedef vector<vld>vvld;typedef vvld v2ld;typedef vector<v2ld>v3ld;typedef vector<v3ld>v4ld;typedef pair<int,int>pii;typedef vector<int>vi;typedef vector<vi>vvi;typedef vvi v2i;typedef vector<vvi>v3i;typedef vector<v3i>v4i;typedef vector<bool>vb;typedef vector<vb>vvb;typedef vvb v2b;typedef vector<vvb>v3b;typedef vector<v3b>v4b;typedef vector<pii>vpii;typedef vector<vpii>vvpii;typedef vvpii v2pii;typedef vector<vvpii>v3pii;typedef vector<v3pii>v4pii;typedef vector<double>vd;typedef vector<vd>vvd;typedef vvd v2d;typedef vector<v2d>v3d;typedef vector<v3d>v4d;const double inf=1e121;const double eps=1e-10;mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());int randint(int l,int r){int out=rng()%(r-l+1)+l;return out>=l?out:out+r-l+1;}template<typename A,typename B>string to_string(pair<A,B>p);template<typename A,typename B,typename C>string to_string(tuple<A,B,C>p);template<typename A,typename B,typename C,typename D>string to_string(tuple<A,B,C,D>p);string to_string(const string&s){return'"'+s+'"';}string to_string(const char*s){return to_string((string)s);}string to_string(bool b){return(b?"true":"false");}string to_string(vector<bool>v){bool first=true;string res="{";for(int i=0;i<static_cast<int>(v.size());i++){if(!first){res+=", ";}first=false;res+=to_string(v[i]);}res+="}";return res;}template<size_t N>string to_string(bitset<N>v){string res="";for(size_t i=0;i<N;i++){res+=static_cast<char>('0'+v[i]);}return res;}template<typename A>string to_string(A v){bool first=true;string res="{";for(const auto&x:v){if(!first){res+=", ";}first=false;res+=to_string(x);}res+="}";return res;}template<typename A,typename B>string to_string(pair<A,B>p){return"("+to_string(p.first)+", "+to_string(p.second)+")";}template<typename A,typename B,typename C>string to_string(tuple<A,B,C>p){return"("+to_string(get<0>(p))+", "+to_string(get<1>(p))+", "+to_string(get<2>(p))+")";}template<typename A,typename B,typename C,typename D>string to_string(tuple<A,B,C,D>p){return"("+to_string(get<0>(p))+", "+to_string(get<1>(p))+", "+to_string(get<2>(p))+", "+to_string(get<3>(p))+")";}template<typename A,typename B,typename C,typename D,typename E>string to_string(tuple<A,B,C,D,E>p){return"("+to_string(get<0>(p))+", "+to_string(get<1>(p))+", "+to_string(get<2>(p))+", "+to_string(get<3>(p))+","+to_string(get<4>(p))+")";}void debug_out(){cerr<<endl;}template<typename Head,typename...Tail>void debug_out(Head H,Tail...T){cerr<<" "<<to_string(H);debug_out(T...);}template<typename T>struct is_pair{static const bool value=false;};template<typename T,typename U>struct is_pair<std::pair<T,U>>{static const bool value=true;};
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	const int INF=0x3f3f3f3f3f3f3f3fll;
																																																	
																																																	const int INF=0x3f3f3f3f;
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	ll read(){ll x;cin>>x;return x;}template<typename T>void read(T&x){cin>>x;}template<typename T>void write(const T&x){cout<<x;}void write(double x){cout<<fixed<<setprecision(12)<<x;}
																																																	
																																																	
																																																	
																																																	
																																																	template<typename T>typename enable_if<!is_integral<T>::value&&!is_pair<T>::value,void>::type read(T&x){cin>>x;}ll read(){char c;ll out=0,f=1;for(c=getchar();!isdigit(c)&&c!='-';c=getchar()){}if(c=='-'){f=-1;c=getchar();}for(;isdigit(c);c=getchar())out=(out<<3)+(out<<1)+c-'0';return out*f;}template<typename T>typename enable_if<is_integral<T>::value,T>::type read(T&x){char c;T f=1;x=0;for(c=getchar();!isdigit(c)&&c!='-';c=getchar()){}if(c=='-'){f=-1;c=getchar();}for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';return x*=f;}char read(char&x){for(x=getchar();isspace(x);x=getchar()){}return x;}double read(double&x){scanf("%lf",&x);return x;}template<typename T>typename enable_if<!is_integral<T>::value&&!is_pair<T>::value,void>::type write(const T&x){cout<<x;}template<typename T>typename enable_if<is_integral<T>::value,void>::type write(const T&x){if(x<0){putchar('-');write(-x);return;}if(x>9)write(x/10);putchar(x%10+'0');}void write(char x){putchar(x);}void write(double x){printf("%.12lf",x);}void write(ld x){cout<<fixed<<setprecision(12)<<x;}
																																																	
																																																	template<typename T>typename enable_if<is_pair<T>::value,void>::type read(T&x){read(x.fi);read(x.se);}template<typename T>typename enable_if<is_pair<T>::value,void>::type write(const T&x){write(x.fi);sp;write(x.se);}template<typename T,typename...Args>void read(T&x,Args&...args){read(x);read(args...);}template<typename OutputIt,typename=typename enable_if<is_same<output_iterator_tag,typename iterator_traits<OutputIt>::iterator_category>::value||(is_base_of<forward_iterator_tag,typename iterator_traits<OutputIt>::iterator_category>::value&&!is_const<OutputIt>::value)>::type>void read(OutputIt __first,OutputIt __last){for(;__first!=__last;++__first)read(*__first);}template<typename InputIt,typename=typename enable_if<is_base_of<input_iterator_tag,typename iterator_traits<InputIt>::iterator_category>::value>::type>void wts(InputIt __first,InputIt __last){bool isFirst=true;for(;__first!=__last;++__first){if(isFirst)isFirst=false;else sp;write(*__first);}br;}template<typename InputIt,typename=typename enable_if<is_base_of<input_iterator_tag,typename iterator_traits<InputIt>::iterator_category>::value>::type>void wtb(InputIt __first,InputIt __last){for(;__first!=__last;++__first){write(*__first);br;}}template<typename T>void wts(const T&x){write(x);sp;}template<typename T>void wtb(const T&x){write(x);br;}template<typename T>void wte(const T&x){write(x);exit(0);}template<typename T,typename...Args>void wts(const T&x,Args...args){wts(x);wts(args...);}template<typename T,typename...Args>void wtb(const T&x,Args...args){wts(x);wtb(args...);}template<typename T,typename...Args>void wte(const T&x,Args...args){wts(x);wte(args...);}template<typename T1,typename T2>inline bool up(T1&x,const T2&y){return x<y?x=y,1:0;}template<typename T1,typename T2>inline bool dn(T1&x,const T2&y){return y<x?x=y,1:0;}template<typename T1,typename T2,typename T3>inline bool inRange(const T1&x,const T2&l,const T3&r){return!(x<l)&&!(r<x);}template<typename T1,typename T2>inline auto id1(const T1&x,const T2&y)->decltype(x<y?x:y){return x<y?x:y;}template<typename T1,typename T2>inline auto id0(const T1&x,const T2&y)->decltype(x<y?y:x){return x<y?y:x;}template<typename T1,typename T2,typename T3>inline T1&madd(T1&x,const T2&y,const T3&modulo){return x=(ll)(x+y+modulo)%modulo;}template<typename T1,typename T2,typename T3>inline T1&mmul(T1&x,const T2&y,const T3&modulo){return x=(ll)x*y%modulo;}inline int modadd(int x,int y,int modulo){return x+y>=modulo?x+y-modulo:x+y;}inline int isinf(int x){return x<INF?x:-1;}inline void yesno(bool x){wtb(x?"Yes":"No");}



using namespace CPTH;

struct LCT
{
	struct Node
	{
		int pa;
		vi ch;
		bool rev;
		
		Node() : pa(0), ch(2), rev(false) {}
	};
	
	vector<Node> t;
	
	LCT(int n) : t(n + 1) {}
	
	bool notRoot(int x) { return x == t[t[x].pa].ch[0] || x == t[t[x].pa].ch[1]; }
	
	void rotate(int x)
	{
		int y = t[x].pa;
		int z = t[y].pa;
		int k = x == t[y].ch[1];
		
		if (notRoot(y)) t[z].ch[y == t[z].ch[1]] = x;
		t[x].pa = z;
		t[y].ch[k] = t[x].ch[k ^ 1];
		t[t[x].ch[k ^ 1]].pa = y;
		t[x].ch[k ^ 1] = y;
		t[y].pa = x;
	}
	
	void reverse(int x)
	{
		swap(t[x].ch[0], t[x].ch[1]);
		t[x].rev ^= 1;
	}
	
	void pushdown(int x)
	{
		if (t[x].rev)
		{
			reverse(t[x].ch[0]);
			reverse(t[x].ch[1]);
			t[x].rev = false;
		}
	}
	
	void splay(int x)
	{
		static stack<int> stk;
		stk.push(x);
		for (int u = x; notRoot(u); u = t[u].pa) stk.push(t[u].pa);
		while (!stk.empty())
		{
			pushdown(stk.top());
			stk.pop();
		}
		while (notRoot(x))
		{
			int y = t[x].pa;
			int z = t[y].pa;
			if (notRoot(y)) rotate((x == t[y].ch[1]) ^ (y == t[z].ch[1]) ? x : y);
			rotate(x);
		}
	}
	
	void splay(int x, int goal)
	{
		while (t[x].pa != goal)
		{
			int y = t[x].pa;
			int z = t[y].pa;
			if (z != goal) rotate((x == t[y].ch[1]) ^ (y == t[z].ch[1]) ? x : y);
			rotate(x);
		}
	}
	
	void access(int x)
	{
		for (int y = 0; x; x = t[y = x].pa)
		{
			splay(x);
			t[x].ch[1] = y;
		}
	}
	
	void makeRoot(int x)
	{
		access(x);
		splay(x);
		reverse(x);
	}
	
	int findRoot(int x)
	{
		access(x);
		splay(x);
		while (t[x].ch[0])
		{
			pushdown(x);
			x = t[x].ch[0];
		}
		splay(x);
		return x;
	}
	
	bool link(int x, int y)
	{
		makeRoot(x);
		if (findRoot(y) == x) return false;
		access(y);
		splay(y);
		t[x].pa = y;
		return true;
	}
	
	void cut(int x, int y)
	{
		makeRoot(x);
		access(y);
		t[x].ch[1] = t[y].pa = 0;
	}
};

signed main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	int n, m;
	read(n, m);
	
	vvi a(n, vi(m + 1));
	for (auto &x : a) read(BE1(x));
	
	LCT lct(n * m);
	
	int r = 0;
	
	vvi g(n * m + 1);
	
	vpii dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	
	For (i, 0, n - 1)
	{
		For (j, 1, m)
		{
			For (k, 0, 3)
			{
				int ni = i + dir[k].fi;
				int nj = j + dir[k].se;
				if (inRange(ni, 0, n - 1) && inRange(nj, 1, m)) g[a[i][j]].pb(a[ni][nj]);
			}
		}
	}
	
	vi mxr(n * m + 1);
	
	For (l, 1, n * m)
	{
		bool flag = true;
		while (flag && r < n * m)
        {
        	++r;
        	For (i, 0, (int)g[r].size() - 1)
            {
            	int v = g[r][i];
            	if (inRange(v, l, r - 1))
            	{
            		if (!lct.link(r, v))
            		{
            			For (j, 0, i - 1)
            			{
            				int w = g[r][j];
            				if (inRange(w, l, r - 1)) lct.cut(r, w);
            			}
            			--r;
            			flag = false;
            			break;
            		}
            	}
            }
        }
        
        mxr[l] = r;
        
        for (auto v : g[l])
        {
        	if (inRange(v, l + 1, r))
        	{
        		lct.cut(l, v);
        	}
        }
    }
    
    SegmentTree<pii, int> seg(
    	vpii(n * m, pii(0, 1)),
    	[](pii x, pii y) {
    		if (x.fi == y.fi) return pii(x.fi, x.se + y.se);
    		return min(x, y);
    	},
    	[](SegmentTreeNode<pii, int> &u, int x) {
    		u.val.fi += x;
    		u.mod += x;
    	},
    	1,
    	pii(INF, 0)
    );
    
    ll ans = 0;
    
    FOR (l, n * m, 1)
    {
    	seg.modify(l, n * m + 1, 1);
    	for (auto v : g[l])
    	{
    		if (inRange(v, l + 1, mxr[l]))
    		{
    			seg.modify(v, n * m + 1, -1);
    		}
    	}
    	pii res = seg.query(l, mxr[l] + 1);
    	if (res.fi == 1) ans += res.se;
    }
    
    wtb(ans);
	
	return 0;
}
