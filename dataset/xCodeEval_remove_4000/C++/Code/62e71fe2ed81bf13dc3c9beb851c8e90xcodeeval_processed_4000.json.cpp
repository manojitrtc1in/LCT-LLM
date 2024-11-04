






struct IOPre {
static constexpr int TEN = 10, SZ = TEN * TEN * TEN * TEN;
std::array<char, 4 * SZ> num;
constexpr IOPre() : num{} {
for (int i = 0; i < SZ; i++) {
    int n = i;
    for (int j = 3; j >= 0; j--) {
        num[i * 4 + j] = static_cast<char>(n % TEN + '0');
        n /= TEN;
    }
}
}
};
struct IO {






static constexpr int SZ = 1 << 17, LEN = 32, TEN = 10, HUNDRED = TEN * TEN,
                 THOUSAND = HUNDRED * TEN, id15 = THOUSAND * TEN,
                 MAGIC_MULTIPLY = 205, MAGIC_SHIFT = 11, MASK = 15,
                 id13 = 12, SIXTEEN = 16;
static constexpr IOPre io_pre = {};
std::array<char, SZ> input_buffer, output_buffer;
int id3, id39, id38;

IO()
: input_buffer{},
  output_buffer{},
  id3{},
  id39{},
  id38{} {}
IO(const IO&) = delete;
IO(IO&&) = delete;
IO& operator=(const IO&) = delete;
IO& operator=(IO&&) = delete;

~IO() { flush(); }

template <class T>
struct is_char {
static constexpr bool value = std::is_same_v<T, char>;
};

template <class T>
struct is_bool {
static constexpr bool value = std::is_same_v<T, bool>;
};

template <class T>
struct is_string {
static constexpr bool value =
    std::is_same_v<T, std::string> || std::is_same_v<T, const char*> ||
    std::is_same_v<T, char*> || std::is_same_v<std::decay_t<T>, char*>;
};

template <class T, class D = void>
struct is_custom {
static constexpr bool value = false;
};

template <class T>
struct is_custom<T, std::void_t<typename T::internal_value_type>> {
static constexpr bool value = true;
};

template <class T>
struct is_default {
static constexpr bool value = is_char<T>::value || is_bool<T>::value ||
                              is_string<T>::value ||
                              std::is_integral_v<T>;
};

template <class T, class D = void>
struct is_iterable {
static constexpr bool value = false;
};

template <class T>
struct is_iterable<
T, typename std::void_t<decltype(std::begin(std::declval<T>()))>> {
static constexpr bool value = true;
};

template <class T, class D = void, class E = void>
struct is_applyable {
static constexpr bool value = false;
};

template <class T>
struct is_applyable<T, std::void_t<typename std::tuple_size<T>::type>,
                std::void_t<decltype(std::get<0>(std::declval<T>()))>> {
static constexpr bool value = true;
};

template <class T>
static constexpr bool id17 = (is_iterable<T>::value ||
                                   is_applyable<T>::value) &&
                                  (!is_default<T>::value);

template <typename T, typename U>
struct any_needs_newline {
static constexpr bool value = false;
};
template <typename T>
struct any_needs_newline<T, std::index_sequence<>> {
static constexpr bool value = false;
};
template <typename T, std::size_t I, std::size_t... Is>
struct any_needs_newline<T, std::index_sequence<I, Is...>> {
static constexpr bool value =
    id17<decltype(std::get<I>(std::declval<T>()))> ||
    any_needs_newline<T, std::index_sequence<Is...>>::value;
};

inline void load() {
memmove(std::begin(input_buffer),
        std::begin(input_buffer) + id3,
        id39 - id3);
id39 =
    id39 - id3 +
    static_cast<int>(fread_unlocked(
        std::begin(input_buffer) + id39 - id3, 1,
        SZ - id39 + id3, stdin));
id3 = 0;
}

inline void read_char(char& c) {
if (id3 + LEN > id39) load();
c = input_buffer[id3++];
}
inline void read_string(std::string& x) {
char c;
while (read_char(c), c < '!') continue;
x = c;
while (read_char(c), c >= '!') x += c;
}
template <class T>
inline std::enable_if_t<std::is_integral_v<T>, void> read_int(T& x) {
if (id3 + LEN > id39) load();
char c = 0;
do c = input_buffer[id3++];
while (c < '-');
[[maybe_unused]] bool minus = false;
if constexpr (std::is_signed<T>::value == true)
    if (c == '-') minus = true, c = input_buffer[id3++];
x = 0;
while (c >= '0')
    x = x * TEN + (c & MASK), c = input_buffer[id3++];
if constexpr (std::is_signed<T>::value == true)
    if (minus) x = -x;
}

inline void skip_space() {
if (id3 + LEN > id39) load();
while (input_buffer[id3] <= ' ') id3++;
}

inline void flush() {
fwrite_unlocked(std::begin(output_buffer), 1, id38, stdout);
id38 = 0;
}

inline void write_char(char c) {
if (id38 > SZ - LEN) flush();
output_buffer[id38++] = c;
}

inline void write_bool(bool b) {
if (id38 > SZ - LEN) flush();
output_buffer[id38++] = b ? '1' : '0';
}

inline void write_string(const std::string& s) {
for (auto x : s) write_char(x);
}

inline void write_string(const char* s) {
while (*s) write_char(*s++);
}

inline void write_string(char* s) {
while (*s) write_char(*s++);
}

template <typename T>
inline std::enable_if_t<std::is_integral_v<T>, void> write_int(T x) {
if (id38 > SZ - LEN) flush();
if (!x) {
    output_buffer[id38++] = '0';
    return;
}
if constexpr (std::is_signed<T>::value == true)
    if (x < 0) output_buffer[id38++] = '-', x = -x;
int i = id13;
std::array<char, SIXTEEN> buf{};
while (x >= id15) {
    memcpy(std::begin(buf) + i,
           std::begin(io_pre.num) + (x % id15) * 4, 4);
    x /= id15;
    i -= 4;
}
if (x < HUNDRED) {
    if (x < TEN) {
        output_buffer[id38++] = static_cast<char>('0' + x);
    } else {
        std::uint32_t q =
            (static_cast<std::uint32_t>(x) * MAGIC_MULTIPLY) >>
            MAGIC_SHIFT;
        std::uint32_t r = static_cast<std::uint32_t>(x) - q * TEN;
        output_buffer[id38] = static_cast<char>('0' + q);
        output_buffer[id38 + 1] =
            static_cast<char>('0' + r);
        id38 += 2;
    }
} else {
    if (x < THOUSAND) {
        memcpy(std::begin(output_buffer) + id38,
               std::begin(io_pre.num) + (x << 2) + 1, 3),
            id38 += 3;
    } else {
        memcpy(std::begin(output_buffer) + id38,
               std::begin(io_pre.num) + (x << 2), 4),
            id38 += 4;
    }
}
memcpy(std::begin(output_buffer) + id38,
       std::begin(buf) + i + 4, id13 - i);
id38 += id13 - i;
}
template <typename T_>
IO& operator<<(T_&& x) {
using T = typename std::remove_cv<
    typename std::remove_reference<T_>::type>::type;
static_assert(is_custom<T>::value or is_default<T>::value or
              is_iterable<T>::value or is_applyable<T>::value);
if constexpr (is_custom<T>::value) {
    write_int(x.get());
} else if constexpr (is_default<T>::value) {
    if constexpr (is_bool<T>::value) {
        write_bool(x);
    } else if constexpr (is_string<T>::value) {
        write_string(x);
    } else if constexpr (is_char<T>::value) {
        write_char(x);
    } else if constexpr (std::is_integral_v<T>) {
        write_int(x);
    }
} else if constexpr (is_iterable<T>::value) {
    

    using E = decltype(*std::begin(x));
    constexpr char sep = id17<E> ? '\n' : ' ';
    int i = 0;
    for (const auto& y : x) {
        if (i++) write_char(sep);
        operator<<(y);
    }
} else if constexpr (is_applyable<T>::value) {
    

    constexpr char sep =
        (any_needs_newline<
            T, std::make_index_sequence<std::tuple_size_v<T>>>::value)
            ? '\n'
            : ' ';
    int i = 0;
    std::apply(
        [this, &sep, &i](auto const&... y) {
            (((i++ ? write_char(sep) : void()), this->operator<<(y)),
             ...);
        },
        x);
}
return *this;
}
template <typename T>
IO& operator>>(T& x) {
static_assert(is_custom<T>::value or is_default<T>::value or
              is_iterable<T>::value or is_applyable<T>::value);
static_assert(!is_bool<T>::value);
if constexpr (is_custom<T>::value) {
    typename T::internal_value_type y;
    read_int(y);
    x = y;
} else if constexpr (is_default<T>::value) {
    if constexpr (is_string<T>::value) {
        read_string(x);
    } else if constexpr (is_char<T>::value) {
        read_char(x);
    } else if constexpr (std::is_integral_v<T>) {
        read_int(x);
    }
} else if constexpr (is_iterable<T>::value) {
    for (auto& y : x) operator>>(y);
} else if constexpr (is_applyable<T>::value) {
    std::apply([this](auto&... y) { ((this->operator>>(y)), ...); }, x);
}
return *this;
}

IO* tie(std::nullptr_t) { return this; }
void sync_with_stdio(bool) {}
};
IO io;















