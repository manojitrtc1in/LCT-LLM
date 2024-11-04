
using namespace std;

using ll = long long;
using ld = long double;





    

    










class id0 final {
private:
    int n;
    uint64_t* values;

    int get_size() const {
        return (n + 255) >> 8 << 2;
    }

    void extand(int new_n) {
        int prev_size = get_size();
        n = new_n;
        int new_size = get_size();

        if (new_size > prev_size) {
            uint64_t* new_values = new uint64_t[new_size]{};
            memcpy(new_values, values, sizeof(uint64_t) * prev_size);
            delete[] values;
            values = new_values;
        }
    }

    void remove_trash() {
        int sz = get_size();
        if ((n >> 6) < sz) {
            for (int i = (n >> 6) + 1; i < sz; i++)
                values[i] = 0;

            if (n & 63) {
                values[n >> 6] <<= 64 - (n & 63);
                values[n >> 6] >>= 64 - (n & 63);
            } else {
                values[n >> 6] = 0;
            }
        }
    }

public:
    id0(int n = 0, unsigned long long value = 0) : n(n) {
        values = new uint64_t[get_size()]{};
        for (int i = 0; i < n && i < 64; i++)
            if (value >> i & 1)
                set_bit(i, true);

    }

    id0(const id0 &bs) : n(bs.n) {
        int sz = get_size();
        values = new uint64_t[sz];
        memcpy(values, bs.values, sizeof(uint64_t) * sz);
    }

    int size() const {
        return n;
    }

    void set_bit(int pos, bool bit) {
        int id = pos >> 6;
        pos &= 63;
        if (bit)
            values[id] |= uint64_t(1) << pos;
        else
            values[id] &= ~(uint64_t(1) << pos);
    }

    bool get_bit(int pos) const {
        int id = pos >> 6;
        pos &= 63;
        return values[id] >> pos & 1;
    }

    id0& operator=(const id0 &bs) {
        delete[] values;
        n = bs.n;
        int sz = get_size();
        values = new uint64_t[sz];
        memcpy(values, bs.values, sizeof(uint64_t) * sz);
        return *this;
    }

    id0& operator|=(const id0 &bs) {
        if (size() < bs.size())
            extand(bs.size());

        for (int i = 0; (i << 6) < bs.size(); i += 4)
            _mm256_storeu_si256(reinterpret_cast<__m256i*>(values + i),
                _mm256_or_si256(_mm256_lddqu_si256(reinterpret_cast<const __m256i*>(values + i)),
                    _mm256_lddqu_si256(reinterpret_cast<const __m256i*>(bs.data() + i))));

        return *this;
    }

    id0& operator&=(const id0 &bs) {
        if (size() < bs.size())
            extand(bs.size());

        for (int i = 0; (i << 6) < bs.size(); i += 4)
            _mm256_storeu_si256(reinterpret_cast<__m256i*>(values + i),
                _mm256_and_si256(_mm256_lddqu_si256(reinterpret_cast<const __m256i*>(values + i)),
                    _mm256_lddqu_si256(reinterpret_cast<const __m256i*>(bs.data() + i))));

        return *this;
    }

    id0& operator^=(const id0 &bs) {
        if (size() < bs.size())
            extand(bs.size());

        for (int i = 0; (i << 6) < bs.size(); i += 4)
            _mm256_storeu_si256(reinterpret_cast<__m256i*>(values + i),
                _mm256_xor_si256(_mm256_lddqu_si256(reinterpret_cast<const __m256i*>(values + i)),
                    _mm256_lddqu_si256(reinterpret_cast<const __m256i*>(bs.data() + i))));

        return *this;
    }

