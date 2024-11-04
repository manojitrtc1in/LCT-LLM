
























using namespace std;

typedef long long ll;
typedef long double ld;














const int INF = 1791791791;
const ll INFLL = 1791791791791791791ll;

template<int id3, int id2>
class FastIO {
    char cbuf[id3 + 1];
    int icur = 0;

    inline bool go_to_next_token() {
        while (cbuf[icur] == ' ' || cbuf[icur] == '\n') icur++;
        while (cbuf[icur] == 0) {
            icur = 0;
            if (fgets(cbuf, sizeof(cbuf), stdin) != cbuf)
                return false;
            while (cbuf[icur] == ' ' || cbuf[icur] == '\n') icur++;
        }
        return true;
    }
  public:
    string readString() {
        assert(go_to_next_token());
        string ans;
        while (cbuf[icur] != ' ' && cbuf[icur] != '\n' && cbuf[icur] != 0)
            ans.push_back(cbuf[icur++]);
        ans.shrink_to_fit();
        return ans;
    }

    template<class int_type>
    int_type readInt() {
        assert(go_to_next_token());
        int_type x = 0;
        bool m = cbuf[icur] == '-';
        if (m) icur++;
        while ('0' <= cbuf[icur] && cbuf[icur] <= '9') {
            x *= 10;
            x += (cbuf[icur] - '0');
            icur++;
        }
        if (m) x = -x;
        return x;
    }

    bool seekEof() {
        return !go_to_next_token();
    }

  private:
    char obuf[id2 + 1];
    int ocur = 0;

    inline void write_string(const char *str, size_t sz = 0) {
        if (sz == 0)
            sz = strlen(str);
        if (ocur + sz > id2) {
            fputs(obuf, stdout);
            fputs(str, stdout);
            ocur = 0;
            obuf[0] = 0;
            return;
        }
        strcpy(obuf + ocur, str);
        ocur += sz;
        obuf[ocur] = 0;
   }

  public:
    template<class int_type>
    void writeInt(int_type x, bool sp = true) {
        char buf[20];
        int c = 0;
        if (x < 0) {
            buf[c++] = '-';
            x = -x;
        }
        int s = c;
        if (x == 0) {
            buf[c++] = '0';
        }
        while (x > 0) {
            buf[c++] = (x % 10) + '0';
            x /= 10;
        }
        for (int i = 0; 2 * i < c - s; i++) {
            swap(buf[s + i], buf[c - 1 - i]);
        }
        buf[c] = 0;
        write_string(buf, c);
        if (sp)
            write_string(" ", 1);
    }

    void writeString(string s, bool space = true) {
        write_string(s.c_str(), s.size());
        if (space)
            write_string(" ", 1);
    }

    void writeEndl() {
        write_string("\n", 1);

        if (lflush)
            flush();

 
    }

    void flush() {
        fputs(obuf, stdout);
        ocur = 0;
        obuf[0] = 0;
    }

private:
    bool lflush;

public:

    FastIO(bool local_flush) { 
        obuf[0] = 0;
        lflush = local_flush;
    }
    
    ~FastIO() {
        fputs(obuf, stdout);
    }
};

FastIO<10000000, 10000000> IO(true);

template<class T>
class id4 {
    map<T, int> mp;
    int s = 0;
public:
    id4() {}
    void insert(T x) {
        mp[x]++;
        s++;
    }
    void erase(T x) {
        auto it = mp.find(x);
        it->second--;
        if (it->second == 0)
            mp.erase(it);
        s--;
    }
    size_t size() const {
        return s;
    }
    void clear() {
        *this = id4<T>();
    }
    T any() {
        return mp.begin()->first;
    }
    map<T, int>& access() {
        return mp;
    }
    int count(T x) {
        if (mp.count(x))
            return mp[x];
        return 0;
    }
};

