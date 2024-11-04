

using namespace std;
typedef long long ll;
const int INF = 1e8 + 7;
const int MOD = 1e9 + 7;

template<int N, int MOD>
struct InvRec{
    int inv[N+7];
    InvRec(){
        inv[1] = 1;
        for(int i = 2; i <= N; i ++){
            inv[i] = (MOD - MOD / i) * 1ll * inv[MOD % i] % MOD;
        }
    }
    int get(int i){ return inv[i]; }
};

template <typename T, int TypeOp, int TypeSet>
class SegmentTree {
public:
    using ll = long long;
    ll retval = 0;
    T id0 = 0;
    std::vector<T> lazy;
    std::vector<T> tree;
    int levels,n, el;
    T (*f)(T,T);
    void (SegmentTree::*UpdFun)(int, int, int, T);
    void (SegmentTree::*id1)(int, int, int);
    

    

    


public:
    static T minval(T a, T b){ return a < b ? a : b; }
    static T maxval(T a, T b){ return a > b ? a : b; }
    static T addval(T a, T b){ return a + b; }
    inline void UpdForSumAdd(int l, int r, int rt, T c){
        lazy[rt] += c;
        tree[rt] += c * (r-l+1);
    }
    inline void UpdForSumEq(int l, int r, int rt, T c){
        lazy[rt] = c;
        tree[rt] = c * (r-l+1);
    }

    inline void UpdForMostValAdd(int l, int r, int rt, T c){
        lazy[rt] += c;
        tree[rt] += c;
    }
    inline void UpdForMostValEq(int l, int r, int rt, T c){
        lazy[rt] = f(lazy[rt], c);
        tree[rt] = f(tree[rt], c);
    }
    inline void PushDownForSumAdd(int l, int r, int rt){
        if(lazy[rt] != id0){
            int x = r - l + 1;
            lazy[rt<<1] += lazy[rt];
            tree[rt<<1] += lazy[rt] * (x - (x>>1));
            lazy[rt<<1|1] += lazy[rt];
            tree[rt<<1|1] += lazy[rt] * (x>>1);
            lazy[rt] = id0;
        }
    }
    inline void PushDownForSumEq(int l, int r, int rt){
        if(lazy[rt] != id0){
            int x = r - l + 1;
            lazy[rt<<1] = lazy[rt];
            tree[rt<<1] = lazy[rt] * (x - (x>>1));
            lazy[rt<<1|1] = lazy[rt];
            tree[rt<<1|1] = lazy[rt] * (x>>1);
            lazy[rt] = id0;
        }
    }
    inline void PushDownForMostValAdd(int l, int r, int rt){
        if(lazy[rt] != id0){
            lazy[rt<<1] += lazy[rt];
            tree[rt<<1] += lazy[rt];
            lazy[rt<<1|1] += lazy[rt];
            tree[rt<<1|1] += lazy[rt];
            lazy[rt] = id0;
        }
    }
    inline void PushDownForMostValEq(int l, int r, int rt){
        if(lazy[rt] != id0){
            lazy[rt<<1] = lazy[rt];
            tree[rt<<1] = f(lazy[rt<<1], tree[rt<<1]);
            lazy[rt<<1|1] = lazy[rt];
            tree[rt<<1|1] = f(lazy[rt<<1|1], tree[rt<<1|1]);
            lazy[rt] = id0;
        }
    }
    void InitFunc(int n){
        using namespace std::placeholders;
        if(TypeOp == 0 || TypeOp == 1){
            if(TypeSet == 0) {
                this->UpdFun = &SegmentTree::UpdForMostValAdd;
                this->id1 = &SegmentTree::PushDownForMostValAdd;




            }else{
                this->UpdFun = &SegmentTree::UpdForMostValEq;
                this->id1 = &SegmentTree::PushDownForMostValEq;




            }

            if(std::is_same<int, T>::value) retval = (ll)2e9;
            else if(std::is_same<ll, T>::value) retval = (ll)4e18;
            if(TypeOp == 1) retval *= -1;
            if(TypeOp == 0) this->f = &SegmentTree::minval;
            else this->f = &SegmentTree::maxval;

        }else if(TypeOp == 2){
            this->f = &SegmentTree::addval;
            if(TypeSet == 0) {
                this->UpdFun = &SegmentTree::UpdForSumAdd;
                this->id1 = &SegmentTree::PushDownForSumAdd;




            }else {
                this->UpdFun = &SegmentTree::UpdForSumEq;
                this->id1 = &SegmentTree::PushDownForSumEq;




            }
            retval = 0;
        }
        tree.assign(n<<2, T());
        lazy.assign(n<<2, T());
        this->n = n;
    }
public:

