

using namespace std;




int n, q;
vector<int> edges[N];
unordered_map<int, char> mpc;
vector<pair<int, int>> queries[N];
pair<int, int> querx[N];
int ansx[N];



typedef struct HASHtype {
    typedef long long LL;
    static const LL B1 = 127LL, P1 = 1000000009LL;
    static const LL B2 = 131LL, P2 = 1000000007LL;
    static vector<LL> XP1, IP1, XP2, IP2;
    LL h1, h2;
    int size;
    static LL quick_inverse(LL n, LL p) {
        LL r = 1;
        for (LL i = p - 2; i; i >>= 1, n = n * n % p)
            if (i & 1LL)
                r = r * n % p;
        return r;
    }
    static void init(int n) {
        XP1.resize(n + 1);
        IP1.resize(n + 1);
        XP2.resize(n + 1);
        IP2.resize(n + 1);
        XP1[0] = XP2[0] = 1LL;
        for (int i = 1; i <= n; i++)
            XP1[i] = XP1[i - 1] * B1 % P1, XP2[i] = XP2[i - 1] * B2 % P2;
        IP1[n] = quick_inverse(XP1[n], P1);
        IP2[n] = quick_inverse(XP2[n], P2);
        for (int i = n; i; i--)
            IP1[i - 1] = IP1[i] * B1 % P1, IP2[i - 1] = IP2[i] * B2 % P2;
    }
    static const HASHtype empty() { return {.h1 = 0, .h2 = 0, .size = 0}; }
    static const HASHtype singleton(char x) {
        return {.h1 = x, .h2 = x, .size = 1};
    }
    static const HASHtype fromString(const string &x);
} HASH;

vector<HASH::LL> HASH::XP1, HASH::IP1, HASH::XP2, HASH::IP2;

const HASH operator+(const HASH &x, const HASH &y) {
    return {.h1 = (x.h1 * HASH::XP1[y.size] + y.h1) % HASH::P1,
            .h2 = (x.h2 * HASH::XP2[y.size] + y.h2) % HASH::P2,
            .size = x.size + y.size};
}



const HASH operator<<(const HASH &x, const HASH &y) {
    return {
        .h1 = (y.h1 - x.h1 * HASH::XP1[y.size - x.size] % HASH::P1 + HASH::P1) %
              HASH::P1,
        .h2 = (y.h2 - x.h2 * HASH::XP2[y.size - x.size] % HASH::P2 + HASH::P2) %
              HASH::P2,
        .size = y.size - x.size};
}



const HASH operator>>(const HASH &x, const HASH &y) {
    return {.h1 = ((x.h1 - y.h1) * HASH::IP1[y.size] % HASH::P1 + HASH::P1) %
                  HASH::P1,
            .h2 = ((x.h2 - y.h2) * HASH::IP2[y.size] % HASH::P2 + HASH::P2) %
                  HASH::P2,
            .size = x.size - y.size};
}

bool operator==(const HASH &x, const HASH &y) {
    return x.h1 == y.h1 && x.h2 == y.h2;
}

namespace std {
template <> struct hash<HASH> {
    std::size_t operator()(const HASH &k) const {
        return (std::size_t)(((k.h1 >> 32) ^ k.h1) ^ (k.h2 >> 32) ^ k.h2);
    }
};
}

