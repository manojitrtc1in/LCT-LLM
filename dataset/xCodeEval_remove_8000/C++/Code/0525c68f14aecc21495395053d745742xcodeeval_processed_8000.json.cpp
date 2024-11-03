





















using namespace std;



typedef std::pair<int,int> pii; typedef long long ll; typedef unsigned long long ull; typedef unsigned int ui; typedef pair<ui,ui> puu;

template <typename T, typename U> std::istream&operator>>(std::istream&i, pair<T,U>&p) {i >> p.x >> p.y; return i;}
template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template <typename T, typename U> std::ostream&operator<<(std::ostream&o, const pair<T,U>&p) {o << p.x << ' ' << p.y; return o;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {if(t.empty())o<<'\n';for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}
template<typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using maxheap = priority_queue<T, vector<T>, less<T>>;
template <typename T> bool in(T a, T b, T c) { return a <= b && b < c; }
ui logceil(int x) { return 8*sizeof(int)-__builtin_clz(x); }

namespace std { template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}}; }
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename F> double id2(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){l=m;}else{h=m;}}return (l+h)/2;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename F> double bsld(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){h=m;}else{l=m;}}return (l+h)/2;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }

template<typename T>class vector2:public vector<vector<T>>{public:vector2(){} vector2(size_t a,size_t b,T t=T()):vector<vector<T>>(a,vector<T>(b,t)){}};
template<typename T>class vector3:public vector<vector2<T>>{public:vector3(){} vector3(size_t a,size_t b,size_t c,T t=T()):vector<vector2<T>>(a,vector2<T>(b,c,t)){}};
template<typename T>class vector4:public vector<vector3<T>>{public:vector4(){} vector4(size_t a,size_t b,size_t c,size_t d,T t=T()):vector<vector3<T>>(a,vector3<T>(b,c,d,t)){}};
template<typename T>class vector5:public vector<vector4<T>>{public:vector5(){} vector5(size_t a,size_t b,size_t c,size_t d,size_t e,T t=T()):vector<vector4<T>>(a,vector4<T>(b,c,d,e,t)){}};

















class Num {
public:
    typedef uint64_t word;

    std::vector<word> words;
    bool neg;

    static word word_mask(){
        return (word)-1;
    }

    static size_t word_bits(){
        return sizeof(word)*CHAR_BIT;
    }

    static word word_half_mask(){
        return word_mask() >> word_bits()/2;
    }

    static word char_to_word(char c){
        switch (c){
            case '0': return 0;
            case '1': return 1;
            case '2': return 2;
            case '3': return 3;
            case '4': return 4;
            case '5': return 5;
            case '6': return 6;
            case '7': return 7;
            case '8': return 8;
            case '9': return 9;
            case 'a': case 'A': return 10;
            case 'b': case 'B': return 11;
            case 'c': case 'C': return 12;
            case 'd': case 'D': return 13;
            case 'e': case 'E': return 14;
            case 'f': case 'F': return 15;
            case 'g': case 'G': return 16;
            case 'h': case 'H': return 17;
            case 'i': case 'I': return 18;
            case 'j': case 'J': return 19;
            case 'k': case 'K': return 20;
            case 'l': case 'L': return 21;
            case 'm': case 'M': return 22;
            case 'n': case 'N': return 23;
            case 'o': case 'O': return 24;
            case 'p': case 'P': return 25;
            case 'q': case 'Q': return 26;
            case 'r': case 'R': return 27;
            case 's': case 'S': return 28;
            case 't': case 'T': return 29;
            case 'u': case 'U': return 30;
            case 'v': case 'V': return 31;
            case 'w': case 'W': return 32;
            case 'x': case 'X': return 33;
            case 'y': case 'Y': return 34;
            case 'z': case 'Z': return 35;
            default: return word_mask();
        }
    }

    static word word_gcd(word a, word b){
        while (1){
            if (a == 0) return b;
            b %= a;
            if (b == 0) return a;
            a %= b;
        }
    }

