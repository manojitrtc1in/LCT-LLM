
using namespace std;






typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<string> vs;
template<typename T> vector<T> table(int n, T val){ return vector<T>(n, val); }
template<typename... Args> auto table(int n, Args... args){ auto val = table(args...); return vector<decltype(val)>(n, move(val)); }
template<typename... Args> using umap = unordered_map<Args...>;
template<typename... Args> using uset = unordered_set<Args...>;
typedef umap<ll,ll> umapl;








template<class T> bool mmin(T& a, const T& b) { return b<a?a=b,1:0; }
template<class T> bool mmax(T& a, const T& b) { return a<b?a=b,1:0; }
void put() {}
template<class T, class... Args> void put(T a, Args... args) { cout << a; if(sizeof...(args)) cout << ' '; put(args...); }
template<class... Args> void putn(Args... args) { put(args...); cout << endl; }
template<class... Args> void putb(Args... args) { put(args...); cout << ' '; }
template<class It> void put_each(It first, It last) { while(first!=last) { put(*first); if(++first!=last) putb(); } }
template<class It> void id2(It first, It last) { put_each(first,last); putn(); }
template<class It> void id0(It first, It last) { put_each(first,last); putb(); }
void yesno(bool c) { putn(c?"Yes":"No"); }
void yes() { yesno(true); } void no() { yesno(false); }
void imp() { putn("-1"); }
const int inf = 0x3f3f3f3f;
const ll infl = 0x3f3f3f3f3f3f3f3f;











