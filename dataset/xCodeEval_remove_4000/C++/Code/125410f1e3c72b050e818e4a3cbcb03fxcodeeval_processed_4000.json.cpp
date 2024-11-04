




using ll = int64_t;

using namespace std;

template <class T>
auto compress(const vector<T>& a) {
    int n = size(a);
    vector<pair<T, int>> p(n);
    for (int i = 0; i < n; ++i) p[i] = {a[i], i};
    sort(begin(p), end(p));
    vector<int> compressed(n);
    vector<T> vals;
    for (int k = 0, rnk = -1; k < n; ++k) {
        if (k == 0 or p[k - 1].first < p[k].first)
            vals.push_back(p[k].first), ++rnk;
        compressed[p[k].second] = rnk;
    }
    return make_pair(compressed, vals);
}

namespace IO {
    constexpr bool UNSAFE = false;
    constexpr int id6 = 1 << 15;

    
    static struct FastInput {
        FastInput() {
            if constexpr (UNSAFE) {
                chars_read = fread(buf, 1, BUF_SIZE, in);
                buf_pos = 0;
                buf[0] = (chars_read == 0 ? -1 : buf[0]);
            }
        }
        static constexpr int BUF_SIZE = id6;
        char buf[BUF_SIZE];
        size_t chars_read = 0;
        size_t buf_pos = 0;
        FILE* in = stdin;
        char cur = 0;
        inline char get_char() {
            if constexpr (!UNSAFE) {
                if (buf_pos >= chars_read) {
                    chars_read = fread(buf, 1, BUF_SIZE, in);
                    buf_pos = 0;
                    buf[0] = (chars_read == 0 ? -1 : buf[0]);
                }
            }
            return cur = buf[buf_pos++];
        }
        template <typename T>
        inline FastInput* tie(T) { return this; }
        inline void sync_with_stdio(bool) {}
        inline explicit operator bool() { return cur != -1; }
        inline static bool is_blank(char c) { return c <= ' '; }
        inline bool skip_blanks() {
            while (is_blank(cur) && cur != -1) get_char();
            return cur != -1;
        }
        inline FastInput& operator>>(char& c) {
            skip_blanks();
            c = cur;
            return *this;
        }
        inline FastInput& operator>>(std::string& s) {
            if (skip_blanks()) {
                s.clear();
                do {
                    s += cur;
                } while (!is_blank(get_char()));
            }
            return *this;
        }
        template <typename T>
        inline FastInput& read_integer(T& n) {
            

            n = 0;
            if (skip_blanks()) {
                int sign = +1;
                if (cur == '-') {
                    sign = -1;
                    get_char();
                }
                do {
                    n += n + (n << 3) + cur - '0';
                } while (!is_blank(get_char()));
                n *= sign;
            }
            return *this;
        }
        template <typename T>
        inline typename std::enable_if<std::is_integral<T>::value,
                                       FastInput&>::type
        operator>>(T& n) {
            return read_integer(n);
        }
    
        inline FastInput& operator>>(__int128& n) { return read_integer(n); }
    
        template <typename T>
        inline typename std::enable_if<std::is_floating_point<T>::value,
                                       FastInput&>::type
        operator>>(T& n) {
            

            n = 0;
            if (skip_blanks()) {
                std::string s;
                (*this) >> s;
                sscanf(s.c_str(), "%lf", &n);
            }
            return *this;
        }
    } fast_input;
    
    static struct FastOutput {
        static constexpr int BUF_SIZE = id6;
        char buf[BUF_SIZE];
        size_t buf_pos = 0;
        static constexpr int TMP_SIZE = id6;
        char tmp[TMP_SIZE];
        FILE* out = stdout;
        inline void put_char(char c) {
            buf[buf_pos++] = c;
            if (buf_pos == BUF_SIZE) {
                fwrite(buf, 1, buf_pos, out);
                buf_pos = 0;
            }
        }
        ~FastOutput() { fwrite(buf, 1, buf_pos, out); }
        inline FastOutput& operator<<(char c) {
            put_char(c);
            return *this;
        }
        inline FastOutput& operator<<(const char* s) {
            while (*s) put_char(*s++);
            return *this;
        }
        inline FastOutput& operator<<(const std::string& s) {
            for (auto x : s) put_char(x);
            return *this;
        }
        template <typename T>
        inline char* id4(T n) {
            

            char* p = tmp + TMP_SIZE - 1;
            if (n == 0)
                *--p = '0';
            else {
                bool is_negative = false;
                if (n < 0) {
                    is_negative = true;
                    n = -n;
                }
                while (n > 0) {
                    *--p = (char)('0' + n % 10);
                    n /= 10;
                }
                if (is_negative) *--p = '-';
            }
            return p;
        }
        template <typename T>
        inline typename std::enable_if<std::is_integral<T>::value, char*>::type
        stringify(T n) {
            return id4(n);
        }
    
