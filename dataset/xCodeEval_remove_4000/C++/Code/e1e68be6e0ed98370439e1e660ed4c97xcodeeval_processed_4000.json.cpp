

















using namespace std;














using namespace std;








using LL = long long;






















template <typename T>
inline T& unused_var(T& v) {
    return v;
}






struct cww {
    
    cww() {

        ios::sync_with_stdio(false);
        cin.tie(0);


        cout << fixed;
        cout << setprecision(DECIMAL_DIGITS);

    }
};



cww star;


template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v) {
    for (auto& it : v) is >> it;
    return is;
}






class reverse_range {
  private:
    struct I {
        int x;
        int operator*() { return x - 1; }
        bool operator!=(I& lhs) { return x > lhs.x; }
        void operator++() { --x; }
    };
    I i, n;

  public:
    
    reverse_range(int n) : i({0}), n({n}) {}
    
    reverse_range(int i, int n) : i({i}), n({n}) {}
    
    I& begin() { return n; }
    
    I& end() { return i; }
};

class range {
  private:
    struct I {
        int x;
        int operator*() { return x; }
        bool operator!=(I& lhs) { return x < lhs.x; }
        void operator++() { ++x; }
    };
    I i, n;

  public:
    
    range(int n) : i({0}), n({n}) {}
    
    range(int i, int n) : i({i}), n({n}) {}
    
    I& begin() { return i; }
    
    I& end() { return n; }
    
    reverse_range operator!() { return reverse_range(*i, *n); }
};





template <typename T>
struct min_op {
    
    static T exec(const T l, const T r) { return l < r ? l : r; }
};


template <typename T>
struct max_op {
    
    static T exec(const T l, const T r) { return l > r ? l : r; }
};


template <typename F, typename T>
inline T multi_op(T&& v) {
    return v;
}


template <typename F, typename T, typename... Ts>
inline T multi_op(const T head, Ts&&... tail) {
    return F::exec(head, multi_op<F>(tail...));
}


template <typename T, typename... Ts>
inline T multi_min(T&& head, Ts&&... tail) {
    return multi_op<min_op<T>>(head, tail...);
}


template <typename T, typename... Ts>
inline T multi_max(T&& head, Ts&&... tail) {
    return multi_op<max_op<T>>(head, tail...);
}


template <typename F, typename T, typename... Ts>
inline bool ch_op(T& target, Ts&&... candidates) {
    const T old = target;
    target      = multi_op<F>(target, candidates...);
    return old != target;
}


template <typename T, typename... Ts>
inline bool chmin(T& target, Ts&&... candidates) {
    return ch_op<min_op<T>>(target, candidates...);
}


template <typename T, typename... Ts>
inline bool chmax(T& target, Ts&&... candidates) {
    return ch_op<max_op<T>>(target, candidates...);
}







const pid_t pid = getpid();


class id0 {
  private:
    

    unsigned value;

    
    inline void update() {
        value = value ^ (value << 13);
        value = value ^ (value >> 17);
        value = value ^ (value << 5);
    }

    
    inline unsigned get() {
        unsigned v = value;
        update();
        return v;
    }

  public:
    
    template <int bit = 31>
    inline int next_int() {
        return (int)(get() >> (32 - bit));
    }

    
    template <int bit = 31>
    inline int next_signed() {
        unsigned v = get();
        return (int)((v >> (31 - bit)) - (1 << (bit)));
    }

    
    template <int bit = 31>
    inline int range_max() {
        return (int)((1u << bit) - 1);
    };

    
    id0(const unsigned seed) {
        value = seed;
        update();
    }

    
    id0() : id0(pid) {}
};















constexpr int mod = STATIC_MOD;

int mod;



class ModInt {
  private:
    

    int x;

  public:
    
    long long operator*() const { return x; }
    
    ModInt() { x = 0; }

    
    ModInt(const int y) { x = y; }

    
    ModInt(const long long y) { x = (int)((mod + y % mod) % mod); }

    
    ModInt(const ModInt& o) { this->x = *o; }
    
    static inline ModInt raw(const long long x) {
        

        return ModInt((int)x);
    }

    
    static inline ModInt get(const long long x) { return ModInt(x); }

    
    ModInt& operator=(const int o) {
        this->x = o >= mod ? o - mod : o;
        return *this;
    }

    
    ModInt& operator=(const long long o) {
        this->x = (int)((mod + o % mod) % mod);
        return *this;
    }

    
    ModInt& operator=(const ModInt o) {
        this->x = *o;
        return *this;
    }
};


inline ModInt add(const ModInt l, const ModInt r) {
    const long long x = *l + *r;
    return ModInt::raw(x >= mod ? x - mod : x);
}


