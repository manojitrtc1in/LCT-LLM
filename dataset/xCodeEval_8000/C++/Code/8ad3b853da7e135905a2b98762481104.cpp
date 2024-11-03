#pragma GCC optimize("O3")
#include <bits/stdc++.h>


































































#ifndef ROBIN_HOOD_H_INCLUDED
#define ROBIN_HOOD_H_INCLUDED



#define ROBIN_HOOD_VERSION_MAJOR 3 

#define ROBIN_HOOD_VERSION_MINOR 2 

#define ROBIN_HOOD_VERSION_PATCH 2 


#include <algorithm>
#include <cstring>
#include <functional>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>



#ifdef ROBIN_HOOD_LOG_ENABLED
#    include <iostream>
#    define ROBIN_HOOD_LOG(x) std::cout << __FUNCTION__ << "@" << __LINE__ << ": " << x << std::endl
#else
#    define ROBIN_HOOD_LOG(x)
#endif



#define ROBIN_HOOD_UNUSED(identifier)



#if SIZE_MAX == UINT32_MAX
#    define ROBIN_HOOD_BITNESS 32
#elif SIZE_MAX == UINT64_MAX
#    define ROBIN_HOOD_BITNESS 64
#else
#    error Unsupported bitness
#endif



#ifdef _WIN32
#    define ROBIN_HOOD_LITTLE_ENDIAN 1
#    define ROBIN_HOOD_BIG_ENDIAN 0
#else
#    if __GNUC__ >= 4
#        define ROBIN_HOOD_LITTLE_ENDIAN (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
#        define ROBIN_HOOD_BIG_ENDIAN (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
#    else
#        error cannot determine endianness
#    endif
#endif



#ifdef _WIN32
#    define ROBIN_HOOD_NOINLINE __declspec(noinline)
#else
#    if __GNUC__ >= 4
#        define ROBIN_HOOD_NOINLINE __attribute__((noinline))
#    else
#        define ROBIN_HOOD_NOINLINE
#    endif
#endif



#ifdef _WIN32
#    if ROBIN_HOOD_BITNESS == 32
#        define ROBIN_HOOD_BITSCANFORWARD _BitScanForward
#    else
#        define ROBIN_HOOD_BITSCANFORWARD _BitScanForward64
#    endif
#    include <intrin.h>
#    pragma intrinsic(ROBIN_HOOD_BITSCANFORWARD)
#    define ROBIN_HOOD_COUNT_TRAILING_ZEROES(x)                                          \
        [](size_t mask) -> int {                                                         \
            unsigned long index;                                                         \
            return ROBIN_HOOD_BITSCANFORWARD(&index, mask) ? index : ROBIN_HOOD_BITNESS; \
        }(x)
#else
#    if __GNUC__ >= 4
#        if ROBIN_HOOD_BITNESS == 32
#            define ROBIN_HOOD_CTZ(x) __builtin_ctzl(x)
#            define ROBIN_HOOD_CLZ(x) __builtin_clzl(x)
#        else
#            define ROBIN_HOOD_CTZ(x) __builtin_ctzll(x)
#            define ROBIN_HOOD_CLZ(x) __builtin_clzll(x)
#        endif
#        define ROBIN_HOOD_COUNT_LEADING_ZEROES(x) (x ? ROBIN_HOOD_CLZ(x) : ROBIN_HOOD_BITNESS)
#        define ROBIN_HOOD_COUNT_TRAILING_ZEROES(x) (x ? ROBIN_HOOD_CTZ(x) : ROBIN_HOOD_BITNESS)
#    else
#        error clz not supported
#    endif
#endif



namespace robin_hood {
namespace detail {
#if defined(__SIZEOF_INT128__)
#    define ROBIN_HOOD_UMULH(a, b) \
        static_cast<uint64_t>(     \
            (static_cast<unsigned __int128>(a) * static_cast<unsigned __int128>(b)) >> 64u)

#    define ROBIN_HOOD_HAS_UMUL128 1
inline uint64_t umul128(uint64_t a, uint64_t b, uint64_t* high) {
    auto result = static_cast<unsigned __int128>(a) * static_cast<unsigned __int128>(b);
    *high = static_cast<uint64_t>(result >> 64);
    return static_cast<uint64_t>(result);
}
#elif (defined(_WIN32) && ROBIN_HOOD_BITNESS == 64)
#    define ROBIN_HOOD_HAS_UMUL128 1
#    include <intrin.h> 

#    pragma intrinsic(__umulh)
#    pragma intrinsic(_umul128)
#    define ROBIN_HOOD_UMULH(a, b) __umulh(a, b)
inline uint64_t umul128(uint64_t a, uint64_t b, uint64_t* high) {
    return _umul128(a, b, high);
}
#endif
} 

} 