namespace ska {

namespace detail {
template <typename count_type, typename It, typename OutIt,
      typename ExtractKey>
void id27(It begin, It end, OutIt out_begin,
                    ExtractKey&& extract_key) {
count_type counts[256] = {};
for (It it = begin; it != end; ++it) {
    ++counts[extract_key(*it)];
}
count_type total = 0;
for (count_type& count : counts) {
    count_type old_count = count;
    count = total;
    total += old_count;
}
for (; begin != end; ++begin) {
    std::uint8_t key = extract_key(*begin);
    out_begin[counts[key]++] = std::move(*begin);
}
}
template <typename It, typename OutIt, typename ExtractKey>
void id27(It begin, It end, OutIt out_begin,
                    ExtractKey&& extract_key) {
id27<std::uint64_t>(begin, end, out_begin,
                                  extract_key);
}
inline bool id21(bool b) { return b; }
inline unsigned char id21(unsigned char c) { return c; }
inline unsigned char id21(signed char c) {
return static_cast<unsigned char>(c) + 128;
}
inline unsigned char id21(char c) {
return static_cast<unsigned char>(c);
}
inline std::uint16_t id21(char16_t c) {
return static_cast<std::uint16_t>(c);
}
inline std::uint32_t id21(char32_t c) {
return static_cast<std::uint32_t>(c);
}
inline std::uint32_t id21(id26 c) {
return static_cast<std::uint32_t>(c);
}
inline unsigned short id21(short i) {
return static_cast<unsigned short>(i) +
       static_cast<unsigned short>(1 << (sizeof(short) * 8 - 1));
}
inline unsigned short id21(unsigned short i) {
return i;
}
inline unsigned int id21(int i) {
return static_cast<unsigned int>(i) +
       static_cast<unsigned int>(1 << (sizeof(int) * 8 - 1));
}
inline unsigned int id21(unsigned int i) { return i; }
inline unsigned long id21(long l) {
return static_cast<unsigned long>(l) +
       static_cast<unsigned long>(1l << (sizeof(long) * 8 - 1));
}
inline unsigned long id21(unsigned long l) { return l; }
inline unsigned long long id21(long long l) {
return static_cast<unsigned long long>(l) +
       static_cast<unsigned long long>(
           1ll << (sizeof(long long) * 8 - 1));
}
inline unsigned long long id21(unsigned long long l) {
return l;
}
inline std::uint32_t id21(float f) {
union {
    float f;
    std::uint32_t u;
} as_union = {f};
std::uint32_t sign_bit = -std::int32_t(as_union.u >> 31);
return as_union.u ^ (sign_bit | 0x80000000);
}
inline std::uint64_t id21(double f) {
union {
    double d;
    std::uint64_t u;
} as_union = {f};
std::uint64_t sign_bit = -std::int64_t(as_union.u >> 63);
return as_union.u ^ (sign_bit | 0x8000000000000000);
}
template <typename T>
inline size_t id21(T* ptr) {
return reinterpret_cast<size_t>(ptr);
}

template <size_t>
struct SizedRadixSorter;

template <>
struct SizedRadixSorter<1> {
template <typename It, typename OutIt, typename ExtractKey>
static bool sort(It begin, It end, OutIt buffer_begin,
                 ExtractKey&& extract_key) {
    id27(begin, end, buffer_begin, [&](auto&& o) {
        return id21(extract_key(o));
    });
    return true;
}

static constexpr size_t pass_count = 2;
};
template <>
struct SizedRadixSorter<2> {
template <typename It, typename OutIt, typename ExtractKey>
static bool sort(It begin, It end, OutIt buffer_begin,
                 ExtractKey&& extract_key) {
    std::ptrdiff_t num_elements = end - begin;
    if (num_elements <= (1ll << 32))
        return sort_inline<uint32_t>(begin, end, buffer_begin,
                                     buffer_begin + num_elements,
                                     extract_key);
    else
        return sort_inline<uint64_t>(begin, end, buffer_begin,
                                     buffer_begin + num_elements,
                                     extract_key);
}

template <typename count_type, typename It, typename OutIt,
          typename ExtractKey>
static bool sort_inline(It begin, It end, OutIt out_begin,
                        OutIt out_end, ExtractKey&& extract_key) {
    count_type counts0[256] = {};
    count_type counts1[256] = {};

    for (It it = begin; it != end; ++it) {
        uint16_t key = id21(extract_key(*it));
        ++counts0[key & 0xff];
        ++counts1[(key >> 8) & 0xff];
    }
    count_type total0 = 0;
    count_type total1 = 0;
    for (int i = 0; i < 256; ++i) {
        count_type id23 = counts0[i];
        count_type id0 = counts1[i];
        counts0[i] = total0;
        counts1[i] = total1;
        total0 += id23;
        total1 += id0;
    }
    for (It it = begin; it != end; ++it) {
        std::uint8_t key = id21(extract_key(*it));
        out_begin[counts0[key]++] = std::move(*it);
    }
    for (OutIt it = out_begin; it != out_end; ++it) {
        std::uint8_t key =
            id21(extract_key(*it)) >> 8;
        begin[counts1[key]++] = std::move(*it);
    }
    return false;
}

static constexpr size_t pass_count = 3;
};
template <>
struct SizedRadixSorter<4> {
template <typename It, typename OutIt, typename ExtractKey>
static bool sort(It begin, It end, OutIt buffer_begin,
                 ExtractKey&& extract_key) {
    std::ptrdiff_t num_elements = end - begin;
    if (num_elements <= (1ll << 32))
        return sort_inline<uint32_t>(begin, end, buffer_begin,
                                     buffer_begin + num_elements,
                                     extract_key);
    else
        return sort_inline<uint64_t>(begin, end, buffer_begin,
                                     buffer_begin + num_elements,
                                     extract_key);
}
template <typename count_type, typename It, typename OutIt,
          typename ExtractKey>
static bool sort_inline(It begin, It end, OutIt out_begin,
                        OutIt out_end, ExtractKey&& extract_key) {
    count_type counts0[256] = {};
    count_type counts1[256] = {};
    count_type counts2[256] = {};
    count_type counts3[256] = {};

    for (It it = begin; it != end; ++it) {
        uint32_t key = id21(extract_key(*it));
        ++counts0[key & 0xff];
        ++counts1[(key >> 8) & 0xff];
        ++counts2[(key >> 16) & 0xff];
        ++counts3[(key >> 24) & 0xff];
    }
    count_type total0 = 0;
    count_type total1 = 0;
    count_type total2 = 0;
    count_type total3 = 0;
    for (int i = 0; i < 256; ++i) {
        count_type id23 = counts0[i];
        count_type id0 = counts1[i];
        count_type id33 = counts2[i];
        count_type id22 = counts3[i];
        counts0[i] = total0;
        counts1[i] = total1;
        counts2[i] = total2;
        counts3[i] = total3;
        total0 += id23;
        total1 += id0;
        total2 += id33;
        total3 += id22;
    }
    for (It it = begin; it != end; ++it) {
        std::uint8_t key = id21(extract_key(*it));
        out_begin[counts0[key]++] = std::move(*it);
    }
    for (OutIt it = out_begin; it != out_end; ++it) {
        std::uint8_t key =
            id21(extract_key(*it)) >> 8;
        begin[counts1[key]++] = std::move(*it);
    }
    for (It it = begin; it != end; ++it) {
        std::uint8_t key =
            id21(extract_key(*it)) >> 16;
        out_begin[counts2[key]++] = std::move(*it);
    }
    for (OutIt it = out_begin; it != out_end; ++it) {
        std::uint8_t key =
            id21(extract_key(*it)) >> 24;
        begin[counts3[key]++] = std::move(*it);
    }
    return false;
}

static constexpr size_t pass_count = 5;
};
template <>
struct SizedRadixSorter<8> {
template <typename It, typename OutIt, typename ExtractKey>
static bool sort(It begin, It end, OutIt buffer_begin,
                 ExtractKey&& extract_key) {
    std::ptrdiff_t num_elements = end - begin;
    if (num_elements <= (1ll << 32))
        return sort_inline<uint32_t>(begin, end, buffer_begin,
                                     buffer_begin + num_elements,
                                     extract_key);
    else
        return sort_inline<uint64_t>(begin, end, buffer_begin,
                                     buffer_begin + num_elements,
                                     extract_key);
}
template <typename count_type, typename It, typename OutIt,
          typename ExtractKey>
static bool sort_inline(It begin, It end, OutIt out_begin,
                        OutIt out_end, ExtractKey&& extract_key) {
    count_type counts0[256] = {};
    count_type counts1[256] = {};
    count_type counts2[256] = {};
    count_type counts3[256] = {};
    count_type counts4[256] = {};
    count_type counts5[256] = {};
    count_type counts6[256] = {};
    count_type counts7[256] = {};

    for (It it = begin; it != end; ++it) {
        uint64_t key = id21(extract_key(*it));
        ++counts0[key & 0xff];
        ++counts1[(key >> 8) & 0xff];
        ++counts2[(key >> 16) & 0xff];
        ++counts3[(key >> 24) & 0xff];
        ++counts4[(key >> 32) & 0xff];
        ++counts5[(key >> 40) & 0xff];
        ++counts6[(key >> 48) & 0xff];
        ++counts7[(key >> 56) & 0xff];
    }
    count_type total0 = 0;
    count_type total1 = 0;
    count_type total2 = 0;
    count_type total3 = 0;
    count_type total4 = 0;
    count_type total5 = 0;
    count_type total6 = 0;
    count_type total7 = 0;
    for (int i = 0; i < 256; ++i) {
        count_type id23 = counts0[i];
        count_type id0 = counts1[i];
        count_type id33 = counts2[i];
        count_type id22 = counts3[i];
        count_type id32 = counts4[i];
        count_type id36 = counts5[i];
        count_type id16 = counts6[i];
        count_type id24 = counts7[i];
        counts0[i] = total0;
        counts1[i] = total1;
        counts2[i] = total2;
        counts3[i] = total3;
        counts4[i] = total4;
        counts5[i] = total5;
        counts6[i] = total6;
        counts7[i] = total7;
        total0 += id23;
        total1 += id0;
        total2 += id33;
        total3 += id22;
        total4 += id32;
        total5 += id36;
        total6 += id16;
        total7 += id24;
    }
    for (It it = begin; it != end; ++it) {
        std::uint8_t key = id21(extract_key(*it));
        out_begin[counts0[key]++] = std::move(*it);
    }
    for (OutIt it = out_begin; it != out_end; ++it) {
        std::uint8_t key =
            id21(extract_key(*it)) >> 8;
        begin[counts1[key]++] = std::move(*it);
    }
    for (It it = begin; it != end; ++it) {
        std::uint8_t key =
            id21(extract_key(*it)) >> 16;
        out_begin[counts2[key]++] = std::move(*it);
    }
    for (OutIt it = out_begin; it != out_end; ++it) {
        std::uint8_t key =
            id21(extract_key(*it)) >> 24;
        begin[counts3[key]++] = std::move(*it);
    }
    for (It it = begin; it != end; ++it) {
        std::uint8_t key =
            id21(extract_key(*it)) >> 32;
        out_begin[counts4[key]++] = std::move(*it);
    }
    for (OutIt it = out_begin; it != out_end; ++it) {
        std::uint8_t key =
            id21(extract_key(*it)) >> 40;
        begin[counts5[key]++] = std::move(*it);
    }
    for (It it = begin; it != end; ++it) {
        std::uint8_t key =
            id21(extract_key(*it)) >> 48;
        out_begin[counts6[key]++] = std::move(*it);
    }
    for (OutIt it = out_begin; it != out_end; ++it) {
        std::uint8_t key =
            id21(extract_key(*it)) >> 56;
        begin[counts7[key]++] = std::move(*it);
    }
    return false;
}

static constexpr size_t pass_count = 9;
};

template <typename>
struct RadixSorter;
template <>
struct RadixSorter<bool> {
template <typename It, typename OutIt, typename ExtractKey>
static bool sort(It begin, It end, OutIt buffer_begin,
                 ExtractKey&& extract_key) {
    size_t false_count = 0;
    for (It it = begin; it != end; ++it) {
        if (!extract_key(*it)) ++false_count;
    }
    size_t true_position = false_count;
    false_count = 0;
    for (; begin != end; ++begin) {
        if (extract_key(*begin))
            buffer_begin[true_position++] = std::move(*begin);
        else
            buffer_begin[false_count++] = std::move(*begin);
    }
    return true;
}

static constexpr size_t pass_count = 2;
};
template <>
struct RadixSorter<signed char>
: SizedRadixSorter<sizeof(signed char)> {};
template <>
struct RadixSorter<unsigned char>
: SizedRadixSorter<sizeof(unsigned char)> {};
template <>
struct RadixSorter<signed short>
: SizedRadixSorter<sizeof(signed short)> {};
template <>
struct RadixSorter<unsigned short>
: SizedRadixSorter<sizeof(unsigned short)> {};
template <>
struct RadixSorter<signed int> : SizedRadixSorter<sizeof(signed int)> {
};
template <>
struct RadixSorter<unsigned int>
: SizedRadixSorter<sizeof(unsigned int)> {};
template <>
struct RadixSorter<signed long>
: SizedRadixSorter<sizeof(signed long)> {};
template <>
struct RadixSorter<unsigned long>
: SizedRadixSorter<sizeof(unsigned long)> {};
template <>
struct RadixSorter<signed long long>
: SizedRadixSorter<sizeof(signed long long)> {};
template <>
struct RadixSorter<unsigned long long>
: SizedRadixSorter<sizeof(unsigned long long)> {};
template <>
struct RadixSorter<float> : SizedRadixSorter<sizeof(float)> {};
template <>
struct RadixSorter<double> : SizedRadixSorter<sizeof(double)> {};
template <>
struct RadixSorter<char> : SizedRadixSorter<sizeof(char)> {};
template <>
struct RadixSorter<id26> : SizedRadixSorter<sizeof(id26)> {};
template <>
struct RadixSorter<char16_t> : SizedRadixSorter<sizeof(char16_t)> {};
template <>
struct RadixSorter<char32_t> : SizedRadixSorter<sizeof(char32_t)> {};
template <typename K, typename V>
struct RadixSorter<std::pair<K, V>> {
template <typename It, typename OutIt, typename ExtractKey>
static bool sort(It begin, It end, OutIt buffer_begin,
                 ExtractKey&& extract_key) {
    bool first_result = RadixSorter<V>::sort(
        begin, end, buffer_begin,
        [&](auto&& o) { return extract_key(o).second; });
    auto extract_first = [&](auto&& o) {
        return extract_key(o).first;
    };

    if (first_result) {
        return !RadixSorter<K>::sort(buffer_begin,
                                     buffer_begin + (end - begin),
                                     begin, extract_first);
    } else {
        return RadixSorter<K>::sort(begin, end, buffer_begin,
                                    extract_first);
    }
}

static constexpr size_t pass_count =
    RadixSorter<K>::pass_count + RadixSorter<V>::pass_count;
};
template <typename K, typename V>
struct RadixSorter<const std::pair<K, V>&> {
template <typename It, typename OutIt, typename ExtractKey>
static bool sort(It begin, It end, OutIt buffer_begin,
                 ExtractKey&& extract_key) {
    bool first_result = RadixSorter<V>::sort(
        begin, end, buffer_begin, [&](auto&& o) -> const V& {
            return extract_key(o).second;
        });
    auto extract_first = [&](auto&& o) -> const K& {
        return extract_key(o).first;
    };

    if (first_result) {
        return !RadixSorter<K>::sort(buffer_begin,
                                     buffer_begin + (end - begin),
                                     begin, extract_first);
    } else {
        return RadixSorter<K>::sort(begin, end, buffer_begin,
                                    extract_first);
    }
}

static constexpr size_t pass_count =
    RadixSorter<K>::pass_count + RadixSorter<V>::pass_count;
};
template <size_t I, size_t S, typename Tuple>
struct TupleRadixSorter {
using NextSorter = TupleRadixSorter<I + 1, S, Tuple>;
using ThisSorter =
    RadixSorter<typename std::tuple_element<I, Tuple>::type>;

template <typename It, typename OutIt, typename ExtractKey>
static bool sort(It begin, It end, OutIt out_begin, OutIt out_end,
                 ExtractKey&& extract_key) {
    bool which = NextSorter::sort(begin, end, out_begin, out_end,
                                  extract_key);
    auto extract_i = [&](auto&& o) {
        return std::get<I>(extract_key(o));
    };
    if (which)
        return !ThisSorter::sort(out_begin, out_end, begin,
                                 extract_i);
    else
        return ThisSorter::sort(begin, end, out_begin, extract_i);
}

static constexpr size_t pass_count =
    ThisSorter::pass_count + NextSorter::pass_count;
};
template <size_t I, size_t S, typename Tuple>
struct TupleRadixSorter<I, S, const Tuple&> {
using NextSorter = TupleRadixSorter<I + 1, S, const Tuple&>;
using ThisSorter =
    RadixSorter<typename std::tuple_element<I, Tuple>::type>;

template <typename It, typename OutIt, typename ExtractKey>
static bool sort(It begin, It end, OutIt out_begin, OutIt out_end,
                 ExtractKey&& extract_key) {
    bool which = NextSorter::sort(begin, end, out_begin, out_end,
                                  extract_key);
    auto extract_i = [&](auto&& o) -> decltype(auto) {
        return std::get<I>(extract_key(o));
    };
    if (which)
        return !ThisSorter::sort(out_begin, out_end, begin,
                                 extract_i);
    else
        return ThisSorter::sort(begin, end, out_begin, extract_i);
}

static constexpr size_t pass_count =
    ThisSorter::pass_count + NextSorter::pass_count;
};
template <size_t I, typename Tuple>
struct TupleRadixSorter<I, I, Tuple> {
template <typename It, typename OutIt, typename ExtractKey>
static bool sort(It, It, OutIt, OutIt, ExtractKey&&) {
    return false;
}

static constexpr size_t pass_count = 0;
};
template <size_t I, typename Tuple>
struct TupleRadixSorter<I, I, const Tuple&> {
template <typename It, typename OutIt, typename ExtractKey>
static bool sort(It, It, OutIt, OutIt, ExtractKey&&) {
    return false;
}

static constexpr size_t pass_count = 0;
};

template <typename... Args>
struct RadixSorter<std::tuple<Args...>> {
using SorterImpl =
    TupleRadixSorter<0, sizeof...(Args), std::tuple<Args...>>;

template <typename It, typename OutIt, typename ExtractKey>
static bool sort(It begin, It end, OutIt buffer_begin,
                 ExtractKey&& extract_key) {
    return SorterImpl::sort(begin, end, buffer_begin,
                            buffer_begin + (end - begin),
                            extract_key);
}

static constexpr size_t pass_count = SorterImpl::pass_count;
};

template <typename... Args>
struct RadixSorter<const std::tuple<Args...>&> {
using SorterImpl = TupleRadixSorter<0, sizeof...(Args),
                                    const std::tuple<Args...>&>;

template <typename It, typename OutIt, typename ExtractKey>
static bool sort(It begin, It end, OutIt buffer_begin,
                 ExtractKey&& extract_key) {
    return SorterImpl::sort(begin, end, buffer_begin,
                            buffer_begin + (end - begin),
                            extract_key);
}

static constexpr size_t pass_count = SorterImpl::pass_count;
};

template <typename T, size_t S>
struct RadixSorter<std::array<T, S>> {
template <typename It, typename OutIt, typename ExtractKey>
static bool sort(It begin, It end, OutIt buffer_begin,
                 ExtractKey&& extract_key) {
    auto buffer_end = buffer_begin + (end - begin);
    bool which = false;
    for (size_t i = S; i > 0; --i) {
        auto extract_i = [&, i = i - 1](auto&& o) {
            return extract_key(o)[i];
        };
        if (which)
            which = !RadixSorter<T>::sort(buffer_begin, buffer_end,
                                          begin, extract_i);
        else
            which = RadixSorter<T>::sort(begin, end, buffer_begin,
                                         extract_i);
    }
    return which;
}

static constexpr size_t pass_count = RadixSorter<T>::pass_count * S;
};

template <typename T>
struct RadixSorter<const T> : RadixSorter<T> {};
template <typename T>
struct RadixSorter<T&> : RadixSorter<const T&> {};
template <typename T>
struct RadixSorter<T&&> : RadixSorter<T> {};
template <typename T>
struct RadixSorter<const T&> : RadixSorter<T> {};
template <typename T>
struct RadixSorter<const T&&> : RadixSorter<T> {};


















struct ExampleStructA {
int i;
};
struct ExampleStructB {
float f;
};
inline int id9(ExampleStructA a) { return a.i; }
inline float id9(ExampleStructB b) { return b.f; }
template <typename T, typename Enable = void>
struct FallbackRadixSorter
: RadixSorter<decltype(id9(std::declval<T>()))> {
using base =
    RadixSorter<decltype(id9(std::declval<T>()))>;

template <typename It, typename OutIt, typename ExtractKey>
static bool sort(It begin, It end, OutIt buffer_begin,
                 ExtractKey&& extract_key) {
    return base::sort(begin, end, buffer_begin,
                      [&](auto&& a) -> decltype(auto) {
                          return id9(extract_key(a));
                      });
}
};

template <typename...>
struct nested_void {
using type = void;
};

template <typename... Args>
using void_t = typename nested_void<Args...>::type;

template <typename T>
struct has_subscript_operator_impl {
template <typename U, typename = decltype(std::declval<U>()[0])>
static std::true_type test(int);
template <typename>
static std::false_type test(...);

using type = decltype(test<T>(0));
};

template <typename T>
using has_subscript_operator =
typename has_subscript_operator_impl<T>::type;

template <typename T>
struct FallbackRadixSorter<
T, void_t<decltype(id21(std::declval<T>()))>>
: RadixSorter<decltype(id21(std::declval<T>()))> {};

template <typename T>
struct RadixSorter : FallbackRadixSorter<T> {};

template <typename T>
size_t id29 = RadixSorter<T>::pass_count;

template <typename It, typename Func>
inline void id37(It begin, size_t iteration_count,
                               Func&& to_call) {
size_t loop_count = iteration_count / 4;
size_t id19 = iteration_count - loop_count * 4;
for (; loop_count > 0; --loop_count) {
    to_call(begin);
    ++begin;
    to_call(begin);
    ++begin;
    to_call(begin);
    ++begin;
    to_call(begin);
    ++begin;
}
switch (id19) {
    case 3:
        to_call(begin);
        ++begin;
    case 2:
        to_call(begin);
        ++begin;
    case 1:
        to_call(begin);
}
}

template <typename It, typename F>
inline It id25(It begin, It end, F&& func) {
for (;; ++begin) {
    if (begin == end) return end;
    if (!func(*begin)) break;
}
It it = begin;
for (++it; it != end; ++it) {
    if (!func(*it)) continue;

    std::iter_swap(begin, it);
    ++begin;
}
return begin;
}

struct PartitionInfo {
PartitionInfo() : count(0) {}

union {
    size_t count;
    size_t offset;
};
size_t next_offset;
};

template <size_t>
struct UnsignedForSize;
template <>
struct UnsignedForSize<1> {
typedef uint8_t type;
};
template <>
struct UnsignedForSize<2> {
typedef uint16_t type;
};
template <>
struct UnsignedForSize<4> {
typedef uint32_t type;
};
template <>
struct UnsignedForSize<8> {
typedef uint64_t type;
};
template <typename T>
struct SubKey;
template <size_t Size>
struct SizedSubKey {
template <typename T>
static auto sub_key(T&& value, void*) {
    return id21(value);
}

typedef SubKey<void> next;

using sub_key_type = typename UnsignedForSize<Size>::type;
};
template <typename T>
struct SubKey<const T> : SubKey<T> {};
template <typename T>
struct SubKey<T&> : SubKey<T> {};
template <typename T>
struct SubKey<T&&> : SubKey<T> {};
template <typename T>
struct SubKey<const T&> : SubKey<T> {};
template <typename T>
struct SubKey<const T&&> : SubKey<T> {};
template <typename T, typename Enable = void>
struct FallbackSubKey
: SubKey<decltype(id9(std::declval<T>()))> {
using base = SubKey<decltype(id9(std::declval<T>()))>;

template <typename U>
static decltype(auto) sub_key(U&& value, void* data) {
    return base::sub_key(id9(value), data);
}
};
template <typename T>
struct FallbackSubKey<
T, void_t<decltype(id21(std::declval<T>()))>>
: SubKey<decltype(id21(std::declval<T>()))> {};
template <typename T>
struct SubKey : FallbackSubKey<T> {};
template <>
struct SubKey<bool> {
template <typename T>
static bool sub_key(T&& value, void*) {
    return value;
}

typedef SubKey<void> next;

using sub_key_type = bool;
};
template <>
struct SubKey<void>;
template <>
struct SubKey<unsigned char> : SizedSubKey<sizeof(unsigned char)> {};
template <>
struct SubKey<unsigned short> : SizedSubKey<sizeof(unsigned short)> {};
template <>
struct SubKey<unsigned int> : SizedSubKey<sizeof(unsigned int)> {};
template <>
struct SubKey<unsigned long> : SizedSubKey<sizeof(unsigned long)> {};
template <>
struct SubKey<unsigned long long>
: SizedSubKey<sizeof(unsigned long long)> {};
template <typename T>
struct SubKey<T*> : SizedSubKey<sizeof(T*)> {};
template <typename F, typename S, typename Current>
struct PairSecondSubKey : Current {
static decltype(auto) sub_key(const std::pair<F, S>& value,
                              void* sort_data) {
    return Current::sub_key(value.second, sort_data);
}

using next = typename std::conditional<
    std::is_same<SubKey<void>, typename Current::next>::value,
    SubKey<void>,
    PairSecondSubKey<F, S, typename Current::next>>::type;
};
template <typename F, typename S, typename Current>
struct PairFirstSubKey : Current {
static decltype(auto) sub_key(const std::pair<F, S>& value,
                              void* sort_data) {
    return Current::sub_key(value.first, sort_data);
}

using next = typename std::conditional<
    std::is_same<SubKey<void>, typename Current::next>::value,
    PairSecondSubKey<F, S, SubKey<S>>,
    PairFirstSubKey<F, S, typename Current::next>>::type;
};
template <typename F, typename S>
struct SubKey<std::pair<F, S>> : PairFirstSubKey<F, S, SubKey<F>> {};
template <size_t Index, typename First, typename... More>
struct TypeAt : TypeAt<Index - 1, More..., void> {};
template <typename First, typename... More>
struct TypeAt<0, First, More...> {
typedef First type;
};

template <size_t Index, typename Current, typename First,
      typename... More>
struct TupleSubKey;

template <size_t Index, typename Next, typename First, typename... More>
struct NextTupleSubKey {
using type = TupleSubKey<Index, Next, First, More...>;
};
template <size_t Index, typename First, typename Second,
      typename... More>
struct NextTupleSubKey<Index, SubKey<void>, First, Second, More...> {
using type =
    TupleSubKey<Index + 1, SubKey<Second>, Second, More...>;
};
template <size_t Index, typename First>
struct NextTupleSubKey<Index, SubKey<void>, First> {
using type = SubKey<void>;
};

template <size_t Index, typename Current, typename First,
      typename... More>
struct TupleSubKey : Current {
template <typename Tuple>
static decltype(auto) sub_key(const Tuple& value, void* sort_data) {
    return Current::sub_key(std::get<Index>(value), sort_data);
}

using next = typename NextTupleSubKey<Index, typename Current::next,
                                      First, More...>::type;
};
template <size_t Index, typename Current, typename First>
struct TupleSubKey<Index, Current, First> : Current {
template <typename Tuple>
static decltype(auto) sub_key(const Tuple& value, void* sort_data) {
    return Current::sub_key(std::get<Index>(value), sort_data);
}

using next = typename NextTupleSubKey<Index, typename Current::next,
                                      First>::type;
};
template <typename First, typename... More>
struct SubKey<std::tuple<First, More...>>
: TupleSubKey<0, SubKey<First>, First, More...> {};

struct BaseListSortData {
size_t current_index;
size_t recursion_limit;
void* id1;
};
template <typename It, typename ExtractKey>
struct ListSortData : BaseListSortData {
void (*next_sort)(It, It, std::ptrdiff_t, ExtractKey&, void*);
};

template <typename CurrentSubKey, typename T>
struct ListElementSubKey
: SubKey<
      typename std::decay<decltype(std::declval<T>()[0])>::type> {
using base = SubKey<
    typename std::decay<decltype(std::declval<T>()[0])>::type>;

using next = ListElementSubKey;

template <typename U>
static decltype(auto) sub_key(U&& value, void* sort_data) {
    BaseListSortData* list_sort_data =
        static_cast<BaseListSortData*>(sort_data);
    const T& list = CurrentSubKey::sub_key(
        value, list_sort_data->id1);
    return base::sub_key(list[list_sort_data->current_index],
                         list_sort_data->id1);
}
};

template <typename T>
struct ListSubKey {
using next = SubKey<void>;

using sub_key_type = T;

static const T& sub_key(const T& value, void*) { return value; }
};

template <typename T>
struct FallbackSubKey<
T, typename std::enable_if<has_subscript_operator<T>::value>::type>
: ListSubKey<T> {};

template <typename It, typename ExtractKey>
inline void id11(It begin, It end, ExtractKey& extract_key) {
std::sort(begin, end, [&](auto&& l, auto&& r) {
    return extract_key(l) < extract_key(r);
});
}

template <std::ptrdiff_t id14, typename It,
      typename ExtractKey>
inline bool id20(It begin, It end,
                                   std::ptrdiff_t num_elements,
                                   ExtractKey& extract_key) {
if (num_elements <= 1) return true;
if (num_elements >= id14) return false;
id11(begin, end, extract_key);
return true;
}

template <std::ptrdiff_t id14,
      std::ptrdiff_t id6,
      typename CurrentSubKey,
      typename SubKeyType = typename CurrentSubKey::sub_key_type>
struct InplaceSorter;

template <std::ptrdiff_t id14,
      std::ptrdiff_t id6,
      typename CurrentSubKey, size_t NumBytes, size_t Offset = 0>
struct UnsignedInplaceSorter {
static constexpr size_t ShiftAmount =
    (((NumBytes - 1) - Offset) * 8);
template <typename T>
inline static uint8_t current_byte(T&& elem, void* sort_data) {
    return CurrentSubKey::sub_key(elem, sort_data) >> ShiftAmount;
}
template <typename It, typename ExtractKey>
static void sort(It begin, It end, std::ptrdiff_t num_elements,
                 ExtractKey& extract_key,
                 void (*next_sort)(It, It, std::ptrdiff_t,
                                   ExtractKey&, void*),
                 void* sort_data) {
    if (num_elements < id6)
        id34(begin, end, extract_key, next_sort,
                           sort_data);
    else
        id8(begin, end, extract_key, next_sort,
                      sort_data);
}

template <typename It, typename ExtractKey>
static void id34(
    It begin, It end, ExtractKey& extract_key,
    void (*next_sort)(It, It, std::ptrdiff_t, ExtractKey&, void*),
    void* sort_data) {
    PartitionInfo partitions[256];
    for (It it = begin; it != end; ++it) {
        ++partitions[current_byte(extract_key(*it), sort_data)]
              .count;
    }
    size_t total = 0;
    uint8_t id7[256];
    int id35 = 0;
    for (int i = 0; i < 256; ++i) {
        size_t count = partitions[i].count;
        if (!count) continue;
        partitions[i].offset = total;
        total += count;
        partitions[i].next_offset = total;
        id7[id35] = i;
        ++id35;
    }
    if (id35 > 1) {
        uint8_t* current_block_ptr = id7;
        PartitionInfo* current_block =
            partitions + *current_block_ptr;
        uint8_t* last_block =
            id7 + id35 - 1;
        It it = begin;
        It block_end = begin + current_block->next_offset;
        It last_element = end - 1;
        for (;;) {
            PartitionInfo* block =
                partitions +
                current_byte(extract_key(*it), sort_data);
            if (block == current_block) {
                ++it;
                if (it == last_element)
                    break;
                else if (it == block_end) {
                    for (;;) {
                        ++current_block_ptr;
                        if (current_block_ptr == last_block)
                            goto recurse;
                        current_block =
                            partitions + *current_block_ptr;
                        if (current_block->offset !=
                            current_block->next_offset)
                            break;
                    }

                    it = begin + current_block->offset;
                    block_end = begin + current_block->next_offset;
                }
            } else {
                size_t offset = block->offset++;
                std::iter_swap(it, begin + offset);
            }
        }
    }
recurse:
    if (Offset + 1 != NumBytes || next_sort) {
        size_t start_offset = 0;
        It partition_begin = begin;
        for (uint8_t *it = id7,
                     *end = id7 + id35;
             it != end; ++it) {
            size_t end_offset = partitions[*it].next_offset;
            It partition_end = begin + end_offset;
            std::ptrdiff_t num_elements = end_offset - start_offset;
            if (!id20<id14>(
                    partition_begin, partition_end, num_elements,
                    extract_key)) {
                UnsignedInplaceSorter<
                    id14, id6,
                    CurrentSubKey, NumBytes,
                    Offset + 1>::sort(partition_begin,
                                      partition_end, num_elements,
                                      extract_key, next_sort,
                                      sort_data);
            }
            start_offset = end_offset;
            partition_begin = partition_end;
        }
    }
}

template <typename It, typename ExtractKey>
static void id8(It begin, It end, ExtractKey& extract_key,
                          void (*next_sort)(It, It, std::ptrdiff_t,
                                            ExtractKey&, void*),
                          void* sort_data) {
    PartitionInfo partitions[256];
    for (It it = begin; it != end; ++it) {
        ++partitions[current_byte(extract_key(*it), sort_data)]
              .count;
    }
    uint8_t id7[256];
    size_t total = 0;
    int id35 = 0;
    for (int i = 0; i < 256; ++i) {
        size_t count = partitions[i].count;
        if (count) {
            partitions[i].offset = total;
            total += count;
            id7[id35] = i;
            ++id35;
        }
        partitions[i].next_offset = total;
    }
    for (uint8_t *
             last_remaining = id7 + id35,
            *end_partition = id7 + 1;
         last_remaining > end_partition;) {
        last_remaining = id25(
            id7, last_remaining,
            [&](uint8_t partition) {
                size_t& begin_offset = partitions[partition].offset;
                size_t& end_offset =
                    partitions[partition].next_offset;
                if (begin_offset == end_offset) return false;

                id37(
                    begin + begin_offset, end_offset - begin_offset,
                    [partitions = partitions, begin, &extract_key,
                     sort_data](It it) {
                        uint8_t this_partition = current_byte(
                            extract_key(*it), sort_data);
                        size_t offset =
                            partitions[this_partition].offset++;
                        std::iter_swap(it, begin + offset);
                    });
                return begin_offset != end_offset;
            });
    }
    if (Offset + 1 != NumBytes || next_sort) {
        for (uint8_t* it = id7 + id35;
             it != id7; --it) {
            uint8_t partition = it[-1];
            size_t start_offset =
                (partition == 0
                     ? 0
                     : partitions[partition - 1].next_offset);
            size_t end_offset = partitions[partition].next_offset;
            It partition_begin = begin + start_offset;
            It partition_end = begin + end_offset;
            std::ptrdiff_t num_elements = end_offset - start_offset;
            if (!id20<id14>(
                    partition_begin, partition_end, num_elements,
                    extract_key)) {
                UnsignedInplaceSorter<
                    id14, id6,
                    CurrentSubKey, NumBytes,
                    Offset + 1>::sort(partition_begin,
                                      partition_end, num_elements,
                                      extract_key, next_sort,
                                      sort_data);
            }
        }
    }
}
};

template <std::ptrdiff_t id14,
      std::ptrdiff_t id6,
      typename CurrentSubKey, size_t NumBytes>
struct UnsignedInplaceSorter<id14,
                         id6, CurrentSubKey,
                         NumBytes, NumBytes> {
template <typename It, typename ExtractKey>
inline static void sort(It begin, It end,
                        std::ptrdiff_t num_elements,
                        ExtractKey& extract_key,
                        void (*next_sort)(It, It, std::ptrdiff_t,
                                          ExtractKey&, void*),
                        void* id1) {
    next_sort(begin, end, num_elements, extract_key,
              id1);
}
};

template <typename It, typename ExtractKey, typename ElementKey>
size_t CommonPrefix(It begin, It end, size_t start_index,
                ExtractKey&& extract_key,
                ElementKey&& element_key) {
const auto& id30 = extract_key(*begin);
size_t largest_match = id30.size();
if (largest_match == start_index) return start_index;
for (++begin; begin != end; ++begin) {
    const auto& current_list = extract_key(*begin);
    size_t current_size = current_list.size();
    if (current_size < largest_match) {
        largest_match = current_size;
        if (largest_match == start_index) return start_index;
    }
    if (element_key(id30[start_index]) !=
        element_key(current_list[start_index]))
        return start_index;
    for (size_t i = start_index + 1; i < largest_match; ++i) {
        if (element_key(id30[i]) !=
            element_key(current_list[i])) {
            largest_match = i;
            break;
        }
    }
}
return largest_match;
}

template <std::ptrdiff_t id14,
      std::ptrdiff_t id6,
      typename CurrentSubKey, typename ListType>
struct ListInplaceSorter {
using ElementSubKey = ListElementSubKey<CurrentSubKey, ListType>;
template <typename It, typename ExtractKey>
static void sort(It begin, It end, ExtractKey& extract_key,
                 ListSortData<It, ExtractKey>* sort_data) {
    size_t current_index = sort_data->current_index;
    void* id1 = sort_data->id1;
    auto current_key = [&](auto&& elem) -> decltype(auto) {
        return CurrentSubKey::sub_key(extract_key(elem),
                                      id1);
    };
    auto element_key = [&](auto&& elem) -> decltype(auto) {
        return ElementSubKey::base::sub_key(elem, sort_data);
    };
    sort_data->current_index = current_index = CommonPrefix(
        begin, end, current_index, current_key, element_key);
    It id10 =
        std::partition(begin, end, [&](auto&& elem) {
            return current_key(elem).size() <= current_index;
        });
    std::ptrdiff_t id28 = id10 - begin;
    if (sort_data->next_sort &&
        !id20<id14>(
            begin, id10, id28,
            extract_key)) {
        sort_data->next_sort(begin, id10,
                             id28, extract_key,
                             id1);
    }
    std::ptrdiff_t num_elements = end - id10;
    if (!id20<id14>(
            id10, end, num_elements, extract_key)) {
        void (*sort_next_element)(It, It, std::ptrdiff_t,
                                  ExtractKey&, void*) =
            static_cast<void (*)(It, It, std::ptrdiff_t,
                                 ExtractKey&, void*)>(
                &id2);
        InplaceSorter<id14, id6,
                      ElementSubKey>::sort(id10, end,
                                           num_elements,
                                           extract_key,
                                           sort_next_element,
                                           sort_data);
    }
}

template <typename It, typename ExtractKey>
static void id2(It begin, It end, std::ptrdiff_t,
                                ExtractKey& extract_key,
                                void* id1) {
    ListSortData<It, ExtractKey> offset =
        *static_cast<ListSortData<It, ExtractKey>*>(id1);
    ++offset.current_index;
    --offset.recursion_limit;
    if (offset.recursion_limit == 0) {
        id11(begin, end, extract_key);
    } else {
        sort(begin, end, extract_key, &offset);
    }
}

template <typename It, typename ExtractKey>
static void sort(It begin, It end, std::ptrdiff_t,
                 ExtractKey& extract_key,
                 void (*next_sort)(It, It, std::ptrdiff_t,
                                   ExtractKey&, void*),
                 void* id1) {
    ListSortData<It, ExtractKey> offset;
    offset.current_index = 0;
    offset.recursion_limit = 16;
    offset.next_sort = next_sort;
    offset.id1 = id1;
    sort(begin, end, extract_key, &offset);
}
};

template <std::ptrdiff_t id14,
      std::ptrdiff_t id6,
      typename CurrentSubKey>
struct InplaceSorter<id14, id6,
                 CurrentSubKey, bool> {
template <typename It, typename ExtractKey>
static void sort(It begin, It end, std::ptrdiff_t,
                 ExtractKey& extract_key,
                 void (*next_sort)(It, It, std::ptrdiff_t,
                                   ExtractKey&, void*),
                 void* sort_data) {
    It middle = std::partition(begin, end, [&](auto&& a) {
        return !CurrentSubKey::sub_key(extract_key(a), sort_data);
    });
    if (next_sort) {
        next_sort(begin, middle, middle - begin, extract_key,
                  sort_data);
        next_sort(middle, end, end - middle, extract_key,
                  sort_data);
    }
}
};

template <std::ptrdiff_t id14,
      std::ptrdiff_t id6,
      typename CurrentSubKey>
struct InplaceSorter<id14, id6,
                 CurrentSubKey, uint8_t>
: UnsignedInplaceSorter<id14, id6,
                        CurrentSubKey, 1> {};
template <std::ptrdiff_t id14,
      std::ptrdiff_t id6,
      typename CurrentSubKey>
struct InplaceSorter<id14, id6,
                 CurrentSubKey, uint16_t>
: UnsignedInplaceSorter<id14, id6,
                        CurrentSubKey, 2> {};
template <std::ptrdiff_t id14,
      std::ptrdiff_t id6,
      typename CurrentSubKey>
struct InplaceSorter<id14, id6,
                 CurrentSubKey, uint32_t>
: UnsignedInplaceSorter<id14, id6,
                        CurrentSubKey, 4> {};
template <std::ptrdiff_t id14,
      std::ptrdiff_t id6,
      typename CurrentSubKey>
struct InplaceSorter<id14, id6,
                 CurrentSubKey, uint64_t>
: UnsignedInplaceSorter<id14, id6,
                        CurrentSubKey, 8> {};
template <std::ptrdiff_t id14,
      std::ptrdiff_t id6,
      typename CurrentSubKey, typename SubKeyType,
      typename Enable = void>
struct FallbackInplaceSorter;

template <std::ptrdiff_t id14,
      std::ptrdiff_t id6,
      typename CurrentSubKey, typename SubKeyType>
struct InplaceSorter
: FallbackInplaceSorter<id14, id6,
                        CurrentSubKey, SubKeyType> {};

template <std::ptrdiff_t id14,
      std::ptrdiff_t id6,
      typename CurrentSubKey, typename SubKeyType>
struct FallbackInplaceSorter<
id14, id6, CurrentSubKey,
SubKeyType,
typename std::enable_if<
    has_subscript_operator<SubKeyType>::value>::type>
: ListInplaceSorter<id14, id6,
                    CurrentSubKey, SubKeyType> {};

template <std::ptrdiff_t id14,
      std::ptrdiff_t id6,
      typename CurrentSubKey>
struct SortStarter;
template <std::ptrdiff_t id14,
      std::ptrdiff_t id6>
struct SortStarter<id14, id6,
               SubKey<void>> {
template <typename It, typename ExtractKey>
static void sort(It, It, std::ptrdiff_t, ExtractKey&, void*) {}
};

template <std::ptrdiff_t id14,
      std::ptrdiff_t id6,
      typename CurrentSubKey>
struct SortStarter {
template <typename It, typename ExtractKey>
static void sort(It begin, It end, std::ptrdiff_t num_elements,
                 ExtractKey& extract_key,
                 void* id1 = nullptr) {
    if (id20<id14>(
            begin, end, num_elements, extract_key))
        return;

    void (*next_sort)(
        It, It, std::ptrdiff_t, ExtractKey&,
        void*) = static_cast<void (*)(It, It, std::ptrdiff_t,
                                      ExtractKey&, void*)>(
        &SortStarter<id14, id6,
                     typename CurrentSubKey::next>::sort);
    if (next_sort == static_cast<void (*)(It, It, std::ptrdiff_t,
                                          ExtractKey&, void*)>(
                         &SortStarter<id14,
                                      id6,
                                      SubKey<void>>::sort))
        next_sort = nullptr;
    InplaceSorter<id14, id6,
                  CurrentSubKey>::sort(begin, end, num_elements,
                                       extract_key, next_sort,
                                       id1);
}
};

template <std::ptrdiff_t id14,
      std::ptrdiff_t id6, typename It,
      typename ExtractKey>
void id4(It begin, It end, ExtractKey& extract_key) {
using SubKey = SubKey<decltype(extract_key(*begin))>;
SortStarter<id14, id6,
            SubKey>::sort(begin, end, end - begin, extract_key);
}

struct IdentityFunctor {
template <typename T>
decltype(auto) operator()(T&& i) const {
    return std::forward<T>(i);
}
};
}  


template <typename It, typename ExtractKey>
static void ska_sort(It begin, It end, ExtractKey&& extract_key) {
detail::id4<128, 1024>(begin, end, extract_key);
}

template <typename It>
static void ska_sort(It begin, It end) {
ska_sort(begin, end, detail::IdentityFunctor());
}

template <typename It, typename OutIt, typename ExtractKey>
bool id12(It begin, It end, OutIt buffer_begin, ExtractKey&& key) {
std::ptrdiff_t num_elements = end - begin;
if (num_elements < 128 ||
    detail::id29<
        typename std::result_of<ExtractKey(decltype(*begin))>::type> >=
        8) {
    ska_sort(begin, end, key);
    return false;
} else
    return detail::RadixSorter<typename std::result_of<ExtractKey(
        decltype(*begin))>::type>::sort(begin, end, buffer_begin, key);
}
template <typename It, typename OutIt>
bool id12(It begin, It end, OutIt buffer_begin) {
return id12(begin, end, buffer_begin,
                     detail::IdentityFunctor());
}
}  




