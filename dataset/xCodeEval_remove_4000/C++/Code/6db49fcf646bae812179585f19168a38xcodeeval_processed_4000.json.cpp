
























namespace CPTH
{
template <typename valueType, typename modType>
struct SegmentTreeNode
{
   public:
    std::size_t id;
    long long left, right;
    valueType val;
    modType mod;
};

template <typename valueType, typename modType, bool id2 = false>
class SegmentTree
{
   public:
    SegmentTree() = default;

    SegmentTree(const std::vector<valueType> &_initValue,
                std::function<valueType(const valueType &, const valueType &)> _merge,
                std::function<void(SegmentTreeNode<valueType, modType> &, const modType &)> _update,
                long long _startPoint = 1, const valueType &_valueZero = valueType(),
                const modType &_modZero = modType())
    {
        init(_initValue, _merge, _update, _startPoint, _valueZero, _modZero);
    }

    void init(const std::vector<valueType> &_initValue,
              std::function<valueType(const valueType &, const valueType &)> _merge,
              std::function<void(SegmentTreeNode<valueType, modType> &, const modType &)> _update,
              long long _startPoint = 1, const valueType &_valueZero = valueType(),
              const modType &_modZero = modType())
    {
        assert(_startPoint >= LLONG_MIN / 2);
        assert(_startPoint <= LLONG_MAX / 2 - (long long)_initValue.size());
        leftRange = _startPoint;
        rightRange = _startPoint + _initValue.size();
        m_init(_initValue, _merge, _update, _valueZero, _modZero);
    }

    void modify(long long l, long long r, const modType &mod)
    {
        modify(1, leftRange, rightRange, l, r, mod);
    }

    void modify(long long p, const modType &mod)
    {
        assert(p < LLONG_MAX);
        modify(1, leftRange, rightRange, p, p + 1, mod);
    }

    valueType query(long long l, long long r) { return query(1, leftRange, rightRange, l, r); }

    valueType query(long long p) { return query(p, p + 1); }

   private:
    void pushup(std::size_t cur)
    {
        nodes[cur].val = merge(nodes[cur << 1].val, nodes[cur << 1 | 1].val);
    }

    void pushdown(std::size_t cur)
    {
        update(nodes[cur << 1], nodes[cur].mod);
        update(nodes[cur << 1 | 1], nodes[cur].mod);
        nodes[cur].mod = modZero;
    }

    void build(std::size_t cur, long long l, long long r, const std::vector<valueType> &initValue)
    {
        nodes[cur].id = cur;
        nodes[cur].left = l;
        nodes[cur].right = r;
        nodes[cur].mod = modZero;
        if (l == r - 1) nodes[cur].val = initValue[l - leftRange];
        else
        {
            build(cur << 1, l, (l + r) >> 1, initValue);
            build(cur << 1 | 1, (l + r) >> 1, r, initValue);
            pushup(cur);
        }
    }

    void m_init(const std::vector<valueType> &_initValue,
                std::function<valueType(const valueType &, const valueType &)> _merge,
                std::function<void(SegmentTreeNode<valueType, modType> &, const modType &)> _update,
                const valueType &_valueZero, const modType &_modZero)
    {
        merge = _merge;
        update = _update;
        valueZero = _valueZero;
        modZero = _modZero;
        nodes.resize((rightRange - leftRange) << 2);
        build(1, leftRange, rightRange, _initValue);
    }

    void modify(std::size_t cur, long long l, long long r, long long L, long long R,
                const modType &mod)
    {
        if (l >= R || r <= L) return;
        if (L <= l && r <= R) update(nodes[cur], mod);
        else
        {
            if (!id2) pushdown(cur);
            modify(cur << 1, l, (l + r) >> 1, L, R, mod);
            modify(cur << 1 | 1, (l + r) >> 1, r, L, R, mod);
            pushup(cur);
        }
    }

    valueType query(std::size_t cur, long long l, long long r, long long L, long long R)
    {
        if (l >= R || r <= L) return valueZero;
        if (L <= l && r <= R) return nodes[cur].val;
        if (!id2) pushdown(cur);
        return merge(query(cur << 1, l, (l + r) >> 1, L, R),
                     query(cur << 1 | 1, (l + r) >> 1, r, L, R));
    }