    Num(): neg(false){}

    Num(size_t n, word w, bool neg = false): words(n, w), neg(neg){}

    Num(const word *a, const word *b, bool neg = false) : words(a, b), neg(neg){}

    Num(const Num &a){
        words = a.words;
        neg = a.neg;
    }

    Num& operator= (const Num &a){
        words = a.words;
        neg = a.neg;
        return *this;
    }

    Num(long long i): neg(i < 0) {
        for (unsigned long long u = std::abs(i); u;){
            push_back(u);
            for (size_t j = 0; j < word_bits(); j++) u >>= 1;
        }
    }

    Num(std::string s, word base = 10): neg(false){
        if (s[0] == '-'){
            neg = true;
        }
        for (int i = neg; i < s.size(); i++){
            mul_word(base);
            word b = char_to_word(s[i]);
            if (b >= base) break;
            add_word(b);
        }
    }

    void resize(size_t n){
        words.resize(n);
    }

    void pop_back(){
        words.pop_back();
    }

    void push_back(word b){
        words.push_back(b);
    }

    word& back(){
        return words.back();
    }

    const word& back() const {
        return words.back();
    }

    size_t size() const {
        return words.size();
    }

    word& operator [] (size_t i){
        return words[i];
    }

    const word& operator [] (size_t i) const {
        return words[i];
    }

    Num& set_neg(bool neg){
        this->neg = neg;
        return *this;
    }

    Num& truncate(){
        while (size() > 0 && words.back() == 0) pop_back();
        return *this;
    }

    size_t bitlength() const {
        if (size() == 0) return 0;
        size_t last = size() - 1;
        size_t result = word_bitlength((*this)[last]) + last*word_bits();
        return result;
    }

    size_t count_trailing_zeros() const {
        for (size_t i = 0; i < size(); i++){
            word w = (*this)[i];
            if (w) return word_count_trailing_zeros(w) + i*word_bits();
        }
        return 0;
    }

    static int cmp_abs(const Num &a, const Num &b){
        size_t na = a.size(), nb = b.size();
        if (na != nb){
            return na < nb ? -1 : +1;
        }
        for (size_t i = na; i --> 0;){
            word wa = a[i], wb = b[i];
            if (wa != wb){
                return wa < wb ? -1 : +1;
            }
        }
        return 0;
    }

    static int cmp(const Num &a, const Num &b){
        if (a.size() == 0 && b.size() == 0) return 0;
        if (!a.neg && !b.neg) return +cmp_abs(a, b);
        if ( a.neg &&  b.neg) return -cmp_abs(a, b);
        return a.neg && !b.neg ? -1 : +1;
    }

    static size_t word_bitlength(word a){
        for (int i = word_bits() - 1; i >= 0; i--) if ((a >> i) & 1) return i+1;
        return 0;
    }

    static size_t word_count_trailing_zeros(word a){
        for (int i = 0; i < (int)word_bits(); i++) if ((a >> i) & 1) return i;
        return word_bits();
    }

    static word add_carry(word *a, word b){
        return (*a += b) < b;
    }

    static word sub_carry(word *a, word b){
        word tmp = *a;
        return (*a = tmp - b) > tmp;
    }

    static word word_mul_hi(word a, word b){
        size_t n = word_bits()/2;
        word a_hi = a >> n;
        word a_lo = a & word_half_mask();
        word b_hi = b >> n;
        word b_lo = b & word_half_mask();
        word tmp = ((a_lo*b_lo) >> n) + a_hi*b_lo;
        tmp = (tmp >> n) + ((a_lo*b_hi + (tmp & word_half_mask())) >> n);
        return tmp + a_hi*b_hi;
    }

    static Num& add_unsigned_overwrite(Num &a, const Num &b){
        size_t i, na = a.size(), nb = b.size(), n = std::max(na, nb);
        a.resize(n);
        word carry = 0;
        for (i = 0; i < nb; i++){
            carry  = add_carry(&a[i], carry);
            carry += add_carry(&a[i], b[i]);
        }
        for (; i < n && carry; i++) carry = add_carry(&a[i], carry);
        if (carry) a.push_back(carry);
        return a.truncate();
    }

