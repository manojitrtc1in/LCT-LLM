


#define NDEBUG

#include <algorithm>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <memory>


#define forn(t, i, n) for (t i = 0; i < (n); ++i)


#define F1(e) [&](size_t i1) {return e;}


using namespace std;



bool __hack = std::ios::sync_with_stdio(false);


auto __hack1 = cin.tie(nullptr);


template <class T>
T gen_pow(T ret, T x, uint64_t pow) {
    while (pow) {
        if (pow & 1) {
            ret *= x;
        }
        pow /= 2;
        if (pow) {
            x *= x;
        }
    }
    return ret;
}


namespace option_detail {
    

    struct NoneHelper {};
}


template<class Value>
class Option {
public:
    

    static_assert(!std::is_reference<Value>::value,
                  "Option may not be used with reference types");
    static_assert(!std::is_abstract<Value>::value,
                  "Option may not be used with abstract types");

    
    Value* get_pointer() && = delete;

    
    

    

    

    

private:
    

    struct StorageTriviallyDestructible {
        

        
        bool hasValue;

        
    };

    

    struct StorageNonTriviallyDestructible {
        

        union { Value value; };
        bool hasValue;

        
        ~StorageNonTriviallyDestructible() {
            clear();
        }

        void clear() {
            if (hasValue) {
                hasValue = false;
                value.~Value();
            }
        }
    };

    

    using Storage =
    typename std::conditional<std::is_trivially_destructible<Value>::value,
            StorageTriviallyDestructible,
            StorageNonTriviallyDestructible>::type;

    Storage storage_;
};






template<class V> bool operator< (const Option<V>&, const V& other) = delete;
template<class V> bool operator<=(const Option<V>&, const V& other) = delete;
template<class V> bool operator>=(const Option<V>&, const V& other) = delete;
template<class V> bool operator> (const Option<V>&, const V& other) = delete;
template<class V> bool operator< (const V& other, const Option<V>&) = delete;
template<class V> bool operator<=(const V& other, const Option<V>&) = delete;
template<class V> bool operator>=(const V& other, const Option<V>&) = delete;
template<class V> bool operator> (const V& other, const Option<V>&) = delete;


#define ENABLE_IF(e) typename enable_if<e>::type* = nullptr

namespace template_util {
    

    constexpr int bytecount(uint64_t x) {
        return x ? 1 + bytecount(x >> 8) : 0;
    }

    

    template<int N>
    struct bytetype {
        typedef uint64_t type;
    };

    

    template<>
    struct bytetype<4> {
        typedef uint32_t type;
    };

    

    template<>
    struct bytetype<3> {
        
    };

    

    template<>
    struct bytetype<2> {
        
    };

    

    template<>
    struct bytetype<1> {
        typedef uint8_t type;
    };

    

    template<>
    struct bytetype<0> {
        typedef uint8_t type;
    };

    

    template<uint64_t N>
    struct minimal_uint : bytetype<bytecount(N)> {
    };
}


namespace index_iterator_impl {
    template <class T>
    struct member_dispatch_helper {
        

    private:
        T value;
    };

    

    

    template <class C, bool reverse = false>
    struct index_iterator {
        

        typedef random_access_iterator_tag iterator_category;
        

        typedef decltype(((C*)nullptr)->operator[](size_t(0))) reference;
        

        typedef typename remove_reference<reference>::type value_type;
        

        typedef ptrdiff_t difference_type;
        

        typedef conditional<
                is_reference<reference>::value,
                typename add_pointer<value_type>::type,
                member_dispatch_helper<value_type>> pointer;

        

        typedef index_iterator<C, reverse> self_t;

        

        static const difference_type dir = reverse ? -1 : 1;

        

        index_iterator() = default;

        
        

        inline bool operator!=(const self_t& o) { return index != o.index; }
        

        inline bool operator<(const self_t& o) { return reverse ? index > o.index : index < o.index; }
        

        inline bool operator>(const self_t& o) { return reverse ? index < o.index : index > o.index; }
        

        inline bool operator<=(const self_t& o) { return reverse ? index >= o.index : index <= o.index; }
        

