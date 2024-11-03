


















































































































































        [](size_t mask) -> int {                                                         \
            unsigned long index;                                                         \
            return ROBIN_HOOD_BITSCANFORWARD(&index, mask) ? index : ROBIN_HOOD_BITNESS; \
        }(x)


















namespace robin_hood {
namespace detail {


        static_cast<uint64_t>(     \
            (static_cast<unsigned __int128>(a) * static_cast<unsigned __int128>(b)) >> 64u)


inline uint64_t umul128(uint64_t a, uint64_t b, uint64_t* high) {
    auto result = static_cast<unsigned __int128>(a) * static_cast<unsigned __int128>(b);
    *high = static_cast<uint64_t>(result >> 64);
    return static_cast<uint64_t>(result);
}







inline uint64_t umul128(uint64_t a, uint64_t b, uint64_t* high) {
    return _umul128(a, b, high);
}

} 

} 











namespace robin_hood {

namespace detail {





template <typename E, typename... Args>
static ROBIN_HOOD_NOINLINE void doThrow(Args&&... args) {
    throw E(std::forward<Args>(args)...);
}

template <typename E, typename T, typename... Args>
static T* id5(T* t, Args&&... args) {
    if (ROBIN_HOOD_UNLIKELY(nullptr == t)) {
        doThrow<E>(std::forward<Args>(args)...);
    }
    return t;
}

template <typename T>
inline T id17(void const* ptr) {
    

    

    T t;
    std::memcpy(&t, ptr, sizeof(T));
    return t;
}







template <typename T, size_t id13 = 4, size_t id8 = 256>
class id19 {
public:
    id19()
        : mHead(nullptr)
        , id7(nullptr) {}

    

    id19(const id19& id25(o) )
        : mHead(nullptr)
        , id7(nullptr) {}

    id19(id19&& o)
        : mHead(o.mHead)
        , id7(o.id7) {
        o.id7 = nullptr;
        o.mHead = nullptr;
    }

    id19& operator=(id19&& o) {
        reset();
        mHead = o.mHead;
        id7 = o.id7;
        o.id7 = nullptr;
        o.mHead = nullptr;
        return *this;
    }

    id19& operator=(const id19& id25(o) ) {
        

        return *this;
    }

    ~id19() {
        reset();
    }

    

    void reset() {
        while (id7) {
            T* tmp = *id7;
            free(id7);
            id7 = reinterpret_cast<T**>(tmp);
        }
        mHead = nullptr;
    }

    

    

    

    T* allocate() {
        T* tmp = mHead;
        if (!tmp) {
            tmp = performAllocation();
        }

        mHead = *reinterpret_cast<T**>(tmp);
        return tmp;
    }

    

    

    

    

    void deallocate(T* obj) {
        *reinterpret_cast<T**>(obj) = mHead;
        mHead = obj;
    }

    

    

    

    void addOrFree(void* ptr, const size_t numBytes) {
        

        if (numBytes < ALIGNMENT + ALIGNED_SIZE) {
            

            free(ptr);
        } else {
            add(ptr, numBytes);
        }
    }

    void swap(id19<T, id13, id8>& other) {
        using std::swap;
        swap(mHead, other.mHead);
        swap(id7, other.id7);
    }

private:
    

    

    

    

    size_t calcNumElementsToAlloc() const {
        auto tmp = id7;
        size_t id18 = id13;

        while (id18 * 2 <= id8 && tmp) {
            auto x = reinterpret_cast<T***>(tmp);
            tmp = *x;
            id18 *= 2;
        }

        return id18;
    }

    

    void add(void* ptr, const size_t numBytes) {
        const size_t numElements = (numBytes - ALIGNMENT) / ALIGNED_SIZE;

        auto data = reinterpret_cast<T**>(ptr);

        

        auto x = reinterpret_cast<T***>(data);
        *x = id7;
        id7 = data;

        

        auto const headT = reinterpret_cast<T*>(reinterpret_cast<char*>(ptr) + ALIGNMENT);

        auto const head = reinterpret_cast<char*>(headT);

        

        for (size_t i = 0; i < numElements; ++i) {
            *reinterpret_cast<char**>(head + i * ALIGNED_SIZE) = head + (i + 1) * ALIGNED_SIZE;
        }

        

        *reinterpret_cast<T**>(head + (numElements - 1) * ALIGNED_SIZE) = mHead;
        mHead = headT;
    }

    

    

    ROBIN_HOOD_NOINLINE T* performAllocation() {
        size_t const id2 = calcNumElementsToAlloc();

        

        

        size_t const bytes = ALIGNMENT + ALIGNED_SIZE * id2;
        add(id5<std::bad_alloc>(malloc(bytes)), bytes);
        return mHead;
    }

    

    static constexpr size_t ALIGNMENT =
        (std::max)(std::alignment_of<T>::value, std::alignment_of<T*>::value);
    static constexpr size_t ALIGNED_SIZE = ((sizeof(T) - 1) / ALIGNMENT + 1) * ALIGNMENT;

    static_assert(id13 >= 1, "id13");
    static_assert(id8 >= id13, "id8");
    static_assert(ALIGNED_SIZE >= sizeof(T*), "ALIGNED_SIZE");
    static_assert(0 == (ALIGNED_SIZE % sizeof(T*)), "ALIGNED_SIZE mod");
    static_assert(ALIGNMENT >= sizeof(T*), "ALIGNMENT");

