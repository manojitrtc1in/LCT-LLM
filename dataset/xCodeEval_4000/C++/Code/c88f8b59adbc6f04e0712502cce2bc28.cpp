

#include <bits/stdc++.h>
using namespace std;


using u64 = uint64_t;
using u32 = uint32_t;
using i64 = int64_t;
using i32 = int32_t;
template <typename ...Ts>
using vt = std::vector<Ts...>;
template <typename ...Ts>
using mp = std::map<Ts...>;
template <typename ...Ts>
using um = std::unordered_map<Ts...>;
template <typename ...Ts>
using st = std::set<Ts...>;
template <typename ...Ts>
using us = std::unordered_set<Ts...>;
const i64 inf = (1ll << 62);
const i64 imin = std::numeric_limits<i64>::min();
const i64 imax = std::numeric_limits<i64>::max();
const i64 umax = std::numeric_limits<u64>::max();
template <typename T> T abs_m(T a) { return a >= 0 ? a : -a; }
auto maxi(i64 a, i64 b) { return a > b ? a : b; }
auto maxu(u64 a, u64 b) { return a > b ? a : b; }
auto minu(u64 a, u64 b) { return a < b ? a : b; }
auto mini(i64 a, i64 b) { return a < b ? a : b; }
void merror(std::string msg, i64 line_number) { std::cerr << "assert >> " << line_number << ": " << msg << std::endl; exit(42); }
#ifndef NDEBUG
#define massert(c, msg) do { if (!(c)) merror(msg, __LINE__); } while(0)
#define massert2(c) massert(c, "")
#else
#define massert(...)
#define massert2(...)
#endif
template <typename C> i64 isize(const C& c) { return static_cast<i64>(c.size()); }
template <typename T, size_t N> i64 isize(const std::array<T, N>& = {}) { return static_cast<i64>(N); }
template <typename It, typename Cont> bool it_last(It it, const Cont& c) { return ++it == c.end(); }




namespace fun {
template <class Cont, class Fun>
auto map(Cont const& c, Fun const& f) {
    std::vector<std::decay_t<decltype(f(*c.begin()))>> v;
    v.reserve(isize(c));
    std::transform(c.begin(), c.end(),
            std::back_inserter(v),
            f);
    return v;
}
template <class Cont, class Fun>
void map_inplace(Cont & c, Fun const& f) {
    std::transform(c.begin(), c.end(),
            c.begin(),
            f);
}
template <class Cont1, class Cont2>
auto merge(Cont1 const& range1, Cont2 const& range2) {
    std::vector<std::decay_t<decltype(*range1.begin())>> v;
    v.reserve(isize(range1) + isize(range2));
    std::merge(range1.begin(), range1.end(),
            range2.begin(), range2.end(),
            std::back_inserter(v));
    return v;
}
template <class Cont, class ...Args>
void sort(Cont & cont, Args && ...args) {
    std::sort(cont.begin(), cont.end(),
            std::forward<Args>(args)...);
}
template <class Cont, class ...Args>
auto sorted(Cont cont, Args && ...args) {
    sort(cont, std::forward<Args>(args)...);
    return cont;
}
template <class Cont>
void reverse(Cont & cont) {
    std::reverse(cont.begin(), cont.end());
}
template <class Cont>
auto reversed(Cont cont) {
    reverse(cont);
    return cont;
}
template <class Cont, class ...Args>
auto count(Cont cont, Args && ...args) {
    return std::count(cont.begin(), cont.end(), args...);
}
template <class Cont>
auto min_element(Cont const& cont) {
    return std::min_element(cont.begin(), cont.end());
}

auto lex_compare = [](auto const& r1, auto const& r2)
    { return std::lexicographical_compare(r1.begin(), r1.end(), r2.begin(), r2.end()); };

auto first = [](auto const& e) { return e.first; };
auto second = [](auto const& e) { return e.second; };
template <std::size_t n> auto nth = [](auto const& e) { return std::get<n>(e); };

auto surround = [](auto const& a, char b, char c = '\0') { return b + a + (c ? c : b); };
template <typename T> const auto identity = [](const T& t) -> const T& { return t; };
auto join = [](auto const& container, auto const& separator, auto const& mapper) {
    std::string s;
    for (auto it = container.begin(); it != container.end(); it++) {
        if (it != container.begin())
            s += separator;
        s += mapper(*it);
    }
    return s;
};
} 

