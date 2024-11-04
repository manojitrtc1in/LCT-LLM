











using namespace std;





constexpr int pct (int x) {
    return __builtin_popcount (x);    

}
constexpr int bits (int x) { 

    return x == 0 ? 0 : 31 - __builtin_clz (x);
} 

constexpr int p2 (int x) {
    return 1 << x;
}
constexpr int id0 (int x) {
    return p2 (x) - 1;
}

ll cdiv (ll a, ll b) {
    return a / b + ( (a ^ b) > 0 && a % b);    

}
ll fdiv (ll a, ll b) {
    return a / b - ( (a ^ b) < 0 && a % b);    

}



template <const int32_t MOD>
struct modint {
    int32_t value;
    modint() = default;
    modint (int32_t value_) : value (value_) {}
    inline modint<MOD> operator+ (modint<MOD> other) const {
        int32_t c = this->value + other.value;
        return modint<MOD> (c >= MOD ? c - MOD : c);
    }
    inline modint<MOD> operator- (modint<MOD> other) const {
        int32_t c = this->value - other.value;
        return modint<MOD> (c < 0 ? c + MOD : c);
    }
    inline modint<MOD> operator* (modint<MOD> other) const {
        int32_t c = (int64_t) this->value * other.value % MOD;
        return modint<MOD> (c < 0 ? c + MOD : c);
    }
    inline modint<MOD> &operator+= (modint<MOD> other) {
        this->value += other.value;
        if (this->value >= MOD)
            this->value -= MOD;
        return *this;
    }
    inline modint<MOD> &operator-= (modint<MOD> other) {
        this->value -= other.value;
        if (this->value < 0)
            this->value += MOD;
        return *this;
    }
    inline modint<MOD> &operator*= (modint<MOD> other) {
        this->value = (int64_t) this->value * other.value % MOD;
        if (this->value < 0)
            this->value += MOD;
        return *this;
    }
    inline modint<MOD> operator-() const {
        return modint<MOD> (this->value ? MOD - this->value : 0);
    }
    modint<MOD> pow (uint64_t k) const {
        modint<MOD> x = *this, y = 1;
        for (; k; k >>= 1) {
            if (k & 1)
                y *= x;
            x *= x;
        }
        return y;
    }
    modint<MOD> inv() const {
        return pow (MOD - 2);    

    }
    inline modint<MOD> operator/ (modint<MOD> other) const {
        return *this * other.inv();
    }
    inline modint<MOD> operator/= (modint<MOD> other) {
        return *this *= other.inv();
    }
    inline bool operator== (modint<MOD> other) const {
        return value == other.value;
    }
    inline bool operator!= (modint<MOD> other) const {
        return value != other.value;
    }
    inline bool operator< (modint<MOD> other) const {
        return value < other.value;
    }
    inline bool operator> (modint<MOD> other) const {
        return value > other.value;
    }
};
template <int32_t MOD>
modint<MOD> operator* (int64_t value, modint<MOD> n) {
    return modint<MOD> (value) * n;
}
template <int32_t MOD>
modint<MOD> operator* (int32_t value, modint<MOD> n) {
    return modint<MOD> (value % MOD) * n;
}
template <int32_t MOD>
istream &operator>> (istream &in, modint<MOD> &n) {
    return in >> n.value;
}
template <int32_t MOD>
ostream &operator<< (ostream &out, modint<MOD> n) {
    return out << n.value;
}

const int maxn = 5e5 + 100;
int T;
int n, k;
int a[maxn];
int main() {
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d%d", &n, &k);
        for (int i = 0; i < k; i++) {
            scanf ("%d", &a[i]);
            a[i] = n - a[i];
        }
        sort (a, a + k);
        int ans = 0;
        int res = n - 1;
        while (ans < k && res >= a[ans]) {
            res -= a[ans++];
        }
        cout << ans << endl;
    }
}