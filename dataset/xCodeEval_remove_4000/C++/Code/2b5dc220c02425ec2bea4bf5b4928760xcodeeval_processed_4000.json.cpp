






using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }







namespace FFT {
    

    template<typename float_t>
    struct complex {
        float_t x, y;

        complex<float_t>(float_t _x = 0, float_t _y = 0) : x(_x), y(_y) {}

        float_t real() const { return x; }
        float_t imag() const { return y; }

        void real(float_t _x) { x = _x; }
        void imag(float_t _y) { y = _y; }

        complex<float_t>& operator+=(const complex<float_t> &other) { x += other.x; y += other.y; return *this; }
        complex<float_t>& operator-=(const complex<float_t> &other) { x -= other.x; y -= other.y; return *this; }

        complex<float_t> operator+(const complex<float_t> &other) const { return complex<float_t>(*this) += other; }
        complex<float_t> operator-(const complex<float_t> &other) const { return complex<float_t>(*this) -= other; }

        complex<float_t> operator*(const complex<float_t> &other) const {
            return {x * other.x - y * other.y, x * other.y + other.x * y};
        }

        complex<float_t> operator*(float_t mult) const {
            return {x * mult, y * mult};
        }

        friend complex<float_t> conj(const complex<float_t> &c) {
            return {c.x, -c.y};
        }

        friend ostream& operator<<(ostream &os, const complex<float_t> &c) {
            return os << '(' << c.x << ", " << c.y << ')';
        }
    };

    template<typename float_t>
    complex<float_t> polar(float_t magnitude, float_t angle) {
        return {magnitude * cos(angle), magnitude * sin(angle)};
    }

    using float_t = double;

    const float_t ONE = 1;
    const float_t PI = acos(-ONE);

    vector<complex<float_t>> roots = {{0, 0}, {1, 0}};
    vector<int> bit_reverse;

    bool id4(int n) {
        return (n & (n - 1)) == 0;
    }

    int id14(int n) {
        while (n & (n - 1))
            n = (n | (n - 1)) + 1;

        return max(n, 1);
    }

    

    int get_length(int n) {
        assert(id4(n));
        return __builtin_ctz(n);
    }

    

    

    void id17(int n, vector<complex<float_t>> &values) {
        if (int(bit_reverse.size()) != n) {
            bit_reverse.assign(n, 0);
            int length = get_length(n);

            for (int i = 1; i < n; i++)
                bit_reverse[i] = (bit_reverse[i >> 1] >> 1) | ((i & 1) << (length - 1));
        }

        for (int i = 0; i < n; i++)
            if (i < bit_reverse[i])
                swap(values[i], values[bit_reverse[i]]);
    }

    void id8(int n) {
        if (int(roots.size()) >= n)
            return;

        int length = get_length(int(roots.size()));
        roots.resize(n);

        

        

        while (1 << length < n) {
            float_t min_angle = 2 * PI / (1 << (length + 1));

            for (int i = 0; i < 1 << (length - 1); i++) {
                int index = (1 << (length - 1)) + i;
                roots[2 * index] = roots[index];
                roots[2 * index + 1] = polar(ONE, min_angle * (2 * i + 1));
            }

            length++;
        }
    }

    void id16(int n, vector<complex<float_t>> &values) {
        assert(id4(n));
        id8(n);
        id17(n, values);

        for (int len = 1; len < n; len *= 2)
            for (int start = 0; start < n; start += 2 * len)
                for (int i = 0; i < len; i++) {
                    const complex<float_t> &even = values[start + i];
                    complex<float_t> odd = values[start + len + i] * roots[len + i];
                    values[start + len + i] = even - odd;
                    values[start + i] = even + odd;
                }
    }

