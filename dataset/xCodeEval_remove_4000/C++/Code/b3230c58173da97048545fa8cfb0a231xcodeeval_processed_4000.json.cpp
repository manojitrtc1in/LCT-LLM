





















































using namespace std;


char c;
int n, Q;
bool a[5][N];
int lf[N], rt[N];
int belong[N];

void init() {
    int block = sqrt(n);
    int cnt = 0;
    for (register int i = 1; i <= n; i++) {
        cnt++;
        belong[i] = belong[i - 1];
        if (cnt == block) {
            belong[i]++;
            cnt = 0;
        }
    }
}

struct Query {
    int l, r, id, ans;
    bool operator < (const Query &q) const {
        if (belong[l] != belong[q.l]) {
            return belong[l] < belong[q.l];
        } else {
            if (belong[l] & 1) return r < q.r;
            else return r > q.r;
        }
    }
} q[M];

bool cmp(const Query q1, const Query q2) {
    return q1.id < q2.id;
}

int l, r, cnt;

int con1[N];
int con2[N];


void addl() {
    if (f(l, 1, 1, 1, 1, 0, 1) && rt[l + 1] <= r) {
        

    } else {
        cnt -= con2[l];
        cnt += con1[l + 1];
    }
    l++;
}

void addr() {
    if (f(r, 1, 0, 1, 1, 1, 1) && lf[r] >= l) {
        

    } else {
        cnt -= con1[r];
        cnt += con2[r];
    }
    r++;
}

void minl() {
    if (f(l - 1, 1, 1, 1, 1, 0, 1) && rt[l] <= r) {
        

    } else {
        cnt -= con1[l];
        cnt += con2[l - 1];
    }
    l--;
}

void minr() {
    if (f(r - 1, 1, 0, 1, 1, 1, 1) && lf[r - 1] >= l) {
        

    } else {
        cnt -= con2[r - 1];
        cnt += con1[r - 1];
    }
    r--;
}

namespace Fast_I {
    char *_Buf, *_Start_ptr, *_End_ptr;
    std::streambuf* inbuf;
    unsigned int Size;
    bool _Ok;

    struct id6 {
        operator bool() {
            return _Ok;
        }
        id6(std::streambuf*, unsigned int);
        id6(unsigned int);
        id6(const char*, unsigned int);
        id6& operator>>(char&);
        id6& operator>>(char*);
        id6& operator>>(bool&);
        id6& operator>>(short&);
        id6& operator>>(int&);
        id6& operator>>(long&);
        id6& operator>>(long long&);
        id6& operator>>(unsigned short&);
        id6& operator>>(unsigned int&);
        id6& operator>>(unsigned long&);
        id6& operator>>(unsigned long long&);
        id6& operator>>(float&);
        id6& operator>>(double&);
        id6& operator>>(long double&);
        id6& operator>>(std::string&);
        template <typename Typex>
        void operator()(Typex& _Val) {
            *this >> _Val;
        }
        template <typename Typex, typename... More>
        void operator()(Typex&, More&...);
        std::streambuf* rdbuf() {
            return inbuf;
        }
        void rdbuf(std::streambuf* _inbuf) {
            inbuf = _inbuf;
        }
        void rdbuf(const char*);
        void pop();
        char peek();
    };
}  

namespace Fast_O {
    std::string buf;
    std::streambuf* outbuf;

    struct id3 {
        id3(std::streambuf*, unsigned int);
        id3(std::streambuf* out) {
            outbuf = out;
        }
        id3(const char*, unsigned int);
        id3(unsigned int);
        void flush();
        ~id3();
        void endl() {
            buf.push_back('\n');
        }
        template <typename Typex>
        void endl(const Typex& _Val);
        template <typename Typex, typename... More>
        void endl(const Typex&, const More&...);
        template <typename Typex>
        void operator()(const Typex& _Val);
        template <typename Typex, typename... More>
        void operator()(const Typex&, const More&...);
        id3& operator<<(char);
        id3& operator<<(const char*);
        id3& operator<<(const std::string&);
        id3& operator<<(bool);
        id3& operator<<(short);
        id3& operator<<(int);
        id3& operator<<(long);
        id3& operator<<(long long);
        id3& operator<<(unsigned short);
        id3& operator<<(unsigned int);
        id3& operator<<(unsigned long);
        id3& operator<<(unsigned long long);
        std::streambuf* rdbuf() {
            return outbuf;
        }
        void rdbuf(std::streambuf* _outbuf) {
            outbuf = _outbuf;
        }
        void rdbuf(const char*);
    };
}  