        inline char* stringify(__int128 n) { return id4(n); }
    
        template <typename T>
        inline typename std::enable_if<std::is_floating_point<T>::value,
                                       char*>::type
        stringify(T n) {
            sprintf(tmp, "%.17f", n);
            return tmp;
        }
        template <typename T>
        inline FastOutput& operator<<(const T& n) {
            auto p = stringify(n);
            for (; *p != 0; p++) put_char(*p);
            return *this;
        }
    } fast_output;
    

}  




template <class Base,
          class Node,
          class Update,
          class MakeNode,
          class CombineNodes,
          class ApplyUpdate,
          class ComposeUpdates = std::nullptr_t>
struct id8 {
    static constexpr bool is_lazy =
        !std::is_same<ComposeUpdates, std::nullptr_t>::value;

   public:
    template <typename... T>
    explicit id8(int n, const Base& id_base, T... args)
        : id8(std::vector<Base>(n, id_base), args...) {}
    explicit id8(const std::vector<Base>& v,
                          const Node& _id_node,
                          const MakeNode& _make_node,
                          const CombineNodes& _combine,
                          const Update& _id_update,
                          const ApplyUpdate& _apply_update,
                          const ComposeUpdates& id0 = nullptr)
        : _n(int(v.size())),
          make_node(_make_node),
          combine(_combine),
          id_node(_id_node),
          apply_update(_apply_update),
          id_update(_id_update),
          compose_updates(id0) {
        build(v);
    }

    void build(const std::vector<Base>& v) {
        _n = int(v.size());
        log = 0;
        while ((1 << log) < _n) ++log;
        size = 1 << log;
        d = std::vector<Node>(2 * size, id_node);
        if constexpr (is_lazy) lz = std::vector<Update>(size, id_update);
        for (int i = 0; i < _n; i++) d[size + i] = make_node(v[i], i);
        for (int i = size - 1; i >= 1; i--) update(i);
    }
    
