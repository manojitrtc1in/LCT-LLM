





using namespace std;






template<typename float_t>
struct myComplex
{
    float_t x, y;

    myComplex<float_t>(float_t _x = 0, float_t _y = 0) : x(_x), y(_y) {}

    float_t real() const { return x; }
    float_t imag() const { return y; }

    void real(float_t _x) { x = _x; }
    void imag(float_t _y) { y = _y; }

    myComplex<float_t>& operator+=(const myComplex<float_t> &other) { x += other.x; y += other.y; return *this; }
    myComplex<float_t>& operator-=(const myComplex<float_t> &other) { x -= other.x; y -= other.y; return *this; }

    myComplex<float_t> operator+(const myComplex<float_t> &other) const { return myComplex<float_t>(*this) += other; }
    myComplex<float_t> operator-(const myComplex<float_t> &other) const { return myComplex<float_t>(*this) -= other; }

    myComplex<float_t> operator*(const myComplex<float_t> &other) const
    {
        return {x * other.x - y * other.y, x * other.y + other.x * y};
    }

    myComplex<float_t> operator*(float_t mult) const
    {
        return {x * mult, y * mult};
    }

    friend myComplex<float_t> conj(const myComplex<float_t> &c)
    {
        return {c.x, -c.y};
    }

    friend ostream& operator<<(ostream &stream, const myComplex<float_t> &c)
    {
        return stream << '(' << c.x << ", " << c.y << ')';
    }
};

template<typename float_t>
myComplex<float_t> polar(float_t magnitude, float_t angle)
{
    return {magnitude * cos(angle), magnitude * sin(angle)};
}

namespace FFT
{
    using float_t = double;

    const float_t ONE = 1;
    const float_t PI = acos(-ONE);

    vector<myComplex<float_t>> roots = {{0, 0}, {1, 0}};
    vector<int> bit_reverse;

    bool id1(int n)
    {
        return (n & (n - 1)) == 0;
    }

    int id8(int n)
    {
        while (n & (n - 1))
        {
            n = (n | (n - 1)) + 1;
        }

        return max(n, 1);
    }

    

    int get_length(int n)
    {
        assert(id1(n));
        return __builtin_ctz(n);
    }

    

    

