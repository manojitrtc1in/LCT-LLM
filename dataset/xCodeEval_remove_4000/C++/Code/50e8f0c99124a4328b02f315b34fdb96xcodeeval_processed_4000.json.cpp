





using namespace std;




template<typename float_type>
struct complex {
    float_type x, y;

    complex<float_type>(float_type _real = 0, float_type _imag = 0) {
        real(_real);
        imag(_imag);
    }

    float_type real() const {
        return x;
    }

    void real(float_type _real) {
        x = _real;
    }

    float_type imag() const {
        return y;
    }

    void imag(float_type _imag) {
        y = _imag;
    }

    complex<float_type> operator+(const complex<float_type> &other) const {
        return complex<float_type>(real() + other.real(), imag() + other.imag());
    }

    complex<float_type> operator-(const complex<float_type> &other) const {
        return complex<float_type>(real() - other.real(), imag() - other.imag());
    }

    complex<float_type> operator*(const complex<float_type> &other) const {
        return complex<float_type>(real() * other.real() - imag() * other.imag(),
                                   real() * other.imag() + imag() * other.real());
    }
};

template<typename float_type>
complex<float_type> conj(const complex<float_type> &x) {
    return complex<float_type>(x.real(), -x.imag());
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

    bool id0(int n) {
        return (n & (n - 1)) == 0;
    }

    int id4(int n) {
        assert(n > 0);

        while (n & (n - 1)) {
            n = (n | (n - 1)) + 1;
        }

        return n;
    }

    

    int get_length(int n) {
        assert(id0(n));
        return __builtin_ctz(n);
    }

    

    

    void id6(int n, complex<float_type> *values) {
        int length = get_length(n);

        for (int i = 0; i < n; i++) {
            int bit_reverse = 0;

            for (int x = i, k = 0; k < length; k++) {
                bit_reverse = (bit_reverse << 1) + (x & 1);
                x >>= 1;
            }

            if (i < bit_reverse) {
                swap(values[i], values[bit_reverse]);
            }
        }
    }

    void id3(int n) {
        roots.resize(n);

        for (int i = 0; i < n; i++) {
            roots[i] = polar(1.0, 2 * PI * i / n);
        }
    }

    void fft_recursive(int n, complex<float_type> *values, int depth = 0) {
        if (n <= 1)
            return;

        if (depth == 0) {
            assert(id0(n));
            id3(n);
            id6(n, values);
        }

        n /= 2;
        fft_recursive(n, values, depth + 1);
        fft_recursive(n, values + n, depth + 1);

        for (int i = 0; i < n; i++) {
            complex<float_type> even = values[i], odd = values[i + n];
            values[i] = even + roots[i << depth] * odd;
            values[i + n] = even + roots[(i + n) << depth] * odd;
        }
    }

    

    void id5(int N, complex<float_type> *values) {
        assert(id0(N));
        id3(N);
        id6(N, values);

        for (int depth = get_length(N) - 1; depth >= 0; depth--) {
            int n = N >> (depth + 1);

            for (int start = 0; start < N; start += 2 * n) {
                for (int i = 0; i < n; i++) {
                    complex<float_type> even = values[start + i], odd = values[start + i + n];
                    values[start + i] = even + roots[i << depth] * odd;
                    values[start + i + n] = even + roots[(i + n) << depth] * odd;
                }
            }
        }
    }

    template<typename T>
    vector<float_type> multiply(const vector<T> &left, const vector<T> &right) {
        int n = left.size();
        int m = right.size();
        int N = FFT::id4(n + m - 1);
        vector<complex<FFT::float_type>> a_values(N), b_values(N);

        for (int i = 0; i < n; i++) {
            a_values[i].real(left[i]);
        }

        for (int i = 0; i < m; i++) {
            b_values[i].real(right[i]);
        }

        FFT::fft_recursive(N, &a_values[0]);

        

        if (left == right) {
            b_values = a_values;
        } else {
            FFT::fft_recursive(N, &b_values[0]);
        }

        for (int i = 0; i < N; i++) {
            a_values[i] = conj(a_values[i] * b_values[i]);
        }

        FFT::fft_recursive(N, &a_values[0]);
        vector<float_type> result(N);

        for (int i = 0; i < N; i++) {
            result[i] = a_values[i].real() / N;
        }

        return result;
    }
}


