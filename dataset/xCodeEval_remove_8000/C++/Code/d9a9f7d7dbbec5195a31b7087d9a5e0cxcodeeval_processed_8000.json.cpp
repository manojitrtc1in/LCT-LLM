
































 
 

    template<a1 A1> \
    inline constexpr auto name
 

    template<a1 A1, a2 A2> \
    inline constexpr auto name
 

    template<a1 A1, a2 A2, a3 A3> \
    inline constexpr auto name
 

    template<a1 A1> \
    using name
 

    template<a1 A1, a2 A2> \
    using name
 

    template<a1 A1, a2 A2, a3 A3> \
    using name
 

    template<a1 A1> \
    inline constexpr auto name
 

    template<a1 A1, a2 A2> \
    inline constexpr auto name
 

    template<a1 A1, a2 A2, a3 A3> \
    inline constexpr auto name
 

    template<a1 A1> \
    using name
 

    template<a1 A1, a2 A2> \
    using name
 

    template<a1 A1, a2 A2, a3 A3> \
    using name
 





constexpr bool DEBUG = 0;

constexpr bool DEBUG = 1;

 




namespace uf
{
    inline namespace base
    {
        inline namespace sized
        {
            using u8 = std::uint8_t;
            using i8 = std::int8_t;
 
            using u16 = std::uint16_t;
            using i16 = std::int16_t;
 
            using u32 = std::uint32_t;
            using i32 = std::int32_t;
 
            using u64 = std::uint64_t;
            using i64 = std::int64_t;
        }
        

 
        enum class sfinae;
        inline constexpr sfinae SF{ 0 };
 
        template<typename... Ts>
        using sfinae_t = sfinae;
 
        template<bool X>
        using enif = std::enable_if_t<X, sfinae>;
 
        template<bool X>
        using disif = std::enable_if_t<!X, sfinae>;
 
        template<typename Tp>
        struct type_identity
        {
            using type = Tp;
        };
 
        template<auto N>
        using constant = std::integral_constant<decltype(N), N>;
 
        template<auto... Ns>
        struct sequence
        {
            static constexpr u64 size = sizeof...(Ns);
 
            template<auto N>
            static constexpr auto value = std::get<N>(std::tuple(Ns...));
 
            template<auto N>
            using type = std::tuple_element_t<N, std::tuple<decltype(Ns)...>>;
 
            template<typename Tp>
            using cast = sequence<static_cast<Tp>(Ns)...>;
 
            template<typename Tp>
            using cast_std = std::integer_sequence<Tp, Ns...>;
        };
    }
    

}




 



    template<a1 A1> \
    inline constexpr auto name
 

    template<a1 A1, a2 A2> \
    inline constexpr auto name
 

    template<a1 A1, a2 A2, a3 A3> \
    inline constexpr auto name
 

    template<a1 A1> \
    using name
 

    template<a1 A1, a2 A2> \
    using name
 

    template<a1 A1, a2 A2, a3 A3> \
    using name
 

    template<a1 A1> \
    inline constexpr auto name
 

    template<a1 A1, a2 A2> \
    inline constexpr auto name
 

    template<a1 A1, a2 A2, a3 A3> \
    inline constexpr auto name
 

    template<a1 A1> \
    using name
 

    template<a1 A1, a2 A2> \
    using name
 

    template<a1 A1, a2 A2, a3 A3> \
    using name
 
namespace uf::mt
{
    template<typename, typename Tp>
    constexpr auto&& id28(Tp&& x)
    {
        return std::forward<Tp>(x);
    }
 
    template<auto, typename Tp>
    constexpr auto&& id28(Tp&& x)
    {
        return std::forward<Tp>(x);
    }
 
    template<typename, typename Tp>
    constexpr Tp id28();
 
    template<auto, typename Tp>
    constexpr Tp id28();
 
    template<typename Tp>
    struct is_decayed : std::bool_constant<!std::is_const_v<Tp> && !std::is_volatile_v<Tp> && !std::is_reference_v<Tp>> { };
 
    DECLARE_N1(is_decayed, typename);
 
    template<typename F, typename... Ts>
    struct tpack_first : type_identity<F> { };
 
    DECLARE_T1S(tpack_first, typename...);
 
    template<auto N, auto... Ns>
    struct npack_first : constant<N> { };
 
    DECLARE_N2S(npack_first, auto, auto...);
 
    template<typename... Ts>
    struct tpack_last : type_identity<typename decltype((type_identity<Ts>{ }, ...))::type > { };
 
    DECLARE_T1S(tpack_last, typename...);
 
    template<auto... Ns>
    struct npack_last : constant<(Ns, ...)> { };
 
    DECLARE_N1S(npack_last, auto...);
 
    template<u64 N, typename... Ts>
    struct tpack_nth : type_identity<std::tuple_element_t<N, std::tuple<Ts...>>> { };
 
    DECLARE_T2S(tpack_nth, u64, typename...);
 
    template<u64 N, auto... Ns>
    struct npack_nth : constant<sequence<Ns...>::template nth<N>> { };
 
    DECLARE_N2S(npack_nth, u64, auto...);
 
    template<auto N, auto... Ns>
    struct is_npack_contain : std::bool_constant<((N == Ns) || ...)> { };
 
    DECLARE_N2S(is_npack_contain, auto, auto...);
 
    template<typename Tp, typename... Ts>
    struct is_tpack_contain : std::bool_constant<(std::is_same_v<Tp, Ts> || ...)> { };
 
    DECLARE_N2S(is_tpack_contain, typename, typename...);
 
    template<typename... Ts>
    struct is_tpack_same : std::bool_constant<(std::is_same_v<tpack_first_t<Ts...>, Ts> && ...)> { };
 
    DECLARE_N1S(is_tpack_same, typename...);
 
    template<auto... Ns>
    struct is_npack_same : std::bool_constant<((sequence<Ns...>::template value<0> == Ns) && ...)> { };
 
    DECLARE_N1S(is_npack_same, auto...);
 
    template<typename... Ts>
    struct is_tpack_different;
 
    template<typename First, typename... Ts>
    struct is_tpack_different<First, Ts...> : std::bool_constant<!(std::is_same_v<First, Ts> || ...) && is_tpack_different<Ts...>::value> { };
 
    template<typename First>
    struct is_tpack_different<First> : std::true_type { };
 
    template<>
    struct is_tpack_different<> : std::true_type { };
 
    DECLARE_N1S(is_tpack_different, typename...);
 
