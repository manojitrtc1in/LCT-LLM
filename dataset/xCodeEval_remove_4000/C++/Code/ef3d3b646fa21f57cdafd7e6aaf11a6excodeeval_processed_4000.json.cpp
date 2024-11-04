



















using namespace std;

template<typename S,typename T>auto&operator<<(ostream&o,pair<S,T>p){return o<<"{"<<p.fi<<","<<p.se<<"}";}
template<typename T>auto&operator<<(ostream&o,set<T>s){for(auto&e:s)o<<e<<" ";return o;}
template<typename S,typename T,typename U>
auto&operator<<(ostream&o,priority_queue<S,T,U>q){while(!q.empty())o<<q.top()<<" ",q.pop();return o;}
template<typename K,typename T>auto&operator<<(ostream&o,map<K,T>&m){for(auto&e:m)o<<e<<" ";return o;}
template<typename T>auto&operator<<(ostream&o,vector<T>v){for(auto&e:v)o<<e<<" ";return o;}
void ashow(){cout<<endl;}template<typename T,typename...A>void ashow(T t,A...a){cout<<t<<" ";ashow(a...);}
template<typename S,typename T,typename U>
struct TRI{S fi;T se;U th;TRI(){}TRI(S f,T s,U t):fi(f),se(s),th(t){}
bool operator<(const TRI&_)const{return(fi==_.fi)?((se==_.se)?(th<_.th):(se<_.se)):(fi<_.fi);}};
template<typename S,typename T,typename U>
auto&operator<<(ostream&o,TRI<S,T,U>&t){return o<<"{"<<t.fi<<","<<t.se<<","<<t.th<<"}";}

typedef pair<int, int> P;
typedef pair<ll, ll> pll;
typedef TRI<int, int, int> tri;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<P> vp;
typedef vector<double> vd;
typedef vector<string> vs;

const int MAX_N = 100005;

template<typename _Tp> class BSTNode {
public:
    int from, to, sz;
    _Tp value, al, lazy;
    BSTNode *left, *right, *par;
    BSTNode(const int _from, const int _to) noexcept
        : from(_from), to(_to), sz(0), value(id1), al(id2), lazy(id1),
            left(nullptr), right(nullptr), par(nullptr){}
    BSTNode(const int _from, const int _to, const _Tp& _value) noexcept
        : from(_from), to(_to), sz(1), value(_value), al(value), lazy(id1),
            left(nullptr), right(nullptr), par(nullptr){}
    static const _Tp id1 = (_Tp)0;
    static const _Tp id2 = (_Tp)0;
    static void opr1(_Tp& arg1, const _Tp arg2) noexcept { arg1 += arg2; }
    static _Tp opr2(const _Tp arg1, const _Tp arg2) noexcept { return arg1 + arg2; }
    inline bool IsRoot() const noexcept { return !par; }
    inline bool IsVertex() const noexcept { return from == to; }
    void push() noexcept {
        if(lazy != id1){
            if(IsVertex()) opr1(value, lazy);
            al += lazy * sz;
            if(left) opr1(left->lazy, lazy);
            if(right) opr1(right->lazy, lazy);
            lazy = id1;
        }
    }
    void eval() noexcept {
        sz = IsVertex(), al = value;
        if(left) left->push(), sz += left->sz, al = opr2(left->al, al);
        if(right) right->push(), sz += right->sz, al = opr2(al, right->al);
    }
    void rotate(const bool right_) noexcept {
        BSTNode *p = par, *g = p->par;
        if(right_){
            if((p->left = right)) right->par = p;
            right = p, p->par = this;
        }else{
            if((p->right = left)) left->par = p;
            left = p, p->par = this;
        }
        p->eval(), eval();
        if(!(par = g)) return;
        if(g->left == p) g->left = this;
        if(g->right == p) g->right = this;
        g->eval();
    }
};

template<typename _Tp>
BSTNode<_Tp>* splay(BSTNode<_Tp> *u) noexcept {
    if(!u) return nullptr;
    while(!(u->IsRoot())){
        BSTNode<_Tp> *p = u->par, *gp = p->par;
        if(p->IsRoot()){ 

            p->push(), u->push();
            u->rotate((u == p->left));
        }else{
            gp->push(), p->push(), u->push();
            bool flag = (u == p->left);
            if((u == p->left) == (p == gp->left)){ 

                p->rotate(flag), u->rotate(flag);
            }else{ 

                u->rotate(flag), u->rotate(!flag);
            }
        }
    }
    u->push();
    return u;
}

template<typename _Tp>
BSTNode<_Tp>* join(BSTNode<_Tp> *root1, BSTNode<_Tp> *root2) noexcept {
    if(!root1 || !root2) return root1 ? root1 : root2;
    BSTNode<_Tp> *cur = nullptr, *nx = root1;
    do{ cur = nx, cur->push(), nx = cur->right; }while(nx);
    BSTNode<_Tp> *ver = splay(cur);
    ver->right = root2, ver->eval(), root2->par = ver;
    return ver;
}

