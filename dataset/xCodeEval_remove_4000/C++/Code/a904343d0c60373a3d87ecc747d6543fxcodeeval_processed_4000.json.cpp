





using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }







namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    size_t input_pos = 0, input_len = 0;

    void id15() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;

        if (input_len == 0)
            input_buffer[0] = EOF;
    }

    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            id15();

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














namespace detail
{
inline unsigned int id10(int i)
{
    return static_cast<unsigned int>(i) + static_cast<unsigned int>(1 << (sizeof(int) * 8 - 1));
}
inline unsigned int id10(unsigned int i)
{
    return i;
}
inline unsigned long id10(long l)
{
    return static_cast<unsigned long>(l) + static_cast<unsigned long>(1l << (sizeof(long) * 8 - 1));
}
inline unsigned long id10(unsigned long l)
{
    return l;
}
inline unsigned long long id10(long long l)
{
    return static_cast<unsigned long long>(l) + static_cast<unsigned long long>(1ll << (sizeof(long long) * 8 - 1));
}
inline unsigned long long id10(unsigned long long l)
{
    return l;
}
inline std::uint32_t id10(float f)
{
    union
    {
        float f;
        std::uint32_t u;
    } as_union = { f };
    std::uint32_t sign_bit = -std::int32_t(as_union.u >> 31);
    return as_union.u ^ (sign_bit | 0x80000000);
}
inline std::uint64_t id10(double f)
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
inline void id14(It begin, size_t iteration_count, Func && to_call)
{
    size_t loop_count = iteration_count / 4;
    size_t id8 = iteration_count - loop_count * 4;
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
    switch(id8)
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
inline It id11(It begin, It end, F && func)
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
        return id10(value);
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
struct FallbackSubKey<T, void_t<decltype(id10(std::declval<T>()))>>
    : SubKey<decltype(id10(std::declval<T>()))>
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
inline void id5(It begin, It end, ExtractKey & extract_key)
{
    std::sort(begin, end, [&](const typename std::remove_reference<decltype(*begin)>::type & l,
                              const typename std::remove_reference<decltype(*begin)>::type & r) { return extract_key(l) < extract_key(r); });
}

template<std::ptrdiff_t id7, typename It, typename ExtractKey>
inline bool id9(It begin, It end, std::ptrdiff_t num_elements, ExtractKey & extract_key)
{
    if (num_elements <= 1)
        return true;
    if (num_elements >= id7)
        return false;
    id5(begin, end, extract_key);
    return true;
}

template<std::ptrdiff_t id7, std::ptrdiff_t id1, typename CurrentSubKey, typename SubKeyType = typename CurrentSubKey::sub_key_type>
struct InplaceSorter;

template<std::ptrdiff_t id7, std::ptrdiff_t id1, typename CurrentSubKey, size_t NumBytes, size_t Offset = 0>
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
        if (num_elements < id1)
            id12(begin, end, extract_key, next_sort, sort_data);
        else
            id4(begin, end, extract_key, next_sort, sort_data);
    }

    template<typename It, typename ExtractKey>
    static void id12(It begin, It end, ExtractKey & extract_key, void (*next_sort)(It, It, std::ptrdiff_t, ExtractKey &, void *), void * sort_data)
    {
        PartitionInfo partitions[256];
        for (It it = begin; it != end; ++it)
        {
            ++partitions[current_byte(extract_key(*it), sort_data)].count;
        }
        size_t total = 0;
        uint8_t id3[256];
        int id13 = 0;
        for (int i = 0; i < 256; ++i)
        {
            size_t count = partitions[i].count;
            if (!count)
                continue;
            partitions[i].offset = total;
            total += count;
            partitions[i].next_offset = total;
            id3[id13] = i;
            ++id13;
        }
        if (id13 > 1)
        {
            uint8_t * current_block_ptr = id3;
            PartitionInfo * current_block = partitions + *current_block_ptr;
            uint8_t * last_block = id3 + id13 - 1;
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
            for (uint8_t * it = id3, * part_end = id3 + id13; it != part_end; ++it)
            {
                size_t end_offset = partitions[*it].next_offset;
                It partition_end = begin + end_offset;
                std::ptrdiff_t num_elements = end_offset - start_offset;
                if (!id9<id7>(partition_begin, partition_end, num_elements, extract_key))
                {
                    UnsignedInplaceSorter<id7, id1, CurrentSubKey, NumBytes, Offset + 1>::sort(partition_begin, partition_end, num_elements, extract_key, next_sort, sort_data);
                }
                start_offset = end_offset;
                partition_begin = partition_end;
            }
        }
    }