    inline namespace sequence_operations
    {
        template<typename S>
        struct seq_first : constant<S::template get<0>> { };
 
        DECLARE_N1(seq_first, typename);
 
        template<typename S>
        struct seq_last : constant<S::template get<S::size - 1>> { };
 
        DECLARE_N1(seq_last, typename);
 
        template<typename S, u64... Ns>
        struct seq_select : type_identity<sequence<S::template get<Ns>()...>> { };
 
        DECLARE_T2S(seq_select, typename, u64...);
 
        template<typename S1, typename S2>
        struct seq_select_seq;
 
        template<typename S1, auto... Ns>
        struct seq_select_seq<S1, sequence<Ns...>> : seq_select<S1, Ns...> { };
 
        DECLARE_T2(seq_select_seq, typename, typename);
 
        template<typename S, auto N>
        struct is_seq_contain;
 
        template<auto... Ns, auto N>
        struct is_seq_contain<sequence<Ns...>, N> : is_npack_contain<N, Ns...> { };
 
        DECLARE_N2(is_seq_contain, typename, auto);
 
        template<typename... Ts>
        struct seq_concat;
 
        template<>
        struct seq_concat<> : type_identity<sequence<>> { };
 
        template<auto... Ns>
        struct seq_concat<sequence<Ns...>> : type_identity<sequence<Ns...>> { };
 
        template<auto... Ns1, auto... Ns2, typename... Ts>
        struct seq_concat<sequence<Ns1...>, sequence<Ns2...>, Ts...> : seq_concat<sequence<Ns1..., Ns2...>, Ts...> { };
 
        DECLARE_T1S(seq_concat, typename...);
 
        template<typename S, auto... Ns>
        struct seq_push_back;
 
        template<auto... SArgs, auto... Ns>
        struct seq_push_back<sequence<SArgs...>, Ns...> : type_identity<sequence<SArgs..., Ns...>> { };
 
        DECLARE_T2S(seq_push_back, typename, auto...);
 
        template<typename S, auto... Ns>
        struct seq_push_front;
 
        template<auto... SArgs, auto... Ns>
        struct seq_push_front<sequence<SArgs...>, Ns...> : type_identity<sequence<Ns..., SArgs...>> { };
 
        DECLARE_T2S(seq_push_front, typename, auto...);
 
        template<auto V, u64 N>
        struct seq_one_value : type_identity<seq_concat_t<seq_push_back_t<sequence<>, V>, typename seq_one_value<V, N - 1>::type>> { };
 
        template<auto V>
        struct seq_one_value<V, 0> : type_identity<sequence<>> { };
 
        DECLARE_T2(seq_one_value, auto, u64);
 
        template<typename S>
        struct seq_reverse;
 
        template<auto N, auto... Ns>
        struct seq_reverse<sequence<N, Ns...>>
        {
            using type = seq_push_back_t<typename seq_reverse<sequence<Ns...>>::type, N>;
        };
 
        template<>
        struct seq_reverse<sequence<>> : type_identity<sequence<>> { };
 
        DECLARE_T1(seq_reverse, typename);
 
        template<auto B, auto E>
        struct seq_increasing
        {
            static_assert (B < E);
            using type = seq_concat_t<sequence<B>, typename seq_increasing<B + 1, E>::type>;
        };
 
        template<auto E>
        struct seq_increasing<E, E> : type_identity<sequence<>> { };
 
        template<u64 N>
        using make_sequence = typename seq_increasing<u64(0), u64(N)>::type;
 
        DECLARE_T2(seq_increasing, auto, auto);
 
        template<auto B, auto E>
        struct seq_decreasing
        {
            static_assert (i64(B) >= i64(E - 1));
            using type = seq_reverse_t<seq_increasing_t<E, B + 1>>;
        };
 
        DECLARE_T2(seq_decreasing, auto, auto);
 
        template<typename S, u64 N>
        struct seq_remove_front
        {
            using type = seq_select_seq_t<S, seq_increasing_t<N, S::size>>;
        };
 
        DECLARE_T2(seq_remove_front, typename, u64);
 
        template<typename S, u64 N>
        struct seq_remove_back
        {
            using type = seq_select_seq_t<S, make_sequence<S::size - N>>;
        };
 
        DECLARE_T2(seq_remove_back, typename, u64);
 
        template<typename S, auto... Ns>
        struct seq_remove;
 
        template<auto Arg, auto... Args, auto... Ns>
        struct seq_remove<sequence<Arg, Args...>, Ns...>
        {
            using type = std::conditional_t<((Arg == Ns) || ...),
                typename seq_remove<sequence<Args...>, Ns...>::type,
                seq_push_front_t<typename seq_remove<sequence<Args...>, Ns...>::type, Arg>>;
        };
 
        template<auto... Ns>
        struct seq_remove<sequence<>, Ns...> : type_identity<sequence<>> { };
 
        DECLARE_T2S(seq_remove, typename, auto...);
    }
    

 
    inline namespace tuple_operations
    {
        template<typename T>
        struct tuple_first : type_identity<std::tuple_element_t<0, T>> { };
 
        DECLARE_T1(tuple_first, typename);
 
        template<typename T>
        struct tuple_last : type_identity<std::tuple_element_t<std::tuple_size_v<T> -1, T>> { };
 
        DECLARE_T1(tuple_last, typename);
 
        template<typename T, u64... Ns>
        struct tuple_select : type_identity<std::tuple<std::tuple_element_t<Ns, T>...>> { };
 
        DECLARE_T2S(tuple_select, typename, u64...);
 
        template<typename T, typename S>
        struct tuple_select_seq;
 
        template<typename T, auto... Ns>
        struct tuple_select_seq<T, sequence<Ns...>> : tuple_select<T, Ns...> { };
 
        DECLARE_T2(tuple_select_seq, typename, typename);
 
        template<typename T, typename Tp>
        struct is_tuple_contain;
 
        template<typename... Ts, typename Tp>
        struct is_tuple_contain<std::tuple<Ts...>, Tp> : is_tpack_contain<Tp, Ts...> { };
 
        DECLARE_N2(is_tuple_contain, typename, typename);
 
        template<typename... Ts>
        struct tuple_concat;
 
        template<>
        struct tuple_concat<> : type_identity<std::tuple<>> { };
 
        template<typename... Ts>
        struct tuple_concat<std::tuple<Ts...>> : type_identity<std::tuple<Ts...>> { };
 
        template<typename... Ts1, typename... Ts2, typename... Ts>
        struct tuple_concat<std::tuple<Ts1...>, std::tuple<Ts2...>, Ts...> : tuple_concat<std::tuple<Ts1..., Ts2...>, Ts...> { };
 
        DECLARE_T1S(tuple_concat, typename...);
 
        template<typename T, typename... Ts>
        struct tuple_push_back;
 
        template<typename... TArgs, typename... Ts>
        struct tuple_push_back<std::tuple<TArgs...>, Ts...> : type_identity<std::tuple<TArgs..., Ts...>> { };
 
        DECLARE_T2S(tuple_push_back, typename, typename...);
 
        template<typename T, typename... Ts>
        struct tuple_push_front;
 
        template<typename... TArgs, typename... Ts>
        struct tuple_push_front<std::tuple<TArgs...>, Ts...>
        {
            using type = std::tuple<Ts..., TArgs...>;
        };
 
        DECLARE_T2S(tuple_push_front, typename, typename...);
 
        template<typename T, u64 N>
        struct tuple_one_type : type_identity<tuple_concat_t<tuple_push_back_t<std::tuple<>, T>, typename tuple_one_type<T, N - 1>::type>> { };
 
        template<typename T>
        struct tuple_one_type<T, 0> : type_identity<std::tuple<>> { };
 
        DECLARE_T2(tuple_one_type, typename, u64);
 
        template<typename T>
        struct tuple_reverse;
 
        template<typename T1, typename... Ts>
        struct tuple_reverse<std::tuple<T1, Ts...>>
        {
            using type = tuple_push_back_t<typename tuple_reverse<std::tuple<Ts...>>::type, T1>;
        };
 
        DECLARE_T1(tuple_reverse, typename);
 
        template<typename T, u64 N>
        struct tuple_remove_front
        {
            using type = tuple_select_seq_t<T, seq_increasing_t<N, std::tuple_size_v<T>>>;
        };
 
        DECLARE_T2(tuple_remove_front, typename, u64);
 
        template<typename T, u64 N>
        struct tuple_remove_back
        {
            using type = tuple_select_seq_t<T, make_sequence<std::tuple_size_v<T> -N>>;
        };
 
        DECLARE_T2(tuple_remove_back, typename, u64);
 
        template<typename T, typename... Ts>
        struct tuple_remove;
 
        template<typename Arg, typename... Args, typename... Ts>
        struct tuple_remove<std::tuple<Arg, Args...>, Ts...>
        {
            using type = std::conditional_t<((std::is_same_v<Arg, Ts>) || ...),
                typename tuple_remove<std::tuple<Args...>, Ts...>::type,
                tuple_push_front_t<typename tuple_remove<std::tuple<Args...>, Ts...>::type, Arg>>;
        };
 
        template<typename... Ts>
        struct tuple_remove<std::tuple<>, Ts...> : type_identity<std::tuple<>> { };
 
        DECLARE_T2S(tuple_remove, typename, typename...);
    }
    

 
    template<typename Tp>
    struct is_instantiated : std::false_type { };
 