        inline bool operator>=(const self_t& o) { return reverse ? index <= o.index : index >= o.index; }

        

        inline reference operator*() { return (*container)[index]; }
        

        inline const reference operator*() const { return (*container)[index]; }
        

        inline pointer operator->() { return pointer((*container)[index]); }

        

        inline self_t& operator++() { index += dir; return *this; }
        

        inline self_t operator++(int) { auto copy = *this; index += dir; return copy; }
        

        inline self_t& operator--() { index -= dir; return *this; }
        

        inline self_t operator--(int) { auto copy = *this; index -= dir; return copy; }

        

        inline self_t& operator+=(difference_type n) { index += dir * n; return *this; };
        

        inline self_t& operator-=(difference_type n) { index -= dir * n; return *this; };
        

        inline friend self_t operator-(self_t a, difference_type n) { return a -= n; };
        

        inline friend self_t operator+(difference_type n, self_t a) { return a += n; };
        

        inline friend self_t operator+(self_t a, difference_type n) { return a += n; };
        

        inline friend difference_type operator-(const self_t& a, const self_t& b) { return dir * (a.index - b.index); };

        

        inline reference operator[](difference_type n) { return (*container)[index + dir * n]; };
        

        inline const reference operator[](difference_type n) const { return (*container)[index + dir * n]; };

    private:
        C* container;
        difference_type index;
    };
}


namespace multivec_impl {
    template <size_t NDIMS>
    struct shape {
        size_t dim, stride;
        shape<NDIMS - 1> subshape;
        
        shape(size_t dim_, shape<NDIMS - 1>&& s): dim(dim_), stride(s.size()), subshape(std::move(s)) {}
        size_t size() const { return dim * stride; }
        
        
    };
    template <> struct shape<0> { size_t size() const { return 1; } };
    

    template <size_t I, size_t NDIMS>
    struct __shape_traverse {
        

    };

    template <size_t NDIMS>
    struct __shape_traverse<0, NDIMS> {
        static size_t get_dim(const shape<NDIMS>& s) { return s.dim; }
        
    };

    template <size_t I, size_t NDIMS>
    size_t get_dim(const shape<NDIMS>& s) { return __shape_traverse<I, NDIMS>::get_dim(s); }

    
    template <class Index, class... Rest, size_t NDIMS, ENABLE_IF(is_integral<Index>::value)>
    size_t get_shift(const shape<NDIMS>& s, size_t cur_shift, Index i, Rest... is) {
        assert(0 <= i && i < s.dim);
        return get_shift(s.subshape, cur_shift + i * s.stride, is...);
    }

    template <size_t NDIMS> size_t get_shift(const shape<NDIMS>&, size_t cur_shift) { return cur_shift; }

    
    template <class... T> shape<sizeof...(T)> make_shape(T... dims);

    template <class Dim, class... Rest, ENABLE_IF(is_integral<Dim>::value)>
    shape<sizeof...(Rest) + 1> make_shape(Dim dim, Rest... dims) {
        assert(dim >= 0);
        return {(size_t)dim, make_shape<Rest...>(dims...)};
    }

    template <> shape<0> make_shape() { return {}; }

    
    template <template<class, size_t> class Base, class T, size_t NDIMS>
    struct vec_mixin : public Base<T, NDIMS> {
        using Base<T, NDIMS>::Base;
        

        typedef Base<T, NDIMS> B;
        
        
        template <size_t I = 0> inline size_t dim() const { return get_dim<I>(B::s); }
        

        template <class... Indices, bool enabled = NDIMS == sizeof...(Indices), ENABLE_IF(enabled)>
        inline T& operator()(Indices... is) {
            size_t i = multivec_impl::get_shift(B::s, 0, is...);
            return B::data[i];
        }

        
        template <class F, class... Indices, typename result_of<F()>::type* = nullptr, ENABLE_IF(sizeof...(Indices) == NDIMS)>
        inline void fill(F f, Indices... is) & {
            (*this)(is...) = f();
        };

