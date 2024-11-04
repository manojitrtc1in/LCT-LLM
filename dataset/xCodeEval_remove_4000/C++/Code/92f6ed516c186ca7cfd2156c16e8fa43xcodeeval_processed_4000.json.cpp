














using namespace std;







typedef vector<int> vi;





typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

template<typename float_t>
struct fast_complex {
    

    float_t x, y;

    fast_complex<float_t>(float_t _x = 0, float_t _y = 0) : x(_x), y(_y) {}

    float_t real() const {
        return x;
    }

    void real(float_t _x) {
        x = _x;
    }

    float_t imag() const {
        return y;
    }

    void imag(float_t _y) {
        y = _y;
    }

    fast_complex<float_t>& operator+=(const fast_complex<float_t> &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    fast_complex<float_t>& operator-=(const fast_complex<float_t> &other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    fast_complex<float_t> operator+(const fast_complex<float_t> &other) const {
        return fast_complex<float_t>(*this) += other;
    }

    fast_complex<float_t> operator-(const fast_complex<float_t> &other) const {
        return fast_complex<float_t>(*this) -= other;
    }

    fast_complex<float_t> operator*(const fast_complex<float_t> &other) const {
        return {x * other.x - y * other.y, x * other.y + other.x * y};
    }
};

template<typename float_t>
fast_complex<float_t> id9(const fast_complex<float_t> &c) {
    return {c.x, -c.y};
}

template<typename float_t>
fast_complex<float_t> id0(float_t magnitude, float_t angle) {
    return {magnitude * cos(angle), magnitude * sin(angle)};
}

template<typename float_t>
ostream& operator<<(ostream &stream, const fast_complex<float_t> &c) {
    return stream << '(' << c.x << ", " << c.y << ')';
}


namespace FFT {
    typedef double float_t;
    const float_t ONE = 1;
    const float_t PI = acos(-ONE);

    vector<fast_complex<float_t>> roots;
    vector<int> bit_reverse;

    bool id3(int n) {
        return (n & (n - 1)) == 0;
    }

    int id1(int n) {
        assert(n > 0);

        while (n & (n - 1))
            n = (n | (n - 1)) + 1;

        return n;
    }

    

    int get_length(int n) {
        assert(id3(n));
        return __builtin_ctz(n);
    }

    

    

    template<typename fast_complex_array>
    void id10(int n, fast_complex_array &&values) {
        if ((int) bit_reverse.size() != n) {
            bit_reverse.assign(n, 0);
            int length = get_length(n);

            for (int i = 0; i < n; i++)
                bit_reverse[i] = (bit_reverse[i >> 1] >> 1) + ((i & 1) << (length - 1));
        }

        for (int i = 0; i < n; i++)
            if (i < bit_reverse[i])
                swap(values[i], values[bit_reverse[i]]);
    }

    void id2(int n) {
        if ((int) roots.size() >= n)
            return;

        if (roots.empty())
            roots = {{0, 0}, {1, 0}};

        int length = get_length(roots.size());
        roots.resize(n);

        

        

        while (1 << length < n) {
            double min_angle = 2 * PI / (1 << (length + 1));

            for (int i = 0; i < 1 << (length - 1); i++) {
                int index = (1 << (length - 1)) + i;
                roots[2 * index] = roots[index];
                roots[2 * index + 1] = id0(ONE, min_angle * (2 * i + 1));
            }

            length++;
        }
    }

    template<typename fast_complex_array>
    void fft_recursive(int n, fast_complex_array &&values, int depth = 0) {
        if (n <= 1)
            return;

        if (depth == 0) {
            assert(id3(n));
            id2(n);
            id10(n, values);
        }

        n /= 2;
        fft_recursive(n, values, depth + 1);
        fft_recursive(n, values + n, depth + 1);

        for (int i = 0; i < n; i++) {
            const fast_complex<float_t> &even = values[i];
            fast_complex<float_t> odd = values[n + i] * roots[n + i];
            values[n + i] = even - odd;
            values[i] = even + odd;
        }
    }

    

    template<typename fast_complex_array>
    void id6(int N, fast_complex_array &&values) {
        assert(id3(N));
        id2(N);
        id10(N, values);

        for (int n = 1; n < N; n *= 2)
            for (int start = 0; start < N; start += 2 * n)
                for (int i = 0; i < n; i++) {
                    const fast_complex<float_t> &even = values[start + i];
                    fast_complex<float_t> odd = values[start + n + i] * roots[n + i];
                    values[start + n + i] = even - odd;
                    values[start + i] = even + odd;
                }
    }

    inline fast_complex<float_t> extract(int N, const vector<fast_complex<float_t>> &values, int index, int side) {
        if (side == -1) {
            

            int other = (N - index) & (N - 1);
            return (id9(values[other] * values[other]) - values[index] * values[index]) * fast_complex<float_t>(0, 0.25);
        }

        int other = (N - index) & (N - 1);
        int sign = side == 0 ? +1 : -1;
        fast_complex<float_t> multiplier = side == 0 ? fast_complex<float_t>(0.5, 0) : fast_complex<float_t>(0, -0.5);
        return multiplier * fast_complex<float_t>(values[index].real() + values[other].real() * sign,
                                             values[index].imag() - values[other].imag() * sign);
    }

    void invert_fft(int N, vector<fast_complex<float_t>> &values) {
        assert(N >= 2);

        for (int i = 0; i < N; i++)
            values[i] = id9(values[i]) * (ONE / N);

        for (int i = 0; i < N / 2; i++) {
            fast_complex<float_t> first = values[i] + values[N / 2 + i];
            fast_complex<float_t> second = (values[i] - values[N / 2 + i]) * roots[N / 2 + i];
            values[i] = first + second * fast_complex<float_t>(0, 1);
        }

        fft_recursive(N / 2, values.begin());

        for (int i = N - 1; i >= 0; i--)
            values[i] = i % 2 == 0 ? values[i / 2].real() : values[i / 2].imag();
    }

    const int id4 = 150;
    const double id8 = 2e15;
    const int id5 = 1 << 15;

    template<typename T_out, typename T_in>
    vector<T_out> square(const vector<T_in> &input) {
        int n = input.size();

        

        if (n < 1.5 * id4) {
            vector<T_out> result(2 * n - 1);

            for (int i = 0; i < n; i++) {
                result[2 * i] += (T_out) input[i] * input[i];

                for (int j = i + 1; j < n; j++)
                    result[i + j] += (T_out) 2 * input[i] * input[j];
            }

            return result;
        }

        int N = id1(n);
        assert(N >= 2);
        id2(2 * N);
        vector<fast_complex<float_t>> values(N, 0);

        for (int i = 0; i < n; i += 2)
            values[i / 2] = fast_complex<float_t>(input[i], i + 1 < n ? input[i + 1] : 0);

        id6(N, values.begin());

        for (int i = 0; i <= N / 2; i++) {
            int j = (N - i) & (N - 1);
            fast_complex<float_t> even = extract(N, values, i, 0);
            fast_complex<float_t> odd = extract(N, values, i, 1);
            fast_complex<float_t> aux = even * even + odd * odd * roots[N + i] * roots[N + i];
            fast_complex<float_t> tmp = even * odd;
            values[i] = aux - fast_complex<float_t>(0, 2) * tmp;
            values[j] = id9(aux) - fast_complex<float_t>(0, 2) * id9(tmp);
        }

        for (int i = 0; i < N; i++)
            values[i] = id9(values[i]) * (ONE / N);

        fft_recursive(N, values.begin());
        vector<T_out> result(2 * n - 1);

        for (int i = 0; i < (int) result.size(); i++) {
            float_t value = i % 2 == 0 ? values[i / 2].real() : values[i / 2].imag();
            result[i] = is_integral<T_out>::value ? round(value) : value;
        }

        return result;
    }

    template<typename T_out, typename T_in>
    vector<T_out> multiply(const vector<T_in> &left, const vector<T_in> &right) {
        if (left == right)
            return square<T_out>(left);

        int n = left.size();
        int m = right.size();

        

        if (min(n, m) < id4) {
            vector<T_out> result(n + m - 1);

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    result[i + j] += (T_out) left[i] * right[j];

            return result;
        }

        int N = id1(n + m - 1);
        vector<fast_complex<float_t>> values(N, 0);

        for (int i = 0; i < n; i++)
            values[i].real(left[i]);

        for (int i = 0; i < m; i++)
            values[i].imag(right[i]);

        id6(N, values.begin());

        for (int i = 0; i <= N / 2; i++) {
            int j = (N - i) & (N - 1);
            fast_complex<float_t> product_i = extract(N, values, i, -1);
            values[i] = product_i;
            values[j] = id9(product_i);
        }

        invert_fft(N, values);
        vector<T_out> result(n + m - 1);

        for (int i = 0; i < (int) result.size(); i++)
            result[i] = is_integral<T_out>::value ? round(values[i].real()) : values[i].real();

        return result;
    }

    template<typename T>
    vector<T> id7(const vector<T> &left, const vector<T> &right, T mod, bool split = false) {
        int n = left.size();
        int m = right.size();

        for (int i = 0; i < n; i++)
            assert(0 <= left[i] && left[i] < mod);

        for (int i = 0; i < m; i++)
            assert(0 <= right[i] && right[i] < mod);

        

        if (min(n, m) < (split ? 2 : 1) * id4) {
            const uint64_t ULL_BOUND = numeric_limits<uint64_t>::max() - (uint64_t) mod * mod;
            vector<uint64_t> result(n + m - 1);

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    result[i + j] += (uint64_t) left[i] * right[j];

                    if (result[i + j] > ULL_BOUND)
                        result[i + j] %= mod;
                }

            for (int i = 0; i < (int) result.size(); i++)
                if (result[i] >= (uint64_t) mod)
                    result[i] %= mod;

            return vector<T>(result.begin(), result.end());
        }

        if (!split) {
            const vector<uint64_t> &product = multiply<uint64_t>(left, right);
            vector<T> result(n + m - 1);

            for (int i = 0; i < (int) result.size(); i++)
                result[i] = product[i] % mod;

            return result;
        }

        int N = id1(n + m - 1);
        vector<fast_complex<float_t>> left_fft(N, 0), right_fft(N, 0);

        for (int i = 0; i < n; i++) {
            left_fft[i].real(left[i] % id5);
            left_fft[i].imag(left[i] / id5);
        }

        id6(N, left_fft.begin());

        if (left == right) {
            copy(left_fft.begin(), left_fft.end(), right_fft.begin());
        } else {
            for (int i = 0; i < m; i++) {
                right_fft[i].real(right[i] % id5);
                right_fft[i].imag(right[i] / id5);
            }

            id6(N, right_fft.begin());
        }

        vector<fast_complex<float_t>> product(N);
        vector<T> result(n + m - 1);

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

            for (int i = 0; i < (int) result.size(); i++) {
                uint64_t value = round(product[i].real());
                result[i] = (result[i] + value % mod * multiplier) % mod;
            }
        }

        return result;
    }
}

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> lhs(2*x+1);
  vector<int> rhs(2*x+1);
  for(int i = 0; i <= n; i++) {
    int d;
    cin >> d;
    lhs[x-d]++;
    rhs[x+d]++;
  }
  vector<int> poly = FFT::id7(lhs, rhs, 998244353, true);
  int q;
  cin >> q;
  for(int qq = 0; qq < q; qq++) {
    int ret = -1;
    int cand;
    cin >> cand;
    for(int v = 1; v * v <= cand; v++) {
      if(cand%v) continue;
      int a = v;
      if(a > 2*y && (a-2*y)%2==0 && 2*x+(a-2*y)/2 < sz(poly) && poly[2*x+(a-2*y)/2]) ret = a;
      a = cand/a;
      if(a > 2*y && (a-2*y)%2==0 && 2*x+(a-2*y)/2 < sz(poly) && poly[2*x+(a-2*y)/2]) {
        ret = a;
        break;
      }
    }
    cout << ret << " \n"[qq == q-1];
  }
}












int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}