    template<typename It, typename ExtractKey>
    static void id4(It begin, It end, ExtractKey & extract_key, void (*next_sort)(It, It, std::ptrdiff_t, ExtractKey &, void *), void * sort_data)
    {
        PartitionInfo partitions[256];
        for (It it = begin; it != end; ++it)
        {
            ++partitions[current_byte(extract_key(*it), sort_data)].count;
        }
        uint8_t id3[256];
        size_t total = 0;
        int id13 = 0;
        for (int i = 0; i < 256; ++i)
        {
            size_t count = partitions[i].count;
            if (count)
            {
                partitions[i].offset = total;
                total += count;
                id3[id13] = i;
                ++id13;
            }
            partitions[i].next_offset = total;
        }
        for (uint8_t * last_remaining = id3 + id13, * end_partition = id3 + 1; last_remaining > end_partition;)
        {
            last_remaining = id11(id3, last_remaining, [&](uint8_t partition)
            {
                size_t & begin_offset = partitions[partition].offset;
                size_t & end_offset = partitions[partition].next_offset;
                if (begin_offset == end_offset)
                    return false;

                id14(begin + begin_offset, end_offset - begin_offset, [&](It it)
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
            for (uint8_t * it = id3 + id13; it != id3; --it)
            {
                uint8_t partition = it[-1];
                size_t start_offset = (partition == 0 ? 0 : partitions[partition - 1].next_offset);
                size_t end_offset = partitions[partition].next_offset;
                It partition_begin = begin + start_offset;
                It partition_end = begin + end_offset;
                std::ptrdiff_t num_elements = end_offset - start_offset;
                if (!id9<id7>(partition_begin, partition_end, num_elements, extract_key))
                {
                    UnsignedInplaceSorter<id7, id1, CurrentSubKey, NumBytes, Offset + 1>::sort(partition_begin, partition_end, num_elements, extract_key, next_sort, sort_data);
                }
            }
        }
    }
};

template<std::ptrdiff_t id7, std::ptrdiff_t id1, typename CurrentSubKey, size_t NumBytes>
struct UnsignedInplaceSorter<id7, id1, CurrentSubKey, NumBytes, NumBytes>
{
    template<typename It, typename ExtractKey>
    inline static void sort(It begin, It end, std::ptrdiff_t num_elements, ExtractKey & extract_key, void (*next_sort)(It, It, std::ptrdiff_t, ExtractKey &, void *), void * next_sort_data)
    {
        next_sort(begin, end, num_elements, extract_key, next_sort_data);
    }
};

template<std::ptrdiff_t id7, std::ptrdiff_t id1, typename CurrentSubKey>
struct InplaceSorter<id7, id1, CurrentSubKey, uint32_t> : UnsignedInplaceSorter<id7, id1, CurrentSubKey, 4>
{
};
template<std::ptrdiff_t id7, std::ptrdiff_t id1, typename CurrentSubKey>
struct InplaceSorter<id7, id1, CurrentSubKey, uint64_t> : UnsignedInplaceSorter<id7, id1, CurrentSubKey, 8>
{
};

template<std::ptrdiff_t id7, std::ptrdiff_t id1, typename CurrentSubKey>
struct SortStarter;
template<std::ptrdiff_t id7, std::ptrdiff_t id1>
struct SortStarter<id7, id1, SubKey<void>>
{
    template<typename It, typename ExtractKey>
    static void sort(It, It, std::ptrdiff_t, ExtractKey &, void *)
    {
    }
};

template<std::ptrdiff_t id7, std::ptrdiff_t id1, typename CurrentSubKey>
struct SortStarter
{
    template<typename It, typename ExtractKey>
    static void sort(It begin, It end, std::ptrdiff_t num_elements, ExtractKey & extract_key, void * next_sort_data = nullptr)
    {
        if (id9<id7>(begin, end, num_elements, extract_key))
            return;

        void (*next_sort)(It, It, std::ptrdiff_t, ExtractKey &, void *) = static_cast<void (*)(It, It, std::ptrdiff_t, ExtractKey &, void *)>(&SortStarter<id7, id1, typename CurrentSubKey::next>::sort);
        if (next_sort == static_cast<void (*)(It, It, std::ptrdiff_t, ExtractKey &, void *)>(&SortStarter<id7, id1, SubKey<void>>::sort))
            next_sort = nullptr;
        InplaceSorter<id7, id1, CurrentSubKey>::sort(begin, end, num_elements, extract_key, next_sort, next_sort_data);
    }
};

template<std::ptrdiff_t id7, std::ptrdiff_t id1, typename It, typename ExtractKey>
void id0(It begin, It end, ExtractKey & extract_key)
{
    using SubKey = SubKey<decltype(extract_key(*begin))>;
    SortStarter<id7, id1, SubKey>::sort(begin, end, end - begin, extract_key);
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
    detail::id0<128, 1024>(begin, end, extract_key);
}

template<typename It>
static void ska_sort(It begin, It end)
{
    ska_sort(begin, end, detail::IdentityFunctor());
}

auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };

uint64_t id2(uint64_t x) {
    

    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}

const uint64_t id6 = id2(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));

template<typename T>
struct array_hash {
    using hash_t = uint64_t;