        template <class F, class... Indices, ENABLE_IF(sizeof...(Indices) < NDIMS)>
        inline void fill(F f, Indices... is) & {
            forn (size_t, i, dim()) fill(f, i, is...);
        };

        


        

    };

    
    template <class T, size_t NDIMS>
    struct vec_base {
        inline vec_base(multivec_impl::shape<NDIMS>&& s_): s(move(s_)), data(new T[s.size()]) {}
        
        
        inline vec_base(const vec_base& o): s(o.s), data(new T[s.size()]) {
            memcpy(data.get(), o.data.get(), sizeof(T) * s.size());
        }
        
    protected:
        multivec_impl::shape<NDIMS> s;
        unique_ptr<T[]> data;
    };
}



template <class T, size_t NDIMS>
using vec = multivec_impl::vec_mixin<multivec_impl::vec_base, T, NDIMS>;


template <class T, class... NDIMS>
inline vec<T, sizeof...(NDIMS)> make_vec(NDIMS... dims) {
    return {multivec_impl::make_shape(dims...)};
}

namespace segment_tree_impl {
    size_t calc_size(size_t n) {
        size_t ret = 1;
        while (ret < n) {
            ret *= 2;
        }
        return ret;
    }
}

namespace segment_tree {
    template<class T>
    struct val_traits {
        

    };

    template<class T, class U>
    struct update_traits {
        

    };

    struct dummy_update {
    };

    
    template<class T, class U = dummy_update>
    struct stree {
        using VT = val_traits<T>;
        using UT = update_traits<T, U>;

        
        template<class F>
        stree(size_t n, F f)
                : n_(n), size(segment_tree_impl::calc_size(n)), ar(size - 1 + n), ur(size - 1 + n, UT::one()) {
            for (int i = 0; i < n; ++i) {
                ar[size - 1 + i] = f(i);
            }
            for (int i = size - 2; i >= 0; --i) {
                ar[i] = 2 * i + 1 < ar.size() ? ar[2 * i + 1] : VT::zero();
                if (2 * i + 2 < ar.size()) {
                    VT::compose(ar[i], ar[2 * i + 2]);
                }
            }
        }

        T sumRange(size_t l, size_t r) {
            assert(l < r && r <= n_);
            return sumRange(0, 0, size, l, r);
        }

        T updateRange(size_t l, size_t r, U u) {
            assert(l < r && r <= n_);
            return updateRange(0, 0, size, l, r, u);
        }

        
    private:

        T sumRange(size_t n, size_t nl, size_t nr, size_t l, size_t r) {
            assert(l < nr && nl < r);
            if (l <= nl && nr <= r) {
                return ar[n];
            }
            size_t mid = (nl + nr) / 2;
            T ret;
            if (r <= mid) {
                ret = sumRange(2 * n + 1, nl, mid, l, r);
            } else if (mid <= l) {
                ret = sumRange(2 * n + 2, mid, nr, l, r);
            } else {
                ret = sumRange(2 * n + 1, nl, mid, l, r);
                VT::compose(ret, sumRange(2 * n + 2, mid, nr, l, r));
            }
            UT::apply(ret, ur[n], max(l, nl), min(r, nr));
            return ret;
        }

        inline void propagate_down(size_t n, size_t nl, size_t mid, size_t nr) {
            UT::apply(ar[2 * n + 1], ur[n], nl, mid);
            UT::compose(ur[2 * n + 1], ur[n]);
            if (2 * n + 2 < ar.size()) {
                UT::apply(ar[2 * n + 2], ur[n], mid, nr);
                UT::compose(ur[2 * n + 2], ur[n]);
            }
            ur[n] = UT::one();
        }

        T updateRange(size_t n, size_t nl, size_t nr, size_t l, size_t r, U u) {
            assert(l < nr && nl < r);
            if (l <= nl && nr <= r) {
                ar[n] *= u;
                ur[n] *= u;
                return ar[n];
            }
            size_t mid = (nl + nr) / 2;
            propagate_down(n, nl, mid, nr);
            ar[n] = mid <= l ? ar[2 * n + 1] : updateRange(2 * n + 1, nl, mid, l, r, u);
            VT::compose(ar[n], r <= mid ? ar[2 * n + 2] : updateRange(2 * n + 2, mid, nr, l, r, u));
            return ar[n];
        }

        
        const size_t n_, size;
        vector<T> ar;
        vector<U> ur;
    };
}




