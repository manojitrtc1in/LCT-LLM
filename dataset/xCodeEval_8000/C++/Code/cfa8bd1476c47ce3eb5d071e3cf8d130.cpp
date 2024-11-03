#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstring>
#include <cmath>
#include <complex>
#include <cstdio>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
#include <type_traits>
#include <tuple>
 
 
#define GET_4TH_ARG(arg1, arg2, arg3, arg4, ...) arg4
#define F0(f) [=]() -> decltype(auto) { return (f); }
#define F1(_, f) [=](auto&& _) -> decltype(auto) { (void)_; return (f); }
#define F2(_1, _2, f) [=](auto&& _1, auto&& _2) -> decltype(auto) { (void)_1; (void)_2; return (f); }
#define FV_macro_chooser(...) GET_4TH_ARG(__VA_ARGS__, F2, F1, F0)
#define FV(...) FV_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define G0(f) [&]() -> decltype(auto) { return (f); }
#define G1(_, f) [&](auto&& _) -> decltype(auto) { (void)_; return (f); }
#define G2(_1, _2, f) [&](auto&& _1, auto&& _2) -> decltype(auto) { (void)_1; (void)_2; return (f); }
#define FR_macro_chooser(...) GET_4TH_ARG(__VA_ARGS__, G2, G1, G0)
#define FR(...) FR_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
 
 
#ifndef GET_4TH_ARG
    #define GET_4TH_ARG(arg1, arg2, arg3, arg4, ...) arg4
#endif
#define GET_7TH_ARG(arg1, arg2, arg3, arg4, arg5, arg6, arg7, ...) arg7
#define template_for_iterable_3(T, I, V) template<typename T, typename I = typename T::iterator, typename V = typename T::value_type>
#define template_for_iterable_2(T, I) template_for_iterable_3(T, I, )
#define template_for_iterable_1(T) template_for_iterable_2(T, I)
#define template_for_iterable_macro_chooser(...) GET_4TH_ARG(__VA_ARGS__, template_for_iterable_3, template_for_iterable_2, template_for_iterable_1)
#define template_for_iterable(...) template_for_iterable_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define iterator_macro(extra, neq, incr, val)               \
    struct Iterator {                                       \
        extra                                               \
        bool operator != (const Iterator& other) const {    \
            (void)other;                                    \
            return neq;                                     \
        }                                                   \
        void operator ++ () incr                            \
        decltype(auto) operator * () const {                      \
            return val;                                     \
        }                                                   \
    };
#define def_iterator_manip_iter(name, templ, args, args_, extra, it_begin, it_end, extra_it, neq_it, incr_it, val_it) \
    def_iterator_manip(name, templ, args, args_, extra, { iterator_macro(extra extra_it mutable I it;, neq_it, incr_it, val_it); return iterable_wrapper(it_begin, it_end); })                                                                                                           
#define def_iterator_manip_2(name, code)        \
    constexpr struct {                          \
        using is_composable_ = void;         \
        template_for_iterable(T, I, V)          \
        decltype(auto) operator() (const T& v) const code      \
    } name;                                     
#define def_iterator_manip_6(name, templ, args, args_, extra, code)     \
    templ                                                               \
    struct name##_ {                                                    \
        using is_composable_ = void;                                 \
        extra                                                           \
        template_for_iterable(T, I, V)                                  \
        decltype(auto) operator () (const T& v) const code              \
    };                                                                  \
    templ                                                               \
    constexpr decltype(auto) name args {                                          \
        return name##_ args_;                                           \
    }
#define def_iterator_manip_iter_chooser(...) GET_7TH_ARG(__VA_ARGS__, def_iterator_manip_6, , , , def_iterator_manip_2)
#define def_iterator_manip(...) def_iterator_manip_iter_chooser(__VA_ARGS__)(__VA_ARGS__)
#define def_template_lambda(templ, name, args, code)    \
    constexpr struct {                                  \
        using is_composable_ = void;                 \
        templ                                           \
        decltype(auto) operator() args const code       \
    } name;
 
 


template<typename T, typename = void>
struct is_iterable : public std::false_type { };
 
template<typename T>
struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>())), decltype(std::end(std::declval<T>()))>> : public std::true_type { };
 
template<typename T>
constexpr bool is_iterable_v = is_iterable<T>::value;
 
 


template<typename T, typename = void>
struct is_composable : public std::false_type { };
 
template<typename T>
struct is_composable<T, std::void_t<typename T::is_composable_>> : public std::true_type { };
 
template<typename T>
constexpr bool is_composable_v = is_composable<T>::value;
 
 


template<typename I>
constexpr auto iterable_wrapper(const I& b, const I& e) {
    struct Wrapper {
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
        using is_iterable_wrapper = void;
        using iterator = I;
        using value_type = std::decay_t<decltype(*std::declval<I>())>;
#pragma GCC diagnostic pop
        I b, e;
        auto begin() const {
            return b;
        }
        auto end() const {
            return e;
        }
    };
    return Wrapper{b, e};
}
 
template_for_iterable(T, I)
constexpr auto iter(const T& iterable) {
    return iterable_wrapper(std::begin(iterable), std::end(iterable));
}
 
 


template<typename C>

