


using namespace std;
using ll = long long int;


template<typename T>
struct Z_p{
    using Type = typename decay<decltype(T::value)>::type;
    static vector<Type> MOD_INV;
    constexpr Z_p(): value(){ }
    template<typename U> Z_p(const U &x){ value = normalize(x); }
    template<typename U> static Type normalize(const U &x){
        Type v;
        if(-mod() <= x && x < mod()) v = static_cast<Type>(x);
        else v = static_cast<Type>(x % mod());
        if(v < 0) v += mod();
        return v;
    }
    const Type& operator()() const{ return value; }
    template<typename U> explicit operator U() const{ return static_cast<U>(value); }
    constexpr static Type mod(){ return T::value; }
    Z_p &operator+=(const Z_p &otr){ if((value += otr.value) >= mod()) value -= mod(); return *this; }
    Z_p &operator-=(const Z_p &otr){ if((value -= otr.value) < 0) value += mod(); return *this; }
    template<typename U> Z_p &operator+=(const U &otr){ return *this += Z_p(otr); }
    template<typename U> Z_p &operator-=(const U &otr){ return *this -= Z_p(otr); }
    Z_p &operator++(){ return *this += 1; }
    Z_p &operator--(){ return *this -= 1; }
    Z_p operator++(int){ Z_p result(*this); *this += 1; return result; }
    Z_p operator--(int){ Z_p result(*this); *this -= 1; return result; }
    Z_p operator-() const{ return Z_p(-value); }
    template<typename U = T>
    typename enable_if<is_same<typename Z_p<U>::Type, int>::value, Z_p>::type &operator*=(const Z_p& rhs){
        
        uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
        uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
        asm(
            "divl %4; \n\t"
            : "=a" (d), "=d" (m)
            : "d" (xh), "a" (xl), "r" (mod())
        );
        value = m;
        
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
        
        return *this;
    }
    template<typename U = T>
    typename enable_if<is_same<typename Z_p<U>::Type, int64_t>::value, Z_p>::type &operator*=(const Z_p &rhs){
        uint64_t ret = static_cast<uint64_t>(value) * static_cast<uint64_t>(rhs.value) - static_cast<uint64_t>(mod()) * static_cast<uint64_t>(1.L / static_cast<uint64_t>(mod()) * static_cast<uint64_t>(value) * static_cast<uint64_t>(rhs.value));
        value = normalize(static_cast<int64_t>(ret + static_cast<uint64_t>(mod()) * (ret < 0) - static_cast<uint64_t>(mod()) * (ret >= static_cast<uint64_t>(mod()))));
        return *this;
    }
    template<typename U = T>
    typename enable_if<!is_integral<typename Z_p<U>::Type>::value, Z_p>::type &operator*=(const Z_p &rhs){
        value = normalize(value * rhs.value);
        return *this;
    }
    template<typename U>
    Z_p &operator^=(U e){
        if(e < 0) *this = 1 / *this, e = -e;
        Z_p res = 1;
        for(; e; *this *= *this, e >>= 1) if(e & 1) res *= *this;
        return *this = res;
    }
    template<typename U>
    Z_p operator^(U e) const{
        return Z_p(*this) ^= e;
    }
    Z_p &operator/=(const Z_p &otr){
        Type a = otr.value, m = mod(), u = 0, v = 1;
        if(a < (int)MOD_INV.size()) return *this *= MOD_INV[a];
        while(a){
            Type t = m / a;
            m -= t * a; swap(a, m);
            u -= t * v; swap(u, v);
        }
        assert(m == 1);
        return *this *= u;
    }
    template<typename U> friend const Z_p<U> &abs(const Z_p<U> &v){ return v; }
    Type value;
};
template<typename T> bool operator==(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value == rhs.value; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(const Z_p<T>& lhs, U rhs){ return lhs == Z_p<T>(rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) == rhs; }
template<typename T> bool operator!=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(const Z_p<T> &lhs, U rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(U lhs, const Z_p<T> &rhs){ return !(lhs == rhs); }
template<typename T> bool operator<(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value < rhs.value; }
template<typename T> bool operator>(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value > rhs.value; }
template<typename T> bool operator<=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value <= rhs.value; }
template<typename T> bool operator>=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value >= rhs.value; }
template<typename T> Z_p<T> operator+(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator+(const Z_p<T> &lhs, U rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator+(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T> Z_p<T> operator-(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator-(const Z_p<T>& lhs, U rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator-(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T> Z_p<T> operator*(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator*(const Z_p<T>& lhs, U rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator*(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T> Z_p<T> operator/(const Z_p<T> &lhs, const Z_p<T> &rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator/(const Z_p<T>& lhs, U rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator/(U lhs, const Z_p<T> &rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T> istream &operator>>(istream &in, Z_p<T> &number){
    typename common_type<typename Z_p<T>::Type, int64_t>::type x;
    in >> x;
    number.value = Z_p<T>::normalize(x);
    return in;
}
template<typename T> ostream &operator<<(ostream &out, const Z_p<T> &number){ return out << number(); }





constexpr int mod = (119 << 23) + 1; 



using Zp = Z_p<integral_constant<decay<decltype(mod)>::type, mod>>;

template<typename T> vector<typename Z_p<T>::Type> Z_p<T>::MOD_INV;
template<typename T = integral_constant<decay<decltype(mod)>::type, mod>>
void id1(int SZ){
    auto &inv = Z_p<T>::MOD_INV;
    if(inv.empty()) inv.assign(2, 1);
    for(; inv.size() <= SZ; ) inv.push_back((mod - 1LL * mod / (int)inv.size() * inv[mod % (int)inv.size()]) % mod);
}

template<typename T>
vector<T> id2(T base, int SZ){
    vector<T> res(SZ + 1, 1);
    for(auto i = 1; i <= SZ; ++ i) res[i] = res[i - 1] * base;
    return res;
}

template<typename T>
vector<T> id0(int SZ){
    vector<T> res(SZ + 1, 1); res[0] = 1;
    for(auto i = 1; i <= SZ; ++ i) res[i] = res[i - 1] * i;
    return res;
}


using namespace __gnu_pbds;

struct chash {
    const int RANDOM = (int64_t)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static uint64_t hash_f(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
    int operator()(int x) const { return hash_f(x)^RANDOM; }
};
using hashmap = gp_hash_table<int, int, chash>;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int k; cin >> k;
    Zp A, h; cin >> A >> h;
    Zp pwA[100];
    pwA[0] = 1;
    for (int i = 1; i < 100; ++i)
        pwA[i] = A*pwA[i-1];

    vector<int> ans((1<<k) + 1);
    if (k <= 4) {
        

        int games = (1<<k) - 1;
        for (int mask = 0; mask < 1<<games; ++mask) {
            deque<int> q;
            for (int i = 1; i <= 1<<k; ++i)
                q.push_back(i);
            q.push_back(-1);
            int place = (1<<(k-1)) + 1;
            Zp cur = 0;
            for (int game = 0; game < games; ++game) {
                if (q.front() == -1) {
                    q.pop_front();
                    q.push_back(-1);
                    place = (place + 1)/2;
                }
                int x = q.front(); q.pop_front();
                int y = q.front(); q.pop_front();
                if (mask&(1<<game)) {
                    q.push_back(x);
                    cur += Zp(y) * (pwA[place]);
                    ans[y] = place;
                }
                else {
                    q.push_back(y);
                    cur += Zp(x) * (pwA[place]);
                    ans[x] = place;
                }
            }
            cur += Zp(q.back())*A;
            ans[q.back()] = 1;
            if (cur == h) {
                for (int i = 1; i <= 1<<k; ++i)
                    cout << ans[i] << ' ';
                return cout << '\n', 0;
            }
        }
        return cout << -1, 0;
    }

    

    hashmap mask_id;
    int next_id = 0;
    vector<hashmap> what_mask;
    
    

    int Q[300];
    for (int a1 = 1; a1 <= 4; ++a1) for (int a2 = 5; a2 <= 8; ++a2) for (int a3 = 9; a3 <= 12; ++a3) for (int a4 = 13; a4 <= 16; ++a4) 
    for (int a5 = 17; a5 <= 20; ++a5) for (int a6 = 21; a6 <= 24; ++a6) for (int a7 = 25; a7 <= 28; ++a7) for (int a8 = 29; a8 <= 32; ++a8) {
        
        int id = (1<<(a1-1)) ^ (1<<(a2-1)) ^ (1<<(a3-1)) ^ (1<<(a4-1)) ^ (1<<(a5-1)) ^ (1<<(a6-1)) ^ (1<<(a7-1)) ^ (1<<(a8-1));
        if (mask_id.find(id) == mask_id.end()) {
            mask_id[id] = next_id++;
            what_mask.emplace_back();
        }
        id = mask_id[id];
        
        int games = 7;
        for (int mask = 0; mask < 1<<7; ++mask) {
            

            Q[0] = a1, Q[1] = a2, Q[2] = a3, Q[3] = a4, Q[4] = a5, Q[5] = a6, Q[6] = a7, Q[7] = a8, Q[8] = -1;
            int place = 5, fptr = 0, bptr = 9;
            Zp cur = 0;
            for (int game = 0; game < games; ++game) {
                if (Q[fptr] == -1) {
                    ++fptr;
                    Q[bptr++] = -1;
                    place = (place + 1)/2;
                }
                int x = Q[fptr++];
                int y = Q[fptr++];
                if (mask&(1<<game)) {
                    Q[bptr++] = x;
                    cur += Zp(y) * (pwA[place]);
                }
                else {
                    Q[bptr++] = y;
                    cur += Zp(x) * (pwA[place]);
                }
            }
            cur += Zp(Q[bptr-1])*A;
            what_mask[id][int(cur)] = mask;
        }
    }

    


    int rem[16], rem2[8];
    const Zp A17 = A^17;
    const Zp A9 = A^9;
    hashmap done;
    for (int mask = 0; mask < 1<<24; ++mask) {
        Zp cur = 0;
        for (int game = 0; game < 16; ++game) {
            if (mask&(1<<game)) {
                rem[game] = 2*game + 1;
                cur += Zp(2*game + 2) * (A17);
                ans[2*game + 2] = 17;
            }
            else {
                rem[game] = 2*game + 2;
                cur += Zp(2*game + 1) * (A17);
                ans[2*game + 1] = 17;
            }
        }
        for (int game = 0; game < 8; ++game) {
            if (mask&(1<<(game + 16))) {
                rem2[game] = rem[2*game];
                cur += Zp(rem[2*game + 1]) * (A9);
                ans[rem[2*game + 1]] = 9;
            }
            else {
                rem2[game] = rem[2*game + 1];
                cur += Zp(rem[2*game]) * (A9);
                ans[rem[2*game]] = 9;
            }
        }

        int id = 0;
        for (int i = 0; i < 8; ++i)
            id ^= 1<<(rem2[i] - 1);
        id = mask_id[id];

        

        

        if (what_mask[id].find(int(h - cur)) == what_mask[id].end()) continue;
        int ans_mask = what_mask[id][int(h - cur)];

        deque<int> q;
        for (int i = 0; i < 8; ++i)
            q.push_back(rem2[i]);
        q.push_back(-1);
        int place = 5, games = 7;
        for (int game = 0; game < games; ++game) {
            if (q.front() == -1) {
                q.pop_front();
                q.push_back(-1);
                place = (place + 1)/2;
            }
            int x = q.front(); q.pop_front();
            int y = q.front(); q.pop_front();
            if (ans_mask&(1<<game)) {
                q.push_back(x);
                ans[y] = place;
            }
            else {
                q.push_back(y);
                ans[x] = place;
            }
        }
        ans[q.back()] = 1;

        for (int i = 1; i <= 1<<k; ++i)
            cout << ans[i] << ' ';
        return cout << '\n', 0;
    }
    cout << -1;
}