namespace mod_impl {
    

    template <class T>
    constexpr inline T mod(T MOD) {
        return MOD;
    }

    

    template <class T>
    constexpr inline T mod(T* MOD) {
        return *MOD;
    }

    

    template <class T>
    constexpr inline T max_mod(T MOD) {
        return MOD - 1;
    }

    

    template <class T>
    constexpr inline T max_mod(T*) {
        return numeric_limits<T>::max();
    }

    
    constexpr inline uint64_t combine_max_sum(uint64_t a, uint64_t b) {
        return a > ~b ? 0 : a + b;
    }

    constexpr inline uint64_t combine_max_mul(uint64_t a, uint64_t b) {
        return a > numeric_limits<uint64_t>::max() / b ? 0 : a * b;
    }

    

    template <class T>
    constexpr inline uint64_t next_divisable(T mod, uint64_t max) {
        return max % mod == 0 ? max : combine_max_sum(max, mod - max % mod);
    }

    

    template <class T>
    constexpr inline uint64_t next_divisable(T*, uint64_t) {
        return 0;
    }

    

    constexpr int IF_THRESHOLD = 2;

    template <class T, T MOD_VALUE, uint64_t MAX,
            class RET = typename template_util::minimal_uint<max_mod(MOD_VALUE)>::type,
            ENABLE_IF(MAX <= max_mod(MOD_VALUE) && !is_pointer<T>::value)>
    inline RET smart_mod(typename template_util::minimal_uint<MAX>::type value) {
        return value;
    }

    template <class T, T MOD_VALUE, uint64_t MAX,
            class RET = typename template_util::minimal_uint<max_mod(MOD_VALUE)>::type,
            ENABLE_IF(max_mod(MOD_VALUE) < MAX && MAX <= IF_THRESHOLD * max_mod(MOD_VALUE) && !is_pointer<T>::value)>
    inline RET smart_mod(typename template_util::minimal_uint<MAX>::type value) {
        while (value >= mod(MOD_VALUE)) {
            value -= mod(MOD_VALUE);
        }
        return (RET)value;
    }

    template <class T, T MOD_VALUE, uint64_t MAX,
             class RET = typename template_util::minimal_uint<max_mod(MOD_VALUE)>::type,
             ENABLE_IF(IF_THRESHOLD * max_mod(MOD_VALUE) < MAX || is_pointer<T>::value)>
    inline RET smart_mod(typename template_util::minimal_uint<MAX>::type value) {
        return (RET)(value % mod(MOD_VALUE));
    }
}


#define MAX_MOD mod_impl::max_mod(MOD_VALUE)

struct DenormTag {};

template <class T, T MOD_VALUE, uint64_t MAX = MAX_MOD, ENABLE_IF(MAX_MOD >= 2)>
struct ModVal {
    typedef typename template_util::minimal_uint<MAX>::type storage;
    storage value;

    

    inline ModVal(): value(0) {
        assert(MOD >= 2);
    }

    
    inline ModVal(storage v, DenormTag): value(v) {
        assert(MOD >= 2);
        assert(v <= MAX);
    };

    inline operator ModVal<T, MOD_VALUE>() {
        return {mod_impl::smart_mod<T, MOD_VALUE, MAX>(value), DenormTag()};
    };

    explicit inline operator uint64_t() const {
        return mod_impl::smart_mod<T, MOD_VALUE, MAX>(value);
    }
};


template <class T, T MOD_VALUE, uint64_t MAX1, uint64_t MAX2,
        uint64_t NEW_MAX = mod_impl::combine_max_sum(MAX1, MAX2),
        ENABLE_IF(NEW_MAX != 0), class Ret = ModVal<T, MOD_VALUE, NEW_MAX>>
inline Ret operator+(ModVal<T, MOD_VALUE, MAX1> o1, ModVal<T, MOD_VALUE, MAX2> o2) {
    return {typename Ret::storage(typename Ret::storage() + o1.value + o2.value), DenormTag()};
}


