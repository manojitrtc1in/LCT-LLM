


#include <algorithm>
#include <array>
#include <cmath>
#include <initializer_list>
#include <list>
#include <unordered_set>
#include <utility>




#pragma once
#ifndef _DEBUG
#define NDEBUG
#endif
#include <list>

constexpr auto is_debug =
#ifdef NDEBUG
    false
#else
    true
#endif
;

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <type_traits>

using namespace std::literals; 

using std::size_t;
using std::vector;
using std::string;
using std::cout;
using std::cin;

[[maybe_unused]] const auto static_ini_ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return std::cout.tie(nullptr);
}();

class console_output_buffer_binder final
{
    using buf_ptr_t = std::streambuf*;

    vector<std::stringbuf> buffers_;
    const buf_ptr_t console_buf_ = cout.rdbuf();

public:
    explicit console_output_buffer_binder(const size_t additional_count = 0) noexcept :
        buffers_(additional_count + 1),
        console_buf_(std::cout.rdbuf(&buffers_.front())) { bind_to(0); }

    console_output_buffer_binder(const console_output_buffer_binder&) = delete;
    console_output_buffer_binder& operator=(const console_output_buffer_binder&) = delete;

    struct scope_binder
    {
        const buf_ptr_t new_buf_p;
        const buf_ptr_t old_buf_p;

        explicit scope_binder(std::streambuf* new_buf) : new_buf_p(new_buf), old_buf_p(cout.rdbuf(new_buf)) {}
        ~scope_binder() { cout.rdbuf(old_buf_p); }
    };

    void bind_to(const size_t i) { cout.rdbuf(&buffers_[i]); }

    auto scope_bind_to(const size_t i) { return scope_binder{&buffers_[i]}; }

    void add_to_front() { buffers_.emplace_back(); }

    auto scope_add_front()
    {
        add_to_front();
        return scope_bind_to(buffers_.size() - 1);
    }

    ~console_output_buffer_binder()
    {
        cout.rdbuf(console_buf_);
        const auto size = buffers_.size();
        for(auto i = size - 1; i < size; --i) cout << buffers_[i].str();
    }
};

#ifdef __cpp_lib_concepts
#include <concepts>
#include <ranges>

template<typename From, typename To>
concept ConvertibleToRef = std::convertible_to<From, std::decay_t<To>&&> || std::convertible_to<From, std::decay_t<To>&>;

template<typename T, ConvertibleToRef<std::istream> InputStream, typename... Args>
requires requires(InputStream is, T t)
{
    std::constructible_from<T, Args...>;
    is >> t;
}
#else
template<
    typename T,
    typename InputStream,
    typename... Args,
    std::enable_if_t<std::is_constructible_v<T, Args...>>* = nullptr,
    std::enable_if_t<std::is_convertible_v<T, std::istream&&> || std::is_convertible_v<T, std::istream&>>* = nullptr
>
#endif
T get_from_stream(InputStream&& is, Args&&... args)
{
    if constexpr(sizeof...(Args) > 0)
    {
        T t{(std::forward<Args>(args), ...)};
        is >> t;
        return t;       
    }
    else return *std::istream_iterator<T>(is);
}


#ifndef NDEBUG
#include "../algorithm_utility/debug_utils.h"
#endif

using std::array;
using std::string_view;
using std::initializer_list;
using std::uint8_t;
using std::pair;
using std::unordered_set;
using std::list;



class rabbit_move_box
{
    struct coordinate
    {
        int x;
        int y;
    };

    coordinate start_;
    coordinate end_;
public:
    constexpr rabbit_move_box(const coordinate start, const coordinate end) noexcept : start_(start), end_(end) {}

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

            rabbit_move_box{start, end}.solve();
        }
    }
};


class snake_circle_rooms
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
        vector<size_t> indices_of_off_state;
        size_t i;
        auto semi_returnable = true;
        indices_of_off_state.reserve(states_.size());

        {
            auto is_all_clock_wise = true, is_all_anti_clock_wise = true;
            for(i = 0; i < states_.size(); ++i)
            {
                switch(states_[i])
                {
                case belt_state::clockwise: is_all_anti_clock_wise = false;
                    if(!is_all_clock_wise) goto end_label;
                    break;
                case belt_state::anticlockwise: is_all_clock_wise = false;
                    if(!is_all_anti_clock_wise) goto end_label;
                    break;
                case belt_state::off: indices_of_off_state.emplace_back(i);
                    break;
                end_label:
                    semi_returnable = false;
                }
                if(!semi_returnable) break;
            }
        }

        for(; i < states_.size(); ++i) if(states_[i] == belt_state::off) indices_of_off_state.emplace_back(i);

        return {semi_returnable, indices_of_off_state};
    }