template <class T> auto vector_less(T const& a, T const& b) { return fun::lex_compare(a, b); }




template<class F, class T, int next_index_reversed>
struct TupleForeach { auto operator()(F const& f, T const& t) {
    auto static constexpr n = static_cast<int>(std::tuple_size<T>::value) - next_index_reversed - 1;
    f(n, std::get<n>(t));
    TupleForeach<F, T, next_index_reversed - 1>()(f, t);
}};
template<class F, class T>
struct TupleForeach<F, T, -1> { auto operator()(F const&, T const&) {
}};
template <class F, class T> void tuple_foreach(F const& f, T const& t)
    { TupleForeach<F, T, std::tuple_size<T>::value - 1>()(f, t); }
template <class F, class S, class ...Ts>
auto join_tuple(std::tuple<Ts...> const& tpl, S const& separator, F const& mapper) {
    std::string res;
    tuple_foreach([&](i64 num, auto const& e) {
        if (num != 0) res += separator;
        res += mapper(e);
    }, tpl);
    return res;
}




template<class...> using void_t = void;
template <class, class = void> struct has_repr : std::false_type {};
template <class T> struct has_repr<T, void_t<decltype(std::declval<T>()._repr())>> : std::true_type {};
template <class, class = void> struct has_str : std::false_type {};
template <class T> struct has_str<T, void_t<decltype(std::declval<T>()._str())>> : std::true_type {};
template <class, class = void> struct has_read : std::false_type {};
template <class T> struct has_read<T, void_t<decltype(std::declval<T>()._read())>> : std::true_type {};
template <class, class = void> struct is_map : std::false_type {};
template <class T> struct is_map<T, void_t<typename T::key_type, typename T::mapped_type>> : std::true_type {};
template <class, class = void> struct is_set : std::false_type {};
template <class T> struct is_set<T, void_t<typename T::key_type>> : std::true_type {};
template <class T> constexpr bool _is_char_ptr()
    { return std::is_same<std::decay_t<T>, char*>::value || std::is_same<std::decay_t<T>, const char*>::value; }
template <class, class = void> struct is_ptr : std::false_type {};
template <class ...Ts> struct is_ptr<std::shared_ptr<Ts...>> : std::true_type {};
template <class ...Ts> struct is_ptr<std::unique_ptr<Ts...>> : std::true_type {};
template <class ...Ts> struct is_ptr<std::weak_ptr<Ts...>> : std::true_type {};
template <class T> struct is_ptr<T, void_t<std::enable_if_t<std::is_pointer<T>::value && !_is_char_ptr<T>()>>>
    : std::true_type {};




template <class T, class = void> struct _Str { auto operator()(const T& t)
    { return std::to_string(t); }};
template <class T> std::string str(const T& t)
    { return _Str<T>()(t); }
template <> struct _Str<std::string> { auto operator()(const std::string& t)
    { return t; }};
template <class T> struct _Str<T, std::enable_if_t<_is_char_ptr<T>()>> { auto operator()(T const& t)
    { return std::string(t); }};
template <> struct _Str<char> { auto operator()(char const& t)
    { return std::string(1, t); }};
template <class T> struct _Str<T, std::enable_if_t<is_ptr<T>::value>> { auto operator()(T const& t)
    { return t ? str(*t) : str("(nullptr)"); }};
template <class T> struct _Str<T, std::enable_if_t<has_str<T>::value>> { auto operator()(T const& t)
    { return t._str(); }};
template <class T> struct _Str<std::reference_wrapper<T>> { auto operator()(T const& t)
    { return str(t.get()); }};
struct StrFunctor { template <class T> auto operator()(T const& t) const; };
template <class T, std::size_t N> struct _Str<std::array<T, N>> { auto operator()(std::array<T, N> const& t)
    { return fun::join(t, ' ', StrFunctor()); }};
template <class T> struct _Str<std::vector<T>> { auto operator()(std::vector<T> const& t)
    { return fun::join(t, ' ', StrFunctor()); }};
template <class T> struct _Str<T, std::enable_if_t<is_set<T>::value && !is_map<T>::value>>
        { auto operator()(T const& t)
    { return fun::join(t, ' ', StrFunctor()); }};
template <class T> struct _Str<T, std::enable_if_t<is_map<T>::value>> { auto operator()(T const& t)
    { return fun::join(t, ' ', StrFunctor()); }};
template <class ...Ts> struct _Str<std::tuple<Ts...>> { auto operator()(std::tuple<Ts...> const& t)
    { return join_tuple(t, ' ', StrFunctor()); }};