struct container_carrying_iterator : public C::iterator {
    std::shared_ptr<C> p;
    container_carrying_iterator(std::shared_ptr<C> p_, typename C::iterator it) : C::iterator(it), p(p_) { }
};
template<typename C>
constexpr auto iterc(C&& v) {
    using D = std::decay_t<C>;
    std::shared_ptr<D> p(new D(v));
    return iterable_wrapper(container_carrying_iterator<D>{ p, std::begin(*p) }, container_carrying_iterator<D>{ p, std::end(*p) });
}
 
template<typename T>
constexpr auto iter(std::initializer_list<T> l) {
    return iterc(std::vector<T>(l));
}
 
 


 
template<typename T, typename F, typename = std::invoke_result_t<F, T>>
decltype(auto) operator > (T&& v, const F& f) {
    return f(std::forward<T>(v));
}
 
template<typename M1, typename M2>
struct composed {
    using is_composable_ = void;
    const M1 m1;
    const M2 m2;
    template<typename T>
    decltype(auto) operator () (const T& v) const {
        return v > m2 > m1;
    }
};
 
template<typename M1, typename M2, typename = std::enable_if_t<is_composable_v<M1> or is_composable_v<M2>>>
constexpr auto operator < (const M1& m1, const M2& m2) {
    return composed<M1, M2>{m1, m2};
}
 
 


#define to_container_macro(T, ins)                               \
    def_iterator_manip(                                     \
    to_##T, {                                            \
        std:: T <V> s;                                   \
        for(auto&& x : v) {                                 \
            s.ins(std::forward<decltype(x)>(x));      \
        }                                                   \
        return s;                                           \
    })
to_container_macro(vector, push_back)
to_container_macro(set, insert)
to_container_macro(unordered_set, insert)
 
 


def_iterator_manip(
is_nil, {
    return not (std::begin(v) != std::end(v));
});
 
 


def_iterator_manip_iter(
    apply,
    template<typename F>,
    (F f),
    <F>{f},
    F f;,
    (Iterator{f, std::begin(v)}),
    (Iterator{f, std::end(v)}),
    ,
    it != other.it,
    { ++it; },
    f(*it)
)
 
 


def_iterator_manip_iter(
    take,
    ,
    (size_t n),
    {n},
    size_t n;,
    (Iterator{n, std::begin(v)}),
    (Iterator{0, std::end(v)}),
    ,
    n != other.n,
    { --n; if(n > 0) { ++it; } },
    *it
)
 
 


def_iterator_manip_iter(
    take_while,
    template<typename F>,
    (F f),
    <F>{f},
    F f;,
    (Iterator{f, not (std::begin(v) != std::end(v) and f(*std::begin(v))), std::begin(v)}),
    (Iterator{f, true, std::end(v)}),
    bool is_end;,
    is_end xor other.is_end,
    { ++it; if(not f(*it)) { is_end = true; }},
    *it
)
 
 


def_iterator_manip_iter(
    drop,
    ,
    (size_t n),
    {n},
    mutable size_t n;,
    (Iterator{n, std::end(v), std::begin(v)}),
    (Iterator{0, std::end(v), std::end(v)}),
    const I end_it;
    inline void advance() const {
        while(n > 0) {
            if(not (it != end_it)) {
                n = 0;
                break;
            }
            --n;
            ++it;
        }
    },
    (advance(), other.advance(), it != other.it),
    { advance(); ++it; },
    (advance(), *it)
)
 
 


def_iterator_manip_iter(
    drop_while,
    template<typename F>,
    (F f),
    <F>{f},
    F f;,
    (Iterator{f, std::end(v), false, std::begin(v)}),
    (Iterator{f, std::end(v), true, std::end(v)}),
    const I end_it;
    mutable bool has_advanced;
    inline void advance() const {
        if(not has_advanced) {
            while(it != end_it and f(*it)) {
                ++it;
            }
            has_advanced = true;
        }
    },
    (advance(), other.advance(), it != other.it),
    { advance(); ++it; },
    (advance(), *it)
)
 
 


def_iterator_manip(
head, {
    return *std::begin(v);
})
 
 


constexpr auto tail = drop(1);
 
 


def_iterator_manip(
length, {
    auto b = std::begin(v);
    auto e = std::end(v);
    size_t n = 0;
    while(b != e) {
        ++n;
        ++b;
    }
    return n;
})
 
 


constexpr auto at(size_t n) {
    return head < drop(n);
}
 
 


def_iterator_manip_iter(
    cons,
    template<typename S>,
    (S s),
    <S>{s},
    S s;,
    (Iterator{ s, true, std::begin(v) }),
    (Iterator{ s, false, std::end(v) }),
    bool is_s;,
    is_s != other.is_s or it != other.it,
    { if(is_s) { is_s = false; } else { ++it; } },
    (is_s) ? (s) : (*it)
)
    
 
 


def_iterator_manip(
snoc, {
    return tuple(v > head, v > tail);
})
 
 


template<typename F, typename S>
struct fold_ {
    using is_composable_ = void;
    F f;
    S s;
    template_for_iterable(T)
    decltype(auto) operator () (const T& v) const {
        auto x = s;
        for(auto y : v) {
            x = f(x, y);
        }
        return x;
    }
};
 
template<typename F, typename S>
constexpr auto fold(F f, const S& s) {
    return fold_<F, S>{f, s};
}
 
 
def_iterator_manip(fold1, template<typename F>, (F f), <F>{f}, F f;, { return v > tail > fold(f, v > head);})
 
 


