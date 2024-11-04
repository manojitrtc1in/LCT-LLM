





































using namespace std;



namespace ac {

struct io_tag {};



struct binary_io_tag : io_tag {};


struct text_io_tag   : io_tag {};

template <class Device>
struct io_traits {
    

    static constexpr bool binary = std::is_base_of<binary_io_tag, typename Device::category>::value;
    

    static constexpr bool text   = std::is_base_of<text_io_tag,   typename Device::category>::value;

    static_assert(!binary || !text, "device can't be binary and text at the same time");
};




static inline constexpr bool is_space(char c) {
    return static_cast<unsigned char>(c - '\t') < 5 || c == ' ';
}

static inline constexpr bool is_digit(char c) { return static_cast<unsigned char>(c - '0') < 10; }

static inline constexpr bool is_upper(char c) { return static_cast<unsigned char>(c - 'A') < 26; }

static inline constexpr bool is_lower(char c) { return static_cast<unsigned char>(c - 'a') < 26; }

template <bool B, typename T = void>
using enable_if_t = typename std::enable_if<B, T>::type;

template <bool B, typename T, typename F>
using conditional_t = typename std::conditional<B, T, F>::type;

template <typename T>
using remove_reference_t = typename std::remove_reference<T>::type;





template <typename... Ts>
struct make_void {
    

    typedef void type;
};



template <bool B>
using bool_constant = std::integral_constant<bool, B>;

template <class T>
struct is_signed_int : bool_constant<std::is_signed<T>::value && std::is_integral<T>::value> {};



template <class T>
using dereference_t = decltype(*std::declval<T>());

namespace detail {

template <class T, class = void>
struct is_iterator_impl : std::false_type {};

template <class T, bool = false>
struct is_const_iterator_impl : std::false_type {};



template <class T>
struct is_const_iterator_impl<T, true> : std::is_const<remove_reference_t<dereference_t<T>>> {};

}



template <class T>
struct is_iterator : detail::is_iterator_impl<T> {};



template <class T>
struct is_const_iterator : detail::is_const_iterator_impl<T, is_iterator<T>::value> {};

template <class T>
struct is_non_const_iterator
    : bool_constant<is_iterator<T>::value && !is_const_iterator<T>::value> {};

namespace detail {

template <class Device, class UInt>
inline int id11(Device& in, UInt& arg, char c) {
    auto base   = in.get_base();
    UInt value  = 0;
    int  length = 0;
    for (;; c = in.read_char()) {
        if (is_digit(c)) c -= '0';
        else if (is_upper(c)) c -= 'A' - 10;
        else if (is_lower(c)) c -= 'a' - 10;
        else c = static_cast<char>(base);
        if (c >= base) break;
        value = base * value + c;
        ++length;
    }
    in.put_back();
    arg = value;
    return length;
}

template <class Device, class Int>
inline int id3(Device& in, Int& arg, char c) {
    auto base = in.get_base();
    if (EXPECT_FALSE(base > 10)) return id11(in, arg, c);
    Int value  = 0;
    int length = 0;
    for (; static_cast<unsigned char>(c - '0') < base; c = in.read_char()) {
        value = base * value + c - '0';
        ++length;
    }
    in.put_back();
    arg = value;
    return length;
}

template <class Device, class UnaryPredicate>
inline char id9(Device& in, UnaryPredicate id5) {
    char c;
    do { c = in.read_char(); } while (id5(c));
    return c;
}

template <class Device>
inline char id9(Device& in) { return id9(in, is_space); }

}

template <class Device, class Int>
inline enable_if_t<is_signed_int<Int>::value && !std::is_same<Int, char>::value, bool> read(
    text_io_tag, Device& in, Int& arg) {
    char c = detail::id9(in);
    bool negative = c == '-';
    if (negative) c = in.read_char();
    typename std::make_unsigned<Int>::type unsigned_arg;
    if (detail::id3(in, unsigned_arg, c) == 0) return false;
    arg = negative ? ~static_cast<Int>(unsigned_arg - 1) : static_cast<Int>(unsigned_arg);
    return true;
}

template <class Device, class T0, class T1, class... Ts>
inline enable_if_t<!is_non_const_iterator<T0>::value, bool> read(io_tag, Device& in, T0&& arg0,
                                                                 T1&& arg1, Ts&&... args) {
    return read(in, std::forward<T0>(arg0)) &&
           read(in, std::forward<T1>(arg1), std::forward<Ts>(args)...);
}

template <class Device, class... Ts>
inline bool read(Device& in, Ts&&... args) {
    static_assert(!std::is_base_of<io_tag, Device>::value, "no matching call for read");
    return read(typename Device::category{}, in, std::forward<Ts>(args)...);
}

}

