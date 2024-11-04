














































































































































































using namespace std;
 
using ll = long long;
using db = long double; 

using str = string; 




using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;








tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;



















tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }










const int MOD = 1e9+7; 

const int MX = 2e5+5;
const ll BIG = 1e18; 

const db PI = acos((db)-1);
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr int bits(int x) { 

	return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int id8(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } 

ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } 


tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } 

tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; } 


tcTU> T fstTrue(T lo, T hi, U f) {
	++hi; assert(lo <= hi); 

	while (lo < hi) { 

		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
	--lo; assert(lo <= hi); 

	while (lo < hi) { 

		T mid = lo+(hi-lo+1)/2;
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}
tcT> void remDup(vector<T>& v) { 

	sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { 

	auto it = t.find(u); assert(it != end(t));
	t.erase(it); } 




inline namespace Helpers {
	

	

	

	tcT, class = void> struct is_iterable : false_type {};
	tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
	                                  decltype(end(declval<T>()))
	                                 >
	                       > : true_type {};
	tcT> constexpr bool id13 = is_iterable<T>::value;

	

	tcT, class = void> struct is_readable : false_type {};
	tcT> struct is_readable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cin >> declval<T&>()), istream&>
	        >
	    > : true_type {};
	tcT> constexpr bool id2 = is_readable<T>::value;

	

	

	tcT, class = void> struct is_printable : false_type {};
	tcT> struct is_printable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cout << declval<T>()), ostream&>
	        >
	    > : true_type {};
	tcT> constexpr bool id5 = is_printable<T>::value;
}

inline namespace Input {
	tcT> constexpr bool id12 = !id2<T> && id13<T>;
	tcTUU> void re(T& t, U&... u);
	tcTU> void re(pair<T,U>& p); 


	

	tcT> typename enable_if<id2<T>,void>::type re(T& x) { cin >> x; } 

	tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

	tcT> typename enable_if<id12<T>,void>::type re(T& i); 

	tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
	tcT> typename enable_if<id12<T>,void>::type re(T& i) {
		each(x,i) re(x); }
	tcTUU> void re(T& t, U&... u) { re(t); re(u...); } 


	

	void rv(size_t) {}
	tcTUU> void rv(size_t N, V<T>& t, U&... u);
	template<class...U> void rv(size_t, size_t N2, U&... u);
	tcTUU> void rv(size_t N, V<T>& t, U&... u) {
		t.rsz(N); re(t);
		rv(N,u...); }
	template<class...U> void rv(size_t, size_t N2, U&... u) {
		rv(N2,u...); }

	

	void decrement() {} 

	tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
	
	
}

inline namespace ToString {
	tcT> constexpr bool id6 = !id5<T> && id13<T>;

	

	tcT> typename enable_if<id5<T>,str>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } 

	tcT> str bit_vec(T t) { 

		str res = "{"; id7(i,sz(t)) res += ts(t[i]);
		res += "}"; return res; }
	str ts(V<bool> v) { return bit_vec(v); }
	template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

	tcTU> str ts(pair<T,U> p); 

	tcT> typename enable_if<id6<T>,str>::type ts(T v); 

	tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	tcT> typename enable_if<id13<T>,str>::type ts_sep(T v, str sep) {
		

		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	tcT> typename enable_if<id6<T>,str>::type ts(T v) {
		return "{"+ts_sep(v,", ")+"}"; }

	

	template<int, class T> typename enable_if<!id6<T>,vs>::type 
	  id9(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<id6<T>,vs>::type 
	  id9(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vs res;
		for (const auto& t: v) {
			if (sz(res)) res.bk += ",";
			vs tmp = id9<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		id7(i,sz(res)) {
			str bef = " "; if (i == 0) bef = "{";
			res[i] = bef+res[i];
		}
		res.bk += "}";
		return res;
	}
}

inline namespace Output {
	template<class T> void pr_sep(ostream& os, str, const T& t) { os << ts(t); }
	template<class T, class... U> void pr_sep(ostream& os, str sep, const T& t, const U&... u) {
		pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }
	

	template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); } 
	

	void ps() { cout << "\n"; }
	template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); } 
	

	template<class ...T> void dbg_out(const T&... t) {
		pr_sep(cerr," | ",t...); cerr << endl; }
	void loc_info(int line, str names) {
		cerr << "Line(" << line << ") -> [" << names << "]: "; }
	template<int lev, class T> void id15(const T& t) {
		cerr << "\n\n" << ts_sep(id9<lev>(t),"\n") << "\n" << endl; }
	
		
		
	

		
		
	

	const clock_t beg = clock();
	
}