template <class T1, class T2> struct _Str<std::pair<T1, T2>> { auto operator()(const std::pair<T1, T2>& p)
    { return str(std::make_tuple(p.first, p.second)); }};
template <class T> auto StrFunctor::operator()(T const& t) const
    { return str(t); }




template <class T, class = void> struct _Repr { auto operator()(T const& t)
    { return str(t); }};
template <class T> std::string repr(const T& t)
    { return _Repr<T>()(t); }
template <> struct _Repr<std::string> { auto operator()(const std::string& t)
    { return fun::surround(str(t), '"'); }};
template <> struct _Repr<char> { auto operator()(char const& t)
    { return fun::surround(str(t), '\''); }};
template <class T> struct _Repr<T, std::enable_if_t<_is_char_ptr<T>()>> { auto operator()(T const& t)
    { return fun::surround(str(t), '"'); }};
template <class T> struct _Repr<T, std::enable_if_t<is_ptr<T>::value>> { auto operator()(T const& t)
    { return t ? repr(*t) : str(t); }};
template <class T> struct _Repr<T, std::enable_if_t<has_repr<T>::value>> { auto operator()(T const& t)
    { return t._repr(); }};
template <class T> struct _Repr<std::reference_wrapper<T>> { auto operator()(T const& t)
    { return repr(t.get()); }};
struct ReprFunctor { template <class T> auto operator()(T const& t) const; };
template <class T, std::size_t N> struct _Repr<std::array<T, N>> { auto operator()(std::array<T, N> const& t)
    { return fun::surround(fun::join(t, ',', ReprFunctor()), '[', ']'); }};
template <class T> struct _Repr<std::vector<T>> { auto operator()(std::vector<T> const& t)
    { return fun::surround(fun::join(t, ',', ReprFunctor()), '[', ']'); }};
template <class T> struct _Repr<T, std::enable_if_t<is_set<T>::value && !is_map<T>::value>>
        { auto operator()(T const& t)
    { return fun::surround(fun::join(t, ',', ReprFunctor()), '{', '}'); }};
auto _repr_map_item = [](auto const& item) { return join_tuple(std::make_tuple(item.first, item.second), ':', ReprFunctor()); };
template <class T> struct _Repr<T, std::enable_if_t<is_map<T>::value>> { auto operator()(T const& t)
    { return fun::surround(fun::join(t, ',', _repr_map_item), '{', '}'); }};
template <class ...Ts> struct _Repr<std::tuple<Ts...>> { auto operator()(std::tuple<Ts...> const& t)
    { return fun::surround(join_tuple(t, ',', ReprFunctor()), '(', ')'); }};
template <class T1, class T2> struct _Repr<std::pair<T1, T2>> { auto operator()(const std::pair<T1, T2>& p)
    { return repr(std::make_tuple(p.first, p.second)); }};
template <class T> auto ReprFunctor::operator()(T const& t) const
    { return repr(t); }
template <class ...Ts>
auto make_repr(std::string classname, const std::vector<std::string>& header, Ts &&... ts) {
    massert(isize(header) == sizeof...(ts), "header wrong length");
    std::string res;
    tuple_foreach([&](auto i, auto const& v) {
        if (i != 0) res += ',';
        res += header[i] + "=" + repr(v);
    }, std::make_tuple(std::forward<Ts>(ts)...));
    return classname + fun::surround(res, '(', ')');
}




template <class T>
struct Reader { T operator()()
    { T e = {}; std::cin >> e; return e; }};
template <class T> T read()
    { return Reader<T>()(); }
template <class T, std::size_t N> struct Reader<std::array<T, N>> { std::array<T, N> operator()()
    { std::array<T, N> res = {}; for (std::size_t i = 0; i < N; i++) res[i] = read<T>(); return res; }};
void read() {}
template <class T, class ...Ts> void read(T& v, Ts& ...ts)
    { v = read<T>(); read(ts...); }
template <class T> void readv(i64 n, std::vector<T>& v)
    { std::generate_n(std::back_inserter(v), n, [](){ return read<T>(); }); }
template <class T> std::vector<T> readv(i64 n)
    { std::vector<T> v; readv(n, v); return v; }




