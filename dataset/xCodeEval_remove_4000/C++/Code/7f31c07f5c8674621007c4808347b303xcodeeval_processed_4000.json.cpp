






using namespace std;




template<typename float_type>
struct complex {
    float_type x, y;

    complex<float_type>(float_type _x = 0, float_type _y = 0) : x(_x), y(_y) {}

    float_type real() const {
        return x;
    }

    void real(float_type _x) {
        x = _x;
    }

    float_type imag() const {
        return y;
    }

    void imag(float_type _y) {
        y = _y;
    }

    complex<float_type>& operator+=(const complex<float_type> &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    complex<float_type>& operator-=(const complex<float_type> &other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    complex<float_type> operator+(const complex<float_type> &other) const {
        return complex<float_type>(*this) += other;
    }

    complex<float_type> operator-(const complex<float_type> &other) const {
        return complex<float_type>(*this) -= other;
    }

    complex<float_type> operator*(const complex<float_type> &other) const {
        return complex<float_type>(x * other.x - y * other.y, x * other.y + other.x * y);
    }

    complex<float_type> operator/(const float_type other) const {
        return complex<float_type>(x / other, y / other);
    }
};

template<typename float_type>
complex<float_type> conj(const complex<float_type> &c) {
    return complex<float_type>(c.x, -c.y);
}

template<typename float_type>
complex<float_type> polar(float_type magnitude, float_type angle) {
    return complex<float_type>(magnitude * cos(angle), magnitude * sin(angle));
}

template<typename float_type>
ostream& operator<<(ostream &stream, const complex<float_type> &x) {
    return stream << '(' << x.real() << ',' << x.imag() << ')';
}


namespace FFT {
    typedef double float_type;
    const float_type PI = acos((float_type) -1);

    vector<complex<float_type>> roots;
    vector<int> bit_reverse;

    bool id1(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

    int id6(int n) {
        assert(n > 0);

        while (n & (n - 1))
            n = (n | (n - 1)) + 1;

        return n;
    }

    

    int get_length(int n) {
        assert(id1(n));
        return __builtin_ctz(n);
    }

    

    

    void id9(int n, complex<float_type> *values) {
        if ((int) bit_reverse.size() != n) {
            bit_reverse.resize(n, 0);
            int length = get_length(n);

            for (int i = 0; i < n; i++)
                bit_reverse[i] = (bit_reverse[i >> 1] >> 1) + ((i & 1) << length - 1);
        }

        for (int i = 0; i < n; i++)
            if (i < bit_reverse[i])
                swap(values[i], values[bit_reverse[i]]);
    }

    void id4(int n) {
        if ((int) roots.size() >= n)
            return;

        if (roots.empty()) {
            roots.resize(2);
            roots[1] = complex<float_type>(1, 0);
        }

        int length = get_length(roots.size());
        roots.resize(n);

        

        

        while (1 << length < n) {
            double min_angle = 2 * PI / (1 << length + 1);

            for (int i = 0; i < 1 << length - 1; i++) {
                int index = (1 << length - 1) + i;
                roots[2 * index] = roots[index];
                roots[2 * index + 1] = polar(1.0, min_angle * (2 * i + 1));
            }

            length++;
        }
    }

    void fft_recursive(int n, complex<float_type> *values, int depth = 0) {
        if (n <= 1)
            return;

        if (depth == 0) {
            assert(id1(n));
            id4(n);
            id9(n, values);
        }

        n /= 2;
        fft_recursive(n, values, depth + 1);
        fft_recursive(n, values + n, depth + 1);

        for (int i = 0; i < n; i++) {
            complex<float_type> even = values[i];
            complex<float_type> odd = values[n + i] * roots[n + i];
            values[i] = even + odd;
            values[n + i] = even - odd;
        }
    }

    

    void id8(int N, complex<float_type> *values) {
        assert(id1(N));
        id4(N);
        id9(N, values);

        for (int depth = get_length(N) - 1; depth >= 0; depth--) {
            int n = N >> depth + 1;

            for (int start = 0; start < N; start += 2 * n)
                for (int i = 0; i < n; i++) {
                    complex<float_type> even = values[start + i];
                    complex<float_type> odd = values[start + n + i] * roots[n + i];
                    values[start + i] = even + odd;
                    values[start + n + i] = even - odd;
                }
        }
    }

    complex<float_type> extract(int N, const vector<complex<float_type>> &values, int index, int side) {
        int other = (N - index) & (N - 1);
        int sign = side == 0 ? +1 : -1;
        complex<float_type> multiplier = side == 0 ? complex<float_type>(0.5, 0) : complex<float_type>(0, -0.5);
        return multiplier * complex<float_type>(values[index].real() + values[other].real() * sign,
                                                values[index].imag() - values[other].imag() * sign);
    }

    template<typename T_out, typename T_in>
    vector<T_out> multiply(const vector<T_in> &left, const vector<T_in> &right) {
        int n = left.size();
        int m = right.size();
        int N = id6(n + m - 1);
        vector<complex<float_type>> values(N, 0);

        for (int i = 0; i < n; i++)
            values[i].real(left[i]);

        for (int i = 0; i < m; i++)
            values[i].imag(right[i]);

        id8(N, &values[0]);
        vector<complex<float_type>> product(N, 0);

        for (int i = 0; i < N; i++)
            product[i] = conj(extract(N, values, i, 0) * extract(N, values, i, 1)) * (1.0 / N);

        id8(N, &product[0]);
        vector<T_out> result(n + m - 1);

        for (int i = 0; i < (int) result.size(); i++)
            result[i] = is_integral<T_out>::value ? round(product[i].real()) : product[i].real();

        return result;
    }

    const int id7 = 200;
    const int id10 = 1 << 15;
    const double id0 = 1e15;

    template<typename T>
    vector<T> id5(const vector<T> &left, const vector<T> &right, T mod, bool split = false) {
        int n = left.size();
        int m = right.size();

        for (int i = 0; i < n; i++)
            assert(0 <= left[i] && left[i] < mod);

        for (int i = 0; i < m; i++)
            assert(0 <= right[i] && right[i] < mod);

        


        if (!split)
            assert((double) max(n, m) * mod * mod < id0);


        

        if (min(n, m) < id7 * (split ? 2 : 1)) {
            const uint64_t ULL_BOUND = numeric_limits<uint64_t>::max() - (uint64_t) mod * mod;
            vector<T> answer(n + m - 1);

            for (int sum = 0; sum < (int) answer.size(); sum++) {
                uint64_t value = 0;

                for (int i = max(0, sum - (m - 1)); i <= min(n - 1, sum); i++) {
                    value += (uint64_t) left[i] * right[sum - i];

                    if (value > ULL_BOUND)
                        value %= mod;
                }

                if (value >= (uint64_t) mod)
                    value %= mod;

                answer[sum] = value;
            }

            return answer;
        }

        if (!split) {
            const vector<uint64_t> &product = multiply<uint64_t>(left, right);
            vector<T> answer(n + m - 1);

            for (int i = 0; i < (int) answer.size(); i++)
                answer[i] = product[i] % mod;

            return answer;
        }

        int N = id6(n + m - 1);
        vector<complex<float_type>> left_fft(N, 0), right_fft(N, 0), product(N, 0);

        for (int i = 0; i < n; i++) {
            left_fft[i].real(left[i] % id10);
            left_fft[i].imag(left[i] / id10);
        }

        for (int i = 0; i < m; i++) {
            right_fft[i].real(right[i] % id10);
            right_fft[i].imag(right[i] / id10);
        }

        id8(N, &left_fft[0]);
        id8(N, &right_fft[0]);
        vector<T> answer(n + m - 1);

        for (int exponent = 0; exponent <= 2; exponent++) {
            T multiplier = 1;

            for (int k = 0; k < exponent; k++)
                multiplier = (uint64_t) multiplier * id10 % mod;

            for (int i = 0; i < N; i++)
                product[i] = 0;

            for (int x = 0; x < 2; x++)
                for (int y = 0; y < 2; y++)
                    if (x + y == exponent)
                        for (int i = 0; i < N; i++)
                            product[i] += conj(extract(N, left_fft, i, x) * extract(N, right_fft, i, y)) * (1.0 / N);

            id8(N, &product[0]);

            for (int i = 0; i < (int) answer.size(); i++) {
                uint64_t value = round(product[i].real());
                answer[i] = (answer[i] + value % mod * multiplier) % mod;
            }
        }

        return answer;
    }
}


struct id3 {
    static const int SECTION = 4;
    static const int BASE = pow(10, SECTION);
    static const int DOUBLE_DIV_SECTIONS = 5;

    static const int FFT_CUTOFF = 5000;
    static const int KARATSUBA_CUTOFF = 150;
    static const uint64_t ULL_BOUND = numeric_limits<uint64_t>::max() - (uint64_t) BASE * BASE;
    typedef unsigned short value_t;

    vector<value_t> values;

    id3(uint64_t x = 0) {
        init(x);
    }

    id3(string str) {
        int len = str.length();
        int num_values = max((len + SECTION - 1) / SECTION, 1);
        values.assign(num_values, 0);

        int counter = 0;
        int index = 0;
        value_t p10 = 1;

        for (int i = len - 1; i >= 0; i--) {
            assert('0' <= str[i] && str[i] <= '9');
            values[index] += p10 * (str[i] - '0');

            if (++counter >= SECTION) {
                counter = 0;
                index++;
                p10 = 1;
            } else {
                p10 *= 10;
            }
        }

        trim_check();
    }

    void trim_check() {
        while (values.size() > 1 && values.back() == 0)
            values.pop_back();

        if (values.empty())
            values.resize(1, 0);
    }

    void checked_add(unsigned position, value_t add) {
        if (position >= values.size())
            values.resize(position + 1, 0);

        values[position] += add;
    }

    void init(uint64_t x) {
        values.clear();

        do {
            checked_add(values.size(), x % BASE);
            x /= BASE;
        } while (x > 0);
    }

    string to_string() const {
        string result = "";

        for (value_t v : values) {
            for (int i = 0; i < SECTION; i++) {
                result += v % 10 + '0';
                v /= 10;
            }
        }

        while (result.length() > 1 && result.back() == '0')
            result.pop_back();

        reverse(result.begin(), result.end());
        return result;
    }

    bool operator<(const id3 &other) const {
        int n = values.size();
        int m = other.values.size();

        if (n != m)
            return n < m;

        for (int i = n - 1; i >= 0; i--)
            if (values[i] != other.values[i])
                return values[i] < other.values[i];

        return false;
    }

    bool operator>(const id3 &other) const {
        return other < *this;
    }

    bool operator<=(const id3 &other) const {
        return !(other < *this);
    }

    bool operator>=(const id3 &other) const {
        return !(*this < other);
    }

    bool operator==(const id3 &other) const {
        int n = values.size();
        int m = other.values.size();

        if (n != m)
            return false;

        for (int i = 0; i < n; i++)
            if (values[i] != other.values[i])
                return false;

        return true;
    }

    bool operator!=(const id3 &other) const {
        return !(*this == other);
    }

    

    id3 operator<<(int p) const {
        assert(p >= 0);
        int n = values.size();

        id3 result;
        result.values.resize(n + p, 0);

        for (int i = 0; i < n; i++)
            result.values[i + p] = values[i];

        result.trim_check();
        return result;
    }

    

    id3 operator>>(int p) const {
        assert(p >= 0);
        int n = values.size();

        if (p >= n)
            return id3(0);

        id3 result;
        result.values.resize(n - p);

        for (int i = 0; i < n - p; i++)
            result.values[i] = values[i + p];

        result.trim_check();
        return result;
    }

    

    id3 range(int a, int b = -1) const {
        if (b == -1)
            b = values.size();

        assert(a <= b);
        id3 result;
        result.values.resize(b - a);

        for (int i = 0; i < b - a; i++)
            result.values[i] = values[i + a];

        result.trim_check();
        return result;
    }

    id3& operator+=(const id3 &other) {
        int n = other.values.size();

        for (int i = 0, carry = 0; i < n || carry > 0; i++) {
            checked_add(i, (i < n ? other.values[i] : 0) + carry);

            if (values[i] >= BASE) {
                values[i] -= BASE;
                carry = 1;
            } else {
                carry = 0;
            }
        }

        trim_check();
        return *this;
    }

    id3 operator+(const id3 &other) const {
        return id3(*this) += other;
    }

    id3& operator-=(const id3 &other) {
        assert(*this >= other);
        int n = other.values.size();

        for (int i = 0, carry = 0; i < n || carry > 0; i++) {
            unsigned subtract = (i < n ? other.values[i] : 0) + carry;

            if (values[i] < subtract) {
                values[i] += BASE - subtract;
                carry = 1;
            } else {
                values[i] -= subtract;
                carry = 0;
            }
        }

        trim_check();
        return *this;
    }

    id3 operator-(const id3 &other) const {
        return id3(*this) -= other;
    }

    id3 operator*(const id3 &other) const {
        const id3 *a = this, *b = &other;
        int n = a->values.size();
        int m = b->values.size();

        if (n > m) {
            swap(a, b);
            swap(n, m);
        }

        if (n > KARATSUBA_CUTOFF && n + m > FFT_CUTOFF) {
            const vector<uint64_t> &multiplication = FFT::multiply<uint64_t>(a->values, b->values);
            int N = multiplication.size();
            id3 product = 0;
            uint64_t carry = 0;

            for (int i = 0; i < N || carry > 0; i++) {
                uint64_t value = (i < N ? multiplication[i] : 0) + carry;
                carry = value / BASE;
                value %= BASE;
                product.checked_add(i, value);
            }

            product.trim_check();
            return product;
        }

        if (n > KARATSUBA_CUTOFF) {
            

            int mid = n / 2;
            const id3 &a1 = a->range(0, mid);
            const id3 &a2 = a->range(mid, n);
            const id3 &b1 = b->range(0, mid);
            const id3 &b2 = b->range(mid, m);

            const id3 &x = a2 * b2;
            const id3 &z = a1 * b1;
            const id3 &y = (a1 + a2) * (b1 + b2) - x - z;
            return (x << 2 * mid) + (y << mid) + z;
        }

        

        id3 product = 0;
        product.values.resize(n + m - 1, 0);
        uint64_t value = 0, carry = 0;

        for (int index_sum = 0; index_sum < n + m - 1 || carry > 0; index_sum++) {
            value = carry % BASE;
            carry /= BASE;

            for (int i = max(0, index_sum - (m - 1)); i <= min(n - 1, index_sum); i++) {
                value += (uint64_t) a->values[i] * b->values[index_sum - i];

                if (value > ULL_BOUND) {
                    carry += value / BASE;
                    value %= BASE;
                }
            }

            carry += value / BASE;
            value %= BASE;
            product.checked_add(index_sum, value);
        }

        product.trim_check();
        return product;
    }

    id3& operator*=(const id3 &other) {
        return *this = *this * other;
    }

    id3 operator*(uint64_t mult) const {
        int n = values.size();

        id3 product;
        product.values.resize(n + 1, 0);
        uint64_t carry = 0;

        for (int i = 0; i < n || carry > 0; i++) {
            uint64_t value = mult * (i < n ? values[i] : 0) + carry;
            carry = value / BASE;
            value %= BASE;
            product.checked_add(i, value);
        }

        product.trim_check();
        return product;
    }

    id3& operator*=(uint64_t mult) {
        return *this = *this * mult;
    }

    double estimate_div(const id3 &other) const {
        int n = values.size();
        int m = other.values.size();
        double estimate = 0, id2 = 0;
        int count = 0, other_count = 0;

        double p_base = 1;

        for (int i = n - 1; i >= 0 && count < DOUBLE_DIV_SECTIONS; i--) {
            estimate = estimate + p_base * values[i];
            p_base /= BASE;
            count++;
        }

        p_base = 1;

        for (int i = m - 1; i >= 0 && other_count < DOUBLE_DIV_SECTIONS; i--) {
            id2 = id2 + p_base * other.values[i];
            p_base /= BASE;
            other_count++;
        }

        return estimate / id2 * pow(BASE, n - m);
    }

    pair<id3, id3> div_mod(const id3 &other) const {
        assert(other > 0);

        int n = values.size();
        int m = other.values.size();
        id3 quotient = 0;
        id3 remainder = *this;

        for (int i = n - m; i >= 0; i--) {
            

            if (i >= (int) remainder.values.size())
                continue;

            id3 chunk = remainder.range(i);

            

            int div = (int) (chunk.estimate_div(other) + 1e-7);
            id3 mult = other * div;

            while (div > 0 && mult > chunk) {
                

                mult -= other;
                div--;
            }

            while (div < BASE - 1 && mult + other <= chunk) {
                

                mult += other;
                div++;
            }

            remainder -= mult << i;
            remainder.trim_check();

            if (div > 0)
                quotient.checked_add(i, div);
        }

        quotient.trim_check();
        remainder.trim_check();
        return make_pair(quotient, remainder);
    }

    id3 operator/(const id3 &other) const {
        return div_mod(other).first;
    }

    id3 operator%(const id3 &other) const {
        return div_mod(other).second;
    }

    id3& operator/=(const id3 &other) {
        return *this = *this / other;
    }

    id3& operator%=(const id3 &other) {
        return *this = *this % other;
    }

    

    pair<id3, uint64_t> div_mod(uint64_t denom) const {
        assert(denom > 0);

        int n = values.size();
        id3 quotient = 0;
        uint64_t remainder = 0;

        for (int i = n - 1; i >= 0; i--) {
            remainder = remainder * BASE + values[i];

            if (remainder >= denom) {
                quotient.checked_add(i, remainder / denom);
                remainder %= denom;
            }
        }

        quotient.trim_check();
        return make_pair(quotient, remainder);
    }

    id3 operator/(uint64_t denom) const {
        return div_mod(denom).first;
    }

    uint64_t operator%(uint64_t denom) const {
        return div_mod(denom).second;
    }

    id3& operator/=(uint64_t denom) {
        return *this = *this / denom;
    }

    id3& operator%=(uint64_t denom) {
        return *this = *this % denom;
    }

    id3 power(unsigned exponent) const {
        id3 result = 1;

        for (int k = 31; k >= 0; k--) {
            result *= result;

            if (exponent & 1U << k)
                result *= *this;
        }

        return result;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin >> input;
    int threes = (log10(input[0] - '0') + input.length() - 1) / log10(3);
    id3 value = id3(3).power(threes);
    id3 number = input;

    while (value < number) {
        value *= 3;
        threes++;
    }

    int answer = 3 * threes;

    for (int twos = 1; twos <= 2; twos++) {
        value /= 3;
        value += value;
        threes--;

        if (value >= number)
            answer = min(answer, 3 * threes + 2 * twos);
    }

    cout << max(answer, 1) << '\n';
    return 0;
}
