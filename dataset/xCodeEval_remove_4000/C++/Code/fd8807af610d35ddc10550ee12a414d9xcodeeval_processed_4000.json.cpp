






























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
        inline constexpr sfinae sdef{0};

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







namespace uf::mt
{
    template<typename, typename Tp>
    constexpr auto&& id30(Tp&& x)
    {
        return std::forward<Tp>(x);
    }

    template<auto, typename Tp>
    constexpr auto&& id30(Tp&& x)
    {
        return std::forward<Tp>(x);
    }

    template<typename, typename Tp>
    constexpr Tp id30();

    template<auto, typename Tp>
    constexpr Tp id30();

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
    struct tpack_last : type_identity<typename decltype((type_identity<Ts>{ }, ...))::type> { };

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
        struct seq_concat<sequence<Ns1...>,  sequence<Ns2...>, Ts...> : seq_concat<sequence<Ns1..., Ns2...>, Ts...> { };

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
        struct tuple_last : type_identity<std::tuple_element_t<std::tuple_size_v<T> - 1, T>> { };

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
            using type = tuple_select_seq_t<T, make_sequence<std::tuple_size_v<T> - N>>;
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
    struct is_instantiated : public std::false_type { };

    template<template<typename...> typename Tp, typename... Ts>
    struct is_instantiated<Tp<Ts...>> : public std::true_type { };

    DECLARE_N1(is_instantiated, typename);

    template<typename A, typename B>
    struct is_instantiated_from_same : std::false_type { };

    template<template<typename...> typename Tp, typename... A, typename... B>
    struct is_instantiated_from_same<Tp<A...>, Tp<B...>> : std::true_type { };

    DECLARE_N2(is_instantiated_from_same, typename, typename);

    template<template<typename...> typename Expected, typename Tested>
    struct is_instantiated_from : public std::false_type { };

    template<template<typename...> typename Expected, typename... Ts>
    struct is_instantiated_from<Expected, Expected<Ts...>> : public std::true_type { };

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
    struct function_info<std::function<R(Args...)>> : public function_info<R(Args...)> { };

    template<typename R, typename... Args>
    struct function_info<R(*)(Args...)> : public function_info<R(Args...)> { };

    template<class C, typename R, typename... Args>
    struct function_info<R(C::*)(Args...)> : public function_info<R(Args...)> { };

    

    template<class Tp, typename = sfinae>
    struct is_iterable : public std::false_type { };

    template<class Tp>
    struct is_iterable<Tp, sfinae_t<decltype(*std::begin(std::declval<Tp>())), decltype(std::end(std::declval<Tp>()))>> : public std::true_type { };

    DECLARE_N1(is_iterable, typename);

    template<typename Tp, typename = sfinae>
    struct is_dereferenceable : public std::false_type { };

    template<typename Tp>
    struct is_dereferenceable<Tp, sfinae_t<decltype(*std::declval<Tp>())>> : public std::true_type { };

    DECLARE_N1(is_dereferenceable, typename);

    

    template<typename S>
    struct is_sequence : std::false_type { };

    template<auto... Ns>
    struct is_sequence<sequence<Ns...>> : std::true_type { };

    DECLARE_N1(is_sequence, typename);

    template<typename S>
    struct is_positive_sequence : std::false_type { };

    template<auto... Ns>
    struct is_positive_sequence<sequence<Ns...>> : public std::bool_constant<((Ns >= 0) && ...)> { };

    DECLARE_N1(is_positive_sequence, typename);

    template<typename Tp>
    struct is_smart_pointer : std::bool_constant<is_instantiated_from_v<std::unique_ptr, Tp> || is_instantiated_from_v<std::shared_ptr, Tp> || is_instantiated_from_v<std::weak_ptr, Tp>> { };

    DECLARE_N1(is_smart_pointer, typename);

    template<typename Tp, typename = sfinae>
    struct is_iterator : public std::false_type { };

