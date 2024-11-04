






using namespace std;

struct F {
    int type = 0; 

    void compose(const F &f) {
        if(f.type == 0) return;
        if(f.type != 3)
            type = f.type;
        else
            type = 3 - type;
    }
    int applyAggregate(const int &sz, const int &sum) {
        if(type == 0) return sum;
        if(type == 1) return sz;
        if(type == 2) return 0;
        if(type == 3) return sz - sum;
        assert(false);
    }
};

struct Node {
    static Node *null;
    Node *l, *r;
    F mod;
    long long x;
    bool val = false;
    int y, sz, sum = 0;
    Node() {l = r = this;sz = 0;}
    Node(const long long &_x) {
        x = _x;
        y = rand();
        l = r = null;
        sz = 1;
    }
    ~Node() {
        if(l != null) delete l;
        if(r != null) delete r;
    }
    int get_sum() {
        return mod.applyAggregate(sz, sum);
    }
    void recalc() {
        if(this == null) return;
        sum = l->get_sum() + val + r->get_sum();
    }
    void upd_sz() {
        if(this == null) return;
        sz = l->sz + 1 + r->sz;
    }
};

Node *Node::null = new Node(), *tr;
set<long long> were;
vector<long long> dst;
int n;
pair<int, pair<long long, long long>> v[100000];

void advance(Node *t) {
    if(t == Node::null || t->mod.type == 0) return;
    if(t->l != Node::null)
        t->l->mod.compose(t->mod);
    if(t->r != Node::null)
        t->r->mod.compose(t->mod);
    t->sum = (t->mod.type == 3 ? t->sz - t->sum : (t->mod.type == 1 ? t->sz : 0));
    t->val = (t->mod.type == 3 ? !t->val : t->mod.type == 1);
    t->mod.type = 0;
}

void split(Node *&t, const long long &x, Node *&l, Node *&r) {
    if(t == Node::null) {
        l = r = t;
        return;
    }
    advance(t);
    if(t->x < x) {
        l = t;
        split(l->r, x, l->r, r);
    } else {
        r = t;
        split(r->l, x, l, r->l);
    }
    t->upd_sz();
    t->recalc();
}

Node *merge(Node *l, Node *r) {
    advance(l);
    advance(r);
    if(l == Node::null) return r;
    if(r == Node::null) return l;
    if(l->y > r->y) {
        l->r = merge(l->r, r);
        l->upd_sz();
        l->recalc();
        return l;
    } else {
        r->l = merge(l, r->l);
        r->upd_sz();
        r->recalc();
        return r;
    }
}

long long mex(Node *t) {
    advance(t);
    advance(t->l);
    advance(t->r);


    assert(t->get_sum() <= t->sz);
    assert(t->get_sum() < t->sz);
    if(t->l != Node::null && t->l->get_sum() < t->l->sz)
        return mex(t->l);
    else if(t->val == 0)
        return t->x;
    else if(t->r != Node::null && t->r->get_sum() < t->r->sz)
        return mex(t->r);
    assert(false);
}

Node *build(const int &l, const int &r) {
    if(r == l + 1)
        return new Node(dst[l]);
    Node *lt = build(l, (l + r) / 2), *rt = build((l + r) / 2, r);
    return merge(lt, rt);
}

void solve() {
    srand(time(nullptr));
    scanf("%d", &n);
    were.insert(1);
    for(int i = 0;i < n;i++) {
        scanf("%d %I64d %I64d", &v[i].X, &v[i].Y.X, &v[i].Y.Y);
        were.insert(v[i].Y.X - 1);
        were.insert(v[i].Y.X);
        were.insert(v[i].Y.X + 1);
        were.insert(v[i].Y.Y - 1);
        were.insert(v[i].Y.Y);
        were.insert(v[i].Y.Y + 1);
    }
    were.erase(0);
    dst = vector<long long>(were.begin(), were.end());
    tr = build(0, dst.size());
    for(int i = 0;i < n;i++) {
        Node *l, *m, *r;
        split(tr, v[i].Y.X, l, m);
        split(m, v[i].Y.Y + 1, m, r);
        advance(m);
        m->mod.type = v[i].X;
        tr = merge(merge(l, m), r);
        assert(tr->sum < tr->sz);
        printf("%I64d\n", mex(tr));
    }
    delete tr;
    delete Node::null;
}

int main() {
    if(!ONLINE_JUDGE) { 





    } else
        freopen("input.txt", "r", stdin);
    solve();
    return 0;
}