public:
    void solve() const
    {
        const auto& [semi_returnable, indices_of_off_state] = is_semi_returnable();
        if(semi_returnable)
        {
            cout << states_.size() << '\n';
            return;
        }

        unordered_set<size_t> returnable_room_indices(states_.size());
        for(const auto index : indices_of_off_state)
        {
            returnable_room_indices.insert(index);
            returnable_room_indices.insert((index + 1) % states_.size());
        }

        cout << returnable_room_indices.size() << '\n';
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

            snake_circle_rooms{std::move(states)}.solve();
        }
    }

    explicit snake_circle_rooms(vector<belt_state> belt_states) : states_(std::move(belt_states)) {}
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


class bouncing_boomerangs
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

        [[nodiscard]] auto place_boomerang(size_t available_row_start) const
        {
            const auto indices_size = column_indices.size();
            vector<coordinate> boomerangs(2 * indices_size - 1 - has_two);
            auto add_boomerang = [&, boomerangs_it = boomerangs.begin()](const size_t col)mutable
            {
                *boomerangs_it++ = {available_row_start, col};
            };
            {
                

                auto i = indices_size - 1;
                for(; i > static_cast<decltype(i)>(has_two); --i)
                {
                    add_boomerang(column_indices[i]);
                    add_boomerang(column_indices[i - 1]);
                    ++available_row_start;
                }
                

                

                add_boomerang(column_indices[i]);
            }

            

            if(has_two) add_boomerang(column_indices.front());

            return boomerangs;
        }
    };

    using chain_list_t = vector<chain>;

    vector<bounce_count_t> bounce_times_;

    
    bool resolve_column(
        const size_t col,
        chain_list_t& chain_list,
        size_t& three_end_index,
        size_t& two_end_index
    ) const
    {
        switch(bounce_times_[col])
        {
            

        case 1: chain_list.push_back({initializer_list<size_t>{col}});
            

        case 0: break;
            

        case 2:
            {
                if(two_end_index < three_end_index) two_end_index = three_end_index;
                if(chain_list.size() <= two_end_index) return false;

                auto& chain = chain_list[two_end_index++];
                chain.has_two = true;
                chain.column_indices.emplace_back(col);
            }
            break;
            

        case 3:
            {
                if(chain_list.empty()) return false;
                if(three_end_index == 0) ++three_end_index;
                chain_list.front().column_indices.emplace_back(col);
            }
            break;
        }

        return true;
    }

    [[nodiscard]] auto find_chains() const
    {
        const auto bounce_times_count = bounce_times_.size();
        chain_list_t chain_list;
        size_t three_end_index = 0, two_end_index = 0;

        using return_t = pair<bool, decltype(chain_list)>;

        for(auto i = bounce_times_count - 1; i < bounce_times_count; --i)
            if(!resolve_column(i, chain_list, three_end_index, two_end_index))
                return return_t{false, chain_list};

        return return_t{true, chain_list};
    }

public:
    explicit bouncing_boomerangs(decltype(bounce_times_) bounce_times) : bounce_times_(std::move(bounce_times)) {}

    void solve() const
    {
#ifndef NDEBUG
        [[maybe_unused]] counter c_;
#endif

        const auto& [is_valid, chains] = find_chains();
        if(!is_valid)
        {
            cout << "-1\n";
            return;
        }

        size_t available_row_start = 0;
        size_t coordinates_count = 0;
        console_output_buffer_binder binder{};
        for(const auto& chain : chains)
        {
            const auto& boomerangs = chain.place_boomerang(available_row_start);
            available_row_start = boomerangs.back().row + 1;
            coordinates_count += boomerangs.size();

            for(const auto [row, col] : boomerangs) cout << row + 1 << ' ' << col + 1 << '\n';
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

        bouncing_boomerangs{std::move(values)}.solve();
    }
};

int main()
{
#ifdef NDEBUG
    bouncing_boomerangs::create_from_input();
#else
    bouncing_boomerangs{{2, 0, 3, 0, 1, 1}}.solve();
    bouncing_boomerangs{{0}}.solve();
    bouncing_boomerangs{{3, 2, 2, 2, 1, 1}}.solve();
    bouncing_boomerangs{{3, 2, 1}}.solve();
    bouncing_boomerangs{{2, 2, 1, 1}}.solve();
    bouncing_boomerangs{{3, 3, 2, 1}}.solve();
    bouncing_boomerangs{{3, 3, 3, 1}}.solve();
    bouncing_boomerangs{{3, 3, 2, 2, 1, 1}}.solve();
    

#endif
    return 0;
}
