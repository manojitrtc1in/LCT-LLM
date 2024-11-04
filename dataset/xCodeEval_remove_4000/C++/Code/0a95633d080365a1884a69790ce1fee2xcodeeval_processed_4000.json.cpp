


















  














using namespace std;

const int INF = 1'000'000'017;
const ll LLINF = 1'000'000'000'000'000'017LL;
const ld inf = 1.0 / 0.0;
const ld eps = 1e-9;
const int MOD = 1e9 + 7;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int my_rand() {
    return rand() << 16 ^ rand();
}

struct node {
    int ssz = 1, y = my_rand(), val;
    node *l = nullptr, *r = nullptr, *p = nullptr;

    int cnt_in = 0, cnt_out = 0;
    int is_in = 0, is_out = 0;
    int v;

    node() {}

    node(int val, int v) : val(val), v(v) {}
};

int id0(node*& v) {
    return (v ? v->ssz : 0);
}

int id1(node*& v) {
    return (v ? v->cnt_in : 0);
}

int id2(node*& v) {
    return (v ? v->cnt_out : 0);
}

void upd(node*& v) {
    if (!v) {
        return;
    }
    v->ssz = id0(v->l) + id0(v->r) + 1;
    v->cnt_in = id1(v->l) + id1(v->r) + v->is_in;
    v->cnt_out = id2(v->l) + id2(v->r) + v->is_out;
}

pair<node*, node*> split(node*& v, int k) {
    if (!v || k == 0) {
        return {nullptr, v};
    }
    if (v->ssz == k) {
        return {v, nullptr};
    }
    int ls = id0(v->l);
    //cout << '$' << ls << endl;
    if (ls >= k) {
        if (v->l)
        v->l->p = nullptr;
        auto tmp = split(v->l, k);
        v->l = tmp.s;
        if (tmp.s)
        tmp.s->p = v;
        upd(v);
        return {tmp.f, v};
    }
    else {
        if (v->r)
        v->r->p = nullptr;
        auto tmp = split(v->r, k - ls - 1);
        v->r = tmp.f;
        if (tmp.f)
        tmp.f->p = v;
        upd(v);
        return {v, tmp.s};
    }
}

node* merge(node*& l, node*& r) {
    if (!l) {
        //cout << 'x';
        return r;
    }
    if (!r) {
        //cout << 'y';
        return l;
    }
    if (l->y > r->y) {
        if (l->r)
        l->r->p = nullptr;
        auto tmp = merge(l->r, r);
        //cout << l->val << r->val << endl;
        //cout << l->val << endl;
        l->r = tmp;
        if (tmp)
        tmp->p = l;
        upd(l);
        return l;
    }
    else {
        if (r->l)
        r->l->p = nullptr;
        auto tmp = merge(l, r->l);
        //cout << l->val << r->val << endl;
        //cout << r->val << endl;
        r->l = tmp;
        if (tmp)
        tmp->p = r;
        upd(r);
        return r;
    }
}

int get_pos(node* v) {
    int res = id0(v->l);
    while (v->p) {
        if (v->p->r == v) {
            res += id0(v->p->l) + 1;
        }
        v = v->p;
    }
    return res;
}

void print(node* v, int h = 0) {
    if (!v) {
        return;
    }
    cout << string(h, ' ') << v->val << endl;
    print(v->l, h + 1);
    print(v->r, h + 1);
}

void aprint(node* v) {
    if (!v) {
        return;
    }
    aprint(v->l);
    cout << v->val << ' ';
    aprint(v->r);
}

node* get_root(node* v) {
    if (!v) {
        return v;
    }
    while (v->p) {
        v = v->p;
    }
    //aprint(v);
    //cout << endl;
    return v;
}

