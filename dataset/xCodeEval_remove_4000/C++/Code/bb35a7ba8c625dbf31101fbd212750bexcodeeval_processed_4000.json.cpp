
using namespace std;
























using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdd = vector<pdd>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace __input {
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) {
        re(first); re(rest...);
    }

    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { id3(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { id3(i,SZ) re(a[i]); }
}
using namespace __input;

namespace __output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
        pr(first); pr(rest...);
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{",x.f,", ",x.s,"}");
    }
    template<class T, bool pretty = true> void prContain(const T& x) {
        if (pretty) pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?pretty?", ":" ":"",a), fst = 0;
        if (pretty) pr("}");
    }
    template<class T> void pc(const T& x) { prContain<T, false>(x); pr("\n"); }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }

    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) {
        pr(first); ps();
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {
        pr(first," "); ps(rest...);
    }
}
using namespace __output;





namespace __algorithm {
    template<typename T> void dedup(vector<T>& v) {
        sort(all(v)); v.erase(unique(all(v)), v.end());
    }
    template<typename T> typename vector<T>::const_iterator find(const vector<T>& v, const T& x) {
        auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end();
    }
    template<typename T> size_t index(const vector<T>& v, const T& x) {
        auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin();
    }

    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator lower_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return lower_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator upper_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return upper_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
}
using namespace __algorithm;

struct __monostate {
    friend istream& operator>>(istream& is, const __attribute__((unused))__monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const __attribute__((unused))__monostate& ms) { return os; }
} ms;