inline ModInt mul(const ModInt l, const ModInt r) {
    return ModInt::raw(*l * *r % mod);
}


inline ModInt pow(ModInt a, long long x) {
    ModInt ret = ModInt::raw(1);
    while (x) {
        if (x & 1) {
            ret = mul(ret, a);
        }
        a = mul(a, a);
        x >>= 1;
    }
    return ret;
}


inline ModInt inv(const ModInt x) {
    long long a = *x, b = mod, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        std::swap(a -= t * b, b);
        std::swap(u -= t * v, v);
    }
    return ModInt::get(u);
}


inline ModInt operator-(const ModInt x) { return add(mod, -*x); }


inline ModInt operator+(const ModInt l, const ModInt r) { return add(l, r); }


inline ModInt operator*(const ModInt l, const ModInt r) { return mul(l, r); }


inline ModInt operator-(const ModInt l, const ModInt r) { return add(l, -r); }


inline ModInt operator+(const ModInt l, const int r) {
    return add(l, ModInt::raw(r));
}


inline ModInt operator+(const ModInt l, const long long r) {
    return add(l, ModInt::get(r));
}


inline ModInt operator*(const ModInt l, const int r) {
    return mul(l, ModInt::raw(r));
}


inline ModInt operator*(const ModInt l, const long long r) {
    return mul(l, ModInt::get(r));
}


inline ModInt operator-(const ModInt l, const int r) {
    return add(l, ModInt::raw(mod - r));
}


inline ModInt operator-(const ModInt l, const long long r) {
    return add(l, -ModInt::get(r));
}


inline ModInt operator/(const ModInt l, const int r) {
    return mul(l, inv(ModInt::raw(r)));
}


inline ModInt operator/(const ModInt l, const long long r) {
    return mul(l, inv(ModInt::get(r)));
}


inline ModInt operator^(const ModInt l, const long long r) { return pow(l, r); }


template <typename T>
ModInt& operator+=(ModInt& l, T r) {
    l = l + r;
    return l;
}


template <typename T>
ModInt& operator-=(ModInt& l, T r) {
    l = l - r;
    return l;
}


template <typename T>
ModInt& operator*=(ModInt& l, T r) {
    l = l * r;
    return l;
}


namespace factorial {
    

    constexpr int size =

        id1;

        3123456;

    

    bool is_build = false;

    

    ModInt factorial[size];
    

    ModInt inverse_factorial[size];

    
    void build() {
        is_build     = true;
        factorial[0] = 1;
        for (int i = 1; i < size; i++) {
            factorial[i] = factorial[i - 1] * i;
        }
        inverse_factorial[size - 1] = inv(factorial[size - 1]);
        for (int i = size - 1; i >= 1; i--) {
            inverse_factorial[i - 1] = inverse_factorial[i] * i;
        }
    }

    
    inline ModInt permutation(int n, int k) {
        if (k < 0 || k > n) return ModInt::raw(0);
        if (!is_build) build();
        return factorial[n] * inverse_factorial[n - k];
    }

    
    inline ModInt combination(int n, int k) {
        if (k < 0 || k > n) return ModInt::raw(0);
        if (!is_build) build();
        return factorial[n] * inverse_factorial[k] * inverse_factorial[n - k];
    }
} 

  
  
  


namespace factorial {
    
    ModInt multiChoose(int n, int r) {
        if (n == 0) {
            return ModInt(r == 0 ? 1 : 0);
        }
        if (r == 0) {
            return ModInt(1);
        }
        return combination(n + r - 1, r);
    }

    
    ModInt multiChoose(int n, int r, int lim) {
        if (n == 0) {
            return ModInt(r == 0 ? 1 : 0);
        }
        if (lim <= 0 && r > 0) {
            return ModInt(0);
        }
        if (r == 0) {
            return ModInt(lim < 0 ? 0 : 1);
        }
        ModInt ret = 0;
        for (int i : range(n + 1)) {
            if (i * (lim + 1) > r) break;
            ret += ((i & 1) ? mod - 1 : 1) * combination(n, i)
                   * multiChoose(n, r - i * (lim + 1));
        }
        return ret;
    }
} 



int main() {
    
    int p, s, r;
    scanf("%d%d%d", &p, &s, &r);
    ModInt ret = 0;
    for (int top : range(r, s + 1)) {
        ModInt tot = 0;
        for (int q : range(p)) {
            if (top * q > s - top) break;
            tot +=
                factorial::combination(p - 1, q)
                * factorial::multiChoose(p - q - 1, s - top - top * q, top - 1)
                * inv(q + 1);
        }
        ret += tot;
    }
    ret *= inv(factorial::multiChoose(p, s - r));
    printf("%lld\n", *ret);
    return 0;
}