    int n;
    vector<T> arr;
    hash_t hash;

    array_hash(int _n = 0) {
        init(_n);
    }

    array_hash(const vector<T> &_arr) {
        init(_arr);
    }

    hash_t get_hash(int index) const {
        assert(0 <= index && index < n);
        

        return id2(arr[index] ^ id2(index ^ id6));
    }

    void compute_hash() {
        hash = 0;

        for (int i = 0; i < n; i++)
            hash += get_hash(i);
    }

    void init(int _n) {
        n = _n;
        arr.assign(n, 0);
        compute_hash();
    }

    void init(const vector<T> &_arr) {
        arr = _arr;
        n = int(arr.size());
        compute_hash();
    }

    const T& operator[](int index) const {
        return arr[index];
    }

    void modify(int index, const T &value) {
        hash -= get_hash(index);
        arr[index] = value;
        hash += get_hash(index);
    }
};


int main() {
    using hash_t = uint64_t;

    int N;
    IO::read_int(N);
    array_hash<int> freq(N + 1);
    vector<pair<hash_t, int>> hashes(N + 1);
    hashes[0] = {freq.hash, 0};
    vector<int> prev_same(N + 1, 0);
    vector<int> last_seen(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        int a;
        IO::read_int(a);
        prev_same[i] = last_seen[a];
        last_seen[a] = i;
        freq.modify(a, (freq[a] + 1) % 3);
        hashes[i] = {freq.hash, i};
    }

    ska_sort(hashes.begin(), hashes.end(), [](const pair<hash_t, int> &p) { return (p.first >> 40 << 19) | p.second; });
    

    vector<int> remove(N + 1, 0);

    for (int i = 1; i <= N; i++)
        remove[i] = max(remove[i - 1], prev_same[prev_same[prev_same[i]]]);

    int64_t answer = 0;

    for (int i = 0, j = 0; i <= N; i = j) {
        while (j <= N && hashes[i].first == hashes[j].first) {
            while (i < j && hashes[i].second < remove[hashes[j].second])
                i++;

            answer += j - i;
            j++;
        }
    }

    cout << answer << '\n';
}
 