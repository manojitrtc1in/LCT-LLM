










NDEBUG

























using namespace std;

template<class T>
using vec = std::vector<T>;

template<class T>
using vec2d = std::vector<std::vector<T>>;

template<class T>
using vec3d = std::vector<std::vector<std::vector<T>>>;

template<class T>
using vec4d = std::vector<std::vector<std::vector<std::vector<T>>>>;

template<class T>
vec<T> makeVec(const int n1) {
  return vec<T>(n1);
}

template<class T>
vec<T> makeVec(const int n1, const T initValue) {
  return vec<T>(n1, initValue);
}

template<class T>
vec2d<T> id4(const int n1) {
  return vec2d<T>(n1);
}

template<class T>
vec2d<T> id4(const int n1, const int n2) {
  return vec2d<T>(n1, vec<T>(n2));
}

template<class T>
vec2d<T> id4(const int n1, const int n2, const T initValue) {
  return vec2d<T>(n1, vec<T>(n2, initValue));
}

template<class T>
vec3d<T> id1(const int n1) {
  return vec3d<T>(n1);
}

template<class T>
vec3d<T> id1(const int n1, const int n2) {
  return vec3d<T>(n1, vec2d<T>(n2));
}

template<class T>
vec3d<T> id1(const int n1, const int n2, const int n3) {
  return vec3d<T>(n1, vec2d<T>(n2, vec<T>(n3)));
}

template<class T>
vec3d<T> id1(const int n1, const int n2, const int n3, const T initValue) {
  return vec3d<T>(n1, vec2d<T>(n2, vec<T>(n3, initValue)));
}

template<class T>
vec4d<T> id0(const int n1) {
  return vec4d<T>(n1);
}

template<class T>
vec4d<T> id0(const int n1, const int n2) {
  return vec4d<T>(n1, vec3d<T>(n2));
}

template<class T>
vec4d<T> id0(const int n1, const int n2, const int n3) {
  return vec4d<T>(n1, vec3d<T>(n2, vec2d<T>(n3)));
}

template<class T>
vec4d<T> id0(const int n1, const int n2, const int n3, const int n4) {
  return vec4d<T>(n1, vec3d<T>(n2, vec2d<T>(n3, vec<T>(n4))));
}

template<class T>
vec3d<T>
id0(const int n1, const int n2, const int n3, const int n4, const T initValue) {
  return vec4d<T>(n1, vec3d<T>(n2, vec2d<T>(n3, vec<T>(n4, initValue))));
}

template<class T>
void fillVec(vec<T>& v, const T value) {
  for (int i = 0; i < (int) v.size(); ++i) {
    v[i] = value;
  }
}

template<class T>
void fillVec(vec2d<T>& v, const T value) {
  for (int i = 0; i < (int) v.size(); ++i) {
    fillVec(v[i], value);
  }
}

template<class T>
void fillVec(vec3d<T>& v, const T value) {
  for (int i = 0; i < (int) v.size(); ++i) {
    fillVec(v[i], value);
  }
}

template<class T>
void fillVec(vec4d<T>& v, const T value) {
  for (int i = 0; i < (int) v.size(); ++i) {
    fillVec(v[i], value);
  }
}

















template <class T = double>
T pi() {
    return acos(T(-1));
};

typedef int64_t i64;
typedef uint64_t ui64;
typedef int32_t i32;
typedef uint32_t ui32;


using namespace std;





bool __hack = std::ios::sync_with_stdio(false);


auto id5 = cin.tie(nullptr);



template<class T>
inline T mn(T arg) {
    return arg;
}

template<class T, class... Ts>
inline typename common_type<T, Ts...>::type mn(T arg, Ts... args) {
    auto arg1 = mn(args...);
    return arg < arg1 ? arg : arg1;
}

template<class T>
inline T mx(T arg) {
    return arg;
}

template<class T, class... Ts>
inline typename common_type<T, Ts...>::type mx(T arg, Ts... args) {
    auto arg1 = mx(args...);
    return arg > arg1 ? arg : arg1;
}