    T* mHead;
    T** id7;
};

template <typename T, size_t MinSize, size_t MaxSize, bool id3>
struct NodeAllocator;



template <typename T, size_t MinSize, size_t MaxSize>
struct NodeAllocator<T, MinSize, MaxSize, true> {

    

    void addOrFree(void* ptr, size_t id25(numBytes) ) {
        free(ptr);
    }
};

template <typename T, size_t MinSize, size_t MaxSize>
struct NodeAllocator<T, MinSize, MaxSize, false> : public id19<T, MinSize, MaxSize> {};











namespace DummyInfoByte {

static uint64_t b = 0;

} 

} 


struct is_transparent_tag {};







template <typename First, typename Second>
struct pair {
    using first_type = First;
    using second_type = Second;

    

    explicit pair(std::pair<First, Second> const& o)
        : first{o.first}
        , second{o.second} {}

    

    explicit pair(std::pair<First, Second>&& o)
        : first{std::move(o.first)}
        , second{std::move(o.second)} {}

    constexpr pair(const First& firstArg, const Second& secondArg)
        : first{firstArg}
        , second{secondArg} {}

    constexpr pair(First&& firstArg, Second&& secondArg)
        : first{std::move(firstArg)}
        , second{std::move(secondArg)} {}

    template <typename FirstArg, typename SecondArg>
    constexpr pair(FirstArg&& firstArg, SecondArg&& secondArg)
        : first{std::forward<FirstArg>(firstArg)}
        , second{std::forward<SecondArg>(secondArg)} {}

    template <typename... Args1, typename... Args2>
    pair(std::piecewise_construct_t , std::tuple<Args1...> firstArgs,
         std::tuple<Args2...> secondArgs)
        : pair{firstArgs, secondArgs, std::index_sequence_for<Args1...>{},
               std::index_sequence_for<Args2...>{}} {}

    

    template <typename... Args1, size_t... Indexes1, typename... Args2, size_t... Indexes2>
    inline pair(std::tuple<Args1...>& tuple1, std::tuple<Args2...>& tuple2,
                std::index_sequence<Indexes1...> ,
                std::index_sequence<Indexes2...> )
        : first{std::forward<Args1>(std::get<Indexes1>(tuple1))...}
        , second{std::forward<Args2>(std::get<Indexes2>(tuple2))...} {
        

        

        (void)tuple1;
        (void)tuple2;
    }

    first_type& getFirst() {
        return first;
    }
    first_type const& getFirst() const {
        return first;
    }
    second_type& getSecond() {
        return second;
    }
    second_type const& getSecond() const {
        return second;
    }

    void swap(pair<First, Second>& o) {
        using std::swap;
        swap(first, o.first);
        swap(second, o.second);
    }