    template<template<typename...> typename Tp, typename... Ts>
    struct is_instantiated<Tp<Ts...>> : std::true_type { };
 
    DECLARE_N1(is_instantiated, typename);
 
    template<typename A, typename B>
    struct is_instantiated_from_same : std::false_type { };
 
    template<template<typename...> typename Tp, typename... A, typename... B>
    struct is_instantiated_from_same<Tp<A...>, Tp<B...>> : std::true_type { };
 
    DECLARE_N2(is_instantiated_from_same, typename, typename);
 
    template<template<typename...> typename Expected, typename Tested>
    struct is_instantiated_from : std::false_type { };
 
    template<template<typename...> typename Expected, typename... Ts>
    struct is_instantiated_from<Expected, Expected<Ts...>> : std::true_type { };
 
    DECLARE_N2(is_instantiated_from, template<typename...> typename, typename);
 
    template<typename Tp>
    struct instance_info;
 
    template<template<typename...> typename Tp, typename... Ts>
    struct instance_info<Tp<Ts...>>
    {
        static constexpr u64 args = sizeof...(Ts);
 
        template<typename... Ts_>
        using type = Tp<Ts_...>;
 
        template<u64 N>
        using nth = std::tuple_element_t<N, std::tuple<Ts...>>;
    };
 
    template<template<typename...> typename Template, typename T>
    struct instance_from_tuple;
 
    template<template<typename...> typename Template, typename... Ts>
    struct instance_from_tuple<Template, std::tuple<Ts...>> : type_identity<Template<Ts...>> { };
 
    DECLARE_T2(instance_from_tuple, template<typename...> typename, typename);
 
    template<class F>
    struct function_info;
 
    template<typename R, typename... Args>
    struct function_info<R(Args...)>
    {
        static constexpr u64 arity = sizeof...(Args);
 
        using result = R;
 
        template<u64 N>
        using nth = std::tuple_element_t<N, std::tuple<Args...>>;
    };
 
    template<typename R, typename... Args>
    struct function_info<std::function<R(Args...)>> : function_info<R(Args...)> { };
 
    template<typename R, typename... Args>
    struct function_info<R(*)(Args...)> : function_info<R(Args...)> { };
 
    template<class C, typename R, typename... Args>
    struct function_info<R(C::*)(Args...)> : function_info<R(Args...)> { };
 
    

    template<class Tp, typename = sfinae>
    struct is_iterable : std::false_type { };
 
    template<class Tp>
    struct is_iterable<Tp, sfinae_t<decltype(*std::begin(std::declval<Tp>())), decltype(std::end(std::declval<Tp>()))>> : std::true_type { };
 
    DECLARE_N1(is_iterable, typename);
 
    template<typename Tp, typename = sfinae>
    struct is_dereferenceable : std::false_type { };
 
    template<typename Tp>
    struct is_dereferenceable<Tp, sfinae_t<decltype(*std::declval<Tp>())>> : std::true_type { };
 
    DECLARE_N1(is_dereferenceable, typename);
 
    

    template<typename S>
    struct is_sequence : std::false_type { };
 
    template<auto... Ns>
    struct is_sequence<sequence<Ns...>> : std::true_type { };
 
    DECLARE_N1(is_sequence, typename);
 
    template<typename S>
    struct is_positive_sequence : std::false_type { };
 
    template<auto... Ns>
    struct is_positive_sequence<sequence<Ns...>> : std::bool_constant<((Ns >= 0) && ...)> { };
 
    DECLARE_N1(is_positive_sequence, typename);
 
    template<typename Tp>
    struct is_smart_pointer : std::bool_constant<is_instantiated_from_v<std::unique_ptr, Tp> || is_instantiated_from_v<std::shared_ptr, Tp> || is_instantiated_from_v<std::weak_ptr, Tp>> { };
 
    DECLARE_N1(is_smart_pointer, typename);
 
    template<typename Tp, typename = sfinae>
    struct is_iterator : std::false_type { };
 
    template<typename Tp>
    struct is_iterator<Tp, sfinae_t<typename std::iterator_traits<Tp>::iterator_category>> : std::true_type { };
 
    DECLARE_N1(is_iterator, typename);
 
    template<typename Tp>
    struct is_reverse_iterator : std::bool_constant<is_instantiated_from_v<std::reverse_iterator, Tp>> { };
 
    DECLARE_N1(is_reverse_iterator, typename);
 