template <char c> struct Printer {
    template <class ...Ts> void operator()(Ts const&... ts)
        { outp << str(std::forward_as_tuple(ts...)) << c; }
    std::ostream& outp;
};
auto print = Printer<' '>{std::cout};
auto println = Printer<'\n'>{std::cout};
auto lprint = Printer<' '>{std::cerr};
auto lprintln = Printer<'\n'>{std::cerr};
#ifdef DEBUG_PRINTS
auto dprint = Printer<' '>{std::cerr};
auto dprintln = Printer<'\n'>{std::cerr};
#else
#define dprint(...)
#define dprintln(...)
#endif




size_t hash_combine() { return 1241245u; }
template <class T, class ...Ts>
size_t hash_combine(T const& t, Ts const&... ts) {
    return (std::hash<T>()(t) + 12431u) ^ hash_combine(ts...);
}







void _gen_spec_sum(vt<vt<i64>> & res, vt<i64> & part, i64 const k, i64 const s) {
    massert2(k);
    if (k == 1) {
        res.push_back(part);
        res.back().push_back(s);
        return;
    }
    for (i64 i = 0; i <= s; i++) {
        part.push_back(i);
        _gen_spec_sum(res, part, k - 1, s - i);
        part.pop_back();
    }
}

vt<vt<i64>> gen_specific_sum(i64 const k, i64 const s) {
    vt<vt<i64>> res;
    vt<i64> part;
    _gen_spec_sum(res, part, k, s);
    return res;
}


using PlayerCards = array<i64, 8>;
struct Hand {
    Hand() {
        cards[0] = 8;
    }
    Hand(PlayerCards cards0) {
        for (auto n : cards0) {
            massert2(n >= 0 && n <= 4);
            cards[n]++;
        }
    }
    Hand(vector<i64> const& counts) {
        massert2(isize(counts) == isize(cards));
        for (i64 i = 0; i < isize(counts); i++)
            cards[i] = counts[i];
    }
    bool has_card(i64 n) const {
        massert2(n >= 0 && n <= 4);
        return cards[n];
    }
    void replace(i64 n, i64 m) {
        massert2(n >= 0 && n <= 4);
        massert2(m >= 0 && m <= 4);
        massert2(cards[n]);
        --cards[n];
        ++cards[m];
    }
    bool is_winning() const {
        for (size_t i = 1; i <= 4; i++)
            if (cards[i])
                return false;
        return true;
    }
    bool operator==(Hand const& o) const {
        return cards == o.cards;
    }
    bool operator!=(Hand const& o) const {
        return cards != o.cards;
    }
    auto _str() const { return str(cards); }
    auto _repr() const { return make_repr("Hand", {"cards"}, cards); }
private:
    array<i64, 5> cards = {};
    friend struct std::hash<Hand>;
};
enum class Player { Alice = 0, Bob = 1 };
Player other_player(Player p) {
    return p == Player::Alice ? Player::Bob : Player::Alice;
}
string str_player(Player p) { return p == Player::Alice ? "Alice" : "Bob"; }
struct Board {
    Board() = delete;
    Board(array<Hand, 2> hands0, Player player0) : hands(hands0), player(player0)
    { }
    Board(Board const&) = default;
    Board create_child(i64 n, i64 p) const {
        Board res(*this);
        res.my_hand().replace(n, (n + p) % 5);
        res.player = other_player(res.player);
        return res;
    }
    Board create_parent(i64 n, i64 p) const {
        Board res(*this);
        res.other_hand().replace(n, (5 + n - p) % 5);
        res.player = other_player(res.player);
        return res;
    }
    vt<Board> get_children() const {
        vt<Board> children;
        for (size_t n = 1; n <= 4; n++)
            if (my_hand().has_card(n))
                for (size_t p = 1; p <= 4; p++)
                    if (other_hand().has_card(p))
                        children.push_back(create_child(n, p));
        return children;
    }
    vt<Board> get_parents() const {
        vt<Board> parents;
        for (size_t n = 0; n <= 4; n++)
            if (other_hand().has_card(n))
                for (size_t p = 1; p <= 4; p++)
                    if (my_hand().has_card(p) && p != n)
                        parents.push_back(create_parent(n, p));
        return parents;
    }
    bool is_losing() const {
        massert2(!my_hand().is_winning());
        return other_hand().is_winning();
    }
    auto get_player() const { return player; }
    bool operator==(Board const& o) const {
        return hands == o.hands && player == o.player;
    }
    static Board readme() {
        auto const player = static_cast<Player>(read<i64>());
        array<Hand, 2> hands = {};
        hands[0] = read<PlayerCards>();
        hands[1] = read<PlayerCards>();
        return Board(hands, player);
    }
    auto oneline() const {
        string res = "";
        for (i64 i = 0; i < 2; i++) {
            Player pl = static_cast<Player>(i);
            res += str(hands[i]) + ' ' + (pl == player ? '*' : ' ') + ' ' + str_player(pl) + '\t';
        }
        return res;
    }
    auto _str() const {
        string res = "\n";
        for (i64 i = 0; i < 2; i++) {
            Player pl = static_cast<Player>(i);
            res += str(hands[i]) + ' ' + (pl == player ? '*' : ' ') + ' ' + str_player(pl) + '\n';
        }
        return res;
    }
    auto _repr() const { return make_repr("Board", {"hands", "player"}, hands, str_player(player)); }
private:
    friend struct std::hash<Board>;
    Hand & my_hand() { return hands[static_cast<i64>(player)]; }
    Hand & other_hand() { return hands[static_cast<i64>(other_player(player))]; }
    Hand const& my_hand() const { return hands[static_cast<i64>(player)]; }
    Hand const& other_hand() const { return hands[static_cast<i64>(other_player(player))]; }
    array<Hand, 2> hands;
    Player player;
};