    id0& operator>>=(int shift) {
        if (shift == 0 || n == 0)
            return *this;

        if (shift < 0)
            return *this <<= -shift;

        int sz = get_size();
        if (!(shift & 255)) {
            shift >>= 6;
            if (shift > sz)
                shift = sz;

            int id = sz - shift;
            for (int i = 0; i < id; i += 4)
                _mm256_storeu_si256(reinterpret_cast<__m256i*>(values + i),
                    _mm256_lddqu_si256(reinterpret_cast<const __m256i*>(values + i + shift)));

            memset(values + id, 0, sizeof(uint64_t) * shift);
        } else if (!(shift & 63)) {
            shift >>= 6;
            if (shift > sz)
                shift = sz;

            int id = sz - shift, pos = 0;
            for (; pos + 4 < id; pos += 4)
                _mm256_storeu_si256(reinterpret_cast<__m256i*>(values + pos),
                    _mm256_lddqu_si256(reinterpret_cast<const __m256i*>(values + pos + shift)));

            for (; pos < id; pos++)
                values[pos] = values[pos + shift];

            memset(values + id, 0, sizeof(uint64_t) * shift);
        } else {
            int d = shift >> 6, cnt1 = shift & 63, cnt2 = 64 - cnt1;
            if (d >= sz) {
                memset(values, 0, sizeof(uint64_t) * sz);
                return *this;
            }

            int id = sz - 1 - d, pos = 0;
            __m256i id2 = _mm256_set1_epi64x(cnt1), id1 = _mm256_set1_epi64x(cnt2);
            for (; pos + 4 < id; pos += 4)
                _mm256_storeu_si256(reinterpret_cast<__m256i*>(values + pos),
                    _mm256_or_si256(_mm256_srlv_epi64(
                        _mm256_lddqu_si256(reinterpret_cast<const __m256i*>(values + pos + d)),
                        id2),
                        _mm256_sllv_epi64(_mm256_lddqu_si256(reinterpret_cast<const __m256i*>(values + pos + d + 1)),
                            id1)));

            for (; pos < id; pos++)
                values[pos] = (values[pos + d] >> cnt1) | (values[pos + d + 1] << cnt2);

            values[id] = values[sz - 1] >> cnt1;
            memset(values + id + 1, 0, sizeof(uint64_t) * d);
        }
        return *this;
    }

    id0& operator<<=(int shift) {
        if (shift == 0 || n == 0)
            return *this;

        if (shift < 0)
            return *this >>= -shift;

        int sz = get_size();
        if (!(shift & 255)) {
            shift >>= 6;
            if (shift > sz)
                shift = sz;

            for (int i = sz - 4; i >= shift; i -= 4)
                _mm256_storeu_si256(reinterpret_cast<__m256i*>(values + i),
                    _mm256_lddqu_si256(reinterpret_cast<const __m256i*>(values + i - shift)));

            memset(values, 0, sizeof(uint64_t) * shift);
        } else if (!(shift & 63)) {
            shift >>= 6;
            if (shift > sz)
                shift = sz;

            int pos = sz - 1;
            for (; pos >= shift + 3; pos -= 4)
                _mm256_storeu_si256(reinterpret_cast<__m256i*>(values + pos - 3),
                    _mm256_lddqu_si256(reinterpret_cast<const __m256i*>(values + pos - 3 - shift)));

            for (; pos >= shift; pos--)
                values[pos] = values[pos - shift];

            memset(values, 0, sizeof(uint64_t) * shift);
        } else {
            int d = shift >> 6, cnt1 = shift & 63, cnt2 = 64 - cnt1;
            if (d >= sz) {
                memset(values, 0, sizeof(uint64_t) * sz);
                return *this;
            }

            int pos = sz - 1;
            __m256i id1 = _mm256_set1_epi64x(cnt1), id2 = _mm256_set1_epi64x(cnt2);
            for (; pos > d + 3; pos -= 4)
                _mm256_storeu_si256(reinterpret_cast<__m256i*>(values + pos - 3),
                    _mm256_or_si256(_mm256_sllv_epi64(
                        _mm256_lddqu_si256(reinterpret_cast<const __m256i*>(values + pos - 3 - d)),
                        id1),
                        _mm256_srlv_epi64(_mm256_lddqu_si256(reinterpret_cast<const __m256i*>(values + pos - 4 - d)),
                            id2)));

            for (; pos > d; pos--)
                values[pos] = (values[pos - d] << cnt1) | (values[pos - d - 1] >> cnt2);

            values[d] = values[0] << cnt1;
            memset(values, 0, sizeof(uint64_t) * d);
        }

        remove_trash();
        return *this;
    }

