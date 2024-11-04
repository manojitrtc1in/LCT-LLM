























template <class T=int>
std::vector<T> ReadVector(size_t size) {
    std::vector<T> vector(size);
    for (auto& element : vector) {
        std::cin >> element;
    }
    return vector;
}


void YES(bool yes=true) {
    std::cout << (yes ? "YES\n" : "NO\n");
}

void NO() {
    std::cout << "NO\n";
}





class range {
public:
    int start;
    int stop;
    class iterator {
    public:
        int i;
        iterator(int i) : i(i) {}
        iterator& operator++() {
            ++i;
            return *this;
        }
        int operator*() {
            return i;
        }
        bool operator!= (const iterator& other) {
            return i != other.i;
        }
    };

    range(int stop) : start(0), stop(stop) {}

    range(int start, int stop) : start(start), stop(stop) {}

    iterator begin() {
        return start;
    }

    iterator end() {
        return stop;
    }
};




std::vector<int> list(int a, int b) {
    std::vector<int> vector;
    vector.push_back(a);
    vector.push_back(b);
    return vector;
};
std::vector<int> list(int a, int b, int c) {
    std::vector<int> vector;
    vector.push_back(a);
    vector.push_back(b);
    vector.push_back(c);
    return vector;
};

template<typename T>
void print(const T& x) {
    std::cout << x << ' ';
}
template<typename T>
void println(const T& x) {
    std::cout << x << '\n';
}
void println() {
    std::cout << '\n';
}

template <typename T>
void print(const std::vector<T>& a) {
    for (auto x : a) {
        print(x);
    }
}

template <typename T>
void println(const std::vector<T>& a) {
    for (auto x : a) {
        print(x);
    }
    std::cout << '\n';
}








template <class Row>
class BaseGrid {
public:
    class iterator {
    public:
        BaseGrid<Row>* baseGrid;
        size_t i;
        size_t j;

        iterator(BaseGrid<Row>* baseGrid, size_t i, size_t j)
                : baseGrid(baseGrid), i(i), j(j)
        {}

        iterator& operator++() {
            if (j < (baseGrid->m) - 1) {
                j += 1;
            } else {
                i += 1;
                j = 0;
            }
            return *this;
        }
        bool operator!= (const iterator& other) {
            return i != other.i || j != other.j;
        }

        decltype(&(baseGrid->rows[0][0])) operator->() {
            return &(baseGrid->rows)[i][j];
        }

        decltype(baseGrid->rows[0][0])& operator* () {
            return (baseGrid->rows)[i][j];
        }

        iterator left() {
            if (i > 0) {
                return {baseGrid, i - 1, j};
            }
            return baseGrid->end();
        }

        iterator right() {
            if (i + 1 < baseGrid->n) {
                return {baseGrid, i + 1, j};
            }
        }

        explicit operator bool() {
            return *this != baseGrid->end();
        }
    };

    size_t n;
    size_t m;

    std::vector<Row> rows;
    BaseGrid(size_t n)
            : n(n), rows(n)
    {}

    BaseGrid(size_t n, size_t m)
            : n(n), m(m), rows(n, Row(m))
    {}

    BaseGrid(size_t n, Row row)
            : n(n), m(row.size()), rows(n, row)
    {}

    decltype(rows[0][0])& operator() (int i, int j) {
        return rows[i][j];
    }

    iterator begin() {
        return {this, 0, 0};
    }

    iterator end() {
        return {this, n, 0};
    }

    Row& operator[](size_t i) {
        return rows[i];
    }
};


template <class T>
class Grid : public BaseGrid<std::vector<T>> {
public:
    Grid(size_t n, size_t m)
            : BaseGrid<std::vector<T>>(n, std::vector<T>(m))
    {}
};

template <>
class Grid <char> : public BaseGrid<std::string> {
public:
    Grid(size_t n)
            : BaseGrid(n)
    {}

    Grid(size_t n, std::istream& in)
            : BaseGrid(n)
    {
        for (size_t i = 0; i < n; ++i) {
            in >> rows[i];
        }
    }