class segment_tree {
    int n;
    vector<id4<int> > t;
    int update(int v, int L, int R, int i, int x) {
        if (R <= i || i < L)
            return -INF;
        else if (L == R - 1) {
            int ret = -INF;
            if (t[v].size())
                ret = t[v].any();
            t[v].clear();
            t[v].insert(x);
            return ret;
        } else {
            int rem = -INF;
            rem = max(rem, update(2 * v + 1, L, (L + R) >> 1, i, x));
            rem = max(rem, update(2 * v + 2, (L + R) >> 1, R, i, x));
            if (rem != -INF && t[v].count(rem))
                t[v].erase(rem);
            t[v].insert(x);
            return rem;
        }
    }
    int min_in_segment(int v, int L, int R, int l, int r, int a, int b) {
        if (R <= l || r <= L)
            return INF;
        else if (l <= L && R <= r) {
            auto it = t[v].access().lower_bound(a);
            return (it != t[v].access().end() && it->ff < b ? it->ff : INF);
        } else
            return min(min_in_segment(2 * v + 1, L, (L + R) >> 1, l, r, a, b),
                       min_in_segment(2 * v + 2, (L + R) >> 1, R, l, r, a, b));
    }
    int max_in_segment(int v, int L, int R, int l, int r, int a, int b) {
        if (R <= l || r <= L)
            return -INF;
        else if (l <= L && R <= r) {
            auto it = t[v].access().lower_bound(b);
            if (it != t[v].access().begin())
                return (prev(it)->ff >= a ? prev(it)->ff : -INF);
            else
                return -INF;
        } else
            return max(max_in_segment(2 * v + 1, L, (L + R) >> 1, l, r, a, b),
                       max_in_segment(2 * v + 2, (L + R) >> 1, R, l, r, a, b));
    }
    int erase(int v, int L, int R, int i) {
        if (L > i || R <= i)
            return -INF;
        else if (L == R - 1) {
            int ret = -INF;
            if (t[v].size())
                ret = t[v].access().begin()->ff;
            t[v].clear();
            return ret;
        } else {
            int rem = max(erase(2 * v + 1, L, (L + R) >> 1, i),
                          erase(2 * v + 2, (L + R) >> 1, R, i));
            if (rem != -INF)
                t[v].erase(rem);
            return rem;
        }
    }
public:
    segment_tree(int _n) {
        n = _n;
        t.resize(4 * n);
    }
    void update(int i, int x) {
        update(0, 0, n, i, x);
    }
    int min_in_segment(int l, int r, int a, int b) {
        if (l >= r)
            return INF;
        return min_in_segment(0, 0, n, l, r, a, b);
    }
    int max_in_segment(int l, int r, int a, int b) {
        if (l >= r)
            return -INF;
        return max_in_segment(0, 0, n, l, r, a, b);
    }
    void erase(int i) {
        

        erase(0, 0, n, i);
    }
};

class basic_tree {
protected:
    int n;
    vector<vector<int> > tree;
public:
    basic_tree(int _n = 0) {
        n = _n;
        tree.resize(n);
    }
    size_t size() const {
        return n;
    }
    void add_vertex() {
        n++;
        tree.pb(vector<int>());
    }
    virtual void add_edge(int u, int v) {
        tree[u].pb(v);
        tree[v].pb(u);
    }
    virtual void process() {}
};

class id1 : public basic_tree {
    int ct = 0;
    vector<int> _tin, _tout;
    vector<int> euler;
    void tdfs(int v, int par) {
        _tin[v] = ct++;
        euler.pb(v);
        for (int u : tree[v]) {
            if (u != par) {
                tdfs(u, v);
            }
        }
        _tout[v] = ct;
    }
protected:
    int rt;
public:
    id1(int _n = 0) : basic_tree(_n) {}
    virtual void process() {
        _tin.resize(n);
        _tout.resize(n);
        tdfs(rt, -1);
    }
    

    bool is_ancestor(int u, int v) {
        return tin(u) <= tin(v) && tin(v) < tout(u);
    }
    virtual void set_root(int v) {
        rt = v;
    }
    inline const int& tin(int v) const {
        return _tin[v];
    }
    inline const int& tout(int v) const {
        return _tout[v];
    }
    int operator[](const int & i) const {
        return euler[i];
    }
};

class id0 : public basic_tree {
protected:
    vector<int> sz;
    int rt;
private:
    void dfs(int v, int par) {
        sz[v] = 1;
        for (int u : tree[v])
            if (u != par) {
                dfs(u, v);
                sz[v] += sz[u];
            }
    }
public:
    id0(int _n = 0) : basic_tree(_n) {}
    virtual void process() {
        sz.resize(n);
        dfs(rt, -1);
    }
    virtual void set_root(int v) {
        rt = v;
    }
    int subtree_size(int v) const {
        return sz[v];
    }
};

