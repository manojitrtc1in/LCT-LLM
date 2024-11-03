





using namespace std;


namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

    void id33() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;
    }

    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            id33();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    inline bool isspace(char c) {
        return (unsigned char) (c - '\t') < 5 || c == ' ';
    }

    template<typename T>
    inline void read_int(T &number) {
        while (isspace(next_char(false)))
            next_char();

        bool negative = next_char(false) == '-';

        if (negative)
            next_char();

        number = 0;

        while (isdigit(next_char(false)))
            number = 10 * number + (next_char() - '0');

        if (negative)
            number = -number;
    }
}


















namespace detail
{
template<typename count_type, typename It, typename OutIt, typename ExtractKey>
void id22(It begin, It end, OutIt out_begin, ExtractKey && extract_key)
{
    count_type counts[256] = {};
    for (It it = begin; it != end; ++it)
    {
        ++counts[extract_key(*it)];
    }
    count_type total = 0;
    for (count_type & count : counts)
    {
        count_type old_count = count;
        count = total;
        total += old_count;
    }
    for (; begin != end; ++begin)
    {
        std::uint8_t key = extract_key(*begin);
        out_begin[counts[key]++] = std::move(*begin);
    }
}
template<typename It, typename OutIt, typename ExtractKey>
void id22(It begin, It end, OutIt out_begin, ExtractKey && extract_key)
{
    id22<std::uint64_t>(begin, end, out_begin, extract_key);
}
inline bool id16(bool b)
{
    return b;
}
inline unsigned char id16(unsigned char c)
{
    return c;
}
inline unsigned char id16(signed char c)
{
    return static_cast<unsigned char>(c) + 128;
}
inline unsigned char id16(char c)
{
    return static_cast<unsigned char>(c);
}
inline std::uint16_t id16(char16_t c)
{
    return static_cast<std::uint16_t>(c);
}
inline std::uint32_t id16(char32_t c)
{
    return static_cast<std::uint32_t>(c);
}
inline std::uint32_t id16(id21 c)
{
    return static_cast<std::uint32_t>(c);
}
inline unsigned short id16(short i)
{
    return static_cast<unsigned short>(i) + static_cast<unsigned short>(1 << (sizeof(short) * 8 - 1));
}
inline unsigned short id16(unsigned short i)
{
    return i;
}
inline unsigned int id16(int i)
{
    return static_cast<unsigned int>(i) + static_cast<unsigned int>(1 << (sizeof(int) * 8 - 1));
}
inline unsigned int id16(unsigned int i)
{
    return i;
}
inline unsigned long id16(long l)
{
    return static_cast<unsigned long>(l) + static_cast<unsigned long>(1l << (sizeof(long) * 8 - 1));
}
inline unsigned long id16(unsigned long l)
{
    return l;
}
inline unsigned long long id16(long long l)
{
    return static_cast<unsigned long long>(l) + static_cast<unsigned long long>(1ll << (sizeof(long long) * 8 - 1));
}
inline unsigned long long id16(unsigned long long l)
{
    return l;
}
inline std::uint32_t id16(float f)
{
    union
    {
        float f;
        std::uint32_t u;
    } as_union = { f };
    std::uint32_t sign_bit = -std::int32_t(as_union.u >> 31);
    return as_union.u ^ (sign_bit | 0x80000000);
}
inline std::uint64_t id16(double f)
{
    union
    {
        double d;
        std::uint64_t u;
    } as_union = { f };
    std::uint64_t sign_bit = -std::int64_t(as_union.u >> 63);
    return as_union.u ^ (sign_bit | 0x8000000000000000);
}
template<typename T>
inline size_t id16(T * ptr)
{
    return reinterpret_cast<size_t>(ptr);
}

template<size_t>
struct SizedRadixSorter;

template<>
struct SizedRadixSorter<1>
{
    template<typename It, typename OutIt, typename ExtractKey>
    static bool sort(It begin, It end, OutIt buffer_begin, ExtractKey && extract_key)
    {
        id22(begin, end, buffer_begin, [&](auto && o)
        {
            return id16(extract_key(o));
        });
        return true;
    }

    static constexpr size_t pass_count = 2;
};
template<>
struct SizedRadixSorter<2>
{
    template<typename It, typename OutIt, typename ExtractKey>
    static bool sort(It begin, It end, OutIt buffer_begin, ExtractKey && extract_key)
    {
        std::ptrdiff_t num_elements = end - begin;
        if (num_elements <= (1ll << 32))
            return sort_inline<uint32_t>(begin, end, buffer_begin, buffer_begin + num_elements, extract_key);
        else
            return sort_inline<uint64_t>(begin, end, buffer_begin, buffer_begin + num_elements, extract_key);
    }

    template<typename count_type, typename It, typename OutIt, typename ExtractKey>
    static bool sort_inline(It begin, It end, OutIt out_begin, OutIt out_end, ExtractKey && extract_key)
    {
        count_type counts0[256] = {};
        count_type counts1[256] = {};

        for (It it = begin; it != end; ++it)
        {
            uint16_t key = id16(extract_key(*it));
            ++counts0[key & 0xff];
            ++counts1[(key >> 8) & 0xff];
        }
        count_type total0 = 0;
        count_type total1 = 0;
        for (int i = 0; i < 256; ++i)
        {
            count_type id18 = counts0[i];
            count_type id0 = counts1[i];
            counts0[i] = total0;
            counts1[i] = total1;
            total0 += id18;
            total1 += id0;
        }
        for (It it = begin; it != end; ++it)
        {
            std::uint8_t key = id16(extract_key(*it));
            out_begin[counts0[key]++] = std::move(*it);
        }
        for (OutIt it = out_begin; it != out_end; ++it)
        {
            std::uint8_t key = id16(extract_key(*it)) >> 8;
            begin[counts1[key]++] = std::move(*it);
        }
        return false;
    }

    static constexpr size_t pass_count = 3;
};
template<>
struct SizedRadixSorter<4>
{