    Grid(size_t n, size_t m, char value)
            : BaseGrid<std::string>(n, std::string(m, value))
    {}
};


namespace nt {
    int id2(int a, int b, int *x, int *y)
    {
        if (a == 0)
        {
            *x = 0;
            *y = 1;
            return b;
        }

        int x1, y1;
        int gcd = id2(b%a, a, &x1, &y1);

        *x = y1 - (b/a) * x1;
        *y = x1;

        return gcd;
    }
}

class mint {
public:
    int x;


    mint() : x(0) {}
    mint(int x) : x(x) {}
    mint(mint &other) : x(other.x) {}


    mint operator= (int other) {
        x = other;
        return *this;
    }

    mint operator= (const mint& other) {
        x = other.x;
        return *this;
    }

    mint operator+(const mint& other) {
        return (x + other.x) % MOD;
    }

    mint operator-(const mint& other) {
        return (x + MOD - other.x) % MOD;
    }

    mint operator*(const mint& other) {
        return (x * other.x) % MOD;
    }

    mint operator/(int denominator) {
        int f_mod;
        int id3;
        nt::id2(denominator, MOD, &id3, &f_mod);
        while (id3 < 0)
            id3 += MOD;
        return (id3 * x) % MOD;
    }

    mint operator/(const mint& denominator) {
        return (*this) / denominator.x;
    }

    mint operator^(unsigned long n) {
        mint a = x;
        mint res = 1;

        while (n > 0) {
            if (n & 1)
                res = res * a;
            n = n >> 1;
            a = a * a;
        }

        return res;
    }
};

template <typename T>
mint operator* (T x, const mint& y) {
    return mint(x) * y;
}

namespace nt {

    std::vector<mint> id1(int n) {
        std::vector<mint> fact(n);
        fact[0] = 1;
        fact[1] = 1;
        for (int i = 2; i < fact.size(); ++i) {
            fact[i] = (i * fact[i - 1]);
        }
        return fact;
    }

    std::map<int, int> id0(int x) {
        std::map<int, int> primes;

        for (int d = 2; d * d <= x; ++d) {
            while (x % d == 0) {
                x /= d;
                primes[d] += 1;
            }
        }

        if (x > 1) {
            primes[x] = 1;
        }
        return primes;
    }

    std::vector<int> sieve(int N) {
        std::vector<int> primes(N+5, -1);

        for (int p = 2; p < primes.size(); ++p) {
            if (primes[p] == -1) {
                for (int i = p + p; i < primes.size(); i += p) {
                    if (primes[i] == -1) {
                        primes[i] = p;
                    }
                }
            }
        }
        return primes;
    }

    template <typename T>
    int gcd(T x, T y) {
        uint64_t xx = x;
        uint64_t yy = y;
        return std::__gcd(xx, yy);
    }


}







int START = 0;

template <typename T>
class SegmentTree : std::enable_shared_from_this<SegmentTree<T>> {
public:

    class Segment {
    public:
        size_t left;
        size_t right;
        

        SegmentTree<T>* segment_tree;

        Segment(size_t left, size_t right, SegmentTree<T>*  segment_tree)
            : left(left)
            , right(right)
            , segment_tree(segment_tree)
        {}

        T max() {
            return segment_tree->get_max(1, 0, segment_tree->size - 1, left, right);
        }

        T sum() {
            return segment_tree->get_sum(1, 0, segment_tree->size - 1, left, right);
        }

        size_t lower_bound(T value) {
            return segment_tree->lower_bound(1, 0, segment_tree->size - 1, left, right, value);
        }

        void operator=(T element) {
            segment_tree->assign_element(1, 0, segment_tree->size - 1, left, right, element);
        }

        operator T() {
            if (left == right)
                return segment_tree->get_max(1, 0, segment_tree->size - 1, left, right);
            else
                throw "left != right";
        }

        bool operator< (T other) {
            return T(*this) < other;
        }

        bool operator<= (T other) {
            return T(*this) <= other;
        }


    };


    explicit SegmentTree(const std::vector<T>& values)
        : size(values.size())
        , tree(values.size() * 4)
        , bounds(tree.size())
    {
        build_tree(1, 0, size - 1, values);
    }