void ch_in(node*& v, const int x, bool ok = 1) {
    if (!v) {
        return;
    }
    if (ok) {
        v->is_in += x;
    }
    v->cnt_in += x;
    //cout << "ch_in: " << v->val << ' ' << v->cnt_in << ' ' << x << ' ' << ok << endl;
    //assert(v != v->p);
    ch_in(v->p, x, 0);
}

void ch_out(node*& v, const int x, bool ok = 1) {
    if (!v) {
        return;
    }
    if (ok) {
        v->is_out += x;
    }
    v->cnt_out += x;
    //cout << "ch_out: " << v->val << ' ' << v->cnt_out << ' ' << x << ' ' << ok << endl;
    ch_out(v->p, x, 0);
}

vector<int> in_edge;

void get_in(node*& v) {
    if (!v) {
        return;
    }
    int cl = id1(v->l), cr = id1(v->r);
    if (v->cnt_in > cl + cr) {
        in_edge.eb(v->val);
    }
    if (cl) {
        get_in(v->l);
    }
    if (cr) {
        get_in(v->r);
    }
}

vector<int> xvert;

void get_out(node*& v) {
    if (!v) {
        return;
    }
    //cout << "get_out: " << v->val << ' ' << v->cnt_out << endl;
    int cl = id2(v->l), cr = id2(v->r);
    if (v->cnt_out > cl + cr) {
        xvert.eb(v->v);
    }
    if (cl) {
        get_out(v->l);
    }
    if (cr) {
        get_out(v->r);
    }
}

struct ETF {
    map<pii, pair<node*, node*>> et;
    map<pii, int> en;
    static const int N = 3e5 + 7;
    bool live[N] = {};

    vector<node*> up;

    vector<vector<pair<int, node*>>> g;

    vector<pii> aux;

    set<int> good;

    vector<int> cntw;

    int ecnt = 0;

    ETF() {}

    ETF(int n) {
        g.resize(n + 3);
        up.resize(n + 3);
        cntw.resize(n + 3);
        aux.eb(0, 0);
    }

    node* rt(int v) {
        if (!up[v]) {
            return nullptr;
        }
        int pos = get_pos(up[v]) + 1;
        ///cout << v << ' ' << pos << endl;
        node* r = get_root(up[v]);
        //print(r);
        /*cout << '!' << v << endl;
        if (up[v]) {
            cout << '$' << up[v]->val << endl;
        }
        cout << pos << endl;*/
        auto tmp = split(r, pos);
        //cout << '$' << endl;
        r = merge(tmp.s, tmp.f);
        return r;
    }

    void debug() {
        for (int i = 1; i <= sz(g) - 3; ++i) {
            if (!up[i]) {
                cout << -1;
            }
            else {
                aprint(get_root(up[i]));
            }
            cout << endl;
        }
    }

    void fnd(int u) {
        ch_out(up[u], -cntw[u]);
        up[u] = nullptr;
        while (!g[u].empty()) {
            if (live[g[u].back().f]) {
                up[u] = g[u].back().s;
                ch_out(up[u], cntw[u]);
                break;
            }
            else {
                g[u].pop_back();
            }
        }
    }