    SegmentTree(int n, T val = T()) {
        InitFunc(n);
        std::vector<T> vd;
        vd.reserve(n);
        for(int i = 0; i < this->n; ++ i){
            vd.push_back(val);
        }
        build(1, this->n, 1, vd);
    }
    SegmentTree(int n, T* data){
        InitFunc(n);
        std::vector<T> vd;
        vd.reserve(n);
        for(int i = 0; i < this->n; ++ i){
            vd.push_back(data[i]);
        }
        build(1, this->n, 1, vd);
    }
    SegmentTree(const std::vector<T>& data)  {
        InitFunc(data.size());
        build(1, this->n, 1, data);
    }
    void build(int l, int r, int rt, const std::vector<T>& data){
        lazy[rt] = id0;
        if(l == r){
            tree[rt] = data[l-1];
            return ;
        }
        int mid = l + r >> 1;
        build(l, mid, rt<<1, data);
        build(mid+1, r, rt<<1|1, data);
        PushUp(rt);
    }

    inline void PushUp(int rt){
        tree[rt] = f(tree[rt<<1], tree[rt<<1|1]);
    }

    inline void update(int L, int R, T c){
        update(L, R, c, 1, n, 1);
    }

    void update(int L, int R, T c, int l, int r, int rt){
        if(L <= l && r <= R){
            (this->*UpdFun)(l, r, rt, c);
            return ;
        }
        (this->*id1)(l, r, rt);
        int mid = l + r >> 1;
        if(L <= mid) update(L, R, c, l, mid, rt<<1);
        if(R > mid) update(L, R, c, mid+1, r, rt<<1|1);
        PushUp(rt);
    }
    inline T query(int L, int R){
        return query(L, R, 1, n, 1);
    }
    inline T query(int L, int R, int l, int r, int rt){
        if(L <= l && r <= R){
            return tree[rt];
        }
        (this->*id1)(l, r, rt);
        int mid = (l+r) >> 1;
        T res = (T)retval;
        if(L <= mid) res = f(res, query(L, R, l, mid, rt << 1));
        if(mid < R) res = f(res, query(L, R, mid+1, r, rt << 1|1));
        PushUp(rt);
        return res;
    }

    int find_first_ltc(int L, int R, T c);
    int find_last_ltc(int L, int R, T c){ return find_last_ltc(L, R, c, 1, this->n, 1); } 

    int find_first_gtc(int L, int R, T c);
    int find_last_gtc(int L, int R, T c);

    int find_last_ltc(int L, int R, T c, int l, int r, int rt) {
        if(l == r){ 

            return l;
        }
        (this->*id1)(l, r, rt);
        int mid = l + r >> 1;
        if(mid < R && tree[rt<<1|1] <= c){
            int res = find_last_ltc(L, R, c, mid+1, r, rt<<1|1);
            if(res != -1) return res;
        }
        if(L <= mid && tree[rt<<1] <= c){
            int res = find_last_ltc(L, R, c, l, mid, rt<<1);
            if(res != -1) return res;
        }
        return -1;
    }
    

    

    

    


    

};

template <int N, typename T, int TypeOp, int TypeSet>
class id2{
public:
    id2():segmentTree(N+7){
        cnt = 0;
        if(TypeOp == 0) this->op_fun = &id2::minval;
        if(TypeOp == 1) this->op_fun = &id2::maxval;
        if(TypeOp == 2) this->op_fun = &id2::addval;

        if(std::is_same<int, T>::value) retval = (ll)2e9;
        if(std::is_same<ll, T>::value) retval = (ll)4e18;
        if(TypeOp == 1) retval *= -1;
        if(TypeOp == 2) retval = 0;
    }

    static T minval(T a, T b){ return a < b ? a : b; }
    static T maxval(T a, T b){ return a > b ? a : b; }
    static T addval(T a, T b){ return a + b; }

    T retval;
    T (*op_fun)(T,T);
    SegmentTree<T, TypeOp, TypeSet> segmentTree;
    int sz[N+7]; 

