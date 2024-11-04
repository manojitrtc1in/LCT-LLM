



















constexpr auto is_debug =

    false

    true

;







using namespace std::literals; 

using std::size_t;
using std::vector;
using std::string;
using std::cout;
using std::cin;

[[maybe_unused]] const auto id3 = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return std::cout.tie(nullptr);
}();

class id1 final
{
    using buf_ptr_t = std::streambuf*;

    vector<std::stringbuf> buffers_;
    const buf_ptr_t console_buf_ = cout.rdbuf();

public:
    explicit id1(const size_t additional_count = 0) noexcept :
        buffers_(additional_count + 1),
        console_buf_(std::cout.rdbuf(&buffers_.front())) { bind_to(0); }

    id1(const id1&) = delete;
    id1& operator=(const id1&) = delete;

    struct id17
    {
        const buf_ptr_t new_buf_p;
        const buf_ptr_t old_buf_p;

        explicit id17(std::streambuf* new_buf) : new_buf_p(new_buf), old_buf_p(cout.rdbuf(new_buf)) {}
        ~id17() { cout.rdbuf(old_buf_p); }
    };

    void bind_to(const size_t i) { cout.rdbuf(&buffers_[i]); }

    auto scope_bind_to(const size_t i) { return id17{&buffers_[i]}; }

    void add_to_front() { buffers_.emplace_back(); }

    auto scope_add_front()
    {
        add_to_front();
        return scope_bind_to(buffers_.size() - 1);
    }

    ~id1()
    {
        cout.rdbuf(console_buf_);
        const auto size = buffers_.size();
        for(auto i = size - 1; i < size; --i) cout << buffers_[i].str();
    }
};





template<typename From, typename To>
concept ConvertibleToRef = std::convertible_to<From, std::decay_t<To>&&> || std::convertible_to<From, std::decay_t<To>&>;

template<typename T, ConvertibleToRef<std::istream> InputStream, typename... Args>
requires requires(InputStream is, T t)
{
    std::constructible_from<T, Args...>;
    is >> t;
}

template<
    typename T,
    typename InputStream,
    typename... Args,
    std::enable_if_t<std::is_constructible_v<T, Args...>>* = nullptr,
    std::enable_if_t<std::is_convertible_v<T, std::istream&&> || std::is_convertible_v<T, std::istream&>>* = nullptr
>

T id0(InputStream&& is, Args&&... args)
{
    if constexpr(sizeof...(Args) > 0)
    {
        T t{(std::forward<Args>(args), ...)};
        is >> t;
        return t;       
    }
    else return *std::istream_iterator<T>(is);
}






using std::array;
using std::string_view;
using std::initializer_list;
using std::uint8_t;
using std::pair;
using std::unordered_set;
using std::list;



class id16
{
    struct coordinate
    {
        int x;
        int y;
    };

    coordinate start_;
    coordinate end_;
public:
    constexpr id16(const coordinate start, const coordinate end) noexcept : start_(start), end_(end) {}

    void solve() const noexcept
    {
        const auto dis_x = std::abs(end_.x - start_.x);
        const auto dis_y = std::abs(end_.y - start_.y);

        if(dis_x == 0) cout << dis_y;
        else if(dis_y == 0) cout << dis_x;
        else cout << dis_x + dis_y + 2;
        cout << '\n';
    }

    static void create_from_input()
    {
        size_t size;
        cin >> size;

        for(decltype(size) i = 0; i < size; ++i)
        {
            coordinate start{};
            coordinate end{};

            cin >> start.x;
            cin >> start.y;
            cin >> end.x;
            cin >> end.y;

            id16{start, end}.solve();
        }
    }
};


class id12
{
    enum class belt_state
    {
        

        clockwise,
        

        anticlockwise,
        

        off
    };

    vector<belt_state> states_;

    [[nodiscard]] pair<bool, vector<size_t>> is_semi_returnable() const noexcept
    {
        vector<size_t> id4;
        size_t i;
        auto id10 = true;
        id4.reserve(states_.size());

        {
            auto id14 = true, id7 = true;
            for(i = 0; i < states_.size(); ++i)
            {
                switch(states_[i])
                {
                case belt_state::clockwise: id7 = false;
                    if(!id14) goto end_label;
                    break;
                case belt_state::anticlockwise: id14 = false;
                    if(!id7) goto end_label;
                    break;
                case belt_state::off: id4.emplace_back(i);
                    break;
                end_label:
                    id10 = false;
                }
                if(!id10) break;
            }
        }

        for(; i < states_.size(); ++i) if(states_[i] == belt_state::off) id4.emplace_back(i);

        return {id10, id4};
    }

public:
    void solve() const
    {
        const auto& [id10, id4] = is_semi_returnable();
        if(id10)
        {
            cout << states_.size() << '\n';
            return;
        }

        unordered_set<size_t> id8(states_.size());
        for(const auto index : id4)
        {
            id8.insert(index);
            id8.insert((index + 1) % states_.size());
        }

        cout << id8.size() << '\n';
    }