    template<typename Tp>
    struct is_usual_iterator : std::bool_constant<is_iterator_v<Tp> && !is_reverse_iterator_v<Tp>> { };
 
    DECLARE_N1(is_usual_iterator, typename);
 
    template<typename Tp, typename = sfinae>
    struct is_random_access_iterator : std::false_type { };
 
    template<typename Tp>
    struct is_random_access_iterator<Tp, enif<std::is_same_v<typename std::iterator_traits<Tp>::iterator_category, std::random_access_iterator_tag>>> : std::true_type { };
 
    DECLARE_N1(is_random_access_iterator, typename);
 
    template<typename Tp, typename = sfinae>
    struct is_random_access_container : std::false_type { };
 
    template<typename Tp>
    struct is_random_access_container<Tp, enif<is_iterable_v<Tp>>> : is_random_access_iterator<typename std::remove_reference_t<Tp>::iterator> { };
 
    DECLARE_N1(is_random_access_container, typename);
}


 
namespace uf
{
    using mt::make_sequence;
}


 














 


namespace uf
{
    namespace detail
    {
        template<typename Tp, u64... Ns>
        constexpr auto id10(Tp&& value, sequence<Ns...>)
        {
            return std::make_tuple(mt::id28<Ns>(value)...);
        }
 
        template<u64 N, typename F, typename... Ts>
        constexpr void id33(F&& f, Ts&&... ts)
        {
            if constexpr (N < std::tuple_size_v<mt::tpack_first_t<std::decay_t<Ts>...>>)
            {
                std::invoke(f, std::get<N>(std::forward<Ts>(ts))...);
                id33<N + 1>(f, std::forward<Ts>(ts)...);
            }
        }
 
        template<u64 N, typename F, typename... Ts>
        constexpr auto id9(F&& f, Ts&&... ts)
        {
            return std::invoke(f, std::get<N>(std::forward<Ts>(ts))...);
        }
 
        template<typename F, typename... Ts, u64... Ns>
        constexpr auto id2(sequence<Ns...>, F&& f, Ts&&... ts)
        {
            return std::make_tuple(id9<Ns>(f, std::forward<Ts>(ts)...)...);
        }
 
        template<typename T, auto... Ns>
        constexpr auto id16(T&& t, sequence<Ns...>)
        {
            return std::tuple<decltype(std::get<Ns>(std::forward<T>(t)))...>(std::get<Ns>(std::forward<T>(t))...);
        }
 