    friend id0 operator|(const id0 &a, const id0 &b) {
        return id0(a) |= b;
    }

    friend id0 operator&(const id0 &a, const id0 &b) {
        return id0(a) &= b;
    }

    friend id0 operator^(const id0 &a, const id0 &b) {
        return id0(a) ^= b;
    }

    friend id0 operator>>(const id0 &a, int shift) {
        return id0(a) >>= shift;
    }

    friend id0 operator<<(const id0 &a, int shift) {
        return id0(a) <<= shift;
    }

    bool operator==(const id0 &bs) const {
        if (n != bs.size())
            return false;

        int sz = get_size();
        for (int pos = 0; pos < sz; pos += 4)
            if (!_mm256_testz_si256(_mm256_set1_epi32(-1),
                    _mm256_xor_si256(_mm256_lddqu_si256(reinterpret_cast<const __m256i*>(values + pos)),
                        _mm256_lddqu_si256(reinterpret_cast<const __m256i*>(bs.data() + pos)))))
                return false;

        return true;
    }

    bool operator!=(const id0 &bs) const {
        return !(*this == bs);
    }

    int find_next_one(int pos) const {
        if (pos >= n)
            return n;

        int sz = get_size(), id = pos >> 6;
        for (uint64_t value; (id & 3) || id == (pos >> 6); id++)
            if (value = id == (pos >> 6) ? (values[id] >> (pos & 63) << (pos & 63)) : values[id])
                return (id << 6) + __builtin_ctzll(value);

        for (; id < sz; id += 4)
            if (!_mm256_testz_si256(_mm256_set1_epi32(-1),
                    _mm256_lddqu_si256(reinterpret_cast<const __m256i*>(values + id))))
                break;

        if (id == sz)
            return n;

        for (;; id++)
            if (values[id])
                return (id << 6) + __builtin_ctzll(values[id]);
    }

    int find_next_zero(int pos) const {
        if (pos >= n)
            return n;

        int sz = get_size(), id = pos >> 6;
        for (uint64_t value; (id & 3) || id == (pos >> 6); id++)
            if (value = ~(id == (pos >> 6) ? (values[id] >> (pos & 63) << (pos & 63) | (uint64_t(1) << (pos & 63)) - 1) : values[id]))
                return (id << 6) + __builtin_ctzll(value);

        for (; id < sz; id += 4)
            if (!_mm256_testz_si256(_mm256_set1_epi32(-1),
                    _mm256_xor_si256(_mm256_lddqu_si256(reinterpret_cast<const __m256i*>(values + id)),
                        _mm256_set1_epi32(-1))))
                break;

        if (id == sz)
            return n;

        for (;; id++)
            if (~values[id])
                return (id << 6) + __builtin_ctzll(~values[id]);
    }

    int find_prev_one(int pos) const {
        if (pos < 0)
            return -1;

        int id = pos >> 6;
        for (uint64_t value; id >= 0 && ((id & 3) != 3 || id == (pos >> 6)); id--)
            if (value = id == (pos >> 6) ? (values[id] << (63 - (pos & 63)) >> (63 - (pos & 63))) : values[id])
                return (id << 6) + 63 - __builtin_clzll(value);

        for (; id >= 0; id -= 4)
            if (!_mm256_testz_si256(_mm256_set1_epi32(-1),
                    _mm256_lddqu_si256(reinterpret_cast<const __m256i*>(values + id - 3))))
                break;

        if (id == -1)
            return -1;

        for (;; id--)
            if (values[id])
                return (id << 6) + 63 - __builtin_clzll(values[id]);
    }