    Segment operator()(size_t left, size_t right) {
        

        return {left, right, this};
    }

    Segment operator[](size_t index) {
        

        return {index, index, this};
    }


    std::vector<T> vector() {
        std::vector<T> values(size);
        for (int i = 0; i < size; ++i) {
            values[i] = get_max(1, 0, size - 1, i, i);
        }
        return values;
    }


public:

    const T NONE = std::numeric_limits<T>::max();
    const int SUM = 0;
    const int MAX = 1;
    const int COLOR = 2;

    void build_tree(size_t vertex, size_t tree_left, size_t tree_right, const std::vector<T>& values) {
        bounds[vertex] = {tree_left, tree_right};
        if (tree_left == tree_right) {
            tree[vertex] = {values[tree_left], values[tree_left], values[tree_left]};
        } else {
            size_t tree_middle = (tree_left + tree_right) >> 1;
            build_tree(vertex << 1, tree_left, tree_middle, values);
            build_tree((vertex << 1) + 1, tree_middle + 1, tree_right, values);
            tree[vertex] = {std::get<0>(tree[vertex << 1]) + std::get<0>(tree[(vertex << 1) + 1]),
                            std::max(std::get<1>(tree[vertex << 1]), std::get<1>(tree[(vertex << 1) + 1])),
                            NONE};
        }
    }

    T get_max(size_t vertex, size_t tree_left, size_t tree_right, size_t left, size_t right) {
        if (left == tree_left && right == tree_right) {
            return std::get<1>(tree[vertex]);
        }

        if (std::get<2>(tree[vertex]) != NONE) {
            return std::get<2>(tree[vertex]);
        }

        size_t tree_middle = (tree_left + tree_right) >> 1;

        if (left > std::min(right, tree_middle)) {
            return get_max((vertex << 1) + 1, tree_middle + 1, tree_right, std::max(left, tree_middle + 1), right);
        }

        if (std::max(left, tree_middle + 1) > right) {
            return get_max((vertex << 1), tree_left, tree_middle, left, std::min(right, tree_middle));
        }

        return std::max(
                get_max((vertex << 1) + 1, tree_middle + 1, tree_right, std::max(left, tree_middle + 1), right),
                get_max((vertex << 1), tree_left, tree_middle, left, std::min(right, tree_middle))
        );
    }

    T get_sum(size_t vertex, size_t tree_left, size_t tree_right, size_t left, size_t right) {

        START += 1;

        if (std::get<2>(tree[vertex]) != NONE) {
            return std::get<2>(tree[vertex]) * (right - left + 1);
        }

        if (left == tree_left && right == tree_right) {
            return std::get<0>(tree[vertex]);
        }



        size_t tree_middle = (tree_left + tree_right) >> 1;

        if (left > std::min(right, tree_middle)) {
            return get_sum((vertex << 1) + 1, tree_middle + 1, tree_right, std::max(left, tree_middle + 1), right);
        }

        if (std::max(left, tree_middle + 1) > right) {
            return get_sum((vertex << 1), tree_left, tree_middle, left, std::min(right, tree_middle));
        }

        return
                get_sum((vertex << 1) + 1, tree_middle + 1, tree_right, std::max(left, tree_middle + 1), right) +
                get_sum((vertex << 1), tree_left, tree_middle, left, std::min(right, tree_middle)
        );
    }


    size_t lower_bound(size_t vertex,
                       size_t tree_left,
                       size_t tree_right,
                       size_t left,
                       size_t right,
                       T value) {

        START += 1;

        T color = std::get<2>(tree[vertex]);
        if (color != NONE and color <= value) {
            return left;
        }

        if (color != NONE and color > value) {
            return tree_right + 1;
        }

        size_t tree_middle = (tree_left + tree_right) / 2;

        if (tree_left == left and std::get<1>(tree[vertex]) <= value) {
            return tree_left;
        }

        if (left >= tree_middle + 1) {
            return lower_bound(vertex * 2 + 1, tree_middle + 1, tree_right, left, right, value);
        }

        if (right <= tree_middle) {
            return lower_bound(vertex * 2, tree_left, tree_middle, left, right, value);
        }

        if (std::get<1>(tree[vertex * 2 + 1]) <= value) {
            return lower_bound(vertex * 2, tree_left, tree_middle, left, tree_middle, value);
        }

        if (std::get<1>(tree[vertex * 2 + 1]) > value) {
            return lower_bound(vertex * 2 + 1, tree_middle + 1, tree_right, tree_middle + 1, right, value);
        }
    }

