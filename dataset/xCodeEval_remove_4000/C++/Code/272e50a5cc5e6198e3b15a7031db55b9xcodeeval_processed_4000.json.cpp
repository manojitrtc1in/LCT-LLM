

































namespace math
{
    class Unsigned
    {
    public:
        typedef std::uint32_t Digit;
        typedef std::uint64_t Wigit;
        static const unsigned BITS = 32;
 
        Unsigned(Digit u = 0) :
            digits(1, u)
        {
            

        }
 
        Unsigned(const std::string& s) :
            digits(1, 0)
        {
            std::istringstream iss(s);
            iss >> *this;
            if (iss.fail() || !iss.eof())
            {
                throw std::runtime_error("Error: Unsigned::string");
            }
        }
 
        Unsigned(const Unsigned& copy) :
            digits(copy.digits)
        {
            

        }
 
        Unsigned& operator= (const Unsigned& rhs)
        {
            digits = rhs.digits;
            return *this;
        }
 
        Unsigned operator++ (int)
        {
            Unsigned w(*this);
            ++(*this);
            return w;
        }
 
        Unsigned& operator++ ()
        {
            for (size_t j = 0; j < digits.size() && ++digits[j] == 0; ++j);
            if (digits.back() == 0)
            {
                digits.push_back(1);
            }
            return *this;
        }
 
        Unsigned operator-- (int)
        {
            Unsigned w(*this);
            --(*this);
            return w;
        }
 
        Unsigned& operator-- ()
        {
            if (digits.back() == 0)
            {
                throw std::underflow_error("Error: Unsigned::underflow");
            }
            for (size_t j = 0; j < digits.size() && digits[j]-- == 0; ++j);
            trim();
            return *this;
        }
 
        friend Unsigned operator+ (const Unsigned& u, const Unsigned& v)
        {
            Unsigned w(u);
            w += v;
            return w;
        }
 
        Unsigned& operator+= (const Unsigned& rhs)
        {
            const size_t n = rhs.digits.size();
            if (digits.size() < n)
            {
                digits.resize(n, 0);
            }
            size_t j = 0;
            Wigit k = 0;
            for (; j < n; ++j)
            {
                k = k + digits[j] + rhs.digits[j];
                digits[j] = static_cast<Digit>(k);
                k >>= BITS;
            }
            for (; k != 0 && j < digits.size(); ++j)
            {
                k += digits[j];
                digits[j] = static_cast<Digit>(k);
                k >>= BITS;
            }
            if (k != 0)
            {
                digits.push_back(1);
            }
            return *this;
        }
 
        friend Unsigned operator- (const Unsigned& u, const Unsigned& v)
        {
            Unsigned w(u);
            w -= v;
            return w;
        }
 
        Unsigned& operator-= (const Unsigned& rhs)
        {
            if ((*this) < rhs)
            {
                throw std::underflow_error("Error: Unsigned::underflow");
            }
            size_t j = 0;
            Wigit k = 0;
            for (; j < rhs.digits.size(); ++j)
            {
                k = k + digits[j] - rhs.digits[j];
                digits[j] = static_cast<Digit>(k);
                k = ((k >> BITS) ? -1 : 0);
            }
            for (; k != 0 && j < digits.size(); ++j)
            {
                k += digits[j];
                digits[j] = static_cast<Digit>(k);
                k = ((k >> BITS) ? -1 : 0);
            }
            trim();
            return *this;
        }
 
        friend Unsigned operator* (const Unsigned& u, const Unsigned& v)
        {
            const size_t m = u.digits.size();
            const size_t n = v.digits.size();
            Unsigned w;
            w.digits.resize(m + n, 0);
            for (size_t j = 0; j < n; ++j)
            {
                Wigit k = 0;
                for (size_t i = 0; i < m; ++i)
                {
                    k += static_cast<Wigit>(u.digits[i]) * v.digits[j] +
                        w.digits[i + j];
                    w.digits[i + j] = static_cast<Digit>(k);
                    k >>= BITS;
                }
                w.digits[j + m] = static_cast<Digit>(k);
            }
            w.trim();
            return w;
        }
         
        Unsigned& operator*= (const Unsigned& rhs)
        {
            *this = (*this) * rhs;
            return *this;
        }
 
        friend Unsigned operator/ (const Unsigned& u, const Unsigned& v)
        {
            Unsigned q, r;
            u.divide(v, q, r);
            return q;
        }
 
        Unsigned& operator/= (const Unsigned& rhs)
        {
            Unsigned r;
            divide(rhs, *this, r);
            return *this;
        }
 