    int fa[N+7]; 

    int dep[N+7];

    int son[N+7];


    int cnt = 0;
    int pos[N+7]; 

    int tp[N+7];  


    vector<int> g[N+7];

    void dfs1(int u,int pre,int depth){
        sz[u] = 1;
        fa[u] = pre;
        dep[u] = depth;
        son[u] = 0;
        for(int v : g[u]) if(v != pre){
            dfs1(v , u, depth+1);
            sz[u] += sz[v];
            if(sz[son[u]] < sz[v]) son[u] = v;
        }
    }
    void dfs2(int u,int tpo){
        tp[u] = tpo;
        pos[u] = ++ cnt;
        if(son[u]){ 

            dfs2(son[u],tp[u]);
        }
        for(int v : g[u]) if(v != fa[u] && v != son[u]){
            dfs2(v,v); 

        }
    }
    void add_edge(int u, int v){
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void deal(){
        dfs1(1, 1, 1);
        dfs2(1, 1);
        

    }
    T query(int u, int v){
        T ans = retval;
        while(tp[u] != tp[v]){
            if(dep[tp[u]] < dep[tp[v]]) {
                swap(u,v);
            }
            ans = op_fun(ans, segmentTree.query(pos[tp[u]],pos[u]));
            u = fa[tp[u]];
        }
        if(dep[u] < dep[v]) {
            swap(u,v);
        }
        ans = op_fun(ans, segmentTree.query(pos[v],pos[u]));
        return ans;
    }
    void update(int u, int v, T c){
        while(tp[u] != tp[v]){
            if(dep[tp[u]] < dep[tp[v]]){
                swap(u,v);
            }
            segmentTree.update(pos[tp[u]],pos[u],c);
            u = fa[tp[u]];
        }
        if(dep[u] > dep[v]){
            swap(u,v);
        }
        segmentTree.update(pos[u],pos[v],c);
    }
    


    

    

    

    


    

};






const int N = 1e5 + 7;
ll l[N], r[N], w[N], n;
id2<N, ll, 2, 0> tree_seg;
InvRec<N, MOD> inv;

int main(){
    IOS
    cin >> n;
    std::map<int, vector<pair<int, int>>> event;
    for(int i = 1; i <= n; ++ i){
        cin >> l[i] >> r[i];
        w[i] = inv.get((int)(r[i]-l[i]+1));
        event[l[i]].push_back(std::make_pair(1, i));
        event[r[i]+1].push_back(std::make_pair(-1, i));
    }
    for(int i = 1, u, v; i < n; ++ i){
        cin >> u >> v;
        tree_seg.add_edge(u, v);
    }
    tree_seg.deal();
    ll s1 = 0, s2 = 0, s3 = 0;
    ll cur = 0, ans = 0, last = -1;
    for(auto event_pi : event){
        if(last != -1){
            ll d = event_pi.first - last;
            ll add = ((s1 * s2 % MOD - s3 - 2 * cur) % MOD + MOD) % MOD;
            ans = (ans + d * add % MOD) % MOD;
        }
        last = event_pi.first;
        for(auto pi : event_pi.second){
            int inout = pi.first;
            int index = pi.second;
            ll dep = tree_seg.dep[index];
            if(inout == 1){
                s1 = (s1 + dep * w[index]) % MOD;
                s2 = (s2 + w[index]) % MOD;
                s3 = (s3 + dep * w[index] % MOD * w[index] % MOD) % MOD;
                cur = (cur + (w[index] * (tree_seg.query(index, 1) % MOD) % MOD)) % MOD;
                tree_seg.update(index, 1, w[index]);
            }
            if(inout == -1){
                s1 = ((s1 - dep * w[index]) % MOD + MOD) % MOD;
                s2 = ((s2 - w[index]) % MOD + MOD) % MOD;
                s3 = ((s3 - dep * w[index] % MOD * w[index] % MOD) % MOD + MOD) % MOD;
                tree_seg.update(index, 1, - w[index]);
                cur = ((cur - w[index] * (tree_seg.query(index, 1) % MOD) % MOD) % MOD + MOD) % MOD;
            }
        }
    }
    ll ret = 1;
    for(int i = 1; i <= n; ++ i){
        ret = ret * (r[i] - l[i] + 1) % MOD;
    }
    cout << ret * ans % MOD << endl;


    return 0;
}