        template<typename T, auto... Ns>
        constexpr auto id23(T&& t, sequence<Ns...>)
        {
            return std::make_tuple(std::get<Ns>(std::forward<T>(t))...);
        }
    }
    

 
    inline namespace utils
    {
        template<typename Container, typename E, enif<std::is_lvalue_reference_v<Container>> = SF>
        constexpr auto&& forward_element(E&& e) noexcept
        {
            return std::forward<E>(e);
        }
 
        template<typename Container, typename E, enif<!std::is_reference_v<Container>> = SF>
        constexpr auto&& forward_element(E&& e) noexcept
        {
            return std::move(e);
        }
 
        template<typename E, typename P>
        constexpr bool stf(const E& e, P&& p)
        {
            if constexpr (std::is_invocable_v<std::remove_reference_t<P>, const E&>)
                return std::invoke(p, e);
            else
                return e == p;
        }
 
        template<class E, class... Ps>
        constexpr bool id40(const E& e, Ps&&... ps)
        {
            return (stf(e, ps) || ...);
        }
 
        template<class E, class... Ps>
        constexpr bool id5(const E& e, Ps&&... ps)
        {
            return (stf(e, ps) && ...);
        }
 
        template<class... Ps>
        constexpr auto id24(Ps&&... ps)
        {
            return[ps...](const auto& e) mutable { return id40(e, ps...); }; 

        }
 
        template<class... Ps>
        constexpr auto id37(Ps&&... ps)
        {
            return[ps...](const auto& e) mutable { return id5(e, ps...); }; 

        }
 
        template<typename P>
        auto id39(P&& p)
        {
            return[p = std::forward<P>(p)](const auto& x) mutable { return stf(x.first, p); };
        }
 
        template<typename P>
        auto id27(P&& p)
        {
            return[p = std::forward<P>(p)](const auto& x) mutable { return stf(x.second, p); };
        }
 
        template<u64 N, typename P>
        auto id21(P&& p)
        {
            return[p = std::forward<P>(p)](const auto& x) mutable { return stf(std::get<N>(x), p); };
        }
 
        template<u64 N, typename Tp>
        constexpr auto id25(Tp&& value)
        {
            return detail::id10(std::forward<Tp>(value), make_sequence<N>());
        }
 
        template<typename F, typename... Ts>
        constexpr void id12(F&& f, Ts&&... ts)
        {
            constexpr u64 size = std::tuple_size_v<std::remove_reference_t<mt::tpack_first_t<Ts...>>>;
            static_assert (((std::tuple_size_v<std::remove_reference_t<Ts>> == size) && ...));
            detail::id33<0>(std::forward<F>(f), std::forward<Ts>(ts)...);
        }
 
        template<typename F, typename... Ts>
        constexpr auto tuple_transform(F&& f, Ts&&... ts)
        {
            constexpr u64 size = std::tuple_size_v<std::remove_reference_t<mt::tpack_first_t<Ts...>>>;
            static_assert (((std::tuple_size_v<std::remove_reference_t<Ts>> == size) && ...));
            return detail::id2(make_sequence<size>(), std::forward<F>(f), std::forward<Ts>(ts)...);
        }
 
        template<typename RandomAccessIterator, typename Compare>
        std::vector<u64> sort_indexes(RandomAccessIterator begin, RandomAccessIterator end, Compare&& cmp)
        {
            std::vector<u64> pos(std::distance(begin, end));
            std::iota(pos.begin(), pos.end(), 0);
            std::stable_sort(pos.begin(), pos.end(), [&begin, &cmp](const auto& e1, const auto& e2)
            {
                return cmp(*(begin + e1), *(begin + e2));
            });
            return pos;
        }
 
        template<class Associative, class... Rs>
        void id19(Associative& c, Rs&&... rs)
        {
            for (auto i = c.begin(); i != c.end();)
            {
                if (id40(*i, rs...))
                    i = c.erase(i);
                else
                    ++i;
            }
        }
 
        template<class Associative, class... Rs>
        Associative id42(const Associative& c, Rs&&... rs)
        {
            Associative result;
            for (auto i = c.begin(); i != c.end(); ++i)
                if (!id40(*i, rs...))
                    result.insert(*i);
            return result;
        }
 
        template<typename Index, typename Tp, class F>
        std::pair<bool, Index> id29(Index begin, Index end, Tp&& value, F&& f)
        {
            const auto diff = end - begin;
            if (!diff)
                return { false, end };
            if (diff == 1)
                return { f(begin) == value, begin };
            if (diff == 2)
            {
                const auto x = f(begin + 1);
                if (x == value)
                    return { true, begin + 1 };
                return { f(begin) == value, begin };
            }
            const Index middle = begin + (end - begin) / 2;
            if (value >= f(middle))
                return id29(middle, end, value, f);
            return id29(begin, middle, value, f);
        }
 
        template<typename Index, typename Tp, class F>
        std::pair<bool, Index> id4(Index begin, Index end, Tp&& value, F&& f)
        {
            const auto diff = end - begin;
            if (!diff)
                return { false, end };
            if (diff == 1)
                return { f(begin) == value, begin };
            if (diff == 2)
            {
                const auto x = f(begin);
                if (x == value)
                    return { true, begin };
                return { f(begin + 1) == value, begin + 1 };
            }
            const Index middle = begin + (end - begin) / 2;
            if (value <= f(middle))
                return id4(begin, middle + 1, value, f);
            return id4(middle + 1, end, value, f);
        }
 
        template<typename T, enif<std::is_pointer_v<std::decay_t<T>>> = SF>
        constexpr auto* id30(T&& object)
        {
            return object;
        }
 
        template<typename T, enif<mt::is_usual_iterator_v<std::decay_t<T>> && !std::is_pointer_v<std::decay_t<T>>> = SF>
        constexpr auto* id30(T&& object)
        {
            return object.base();
        }
 
        template<typename T, enif<mt::is_reverse_iterator_v<std::decay_t<T>>> = SF>
        constexpr auto* id30(T&& object)
        {
            return id30(std::prev(object.base()));
        }
 
        template<typename T, enif<mt::is_smart_pointer_v<std::decay_t<T>>> = SF>
        constexpr auto* id30(T&& object)
        {
            return object.get();
        }
 
        template<u64 B = 0, u64 E = std::numeric_limits<u64>::max(), typename T>
        auto id8(T&& t)
        {
            constexpr u64 size = std::tuple_size_v<std::remove_reference_t<T>>;
            if constexpr (E > size)
                return detail::id16(std::forward<T>(t), mt::seq_increasing_t<B, size>());
            else
                return detail::id16(std::forward<T>(t), mt::seq_increasing_t<B, E>());
        }
 
        template<u64 B = 0, u64 E = std::numeric_limits<u64>::max(), typename T>
        auto subtuple(T&& t)
        {
            constexpr u64 size = std::tuple_size_v<std::remove_reference_t<T>>;
            if constexpr (E > size)
                return detail::id23(std::forward<T>(t), mt::seq_increasing_t<B, size>());
            else
                return detail::id23(std::forward<T>(t), mt::seq_increasing_t<B, E>());
        }
 
        template<u64... Ns, typename T>
        auto id35(T&& t)
        {
            return detail::id23(std::forward<T>(t), sequence<Ns...>());
        }
 
        template<u64... Ns, typename T>
        auto id20(T&& t)
        {
            return detail::id16(std::forward<T>(t), sequence<Ns...>());
        }
 
        template<u64... Ns, typename T>
        auto id26(T&& t)
        {
            return detail::id23(std::forward<T>(t), mt::seq_remove_t<make_sequence<std::tuple_size_v<std::decay_t<T>>>, Ns...>());
        }
 
        template<u64... Ns, typename T>
        auto id13(T&& t)
        {
            return detail::id16(std::forward<T>(t), mt::seq_remove_t<make_sequence<std::tuple_size_v<std::decay_t<T>>>, Ns...>());
        }
 
        template<typename Tp>
        auto get_unique(Tp&& obj)
        {
            return std::make_unique<std::remove_reference_t<Tp>>(std::forward<Tp>(obj));
        }
 
        template<typename Tp>
        auto get_shared(Tp&& obj)
        {
            return std::make_shared<std::remove_reference_t<Tp>>(std::forward<Tp>(obj));
        }
 
        template<class Container>
        class id6;
 
        template<class Container>
        class id6<Container&>
        {
        protected:
            Container& container_;
 
        public:
            id6(Container& lref) : container_(lref) { }
        };
 
        template<class Container>
        class id6<Container&&>
        {
        protected:
            Container container_;
 
        public:
            id6(Container&& rref) : container_(std::move(rref)) { }
        };
 
        template<class Container>
        class reverse_wrapper : public id6<Container>
        {
        public:
            template<typename C>
            reverse_wrapper(C&& container) : id6<Container>(std::forward<C>(container)) { }
 
            auto begin()
            {
                return id6<Container>::container_.rbegin();
            }
 
            auto end()
            {
                return id6<Container>::container_.rend();
            }
        };
 
        template<typename C>
        reverse_wrapper(C&&)->reverse_wrapper<C&&>;
 
        class spinlock
        {
            std::atomic_flag flag_ = ATOMIC_FLAG_INIT;
 
        public:
            bool try_lock()
            {
                return !flag_.test_and_set(std::memory_order_acquire);
            }
 
            template<typename Duration>
            void lock(Duration duration)
            {
                while (flag_.test_and_set(std::memory_order_acquire))
                    std::this_thread::sleep_for(duration);
            }
 
            void lock()
            {
                while (flag_.test_and_set(std::memory_order_acquire))
                    std::this_thread::yield();
            }
 
            void unlock()
            {
                flag_.clear(std::memory_order_release);
            }
        };
    }
    

}




 