typedef struct id6 {
    static HASH hpu[N], hpd[N];
    static int iparent[N][L], dpth[N];
    int x, y, a, length, ll, lr;
    static void init() { dfs(1, -1); }
    static void dfs(int i, int p) {
        memset(iparent[i], -1, L * sizeof(int));
        int l = 0;
        

        for (iparent[i][l] = p; iparent[i][l] != -1; l++)
            iparent[i][l + 1] = iparent[iparent[i][l]][l];
        if (p == -1) {
            dpth[i] = 0;
            hpd[i] = HASH::empty();
            hpu[i] = HASH::empty();
        } else {
            dpth[i] = dpth[p] + 1;
            HASH hc = HASH::singleton(mpc[(p << L) + i]);
            hpd[i] = hpd[p] + hc;
            hpu[i] = hc + hpu[p];
        }
        for (auto xj : edges[i]) {
            if (xj == p)
                continue;
            dfs(xj, i);
        }
    }
    id6(int x, int y, int a) : x(x), y(y), a(a) {
        this->ll = dpth[x] - dpth[a];
        this->lr = dpth[y] - dpth[a];
        this->length = this->ll + this->lr;
    }
    int nodeAt(int idx) const {
        if (idx > this->ll) {
            int py = y;
            for (int l = 0, h = this->length - idx; h; h >>= 1, l++)
                if (h & 1)
                    py = iparent[py][l];
            return py;
        } else {
            int px = x;
            for (int l = 0, h = idx; h; h >>= 1, l++)
                if (h & 1)
                    px = iparent[px][l];
            return px;
        }
    }
    HASH operator[](int idx) const {
        if (idx > this->ll)
            return (hpu[x] >> hpu[a]) + (hpd[a] << hpd[nodeAt(idx)]);
        else
            return hpu[x] >> hpu[nodeAt(idx)];
    }
    int charAt(int idx) const {
        if (idx >= this->length)
            return -1;
        else
            return (int)(this->operator[](idx) << this->operator[](idx + 1)).h1;
    }
} HASHString;

HASH HASHString::hpu[N], HASHString::hpd[N];
int HASHString::iparent[N][L], HASHString::dpth[N];

typedef struct id4 {
    int x, length;
    unordered_map<int, HASH> *mp;
    unordered_map<int, array<int, L>> *ip;
    id4(int x, int length,
                     unordered_map<int, HASH> *mp,
                     unordered_map<int, array<int, L>> *ip)
        : x(x), mp(mp), ip(ip), length(length) {}
    int nodeAt(int idx) const {
        int px = x;
        for (int l = 0, h = idx; h; h >>= 1, l++)
            if (h & 1)
                px = (*ip)[px][l];
        return px;
    }
    HASH operator[](int idx) const {
        int px = nodeAt(idx);
        return (*mp)[x] >> (*mp)[px];
    }
    int charAt(int idx) const {
        if (idx >= this->length)
            return -1;
        else
            return (int)(this->operator[](idx) << this->operator[](idx + 1)).h1;
    }
} CTHASHString;

template <typename T, typename U> int HASH_compare(const T &x, const U &y) {
    int a = 0, b = min(x.length, y.length) + 1;
    while (a + 1 < b) {
        int m = (a + b) / 2;
        if (x[m] == y[m])
            a = m;
        else
            b = m;
    }
    return a;
}

typedef struct id0 {
    vector<array<int, NL>> data;
    vector<int> num, tsize, tless;
    vector<HASH> hs;
    unordered_map<HASH, int> mh;
    array<int, NL> zai;
    id0() {
        memset(&zai[0], 0, NL * sizeof(int));
        this->data.push_back(zai);
        this->tsize.push_back(0);
        this->tless.push_back(0);
        this->num.push_back(1);
        this->hs.push_back(HASH::empty());
        this->mh[HASH::empty()] = 0;
    }
    int insert(const int &i, int cur) {
        if (this->data[cur][i] == 0) {
            this->data[cur][i] = this->data.size();
            this->data.push_back(zai);
            this->num.push_back(1);
            this->tsize.push_back(0);
            this->tless.push_back(0);
            HASH hi = this->hs[cur] + HASH::singleton('a' + i);
            this->hs.push_back(hi);
            this->mh[hi] = this->data[cur][i];
        } else
            this->num[this->data[cur][i]]++;
        return this->data[cur][i];
    }
    void count_size(int cur) {
        int this_size = this->num[cur];
        for (int i = 0; i < NL; i++)
            if (this->data[cur][i] != 0) {
                count_size(this->data[cur][i]);
                this_size += this->tsize[this->data[cur][i]];
            }
        this->tsize[cur] = this_size;
    }
    void count_less(int cur, int pless) {
        int this_less = pless;
        this->tless[cur] = this_less;
        this_less += this->num[cur];
        for (int i = 0; i < NL; i++)
            if (this->data[cur][i] != 0) {
                count_less(this->data[cur][i], this_less);
                this_less += this->tsize[this->data[cur][i]];
            }
    }
    int size() const { return this->data.size(); }
} TRIE;