    inline complex<float_t> extract(int n, const vector<complex<float_t>> &values, int index, int side) {
        if (side == -1) {
            

            int other = (n - index) & (n - 1);
            return (conj(values[other] * values[other]) - values[index] * values[index]) * complex<float_t>(0, 0.25);
        }

        int other = (n - index) & (n - 1);
        int sign = side == 0 ? +1 : -1;
        complex<float_t> multiplier = side == 0 ? complex<float_t>(0.5, 0) : complex<float_t>(0, -0.5);
        return multiplier * complex<float_t>(values[index].real() + values[other].real() * sign,
                                             values[index].imag() - values[other].imag() * sign);
    }

    void invert_fft(int n, vector<complex<float_t>> &values) {
        assert(n >= 2);

        for (int i = 0; i < n; i++)
            values[i] = conj(values[i]) * (ONE / n);

        for (int i = 0; i < n / 2; i++) {
            complex<float_t> first = values[i] + values[n / 2 + i];
            complex<float_t> second = (values[i] - values[n / 2 + i]) * roots[n / 2 + i];
            values[i] = first + second * complex<float_t>(0, 1);
        }

        id16(n / 2, values);

        for (int i = n - 1; i >= 0; i--)
            values[i] = i % 2 == 0 ? values[i / 2].real() : values[i / 2].imag();
    }

    const int id15 = 150;
    const float_t id2 = 2e15;
    const int id5 = 1 << 15;

    template<typename T_out, typename T_in>
    vector<T_out> square(const vector<T_in> &input) {
        if (input.empty())
            return {};

        int n = int(input.size());


        

        float_t max_value = float_t(*max_element(input.begin(), input.end()));
        assert(n * max_value * max_value < id2);


        

        if (n < 1.5 * id15) {
            vector<T_out> result(2 * n - 1);

            for (int i = 0; i < n; i++) {
                result[2 * i] += T_out(input[i]) * T_out(input[i]);

                for (int j = i + 1; j < n; j++)
                    result[i + j] += 2 * T_out(input[i]) * T_out(input[j]);
            }

            return result;
        }

        int N = id14(n);
        assert(N >= 2);
        id8(2 * N);
        vector<complex<float_t>> values(N, 0);

        for (int i = 0; i < n; i += 2)
            values[i / 2] = complex<float_t>(float_t(input[i]), i + 1 < n ? float_t(input[i + 1]) : 0);

        id16(N, values);

        for (int i = 0; i <= N / 2; i++) {
            int j = (N - i) & (N - 1);
            complex<float_t> even = extract(N, values, i, 0);
            complex<float_t> odd = extract(N, values, i, 1);
            complex<float_t> aux = even * even + odd * odd * roots[N + i] * roots[N + i];
            complex<float_t> tmp = even * odd;
            values[i] = aux - complex<float_t>(0, 2) * tmp;
            values[j] = conj(aux) - complex<float_t>(0, 2) * conj(tmp);
        }

        for (int i = 0; i < N; i++)
            values[i] = conj(values[i]) * (ONE / N);

        id16(N, values);
        vector<T_out> result(2 * n - 1);

        for (int i = 0; i < int(result.size()); i++) {
            float_t value = i % 2 == 0 ? values[i / 2].real() : values[i / 2].imag();
            result[i] = T_out(is_integral<T_out>::value ? round(value) : value);
        }

        return result;
    }

    

    

    template<typename T_out, typename T_in>
    vector<T_out> multiply(const vector<T_in> &left, const vector<T_in> &right, bool circular = false) {
        if (left.empty() || right.empty())
            return {};

        if (left == right && !circular)
            return square<T_out>(left);

        int n = int(left.size());
        int m = int(right.size());


        

        float_t max_left = float_t(*max_element(left.begin(), left.end()));
        float_t max_right = float_t(*max_element(right.begin(), right.end()));
        assert(max(n, m) * max_left * max_right < id2);


        int output_size = circular ? id14(max(n, m)) : n + m - 1;

        

        if (min(n, m) < id15) {
            auto &&id6 = [&](int x) {
                return x < output_size ? x : x - output_size;
            };

            vector<T_out> result(output_size, 0);

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    result[id6(i + j)] += T_out(left[i]) * T_out(right[j]);

            return result;
        }

        int N = id14(output_size);
        vector<complex<float_t>> values(N, 0);

        for (int i = 0; i < n; i++)
            values[i].real(float_t(left[i]));

        for (int i = 0; i < m; i++)
            values[i].imag(float_t(right[i]));

        id16(N, values);

        for (int i = 0; i <= N / 2; i++) {
            int j = (N - i) & (N - 1);
            complex<float_t> product_i = extract(N, values, i, -1);
            values[i] = product_i;
            values[j] = conj(product_i);
        }

        invert_fft(N, values);
        vector<T_out> result(output_size, 0);

        for (int i = 0; i < output_size; i++)
            result[i] = T_out(is_integral<T_out>::value ? round(values[i].real()) : values[i].real());

        return result;
    }