#if __GNUC__ >= 4
#    define ROBIN_HOOD_LIKELY(condition) __builtin_expect(static_cast<bool>(condition), 1)
#    define ROBIN_HOOD_UNLIKELY(condition) __builtin_expect(static_cast<bool>(condition), 0)
#else
#    define ROBIN_HOOD_LIKELY(condition) condition
#    define ROBIN_HOOD_UNLIKELY(condition) condition
#endif
namespace robin_hood {

namespace detail {





template <typename E, typename... Args>
static ROBIN_HOOD_NOINLINE void doThrow(Args&&... args) {
    throw E(std::forward<Args>(args)...);
}

template <typename E, typename T, typename... Args>
static T* assertNotNull(T* t, Args&&... args) {
    if (ROBIN_HOOD_UNLIKELY(nullptr == t)) {
        doThrow<E>(std::forward<Args>(args)...);
    }
    return t;
}

template <typename T>
inline T unaligned_load(void const* ptr) {
    

    

    T t;
    std::memcpy(&t, ptr, sizeof(T));
    return t;
}







template <typename T, size_t MinNumAllocs = 4, size_t MaxNumAllocs = 256>
class BulkPoolAllocator {
public:
    BulkPoolAllocator()
        : mHead(nullptr)
        , mListForFree(nullptr) {}

    

    BulkPoolAllocator(const BulkPoolAllocator& ROBIN_HOOD_UNUSED(o) )
        : mHead(nullptr)
        , mListForFree(nullptr) {}

    BulkPoolAllocator(BulkPoolAllocator&& o)
        : mHead(o.mHead)
        , mListForFree(o.mListForFree) {
        o.mListForFree = nullptr;
        o.mHead = nullptr;
    }

    BulkPoolAllocator& operator=(BulkPoolAllocator&& o) {
        reset();
        mHead = o.mHead;
        mListForFree = o.mListForFree;
        o.mListForFree = nullptr;
        o.mHead = nullptr;
        return *this;
    }

    BulkPoolAllocator& operator=(const BulkPoolAllocator& ROBIN_HOOD_UNUSED(o) ) {
        

        return *this;
    }

    ~BulkPoolAllocator() {
        reset();
    }

    