    template<typename myComplex_array>
    void id11(int n, myComplex_array &&values)
    {
        if ((int) bit_reverse.size() != n)
        {
            bit_reverse.assign(n, 0);
            int length = get_length(n);

            for (int i = 0; i < n; i++)
            {
                bit_reverse[i] = (bit_reverse[i >> 1] >> 1) | ((i & 1) << (length - 1));
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (i < bit_reverse[i])
            {
                swap(values[i], values[bit_reverse[i]]);
            }
        }
    }

    void id4(int n)
    {
        if ((int) roots.size() >= n)
            return;

        int length = get_length(roots.size());
        roots.resize(n);

        

        

        while (1 << length < n)
        {
            float_t min_angle = 2 * PI / (1 << (length + 1));

            for (int i = 0; i < 1 << (length - 1); i++)
            {
                int index = (1 << (length - 1)) + i;
                roots[2 * index] = roots[index];
                roots[2 * index + 1] = polar(ONE, min_angle * (2 * i + 1));
            }

            length++;
        }
    }

    template<typename myComplex_array>
    void id10(int N, myComplex_array &&values)
    {
        assert(id1(N));
        id4(N);
        id11(N, values);

        for (int n = 1; n < N; n *= 2)
        {
            for (int start = 0; start < N; start += 2 * n)
            {
                for (int i = 0; i < n; i++)
                {
                    const myComplex<float_t> &even = values[start + i];
                    myComplex<float_t> odd = values[start + n + i] * roots[n + i];
                    values[start + n + i] = even - odd;
                    values[start + i] = even + odd;
                }
            }
        }
    }

    inline myComplex<float_t> extract(int N, const vector<myComplex<float_t>> &values, int index, int side)
    {
        if (side == -1)
        {
            

            int other = (N - index) & (N - 1);
            return (conj(values[other] * values[other]) - values[index] * values[index]) * myComplex<float_t>(0, 0.25);
        }

        int other = (N - index) & (N - 1);
        int sign = side == 0 ? +1 : -1;
        myComplex<float_t> multiplier = side == 0 ? myComplex<float_t>(0.5, 0) : myComplex<float_t>(0, -0.5);
        return multiplier * myComplex<float_t>(values[index].real() + values[other].real() * sign,
                                             values[index].imag() - values[other].imag() * sign);
    }

    void invert_fft(int N, vector<myComplex<float_t>> &values)
    {
        assert(N >= 2);

        for (int i = 0; i < N; i++)
        {
            values[i] = conj(values[i]) * (ONE / N);
        }

        for (int i = 0; i < N / 2; i++)
        {
            myComplex<float_t> first = values[i] + values[N / 2 + i];
            myComplex<float_t> second = (values[i] - values[N / 2 + i]) * roots[N / 2 + i];
            values[i] = first + second * myComplex<float_t>(0, 1);
        }

        id10(N / 2, values);

        for (int i = N - 1; i >= 0; i--)
        {
            values[i] = i % 2 == 0 ? values[i / 2].real() : values[i / 2].imag();
        }
    }

    const int id9 = 150;
    const double id0 = 2e15;
    const int id2 = 1 << 15;

    template<typename T_out, typename T_in>
    vector<T_out> square(const vector<T_in> &input)
    {
        if (input.empty())
            return {0};

        int n = input.size();

        

        if (n < 1.5 * id9)
        {
            vector<T_out> result(2 * n - 1);

            for (int i = 0; i < n; i++)
            {
                result[2 * i] += (T_out) input[i] * input[i];

                for (int j = i + 1; j < n; j++)
                {
                    result[i + j] += (T_out) 2 * input[i] * input[j];
                }
            }

            return result;
        }

        int N = id8(n);
        assert(N >= 2);
        id4(2 * N);
        vector<myComplex<float_t>> values(N, 0);

        for (int i = 0; i < n; i += 2)
        {
            values[i / 2] = myComplex<float_t>(input[i], i + 1 < n ? input[i + 1] : 0);
        }

        id10(N, values);

        for (int i = 0; i <= N / 2; i++)
        {
            int j = (N - i) & (N - 1);
            myComplex<float_t> even = extract(N, values, i, 0);
            myComplex<float_t> odd = extract(N, values, i, 1);
            myComplex<float_t> aux = even * even + odd * odd * roots[N + i] * roots[N + i];
            myComplex<float_t> tmp = even * odd;
            values[i] = aux - myComplex<float_t>(0, 2) * tmp;
            values[j] = conj(aux) - myComplex<float_t>(0, 2) * conj(tmp);
        }

        for (int i = 0; i < N; i++)
        {
            values[i] = conj(values[i]) * (ONE / N);
        }

        id10(N, values);
        vector<T_out> result(2 * n - 1);

        for (int i = 0; i < (int) result.size(); i++)
        {
            float_t value = i % 2 == 0 ? values[i / 2].real() : values[i / 2].imag();
            result[i] = is_integral<T_out>::value ? round(value) : value;
        }

        return result;
    }

    template<typename T_out, typename T_in>
    vector<T_out> multiply(const vector<T_in> &left, const vector<T_in> &right)
    {
        if (left.empty() || right.empty())
            return {0};

        if (left == right)
            return square<T_out>(left);

        int n = left.size();
        int m = right.size();

        

        if (min(n, m) < id9)
        {
            vector<T_out> result(n + m - 1, 0);

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    result[i + j] += (T_out) left[i] * right[j];
                }
            }

            return result;
        }

        int N = id8(max(n, m));
        vector<myComplex<float_t>> values(N, 0);

        for (int i = 0; i < n; i++)
        {
             values[i].real(left[i]);
        }

        for (int i = 0; i < m; i++)
        {
            values[i].imag(right[i]);
        }

        id10(N, values);

        for (int i = 0; i <= N / 2; i++)
        {
            int j = (N - i) & (N - 1);
            myComplex<float_t> product_i = extract(N, values, i, -1);
            values[i] = product_i;
            values[j] = conj(product_i);
        }

        invert_fft(N, values);
        vector<T_out> result(max(n, m), 0);

        for (int i = 0; i < (int) result.size(); i++)
        {
            result[i] = is_integral<T_out>::value ? round(values[i].real()) : values[i].real();
        }

