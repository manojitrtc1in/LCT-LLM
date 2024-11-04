



using namespace std;
using ll = int;
using ld = long double;











template <typename T> struct printer {
    static bool print(const T &value) {
        cout << value << ' ';
        return false;
    }
};
template <typename T> struct printer<vector<T>> {
    static bool print(const vector<T> &v) {
        for (const auto &element : v) {
            cout << element << ' ';
        }
        return false;
    }
};
template <typename... Args> void print(const Args &...args) {
    if (!(printer<Args>::print(args), ...)) {
        cout << '\n';
    }
}
[[noreturn]] void TODO(const std::string &what = "") {
    if (what.empty()) {
        throw std::runtime_error{"TODO"};
    }
    throw std::runtime_error{"TODO: " + what};
}



struct output {
    vector<bool> ans;

    void do_print() const {
        for (bool b : ans) {
            cout << (b ? "YES" : "NO") << endl;
        }
    }

    bool operator==([[maybe_unused]] const output &other) const {
        return ans == other.ans;
    }
};
template <> struct printer<output> {
    static bool print(const output &v) {
        v.do_print();
        return true;
    }
};

struct point {
    ll x, y;

    point() {}

    point(ll x_, ll y_)
        : x{x_}
        , y{y_}
    {}

    point(point a, point b)
        : point(b.x - a.x, b.y - a.y)
    {}
};

bool operator<(const point& lhs, const point& rhs) {
    return mp(lhs.x, lhs.y) < mp(rhs.x, rhs.y);
}

istream& operator>>(istream& is, point& p) {
    return is >> p.x >> p.y;
}

ostream& operator<<(ostream& os, const point& p) {
    return os << p.x << ' ' << p.y;
}

