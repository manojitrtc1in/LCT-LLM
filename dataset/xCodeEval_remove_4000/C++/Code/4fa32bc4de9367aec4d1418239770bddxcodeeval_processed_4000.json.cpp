




using namespace std;


namespace FFT {
    typedef double float_type;
    const float_type PI = acos((float_type) -1);

    vector<complex<float_type>> roots;

    bool id3(int n) {
        return (n & (n - 1)) == 0;
    }

    int id1(int n) {
        assert(n > 0);

        while (n & (n - 1)) {
            n = (n | (n - 1)) + 1;
        }

        return n;
    }

    

    int get_length(int n) {
        assert(id3(n));
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

    void id2(int n) {
        roots.resize(n);

        for (int i = 0; i < n; i++) {
            roots[i] = polar(1.0, 2 * PI * i / n);
        }
    }

    void fft_recursive(int n, complex<float_type> *values, int depth = 0) {
        if (n <= 1)
            return;

        if (depth == 0) {
            assert(id3(n));
            id2(n);
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

    

    void id4(int N, complex<float_type> *values) {
        assert(id3(N));
        id2(N);
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
        int N = FFT::id1(n + m - 1);
        vector<complex<FFT::float_type>> a_values(N), b_values(N);

        for (int i = 0; i < n; i++) {
            a_values[i].real(left[i]);
        }

        for (int i = 0; i < m; i++) {
            b_values[i].real(right[i]);
        }

        FFT::id4(N, &a_values[0]);

        

        if (left == right) {
            b_values = a_values;
        } else {
            FFT::id4(N, &b_values[0]);
        }

        for (int i = 0; i < N; i++) {
            a_values[i] = conj(a_values[i] * b_values[i]);
        }

        FFT::id4(N, &a_values[0]);
        vector<float_type> result(N);

        for (int i = 0; i < N; i++) {
            result[i] = a_values[i].real() / N;
        }

        return result;
    }
}


struct id0 {
    static const int SECTION = 4;
    static const int BASE = pow(10, SECTION);
    static const int DOUBLE_DIV_SECTIONS = 5;

    static const int FFT_CUTOFF = 25000;
    static const int KARATSUBA_CUTOFF = 150;
    static const unsigned long long ULL_BOUND = numeric_limits<unsigned long long>::max() -
                                                (unsigned long long) BASE * BASE;
    typedef unsigned short value_t;

    vector<value_t> values;

    id0(unsigned long long x = 0) {
        init(x);
    }

    id0(string str) {
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

    bool operator<(const id0 &other) const {
        int n = values.size();
        int m = other.values.size();

        if (n != m)
            return n < m;

        for (int i = n - 1; i >= 0; i--)
            if (values[i] != other.values[i])
                return values[i] < other.values[i];

        return false;
    }

    bool operator>(const id0 &other) const {
        return other < *this;
    }

    bool operator<=(const id0 &other) const {
        return !(other < *this);
    }

    bool operator>=(const id0 &other) const {
        return !(*this < other);
    }

    bool operator==(const id0 &other) const {
        int n = values.size();
        int m = other.values.size();

        if (n != m)
            return false;

        for (int i = 0; i < n; i++)
            if (values[i] != other.values[i])
                return false;

        return true;
    }

    bool operator!=(const id0 &other) const {
        return !(*this == other);
    }

    

    id0 operator<<(int p) const {
        assert(p >= 0);
        int n = values.size();

        id0 result;
        result.values.resize(n + p, 0);

        for (int i = 0; i < n; i++)
            result.values[i + p] = values[i];

        result.trim_check();
        return result;
    }

    

    id0 operator>>(int p) const {
        assert(p >= 0);
        int n = values.size();

        if (p >= n) {
            return id0(0);
        }

        id0 result;
        result.values.resize(n - p);

        for (int i = 0; i < n - p; i++)
            result.values[i] = values[i + p];

        result.trim_check();
        return result;
    }

    

    id0 range(int a, int b = -1) const {
        if (b == -1)
            b = values.size();

        assert(a <= b);
        id0 result;
        result.values.resize(b - a);

        for (int i = 0; i < b - a; i++)
            result.values[i] = values[i + a];

        result.trim_check();
        return result;
    }

    id0& operator+=(const id0 &other) {
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

    id0 operator+(const id0 &other) const {
        return id0(*this) += other;
    }

    id0& operator-=(const id0 &other) {
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

    id0 operator-(const id0 &other) const {
        return id0(*this) -= other;
    }

    id0 operator*(const id0 &other) const {
        const id0 *a = this, *b = &other;
        int n = a->values.size();
        int m = b->values.size();

        if (n > m) {
            swap(a, b);
            swap(n, m);
        }

        if (n > KARATSUBA_CUTOFF && n + m > FFT_CUTOFF) {
            const vector<FFT::float_type> &multiplication = FFT::multiply(a->values, b->values);
            int N = multiplication.size();
            id0 product = 0;
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
            const id0 &a1 = a->range(0, mid);
            const id0 &a2 = a->range(mid, n);
            const id0 &b1 = b->range(0, mid);
            const id0 &b2 = b->range(mid, m);

            const id0 &x = a2 * b2;
            const id0 &z = a1 * b1;
            const id0 &y = (a1 + a2) * (b1 + b2) - x - z;
            return (x << 2 * mid) + (y << mid) + z;
        }

        

        id0 product = 0;
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

    id0& operator*=(const id0 &other) {
        return *this = *this * other;
    }

    id0 operator*(unsigned long long mult) const {
        int n = values.size();

        id0 product;
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

    id0& operator*=(unsigned long long mult) {
        return *this = *this * mult;
    }

    double estimate_div(const id0 &other) const {
        int n = values.size();
        int m = other.values.size();
        double estimate = 0, id5 = 0;
        int count = 0, other_count = 0;

        double p_base = 1;

        for (int i = n - 1; i >= 0 && count < DOUBLE_DIV_SECTIONS; i--) {
            estimate = estimate + p_base * values[i];
            p_base /= BASE;
            count++;
        }

        p_base = 1;

        for (int i = m - 1; i >= 0 && other_count < DOUBLE_DIV_SECTIONS; i--) {
            id5 = id5 + p_base * other.values[i];
            p_base /= BASE;
            other_count++;
        }

        return estimate / id5 * pow(BASE, n - m);
    }

    pair<id0, id0> div_mod(const id0 &other) const {
        assert(other > 0);

        int n = values.size();
        int m = other.values.size();
        id0 quotient = 0;
        id0 remainder = *this;

        for (int i = n - m; i >= 0; i--) {
            

            if (i >= (int) remainder.values.size())
                continue;

            id0 chunk = remainder.range(i);

            

            int div = (int) (chunk.estimate_div(other) + 1e-7);
            id0 mult = other * div;

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

    id0 operator/(const id0 &other) const {
        return div_mod(other).first;
    }

    id0 operator%(const id0 &other) const {
        return div_mod(other).second;
    }

    id0& operator/=(const id0 &other) {
        return *this = *this / other;
    }

    id0& operator%=(const id0 &other) {
        return *this = *this % other;
    }

    

    pair<id0, unsigned long long> div_mod(unsigned long long denom) const {
        assert(denom > 0);

        int n = values.size();
        id0 quotient = 0;
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

    id0 operator/(unsigned long long denom) const {
        return div_mod(denom).first;
    }

    unsigned long long operator%(unsigned long long denom) const {
        return div_mod(denom).second;
    }

    id0& operator/=(unsigned long long denom) {
        return *this = *this / denom;
    }

    id0& operator%=(unsigned long long denom) {
        return *this = *this % denom;
    }

    id0 power(unsigned exp) const {
        id0 result = 1;

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
    id0 value = id0(3).power(threes);
    id0 number = input;

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
