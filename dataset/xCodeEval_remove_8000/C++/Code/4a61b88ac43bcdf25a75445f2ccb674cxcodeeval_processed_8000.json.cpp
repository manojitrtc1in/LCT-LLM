








namespace std
{
template <typename...> using void_t = void;
}

template <typename T, typename _ = void> struct is_container : std::false_type
{};
template <typename... Ts> struct is_container_helper
{};
template <typename T>
struct is_container<T,
    typename std::conditional<false,
        is_container_helper<decltype(std::declval<T>().size()),
            decltype(std::declval<T>().begin()),
            decltype(std::declval<T>().end()),
            decltype(std::declval<T>().cbegin()),
            decltype(std::declval<T>().cend())>,
        void>::type> : public std::true_type
{};



class IO
{
    static const int bufSize = 1 << 20;

    char inBuf[bufSize], outBuf[bufSize];
    char *ip1 = inBuf, *ip2 = inBuf;
    int goodReadBit = 1, op1 = -1, op2 = bufSize - 1;
    FORCE_INLINE int gc()
    {
        return ip1 == ip2
                && (ip2 = (ip1 = inBuf) + fread(inBuf, 1, bufSize, stdin),
                    ip1 == ip2)
            ? (goodReadBit = 0, EOF)
            : *ip1++;
    }
    template <typename T> FORCE_INLINE void __RI(T &x)
    {
        int ch = gc(), neg = 1;
        x = 0;
        for (; !(isdigit(ch) || ch == '-' || ch == EOF); ch = gc()) {}
        if (ch == EOF) [[unlikely]]
            return;
        if (ch == '-') neg = -1, ch = gc();
        for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - 48) * neg;
    }
    template <typename T> FORCE_INLINE void __RC(T &x)
    {
        int ch;
        while (isspace(ch = gc())) {}
        if (ch == EOF) return;
        x = ch;
    }
    FORCE_INLINE void __RS(std::string &x)
    {
        char ch;
        x.clear();
        for (ch = gc(); isspace(ch); ch = gc()) {}
        if (ch == EOF) return;
        for (; !isspace(ch) && ch != EOF; ch = gc()) x.push_back(ch);
    }

public:
    FORCE_INLINE IO &R(char &x) { return __RC(x), (*this); }
    FORCE_INLINE IO &R(unsigned char &x) { return __RC(x), (*this); }
    FORCE_INLINE IO &R(std::string &x) { return __RS(x), (*this); }
    template <typename T1, typename T2> FORCE_INLINE IO &R(std::pair<T1, T2> &x)
    {
        return R(x.first), R(x.second), (*this);
    }
    template <typename T, typename... Args> FORCE_INLINE IO &RA(T *a, int n)
    {
        for (int i = 0; i < n; ++i) R(a[i]);
        return (*this);
    }
    template <typename T, typename... Args>
    FORCE_INLINE IO &R(T &x, Args &...args)
    {
        return R(x), R(args...), (*this);
    }
    template <typename T, typename... Args>
    FORCE_INLINE IO &RA(T *a, int n, Args... args)
    {
        for (int i = 0; i < n; ++i) RA(a[i], args...);
        return (*this);
    }
    template <typename T>
    FORCE_INLINE typename std::enable_if<std::is_integral<T>::value, IO>::type &
        R(T &x)
    {
        return __RI(x), (*this);
    }
    template <typename T>
    FORCE_INLINE typename std::enable_if<is_container<T>::value, IO>::type &R(
        T &x)
    {
        for (auto &i : x) R(i);
        return (*this);
    }
    template <typename T>
    FORCE_INLINE typename std::enable_if<
        std::is_void<std::void_t<decltype(std::declval<T>().read())>>::value,
        IO>::type &
        R(T &x)
    {
        return x.read(), (*this);
    }