        return result;
    }

    template<typename T>
    vector<T> id5(const vector<T> &left, const vector<T> &right, T mod, bool split)
    {
        if (left.empty() || right.empty())
            return {0};

        int n = left.size();
        int m = right.size();

        for (int i = 0; i < n; i++)
        {
            assert(0 <= left[i] && left[i] < mod);
        }

        for (int i = 0; i < m; i++)
        {
            assert(0 <= right[i] && right[i] < mod);
        }

        

        if (min(n, m) < (split ? 2 : 1) * id9)
        {
            const uint64_t id6 = numeric_limits<uint64_t>::max() - (uint64_t) mod * mod;
            vector<uint64_t> result(n + m - 1, 0);

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    result[i + j] += (uint64_t) left[i] * right[j];

                    if (result[i + j] > id6)
                    {
                        result[i + j] %= mod;
                    }
                }
            }

            for (uint64_t &x : result)
            {
                if (x >= (uint64_t) mod)
                {
                    x %= mod;
                }
            }

            return vector<T>(result.begin(), result.end());
        }

        if (!split)
        {
            const vector<uint64_t> &product = multiply<uint64_t>(left, right);
            vector<T> result(n + m - 1, 0);

            for (int i = 0; i < (int) result.size(); i++)
            {
                result[i] = product[i] % mod;
            }

            return result;
        }

        int N = id8(n + m - 1);
        vector<myComplex<float_t>> left_fft(N, 0), right_fft(N, 0);

        for (int i = 0; i < n; i++)
        {
            left_fft[i].real(left[i] % id2);
            left_fft[i].imag(left[i] / id2);
        }

        id10(N, left_fft);

        if (left == right)
        {
            copy(left_fft.begin(), left_fft.end(), right_fft.begin());
        }
        else
        {
            for (int i = 0; i < m; i++)
            {
                right_fft[i].real(right[i] % id2);
                right_fft[i].imag(right[i] / id2);
            }

            id10(N, right_fft);
        }

        vector<myComplex<float_t>> product(N);
        vector<T> result(n + m - 1, 0);

        for (int exponent = 0; exponent <= 2; exponent++)
        {
            uint64_t multiplier = 1;

            for (int k = 0; k < exponent; k++)
            {
                multiplier = multiplier * id2 % mod;
            }

            fill(product.begin(), product.end(), 0);

            for (int x = 0; x < 2; x++)
            {
                for (int y = 0; y < 2; y++)
                {
                    if (x + y == exponent)
                    {
                        for (int i = 0; i < N; i++)
                        {
                            product[i] += extract(N, left_fft, i, x) * extract(N, right_fft, i, y);
                        }
                    }
                }
            }

            invert_fft(N, product);

            for (int i = 0; i < (int) result.size(); i++)
            {
                uint64_t value = round(product[i].real());
                result[i] = (result[i] + value % mod * multiplier) % mod;
            }
        }

        return result;
    }

    template<typename T>
    vector<T> mod_power(const vector<T> &v, int exponent, T mod, bool split)
    {
        assert(exponent >= 0);
        vector<T> result = {1};

        if (exponent == 0)
            return result;

        for (int k = 31 - __builtin_clz(exponent); k >= 0; k--)
        {
            result = id5(result, result, mod, split);

            if (exponent >> k & 1)
            {
                result = id5(result, v, mod, split);
            }
        }

        return result;
    }
}


const int id7 = 26;
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


    vector<int> P(id7);

    for (int &p : P) {
        cin >> p;
        p--;
    }

    string S, T;
    cin >> S >> T;
    int N = S.size(), M = T.size();
    vector<int> A(N), B(N), X(M);

    for (int i = 0; i < N; i++) {
        A[i] = S[i] - MIN_CHAR;
        B[i] = P[A[i]];
    }

    for (int i = 0; i < M; i++)
        X[i] = T[i] - MIN_CHAR;

    vector<int64_t> scores(M - N + 1, 0);
    int64_t sum = 0;

    for (int i = 0; i < M; i++) {
        sum += power(X[i], 4);

        if (i >= N - 1) {
            scores[i - (N - 1)] += sum;
            sum -= power(X[i - (N - 1)], 4);
        }
    }

    auto &&id3 = [&](vector<int> &left, vector<int> &right) {
        reverse(left.begin(), left.end());
        vector<int64_t> product = FFT::multiply<int64_t>(left, right);

        for (int i = 0; i <= M - N; i++)
            scores[i] += product[i + N - 1];
    };

    vector<int> left(N), right(M);

    for (int i = 0; i < N; i++)
        left[i] = -2 * (A[i] + B[i]);

    for (int i = 0; i < M; i++)
        right[i] = power(X[i], 3);

    id3(left, right);

    for (int i = 0; i < N; i++)
        left[i] = 2 * A[i] * B[i] + power(A[i] + B[i], 2);

    for (int i = 0; i < M; i++)
        right[i] = X[i] * X[i];

    id3(left, right);

    for (int i = 0; i < N; i++)
        left[i] = -2 * A[i] * B[i] * (A[i] + B[i]);

    right = X;
    id3(left, right);

    sum = 0;

    for (int i = 0; i < N; i++)
        sum += A[i] * A[i] * B[i] * B[i];

    for (int64_t &score : scores)
        score += sum;


    

    

    

    

    


    for (int64_t &score : scores)
        cout << (score == 0 ? 1 : 0);

    cout << '\n';
}