    void link(int u, int v, bool chup = 0) {
        if (u > v) {
            swap(u, v);
        }
        ++ecnt;
        aux.eb(u, v);
        //cout << '!' << endl;
        node* ru = rt(u);
        //cout << '!' << endl;
        node* rv = rt(v);
        //cout << '!' << endl;
        node* x1 = new node(ecnt, v);
        node* x2 = new node(ecnt, u);
        /*cout << "ru\n";
        print(ru);
        cout << endl;
        cout << "rv\n";
        print(rv);
        cout << endl;*/
        /*cout << "S\n";
        aprint(ru);
        cout << endl;
        aprint(rv);
        cout << endl;
        cout << "T\n";*/
        ///up[u] = x2;
        ///up[v] = x1;
        live[ecnt] = 1;
        g[u].eb(ecnt, x2);
        g[v].eb(ecnt, x1);
        //cout << "S" << ' ' << x1->val << endl;
        /*for (int i = 1; i <= ecnt; ++i) {
            cout << live[i] << ' ' << aux[i].f << ' ' << aux[i].s << endl;
        }*/
        fnd(u);
        fnd(v);
        en[mp(u, v)] = ecnt;
        et[mp(u, v)] = {x1, x2};
        ru = merge(ru, x1);
        ru = merge(ru, rv);
        //print(ru);
        ru = merge(ru, x2);
        //aprint(ru);
        //cout << endl;
        //cout << "T" << endl;
        if (chup) {
            ch_in(x1, 1);
            //ch_in(x2, 1);
            good.emplace(ecnt);
        }
        //cout << '$' << endl;
        //print(ru);
        //cout << '
        //cout << '!' << endl;
        ///aprint(ru);
        ///cout << endl;
        //cout << '%' << endl;
        ///debug();
    }

    void cut(int u, int v) {
        if (u > v) {
            swap(u, v);
        }
        auto tmp = et[mp(u, v)];
        int pos1 = get_pos(tmp.f), pos2 = get_pos(tmp.s);
        if (pos1 > pos2) {
            swap(pos1, pos2);
        }
        int ex = en[mp(u, v)];
        if (good.find(ex) != good.end()) {
            good.erase(ex);
            ch_in(tmp.f, -1);
            ch_in(tmp.s, -1);
        }
        live[ex] = 0;
        fnd(u);
        fnd(v);
        auto r = get_root(tmp.f);
        //aprint(r);
        //cout << endl;
        //cout << pos1 << ' ' << pos2 << endl;
        auto sp1 = split(r, pos1 + 1);
        auto r1 = split(sp1.f, pos1).f;
        auto sp2 = split(sp1.s, pos2 - pos1);
        auto r2 = split(sp2.f, pos2 - pos1 - 1).f;
        r1 = merge(r1, sp2.s);
        /*aprint(r1);
        cout << endl;
        aprint(r2);
        cout << endl;*/
        ///debug();
    }

    bool get(int u, int v) {
        if (u == v) {
            return 1;
        }
        if (!up[u] || !up[v]) {
            return 0;
        }
        //cout << up[u]->val << ' ' << up[v]->val << endl;
        auto ru = get_root(up[u]), rv = get_root(up[v]);
        //cout << ru->val << endl;
        return (ru == rv);
    }
};

struct DCP {
    vector<ETF> f;
    vector<unordered_map<int, unordered_set<int>>> to;  /// v, w -> u
    map<pii, int> wg;

    DCP() {}

    DCP(int n) {
        int k = 0;
        while ((1 << k) < n) {
            ++k;
        }
        k += 2;
        f.resize(k, ETF(n));
        to.resize(n + 3);
    }

    void link(int u, int v) {
        if (u > v) {
            swap(u, v);
        }
        if (!f[0].get(u, v)) {
            f[0].link(u, v, 1);
        }
        else {
            wg[mp(u, v)] = 0;
            to[u][0].emplace(v);
            to[v][0].emplace(u);
            ++f[0].cntw[u];
            ++f[0].cntw[v];
            ch_out(f[0].up[u], 1);
            ch_out(f[0].up[v], 1);
        }
    }