template<class T, class... Args>
inline bool rmn(T &to, Args... args) {
    auto v = mn(args...);
    if (to > v) {
        to = v;
        return true;
    }
    return false;
}

template<class T, class... Args>
inline bool rmx(T &to, Args... args) {
    auto v = mx(args...);
    if (to < v) {
        to = v;
        return true;
    }
    return false;
}

template <class T>
T gen_pow(T ret, T x, uint64_t pow) {
    while (pow) {
        if (pow & 1) {
            ret *= x;
        }
        pow /= 2;
        if (pow) {
            x *= x;
        }
    }
    return ret;
}

int parseInt(const string& s) { return stoi(s); }

i64 id3(const string& s) { return stoll(s); }

template <class F, bool Rev>
struct ByComparator {
    ByComparator(F f_): f(f_) {};

    template <class T>
    bool operator()(const T& lhs, const T& rhs) {
        if (Rev) {
            return f(lhs) > f(rhs);
        } else {
            return f(lhs) < f(rhs);
        }
    }

    F f;
};

template <bool Rev = false, class F = void>
ByComparator<F, Rev> by(F f) {
    return {f};
}

template <class T>
T pop_back(vector<T>& v) {
    T ret = v.back();
    v.pop_back();
    return ret;
}

template <class T>
T pop(queue<T>& v) {
    T ret = v.front();
    v.pop();
    return ret;
}

template <class T, class C, class Cmp>
T pop(priority_queue<T, C, Cmp>& v) {
    T ret = v.top();
    v.pop();
    return ret;
}




template <class T> using StdTree = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;

template<class T>
void updateEvery(vec<T>& v, function<void(T&)>& f) {
  for_each(all(v), f);
}

template<class T>
void addOne(vec<T>& v) {
  for_each(all(v), [] (T& el) {
    ++el;
  });
}

template<class T>
void subOne(vec<T>& v) {
  for_each(all(v), [] (T& el) {
    --el;
  });
}

vec<int> id2(const vec<int>& p) {
  vec<int> pos(p.size());
  FOR(i, p.size()) {
    pos[p[i]] = i;
  }
  return pos;
}




namespace template_util {
    template<class T>
    constexpr T min(T a, T b) {
        return a < b ? a : b;
    }

    template<class T>
    constexpr T max(T a, T b) {
        return a > b ? a : b;
    }

    constexpr int bytecount(uint64_t x) {
        return x ? 1 + bytecount(x >> 8) : 0;
    }

    template<int N>
    struct bytetype {
        typedef uint64_t type;
    };

    template<>
    struct bytetype<4> {
        typedef uint32_t type;
    };

    template<>
    struct bytetype<3> {
        typedef uint32_t type;
    };

    template<>
    struct bytetype<2> {
        typedef uint16_t type;
    };

    template<>
    struct bytetype<1> {
        typedef uint8_t type;
    };

    template<>
    struct bytetype<0> {
        typedef uint8_t type;
    };

    

    template<uint64_t N>
    struct minimal_uint : bytetype<bytecount(N)> {
    };
}









template<class A, class B>
void dbgPrint(const pair<A, B>& val);

template<class... Ts>
void dbgPrint(const tuple<Ts...>& val);

template<class T>
void dbgPrint(const T& val) {
    cout << val;
}

template<class T>
void dbgPrint(const vector<T>& val) {
    cout << "[";
    bool first = true;
    for (const auto& v : val) {
        if (!first) {
            cout << ", ";
        } else {
            first = false;
        }
        dbgPrint(v);
    }
    cout << "]";
}

template<class K, class V>
void dbgPrint(const unordered_map<K, V>& val) {
    cout << "{";
    bool first = true;
    for (const auto& it : val) {
        if (!first) {
            cout << ", ";
        } else {
            first = false;
        }
        dbgPrint(it.first);
        cout << ": ";
        dbgPrint(it.second);
    }
    cout << "}";
}

template<class A, class B>
void dbgPrint(const pair<A, B>& val) {
    cout << "<";
    dbgPrint(val.first);
    cout << ", ";
    dbgPrint(val.second);
    cout << ">";
}

