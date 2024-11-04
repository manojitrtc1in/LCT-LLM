









using namespace std;

template <typename T>
vector<T> id9(const vector<T> &arr) {
    int n = arr.size();
    vector<T> res(n);
    res[0] = arr[0];
    for (int i = 1; i < n; i++) {
        res[i] = arr[i] + arr[i - 1];
    }
    return res;
}

random_device rd;
mt19937 twister(rd());
uniform_int_distribution<int> distr(0, 528'000'000);

const int MOD = 1'000'000'009;

namespace Mult {

    // Multiplies integers in Z_p without overflow
    inline int mul(int a, int b) {
        return (a * 1ll * b) % MOD;
    }

    // To avoid using operator% while adding numbers
    inline void normalize(int &x) {
        if (x < 0) x += MOD;
        if (x >= MOD) x -= MOD;
    }

    inline int normalized(int x) {
        if (x < 0) return x + MOD;
        if (x >= MOD) return x - MOD;
        return x;
    }

    // we can divide by 2 without using multiplication by its inverse
    inline int id13(int x) {
        if ((x & 1) == 0) return x >> 1;
        return (x + MOD) >> 1;
    }

    // Places result of p * x^t in Z_p[x]/(x^m + 1) in to
    // Runtime O(m)
    void rotate(int *p, int m, int t, int *to) {
        bool negate = false;
        if (t >= m) {
            negate = true;
            t -= m;
        }
        for (int i = 0; i < m - t; ++i) {
            to[i + t] = p[i];
        }
        for (int i = m - t; i < m; ++i) {
            to[i + t - m] = normalized(-p[i]);
        }
        if (negate) {
            for (int i = 0; i < m; ++i) {
                to[i] = normalized(-to[i]);
            }
        }
    }

    // In-Place 2-radix DFT
    // Evaluates polynomial from Z_p[x]/(x^m + 1)[y]/(y^r - 1) in x^0, x^(2m/r), x^(4m/r),... x^((2m/r) * (r - 1))
    // Places result in coefficients, runtime O(mr log r)
    void id1(int *p, int m, int r, int step = 1) {
        if (r == 1) return;
        id1(p, m, r / 2, 2 * step); // even
        id1(p + m * step, m, r / 2, 2 * step); // odd

        // Default scheme
        int* new_p = new int[m * r];
        fill(new_p, new_p + m * r, 0);
        for (int k = 0; k < r / 2; k++) {
            // new_p[k] = p[2 * k * step] + w_n^k * p[step + 2 * k * step]
            // new_p[k + n / 2] = p[2 * k * step] - w_n^k * p[step + 2 * k * step]
            // so w_n^k is x^(2m * k /r)

            // construct new_p[k]
            rotate(p + (step + 2 * k * step) * m, m, 2 * (m / r) * k, new_p + k * m);
            for (int i = 0; i < m; ++i) {
                new_p[k * m + i] += p[(2 * k * step) * m + i];
                normalize(new_p[k * m + i]);
            }

            // construct new_p[k + r / 2]
            rotate(p + (step + 2 * k * step) * m, m, 2 * (m / r) * k, new_p + (k + r / 2) * m);
            for (int i = 0; i < m; ++i) {
                new_p[(k + r / 2) * m + i] = -new_p[(k + r / 2) * m + i];
                new_p[(k + r / 2) * m + i] += p[(2 * k * step) * m + i];
                normalize(new_p[(k + r / 2) * m + i]);
            }
        }

        for (int k = 0; k < r; k++) {
            rotate(new_p + k * m, m, 0, p + (k * step) * m);
        }

        delete[] new_p;
    }

    // In-Place 2-radix inverse DFT
    // "Interpolates" polynomial in Z_p[x]/(x^m + 1)[y]/(x^r - 1) by values in x^0, x^(2m/r), ..., x^((2m/r) * (r - 1))
    // Places result in values, runtime O(mr log r)
    void id0(int *p, int m, int r, int step = 1) {
        if (r == 1) return;

        int *new_p = new int[m * r];
        int *buf = new int[m];
        for (int k = 0; k < r / 2; k++) {
            // new_p[2 * k] = (p[k] + p[k + n / 2]) * 2^{-1}
            // new_p[2 * k + 1] = (p[k] - p[k + n / 2]) * w_n^{n - k} * 2^{-1}
            for (int i = 0; i < m; ++i) {
                new_p[2 * k * m + i] = id13(normalized(p[k * step * m + i] + p[(k + r / 2) * step * m + i]));
                // rotating by 2m - 2k * m/r
                new_p[(2 * k + 1) * m + i] = id13(normalized(p[k * step * m + i] - p[(k + r / 2) * step * m + i]));
            }
            rotate(new_p + (2 * k + 1) * m, m, 2 * m - 2 * (m / r) * k, buf);
            rotate(buf, m, 0, new_p + (2 * k + 1) * m);
        }

        for (int k = 0; k < r; k++) {
            rotate(new_p + k * m, m, 0, p + (k * step) * m);
        }

        delete[] new_p;
        delete[] buf;
        id0(p, m, r / 2, 2 * step);
        id0(p + m * step, m, r / 2, 2 * step);
    }