def_iterator_manip(
sum, {
    return v > fold(std::plus<V>(), V());
})
 
 


def_iterator_manip(
product, {
    return v > fold(std::multiplies<V>(), V(1));
})
 
 


def_iterator_manip(maximum_by, template<typename F>, (F f), <F>{f}, F f;, { return v > fold1(FR(x, y, (f(x, y)) ? (y) : (x))); })
def_iterator_manip(
maximum, {
    return v > maximum_by(std::less<V>());
})
def_iterator_manip(maximum_on, template<typename F>, (F f), <F>{f}, F f;, { return v > fold1(FR(x, y, (f(x) < f(y)) ? (y) : (x))); })
 
 


def_iterator_manip(minimum_by, template<typename F>, (F f), <F>{f}, F f;, { return v > fold1(FR(x, y, (f(y, x)) ? (y) : (x))); })
def_iterator_manip(
minimum, {
    return v > maximum_by(std::less<V>());
})
def_iterator_manip(minimum_on, template<typename F>, (F f), <F>{f}, F f;, { return v > fold1(FR(x, y, (f(y) < f(x)) ? (y) : (x))); })
 
 


def_iterator_manip_iter(
    scan1,
    template<typename F>,
    (F f),
    <F>{f},
    F f;,
    (Iterator{ f, *std::begin(v), true, std::begin(v) }),
    (Iterator{ f, *std::begin(v), true, std::end(v) }),
    mutable V s; mutable bool has_updated;,
    it != other.it,
    { if(not has_updated) { s = f(s, *it); }; has_updated = false; ++it; },
    (has_updated) ? (s) : (has_updated = true, s = f(s, *it))
)
 
 
template<typename F, typename S>
auto scan(F f, const S& s) {
    return scan1(f) < cons(s);
}
 
 


template<typename T, typename S, typename I = typename T::iterator, typename J = typename S::iterator>
constexpr auto operator + (const T& v, const S& u) {
    iterator_macro(
        I i; I i_end; J j; bool in_i;,
        i != other.i or j != other.j,
        { if(in_i) {++i; if(not (i != i_end)) { in_i = false; }} else { ++j; } },
        (in_i) ? (*i) : (*j)
    )
    auto bv = std::begin(v);
    auto ev = std::end(v);
    auto bu = std::begin(u);
    auto eu = std::end(u);
    return iterable_wrapper(Iterator{ bv, ev, bu, bv != ev }, Iterator{ ev, ev, eu, false });
}
 
 


constexpr struct {
    using is_composable_ = void;
    template_for_iterable(T)
    auto operator () (const T& v) const {
        auto u = v > filter(FR(_, not is_nil(_)));
        auto b = std::begin(u);
        auto e = std::end(u);
        using J = decltype(b);
        using V = std::decay_t<decltype(*b)>;
        using K = decltype(std::begin(*b));
        struct Iterator {
            J j; J j_end; std::shared_ptr<V> jv_ptr; std::shared_ptr<K> k_ptr; bool is_end;
            Iterator(J j, J j_end, const V& jv, bool is_end) : j(j), j_end(j_end), jv_ptr(new V(jv)), k_ptr(new K(std::begin(*jv_ptr))), is_end(is_end) { }
            Iterator(J j, J j_end, bool is_end) : j(j), j_end(j_end), jv_ptr(nullptr), k_ptr(nullptr), is_end(is_end) { }
            bool operator != (const Iterator& other) const {
                return is_end xor other.is_end;
            }
            void operator ++ () {
                ++*k_ptr;
                if(not(*k_ptr != std::end(*jv_ptr))) {
                    ++j;
                    if(j != j_end) {
                        *jv_ptr = V(*j);
                        *k_ptr = std::begin(*jv_ptr);
                    } else {
                        is_end = true;
                    }
                }
            }
            auto operator * () const {
                return **k_ptr;
            }
        };
        if(u > is_nil) {
            return iterable_wrapper(Iterator(b, e, true), Iterator(b, e, true));
        } else {
            return iterable_wrapper(Iterator(b, e, *b, false), Iterator(e, e, true));
        }
    }
} flatten;
 
 


template<typename T, typename F, typename = std::enable_if_t<is_iterable_v<T>>>
auto operator >= (const T& v, F f) {
    return v > apply(f) > flatten;
}
 
 


template<typename U, size_t i, size_t s>
bool all_different_(const U& x, const U& y) {
    if constexpr(i < s) {
        return std::get<i>(x) != std::get<i>(y) and all_different_<U, i + 1, s>(x, y);
    } else {
        return true;
    }
}
template<typename U, size_t i, size_t s>
void incr_all_(U& u) {
    if constexpr(i < s) {
        ++std::get<i>(u);
        incr_all_<U, i + 1, s>(u);
    }
}
template<typename F, typename U, size_t ...Seq>
decltype(auto) call_f_(F f, const U& u, std::index_sequence<Seq...>) {
    return f(*std::get<Seq>(u)...);
}
template<typename F, typename ...Ts>
constexpr auto zip_with(F f, const Ts& ...vs) {
    iterator_macro(
        F f;
        std::tuple<decltype(std::begin(std::declval<Ts>()))...> its;,
        (all_different_<decltype(its), 0, sizeof...(Ts)>(its, other.its)),
        { (incr_all_<decltype(its), 0, sizeof...(Ts)>(its)); },
        call_f_(f, its, std::index_sequence_for<Ts...>{})
    )
    return iterable_wrapper(Iterator{ f, std::tuple(std::begin(vs)...) }, Iterator{ f, std::tuple(std::end(vs)...) });
}
 