    static Num& sub_unsigned_overwrite(Num &a, const Num &b){
        

        size_t i, na = a.size(), nb = b.size();
        word carry = 0;
        for (i = 0; i < nb; i++){
            carry  = sub_carry(&a[i], carry);
            carry += sub_carry(&a[i], b[i]);
        }
        for (; i < na && carry; i++) carry = sub_carry(&a[i], carry);
        

        return a.truncate();
    }

    static Num mul_long(const Num &a, const Num &b){
        size_t na = a.size(), nb = b.size(), nc = na + nb + 1;
        Num c(nc, 0, a.neg ^ b.neg), carries(nc, 0);
        for (size_t ia = 0; ia < na; ia++){
            for (size_t ib = 0; ib < nb; ib++){
                size_t i = ia + ib, j = i + 1;
                

                carries[i + 1] += add_carry(&c[i], a[ia] * b[ib]);
                carries[j + 1] += add_carry(&c[j], word_mul_hi(a[ia], b[ib]));
            }
        }
        return add_unsigned_overwrite(c, carries).truncate();
    }

    static Num mul_karatsuba(const Num &a, const Num &b){
        size_t na = a.size(), nb = b.size(), n = std::max(na, nb), m2 = n/2 + (n & 1);
        Num a_parts[2], b_parts[2];
        split(a, a_parts, 2, m2);
        split(b, b_parts, 2, m2);
        m2 *= word_bits();
        Num z0 = a_parts[0] * b_parts[0];
        Num z1 = (a_parts[0] + a_parts[1]) * (b_parts[0] + b_parts[1]);
        Num z2 = a_parts[1] * b_parts[1];
        Num result = z2;
        result <<= m2;
        result += z1 - z2 - z0;
        result <<= m2;
        result += z0;
        return result;
    }

    static Num mul(const Num &a, const Num &b){
        size_t id1 = 20;
        if (a.size() > id1 && b.size() > id1){
            return mul_karatsuba(a, b);
        }
        return mul_long(a, b);
    }

    static Num add_signed(const Num &a, bool a_neg, const Num &b, bool b_neg){
        if (a_neg == b_neg) return add_unsigned(a, b).set_neg(a_neg);
        if (cmp_abs(a, b) >= 0) return sub_unsigned(a, b).set_neg(a_neg);
        return sub_unsigned(b, a).set_neg(b_neg);
    }

    Num& operator >>= (size_t n_bits){
        if (n_bits == 0) return *this;
        size_t n_words = n_bits / word_bits();
        if (n_words >= size()){
            resize(0);
            return *this;
        }
        n_bits %= word_bits();
        if (n_bits == 0){
            for (size_t i = 0; i < size() - n_words; i++){
                (*this)[i] = (*this)[i + n_words];
            }
        }else{
            word hi, lo = (*this)[n_words];
            for (size_t i = 0; i < size() - n_words - 1; i++){
                hi = (*this)[i + n_words + 1];
                (*this)[i] = (hi << (word_bits() - n_bits)) | (lo >> n_bits);
                lo = hi;
            }
            (*this)[size() - n_words - 1] = lo >> n_bits;
        }
        resize(size() - n_words);
        return truncate();
    }

    Num& operator <<= (size_t n_bits){
        if (n_bits == 0) return *this;
        size_t n_words = n_bits / word_bits();
        n_bits %= word_bits();
        size_t old_size = size();
        size_t n = old_size + n_words + (n_bits != 0);
        resize(n);
        if (n_bits == 0){
            for (size_t i = n; i --> n_words;){
                (*this)[i] = (*this)[i - n_words];
            }
        }else{
            word lo, hi = 0;
            for (size_t i = n - 1; i > n_words; i--){
                lo = (*this)[i - n_words - 1];
                (*this)[i] = (hi << n_bits) | (lo >> (word_bits() - n_bits));
                hi = lo;
            }
            (*this)[n_words] = hi << n_bits;
        }
        for (size_t i = 0; i < n_words; i++) (*this)[i] = 0;
        return truncate();
    }