        friend Unsigned operator% (const Unsigned& u, const Unsigned& v)
        {
            Unsigned q, r;
            u.divide(v, q, r);
            return r;
        }
 
        Unsigned& operator%= (const Unsigned& rhs)
        {
            Unsigned q;
            divide(rhs, q, *this);
            return *this;
        }
 
        void divide(Unsigned v, Unsigned& q, Unsigned& r) const
        {
            

            if (v.digits.back() == 0)
            {
                throw std::overflow_error("Error: Unsigned::overflow");
            }
            r.digits = digits;
            const size_t n = v.digits.size();
            if (digits.size() < n) { q.digits.assign(1, 0); return; } 

            unsigned d = BITS;
            for (Digit vn = v.digits.back(); vn != 0; vn >>= 1, --d);
            v <<= d;
            r <<= d;
            const Digit vn = v.digits.back();
 
            

            r.digits.push_back(0);
            const size_t m = r.digits.size();
            q.digits.resize(m - n);
            Unsigned w;
            w.digits.resize(n + 1);
            const Wigit id0 = (static_cast<Wigit>(1) << BITS) - 1;
            for (size_t j = m - n; j-- != 0;)
            {
                

                Wigit qhat = std::min(id0,
                    (static_cast<Wigit>(r.digits[j + n]) << BITS |
                        r.digits[j + n - 1]) / vn);
 
                

                Wigit k = 0;
                for (size_t i = 0; i < n; ++i)
                {
                    k += qhat * v.digits[i];
                    w.digits[i] = static_cast<Digit>(k);
                    k >>= BITS;
                }
                w.digits[n] = static_cast<Digit>(k);
 
                

                bool is_trial = true;
                while (is_trial)
                {
                    size_t i = n;
                    for (; i != 0 && r.digits[j + i] == w.digits[i]; --i);
                    if ((is_trial = (r.digits[j + i] < w.digits[i])))
                    {
                        

                        --qhat;
                        k = 0;
                        for (size_t i = 0; i < n; ++i)
                        {
                            k = k + w.digits[i] - v.digits[i];
                            w.digits[i] = static_cast<Digit>(k);
                            k = ((k >> BITS) ? -1 : 0);
                        }
                        w.digits[n] = static_cast<Digit>(k + w.digits[n]);
                    }
                }
                q.digits[j] = static_cast<Digit>(qhat);
 
                

                k = 0;
                for (size_t i = 0; i < n; ++i)
                {
                    k = k + r.digits[j + i] - w.digits[i];
                    r.digits[j + i] = static_cast<Digit>(k);
                    k = ((k >> BITS) ? -1 : 0);
                }
            }
 
            

            q.trim();
            r.digits.resize(n);
            r >>= d;
        }
 
        friend Unsigned operator<< (const Unsigned& u, size_t v)
        {
            Unsigned w(u);
            w <<= v;
            return w;
        }
 
        Unsigned& operator<<= (size_t rhs)
        {
            if (digits.back() != 0 && rhs != 0)
            {
                const size_t n = rhs / BITS;
                digits.insert(digits.begin(), n, 0);
                rhs -= n * BITS;
                Wigit k = 0;
                for (size_t j = n; j < digits.size(); ++j)
                {
                    k |= static_cast<Wigit>(digits[j]) << rhs;
                    digits[j] = static_cast<Digit>(k);
                    k >>= BITS;
                }
                if (k != 0)
                {
                    digits.push_back(static_cast<Digit>(k));
                }
            }
            return *this;
        }
 
        friend Unsigned operator>> (const Unsigned& u, size_t v)
        {
            Unsigned w(u);
            w >>= v;
            return w;
        }
 
        Unsigned& operator>>= (size_t rhs)
        {
            const size_t n = rhs / BITS;
            if (n >= digits.size())
            {
                digits.assign(1, 0);
            }
            else
            {
                digits.erase(digits.begin(), digits.begin() + n);
                rhs -= n * BITS;
                Wigit k = 0;
                for (size_t j = digits.size(); j-- != 0;)
                {
                    k = k << BITS | digits[j];
                    digits[j] = static_cast<Digit>(k >> rhs);
                    k = static_cast<Digit>(k);
                }
                trim();
            }
            return *this;
        }
 
        friend Unsigned operator& (const Unsigned& u, const Unsigned& v)
        {
            Unsigned w(u);
            w &= v;
            return w;
        }
 
        Unsigned& operator&= (const Unsigned& rhs)
        {
            const size_t n = rhs.digits.size();
            if (digits.size() > n)
            {
                digits.resize(n);
            }
            for (size_t j = 0; j < digits.size(); ++j)
            {
                digits[j] &= rhs.digits[j];
            }
            trim();
            return *this;
        }
 