    void cut(int u, int v) {
        if (u > v) {
            swap(u, v);
        }
        //cout << "CUT " << u << ' ' << v << endl;
        /*for (auto& el : f[0].en) {
            cout << '$' << el.f.f << ' ' << el.f.s << ' ' << el.s << endl;
        }*/
        if (!f[0].en[mp(u, v)] || !f[0].live[f[0].en[mp(u, v)]]) {
            //cout << "No edge (" << u << "; " << v << ") in the forest" << endl;
            int w = wg[mp(u, v)];
            //cout << w << endl;
            for (int i = 0; i <= w; ++i) {
                ch_out(f[i].up[u], -1);
                ch_out(f[i].up[v], -1);
                --f[i].cntw[u];
                --f[i].cntw[v];
            }
            //cout << '!' << endl;
            to[u][w].erase(v);
            to[v][w].erase(u);
            return;
        }
        //cout << "Edge exists in the forest" << endl;
        int z = 0;
        for (auto& el : f) {
            if (el.get(u, v)) {
                //cout << "CUT in " << z << " forest" << endl;
                el.cut(u, v);
            }
            ++z;
        }
        //cout << "Cutting completed!" << endl;
        for (int i = sz(f) - 1; i >= 0; --i) {
            //cout << "Forest number: " << i << endl;
            node *tu = get_root(f[i].up[u]), *tv = get_root(f[i].up[v]);
            //cout << '!' << endl;
            if (id0(tu) > id0(tv)) {
                swap(tu, tv);
                swap(u, v);
            }
            /*aprint(tu);
            cout << '$' << endl;
            aprint(tv);
            cout << '$' << endl;*/
            in_edge.clear();
            xvert.clear();
            //cout << "Prepare tu and tv complete" << endl;
            get_in(tu);
            get_out(tu);
            xvert.eb(u);
            //output(xvert);
            if (u > v) {
                swap(u, v);
            }
            //cout << "In-edge with weight i: " << sz(in_edge) << endl;
            //cout << "Vertices with out_edges of weight i: " << sz(xvert) << endl;
            for (int x : in_edge) {
                pii e = f[i].aux[x];
                int u = e.f, v = e.s;
                f[i].good.erase(x);
                ch_in(f[i].et[mp(u, v)].f, -1);
                //ch_in(f[i].et[mp(u, v)].s, -1);
                ++wg[mp(u, v)];
                //cout << 'Z' << i + 1 << endl;
                f[i + 1].link(u, v, 1);
                //cout << '@' << endl;
            }
            //cout << '%' << endl;
            for (int xu : xvert) {
                bool ok = 0;
                vector<int> to_del;
                for (int xv : to[xu][i]) {
                    //cout << '%' << f[i].up[xv]->val << endl;
                    if (get_root(f[i].up[xv]) == tv) {
                    //cout << '
                        f[i].link(xu, xv, 1);
                        ch_out(f[i].up[xu], -1);
                        --f[i].cntw[xu];
                        to[xu][i].erase(xv);
                        to[xv][i].erase(xu);
                        for (int j = i - 1; j >= 0; --j) {
                            f[j].link(xu, xv);
                        }
                        ok = 1;
                        break;
                    }
                    else {
                        to_del.eb(xv);
                    }
                }
                for (int td : to_del) {
                    to[xu][i].erase(td);
                    to[td][i].erase(xu);
                    --f[i].cntw[xu];
                    ch_out(f[i].up[xu], -1);
                    to[xu][i + 1].emplace(td);
                    to[td][i + 1].emplace(xu);
                    ++f[i + 1].cntw[xu];
                    ch_out(f[i + 1].up[xu], 1);
                    ++wg[mp(min(xu, td), max(xu, td))];
                }
                if (ok) {
                    return;
                }
            }
        }
    }

    bool get(int u, int v) {
        return f[0].get(u, v);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(0));

    int n, m;
    cin >> n >> m;

    DCP dcp(n);

    int last = 0;
    set<pii> es;
    while (m--) {
        int t, x, y;
        cin >> t >> x >> y;
        x = (x + last - 1) % n;
        y = (y + last - 1) % n;
        if (x > y) {
            swap(x, y);
        }
        if (t == 1) {
            if (es.find(mp(x, y)) != es.end()) {
                dcp.cut(x, y);
                es.erase(mp(x, y));
            } else {
                dcp.link(x, y);
                es.emplace(x, y);
            }
        } else {
            cout << (last = dcp.get(x, y));
        }
    }
    return 0;
}