namespace std {
template<>
struct hash<::Hand> { size_t operator()(Hand const& h) const {
    massert2(h.cards[0] + h.cards[1] + h.cards[2] + h.cards[3] + h.cards[4] == 8);
    return h.cards[1] + h.cards[2] * 10u + h.cards[3] * 100u + h.cards[4] * 1000u;
}};
template<>
struct hash<::Board> { size_t operator()(Board const& p) const {
    return hash<::Hand>()(p.hands[0]) +
        hash<::Hand>()(p.hands[1]) * 10000u +
        (static_cast<i64>(p.player) + 1u) * 10000u * 10000u;
}};
} 




enum class Result { Deal, Wins, Loses };
string str_result(Result res) {
    if (res == Result::Deal)
        return "Deal";
    if (res == Result::Wins)
        return "Wins";
    if (res == Result::Loses)
        return "Loses";
    return str(static_cast<i64>(res));
}

struct TempResult {
    TempResult(Board const& board) {
        deal_children = isize(board.get_children());
        result = deal_children ? Result::Deal : Result::Loses;
    }
    bool update_from_child(Result res) {
        massert2(res == Result::Wins || res == Result::Loses);
        massert2(result == Result::Deal);
        if (res == Result::Loses) {
            result = Result::Wins;
            return true;
        }
        --deal_children;
        if (deal_children == 0) {
            result = Result::Loses;
            return true;
        }
        return false;
    }
    i64 deal_children;
    Result result;
};

using States = unordered_map<Board, TempResult>;

struct UnitedStates {
    UnitedStates() {
        queue<Board> nodes;
        for (auto const& sth : gen_specific_sum(5, 8)) {
            Hand hand_sth(sth), hand_empty;
            if (hand_sth != hand_empty) {
                auto b1 = Board({{hand_sth, hand_empty}}, Player::Alice);
                auto b2 = Board({{hand_empty, hand_sth}}, Player::Bob);
                states_.emplace(b1, b1);
                states_.emplace(b2, b2);
                nodes.push(b1);
                nodes.push(b2);
            }
        }
        while (!nodes.empty()) {
            Board const b = nodes.front();
            nodes.pop();
            auto const res = getvalue(b).result;
            massert2(res != Result::Deal);
            for (Board const parent : b.get_parents()) {
                auto & parent_res = getvalue(parent);
                if (parent_res.result == Result::Deal)
                    if (parent_res.update_from_child(res))
                        nodes.push(parent);
            }
        }
    }
    Result get_result(Board const& board) {
        return getvalue(board).result;
    }
private:
    TempResult & getvalue(Board const& board) {
        auto it = states_.find(board);
        if (it != states_.end())
            return it->second;
        return states_.emplace(board, board).first->second;
    }
    States states_;
};

void go() {
    i64 n = {};
    read(n);
    UnitedStates united_states;
    while (n--) {
        auto const board = Board::readme();
        auto const res = united_states.get_result(board);
        if (res == Result::Deal)
            println("Deal");
        if (res == Result::Wins)
            println(str_player(board.get_player()));
        if (res == Result::Loses)
            println(str_player(other_player(board.get_player())));
    }
}


int main () { 

    ios_base::sync_with_stdio(0);


    go();
} 