bool operator==(const point& lhs, const point& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

ll cp(point u, point v) {
    return u.x * v.y - u.y * v.x;
}

ll dp(point u, point v) {
    return u.x * v.x + u.y * v.y;
}

bool id3(point a, point b, point c, point d) {
    if (cp(point(a, b), point(a, c)) == 0 && cp(point(a, b), point(a, d)) == 0) {
        return
            dp(point(c, a), point(c, b)) <= 0 ||
            dp(point(d, a), point(d, b)) <= 0 ||
            dp(point(a, c), point(a, d)) <= 0 ||
            dp(point(b, c), point(b, d)) <= 0;
    }
    if (cp(point(a, b), point(a, c)) == 0) {
        return dp(point(c, a), point(c, b)) <= 0;
    }
    if (cp(point(a, b), point(a, d)) == 0) {
        return dp(point(d, a), point(d, b)) <= 0;
    }
    if (cp(point(c, d), point(c, a)) == 0) {
        return dp(point(a, c), point(a, d)) <= 0;
    }
    if (cp(point(c, d), point(c, b)) == 0) {
        return dp(point(b, c), point(b, d)) <= 0;
    }
    bool s1 = cp(point(a, c), point(a, b)) > 0;
    bool s2 = cp(point(a, b), point(a, d)) > 0;
    bool s3 = cp(point(c, a), point(c, d)) > 0;
    bool s4 = cp(point(c, d), point(c, b)) > 0;
    return s1 == s2 && s3 == s4;
}

struct id0 {
    point center;
    id0(point p) : center(p) {}
    bool operator()(const point &p, const point &q) const {
        point start(1, 0);
        if (p == q)
            return false;
        point op{center, p};
        point oq {center, q};
        if (cp(op, oq) == 0 && dp(op, oq) > 0)
            return false;
        ll sop = cp(start, op), soq = cp(start, oq);
        if (sop == 0) {
            if (dp(start, op) > 0)
                return true;
            return soq < 0;
        }
        if (soq == 0) {
            if (dp(start, oq) > 0)
                return false;
            return sop > 0;
        }
        if ((sop > 0 && soq > 0) || (sop < 0 && soq < 0)) {
            return cp(op, oq) > 0;
        }
        return sop > 0;
    }
};

struct segment_comparator {
    point p;
    point *d;
    vector<pair<point, point>>* pts;

    bool operator()(int lid, int rid) const {
        auto lhs = (*pts)[lid], rhs = (*pts)[rid];
        if (lhs == rhs) {
            return false;
        }
        auto [a, b] = lhs;
        auto [e, f] = rhs;
        if (cp(point(p, a), *d) < 0) {
            swap(a, b);
        }
        if (cp(point(p, e), *d) < 0) {
            swap(e, f);
        }
        if (cp(point(p, e), *d) == 0 && cp(point(p, a), *d) == 0) {
            return dp(point(p, a), point(p, a)) < dp(point(p, e), point(p, e));
        }
        if (cp(point(p, e), point(p, a)) >= 0 && cp(point(e, f), point(e, a)) >= 0) {
            return true;
        }
        if (id3(p, e, a, b)) {
            return true;
        }
        return false;
    }
};

struct input {
    int n;
    vector<pair<point, point>> junk;
    int q;
    vector<point> qs;

    void read() {
        cin >> n;
        junk.resize(n);
        forn(i, n) {
            cin >> junk[i].first >> junk[i].second;
        }
        cin >> q;
        qs.resize(q);
        forn(i, q) {
            cin >> qs[i];
        }
    }

    void do_print() const {
        print(n);
        forn(i, n) {
            print(junk[i].first, junk[i].second);
        }
        print(q);
        forn(i, q) {
            print(qs[i]);
        }
    }

    void gen(mt19937& rnd) {
        uniform_int_distribution<int> cdist(-10, 10);
        uniform_int_distribution<> ndist(1, 10);
        uniform_int_distribution<> qdist(1, 10);
        bool grep = false;
        do {
            junk.resize(n);
            forn(i, n) {
                point a, b;
                bool rep = false;
                int reps = 0;
                do {
                    rep = false;
                    a = {cdist(rnd), cdist(rnd)};
                    b = {cdist(rnd), cdist(rnd)};
                    if (a == b) {
                        rep = true;
                    }
                    if (cp(point(a, {0, 0}), point(a, b)) == 0 && dp(point({0, 0}, a), point({0, 0}, b)) <= 0) {
                        rep = true;
                    }
                    forn(j, i) {
                        if (id3(a, b, junk[j].first, junk[j].second)) {
                            rep = true;
                        }
                    }
                    reps++;
                    if (reps == 30) {
                        grep = true;
                        break;
                    }
                } while (rep);
                junk[i] = {a, b};
                if (grep) {
                    break;
                }
            }
            if (grep) {
                continue;
            }
            qs.resize(q);
            forn(i, q) {
                point a;
                bool rep = false;
                int reps = 0;
                do {
                    rep = false;
                    a = {cdist(rnd), cdist(rnd)};
                    if (a == point{0, 0}) {
                        rep = true;
                    }
                    forn(j, n) {
                        if (cp(point(a, junk[j].first), point(a, junk[j].second)) == 0 && dp(point(a, junk[j].first), point(a, junk[j].second)) <= 0) {
                            rep = true;
                        }
                    }
                    forn(j, i) {
                        if (qs[j] == qs[i]) {
                            rep = true;
                        }
                    }
                    reps++;
                    if (reps == 30) {
                        grep = true;
                        break;
                    }
                } while (rep);
                qs[i] = a;
                if (grep) {
                    break;
                }
            }
        } while (grep);
    }

    void gen() {
        

        static mt19937 rnd{std::random_device{}()};
        uniform_int_distribution<> ndist(1, 10);
        uniform_int_distribution<> qdist(1, 10);
        n = ndist(rnd);
        q = qdist(rnd);
        gen(rnd);
    }

    void gen_max() {
        mt19937 rnd{179};
        n = 1000;
        q = 1500;
        gen(rnd);
    }

    vector<point> points, directions;
    vector<vector<optional<int>>> nxt;

    struct event {
        point p;
        int type, id;
    };

    bool move_fast(int pid, int did) {
        while (true) {
            point p = points[pid];
            point d = directions[did];
            auto id4 = nxt[pid][did];
            if (!id4) {
                return p.x == -d.x && p.y == -d.y;
            }
            auto [a, b] = junk[*id4];
            if (p.x == -d.x && p.y == -d.y && !id3(p, point{0, 0}, a, b)) {
                return true;
            }
            int bid = q + 2 * (*id4) + 1;
            if (dp(d, point(a, b)) < 0) {
                swap(a, b);
                bid--;
            }
            point v{a, b};
            point u{-v.y, v.x};
            if (dp(d, u) < 0) {
                u.x = -u.x;
                u.y = -u.y;
            }
            if (dp(d, v) <= dp(d, u)) {
                return false;
            }
            pid = bid;
        }
    }

    output fast() {
        points = qs;
        map<point, int> dir_id;
        for (auto [a, b] : junk) {
            directions.emplace_back(-a.x, -a.y);
            directions.emplace_back(-b.x, -b.y);
            points.emplace_back(a);
            points.emplace_back(b);
        }
        forn(i, directions.size()) {
            dir_id[directions[i]] = i;
        }
        nxt.resize(points.size(), vector<optional<int>>(directions.size()));
        int pid = 0;
        for (auto p : points) {
            vector<event> evs;
            for (auto d : directions) {
                evs.emplace_back(event{d, 0, 0});
            }
            for (int i = 0; i < n; i++) {
                if (p == junk[i].first || p == junk[i].second) {
                    continue;
                }
                auto [a, b] = junk[i];
                if (cp(point(p, a), point(p, b)) < 0) {
                    swap(a, b);
                }
                evs.emplace_back(event{point{p, a}, 1, i});
                evs.emplace_back(event{point{p, b}, -1, i});
            }
            auto pcmp = id0{{0, 0}};
            auto ecmp = [&](const event& lhs, const event& rhs) {
                if (pcmp(lhs.p, rhs.p)) {
                    return true;
                }
                if (pcmp(rhs.p, lhs.p)) {
                    return false;
                }
                return lhs.type > rhs.type;
            };
            sort(all(evs), ecmp);
            vector<bool> open(n);
            point d{1, 0};
            set<int, segment_comparator> id1{segment_comparator{p, &d, &junk}};
            vector<set<int, segment_comparator>::iterator> iters(n);
            for (auto e : evs) {
                if (e.type == 1) {
                    open[e.id] = true;
                }
                if (e.type == -1 && !open[e.id]) {
                    iters[e.id] = id1.insert(e.id).first;
                }
            }
            for (auto e : evs) {
                

                d = e.p;
                if (e.type == 1) {
                    iters[e.id] = id1.insert(e.id).first;
                } else if (e.type == -1) {
                    id1.erase(iters[e.id]);
                } else {
                    if (id1.empty()) {
                        nxt[pid][dir_id[e.p]] = {};
                        

                    } else {
                        nxt[pid][dir_id[e.p]] = *(id1.begin());
                        

                    }
                }
            }
            pid++;
        }
        vector<bool> ret;
        pid = 0;
        for (auto start : qs) {
            ret.emplace_back([this, start, pid]() {
                bool ok = true;
                for (auto [a, b] : junk) {
                    if (id3(start, {0, 0}, a, b)) {
                        ok = false;
                    }
                }
                if (ok) {
                    return true;
                }
                forn(did, directions.size()) {
                    if (move_fast(pid, did)) {
                        return true;
                    }
                }
                return false;
            }());
            pid++;
        }
        return {ret};
    }

    bool move(point p, point d) {
        optional<pair<point, point>> id4 = [&]() {
            optional<pair<point, point>> cur;
            for (auto [a, b] : junk) {
                if (a == p || b == p) {
                    continue;
                }
                ll pa = cp(point(p, a), d);
                ll pb = cp(point(p, b), d);
                if ((pa > 0 && pb > 0) || (pa < 0 && pb < 0)) {
                    continue;
                }
                if (pa > 0 && cp(point(p, a), point(p, b)) < 0) {
                    continue;
                }
                if (pa < 0 && cp(point(p, a), point(p, b)) > 0) {
                    continue;
                }
                if (pa == 0 && dp(d, point(p, a)) < 0) {
                    continue;
                }
                if (pb == 0 && dp(d, point(p, b)) < 0) {
                    continue;
                }
                if (pa < 0) {
                    swap(a, b);
                }
                if (!cur) {
                    cur = {a, b};
                    continue;
                }
                if (cp(point(p, cur->first), point(p, a)) >= 0 && cp(point(cur->first, cur->second), point(cur->first, a)) >= 0) {
                    cur = {a, b};
                    continue;
                }
                if (id3(p, cur->first, a, b)) {
                    cur = {a, b};
                    continue;
                }
            }
            return cur;
        }();

        if (!id4) {
            return p.x == -d.x && p.y == -d.y;
        }
        if (p.x == -d.x && p.y == -d.y && !id3(p, point{0, 0}, id4->first, id4->second)) {
            return true;
        }
        auto [a, b] = *id4;
        if (dp(d, point(a, b)) < 0) {
            swap(a, b);
        }
        point v{a, b};
        point u{-v.y, v.x};
        if (dp(d, u) < 0) {
            u.x = -u.x;
            u.y = -u.y;
        }
        if (dp(d, v) <= dp(d, u)) {
            return false;
        }
        return move(b, d);
    }

    output slow() {
        vector<point> directions;
        for (auto [a, b] : junk) {
            directions.emplace_back(-a.x, -a.y);
            directions.emplace_back(-b.x, -b.y);
        }
        vector<bool> ret;
        for (auto start : qs) {
            ret.emplace_back([this, start, directions]() mutable {
                directions.emplace_back(-start.x, -start.y);
                for (auto d : directions) {
                    if (move(start, d)) {
                        return true;
                    }
                }
                return false;
            }());
        }
        return {ret};
    }
};
template <> struct printer<input> {
    static bool print(const input &v) {
        v.do_print();
        return true;
    }
};

void test() {
    input in;
    in.read();
    output out = in.fast();
    print(out);
}

void multitest() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; t++) {
        test();
    }
}

void stress() {
    int TESTS = 10'000;
    for (int test = 1; test <= TESTS; test++) {
        input in;
        in.gen();
        input in_fast = in, id2 = in;
        output ja = id2.slow();
        output ca = in_fast.fast();
        if (!(ja == ca)) {
            print("WA test", test);
            print(in);
            print("Expected:", ja);
            print("Found:", ca);
            return;
        }
    }
    print("OK");
}

void max_test() {
    input in;
    in.gen_max();
    auto b = chrono::high_resolution_clock::now();
    in.fast();
    auto e = chrono::high_resolution_clock::now();
    auto d = chrono::duration_cast<chrono::milliseconds>(e - b).count();
    print("Time elapsed: ", 1.0 * d / 1000);
}

void gen() {
    input in;
    in.gen();
    print(in);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    


    test();
    

    

    

    


    return 0;
}