namespace uf
{
    namespace detail
    {
 
    }
    

 
    inline namespace strings
    {
        inline std::string lowercase(const std::string& s)
        {
            std::string result;
            result.reserve(s.size());
            for (auto c : s)
                result.push_back(std::tolower(c));
            return result;
        }
 
        inline std::string lowercase(std::string&& s)
        {
            std::string result(std::move(s));
            for (auto& c : result)
                c = std::tolower(c);
            return result;
        }
 
        inline std::string uppercase(const std::string& s)
        {
            std::string result;
            result.reserve(s.size());
            for (auto c : s)
                result.push_back(std::toupper(c));
            return result;
        }
 
        inline std::string uppercase(std::string&& s)
        {
            std::string result(std::move(s));
            for (auto& c : result)
                c = std::toupper(c);
            return result;
        }
 
        template<class SeqContainer, typename... Ps>
        auto lstrip(const SeqContainer& c, Ps&&... ps)
        {
            auto new_first = c.begin();
            while (new_first != c.end() && id40(*new_first, ps...))
                ++new_first;
            return SeqContainer(new_first, c.end());
        }
 
        template<class SeqContainer, typename... Ps>
        auto rstrip(const SeqContainer& c, Ps&&... ps)
        {
            auto new_last = c.rbegin();
            while (new_last != c.rend() && id40(*new_last, ps...))
                ++new_last;
            return SeqContainer(c.begin(), new_last.base());
        }
 
        template<class SeqContainer, typename... Ps>
        auto strip(const SeqContainer& c, Ps&&... ps)
        {
            auto new_first = c.begin();
            while (new_first != c.end() && id40(*new_first, ps...))
                ++new_first;
            auto new_last = c.rbegin();
            while (new_last != c.rend() && id40(*new_last, ps...))
                ++new_last;
            if (new_last.base() <= new_first)
                return SeqContainer{ };
            return SeqContainer(new_first, new_last.base());
        }
 
        template<class SeqContainer, typename... Ds>
        auto id43(const SeqContainer& c, u64 n, Ds&&... ds)
        {
            using iter = typename SeqContainer::const_iterator;
 
            std::vector<std::pair<iter, iter>> result;
            auto&& fobject = id24(std::forward<Ds>(ds)...);
            const auto wrp = std::ref(fobject);
            for (iter next_begin = std::find_if_not(c.begin(), c.end(), wrp); n && next_begin != c.end();)
            {
                iter id38 = std::find_if(std::next(next_begin), c.end(), wrp);
                result.push_back({ next_begin, id38 });
                if (id38 == c.end())
                    break;
                next_begin = std::find_if_not(std::next(id38), c.end(), wrp);
                --n;
            }
            return result;
        }
 
        template<class SeqContainer, typename... Ds>
        auto split_itr(const SeqContainer& c, Ds&&... ds)
        {
            return id43(c, std::numeric_limits<u64>::max(), ds...);
        }
 
        template<class SeqContainer>
        auto id32(const std::vector<std::pair<typename SeqContainer::const_iterator, typename SeqContainer::const_iterator>>& bounds)
        {
            std::vector<SeqContainer> result;
            result.reserve(bounds.size());
            for (auto [b, e] : bounds)
                result.emplace_back(b, e);
            return result;
        }
 
        template<class SeqContainer, typename... Ds>
        auto split_n(const SeqContainer& c, u64 n, Ds&&... ds)
        {
            return id32<SeqContainer>(id43(c, n, ds...));
        }
 
        template<class SeqContainer, typename... Ds>
        auto split(const SeqContainer& c, Ds&&... ds)
        {
            return split_n(c, std::numeric_limits<u64>::max(), ds...);
        }
 
        template<class C1, class C2, disif<std::is_convertible_v<C2, typename C1::value_type>> = SF>
        bool starts_with(const C1& c, const C2& pattern)
        {
            auto i1 = std::begin(c);
            auto i2 = std::begin(pattern);
            for (; i1 != std::end(c) && i2 != std::end(pattern); ++i1, ++i2)
                if (*i1 != *i2)
                    return false;
            return i2 == std::end(pattern) ? true : false;
        }
 
        template<class C, class E, enif<std::is_convertible_v<E, typename C::value_type>> = SF>
        bool starts_with(const C& c, const E& e)
        {
            return !c.empty() && *std::begin(c) == e;
        }
 
        template<class C1, class C2, disif<std::is_convertible_v<C2, typename C1::value_type>> = SF>
        bool ends_with(const C1& c, const C2& pattern)
        {
            auto i1 = std::rbegin(c);
            auto i2 = std::rbegin(pattern);
            for (; i1 != std::rend(c) && i2 != std::rend(pattern); ++i1, ++i2)
                if (*i1 != *i2)
                    return false;
            return i2 == std::rend(pattern) ? true : false;
        }
 
        template<class C, class E, enif<std::is_convertible_v<E, typename C::value_type>> = SF>
        bool ends_with(const C& c, const E& e)
        {
            return !c.empty() && *std::rbegin(c) == e;
        }
 
        template<class C, u64 N>
        bool starts_with(const C& c, const char(&literal)[N])
        {
            return starts_with(c, std::string_view(literal, N - 1));
        }
 
        template<class C, u64 N>
        bool ends_with(const C& c, const char(&literal)[N])
        {
            return ends_with(c, std::string_view(literal, N - 1));
        }
    }
    

}




 


namespace uf
{
    template<typename Tp>
    class span
    {
        static_assert(std::is_same_v<std::remove_volatile_t<std::remove_reference_t<Tp>>, Tp>, "Span must have a non-reference, non-volatile value_type");
 
    public:
        using value_type = Tp;
        using pointer = value_type*;
        using const_pointer = const value_type*;
        using reference = value_type&;
        using const_reference = const value_type&;
        using iterator = pointer;
        using const_iterator = const_pointer;
        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;
 
    private:
        pointer m_data = nullptr;
        u64 m_size = 0;
 
    public:
        constexpr span() noexcept = default;
 
        constexpr span(pointer begin, u64 count) : m_data(begin), m_size(count) { }
 
        constexpr span(pointer begin, pointer end) : span(begin, end < begin ? 0 : end - begin)
        {
            if ((reinterpret_cast<u64>(end) - reinterpret_cast<u64>(begin)) % sizeof(value_type))
                throw std::out_of_range("span::span: Invalid [begin, end) range");
        }
 
        template<class C>
        span(C&& c) : span(c.data(), c.size())
        {
            static_assert (std::is_lvalue_reference_v<C> || mt::is_instantiated_from_v<uf::span, std::decay_t<C>>, "Attempt to create span from rvalue");
        }
 
        template<u64 N>
        constexpr span(value_type(&arr)[N]) : span(arr, N) { }
 
        constexpr void clear() noexcept
        {
            m_data = nullptr;
            m_size = 0;
        }
 
        constexpr u64 size() const noexcept
        {
            return m_size;
        }
 
        constexpr bool empty() const noexcept
        {
            return !m_size;
        }
 
        constexpr span subspan(u64 begin, u64 count = std::numeric_limits<u64>::max()) const
        {
            if (count == std::numeric_limits<u64>::max())
                return span(m_data + begin, m_data + m_size);
            return span(m_data + begin, m_data + begin + count);
        }
 
        constexpr reference front() const
        {
            return m_data[0];
        }
 
        constexpr reference back() const
        {
            return m_data[m_size - 1];
        }
 
        constexpr pointer data() const noexcept
        {
            return m_data;
        }
 
        constexpr reference operator[](u64 i) const
        {
            return m_data[i];
        }
 
        constexpr reference at(u64 i) const
        {
            if (i >= m_size)
                throw std::out_of_range("span: Out of range, index = " + std::to_string(i) + ", but size = " + std::to_string(size()));
            return operator[](i);
        }
 
        constexpr iterator begin() const noexcept
        {
            return m_data;
        }
 
        constexpr iterator end() const noexcept
        {
            return m_data + m_size;
        }
 
        constexpr const_iterator cbegin() const noexcept
        {
            return m_data;
        }
 