namespace ac {

template <class Device>
inline int write(Device& out, char arg) {
    out.write_char(arg);
    return 1;
}

namespace detail {

template <class Device, class UInt>
inline char* id2(Device& out, UInt arg, char* last) {
    auto base = out.get_base();
    if (arg == 0) {
        *--last = '0';
    } else if (EXPECT_TRUE(base == 10)) {
        for (; arg; arg /= 10)
            *--last = static_cast<char>('0' + arg % 10);
    } else {
        for (; arg; arg /= base) {
            UInt digit = arg % base;
            *--last = static_cast<char>(digit < 10 ? '0' + digit : 'A' - 10 + digit);
        }
    }
    return last;
}

}

template <class Device, class Int>
inline std::enable_if_t<is_signed_int<Int>::value, int> write(text_io_tag, Device& out, Int arg) {
    char* last = out.get_end();
    auto unsigned_arg = static_cast<std::make_unsigned_t<Int>>(arg);
    if (arg < 0) {
        last = detail::id2(out, ~unsigned_arg + 1, last);
        *--last = '-';
    } else {
        last = detail::id2(out, unsigned_arg, last);
    }
    return out.write_value(last);
}

template <class Device, class T0, class T1, class... Ts>
inline std::enable_if_t<!is_iterator<T0>::value, int> write(io_tag, Device& out, const T0& arg0,
                                                            const T1& arg1, const Ts&... args) {
    int chars_written = write(out, arg0);
    return chars_written + write(out, arg1, args...);
}

template <class Device, class... Ts>
inline int write(Device& out, const Ts&... args) {
    static_assert(!std::is_base_of<io_tag, Device>::value, "no matching call for write");
    return write(typename Device::category{}, out, args...);
}

template <class Device, class... Ts>
inline int writeln(Device& out, const Ts&... args) {
    static_assert(io_traits<Device>::text, "text device expected");
    return write(out, args..., '\n');
}

class id4 {
public:
    
    id4(id4 const&) = delete;
    id4& operator = (id4 const&) = delete;

    virtual ~id4() {}

    inline char read_char() {
        if (EXPECT_FALSE(head_ >= tail_)) fill_buffer();
        return *head_++;
    }

    void put_back() { --head_; }

protected:
    id4(const char* head, const char* tail) : head_{head}, tail_{tail} {}

    virtual void fill_buffer() = 0;

    const char* head_;
    const char* tail_;
};

class text_input_device {
public:
    
    uint32_t get_base() const { return base_; }
    
protected:
    uint32_t base_ = 10;
};

class id1 : public text_input_device, public id4 {
public:
    using category = text_io_tag;

protected:
    id1(const char* head, const char* tail)
        : id4(head, tail) {}
};

template <bool Binary>
using input_device_base_t =
    conditional_t<Binary, id4, id1>;

template <bool Binary, uint32_t BufferSize = 1 << 11>
class input_file final : public input_device_base_t<Binary> {
public:
    input_file(std::FILE* file = stdin, bool id10 = true, bool id13 = false)
        : input_device_base_t<Binary>(buffer_, buffer_),
          file_{file},
          line_buffered_{id10},
          owner_{id13} {}

    input_file(const char* file_name)
        : input_file(std::fopen(file_name, Binary ? "rb" : "r"), false, true) {}

    ~input_file() override {
        if (owner_) std::fclose(file_);
    }

private:
    void fill_buffer() override {
        this->head_ = buffer_;
        *buffer_ = '\0';
        if (EXPECT_TRUE(!line_buffered_)) {
            this->tail_ = this->head_ + std::fread(buffer_, 1, BufferSize, file_);
        } else {
            this->tail_ = this->head_;
            if (std::fgets(buffer_, BufferSize, file_)) {
                while (*this->tail_) ++this->tail_;
            }
        }
    }