struct id2 {
    static const int SECTION = 4;
    static const int BASE = pow(10, SECTION);
    static const int DOUBLE_DIV_SECTIONS = 5;

    static const int FFT_CUTOFF = 25000;
    static const int KARATSUBA_CUTOFF = 150;
    static const unsigned long long ULL_BOUND = numeric_limits<unsigned long long>::max() -
                                                (unsigned long long) BASE * BASE;
    typedef unsigned short value_t;

    vector<value_t> values;

    id2(unsigned long long x = 0) {
        init(x);
    }

    id2(string str) {
        int len = str.length();
        int num_values = max((len + SECTION - 1) / SECTION, 1);
        values.clear();
        values.resize(num_values, 0);

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

        if (values.empty()) {
            values.resize(1, 0);
        }
    }

    void checked_add(unsigned position, value_t add) {
        if (position >= values.size())
            values.resize(position + 1, 0);

        values[position] += add;
    }

    void init(unsigned long long x) {
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

        while (result.length() > 1 && result.back() == '0') {
            result.pop_back();
        }

        reverse(result.begin(), result.end());
        return result;
    }

    bool operator<(const id2 &other) const {
        int n = values.size();
        int m = other.values.size();

        if (n != m)
            return n < m;

        for (int i = n - 1; i >= 0; i--)
            if (values[i] != other.values[i])
                return values[i] < other.values[i];

        return false;
    }

    bool operator>(const id2 &other) const {
        return other < *this;
    }

    bool operator<=(const id2 &other) const {
        return !(other < *this);
    }

    bool operator>=(const id2 &other) const {
        return !(*this < other);
    }

    bool operator==(const id2 &other) const {
        int n = values.size();
        int m = other.values.size();

        if (n != m)
            return false;

        for (int i = 0; i < n; i++)
            if (values[i] != other.values[i])
                return false;

        return true;
    }

    bool operator!=(const id2 &other) const {
        return !(*this == other);
    }

    

    id2 operator<<(int p) const {
        assert(p >= 0);
        int n = values.size();

        id2 result;
        result.values.resize(n + p, 0);

        for (int i = 0; i < n; i++)
            result.values[i + p] = values[i];

        result.trim_check();
        return result;
    }

    

    id2 operator>>(int p) const {
        assert(p >= 0);
        int n = values.size();

        if (p >= n) {
            return id2(0);
        }

        id2 result;
        result.values.resize(n - p);

        for (int i = 0; i < n - p; i++)
            result.values[i] = values[i + p];

        result.trim_check();
        return result;
    }

    

    id2 range(int a, int b = -1) const {
        if (b == -1)
            b = values.size();

        assert(a <= b);
        id2 result;
        result.values.resize(b - a);

        for (int i = 0; i < b - a; i++)
            result.values[i] = values[i + a];

        result.trim_check();
        return result;
    }