        constexpr const_iterator cend() const noexcept
        {
            return m_data + m_size;
        }
 
        constexpr reverse_iterator rbegin() const noexcept
        {
            return reverse_iterator(m_data + m_size);
        }
 
        constexpr reverse_iterator rend() const noexcept
        {
            return reverse_iterator(m_data);
        }
 
        constexpr const_reverse_iterator crbegin() const noexcept
        {
            return reverse_iterator(m_data + m_size);
        }
 
        constexpr const_reverse_iterator crend() const noexcept
        {
            return reverse_iterator(m_data);
        }
    };
 
    template<typename C>
    span(C&& c)->span<std::remove_pointer_t<decltype(c.data())>>;
}




 


using uf::span;
using namespace std;
using namespace uf::sized;
using namespace uf::utils;
using namespace uf::strings;
 
template<class M, class Compare>
auto invert_map(M&& m, Compare&& comp)
{
    using rr = remove_reference_t<M>;
    using key_type = typename rr::key_type;
    using value_type = typename rr::mapped_type;
 
    multimap<value_type, key_type, function<bool(const value_type&, const value_type&)>> result(forward<Compare>(comp));
    for (const auto& [k, v] : m)
        result.insert(make_pair(forward_element<M>(const_cast<value_type&>(v)), forward_element<M>(const_cast<key_type&>(k))));
    return result;
}
 
template<class M>
auto id1(M&& m)
{
    using rr = typename remove_reference<M>::type;
    using key_type = typename rr::key_type;
    using value_type = typename rr::mapped_type;
 
    unordered_multimap<value_type, key_type> result;
    for (const auto& [k, v] : m)
        result.insert(make_pair(forward_element<M>(const_cast<value_type&>(v)), forward_element<M>(const_cast<key_type&>(k))));
    return result;
}

template<typename T>
pair<T*, T*> partition(T* begin, T* end)
{
    T base = *(begin + ((end - begin) >> 1));
    
    T* cur_l = begin;
    T* cur_r;
    
    cur_r = end - 1;
    while (true)
    {
        while (cur_l < cur_r && *cur_l < base)
            ++cur_l;
        while (cur_r > cur_l && *cur_r >= base)
            --cur_r;
        if (cur_l == cur_r)
            break;
        swap(*cur_l, *cur_r);
    }
    
    T* const lower_end = cur_l;
    
    cur_r = end - 1;
    while (true)
    {
        while (cur_l < cur_r && *cur_l == base)
            ++cur_l;
        while (cur_r > cur_l && *cur_r > base)
            --cur_r;
        if (cur_l == cur_r)
            break;
        swap(*cur_l, *cur_r);
    }
    
    T* const equal_end = cur_l;
    
    return {lower_end, equal_end};
}
 




template<typename Tp>
using vector2d = vector<vector<Tp>>;
 
template<typename Tp>
void read_value(Tp& v)
{
    cin >> v;
    cin.ignore(1);
}
 
void read_value(std::string& s)
{
    getline(cin, s);
}
 
void read_value(char& c)
{
    cin.get(c);
}
 
template<typename T1, typename T2>
void read_value(pair<T1, T2>& p)
{
    read_value(p.first);
    read_value(p.second);
}
 
template<typename... Ts>
void read_value(tuple<Ts...>& t)
{
    id12([](auto& elem) { read_value(elem); }, t);
}
 
template<typename Tp>
Tp read_value()
{
    Tp x;
    read_value(x);
    return x;
}
 
char read_char()
{
    return read_value<char>();
}
 
u64 id36()
{
    return read_value<u64>();
}
 
i64 id41()
{
    return read_value<i64>();
}
 
string read_string()
{
    return read_value<string>();
}
 
template<typename... Ts>
tuple<Ts...> read_tuple()
{
    tuple<Ts...> result;
    read_value(result);
    return result;
}
 
template<typename Tp, u64 N, typename... Ts>
auto read_tuple()
{
    if constexpr (!N)
        return read_tuple<Ts...>();
    else
        return read_tuple<Tp, N - 1, Tp, Ts...>();
}

template<typename T1, typename T2>
pair<T1, T2> read_pair()
{
    pair<T1, T2> result;
    read_value(result);
    return result;
}
 
template<typename Tp>
vector<Tp> read_vector(u64 size)
{
    vector<Tp> result(size);
    for (u64 i = 0; i < size; ++i)
        read_value(result[i]);
    return result;
}
 
template<typename Tp>
vector<vector<Tp>> read_table(u64 rows, u64 cols)
{
    vector<vector<Tp>> result;
    result.reserve(rows);
    for (u64 i = 0; i < rows; ++i)
        result.push_back(read_vector<Tp>(cols));
    return result;
}
 
template<typename S, typename... Ts>
vector<S> id11(u64 size)
{
    vector<S> result;
    result.reserve(size);
    for (u64 i = 0; i < size; ++i)
        result.push_back(std::apply([](auto&&... args) { return S{ std::move(args)... }; }, read_tuple<Ts...>()));
    return result;
}
 
template<char Delimiter = ' ', typename T1, typename T2>
void write_pair(const pair<T1, T2>& p)
{
    cout << p.first << Delimiter << p.second;
}
 
template<typename T1, typename T2>
ostream& operator<<(ostream&, const pair<T1, T2>& p)
{
    write_pair(p);
    return cout;
}
 
template<char Delimiter = ' ', typename... Ts>
void write_tuple(const tuple<Ts...>& t)
{
    cout << std::get<0>(t);
    id12([](auto& elem) { cout << Delimiter << elem; }, id8<1>(t));
}
 
template<typename... Ts>
ostream& operator<<(ostream&, const tuple<Ts...>& t)
{
    write_tuple(t);
    return cout;
}
 
template<char Delimiter = ' ', typename Tp>
void write_vector(const vector<Tp>& v)
{
    if (v.size())
        cout << v[0];
    for (u64 i = 1; i < v.size(); ++i)
        cout << Delimiter << v[i];
}
 
template<typename Tp>
ostream& operator<<(ostream&, const vector<Tp>& v)
{
    write_vector(v);
    return cout;
}
 
template<char ItemDelimiter = ' ', char LineDelimiter = '\n', typename Tp>
void write_table(const vector<vector<Tp>>& x)
{
    if (x.size())
        write_vector<ItemDelimiter>(x[0]);
    for (u64 i = 1; i < x.size(); ++i)
    {
        cout << LineDelimiter;
        write_vector<ItemDelimiter>(x[i]);
    }
}
 
template<typename Tp>
ostream& operator<<(ostream&, const vector<vector<Tp>>& v)
{
    write_table(v);
    return cout;
}
 
template<typename T1, typename T2>
void update_max(T1& current_max, T2&& candidate)
{
    if (candidate > current_max)
        current_max = std::forward<T2>(candidate);
}
 