    template<typename It, typename OutIt, typename ExtractKey>
    static bool sort(It begin, It end, OutIt buffer_begin, ExtractKey && extract_key)
    {
        std::ptrdiff_t num_elements = end - begin;
        if (num_elements <= (1ll << 32))
            return sort_inline<uint32_t>(begin, end, buffer_begin, buffer_begin + num_elements, extract_key);
        else
            return sort_inline<uint64_t>(begin, end, buffer_begin, buffer_begin + num_elements, extract_key);
    }
    template<typename count_type, typename It, typename OutIt, typename ExtractKey>
    static bool sort_inline(It begin, It end, OutIt out_begin, OutIt out_end, ExtractKey && extract_key)
    {
        count_type counts0[256] = {};
        count_type counts1[256] = {};
        count_type counts2[256] = {};
        count_type counts3[256] = {};

        for (It it = begin; it != end; ++it)
        {
            uint32_t key = id16(extract_key(*it));
            ++counts0[key & 0xff];
            ++counts1[(key >> 8) & 0xff];
            ++counts2[(key >> 16) & 0xff];
            ++counts3[(key >> 24) & 0xff];
        }
        count_type total0 = 0;
        count_type total1 = 0;
        count_type total2 = 0;
        count_type total3 = 0;
        for (int i = 0; i < 256; ++i)
        {
            count_type id18 = counts0[i];
            count_type id0 = counts1[i];
            count_type id27 = counts2[i];
            count_type id17 = counts3[i];
            counts0[i] = total0;
            counts1[i] = total1;
            counts2[i] = total2;
            counts3[i] = total3;
            total0 += id18;
            total1 += id0;
            total2 += id27;
            total3 += id17;
        }
        for (It it = begin; it != end; ++it)
        {
            std::uint8_t key = id16(extract_key(*it));
            out_begin[counts0[key]++] = std::move(*it);
        }
        for (OutIt it = out_begin; it != out_end; ++it)
        {
            std::uint8_t key = id16(extract_key(*it)) >> 8;
            begin[counts1[key]++] = std::move(*it);
        }
        for (It it = begin; it != end; ++it)
        {
            std::uint8_t key = id16(extract_key(*it)) >> 16;
            out_begin[counts2[key]++] = std::move(*it);
        }
        for (OutIt it = out_begin; it != out_end; ++it)
        {
            std::uint8_t key = id16(extract_key(*it)) >> 24;
            begin[counts3[key]++] = std::move(*it);
        }
        return false;
    }

    static constexpr size_t pass_count = 5;
};
template<>
struct SizedRadixSorter<8>
{
    template<typename It, typename OutIt, typename ExtractKey>
    static bool sort(It begin, It end, OutIt buffer_begin, ExtractKey && extract_key)
    {
        std::ptrdiff_t num_elements = end - begin;
        if (num_elements <= (1ll << 32))
            return sort_inline<uint32_t>(begin, end, buffer_begin, buffer_begin + num_elements, extract_key);
        else
            return sort_inline<uint64_t>(begin, end, buffer_begin, buffer_begin + num_elements, extract_key);
    }
    template<typename count_type, typename It, typename OutIt, typename ExtractKey>
    static bool sort_inline(It begin, It end, OutIt out_begin, OutIt out_end, ExtractKey && extract_key)
    {
        count_type counts0[256] = {};
        count_type counts1[256] = {};
        count_type counts2[256] = {};
        count_type counts3[256] = {};
        count_type counts4[256] = {};
        count_type counts5[256] = {};
        count_type counts6[256] = {};
        count_type counts7[256] = {};

        for (It it = begin; it != end; ++it)
        {
            uint64_t key = id16(extract_key(*it));
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
        for (int i = 0; i < 256; ++i)
        {
            count_type id18 = counts0[i];
            count_type id0 = counts1[i];
            count_type id27 = counts2[i];
            count_type id17 = counts3[i];
            count_type id26 = counts4[i];
            count_type id31 = counts5[i];
            count_type id13 = counts6[i];
            count_type id19 = counts7[i];
            counts0[i] = total0;
            counts1[i] = total1;
            counts2[i] = total2;
            counts3[i] = total3;
            counts4[i] = total4;
            counts5[i] = total5;
            counts6[i] = total6;
            counts7[i] = total7;
            total0 += id18;
            total1 += id0;
            total2 += id27;
            total3 += id17;
            total4 += id26;
            total5 += id31;
            total6 += id13;
            total7 += id19;
        }
        for (It it = begin; it != end; ++it)
        {
            std::uint8_t key = id16(extract_key(*it));
            out_begin[counts0[key]++] = std::move(*it);
        }
        for (OutIt it = out_begin; it != out_end; ++it)
        {
            std::uint8_t key = id16(extract_key(*it)) >> 8;
            begin[counts1[key]++] = std::move(*it);
        }
        for (It it = begin; it != end; ++it)
        {
            std::uint8_t key = id16(extract_key(*it)) >> 16;
            out_begin[counts2[key]++] = std::move(*it);
        }
        for (OutIt it = out_begin; it != out_end; ++it)
        {
            std::uint8_t key = id16(extract_key(*it)) >> 24;
            begin[counts3[key]++] = std::move(*it);
        }
        for (It it = begin; it != end; ++it)
        {
            std::uint8_t key = id16(extract_key(*it)) >> 32;
            out_begin[counts4[key]++] = std::move(*it);
        }
        for (OutIt it = out_begin; it != out_end; ++it)
        {
            std::uint8_t key = id16(extract_key(*it)) >> 40;
            begin[counts5[key]++] = std::move(*it);
        }
        for (It it = begin; it != end; ++it)
        {
            std::uint8_t key = id16(extract_key(*it)) >> 48;
            out_begin[counts6[key]++] = std::move(*it);
        }
        for (OutIt it = out_begin; it != out_end; ++it)
        {
            std::uint8_t key = id16(extract_key(*it)) >> 56;
            begin[counts7[key]++] = std::move(*it);
        }
        return false;
    }

    static constexpr size_t pass_count = 9;
};

template<typename>
struct RadixSorter;
template<>
struct RadixSorter<bool>
{
    template<typename It, typename OutIt, typename ExtractKey>
    static bool sort(It begin, It end, OutIt buffer_begin, ExtractKey && extract_key)
    {
        size_t false_count = 0;
        for (It it = begin; it != end; ++it)
        {
            if (!extract_key(*it))
                ++false_count;
        }
        size_t true_position = false_count;
        false_count = 0;
        for (; begin != end; ++begin)
        {
            if (extract_key(*begin))
                buffer_begin[true_position++] = std::move(*begin);
            else
                buffer_begin[false_count++] = std::move(*begin);
        }
        return true;
    }