template<typename ...Ts>
constexpr auto zip(const Ts& ...vs) {
    return zip_with([](decltype(*std::begin(std::declval<Ts>())) ...xs) { return std::tuple<decltype(*std::begin(std::declval<Ts>()))...>(xs...); }, vs...);
}
        
 


def_iterator_manip_iter(
    filter,
    template<typename F>,
    (F f),
    <F>{f},
    F f;,
    (Iterator{f, std::end(v), std::begin(v)}),
    (Iterator{f, std::end(v), std::end(v)}),
    const I end_it;
    inline void advance() const {
        while(it != end_it and not f(*it)) {
            ++it;
        }
    },
    (advance(), other.advance(), it != other.it),
    { advance(); ++it; },
    (advance(), *it)
)
 
 


def_template_lambda(
template<typename T>,
repeat, (T&& v), {
    struct Iterator {
        const std::decay_t<T> v;
        bool operator != (const Iterator&) const {
            return true;
        }
        void operator ++ () { }
        const auto& operator * () const {
            return v;
        }
    };
    return iterable_wrapper(Iterator{v}, Iterator{v});
})
 
 


constexpr auto replicate(size_t n) {
    return take(n) < repeat;
}
 
 


constexpr auto cycle = flatten < repeat;
 
 
#pragma GCC diagnostic ignored "-Wnarrowing"


template<typename T1, typename T2, typename T3, typename T = decltype(T1() + T2() + T3())>
constexpr auto range(const T1& b, const T2& e, const T3& step) {
    iterator_macro(
        T x; T e; T step;
        bool is_end() const {
            return (step >= T(0) and x >= e) or (step < T(0) and x <= e);
        },
        is_end() xor other.is_end(),
        { x += step; },
        x
    )
    return iterable_wrapper(Iterator{b, e, step}, Iterator{e, e, step});
}
 
template<typename T1, typename T2>
constexpr auto range(const T1& b, const T2& e) {
    return range(b, e, 1);
}
 
template<typename T>
constexpr auto range(const T& e) {
    return range(T(), e, 1);
}
#pragma GCC diagnostic pop
 
 


template<typename T>
constexpr auto to_infinity(const T& b = T(), const T& step = 1) {
    iterator_macro(
        T x; T step;,
        true,
        { x += step; },
        x
    )
    return iterable_wrapper(Iterator{b, step}, Iterator{b, step});
}
 
 


def_iterator_manip(
enumerate, {
    return zip(to_infinity(size_t(0)), v);
})
 
 


def_iterator_manip(
reversed, {
    auto s = v > to_vector;
    std::reverse(s.begin(), s.end());
    return iterc(std::move(s));
})
 
 


def_iterator_manip(sorted_by, template<typename F>, (F f), <F>{f}, F f;, { auto s = v > to_vector; std::sort(std::begin(s), std::end(s), f); return iterc(std::move(s)); })
def_iterator_manip(
sorted, {
    return v > sorted_by(std::less<V>());
})
def_iterator_manip(sorted_on, template<typename F>, (F f), <F>{f}, F f;, { return v > apply(FR(_, std::tuple(_, f(_)))) > sorted_by(FR(x, y, std::get<1>(x) < std::get<1>(y))) > apply(FR(_, std::get<0>(_))); })
 
 


def_iterator_manip(
nub, {
    iterator_macro(
        I it_end; I it;,
        it != other.it,
        { decltype(*it) pr; do { pr = *it; ++it; } while(it != it_end and pr == *it); },
        *it
    )
    auto b = std::begin(v);
    auto e = std::end(v);
    return iterable_wrapper(Iterator{e, b}, Iterator{e, e});
})
 
 


template<typename F, typename S>
struct accum_vector_by_ {
    using is_composable_ = void;
    size_t n; F f; S s;
    template_for_iterable(T, I, V)
    decltype(auto) operator () (const T& v) const {
        std::vector<std::decay_t<std::invoke_result_t<F, S, decltype(std::get<1>(std::declval<V>()))>>> u(n, s);
        for(auto&& [i, x] : v) {
            std::cout << std::tuple(i, x) << std::endl;
            u[i] = f(u[i], x);
        }
        return u;
    }
};
 
template<typename F, typename S>
constexpr auto accum_vector_by(size_t n, F f, const S& s) {
    return accum_vector_by_<F, S>{ n, f, s };
}
 
template<typename S>
constexpr auto accum_vector(size_t n, const S& s = S()) {
    auto f = FR(x, y, y);
    return accum_vector_by_<decltype(f), S>{ n, f, s };
}
    
template<typename F, typename S>
struct accum_map_by_ {
    using is_composable_ = void;
    F f; S s;
    template_for_iterable(T, I, V)
    decltype(auto) operator () (const T& v) const {
        std::map<std::decay_t<decltype(std::get<0>(std::declval<V>()))>, std::decay_t<std::invoke_result_t<F, S, decltype(std::get<1>(std::declval<V>()))>>> u;
        for(auto&& [i, x] : v) {
            if(u.count(i)) {
                u[i] = f(u[i], x);
            } else {
                u[i] = f(s, x);
            }
        }
        return u;
    }
};
 
