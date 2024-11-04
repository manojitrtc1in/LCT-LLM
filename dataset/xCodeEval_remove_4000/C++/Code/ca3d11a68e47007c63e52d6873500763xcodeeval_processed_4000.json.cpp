






















namespace std {
template <typename _Tp>
  constexpr bool id7 = is_void<_Tp>::value;
template <typename _Tp>
  constexpr bool id57 = is_null_pointer<_Tp>::value;
template <typename _Tp>
  constexpr bool id48 = is_integral<_Tp>::value;
template <typename _Tp>
  constexpr bool id60 = is_floating_point<_Tp>::value;
template <typename _Tp>
  constexpr bool id16 = is_array<_Tp>::value;
template <typename _Tp>
  constexpr bool id64 = is_pointer<_Tp>::value;
template <typename _Tp>
  constexpr bool id67 =
    is_lvalue_reference<_Tp>::value;
template <typename _Tp>
  constexpr bool id9 =
    is_rvalue_reference<_Tp>::value;
template <typename _Tp>
  constexpr bool id55 =
    is_member_object_pointer<_Tp>::value;
template <typename _Tp>
  constexpr bool id50 =
    is_member_function_pointer<_Tp>::value;
template <typename _Tp>
  constexpr bool id44 = is_enum<_Tp>::value;
template <typename _Tp>
  constexpr bool id59 = is_union<_Tp>::value;
template <typename _Tp>
  constexpr bool id8 = is_class<_Tp>::value;
template <typename _Tp>
  constexpr bool id38 = is_function<_Tp>::value;
template <typename _Tp>
  constexpr bool id40 = is_reference<_Tp>::value;
template <typename _Tp>
  constexpr bool id4 = is_arithmetic<_Tp>::value;
template <typename _Tp>
  constexpr bool id45 = is_fundamental<_Tp>::value;
template <typename _Tp>
  constexpr bool id49 = is_object<_Tp>::value;
template <typename _Tp>
  constexpr bool id27 = is_scalar<_Tp>::value;
template <typename _Tp>
  constexpr bool id24 = is_compound<_Tp>::value;
template <typename _Tp>
  constexpr bool id22 = is_member_pointer<_Tp>::value;
template <typename _Tp>
  constexpr bool id56 = is_const<_Tp>::value;
template <typename _Tp>
  constexpr bool id6 = is_volatile<_Tp>::value;
template <typename _Tp>
  constexpr bool id25 = is_trivial<_Tp>::value;
template <typename _Tp>
  constexpr bool id13 =
    is_trivially_copyable<_Tp>::value;
template <typename _Tp>
  constexpr bool id62 = is_standard_layout<_Tp>::value;
template <typename _Tp>
  constexpr bool id10 = is_pod<_Tp>::value;
template <typename _Tp>
  constexpr bool id2 = is_literal_type<_Tp>::value;
template <typename _Tp>
  constexpr bool id3 = is_empty<_Tp>::value;
template <typename _Tp>
  constexpr bool id1 = is_polymorphic<_Tp>::value;
template <typename _Tp>
  constexpr bool id41 = is_abstract<_Tp>::value;
template <typename _Tp>
  constexpr bool id23 = is_final<_Tp>::value;
template <typename _Tp>
  constexpr bool id0 = is_signed<_Tp>::value;
template <typename _Tp>
  constexpr bool id14 = is_unsigned<_Tp>::value;
template <typename _Tp, typename... _Args>
  constexpr bool id18 =
    is_constructible<_Tp, _Args...>::value;
template <typename _Tp>
  constexpr bool id65 =
    is_default_constructible<_Tp>::value;
template <typename _Tp>
  constexpr bool id66 =
    is_copy_constructible<_Tp>::value;
template <typename _Tp>
  constexpr bool id61 =
    is_move_constructible<_Tp>::value;
template <typename _Tp, typename _Up>
  constexpr bool id53 = is_assignable<_Tp, _Up>::value;
template <typename _Tp>
  constexpr bool id37 = is_copy_assignable<_Tp>::value;
template <typename _Tp>
  constexpr bool id28 = is_move_assignable<_Tp>::value;
template <typename _Tp>
  constexpr bool id51 = is_destructible<_Tp>::value;
template <typename _Tp, typename... _Args>
  constexpr bool id54 =
    is_trivially_constructible<_Tp, _Args...>::value;
template <typename _Tp>
  constexpr bool id33 =
    is_trivially_default_constructible<_Tp>::value;
template <typename _Tp>
  constexpr bool id58 =
    is_trivially_copy_constructible<_Tp>::value;
template <typename _Tp>
  constexpr bool id17 =
    is_trivially_move_constructible<_Tp>::value;
template <typename _Tp, typename _Up>
  constexpr bool id43 =
    is_trivially_assignable<_Tp, _Up>::value;
template <typename _Tp>
  constexpr bool id19 =
    is_trivially_copy_assignable<_Tp>::value;
template <typename _Tp>
  constexpr bool id36 =
    is_trivially_move_assignable<_Tp>::value;
template <typename _Tp>
  constexpr bool id42 =
    is_trivially_destructible<_Tp>::value;
template <typename _Tp, typename... _Args>
  constexpr bool id52 =
    is_nothrow_constructible<_Tp, _Args...>::value;
template <typename _Tp>
  constexpr bool id29 =
    is_nothrow_default_constructible<_Tp>::value;
template <typename _Tp>
  constexpr bool id21 =
    is_nothrow_copy_constructible<_Tp>::value;
template <typename _Tp>
  constexpr bool id68 =
    is_nothrow_move_constructible<_Tp>::value;
template <typename _Tp, typename _Up>
  constexpr bool id30 =
    is_nothrow_assignable<_Tp, _Up>::value;
template <typename _Tp>
  constexpr bool id47 =
    is_nothrow_copy_assignable<_Tp>::value;
template <typename _Tp>
  constexpr bool id39 =
    is_nothrow_move_assignable<_Tp>::value;
template <typename _Tp>
  constexpr bool id34 =
    is_nothrow_destructible<_Tp>::value;
template <typename _Tp>
  constexpr bool id5 =
    has_virtual_destructor<_Tp>::value;
template <typename _Tp>
  constexpr size_t id11 = alignment_of<_Tp>::value;
template <typename _Tp>
  constexpr size_t rank_v = rank<_Tp>::value;
template <typename _Tp, unsigned _Idx = 0>
  constexpr size_t extent_v = extent<_Tp, _Idx>::value;

template <typename _Tp, typename _Up>
  constexpr bool id26 = _GLIBCXX_BUILTIN_IS_SAME_AS(_Tp, _Up);

template <typename _Tp, typename _Up>
  constexpr bool id26 = std::is_same<_Tp, _Up>::value;

template <typename _Base, typename _Derived>
  constexpr bool id35 = is_base_of<_Base, _Derived>::value;
template <typename _From, typename _To>
  constexpr bool id32 = is_convertible<_From, _To>::value;
}

