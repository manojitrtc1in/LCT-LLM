












namespace detail
{
inline unsigned int id13(int i)
{
    return static_cast<unsigned int>(i) + static_cast<unsigned int>(1 << (sizeof(int) * 8 - 1));
}
inline unsigned int id13(unsigned int i)
{
    return i;
}
inline unsigned long id13(long l)
{
    return static_cast<unsigned long>(l) + static_cast<unsigned long>(1l << (sizeof(long) * 8 - 1));
}
inline unsigned long id13(unsigned long l)
{
    return l;
}
inline unsigned long long id13(long long l)
{
    return static_cast<unsigned long long>(l) + static_cast<unsigned long long>(1ll << (sizeof(long long) * 8 - 1));
}
inline unsigned long long id13(unsigned long long l)
{
    return l;
}
inline std::uint32_t id13(float f)
{
    union
    {
        float f;
        std::uint32_t u;
    } as_union = { f };
    std::uint32_t sign_bit = -std::int32_t(as_union.u >> 31);
    return as_union.u ^ (sign_bit | 0x80000000);
}
inline std::uint64_t id13(double f)
{
    union
    {
        double d;
        std::uint64_t u;
    } as_union = { f };
    std::uint64_t sign_bit = -std::int64_t(as_union.u >> 63);
    return as_union.u ^ (sign_bit | 0x8000000000000000);
}

template<typename...>
struct nested_void
{
    using type = void;
};

template<typename... Args>
using void_t = typename nested_void<Args...>::type;


template<typename It, typename Func>
inline void id7(It begin, size_t iteration_count, Func && to_call)
{
    size_t loop_count = iteration_count / 4;
    size_t id11 = iteration_count - loop_count * 4;
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
    switch(id11)
    {
    case 3:
        to_call(begin);
        ++begin;
        [[fallthrough]];
    case 2:
        to_call(begin);
        ++begin;
        [[fallthrough]];
    case 1:
        to_call(begin);
    }
}

template<typename It, typename F>
inline It id2(It begin, It end, F && func)
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
    using sub_key_type = typename UnsignedForSize<Size>::type;

    template<typename T>
    static sub_key_type sub_key(T && value, void *)
    {
        return id13(value);
    }

    typedef SubKey<void> next;
};
template<typename T, typename Enable = void>
struct FallbackSubKey
    : SubKey<decltype(to_radix_sort_key(std::declval<T>()))>
{
    using base = SubKey<decltype(to_radix_sort_key(std::declval<T>()))>;

    template<typename U>
    static base sub_key(U && value, void * data)
    {
        return base::sub_key(to_radix_sort_key(value), data);
    }
};
template<typename T>
struct FallbackSubKey<T, void_t<decltype(id13(std::declval<T>()))>>
    : SubKey<decltype(id13(std::declval<T>()))>
{
};
template<typename T>
struct SubKey : FallbackSubKey<T>
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

template<typename It, typename ExtractKey>
inline void id0(It begin, It end, ExtractKey & extract_key)
{
    std::sort(begin, end, [&](const typename std::remove_reference<decltype(*begin)>::type & l,
                              const typename std::remove_reference<decltype(*begin)>::type & r) { return extract_key(l) < extract_key(r); });
}

template<std::ptrdiff_t id8, typename It, typename ExtractKey>
inline bool id12(It begin, It end, std::ptrdiff_t num_elements, ExtractKey & extract_key)
{
    if (num_elements <= 1)
        return true;
    if (num_elements >= id8)
        return false;
    id0(begin, end, extract_key);
    return true;
}

template<std::ptrdiff_t id8, std::ptrdiff_t id4, typename CurrentSubKey, typename SubKeyType = typename CurrentSubKey::sub_key_type>
struct InplaceSorter;