template<typename _Tp>
pair<BSTNode<_Tp>*, BSTNode<_Tp>*> id1(BSTNode<_Tp> *ver) noexcept {
    BSTNode<_Tp> *res = splay(ver)->left;
    ver->left = nullptr, ver->eval();
    if(res) res->par = nullptr;
    return make_pair(res, ver);
}

template<typename _Tp>
pair<BSTNode<_Tp>*, BSTNode<_Tp>*> id0(BSTNode<_Tp> *ver) noexcept {
    BSTNode<_Tp> *res = splay(ver)->right;
    ver->right = nullptr, ver->eval();
    if(res) res->par = nullptr;
    return make_pair(ver, res);
}

template<typename T> class id3 {
private:
    struct pair_hash {
        template <class T1, class T2>
        size_t operator() (const pair<T1, T2>& p) const {
            size_t lhs = hash<T1>()(p.first), rhs = hash<T2>()(p.second);
            return lhs^(rhs+0x9e3779b9+(lhs<<6)+(lhs>>2));
        }
    };
    BSTNode<T>** vertex_set;
    unordered_map<pair<int, int>, pair<BSTNode<T>*, BSTNode<T>*>, pair_hash> edge_set;
    BSTNode<T> *reroot(BSTNode<T> *ver) noexcept {
        BSTNode<T> *res = splay(ver)->left;
        if(!res) return ver;
        ver->left = nullptr, ver->eval();
        while(ver->right) ver->push(), ver = ver->right;
        splay(ver), ver->right = res, ver->eval(), res->par = ver;
        return ver;
    }
    void link(BSTNode<T> *ver1, BSTNode<T> *ver2) noexcept {
        BSTNode<T>* e1 = new BSTNode<T>(ver1->from, ver2->from);
        BSTNode<T>* e2 = new BSTNode<T>(ver2->from, ver1->from);
        edge_set[{ver1->from, ver2->from}] = {e1, e2};
        join(join(reroot(ver1), e1), join(reroot(ver2), e2));
    }
    void cut(BSTNode<T> *edge1, BSTNode<T> *edge2) noexcept {
        splay(edge1), splay(edge2);
        BSTNode<T> *p = edge1->par;
        bool _right = (edge1 == edge2->right);
        if(p != edge2){
            _right = (p == edge2->right);
            p->par = nullptr, edge1->rotate((edge1 == p->left));
        }
        if(edge1->left) edge1->left->par = nullptr;
        if(edge1->right) edge1->right->par = nullptr;
        if(_right){
            if(edge2->left) edge2->left->par = nullptr;
            join(edge2->left, edge1->right);
        }else{
            if(edge2->right) edge2->right->par = nullptr;
            join(edge1->left, edge2->right);
        }
        

    }
    bool IsConnected(BSTNode<T> *ver1, BSTNode<T> *ver2) noexcept {
        splay(ver1), splay(ver2);
        return ver1->par;
    }
    T& get(BSTNode<T> *ver) noexcept { return splay(ver)->value; }
    void point_update(BSTNode<T> *ver, const T& val){
        splay(ver);
        BSTNode<T>::opr1(ver->value, val);
        ver->al = BSTNode<T>::opr2(ver->al, val);
    }
    void range(BSTNode<T> *edge1, BSTNode<T> *edge2, const T& val) noexcept {
        auto res1 = id1(edge1);
        auto res2 = id0(edge2);
        BSTNode<T>::opr1(res2.first->lazy, val);
        join(join(res1.first,res2.first), res2.second);
    }
    T query(BSTNode<T> *edge1, BSTNode<T> *edge2) noexcept {
        auto res1 = id1(edge1);
        auto res2 = id0(edge2);
        T res = res2.first->al;
        return join(join(res1.first,res2.first), res2.second), res;
    }
    void dfs(const int u, const int p, const BSTNode<T> *cur,
        bool *visit, vector<BSTNode<T>*>& nodes, const vector<vector<int> >& G) noexcept {
        visit[u] = true;
        nodes.push_back(vertex_set[u]);
        for(auto& v : G[u]){
            if(v != p){
                BSTNode<T>* e1 = new BSTNode<T>(u, v);
                nodes.push_back(e1);
                dfs(v, u, cur, visit, nodes, G);
                BSTNode<T>* e2 = new BSTNode<T>(v, u);
                if(u < v) edge_set[{u, v}] = {e1, e2};
                else edge_set[{v, u}] = {e2, e1};
                nodes.push_back(e2);
            }
        }
    }
    void bst_build(vector<BSTNode<T>* >& nodes) noexcept {
        int i, n = (int)nodes.size(), st = 2, isolate = ((n % 4 == 1) ? (n-1) : -1);
        while(st <= n){
            for(i = st-1; i < n; i += 2*st){
                nodes[i]->left = nodes[i-st/2], nodes[i-st/2]->par = nodes[i];
                if(i+st/2 < n) nodes[i]->right = nodes[i+st/2], nodes[i+st/2]->par = nodes[i];
                else if(isolate >= 0) nodes[i]->right = nodes[isolate], nodes[isolate]->par = nodes[i];
                nodes[i]->eval();
            }
            isolate = ((n % (4*st) >= st && (n % (4*st) < 2*st)) ? (i-2*st): isolate);
            st <<= 1;
        }
    }
    void build_forest(const vector<vector<int> >& forest) noexcept {
        bool *visit = new bool[V]();
        for(int i = 0; i < V; i++){
            if(!visit[i]){
                vector<BSTNode<T>* > nodes;
                BSTNode<T> *cur = nullptr;
                dfs(i, -1, cur, visit, nodes, forest);
                bst_build(nodes);
            }
        }
        

    }
    void build_tree(const int root, const vector<vector<int> >& tree) noexcept {
        bool *visit = new bool[V]();
        vector<BSTNode<T>* > nodes;
        BSTNode<T> *cur = nullptr;
        dfs(root, -1, cur, visit, nodes, tree);
        bst_build(nodes);
        

    }

public:
    const int V;
    id3(const vector<T>& ver_value) noexcept : V((int)ver_value.size()){
        vertex_set = new BSTNode<T>*[V];
        for(int i = 0; i < V; i++) vertex_set[i] = new BSTNode<T>(i, i, ver_value[i]);
    }
    id3(const vector<T>& ver_value, const vector<vector<int> >& forest) noexcept
        : id3(ver_value){ build_forest(forest); }
    id3(const vector<T>& ver_value, const int root, const vector<vector<int> >& tree) noexcept
        : id3(ver_value){ build_tree(root, tree); }
    

    

    

    

    

    

    

    

    

    void reroot(const int node_id) noexcept { reroot(vertex_set[node_id]); }
    

    void link(int id2, int id4) noexcept {
        if(id2 > id4) swap(id2, id4);
        link(vertex_set[id2], vertex_set[id4]);
    }
    

    void cut(int id2, int id4){
        if(id2 > id4) swap(id2, id4);
        auto it = edge_set.find({id2, id4});
        assert(it != edge_set.end());
        BSTNode<T> *edge1 = (it->second).first, *edge2 = (it->second).second;
        edge_set.erase(it);
        cut(edge1, edge2);
    }
    

    bool IsConnected(const int id2, const int id4) noexcept {
        if(id2 == id4) return true;
        return IsConnected(vertex_set[id2], vertex_set[id4]);
    }
    

    T& get(const int ver_id) noexcept { return get(vertex_set[ver_id]); }
    

    void point_update(const int ver_id, const T& val) noexcept {
        return point_update(vertex_set[ver_id], val);
    }
    

    void component_range(const int ver_id, const T& val){ range(ver_id, -1, val); }
    

    void range(const int ver_id, const int par_id, const T& val){
        if(par_id < 0) return BSTNode<T>::opr1(splay(vertex_set[ver_id])->lazy, val);
        if(ver_id < par_id){
            auto it = edge_set.find({ver_id, par_id});
            assert(it != edge_set.end());
            range((it->second).second, (it->second).first, val);
        }else{
            auto it = edge_set.find({par_id, ver_id});
            assert(it != edge_set.end());
            range((it->second).first, (it->second).second, val);
        }
    }
    

    T component_query(const int ver_id){ return query(ver_id, -1); }
    

    T query(const int ver_id, const int par_id){
        if(par_id < 0) return splay(vertex_set[ver_id])->al;
        if(ver_id < par_id){
            auto it = edge_set.find({ver_id, par_id});
            assert(it != edge_set.end());
            return query((it->second).second, (it->second).first);
        }else{
            auto it = edge_set.find({par_id, ver_id});
            assert(it != edge_set.end());
            return query((it->second).first, (it->second).second);
        }
    }

private:
    void check_dfs(const BSTNode<T>* cur) const noexcept {
        cur->push();
        if(cur->left) check_dfs(cur->left);
        if(cur->IsVertex()) cout <<"{" << (cur->from) << "," << (cur->value) << "} ";
        if(cur->right) check_dfs(cur->right);
    }
};



unsigned long long u[500010],v[500010];
vector<int> cnt[500010];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int i,n; cin >> n;
    

    vector<unsigned long long> a(n);
    for(int i=0;i<n;i++) a[i] = 1;
    
    vvi tree(n);
    for(int i=0;i<n - 1;i++){
        int w;
        cin >> u[i] >> v[i] >> w; u[i]--; v[i]--;
        cnt[w].push_back(i);
        tree[v[i]].pb(u[i]); tree[u[i]].pb(v[i]); 
    }
    
    id3<unsigned long long> et(a, 0, tree);
    unsigned long long ans = 0;
    for(int i=1;i<=n;i++){
        for(int id:cnt[i]){
            int p = u[id],q = v[id];
            et.cut(p,q);
        }
        for(int id:cnt[i]){
            int p = u[id],q = v[id];
            ans += et.component_query(p)*et.component_query(q);
        }
        for(int id:cnt[i]){
            int p = u[id],q = v[id];
            et.link(p,q);
        }
    }
    cout << ans << "\n";
    
}