    void assign_element(size_t vertex, size_t tree_left, size_t tree_right, size_t left, size_t right, T element) {

        START += 1;

        assert(tree_left <= left);
        assert(right <= tree_right);

        if (left > right) {
            T parent_value = std::get<2>(tree[vertex / 2]);
            if (vertex > 1 and parent_value != NONE) {
                tree[vertex] = {(tree_right - tree_left + 1) * parent_value, parent_value, parent_value};
            }
        } else if (left == tree_left && tree_right == right) {
            tree[vertex] = {(right - left + 1) * element, element, element};
        } else {
            size_t tree_middle = (tree_left + tree_right) / 2;

            T color = std::get<2>(tree[vertex]);
            if (color != NONE) {
                std::get<2>(tree[vertex * 2]) = color;
                std::get<2>(tree[vertex * 2 + 1]) = color;
            }

            assign_element(vertex * 2, tree_left, tree_middle, left, std::min(right, tree_middle), element);
            assign_element(vertex * 2 + 1, tree_middle + 1, tree_right,std::max(left, tree_middle + 1), right, element);

            tree[vertex] = {
                    std::get<0>(tree[vertex * 2]) + std::get<0>(tree[vertex * 2 + 1]),
                    std::max(std::get<1>(tree[vertex * 2]), std::get<1>(tree[vertex * 2 + 1])),
                    NONE
            };
        }
    }

    std::vector<std::tuple<T, T, T>> tree;
    std::vector<std::pair<int, int>> bounds;
    size_t size;
};

using namespace std;
struct Solver {
    void solve() {
        int t = 1;
        

        while (t--) solve_one();

        


        



    }

    void solve_one() {
        read2(n, q);
        auto a = ReadVector(n);
        SegmentTree<int> st(a);

        while(q--) {
            read(kind); read2(x, y);
            --x;

            if (kind == 1) {










                int start = st(0, x).lower_bound(y);
                if (start <= x) {
                    st(start, x) = y;
                }

            } else {

                int answer = 0;

















                while (x < n) {

                    int start = st(x, n - 1).lower_bound(y);
                    if (start > n - 1) {
                        break;
                    }

                    if (start == n - 1) {
                        answer += 1;
                        break;
                    }

                    int prefix = start == 0 ? 0 : st(0, start - 1).sum();
                    int remains = prefix + y;

                    int v = 1;
                    int color = st.NONE;
                    std::get<2>(st.tree[0]) = st.NONE;
                    while (remains > 0 and start < n) {
                        auto [left, right] = st.bounds[v];
                        int new_color = std::get<2>(st.tree[v]);

                        if (color == st.NONE and std::get<2>(st.tree[v / 2]) != st.NONE) {
                            color = std::get<2>(st.tree[v/2]);
                        }

                        int local_color = st.NONE;
                        if (local_color == st.NONE and new_color != st.NONE) {
                            local_color = new_color;
                        }

                        if (color != st.NONE)
                            local_color = color;

                        int v_sum = local_color != st.NONE ? local_color * (right - left + 1) : std::get<0>(st.tree[v]);
                        


                        

                        

                        


                        if (v_sum > remains) {
                            v = v * 2;
                        } else {
                            remains -= v_sum;
                            answer += right - start + 1;
                            start = right + 1;
                            x = right + 1;

                            if (st.bounds[v + 1].first == st.bounds[v + 1].second) {
                                break;
                            }
                            v  = (v + 1) * 2;
                        }
                        if (left == right)
                            break;
                    }

                    y = remains;
                }

                

                

                

                println(answer);
            }
        }
    }
};


int main() {
    IO_FAST
    Solver().solve();
    return 0;
}