    template<typename Tp>
    struct is_iterator<Tp, sfinae_t<typename std::iterator_traits<Tp>::iterator_category>> : public std::true_type { };

    DECLARE_N1(is_iterator, typename);

    template<typename Tp, typename = sfinae>
    struct is_random_access_iterator : public std::false_type { };

    template<typename Tp>
    struct is_random_access_iterator<Tp, enif<std::is_same_v<typename std::iterator_traits<Tp>::iterator_category, std::random_access_iterator_tag>>> : public std::true_type { };

    DECLARE_N1(is_random_access_iterator, typename);

    template<typename Tp, typename = sfinae>
    struct is_random_access_container : std::false_type { };

    template<typename Tp>
    struct is_random_access_container<Tp, enif<is_iterable_v<Tp>>> : public is_random_access_iterator<typename std::remove_reference_t<Tp>::iterator> { };

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
        constexpr auto id8(Tp&& value, sequence<Ns...>)
        {
            return std::make_tuple(mt::id30<Ns>(value)...);
        }

        template<u64 N, typename F, typename... Ts>
        constexpr void id34(F&& f, Ts&&... ts)
        {
            if constexpr (N < std::tuple_size_v<mt::tpack_first_t<std::decay_t<Ts>...>>)
            {
                std::invoke(f, std::get<N>(std::forward<Ts>(ts))...);
                id34<N + 1>(f, std::forward<Ts>(ts)...);
            }
        }

        template<u64 N, typename F, typename... Ts>
        constexpr auto id7(F&& f, Ts&&... ts)
        {
            return std::invoke(f, std::get<N>(std::forward<Ts>(ts))...);
        }

        template<typename F, typename... Ts, u64... Ns>
        constexpr auto id1(sequence<Ns...>, F&& f, Ts&&... ts)
        {
            return std::make_tuple(id7<Ns>(f, std::forward<Ts>(ts)...)...);
        }

        template<typename T, auto... Ns>
        constexpr auto id16(T&& t, sequence<Ns...>)
        {
            return std::tuple<decltype(std::get<Ns>(std::forward<T>(t)))...>(std::get<Ns>(std::forward<T>(t))...);
        }

        template<typename T, auto... Ns>
        constexpr auto id25(T&& t, sequence<Ns...>)
        {
            return std::make_tuple(std::get<Ns>(std::forward<T>(t))...);
        }