    id2& operator+=(const id2 &other) {
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

    id2 operator+(const id2 &other) const {
        return id2(*this) += other;
    }

    id2& operator-=(const id2 &other) {
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

    id2 operator-(const id2 &other) const {
        return id2(*this) -= other;
    }

    id2 operator*(const id2 &other) const {
        const id2 *a = this, *b = &other;
        int n = a->values.size();
        int m = b->values.size();

        if (n > m) {
            swap(a, b);
            swap(n, m);
        }

        if (n > KARATSUBA_CUTOFF && n + m > FFT_CUTOFF) {
            const vector<FFT::float_type> &multiplication = FFT::multiply(a->values, b->values);
            int N = multiplication.size();
            id2 product = 0;
            unsigned long long carry = 0;

            for (int i = 0; i < N || carry > 0; i++) {
                unsigned long long value = (unsigned long long) ((i < N ? multiplication[i] : 0) + 0.5) + carry;
                carry = value / BASE;
                value %= BASE;
                product.checked_add(i, value);
            }

            product.trim_check();
            return product;
        }

        if (n > KARATSUBA_CUTOFF) {
            

            int mid = n / 2;
            const id2 &a1 = a->range(0, mid);
            const id2 &a2 = a->range(mid, n);
            const id2 &b1 = b->range(0, mid);
            const id2 &b2 = b->range(mid, m);

            const id2 &x = a2 * b2;
            const id2 &z = a1 * b1;
            const id2 &y = (a1 + a2) * (b1 + b2) - x - z;
            return (x << 2 * mid) + (y << mid) + z;
        }

        

        id2 product = 0;
        product.values.resize(n + m - 1, 0);
        unsigned long long sum = 0, carry = 0;

        for (int index = 0; index < n + m - 1 || carry > 0; index++) {
            sum = carry % BASE;
            carry /= BASE;

            for (int j = max(0, index - (m - 1)); j <= min(n - 1, index); j++) {
                sum += (unsigned long long) a->values[j] * b->values[index - j];

                if (sum >= ULL_BOUND) {
                    carry += sum / BASE;
                    sum %= BASE;
                }
            }

            carry += sum / BASE;
            sum %= BASE;
            product.checked_add(index, sum);
        }

        product.trim_check();
        return product;
    }

    id2& operator*=(const id2 &other) {
        return *this = *this * other;
    }

    id2 operator*(unsigned long long mult) const {
        int n = values.size();

        id2 product;
        product.values.resize(n + 1, 0);
        unsigned long long carry = 0;

        for (int i = 0; i < n || carry > 0; i++) {
            unsigned long long value = mult * (i < n ? values[i] : 0) + carry;
            carry = value / BASE;
            value %= BASE;
            product.checked_add(i, value);
        }

        product.trim_check();
        return product;
    }

    id2& operator*=(unsigned long long mult) {
        return *this = *this * mult;
    }

    double estimate_div(const id2 &other) const {
        int n = values.size();
        int m = other.values.size();
        double estimate = 0, id1 = 0;
        int count = 0, other_count = 0;

        double p_base = 1;

        for (int i = n - 1; i >= 0 && count < DOUBLE_DIV_SECTIONS; i--) {
            estimate = estimate + p_base * values[i];
            p_base /= BASE;
            count++;
        }

        p_base = 1;

        for (int i = m - 1; i >= 0 && other_count < DOUBLE_DIV_SECTIONS; i--) {
            id1 = id1 + p_base * other.values[i];
            p_base /= BASE;
            other_count++;
        }

        return estimate / id1 * pow(BASE, n - m);
    }

    pair<id2, id2> div_mod(const id2 &other) const {
        assert(other > 0);

        int n = values.size();
        int m = other.values.size();
        id2 quotient = 0;
        id2 remainder = *this;

        for (int i = n - m; i >= 0; i--) {
            

            if (i >= (int) remainder.values.size())
                continue;

            id2 chunk = remainder.range(i);

            

            int div = (int) (chunk.estimate_div(other) + 1e-7);
            id2 mult = other * div;

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

            if (div > 0) {
                quotient.checked_add(i, div);
            }
        }

        quotient.trim_check();
        remainder.trim_check();
        return make_pair(quotient, remainder);
    }

    id2 operator/(const id2 &other) const {
        return div_mod(other).first;
    }

    id2 operator%(const id2 &other) const {
        return div_mod(other).second;
    }

    id2& operator/=(const id2 &other) {
        return *this = *this / other;
    }

    id2& operator%=(const id2 &other) {
        return *this = *this % other;
    }

    

    pair<id2, unsigned long long> div_mod(unsigned long long denom) const {
        assert(denom > 0);

        int n = values.size();
        id2 quotient = 0;
        unsigned long long remainder = 0;

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

    id2 operator/(unsigned long long denom) const {
        return div_mod(denom).first;
    }

    unsigned long long operator%(unsigned long long denom) const {
        return div_mod(denom).second;
    }

    id2& operator/=(unsigned long long denom) {
        return *this = *this / denom;
    }

    id2& operator%=(unsigned long long denom) {
        return *this = *this % denom;
    }

    id2 power(unsigned exp) const {
        id2 result = 1;

        for (int k = 31; k >= 0; k--) {
            result *= result;

            if (exp & 1U << k) {
                result *= *this;
            }
        }

        return result;
    }
};


int main() {
    string input;
    cin >> input;
    int threes = (log10(input[0] - '0') + input.length() - 1) / log10(3);
    id2 value = id2(3).power(threes);
    id2 number = input;

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