template <typename T>
int id3(const T &x, TRIE *trie, const HASH &pre) {
    int a = 0, b = x.length - pre.size + 1;
    while (a + 1 < b) {
        int m = (a + b) / 2;
        if (trie->mh.find(pre << x[pre.size + m]) != trie->mh.end())
            a = m;
        else
            b = m;
    }
    int cur = trie->mh[pre << x[pre.size + a]];
    int r = trie->tless[cur];
    if (pre.size == 0)
        r -= trie->num[0];
    if (x.charAt(pre.size + a) != -1) {
        r += trie->num[cur];
        for (int i = x.charAt(pre.size + a) - 'a'; i >= 0; i--)
            if (trie->data[cur][i] != 0)
                r += trie->tsize[trie->data[cur][i]];
    }
    return r;
}



typedef struct id5 {
    vector<int> parex, rankx, colox, ancex, lca;
    id5(int n, int q) {
        parex.resize(n + 1);
        rankx.resize(n + 1);
        colox.resize(n + 1);
        ancex.resize(n + 1);
        lca.resize(q);
        for (int i = 1; i <= n; i++)
            parex[i] = i, rankx[i] = 0;
    }
    int find(int x) {
        if (parex[x] != x)
            parex[x] = find(parex[x]);
        return parex[x];
    }
    void unionx(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        else if (rankx[x] < rankx[y])
            parex[x] = y;
        else if (rankx[x] > rankx[y])
            parex[y] = x;
        else
            parex[y] = x, rankx[x]++;
    }
    void run(int u, int p) {
        ancex[u] = u;
        for (int i = 0; i < edges[u].size(); i++) {
            int v = edges[u][i];
            if (v != p) {
                run(v, u);
                unionx(u, v);
                ancex[find(u)] = u;
            }
        }
        colox[u] = 1;
        for (int i = 0; i < queries[u].size(); i++)
            if (colox[queries[u][i].first])
                lca[queries[u][i].second] = ancex[find(queries[u][i].first)];
    }
} LCA;



