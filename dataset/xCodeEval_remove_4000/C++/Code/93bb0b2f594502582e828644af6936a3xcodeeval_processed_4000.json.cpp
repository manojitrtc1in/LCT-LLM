









NDEBUG
























using namespace std;

template<class T>
using vec = std::vector<T>;

template<class T>
using vec2d = std::vector<std::vector<T>>;


template<class T>
vec2d<T> id7(const int n1, const int n2) {
  return vec2d<T>(n1, vec<T>(n2));
}
















bool __hack = std::ios::sync_with_stdio(false);


auto id8 = cin.tie(nullptr);























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

    
    string ns() const {
        return next<string>();
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





template<typename Iterator>
struct id1 {
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    const Iterator begin, end;

    id1(Iterator begin_, Iterator end_): begin(begin_), end(end_) {}

    inline value_type operator[](int i) {
        return 0 <= i && begin + i < end ? *(begin + i) : value_type();
    }
};


template<typename Iterator>
void id2(vector<int>& a, vector<int>& b, Iterator rBegin, Iterator rEnd, int n, int max) {
    id1<Iterator> r(rBegin, rEnd);
    vector<int> c(max + 1);
    for (int i = 0; i < n; ++i) {
        auto key = r[a[i]];
        if (key < max) {
            c[key + 1]++;
        }
    }
    for (int i = 0; i < max; ++i) {
        c[i + 1] += c[i];
    }
    for (int i = 0; i < n; ++i) {
        int j = c[(int)r[a[i]]]++;
        b[j] = a[i];
    }
}

template<typename Iterator1, typename Iterator2>
void suffixArray(Iterator1 sBegin, Iterator1 sEnd, Iterator2 SA, int max) {
    int n = (int)(sEnd - sBegin);
    id1<Iterator1> s(sBegin, sEnd);
    int n0 = (n + 2) / 3, n1 = (n + 1) / 3, n2 = n / 3, n02 = n0 + n2;
    vector<int> s12(n02 + 3);
    s12[n02] = s12[n02 + 1] = s12[n02 + 2] = 0;
    vector<int> SA12(n02 + 3);
    SA12[n02] = SA12[n02 + 1] = SA12[n02 + 2] = 0;
    for (int i = 0, j = 0; i < n + (n0 - n1); ++i) {
        if (i % 3 != 0) {
            s12[j++] = i;
        }
    }
    id2(s12, SA12, sBegin + 2, sEnd, n02, max);
    id2(SA12, s12, sBegin + 1, sEnd, n02, max);
    id2(s12, SA12, sBegin + 0, sEnd, n02, max);
    int names = 1;
    auto c0 = s[SA12[0] + 0], c1 = s[SA12[0] + 1], c2 = s[SA12[0] + 2];
    for (int i = 0; i < n02; ++i) {
        if (s[SA12[i] + 0] != c0 || s[SA12[i] + 1] != c1 || s[SA12[i] + 2] != c2) {
            names++;
            c0 = s[SA12[i] + 0]; c1 = s[SA12[i] + 1]; c2 = s[SA12[i] + 2];
        }
        if (SA12[i] % 3 == 1) {
            s12[SA12[i] / 3] = names;
        } else {
            s12[n0 + SA12[i] / 3] = names;
        }
    }
    if (names == n02) {
        for (int i = 0; i < n02; ++i) {
            SA12[s12[i] - 1] = i;
        }
    } else {
        suffixArray(s12.begin(), s12.begin() + n02, SA12.begin(), names);
        for (int i = 0; i < n02; ++i) {
            s12[SA12[i]] = i + 1;
        }
    }
    vector<int> s0(n0), SA0(n0);
    for (int i = 0, j = 0; i < n02; ++i) {
        if (SA12[i] < n0) {
            s0[j++] = 3 * SA12[i];
        }
    }
    id2(s0, SA0, sBegin, sEnd, n0, max);
    function<bool(int,int)> less = [&](int i, int j) -> bool {
        if (i == n || j == n) {
            return i == n;
        }
        if (s[i] != s[j]) {
            return s[i] < s[j];
        }
        if (j % 3 == 2) {
            return !less(j + 1, i + 1);
        }
        if (i + 1 == n || j + 1 == n) {
            return i + 1 == n;
        }
        return s12[i / 3] < s12[j / 3 + n0];
    };
    for (int it = 0, jt = n0 - n1, k = 0; k < n; ++k) {
        int i = -1;
        if (it < n0) {
            i = SA0[it];
        }
        int j = -1;
        if (jt < n02) {
            j = SA12[jt] < n0 ? 3 * SA12[jt] + 1 : 3 * (SA12[jt] - n0) + 2;
        }
        if (it < n0 && (jt >= n02 || less(i, j))) {
            *SA++ = i;
            it++;
        } else {
            *SA++ = j;
            jt++;
        }
    }
}


template<typename Iterator1, typename Iterator2>
vector<int> id3(Iterator1 sBegin, Iterator1 sEnd, Iterator2 SA) {
    int n = (int) (sEnd - sBegin);
    vector<int> ret(n), inv(n);
    for (int i = 0; i < n; ++i) {
        inv[SA[i]] = i;
    }
    for (int i = 0, k = 0; i < n; ++i) {
        k = max(0, k - 1);
        if (inv[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = SA[inv[i] + 1];
        while (i + k < n && j + k < n && sBegin[i + k] == sBegin[j + k]) {
            k++;
        }
        ret[inv[i]] = k;
    }
    return ret;
}






























































































































































































































































































































































































































































































































template<class T>
struct RMQ {
  vec2d<T> st;
  vec<int> logs;
  function<T(T, T)> f;
  int n;
  int k;

  RMQ(const vec<T>& a, const function<T(T, T)>& f_) : f(f_) {
    n = (int) a.size();
    logs = vec<int>(n + 1);
    logs[1] = 0;
    for (int i = 2; i <= n; i++) {
      logs[i] = logs[i / 2] + 1;
    }
    k = 1;
    while (k < logs[n] + 1) {
      k++;
    }
    st = id7<T>(k + 1, n);
    st[0] = a;
    for (int j = 1; j <= k; j++) {
      for (int i = 0; i + (1 << j) <= n; ++i) {
        st[j][i] = f(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T get(int left, int right) {
    int j = logs[right - left + 1];
    return f(st[j][left], st[j][right - (1 << j) + 1]);
  }
};


void solve(istream& inStream, ostream& outStream) {
    in = Input(inStream);
    out = Output(outStream);
    auto n = in.ni();
    auto s = in.ns();
    auto m = in.ni();
    auto t = in.ns();
    auto x = in.ni();
    vector<int> SA;
    string S = s + "
    suffixArray(all(S), back_inserter(SA), 127);
    vector<int> lcp = id3(all(S), SA.begin());
    dbg(SA);
    FOR(i, SA.size()) {
        dbg(i, S.substr(SA[i]));
    }
    dbg(lcp);

    vec<int> id5(n), id4(m);
    FORA(i, 1, SA.size()) {
        if (SA[i] < n) {
            id5[SA[i]] = i;
        } else if (SA[i] > n) {
            id4[SA[i] - n - 1] = i;
        }
    }
    dbg(id5, id4);
    RMQ<int> id6(lcp, [](int a, int b) -> int {return min(a, b);});

    auto id0 = [&] (int sI, int tI) -> int {
        int i = id5[sI];
        int j = id4[tI];
        if (i > j) {
            swap(i, j);
        }
        --j;
        return id6.get(i, j);
    };

    vec<int> dp(n + 1, 0);

    FOR(xx, x) {
        vec<int> nxt(n + 1, 0);
        FOR(i, n) {
            int startT = dp[i];
            int common = id0(i, startT);
            if (common) {
                int newT = startT + common;
                int newI = i + common;
                nxt[newI] = max(nxt[newI], newT);
            }
        }
        FR(i, 1, n) {
            nxt[i] = max(nxt[i], nxt[i-1]);
        }
        dp = nxt;
        FOR(i, n + 1) {
            if (dp[i] == m) {
                out("YES");
                return;
            }
        }
    }
    out("NO");
}





int main() {








    solve(cin, cout);


    return 0;
}