namespace Fast_IO {
    Fast_I::id6 fin(std::cin.rdbuf(), 1048576);  

    Fast_O::id3 fout(std::cout.rdbuf());         

}  







namespace Fast_I {
    id6::id6(std::streambuf* in, unsigned int Sz) {
        _Ok = 1;
        Fast_I::Size = Sz;
        inbuf = in;
        _Start_ptr = _End_ptr = _Buf = new char[Sz];
    }
    id6::id6(const char* in, unsigned int Sz) {
        _Ok = 1;
        Fast_I::Size = Sz;
        rdbuf(in);
        _Start_ptr = _End_ptr = _Buf = new char[Sz];
    }
    id6::id6(unsigned int Sz) {
        _Ok = 1;
        Fast_I::Size = Sz;
        _Start_ptr = _End_ptr = _Buf = new char[Sz];
    }
    void id6::rdbuf(const char* File) {
        static std::ifstream id4(File);
        rdbuf(id4.rdbuf());
    }
    void id7(char& _Val) {
        if (_Start_ptr == _End_ptr) {
            _Start_ptr = _Buf;
            _End_ptr = _Buf + inbuf->sgetn(_Buf, Size);
        }
        if (_Start_ptr == _End_ptr) {
            _Val = -1;
            _Ok = 0;
        } else {
            _Val = *_Start_ptr++;
        }
    }
    id6& id6::operator>>(char& _Val) {
        if (_Ok) {
            id7(_Val);
            while (_Val == 32 || _Val == 10 || _Val == 13 || _Val == 8 || _Val == 9 ||
                    _Val == 7 || _Val == 12 || _Val == 11) {
                id7(_Val);
            }
        }
        return *this;
    }
    id6& id6::operator>>(char* _Val) {
        if (_Ok) {
            id7(*_Val);
            while (*_Val == 32 || *_Val == 10 || *_Val == 13 || *_Val == 8 ||
                    *_Val == 9 || *_Val == 7 || *_Val == 12 || *_Val == 11) {
                id7(*_Val);
            }
            while (*_Val != 32 && *_Val != 10 && *_Val && *_Val != -1 && *_Val != 9 &&
                    *_Val != 11 && *_Val != 12) {
                id7(*++_Val);
            }
            *_Val = 0;
            --_Start_ptr;
        }
        return *this;
    }
    id6& id6::operator>>(std::string& _Val) {
        if (_Ok) {
            char c;
            id7(c);
            while (c == 32 || c == 10 || c == 13 || c == 8 || c == 9 || c == 7 ||
                    c == 12 || c == 11) {
                id7(c);
            }
            for (_Val.clear();
                    c != 32 && c != 10 && c && c != -1 && c != 9 && c != 11 && c != 12;
                    id7(c)) {
                _Val.push_back(c);
            }
            --_Start_ptr;
        }
        return *this;
    }
    template <typename Typex>
    void Get_Int(Typex& _Val) {
        if (_Ok) {
            char ch;
            bool _F = 0;
            for (id7(ch); (ch < 48 || ch > 57) && ch != -1; id7(ch)) {
                _F = ch == 45;
            }
            for (_Val = 0; ch > 47 && ch < 58 && ch != -1; id7(ch)) {
                _Val = _Val * 10 + (ch ^ 48);
            }
            if (_F) {
                _Val = ~_Val + 1;
            }
            --_Start_ptr;
        }
    }
    template <typename Typex>
    void id2(Typex& _Val) {
        if (_Ok) {
            char ch;
            id7(ch);
            while ((ch < 48 || ch > 57) && ch != -1) {
                id7(ch);
            }
            for (_Val = 0; ch > 47 && ch < 58 && ch != -1; id7(ch)) {
                _Val = _Val * 10 + (ch ^ 48);
            }
            --_Start_ptr;
        }
    }
    template <typename Typex>
    void id1(Typex& _Val) {
        if (_Ok) {
            char ch;
            bool _F = 0;
            for (id7(ch); (ch < 48 || ch > 57) && ch != -1; id7(ch)) {
                _F = ch == 45;
            }
            for (_Val = 0; ch > 47 && ch < 58 && ch != -1; id7(ch)) {
                _Val = _Val * 10 + (ch ^ 48);
            }
            if (ch == 46) {
                unsigned long long _Pow = 1;
                for (id7(ch); ch > 47 && ch < 58 && ch != -1; id7(ch)) {
                    _Val += Typex((ch ^ 48) * 1.0 / (_Pow *= 10));
                }
            }
            if (_F) {
                _Val = -_Val;
            }
            --_Start_ptr;
        }
    }
    id6& id6::operator>>(bool& _Val) {
        if (_Ok) {
            char ch;
            id7(ch);
            while (ch == 32 || ch == 10 || ch == 13 || ch == 8 || ch == 9 || ch == 7 ||
                    ch == 12 || ch == 11) {
                id7(ch);
            }
            while (ch != 32 && ch != 10 && ch && ch != -1 && ch != 9 && ch != 11 &&
                    ch != 12) {
                _Val |= ch != 48;
                id7(ch);
            }
            --_Start_ptr;
        }
        return *this;
    }
    id6& id6::operator>>(short& _Val) {
        Get_Int(_Val);
        return *this;
    }
    id6& id6::operator>>(int& _Val) {
        Get_Int(_Val);
        return *this;
    }
    id6& id6::operator>>(long& _Val) {
        Get_Int(_Val);
        return *this;
    }
    id6& id6::operator>>(long long& _Val) {
        Get_Int(_Val);
        return *this;
    }
    id6& id6::operator>>(unsigned short& _Val) {
        id2(_Val);
        return *this;
    }
    id6& id6::operator>>(unsigned int& _Val) {
        id2(_Val);
        return *this;
    }
    id6& id6::operator>>(unsigned long& _Val) {
        id2(_Val);
        return *this;
    }
    id6& id6::operator>>(unsigned long long& _Val) {
        id2(_Val);
        return *this;
    }
    id6& id6::operator>>(float& _Val) {
        id1(_Val);
        return *this;
    }
    id6& id6::operator>>(double& _Val) {
        id1(_Val);
        return *this;
    }
    id6& id6::operator>>(long double& _Val) {
        id1(_Val);
        return *this;
    }
    template <typename Typex, typename... More>
    void id6::operator()(Typex& _Val, More&... _More) {
        *this >> _Val;
        operator()(_More...);
    }
    void id6::pop() {
        char ch;
        id7(ch);
    }
    char id6::peek() {
        if (_Start_ptr == _End_ptr) {
            _Start_ptr = _Buf;
            _End_ptr = _Buf + inbuf->sgetn(_Buf, Size);
        }
        if (_Start_ptr == _End_ptr) {
            _Ok = 0;
            return -1;
        } else {
            return *_Start_ptr;
        }
    }
}  