private:
    const char space = ' ';
    FORCE_INLINE void pc(const char &x)
    {
        if (op1 == op2) flush();
        outBuf[++op1] = x;
    }
    template <typename T> FORCE_INLINE void __WI(T _x)
    {
        typename std::make_unsigned<T>::type x = _x;
        if (_x < 0) pc('-'), x = ~x + 1;
        static char buf[sizeof(T) * 16 / 5];
        static int len = -1;
        static constexpr char digits[201]
            = "0001020304050607080910111213141516171819"
              "2021222324252627282930313233343536373839"
              "4041424344454647484950515253545556575859"
              "6061626364656667686970717273747576777879"
              "8081828384858687888990919293949596979899";
        while (x >= 100) {
            auto num = (x % 100) * 2;
            x /= 100;
            buf[++len] = digits[num + 1];
            buf[++len] = digits[num];
        }
        if (x >= 10) {
            auto num = (x % 100) * 2;
            buf[++len] = digits[num + 1];
            buf[++len] = digits[num];
        } else {
            buf[++len] = '0' + x;
        }
        while (len >= 0) { pc(buf[len]), --len; }
    }

public:
    FORCE_INLINE void flush() { fwrite(outBuf, 1, op1 + 1, stdout), op1 = -1; }
    FORCE_INLINE IO &W(const char &x) { return pc(x), (*this); }
    FORCE_INLINE IO &W(const char *x)
    {
        while (*x != '\0') pc(*(x++));
        return (*this);
    }
    FORCE_INLINE IO &W(const std::string &x) { return W(x.c_str()), (*this); }
    template <typename T1, typename T2>
    FORCE_INLINE IO &W(const std::pair<T1, T2> &x)
    {
        WS(x.first);
        W(x.second);
        return (*this);
    }
    FORCE_INLINE IO &WL() { return W('\n'), (*this); }
    template <typename T> FORCE_INLINE IO &WL(const T &x)
    {
        return W(x), W('\n'), (*this);
    }
    FORCE_INLINE IO &WS() { return W(space), (*this); }
    template <typename T> FORCE_INLINE IO &WS(const T &x)
    {
        return W(x), W(space), (*this);
    }
    template <typename T> FORCE_INLINE IO &WA(T *a, int n)
    {
        for (int i = 0; i < n; i++) WS(a[i]);
        WL();
        return (*this);
    }
    template <typename T, typename... Args>
    FORCE_INLINE IO &W(const T &x, const Args &...args)
    {
        W(x), W(space), W(args...);
        return (*this);
    }
    template <typename T, typename... Args>
    FORCE_INLINE IO &WS(const T &x, const Args &...args)
    {
        return W(x), W(space), W(args...), W(space), (*this);
    }
    template <typename... Args> FORCE_INLINE IO &WL(const Args &...args)
    {
        return W(args...), W('\n'), (*this);
    }
    template <typename T, typename... Args>
    FORCE_INLINE IO &WA(T *a, int n, Args... args)
    {
        for (int i = 0; i < n; i++) WA(a[i], args...);
        return (*this);
    }
    template <typename T>
    FORCE_INLINE typename std::enable_if<std::is_integral<T>::value, IO>::type &
        W(const T &x)
    {
        return __WI(x), (*this);
    }
    template <typename T>
    FORCE_INLINE typename std::enable_if<is_container<T>::value, IO>::type &W(
        const T &x)
    {

        for (auto &i : x) {
            if (is_container<decltype(i)>::value)
                W(i);
            else
                WS(i);
        }
        WL();
        return (*this);
    }
    template <typename T>
    FORCE_INLINE typename std::enable_if<
        std::is_void<std::void_t<decltype(std::declval<T>().write())>>::value,
        IO>::type &
        W(const T &x)
    {
        return x.write(), (*this);
    }
    template <typename T> FORCE_INLINE IO &operator>>(T &x)
    {
        R(x);
        return (*this);
    }
    template <typename T> FORCE_INLINE IO &operator<<(const T &x)
    {
        W(x);
        return (*this);
    }
    int good() { return goodReadBit; }
    IO() {}
    ~IO() { flush(); }
} io;

