    static void div_mod(const Num &numerator, Num denominator, Num &quotient, Num &remainder){
        quotient = 0;
        remainder = numerator;
        if (cmp_abs(remainder, denominator) >= 0){
            int n = numerator.bitlength() - denominator.bitlength();
            denominator <<= n;
            for (; n >= 0; n--){
                if (cmp_abs(remainder, denominator) >= 0){
                    sub_unsigned_overwrite(remainder, denominator);
                    quotient.set_bit(n);
                }
                denominator >>= 1;
            }
        }
        quotient.set_neg(numerator.neg ^ denominator.neg);
        remainder.set_neg(numerator.neg);
    }

    static void div_mod_half_word(const Num &numerator, word denominator, Num &quotient, word &remainder){
        remainder = 0;
        Num dst(numerator.size(), 0);

        for (size_t i = numerator.size(); i --> 0;){
            word dst_word = 0;
            word src_word = numerator[i];
            word parts[2];
            parts[0] = src_word >> word_bits()/2;
            parts[1] = src_word & word_half_mask();

            for (size_t j = 0; j < 2; j++){
                remainder <<= word_bits()/2;
                remainder |= parts[j];

                word div_word = remainder / denominator;
                word mod_word = remainder % denominator;
                remainder = mod_word;

                dst_word <<= word_bits()/2;
                dst_word |= div_word;
            }

            dst[i] = dst_word;
        }

        quotient = dst.truncate().set_neg(numerator.neg);
    }

    static void split(const Num &a, Num *parts, size_t n_parts, size_t n){
        size_t i = 0;
        for (size_t k = 0; k < n_parts; k++){
            Num &part = parts[k];
            part.resize(n);
            for (size_t j = 0; j < n && i < a.size(); j++) part[j] = a[i++];
            part = part.truncate();
        }
    }

    static Num div(const Num &numerator, const Num& denominator){
        Num quotient, remainder;
        div_mod(numerator, denominator, quotient, remainder);
        return quotient;
    }

    static Num mod(const Num &numerator, const Num& denominator){
        Num quotient, remainder;
        div_mod(numerator, denominator, quotient, remainder);
        return remainder;
    }

    static Num add_unsigned(const Num &a, const Num &b){
        Num result(a);
        return add_unsigned_overwrite(result, b);
    }

    static Num sub_unsigned(const Num &a, const Num &b){
        Num result(a);
        return sub_unsigned_overwrite(result, b);
    }

    static Num add(const Num &a, const Num &b){
        Num result = add_signed(a, a.neg, b, b.neg);
        return result;
    }

    static Num sub(const Num &a, const Num &b){
        Num result = add_signed(a, a.neg, b, !b.neg);
        return result;
    }

    static Num gcd(const Num &a0, const Num &b0){

        if (a0.size() == 1 && b0.size() == 1){
            return Num(1, word_gcd(a0[0], b0[0]));
        }

        Num a(a0), b(b0);
        a.neg = b.neg = false;

        if (a.size() == 0) return b0;
        if (b.size() == 0) return a0;

        size_t n = std::min(a.count_trailing_zeros(), b.count_trailing_zeros());

        a >>= n;
        b >>= n;

        do {
            b >>= b.count_trailing_zeros();
            if (cmp_abs(a, b) > 0) a.words.swap(b.words);
            sub_unsigned_overwrite(b, a);
        } while (b.size() > 0);

        a <<= n;

        return a;
    }

    typedef void (*random_func)(uint8_t *bytes, size_t n_bytes);