template<int I>
struct dbgPrintTuple {
    template<class... Ts>
    static void print(const tuple<Ts...>& val) {
        dbgPrintTuple<I - 1>::print(val);
        cout << ", ";
        dbgPrint(get<I>(val));
    }
};

template<>
struct dbgPrintTuple<0> {
    template<class... Ts>
    static void print(const tuple<Ts...>& val) {
        dbgPrint(get<0>(val));
    }
};

template<class... Ts>
void dbgPrint(const tuple<Ts...>& val) {
    cout << "<";
    dbgPrintTuple<sizeof...(Ts) - 1>::print(val);
    cout << ">";
}









template<class... Vals>
void dbg(Vals... vals);

template<class Val>
void dbg(Val val) {
    dbgPrint(val);
    cout << endl;
}

template<>
void dbg() {
    cout << endl;
}

template<class Val, class... Vals>
void dbg(Val val, Vals... vals) {
    dbgPrint(val);
    cout << " ";
    dbg(vals...);
};








using namespace std;






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

    i64 ni64() const {
        return next<i64>();
    }

    string ns() const {
        return next<string>();
    }

    template<class T>
    vec<T> nVec(int n) const {
        vec<T> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = next<T>();
        }
        return v;
    }

    vec<int> nvi(int n) const {
        return nVec<int>(n);
    }

    vec<i64> nvi64(int n) const {
        return nVec<i64>(n);
    }

    vec<string> nvs(int n) const {
        return nVec<string>(n);
    }

    template<class T>
    void read(vec<T>& v, int n) {
        for (int i = 0; i < n; ++i) {
            v[i] = next<T>();
        }
    }

    template<class T, class U=T>
    void read(vec<T>& v, vec<U>& v2, int n) {
        for (int i = 0; i < n; ++i) {
            v[i] = next<T>();
            v2[i] = next<U>();
        }
    }

    template<class T, class U=T, class V=T>
    void read(vec<T>& v, vec<U>& v2, vec<V>& v3, int n) {
        for (int i = 0; i < n; ++i) {
            v[i] = next<T>();
            v2[i] = next<U>();
            v2[i] = next<V>();
        }
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

template<typename T>
void printSingle(const vec<T> &v) {
    for (std::size_t i = 0; i < v.size(); ++i) {
        if (i == 0) {
            *out << v[i];
        } else {
            *out << ' ' << v[i];
        }
    }
}

template<typename T, typename U>
void printSingle(const pair<T, U> &p) {
    *out << p.first << ' ' << p.second;
}

public:
Output(ostream &out) : out(&out) {}

inline void flush() {
    out->flush();
}

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

template<typename T>
ostream& operator<< (const T& x) {
    *out << x;
}

};

Output out(cout);

class AMindControl {
public:
	void solve(istream& in1, ostream& out1) {
        Input in(in1);
        Output out(out1);
        auto n = in.ni();
        auto m = in.ni();
        auto k = in.ni();
        auto a = in.nvi(n);
        int willRemove = m - 1;
        int left = n - willRemove;
        int dst = left - 1;

        multiset<int> Q;
        k = min(k, m - 1);

        vec<int> order;
        int res = max(a[k], a[k + dst]);
        for (int i = k, j = k + dst; j < n; ++i, ++j) {
            res = min(res, max(a[i], a[j]));
            order.push_back(max(a[i], a[j]));


        }




        for (int i = k - 1, j = 1; i >= 0; --i, ++j) {
            int cur = max(a[i], a[i + dst]);
            for (int t = i; t + dst <= n - 1 - j; ++t) {
                cur = min(cur, max(a[t], a[t + dst]));
            }




            order.pop_back();
            res = max(res, cur);
        }
        out(res);
	}

	void prepare() {

	}
};

int main() {
	AMindControl solver;
	solver.prepare();
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	int n;
in >> n;
for(int i = 0; i < n; ++i) {
	solver.solve(in, out);
}

	return 0;
}