    static constexpr size_t pass_count = 2;
};
template<>
struct RadixSorter<signed char> : SizedRadixSorter<sizeof(signed char)>
{
};
template<>
struct RadixSorter<unsigned char> : SizedRadixSorter<sizeof(unsigned char)>
{
};
template<>
struct RadixSorter<signed short> : SizedRadixSorter<sizeof(signed short)>
{
};
template<>
struct RadixSorter<unsigned short> : SizedRadixSorter<sizeof(unsigned short)>
{
};
template<>
struct RadixSorter<signed int> : SizedRadixSorter<sizeof(signed int)>
{
};
template<>
struct RadixSorter<unsigned int> : SizedRadixSorter<sizeof(unsigned int)>
{
};
template<>
struct RadixSorter<signed long> : SizedRadixSorter<sizeof(signed long)>
{
};
template<>
struct RadixSorter<unsigned long> : SizedRadixSorter<sizeof(unsigned long)>
{
};
template<>
struct RadixSorter<signed long long> : SizedRadixSorter<sizeof(signed long long)>
{
};
template<>
struct RadixSorter<unsigned long long> : SizedRadixSorter<sizeof(unsigned long long)>
{
};
template<>
struct RadixSorter<float> : SizedRadixSorter<sizeof(float)>
{
};
template<>
struct RadixSorter<double> : SizedRadixSorter<sizeof(double)>
{
};
template<>
struct RadixSorter<char> : SizedRadixSorter<sizeof(char)>
{
};
template<>
struct RadixSorter<id21> : SizedRadixSorter<sizeof(id21)>
{
};
template<>
struct RadixSorter<char16_t> : SizedRadixSorter<sizeof(char16_t)>
{
};
template<>
struct RadixSorter<char32_t> : SizedRadixSorter<sizeof(char32_t)>
{
};
template<typename K, typename V>
struct RadixSorter<std::pair<K, V>>
{
    template<typename It, typename OutIt, typename ExtractKey>
    static bool sort(It begin, It end, OutIt buffer_begin, ExtractKey && extract_key)
    {
        bool first_result = RadixSorter<V>::sort(begin, end, buffer_begin, [&](auto && o)
        {
            return extract_key(o).second;
        });
        auto extract_first = [&](auto && o)
        {
            return extract_key(o).first;
        };

        if (first_result)
        {
            return !RadixSorter<K>::sort(buffer_begin, buffer_begin + (end - begin), begin, extract_first);
        }
        else
        {
            return RadixSorter<K>::sort(begin, end, buffer_begin, extract_first);
        }
    }

    static constexpr size_t pass_count = RadixSorter<K>::pass_count + RadixSorter<V>::pass_count;
};
template<typename K, typename V>
struct RadixSorter<const std::pair<K, V> &>
{
    template<typename It, typename OutIt, typename ExtractKey>
    static bool sort(It begin, It end, OutIt buffer_begin, ExtractKey && extract_key)
    {
        bool first_result = RadixSorter<V>::sort(begin, end, buffer_begin, [&](auto && o) -> const V &
        {
            return extract_key(o).second;
        });
        auto extract_first = [&](auto && o) -> const K &
        {
            return extract_key(o).first;
        };

        if (first_result)
        {
            return !RadixSorter<K>::sort(buffer_begin, buffer_begin + (end - begin), begin, extract_first);
        }
        else
        {
            return RadixSorter<K>::sort(begin, end, buffer_begin, extract_first);
        }
    }

    static constexpr size_t pass_count = RadixSorter<K>::pass_count + RadixSorter<V>::pass_count;
};
template<size_t I, size_t S, typename Tuple>
struct TupleRadixSorter
{
    using NextSorter = TupleRadixSorter<I + 1, S, Tuple>;
    using ThisSorter = RadixSorter<typename std::tuple_element<I, Tuple>::type>;

    template<typename It, typename OutIt, typename ExtractKey>
    static bool sort(It begin, It end, OutIt out_begin, OutIt out_end, ExtractKey && extract_key)
    {
        bool which = NextSorter::sort(begin, end, out_begin, out_end, extract_key);
        auto extract_i = [&](auto && o)
        {
            return std::get<I>(extract_key(o));
        };
        if (which)
            return !ThisSorter::sort(out_begin, out_end, begin, extract_i);
        else
            return ThisSorter::sort(begin, end, out_begin, extract_i);
    }

    static constexpr size_t pass_count = ThisSorter::pass_count + NextSorter::pass_count;
};
template<size_t I, size_t S, typename Tuple>
struct TupleRadixSorter<I, S, const Tuple &>
{
    using NextSorter = TupleRadixSorter<I + 1, S, const Tuple &>;
    using ThisSorter = RadixSorter<typename std::tuple_element<I, Tuple>::type>;

    template<typename It, typename OutIt, typename ExtractKey>
    static bool sort(It begin, It end, OutIt out_begin, OutIt out_end, ExtractKey && extract_key)
    {
        bool which = NextSorter::sort(begin, end, out_begin, out_end, extract_key);
        auto extract_i = [&](auto && o) -> decltype(auto)
        {
            return std::get<I>(extract_key(o));
        };
        if (which)
            return !ThisSorter::sort(out_begin, out_end, begin, extract_i);
        else
            return ThisSorter::sort(begin, end, out_begin, extract_i);
    }

    static constexpr size_t pass_count = ThisSorter::pass_count + NextSorter::pass_count;
};
template<size_t I, typename Tuple>
struct TupleRadixSorter<I, I, Tuple>
{
    template<typename It, typename OutIt, typename ExtractKey>
    static bool sort(It, It, OutIt, OutIt, ExtractKey &&)
    {
        return false;
    }