    static Num random_bits(size_t n_bits, random_func func){
        if (n_bits == 0) return 0;
        size_t partial_bits = n_bits % word_bits();
        size_t n_words = n_bits / word_bits() + (partial_bits > 0);
        size_t n_bytes = n_words*sizeof(word);
        Num result(n_words, 0);
        uint8_t *bytes = (uint8_t*)&result[0];
        func(bytes, n_bytes);
        if (partial_bits){
            size_t id3 = word_bits() - partial_bits;
            result.back() >>= id3;
        }
        return result;
    }

    static Num random_inclusive(const Num &inclusive, random_func func){
        size_t n_bits = inclusive.bitlength();
        while (true){
            Num result = random_bits(n_bits, func);
            if (result <= inclusive) return result;
        }
    }

    static Num random_exclusive(const Num &exclusive, random_func func){
        size_t n_bits = exclusive.bitlength();
        while (true){
            Num result = random_bits(n_bits, func);
            if (result < exclusive) return result;
        }
    }

    static Num random_second_exclusive(const Num &id4, const Num &id0, random_func func){
        return id4 + random_exclusive(id0 - id4, func);
    }

    static Num random_both_inclusive(const Num &id4, const Num &id5, random_func func){
        return id4 + random_inclusive(id5 - id4, func);
    }

    Num& set_bit(size_t i){
        size_t i_word = i / word_bits();
        size_t i_bit =  i % word_bits();
        if (size() <= i_word) resize(i_word + 1);
        (*this)[i_word] |= ((word)1) << i_bit;
        return *this;
    }

    word get_bit(size_t i) const {
        size_t i_word = i / word_bits();
        size_t i_bit =  i % word_bits();
        if (i_word >= size()) return 0;
        return ((*this)[i_word] >> i_bit) & 1;
    }

    void clr_bit(size_t i){
        size_t i_word = i / word_bits();
        size_t i_bit =  i % word_bits();
        if (i_word >= size()) return;
        word mask = 1;
        mask <<= i_bit;
        (*this)[i_word] &= ~mask;
    }

    Num& mul_word(word b){
        word carry = 0;
        for (size_t i = 0; i < size(); i++){
            word a = (*this)[i];
            word tmp = a * b;
            carry = add_carry(&tmp, carry);
            carry += word_mul_hi(a, b);
            (*this)[i] = tmp;
        }
        if (carry) push_back(carry);
        return truncate();
    }

    Num& add_word(word carry, size_t i0 = 0){
        if (i0 >= size()) resize(i0 + 1);
        for (size_t i = i0; i < size() && carry; i++){
            carry = add_carry(&(*this)[i], carry);
        }
        if (carry) push_back(carry);
        return truncate();
    }

    void print(std::ostream&os, word base = 10, const char *alphabet = "0123456789abcdefghijklmnopqrstuvwxyz") const {
        if (size() == 0){
            os << '0';
        }else{
            vector<char> text;
            Num tmp(*this);
            while (tmp.size() > 0){
                word remainder;
                div_mod_half_word(tmp, base, tmp, remainder);
                text.push_back(alphabet[remainder]);
            }
            if (neg) os << '-';
            for (int i = text.size()-1; i >= 0; --i) os << text[i];
        }
    }

    long long to_longlong() const {
        if (size() == 0) return 0;
        word d = (*this)[0];
        return neg ? -d : d;
    }

    double to_double() const {
        if (size() == 0) return 0.0;
        double d = 0.0, base = ::pow(2.0, word_bits());
        for (size_t i = size(); i --> 0;) d = d * base + (*this)[i];
        return neg ? -d : d;
    }

    Num pow(size_t exponent) const {
        Num result(1), p(*this);
        for (; exponent; exponent >>= 1){
            if (exponent & 1){
                result = result * p;
                exponent--;
            }
            p = p*p;
        }
        return result;
    }

    Num mod_pow(Num exponent, const Num &modulus) const {
        Num result(1), base = (*this) % modulus;
        for (; exponent.size() > 0; exponent >>= 1){
            if (exponent.get_bit(0)){
                result = (result * base) % modulus;
            }
            base = (base * base) % modulus;
        }
        return result;
    }

