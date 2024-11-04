







    constexpr bool DEBUG = 0;

    constexpr bool DEBUG = 1;


template<typename... Ts>
void dbg_function(std::string_view names, const Ts&... values)
{
    using namespace std;

    auto id6 = [](string_view s)
    {
        uint64_t lvl = 0;
        for (uint64_t i = 0; i < s.size(); ++i)
        {
            if (s[i] == '[' || s[i] =='{' || s[i] == '(')
                ++lvl;
            else if (s[i] == ']' || s[i] =='}' || s[i] == ')')
                --lvl;
            else if (s[i] == ',' && !lvl)
                return i;
        }
        return string_view::npos;
    };
    auto get_name = [](string_view s)
    {
        auto wb = s.find_first_not_of(' ');
        auto we = s.find_last_not_of(' ');
        return s.substr(wb, we - wb + 1);
    };
    size_t comma_index;
    (
        (
            static_cast<void>(static_cast<void>(comma_index = id6(names))),
            static_cast<void>(static_cast<void>(cout << get_name(names.substr(0, comma_index)) << " = ")),
            static_cast<void>(names = names.substr(comma_index + 1)),
            cout << values, (comma_index == string_view::npos) ? (cout << endl) : (cout << " | ")
        ),
        ...
    );
}



using namespace std;

using u8 = uint8_t;
using i8 = int8_t;

using u16 = uint16_t;
using i16 = int16_t;

using u32 = uint32_t;
using i32 = int32_t;

using u64 = uint64_t;
using i64 = int64_t;

u8 operator"" _u8(unsigned long long int value) noexcept { return value; }
i8 operator"" _i8(unsigned long long int value) noexcept { return value; }

u16 operator"" _u16(unsigned long long int value) noexcept { return value; }
i16 operator"" _i16(unsigned long long int value) noexcept { return value; }

u32 operator"" _u32(unsigned long long int value) noexcept { return value; }
i32 operator"" _i32(unsigned long long int value) noexcept { return value; }

u64 operator"" _u64(unsigned long long int value) noexcept { return value; }
i64 operator"" _i64(unsigned long long int value) noexcept { return value; }

template<typename Tp>
constexpr Tp ll() { return numeric_limits<Tp>::min(); }

template<typename Tp>
constexpr Tp hl() { return numeric_limits<Tp>::max(); }

template<typename UniversalContainer, typename E>
constexpr auto&& forward_element(E&& e)
{
    if constexpr (!is_lvalue_reference_v<E>)
        return static_cast<remove_reference_t<E>&&>(e);
    else if constexpr (is_lvalue_reference_v<UniversalContainer>)
        return static_cast<remove_reference_t<E>&>(e);
    else
        return static_cast<remove_reference_t<E>&&>(e);
}

template<class Tp>
using const_reference_wrapper = reference_wrapper<const Tp>;

template<u64 N, typename... Ts>
struct optimal_element_helper
{
    using type = tuple<Ts...>;
};

template<typename... Ts>
struct optimal_element_helper<1, Ts...>
{
    using type = typename tuple_element<0, tuple<Ts...>>::type;
};

template<typename... Ts>
struct optimal_element_helper<2, Ts...>
{
    using type = pair<Ts...>;
};

template<typename... Ts>
struct optimal_element
{
    using type = typename optimal_element_helper<sizeof...(Ts), Ts...>::type;
};

template<typename... Ts>
using optimal_element_t = typename optimal_element<Ts...>::type;

template<typename... Ts>
using optimal_element_rr_t = optimal_element_t<remove_reference_t<Ts>...>;

template<template<typename...> typename Expected, typename Tested>
struct is_same_template 

{
    template<typename Tp>
    struct helper
    {
        static constexpr bool value = false;
    };

    template<typename... Ts>
    struct helper<Expected<Ts...>>
    {
        static constexpr bool value = true;
    };

    static constexpr bool value = helper<Tested>::value;
};

template<typename Tp>
inline constexpr bool id0 = is_same_template<tuple, Tp>::value;

template<typename Tp>
inline constexpr bool id15 = is_same_template<pair, Tp>::value;

