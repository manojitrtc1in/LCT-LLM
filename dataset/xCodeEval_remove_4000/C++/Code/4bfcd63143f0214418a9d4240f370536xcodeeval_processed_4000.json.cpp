













using namespace std;

const int N = 5e5 + 500;

int tin[N], tout[N], tim, poss[N], pw[N];
int up[N][21], d[N], heavy[N], val[N], t[N];
vector <int> ord;
int pos[N], who[N], siz[N], pred[N], rmq[N][21], pos_r[N];
vector <pair <pair <int, int>, int> > qr[N];
bool mk[N];
vector <int> g[N];
string s;
int l[N], r[N], rgt[N], lft[N];
map <pair <int, int>, char> color;
vector <int> perm;
int n, m, q;

void upd(int v) {for (; v < N; v = (v | (v + 1))) t[v]++;}
int gett(int v) {int ret = 0; for (; v >= 0; v = (v & (v + 1)) - 1) ret += t[v]; return ret;}

bool isac(int v, int u) {return (tin[v] <= tin[u] && tout[v] >= tout[u]);}
int lca(int v, int u) {
    if (isac(v, u)) {
        return v;
    }
    if (isac(u, v)) {
        return u;
    }
    for (int st = 16; st >= 0; st--) {
        if (!isac(up[v][st], u)) {
            v = up[v][st];
        }
    }
    return up[v][0];
}

void dfs(int v, int pr) {
    siz[v] = 1;
    pred[v] = pr;
    tin[v] = tim++;
    up[v][0] = pr;
    for (auto u : g[v]) {
        if (u == pr) {
            continue;
        }
        d[u] = d[v] + 1;
        dfs(u, v);
        siz[v] += siz[u];
    }

    heavy[v] = -1;
    for (auto u : g[v]) {
        if (u == pr) {
            continue;
        }
        if (siz[u] > siz[v] / 2) {
            heavy[v] = u;
        }
    }
    tout[v] = tim++;
    ord.push_back(v);
}


int get(char c) {
    if (c == '
        return 26;
    }
    return c - 'a';
}

int get(int l, int r) {
    if (r < l) {
        swap(l, r);
    }
    int len = r - l + 1, pl = pw[len];
    return min(rmq[l][pl], rmq[r - (1 << pl) + 1][pl]);
}

int lcp[N], c[N], p[N], cn[N], pn[N], cnt[N];
int cls[N][21];
void build(int n) {
    for (int i = 0; i < n; i++) {
        rmq[i][0] = lcp[i];
    }
    pw[0] = -1;
    for (int i = 1; i < n; i++) {
        pw[i] = pw[i / 2] + 1;
    }
    for (int st = 1; st < 20; st++) {
        for (int i = 0; i < n; i++) {
            rmq[i][st] = min(rmq[i][st - 1], rmq[min(i + (1 << (st - 1)), n - 1)][st - 1]);
        }
    }
}

int LOG = 0;

int id5(int a, int b) {
    int ret = 0;
    for (int i = LOG; i >= 0; i--) {
        if (cls[a][i] == cls[b][i]) {
            ret += (1 << i);
            a += (1 << i);
            b += (1 << i);
            if (a >= s.size()) {
                a -= s.size();
            }
            if (b >= s.size()) {
                b -= s.size();
            }
        }
    }
    return ret;
}