inline namespace FileIO {
	void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
	void setOut(str s) { freopen(s.c_str(),"w",stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0); 

		

		

		

		if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

	}
}
 
typedef long long ll;
typedef pair<int, int> pi;
 



 
const int INF = 1e9 + 1;
const int N = 202000;
 
const ll MOD1 = 998244391;
const ll M1 = 1e6 + 3;
int deg1[N];
 
vector<int> lcp(vector<int> &s, vector<int> &sa, vector<int> &pos)
{
    int n = s.size();
    vector<int> L(n);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (k > 0) k--;
        if (pos[i] == n - 1)
            L[n - 1] = -1, k = 0;
        else
        {
            int j = sa[pos[i] + 1];
            while (max(i + k, j + k) < n && s[i + k] == s[j + k])
                k++;
            L[pos[i]] = k;
        }
    }
    return L;
}
 
 
int H[N];
int sp[20][N];
 
int get(int l, int r)
{
    int j = H[r - l + 1];
    return min(sp[j][l], sp[j][r - (1 << j) + 1]);
}
 
void buildsa(vector<int> &s, vector<int> &sa, vector<int> &pos)
{
    map<int, int> mm;
    for (int i = 0; i < (int)s.size(); i++)
        mm[s[i]] = -1;
    int x = 0;
    for (int c = 0; c <= s.size(); c++)
    {
        if (mm.find(c) != mm.end())
            mm[c] = x++;
    }
    for (int i = 0; i < (int)s.size(); i++)
    {
        pos[i] = mm[s[i]];
    }
    vector<pair<pi, int> > p(s.size());
    for (int j = 1; (1 << j) <= 2 * (int)s.size(); j++)
    {
        for (int i = 0; i < (int)s.size(); i++)
        {
            p[i] = {{pos[i], pos[(i + (1 << j) / 2) % s.size()]}, i};
        }
        sort(p.begin(), p.end());
        int x = 0;
        pos[p[0].second] = x;
        for (int i = 1; i < (int)p.size(); i++)
        {
            if (p[i].first != p[i - 1].first) x++;
            pos[p[i].second] = x;
        }
    }
    for (int i = 0; i < (int)s.size(); i++)
    {
        sa[pos[i]] = i;
    }
}

vector<int> id11(vector<int> &s, vector<int> &sa, vector<int> &isa){
	int cur_best = MOD; 

	vi res(sz(s), MOD);

	set<array<int, 2>> id0; 

	set<array<int, 2>> id3; 


	for(int i = 0; i < sz(s); i++){
		dbg(i);
		if(cur_best == MOD || isa[i] < isa[cur_best]){
			

			id0.clear();
			id3.clear();
			cur_best = i;
			dbg("CLEARING");
		}
		else{
			int len_common = get(isa[cur_best], isa[i]-1);
			int pos_diff = i+len_common;
			id0.insert(array<int, 2>{pos_diff, i});
			id3.insert(array<int, 2>{i, pos_diff});
		}

		

		while(sz(id0)){
			array<int, 2> remove_top = (*id0.begin());
			if(remove_top[0] <= i){
				id0.erase(remove_top);
				id3.erase(array<int, 2>{remove_top[1], remove_top[0]});
			}
			else{
				break;
			}
		}

		

		if(sz(id3)){
			res[i] = (*prev(id3.end()))[0];
		}
		else{
			res[i] = cur_best;
		}
	}

	return res;
}
 