template<typename Tp>
inline constexpr bool id3 = !id15<Tp> && !id0<Tp>;

template<typename Tp>
tuple<Tp> tuple_cast(Tp&& value) { return {std::forward<Tp>(value)}; }

template<typename Pair, typename = enable_if_t<id15<decay_t<Pair>>>>
auto tuple_cast(Pair&& p) { return tuple{forward_element<Pair>(p.first), forward_element<Pair>(p.second)}; }

template<typename Tuple, typename = enable_if_t<id0<decay_t<Tuple>>>>
auto pair_cast(Tuple&& t) { return pair{forward_element<Tuple>(std::get<0>(t)), forward_element<Tuple>(std::get<0>(t))}; }

template<class Tp>
struct reader
{
    using type = Tp;

    template<typename... Args>
    type exec(const Args&...) const
    {
        type result;
        cin >> result;
        return result;
    }
};

template<typename F, typename S>
struct reader<pair<F, S>>
{
    using type = pair<F, S>;

    template<typename... Args>
    type exec(const Args&... args) const
    {
        return {reader<F>().exec(args...), reader<S>().exec(args...)};
    }
};

template<typename... Ts>
struct reader<tuple<Ts...>>
{
    using type = tuple<Ts...>;

    template<typename... Args>
    type exec(const Args&... args) const
    {
        return {reader<Ts>().exec(args...)...};
    }
};

template<typename Tp>
struct reader<vector<Tp>>
{
    using type = vector<Tp>;

    template<typename... Args>
    type exec(u64 size, const Args&... args) const
    {
        type result(size);
        for (auto& e : result)
            e = reader<Tp>().exec(args...);
        return result;
    }
};

template<typename Tp, typename... Args>
Tp read(const Args&... args) { return reader<Tp>().exec(args...); }

template<typename Tp, typename... Args>
void id10(Tp& ref, const Args&... args) { ref = reader<Tp>().exec(args...); }

template<typename... Ts>
auto read_t() { return read<optimal_element_t<Ts...>>(); }

template<typename Tp>
auto read_v(u64 size = hl<u64>())
{
    if (size == hl<u64>())
        size = read<u64>();
    return read<vector<Tp>>(size);
}

template<typename Tp>
auto read_m(u64 rows, u64 cols) { return read<vector<vector<Tp>>>(rows, cols); }

template<typename... Ts>
auto read_tv(u64 size = hl<u64>())
{
    if (size == hl<u64>())
        size = read<u64>();
    return read<optimal_element_t<vector<Ts>...>>(size);
}

template<typename... Ts>
auto id21(u64 size = hl<u64>())
{
    if (size == hl<u64>())
        size = read<u64>();
    return read<vector<optimal_element_t<Ts...>>>(size);
}

template<typename VecTpl, u64... Ns>
auto id20(VecTpl&& vt, index_sequence<Ns...>)
{
    using tt = typename remove_reference_t<VecTpl>::value_type;

    optimal_element_t<vector<tuple_element_t<Ns, tt>>...> result{vector<tuple_element_t<Ns, tt>>(vt.size())...};
    for (u64 i = 0; i < vt.size(); ++i)
        ((std::get<Ns>(result)[i] = forward_element<VecTpl>(std::get<Ns>(vt[i]))), ...);
    return result;
}

template<typename VecTpl>
auto to_tv(VecTpl&& vt)
{
    using tt = typename remove_reference_t<VecTpl>::value_type;

    if constexpr (id3<tt>)
        return std::forward<VecTpl>(vt);
    else
        return id20(std::forward<VecTpl>(vt), make_index_sequence<tuple_size_v<tt>>());
}

template<typename TplVec, u64... Ns>
auto id2(TplVec&& tv, index_sequence<Ns...>)
{
    using tt = remove_reference_t<TplVec>;

    vector<optimal_element_t<typename tuple_element_t<Ns, tt>::value_type...>> result;
    result.reserve(std::get<0>(tv).size());
    for (u64 i = 0; i < std::get<0>(tv).size(); ++i)
        result.push_back({forward_element<TplVec>(std::get<Ns>(tv)[i])...});
    return result;
}