    // Multiplies two polynomials in Z_p[x]/(x^n + 1), n must be power of 2
    // Result is placed in to
    // WARNING: to must have extra 8n space, this extra space will be used as buffer
    // Runtime O(n log n log log n)
    void multiply_raw(int *p, int *q, int n, int *to) {
        // O(n^2) multiplication for small n
        if (n <= 32) {
            for (int i = 0; i < n; ++i) {
                to[i] = 0;
            }

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n - i; ++j) {
                    to[i + j] += mul(p[i], q[j]);
                    normalize(to[i + j]);
                }
                for (int j = n - i; j < n; ++j) {
                    to[i + j - n] -= mul(p[i], q[j]);
                    normalize(to[i + j - n]);
                }
            }
            return;
        }

        int m = 1;
        while (m * 1ll * m < n / 2) {
            m *= 2;
        }
        int r = n / m;
        // Expand to ring Z_p[x]/(x^{2m} + 1)[y]/(y^r + 1), then use map y -> x^{2m/r}y to hop to Z_p[x]/(x^{2m} + 1)[y]/(y^r - 1)
        fill(to, to + 6 * n, 0);
        for (int i = 0; i < r; ++i) {
            rotate(p + m * i, m, 0, to + 4 * n + 2 * m * i);
            rotate(to + 4 * n + 2 * m * i, 2 * m, (2 * m / r) * i, to + 2 * m * i);
            rotate(q + m * i, m, 0, to + 4 * n + 2 * m * i);
            rotate(to + 4 * n + 2 * m * i, 2 * m, (2 * m / r) * i, to + 2 * n + 2 * m * i);
        }

        // Multiply in that ring using DFT

        id1(to, 2 * m, r);
        id1(to + 2 * n, 2 * m, r);
        for (int i = 0; i < r; ++i) {
            multiply_raw(to + 2 * m * i, to + 2 * n + 2 * m * i, 2 * m, to + 4 * n + 2 * m * i);
        }
        id0(to + 4 * n, 2 * m, r);

        // Now unmap to hop back to Z_p[x]/(x^{2m} + 1)[y]/(y^r + 1) via y -> x^{4m - 2m/r}y
        for (int i = 0; i < r; ++i) {
            rotate(to + 4 * n + 2 * m * i, 2 * m, 4 * m - (2 * m / r) * i, to + 2 * n + 2 * m * i);
        }

        // Deduce result of multiplication by unravelling y = x^m
        fill(to, to + n, 0);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < 2 * m; ++j) {
                int pos = m * i + j;
                bool negate = false;
                if (pos >= n) {
                    pos -= n;
                    negate = true;
                }
                if (negate) {
                    to[pos] -= to[2 * n + 2 * m * i + j];
                } else {
                    to[pos] += to[2 * n + 2 * m * i + j];
                }
                normalize(to[pos]);
            }
        }
    }
}; // namespace Mult


const int MAX_MEM = 10000000;
int buf[MAX_MEM];

template <typename T>
vector<T> multiply(const vector<T> &a, const vector<T> &b) {
    int sz = 1;
    while (sz < (int) a.size() + (int) b.size() - 1) {
        sz *= 2;
    }
    int* pa = new int[sz];
    int* pb = new int[sz];
    fill(pa, pa + sz, 0);
    fill(pb, pb + sz, 0);
    for (int i = 0; i < (int) a.size(); ++i) {
        pa[i] = Mult::normalized(a[i] % MOD);
    }
    for (int i = 0; i < (int) b.size(); ++i) {
        pb[i] = Mult::normalized(b[i] % MOD);
    }
    Mult::multiply_raw(pa, pb, sz, buf); 
    vector<T> res(a.size() + b.size() - 1);
    for (int i = 0; i < (int) res.size(); ++i) {
        res[i] = buf[i];
    }
    delete[] pa;
    delete[] pb;
    return res;
}

template <typename T>
vector<T> scalar_products(const vector<T> &a, const vector<T> &b) {
    int n = a.size(), m = b.size();
    vector<T> v(n), u(n);
    for (int i = 0; i < m; i++) {
        u[i] = b[m - i - 1];
    }
    for (int i = 0; i < n; i++) {
        v[i] = a[i];
    }
    vector<T> prod = multiply(v, u);
    int res_size = n - m + 1;
    int end = n - 1;
    return vector<T>(prod.begin() + end - res_size + 1, prod.begin() + end + 1);
}

template <typename T>
bool id3(int i, T da, T db) {
    if (i == 0) {
        return da == 0 && db == 0;
    }
    if (i == 1) {
        return (db == 1 || db == 0) && da == 0;
    }
    
    T new_da = da - db;
    T new_db = da + db;

    int k = (i + 1) / 2;

    T offset_a = k + 2 * k * 1ll * (k - 1);
    new_da += offset_a;
    new_db -= k;
    new_db = -new_db;

    if (new_db < 0 || new_db > i) {
        return false;
    }

    new_da -= new_db;
    new_da /= 2;

    T lo = new_db * (new_db - 1) / 2;
    T hi = i * 1ll * new_db - new_db * (new_db + 1) / 2;
    return lo <= new_da && new_da <= hi;
}