    template<typename T>
    vector<T> power(const vector<T> &v, int exponent) {
        assert(exponent >= 0);
        vector<T> result = {1};

        if (exponent == 0)
            return result;

        for (int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
            result = multiply<T>(result, result);

            if (exponent >> k & 1)
                result = multiply<T>(result, v);
        }

        return result;
    }

    

    

    template<typename T>
    vector<T> id12(const vector<T> &left, const vector<T> &right, const int mod, bool split, bool circular = false) {
        if (left.empty() || right.empty())
            return {};

        int n = int(left.size());
        int m = int(right.size());

        for (int i = 0; i < n; i++)
            assert(0 <= left[i] && left[i] <= mod - 1);

        for (int i = 0; i < m; i++)
            assert(0 <= right[i] && right[i] <= mod - 1);


        

        assert(split || float_t(max(n, m)) * mod * mod < id2);


        int output_size = circular ? id14(max(n, m)) : n + m - 1;

        

        if (min(n, m) < (split ? 2 : 1) * id15) {
            auto &&id6 = [&](int x) {
                return x < output_size ? x : x - output_size;
            };

            const uint64_t id13 = numeric_limits<uint64_t>::max() - uint64_t(mod) * mod;
            vector<uint64_t> result(output_size, 0);

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    int index = id6(i + j);
                    result[index] += uint64_t(left[i]) * uint64_t(right[j]);

                    if (result[index] > id13)
                        result[index] %= mod;
                }

            for (uint64_t &x : result)
                if (x >= uint64_t(mod))
                    x %= mod;

            return vector<T>(result.begin(), result.end());
        }

        if (!split) {
            const vector<uint64_t> &product = multiply<uint64_t>(left, right, circular);
            vector<T> result(output_size, 0);

            for (int i = 0; i < output_size; i++)
                result[i] = T(product[i] % mod);

            return result;
        }

        int N = id14(output_size);
        vector<complex<float_t>> left_fft(N, 0), right_fft(N, 0);

        for (int i = 0; i < n; i++) {
            left_fft[i].real(int(left[i]) % id5);
            left_fft[i].imag(int(left[i]) / id5);
        }

        id16(N, left_fft);

        if (left == right) {
            copy(left_fft.begin(), left_fft.end(), right_fft.begin());
        } else {
            for (int i = 0; i < m; i++) {
                right_fft[i].real(int(right[i]) % id5);
                right_fft[i].imag(int(right[i]) / id5);
            }

            id16(N, right_fft);
        }

        vector<complex<float_t>> product(N);
        vector<T> result(output_size, 0);

        for (int exponent = 0; exponent <= 2; exponent++) {
            uint64_t multiplier = 1;

            for (int k = 0; k < exponent; k++)
                multiplier = multiplier * id5 % mod;

            fill(product.begin(), product.end(), 0);

            for (int x = 0; x < 2; x++)
                for (int y = 0; y < 2; y++)
                    if (x + y == exponent)
                        for (int i = 0; i < N; i++)
                            product[i] += extract(N, left_fft, i, x) * extract(N, right_fft, i, y);

            invert_fft(N, product);

            for (int i = 0; i < output_size; i++) {
                uint64_t value = uint64_t(round(product[i].real()));
                result[i] = T((uint64_t(result[i]) + value % mod * multiplier) % mod);
            }
        }