        template<typename Index, typename Tp, class F>
        Index id15(Index left, Index right, Index end, Tp&& value, F&& f)
        {
            const auto diff = right - left;
            if (diff <= 1)
            {
                if (f(right) == value)
                    return right;
                if (f(left) == value)
                    return left;
                return end;
            }
            const Index middle = left + diff / 2;
            if (f(middle) < value)
                return id15(middle, right, end, std::forward<Tp>(value), std::forward<F>(f));
            return id15(left, middle, end, std::forward<Tp>(value), std::forward<F>(f));
        }
    }
    


    inline namespace utils
    {
        template<typename Container, typename E, enif<std::is_lvalue_reference_v<Container>> = sdef>
        constexpr auto&& forward_element(E&& e)
        {
            return std::forward<E>(e);
        }

        template<typename Container, typename E, enif<!std::is_reference_v<Container>> = sdef>
        constexpr auto&& forward_element(E&& e)
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
        constexpr bool id12(const E& e, Ps&&... ps)
        {
            return (stf(e, ps) || ...);
        }

        template<class E, class... Ps>
        constexpr bool id3(const E& e, Ps&&... ps)
        {
            return (stf(e, ps) && ...);
        }

        template<class... Ps>
        constexpr auto id22(Ps&&... ps)
        {
            return std::bind([](const auto& e, Ps&... ps){ return id12(e, ps...); }, std::placeholders::_1, std::forward<Ps>(ps)...);
        }

        template<class... Ps>
        constexpr auto id40(Ps&&... ps)
        {
            return std::bind([](const auto& e, Ps&... ps){ return id3(e, ps...); }, std::placeholders::_1, std::forward<Ps>(ps)...);
        }

        template<u64 N, typename Tp>
        constexpr auto id26(Tp&& value)
        {
            return detail::id8(std::forward<Tp>(value), make_sequence<N>());
        }

        template<typename F, typename... Ts>
        constexpr void id13(F&& f, Ts&&... ts)
        {
            constexpr u64 size = std::tuple_size_v<std::remove_reference_t<mt::tpack_first_t<Ts...>>>;
            static_assert (((std::tuple_size_v<std::remove_reference_t<Ts>> == size) && ...));
            detail::id34<0>(std::forward<F>(f), std::forward<Ts>(ts)...);
        }

        template<typename F, typename... Ts>
        constexpr auto tuple_transform(F&& f, Ts&&... ts)
        {
            constexpr u64 size = std::tuple_size_v<std::remove_reference_t<mt::tpack_first_t<Ts...>>>;
            static_assert (((std::tuple_size_v<std::remove_reference_t<Ts>> == size) && ...));
            return detail::id1(make_sequence<size>(), std::forward<F>(f), std::forward<Ts>(ts)...);
        }

        template<class R, class SeqContainer>
        R add_positions(SeqContainer&& x)
        {
            R result;
            result.reserve(x.size());
            u64 j = 0;
            for (auto i = x.begin(); i != x.end(); ++i, ++j)
                result.emplace_back(j, forward_element<SeqContainer>(*i));
            return result;
        }

        template<class SeqContainer>
        auto add_positions(SeqContainer&& x)
        {
            return add_positions<mt::instance_info<std::decay_t<SeqContainer>>::template type<std::pair<u64, typename std::decay_t<SeqContainer>::value_type>>>>(std::forward<SeqContainer>(x));
        }

        template<class SeqContainer, typename Compare>
        auto id10(SeqContainer&& c, Compare&& compare)
        {
            auto result = add_positions(std::forward<SeqContainer>(c));
            std::sort(result.begin(), result.end(), [&compare](const auto& e1, const auto& e2)
            {
                return compare(e1.second, e2.second);
            });
            return result;
        }

        template<typename Tp, typename C, typename F>
        void id4(C&& c, F&& f)
        {
            using value_type = typename std::decay_t<C>::value_type;

            if constexpr (std::is_same_v<Tp, value_type>)
                std::for_each(c.begin(), c.end(), f);
            else
                for (auto& value : c)
                    id4<Tp>(forward_element<C>(value), f);
        }

        template<typename P>
        auto id42(P&& p)
        {
            return [p = std::forward<P>(p)](const auto& x) mutable -> bool { return stf(x.first, p); };
        }

        template<typename P>
        auto id29(P&& p)
        {
            return [p = std::forward<P>(p)](const auto& x) mutable -> bool { return stf(x.second, p); };
        }

        template<u64 N, typename P>
        auto id23(P&& p)
        {
            return [p = std::forward<P>(p)](const auto& x) mutable -> bool { return stf(std::get<N>(x), p); };
        }

        template<class AssocContainer, class... Rs>
        void id17(AssocContainer& c, Rs&&... rs)
        {
            for (auto i = c.begin(); i != c.end();)
            {
                if (id12(*i, rs...))
                    i = c.erase(i);
                else
                    ++i;
            }
        }

        template<class AssocContainer, class... Rs>
        AssocContainer id47(const AssocContainer& c, Rs&&... rs)
        {
            AssocContainer result;
            for (auto i = c.begin(); i != c.end(); ++i)
                if (!id12(*i, rs...))
                    result.insert(*i);
            return result;
        }

        template<typename Index, typename Tp, class F>
        Index binary_search(Index left, Index right, Tp&& value, F&& f)
        {
            if (left >= right)
                return right;
            return detail::id15(left, right - 1, right, value, std::forward<F>(f));
        }

        template<typename T>
        auto* id19(T* object)
        {
            return object;
        }

        template<typename T, enif<mt::is_iterator_v<std::decay_t<T>>> = sdef, disif<mt::is_instantiated_from_v<std::reverse_iterator, std::remove_reference_t<T>>> = sdef>
        auto* id19(T&& object)
        {
            return object.base();
        }

        template<typename T, enif<mt::is_instantiated_from_v<std::reverse_iterator, std::remove_reference_t<T>>> = sdef>
        auto* id19(T&& object)
        {
            auto b = object.base();
            return id19(--b);
        }

        template<typename T, enif<uf::mt::is_smart_pointer_v<std::decay_t<T>>> = sdef>
        auto* id19(T&& object)
        {
            return object.get();
        }

        template<u64 B = 0, u64 E = std::numeric_limits<u64>::max(), typename T>
        auto id6(T&& t)
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
                return detail::id25(std::forward<T>(t), mt::seq_increasing_t<B, size>());
            else
                return detail::id25(std::forward<T>(t), mt::seq_increasing_t<B, E>());
        }

        template<u64... Ns, typename T>
        auto id35(T&& t)
        {
            return detail::id25(std::forward<T>(t), sequence<Ns...>());
        }

        template<u64... Ns, typename T>
        auto id18(T&& t)
        {
            return detail::id16(std::forward<T>(t), sequence<Ns...>());
        }

        template<u64... Ns, typename T>
        auto id27(T&& t)
        {
            return detail::id25(std::forward<T>(t), mt::seq_remove_t<make_sequence<std::tuple_size_v<std::decay_t<T>>>, Ns...>());
        }

        template<u64... Ns, typename T>
        auto id14(T&& t)
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

        class spinlock
        {
            std::atomic_flag flag_ = ATOMIC_FLAG_INIT;

        public:
            bool try_lock()
            {
                return !flag_.test_and_set(std::memory_order_acquire);
            }

            template<typename Period>
            void lock(i64 count)
            {
                while (flag_.test_and_set(std::memory_order_acquire))
                    std::this_thread::sleep_for(std::chrono::duration<i64, Period>(count));
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
        template<class SeqContainer, class IterVector>
        auto id33(IterVector&& iters)
        {
            std::vector<SeqContainer> result;
            result.reserve(iters.size());
            for (auto [b, e] : iters)
                result.emplace_back(b, e);
            return result;
        }

        template<class SeqContainer, class IterVector, u64... Ns>
        auto id28(IterVector&& iters, sequence<Ns...>)
        {
            return std::tuple(SeqContainer(iters[Ns].first, iters[Ns].second)...);
        }
    }
    


    inline namespace strings
    {
        constexpr bool is_digit(char c) noexcept
        {
            return c >= '0' && c <= '9';
        }

        constexpr bool is_lower(char c) noexcept
        {
            return c >= 'a' && c <= 'z';
        }

        constexpr bool is_upper(char c) noexcept
        {
            return c >= 'A' && c <= 'Z';
        }

        constexpr bool is_letter(char c) noexcept
        {
            return is_lower(c) || is_upper(c);
        }

        void lowercase(std::string& s)
        {
            for (char& c : s)
                if (is_upper(c))
                    c += 'a' - 'A';
        }

        void uppercase(std::string& s)
        {
            for (char& c : s)
                if (is_lower(c))
                    c -= 'a' - 'A';
        }

        template<class SeqContainer, typename... Ps>
        void lstrip(SeqContainer& c, Ps&&... ps)
        {
            auto fwd = c.begin();
            while (fwd != c.end() && satisfies_one(*fwd, ps...))
                ++fwd;
            c.erase(c.begin(), fwd);
        }

        template<class SeqContainer, typename... Ps>
        void rstrip(SeqContainer& c, Ps&&... ps)
        {
            auto bck = c.rbegin();
            while (bck != c.rend() && satisfies_one(*bck, ps...))
                ++bck;
            c.erase(bck.base(), c.end());
        }

        template<class SeqContainer, typename... Ps>
        void strip(SeqContainer& c, Ps&&... ps)
        {
            lstrip(c, ps...);
            rstrip(c, ps...);
        }

        template<class SeqContainer, class... Ds>
        auto split_itr(u64 n, const SeqContainer& c, Ds&&... ds)
        {
            using iter = typename SeqContainer::const_iterator;

            bool empty_seq = true;
            std::vector<std::pair<iter, iter>> result;
            for (auto i = c.begin(); i != c.end(); ++i)
            {
                if (satisfies_one(*i, ds...))
                {
                    if (empty_seq)
                        continue;
                    result.back().second = i;
                    empty_seq = true;
                    if (result.size() == n)
                        break;
                }
                else
                {
                    if (empty_seq)
                    {
                        empty_seq = false;
                        result.push_back({i, c.end()});
                    }
                }
            }
            return result;
        }

        template<class SeqContainer, class... Ds>
        auto split_itr(const SeqContainer& c, Ds&&... ds)
        {
            return split_itr(std::numeric_limits<u64>::max(), c, ds...);
        }

        template<class SeqContainer, class... Ds>
        auto split(u64 n, const SeqContainer& c, Ds&&... ds)
        {
            return detail::id33<SeqContainer>(split_itr(n, c, ds...));
        }

        template<class SeqContainer, class... Ds>
        auto split(const SeqContainer& c, Ds&&... ds)
        {
            return split(std::numeric_limits<u64>::max(), c, ds...);
        }

        template<u64 N, class SeqContainer, class... Ds>
        auto split(const SeqContainer& c, Ds&&... ds)
        {
            return detail::id28<SeqContainer>(split_itr(c, ds...), make_sequence<N>());
        }

        template<class SeqContainer, class... Ds>
        auto id20(u64 n, const SeqContainer& c, Ds&&... ds)
        {
            using iter = typename SeqContainer::const_iterator;

            std::vector<std::pair<iter, iter>> result;
            iter id2 = c.begin();
            for (auto i = c.begin(); i != c.end(); ++i)
            {
                if (satisfies_one(*i, ds...))
                {
                    result.push_back({id2, i});
                    if (result.size() == n)
                        return result;
                    id2 = i + 1;
                }
            }
            result.push_back({id2, c.end()});
            return result;
        }

        template<class SeqContainer, class... Ds>
        auto id20(const SeqContainer& c, Ds&&... ds)
        {
            return id20(std::numeric_limits<u64>::max(), c, ds...);
        }

        template<class SeqContainer, class... Ds>
        auto id46(u64 n, const SeqContainer& c, Ds&&... ds)
        {
            return detail::id33<SeqContainer>(id20(n, c, ds...));
        }

        template<class SeqContainer, class... Ds>
        auto id46(const SeqContainer& c, Ds&&... ds)
        {
            return id46(std::numeric_limits<u64>::max(), c, ds...);
        }

        template<u64 N, class SeqContainer, class... Ds>
        auto id46(const SeqContainer& c, Ds&&... ds)
        {
            return detail::id28<SeqContainer>(id20(c, ds...), make_sequence<N>());
        }

        template<class C1, class C2, disif<std::is_convertible_v<C2, typename C1::value_type>> = sdef>
        bool starts_with(const C1& c, const C2& pattern)
        {
            auto i1 = std::begin(c);
            auto i2 = std::begin(pattern);
            for (; i1 != std::end(c) && i2 != std::end(pattern); ++i1, ++i2)
                if (*i1 != *i2)
                    return false;
            return i2 == std::end(pattern) ? true : false;
        }

        template<class C, class E, enif<std::is_convertible_v<E, typename C::value_type>> = sdef>
        bool starts_with(const C& c, const E& e)
        {
            return !c.empty() && *std::begin(c) == e;
        }

        template<class C1, class C2, disif<std::is_convertible_v<C2, typename C1::value_type>> = sdef>
        bool ends_with(const C1& c, const C2& pattern)
        {
            auto i1 = std::rbegin(c);
            auto i2 = std::rbegin(pattern);
            for (; i1 != std::rend(c) && i2 != std::rend(pattern); ++i1, ++i2)
                if (*i1 != *i2)
                    return false;
            return i2 == std::rend(pattern) ? true : false;
        }

        template<class C, class E, enif<std::is_convertible_v<E, typename C::value_type>> = sdef>
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
auto id0(M&& m)
{
    using rr = remove_reference_t<M>;
    using key_type = typename rr::key_type;
    using value_type = typename rr::mapped_type;

    unordered_multimap<value_type, key_type> result;
    for (const auto& [k, v] : m)
        result.insert(make_pair(forward_element<M>(const_cast<value_type&>(v)), forward_element<M>(const_cast<key_type&>(k))));
    return result;
}



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

template<typename Tp>
Tp read_value()
{
    Tp x;
    read_value(x);
    return x;
}

template<typename... Ts>
tuple<Ts...> read_tuple()
{
    tuple<Ts...> result;
    id13([](auto& elem){ read_value(elem); }, result);
    return result;
}

template<char Last = 0, typename... Ts>
void write_tuple(const tuple<Ts...>& t, char delimiter = ' ')
{
    cout << std::get<0>(t);
    id13(id6<1>(t), [delimiter](auto& elem){ cout << delimiter << elem; });
    if constexpr (Last)
        cout << Last;
}

template<typename... Ts>
ostream& operator<<(ostream&, const tuple<Ts...>& t)
{
    write_tuple(t);
    return cout;
}

template<typename Tp>
vector<Tp> read_vector(u64 size)
{
    vector<Tp> result(size);
    for (u64 i = 0; i < size; ++i)
        read_value(result[i]);
    return result;
}

template<char Last = 0, typename Tp>
void write_vector(const vector<Tp>& v, char delimiter = ' ')
{
    if (v.size())
        cout << v[0];
    for (u64 i = 1; i < v.size(); ++i)
        cout << delimiter << v[i];
    if constexpr (Last)
        cout << Last;
}

template<typename Tp>
ostream& operator<<(ostream&, const vector<Tp>& v)
{
    write_vector(v);
    return cout;
}

template<typename Tp>
vector<vector<Tp>> read_table(u64 rows, u64 cols)
{
    vector<vector<Tp>> result(rows, vector<Tp>(cols));
    for (u64 i = 0; i < rows; ++i)
        result[i] = read_vector<Tp>(cols);
    return result;
}

template<char Last = 0, typename Tp>
void write_table(const vector<vector<Tp>>& x, char id39 = ' ', char id44 = '\n')
{
    if (x.size())
        write_vector(x[0], id39);
    for (u64 i = 1; i < x.size(); ++i)
    {
        cout << id44;
        write_vector(x[i], id39);
    }
    if constexpr (Last)
        cout << Last;
}

template<typename Tp>
ostream& operator<<(ostream&, const vector<vector<Tp>>& v)
{
    write_table(v);
    return cout;
}

template<typename... Ts>
vector<tuple<Ts...>> id5(u64 size)
{
    vector<tuple<Ts...>> result;
    for (u64 i = 0; i < size; ++i)
        result.push_back(read_tuple<Ts...>());
    return result;
}

template<char Last = 0, typename... Ts>
void id37(const vector<tuple<Ts...>>& x, char id39 = ' ', char id44 = '\n')
{
    if (x.size())
        write_tuple(x[0], id39);
    for (u64 i = 0; i < x.size(); ++i)
    {
        cout << id44;
        write_tuple(x[i], id39);
    }
    if constexpr (Last)
        cout << Last;
}

template<typename... Ts>
ostream& operator<<(ostream&, const vector<tuple<Ts...>>& v)
{
    id37(v);
    return cout;
}

template<typename Tp, typename... Ts>
vector<Tp> id9(u64 size)
{
    vector<Tp> result;
    result.reserve(size);
    for (u64 i = 0; i < size; ++i)
    {
        tuple<Ts...> x = read_tuple<Ts...>();
        result.push_back(std::apply([](auto... args){ return Tp{args...}; }, x));
    }
    return result;
}






constexpr string_view id43 = "../competitive/input";
constexpr string_view id41 = "../competitive/output";

constexpr bool DEBUG_TIME = 0;
constexpr bool id38 = 0;
constexpr bool id36 = 0;
constexpr bool id21 = 0;

constexpr string_view FILE_IN = "";
constexpr string_view FILE_OUT = "";

constexpr bool id24 = 0;



void solve(const vector<any>& id31 [[maybe_unused]])
{
    u64 n = read_value<u64>();
    auto v = read_vector<int>(n);

    if (v.size() == 1)
    {
        cout << 1 << endl;
        return;
    }

    map<int, int> c;
    for (auto e : v)
        ++c[e];

    for (auto i = v.rbegin(); i != v.rend(); ++i)
    {
        bool id11 = false;
        bool id32 = false;
        bool good = false;

        auto mx = max_element(c.begin(), c.end(), [](pair<int, int> p1, pair<int, int> p2)
        {
            return p1.second < p2.second;
        })->second;

        auto mn = min_element(c.begin(), c.end(), [](pair<int, int> p1, pair<int, int> p2)
        {
            return p1.second < p2.second;
        })->second;

        if (mx - mn == 1)
        {
            auto mxc = count_if(c.begin(), c.end(), [mx](auto p){ return p.second == mx; });
            if (mxc == 1)
                id11 = true;
        }
        if (mn == 1)
        {
            auto mxc = count_if(c.begin(), c.end(), [mx](auto p){ return p.second == mx; });
            auto mnc = count_if(c.begin(), c.end(), [mn](auto p){ return p.second == mn; });
            if (mnc == 1 && mxc == (int)(c.size() - 1))
                id32 = true;
        }
        if (mx == mn)
            good = true;

        if (good && i != v.rbegin())
        {
            cout << i.base() - v.begin() + 1 << endl;
            return;
        }
        if (id11 || id32)
        {
            cout << i.base() - v.begin() << endl;
            return;
        }

        if (!--c[*i])
            c.erase(*i);
    }
}



vector<any> id45()
{
    return { };
}



int main()
{
    using namespace chrono;

    const auto start = high_resolution_clock::now();
    if constexpr (!DEBUG)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    auto in_buf = cin.rdbuf();
    auto out_buf = cout.rdbuf();
    ifstream input_file;
    ofstream output_file;
    if constexpr (DEBUG)
    {
        if constexpr (!id38)
        {
            input_file.open(id43.data());
            cin.rdbuf(input_file.rdbuf());
        }
        if constexpr (!id36)
        {
            output_file.open(id41.data());
            cout.rdbuf(output_file.rdbuf());
        }
    }
    else
    {
        if constexpr (FILE_IN.size())
        {
            input_file.open(FILE_IN.data());
            cin.rdbuf(input_file.rdbuf());
        }
        if constexpr (FILE_OUT.size())
        {
            output_file.open(FILE_OUT.data());
            cout.rdbuf(output_file.rdbuf());
        }
    }
    u64 tests = 1;
    vector<any> id31;
    if constexpr (id24)
    {
        id31 = id45();
        cin >> tests;
    }
    for (u64 i = 1; i <= tests; ++i)
    {
        if constexpr (DEBUG && id21)
        {
            if (tests > 1)
                cout << "TEST " << i << endl;
        }
        solve(id31);
        if constexpr (DEBUG && id21)
        {
            if (tests > 1)
                cout << "END TEST " << i << endl;
            if (i != tests)
                cout << endl;
        }
    }
    if constexpr (DEBUG && DEBUG_TIME)
        cout << endl << endl << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;
    cout.flush();
    cin.rdbuf(in_buf);
    cout.rdbuf(out_buf);
    return 0;
}