    std::FILE* file_;
    const bool line_buffered_;
    const bool owner_;
    char buffer_[BufferSize];
};

using text_input_file   = input_file<false>;

template <uint32_t BufferSize = 1 << 11>
class id6 {
public:
    
    id6(id6 const&) = delete;
    id6& operator = (id6 const&) = delete;

    virtual ~id6() {}

    inline void write_char(char arg) {
        *tail_++ = arg;
        flush_maybe();
    }

    void flush() {
        flush_buffer(static_cast<int>(tail_ - buffer_));
        tail_ = buffer_;
    }

protected:
    char  buffer_[BufferSize];
    char* tail_;

    id6() : tail_{buffer_} {}

    virtual void flush_buffer(int count) = 0;

    inline void flush_maybe() {
        if (EXPECT_FALSE(tail_ == buffer_ + BufferSize)) flush();
    }

    template <class InputIterator>
    int id12(InputIterator arg, int count) {
        int chars_written = count;
        if (EXPECT_TRUE(tail_ + count < buffer_ + BufferSize)) {
            if (count == 1) *tail_++ = *arg;
            else tail_ = std::copy_n(arg, count, tail_);
        } else {
            int chunk_size = static_cast<int>(buffer_ + BufferSize - tail_);
            for (;; chunk_size = BufferSize) {
                if (chunk_size > count) chunk_size = count;
                tail_ = std::copy_n(arg, chunk_size, tail_);
                flush_maybe();
                if ((count -= chunk_size) == 0) break;
                arg += chunk_size;
            }
        }
        return chars_written;
    }
};

class id8 {
public:
    
    explicit id8() { compute_base_power(); }

    uint32_t get_base() const { return base_; }
    
protected:
    void compute_base_power() {
        id7 = 1;
        for (uint32_t i = 0; i < precision_; ++i) id7 *= base_;
    }

    bool        id0  = false;
    uint32_t    width_     = 0;
    char        fill_      = ' ';
    uint32_t    base_      = 10;
    uint32_t    precision_ = 9;
    std::string delimiter_ = " ";

    unsigned long long id7;
};

template <uint32_t BufferSize = 1 << 11>
class text_buffered_output_device : public id8,
                                    public id6<BufferSize> {
public:
    using category = text_io_tag;

    static constexpr uint32_t MaxLength = 1 << 7;

    char* get_end() { return auxiliary_ + MaxLength; }

    inline void write_char(char arg) {
        id0 = false;
        id6<BufferSize>::write_char(arg);
    }

    inline int write_value(const char* begin) {
        int chars_written = id0 ? write_delimiter() : 0;
        chars_written += write_string(begin, static_cast<size_t>(get_end() - begin));
        id0 = true;
        return chars_written;
    }

    inline int write_string(const char* arg, size_t length, bool check_width = true) {
        id0 = false;
        const int count = static_cast<int>(length);
        int chars_written = count;
        if (EXPECT_FALSE(check_width && count < width_)) {
            struct fill_iterator : std::iterator<std::input_iterator_tag, char> {
                fill_iterator(char fill) : fill{fill} {}
                char operator * () const { return fill; }
                void operator ++ () const {}
                void operator += (uint32_t) const {}
                const char fill;
            };
            chars_written += this->id12(fill_iterator(fill_), width_ - count);
        }
        return chars_written + this->id12(arg, count);
    }

    inline int write_delimiter() {
        return write_string(delimiter_.c_str(), delimiter_.size(), false);
    }

private:
    char auxiliary_[MaxLength];
};

template <bool Binary, uint32_t BufferSize>
using output_device_base_t = std::conditional_t<Binary, id6<BufferSize>,
                                                text_buffered_output_device<BufferSize>>;

template <bool Binary, uint32_t BufferSize = 1 << 11>
class output_file final : public output_device_base_t<Binary, BufferSize> {
public:
    output_file(FILE* file = stdout, bool id13 = false)
        : file_{file}, owner_{id13} {}