struct CENT {
    int *cmax, *csize, n;
    vector<int> nodes;
    bool *rem;
    vector<pair<int, vector<int>>> cents;
    vector<unordered_map<int, HASH>> chu;
    vector<unordered_map<int, array<int, L>>> cip;
    vector<unordered_map<int, int>> clen;
    vector<vector<int>> cnodes;
    vector<TRIE> tries;
    vector<unordered_map<int, TRIE>> sub_tries;
    array<int, L> tip;
    CENT(int n) : n(n) {
        cmax = (int *)malloc((this->n + 1) * sizeof(int));
        csize = (int *)malloc((this->n + 1) * sizeof(int));
        rem = (bool *)malloc((this->n + 1) * sizeof(bool));
        memset(rem, false, (this->n + 1) * sizeof(bool));
        memset(&tip[0], -1, L * sizeof(int));
    }
    ~CENT() {
        free(cmax);
        free(csize);
        free(rem);
    }
    void dfs(int x, int p) {
        nodes.push_back(x);
        csize[x] = 1;
        cmax[x] = 0;
        for (auto i : edges[x])
            if (i != p && !rem[i]) {
                dfs(i, x);
                csize[x] += csize[i];
                if (csize[i] > cmax[x])
                    cmax[x] = csize[i];
            }
    }
    void hash_dfs(int i, int p, int ci) {
        int l = 0;
        for (cip[ci][i] = tip, cip[ci][i][l] = p; cip[ci][i][l] != -1; l++)
            cip[ci][i][l + 1] = cip[ci][cip[ci][i][l]][l];
        if (p == -1) {
            clen[ci][i] = 0;
            chu[ci][i] = HASH::empty();
        } else {
            clen[ci][i] = clen[ci][p] + 1;
            HASH hc = HASH::singleton(mpc[(p << L) + i]);
            chu[ci][i] = hc + chu[ci][p];
        }
        for (auto xj : edges[i])
            if (xj != p && !rem[xj])
                hash_dfs(xj, i, ci);
    }
    void trie_dfs(int i, int p, TRIE *t, int cur) {
        if (p != -1)
            cur = t->insert(mpc[(p << L) + i] - 'a', cur);
        for (auto xj : edges[i])
            if (xj != p && !rem[xj])
                trie_dfs(xj, i, t, cur);
    }
    void decompose() {
        cents.clear();
        vector<int> ztl;
        unordered_map<int, HASH> zmih;
        unordered_map<int, array<int, L>> zmia;
        unordered_map<int, int> zmii;
        TRIE id1;
        unordered_map<int, TRIE> id2;
        cents.push_back(make_pair(0, ztl)); 

        chu.push_back(zmih);
        cip.push_back(zmia);
        clen.push_back(zmii);
        tries.push_back(id1);
        sub_tries.push_back(id2);
        cnodes.push_back(ztl);
        queue<pair<int, int>> q;
        q.push(make_pair(1, 0));
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            nodes.clear();
            dfs(t.first, -1);
            int ct = -1;
            for (auto i : nodes)
                if (csize[i] * 2 >= csize[t.first] &&
                    cmax[i] * 2 <= csize[t.first]) {
                    ct = i;
                    break;
                }
            if (ct == -1)
                ct = t.first;
            vector<int> ctl;
            cents.push_back(make_pair(ct, ctl));
            cnodes.push_back(nodes);
            int cti = cents.size() - 1;
            cents[t.second].second.push_back(cti);
            for (auto i : edges[ct])
                if (!rem[i])
                    q.push(make_pair(i, cti));
            chu.push_back(zmih);
            cip.push_back(zmia);
            clen.push_back(zmii);
            hash_dfs(ct, -1, cti);
            tries.push_back(id1);
            trie_dfs(ct, -1, &tries[cti], 0);
            tries[cti].count_size(0);
            tries[cti].count_less(0, 0);
            sub_tries.push_back(id2);
            for (auto i : edges[ct])
                if (!rem[i]) {
                    sub_tries[cti][i] = id1;
                    trie_dfs(i, ct, &sub_tries[cti][i], 0);
                    sub_tries[cti][i].count_size(0);
                    sub_tries[cti][i].count_less(0, 0);
                }
            rem[ct] = true;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    HASH::init(n);
    char c;
    int a, b, d;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        edges[a].push_back(b);
        edges[b].push_back(a);
        mpc[(a << L) + b] = mpc[(b << L) + a] = c;
    }
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        queries[a].push_back(make_pair(b, i));
        queries[b].push_back(make_pair(a, i));
        querx[i] = make_pair(a, b);
    }
    LCA lca(n, q);
    lca.run(1, -1);
    CENT cent(n);
    cent.decompose();
    HASHString::init();
    memset(ansx, 0, q * sizeof(int));
    queue<int> qq;
    qq.push(1);
    while (!qq.empty()) {
        int i = qq.front();
        qq.pop();
        int ct = cent.cents[i].first;
        for (auto ia : cent.cnodes[i]) {
            for (auto ib : queries[ia]) {
                int qi = ib.second;
                if (querx[qi].first != ia)
                    continue;
                if (querx[qi].first == querx[qi].second) {
                    ansx[qi] = -1;
                    continue;
                }
                HASHString x(querx[qi].first, querx[qi].second, lca.lca[qi]);
                CTHASHString xc(querx[qi].first,
                                cent.clen[i][querx[qi].first], &cent.chu[i],
                                &cent.cip[i]);
                int w = HASH_compare(x, xc);
                int wi = x.charAt(w) - xc.charAt(w);
                if (wi < 0)
                    ;
                else if (wi > 0 && !(xc.length <= x.length && w == xc.length)) {
                    ansx[qi] += cent.cnodes[i].size();
                    int nxd = xc.nodeAt(cent.clen[i][querx[qi].first] - 1);
                    TRIE *trie = &cent.sub_tries[i][nxd];
                    ansx[qi] -= trie->tsize[0] - 1;
                } else {
                    TRIE *trie = &cent.tries[i];
                    HASH pre = xc[xc.length];
                    ansx[qi] += id3(x, trie, pre);
                    if (xc.length != 0 && x.length > xc.length) {
                        int nxd = xc.nodeAt(cent.clen[i][querx[qi].first] - 1);
                        trie = &cent.sub_tries[i][nxd];
                        ansx[qi] -= id3(x, trie, pre) - 1;
                    }
                }
            }
        }
        for (auto iq : cent.cents[i].second)
            qq.push(iq);
    }
    for (int i = 0; i < q; i++)
        cout << ansx[i] << endl;
    return 0;
}