template<std::ptrdiff_t id8, std::ptrdiff_t id4, typename CurrentSubKey, size_t NumBytes, size_t Offset = 0>
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
        if (num_elements < id4)
            id1(begin, end, extract_key, next_sort, sort_data);
        else
            id9(begin, end, extract_key, next_sort, sort_data);
    }

    template<typename It, typename ExtractKey>
    static void id1(It begin, It end, ExtractKey & extract_key, void (*next_sort)(It, It, std::ptrdiff_t, ExtractKey &, void *), void * sort_data)
    {
        PartitionInfo partitions[256];
        for (It it = begin; it != end; ++it)
        {
            ++partitions[current_byte(extract_key(*it), sort_data)].count;
        }
        size_t total = 0;
        uint8_t id6[256];
        int id5 = 0;
        for (int i = 0; i < 256; ++i)
        {
            size_t count = partitions[i].count;
            if (!count)
                continue;
            partitions[i].offset = total;
            total += count;
            partitions[i].next_offset = total;
            id6[id5] = i;
            ++id5;
        }
        if (id5 > 1)
        {
            uint8_t * current_block_ptr = id6;
            PartitionInfo * current_block = partitions + *current_block_ptr;
            uint8_t * last_block = id6 + id5 - 1;
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
            for (uint8_t * it = id6, * part_end = id6 + id5; it != part_end; ++it)
            {
                size_t end_offset = partitions[*it].next_offset;
                It partition_end = begin + end_offset;
                std::ptrdiff_t num_elements = end_offset - start_offset;
                if (!id12<id8>(partition_begin, partition_end, num_elements, extract_key))
                {
                    UnsignedInplaceSorter<id8, id4, CurrentSubKey, NumBytes, Offset + 1>::sort(partition_begin, partition_end, num_elements, extract_key, next_sort, sort_data);
                }
                start_offset = end_offset;
                partition_begin = partition_end;
            }
        }
    }

    template<typename It, typename ExtractKey>
    static void id9(It begin, It end, ExtractKey & extract_key, void (*next_sort)(It, It, std::ptrdiff_t, ExtractKey &, void *), void * sort_data)
    {
        PartitionInfo partitions[256];
        for (It it = begin; it != end; ++it)
        {
            ++partitions[current_byte(extract_key(*it), sort_data)].count;
        }
        uint8_t id6[256];
        size_t total = 0;
        int id5 = 0;
        for (int i = 0; i < 256; ++i)
        {
            size_t count = partitions[i].count;
            if (count)
            {
                partitions[i].offset = total;
                total += count;
                id6[id5] = i;
                ++id5;
            }
            partitions[i].next_offset = total;
        }
        for (uint8_t * last_remaining = id6 + id5, * end_partition = id6 + 1; last_remaining > end_partition;)
        {
            last_remaining = id2(id6, last_remaining, [&](uint8_t partition)
            {
                size_t & begin_offset = partitions[partition].offset;
                size_t & end_offset = partitions[partition].next_offset;
                if (begin_offset == end_offset)
                    return false;

                id7(begin + begin_offset, end_offset - begin_offset, [&](It it)
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
            for (uint8_t * it = id6 + id5; it != id6; --it)
            {
                uint8_t partition = it[-1];
                size_t start_offset = (partition == 0 ? 0 : partitions[partition - 1].next_offset);
                size_t end_offset = partitions[partition].next_offset;
                It partition_begin = begin + start_offset;
                It partition_end = begin + end_offset;
                std::ptrdiff_t num_elements = end_offset - start_offset;
                if (!id12<id8>(partition_begin, partition_end, num_elements, extract_key))
                {
                    UnsignedInplaceSorter<id8, id4, CurrentSubKey, NumBytes, Offset + 1>::sort(partition_begin, partition_end, num_elements, extract_key, next_sort, sort_data);
                }
            }
        }
    }
};

template<std::ptrdiff_t id8, std::ptrdiff_t id4, typename CurrentSubKey, size_t NumBytes>
struct UnsignedInplaceSorter<id8, id4, CurrentSubKey, NumBytes, NumBytes>
{
    template<typename It, typename ExtractKey>
    inline static void sort(It begin, It end, std::ptrdiff_t num_elements, ExtractKey & extract_key, void (*next_sort)(It, It, std::ptrdiff_t, ExtractKey &, void *), void * next_sort_data)
    {
        next_sort(begin, end, num_elements, extract_key, next_sort_data);
    }
};

template<std::ptrdiff_t id8, std::ptrdiff_t id4, typename CurrentSubKey>
struct InplaceSorter<id8, id4, CurrentSubKey, uint32_t> : UnsignedInplaceSorter<id8, id4, CurrentSubKey, 4>
{
};
template<std::ptrdiff_t id8, std::ptrdiff_t id4, typename CurrentSubKey>
struct InplaceSorter<id8, id4, CurrentSubKey, uint64_t> : UnsignedInplaceSorter<id8, id4, CurrentSubKey, 8>
{
};

template<std::ptrdiff_t id8, std::ptrdiff_t id4, typename CurrentSubKey>
struct SortStarter;
template<std::ptrdiff_t id8, std::ptrdiff_t id4>
struct SortStarter<id8, id4, SubKey<void>>
{
    template<typename It, typename ExtractKey>
    static void sort(It, It, std::ptrdiff_t, ExtractKey &, void *)
    {
    }
};

template<std::ptrdiff_t id8, std::ptrdiff_t id4, typename CurrentSubKey>
struct SortStarter
{
    template<typename It, typename ExtractKey>
    static void sort(It begin, It end, std::ptrdiff_t num_elements, ExtractKey & extract_key, void * next_sort_data = nullptr)
    {
        if (id12<id8>(begin, end, num_elements, extract_key))
            return;

        void (*next_sort)(It, It, std::ptrdiff_t, ExtractKey &, void *) = static_cast<void (*)(It, It, std::ptrdiff_t, ExtractKey &, void *)>(&SortStarter<id8, id4, typename CurrentSubKey::next>::sort);
        if (next_sort == static_cast<void (*)(It, It, std::ptrdiff_t, ExtractKey &, void *)>(&SortStarter<id8, id4, SubKey<void>>::sort))
            next_sort = nullptr;
        InplaceSorter<id8, id4, CurrentSubKey>::sort(begin, end, num_elements, extract_key, next_sort, next_sort_data);
    }
};

template<std::ptrdiff_t id8, std::ptrdiff_t id4, typename It, typename ExtractKey>
void id3(It begin, It end, ExtractKey & extract_key)
{
    using SubKey = SubKey<decltype(extract_key(*begin))>;
    SortStarter<id8, id4, SubKey>::sort(begin, end, end - begin, extract_key);
}

struct IdentityFunctor
{
    template<typename T>
    T&& operator()(T && i) const
    {
        return std::forward<T>(i);
    }
};
}

template<typename It, typename ExtractKey>
static void ska_sort(It begin, It end, ExtractKey && extract_key)
{
    detail::id3<128, 1024>(begin, end, extract_key);
}

template<typename It>
static void ska_sort(It begin, It end)
{
    ska_sort(begin, end, detail::IdentityFunctor());
}







using namespace std;

namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

    void id10() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;

        if (input_len == 0)
            input_buffer[0] = EOF;
    }

    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            id10();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    template<typename T>
    inline void read_int(T &number) {
        bool negative = false;
        number = 0;

        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;

        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));

        if (negative)
            number = -number;
    }

    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }
}

int main() {
    int N, P, K;
    IO::read_int(N, P, K);
    vector<int> values(N);

    for (int i = 0; i < N; i++) {
        int A;
        IO::read_int(A);
        long long square = (long long) A * A % P;
        values[i] = (square * square - (long long) A * K % P + P) % P;
    }

    ska_sort(values.begin(), values.end());
    int total = 0;

    for (int i = 0, j = 0; i < N; i = j)
        while (j < N && values[i] == values[j]) {
            total += j - i;
            j++;
        }

    cout << total << '\n';
}