struct edge {
    int to, nxt;
    constexpr edge() : to{}, nxt{} {}
    constexpr edge(int to_, int id31) : to{to_}, nxt{id31} {}
};
struct graph {
    using edge_t = edge;
    graph(int n, int m) : head(n, -1), cur_edges{} { edges.reserve(m); }
    void add_edge(int u, int v) {
        edges.push_back({v, head[u]});
        head[u] = cur_edges++;
    }
    void clear() {
        std::fill(std::begin(head), std::end(head), -1);
        edges.clear();
        cur_edges = 0;
    }
    struct edge_range {
        const edge_t* edges_array;
        const int start;
        struct edge_iterator {
            const edge_t* edges_array;
            int edge_index;
            explicit constexpr edge_iterator(const edge_t* id5,
                                             const int id18)
                : edges_array{id5}, edge_index{id18} {}
            constexpr const edge_iterator& operator++() {
                edge_index = edges_array[edge_index].nxt;
                return *this;
            }
            constexpr const edge_iterator operator++(int) {
                auto temp = *this;
                return operator++(), temp;
            }
            constexpr auto operator*() const {
                return edges_array[edge_index].to;
            }
            constexpr bool operator!=(const edge_iterator& it) const {
                return edge_index != it.edge_index;
            }
            constexpr bool operator==(const edge_iterator& it) const {
                return edge_index == it.edge_index;
            }
        };
        constexpr edge_iterator begin() {
            return edge_iterator(edges_array, start);
        }
        constexpr edge_iterator end() { return edge_iterator(edges_array, -1); }
        constexpr edge_iterator begin() const {
            return edge_iterator(edges_array, start);
        }
        constexpr edge_iterator end() const {
            return edge_iterator(edges_array, -1);
        }
    };
    edge_range operator[](int u) { return edge_range{edges.data(), head[u]}; }
    edge_range operator[](int u) const {
        return edge_range{edges.data(), head[u]};
    }