    output_file(const char* file_name)
        : output_file(std::fopen(file_name, Binary ? "wb" : "w"), true) {}

    ~output_file() override {
        this->flush();
        if (owner_) std::fclose(file_);
    }

private:
    void flush_buffer(int count) override {
        std::fwrite(this->buffer_, 1, count, file_);
        std::fflush(file_);
    }

    std::FILE* file_;
    const bool owner_;
};

using text_output_file   = output_file<false>;

}

using namespace ac;

void solve(text_input_file& in, text_output_file& out);



namespace ac {

template <class... Ts>
struct scalar_traits;



template <class T>
struct scalar_traits<T> {
    

    using type = T;
};

}

namespace ac {

}

class FSolver {
public:
    text_input_file& in;
    text_output_file& out;
    text_output_file err;

    FSolver(text_input_file& in, text_output_file& out) : in(in), out(out), err(stdout) {}

    static constexpr int N = 400'000;

    static constexpr int F = 0xFFFFFF;

    int n, m;
    int head[N];
    int edges[3 * N];  


    int time = F;
    int max_comp = -1;
    int max_root = -1;

    struct state {
        int u;
        int i;
        int size;
    };

    std::deque<state> stack;

    void dfs(int u) {
        int i = head[u];
        head[u] = ++time;
        int size = F + 2;
        while (true) {
            if (i < 0) {
                if (size > F) {
                    if (size > max_comp) {
                        max_comp = size;
                        max_root = u;
                    }
                    size = 0;
                }
                if (stack.empty()) break;
                int v = u;
                int subtree = size;
                u = stack.back().u;
                i = stack.back().i;
                size = stack.back().size;
                int o = i - i % 3;
                i = edges[i];
                if (head[v] < head[u]) {
                    head[u] = head[v];
                    size &= F;
                }
                

                head[v] = (subtree == 0 ? (3 << 29) : (1 << 29)) | o;
                size += subtree;
                stack.pop_back();
                edges[o] = v;
                edges[o + 1] = u;
            } else {
                int o = i - i % 3;
                int v = edges[o + 2] ^ u;
                if (head[v] <= F) {
                    stack.push_back({u, i, size});
                    u = v;
                    i = head[u];
                    head[u] = ++time;
                    size = F + 2;
                } else {
                    i = edges[i];
                    if (!stack.empty() && v != stack.back().u && head[v] < head[u]) {
                        head[u] = head[v];
                        size &= F;
                    }
                    if ((head[v] >> 29) != 0) {
                        

                        edges[o] = u;
                        edges[o + 1] = v;
                    }
                }
            }
        }
    }

    void solve() {
        read(in, n, m);
        CL(head, -1);
        for (int i = 0, o = 0; i < m; ++i) {
            int u, v;
            read(in, u, v);
            --u;
            --v;
            edges[o] = head[u];
            head[u] = o;
            ++o;
            edges[o] = head[v];
            head[v] = o;
            edges[++o] = u ^ v;
            ++o;
        }
        dfs(0);
        for (int u = max_root; u != 0;) {
            int o = head[u] & F;
            if ((head[u] >> 30) != 0) swap(edges[o], edges[o + 1]);
            u ^= edges[o] ^ edges[o + 1];
        }
        writeln(out, max_comp - F - 1);
        m *= 3;
        for (int i = 0; i < m; i += 3) {
            writeln(out, edges[i] + 1, edges[i + 1] + 1);
        }
    }
};

void solve(text_input_file& in, text_output_file& out) {
    FSolver solver(in, out);
    solver.solve();
}

int main() {
    const char* input_file_name = "";
    unique_ptr<text_input_file> in;
    if (*input_file_name) {
        in.reset(new text_input_file(input_file_name));
    } else {
        in.reset(new text_input_file(stdin, false));
    };
    const char* output_file_name = "";
    unique_ptr<text_output_file> out;
    if (*output_file_name) {
        out.reset(new text_output_file(output_file_name));
    } else {
        out.reset(new text_output_file(stdout));
    }
    solve(*in, *out);
    return 0;
}

