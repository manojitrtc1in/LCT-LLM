





using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }









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

namespace FFT {
    using float_t = double;

    const float_t ONE = 1;
    const float_t PI = acos(-ONE);

    vector<complex<float_t>> roots = {{0, 0}, {1, 0}};
    vector<int> bit_reverse;

    bool id1(int n) {
        return (n & (n - 1)) == 0;
    }

    int id9(int n) {
        while (n & (n - 1))
            n = (n | (n - 1)) + 1;

        return max(n, 1);
    }

    

    int get_length(int n) {
        assert(id1(n));
        return __builtin_ctz(n);
    }

    

    

    void id12(int n, vector<complex<float_t>> &values) {
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

    void id5(int n) {
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

    void id11(int n, vector<complex<float_t>> &values) {
        assert(id1(n));
        id5(n);
        id12(n, values);

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

        id11(n / 2, values);

        for (int i = n - 1; i >= 0; i--)
            values[i] = i % 2 == 0 ? values[i / 2].real() : values[i / 2].imag();
    }

    const int id10 = 150;
    const double id0 = 2e15;
    const int id2 = 1 << 15;

    template<typename T_out, typename T_in>
    vector<T_out> square(const vector<T_in> &input) {
        if (input.empty())
            return {};

        int n = int(input.size());


        

        double max_value = *max_element(input.begin(), input.end());
        assert(n * max_value * max_value < id0);


        

        if (n < 1.5 * id10) {
            vector<T_out> result(2 * n - 1);

            for (int i = 0; i < n; i++) {
                result[2 * i] += T_out(input[i]) * input[i];

                for (int j = i + 1; j < n; j++)
                    result[i + j] += T_out(2) * input[i] * input[j];
            }

            return result;
        }

        int N = id9(n);
        assert(N >= 2);
        id5(2 * N);
        vector<complex<float_t>> values(N, 0);

        for (int i = 0; i < n; i += 2)
            values[i / 2] = complex<float_t>(input[i], i + 1 < n ? input[i + 1] : 0);

        id11(N, values);

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

        id11(N, values);
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


        

        double max_left = *max_element(left.begin(), left.end());
        double max_right = *max_element(right.begin(), right.end());
        assert(max(n, m) * max_left * max_right < id0);


        int output_size = circular ? id9(max(n, m)) : n + m - 1;

        

        if (min(n, m) < id10) {
            auto &&id3 = [&](int x) {
                return x < output_size ? x : x - output_size;
            };

            vector<T_out> result(output_size, 0);

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    result[id3(i + j)] += T_out(left[i]) * right[j];

            return result;
        }

        int N = id9(output_size);
        vector<complex<float_t>> values(N, 0);

        for (int i = 0; i < n; i++)
            values[i].real(left[i]);

        for (int i = 0; i < m; i++)
            values[i].imag(right[i]);

        id11(N, values);

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

    

    

    vector<int> id6(const vector<int> &left, const vector<int> &right, int mod, bool split, bool circular = false) {
        if (left.empty() || right.empty())
            return {};

        int n = int(left.size());
        int m = int(right.size());

        for (int i = 0; i < n; i++)
            assert(0 <= left[i] && left[i] < mod);

        for (int i = 0; i < m; i++)
            assert(0 <= right[i] && right[i] < mod);


        

        assert(split || (double) max(n, m) * mod * mod < id0);


        int output_size = circular ? id9(max(n, m)) : n + m - 1;

        

        if (min(n, m) < (split ? 2 : 1) * id10) {
            auto &&id3 = [&](int x) {
                return x < output_size ? x : x - output_size;
            };

            const uint64_t id7 = numeric_limits<uint64_t>::max() - uint64_t(mod) * mod;
            vector<uint64_t> result(output_size, 0);

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    int index = id3(i + j);
                    result[index] += uint64_t(left[i]) * right[j];

                    if (result[index] > id7)
                        result[index] %= mod;
                }

            for (uint64_t &x : result)
                if (x >= uint64_t(mod))
                    x %= mod;

            return vector<int>(result.begin(), result.end());
        }

        if (!split) {
            const vector<uint64_t> &product = multiply<uint64_t>(left, right, circular);
            vector<int> result(output_size, 0);

            for (int i = 0; i < output_size; i++)
                result[i] = int(product[i] % mod);

            return result;
        }

        int N = id9(output_size);
        vector<complex<float_t>> left_fft(N, 0), right_fft(N, 0);

        for (int i = 0; i < n; i++) {
            left_fft[i].real(left[i] % id2);
            left_fft[i].imag(left[i] / id2);
        }

        id11(N, left_fft);

        if (left == right) {
            copy(left_fft.begin(), left_fft.end(), right_fft.begin());
        } else {
            for (int i = 0; i < m; i++) {
                right_fft[i].real(right[i] % id2);
                right_fft[i].imag(right[i] / id2);
            }

            id11(N, right_fft);
        }

        vector<complex<float_t>> product(N);
        vector<int> result(output_size, 0);

        for (int exponent = 0; exponent <= 2; exponent++) {
            uint64_t multiplier = 1;

            for (int k = 0; k < exponent; k++)
                multiplier = multiplier * id2 % mod;

            fill(product.begin(), product.end(), 0);

            for (int x = 0; x < 2; x++)
                for (int y = 0; y < 2; y++)
                    if (x + y == exponent)
                        for (int i = 0; i < N; i++)
                            product[i] += extract(N, left_fft, i, x) * extract(N, right_fft, i, y);

            invert_fft(N, product);

            for (int i = 0; i < output_size; i++) {
                uint64_t value = uint64_t(round(product[i].real()));
                result[i] = int((result[i] + value % mod * multiplier) % mod);
            }
        }

        return result;
    }

    vector<int> mod_power(const vector<int> &v, int exponent, int mod, bool split) {
        assert(exponent >= 0);
        vector<int> result = {1};

        if (exponent == 0)
            return result;

        for (int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
            result = id6(result, result, mod, split);

            if (exponent >> k & 1)
                result = id6(result, v, mod, split);
        }

        return result;
    }
}


const int id8 = 26;
const char MIN_CHAR = 'a';

int power(int x, int p) {
    int ans = 1;

    while (p-- > 0)
        ans *= x;

    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    cin.tie(nullptr);


    vector<int> P(id8);

    for (int &p : P) {
        cin >> p;
        p--;
    }

    string S, T;
    cin >> S >> T;
    int N = int(S.size()), M = int(T.size());
    vector<int> A(N), B(N), X(M);

    for (int i = 0; i < N; i++) {
        A[i] = S[i] - MIN_CHAR;
        B[i] = P[A[i]];
    }

    for (int i = 0; i < M; i++)
        X[i] = T[i] - MIN_CHAR;

    dbg(A, B, X);

    vector<int64_t> scores(M - N + 1, 0);
    int64_t sum = 0;

    for (int i = 0; i < M; i++) {
        sum += power(X[i], 4);

        if (i >= N - 1) {
            scores[i - (N - 1)] += sum;
            sum -= power(X[i - (N - 1)], 4);
        }
    }

    auto &&id4 = [&](vector<int> &left, vector<int> &right) {
        reverse(left.begin(), left.end());
        auto product = FFT::multiply<int64_t>(left, right, true);

        for (int i = 0; i <= M - N; i++)
            scores[i] += product[i + N - 1];
    };

    vector<int> left(N), right(M);

    for (int i = 0; i < N; i++)
        left[i] = -2 * (A[i] + B[i]);

    for (int i = 0; i < M; i++)
        right[i] = power(X[i], 3);

    id4(left, right);

    for (int i = 0; i < N; i++)
        left[i] = 2 * A[i] * B[i] + power(A[i] + B[i], 2);

    for (int i = 0; i < M; i++)
        right[i] = X[i] * X[i];

    id4(left, right);

    for (int i = 0; i < N; i++)
        left[i] = -2 * A[i] * B[i] * (A[i] + B[i]);

    right = X;
    id4(left, right);

    sum = 0;

    for (int i = 0; i < N; i++)
        sum += A[i] * A[i] * B[i] * B[i];

    for (int64_t &score : scores)
        score += sum;

    dbg(scores);

    

    

    

    

    


    for (int64_t &score : scores)
        cout << (score == 0 ? 1 : 0);

    cout << '\n';
}