template<typename F, typename S>
constexpr auto accum_map_by(F f, const S& s) {
    return accum_map_by_<F, S>{ f, s };
}
 
template<typename S>
constexpr auto accum_map(const S& s = S()) {
    auto f = FR(x, y, y);
    return accum_map_by_<decltype(f), S>{ f, s };
}
 
template<typename F, typename S>
struct accum_unordered_map_by_ {
    using is_composable_ = void;
    F f; S s;
    template_for_iterable(T, I, V)
    decltype(auto) operator () (const T& v) const {
        std::unordered_map<std::decay_t<decltype(std::get<0>(std::declval<V>()))>, std::decay_t<std::invoke_result_t<F, S, decltype(std::get<1>(std::declval<V>()))>>> u;
        for(auto&& [i, x] : v) {
            if(u.count(i)) {
                u[i] = f(u[i], x);
            } else {
                u[i] = f(s, x);
            }
        }
        return u;
    }
};
 
template<typename F, typename S>
constexpr auto accum_unordered_map_by(F f, const S& s) {
    return accum_unordered_map_by_<F, S>{ f, s };
}
 
template<typename S>
constexpr auto accum_unordered_map(const S& s = S()) {
    auto f = FR(x, y, y);
    return accum_unordered_map_by_<decltype(f), S>{ f, s };
}
 
 


template<typename T>
constexpr auto istream_iterable(std::istream& in) {
    iterator_macro(
        std::istream& in; mutable T val; bool is_end; mutable bool has_read;,
        is_end xor other.is_end,
        { if(not(in >> val)) { is_end = true; } },
        (has_read) ? (val) : (has_read = true, in >> val, val)
    )
    return iterable_wrapper(Iterator{ in, T{}, false, false }, Iterator{ in, T{}, true, true });
}
 
template<typename T>
constexpr auto input = istream_iterable<T>(std::cin);
 
 


template<typename T>
std::ostream& print_iterable(std::ostream& out, const T& v, const std::string& sep = " ") {
    for(auto it = std::begin(v); it != std::end(v); ) {
        out << *it;
        ++it;
        if(it != std::end(v)) {
            out << sep;
        } else {
            return out;
        }
    }
    return out;
}
template<typename T, typename = typename T::is_iterable_wrapper>
constexpr std::ostream& operator << (std::ostream& out, const T& v) {
    return print_iterable(out, v);
}
 
#define def_iterable_ostream(I)                                     \
template<typename ...Ts>                                                \
std::ostream& operator << (std::ostream& out, const I<Ts...>& v) {      \
    return out << iter(v);                                          \
}
 
def_iterable_ostream(std::vector)
def_iterable_ostream(std::map)
def_iterable_ostream(std::unordered_map)
def_iterable_ostream(std::set)
def_iterable_ostream(std::unordered_set)
 


int _log2(int x) {
    if(x == 0) {
        return 0;
    }
    return 31 - __builtin_clz(x);
}
 
 