namespace pdqsort_detail
{
enum {
    insertion_sort_threshold = 24,
    ninther_threshold = 128,
    partial_insertion_sort_limit = 8,
    block_size = 64,
    cacheline_size = 64
};

template <class T> struct is_default_compare : std::false_type
{};
template <class T> struct is_default_compare<std::less<T>> : std::true_type
{};
template <class T> struct is_default_compare<std::greater<T>> : std::true_type
{};

template <class T> inline int log2(T n)
{
    int log = 0;
    while (n >>= 1) ++log;
    return log;
}
template <class Iter, class Compare>
inline void id10(Iter begin, Iter end, Compare comp)
{
    typedef typename std::iterator_traits<Iter>::value_type T;
    if (begin == end) return;
    for (Iter cur = begin + 1; cur != end; ++cur) {
        Iter sift = cur;
        Iter id11 = cur - 1;
        if (comp(*sift, *id11)) {
            T tmp = PDQSORT_PREFER_MOVE(*sift);
            do {
                *sift-- = PDQSORT_PREFER_MOVE(*id11);
            } while (sift != begin && comp(tmp, *--id11));
            *sift = PDQSORT_PREFER_MOVE(tmp);
        }
    }
}
template <class Iter, class Compare>
inline void id4(Iter begin, Iter end, Compare comp)
{
    typedef typename std::iterator_traits<Iter>::value_type T;
    if (begin == end) return;
    for (Iter cur = begin + 1; cur != end; ++cur) {
        Iter sift = cur;
        Iter id11 = cur - 1;
        if (comp(*sift, *id11)) {
            T tmp = PDQSORT_PREFER_MOVE(*sift);
            do {
                *sift-- = PDQSORT_PREFER_MOVE(*id11);
            } while (comp(tmp, *--id11));
            *sift = PDQSORT_PREFER_MOVE(tmp);
        }
    }
}
template <class Iter, class Compare>
inline bool id12(Iter begin, Iter end, Compare comp)
{
    typedef typename std::iterator_traits<Iter>::value_type T;
    if (begin == end) return true;
    std::size_t limit = 0;
    for (Iter cur = begin + 1; cur != end; ++cur) {
        Iter sift = cur;
        Iter id11 = cur - 1;
        if (comp(*sift, *id11)) {
            T tmp = PDQSORT_PREFER_MOVE(*sift);
            do {
                *sift-- = PDQSORT_PREFER_MOVE(*id11);
            } while (sift != begin && comp(tmp, *--id11));
            *sift = PDQSORT_PREFER_MOVE(tmp);
            limit += cur - sift;
        }
        if (limit > partial_insertion_sort_limit) return false;
    }
    return true;
}
template <class Iter, class Compare>
inline void sort2(Iter a, Iter b, Compare comp)
{
    if (comp(*b, *a)) std::iter_swap(a, b);
}
template <class Iter, class Compare>
inline void sort3(Iter a, Iter b, Iter c, Compare comp)
{
    sort2(a, b, comp);
    sort2(b, c, comp);
    sort2(a, b, comp);
}
template <class T> inline T *id14(T *p)
{

    std::uintptr_t ip = reinterpret_cast<std::uintptr_t>(p);

    std::size_t ip = reinterpret_cast<std::size_t>(p);

    ip = (ip + cacheline_size - 1) & -cacheline_size;
    return reinterpret_cast<T *>(ip);
}
template <class Iter>
inline void swap_offsets(Iter first, Iter last, unsigned char *id3,
    unsigned char *id13, size_t num, bool id0)
{
    typedef typename std::iterator_traits<Iter>::value_type T;
    if (id0) {
        for (size_t i = 0; i < num; ++i) {
            std::iter_swap(first + id3[i], last - id13[i]);
        }
    } else if (num > 0) {
        Iter l = first + id3[0];
        Iter r = last - id13[0];
        T tmp(PDQSORT_PREFER_MOVE(*l));
        *l = PDQSORT_PREFER_MOVE(*r);
        for (size_t i = 1; i < num; ++i) {
            l = first + id3[i];
            *r = PDQSORT_PREFER_MOVE(*l);
            r = last - id13[i];
            *l = PDQSORT_PREFER_MOVE(*r);
        }
        *r = PDQSORT_PREFER_MOVE(tmp);
    }
}
template <class Iter, class Compare>
inline std::pair<Iter, bool> id15(
    Iter begin, Iter end, Compare comp)
{
    typedef typename std::iterator_traits<Iter>::value_type T;
    T pivot(PDQSORT_PREFER_MOVE(*begin));
    Iter first = begin;
    Iter last = end;
    while (comp(*++first, pivot))
        ;
    if (first - 1 == begin)
        while (first < last && !comp(*--last, pivot))
            ;
    else
        while (!comp(*--last, pivot))
            ;
    bool id5 = first >= last;
    if (!id5) {
        std::iter_swap(first, last);
        ++first;
        unsigned char offsets_l_storage[block_size + cacheline_size];
        unsigned char offsets_r_storage[block_size + cacheline_size];
        unsigned char *id3 = id14(offsets_l_storage);
        unsigned char *id13 = id14(offsets_r_storage);
        Iter id2 = first;
        Iter id7 = last;
        size_t num_l, num_r, start_l, start_r;
        num_l = num_r = start_l = start_r = 0;
        while (first < last) {
            size_t num_unknown = last - first;
            size_t left_split
                = num_l == 0 ? (num_r == 0 ? num_unknown / 2 : num_unknown) : 0;
            size_t right_split = num_r == 0 ? (num_unknown - left_split) : 0;
            if (left_split >= block_size) {
                for (size_t i = 0; i < block_size;) {
                    id3[num_l] = i++, num_l += !comp(*first, pivot),
                    ++first;
                    id3[num_l] = i++, num_l += !comp(*first, pivot),
                    ++first;
                    id3[num_l] = i++, num_l += !comp(*first, pivot),
                    ++first;
                    id3[num_l] = i++, num_l += !comp(*first, pivot),
                    ++first;
                    id3[num_l] = i++, num_l += !comp(*first, pivot),
                    ++first;
                    id3[num_l] = i++, num_l += !comp(*first, pivot),
                    ++first;
                    id3[num_l] = i++, num_l += !comp(*first, pivot),
                    ++first;
                    id3[num_l] = i++, num_l += !comp(*first, pivot),
                    ++first;
                }
            } else {
                for (size_t i = 0; i < left_split;) {
                    id3[num_l] = i++, num_l += !comp(*first, pivot),
                    ++first;
                }
            }
            if (right_split >= block_size) {
                for (size_t i = 0; i < block_size;) {
                    id13[num_r] = ++i, num_r += comp(*--last, pivot);
                    id13[num_r] = ++i, num_r += comp(*--last, pivot);
                    id13[num_r] = ++i, num_r += comp(*--last, pivot);
                    id13[num_r] = ++i, num_r += comp(*--last, pivot);
                    id13[num_r] = ++i, num_r += comp(*--last, pivot);
                    id13[num_r] = ++i, num_r += comp(*--last, pivot);
                    id13[num_r] = ++i, num_r += comp(*--last, pivot);
                    id13[num_r] = ++i, num_r += comp(*--last, pivot);
                }
            } else {
                for (size_t i = 0; i < right_split;) {
                    id13[num_r] = ++i, num_r += comp(*--last, pivot);
                }
            }
            size_t num = std::min(num_l, num_r);
            swap_offsets(id2, id7, id3 + start_l,
                id13 + start_r, num, num_l == num_r);
            num_l -= num;
            num_r -= num;
            start_l += num;
            start_r += num;
            if (num_l == 0) {
                start_l = 0;
                id2 = first;
            }
            if (num_r == 0) {
                start_r = 0;
                id7 = last;
            }
        }
        if (num_l) {
            id3 += start_l;
            while (num_l--)
                std::iter_swap(id2 + id3[num_l], --last);
            first = last;
        }
        if (num_r) {
            id13 += start_r;
            while (num_r--)
                std::iter_swap(id7 - id13[num_r], first),
                    ++first;
            last = first;
        }
    }
    Iter pivot_pos = first - 1;
    *begin = PDQSORT_PREFER_MOVE(*pivot_pos);
    *pivot_pos = PDQSORT_PREFER_MOVE(pivot);
    return std::make_pair(pivot_pos, id5);
}
template <class Iter, class Compare>
inline std::pair<Iter, bool> partition_right(Iter begin, Iter end, Compare comp)
{
    typedef typename std::iterator_traits<Iter>::value_type T;
    T pivot(PDQSORT_PREFER_MOVE(*begin));
    Iter first = begin;
    Iter last = end;
    while (comp(*++first, pivot))
        ;
    if (first - 1 == begin)
        while (first < last && !comp(*--last, pivot))
            ;
    else
        while (!comp(*--last, pivot))
            ;
    bool id5 = first >= last;
    while (first < last) {
        std::iter_swap(first, last);
        while (comp(*++first, pivot))
            ;
        while (!comp(*--last, pivot))
            ;
    }
    Iter pivot_pos = first - 1;
    *begin = PDQSORT_PREFER_MOVE(*pivot_pos);
    *pivot_pos = PDQSORT_PREFER_MOVE(pivot);
    return std::make_pair(pivot_pos, id5);
}
template <class Iter, class Compare>
inline Iter partition_left(Iter begin, Iter end, Compare comp)
{
    typedef typename std::iterator_traits<Iter>::value_type T;
    T pivot(PDQSORT_PREFER_MOVE(*begin));
    Iter first = begin;
    Iter last = end;
    while (comp(pivot, *--last))
        ;
    if (last + 1 == end)
        while (first < last && !comp(pivot, *++first))
            ;
    else
        while (!comp(pivot, *++first))
            ;
    while (first < last) {
        std::iter_swap(first, last);
        while (comp(pivot, *--last))
            ;
        while (!comp(pivot, *++first))
            ;
    }
    Iter pivot_pos = last;
    *begin = PDQSORT_PREFER_MOVE(*pivot_pos);
    *pivot_pos = PDQSORT_PREFER_MOVE(pivot);
    return pivot_pos;
}
template <class Iter, class Compare, bool Branchless>
inline void id6(
    Iter begin, Iter end, Compare comp, int bad_allowed, bool leftmost = true)
{
    typedef typename std::iterator_traits<Iter>::difference_type diff_t;
    while (true) {
        diff_t size = end - begin;
        if (size < insertion_sort_threshold) {
            if (leftmost)
                id10(begin, end, comp);
            else
                id4(begin, end, comp);
            return;
        }
        diff_t s2 = size / 2;
        if (size > ninther_threshold) {
            sort3(begin, begin + s2, end - 1, comp);
            sort3(begin + 1, begin + (s2 - 1), end - 2, comp);
            sort3(begin + 2, begin + (s2 + 1), end - 3, comp);
            sort3(begin + (s2 - 1), begin + s2, begin + (s2 + 1), comp);
            std::iter_swap(begin, begin + s2);
        } else
            sort3(begin + s2, begin, end - 1, comp);
        if (!leftmost && !comp(*(begin - 1), *begin)) {
            begin = partition_left(begin, end, comp) + 1;
            continue;
        }
        std::pair<Iter, bool> part_result = Branchless
            ? id15(begin, end, comp)
            : partition_right(begin, end, comp);
        Iter pivot_pos = part_result.first;
        bool id5 = part_result.second;
        diff_t l_size = pivot_pos - begin;
        diff_t r_size = end - (pivot_pos + 1);
        bool id8 = l_size < size / 8 || r_size < size / 8;
        if (id8) {
            if (--bad_allowed == 0) {
                std::make_heap(begin, end, comp);
                std::sort_heap(begin, end, comp);
                return;
            }
            if (l_size >= insertion_sort_threshold) {
                std::iter_swap(begin, begin + l_size / 4);
                std::iter_swap(pivot_pos - 1, pivot_pos - l_size / 4);
                if (l_size > ninther_threshold) {
                    std::iter_swap(begin + 1, begin + (l_size / 4 + 1));
                    std::iter_swap(begin + 2, begin + (l_size / 4 + 2));
                    std::iter_swap(pivot_pos - 2, pivot_pos - (l_size / 4 + 1));
                    std::iter_swap(pivot_pos - 3, pivot_pos - (l_size / 4 + 2));
                }
            }
            if (r_size >= insertion_sort_threshold) {
                std::iter_swap(pivot_pos + 1, pivot_pos + (1 + r_size / 4));
                std::iter_swap(end - 1, end - r_size / 4);
                if (r_size > ninther_threshold) {
                    std::iter_swap(pivot_pos + 2, pivot_pos + (2 + r_size / 4));
                    std::iter_swap(pivot_pos + 3, pivot_pos + (3 + r_size / 4));
                    std::iter_swap(end - 2, end - (1 + r_size / 4));
                    std::iter_swap(end - 3, end - (2 + r_size / 4));
                }
            }
        } else {
            if (id5
                && id12(begin, pivot_pos, comp)
                && id12(pivot_pos + 1, end, comp))
                return;
        }
        id6<Iter, Compare, Branchless>(
            begin, pivot_pos, comp, bad_allowed, leftmost);
        begin = pivot_pos + 1;
        leftmost = false;
    }
}
}
template <class Iter, class Compare>
inline void id9(Iter begin, Iter end, Compare comp)
{
    if (begin == end) return;

    pdqsort_detail::id6<Iter, Compare,
        pdqsort_detail::is_default_compare<
            typename std::decay<Compare>::type>::value
            && std::is_arithmetic<
                typename std::iterator_traits<Iter>::value_type>::value>(
        begin, end, comp, pdqsort_detail::log2(end - begin));

    pdqsort_detail::id6<Iter, Compare, false>(
        begin, end, comp, pdqsort_detail::log2(end - begin));

}
template <class Iter> inline void id9(Iter begin, Iter end)
{
    typedef typename std::iterator_traits<Iter>::value_type T;
    id9(begin, end, std::less<T>());
}
template <class Iter, class Compare>
inline void id1(Iter begin, Iter end, Compare comp)
{
    if (begin == end) return;
    pdqsort_detail::id6<Iter, Compare, true>(
        begin, end, comp, pdqsort_detail::log2(end - begin));
}
template <class Iter> inline void id1(Iter begin, Iter end)
{
    typedef typename std::iterator_traits<Iter>::value_type T;
    id1(begin, end, std::less<T>());
}








