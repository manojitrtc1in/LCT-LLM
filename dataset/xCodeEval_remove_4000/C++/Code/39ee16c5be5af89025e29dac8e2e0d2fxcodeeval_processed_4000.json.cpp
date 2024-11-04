







































































using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef double ld;
const ll MOD = 1e9 + 7;
T1 ostream& operator<<(ostream& stream, const vector<T>& t);
namespace FFT_precision{
    template<typename T>vector<T> multiply(const vector<T> & a, const vector<T> & b, bool split = false, bool normalize = false);
}
struct Big{
    static const int base = 1000000000;
    static const int base_digits = 9;
    int sign;
    vector<int> a;
    int size(){
        if(a.empty())
            return 0;
        int ans = (sz(a) - 1) * base_digits;
        int ca = a.back();
        while(ca)
            ans++, ca /= 10;
        return ans;
    }
    Big operator^(const Big& v){
        Big ans = 1, a = *this, b = v;
        while(!b.isZero()){
            if(b % 2)
                ans *= a;
            a *= a, b /= 2;
        }
        return ans;
    }
    string to_string(){
        stringstream ss;
        ss << *this;
        string s;
        ss >> s;
        return s;
    }
    int sumof(){
        string s = to_string();
        int ans = 0;
        for(auto c : s)
            ans += c - '0';
        return ans;
    }
    Big()
        : sign(1){
        }
    Big(long long v){
        *this = v;
    }
    Big(const string& s){
        read(s);
    }
    void operator=(long long v){
        sign = 1;
        a.clear();
        if(v < 0)
            sign = -1, v = -v;
        for(; v > 0; v = v / base)
            a.push_back(v % base);
    }
    Big operator+(const Big& v)const{
        if(sign == v.sign){
            Big res = v;
            for(int i = 0, carry = 0; i < max(sz(a), sz(v.a)) || carry; ++i){
                if(i == sz(res.a))
                    res.a.push_back(0);
                res.a[i] += carry + (i < sz(a) ? a[i] : 0);
                carry = res.a[i] >= base;
                if(carry)
                    res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }
    template<typename T> friend
    Big operator+(const T &v, const Big &b){
        return b+Big(v);
    }
    Big operator-(const Big& v)const{
        if(sign == v.sign){
            if(abs() >= v.abs()){
                Big res = *this;
                for(int i = 0, carry = 0; i < sz(v.a) || carry; ++i){
                    res.a[i] -= carry + (i < sz(v.a) ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if(carry)
                        res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }
    void operator*=(int v){
        if(v < 0)
            sign = -sign, v = -v;
        for(int i = 0, carry = 0; i < sz(a) || carry; ++i){
            if(i == sz(a))
                a.push_back(0);
            long long cur = a[i] * (long long)v + carry;
            carry = (int)(cur / base);
            a[i] = (int)(cur % base);
            

        }
        trim();
    }
    Big operator*(int v)const{
        Big res = *this;
        res *= v;
        return res;
    }
    void operator*=(long long v){
        if(v < 0)
            sign = -sign, v = -v;
        for(int i = 0, carry = 0; i < sz(a) || carry; ++i){
            if(i == sz(a))
                a.push_back(0);
            long long cur = a[i] * (long long)v + carry;
            carry = (int)(cur / base);
            a[i] = (int)(cur % base);
            

        }
        trim();
    }
    Big operator*(long long v)const{
        Big res = *this;
        res *= v;
        return res;
    }
    friend pair<Big, Big> divmod(const Big& a1, const Big& b1){
        int norm = base / (b1.a.back() + 1);
        Big a = a1.abs() * norm;
        Big b = b1.abs() * norm;
        Big q, r;
        q.a.resize(sz(a.a));
        for(int i = sz(a.a) - 1; i >= 0; i--){
            r *= base;
            r += a.a[i];
            int s1 = sz(r.a) <= sz(b.a) ? 0 : r.a[sz(b.a)];
            int s2 = sz(r.a) <= sz(b.a) - 1 ? 0 : r.a[sz(b.a) - 1];
            int d = ((long long)base * s1 + s2) / b.a.back();
            r -= b * d;
            while(r < 0)
                r += b, --d;
            q.a[i] = d;
        }
        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }
    Big operator/(const Big& v)const{
        return divmod(*this, v).first;
    }
    Big operator%(const Big& v)const{
        return divmod(*this, v).second;
    }
    void operator/=(int v){
        if(v < 0)
            sign = -sign, v = -v;
        for(int i = sz(a) - 1, rem = 0; i >= 0; --i){
            long long cur = a[i] + rem * (long long)base;
            a[i] = (int)(cur / v);
            rem = (int)(cur % v);
        }
        trim();
    }
    Big operator/(int v)const{
        Big res = *this;
        res /= v;
        return res;
    }
    int operator%(int v)const{
        if(v < 0)
            v = -v;
        int m = 0;
        for(int i = sz(a) - 1; i >= 0; --i)
            m = (a[i] + m * (long long)base) % v;
        return m * sign;
    }
    void operator+=(const Big& v){
        *this = *this + v;
    }
    void operator++(){
        *this = *this + 1;
    }
    void operator-=(const Big& v){
        *this = *this - v;
    }
    void operator*=(const Big& v){
        *this = *this * v;
    }
    void operator/=(const Big& v){
        *this = *this / v;
    }
    void operator%=(const Big& v){
        *this = *this-(*this / v)*v;
    }
    bool operator<(const Big& v)const{
        if(sign != v.sign)
            return sign < v.sign;
        if(sz(a) != sz(v.a))
            return sz(a) * sign < sz(v.a) * v.sign;
        for(int i = sz(a) - 1; i >= 0; i--)
            if(a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }
    bool operator>(const Big& v)const{
        return v < *this;
    }
    bool operator<=(const Big& v)const{
        return !(v < *this);
    }
    bool operator>=(const Big& v)const{
        return !(*this < v);
    }
    bool operator==(const Big& v)const{
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const Big& v)const{
        return *this < v || v < *this;
    }
    void trim(){
        while(!a.empty() && !a.back())
            a.pop_back();
        if(a.empty())
            sign = 1;
    }
    bool isZero()const{
        return a.empty() || (sz(a) == 1 && !a[0]);
    }
    Big operator-()const{
        Big res = *this;
        res.sign = -sign;
        return res;
    }
    Big abs()const{
        Big res = *this;
        res.sign *= res.sign;
        return res;
    }
    explicit operator long long () const{
        long long res = 0;
        for(int i = sz(a) - 1; i >= 0; i--)
            res = res * base + a[i];
        return res * sign;
    }
    explicit operator int () const{
        return (operator long long)();
    }
    friend Big gcd(const Big& a, const Big& b){
        return b.isZero() ? a : gcd(b, a % b);
    }
    friend Big lcm(const Big& a, const Big& b){
        return a / gcd(a, b) * b;
    }
    void read(const string& s){
        sign = 1;
        a.clear();
        int pos = 0;
        while(pos < sz(s) && (s[pos] == '-' || s[pos] == '+')){
            if(s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for(int i = sz(s) - 1; i >= pos; i -= base_digits){
            int x = 0;
            for(int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }
    friend istream& operator>>(istream& stream, Big& v){
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }
    explicit operator string () const{
        stringstream stream;
        if(sign == -1)
            stream << '-';
        stream << (a.empty() ? 0 : a.back());
        for(int i = sz(a) - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << a[i];
        return stream.str();
    }
    friend ostream& operator<<(ostream& stream, const Big& v){
        return stream << string(v);
        

            

        

        

            

        

    }
    static vector<int> convert_base(const vector<int>& a, int old_digits, int new_digits){
        if(old_digits == new_digits) return a;
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for(int i = 1; i < sz(p); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for(int i = 0; i < sz(a); i++){
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while(cur_digits >= new_digits){
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int)cur);
        while(!res.empty() && !res.back())
            res.pop_back();
        return res;
    }
    static vl karatsubaMultiply(vl a, vl b){
        while(sz(a) < sz(b)) a.push_back(0);
        while(sz(b) < sz(a)) b.push_back(0);
        while(sz(a) & (sz(a) - 1)) a.push_back(0), b.push_back(0);
        int n = sz(a);
        vl res(n + n);
        if(n <= 32){
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }
        int k = n >> 1;
        vl a1(a.begin(), a.begin() + k);
        vl a2(a.begin() + k, a.end());
        vl b1(b.begin(), b.begin() + k);
        vl b2(b.begin() + k, b.end());
        vl id0 = karatsubaMultiply(a1, b1);
        vl id1 = karatsubaMultiply(a2, b2);
        for(int i = 0; i < k; i++)
            a2[i] += a1[i];
        for(int i = 0; i < k; i++)
            b2[i] += b1[i];
        vl r = karatsubaMultiply(a2, b2);
        for(int i = 0; i < sz(id0); i++)
            r[i] -= id0[i];
        for(int i = 0; i < sz(id1); i++)
            r[i] -= id1[i];
        for(int i = 0; i < sz(r); i++)
            res[i + k] += r[i];
        for(int i = 0; i < sz(id0); i++)
            res[i] += id0[i];
        for(int i = 0; i < sz(id1); i++)
            res[i + n] += id1[i];
        return res;
    }
    Big operator*(const Big& v)const{
        int digs = sz(this->a)+sz(v.a) >= 256 ? 3 : 6;
        int tmp_base = 1; rep(i,digs) tmp_base *= 10;
        vector<int> a6 = convert_base(this->a, base_digits, digs);
        vector<int> b6 = convert_base(v.a, base_digits, digs);
        vl a(a6.begin(), a6.end());
        vl b(b6.begin(), b6.end());
        while(sz(a) < sz(b))
            a.push_back(0);
        while(sz(b) < sz(a))
            b.push_back(0);
        while(sz(a) & (sz(a) - 1))
            a.push_back(0), b.push_back(0);
        vl c;
        if(digs == 6)
            c = karatsubaMultiply(a, b);
        else
            c = FFT_precision::multiply(a,b);
        Big res;
        res.sign = sign * v.sign;
        for(int i = 0, carry = 0; i < sz(c); i++){
            long long cur = c[i] + carry;
            res.a.push_back((int)(cur % tmp_base));
            carry = (int)(cur / tmp_base);
        }
        res.a = convert_base(res.a, digs, base_digits);
        res.trim();
        return res;
    }
};
ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}
T1 istream& read(T, T, istream& = cin);
namespace FFT_precision{
    typedef double ld; 

    struct C { ld re, im;
        C operator * (const C & he) const {
            return C{re * he.re - im * he.im,
                re * he.im + im * he.re};
        }
        void operator += (const C & he) { re += he.re; im += he.im; }
    };
    void dft(vector<C> & a, bool rev) {
        const int n = a.size();
        for(int i = 1, k = 0; i < n; ++i) {
            for(int bit = n / 2; (k ^= bit) < bit; bit /= 2);;;
            if(i < k) swap(a[i], a[k]);
        }
        for(int len = 1, who = 0; len < n; len *= 2, ++who) {
            static vector<C> t[30];
            vector<C> & om = t[who];
            if(om.empty()) {
                om.resize(len);
                const ld ang = 2 * acosl(0) / len;
                rep(i, len) om[i] = i%2 || !who ?
                    C{cos(i*ang), sin(i*ang)} : t[who-1][i/2];
            }
            for(int i = 0; i < n; i += 2 * len)
                rep(k, len) {
                    const C x = a[i+k], y = a[i+k+len]
                        * C{om[k].re, om[k].im * (rev ? -1 : 1)};
                    a[i+k] += y;
                    a[i+k+len] = C{x.re - y.re, x.im - y.im};
                }
        }
        if(rev) rep(i, n) a[i].re /= n;
    }
    template<typename T>vector<T> multiply(const vector<T> & a, const vector<T> & b,
            bool split, bool normalize) {
        if(a.empty() || b.empty()) return {};
        T big = 0; if(normalize) { 

            assert(a.size() == b.size()); 

            for(T x : a) big = max(big, x);
            for(T x : b) big = max(big, x);
            big /= 2;
        }
        int n = a.size() + b.size();
        vector<T> ans(n - 1);
        
        while(n&(n-1)) ++n;
        auto foo = [&](const vector<C> & w, int i, int k) {
            int j = i ? n - i : 0, r = k ? -1 : 1;
            return C{w[i].re + w[j].re * r, w[i].im
                - w[j].im * r} * (k ? C{0, -0.5} : C{0.5, 0});
        };
        if(!split) { 

            vector<C> in(n), done(n);
            rep(i, a.size()) in[i].re = a[i] - big;
            rep(i, b.size()) in[i].im = b[i] - big;
            dft(in, false);
            rep(i, n) done[i] = foo(in, i, 0) * foo(in, i, 1);
            dft(done, true);
            rep(i, ans.size()) ans[i] = is_integral<T>::value ?
                llround(done[i].re) : done[i].re;
            

        }
        else { 

            const T M = 1<<15; 

            vector<C> t[2]; 

            rep(x, 2) {
                t[x].resize(n);
                auto & in = x ? b : a; 

                rep(i, in.size()) t[x][i]=C{ld(in[i]%M), ld(in[i]/M)};
                dft(t[x], false);
            }
            T mul = 1;
            for(int s = 0; s < 3; ++s, mul = (mul*M)%MOD) {
                vector<C> prod(n);
                rep(x, 2) rep(y, 2) if(x + y == s) rep(i, n)
                    prod[i] += foo(t[0], i, x) * foo(t[1], i, y);
                dft(prod, true); 

                rep(i, ans.size()) ans[i]= (ans[i]+llround(prod[i].re)%MOD*mul)%MOD;
            }
        }
        if(normalize) {
            T so_far = 0;
            rep(i, ans.size()) {
                if(i < (int) a.size()) so_far += a[i] + b[i];
                else so_far -= a[i-a.size()] + b[i-a.size()];
                ans[i] += big * so_far - big * big * min(i + 1, (int) ans.size() - i);
            }
        }
        return ans;
    }
}
struct _print {
    string sep,end;
    bool space;
    ostream &stream;
    _print(string _sep=" ",string _end="\n",
            ostream &_stream = cout)
        : sep(_sep),end(_end),space(false),
            stream(_stream) {}
    ~_print() { stream << end; }
    template <typename T>
        _print &operator , (const T &t) {
            if (space) stream << sep;
            space = true;
            stream << t;
            return *this;
        }
};



void _(){
    string s;
    cin >> s;
    string head = s.substr(0,min(sz(s),18ll));
    ld tmp = log(atoll(head.c_str()));
    tmp += log(10)*(sz(s)-sz(head));
    Big x(s);
    Big base = 1;
    int ans = int(1e9);
    ld minimum_needed = (tmp-2*log(2))/log(3)-1e-9;
    int p = minimum_needed;
    p = max(p,0);
    Big three = Big(3)^p;
    rep(twos,0,2){
        Big tmp = three;
        int w = p;
        while(tmp < x){
            tmp *= 3;
            ++w;
        }
        ans = min(ans,2*twos+3*w);
        three *= 2;
    }
    ans = max(ans,1);
    print ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
        _();
}