namespace Fast_O {
    id3::id3(std::streambuf* out, unsigned int Size) {
        buf.reserve(Size);
        outbuf = out;
    }
    id3::id3(const char* File, unsigned int Size) {
        buf.reserve(Size);
        rdbuf(File);
    }
    void id3::rdbuf(const char* File) {
        static std::ofstream id0(File);
        rdbuf(id0.rdbuf());
    }
    id3::id3(unsigned int Size) {
        buf.reserve(Size);
    }
    void id3::flush() {
        outbuf->sputn(buf.data(), buf.size());
        buf.clear();
    }
    id3::~id3() {
        flush();
    }
    id3& id3::operator<<(char _Val) {
        buf.push_back(_Val);
        return *this;
    }
    id3& id3::operator<<(const char* _Val) {
        while (*_Val) {
            buf.push_back(*_Val++);
        }
        return *this;
    }
    id3& id3::operator<<(const std::string& _Val) {
        for (auto&& i : _Val) {
            buf.push_back(i);
        }
        return *this;
    }
    template <typename Typex>
    void id5(Typex _Val) {
        char* _Stack = (char*)malloc(sizeof(Typex) * 3);
        unsigned S_top = 0;
        while (_Val) {
            _Stack[++S_top] = (_Val % 10) ^ 48;
            _Val /= 10;
        }
        if (!S_top) {
            buf.push_back('0');
        }
        while (S_top) {
            buf.push_back(_Stack[S_top--]);
        }
        free(_Stack);
    }
    void Put_Int(long long _Val) {
        if (_Val < 0) {
            buf.push_back('-');
            id5(~_Val + 1);
        } else {
            id5(_Val);
        }
    }
    id3& id3::operator<<(bool _Val) {
        buf.push_back(_Val ? '1' : '0');
        return *this;
    }
    id3& id3::operator<<(short _Val) {
        Put_Int(_Val);
        return *this;
    }
    id3& id3::operator<<(int _Val) {
        Put_Int(_Val);
        return *this;
    }
    id3& id3::operator<<(long _Val) {
        Put_Int(_Val);
        return *this;
    }
    id3& id3::operator<<(long long _Val) {
        Put_Int(_Val);
        return *this;
    }
    id3& id3::operator<<(unsigned short _Val) {
        id5(_Val);
        return *this;
    }
    id3& id3::operator<<(unsigned int _Val) {
        id5(_Val);
        return *this;
    }
    id3& id3::operator<<(unsigned long _Val) {
        id5(_Val);
        return *this;
    }
    id3& id3::operator<<(unsigned long long _Val) {
        id5(_Val);
        return *this;
    }
    template <typename Typex>
    void id3::endl(const Typex& _Val) {
        *this << _Val << '\n';
    }
    template <typename Typex, typename... More>
    void id3::endl(const Typex& _Val, const More&... _More) {
        *this << _Val;
        endl(_More...);
    }
    template <typename Typex>
    void id3::operator()(const Typex& _Val) {
        *this << _Val;
    }
    template <typename Typex, typename... More>
    void id3::operator()(const Typex& _Val, const More&... _More) {
        *this << _Val;
        operator()(_More...);
    }
}  