namespace OY {






    template <uint64_t _BufferSize = 1024, uint64_t _BlockSize = 20>
    class inputHelper {
        FILE *id63;
        char m_buf[_BufferSize], *m_end, *m_cursor;
        bool m_ok;
        void flush() {
            uint64_t a = m_end - m_cursor;
            if (a >= _BlockSize) return;
            memmove(m_buf, m_cursor, a);
            uint64_t b = fread(m_buf + a, 1, _BufferSize - a, id63);
            m_cursor = m_buf;
            if (a + b < _BufferSize) {
                m_end = m_buf + a + b;
                *m_end = EOF;
            }
        }

    public:
        explicit inputHelper(const char *inputFileName) : m_ok(true) {
            if (!*inputFileName)
                id63 = stdin;
            else
                id63 = fopen(inputFileName, "rt");
            m_end = m_cursor = m_buf + _BufferSize;
        }
        ~inputHelper() { fclose(id63); }
        static inputHelper<_BufferSize, _BlockSize> &getInstance() {

            static inputHelper<_BufferSize, _BlockSize> s_obj("in.txt");

            static inputHelper<_BufferSize, _BlockSize> s_obj("");

            return s_obj;
        }
        static constexpr bool isBlank(char c) { return c == ' ' || c == '\t' || c == '\n' || c == '\r'; }
        static constexpr bool isEndline(char c) { return c == '\n' || c == EOF; }
        const char &getChar_Checked() {
            if (m_cursor < m_end) return *m_cursor;
            uint64_t b = fread(m_buf, 1, _BufferSize, id63);
            m_cursor = m_buf;
            if (b < _BufferSize) {
                m_end = m_buf + b;
                *m_end = EOF;
            }
            return *m_cursor;
        }
        const char &getChar_Unchecked() const { return *m_cursor; }
        void next() { ++m_cursor; }
        void setState(bool _ok) { m_ok = _ok; }
        template <typename _Tp, std::enable_if_t<std::id0<_Tp> & std::id48<_Tp>> * = nullptr>
        inputHelper<_BufferSize, _BlockSize> &operator>>(_Tp &ret) {
            while (isBlank(getChar_Checked())) next();
            flush();
            if (getChar_Unchecked() == '-') {
                next();
                if (isdigit(getChar_Unchecked())) {
                    ret = -(getChar_Unchecked() - '0');
                    while (next(), isdigit(getChar_Unchecked())) ret = ret * 10 - (getChar_Unchecked() - '0');
                } else
                    m_ok = false;
            } else {
                if (isdigit(getChar_Unchecked())) {
                    ret = getChar_Unchecked() - '0';
                    while (next(), isdigit(getChar_Unchecked())) ret = ret * 10 + (getChar_Unchecked() - '0');
                } else
                    m_ok = false;
            }
            return *this;
        }
        template <typename _Tp, std::enable_if_t<std::id14<_Tp> & std::id48<_Tp>> * = nullptr>
        inputHelper<_BufferSize, _BlockSize> &operator>>(_Tp &ret) {
            while (isBlank(getChar_Checked())) next();
            flush();
            if (isdigit(getChar_Unchecked())) {
                ret = getChar_Unchecked() - '0';
                while (next(), isdigit(getChar_Unchecked())) ret = ret * 10 + (getChar_Unchecked() - '0');
            } else
                m_ok = false;
            return *this;
        }
        template <typename _Tp, std::enable_if_t<std::id60<_Tp>> * = nullptr>
        inputHelper<_BufferSize, _BlockSize> &operator>>(_Tp &ret) {
            bool neg = false, integer = false, decimal = false;
            while (isBlank(getChar_Checked())) next();
            flush();
            if (getChar_Unchecked() == '-') {
                neg = true;
                next();
            }
            if (!isdigit(getChar_Unchecked()) && getChar_Unchecked() != '.') {
                m_ok = false;
                return *this;
            }
            if (isdigit(getChar_Unchecked())) {
                integer = true;
                ret = getChar_Unchecked() - '0';
                while (next(), isdigit(getChar_Unchecked())) ret = ret * 10 + (getChar_Unchecked() - '0');
            }
            if (getChar_Unchecked() == '.') {
                next();
                if (isdigit(getChar_Unchecked())) {
                    if (!integer) ret = 0;
                    decimal = true;
                    _Tp unit = 0.1;
                    ret += unit * (getChar_Unchecked() - '0');
                    while (next(), isdigit(getChar_Unchecked())) {
                        unit *= 0.1;
                        ret += unit * (getChar_Unchecked() - '0');
                    }
                }
            }
            if (!integer && !decimal)
                m_ok = false;
            else if (neg)
                ret = -ret;
            return *this;
        }
        inputHelper<_BufferSize, _BlockSize> &operator>>(char &ret) {
            while (isBlank(getChar_Checked())) next();
            ret = getChar_Checked();
            next();
            return *this;
        }
        inputHelper<_BufferSize, _BlockSize> &operator>>(std::string &ret) {
            while (isBlank(getChar_Checked())) next();
            if (getChar_Checked() != EOF) {
                ret.clear();
                do {
                    ret += getChar_Checked();
                    next();
                } while (!isBlank(getChar_Checked()) && getChar_Unchecked() != EOF);
            } else
                m_ok = false;
            return *this;
        }
        explicit operator bool() { return m_ok; }
    };
    template <uint64_t _BufferSize = 1048576>
    class outputHelper {
        FILE *id63 = nullptr;
        char m_buf[_BufferSize], *m_end, *m_cursor;
        char id46[50], *id12, *id31;
        uint64_t id20, id15;