    static constexpr size_t pass_count = 0;
};
template<size_t I, typename Tuple>
struct TupleRadixSorter<I, I, const Tuple &>
{
    template<typename It, typename OutIt, typename ExtractKey>
    static bool sort(It, It, OutIt, OutIt, ExtractKey &&)
    {
        return false;
    }

    static constexpr size_t pass_count = 0;
};

template<typename... Args>
struct RadixSorter<std::tuple<Args...>>
{
    using SorterImpl = TupleRadixSorter<0, sizeof...(Args), std::tuple<Args...>>;

    template<typename It, typename OutIt, typename ExtractKey>
    static bool sort(It begin, It end, OutIt buffer_begin, ExtractKey && extract_key)
    {
        return SorterImpl::sort(begin, end, buffer_begin, buffer_begin + (end - begin), extract_key);
    }

    static constexpr size_t pass_count = SorterImpl::pass_count;
};

template<typename... Args>
struct RadixSorter<const std::tuple<Args...> &>
{
    using SorterImpl = TupleRadixSorter<0, sizeof...(Args), const std::tuple<Args...> &>;

    template<typename It, typename OutIt, typename ExtractKey>
    static bool sort(It begin, It end, OutIt buffer_begin, ExtractKey && extract_key)
    {
        return SorterImpl::sort(begin, end, buffer_begin, buffer_begin + (end - begin), extract_key);
    }

    static constexpr size_t pass_count = SorterImpl::pass_count;
};

template<typename T, size_t S>
struct RadixSorter<std::array<T, S>>
{
    template<typename It, typename OutIt, typename ExtractKey>
    static bool sort(It begin, It end, OutIt buffer_begin, ExtractKey && extract_key)
    {
        auto buffer_end = buffer_begin + (end - begin);
        bool which = false;
        for (size_t i = S; i > 0; --i)
        {
            auto extract_i = [&, i = i - 1](auto && o)
            {
                return extract_key(o)[i];
            };
            if (which)
                which = !RadixSorter<T>::sort(buffer_begin, buffer_end, begin, extract_i);
            else
                which = RadixSorter<T>::sort(begin, end, buffer_begin, extract_i);
        }
        return which;
    }

    static constexpr size_t pass_count = RadixSorter<T>::pass_count * S;
};

template<typename T>
struct RadixSorter<const T> : RadixSorter<T>
{
};
template<typename T>
struct RadixSorter<T &> : RadixSorter<const T &>
{
};
template<typename T>
struct RadixSorter<T &&> : RadixSorter<T>
{
};
template<typename T>
struct RadixSorter<const T &> : RadixSorter<T>
{
};
template<typename T>
struct RadixSorter<const T &&> : RadixSorter<T>
{
};












struct ExampleStructA { int i; };
struct ExampleStructB { float f; };
inline int id8(ExampleStructA a) { return a.i; }
inline float id8(ExampleStructB b) { return b.f; }
template<typename T, typename Enable = void>
struct FallbackRadixSorter : RadixSorter<decltype(id8(std::declval<T>()))>
{
    using base = RadixSorter<decltype(id8(std::declval<T>()))>;

    template<typename It, typename OutIt, typename ExtractKey>
    static bool sort(It begin, It end, OutIt buffer_begin, ExtractKey && extract_key)
    {
        return base::sort(begin, end, buffer_begin, [&](auto && a) -> decltype(auto)
        {
            return id8(extract_key(a));
        });
    }
};

template<typename...>
struct nested_void
{
    using type = void;
};

template<typename... Args>
using void_t = typename nested_void<Args...>::type;

template<typename T>
struct has_subscript_operator_impl
{
    template<typename U, typename = decltype(std::declval<U>()[0])>
    static std::true_type test(int);
    template<typename>
    static std::false_type test(...);