int main() {
    cin >> n;
    init();
    for (register int i = 1; i <= 3; i++) {
        for (register int j = 1; j <= n; j++) {
            cin >> c;
            a[i][j] = c == '1';
        }
    }
    for (register int i = 1; i <= n; i++) {
        if (a[1][i] && !a[2][i] && a[3][i]) {
            con1[i] = 2;
        } else if (a[1][i] || a[2][i] || a[3][i]) {
            con1[i] = 1;
        } else {
            con1[i] = 0;
        }
    }
    for (register int i = 1; i < n; i++) {
        if (!a[1][i]) {
            if (f(i, 0, 0, 0, 0, 0, 0)) con2[i] = 0;
            if (f(i, 0, 0, 0, 0, 0, 1)) con2[i] = 1;
            if (f(i, 0, 0, 0, 0, 1, 0)) con2[i] = 1;
            if (f(i, 0, 0, 0, 0, 1, 1)) con2[i] = 1;
            if (f(i, 0, 0, 0, 1, 0, 0)) con2[i] = 1;
            if (f(i, 0, 0, 0, 1, 0, 1)) con2[i] = 2;
            if (f(i, 0, 0, 0, 1, 1, 0)) con2[i] = 1;
            if (f(i, 0, 0, 0, 1, 1, 1)) con2[i] = 1;

            if (f(i, 0, 0, 1, 0, 0, 0)) con2[i] = 1;
            if (f(i, 0, 0, 1, 0, 0, 1)) con2[i] = 1;
            if (f(i, 0, 0, 1, 0, 1, 0)) con2[i] = 2;
            if (f(i, 0, 0, 1, 0, 1, 1)) con2[i] = 1;
            if (f(i, 0, 0, 1, 1, 0, 0)) con2[i] = 2;
            if (f(i, 0, 0, 1, 1, 0, 1)) con2[i] = 2;
            if (f(i, 0, 0, 1, 1, 1, 0)) con2[i] = 2;
            if (f(i, 0, 0, 1, 1, 1, 1)) con2[i] = 1;

            if (f(i, 0, 1, 0, 0, 0, 0)) con2[i] = 1;
            if (f(i, 0, 1, 0, 0, 0, 1)) con2[i] = 2;
            if (f(i, 0, 1, 0, 0, 1, 0)) con2[i] = 1;
            if (f(i, 0, 1, 0, 0, 1, 1)) con2[i] = 1;
            if (f(i, 0, 1, 0, 1, 0, 0)) con2[i] = 2;
            if (f(i, 0, 1, 0, 1, 0, 1)) con2[i] = 3;
            if (f(i, 0, 1, 0, 1, 1, 0)) con2[i] = 1;
            if (f(i, 0, 1, 0, 1, 1, 1)) con2[i] = 1;

            if (f(i, 0, 1, 1, 0, 0, 0)) con2[i] = 1;
            if (f(i, 0, 1, 1, 0, 0, 1)) con2[i] = 1;
            if (f(i, 0, 1, 1, 0, 1, 0)) con2[i] = 1;
            if (f(i, 0, 1, 1, 0, 1, 1)) con2[i] = 1;
            if (f(i, 0, 1, 1, 1, 0, 0)) con2[i] = 2;
            if (f(i, 0, 1, 1, 1, 0, 1)) con2[i] = 2;
            if (f(i, 0, 1, 1, 1, 1, 0)) con2[i] = 1;
            if (f(i, 0, 1, 1, 1, 1, 1)) con2[i] = 1;
        } else {
            if (f(i, 1, 0, 0, 0, 0, 0)) con2[i] = 1;
            if (f(i, 1, 0, 0, 0, 0, 1)) con2[i] = 2;
            if (f(i, 1, 0, 0, 0, 1, 0)) con2[i] = 2;
            if (f(i, 1, 0, 0, 0, 1, 1)) con2[i] = 2;
            if (f(i, 1, 0, 0, 1, 0, 0)) con2[i] = 1;
            if (f(i, 1, 0, 0, 1, 0, 1)) con2[i] = 2;
            if (f(i, 1, 0, 0, 1, 1, 0)) con2[i] = 1;
            if (f(i, 1, 0, 0, 1, 1, 1)) con2[i] = 1;

            if (f(i, 1, 0, 1, 0, 0, 0)) con2[i] = 2;
            if (f(i, 1, 0, 1, 0, 0, 1)) con2[i] = 2;
            if (f(i, 1, 0, 1, 0, 1, 0)) con2[i] = 3;
            if (f(i, 1, 0, 1, 0, 1, 1)) con2[i] = 2;
            if (f(i, 1, 0, 1, 1, 0, 0)) con2[i] = 2;
            if (f(i, 1, 0, 1, 1, 0, 1)) con2[i] = 2;
            if (f(i, 1, 0, 1, 1, 1, 0)) con2[i] = 2;
            if (f(i, 1, 0, 1, 1, 1, 1)) con2[i] = 1;

            if (f(i, 1, 1, 0, 0, 0, 0)) con2[i] = 1;
            if (f(i, 1, 1, 0, 0, 0, 1)) con2[i] = 2;
            if (f(i, 1, 1, 0, 0, 1, 0)) con2[i] = 1;
            if (f(i, 1, 1, 0, 0, 1, 1)) con2[i] = 1;
            if (f(i, 1, 1, 0, 1, 0, 0)) con2[i] = 1;
            if (f(i, 1, 1, 0, 1, 0, 1)) con2[i] = 2;
            if (f(i, 1, 1, 0, 1, 1, 0)) con2[i] = 1;
            if (f(i, 1, 1, 0, 1, 1, 1)) con2[i] = 1;

            if (f(i, 1, 1, 1, 0, 0, 0)) con2[i] = 1;
            if (f(i, 1, 1, 1, 0, 0, 1)) con2[i] = 1;
            if (f(i, 1, 1, 1, 0, 1, 0)) con2[i] = 1;
            if (f(i, 1, 1, 1, 0, 1, 1)) con2[i] = 1;
            if (f(i, 1, 1, 1, 1, 0, 0)) con2[i] = 1;
            if (f(i, 1, 1, 1, 1, 0, 1)) con2[i] = 1;
            if (f(i, 1, 1, 1, 1, 1, 0)) con2[i] = 1;
            if (f(i, 1, 1, 1, 1, 1, 1)) con2[i] = 1;
        }
    }
    lf[0] = 0;
    for (register int i = 1; i <= n; i++) {
        if (a[1][i] && a[2][i] && a[3][i]) {
            lf[i] = i;
        } else if (a[1][i] && !a[2][i] && a[3][i]) {
            lf[i] = lf[i - 1];
        } else {
            lf[i] = 0;
        }
    }
    rt[n + 1] = n + 1;
    for (register int i = n; i >= 1; i--) {
        if (a[1][i] && a[2][i] && a[3][i]) {
            rt[i] = i;
        } else if (a[1][i] && !a[2][i] && a[3][i]) {
            rt[i] = rt[i + 1];
        } else {
            rt[i] = n + 1;
        }
    }
    cin >> Q;
    for (register int i = 1; i <= Q; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + Q + 1);
    l = r = 1;
    cnt = con1[1];
    for (register int i = 1; i <= Q; i++) {
        while (q[i].l < l) minl();
        while (q[i].r > r) addr();
        while (q[i].l > l) addl();
        while (q[i].r < r) minr();
        q[i].ans = cnt;
    }
    sort(q + 1, q + Q + 1, cmp);
    for (register int i = 1; i <= Q; i++) {
        cout.endl(q[i].ans);
    }
}