template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct cartesian {

    cartesian() : root(NULL) {};
    template<class T> cartesian(const vector<T>& v) : root(build(v,0,v.size())) {}
    template<class T> cartesian(const T val) : root(new item(val)) {}
    ~cartesian() { if(root) delete root; }

    cartesian(cartesian& rhs) : root(reprio_copy(rhs.root)) {}
    cartesian(cartesian&& rhs) : root(NULL) { *this = move(rhs); }

    void operator=(cartesian& rhs) { *this = cartesian(rhs); }
    void operator=(cartesian&& rhs) { if(root) delete root; root = rhs.root; rhs.root = NULL; }

    void append(cartesian& rhs) { append(cartesian(rhs)); }
    void append(cartesian&& rhs) { root = merge(root,rhs.root); rhs.root = NULL; }
    void prepend(cartesian& rhs) { prepend(cartesian(rhs)); }
    void prepend(cartesian&& rhs) { root = merge(rhs.root,root); rhs.root = NULL; }

    cartesian& operator+=(cartesian& rhs) { return *this += cartesian(rhs); }
    cartesian& operator+=(cartesian&& rhs) { append(move(rhs)); return *this; }

    

    friend cartesian operator+(cartesian&& lhs, cartesian&& rhs) { 
        cartesian ans(move(lhs)); 
        ans.append(move(rhs)); 
        return ans; 
    } 
    

    friend cartesian operator+(cartesian& lhs, cartesian& rhs) { return cartesian(lhs) + cartesian(rhs); }
    friend cartesian operator+(cartesian& lhs, cartesian&& rhs) { return cartesian(lhs) + move(rhs); }
    friend cartesian operator+(cartesian&& lhs, cartesian& rhs) { return move(lhs) + cartesian(rhs); }

    

    cartesian cut(int l, int r) {
        assert(0<=l && l<=r && r<=size());
        cartesian ans,rhs;
        split(root,l,root,ans.root);
        split(ans.root,r-l,ans.root,rhs.root);
        append(move(rhs));
        return ans; 
    }

    

    cartesian cut_prefix(int len) { 
        cartesian ans;
        split(root,len,ans.root,root);
        return ans;
    }

    

    cartesian cut_suffix(int len) { 
        cartesian ans;
        split(root,size()-len,root,ans.root);
        return ans;
    }

    

    S& get(int i) {
        assert(0<=i && i<size());
        return get(root,i);
    }

    

    

    int lower_bound(const S& val) { return lower_bound(root,val); }
    int upper_bound(const S& val) { return upper_bound(root,val); }
    int count(const S& val) { return upper_bound(root,val) - lower_bound(root,val); }
    void insert(S val) { insert(lower_bound(root,val),val); }

    

    void insert(int i, cartesian& t) { insert(i,cartesian(t)); }
    void insert(int i, cartesian&& t) {
        insert(root,i,t.root);
        t.root = NULL;
    }

    

    void erase(int i) { 
        assert(0<=i && i<size());
        erase(root,i);
    }

    S query(int l, int r) {
        assert(0<=l && l<=r && r<=size());
        return query(root,l,r,0,size());
    }

    void lazy_update(int l, int r, F f) {
        assert(0<=l && l<=r && r<=size());
        lazy_update(root,l,r,0,size(),f);        
    }

    int size() { return size(root); }
    bool empty() { return size()==0; }

    vector<S> to_vector() {
        vector<S> ans;
        traverse_in_order(ans,root);
        return ans;
    }

  private:
    struct item {
        S val, range_val;
        F lz;
        long long prio;
        int size;
        item *l, *r;
        item(S val) : val(val), range_val(val), lz(id()), prio(dist(g)), size(1), l(NULL), r(NULL) {};
        ~item() {
            if(l) delete l;
            if(r) delete r;
        }
    };
    using pitem = item*;

    pitem reprio_copy(pitem t) {
        if(!t) return NULL;
        pitem ans = new item(*t);
        ans->prio = dist(g);
        ans->l = reprio_copy(t->l);
        ans->r = reprio_copy(t->r);
        return ans;
    }

    pitem merge(pitem l, pitem r) {
        if(!l || !r) return l ? l : r;
        push(l);
        push(r);
        pitem ans;
        if(l->prio > r->prio) {
            l->r = merge(l->r,r);
            ans = l;
        } else {
            r->l = merge(l,r->l);
            ans = r;
        }
        pull(ans);
        return ans;
    }

    void split(pitem t, int len, pitem& l, pitem& r) {
        if(!t) return void(l = r = NULL);
        push(t);
        if(size(t->l) <= len - 1) 
            split(t->r, len - size(t->l) - 1, t->r, r), l = t;
        else
            split(t->l, len, l, t->l), r = t;
        pull(t);
    }

    void insert(pitem& t, int i, pitem it) {
        if(!t) return void(t = it);
        push(t);
        if (it->prio > t->prio)
            split(t, i, it->l, it->r),  t = it;
        else if(size(t->l) <= i - 1)
            insert(t->r, i - size(t->l) - 1, it);
        else 
            insert(t->l, i, it);
        pull(t);
    }

    void erase(pitem& t, int i) {
        push(t);
        if(size(t->l)==i) {
            pitem buf = t;
            t = merge(t->l, t->r);
            buf->l = buf->r = NULL;
            delete buf;
        } else if(i < size(t->l)) erase(t->l,i); 
        else erase(t->r,i-size(t->l)-1);
        pull(t);
    }

    void heapify(pitem t) {
        if(!t) return;
        pitem mx = t;
        if(t->l != NULL && t->l->prio > mx->prio)
            mx = t->l;
        if(t->r != NULL && t->r->prio > mx->prio)
            mx = t->r;
        if(mx != t) {
            swap(t->prio, mx->prio);
            heapify(mx);
        }
    }

    

    template<class T> pitem build(const vector<T>& a, int l, int r) {
        if(l==r) return NULL;
        int mid = (l + r) / 2;
        pitem t = new item(a[mid]);
        t->l = build(a, l, mid);
        t->r = build(a, mid + 1, r);
        heapify(t);
        pull(t);
        return t;
    }

    S& get(pitem t, int i) {
        if(size(t->l)==i) return t->val;
        else if(i < size(t->l)) return get(t->l, i);
        else return get(t->r, i-size(t->l)-1);
    }

    int lower_bound(pitem t, const S& val) {
        if(!t) return 0;
        else if(val <= t->val) return lower_bound(t->l,val);
        else return lower_bound(t->r,val) + size(t->l) + 1;
    }

    int upper_bound(pitem t, const S& val) {
        if(!t) return 0;
        else if(val < t->val) return upper_bound(t->l,val);
        else return upper_bound(t->r,val) + size(t->l) + 1;
    }

    int size(pitem t) { return t ? t->size : 0; }
    
    S range_val(pitem t) { return t ? t->range_val : e(); }

    void pull(pitem t) { 
        if(t) {
            t->size = 1 + size(t->l) + size(t->r); 
            t->range_val = op(op(range_val(t->l),t->val),range_val(t->r));
        }
    }

    S query(pitem t, int l, int r, int u, int v) {
        if(v<=l || r<=u) return e();
        if(l<=u && v<=r) return range_val(t);
        push(t);
        int i = u + size(t->l);
        S ans = query(t->l, l, r, u, i);
        if(l<=i && i<r) ans = op(ans,t->val);
        ans = op(ans,query(t->r, l, r, i+1, v));
        return ans;
    }

    void lazy_update(pitem t, int l, int r, int u, int v, F f) {
        if(u==v || v<=l || r<=u) return;
        if(l<=u && v<=r) return lazy_apply(t,f);
        push(t);
        int i = u + size(t->l);
        lazy_update(t->l, l, r, u, i, f);
        if(l<=i && i<r) t->val = mapping(f,t->val);
        lazy_update(t->r, l, r, i+1, v, f);
        pull(t);
    }

    void lazy_apply(pitem t, F f) {
        t->val = mapping(f, t->val);
        t->range_val = mapping(f, t->range_val);
        t->lz = composition(f,t->lz);
    }

    void push(pitem t) {
        if(t) {
            if(t->l) lazy_apply(t->l,t->lz);
            if(t->r) lazy_apply(t->r,t->lz);
            t->lz = id();
        }
    }

    void traverse_in_order(vector<S>& v, pitem t) {
        if(t) {
            traverse_in_order(v,t->l);
            v.push_back(t->val);
            traverse_in_order(v,t->r);
        }
    }

    item *root;
    static mt19937 g;
    static uniform_int_distribution<long long> dist;
};
template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)()> mt19937 cartesian<S,op,e,F,mapping,composition,id>::g(std::chrono::high_resolution_clock::now().time_since_epoch().count());
template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)()> uniform_int_distribution<long long> cartesian<S,op,e,F,mapping,composition,id>::dist;
template<class Q> using cart = cartesian<typename Q::node,Q::op,Q::e,typename Q::lz,Q::mapping,Q::composition,Q::id>;