    First first;
    Second second;
};





template <typename T>
struct hash : public std::hash<T> {
    size_t operator()(T const& obj) const {
        return std::hash<T>::operator()(obj);
    }
};





inline size_t hash_bytes(void const* ptr, size_t const len) {
    static constexpr uint64_t m = UINT64_C(0xc6a4a7935bd1e995);
    static constexpr uint64_t seed = UINT64_C(0xe17a1465);
    static constexpr unsigned int r = 47;

    auto const data64 = reinterpret_cast<uint64_t const*>(ptr);
    uint64_t h = seed ^ (len * m);

    size_t const n_blocks = len / 8;
    for (size_t i = 0; i < n_blocks; ++i) {
        uint64_t k = detail::id17<uint64_t>(data64 + i);

        k *= m;
        k ^= k >> r;
        k *= m;

        h ^= k;
        h *= m;
    }

    auto const data8 = reinterpret_cast<uint8_t const*>(data64 + n_blocks);
    switch (len & 7u) {
    case 7:
        h ^= static_cast<uint64_t>(data8[6]) << 48u;
        

    case 6:
        h ^= static_cast<uint64_t>(data8[5]) << 40u;
        

    case 5:
        h ^= static_cast<uint64_t>(data8[4]) << 32u;
        

    case 4:
        h ^= static_cast<uint64_t>(data8[3]) << 24u;
        

    case 3:
        h ^= static_cast<uint64_t>(data8[2]) << 16u;
        

    case 2:
        h ^= static_cast<uint64_t>(data8[1]) << 8u;
        

    case 1:
        h ^= static_cast<uint64_t>(data8[0]);
        h *= m;
    };

    h ^= h >> r;
    h *= m;
    h ^= h >> r;

    return static_cast<size_t>(h);
}

template <>
struct hash<std::string> {
    size_t operator()(std::string const& str) const {
        return hash_bytes(str.data(), str.size());
    }
};



template <>
struct hash<uint64_t> {
    size_t operator()(uint64_t const& obj) const {

        

        static constexpr uint64_t k = UINT64_C(0xde5fb9d2630458e9);
        uint64_t h;
        uint64_t l = detail::umul128(obj, k, &h);
        return h + l;

        static constexpr uint32_t k = UINT32_C(0x9a0ecda7);
        uint64_t const r = obj * k;
        uint32_t h = static_cast<uint32_t>(r >> 32);
        uint32_t l = static_cast<uint32_t>(r);
        return h + l;

        

        uint64_t h = obj;
        h ^= h >> 33;
        h *= 0xff51afd7ed558ccd;
        h ^= h >> 33;
        h *= 0xc4ceb9fe1a85ec53;
        h ^= h >> 33;
        return static_cast<size_t>(h);

    }
};

template <>
struct hash<int64_t> {
    size_t operator()(int64_t const& obj) const {
        return hash<uint64_t>{}(static_cast<uint64_t>(obj));
    }
};

template <>
struct hash<uint32_t> {
    size_t operator()(uint32_t const& h) const {

        return static_cast<size_t>((UINT64_C(0xca4bcaa75ec3f625) * (uint64_t)h) >> 32);

        return hash<uint64_t>{}(static_cast<uint64_t>(h));

    }
};

template <>
struct hash<int32_t> {
    size_t operator()(int32_t const& obj) const {
        return hash<uint32_t>{}(static_cast<uint32_t>(obj));
    }
};

namespace detail {























































template <bool id3, size_t id4, typename Key, typename T, typename Hash,
          typename KeyEqual>
class unordered_map
    : public Hash,
      public KeyEqual,
      detail::NodeAllocator<
          robin_hood::pair<typename std::conditional<id3, Key, Key const>::type, T>, 4, 16384,
          id3> {
public:
    using key_type = Key;
    using mapped_type = T;
    using value_type =
        robin_hood::pair<typename std::conditional<id3, Key, Key const>::type, T>;
    using size_type = size_t;
    using hasher = Hash;
    using key_equal = KeyEqual;
    using Self =
        unordered_map<id3, id4, key_type, mapped_type, hasher, key_equal>;
    static constexpr bool is_flat_map = id3;

private:
    static_assert(id4 > 10 && id4 < 100,
                  "id4 needs to be >10 && < 100");

    


    

    static constexpr size_t InitialNumElements = sizeof(uint64_t);
    static constexpr int InitialInfoNumBits = 5;
    static constexpr uint8_t id12 = 1 << InitialInfoNumBits;
    static constexpr uint8_t id22 = sizeof(size_t) * 8 - InitialInfoNumBits;
    using DataPool = detail::NodeAllocator<value_type, 4, 16384, id3>;

    

    using InfoType = int32_t;

    


    

    

    

    template <typename M, bool>
    class DataNode {};

    

    template <typename M>
    class DataNode<M, true> {
    public:
        template <typename... Args>
        explicit DataNode(M& id25(map) , Args&&... args)
            : mData(std::forward<Args>(args)...) {}

        DataNode(M& id25(map) , DataNode<M, true>&& n)
            : mData(std::move(n.mData)) {}

        

        void destroy(M& id25(map) ) {}
        void destroyDoNotDeallocate() {}

        value_type const* operator->() const {
            return &mData;
        }
        value_type* operator->() {
            return &mData;
        }

        const value_type& operator*() const {
            return mData;
        }

        value_type& operator*() {
            return mData;
        }

        typename value_type::first_type& getFirst() {
            return mData.first;
        }

        typename value_type::first_type const& getFirst() const {
            return mData.first;
        }

        typename value_type::second_type& getSecond() {
            return mData.second;
        }

        typename value_type::second_type const& getSecond() const {
            return mData.second;
        }

        void swap(DataNode<M, true>& o) {
            mData.swap(o.mData);
        }

    private:
        value_type mData;
    };

    

    template <typename M>
    class DataNode<M, false> {
    public:
        template <typename... Args>
        explicit DataNode(M& map, Args&&... args)
            : mData(map.allocate()) {
            ::new (static_cast<void*>(mData)) value_type(std::forward<Args>(args)...);
        }

        DataNode(M& id25(map) , DataNode<M, false>&& n)
            : mData(std::move(n.mData)) {}

        void destroy(M& map) {
            

            mData->~value_type();
            map.deallocate(mData);
        }

        void destroyDoNotDeallocate() {
            mData->~value_type();
        }

        value_type const* operator->() const {
            return mData;
        }

        value_type* operator->() {
            return mData;
        }

        const value_type& operator*() const {
            return *mData;
        }

        value_type& operator*() {
            return *mData;
        }

        typename value_type::first_type& getFirst() {
            return mData->first;
        }

        typename value_type::first_type const& getFirst() const {
            return mData->first;
        }

        typename value_type::second_type& getSecond() {
            return mData->second;
        }

        typename value_type::second_type const& getSecond() const {
            return mData->second;
        }

        void swap(DataNode<M, false>& o) {
            using std::swap;
            swap(mData, o.mData);
        }

    private:
        value_type* mData;
    };

    using Node = DataNode<Self, id3>;

    


    template <typename M, bool UseMemcpy>
    struct Cloner;

    

    template <typename M>
    struct Cloner<M, true> {
        void operator()(M const& source, M& target) const {
            

            

            auto src = reinterpret_cast<char const*>(source.id15);
            auto tgt = reinterpret_cast<char*>(target.id15);
            std::copy(src, src + target.calcNumBytesTotal(target.mMask + 1), tgt);
        }
    };

    template <typename M>
    struct Cloner<M, false> {
        void operator()(M const& source, M& target) const {
            

            

            std::copy(source.mInfo, source.mInfo + target.calcNumBytesInfo(target.mMask + 1),
                      target.mInfo);

            for (size_t i = 0; i < target.mMask + 1; ++i) {
                if (target.mInfo[i]) {
                    ::new (static_cast<void*>(target.id15 + i))
                        Node(target, *source.id15[i]);
                }
            }
        }
    };

    


    template <typename M, bool id10>
    struct Destroyer {};

    template <typename M>
    struct Destroyer<M, true> {
        void nodes(M& m) const {
            m.id21 = 0;
        }

        void nodesDoNotDeallocate(M& m) const {
            m.id21 = 0;
        }
    };

    template <typename M>
    struct Destroyer<M, false> {
        void nodes(M& m) const {
            m.id21 = 0;
            

            for (size_t idx = 0; idx <= m.mMask; ++idx) {
                if (0 != m.mInfo[idx]) {
                    Node& n = m.id15[idx];
                    n.destroy(m);
                    n.~Node();
                }
            }
        }

        void nodesDoNotDeallocate(M& m) const {
            m.id21 = 0;
            

            for (size_t idx = 0; idx <= m.mMask; ++idx) {
                if (0 != m.mInfo[idx]) {
                    Node& n = m.id15[idx];
                    n.destroyDoNotDeallocate();
                    n.~Node();
                }
            }
        }
    };

    


    

    template <bool IsConst>
    class Iter {
    private:
        using NodePtr = typename std::conditional<IsConst, Node const*, Node*>::type;

    public:
        using difference_type = std::ptrdiff_t;
        using value_type = typename Self::value_type;
        using reference = typename std::conditional<IsConst, value_type const&, value_type&>::type;
        using pointer = typename std::conditional<IsConst, value_type const*, value_type*>::type;
        using iterator_category = std::forward_iterator_tag;

        

        

        Iter()
            : id15(nullptr)
            , mInfo(nullptr) {}

        

        Iter(Iter<false> const& other)
            : id15(other.id15)
            , mInfo(other.mInfo) {}

        Iter(NodePtr valPtr, uint8_t const* infoPtr)
            : id15(valPtr)
            , mInfo(infoPtr) {}

        

        Iter& operator++() {
            mInfo++;
            id15++;
            int inc;
            do {
                auto const n = detail::id17<size_t>(mInfo);

                inc = ROBIN_HOOD_COUNT_TRAILING_ZEROES(n) / 8;

                inc = ROBIN_HOOD_COUNT_LEADING_ZEROES(n) / 8;

                mInfo += inc;
                id15 += inc;
            } while (inc == sizeof(size_t));
            return *this;
        }

        reference operator*() const {
            return **id15;
        }

        pointer operator->() const {
            return &**id15;
        }

        template <bool O>
        bool operator==(Iter<O> const& o) const {
            return id15 == o.id15;
        }

        template <bool O>
        bool operator!=(Iter<O> const& o) const {
            return id15 != o.id15;
        }

    private:
        friend class unordered_map<id3, id4, key_type, mapped_type, hasher,
                                   key_equal>;
        NodePtr id15;
        uint8_t const* mInfo;
    };

    


    size_t calcNumBytesInfo(size_t numElements) const {
        const size_t s = sizeof(uint8_t) * (numElements + 1);
        if (ROBIN_HOOD_UNLIKELY(s / sizeof(uint8_t) != numElements + 1)) {
            throwOverflowError();
        }
        

        return s + sizeof(uint64_t);
    }
    size_t calcNumBytesNode(size_t numElements) const {
        const size_t s = sizeof(Node) * numElements;
        if (ROBIN_HOOD_UNLIKELY(s / sizeof(Node) != numElements)) {
            throwOverflowError();
        }
        return s;
    }
    size_t calcNumBytesTotal(size_t numElements) const {
        const size_t si = calcNumBytesInfo(numElements);
        const size_t sn = calcNumBytesNode(numElements);
        const size_t s = si + sn;
        if (ROBIN_HOOD_UNLIKELY(s <= si || s <= sn)) {
            throwOverflowError();
        }
        return s;
    }

    

    

    

    template <typename HashKey>
    void id1(HashKey&& key, size_t& idx, InfoType& info) const {
        static constexpr size_t id0 =
            std::is_same<::robin_hood::hash<key_type>, hasher>::value
                ? 1
                : (ROBIN_HOOD_BITNESS == 64 ? UINT64_C(0xb3727c1f779b8d8b) : UINT32_C(0xda4afe47));
        idx = Hash::operator()(key) * id0;
        info = static_cast<InfoType>(id16 + static_cast<InfoType>(idx >> id23));
        idx &= mMask;
    }

    

    void next(InfoType* info, size_t* idx) const {
        *idx = (*idx + 1) & mMask;
        *info = static_cast<InfoType>(*info + id16);
    }

    void nextWhileLess(InfoType* info, size_t* idx) const {
        

        while (*info < mInfo[*idx]) {
            next(info, idx);
        }
    }

    

    

    

    void shiftUp(size_t idx, size_t const id9) {
        while (idx != id9) {
            size_t prev_idx = (idx - 1) & mMask;
            if (mInfo[idx]) {
                id15[idx] = std::move(id15[prev_idx]);
            } else {
                ::new (static_cast<void*>(id15 + idx)) Node(std::move(id15[prev_idx]));
            }
            mInfo[idx] = static_cast<uint8_t>(mInfo[prev_idx] + id16);
            if (ROBIN_HOOD_UNLIKELY(mInfo[idx] + id16 > 0xFF)) {
                id24 = 0;
            }
            idx = prev_idx;
        }
    }

    void shiftDown(size_t idx) {
        

        

        id15[idx].destroy(*this);

        

        size_t nextIdx = (idx + 1) & mMask;
        while (mInfo[nextIdx] >= 2 * id16) {
            mInfo[idx] = static_cast<uint8_t>(mInfo[nextIdx] - id16);
            id15[idx] = std::move(id15[nextIdx]);
            idx = nextIdx;
            nextIdx = (idx + 1) & mMask;
        }

        mInfo[idx] = 0;
        

        

        id15[idx].~Node();
    }

    

    template <typename Other>
    size_t findIdx(Other const& key) const {
        size_t idx;
        InfoType info;
        id1(key, idx, info);

        do {
            

            if (info == mInfo[idx] && KeyEqual::operator()(key, id15[idx].getFirst())) {
                return idx;
            }
            next(&info, &idx);
            if (info == mInfo[idx] && KeyEqual::operator()(key, id15[idx].getFirst())) {
                return idx;
            }
            next(&info, &idx);
        } while (info <= mInfo[idx]);

        

        return mMask + 1;
    }

    void cloneData(const unordered_map& o) {
        Cloner<unordered_map, id3 && std::is_trivially_copyable<Node>::value>()(o, *this);
    }

    

    

    size_t insert_move(Node&& keyval) {
        

        

        if (0 == id24 && !try_increase_info()) {
            throwOverflowError();
        }

        size_t idx;
        InfoType info;
        id1(keyval.getFirst(), idx, info);

        

        while (info <= mInfo[idx]) {
            idx = (idx + 1) & mMask;
            info = static_cast<InfoType>(info + id16);
        }

        

        auto const id9 = idx;
        auto const id11 = static_cast<uint8_t>(info);
        if (ROBIN_HOOD_UNLIKELY(id11 + id16 > 0xFF)) {
            id24 = 0;
        }

        

        while (0 != mInfo[idx]) {
            next(&info, &idx);
        }

        auto& l = id15[id9];
        if (idx == id9) {
            ::new (static_cast<void*>(&l)) Node(std::move(keyval));
        } else {
            shiftUp(idx, id9);
            l = std::move(keyval);
        }

        

        mInfo[id9] = id11;

        ++id21;
        return id9;
    }

public:
    using iterator = Iter<false>;
    using const_iterator = Iter<true>;

    

    

    

    

    

    explicit unordered_map(size_t id25(bucket_count)  = 0,
                           const Hash& h = Hash{}, const KeyEqual& equal = KeyEqual{})
        : Hash{h}
        , KeyEqual{equal} {}

    template <typename Iter>
    unordered_map(Iter first, Iter last, size_t id25(bucket_count)  = 0,
                  const Hash& h = Hash{}, const KeyEqual& equal = KeyEqual{})
        : Hash{h}
        , KeyEqual{equal} {
        insert(first, last);
    }

    unordered_map(std::initializer_list<value_type> init,
                  size_t id25(bucket_count)  = 0, const Hash& h = Hash{},
                  const KeyEqual& equal = KeyEqual{})
        : Hash{h}
        , KeyEqual{equal} {
        insert(init.begin(), init.end());
    }

    unordered_map(unordered_map&& o)
        : Hash{std::move(static_cast<Hash&>(o))}
        , KeyEqual{std::move(static_cast<KeyEqual&>(o))}
        , DataPool{std::move(static_cast<DataPool&>(o))}
        , id15{std::move(o.id15)}
        , mInfo{std::move(o.mInfo)}
        , id21{std::move(o.id21)}
        , mMask{std::move(o.mMask)}
        , id24{std::move(o.id24)}
        , id16{std::move(o.id16)}
        , id23{std::move(o.id23)} {
        

        o.mMask = 0;
    }

    unordered_map& operator=(unordered_map&& o) {
        if (&o != this) {
            

            destroy();
            id15 = std::move(o.id15);
            mInfo = std::move(o.mInfo);
            id21 = std::move(o.id21);
            mMask = std::move(o.mMask);
            id24 = std::move(o.id24);
            id16 = std::move(o.id16);
            id23 = std::move(o.id23);
            Hash::operator=(std::move(static_cast<Hash&>(o)));
            KeyEqual::operator=(std::move(static_cast<KeyEqual&>(o)));
            DataPool::operator=(std::move(static_cast<DataPool&>(o)));
            

            o.mMask = 0;
        }
        return *this;
    }

    unordered_map(const unordered_map& o)
        : Hash{static_cast<const Hash&>(o)}
        , KeyEqual{static_cast<const KeyEqual&>(o)}
        , DataPool{static_cast<const DataPool&>(o)} {

        if (!o.empty()) {
            

            


            id15 = static_cast<Node*>(
                detail::id5<std::bad_alloc>(malloc(calcNumBytesTotal(o.mMask + 1))));
            

            mInfo = reinterpret_cast<uint8_t*>(id15 + o.mMask + 1);
            id21 = o.id21;
            mMask = o.mMask;
            id24 = o.id24;
            id16 = o.id16;
            id23 = o.id23;
            cloneData(o);
        }
    }

    

    unordered_map& operator=(unordered_map const& o) {
        if (&o == this) {
            

            return *this;
        }

        

        

        if (o.empty()) {
            if (0 == mMask) {
                

                return *this;
            }

            

            

            destroy();

            

            using detail::DummyInfoByte::b;
            id15 = reinterpret_cast<Node*>(&b) - 1; 

            mInfo = reinterpret_cast<uint8_t*>(&b);
            Hash::operator=(static_cast<const Hash&>(o));
            KeyEqual::operator=(static_cast<const KeyEqual&>(o));
            DataPool::operator=(static_cast<DataPool const&>(o));
            id21 = 0;
            mMask = 0;
            id24 = 0;
            id16 = id12;
            id23 = id22;
            return *this;
        }

        

        Destroyer<Self, id3 && std::is_trivially_destructible<Node>::value>{}.nodes(*this);

        if (mMask != o.mMask) {
            

            if (0 != mMask) {
                

                free(id15);
            }

            id15 = static_cast<Node*>(
                detail::id5<std::bad_alloc>(malloc(calcNumBytesTotal(o.mMask + 1))));

            

            mInfo = reinterpret_cast<uint8_t*>(id15 + o.mMask + 1);
            id16 = o.id16;
            id23 = o.id23;
            

        }
        Hash::operator=(static_cast<const Hash&>(o));
        KeyEqual::operator=(static_cast<const KeyEqual&>(o));
        id21 = o.id21;
        mMask = o.mMask;
        id24 = o.id24;
        cloneData(o);

        return *this;
    }

    

    void swap(unordered_map& o) {
        using std::swap;
        swap(id15, o.id15);
        swap(mInfo, o.mInfo);
        swap(id21, o.id21);
        swap(mMask, o.mMask);
        swap(id24, o.id24);
        swap(id16, o.id16);
        swap(id23, o.id23);
        swap(static_cast<Hash&>(*this), static_cast<Hash&>(o));
        swap(static_cast<KeyEqual&>(*this), static_cast<KeyEqual&>(o));
        

        swap(static_cast<DataPool&>(*this), static_cast<DataPool&>(o));
    }

    

    void clear() {
        if (empty()) {
            

            

            return;
        }

        Destroyer<Self, id3 && std::is_trivially_destructible<Node>::value>{}.nodes(*this);

        

        

        uint8_t const z = 0;
        std::fill(mInfo, mInfo + (sizeof(uint8_t) * (mMask + 1)), z);

        id16 = id12;
        id23 = id22;
    }

    

    ~unordered_map() {
        destroy();
    }

    

    bool operator==(const unordered_map& other) const {
        if (other.size() != size()) {
            return false;
        }
        for (auto const& otherEntry : other) {
            auto const myIt = find(otherEntry.first);
            if (myIt == end() || !(myIt->second == otherEntry.second)) {
                return false;
            }
        }

        return true;
    }

    bool operator!=(const unordered_map& other) const {
        return !operator==(other);
    }

    mapped_type& operator[](const key_type& key) {
        return id20(key);
    }

    mapped_type& operator[](key_type&& key) {
        return id20(std::move(key));
    }

    template <typename Iter>
    void insert(Iter first, Iter last) {
        for (; first != last; ++first) {
            

            insert(value_type(*first));
        }
    }

    template <typename... Args>
    std::pair<iterator, bool> emplace(Args&&... args) {
        Node n{*this, std::forward<Args>(args)...};
        auto r = doInsert(std::move(n));
        if (!r.second) {
            

            n.destroy(*this);
        }
        return r;
    }

    std::pair<iterator, bool> insert(const value_type& keyval) {
        return doInsert(keyval);
    }

    std::pair<iterator, bool> insert(value_type&& keyval) {
        return doInsert(std::move(keyval));
    }

    

    size_t count(const key_type& key) const {
        return findIdx(key) == (mMask + 1) ? 0 : 1;
    }

    

    

    mapped_type& at(key_type const& key) {
        auto idx = findIdx(key);
        if (idx == mMask + 1) {
            doThrow<std::out_of_range>("key not found");
        }
        return id15[idx].getSecond();
    }

    

    

    mapped_type const& at(key_type const& key) const {
        auto idx = findIdx(key);
        if (idx == mMask + 1) {
            doThrow<std::out_of_range>("key not found");
        }
        return id15[idx].getSecond();
    }

    const_iterator find(const key_type& key) const {
        const size_t idx = findIdx(key);
        return const_iterator{id15 + idx, mInfo + idx};
    }

    template <typename OtherKey>
    const_iterator find(const OtherKey& key, is_transparent_tag ) const {
        const size_t idx = findIdx(key);
        return const_iterator{id15 + idx, mInfo + idx};
    }

    iterator find(const key_type& key) {
        const size_t idx = findIdx(key);
        return iterator{id15 + idx, mInfo + idx};
    }

    template <typename OtherKey>
    iterator find(const OtherKey& key, is_transparent_tag ) {
        const size_t idx = findIdx(key);
        return iterator{id15 + idx, mInfo + idx};
    }

    iterator begin() {
        if (empty()) {
            return end();
        }
        return ++iterator(id15 - 1, mInfo - 1);
    }
    const_iterator begin() const {
        return cbegin();
    }
    const_iterator cbegin() const {
        if (empty()) {
            return cend();
        }
        return ++const_iterator(id15 - 1, mInfo - 1);
    }

    iterator end() {
        

        

        return iterator{reinterpret_cast<Node*>(mInfo), nullptr};
    }
    const_iterator end() const {
        return cend();
    }
    const_iterator cend() const {
        return const_iterator{reinterpret_cast<Node*>(mInfo), nullptr};
    }

    iterator erase(const_iterator pos) {
        

        return erase(iterator{const_cast<Node*>(pos.id15), const_cast<uint8_t*>(pos.mInfo)});
    }

    

    iterator erase(iterator pos) {
        

        auto const idx = static_cast<size_t>(pos.id15 - id15);

        shiftDown(idx);
        --id21;

        if (*pos.mInfo) {
            

            return pos;
        }

        

        return ++pos;
    }

    size_t erase(const key_type& key) {
        size_t idx;
        InfoType info;
        id1(key, idx, info);

        

        do {
            if (info == mInfo[idx] && KeyEqual::operator()(key, id15[idx].getFirst())) {
                shiftDown(idx);
                --id21;
                return 1;
            }
            next(&info, &idx);
        } while (info <= mInfo[idx]);

        

        return 0;
    }

    void reserve(size_t count) {
        auto newSize = InitialNumElements > mMask + 1 ? InitialNumElements : mMask + 1;
        while (calcMaxNumElementsAllowed(newSize) < count && newSize != 0) {
            newSize *= 2;
        }
        if (ROBIN_HOOD_UNLIKELY(newSize == 0)) {
            throwOverflowError();
        }

        rehash(newSize);
    }

    void rehash(size_t numBuckets) {
        if (ROBIN_HOOD_UNLIKELY((numBuckets & (numBuckets - 1)) != 0)) {
            doThrow<std::runtime_error>("rehash only allowed for power of two");
        }

        Node* const oldKeyVals = id15;
        uint8_t const* const oldInfo = mInfo;

        const size_t id14 = mMask + 1;

        

        init_data(numBuckets);
        if (id14 > 1) {
            for (size_t i = 0; i < id14; ++i) {
                if (oldInfo[i] != 0) {
                    insert_move(std::move(oldKeyVals[i]));
                    

                    oldKeyVals[i].~Node();
                }
            }

            

            DataPool::addOrFree(oldKeyVals, calcNumBytesTotal(id14));
        }
    }

    size_type size() const {
        return id21;
    }

    size_type max_size() const {
        return static_cast<size_type>(-1);
    }

    bool empty() const {
        return 0 == id21;
    }

    float max_load_factor() const {
        return id4 / 100.0f;
    }

    

    float load_factor() const {
        return static_cast<float>(size()) / (mMask + 1);
    }

    size_t mask() const {
        return mMask;
    }

private:
    ROBIN_HOOD_NOINLINE void throwOverflowError() const {
        throw std::overflow_error("robin_hood::map overflow");
    }

    void init_data(size_t max_elements) {
        id21 = 0;
        mMask = max_elements - 1;
        id24 = calcMaxNumElementsAllowed(max_elements);

        

        id15 = reinterpret_cast<Node*>(
            detail::id5<std::bad_alloc>(calloc(1, calcNumBytesTotal(max_elements))));
        mInfo = reinterpret_cast<uint8_t*>(id15 + max_elements);

        

        mInfo[max_elements] = 1;

        id16 = id12;
        id23 = id22;
    }

    template <typename Arg>
    mapped_type& id20(Arg&& key) {
        while (true) {
            size_t idx;
            InfoType info;
            id1(key, idx, info);
            nextWhileLess(&info, &idx);

            

            

            while (info == mInfo[idx]) {
                if (KeyEqual::operator()(key, id15[idx].getFirst())) {
                    

                    return id15[idx].getSecond();
                }
                next(&info, &idx);
            }

            

            if (ROBIN_HOOD_UNLIKELY(id21 >= id24)) {
                increase_size();
                continue;
            }

            

            auto const id9 = idx;
            auto const id11 = info;
            if (ROBIN_HOOD_UNLIKELY(id11 + id16 > 0xFF)) {
                id24 = 0;
            }

            

            while (0 != mInfo[idx]) {
                next(&info, &idx);
            }

            auto& l = id15[id9];
            if (idx == id9) {
                

                

                ::new (static_cast<void*>(&l))
                    Node(*this, std::piecewise_construct,
                         std::forward_as_tuple(std::forward<Arg>(key)), std::forward_as_tuple());
            } else {
                shiftUp(idx, id9);
                l = Node(*this, std::piecewise_construct,
                         std::forward_as_tuple(std::forward<Arg>(key)), std::forward_as_tuple());
            }

            

            mInfo[id9] = static_cast<uint8_t>(id11);

            ++id21;
            return id15[id9].getSecond();
        }
    }

    

    template <typename Arg>
    std::pair<iterator, bool> doInsert(Arg&& keyval) {
        while (true) {
            size_t idx;
            InfoType info;
            id1(keyval.getFirst(), idx, info);
            nextWhileLess(&info, &idx);

            

            while (info == mInfo[idx]) {
                if (KeyEqual::operator()(keyval.getFirst(), id15[idx].getFirst())) {
                    

                    

                    return std::make_pair<iterator, bool>(iterator(id15 + idx, mInfo + idx),
                                                          false);
                }
                next(&info, &idx);
            }

            

            if (ROBIN_HOOD_UNLIKELY(id21 >= id24)) {
                increase_size();
                continue;
            }

            

            auto const id9 = idx;
            auto const id11 = info;
            if (ROBIN_HOOD_UNLIKELY(id11 + id16 > 0xFF)) {
                id24 = 0;
            }

            

            while (0 != mInfo[idx]) {
                next(&info, &idx);
            }

            auto& l = id15[id9];
            if (idx == id9) {
                ::new (static_cast<void*>(&l)) Node(*this, std::forward<Arg>(keyval));
            } else {
                shiftUp(idx, id9);
                l = Node(*this, std::forward<Arg>(keyval));
            }

            

            mInfo[id9] = static_cast<uint8_t>(id11);

            ++id21;
            return std::make_pair(iterator(id15 + id9, mInfo + id9), true);
        }
    }

    size_t calcMaxNumElementsAllowed(size_t maxElements) {
        static constexpr size_t overflowLimit = (std::numeric_limits<size_t>::max)() / 100;
        static constexpr double factor = id4 / 100.0;

        

        if (maxElements > overflowLimit) {
            return static_cast<size_t>(static_cast<double>(maxElements) * factor);
        } else {
            return (maxElements * id4) / 100;
        }
    }

    bool try_increase_info() {
        ROBIN_HOOD_LOG("id16=" << id16 << ", numElements=" << id21
                                   << ", id6="
                                   << calcMaxNumElementsAllowed(mMask + 1));
        

        id16 = static_cast<uint8_t>(id16 >> 1);
        if (1 == id16) {
            

            return false;
        }

        

        

        ++id23;
        auto const data = reinterpret_cast<uint64_t*>(mInfo);
        auto const numEntries = (mMask + 1) / 8;

        for (size_t i = 0; i < numEntries; ++i) {
            data[i] = (data[i] >> 1) & UINT64_C(0x7f7f7f7f7f7f7f7f);
        }
        id24 = calcMaxNumElementsAllowed(mMask + 1);
        return true;
    }

    void increase_size() {
        

        if (0 == mMask) {
            init_data(InitialNumElements);
            return;
        }

        auto const id6 = calcMaxNumElementsAllowed(mMask + 1);
        if (id21 < id6 && try_increase_info()) {
            return;
        }

        ROBIN_HOOD_LOG("id21=" << id21 << ", id6="
                                       << id6 << ", load="
                                       << (static_cast<double>(id21) * 100.0 /
                                           (static_cast<double>(mMask) + 1)));
        

        if (id21 * 2 < calcMaxNumElementsAllowed(mMask + 1)) {
            throwOverflowError();
        }

        rehash((mMask + 1) * 2);
    }

    void destroy() {
        if (0 == mMask) {
            

            return;
        }

        Destroyer<Self, id3 && std::is_trivially_destructible<Node>::value>{}
            .nodesDoNotDeallocate(*this);
        free(id15);
    }

    

    Node* id15 = reinterpret_cast<Node*>(reinterpret_cast<uint8_t*>(&detail::DummyInfoByte::b) -
                                             sizeof(Node));                 

    uint8_t* mInfo = reinterpret_cast<uint8_t*>(&detail::DummyInfoByte::b); 

    size_t id21 = 0;                                                

    size_t mMask = 0;                                                       

    size_t id24 = 0;                                      

    InfoType id16 = id12;                                     

    InfoType id23 = id22;                         

                                                    

};

} 


template <typename Key, typename T, typename Hash = hash<Key>,
          typename KeyEqual = std::equal_to<Key>, size_t id4 = 80>
using unordered_flat_map = detail::unordered_map<true, id4, Key, T, Hash, KeyEqual>;

template <typename Key, typename T, typename Hash = hash<Key>,
          typename KeyEqual = std::equal_to<Key>, size_t id4 = 80>
using unordered_node_map = detail::unordered_map<false, id4, Key, T, Hash, KeyEqual>;

template <typename Key, typename T, typename Hash = hash<Key>,
          typename KeyEqual = std::equal_to<Key>, size_t id4 = 80>
using unordered_map =
    detail::unordered_map<sizeof(robin_hood::pair<Key, T>) <= sizeof(size_t) * 6 &&
                              std::is_nothrow_move_constructible<robin_hood::pair<Key, T>>::value &&
                              std::is_nothrow_move_assignable<robin_hood::pair<Key, T>>::value,
                          id4, Key, T, Hash, KeyEqual>;

} 