template <class T, T MOD_VALUE, uint64_t MAX1, uint64_t MAX2,
        uint64_t NEW_MAX = mod_impl::combine_max_mul(MAX1, MAX2),
        ENABLE_IF(NEW_MAX != 0), class Ret = ModVal<T, MOD_VALUE, NEW_MAX>>
inline Ret operator*(ModVal<T, MOD_VALUE, MAX1> o1, ModVal<T, MOD_VALUE, MAX2> o2) {
    return {typename Ret::storage(typename Ret::storage(1) * o1.value * o2.value), DenormTag()};
}


template <class T, T MOD_VALUE, uint64_t MAX>
inline ModVal<T, MOD_VALUE>& operator+=(ModVal<T, MOD_VALUE>& lhs, const ModVal<T, MOD_VALUE, MAX>& rhs) {
    lhs = lhs + rhs;
    return lhs;
}


template <class T, T MOD_VALUE, class MOD_TYPE>
struct ModCompanion {
    typedef MOD_TYPE mod_type;
    typedef ModVal<mod_type, MOD_VALUE> type;
    T mod = MOD_VALUE;

    
    template <uint64_t C>
    inline static constexpr ModVal<mod_type, MOD_VALUE, C> c() {
        return {C, DenormTag()};
    };

    
};


#undef MAX_MOD

template <uint64_t MOD_VALUE>
struct Mod : ModCompanion<uint64_t, MOD_VALUE, typename template_util::minimal_uint<MOD_VALUE>::type> {
    template<uint64_t VAL>
    static constexpr uint64_t literal_builder() {
        return VAL;
    }

    template<uint64_t VAL, char DIGIT, char... REST>
    static constexpr uint64_t literal_builder() {
        return literal_builder<(10 * VAL + DIGIT - '0') % MOD_VALUE, REST...>();
    }
};


#define REGISTER_MOD_LITERAL(mod, suffix) \
template <char... DIGITS> mod::type operator "" _##suffix() { \
    return mod::c<mod::literal_builder<0, DIGITS...>()>(); \
}


template<class T>
T next(istream& in) {
    T ret;
    in >> ret;
    return ret;
}


template<class T, class... Dims>
vec<T, sizeof...(Dims)> next_vec(istream& in, Dims... dims) {
    auto tmp = make_vec<T>(dims...);
    tmp.fill([&]() { return next<T>(in); });
    return tmp;
}





const uint32_t mod = 1000000007;
typedef Mod<mod> md;
typedef md::type mt;
REGISTER_MOD_LITERAL(md, mod)

using namespace segment_tree;

using fib = pair<mt, mt>;
fib fibzero = {0_mod, 0_mod}, fibone = {1_mod, 0_mod}, X = {0_mod, 1_mod};

inline fib& operator*=(fib& a, const fib& b) {
    

    auto tmp = a.second * b.second;
    a = {a.first * b.first + tmp, a.first * b.second + a.second * b.first + tmp};
    return a;
}

namespace segment_tree {
    template<>
    struct val_traits<fib> {
        static inline fib zero() {
            return fibzero;
        };

        static inline void compose(fib& a, const fib& b) {
            a.first += b.first;
            a.second += b.second;
        }
    };

    template<>
    struct update_traits<fib, fib> {
        static inline fib one() {
            return fibone;
        };

        static inline void compose(fib& a, const fib& b) {
            a *= b;
        }

        static inline void apply(fib& a, const fib& b, size_t, size_t) {
            a *= b;
        }
    };
}

void solve(istream& in, ostream& out) {
    int n = next<int>(in);
    int m = next<int>(in);
    auto a = next_vec<int>(in, n);
    stree<fib, fib> t(n, F1(gen_pow(fibone, X, a(i1))));
    for (int i = 0; i < m; ++i) {
        if (next<int>(in) == 1) {
            int l = next<int>(in) - 1;
            int r = next<int>(in);
            int x = next<int>(in);
            t.updateRange(l, r, gen_pow(fibone, X, x));
        } else {
            int l = next<int>(in) - 1;
            int r = next<int>(in);
            out << (uint64_t)(t.sumRange(l, r).second) << endl;
        }
    }
}


int main() {
    solve(cin, cout);
    return 0;
}

