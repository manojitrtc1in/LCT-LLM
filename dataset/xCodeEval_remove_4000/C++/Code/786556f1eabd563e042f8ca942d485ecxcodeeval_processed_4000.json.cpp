



















using namespace std;
using ll = long long;
using ld = long double;
[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
template <class C> int sz(const C& c) { return int(::size(c)); }




    do { if (!(expr)) { \
        ::cerr << "assertion failed: " << 
        ::abort(); \
    } } while (0)






struct identity { template <class T> constexpr T&& operator()(T&& t) const noexcept { return forward<T>(t); }; };
template <class T> using remove_cvref_t = remove_cv_t<remove_reference_t<T>>;


namespace cp_lib_type_meta {
    struct NoOp { template <class... Args> void operator()(Args&&...) const noexcept {} };
    template <class T, class = void> constexpr bool id16 = false;
    template <class T> constexpr bool id16<T, void_t<tuple_element_t<0, T>>> = true;
}


namespace cp_lib_modint { struct ModIntTag {}; }


namespace cp_lib_io {
    constexpr int BUF_SIZE = 1 << 20;
    constexpr array<array<char, 4>, 10'000> DIGITS = []{
        array<array<char, 4>, 10'000> digits{};
        for (int i = 3, d = 1; i >= 0; --i, d *= 10)
            rep(j, 10'000)
                digits[j][i] = char('0' + j / d % 10);
        return digits;
    }();
    array<char, BUF_SIZE> ibuf, obuf;
    char *iptr = data(ibuf), *iend = iptr, *optr = data(obuf);

    template <class T> constexpr bool id17 = false;
    template <class T, size_t I> constexpr bool id17<array<T, I>> = true;

    void flush() {
        for (auto* p = begin(obuf); p != optr; p += write(STDOUT_FILENO, p, optr - p));
        optr = begin(obuf);
    }
    int id4 = []{ atexit(flush); return 0; }();

    void refill() {
        memmove(begin(ibuf), iptr, iend - iptr);
        iend -= iptr - begin(ibuf);
        iptr = begin(ibuf);
        iend += read(STDIN_FILENO, iend, end(ibuf) - 1 - iend);
        *iend = '\0';
    }

    template <class T, class T2 = remove_reference_t<remove_cv_t<T>>>
    void print(T&& val) {
        if (end(obuf) - optr < 64)
            flush();

        if constexpr (is_same_v<T2, char>)
            *optr++ = val;
        else if constexpr (is_same_v<T2, bool> || is_same_v<T2, vector<bool>::reference>)
            return print(int(val));
        else if constexpr (is_integral_v<T2> && is_signed_v<T2>) {
            if (val < 0)
                *optr++ = '-';
            using U = make_unsigned_t<T2>;
            return print(U(val < 0 ? -U(val) : U(val)));
        } else if constexpr (is_integral_v<T2> && is_unsigned_v<T2>) {
            T2 val2 = val;
            array<char, 64> tmp;
            char* tptr = end(tmp);
            while (val2 >= 10'000)
                tptr -= 4, memcpy(tptr, &DIGITS[val2 % 10'000][0], 4), val2 /= T2(10'000);
            int d = (val2 >= 100 ? (val2 >= 1000 ? 4 : 3) : (val2 >= 10 ? 2 : 1));
            memcpy(optr, &DIGITS[val2][4 - d], d);
            memcpy(optr + d, tptr, end(tmp) - tptr);
            optr += d + int(end(tmp) - tptr);
        } else if constexpr (is_floating_point_v<T2>)
            optr += sprintf(optr, "%.30Lf", (long double)val);
        else if constexpr (is_convertible_v<T, string_view>) {
            string_view sv(val);
            if (sz(sv) + 1 <= end(obuf) - optr)
                memcpy(optr, data(sv), sz(sv)), optr += sz(sv);
            else {
                flush();
                for (auto *p = data(sv), *pe = p + sz(sv); p != pe; p += write(STDOUT_FILENO, p, pe - p));
            }
        } else if constexpr (is_base_of_v<cp_lib_modint::ModIntTag, T2>)
            return print(decltype(T2::mod())(val));
        else if constexpr (cp_lib_type_meta::id16<T2> && !id17<T2>)
            return apply([](auto&&... items) { (print(items), ...); }, forward<T>(val));
        else {
            trav(item, val)
                print(item);
            return;
        }
        *optr++ = ' ';
    }

    template <class T>
    void read(T& val) {
        do {
            for (; iptr != iend && *iptr <= ' '; ++iptr);
            if (iend - iptr < 64)
                refill();
        } while (*iptr <= ' ');

        auto read_other = [&](auto other) {
            read(other);
            return other;
        };

        if constexpr (is_same_v<T, char>)
            val = *iptr++;
        else if constexpr (is_same_v<T, bool> || is_same_v<T, vector<bool>::reference>) {
            val = bool(read_other(uint8_t()));
        } else if constexpr (is_base_of_v<cp_lib_modint::ModIntTag, T>) {
            val = T(read_other(ll()));
        } else if constexpr (is_integral_v<T>) {
            if (is_signed_v<T> && *iptr == '-')
                ++iptr, val = T(-read_other(make_unsigned_t<T>()));
            else
                for (val = 0; iptr != iend && *iptr > ' '; val = T(10 * val + (*iptr++ & 15)));
        } else if constexpr (is_floating_point_v<T>)
            val = T(strtold(iptr, &iptr));
        else if constexpr (is_same_v<T, string>) {
            val.clear();
            do {
                auto* after = find_if(iptr, iend, [](char c) { return c <= ' '; });
                val.append(iptr, after);
                if ((iptr = after) != iend)
                    break;
                refill();
            } while (iptr != iend);
        } else if constexpr (cp_lib_type_meta::id16<T> && !id17<T>)
            apply([](auto&... items) { (read(items), ...); }, val);
        else
            trav(item, val)
                read(item);
    }
}

using cp_lib_io::flush;

template <class... Args>
void print(Args&&... args) { (cp_lib_io::print(forward<Args>(args)), ...); }

template <class... Args>
void println(Args&&... args) {
    if (sizeof...(Args))
        (cp_lib_io::print(forward<Args>(args)), ...), *(cp_lib_io::optr - 1) = '\n';
    else
        print('\n'), --cp_lib_io::optr;
}

template <class... Args>
void read(Args&... args) { (cp_lib_io::read(args), ...); }



template <class A, class M>
struct Graph {
    const A& adj;
    int n;
    M map;

    Graph(const A& adj_, int n_, M&& map_) : adj{adj_}, n{n_}, map{forward<M>(map_)} {}
    Graph(const A& adj_, M&& map_) : adj{adj_}, n{sz(adj)}, map{forward<M>(map_)} {}
    Graph(const A& adj_, int n_) : adj{adj_}, n{n_}, map{identity{}} {}
    explicit Graph(const A& adj_) : adj{adj_}, n{sz(adj)}, map{identity{}} {}
};

template <class A> Graph(const A&, int) -> Graph<A, identity>;
template <class A> Graph(const A&) -> Graph<A, identity>;

struct id5 {
 private:
    vector<int> size, depth, parent, top, idx, stack;

    template <bool Edges, class F>
    void decomp(int u, int v, F&& f) const {
        for (; top[u] != top[v]; v = parent[top[v]]) {
            if (depth[top[u]] > depth[top[v]]) swap(u, v);
            f(idx[top[v]] - Edges, idx[v] + !Edges);
        }
        f(min(idx[u], idx[v]), max(idx[u], idx[v]) + !Edges);
    }

    template <bool Edges, class F>
    void id0(int u, int v, F&& f) {
        while (top[u] != top[v]) {
            if (depth[top[u]] > depth[top[v]])
                f(idx[top[u]] - Edges, idx[u] + !Edges, true), u = parent[top[u]];
            else
                stack.push_back(v), v = parent[top[v]];
        }
        f(min(idx[u], idx[v]), max(idx[u], idx[v]) + !Edges, depth[u] > depth[v]);
        while (sz(stack))
            f(idx[top[stack.back()]] - Edges, idx[stack.back()] + !Edges, false), stack.pop_back();
    }

 public:
    template <class G>
    id5(G&& graph, int root) {
        auto [adj, n, to] = Graph(forward<G>(graph));
        size = parent = top = depth = idx = vector(n, 0);
        top[root] = parent[root] = root;
        auto dfs_size = [&, &adj=adj, &to=to](int v, auto&& self) -> void {
            size[v] = 1;
            trav(e, adj[v])
                if (to(e) != parent[v])
                    depth[to(e)] = depth[v] + 1, parent[to(e)] = v, self(to(e), self), size[v] += size[to(e)];
        };
        dfs_size(root, dfs_size);

        auto id3 = [&, t=0, &adj=adj, &to=to](int v, auto&& self) mutable -> void {
            idx[v] = t++;
            auto id10 = find_if(all(adj[v]), [&](auto& e) {
                return to(e) != parent[v] && 2 * size[to(e)] > size[v];
            });
            if (id10 != end(adj[v]))
                top[to(*id10)] = top[v], self(to(*id10), self);
            for (auto it = begin(adj[v]); it != end(adj[v]); ++it)
                if (it != id10 && to(*it) != parent[v])
                    top[to(*it)] = to(*it), self(to(*it), self);
        };
        id3(root, id3);
    }

    int node(int v) const { return idx[v]; }
    int edge(int u, int v) const { return max(idx[u], idx[v]) - 1; }
    pair<int, int> subtree(int v) const { return {idx[v], idx[v] + size[v]}; }
    pair<int, int> subtree_edges(int v) const { return {idx[v], idx[v] + size[v] - 1}; }

    template <class F> void decompose(int u, int v, F&& f) const { decomp<false>(u, v, forward<F>(f)); }
    template <class F> void id18(int u, int v, F&& f) const { decomp<true>(u, v, forward<F>(f)); }
    template <class F> void id14(int u, int v, F&& f) { id0<false>(u, v, forward<F>(f)); }
    template <class F> void id22(int u, int v, F&& f) { id0<true>(u, v, forward<F>(f)); }

    int lca(int u, int v) const {
        for (; top[u] != top[v]; v = parent[top[v]])
            if (depth[top[u]] > depth[top[v]]) swap(u, v);
        return depth[u] < depth[v] ? u : v;
    }
};


template <class It, class ItEnd>
vector<int> suffix_array(It it, ItEnd it_end, int alph) {
    int n = int(it_end - it);
    if (n <= 1)
        return vector(n, 0);
    if (n == 2)
        return {(it[0] >= it[1]), (it[0] < it[1])};

    vector sa(n, 0);
    if (n < 10) {
        iota(all(sa), 0);
        sort(all(sa), [&](int i, int j) {
            return lexicographical_compare(it + i, it_end, it + j, it_end);
        });
        return sa;
    }
    if (n < 40) {
        vector<int> rnk(it, it_end), id21(n, 0);
        iota(all(sa), 0);
        for (int w = 1; w < n; w *= 2) {
            auto rnks = [&](int i) { return pair(rnk[i], (i + w < n ? rnk[i + w] : -1)); };
            auto cmp = [&](int i, int j) { return rnks(i) < rnks(j); };
            sort(all(sa), cmp);
            id21[sa[0]] = 0;
            rep(i, 1, n)
                id21[sa[i]] = id21[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
            swap(rnk, id21);
        }
        return sa;
    }

    vector is_s(n, false);
    repr(i, n - 2)
        is_s[i] = (it[i] < it[i + 1] || (it[i] == it[i + 1] && is_s[i + 1]));

    vector head(alph + 1, 0), tail(alph + 1, 0);
    rep(i, n)
        ++head[it[i] + 1], tail[it[i]] += !is_s[i];
    partial_sum(all(head), begin(head));
    rep(i, alph + 1)
        tail[i] += head[i];

    vector tmp(alph + 1, 0);
    auto induce = [&](const vector<int>& lms) {
        fill(all(sa), -1);
        copy(all(tail), begin(tmp));
        trav(i, lms)
            sa[tmp[it[i]]++] = i;

        copy(all(head), begin(tmp));
        sa[tmp[it[n - 1]]++] = n - 1;
        rep(i, n)
            if (int j = sa[i]; j > 0 && !is_s[j - 1])
                sa[tmp[it[j - 1]]++] = j - 1;

        copy(all(head), begin(tmp));
        repr(i, n - 1)
            if (int j = sa[i]; j > 0 && is_s[j - 1])
                sa[--tmp[it[j - 1] + 1]] = j - 1;
    };

    vector id11(n, -1), lms(0, 0);
    rep(i, 1, n)
        if (is_s[i] && !is_s[i - 1])
            id11[i] = sz(lms), lms.push_back(i);
    induce(lms);

    if (sz(lms)) {
        vector s2(sz(lms), 0), id6(0, 0);
        trav(i, sa)
            if (id11[i] != -1)
                id6.push_back(i);

        int alph2 = 0;
        rep(i, 1, sz(lms)) {
            int a = id6[i - 1], b = id6[i];
            alph2 += !equal(it + a, it + (id11[a] + 1 == sz(lms) ? n : lms[id11[a] + 1]),
                            it + b, it + (id11[b] + 1 == sz(lms) ? n : lms[id11[b] + 1]));
            s2[id11[b]] = alph2;
        }

        auto sa2 = suffix_array(all(s2), alph2 + 1);
        rep(i, sz(lms))
            id6[i] = lms[sa2[i]];
        induce(id6);
    }

    return sa;
}


template <class ItS, class ItSEnd, class ItSa, class ItSaEnd>
array<vector<int>, 2> id9(ItS it_s, ItSEnd id7, ItSa it_sa,
                                [[maybe_unused]] ItSaEnd id8) {
    int n = int(id7 - it_s);
    cp_lib_assert(int(id8 - it_sa) == n);
    vector lcp(n - 1, 0), rank(n, 0);
    rep(i, n)
        rank[it_sa[i]] = i;

    for (int i = 0, k = 0; i < n; ++i, k = max(0, k - 1)) {
        if (rank[i] < n - 1) {
            auto it_i = it_s + i, it_j = it_s + it_sa[rank[i] + 1];
            lcp[rank[i]] = k = int(mismatch(it_i + k, id7, it_j + k, id7).first - it_i);
        } else
            k = 0;
    }

    return {move(lcp), move(rank)};
}


template <class T> constexpr inline bool id1(T n) { return n && !(n & (n - 1)); }
template <class T> constexpr inline int id12(T n) { return n ? 63 - __builtin_clzll(n) : 0; }
template <class T> constexpr inline int id20(T n) { return n ? id12(n) + !id1(n) : 0; }

namespace cp_lib_rmq {
    template <class T, bool Max> T minmax(T a, T b) { return (a < b) ^ Max ? a : b; }
}

template <class T, T (*Combine)(T, T)>
struct SparseTable {
    vector<vector<T>> d = {};

    SparseTable() = default;
    explicit SparseTable(const vector<T>& v) {
        int n = sz(v), k = id12(n);
        d.assign(k + 1, v);
        rep(i, k) rep(j, n)
            d[i + 1][j] = Combine(d[i][j], d[i][min(j + (1 << i), n - 1)]);
    }

    

    T query(int l, int r) const {
        int k = id12(r - l);
        return Combine(d[k][l], d[k][r - (1 << k)]);
    }
};

template <class T>
using Rmq = SparseTable<T, cp_lib_rmq::minmax<T, false>>;
template <class T>
using Rmaxq = SparseTable<T, cp_lib_rmq::minmax<T, true>>;


template <class T, class Add = plus<>, class Sub = minus<>>
class id24 {
    T identity;
    Add add;
    Sub sub;
    vector<T> d;

 public:
    id24(int n, T identity_, Add add_ = Add(), Sub sub_ = Sub())
        : identity(move(identity_)), add(move(add_)), sub(move(sub_)), d(n, identity) {}

    id24(vector<T> a, T identity_ = T(), Add add_ = Add(), Sub sub_ = Sub())
        : identity(move(identity_)), add(move(add_)), sub(move(sub_)), d(move(a)) {
        partial_sum(all(d), begin(d), add);
        repr(i, sz(d), 1)
            if (i & (i - 1))
                d[i - 1] = sub(d[i - 1], d[(i & (i - 1)) - 1]);
    }

    template <class It, class ItEnd>
    id24(It it, ItEnd it_end, T identity_ = T(), Add add_ = Add(), Sub sub_ = Sub())
        : id24(vector(it, it_end), move(identity_), move(add_), move(sub_)) {}

    T query(int r) const {
        T res = identity;
        for (; r; r &= r - 1)
            res = add(res, d[r - 1]);
        return res;
    }
    T query(int l, int r) const { return sub(query(r), query(l)); }

    template <class F>
    int lower_bound(F&& f) const {
        int i = 0, j = (1 << id12(sz(d)));
        for (T pref = identity, pref2; j; j >>= 1)
            if (i + j <= sz(d) && !f(pref2 = add(pref, d[i + j - 1])))
                pref = move(pref2), i += j;
        return i;
    }

    void update(int i, T v) {
        for (; i < sz(d); i |= i + 1)
            d[i] = add(d[i], v);
    }
};

template <class It, class ItEnd>
id24(It, ItEnd) -> id24<typename iterator_traits<It>::value_type, plus<>, minus<>>;

int main() {
    int n, m, q; read(n, m, q);
    vector adj(n, vector<pair<int, char>>());
    vector edge(n - 1, tuple(0, 0, ' '));
    rep(i, n - 1) {
        int u, v; char c; read(u, v, c); --u, --v;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
        edge[i] = {u, v, c};
    }

    string s, stmp;
    vector<int> id23;
    rep(i, m) {
        read(stmp);
        id23.push_back(sz(stmp));
        s.append(stmp);
        s.push_back(char('a' - 1));
    }

    int k = sz(s);
    s.resize(k + 2 * (n - 1));
    id5 hld(Graph(adj, [&](auto& p) { return p.first; }), 0);
    for (auto [u, v, c] : edge) {
        int i = hld.edge(u, v);
        s[k + i] = c;
        s[sz(s) - 1 - i] = c;
    }

    auto sa = suffix_array(all(s), 'z' + 1);
    auto [lcp_arr, rank] = id9(all(s), all(sa));
    Rmq<int> id19(lcp_arr);

    vector qs(m, vector<array<int, 4>>());
    rep(q_idx, q) {
        int u, v, l, r; read(u, v, l, r); --u, --v, --l;
        vector<tuple<int, int, bool>> paths;
        hld.id22(u, v, [&](int id13, int id15, bool rev) {
            paths.emplace_back(id13, id15, rev);
        });

        auto id2 = [&, &rank=rank](int i) {
            for (auto [id13, id15, rev] : paths) {
                if (i == sz(s))
                    return pair(true, false);

                int path_len = id15 - id13;
                int l_s = (rev ? sz(s) - id15 : k + id13);
                auto [l_sa, r_sa] = minmax(rank[i], rank[l_s]);
                int lcp = (l_sa == r_sa ? sz(s) - l_s : id19.query(l_sa, r_sa));

                if (lcp < path_len) {
                    if (i + lcp == sz(s))
                        return pair(true, false);
                    return pair(s[i + lcp] < s[l_s + lcp], false);
                }

                i += path_len;
            }

            return pair(false, true);
        };

        auto it_l = partition_point(all(sa), [&](int i) {
            auto [is_less, _] = id2(i);
            return is_less;
        });
        auto it_r = partition_point(all(sa), [&](int i) {
            auto [is_less, is_equal] = id2(i);
            return is_less || is_equal;
        });

        if (l)
            qs[l - 1].push_back({int(it_l - begin(sa)), int(it_r - begin(sa)), q_idx, -1});
        qs[r - 1].push_back({int(it_l - begin(sa)), int(it_r - begin(sa)), q_idx, 1});
    }

    id24 ft(sz(sa), 0);
    int len_before = 0;
    vector ans(q, 0);
    rep(i, m) {
        rep(j, id23[i])
            ft.update(rank[len_before + j], 1);
        len_before += id23[i] + 1;

        for (auto [l_sa, r_sa, q_idx, factor] : qs[i])
            ans[q_idx] += factor * ft.query(l_sa, r_sa);
    }

    trav(i, ans)
        println(i);
}