    std::function<valueType(const valueType &, const valueType &)> merge;
    std::function<void(SegmentTreeNode<valueType, modType> &, const modType &)> update;
    std::vector<SegmentTreeNode<valueType, modType>> nodes;
    long long leftRange = 0, rightRange = 0;
    valueType valueZero;
    modType modZero;
};
}  





																																																	
																																																	
																																																	
																																																	




																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	using namespace std;typedef long long ll;typedef pair<int,int>pii;typedef vector<int>vi;typedef vector<vi> vvi;typedef vvi v2i;typedef vector<vvi>v3i;typedef vector<v3i>v4i;typedef vector<bool>vb;typedef vector<vb>vvb;typedef vvb v2b;typedef vector<vvb>v3b;typedef vector<v3b>v4b;typedef vector<pii>vpii;typedef vector<vpii>vvpii;typedef vvpii v2pii;typedef vector<vvpii>v3pii;typedef vector<v3pii>v4pii;typedef long double ld;typedef vector<ld>vd;typedef vector<vd>vvd;typedef vvd v2d;typedef vector<v2d>v3d;typedef vector<v3d>v4d;const ld inf=1e121;const ld eps=1e-10;mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());int randint(int l,int r){int out=rng()%(r-l+1)+l;return out>=l?out:out+r-l+1;}template<typename A,typename B>string to_string(pair<A,B>p);template<typename A,typename B,typename C>string to_string(tuple<A,B,C>p);template<typename A,typename B,typename C,typename D>string to_string(tuple<A,B,C,D>p);string to_string(const string&s){return '"'+s+'"';}string to_string(const char*s){return to_string((string)s);}string to_string(bool b){return(b?"true":"false");}string to_string(vector<bool>v){bool first=true;string res="{";for(int i=0;i<static_cast<int>(v.size());i++){if(!first){res+=",";}first=false;res+=to_string(v[i]);}res+="}";return res;}template<size_t N>string to_string(bitset<N>v){string res="";for(size_t i=0;i<N;i++){res+=static_cast<char>('0'+v[i]);}return res;}template<typename A>string to_string(A v){bool first=true;string res="{";for(const auto&x:v){if(!first){res+=",";}first=false;res+=to_string(x);}res+="}";return res;}template<typename A,typename B>string to_string(pair<A,B>p){return "("+to_string(p.first)+","+to_string(p.second)+")";}template<typename A,typename B,typename C>string to_string(tuple<A,B,C>p){return "("+to_string(get<0>(p))+","+to_string(get<1>(p))+","+to_string(get<2>(p))+")";}template<typename A,typename B,typename C,typename D>string to_string(tuple<A,B,C,D>p){return "("+to_string(get<0>(p))+","+to_string(get<1>(p))+","+to_string(get<2>(p))+","+to_string(get<3>(p))+")";}template<typename A,typename B,typename C,typename D,typename E>string to_string(tuple<A,B,C,D,E>p){return "("+to_string(get<0>(p))+","+to_string(get<1>(p))+","+to_string(get<2>(p))+","+to_string(get<3>(p))+","+to_string(get<4>(p))+")";}void debug_out(){cerr<<endl;}template<typename Head,typename...Tail>void debug_out(Head H,Tail...T){cerr<<" "<<to_string(H);debug_out(T...);}template<typename T>struct is_pair{static const bool value=false;};template<typename T,typename U>struct is_pair<std::pair<T,U>>{static const bool value=true;};
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	const int INF=0x3f3f3f3f3f3f3f3fll;
																																																	
																																																	const int INF=0x3f3f3f3f;
																																																	
																																																	
																																																	
																																																	
																																																	
																																																	ll read(){ll x;cin>>x;return x;}template<typename T>void read(T&x){cin>>x;}template<typename T>void write(const T&x){cout<<x;}
																																																	
																																																	
																																																	
																																																	
																																																	template<typename T>typename enable_if<!is_integral<T>::value&&!is_pair<T>::value,void>::type read(T&x){cin>>x;}ll read(){char c;ll out=0,f=1;for(c=getchar();!isdigit(c)&&c!='-';c=getchar());if(c=='-'){f=-1;c=getchar();}for(;isdigit(c);c=getchar())out=(out<<3)+(out<<1)+c-'0';return out*f;}template<typename T>typename enable_if<is_integral<T>::value,T>::type read(T&x){char c;T f=1;x=0;for(c=getchar();!isdigit(c)&&c!='-';c=getchar());if(c=='-'){f=-1;c=getchar();}for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';return x*=f;}char read(char&x){for(x=getchar();isspace(x);x=getchar());return x;}double read(double&x){scanf("%lf",&x);return x;}ld read(ld&x){scanf("%Lf",&x);return x;}template<typename T>typename enable_if<!is_integral<T>::value&&!is_pair<T>::value,void>::type write(const T&x){cout<<x;}template<typename T>typename enable_if<is_integral<T>::value,void>::type write(const T&x){if(x<0){putchar('-');write(-x);return;}if(x>9)write(x/10);putchar(x%10+'0');}void write(const char&x){putchar(x);}void write(const double&x){printf("%.10lf",x);}void write(const ld&x){printf("%.10Lf",x);}
																																																	
																																																	template<typename T>typename enable_if<is_pair<T>::value,void>::type read(T&x){read(x.fi);read(x.se);}template<typename T>typename enable_if<is_pair<T>::value,void>::type write(const T&x){write(x.fi);sp;write(x.se);}template<typename T,typename...Args>void read(T&x,Args&...args){read(x);read(args...);}template<typename OutputIt,typename=typename enable_if<is_same<output_iterator_tag,typename iterator_traits<OutputIt>::iterator_category>::value||(is_base_of<forward_iterator_tag,typename iterator_traits<OutputIt>::iterator_category>::value&&!is_const<OutputIt>::value)>::type>void read(OutputIt __first,OutputIt __last){for(;__first!=__last;++__first)read(*__first);}template<typename InputIt,typename=typename enable_if<is_base_of<input_iterator_tag,typename iterator_traits<InputIt>::iterator_category>::value>::type>void wts(InputIt __first,InputIt __last){bool isFirst=true;for(;__first!=__last;++__first){if(isFirst)isFirst=false;else sp;write(*__first);}br;}template<typename InputIt,typename=typename enable_if<is_base_of<input_iterator_tag,typename iterator_traits<InputIt>::iterator_category>::value>::type>void wtb(InputIt __first,InputIt __last){for(;__first!=__last;++__first){write(*__first);br;}}template<typename T>void wts(const T&x){write(x);sp;}template<typename T>void wtb(const T&x){write(x);br;}template<typename T>void wte(const T&x){write(x);exit(0);}template<typename T,typename...Args>void wts(const T&x,Args...args){wts(x);wts(args...);}template<typename T,typename...Args>void wtb(const T&x,Args...args){wts(x);wtb(args...);}template<typename T,typename...Args>void wte(const T&x,Args...args){wts(x);wte(args...);}template<typename T1,typename T2>inline bool up(T1&x,const T2&y){return x<y?x=y,1:0;}template<typename T1,typename T2>inline bool dn(T1&x,const T2&y){return y<x?x=y,1:0;}template<typename T1,typename T2,typename T3>inline bool inRange(const T1&x,const T2&l,const T3&r){return!(x<l)&&!(r<x);}template<typename T1,typename T2>inline auto id1(const T1&x,const T2&y)->decltype(x<y?x:y){return x<y?x:y;}template<typename T1,typename T2>inline auto id0(const T1&x,const T2&y)->decltype(x<y?y:x){return x<y?y:x;}template<typename T1,typename T2,typename T3>inline T1&madd(T1&x,const T2&y,const T3&modulo){return x=(ll)(x+y+modulo)%modulo;}template<typename T1,typename T2,typename T3>inline T1&mmul(T1&x,const T2&y,const T3&modulo){return x=(ll)x*y%modulo;}inline int modadd(int x,int y,int modulo){return(x+=y)>=modulo?x-modulo:x;}inline int isinf(int x){return x<INF?x:-1;}inline void yesno(bool x){wtb(x?"Yes":"No");}


using namespace CPTH;

struct Modify
{
	int p, x;
};

struct Query
{
	int l, r, w, id;
};

struct Val
{
	int ans, pre, suf, sum;
};

signed main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	int n = read();
	
	vector<Modify> modify;
	
	For (i, 1, n) modify.pb({i, (int)read()});
	
	int k = read();
	
	vector<Query> query;
	
	For (i, 0, k - 1)
	{
		int l = read();
		int r = read();
		int w = read();
		query.pb({l, r, w, i});
	}
	
	SegmentTree<Val, int, true> seg
	(
		vector<Val>(n, {0, 0, 0, -n}),
		[n](const Val &x, const Val &y)
		{
			Val res;
			res.ans = max(x.suf + y.pre, max(x.ans, y.ans));
			res.pre = max(x.pre, x.sum + y.pre);
			res.suf = max(y.suf, x.suf + y.sum);
			res.sum = max(x.sum + y.sum, -n);
			return res;
		},
		[](SegmentTreeNode<Val, int> &node, int x)
		{
			if (x == INF) return;
			node.val.ans = node.val.pre = node.val.suf = max(0, x);
			node.val.sum = x;
		},
		1,
		{0, 0, 0, 0},
		INF
	);
	
	vi ans(k);
	
	function<void(vector<Modify> &, vector<Query> &, int, int)> solve = [&](vector<Modify> &ms, vector<Query> &qs, int l, int r)
	{
		if (qs.empty()) return;
		if (l == r - 1)
		{
			for (auto q : qs)
			{
				ans[q.id] = l;
			}
			return;
		}
		vector<Modify> lm, rm;
		int mid = (l + r) >> 1;
		for (auto m : ms)
		{
			if (m.x >= mid)
			{
				seg.modify(m.p, 1);
				rm.push_back(m);
			}
			else lm.push_back(m);
		}
		vector<Query> lq, rq;
		for (auto q : qs)
		{
			if (seg.query(q.l, q.r + 1).ans >= q.w) rq.push_back(q);
			else lq.push_back(q);
		}
		vector<Modify>().swap(ms);
		vector<Query>().swap(qs);
		solve(lm, lq, l, mid);
		for (auto m : rm) seg.modify(m.p, -n);
		solve(rm, rq, mid, r);
	};
	
	solve(modify, query, 1, 1000000001);
	
	for (auto x : ans) wtb(x);
	
	return 0;
}