vector<int> msep(vector<int> &s, vector<int> &sa, vector<int> &pos)
{

    vector<int> res(s.size());
 
    int n = s.size();
    int ri = 0;
    int PI = INF;
 
    set<array<int, 3> > waitlist;
    set<array<int, 3> > id10;
 
    auto emplace = [&](int z) { 
        PI = min(PI, z);
        if (PI != INF && PI < z && get(PI, z - 1) >= ri - sa[z])
        {
            waitlist.insert({sa[z] + get(PI, z - 1), z, sa[z]});
            id10.insert({-sa[z], sa[z] + get(PI, z - 1), z});
        }
    };
 
    while (ri < n)
    {
        ri++;
        while (waitlist.size())
        {
            array<int, 3> it = *waitlist.begin();
            int z = it[1];
            if (it[0] >= ri) break;
            waitlist.erase(it);
            id10.erase({-it[2], it[0], it[1]});
        }
        emplace(pos[ri - 1]);
 
        if (id10.size())
        {
            res[ri - 1] = -(*id10.begin())[0];
        }
        else
        {
            res[ri - 1] = sa[PI];
        }
    }
    dbg(s);
    dbg(sa);
    dbg(pos);
    dbg(res);

    vi my_res = id11(s, sa, pos);
    dbg(my_res);
    if(res != my_res){
    	ps("ERROR");
    	exit(0);
    }
    return my_res;
}
 
double id4 = 0;
 
vector<int> fast_op(vector<int> s)
{
    double st = clock();
 
    s.push_back(0);
    vector<int> sa(s.size());
    vector<int> pos(s.size());
    buildsa(s, sa, pos);
    vector<int> L = lcp(s, sa, pos);
 
    for (int i = 0; i < (int)s.size(); i++) sp[0][i] = L[i];
    for (int j = 0; j < 20; j++)
        for (int i = 0; i + (1 << j) - 1 < (int)s.size(); i++)
            sp[j][i] = get(i, i + (1 << j) - 1);
 
    s.pop_back();
 
    auto cmp = [&](int l1, int l2, int len)
    {
        if (get(min(pos[l1], pos[l2]), max(pos[l1], pos[l2]) - 1) >= len)
            return 1;
        return 0;
    };
 
    vector<int> id1 = msep(s, sa, pos);
    vector<int> id14(s.size());
    for (int i = 0; i < s.size(); i++)
    {
        int len = i + 1 - id1[i];
        id14[i] = id1[i];
        int j = 0;
        for (j = 0; j < 20; j++)
        {
            ll nc = id14[i] - (1ll << j) * len;
            if (nc >= 0 && cmp(nc, id14[i], (1ll << j) * len))
                id14[i] = nc;
            else
                break;
        }
        for (; j >= 0; j--)
        {
            ll nc = id14[i] - (1ll << j) * len;
            if (nc >= 0 && cmp(nc, id14[i], (1ll << j) * len))
                id14[i] = nc;
        }
    }
 
    id4 += 1.0 * (clock() - st) / CLOCKS_PER_SEC;
 
    deque<pair<int, int> > h;
 
    struct SegTree{
        struct Node
        {
            int l, r;
            ll len;
            ll h1;
        };
 
        vector<Node> tree;
        vector<Node> hashes;
        int pnt;
 
        SegTree(vector<int> s)
        {
            tree.resize(4 * s.size());
            hashes.resize(s.size());
            hashes[0].h1 = s[0];
            for (int i = 1; i < s.size(); i++)
            {
                hashes[i].h1 = (hashes[i - 1].h1 * M1 + s[i]) % MOD1;
            }
            pnt = s.size();
        }
        Node Get(int l, int r)
        {
            Node res;
            res.l = l;
            res.r = r;
            res.len = r - l + 1;
            res.h1 = (hashes[r].h1 - (l ? hashes[l - 1].h1 : 0) * deg1[r - l + 1]) % MOD1;
            res.h1 = (res.h1 + MOD1) % MOD1;
            return res;
        }
        Node Merge(Node L, Node R)
        {
            if (L.len + R.len < N) L.h1 = (L.h1 * deg1[R.len] + R.h1) % MOD1;
            L.len += R.len;
            return L;
        }
        void Set(int pos, Node X, int L, int R, int V)
        {
            if (L + 1 == R)
            {
                tree[V] = X;
                return;
            }
            int M = (L + R) / 2;
            if (pos < M) Set(pos, X, L, M, 2 * V + 1);
            else Set(pos, X, M, R, 2 * V + 2);
            tree[V] = Merge(tree[2 * V + 1], tree[2 * V + 2]);
        }
        void push_front(int l, int r)
        {
            pnt--;
            Set(pnt, Get(l, r), 0, tree.size() / 4, 0);
        }
        Node Get(int chars, int L, int R, int V)
        {
            if (L + 1 == R)
            {
                return Get(tree[V].l, tree[V].l + chars - 1);
            }
            int M = (L + R) / 2;
            if (tree[2 * V + 1].len >= chars)
                return Get(chars, L, M, 2 * V + 1);
            return Merge(tree[2 * V + 1], Get(chars - tree[2 * V + 1].len, M, R, 2 * V + 2));
        }
        Node Get(int chars)
        {
            return Get(chars, 0, tree.size() / 4, 0);
        }
    };
 
    SegTree TT(s);
    for (int i = 1; i <= s.size(); i++)
    {
        int pos1 = id1[s.size() - i];
        int pos2 = id14[s.size() - i];
        int len = s.size() - i + 1 - pos1;
 
        if (pos1 == pos2)
        {
            int LL = id1[s.size() - i];
            int RR = min((int)s.size() - i, id1[s.size() - i] + i - 1);
            h.push_front({LL, RR});
            TT.push_front(LL, RR);
            continue;
        }
        int t2 = -1;
        int aval = s.size() - i + 1 - pos2 - len;
 
        aval = min(aval, i);
        if (TT.Get(aval).h1 != TT.Get(pos2 + len, pos2 + len + aval - 1).h1)
            t2 = 1;
 
        int shL = aval, shR = i;
        while (t2 == -1 && shL + 1 < shR)
        {
            int sh = (shL + shR) / 2;
            int x1 = TT.Get(sh).h1;
            int x2 = TT.Merge(TT.Get(pos2 + len, s.size() - i), TT.Get(sh - aval)).h1;
            if (x1 != x2)
                shR = sh;
            else
                shL = sh;
        }
 
        if (t2 == -1 && shR < i)
        {
            int x1 = TT.Get(shR).h1;
            int x2 = TT.Merge(TT.Get(pos2 + len, s.size() - i), TT.Get(shR - aval)).h1;
            if (x1 != x2)
            {
                if ((x1 - x2 + MOD1) % MOD1 < MOD1 / 2)
                {
                    t2 = 2;
                }
                else
                {
                    t2 = 1;
                }
            }
        }
 
        if (t2 == 1)
        {
            int LL = id1[s.size() - i];
            int RR = min((int)s.size() - i, id1[s.size() - i] + i - 1);
            h.push_front({LL, RR});
            TT.push_front(LL, RR);
        }
        else
        {
            int LL = id14[s.size() - i];
            int RR = min((int)s.size() - i, id14[s.size() - i] + i - 1);
            h.push_front({LL, RR});
            TT.push_front(LL, RR);
        }
    }
    vector<int> s2;
    for (int j = 0; j < h.size(); j++)
    {
        for (int k = h[j].l; k <= h[j].r; k++)
        {
            s2.push_back(s[k]);
            if (s2.size() == s.size())
                break;
        }
        if (s2.size() == s.size())
            break;
    }
    return s2;
}
 