    Num sqrt() const {
        Num n = *this;
        int bit = bitlength();
        if (bit & 1) bit ^= 1;
        Num result = 0;
        for (; bit >= 0; bit -= 2){
            Num tmp = result;
            tmp.set_bit(bit);
            if (n >= tmp){
                n -= tmp;
                result.set_bit(bit + 1);
            }
            result >>= 1;
        }
        return result;
    }

    Num& operator ++(){
        add_word(1);
        return *this;
    }

    Num& operator += (const Num &b){ return *this = add(*this, b); }
    Num& operator -= (const Num &b){ return *this = sub(*this, b); }
    Num& operator *= (const Num &b){ return *this = mul(*this, b); }
    Num& operator /= (const Num &b){ return *this = div(*this, b); }
    Num& operator %= (const Num &b){ return *this = mod(*this, b); }

    bool operator == (const Num &b) const { return cmp(*this, b) == 0; }
    bool operator != (const Num &b) const { return cmp(*this, b) != 0; }
    bool operator <= (const Num &b) const { return cmp(*this, b) <= 0; }
    bool operator >= (const Num &b) const { return cmp(*this, b) >= 0; }
    bool operator <  (const Num &b) const { return cmp(*this, b) <  0; }
    bool operator >  (const Num &b) const { return cmp(*this, b) >  0; }

    Num operator + (const Num &b) const { return add(*this, b); }
    Num operator - (const Num &b) const { return sub(*this, b); }
    Num operator * (const Num &b) const { return mul(*this, b); }
    Num operator / (const Num &b) const { return div(*this, b); }
    Num operator % (const Num &b) const { return mod(*this, b); }
    Num operator - (            ) const { return Num(*this).set_neg(!neg); }

    Num operator >> (size_t n_bits) const { return Num(*this) >>= n_bits; }
    Num operator << (size_t n_bits) const { return Num(*this) <<= n_bits; }
};







template <unsigned int N> class Field {
    typedef unsigned int ui;
    typedef unsigned long long ull;
	inline ui pow(ui a, ui p){ui r=1,e=a;while(p){if(p&1){r=((ull)r*e)%N;}e=((ull)e*e)%N;p>>=1;}return r;}
	
	inline ui inv(ui a){return pow(a,N-2);}
public:
    inline Field(int x = 0) : v(x) {}
	inline Field<N> pow(int p){return (*this)^p; }
	inline Field<N> operator^(int p){return {(int)pow(v,(ui)p)};}
    inline Field<N>&operator+=(const Field<N>&o) {if ((ll)v+o.v >= N) v += o.v - N; else v += o.v; return *this; }
    inline Field<N>&operator-=(const Field<N>&o) {if (v<o.v) v -= o.v-N; else v-=o.v; return *this; }
    inline Field<N>&operator*=(const Field<N>&o) {v=(ull)v*o.v % N; return *this; }
    inline Field<N>&operator/=(const Field<N>&o) { return *this*=inv(o.v); }
    inline Field<N> operator+(const Field<N>&o) const {Field<N>r{*this};return r+=o;}
    inline Field<N> operator-(const Field<N>&o) const {Field<N>r{*this};return r-=o;}
    inline Field<N> operator*(const Field<N>&o) const {Field<N>r{*this};return r*=o;}
    inline Field<N> operator/(const Field<N>&o) const {Field<N>r{*this};return r/=o;}
    inline Field<N> operator-() {if(v) return {(int)(N-v)}; else return {0};};
    inline Field<N>& operator++() { ++v; if (v==N) v=0; return *this; }
    inline Field<N> operator++(int) { Field<N>r{*this}; ++*this; return r; }
    inline Field<N>& operator--() { --v; if (v==-1) v=N-1; return *this; }
    inline Field<N> operator--(int) { Field<N>r{*this}; --*this; return r; }
    inline bool operator==(const Field<N>&o) const { return o.v==v; }
	inline bool operator!=(const Field<N>&o) const { return o.v!=v; }
	inline explicit operator ui() const { return v; }
	inline static vector<Field<N>>fact(int t){vector<Field<N>>F(t+1,1);for(int i=2;i<=t;++i){F[i]=F[i-1]*i;}return F;}
	inline static vector<Field<N>>invfact(int t){vector<Field<N>>F(t+1,1);Field<N> X{1};for(int i=2;i<=t;++i){X=X*i;}F[t]=1/X;for(int i=t-1;i>=2;--i){F[i]=F[i+1]*(i+1);}return F;}
private: ui v;
};
template<unsigned int N>istream &operator>>(std::istream&is,Field<N>&f){unsigned int v;is>>v;f=v;return is;}
template<unsigned int N>ostream &operator<<(std::ostream&os,const Field<N>&f){return os<<(unsigned int)f;}
template<unsigned int N>Field<N> operator+(int i,const Field<N>&f){return Field<N>(i)+f;}
template<unsigned int N>Field<N> operator-(int i,const Field<N>&f){return Field<N>(i)-f;}
template<unsigned int N>Field<N> operator*(int i,const Field<N>&f){return Field<N>(i)*f;}
template<unsigned int N>Field<N> operator/(int i,const Field<N>&f){return Field<N>(i)/f;}