void id4() {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        int c = get(s[i]);
        cnt[c]++;
    }
    for (int i = 1; i < 27; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; i++) {
        int c = get(s[i]);
        p[--cnt[c]] = i;
    }
    c[p[0]] = 0;
    int classes = 0;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i - 1]]) {
            classes++;
        }
        c[p[i]] = classes;
        cls[p[i]][0] = classes;
    }
    for (int h = 0; (1 << h) <= n; h++) {
        LOG = h + 1;
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0) {
                pn[i] += n;
            }
        }
        for (int i = 0; i <= classes + 4; i++) {
            cnt[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            cnt[c[pn[i]]]++;
        }
        for (int i = 1; i <= classes; i++) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            p[--cnt[c[pn[i]]]] = pn[i];
        }
        cn[p[0]] = 0;
        classes = 0;
        for (int i = 1; i < n; i++) {
            int a = p[i] + (1 << h), b = p[i - 1] + (1 << h);
            if (a >= n) {
                a -= n;
            }
            if (b >= n) {
                b -= n;
            }
            if (c[p[i]] != c[p[i - 1]] || c[a] != c[b]) {
                classes++;
            }
            cn[p[i]] = classes;
            cls[p[i]][h + 1] = classes;
        }
        

        for (int i = 0; i < n; i++) {


            c[i] = cn[i];
        }
    }
    for (int i = 0; i < n - 1; i++) {
        lcp[i] = id5(p[i], p[i + 1]);
        lcp[i] = min(lcp[i], min(n - p[i], n - p[i + 1]));
    }
    build(n);
    for (int i = 0; i < n; i++) {
        poss[p[i]] = i;
        perm.push_back(p[i]);
    }
}


void id0() {
    vector <int> path;
    int it = s.size(), cnt = 0;
    for (auto v : ord) {
        if (mk[v]) {
            continue;
        }
        int u = pred[v];
        path.clear();
        while (v != 1 && heavy[u] == v) {
            mk[v] = 1;
            path.push_back(v);
            v = pred[v]; u = pred[v];
        }
        mk[v] = 1;
        path.push_back(v);
        for (auto x : path) {
            who[s.size()] = x;
            pos[x] = s.size();
            s += color[{x, pred[x]}];
        }
        for (auto x : path) {
            rgt[x] = s.size() - 1;
        }
        reverse(path.begin(),path.end());
        for (auto x : path) {
            pos_r[x] = s.size();
            s += color[{x, pred[x]}];
        }
        s += "


    }
}


bool have(int a, int &lcp, int &b, int &need) {
    a = poss[(perm[a] + lcp) % s.size()];
    if (a == b) {
        return 1;
    }
    int l = min(a, b);
    int r = max(a, b) - 1;
    return get(l, r) >= need;
}

int id2(int &start, int &x, int &lcp, int r) {
    int l = start;
    while (l < r) {
        

        int md = (1 + l + r) >> 1;
        if (poss[(perm[md] + lcp) % s.size()] > x) {
            r = md - 1;
        } else {
            l = md;
        }
    }
    return r;
}

int id3(int &start, int &x, int &lcp, int l) {
    int r = start;
    while (l < r) {
        int md = (l + r + 1) >> 1;
        if (poss[(perm[md] + lcp) % s.size()] > x) {
            r = md - 1;
        } else {
            l = md;
        }
    }
    return r;
}

int before(int &mid, int &lcp, int &x, int &d, int &R) {
    int l = x;
    int r = id2(x, mid, lcp, R);
    while (l < r) {
        int md = (l + r) >> 1;
        if (have(md, lcp, mid, d)) {
            r = md;
        } else {
            l = md + 1;
        }
    }
    if (!have(l, lcp, mid, d)) {
        l++;
    }
    return l;
}

int after(int &mid, int &lcp, int &x, int &d, int &L) {
    int l = id3(x, mid, lcp, L);
    int r = x;
    while (l < r) {
        int md = (l + r + 1) >> 1;
        if (have(md, lcp, mid, d)) {
            l = md;
        } else {
            r = md - 1;
        }
    }
    if (!have(r, lcp, mid, d)) {
        r--;
    }
    return r;
}

int dist(int a, int b) {return d[b] - d[a];}
void go_up(int a, int b, int &l, int &r, int &len) {
    if (a == 1) {
        return;
    }
    int L = l, R = r;
    if (rgt[a] == rgt[b]) {
        int d = dist(b, a);
        if (d) {
            l = before(poss[pos[a]], len, l, d, R);
            r = after(poss[pos[a]], len, r, d, L);
        }
        if (l > r) {
            return;
        }
        len += d;
    } else {
        int v = who[rgt[a]];
        int d = dist(pred[v], a);
        if (d) {
            l = before(poss[pos[a]], len, l, d, R);
            r = after(poss[pos[a]], len, r, d, L);
        }
        if (l > r) {
            return;
        }
        len += d;
        go_up(pred[v], b, l, r, len);
    }
}