    using type = decltype(test<T>(0));
};

template<typename T>
using has_subscript_operator = typename has_subscript_operator_impl<T>::type;


template<typename T>
struct FallbackRadixSorter<T, void_t<decltype(id16(std::declval<T>()))>>
    : RadixSorter<decltype(id16(std::declval<T>()))>
{
};

template<typename T>
struct RadixSorter : FallbackRadixSorter<T>
{
};

template<typename T>
size_t id24 = RadixSorter<T>::pass_count;

template<typename It, typename Func>
inline void id32(It begin, size_t iteration_count, Func && to_call)
{
    size_t loop_count = iteration_count / 4;
    size_t id14 = iteration_count - loop_count * 4;
    for (; loop_count > 0; --loop_count)
    {
        to_call(begin);
        ++begin;
        to_call(begin);
        ++begin;
        to_call(begin);
        ++begin;
        to_call(begin);
        ++begin;
    }
    switch(id14)
    {
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

template<typename It, typename F>
inline It id20(It begin, It end, F && func)
{
    for (;; ++begin)
    {
        if (begin == end)
            return end;
        if (!func(*begin))
            break;
    }
    It it = begin;
    for(++it; it != end; ++it)
    {
        if (!func(*it))
            continue;

        std::iter_swap(begin, it);
        ++begin;
    }
    return begin;
}

struct PartitionInfo
{
    PartitionInfo()
        : count(0)
    {
    }

    union
    {
        size_t count;
        size_t offset;
    };
    size_t next_offset;
};

template<size_t>
struct UnsignedForSize;
template<>
struct UnsignedForSize<1>
{
    typedef uint8_t type;
};
template<>
struct UnsignedForSize<2>
{
    typedef uint16_t type;
};
template<>
struct UnsignedForSize<4>
{
    typedef uint32_t type;
};
template<>
struct UnsignedForSize<8>
{
    typedef uint64_t type;
};
template<typename T>
struct SubKey;
template<size_t Size>
struct SizedSubKey
{
    template<typename T>
    static auto sub_key(T && value, void *)
    {
        return id16(value);
    }

    typedef SubKey<void> next;

    using sub_key_type = typename UnsignedForSize<Size>::type;
};
template<typename T>
struct SubKey<const T> : SubKey<T>
{
};
template<typename T>
struct SubKey<T &> : SubKey<T>
{
};
template<typename T>
struct SubKey<T &&> : SubKey<T>
{
};
template<typename T>
struct SubKey<const T &> : SubKey<T>
{
};
template<typename T>
struct SubKey<const T &&> : SubKey<T>
{
};
template<typename T, typename Enable = void>
struct FallbackSubKey
    : SubKey<decltype(id8(std::declval<T>()))>
{
    using base = SubKey<decltype(id8(std::declval<T>()))>;

    template<typename U>
    static decltype(auto) sub_key(U && value, void * data)
    {
        return base::sub_key(id8(value), data);
    }
};
template<typename T>
struct FallbackSubKey<T, void_t<decltype(id16(std::declval<T>()))>>
    : SubKey<decltype(id16(std::declval<T>()))>
{
};
template<typename T>
struct SubKey : FallbackSubKey<T>
{
};
template<>
struct SubKey<bool>
{
    template<typename T>
    static bool sub_key(T && value, void *)
    {
        return value;
    }

    typedef SubKey<void> next;

    using sub_key_type = bool;
};
template<>
struct SubKey<void>;
template<>
struct SubKey<unsigned char> : SizedSubKey<sizeof(unsigned char)>
{
};
template<>
struct SubKey<unsigned short> : SizedSubKey<sizeof(unsigned short)>
{
};
template<>
struct SubKey<unsigned int> : SizedSubKey<sizeof(unsigned int)>
{
};
template<>
struct SubKey<unsigned long> : SizedSubKey<sizeof(unsigned long)>
{
};
template<>
struct SubKey<unsigned long long> : SizedSubKey<sizeof(unsigned long long)>
{
};
template<typename T>
struct SubKey<T *> : SizedSubKey<sizeof(T *)>
{
};
template<typename F, typename S, typename Current>
struct PairSecondSubKey : Current
{
    static decltype(auto) sub_key(const std::pair<F, S> & value, void * sort_data)
    {
        return Current::sub_key(value.second, sort_data);
    }

    using next = typename std::conditional<std::is_same<SubKey<void>, typename Current::next>::value, SubKey<void>, PairSecondSubKey<F, S, typename Current::next>>::type;
};
template<typename F, typename S, typename Current>
struct PairFirstSubKey : Current
{
    static decltype(auto) sub_key(const std::pair<F, S> & value, void * sort_data)
    {
        return Current::sub_key(value.first, sort_data);
    }

    using next = typename std::conditional<std::is_same<SubKey<void>, typename Current::next>::value, PairSecondSubKey<F, S, SubKey<S>>, PairFirstSubKey<F, S, typename Current::next>>::type;
};
template<typename F, typename S>
struct SubKey<std::pair<F, S>> : PairFirstSubKey<F, S, SubKey<F>>
{
};
template<size_t Index, typename First, typename... More>
struct TypeAt : TypeAt<Index - 1, More..., void>
{
};
template<typename First, typename... More>
struct TypeAt<0, First, More...>
{
    typedef First type;
};

template<size_t Index, typename Current, typename First, typename... More>
struct TupleSubKey;

template<size_t Index, typename Next, typename First, typename... More>
struct NextTupleSubKey
{
    using type = TupleSubKey<Index, Next, First, More...>;
};
template<size_t Index, typename First, typename Second, typename... More>
struct NextTupleSubKey<Index, SubKey<void>, First, Second, More...>
{
    using type = TupleSubKey<Index + 1, SubKey<Second>, Second, More...>;
};
template<size_t Index, typename First>
struct NextTupleSubKey<Index, SubKey<void>, First>
{
    using type = SubKey<void>;
};

template<size_t Index, typename Current, typename First, typename... More>
struct TupleSubKey : Current
{
    template<typename Tuple>
    static decltype(auto) sub_key(const Tuple & value, void * sort_data)
    {
        return Current::sub_key(std::get<Index>(value), sort_data);
    }

    using next = typename NextTupleSubKey<Index, typename Current::next, First, More...>::type;
};
template<size_t Index, typename Current, typename First>
struct TupleSubKey<Index, Current, First> : Current
{
    template<typename Tuple>
    static decltype(auto) sub_key(const Tuple & value, void * sort_data)
    {
        return Current::sub_key(std::get<Index>(value), sort_data);
    }

    using next = typename NextTupleSubKey<Index, typename Current::next, First>::type;
};
template<typename First, typename... More>
struct SubKey<std::tuple<First, More...>> : TupleSubKey<0, SubKey<First>, First, More...>
{
};

struct BaseListSortData
{
    size_t current_index;
    size_t recursion_limit;
    void * id1;
};
template<typename It, typename ExtractKey>
struct ListSortData : BaseListSortData
{
    void (*next_sort)(It, It, std::ptrdiff_t, ExtractKey &, void *);
};

template<typename CurrentSubKey, typename T>
struct ListElementSubKey : SubKey<typename std::decay<decltype(std::declval<T>()[0])>::type>
{
    using base = SubKey<typename std::decay<decltype(std::declval<T>()[0])>::type>;

    using next = ListElementSubKey;

    template<typename U>
    static decltype(auto) sub_key(U && value, void * sort_data)
    {
        BaseListSortData * list_sort_data = static_cast<BaseListSortData *>(sort_data);
        const T & list = CurrentSubKey::sub_key(value, list_sort_data->id1);
        return base::sub_key(list[list_sort_data->current_index], list_sort_data->id1);
    }
};

template<typename T>
struct ListSubKey
{
    using next = SubKey<void>;

    using sub_key_type = T;

    static const T & sub_key(const T & value, void *)
    {
        return value;
    }
};

template<typename T>
struct FallbackSubKey<T, typename std::enable_if<has_subscript_operator<T>::value>::type> : ListSubKey<T>
{
};

template<typename It, typename ExtractKey>
inline void id10(It begin, It end, ExtractKey & extract_key)
{
    std::sort(begin, end, [&](auto && l, auto && r){ return extract_key(l) < extract_key(r); });
}

template<std::ptrdiff_t id12, typename It, typename ExtractKey>
inline bool id15(It begin, It end, std::ptrdiff_t num_elements, ExtractKey & extract_key)
{
    if (num_elements <= 1)
        return true;
    if (num_elements >= id12)
        return false;
    id10(begin, end, extract_key);
    return true;
}

template<std::ptrdiff_t id12, std::ptrdiff_t id5, typename CurrentSubKey, typename SubKeyType = typename CurrentSubKey::sub_key_type>
struct InplaceSorter;

template<std::ptrdiff_t id12, std::ptrdiff_t id5, typename CurrentSubKey, size_t NumBytes, size_t Offset = 0>
struct UnsignedInplaceSorter
{
    static constexpr size_t ShiftAmount = (((NumBytes - 1) - Offset) * 8);
    template<typename T>
    inline static uint8_t current_byte(T && elem, void * sort_data)
    {
        return CurrentSubKey::sub_key(elem, sort_data) >> ShiftAmount;
    }
    template<typename It, typename ExtractKey>
    static void sort(It begin, It end, std::ptrdiff_t num_elements, ExtractKey & extract_key, void (*next_sort)(It, It, std::ptrdiff_t, ExtractKey &, void *), void * sort_data)
    {
        if (num_elements < id5)
            id29(begin, end, extract_key, next_sort, sort_data);
        else
            id7(begin, end, extract_key, next_sort, sort_data);
    }

    template<typename It, typename ExtractKey>
    static void id29(It begin, It end, ExtractKey & extract_key, void (*next_sort)(It, It, std::ptrdiff_t, ExtractKey &, void *), void * sort_data)
    {
        PartitionInfo partitions[256];
        for (It it = begin; it != end; ++it)
        {
            ++partitions[current_byte(extract_key(*it), sort_data)].count;
        }
        size_t total = 0;
        uint8_t id6[256];
        int id30 = 0;
        for (int i = 0; i < 256; ++i)
        {
            size_t count = partitions[i].count;
            if (!count)
                continue;
            partitions[i].offset = total;
            total += count;
            partitions[i].next_offset = total;
            id6[id30] = i;
            ++id30;
        }
        if (id30 > 1)
        {
            uint8_t * current_block_ptr = id6;
            PartitionInfo * current_block = partitions + *current_block_ptr;
            uint8_t * last_block = id6 + id30 - 1;
            It it = begin;
            It block_end = begin + current_block->next_offset;
            It last_element = end - 1;
            for (;;)
            {
                PartitionInfo * block = partitions + current_byte(extract_key(*it), sort_data);
                if (block == current_block)
                {
                    ++it;
                    if (it == last_element)
                        break;
                    else if (it == block_end)
                    {
                        for (;;)
                        {
                            ++current_block_ptr;
                            if (current_block_ptr == last_block)
                                goto recurse;
                            current_block = partitions + *current_block_ptr;
                            if (current_block->offset != current_block->next_offset)
                                break;
                        }

                        it = begin + current_block->offset;
                        block_end = begin + current_block->next_offset;
                    }
                }
                else
                {
                    size_t offset = block->offset++;
                    std::iter_swap(it, begin + offset);
                }
            }
        }
        recurse:
        if (Offset + 1 != NumBytes || next_sort)
        {
            size_t start_offset = 0;
            It partition_begin = begin;
            for (uint8_t * it = id6, * part_end = id6 + id30; it != part_end; ++it)
            {
                size_t end_offset = partitions[*it].next_offset;
                It partition_end = begin + end_offset;
                std::ptrdiff_t num_elements = end_offset - start_offset;
                if (!id15<id12>(partition_begin, partition_end, num_elements, extract_key))
                {
                    UnsignedInplaceSorter<id12, id5, CurrentSubKey, NumBytes, Offset + 1>::sort(partition_begin, partition_end, num_elements, extract_key, next_sort, sort_data);
                }
                start_offset = end_offset;
                partition_begin = partition_end;
            }
        }
    }

    template<typename It, typename ExtractKey>
    static void id7(It begin, It end, ExtractKey & extract_key, void (*next_sort)(It, It, std::ptrdiff_t, ExtractKey &, void *), void * sort_data)
    {
        PartitionInfo partitions[256];
        for (It it = begin; it != end; ++it)
        {
            ++partitions[current_byte(extract_key(*it), sort_data)].count;
        }
        uint8_t id6[256];
        size_t total = 0;
        int id30 = 0;
        for (int i = 0; i < 256; ++i)
        {
            size_t count = partitions[i].count;
            if (count)
            {
                partitions[i].offset = total;
                total += count;
                id6[id30] = i;
                ++id30;
            }
            partitions[i].next_offset = total;
        }
        for (uint8_t * last_remaining = id6 + id30, * end_partition = id6 + 1; last_remaining > end_partition;)
        {
            last_remaining = id20(id6, last_remaining, [&](uint8_t partition)
            {
                size_t & begin_offset = partitions[partition].offset;
                size_t & end_offset = partitions[partition].next_offset;
                if (begin_offset == end_offset)
                    return false;

                id32(begin + begin_offset, end_offset - begin_offset, [partitions = partitions, begin, &extract_key, sort_data](It it)
                {
                    uint8_t this_partition = current_byte(extract_key(*it), sort_data);
                    size_t offset = partitions[this_partition].offset++;
                    std::iter_swap(it, begin + offset);
                });
                return begin_offset != end_offset;
            });
        }
        if (Offset + 1 != NumBytes || next_sort)
        {
            for (uint8_t * it = id6 + id30; it != id6; --it)
            {
                uint8_t partition = it[-1];
                size_t start_offset = (partition == 0 ? 0 : partitions[partition - 1].next_offset);
                size_t end_offset = partitions[partition].next_offset;
                It partition_begin = begin + start_offset;
                It partition_end = begin + end_offset;
                std::ptrdiff_t num_elements = end_offset - start_offset;
                if (!id15<id12>(partition_begin, partition_end, num_elements, extract_key))
                {
                    UnsignedInplaceSorter<id12, id5, CurrentSubKey, NumBytes, Offset + 1>::sort(partition_begin, partition_end, num_elements, extract_key, next_sort, sort_data);
                }
            }
        }
    }
};

template<std::ptrdiff_t id12, std::ptrdiff_t id5, typename CurrentSubKey, size_t NumBytes>
struct UnsignedInplaceSorter<id12, id5, CurrentSubKey, NumBytes, NumBytes>
{
    template<typename It, typename ExtractKey>
    inline static void sort(It begin, It end, std::ptrdiff_t num_elements, ExtractKey & extract_key, void (*next_sort)(It, It, std::ptrdiff_t, ExtractKey &, void *), void * id1)
    {
        next_sort(begin, end, num_elements, extract_key, id1);
    }
};

template<typename It, typename ExtractKey, typename ElementKey>
size_t CommonPrefix(It begin, It end, size_t start_index, ExtractKey && extract_key, ElementKey && element_key)
{
    const auto & id25 = extract_key(*begin);
    size_t largest_match = id25.size();
    if (largest_match == start_index)
        return start_index;
    for (++begin; begin != end; ++begin)
    {
        const auto & current_list = extract_key(*begin);
        size_t current_size = current_list.size();
        if (current_size < largest_match)
        {
            largest_match = current_size;
            if (largest_match == start_index)
                return start_index;
        }
        if (element_key(id25[start_index]) != element_key(current_list[start_index]))
            return start_index;
        for (size_t i = start_index + 1; i < largest_match; ++i)
        {
            if (element_key(id25[i]) != element_key(current_list[i]))
            {
                largest_match = i;
                break;
            }
        }
    }
    return largest_match;
}

template<std::ptrdiff_t id12, std::ptrdiff_t id5, typename CurrentSubKey, typename ListType>
struct ListInplaceSorter
{
    using ElementSubKey = ListElementSubKey<CurrentSubKey, ListType>;
    template<typename It, typename ExtractKey>
    static void sort(It begin, It end, ExtractKey & extract_key, ListSortData<It, ExtractKey> * sort_data)
    {
        size_t current_index = sort_data->current_index;
        void * id1 = sort_data->id1;
        auto current_key = [&](auto && elem) -> decltype(auto)
        {
            return CurrentSubKey::sub_key(extract_key(elem), id1);
        };
        auto element_key = [&](auto && elem) -> decltype(auto)
        {
            return ElementSubKey::base::sub_key(elem, sort_data);
        };
        sort_data->current_index = current_index = CommonPrefix(begin, end, current_index, current_key, element_key);
        It id9 = std::partition(begin, end, [&](auto && elem)
        {
            return current_key(elem).size() <= current_index;
        });
        std::ptrdiff_t id23 = id9 - begin;
        if (sort_data->next_sort && !id15<id12>(begin, id9, id23, extract_key))
        {
            sort_data->next_sort(begin, id9, id23, extract_key, id1);
        }
        std::ptrdiff_t num_elements = end - id9;
        if (!id15<id12>(id9, end, num_elements, extract_key))
        {
            void (*sort_next_element)(It, It, std::ptrdiff_t, ExtractKey &, void *) = static_cast<void (*)(It, It, std::ptrdiff_t, ExtractKey &, void *)>(&id2);
            InplaceSorter<id12, id5, ElementSubKey>::sort(id9, end, num_elements, extract_key, sort_next_element, sort_data);
        }
    }

    template<typename It, typename ExtractKey>
    static void id2(It begin, It end, std::ptrdiff_t, ExtractKey & extract_key, void * id1)
    {
        ListSortData<It, ExtractKey> offset = *static_cast<ListSortData<It, ExtractKey> *>(id1);
        ++offset.current_index;
        --offset.recursion_limit;
        if (offset.recursion_limit == 0)
        {
            id10(begin, end, extract_key);
        }
        else
        {
            sort(begin, end, extract_key, &offset);
        }
    }


    template<typename It, typename ExtractKey>
    static void sort(It begin, It end, std::ptrdiff_t, ExtractKey & extract_key, void (*next_sort)(It, It, std::ptrdiff_t, ExtractKey &, void *), void * id1)
    {
        ListSortData<It, ExtractKey> offset;
        offset.current_index = 0;
        offset.recursion_limit = 16;
        offset.next_sort = next_sort;
        offset.id1 = id1;
        sort(begin, end, extract_key, &offset);
    }
};

template<std::ptrdiff_t id12, std::ptrdiff_t id5, typename CurrentSubKey>
struct InplaceSorter<id12, id5, CurrentSubKey, bool>
{
    template<typename It, typename ExtractKey>
    static void sort(It begin, It end, std::ptrdiff_t, ExtractKey & extract_key, void (*next_sort)(It, It, std::ptrdiff_t, ExtractKey &, void *), void * sort_data)
    {
        It middle = std::partition(begin, end, [&](auto && a){ return !CurrentSubKey::sub_key(extract_key(a), sort_data); });
        if (next_sort)
        {
            next_sort(begin, middle, middle - begin, extract_key, sort_data);
            next_sort(middle, end, end - middle, extract_key, sort_data);
        }
    }
};

template<std::ptrdiff_t id12, std::ptrdiff_t id5, typename CurrentSubKey>
struct InplaceSorter<id12, id5, CurrentSubKey, uint8_t> : UnsignedInplaceSorter<id12, id5, CurrentSubKey, 1>
{
};
template<std::ptrdiff_t id12, std::ptrdiff_t id5, typename CurrentSubKey>
struct InplaceSorter<id12, id5, CurrentSubKey, uint16_t> : UnsignedInplaceSorter<id12, id5, CurrentSubKey, 2>
{
};
template<std::ptrdiff_t id12, std::ptrdiff_t id5, typename CurrentSubKey>
struct InplaceSorter<id12, id5, CurrentSubKey, uint32_t> : UnsignedInplaceSorter<id12, id5, CurrentSubKey, 4>
{
};
template<std::ptrdiff_t id12, std::ptrdiff_t id5, typename CurrentSubKey>
struct InplaceSorter<id12, id5, CurrentSubKey, uint64_t> : UnsignedInplaceSorter<id12, id5, CurrentSubKey, 8>
{
};
template<std::ptrdiff_t id12, std::ptrdiff_t id5, typename CurrentSubKey, typename SubKeyType, typename Enable = void>
struct FallbackInplaceSorter;

template<std::ptrdiff_t id12, std::ptrdiff_t id5, typename CurrentSubKey, typename SubKeyType>
struct InplaceSorter : FallbackInplaceSorter<id12, id5, CurrentSubKey, SubKeyType>
{
};

template<std::ptrdiff_t id12, std::ptrdiff_t id5, typename CurrentSubKey, typename SubKeyType>
struct FallbackInplaceSorter<id12, id5, CurrentSubKey, SubKeyType, typename std::enable_if<has_subscript_operator<SubKeyType>::value>::type>
    : ListInplaceSorter<id12, id5, CurrentSubKey, SubKeyType>
{
};

template<std::ptrdiff_t id12, std::ptrdiff_t id5, typename CurrentSubKey>
struct SortStarter;
template<std::ptrdiff_t id12, std::ptrdiff_t id5>
struct SortStarter<id12, id5, SubKey<void>>
{
    template<typename It, typename ExtractKey>
    static void sort(It, It, std::ptrdiff_t, ExtractKey &, void *)
    {
    }
};

template<std::ptrdiff_t id12, std::ptrdiff_t id5, typename CurrentSubKey>
struct SortStarter
{
    template<typename It, typename ExtractKey>
    static void sort(It begin, It end, std::ptrdiff_t num_elements, ExtractKey & extract_key, void * id1 = nullptr)
    {
        if (id15<id12>(begin, end, num_elements, extract_key))
            return;

        void (*next_sort)(It, It, std::ptrdiff_t, ExtractKey &, void *) = static_cast<void (*)(It, It, std::ptrdiff_t, ExtractKey &, void *)>(&SortStarter<id12, id5, typename CurrentSubKey::next>::sort);
        if (next_sort == static_cast<void (*)(It, It, std::ptrdiff_t, ExtractKey &, void *)>(&SortStarter<id12, id5, SubKey<void>>::sort))
            next_sort = nullptr;
        InplaceSorter<id12, id5, CurrentSubKey>::sort(begin, end, num_elements, extract_key, next_sort, id1);
    }
};

template<std::ptrdiff_t id12, std::ptrdiff_t id5, typename It, typename ExtractKey>
void id4(It begin, It end, ExtractKey & extract_key)
{
    using SubKey = SubKey<decltype(extract_key(*begin))>;
    SortStarter<id12, id5, SubKey>::sort(begin, end, end - begin, extract_key);
}

struct IdentityFunctor
{
    template<typename T>
    decltype(auto) operator()(T && i) const
    {
        return std::forward<T>(i);
    }
};
}

template<typename It, typename ExtractKey>
static void ska_sort(It begin, It end, ExtractKey && extract_key)
{
    detail::id4<128, 1024>(begin, end, extract_key);
}

template<typename It>
static void ska_sort(It begin, It end)
{
    ska_sort(begin, end, detail::IdentityFunctor());
}

template<typename It, typename OutIt, typename ExtractKey>
bool id11(It begin, It end, OutIt buffer_begin, ExtractKey && key)
{
    std::ptrdiff_t num_elements = end - begin;
    if (num_elements < 128 || detail::id24<typename std::result_of<ExtractKey(decltype(*begin))>::type> >= 8)
    {
        ska_sort(begin, end, key);
        return false;
    }
    else
        return detail::RadixSorter<typename std::result_of<ExtractKey(decltype(*begin))>::type>::sort(begin, end, buffer_begin, key);
}
template<typename It, typename OutIt>
bool id11(It begin, It end, OutIt buffer_begin)
{
    return id11(begin, end, buffer_begin, detail::IdentityFunctor());
}


const bool id3 = true;
const long long LL_INF = (long long) 2e18 + 5;

struct point {
    long long x, y;

    point(long long _x = 0, long long _y = 0) : x(_x), y(_y) {}

    point operator-(const point &other) const {
        return point(x - other.x, y - other.y);
    }
};

long long cross(const point &a, const point &b) {
    return a.x * b.y - b.x * a.y;
}

int cross_sign(const point &a, const point &b) {
    if (id3) {
        double double_value = (double) a.x * b.y - (double) b.x * a.y;

        if (abs(double_value) > 1e18)
            return double_value > 0 ? +1 : -1;
    }

    uint64_t id28 = (uint64_t) a.x * b.y - (uint64_t) b.x * a.y;

    if (id28 == 0)
        return 0;

    return id28 < 9e18 ? +1 : -1;
}

bool left_turn(const point &a, const point &b, const point &c) {
    return cross_sign(b - a, c - b) > 0;
}


const int N_MAX = 1e6 + 5;









struct monotonic_dp_hull {
    point points[N_MAX];
    int front = 0, back = 0;

    inline void insert(const point &p) {
        if (front >= back) {
            points[back++] = p;
            return;
        }

        if (p.x == points[back - 1].x) {
            if (p.y <= points[back - 1].y)
                return;
            else
                back--;
        }

        while (back - front >= 2 && left_turn(points[back - 2], points[back - 1], p))
            back--;

        points[back++] = p;
    }

    inline void insert(long long a, long long b) {
        insert(point(a, b));
    }

    

    inline long long query(long long x) {
        while (back - front >= 2 && x * (points[front + 1].x - points[front].x) >= points[front].y - points[front + 1].y)
            front++;

        return points[front].x * x + points[front].y;
    }
};


struct rectangle {
    int x = 0, y = 0;
    long long cost = 0;

    bool operator<(const rectangle &other) const {
        return x < other.x;
    }
};

int N;
vector<rectangle> rect;

int main() {
    IO::read_int(N);
    rect.resize(N);

    for (rectangle &r : rect) {
        IO::read_int(r.x);
        IO::read_int(r.y);
        IO::read_int(r.cost);
    }

    ska_sort(rect.begin(), rect.end(), [](const rectangle &r) {
        return r.x;
    });

    monotonic_dp_hull hull;
    hull.insert(0, 0);
    long long best = 0;

    for (rectangle &r : rect) {
        long long value = (long long) r.x * r.y + hull.query(-r.y) - r.cost;
        best = max(best, value);
        hull.insert(r.x, value);
    }

    printf("%lld\n", best);
}