using namespace std;

typedef long long ll;
const ll INF = 1e15 + 21;
const ll MAXN = 1e5 + 5;
typedef pair<ll, ll> pii;

ll N, Q;
ll V[MAXN];
ll C[MAXN];
ll dp[MAXN];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    for (ll i = 0; i < N; i++) {
        cin >> V[i];
    }
    for (ll i = 0; i < N; i++) {
        cin >> C[i];
    }
    robin_hood::unordered_map<ll, ll> curMax;
    for (int i = 0; i < N; i++) {
        curMax[C[i]] = -INF;
    }
    for (ll i = 0; i < Q; i++) {
        for (auto j : curMax) {
            curMax[j.first] = -INF;
        }
        ll a, b;
        cin >> a >> b;
        fill(dp, dp + N, -1);
        pii mx1 = {0, 1e5 + 5};
        pii mx2 = {0, 1e5 + 4};
        for (ll j = 0; j < N; j++) {
            if (mx1.second == C[j]) {
                dp[j] = mx2.first + b * V[j];
            } else {
                dp[j] = mx1.first + b * V[j];
            }
            dp[j] = max(dp[j], curMax[C[j]] + a * V[j]);
            if (dp[j] > mx1.first) {
                if (C[j] == mx1.second) {
                    mx1 = {dp[j], C[j]};
                } else {
                    mx2 = {mx1.first, mx1.second};
                    mx1 = {dp[j], C[j]};
                }
            } else if (dp[j] > mx2.first) {
                if (C[j] == mx1.second) {
                    continue;
                } else {
                    mx2 = {dp[j], C[j]};
                }
            }
            curMax[C[j]] = max(curMax[C[j]], dp[j]);
        }
        cout << mx1.first << endl;
    }
}