    void reset() {
        while (mListForFree) {
            T* tmp = *mListForFree;
            free(mListForFree);
            mListForFree = reinterpret_cast<T**>(tmp);
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

    void swap(BulkPoolAllocator<T, MinNumAllocs, MaxNumAllocs>& other) {
        using std::swap;
        swap(mHead, other.mHead);
        swap(mListForFree, other.mListForFree);
    }

private:
    

    

    

    

    size_t calcNumElementsToAlloc() const {
        auto tmp = mListForFree;
        size_t numAllocs = MinNumAllocs;

        while (numAllocs * 2 <= MaxNumAllocs && tmp) {
            auto x = reinterpret_cast<T***>(tmp);
            tmp = *x;
            numAllocs *= 2;
        }

        return numAllocs;
    }

    

    void add(void* ptr, const size_t numBytes) {
        const size_t numElements = (numBytes - ALIGNMENT) / ALIGNED_SIZE;

        auto data = reinterpret_cast<T**>(ptr);

        

        auto x = reinterpret_cast<T***>(data);
        *x = mListForFree;
        mListForFree = data;

        

        auto const headT = reinterpret_cast<T*>(reinterpret_cast<char*>(ptr) + ALIGNMENT);

        auto const head = reinterpret_cast<char*>(headT);

        

        for (size_t i = 0; i < numElements; ++i) {
            *reinterpret_cast<char**>(head + i * ALIGNED_SIZE) = head + (i + 1) * ALIGNED_SIZE;
        }

        

        *reinterpret_cast<T**>(head + (numElements - 1) * ALIGNED_SIZE) = mHead;
        mHead = headT;
    }

    

    

    ROBIN_HOOD_NOINLINE T* performAllocation() {
        size_t const numElementsToAlloc = calcNumElementsToAlloc();

        

        

        size_t const bytes = ALIGNMENT + ALIGNED_SIZE * numElementsToAlloc;
        add(assertNotNull<std::bad_alloc>(malloc(bytes)), bytes);
        return mHead;
    }

    

    static constexpr size_t ALIGNMENT =
        (std::max)(std::alignment_of<T>::value, std::alignment_of<T*>::value);
    static constexpr size_t ALIGNED_SIZE = ((sizeof(T) - 1) / ALIGNMENT + 1) * ALIGNMENT;

    static_assert(MinNumAllocs >= 1, "MinNumAllocs");
    static_assert(MaxNumAllocs >= MinNumAllocs, "MaxNumAllocs");
    static_assert(ALIGNED_SIZE >= sizeof(T*), "ALIGNED_SIZE");
    static_assert(0 == (ALIGNED_SIZE % sizeof(T*)), "ALIGNED_SIZE mod");
    static_assert(ALIGNMENT >= sizeof(T*), "ALIGNMENT");

    T* mHead;
    T** mListForFree;
};

template <typename T, size_t MinSize, size_t MaxSize, bool IsFlatMap>
struct NodeAllocator;



template <typename T, size_t MinSize, size_t MaxSize>
struct NodeAllocator<T, MinSize, MaxSize, true> {

    

    void addOrFree(void* ptr, size_t ROBIN_HOOD_UNUSED(numBytes) ) {
        free(ptr);
    }
};

template <typename T, size_t MinSize, size_t MaxSize>
struct NodeAllocator<T, MinSize, MaxSize, false> : public BulkPoolAllocator<T, MinSize, MaxSize> {};











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
        uint64_t k = detail::unaligned_load<uint64_t>(data64 + i);

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
#if defined(ROBIN_HOOD_HAS_UMUL128)
        

        static constexpr uint64_t k = UINT64_C(0xde5fb9d2630458e9);
        uint64_t h;
        uint64_t l = detail::umul128(obj, k, &h);
        return h + l;
#elif ROBIN_HOOD_BITNESS == 32
        static constexpr uint32_t k = UINT32_C(0x9a0ecda7);
        uint64_t const r = obj * k;
        uint32_t h = static_cast<uint32_t>(r >> 32);
        uint32_t l = static_cast<uint32_t>(r);
        return h + l;
#else
        

        uint64_t h = obj;
        h ^= h >> 33;
        h *= 0xff51afd7ed558ccd;
        h ^= h >> 33;
        h *= 0xc4ceb9fe1a85ec53;
        h ^= h >> 33;
        return static_cast<size_t>(h);
#endif
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
#if ROBIN_HOOD_BITNESS == 32
        return static_cast<size_t>((UINT64_C(0xca4bcaa75ec3f625) * (uint64_t)h) >> 32);
#else
        return hash<uint64_t>{}(static_cast<uint64_t>(h));
#endif
    }
};

template <>
struct hash<int32_t> {
    size_t operator()(int32_t const& obj) const {
        return hash<uint32_t>{}(static_cast<uint32_t>(obj));
    }
};

namespace detail {























































template <bool IsFlatMap, size_t MaxLoadFactor100, typename Key, typename T, typename Hash,
          typename KeyEqual>
class unordered_map
    : public Hash,
      public KeyEqual,
      detail::NodeAllocator<
          robin_hood::pair<typename std::conditional<IsFlatMap, Key, Key const>::type, T>, 4, 16384,
          IsFlatMap> {
public:
    using key_type = Key;
    using mapped_type = T;
    using value_type =
        robin_hood::pair<typename std::conditional<IsFlatMap, Key, Key const>::type, T>;
    using size_type = size_t;
    using hasher = Hash;
    using key_equal = KeyEqual;
    using Self =
        unordered_map<IsFlatMap, MaxLoadFactor100, key_type, mapped_type, hasher, key_equal>;
    static constexpr bool is_flat_map = IsFlatMap;

private:
    static_assert(MaxLoadFactor100 > 10 && MaxLoadFactor100 < 100,
                  "MaxLoadFactor100 needs to be >10 && < 100");

    


    

    static constexpr size_t InitialNumElements = sizeof(uint64_t);
    static constexpr int InitialInfoNumBits = 5;
    static constexpr uint8_t InitialInfoInc = 1 << InitialInfoNumBits;
    static constexpr uint8_t InitialInfoHashShift = sizeof(size_t) * 8 - InitialInfoNumBits;
    using DataPool = detail::NodeAllocator<value_type, 4, 16384, IsFlatMap>;

    

    using InfoType = int32_t;

    


    

    

    

    template <typename M, bool>
    class DataNode {};

    

    template <typename M>
    class DataNode<M, true> {
    public:
        template <typename... Args>
        explicit DataNode(M& ROBIN_HOOD_UNUSED(map) , Args&&... args)
            : mData(std::forward<Args>(args)...) {}

        DataNode(M& ROBIN_HOOD_UNUSED(map) , DataNode<M, true>&& n)
            : mData(std::move(n.mData)) {}

        

        void destroy(M& ROBIN_HOOD_UNUSED(map) ) {}
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

        DataNode(M& ROBIN_HOOD_UNUSED(map) , DataNode<M, false>&& n)
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

    using Node = DataNode<Self, IsFlatMap>;

    


    template <typename M, bool UseMemcpy>
    struct Cloner;

    

    template <typename M>
    struct Cloner<M, true> {
        void operator()(M const& source, M& target) const {
            

            

            auto src = reinterpret_cast<char const*>(source.mKeyVals);
            auto tgt = reinterpret_cast<char*>(target.mKeyVals);
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
                    ::new (static_cast<void*>(target.mKeyVals + i))
                        Node(target, *source.mKeyVals[i]);
                }
            }
        }
    };

    