template <typename T>
vector<int> id10(int i, T da, T db) {
    if (i == 0) {
        return {};
    }
    if (i == 1) {
        return (db == 1 ? vector<int>({0}) : vector<int>());
    }
    
    T new_da = da - db;
    T new_db = da + db;

    int k = (i + 1) / 2;

    T offset_a = k + 2 * k * 1ll * (k - 1);
    new_da += offset_a;
    new_db -= k;
    new_db = -new_db;

    new_da -= new_db;
    new_da /= 2;

    vector<int> res(new_db);
    iota(res.begin(), res.end(), 0);

    T cur_sum = new_db * (new_db - 1) / 2;
    int ptr = new_db - 1;

    while (cur_sum < new_da) {
        int old_val = res[ptr];
        int delta = min(new_da - cur_sum, i - (new_db - ptr) - old_val);
        res[ptr] += delta;
        cur_sum += delta;
        ptr--;
    }

    vector<bool> cum(i);
    for (int k : res) {
        cum[k] = true;
    }
    res = {};
    for (int j = 0; j < i; j++) {
        if (j % 2 == 0) {
            cum[j] = not cum[j];
        }
        if (cum[j]) {
            res.push_back(i - 1 - j);
        }
    }

    return res;
}


void solve() {
    int n; cin >> n;
    vector<int64_t> as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }

    int m; cin >> m;
    vector<int64_t> bs(m);
    for (int i = 0; i < m; i++) {
        cin >> bs[i];
    }

    vector<int64_t> as_source = as, bs_source = bs;

    as = id9(id9(as));
    bs = id9(id9(bs));

    vector<int64_t> id8 = scalar_products(as, vector<int64_t>(bs.begin() + 2, bs.end()));
    for (int64_t &i : as) {
        i--;
    }
    for (int64_t &i : bs) {
        i++;
    }
    vector<int64_t> id2 = scalar_products(as, vector<int64_t>(bs.begin() + 2, bs.end()));
    for (int64_t &i : as) {
        i++;
    }
    for (int64_t &i : bs) {
        i--;
    }

    vector<int> id12(n - m + 1);
    vector<int> id11(n - m + 1);

    auto shrink = [&](int64_t x) -> int {
        return Mult::normalized(x % MOD);
    };

    vector<int> as_square(n), bs_square(m);
    for (int i = 0; i < n; i++) {
        as_square[i] = Mult::mul(shrink(as[i]), shrink(as[i]));
    }
    for (int i = 0; i < m; i++) {
        bs_square[i] = Mult::mul(shrink(bs[i]), shrink(bs[i]));
    }

    int id5 = 0;

    for (int i = 2; i < m; i++) {
        id11[0] = Mult::normalized(id11[0] + as_square[i]);
        id5 = Mult::normalized(id5 + bs_square[i]);
    }

    for (int i = 1; i < n - m + 1; i++) {
        id11[i] = id11[i - 1];
        id11[i] = Mult::normalized(id11[i] + as_square[i + m - 1]);
        id11[i] = Mult::normalized(id11[i] - as_square[i + 1]);
    }

    for (int i = 0; i < n - m + 1; i++) {
        id12[i] = Mult::normalized(id8[i + 2] - id2[i + 2] - (m - 2));
        id11[i] = Mult::normalized(id11[i] + id5);
        id11[i] = shrink(id11[i] - 2 * id8[i + 2]);
    }

    auto id6 = [&as_source](int i) -> int64_t {
        if (i < 0) {
            return 0;
        }

        return as_source[i];
    };

    for (int i = 0; i < n - m + 1; i++) {
        if (id12[i] <= m - 2 && id12[i] == id11[i]) {
            bool ok = false;

            as[i] -= id6(i - 1) * 2 + id6(i - 2);
            as[i + 1] -= id6(i - 1);

            int64_t id7, id4;
            for (int64_t p1 = as[i + 1] - bs[1] + 1; p1 >= as[i + 1] - bs[1]; p1--) {
                for (int64_t p0 = as[i] - 2 * p1 + 1 - bs[0]; p0 >= as[i] - bs[0] - 2 * p1; p0--) {
                    if (id3(i, p0, p1)) {
                        ok = true;
                        id7 = p0;
                        id4 = p1;
                    }
                }
            }

            as[i] += id6(i - 1) * 2 + id6(i - 2);
            as[i + 1] += id6(i - 1);
 
            for (int j = i + 2; j < i + m; j++) {
                if (bs[j - i] - as[j] > 1) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                vector<int> answer = id10(i, id7, id4);
                as[i] -= 2 * id4 + id7 + id6(i - 1) * 2 + id6(i - 2);
                as[i + 1] -= id4 + id6(i - 1);
                for (int j = i; j < i + m; j++) {
                    if (bs[j - i] - as[j] == 1) {
                        answer.push_back(j);
                    }
                }
                
                cout << answer.size() << endl;
                for (int i : answer) {
                    cout << i + 1 << ' ';
                }
                cout << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}