    int find_prev_zero(int pos) const {
        if (pos < 0)
            return -1;

        int id = pos >> 6;
        for (uint64_t value; id >= 0 && ((id & 3) != 3 || id == (pos >> 6)); id--)
            if (value = ~(id == (pos >> 6) ? (values[id] << (63 - (pos & 63)) >> (63 - (pos & 63)) | -(uint64_t(1) << ((pos & 63) + 1))) : values[id]))
                return (id << 6) + 63 - __builtin_clzll(value);

        for (; id >= 0; id -= 4)
            if (!_mm256_testz_si256(_mm256_set1_epi32(-1),
                    _mm256_xor_si256(_mm256_lddqu_si256(reinterpret_cast<const __m256i*>(values + id - 3)),
                        _mm256_set1_epi32(-1))))
                break;

        if (id == -1)
            return -1;

        for (;; id--)
            if (~values[id])
                return (id << 6) + 63 - __builtin_clzll(~values[id]);
    }

    bool any() const {
        int sz = get_size();
        for (int id = 0; id < sz; id += 4)
            if (!_mm256_testz_si256(_mm256_set1_epi32(-1),
                    _mm256_lddqu_si256(reinterpret_cast<const __m256i*>(values + id))))
                return true;

        return false;
    }

    void flip() {
        int sz = get_size();
        for (int id = 0; id < sz; id += 4)
            _mm256_storeu_si256(reinterpret_cast<__m256i*>(values + id),
                _mm256_xor_si256(_mm256_lddqu_si256(reinterpret_cast<const __m256i*>(values + id)),
                    _mm256_set1_epi32(-1)));

        remove_trash();
    }

    int popcount() const {
        int sz = get_size(), tot = 0;
        for (int i = 0; i < sz; i++)
            tot += __builtin_popcountll(values[i]);

        return tot;
    }

    void set() {
        memset(values, -1, sizeof(uint64_t) * get_size());
        remove_trash();
    }

    void reset() {
        memset(values, 0, sizeof(uint64_t) * get_size());
    }

    void set_segment(int l, int r) {
        while (l < r && (l & 255))
            set_bit(l++, true);

        while (r > l && (r & 255))
            set_bit(--r, true);

        l >>= 6;
        r >>= 6;
        for (int id = l; id < r; id += 4)
            _mm256_storeu_si256(reinterpret_cast<__m256i*>(values + id),
                _mm256_set1_epi64x(-1));
    }

    void reset_segment(int l, int r) {
        while (l < r && (l & 255))
            set_bit(l++, false);

        while (r > l && (r & 255))
            set_bit(--r, false);

        l >>= 6;
        r >>= 6;
        for (int id = l; id < r; id += 4)
            _mm256_storeu_si256(reinterpret_cast<__m256i*>(values + id),
                _mm256_setzero_si256());
    }

    explicit operator std::string() const {
        std::string res(n, '0');
        for (int i = 0; i < n; i++)
            res[i] = '0' + get_bit(i);

        return res;
    }

    explicit operator unsigned long long() const {
        unsigned long long res = 0;
        for (int i = n - 1; i >= 0; i--)
            res = (res << 1) ^ get_bit(i);

        return res;
    }

    friend std::ostream& operator<<(std::ostream &out, const id0 &bs) {
        out << std::string(bs);
        return out;
    }

    uint64_t* data() const {
        return values;
    }

    ~id0() {
        delete[] values;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    constexpr int N = 2e5 + 100;
    id0 bs(N);

    auto subtract = [&](int pos) {
        int first_one = bs.find_next_one(pos);
        

        bs.set_segment(pos, first_one);
        bs.set_bit(first_one, 0);
    };

    auto add = [&](int pos) {
        int first_zero = bs.find_next_zero(pos);
        bs.reset_segment(pos, first_zero);
        bs.set_bit(first_zero, 1);
    };

    for (auto &x : a) add(x);

    while (q--) {
        int pos, new_value;
        cin >> pos >> new_value;
        pos--;

        subtract(a[pos]);
        a[pos] = new_value;
        add(a[pos]);
        
        cout << bs.find_prev_one(N - 1) << '\n';

        assert(bs.find_prev_zero(N - 1) == N - 1);
        int prev_zero = bs.find_prev_zero(bs.find_prev_one(N - 1));
        if (prev_zero != -1) assert(prev_zero < bs.find_prev_one(N - 1) && !bs.get_bit(prev_zero));
    }
}