vector <pair <int, int> > path;
void go_down(int a, int b, int &l, int &r, int &len) {
    path.clear();
    while (rgt[a] != rgt[b]) {
        int v = who[rgt[a]];
        path.push_back({a, v});
        a = pred[v];
    }
    path.push_back({a, b});
    reverse(path.begin(),path.end());
    int fst = a;
    for (auto x : path) {
        int a = x.second, b = x.first;
        int B = b;
        int d = dist(pred[a], b);
        int L = l, R = r;
        if (d) {
            l = before(poss[pos_r[a]], len, l, d, R);
            r = after(poss[pos_r[a]], len, r, d, L);
        }
        if (l > r) {
            return;
        }
        len += d;
    }
}

void go_to(int &a, int b) {
    for (int st = 17; st >= 0; st--) {
        if (!isac(up[a][st], b)) {
            a = up[a][st];
        }
    }
}

pair <int, int> id1(int from, int to) {
    int l = 0, r = s.size() - 1, len = 0;
    int c = get(color[{from, pred[from]}]);
    int lc = lca(from, to);
    if (from != lc) {
        go_up(from, lc, l, r, len);
    }
    if (to != lc) {
        int plc = to;
        go_to(plc, lc);
        go_down(to, plc, l, r, len);
    }
    return {l, r};
}

struct query {
    int from, to, L, R;
};

int KMP(string x) {
    vector <int> pr(x.size() + 5, 0);
    int i = 0, mx, ret = 0;
    while (x[i] != ' ') {
        i++;
    }
    mx = i;
    for (int i = 1; i < x.size(); i++) {
        int j = pr[i - 1];
        while (j && x[i] != x[j]) {
            j = pr[j - 1];
        }
        if (x[i] == x[j]) {
            j++;
        }
        if (j == mx) {
            ret++;
        }
        pr[i] = j;
    }
    return ret;
}

void brute(vector <int> &cans, vector <query> &qrs, vector <int> &l, vector <int> &r) {
    vector <int> ans(q);
    int ptr = 0;
    for (auto x : qrs) {
        int from = x.from, to = x.to, L = x.L, R = x.R;
        string ss = "";
        while (!isac(from, to)) {
            ss += color[{from, up[from][0]}];
            from = up[from][0];
        }
        string t = "";
        while (to != from) {
            t = color[{to, up[to][0]}] + t;
            to = up[to][0];
        }
        ss += t;
        string p = ss + " ";
        for (int i = l[L]; i <= r[R]; i++) {
            p += s[i];
        }
        cout << cans[ptr] << " " << KMP(p) << '\n';
        ptr++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        color[{v, u}] = c;
        color[{u, v}] = c;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector <int> l(m), r(m);
    string t;
    for (int i = 0; i < m; i++) {
        cin >> t;
        l[i] = s.size();
        s += t;
        r[i] = s.size();
        s += "
    }

    dfs(1, 1);
    color[{1, 1}] = '
    for (int st = 1; st < 20; st++) {
        for (int i = 1; i <= n; i++) {
            up[i][st] = up[up[i][st - 1]][st - 1];
        }
    }
    id0();







    id4();




    for (int it = 0; it < q; it++) {
        int from, to, L, R;
        cin >> from >> to >> L >> R; L--; R--;


        L = l[L]; R = r[R] - 1;

        pair <int, int> brd = id1(from, to);
        if (brd.second < brd.first) {
            continue;
        }
        if (L - 1 >= 0) {
            qr[L - 1].push_back({brd, it * 2});
        }
        if (R < r[m - 1]) {
            qr[R].push_back({brd, it * 2 + 1});
        }
    }
    

    for (int i = 0; i < r[m - 1]; i++) {
        upd(poss[i]);
        for (auto x : qr[i]) {
            int l = x.first.first, r = x.first.second;
            int j = x.second;
            val[j] = gett(r) - gett(l - 1);
        }
    }
    vector <int> ans(q);
    for (int it = 0; it < q; it++) {
        ans[it] = val[it * 2 + 1] - val[it * 2];
        cout << ans[it] << '\n';
    }





    return 0;
}