template<typename T, typename F>
class sparse_table {
private:
    std::vector<size_t> LOG2;
    F f;
    std::vector<std::vector<T>> st;
public:
    explicit sparse_table(F f_ = F()) : f(f_) { }
    template<typename I, typename = std::enable_if<is_iterable_v<I>>>
    explicit sparse_table(const I& v, F f_ = F()) : f(f_) {
        build(v);
    }
    template<typename I>
    void build(const I& v) {
        st.emplace_back(v > to_vector);
        size_t n = st[0].size();
        LOG2.assign(n + 1, 0);
        for(auto i : range(2, n + 1)) {
            LOG2[i] = LOG2[i / 2] + 1;
        }
        st.resize(LOG2[n] + 1);
        for(auto j : range(1, st.size())) {
            st[j].resize(n - (1 << j) + 1);
            for(auto i : range(st[j].size())) {
                st[j][i] = f(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    T range_query(size_t l, size_t r) const {
        auto j = LOG2[r - l];
        return f(st[j][l], st[j][r - (1 << j)]);
    }
};
 
template<typename T, typename F>
auto make_sparse_table(F f = F()) {
    return sparse_table<T, F>(f);
}
template<typename T, typename F, typename I>
auto make_sparse_table(const I& v, F f = F()) {
    return sparse_table<T, F>(v, f);
}
 
 


template<typename T, typename F, typename Finv>
class fenwick_tree {
private:
    size_t n, max_pow2;
    std::vector<T> ft;
    const T identity;
    F f;
    Finv finv;
public:
    explicit fenwick_tree(size_t n_, const T& identity_, F f_, Finv finv_) :
        n(n_), max_pow2(_log2(n)), ft(n, identity_), identity(identity_), f(f_), finv(finv_) { }
    template<typename I, typename = std::enable_if_t<is_iterable_v<I>>>
    explicit fenwick_tree(const I& v, const T& identity_, F f_, Finv finv_) : identity(identity_), f(f_), finv(finv_) {
        build(v);
    }
    template<typename I, typename = void>
    void build(const I& v) {
        auto v0 = v > to_vector;
        build(v0);
    }
    template<typename S>
    void build(const std::vector<S>& v) {
        n = v.size();
        max_pow2 = _log2(n);
        ft.assign(n, identity);
        for(const auto& [p, x] : enumerate(v)) {
            auto q = p | (p + 1);
            ft[p] = f(ft[p], x);
            if(q < n) {
                ft[q] = f(ft[q], ft[p]);
            }
        }
    }
    void point_update(size_t p, const T& v) {
        for(; p < n; p |= p + 1) {
            ft[p] = f(ft[p], v);
        }
    }
    T prefix_query(size_t p) const {
        int r = p;
        --r;
        T ans = identity;
        for(; r >= 0; r = (r & (r + 1)) - 1) {
            ans = f(ans, ft[r]);
        }
        return ans;
    }
    T range_query(size_t l, size_t r) const {
        return finv(prefix_query(r), prefix_query(r));
    }
    size_t lower_bound(const T& x) const {   

        T total = identity;
        if(total >= x) {
            return 0;
        }
        size_t ans = 0;
        for(size_t i = 1 << max_pow2; i > 0; i >>= 1) {
            if(ans + i - 1 < n and f(total, ft[ans + i - 1]) < x) {
                total = f(total, ft[ans + i - 1]);
                ans += i;
            }
        }
        return ans + 1;
    }
};
 
template<typename T, typename F = std::plus<T>, typename Finv = std::minus<T>>
auto make_fenwick_tree(size_t n, const T& identity = T(), F f = F(), Finv finv = Finv()) {
    return fenwick_tree<T, F, Finv>(n, identity, f, finv);
}
 
template<typename T, typename F = std::plus<T>, typename Finv = std::minus<T>, typename I, typename = std::enable_if_t<is_iterable_v<I>>>
auto make_fenwick_tree(const I& v, const T& identity = T(), F f = F(), Finv finv = Finv()) {
    return fenwick_tree<T, F, Finv>(v, identity, f, finv);
}
 
 


template<typename T, typename Merge>
class point_update_range_tree {
private:
    size_t n, max_pow2;
    std::vector<std::vector<T>> rt;
    const T identity;
    Merge merge;
public:
    explicit point_update_range_tree(size_t n_, const T& identity_, Merge merge_) : point_update_range_tree(identity_ > replicate(n_), identity_, merge_) { }
    template<typename I, typename = std::enable_if_t<is_iterable_v<I>>>
    explicit point_update_range_tree(const I& v, const T& identity_, Merge merge_) : identity(identity_), merge(merge_) {
        build(v);
    }
    template<typename I>
    void build(const I& v) {
        rt.emplace_back(v > to_vector);
        n = rt[0].size();
        max_pow2 = _log2(n);
        rt.resize(max_pow2 + 1);
        for(auto i : range(1, max_pow2 + 1)) {
            for(auto j : range(0, rt.back().size() / 2)) {
                rt[i][j] = merge(rt[i - 1][j * 2], rt[i - 1][j * 2 + 1]);
            }
        }
    }
    void point_update(size_t p, const T& v) {
        rt[0][p] = v;
        for(auto i : range(max_pow2)) {
            p /= 2;
            rt[i + 1][p] = merge(rt[i][p * 2], rt[i][p * 2 + 1]);
        }
    }
    T point_query(size_t p) const {
        return rt[0][p];
    }
    T full_query() const {
        return rt.back().back();
    }
    T range_query(size_t l, size_t r) {
        if(l >= r) {
            return identity;
        }
        T ans = identity;
        for(int i = 0; r - l >= (1 << i); ++i) {
            size_t j = 1 << i;
            if(l & j) {
                ans = merge(rt[i][l >> i], ans);
                l += j;
                if(l >= r) {
                    return ans;
                }
            }
            if(r & j) {
                r -= j;
                ans = merge(ans, rt[i][r >> i]);
            }
        }
        return ans;
    }
};
 
 
template<typename T, typename Merge>
auto make_point_update_range_tree(size_t n, const T& identity = T(), Merge merge = Merge()) {
    return point_update_range_tree<T, Merge>(n, identity, merge);
}
template<typename T, typename Merge, typename I, typename = std::enable_if_t<is_iterable_v<I>>>
auto make_point_update_range_tree(const I& v, const T& identity = T(), Merge merge = Merge()) {
    return point_update_range_tree<T, Merge>(v, identity, merge);
}
 
 


template<typename Idx>
struct interval {
    Idx l, r;
    bool contains(const interval& other) const {
        return l <= other.l and other.r <= r;
    }
    bool disjoint(const interval& other) const {
        return r <= other.l or other.r <= l;
    }
    void left_half() {
        r = (l + r) / 2;
    }
    void right_half() {
        l = (l + r) / 2;
    }
    Idx size() const {
        return r - l;
    }
};
 
template<typename Idx, typename T>
class contiguous_binary_tree {
private:
    const T id;
    std::vector<T> tree;
public:
    class iterator {
    private:
        contiguous_binary_tree<Idx, T>* tree_ptr;
        size_t j;
        interval<Idx> i;
    public:
        explicit iterator(contiguous_binary_tree<Idx, T>* t) : tree_ptr(t), j(1), i{0, Idx(t->size())} { }
        void go_left() {
            i.left_half();
            j = j * 2;
        }
        void go_right() {
            i.right_half();
            j = j * 2 + 1;
        }
        iterator left_child() const {
            iterator it(*this);
            it.go_left();
            return it;
        }
        iterator right_child() const {
            iterator it(*this);
            it.go_right();
            return it;
        }
        constexpr bool is_leaf() const {
            return i.size() == 1;
        }
        T& operator * () const {
            return tree_ptr->tree[j];
        }
        T* operator -> () const {
            return &(tree_ptr->tree[j]);
        }
        inline auto get_interval() const {
            return i;
        }
        constexpr Idx left_index() const {
            return i.l;
        }
        constexpr Idx right_index() const {
            return i.r;
        }
    };
    explicit contiguous_binary_tree(const T& id) : id(id) { }
    void build(Idx n) {
        tree.assign(1 << (_log2(n - 1) + 2), id);
    }
    constexpr Idx size() const {
        return tree.size() / 2;
    }
    iterator get_root() {
        return iterator(this);
    }
};
 
template<typename Idx, typename T>
class sparse_binary_tree {
private:
    struct vertex {
        T val;
        size_t l = 0, r = 0;
    };
    const T id;
    Idx sz;
    std::vector<vertex> tree;
    size_t new_vertex() {
        tree.push_back(vertex{ id, 0, 0 });
        return tree.size() - 1;
    }
    inline void propagate(size_t j) {
        if(tree[j].l == tree[j].r) {
            tree[j].l = new_vertex();
            tree[j].r = new_vertex();
        }
    }
public:
    class iterator {
    private:
        sparse_binary_tree<Idx, T>* tree_ptr;
        size_t j;
        interval<Idx> i;
    public:
        explicit iterator(sparse_binary_tree<Idx, T>* t) : tree_ptr(t), j(0), i{0, Idx(t->size())} { }
        void inline propagate() {
            tree_ptr->propagate(j);
        }
        void go_left() {
            propagate();
            i.left_half();
            j = tree_ptr->tree[j].l;
        }
        void go_right() {
            propagate();
            i.right_half();
            j = tree_ptr->tree[j].r;
        }
        iterator left_child() const {
            iterator it(*this);
            it.go_left();
            return it;
        }
        iterator right_child() const {
            iterator it(*this);
            it.go_right();
            return it;
        }
        constexpr bool is_leaf() const {
            return i.size() == 1;
        }
        T& operator * () const {
            return tree_ptr->tree[j].val;
        }
        T* operator -> () const {
            return &(tree_ptr->tree[j].val);
        }
        inline auto get_interval() const {
            return i;
        }
        constexpr Idx left_index() const {
            return i.l;
        }
        constexpr Idx right_index() const {
            return i.r;
        }
    };
    explicit sparse_binary_tree(const T& id) : id(id) { }
    void build(Idx n) {
        new_vertex();
        sz = n;
    }
    constexpr Idx size() const {
        return sz;
    }
    iterator get_root() {
        return iterator(this);
    }
};
 
template<typename Idx, typename T, template<typename, typename> typename BinaryTree, typename Operation>
class range_tree {
public:
    class iterator;
private:
    class vertex {
    private:
        bool pending_operation;
        Operation op;
    public:
        T val;
        explicit vertex(const T& val_) : pending_operation(false), val(val_) { }
        constexpr bool no_op() const {
            return not pending_operation;
        }
        void apply_operation(const Operation& new_op, Idx l, Idx r) {
            if(no_op()) {
                op = new_op;
                pending_operation = true;
            } else {
                op.append(new_op);
            }
            new_op.apply_to(val, l, r);
        }
        inline const Operation& get_operation() const {
            return op;
        }
        void delete_operation() {
            pending_operation = false;
        }
    };
    BinaryTree<Idx, vertex> bt;
    template<typename S>
    void internal_build(iterator it, const std::vector<S>& v) {
        if(it.get_interval().disjoint(interval<Idx>{0, Idx(v.size())})) {
            return;
        }
        if(it.is_leaf()) {
            it->val = v[it.left_index()];
            return;
        }
        internal_build(it.left_child(), v);
        internal_build(it.right_child(), v);
        it->val = Operation::merge(it.left_child()->val, it.right_child()->val);
    }
    T internal_range_query(iterator it, interval<Idx> i) {
        if(i.contains(it.get_interval())) {
            return it->val;
        }
        it.propagate();
        if(i.disjoint(it.left_child().get_interval())) {
            return internal_range_query(it.right_child(), i);
        }
        if(i.disjoint(it.right_child().get_interval())) {
            return internal_range_query(it.left_child(), i);
        }
        return Operation::merge(internal_range_query(it.left_child(), i), internal_range_query(it.right_child(), i));
    }
    void internal_range_update(iterator it, interval<Idx> i, const Operation& op) {
        if(i.contains(it.get_interval())) {
            it->apply_operation(op.restrict(it.left_index(), it.right_index(), i.l, i.r), it.left_index(), it.right_index());
            return;
        }
        it.propagate();
        if(not i.disjoint(it.left_child().get_interval())) {
            internal_range_update(it.left_child(), i, op);
        }
        if(not i.disjoint(it.right_child().get_interval())) {
            internal_range_update(it.right_child(), i, op);
        }
        it->val = Operation::merge(it.left_child()->val, it.right_child()->val);
    }
public:
    class iterator : public BinaryTree<Idx, vertex>::iterator {
        public:
        iterator(const typename BinaryTree<Idx, vertex>::iterator& other) : BinaryTree<Idx, vertex>::iterator(other) { }
        void propagate() {
            if((*this)->no_op()) {
                return;
            }
            Idx l = this->left_index(), r = this->right_index();
            Idx m = (l + r) / 2;
            this->left_child()->apply_operation((*this)->get_operation().restrict(l, m, l, r), l, m);
            this->right_child()->apply_operation((*this)->get_operation().restrict(m, r, l, r), m, r);
            (*this)->delete_operation();
        }
    };
    range_tree () : bt(Operation::identity) { }
    explicit range_tree(Idx n) : bt(vertex(Operation::identity)) {
        build(n);
    }
    template<typename I, typename = std::enable_if_t<is_iterable_v<I>>>
    explicit range_tree(const I& v) : bt(vertex(Operation::identity)) {
        build(v);
    }
    inline void build(Idx n) {
        bt.build(n);
    }
    template<typename I, typename = std::enable_if_t<is_iterable_v<I>>>
    inline void build(const I& v) {
        build(v > to_vector);
    }
    template<typename S>
    void build(const std::vector<S>& v) {
        bt.build(v.size());
        internal_build(bt.get_root(), v);
    }
    inline T full_query() {
        return bt.get_root()->val;
    }
    inline T full_query(iterator root) {
        return root->val;
    }
    inline T range_query(Idx l, Idx r) {
        return range_query(l, r, bt.get_root());
    }
    T range_query(Idx l, Idx r, iterator root) {
        interval<Idx> i{l, r};
        if(l < r and not i.disjoint(root.get_interval())) {
            return internal_range_query(root, i);
        }
        else {
            return Operation::identity;
        }
    }
    inline void range_update(Idx l, Idx r, const Operation& op) {
        range_update(l, r, op, bt.get_root());
    }
    void range_update(Idx l, Idx r, const Operation& op, iterator root) {
        interval<Idx> i{l, r};
        if(l < r and not i.disjoint(root.get_interval())) {
            internal_range_update(root, i, op);
        }
    }
};
 
template<typename Idx, typename T, template<typename, typename> typename BinaryTree, typename Operation>
auto make_range_tree() {
    return range_tree<Idx, T, BinaryTree, Operation>();
}
template<typename Idx, typename T, template<typename, typename> typename BinaryTree, typename Operation>
auto make_range_tree(Idx n) {
    return range_tree<Idx, T, BinaryTree, Operation>(n);
}
template<typename Idx, typename T, template<typename, typename> typename BinaryTree, typename Operation, typename I, typename = std::enable_if_t<is_iterable_v<I>>>
auto make_range_tree(const I& v) {
    return range_tree<Idx, T, BinaryTree, Operation>(v);
}
 


template<typename Idx, typename T>
struct range_tree_sum_operation {
    constexpr static T identity = 0;
    T v;
    static T merge(const T& x, const T& y) {
        return x + y;
    }
    void apply_to(T& x, Idx l, Idx r) const {
        x += v * (r - l);
    }
    void append(const range_tree_sum_operation& other) {
        v += other.v;
    }
    auto restrict(Idx, Idx, Idx, Idx) const {
        return *this;
    }
};
 
 


template<typename U, size_t i, size_t s>
std::ostream& ostream_tuple_helper_(std::ostream& out, const U& u) {
    if constexpr(i == 0) {
        out << "{ ";
    }
    out << std::get<i>(u);
    if constexpr(i + 1 < s) {
        out << ", ";
        return ostream_tuple_helper_<U, i + 1, s>(out, u);
    } else {
        return out << " }";
    }
}
 
template<typename ...Ts>
std::ostream& operator << (std::ostream& out, const std::tuple<Ts...>& u) {
    return ostream_tuple_helper_<decltype(u), 0, sizeof...(Ts)>(out, u);
}
 
template<typename T, typename S>
std::ostream& operator << (std::ostream& out, const std::pair<T, S>& p) {
    return out << std::tuple(p.first, p.second);
}
 
 
using namespace std;
 
struct Val {
    int fours, sevens, lis, lds;
};
struct Op {
    bool flip;
    constexpr static Val identity = {0, 0, 0, 0};
    static Val merge(Val x, Val y) {
        return {x.fours + y.fours,
            x.sevens + y.sevens,
            max(x.fours + y.lis, x.lis + y.sevens),
            max(x.sevens + y.lds, x.lds + y.fours)};
    }
    Op restrict(int, int, int, int) const {
        return *this;
    }
    void apply_to(Val& x, int, int) const {
        if(flip) {
            swap(x.fours, x.sevens);
            swap(x.lis, x.lds);
        }
    }
    void append(const Op& other) {
        flip ^= other.flip;
    }
};
 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    auto rt = make_range_tree<int, Val, sparse_binary_tree, Op>(input<char> > take(n) > apply(FV(c, (c == '4') ? (Val{1, 0, 1, 1}) : (Val{0, 1, 1, 1}))));
    while(m--) {
        string s;
        cin >> s;
        if(s[0] == 'c') {
            cout << rt.full_query().lis << "\n";
        } else {
            int l, r;
            cin >> l >> r;
            rt.range_update(l - 1, r, {true});
        }
    }
    return 0;
}