    static void create_from_input()
    {
        size_t size;
        cin >> size;

        for(decltype(size) i = 0; i < size; ++i)
        {
            vector<belt_state> states;
            {
                size_t room_num{};
                cin >> room_num;
                states.resize(room_num);
            }

            for(auto& state : states)
            {
                char input_state;
                cin >> input_state;
                switch(input_state)
                {
                case '>': state = belt_state::clockwise;
                    break;
                case '<': state = belt_state::anticlockwise;
                    break;
                case '-': state = belt_state::off;
                    break;
                default: ;
                }
            }

            id12{std::move(states)}.solve();
        }
    }

    explicit id12(vector<belt_state> belt_states) : states_(std::move(belt_states)) {}
};


class bomb_string
{
    string_view str_;
public:
    explicit constexpr bomb_string(const string_view str) noexcept : str_(str) {}

    void solve() const
    {
        size_t size = 0;
        for(const auto c : str_)
            if(c == 'B' && size > 0) --size;
            else ++size;
        cout << size << '\n';
    }

    static void create_from_input()
    {
        size_t size;
        cin >> size;

        for(decltype(size) i = 0; i < size; ++i)
        {
            string str;
            cin >> str;
            bomb_string{std::move(str)}.solve();
        }
    }
};


class id11
{
public:
    using bounce_count_t = uint8_t;

private:
    struct coordinate
    {
        size_t row, col;
    };

    

    struct chain
    {
        

        vector<size_t> column_indices;

        bool has_two;

        [[nodiscard]] auto place_boomerang(size_t id9) const
        {
            const auto indices_size = column_indices.size();
            vector<coordinate> id2(2 * indices_size - 1 - has_two);
            auto id13 = [&, id6 = id2.begin()](const size_t col)mutable
            {
                *id6++ = {id9, col};
            };
            {
                

                auto i = indices_size - 1;
                for(; i > static_cast<decltype(i)>(has_two); --i)
                {
                    id13(column_indices[i]);
                    id13(column_indices[i - 1]);
                    ++id9;
                }
                

                

                id13(column_indices[i]);
            }

            

            if(has_two) id13(column_indices.front());

            return id2;
        }
    };

    using chain_list_t = vector<chain>;

    vector<bounce_count_t> bounce_times_;

    
    bool resolve_column(
        const size_t col,
        chain_list_t& chain_list,
        size_t& id15,
        size_t& id18
    ) const
    {
        switch(bounce_times_[col])
        {
            

        case 1: chain_list.push_back({initializer_list<size_t>{col}});
            

        case 0: break;
            

        case 2:
            {
                if(id18 < id15) id18 = id15;
                if(chain_list.size() <= id18) return false;

                auto& chain = chain_list[id18++];
                chain.has_two = true;
                chain.column_indices.emplace_back(col);
            }
            break;
            

        case 3:
            {
                if(chain_list.empty()) return false;
                if(id15 == 0) ++id15;
                chain_list.front().column_indices.emplace_back(col);
            }
            break;
        }

        return true;
    }

    [[nodiscard]] auto find_chains() const
    {
        const auto id5 = bounce_times_.size();
        chain_list_t chain_list;
        size_t id15 = 0, id18 = 0;

        using return_t = pair<bool, decltype(chain_list)>;

        for(auto i = id5 - 1; i < id5; --i)
            if(!resolve_column(i, chain_list, id15, id18))
                return return_t{false, chain_list};

        return return_t{true, chain_list};
    }

public:
    explicit id11(decltype(bounce_times_) bounce_times) : bounce_times_(std::move(bounce_times)) {}

    void solve() const
    {

        [[maybe_unused]] counter c_;


        const auto& [is_valid, chains] = find_chains();
        if(!is_valid)
        {
            cout << "-1\n";
            return;
        }

        size_t id9 = 0;
        size_t coordinates_count = 0;
        id1 binder{};
        for(const auto& chain : chains)
        {
            const auto& id2 = chain.place_boomerang(id9);
            id9 = id2.back().row + 1;
            coordinates_count += id2.size();

            for(const auto [row, col] : id2) cout << row + 1 << ' ' << col + 1 << '\n';
        }

        {
            auto front_scope = binder.scope_add_front();
            cout << coordinates_count << '\n';
        }
    }

    static void create_from_input()
    {
        vector<uint8_t> values;
        {
            size_t size;
            cin >> size;
            values.resize(size);
        }

        for(auto& v : values)
        {
            unsigned short temp;
            cin >> temp;
            v = static_cast<decltype(values)::value_type>(temp);
        }

        id11{std::move(values)}.solve();
    }
};

int main()
{

    id11::create_from_input();

    id11{{2, 0, 3, 0, 1, 1}}.solve();
    id11{{0}}.solve();
    id11{{3, 2, 2, 2, 1, 1}}.solve();
    id11{{3, 2, 1}}.solve();
    id11{{2, 2, 1, 1}}.solve();
    id11{{3, 3, 2, 1}}.solve();
    id11{{3, 3, 3, 1}}.solve();
    id11{{3, 3, 2, 2, 1, 1}}.solve();
    


    return 0;
}