template<class S, class T = decltype(S::val)> 
vector<T> id1(const vector<S>& v) {
    vector<T> ans;
    transform(v.begin(),v.end(),back_inserter(ans),[](const S& a) -> T { return a.val; });
    return ans;
}



template<class T>
struct no_op {
    struct node {
        T val;
        node() : node(T(0)) {}
        node(T val) : val(val) {}
        friend operator<=(const node& lhs, const node& rhs) { return lhs.val <= rhs.val; }
        friend operator<(const node& lhs, const node& rhs) { return lhs.val < rhs.val; }
    };
    struct lz {};
    static node e() { return node(T(0)); }
    static node op(node lhs, node rhs) { return e(); }
    static lz id() { return lz(); }
    static lz composition(lz lhs, lz rhs) { return id(); }
    static node mapping(lz l, node n) { return n; }
};
using cartll = cart<no_op<long long>>;





struct max_set {
    struct node {
        int i;
        ll val;
        node() : node(0,-infl) {}
        node(int i, ll val) : i(i), val(val) {}
        friend operator<=(const node& lhs, const node& rhs) { return lhs.i <= rhs.i; }
        friend operator<(const node& lhs, const node& rhs) { return lhs.i < rhs.i; }
    };
    struct lz {};
    static node op(node lhs, node rhs) { return node(lhs.val > rhs.val ? lhs.i : rhs.i, max(lhs.val,rhs.val)); }
    static node e() { return node(); }
    static lz id() { return lz(); }
    static lz composition(lz newlz, lz oldlz) { return id(); }
    static node mapping(lz l, node n) { return n; }
};




void solve() {
    int n,m; cin >> n >> m;
    auto dp = table(n+1,2,-1);

    vector<int> len(2);
    vector<cart<max_set>> mp(2);


    forn(ii,2) mp[ii].insert({0,0});

    fora(i,1,n) {
        int k; cin >> k;
        vector<int> a(2), b(2);
        cin >> a[0] >> b[0] >> a[1] >> b[1];

        vi ok(2);
        forn(ii,2) {
            if(a[ii] <= k && k <= b[ii]) len[ii]++;
            else len[ii] = 0;







            mp[!ii].cut_prefix(mp[!ii].lower_bound({a[!ii],-infl}));





            mp[!ii].cut_suffix(mp[!ii].size() - mp[!ii].lower_bound({b[!ii]+1,+infl}));












            if(mp[!ii].empty()) continue;

            int it = mp[!ii].query(0,mp[!ii].size()).val;


            if(it>=i-len[ii]) {
                dp[i][ii] = it;
                ok[ii] = 1;
            }
        }

        forn(ii,2) {
            if(ok[ii]) {
                mp[ii].insert({k,i});
            }
        }
    }

    if(dp[n][0]>-1 || dp[n][1]>-1) {
        yes();
        int par = dp[n][0]>-1 ? 0 : 1;
        int i = n, j = n;
        vi pos;
        while(j>=1) {
            if(j==dp[i][par]) {
                i = dp[i][par];
                par ^= 1;
            }
            pos.push_back(par);
            j--;
        }
        reverse(all(pos));
        id2(all(pos));


    } else no();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1; 

    while(tc--) solve();

    return 0;
}