        return result;
    }

    template<typename T>
    vector<T> mod_power(const vector<T> &v, int exponent, const int mod, bool split) {
        assert(exponent >= 0);
        vector<T> result = {1};

        if (exponent == 0)
            return result;

        for (int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
            result = id12(result, result, mod, split);

            if (exponent >> k & 1)
                result = id12(result, v, mod, split);
        }

        return result;
    }

    

    template<typename T>
    vector<T> id1(const vector<vector<T>> &polynomials, const int mod, bool split) {
        if (polynomials.empty())
            return {1};

        struct compare_size {
            bool operator()(const vector<T> &x, const vector<T> &y) {
                return x.size() > y.size();
            }
        };

        priority_queue<vector<T>, vector<vector<T>>, compare_size> pq(polynomials.begin(), polynomials.end());

        while (pq.size() > 1) {
            vector<T> a = pq.top(); pq.pop();
            vector<T> b = pq.top(); pq.pop();
            pq.push(id12(a, b, mod, split));
        }

        return pq.top();
    }
}

vector<int> id0;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
    maximum = max(maximum, 2);
    id0.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            id0[p] = p;
            primes.push_back(p);

            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    id0[i] = p;
                }
        }
}





vector<pair<int64_t, int>> id3(int64_t n) {
    int64_t id10 = int64_t(id0.size()) - 1;
    assert(1 <= n && n <= id10 * id10);
    vector<pair<int64_t, int>> result;

    if (n <= id10) {
        while (n != 1) {
            int64_t p = id0[n];
            int exponent = 0;

            do {
                n /= p;
                exponent++;
            } while (n % p == 0);

            result.emplace_back(p, exponent);
        }

        return result;
    }

    for (int64_t p : primes) {
        if (p * p > n)
            break;

        if (n % p == 0) {
            result.emplace_back(p, 0);

            do {
                n /= p;
                result.back().second++;
            } while (n % p == 0);
        }
    }

    if (n > 1)
        result.emplace_back(n, 1);

    return result;
}



const int id7 = 185000;

int64_t factors[id7];

int id9(const vector<pair<int64_t, int>> &id11, bool sorted = false) {
    static int64_t buffer[id7];
    int f_size = 0;
    factors[f_size++] = 1;

    for (auto &pf : id11) {
        int64_t p = pf.first;
        int exponent = pf.second;
        int before_size = f_size;

        for (int e = 1; e <= exponent; e++)
            for (int i = 0; i < before_size; i++) {
                factors[f_size] = factors[f_size - before_size] * p;
                f_size++;
            }

        if (sorted && factors[before_size - 1] > p)
            for (int section = before_size; section < f_size; section *= 2)
                for (int i = 0; i + section < f_size; i += 2 * section) {
                    int length = min(2 * section, f_size - i);
                    merge(factors + i, factors + i + section, factors + i + section, factors + i + length, buffer);
                    copy(buffer, buffer + length, factors + i);
                }
    }

    return f_size;
}


const int L_MAX = 1e6 + 5;

int main() {
    ios::sync_with_stdio(false);

    cin.tie(nullptr);


    sieve(L_MAX);

    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> lines(X + 1, 0);

    for (int i = 0; i <= N; i++) {
        int a;
        cin >> a;
        lines[a] = 1;
    }

    vector<int> rev_lines = lines;
    reverse(rev_lines.begin(), rev_lines.end());
    vector<int> product = FFT::multiply<int>(lines, rev_lines);
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int len;
        cin >> len;
        len /= 2;
        int F = id9(id3(len));
        int best = -1;

        for (int f = 0; f < F; f++) {
            int factor = int(factors[f]);

            if (factor > Y && factor - Y <= X && product[X + factor - Y] != 0)
                best = max(best, 2 * factor);
        }

        cout << best << (q < Q - 1 ? ' ' : '\n');
    }
}
