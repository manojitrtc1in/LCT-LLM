









NDEBUG
























using namespace std;

template<class T>
using vec = std::vector<T>;

template<class T>
using vec2d = std::vector<std::vector<T>>;


template<class T>
vec2d<T> id0(const int n1, const int n2) {
  return vec2d<T>(n1, vec<T>(n2));
}













bool __hack = std::ios::sync_with_stdio(false);


auto id1 = cin.tie(nullptr);























struct Input {

    Input(istream &in) : in(&in) {}

    template<class T>
    T next() const {
        T x;
        *in >> x;
        return x;
    }

    int ni() const {
        return next<int>();
    }

    
    istream *in;
};

Input in(cin);


class Output {

private:
ostream *out;

template<typename T>
void printSingle(const T &value) {
    *out << value;
}


public:
Output(ostream &out) : out(&out) {}


inline void setPrecision(int d) {
    *out << fixed << setprecision(d);
}

inline void print() {}

template<typename T, typename...Ts>
inline void print(const T &f, const Ts&... args) {
    printSingle(f);
    if (sizeof...(args) != 0) {
        *out << ' ';
        print(args...);
    }
}

template<typename...Ts>
inline void println(const Ts&... args) {
    print(args...);
    *out << '\n';
}

template<typename...Ts>
inline void operator() (const Ts&... args) {
    println(args...);
}


};

Output out(cout);


namespace template_util {
    

    constexpr int bytecount(uint64_t x) {
        return x ? 1 + bytecount(x >> 8) : 0;
    }

    template<int N>
    struct bytetype {
        
    };

    
    

    template<uint64_t N>
    struct minimal_uint : bytetype<bytecount(N)> {
    };
}






double PI = acos(-1.);































































template <class T>
struct Point {
    T x, y;
    
    Point(const T& x, const T& y) : x(x), y(y) {}
    

};






FF2(operator *, Point<T1>& p1, Point<T2>& p2, p1.x * p2.x + p1.y * p2.y)








FF1(angle, Point<T>& point, atan2(point.y, point.x))




FF1(length, Point<T>& point, sqrt(point * point))













































































































































typedef Point<double> Pnt;

void solve(istream& inStream, ostream& outStream) {
    in = Input(inStream);
    out = Output(outStream);
    auto n = in.ni();
    auto m = in.ni();
    vec<pair<double, double>> ps(n);

    auto nrm = [] (pair<double, double> x) -> pair<double, double> {
        while (x.first < 0) {
            x.first += 2 * PI;
            x.second += 2 * PI;
        }
        while (x.first >= 2 * PI) {
            x.first -= 2 * PI;
            x.second -= 2 * PI;
        }
        return x;
    };

    auto check = [&] (double d) -> bool {

        vec<pair<double, double>> segs;
        FOR(i, n) {
            double offset = acos(min(d / ps[i].second, 1.0));
            segs.push_back(nrm(make_pair(ps[i].first - offset, ps[i].first + offset)));
        }
        sort(all(segs));

        






















        int sz = (int)segs.size();

        FOR(i, sz) {
            segs.push_back({segs[i].first + 2 * PI, segs[i].second + 2 * PI});
        }

        int idx = 2 * sz;
        vec2d<int> nxt = id0<int>(2 * sz + 1, 17);
        FOR(j, 17) nxt[idx][j] = idx;
        for (int i = 2 * sz - 1; i >= 0; --i) {
            while (segs[idx - 1].first > segs[i].second) {
                --idx;
            }
            nxt[i][0] = idx;
        }
        FORA(j, 1, 17) FOR(i, 2 * sz) nxt[i][j] = nxt[nxt[i][j-1]][j-1];
        FOR(i, sz) {
            int res = 0;
            int cur = i;
            for (int j = 16; j >= 0; --j) {
                if (nxt[cur][j] < i + sz) {
                    res += (1 << j);
                    cur = nxt[cur][j];
                }
            }
            if (res + 1 <= m) return true;
        }
        return false;
    };

    double r = 1e100;
    FOR(i, n) {
        auto x = in.next<double>();
        auto y = in.next<double>();
        auto p = Pnt(x, y);
        ps[i] = {angle(p), length(p)};
        r = min(r, ps[i].second);
    }
    out.setPrecision(15);
    if (m >= n) {
        out(r);
        return;
    }
    double l = 0;
    FOR(iter, 70) {
        double e = (l + r) / 2;
        if (check(e)) {
           l = e;
        } else {
            r = e;
        }
    }
    out((l + r) / 2);
}





int main() {








    solve(cin, cout);


    return 0;
}