    void set(int p, Node x) {
        p += size;
        if constexpr (is_lazy)
            for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; ++i) update(p >> i);
    }

    Node get(int p) {
        p += size;
        if constexpr (is_lazy)
            for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    Node query(int l, int r) {
        if (l == r) return id_node;
        l += size, r += size;
        if constexpr (is_lazy) {
            int id5 = __builtin_ctz(l);
            int id7 = __builtin_ctz(r);
            for (int i = log; i > id5; --i) push(l >> i);
            for (int i = log; i > id7; --i) push((r - 1) >> i);
        }
        Node sml = id_node, smr = id_node;
        while (l < r) {
            if (l & 1) sml = combine(sml, d[l++]);
            if (r & 1) smr = combine(d[--r], smr);
            l >>= 1, r >>= 1;
        }
        return combine(sml, smr);
    }
    
    Node all_query() const { return d[1]; }
    
    void update(int p, Update f) {
        p += size;
        if constexpr (is_lazy)
            for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = apply_update(f, d[p]);
        for (int i = 1; i <= log; ++i) update(p >> i);
    }
    
    void update(int l, int r, Update f) {
        if (l == r) return;
        l += size, r += size;
        const int id5 = __builtin_ctz(l);
        const int id7 = __builtin_ctz(r);
        if constexpr (is_lazy) {
            for (int i = log; i > id5; --i) push(l >> i);
            for (int i = log; i > id7; --i) push((r - 1) >> i);
        }
        {
            const int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1, r >>= 1;
            }
            l = l2, r = r2;
        }
        for (int i = id5 + 1; i <= log; ++i) update(l >> i);
        for (int i = id7 + 1; i <= log; ++i) update((r - 1) >> i);
    }

    template <class G>
    int max_right(int l, G g) {
        

        

        if (l == _n) return _n;
        l += size;
        if constexpr (is_lazy)
            for (int i = log; i >= 1; i--) push(l >> i);
        Node sm = id_node;
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(combine(sm, d[l]))) {
                while (l < size) {
                    if constexpr (is_lazy) push(l);
                    l = (2 * l);
                    if (g(combine(sm, d[l]))) {
                        sm = combine(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = combine(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <class G>
    int min_left(int r, G g) {
        

        

        if (r == 0) return 0;
        r += size;
        if constexpr (is_lazy)
            for (int i = log; i >= 1; i--) push((r - 1) >> i);
        Node sm = id_node;
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(combine(d[r], sm))) {
                while (r < size) {
                    if constexpr (is_lazy) push(r);
                    r = (2 * r + 1);
                    if (g(combine(d[r], sm))) {
                        sm = combine(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = combine(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

   private:
    int _n, size, log;
    std::vector<Node> d;
    std::vector<Update> lz;
    MakeNode make_node;
    CombineNodes combine;
    Node id_node;
    ApplyUpdate apply_update;
    Update id_update;
    ComposeUpdates compose_updates;

    void update(int k) { d[k] = combine(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, Update f) {
        d[k] = apply_update(f, d[k]);
        if constexpr (is_lazy)
            if (k < size) lz[k] = compose_updates(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id_update;
    }
};



int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int test = 1; test <= t; test++) {
        

        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        vector<int> id2(n, n);
        vector<int> id9(n, n);
        stack<int> s;
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && a[s.top()] < a[i]) s.pop();
            if (!s.empty()) id2[i] = s.top();
            s.push(i);
        }
        stack<int>().swap(s);
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && a[s.top()] > a[i]) s.pop();
            if (!s.empty()) id9[i] = s.top();
            s.push(i);
        }
        vector<int> closest_ge(n, n);
        vector<int> closest_le(n, n);
        const auto rec = [&](const auto& self, int l, int r) -> void {
            if (l >= r) return;
            int m = (l + r + 1) / 2;
            if (l < m - 1) self(self, l, m - 1);
            if (m < r) self(self, m, r);
            vector<int> temp(a.begin() + l, a.begin() + r + 1);
            auto [compressed, vals] = compress(temp);
            int sz = temp.size();
            vector<int> id3(sz, n);
            vector<int> id1(sz, n);
            for (int i = m; i <= r; ++i) {
                int loc =
                    lower_bound(begin(vals), end(vals), a[i]) - begin(vals);
                id3[loc] = min(id3[loc], id9[i]);
                id1[loc] = min(id1[loc], id2[i]);
            }
            for (int i = 1; i < sz; ++i)
                id3[i] = min(id3[i], id3[i - 1]);
            for (int i = sz - 2; i >= 0; --i)
                id1[i] = min(id1[i], id1[i + 1]);
            for (int i = l; i < m; ++i) {
                int loc =
                    lower_bound(begin(vals), end(vals), a[i]) - begin(vals);
                closest_le[i] = min(closest_le[i], id3[loc]);
                closest_ge[i] = min(closest_ge[i], id1[loc]);
            }
        };
        rec(rec, 0, n - 1);
        ll ans = 0;

        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) v[i] = {closest_le[i], closest_ge[i]};
        using Base = pair<int, int>;
        struct Node {
            int le, ge;
        };
        const Node id_node = Node{n, n};
        auto make_node = [](const Base& b, int i) {
            return Node{b.first, b.second};
        };
        auto combine = [](const Node& n, const Node& m) {
            return Node{min(n.le, m.le), min(n.ge, m.ge)};
        };
        using Update = int;
        const Update id_update = 0;
        auto apply_update = [](const Update& u, const Node& n) {
            return n;
        };
        id8 st(v, id_node, make_node, combine, id_update,
                        apply_update);
        int r = 0;
        for (int i = 0; i < n; ++i) {
            while (r < n) {
                auto nd = st.query(i, r);
                if (!(nd.le > r && nd.ge > r)) break;
                ++r;
            }
            ans += r - i;
        }
        cout << ans << '\n';
    }
}