        friend Unsigned operator^ (const Unsigned& u, const Unsigned& v)
        {
            Unsigned w(u);
            w ^= v;
            return w;
        }
 
        Unsigned& operator^= (const Unsigned& rhs)
        {
            const size_t n = rhs.digits.size();
            if (digits.size() < n)
            {
                digits.resize(n, 0);
            }
            for (size_t j = 0; j < n; ++j)
            {
                digits[j] ^= rhs.digits[j];
            }
            trim();
            return *this;
        }
 
        friend Unsigned operator| (const Unsigned& u, const Unsigned& v)
        {
            Unsigned w(u);
            w |= v;
            return w;
        }
 
        Unsigned& operator|= (const Unsigned& rhs)
        {
            const size_t n = rhs.digits.size();
            if (digits.size() < n)
            {
                digits.resize(n, 0);
            }
            for (size_t j = 0; j < n; ++j)
            {
                digits[j] |= rhs.digits[j];
            }
            return *this;
        }
 
        friend bool operator< (const Unsigned& u, const Unsigned& v)
        {
            const size_t m = u.digits.size();
            size_t n = v.digits.size();
            if (m != n)
            {
                return (m < n);
            }
            for (--n; n != 0 && u.digits[n] == v.digits[n]; --n);
            return (u.digits[n] < v.digits[n]); } friend bool operator> (const Unsigned& u, const Unsigned& v)
        {
            return (v < u);
        }
 
        friend bool operator<= (const Unsigned& u, const Unsigned& v)
        {
            return !(v < u); } friend bool operator>= (const Unsigned& u, const Unsigned& v)
        {
            return !(u < v);
        }
 
        friend bool operator== (const Unsigned& u, const Unsigned& v)
        {
            return (u.digits == v.digits);
        }
 
        friend bool operator!= (const Unsigned& u, const Unsigned& v)
        {
            return (u.digits != v.digits);
        }
 
        Digit to_uint() const
        {          return digits[0];
        }
 
        std::string to_string() const
        {
            std::ostringstream oss;
            Unsigned q(*this), r;
            do
            {
                q.divide(10, q, r);
                oss << r.digits[0];
            } while (q.digits.back() != 0);
            std::string s(oss.str());
            std::reverse(s.begin(), s.end());
            return s;
        }
 
        friend std::ostream& operator<< (std::ostream& os, const Unsigned& u)
        {
            os << u.to_string(); return os; } friend std::istream& operator>> (std::istream& is, Unsigned& u)
        {
            char digit = '\0';
            is >> digit;
            if (is.good() && std::isdigit(digit))
            {
                u = digit - '0';
                while (std::isdigit(is.peek()))
                {
                    is >> digit;
                    u = 10 * u + (digit - '0');
                }
            }
            else
            {
                is.setstate(std::ios_base::failbit);
            }
            return is;
        }
 
    private:
        std::vector<Digit> digits;
 
        void trim()
        {
            while (digits.back() == 0 && digits.size() > 1)
            {
                digits.pop_back();
            }
        }
    };
} 


const int N = 1000 + 5;
int n, m;
const int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int dis[N][N][4];
char map[N][N];
bool vis[N][N][4];
std::deque<int> dq;

void addFront(int x, int y, int dire, int d) {
    if (d < dis[x][y][dire]) {
        dis[x][y][dire] = d;
        dq.push_front(dire); dq.push_front(y); dq.push_front(x);
    }
}

void addBack(int x, int y, int dire, int d) {
    if (d < dis[x][y][dire]) {
        dis[x][y][dire] = d;
        dq.push_back(x); dq.push_back(y); dq.push_back(dire);
    }
}

void solution() {
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < 4; ++k) dis[i][j][k] = 0x7fffffff;
    for (int i = 0; i < n; ++i) scanf("%s", map[i]);
    addFront(n - 1, m - 1, 3, 0);
    while (!dq.empty()) {
        int x = dq[0], y = dq[1], dire = dq[2]; for (int i = 0; i < 3; ++i) dq.pop_front(); 

        if (vis[x][y][dire]) continue; vis[x][y][dire] = true;
        int d = dis[x][y][dire], dx = x + dir[dire][0], dy = y + dir[dire][1];
        if (dx >= 0 && dx < n && dy >= 0 && dy < m) addFront(dx, dy, dire, d);
        if (map[x][y] == '
    }
    std::cout << (dis[0][0][3] == 0x7fffffff ? -1 : dis[0][0][3]) << std::endl;
}

signed main() {

    fileIn;
    



    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);


    logs("main.exe");
    solution();
}