   private:
    std::vector<int> head;
    std::vector<edge_t> edges;
    int cur_edges;
};
using graph_t = graph;

static constexpr int N = 200'000;
int a[N], b[N], max_length[N], indegree[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    std::int64_t k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) cin >> a[i];

    if (k == 1) {
        cout << *std::min_element(a, a + n) << '\n';
        return 0;
    }

    std::copy(a, a + n, b);

    ska::ska_sort(b, b + n);

    std::vector<std::array<int, 2>> edges(m);
    for (auto& [u, v] : edges) {
        cin >> u >> v;
        --u, --v;
    }

    graph_t g(n, m);
    std::vector<int> order;
    int ans =
        *std::ranges::partition_point(std::views::iota(0, n), [&](int id) {
            auto max = b[id];
            g.clear();
            std::fill_n(max_length, n, -1);
            std::fill_n(indegree, n, 0);
            order.clear();
            for (auto [u, v] : edges)
                if (a[u] <= max && a[v] <= max) g.add_edge(u, v), ++indegree[v];
            for (int u = 0; u < n; ++u)
                if (!indegree[u]) order.push_back(u), max_length[u] = 1;
            int ptr = 0;
            while (ptr < (int)order.size()) {
                auto u = order[ptr++];
                for (auto v : g[u]) {
                    max_length[v] = std::max(max_length[u] + 1, max_length[v]);
                    if (!--indegree[v]) order.push_back(v);
                }
            }
            if ((int)order.size() < n) return false;
            for (int i = 0; i < n; ++i)
                if (max_length[i] >= k) return false;
            return true;
        });

    cout << (ans == n ? -1 : b[ans]) << "\n";
}