vector<int> op(vector<int> s)
{
    for (int i = 1; i < s.size(); i++)
    {
        vector<int> h = {INF};
        for (int j = 0; j + i <= s.size(); j++)
        {
            vector<int> t;
            for (int k = 0; k < i; k++)
                t.push_back(s[j + k]);
            h = min(h, t);
        }
        for (int j = 0; j < i; j++)
        {
            s[s.size() - i + j] = h[j];
        }
    }
    return s;
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    deg1[0] = 1;
    for (int i = 1; i < N; i++)
        deg1[i] = deg1[i - 1] * M1 % MOD1;
    for (int i = 3; i < N; i++)
        H[i] = (((i - 1) & (i - 2)) == 0) + H[i - 1];
 
    int n;
    cin >> n;
    vector<vector<int> > b(7, vector<int>(n));
    for (int i = 0; i < n; i++) cin >> b[0][i];
    

    

    

    

    

    

    for (int i = 1; i < 6; i++) b[i] = fast_op(b[i - 1]);
    int pos = 0;
    while (pos + 1 < n && b[0][pos + 1] <= b[0][pos]) pos++;
    for (int i = 0; i < pos; i++) b[6][i] = b[0][i];
    for (int i = pos; i < n; i++) b[6][i] = b[0][pos];
    int q;
    cin >> q;
    while (q--)
    {
        int i, j;
        cin >> i >> j;
        j--;
        i = min(i, 6);
        cout << b[i][j] << "\n";
    }
    return 0;
 
}