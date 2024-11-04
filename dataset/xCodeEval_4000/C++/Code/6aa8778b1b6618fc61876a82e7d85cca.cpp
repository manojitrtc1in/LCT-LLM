#include <iostream>
#include <vector>
#include <numeric>
#include <random>

#ifdef ONLINE_JUDGE
#define USE_FAST_IO
#pragma GCC target("avx,avx2,sse,sse2")
#endif

using namespace std;

template <typename T>
vector<T> adj_sums(const vector<T> &arr) {
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

const int MOD = 2 * distr(twister) + 1;

namespace Mult {

    

    inline int mul(int a, int b) {
        return (a * 1ll * b) % MOD;
    }

    

    inline void normalize(int &x) {
        if (x < 0) x += MOD;
        if (x >= MOD) x -= MOD;
    }

    inline int normalized(int x) {
        if (x < 0) return x + MOD;
        if (x >= MOD) return x - MOD;
        return x;
    }

    

    inline int fastdiv2(int x) {
        if ((x & 1) == 0) return x >> 1;
        return (x + MOD) >> 1;
    }

    

    

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

    

    

    

    void fill_dft(int *p, int m, int r, int step = 1) {
        if (r == 1) return;
        fill_dft(p, m, r / 2, 2 * step); 

        fill_dft(p + m * step, m, r / 2, 2 * step); 


        

        int* new_p = new int[m * r];
        fill(new_p, new_p + m * r, 0);
        for (int k = 0; k < r / 2; k++) {
            

            

            


            

            rotate(p + (step + 2 * k * step) * m, m, 2 * (m / r) * k, new_p + k * m);
            for (int i = 0; i < m; ++i) {
                new_p[k * m + i] += p[(2 * k * step) * m + i];
                normalize(new_p[k * m + i]);
            }

            

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

    

    

    

    void fill_inverse_dft(int *p, int m, int r, int step = 1) {
        if (r == 1) return;

        int *new_p = new int[m * r];
        int *buf = new int[m];
        for (int k = 0; k < r / 2; k++) {
            

            

            for (int i = 0; i < m; ++i) {
                new_p[2 * k * m + i] = fastdiv2(normalized(p[k * step * m + i] + p[(k + r / 2) * step * m + i]));
                

                new_p[(2 * k + 1) * m + i] = fastdiv2(normalized(p[k * step * m + i] - p[(k + r / 2) * step * m + i]));
            }
            rotate(new_p + (2 * k + 1) * m, m, 2 * m - 2 * (m / r) * k, buf);
            rotate(buf, m, 0, new_p + (2 * k + 1) * m);
        }

        for (int k = 0; k < r; k++) {
            rotate(new_p + k * m, m, 0, p + (k * step) * m);
        }

        delete[] new_p;
        delete[] buf;
        fill_inverse_dft(p, m, r / 2, 2 * step);
        fill_inverse_dft(p + m * step, m, r / 2, 2 * step);
    }

    

    

    

    

    void multiply_raw(int *p, int *q, int n, int *to) {
        

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
        

        fill(to, to + 6 * n, 0);
        for (int i = 0; i < r; ++i) {
            rotate(p + m * i, m, 0, to + 4 * n + 2 * m * i);
            rotate(to + 4 * n + 2 * m * i, 2 * m, (2 * m / r) * i, to + 2 * m * i);
            rotate(q + m * i, m, 0, to + 4 * n + 2 * m * i);
            rotate(to + 4 * n + 2 * m * i, 2 * m, (2 * m / r) * i, to + 2 * n + 2 * m * i);
        }

        


        fill_dft(to, 2 * m, r);
        fill_dft(to + 2 * n, 2 * m, r);
        for (int i = 0; i < r; ++i) {
            multiply_raw(to + 2 * m * i, to + 2 * n + 2 * m * i, 2 * m, to + 4 * n + 2 * m * i);
        }
        fill_inverse_dft(to + 4 * n, 2 * m, r);

        

        for (int i = 0; i < r; ++i) {
            rotate(to + 4 * n + 2 * m * i, 2 * m, 4 * m - (2 * m / r) * i, to + 2 * n + 2 * m * i);
        }

        

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
}; 



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
        pa[i] = (a[i] % MOD + MOD) % MOD;
    }
    for (int i = 0; i < (int) b.size(); ++i) {
        pb[i] = (b[i] % MOD + MOD) % MOD;
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
bool solve_for_two(int i, T da, T db) {
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
vector<int> find_solution_for_two(int i, T da, T db) {
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

    as = adj_sums(adj_sums(as));
    bs = adj_sums(adj_sums(bs));

    vector<int64_t> first_prods = scalar_products(as, vector<int64_t>(bs.begin() + 2, bs.end()));
    for (int64_t &i : as) {
        i--;
    }
    for (int64_t &i : bs) {
        i++;
    }
    vector<int64_t> second_prods = scalar_products(as, vector<int64_t>(bs.begin() + 2, bs.end()));
    for (int64_t &i : as) {
        i++;
    }
    for (int64_t &i : bs) {
        i--;
    }

    vector<int> sum_pairwise_diffs(n - m + 1);
    vector<int> sum_pairwise_sq_diffs(n - m + 1);

    auto shrink = [&](int64_t x) -> int {
        return (x % MOD + MOD) % MOD;
    };

    vector<int> as_square(n), bs_square(m);
    for (int i = 0; i < n; i++) {
        as_square[i] = Mult::mul(shrink(as[i]), shrink(as[i]));
    }
    for (int i = 0; i < m; i++) {
        bs_square[i] = Mult::mul(shrink(bs[i]), shrink(bs[i]));
    }

    int bs_square_sum = 0;

    for (int i = 2; i < m; i++) {
        sum_pairwise_sq_diffs[0] = Mult::normalized(sum_pairwise_sq_diffs[0] + as_square[i]);
        bs_square_sum = Mult::normalized(bs_square_sum + bs_square[i]);
    }

    for (int i = 1; i < n - m + 1; i++) {
        sum_pairwise_sq_diffs[i] = sum_pairwise_sq_diffs[i - 1];
        sum_pairwise_sq_diffs[i] = Mult::normalized(sum_pairwise_sq_diffs[i] + as_square[i + m - 1]);
        sum_pairwise_sq_diffs[i] = Mult::normalized(sum_pairwise_sq_diffs[i] - as_square[i + 1]);
    }

    for (int i = 0; i < n - m + 1; i++) {
        sum_pairwise_diffs[i] = Mult::normalized(first_prods[i + 2] - second_prods[i + 2] - (m - 2));
        sum_pairwise_sq_diffs[i] = Mult::normalized(sum_pairwise_sq_diffs[i] + bs_square_sum);
        sum_pairwise_sq_diffs[i] = shrink(sum_pairwise_sq_diffs[i] - 2 * first_prods[i + 2]);
    }

    auto get_as_source = [&as_source](int i) -> int64_t {
        if (i < 0) {
            return 0;
        }

        return as_source[i];
    };

    for (int i = 0; i < n - m + 1; i++) {
        if (sum_pairwise_diffs[i] <= m - 2 && sum_pairwise_diffs[i] == sum_pairwise_sq_diffs[i]) {
            bool ok = false;

            as[i] -= get_as_source(i - 1) * 2 + get_as_source(i - 2);
            as[i + 1] -= get_as_source(i - 1);

            int64_t good_p0, good_p1;
            for (int64_t p1 = as[i + 1] - bs[1] + 1; p1 >= as[i + 1] - bs[1]; p1--) {
                for (int64_t p0 = as[i] - 2 * p1 + 1 - bs[0]; p0 >= as[i] - bs[0] - 2 * p1; p0--) {
                    if (solve_for_two(i, p0, p1)) {
                        ok = true;
                        good_p0 = p0;
                        good_p1 = p1;
                    }
                }
            }

            as[i] += get_as_source(i - 1) * 2 + get_as_source(i - 2);
            as[i + 1] += get_as_source(i - 1);
 
            for (int j = i + 2; j < i + m; j++) {
                if (bs[j - i] - as[j] > 1) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                vector<int> answer = find_solution_for_two(i, good_p0, good_p1);
                as[i] -= 2 * good_p1 + good_p0 + get_as_source(i - 1) * 2 + get_as_source(i - 2);
                as[i + 1] -= good_p1 + get_as_source(i - 1);
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
#ifdef USE_FAST_IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int t; cin >> t;
    while (t--) {
        solve();
    }
}