typedef Field<1000000007> FieldMod;

struct Ring {
	static ll div(ll p, ll q, ll N) {
		ll t=0,nt=1,r=N,nr=q;
		while(nr){ ll q=r/nr;t-=q*nt;r-=q*nr;swap(t,nt);swap(r,nr); }
		t=(t<0)?t+N:t;
		r=(r<0)?r+N:r;
		if (gcd(p,N)%r) { return 0; }
		return ((ll)t*(ll)p/r)%N;
	}
};



class Chinese {
public:
    Chinese(const vector<ll> &p, ll M) : P(1), M(M), F(p.size()), T(p.size()), p(p) {
        for(int i=0;i<p.size();++i) P*=p[i];
        for(int i=0;i<p.size();++i) F[i]=P/p[i];
        for(int i=0;i<p.size();++i) T[i]=Ring::div(1, (F[i]%p[i]).to_longlong(), p[i]);
    }

    ll operator()(const vector<ll> &R) {






        Num X = 0;


        for (int i=0;i<R.size();++i) X += F[i] * ((Num{T[i]} * R[i])%p[i]);
        X %= P;
        X %= M;
        return X.to_longlong();
    }
private:


    Num P;
    ll M;
    vector<Num> F;
    vector<ll> T,p;
};







class GCDTable {
public:
void solve(istream& cin, ostream& cout) {
    ll N, M; cin >> N >> M;
    int K; cin >> K;
    vector<ll> A(K); cin >> A;

    ll row = 1;
    for (ll &a:A) {
        ll t = a / gcd(row, a);
        if (t > N/row) {
            cout << "NO\n";
            return;
        }
        row *= t;
        if (row > N) {
            cout << "NO\n";
            return;
        }
    }

    vector<ll> P;
    ll r = row;
    for (ll i = 2; i * i <= r; ++i) {
        if (r % i == 0) {
            ll z = 1;
            while (r % i == 0) {
                r /= i;
                z *= i;
            }
            P.push_back(z);
        }
    }
    if (r != 1) P.push_back(r);

    vector<ll> D;
    for (ll p:P) {
        int ans = -1;
        for (int i = 0; i < min(ll(K), p); ++i) {
            if (A[i] % p == 0) {
                ans = i;
                break;
            }
        }
        if (ans == -1) {
            cout << "NO\n";
            return;
        }
        D.push_back(ans ? p - ans : 0);
    }

    Chinese CH{P, row};
    ll col = CH(D);
    if (col == 0) col = row;
    if (col > M - K + 1) {
        cout << "NO\n";
        return;
    }


    for (int i = 0; i < K; ++i) {
        if (gcd(row, col + i) != A[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	GCDTable solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}