    public:
        outputHelper(const char *outputFileName, int prec = 6) : m_end(m_buf + _BufferSize) {
            if (!*outputFileName)
                id63 = stdout;
            else
                id63 = fopen(outputFileName, "wt");
            m_cursor = m_buf;
            id12 = id46;
            precision(prec);
        }
        static outputHelper<_BufferSize> &getInstance() {

            static outputHelper<_BufferSize> s_obj("out.txt");

            static outputHelper<_BufferSize> s_obj("");

            return s_obj;
        }
        ~outputHelper() {
            flush();
            fclose(id63);
        }
        void precision(int prec) {
            id20 = prec;
            id15 = pow(10, prec);
            id31 = id46 + prec;
        }
        outputHelper<_BufferSize> &flush() {
            fwrite(m_buf, 1, m_cursor - m_buf, id63);
            fflush(id63);
            m_cursor = m_buf;
            return *this;
        }
        void putChar(const char &c) {
            if (m_cursor == m_end) flush();
            *m_cursor++ = c;
        }
        void putS(const char *c) {
            while (*c) putChar(*c++);
        }
        template <typename _Tp, std::enable_if_t<std::id0<_Tp> & std::id48<_Tp>> * = nullptr>
        outputHelper<_BufferSize> &operator<<(const _Tp &ret) {
            _Tp _ret = _Tp(ret);
            if (_ret >= 0) {
                do {
                    *id12++ = '0' + _ret % 10;
                    _ret /= 10;
                } while (_ret);
                do putChar(*--id12);
                while (id12 > id46);
            } else {
                putChar('-');
                do {
                    *id12++ = '0' - _ret % 10;
                    _ret /= 10;
                } while (_ret);
                do putChar(*--id12);
                while (id12 > id46);
            }
            return *this;
        }
        template <typename _Tp, std::enable_if_t<std::id14<_Tp> & std::id48<_Tp>> * = nullptr>
        outputHelper<_BufferSize> &operator<<(const _Tp &ret) {
            _Tp _ret = _Tp(ret);
            do {
                *id12++ = '0' + _ret % 10;
                _ret /= 10;
            } while (_ret);
            do putChar(*--id12);
            while (id12 > id46);
            return *this;
        }
        template <typename _Tp, std::enable_if_t<std::id60<_Tp>> * = nullptr>
        outputHelper<_BufferSize> &operator<<(const _Tp &ret) {
            if (ret < 0) {
                putChar('-');
                return *this << -ret;
            }
            _Tp _ret = ret * id15;
            uint64_t integer = _ret;
            if (_ret - integer >= 0.4999999999) integer++;
            do {
                *id12++ = '0' + integer % 10;
                integer /= 10;
            } while (integer);
            if (id12 > id31) {
                do putChar(*--id12);
                while (id12 > id31);
                putChar('.');
            } else {
                putS("0.");
                for (int i = id31 - id12; i--;) putChar('0');
            }
            do putChar(*--id12);
            while (id12 > id46);
            return *this;
        }
        outputHelper<_BufferSize> &operator<<(const char &ret) {
            putChar(ret);
            return *this;
        }
        outputHelper<_BufferSize> &operator<<(const std::string &ret) {
            putS(ret.data());
            return *this;
        }
    };
    template <uint64_t _BufferSize, uint64_t _BlockSize>
    inputHelper<_BufferSize, _BlockSize> &getline(inputHelper<_BufferSize, _BlockSize> &ih, std::string &ret) {
        ret.clear();
        if (ih.getChar_Checked() == EOF)
            ih.setState(0);
        else {
            while (!inputHelper<_BufferSize, _BlockSize>::isEndline(ih.getChar_Checked())) {
                ret += ih.getChar_Unchecked();
                ih.next();
            }
            ih.next();
        }
        return ih;
    }
    template <typename D, typename T, typename... S>
    void printLog(D delim, const T &x, S... rest) {
        cout << x;
        if (sizeof...(rest) > 0) {
            cout << delim;
            printLog(delim, rest...);
        }
    }
}
using OY::getline;
const int N = 3e5;
int fa[N];
long long a[N];
std::vector<std::vector<int>> seg;