template<typename TplVec>
auto id13(TplVec&& tv)
{
    using tt = remove_reference_t<TplVec>;

    if constexpr (id3<TplVec>)
        return std::forward<TplVec>(tv);
    else
        return id2(std::forward<TplVec>(tv), make_index_sequence<tuple_size_v<tt>>());
}



template<class F, class S, template<class> class Compare>
class pair_second_compare
{
    const Compare<S> m_comp;

public:
    bool operator()(const pair<F, S>& a, const pair<F, S>& b) const
    {
        return m_comp(a.second, b.second);
    }
};

template<typename... Ts>
auto cust_min(Ts&&... args)
{
    using element_type = remove_reference_t<tuple_element_t<0, tuple<Ts...>>>;

    reference_wrapper<const element_type> last = std::get<0>(tuple<const Ts&...>{args...});
    ((last = (args < last.get()) ? ref(static_cast<const element_type&>(args)) : last), ...);
    return last.get();
}

template<typename... Ts>
auto cust_max(Ts&&... args)
{
    using element_type = remove_reference_t<tuple_element_t<0, tuple<Ts...>>>;

    const_reference_wrapper<element_type> last = std::get<0>(tuple<const Ts&...>{args...});
    ((last = (!(args < last.get())) ? ref(static_cast<const element_type&>(args)) : last), ...);
    return last.get();
}

template<class Predicate>
i64 id14(i64 left, i64 right, const Predicate& p)
{
    const auto s = (right - left) / 2;
    if (!s)
    {
        if (p(right))
            return right;
        return left;
    }
    if (p(left + s))
        return custom_binary_search(left + s, right, p);
    return custom_binary_search(left, right - s, p);
}

template<template<class> class Compare, class AnyMap>
auto id4(AnyMap&& in)
{
    using value_type = typename remove_reference_t<AnyMap>::value_type::second_type;
    using key_type = typename remove_reference_t<AnyMap>::key_type;

    map<value_type, unordered_set<key_type>, Compare<value_type>> result;
    for (const auto& [k, v] : in)
        result[v].insert(k);
    return result;
}

template<class AnyMap>
auto id7(AnyMap&& in)
{
    using value_type = typename remove_reference_t<AnyMap>::value_type::second_type;
    using key_type = typename remove_reference_t<AnyMap>::key_type;

    unordered_map<value_type, unordered_set<key_type>> result;
    for (const auto& [k, v] : in)
        result[v].insert(k);
    return result;
}

template<template<typename...> typename TmplContainer, typename ValueType, typename... Ts>
auto id19(const TmplContainer<ValueType, Ts...>& container)
{
    TmplContainer<pair<u64, ValueType>, Ts...> result;
    u64 j = 0;
    for (auto i = container.begin(); i != container.end(); ++i, ++j)
        result.push_back({j, *i});
    return result;
}

template<template<typename...> class TmplContainer, typename ValueType, typename... Ts>
auto id19(TmplContainer<ValueType, Ts...>&& container)
{
    TmplContainer<pair<u64, ValueType>, Ts...> result;
    u64 j = 0;
    for (auto i = container.begin(); i != container.end(); ++i, ++j)
        result.push_back({j, std::move(*i)});
    return result;
}

template<class Container, class Compare>
auto id8(Container&& container, const Compare& comp)
{
    auto transformed = id19(std::forward<Container>(container));
    sort(transformed.begin(), transformed.end(), [&comp](const auto& a, const auto& b)
    {
        return comp(a.second, b.second);
    });
    return transformed;
}

template<template<class> class Compare, class Container>
auto id22(Container&& container)
{
    using value_type = typename remove_reference_t<Container>::value_type;

    set<value_type, Compare<value_type>> result;
    for (auto& e : container)
        result.insert(forward_element<Container>(e));
    return result;
}

template<class Container>
auto id18(Container&& container)
{
    using value_type = typename remove_reference_t<Container>::value_type;

    unordered_set<value_type> result;
    for (auto& e : container)
        result.insert(forward_element<Container>(e));
    return result;
}

template<class AssociativeContainer>
void id9(AssociativeContainer& container, const typename AssociativeContainer::key_type& key)
{
    for (auto i = begin(container); i != end(container);)
        if (key == *i)
            i = container.erase(i);
        else
            ++i;
}