namespace __io {
    FILE* setIn(string s) { return freopen(s.c_str(),"r",stdin); }
    FILE* setOut(string s) { return freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;





struct id4 {
    int SZ;
    vector<int> pattern;
    vector<int> suffix_link;

    size_t append(int matched, int c) const {
        while (matched > 0 && pattern[matched] != c)
            matched = suffix_link[matched];
        return matched + int(pattern[matched] == c);
    }

    id4() : SZ(0) { }

    template<typename I>
    id4(I begin, I end) { initialize(begin, end); }

    template<typename I>
    void initialize(I begin, I end) {
        pattern.resize(end - begin);
        copy(begin, end, pattern.begin());
        SZ = int(pattern.size());
        suffix_link.assign(SZ + 1, 0);
        for (int matched = 1; matched < SZ; matched++)
            suffix_link[matched + 1] = append(suffix_link[matched], pattern[matched]);
    }

    template<typename I, typename F>
    void find_matches(I begin, I end, F consume) const {
        int i = 0;
        int matched = 0;
        for (I iter = begin; iter != end; iter++, i++) {
            matched = append(matched, *iter);
            if (matched == SZ) {
                consume(i - SZ + 1);
                matched = suffix_link[matched];
            }
        }
    }

    template<typename I>
    int count_matches(I begin, I end) const {
        int count = 0;
        find_matches(begin, end, [&](int i) { count++; });
        return count;
    }

    template<typename I>
    vector<int> id7(I begin, I end) const {
        vector<int> indices;
        find_matches(begin, end, [&](int i) { indices.push_back(i); });
        return indices;
    }
};





vector<int> id10;
vector<int> length_order;
template<int MIN_CHAR, int SIGMA>
struct id5 {
    struct state {
        int len = 0;
        int suffix_link = -1;
        

        array<int, SIGMA> transitions;
        state() { transitions.fill(-1); }
    };

    int SZ, last;
    vector<state> data;
    vector<bool> is_clone;

    const state& operator [] (int loc) const { return data[loc]; }

    int create_state(state s = {}) {
        data.push_back(s);
        is_clone.push_back(s.len != 0);
        return int(data.size()) - 1;
    }

    id5() : SZ(0) { last = create_state(); }

    template<typename I>
    id5(I begin, I end) {
        initialize(begin, end);
    }

    template<typename I>
    void initialize(I begin, I end) {
        SZ = 0;
        data.clear();
        is_clone.clear();
        last = create_state();

        for (I iter = begin; iter != end; iter++)
            __append(*iter);
        __initialize_auxiliary_data();
    }

    void __append(int c) {
        assert(MIN_CHAR <= c && c < MIN_CHAR + SIGMA);
        c -= MIN_CHAR;

        int p = last;

        last = create_state();
        

        data[last].len = ++SZ;

        while (p != -1 && data[p].transitions[c] == -1) {
            data[p].transitions[c] = last;
            p = data[p].suffix_link;
        }

        if (p == -1) {
            data[last].suffix_link = 0;
            return;
        }

        int q = data[p].transitions[c];
        if (data[q].len - data[p].len == 1) {
            data[last].suffix_link = q;
            return;
        }

        int pc = create_state(data[q]);
        data[pc].len = data[p].len + 1;

        while (p != -1 && data[p].transitions[c] == q) {
            data[p].transitions[c] = pc;
            p = data[p].suffix_link;
        }

        data[q].suffix_link = pc;
        data[last].suffix_link = pc;
    }

    vector<int> ct_end_pos;
    

    


    void __initialize_auxiliary_data() {
        id10.assign(SZ + 1, 0);
        for (int loc = 0; loc < int(data.size()); loc++)
            id10[data[loc].len]++;
		for (int len = SZ; len > 0; len--)
            id10[len - 1] += id10[len];

        length_order.resize(data.size());
		for (int loc = 0; loc < int(data.size()); loc++)
            length_order[--id10[data[loc].len]] = loc;
        


        ct_end_pos.assign(data.size(), 0);
        

        


        for (int i = 0; i < int(data.size()); i++) {
            int loc = length_order[i];
            if (loc) {
                

                ct_end_pos[loc] += !is_clone[loc];
                ct_end_pos[data[loc].suffix_link] += ct_end_pos[loc];
            } else ct_end_pos[loc] = 0;

            
        }
    }

    int transition(int loc, int c) const {
        assert(loc != -1 && MIN_CHAR <= c && c < MIN_CHAR + SIGMA);
        return data[loc].transitions[c - MIN_CHAR];
    }

    template<typename I>
    int id8(I begin, I end) const {
        int loc = 0;
        for (auto iter = begin; iter != end && loc != -1; iter++)
            loc = transition(loc, *iter);
        return loc;
    }

    template<typename I>
    int id6(I begin, I end) const {
        int loc = id8(begin, end);
        return loc == -1 ? -1 : data[loc].first_end_pos - distance(begin, end) + 1;
    }

    template<typename I>
    int id0(I begin, I end) const {
        int loc = id8(begin, end);
        return loc == -1 ? 0 : ct_end_pos[loc];
    }
};





template<int MIN_CHAR, int SIGMA>
struct mutable_string {
    int SZ;
    vector<int> data;

    int BLOCK_SZ;
    vector<id5<MIN_CHAR, SIGMA>> blocks;

    template<typename I>
    mutable_string(I begin, I end) : data(begin, end) {
        SZ = data.size();
        BLOCK_SZ = ceil(sqrt(data.size()));
        for (int i = 0; i < SZ; i += BLOCK_SZ)
            blocks.emplace_back(data.begin() + i, data.begin() + min(i + BLOCK_SZ, SZ));
    }

    vector<int>::iterator block_start(int block_id) {
        return data.begin() + min(block_id * BLOCK_SZ, SZ);
    }
    vector<int>::const_iterator block_start(int block_id) const {
        return data.begin() + min(block_id * BLOCK_SZ, SZ);
    }

    

    void assign(int i, int c) {
        data[i] = c;
        int block_id = i / BLOCK_SZ;
        

        blocks[block_id].initialize(block_start(block_id), block_start(block_id + 1));
    }

    

    template<typename I>
    int id1(I begin, I end, int pos, int len) const {
        static id4 kmp;
        kmp.initialize(begin, end);

        int id9 = (pos + BLOCK_SZ - 1) / BLOCK_SZ;
        int id2  = (pos + len) / BLOCK_SZ;

        if (kmp.SZ >= BLOCK_SZ || id9 >= id2 || (id2 - id9) * kmp.SZ * 3 >= len)
            return kmp.count_matches(data.begin() + pos, data.begin() + pos + len);

        int count = 0;

        count += kmp.count_matches(data.begin() + pos, block_start(id9) + kmp.SZ - 1);

        for (int block_id = id9; block_id < id2; block_id++) {
            count += blocks[block_id].id0(begin, end);

            if (block_id != id9) {
                auto boundary = block_start(block_id);
                count += kmp.count_matches(boundary - kmp.SZ + 1, boundary + kmp.SZ - 1);
            }
        }

        count += kmp.count_matches(block_start(id2) - kmp.SZ + 1, data.begin() + pos + len);

        return count;
    }

    template<typename I>
    int count_matches(I begin, I end) const {
        return id1(begin, end, 0, SZ);
    }
};

int main() {
    setIO();

    string s; re(s);

    const int MAX_LEN = 1e5;
    mutable_string<'a', 26> ms(all(s));

    int Q; re(Q); id3 (q, Q) {
        int t; re(t);
        if (t == 1) {
            int i; char c; re(i, c);
            ms.assign(i - 1, c);
        } else {
            int l, r; string y; re(l, r, y);
            ps(ms.id1(y.begin(), y.end(), l - 1, r - l + 1));
        }
    }

    return 0;
}