class prob_G : public id1, public id0 {
    int & n;
    vector<vector<int> > & tree;
    int & rt;
    segment_tree cur;
    segment_tree parents;
    vector<int> csz;
    int min_in_subtree(int root, int v, int a, int b, int x) {
        if (is_ancestor(root, v))
            return min(cur.min_in_segment(tin(v) + 1, tout(v), a, b),
                       parents.min_in_segment(tin(v) + 1, tout(v), a - x, b - x) + x);
        else if (tin(v) == 0)
            return min(min(cur.min_in_segment(1, tin(root), a, b),
                           cur.min_in_segment(tout(root), n, a, b)),
                       min(parents.min_in_segment(1, tin(root), a - x, b - x) + x,
                           parents.min_in_segment(tout(root), n, a - x, b - x) + x));
        else {
            return min(min(cur.min_in_segment(0, tin(root), a, b),
                           cur.min_in_segment(tout(root), n, a, b)),
                       min(parents.min_in_segment(0, tin(root), a - x, b - x) + x,
                           parents.min_in_segment(tout(root), n, a - x, b - x) + x));
        }
    }
    int max_in_subtree(int root, int v, int a, int b, int x) {
        if (is_ancestor(root, v))
            return max(cur.max_in_segment(tin(v) + 1, tout(v), a, b),
                       parents.max_in_segment(tin(v) + 1, tout(v), a - x, b - x) + x);
        else if (tin(v) == 0)
            return max(max(cur.max_in_segment(1, tin(root), a, b),
                           cur.max_in_segment(tout(root), n, a, b)),
                       max(parents.max_in_segment(1, tin(root), a - x, b - x) + x,
                           parents.max_in_segment(tout(root), n, a - x, b - x) + x));
        else
            return max(max(cur.max_in_segment(0, tin(root), a, b),
                           cur.max_in_segment(tout(root), n, a, b)),
                       max(parents.max_in_segment(0, tin(root), a - x, b - x) + x,
                           parents.max_in_segment(tout(root), n, a - x, b - x) + x));
    }
    int gsz(int v) {
        return csz[tin(v)];
    }
    vector<int> st;
    void dfs(int v, int par) {
        st.pb(v);
        cur.erase(tin(v));
        parents.update(tin(v), sz[v]);
        for (int u : tree[v]) {
            if (u != par) {
                csz[tin(v)] = n - sz[u];
                dfs(u, v);
                csz[tin(v)] = sz[v];
            }
        }
        st.pop_back();
        cur.update(tin(v), sz[v]);
        parents.erase(tin(v));
        vector<int> children = tree[v];
        sort(all(children), [this](const int& i, const int& j) -> bool { return csz[tin(i)] < csz[tin(j)]; });
        
        if (children.empty())
            ans[v] = 0;
        else if (children.size() == 1 || gsz(children.back()) == gsz(children[children.size() - 2])) {
            ans[v] = gsz(children.back());
        } else {
            int midl = (gsz(children.back()) + gsz(children[0])) / 2;
            int midr = (gsz(children.back()) + gsz(children[0]) + 1) / 2;
            int x;
            ans[v] = gsz(children.back());
            if ((x = min_in_subtree(v, children.back(), gsz(children.back()) - midr, INF, -sz[v])) != INF) {
                ans[v] = min(ans[v], max(gsz(children[0]) + x,
                                         max(gsz(children.back()) - x,
                                             gsz(children[children.size() - 2]))));
            }
            if (abs(gsz(children[0]) + x - (gsz(children.back()) - x)) <= 1)
                return;
            

            if ((x = max_in_subtree(v, children.back(), -INF, gsz(children.back()) - midl, -sz[v])) != -INF) {
                ans[v] = min(ans[v], max(gsz(children[0]) + x,
                                         max(gsz(children.back()) - x,
                                             gsz(children[children.size() - 2]))));
            }
            

        }
    }
public:
    prob_G(int _n = 0) : id1(_n), id0(_n), n(id1::n), tree(id1::tree), rt(id1::rt), cur(_n), parents(_n) {}
    vector<int> ans;
    void process() {
        id1::process();
        id0::process();
        csz.resize(n);
        forn(i, n) {
            csz[tin(i)] = sz[i];
            cur.update(tin(i), sz[i]);
        }
        ans.resize(n);
        dfs(rt, -1);
    }
    void set_root(int v) {
        id1::set_root(v);
        id0::set_root(v);
    }
    void add_edge(int u, int v) {
        id1::add_edge(u, v);
        id0::add_edge(u, v);
    }
};

int main() {
    

   
    int n = IO.readInt<int>();
    prob_G G(n);
    forn(i, n) {
        int u = IO.readInt<int>();
        int v = IO.readInt<int>();
        if (u == 0) {
            G.set_root(v - 1);
            continue;
        }
        u--; v--;
        G.add_edge(u, v);
    }

    G.process();
    for (int x : G.ans)
        IO.writeInt(x);
    IO.writeEndl();

    return 0;
}