template<class AssociativeContainer, class Predicate>
void id1(AssociativeContainer& container, Predicate&& p)
{
    for (auto i = begin(container); i != end(container);)
        if (p(*i))
            i = container.erase(i);
        else
            ++i;
}

class factorizer
{
public:
    void factorize(u64 n, vector<u64>& out)
    {
        if (n > id5)
            calculate_primes(n);
        auto last_p = primes_.cbegin();
        u64 index = 0;
        while (n != 1)
        {
            for (auto p = last_p; ; ++p)
            {
                if (n % *p == 0)
                {
                    n /= *p;
                    if (index >= out.size())
                        out.push_back(*p);
                    else
                        out[index++] = *p;
                    last_p = p;
                    break;
                }
            }
        }
    }

    vector<u64> factorize(u64 n)
    {
        vector<u64> result;
        factorize(n, result);
        return result;
    }

    bool is_prime(u64 n)
    {
        if (n > id5)
            calculate_primes(n);
        return primes_.count(n);
    }

    void calculate_primes(u64 n)
    {
        if (n < id5)
            return;
        u64 s = sqrt(static_cast<long double>(n)) + 1e-25L;
        vector<u8> ns(n - id5, 1);
        for (u64 d = 2; d <= s; ++d)
        {
            if (d <= id5 && !primes_.count(d))
                continue;
            else if (!ns[d - id5 - 1])
                continue;
            for (u64 i = cust_max(2_u64 * d, id5 + 1_u64); i <= n; i += d)
                ns[i - id5 - 1] = 0;
        }
        for (auto i = ns.cbegin(); i != ns.cend(); ++i)
            if (*i)
                primes_.insert(distance(ns.cbegin(), i) + id5 + 1_u64);
        id5 = n;
    }

    const auto& primes() const noexcept { return primes_; }

    const auto& limit() const noexcept { return id5; }

private:
    u64 id5 = 1_u64;
    set<u64> primes_;
};



constexpr bool DEBUG_TIME = 0;
constexpr bool id17 = 0;
constexpr bool id16 = 0;
constexpr bool id11 = 0;

constexpr string_view FILE_IN = "";
constexpr string_view FILE_OUT = "";

constexpr bool id12 = 0;



void solve()
{
    i64 n = read<i64>();
    vector<set<i64>> vs(n);
    set<i64> alls;
    for (i64 i = 0; i < n; ++i)
    {
        auto v = read_v<i64>();
        for (auto e : v)
        {
            alls.insert(e);
            vs[i].insert(e);
        }
    }

    id1(alls, [&](const auto& e) -> bool
    {
        bool result = true;
        for (const auto& s : vs)
            if (!s.count(e))
            {
                result = false;
                break;
            }
        if (!result)
            return true;
        return false;
    });

    for (auto i : alls)
        cout << i << ' ';
    cout << endl;
}



int main()
{
    using namespace chrono;

    auto start = high_resolution_clock::now();
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
        if constexpr (!id17)
        {
            input_file.open("../codeforces/input");
            cin.rdbuf(input_file.rdbuf());
        }
        if constexpr (!id16)
        {
            output_file.open("../codeforces/output");
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
    if constexpr (id12)
        tests = read<u64>();
    for (u64 i = 1; i <= tests; ++i)
    {
        if constexpr (DEBUG && id11)
        {
            if (tests > 1)
                cout << "<out" << i << ">" << endl;
        }
        solve();
        if constexpr (DEBUG && id11)
        {
            if (tests > 1)
                cout << "</out" << i << ">" << endl;
            if (i != tests)
                cout << endl;
        }
    }
    if constexpr (DEBUG && DEBUG_TIME)
    {
        cout << endl << endl;
        const auto exec_duration = high_resolution_clock::now() - start;
        const auto exec_sec = duration_cast<duration<long double, ratio<1, 1>>>(exec_duration).count();
        cout << "time: " << fixed << setprecision(6) << exec_sec << " seconds" << endl;
    }
    cout.flush();
    cin.rdbuf(in_buf);
    cout.rdbuf(out_buf);
    return 0;
}