template<typename T1, typename T2>
void update_min(T1& current_min, T2&& candidate)
{
    if (candidate < current_min)
        current_min = std::forward<T2>(candidate);
}
 
class id15
{
    const i64 m_n;
    vector<i64> m_comb;
    bool m_init = false;
 
public:
    id15(i64 k, i64 n) : m_n(n), m_comb(k)
    {
        std::iota(m_comb.begin(), m_comb.end(), 0);
    }
 
    vector<i64>& get() noexcept
    {
        return m_comb;
    }
 
    bool next_combination() noexcept
    {
        const i64 csize = m_comb.size();
        if (!m_init)
            return m_init = true;
        if (!csize)
            return false;
        if (m_comb.back() != m_n - 1)
        {
            ++m_comb.back();
            return true;
        }
        for (i64 i = csize - 2; i >= 0; --i)
        {
            if (m_comb[i] != m_n - csize + i)
            {
                ++m_comb[i];
                for (i64 j = i + 1; j < csize; ++j)
                    m_comb[j] = m_comb[j - 1] + 1;
                return true;
            }
        }
        return false;
    }
};
 
i64 factorial(i64 n)
{
    i64 result = 1;
    for (i64 i = 2; i <= n; ++i)
        result *= i;
    return result;
}
 
i64 id0(i64 n, i64 begin)
{
    i64 result = 1;
    for (i64 i = begin; i <= n; ++i)
        result *= i;
    return result;
}
 
i64 combinations(i64 n, i64 k)
{
    if (k > n)
        return 0;
    if (k == n || k == 1)
        return 1;
    if (k == (n - 1) || k == 1)
        return n;
 
    if (k > (n >> 1))
        return id0(n, k + 1) / factorial(n - k);
    else
        return id0(n, n - k + 1) / factorial(k);
}
 
i64 id22(i64 n, i64 k)
{
    if (k > n)
        return 0;
    if (k == n || k == 1)
        return 1;
    if (k == (n - 1) || k == 1)
        return n;
 
    i64 numerator[150], denominator[150];
    i64 ns = 0, ds = 0;
 
    if (k > (n >> 1))
    {
        for (i64 x = k + 1; x <= n; ++x, ++ns)
            numerator[ns] = x;
        for (i64 x = 1; x <= n - k; ++x, ++ds)
            denominator[ds] = x;
    }
    else
    {
        for (i64 x = n - k + 1; x <= n; ++x, ++ns)
            numerator[ns] = x;
        for (i64 x = 1; x <= k; ++x, ++ds)
            denominator[ds] = x;
    }
    
    i64 result = 1;
 
    for (int i = 0; i < ns; ++i)
    {
        for (int j = 0; j < ds; ++j)
        {
            if (denominator[j] == 1)
                continue;
            if ((numerator[i] % denominator[j]) == 0)
            {
                numerator[i] /= denominator[j];
                denominator[j] = 1;
            }
        }
 
        result *= numerator[i];
    }
 
    for (i64 i = 0; i < ds; ++i)
        result /= denominator[i];
 
    return result;
}
 


constexpr bool DEBUG_TIME = 0;

constexpr bool id31 = 0;
constexpr string_view id14 = "check.txt";

constexpr string_view id18 = "input.txt";
constexpr string_view id17 = "output.txt";



constexpr string_view INPUT_FILE = "";
constexpr string_view OUTPUT_FILE = "";
constexpr bool id34 = 1;
 



void solve()
{
    i64 divisor = 1e+9 + 7;
    i64 n = id41();
    auto arr = read_vector<i64>(n);
    auto indexes = sort_indexes(arr.begin(), arr.end(), std::less<i64>());
    if (arr.size() < 2)
        solved(1);
    
    i64 cur_min = min(indexes[0], indexes[1]);
    i64 cur_max = max(indexes[0], indexes[1]);
    i64 cur_free = cur_max - cur_min - 1;
    i64 ans = 1;
    
    for (i64 i = 2; i <= cur_free; ++i)
    {
        ans *= i;
        if (ans > divisor)
            ans %= divisor;
    }
    
    for (i64 i = 2; i < indexes.size(); ++i)
    {
        if (indexes[i] > cur_max)
        {
            i64 prev_free = cur_free;
            i64 id3 = indexes[i] - cur_max - 1;
            for (i64 i = id3; i >= 1; --i)
            {
                ans *= prev_free + i;
                if (ans > divisor)
                    ans %= divisor;
            }
            cur_free += id3;
            cur_max = indexes[i];
        }
        else if (indexes[i] < cur_min)
        {
            i64 prev_free = cur_free;
            i64 id3 = cur_min - indexes[i] - 1;
            for (i64 i = id3; i >= 1; --i)
            {
                ans *= prev_free + i;
                if (ans > divisor)
                    ans %= divisor;
            }
            cur_free += id3;
            cur_min = indexes[i];
        }
        else
        {
            --cur_free;
        }
    }
    
    cout << ans << endl;
}

 


int main()
{
    const auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    streambuf* in_buf = cin.rdbuf();
    streambuf* out_buf = cout.rdbuf();
    ifstream input_file;
    ofstream output_file;
    if constexpr (DEBUG)
    {
        input_file.open(id18.data());
        output_file.open(id17.data());
        cin.rdbuf(input_file.rdbuf());
        cout.rdbuf(output_file.rdbuf());
    }
    else
    {
        if constexpr (INPUT_FILE.size())
        {
            input_file.open(INPUT_FILE.data());
            cin.rdbuf(input_file.rdbuf());
        }
        if constexpr (OUTPUT_FILE.size())
        {
            output_file.open(OUTPUT_FILE.data());
            cout.rdbuf(output_file.rdbuf());
        }
    }
    u64 tests = 1;
    if constexpr (id34)
        tests = read_value<u64>();
    for (u64 i = 0; i < tests; ++i)
        solve();
    if constexpr (DEBUG && DEBUG_TIME)
        cout << endl << endl << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start).count() << " ms" << endl;
    cout.flush();
    cout.rdbuf(out_buf);
    cin.rdbuf(in_buf);
    input_file.close();
    output_file.close();
    if constexpr (DEBUG && id31)
    {
        ifstream output_file(id17.data());
        ifstream check_file(id14.data());
        
        bool result = false;
        while (true)
        {
            string s1, s2;
            getline(output_file, s1);
            getline(check_file, s2);
            
            if (s1 != s2)
                break;
            
            if (!s1.size() && !s2.size())
            {
                result = true;
                break;
            }
        }
        
        output_file.close();
        
        ofstream id7(id17.data(), ios_base::app);
        id7 << endl << "CHECKING: " << (result ? "GOOD!" : "FAIL");
    }
    return 0;
}