int find(int x) {
    return (fa[x] == x ? fa[x] : fa[x] = find(fa[x]));
}

std::deque<int> q;

void solve() {
    int n, m, l, r;
    long long x;
    cin >> n >> m;
    fa[0] = a[0] = 0;
    seg.resize(n + 5);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        cin >> a[i];
    }
    fa[n + 1] = n + 1;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        a[i] += a[i - 1]  - x;
    }
    for (int i = 0; i <= n; ++i) {
        if (!a[i]) {
            fa[i] = i + 1;
            q.push_back(i);
        }
    }
    

    for (int i = 1; i <= m; ++i) {
        cin >> l >> r;
        seg[l - 1].push_back(r);
        seg[r].push_back(l - 1);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        for (int v : seg[u]) {
            if (a[v]) continue;
            l = std::min(v, u), r = std::max(v, u);
            int now = l;
            while (now <= r) {
                if (a[now]) {
                    a[now] = 0;
                    q.push_back(now);
                }
                now = fa[now] = find(now + 1);
            }
        }
    }
    bool pd = true;
    for (int i = 0; i <= n; ++i) {
        if (a[i]) {
            pd = false;
            break;
        }
    }
    if (pd) cout << "YES\n";
    else cout << "NO\n";
    q.clear();
    seg.clear();
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}