    template <typename M, bool IsFlatMapAndTrivial>
    struct Destroyer {};

    template <typename M>
    struct Destroyer<M, true> {
        void nodes(M& m) const {
            m.mNumElements = 0;
        }

        void nodesDoNotDeallocate(M& m) const {
            m.mNumElements = 0;
        }
    };

    template <typename M>
    struct Destroyer<M, false> {
        void nodes(M& m) const {
            m.mNumElements = 0;
            

            for (size_t idx = 0; idx <= m.mMask; ++idx) {
                if (0 != m.mInfo[idx]) {
                    Node& n = m.mKeyVals[idx];
                    n.destroy(m);
                    n.~Node();
                }
            }
        }

        void nodesDoNotDeallocate(M& m) const {
            m.mNumElements = 0;
            

            for (size_t idx = 0; idx <= m.mMask; ++idx) {
                if (0 != m.mInfo[idx]) {
                    Node& n = m.mKeyVals[idx];
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
            : mKeyVals(nullptr)
            , mInfo(nullptr) {}

        

        Iter(Iter<false> const& other)
            : mKeyVals(other.mKeyVals)
            , mInfo(other.mInfo) {}

        Iter(NodePtr valPtr, uint8_t const* infoPtr)
            : mKeyVals(valPtr)
            , mInfo(infoPtr) {}

        

        Iter& operator++() {
            mInfo++;
            mKeyVals++;
            int inc;
            do {
                auto const n = detail::unaligned_load<size_t>(mInfo);
#if ROBIN_HOOD_LITTLE_ENDIAN
                inc = ROBIN_HOOD_COUNT_TRAILING_ZEROES(n) / 8;
#else
                inc = ROBIN_HOOD_COUNT_LEADING_ZEROES(n) / 8;
#endif
                mInfo += inc;
                mKeyVals += inc;
            } while (inc == sizeof(size_t));
            return *this;
        }

        reference operator*() const {
            return **mKeyVals;
        }

        pointer operator->() const {
            return &**mKeyVals;
        }

        template <bool O>
        bool operator==(Iter<O> const& o) const {
            return mKeyVals == o.mKeyVals;
        }

        template <bool O>
        bool operator!=(Iter<O> const& o) const {
            return mKeyVals != o.mKeyVals;
        }

    private:
        friend class unordered_map<IsFlatMap, MaxLoadFactor100, key_type, mapped_type, hasher,
                                   key_equal>;
        NodePtr mKeyVals;
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
    void keyToIdx(HashKey&& key, size_t& idx, InfoType& info) const {
        static constexpr size_t bad_hash_prevention =
            std::is_same<::robin_hood::hash<key_type>, hasher>::value
                ? 1
                : (ROBIN_HOOD_BITNESS == 64 ? UINT64_C(0xb3727c1f779b8d8b) : UINT32_C(0xda4afe47));
        idx = Hash::operator()(key) * bad_hash_prevention;
        info = static_cast<InfoType>(mInfoInc + static_cast<InfoType>(idx >> mInfoHashShift));
        idx &= mMask;
    }

    

    void next(InfoType* info, size_t* idx) const {
        *idx = (*idx + 1) & mMask;
        *info = static_cast<InfoType>(*info + mInfoInc);
    }

    void nextWhileLess(InfoType* info, size_t* idx) const {
        

        while (*info < mInfo[*idx]) {
            next(info, idx);
        }
    }

    

    

    

    void shiftUp(size_t idx, size_t const insertion_idx) {
        while (idx != insertion_idx) {
            size_t prev_idx = (idx - 1) & mMask;
            if (mInfo[idx]) {
                mKeyVals[idx] = std::move(mKeyVals[prev_idx]);
            } else {
                ::new (static_cast<void*>(mKeyVals + idx)) Node(std::move(mKeyVals[prev_idx]));
            }
            mInfo[idx] = static_cast<uint8_t>(mInfo[prev_idx] + mInfoInc);
            if (ROBIN_HOOD_UNLIKELY(mInfo[idx] + mInfoInc > 0xFF)) {
                mMaxNumElementsAllowed = 0;
            }
            idx = prev_idx;
        }
    }

    void shiftDown(size_t idx) {
        

        

        mKeyVals[idx].destroy(*this);

        

        size_t nextIdx = (idx + 1) & mMask;
        while (mInfo[nextIdx] >= 2 * mInfoInc) {
            mInfo[idx] = static_cast<uint8_t>(mInfo[nextIdx] - mInfoInc);
            mKeyVals[idx] = std::move(mKeyVals[nextIdx]);
            idx = nextIdx;
            nextIdx = (idx + 1) & mMask;
        }

        mInfo[idx] = 0;
        

        

        mKeyVals[idx].~Node();
    }

    

    template <typename Other>
    size_t findIdx(Other const& key) const {
        size_t idx;
        InfoType info;
        keyToIdx(key, idx, info);

        do {
            

            if (info == mInfo[idx] && KeyEqual::operator()(key, mKeyVals[idx].getFirst())) {
                return idx;
            }
            next(&info, &idx);
            if (info == mInfo[idx] && KeyEqual::operator()(key, mKeyVals[idx].getFirst())) {
                return idx;
            }
            next(&info, &idx);
        } while (info <= mInfo[idx]);

        

        return mMask + 1;
    }

    void cloneData(const unordered_map& o) {
        Cloner<unordered_map, IsFlatMap && std::is_trivially_copyable<Node>::value>()(o, *this);
    }

    

    

    size_t insert_move(Node&& keyval) {
        

        

        if (0 == mMaxNumElementsAllowed && !try_increase_info()) {
            throwOverflowError();
        }

        size_t idx;
        InfoType info;
        keyToIdx(keyval.getFirst(), idx, info);

        

        while (info <= mInfo[idx]) {
            idx = (idx + 1) & mMask;
            info = static_cast<InfoType>(info + mInfoInc);
        }

        

        auto const insertion_idx = idx;
        auto const insertion_info = static_cast<uint8_t>(info);
        if (ROBIN_HOOD_UNLIKELY(insertion_info + mInfoInc > 0xFF)) {
            mMaxNumElementsAllowed = 0;
        }

        

        while (0 != mInfo[idx]) {
            next(&info, &idx);
        }

        auto& l = mKeyVals[insertion_idx];
        if (idx == insertion_idx) {
            ::new (static_cast<void*>(&l)) Node(std::move(keyval));
        } else {
            shiftUp(idx, insertion_idx);
            l = std::move(keyval);
        }

        

        mInfo[insertion_idx] = insertion_info;

        ++mNumElements;
        return insertion_idx;
    }

public:
    using iterator = Iter<false>;
    using const_iterator = Iter<true>;

    

    

    

    

    

    explicit unordered_map(size_t ROBIN_HOOD_UNUSED(bucket_count)  = 0,
                           const Hash& h = Hash{}, const KeyEqual& equal = KeyEqual{})
        : Hash{h}
        , KeyEqual{equal} {}

    template <typename Iter>
    unordered_map(Iter first, Iter last, size_t ROBIN_HOOD_UNUSED(bucket_count)  = 0,
                  const Hash& h = Hash{}, const KeyEqual& equal = KeyEqual{})
        : Hash{h}
        , KeyEqual{equal} {
        insert(first, last);
    }

    unordered_map(std::initializer_list<value_type> init,
                  size_t ROBIN_HOOD_UNUSED(bucket_count)  = 0, const Hash& h = Hash{},
                  const KeyEqual& equal = KeyEqual{})
        : Hash{h}
        , KeyEqual{equal} {
        insert(init.begin(), init.end());
    }

    unordered_map(unordered_map&& o)
        : Hash{std::move(static_cast<Hash&>(o))}
        , KeyEqual{std::move(static_cast<KeyEqual&>(o))}
        , DataPool{std::move(static_cast<DataPool&>(o))}
        , mKeyVals{std::move(o.mKeyVals)}
        , mInfo{std::move(o.mInfo)}
        , mNumElements{std::move(o.mNumElements)}
        , mMask{std::move(o.mMask)}
        , mMaxNumElementsAllowed{std::move(o.mMaxNumElementsAllowed)}
        , mInfoInc{std::move(o.mInfoInc)}
        , mInfoHashShift{std::move(o.mInfoHashShift)} {
        

        o.mMask = 0;
    }

    unordered_map& operator=(unordered_map&& o) {
        if (&o != this) {
            

            destroy();
            mKeyVals = std::move(o.mKeyVals);
            mInfo = std::move(o.mInfo);
            mNumElements = std::move(o.mNumElements);
            mMask = std::move(o.mMask);
            mMaxNumElementsAllowed = std::move(o.mMaxNumElementsAllowed);
            mInfoInc = std::move(o.mInfoInc);
            mInfoHashShift = std::move(o.mInfoHashShift);
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
            

            


            mKeyVals = static_cast<Node*>(
                detail::assertNotNull<std::bad_alloc>(malloc(calcNumBytesTotal(o.mMask + 1))));
            

            mInfo = reinterpret_cast<uint8_t*>(mKeyVals + o.mMask + 1);
            mNumElements = o.mNumElements;
            mMask = o.mMask;
            mMaxNumElementsAllowed = o.mMaxNumElementsAllowed;
            mInfoInc = o.mInfoInc;
            mInfoHashShift = o.mInfoHashShift;
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
            mKeyVals = reinterpret_cast<Node*>(&b) - 1; 

            mInfo = reinterpret_cast<uint8_t*>(&b);
            Hash::operator=(static_cast<const Hash&>(o));
            KeyEqual::operator=(static_cast<const KeyEqual&>(o));
            DataPool::operator=(static_cast<DataPool const&>(o));
            mNumElements = 0;
            mMask = 0;
            mMaxNumElementsAllowed = 0;
            mInfoInc = InitialInfoInc;
            mInfoHashShift = InitialInfoHashShift;
            return *this;
        }

        

        Destroyer<Self, IsFlatMap && std::is_trivially_destructible<Node>::value>{}.nodes(*this);

        if (mMask != o.mMask) {
            

            if (0 != mMask) {
                

                free(mKeyVals);
            }

            mKeyVals = static_cast<Node*>(
                detail::assertNotNull<std::bad_alloc>(malloc(calcNumBytesTotal(o.mMask + 1))));

            

            mInfo = reinterpret_cast<uint8_t*>(mKeyVals + o.mMask + 1);
            mInfoInc = o.mInfoInc;
            mInfoHashShift = o.mInfoHashShift;
            

        }
        Hash::operator=(static_cast<const Hash&>(o));
        KeyEqual::operator=(static_cast<const KeyEqual&>(o));
        mNumElements = o.mNumElements;
        mMask = o.mMask;
        mMaxNumElementsAllowed = o.mMaxNumElementsAllowed;
        cloneData(o);

        return *this;
    }

    

    void swap(unordered_map& o) {
        using std::swap;
        swap(mKeyVals, o.mKeyVals);
        swap(mInfo, o.mInfo);
        swap(mNumElements, o.mNumElements);
        swap(mMask, o.mMask);
        swap(mMaxNumElementsAllowed, o.mMaxNumElementsAllowed);
        swap(mInfoInc, o.mInfoInc);
        swap(mInfoHashShift, o.mInfoHashShift);
        swap(static_cast<Hash&>(*this), static_cast<Hash&>(o));
        swap(static_cast<KeyEqual&>(*this), static_cast<KeyEqual&>(o));
        

        swap(static_cast<DataPool&>(*this), static_cast<DataPool&>(o));
    }

    

    void clear() {
        if (empty()) {
            

            

            return;
        }

        Destroyer<Self, IsFlatMap && std::is_trivially_destructible<Node>::value>{}.nodes(*this);

        

        

        uint8_t const z = 0;
        std::fill(mInfo, mInfo + (sizeof(uint8_t) * (mMask + 1)), z);

        mInfoInc = InitialInfoInc;
        mInfoHashShift = InitialInfoHashShift;
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
        return doCreateByKey(key);
    }

    mapped_type& operator[](key_type&& key) {
        return doCreateByKey(std::move(key));
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
        return mKeyVals[idx].getSecond();
    }

    

    

    mapped_type const& at(key_type const& key) const {
        auto idx = findIdx(key);
        if (idx == mMask + 1) {
            doThrow<std::out_of_range>("key not found");
        }
        return mKeyVals[idx].getSecond();
    }

    const_iterator find(const key_type& key) const {
        const size_t idx = findIdx(key);
        return const_iterator{mKeyVals + idx, mInfo + idx};
    }

    template <typename OtherKey>
    const_iterator find(const OtherKey& key, is_transparent_tag ) const {
        const size_t idx = findIdx(key);
        return const_iterator{mKeyVals + idx, mInfo + idx};
    }

    iterator find(const key_type& key) {
        const size_t idx = findIdx(key);
        return iterator{mKeyVals + idx, mInfo + idx};
    }

    template <typename OtherKey>
    iterator find(const OtherKey& key, is_transparent_tag ) {
        const size_t idx = findIdx(key);
        return iterator{mKeyVals + idx, mInfo + idx};
    }

    iterator begin() {
        if (empty()) {
            return end();
        }
        return ++iterator(mKeyVals - 1, mInfo - 1);
    }
    const_iterator begin() const {
        return cbegin();
    }
    const_iterator cbegin() const {
        if (empty()) {
            return cend();
        }
        return ++const_iterator(mKeyVals - 1, mInfo - 1);
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
        

        return erase(iterator{const_cast<Node*>(pos.mKeyVals), const_cast<uint8_t*>(pos.mInfo)});
    }

    

    iterator erase(iterator pos) {
        

        auto const idx = static_cast<size_t>(pos.mKeyVals - mKeyVals);

        shiftDown(idx);
        --mNumElements;

        if (*pos.mInfo) {
            

            return pos;
        }

        

        return ++pos;
    }

    size_t erase(const key_type& key) {
        size_t idx;
        InfoType info;
        keyToIdx(key, idx, info);

        

        do {
            if (info == mInfo[idx] && KeyEqual::operator()(key, mKeyVals[idx].getFirst())) {
                shiftDown(idx);
                --mNumElements;
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

        Node* const oldKeyVals = mKeyVals;
        uint8_t const* const oldInfo = mInfo;

        const size_t oldMaxElements = mMask + 1;

        

        init_data(numBuckets);
        if (oldMaxElements > 1) {
            for (size_t i = 0; i < oldMaxElements; ++i) {
                if (oldInfo[i] != 0) {
                    insert_move(std::move(oldKeyVals[i]));
                    

                    oldKeyVals[i].~Node();
                }
            }

            

            DataPool::addOrFree(oldKeyVals, calcNumBytesTotal(oldMaxElements));
        }
    }

    size_type size() const {
        return mNumElements;
    }

    size_type max_size() const {
        return static_cast<size_type>(-1);
    }

    bool empty() const {
        return 0 == mNumElements;
    }

    float max_load_factor() const {
        return MaxLoadFactor100 / 100.0f;
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
        mNumElements = 0;
        mMask = max_elements - 1;
        mMaxNumElementsAllowed = calcMaxNumElementsAllowed(max_elements);

        

        mKeyVals = reinterpret_cast<Node*>(
            detail::assertNotNull<std::bad_alloc>(calloc(1, calcNumBytesTotal(max_elements))));
        mInfo = reinterpret_cast<uint8_t*>(mKeyVals + max_elements);

        

        mInfo[max_elements] = 1;

        mInfoInc = InitialInfoInc;
        mInfoHashShift = InitialInfoHashShift;
    }

    template <typename Arg>
    mapped_type& doCreateByKey(Arg&& key) {
        while (true) {
            size_t idx;
            InfoType info;
            keyToIdx(key, idx, info);
            nextWhileLess(&info, &idx);

            

            

            while (info == mInfo[idx]) {
                if (KeyEqual::operator()(key, mKeyVals[idx].getFirst())) {
                    

                    return mKeyVals[idx].getSecond();
                }
                next(&info, &idx);
            }

            

            if (ROBIN_HOOD_UNLIKELY(mNumElements >= mMaxNumElementsAllowed)) {
                increase_size();
                continue;
            }

            

            auto const insertion_idx = idx;
            auto const insertion_info = info;
            if (ROBIN_HOOD_UNLIKELY(insertion_info + mInfoInc > 0xFF)) {
                mMaxNumElementsAllowed = 0;
            }

            

            while (0 != mInfo[idx]) {
                next(&info, &idx);
            }

            auto& l = mKeyVals[insertion_idx];
            if (idx == insertion_idx) {
                

                

                ::new (static_cast<void*>(&l))
                    Node(*this, std::piecewise_construct,
                         std::forward_as_tuple(std::forward<Arg>(key)), std::forward_as_tuple());
            } else {
                shiftUp(idx, insertion_idx);
                l = Node(*this, std::piecewise_construct,
                         std::forward_as_tuple(std::forward<Arg>(key)), std::forward_as_tuple());
            }

            

            mInfo[insertion_idx] = static_cast<uint8_t>(insertion_info);

            ++mNumElements;
            return mKeyVals[insertion_idx].getSecond();
        }
    }

    

    template <typename Arg>
    std::pair<iterator, bool> doInsert(Arg&& keyval) {
        while (true) {
            size_t idx;
            InfoType info;
            keyToIdx(keyval.getFirst(), idx, info);
            nextWhileLess(&info, &idx);

            

            while (info == mInfo[idx]) {
                if (KeyEqual::operator()(keyval.getFirst(), mKeyVals[idx].getFirst())) {
                    

                    

                    return std::make_pair<iterator, bool>(iterator(mKeyVals + idx, mInfo + idx),
                                                          false);
                }
                next(&info, &idx);
            }

            

            if (ROBIN_HOOD_UNLIKELY(mNumElements >= mMaxNumElementsAllowed)) {
                increase_size();
                continue;
            }

            

            auto const insertion_idx = idx;
            auto const insertion_info = info;
            if (ROBIN_HOOD_UNLIKELY(insertion_info + mInfoInc > 0xFF)) {
                mMaxNumElementsAllowed = 0;
            }

            

            while (0 != mInfo[idx]) {
                next(&info, &idx);
            }

            auto& l = mKeyVals[insertion_idx];
            if (idx == insertion_idx) {
                ::new (static_cast<void*>(&l)) Node(*this, std::forward<Arg>(keyval));
            } else {
                shiftUp(idx, insertion_idx);
                l = Node(*this, std::forward<Arg>(keyval));
            }

            

            mInfo[insertion_idx] = static_cast<uint8_t>(insertion_info);

            ++mNumElements;
            return std::make_pair(iterator(mKeyVals + insertion_idx, mInfo + insertion_idx), true);
        }
    }

    size_t calcMaxNumElementsAllowed(size_t maxElements) {
        static constexpr size_t overflowLimit = (std::numeric_limits<size_t>::max)() / 100;
        static constexpr double factor = MaxLoadFactor100 / 100.0;

        

        if (maxElements > overflowLimit) {
            return static_cast<size_t>(static_cast<double>(maxElements) * factor);
        } else {
            return (maxElements * MaxLoadFactor100) / 100;
        }
    }

    bool try_increase_info() {
        ROBIN_HOOD_LOG("mInfoInc=" << mInfoInc << ", numElements=" << mNumElements
                                   << ", maxNumElementsAllowed="
                                   << calcMaxNumElementsAllowed(mMask + 1));
        

        mInfoInc = static_cast<uint8_t>(mInfoInc >> 1);
        if (1 == mInfoInc) {
            

            return false;
        }

        

        

        ++mInfoHashShift;
        auto const data = reinterpret_cast<uint64_t*>(mInfo);
        auto const numEntries = (mMask + 1) / 8;

        for (size_t i = 0; i < numEntries; ++i) {
            data[i] = (data[i] >> 1) & UINT64_C(0x7f7f7f7f7f7f7f7f);
        }
        mMaxNumElementsAllowed = calcMaxNumElementsAllowed(mMask + 1);
        return true;
    }

    void increase_size() {
        

        if (0 == mMask) {
            init_data(InitialNumElements);
            return;
        }

        auto const maxNumElementsAllowed = calcMaxNumElementsAllowed(mMask + 1);
        if (mNumElements < maxNumElementsAllowed && try_increase_info()) {
            return;
        }

        ROBIN_HOOD_LOG("mNumElements=" << mNumElements << ", maxNumElementsAllowed="
                                       << maxNumElementsAllowed << ", load="
                                       << (static_cast<double>(mNumElements) * 100.0 /
                                           (static_cast<double>(mMask) + 1)));
        

        if (mNumElements * 2 < calcMaxNumElementsAllowed(mMask + 1)) {
            throwOverflowError();
        }

        rehash((mMask + 1) * 2);
    }

    void destroy() {
        if (0 == mMask) {
            

            return;
        }

        Destroyer<Self, IsFlatMap && std::is_trivially_destructible<Node>::value>{}
            .nodesDoNotDeallocate(*this);
        free(mKeyVals);
    }

    

    Node* mKeyVals = reinterpret_cast<Node*>(reinterpret_cast<uint8_t*>(&detail::DummyInfoByte::b) -
                                             sizeof(Node));                 

    uint8_t* mInfo = reinterpret_cast<uint8_t*>(&detail::DummyInfoByte::b); 

    size_t mNumElements = 0;                                                

    size_t mMask = 0;                                                       

    size_t mMaxNumElementsAllowed = 0;                                      

    InfoType mInfoInc = InitialInfoInc;                                     

    InfoType mInfoHashShift = InitialInfoHashShift;                         

                                                    

};

} 


template <typename Key, typename T, typename Hash = hash<Key>,
          typename KeyEqual = std::equal_to<Key>, size_t MaxLoadFactor100 = 80>
using unordered_flat_map = detail::unordered_map<true, MaxLoadFactor100, Key, T, Hash, KeyEqual>;

template <typename Key, typename T, typename Hash = hash<Key>,
          typename KeyEqual = std::equal_to<Key>, size_t MaxLoadFactor100 = 80>
using unordered_node_map = detail::unordered_map<false, MaxLoadFactor100, Key, T, Hash, KeyEqual>;

template <typename Key, typename T, typename Hash = hash<Key>,
          typename KeyEqual = std::equal_to<Key>, size_t MaxLoadFactor100 = 80>
using unordered_map =
    detail::unordered_map<sizeof(robin_hood::pair<Key, T>) <= sizeof(size_t) * 6 &&
                              std::is_nothrow_move_constructible<robin_hood::pair<Key, T>>::value &&
                              std::is_nothrow_move_assignable<robin_hood::pair<Key, T>>::value,
                          MaxLoadFactor100, Key, T, Hash, KeyEqual>;

} 


#endif

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