using i128 = __int128_t;
using i64 = int64_t;
using i32 = int32_t;
using i16 = int16_t;
using u128 = __uint128_t;
using u64 = uint64_t;
using u32 = uint32_t;
using u16 = uint16_t;
const i32 INF = 0x3f3f3f3f;
const i64 INFL = 0x3f3f3f3f3f3f3f3f;

    do {                                                                       \
        freopen(
        freopen(
    } while (0)


using namespace std;
const int MAXV = 1 << 17;
const int B = 256;
int count(vector<int> v)
{
    id9(ALL(v));
    int l = 0, res = 0, n = v.size();
    for (int i = 0; i < n; i++) {
        

        if (v[l] == v[i]) {
            res = max(res, i - l + 1);
        } else {
            l = i;
        }
    }
    return res;
}
int main()
{
    int n;
    io >> n;
    vector<int> a(n);
    io >> a;
    vector<int> v;
    int ans = 0;
    for (int i = -B; i <= B; i++) {
        v.clear();
        for (int j = 0; j < n; j++) { v.push_back(a[j] - i * j); }
        ans = max(ans, count(v));
    }

    for (int i = 0; i < n; i++) {
        v.clear();
        for (int j = i + 1; j < min(n, i + MAXV / B + 1); j++) {
            if ((a[j] - a[i]) % (j - i) == 0) {
                int d = (a[j] - a[i]) / (j - i);
                if (abs(d) <= B) continue;
                v.push_back(a[j] - d * (j - i - 1));
            }
        }
        ans = max(ans, count(v) + 1);
    }
    io.WL(n - ans);
    return 0;
}