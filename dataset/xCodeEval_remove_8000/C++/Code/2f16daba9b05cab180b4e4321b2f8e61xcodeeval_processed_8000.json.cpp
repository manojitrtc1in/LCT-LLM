





















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
template<typename F> double id3(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){l=m;}else{h=m;}}return (l+h)/2;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename F> double bsld(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){h=m;}else{l=m;}}return (l+h)/2;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }

template<typename T>class vector2:public vector<vector<T>>{public:vector2(){} vector2(size_t a,size_t b,T t=T()):vector<vector<T>>(a,vector<T>(b,t)){}};
template<typename T>class vector3:public vector<vector2<T>>{public:vector3(){} vector3(size_t a,size_t b,size_t c,T t=T()):vector<vector2<T>>(a,vector2<T>(b,c,t)){}};
template<typename T>class vector4:public vector<vector3<T>>{public:vector4(){} vector4(size_t a,size_t b,size_t c,size_t d,T t=T()):vector<vector3<T>>(a,vector3<T>(b,c,d,t)){}};
template<typename T>class vector5:public vector<vector4<T>>{public:vector5(){} vector5(size_t a,size_t b,size_t c,size_t d,size_t e,T t=T()):vector<vector4<T>>(a,vector4<T>(b,c,d,e,t)){}};








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
	static int div(int p, int q, int N) {
		ll t=0,nt=1,r=N,nr=q;
		while(nr){ ll q=r/nr;t-=q*nt;r-=q*nr;swap(t,nt);swap(r,nr); }
		t=(t<0)?t+N:t;
		r=(r<0)?r+N:r;
		if (gcd(p,N)%r) { return 0; }
		return (int)(((ll)t*(ll)p/r)%N);
	}
};












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
        for (unsigned u = std::abs(i); u;){
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
        size_t id2 = 20;
        if (a.size() > id2 && b.size() > id2){
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
            size_t id4 = word_bits() - partial_bits;
            result.back() >>= id4;
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

    static Num random_second_exclusive(const Num &id5, const Num &id0, random_func func){
        return id5 + random_exclusive(id0 - id5, func);
    }

    static Num random_both_inclusive(const Num &id5, const Num &id7, random_func func){
        return id5 + random_inclusive(id7 - id5, func);
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







template<typename Index, bool id6 = false, bool id1 = false>
class SuffixArray {
public:
	static_assert(id6 || !id1, "Must have RMQ for LCP");

	template<typename T>
	explicit SuffixArray(T t):N(t.size()), S(N), I(N), LCP(id6 ? N : 0) {
		typedef typename std::remove_reference<decltype(t[0])>::type Item;
		vector<pair<Item, Index>> TR(N);
		for (Index i = 0; i < N; ++i) { TR[i] = {t[i], i}; }
		sort(TR.begin(), TR.end());
		vector<Index> R(N);
		Index r = R[TR[0].y] = S[TR[0].y] = 0;
		for (Index i = 1; i < N; ++i) {
			R[TR[i].y] = r += (TR[i - 1].x != TR[i].x);
			S[TR[i].y] = i;
		}
		vector<Index> RA(N), SA(N), C(N);
		for (Index k = 1; k < N; k <<= 1) {
			counting_sort(R, C, SA, k);
			counting_sort(R, C, SA, 0);
			RA[S[0]] = r = 0;
			for (Index i = 1; i < N; ++i) {
				RA[S[i]] = r += (R[S[i]] != R[S[i - 1]] || S[i] + k >= N || S[i - 1] + k >= N ||
								R[S[i] + k] != R[S[i - 1] + k]);
			}
			swap(RA, R);
			if (R[S[N - 1]] == N - 1)break;
		}
		for (Index i = 0; i < N; ++i) { I[S[i]] = i; }
		if (id6) {
			Index k = 0;
			for (Index i = 0; i < N; ++i) {
				if (I[i] == N - 1) {
					LCP[I[i]] = k = 0;
					continue;
				}
				while (i + k < N && S[I[i] + 1] + k < N && t[i + k] == t[S[I[i] + 1] + k]) { ++k; }
				LCP[I[i]] = k;
				if (k > 0) { --k; }
			}
		}
		if (id1) {
			RMQ.push_back(LCP);
			for (int p = 0; (1 << p) < N; ++p) {
				RMQ.push_back(RMQ[p]);
				for (int i = 0; i < N - (1 << p); ++i) { RMQ[p + 1][i] = min(RMQ[p + 1][i], RMQ[p][i + (1 << p)]); }
			}







		}
	}

	Index next(Index i) { return (I[i] == N - 1) ? -1 : S[I[i] + 1]; }

	template<typename=std::enable_if<id6>>
	Index lcp(Index i) const { return LCP[I[i]]; }

	template<typename=std::enable_if<id1>>
	Index lcp(Index i, Index j) const {
		i = I[i];
		j = I[j];
		if (i > j) { swap(i, j); }
		if (i == j - 1)return LCP[i];
		Index p = 0;
		while ((1 << p) < j - i) { ++p; }
		--p;
		return min(RMQ[p][i], RMQ[p][j - (1 << p)]);
	}

	inline void counting_sort(const vector<int> &R, vector<int> &C, vector<int> &SA, int k) {
		Index i;
		fill(C.begin(), C.end(), 0);
		for (i = 0; i < N; i++) { C[i + k < N ? R[i + k] : 0]++; }
		for (Index sum = i = 0; i < N; i++) { C[i] = (sum += C[i], sum - C[i]); }
		for (i = 0; i < N; i++) { SA[C[S[i] + k < N ? R[S[i] + k] : 0]++] = S[i]; }
		swap(SA, S);
	}

	Index N;
	vector<Index> S, I, LCP;
	vector<vector<Index>> RMQ;
};

class dreamoonandbinary {
public:
    void solve(istream& cin, ostream& cout) {
        string S;
        cin >> S;
        int N = S.size();
        S += '$';
        SuffixArray<int, true, true> SA(S);



        vector<vector<FieldMod>> E(N+1);
        vector<vector<int>> M(N+1);
        for (int e = 1; e <= N; ++e) {
            E[e] = vector<FieldMod>(e+1, 0);
            E[e][0] = 1;

            M[e] = vector<int>(e+1,1e9);
            M[e][0] = 1;

            for (int b = 1; b < e; ++b) {
                if (S[b] == '0') {
                    E[e][b] = E[e][b - 1];
                    continue;
                }

                FieldMod x = 0;
                int l = e - b;
                int origin = b - l;
                int lo = max(origin + 1, 0), hi = b - 1;
                if (origin >= 0) {
                    int lcp = SA.lcp(origin, b);






                    if (lcp >= l) --lo;
                    else if (S[origin + lcp] < S[b + lcp]) --lo;


                }





                x += E[b][hi];
                if (lo) x -= E[b][lo - 1];
                E[e][b] = E[e][b - 1] + x;
                if (lo <= hi) M[e][b] = min(M[e][b], M[b][lo] + 1);
            }

            for (int b = e-2; b >= 1; --b) { M[e][b] = min(M[e][b], M[e][b+1]);  }
        }

        cout << E[N][N - 1] << endl;

        Num X = 0;
        int hi = N;
        for (int l = 0; l <= hi; ++l) {
            if (M[N][N-l] != 1e9) {
                Num Z{S.substr(N-l,l), 2};
                Z += Num{ll(M[N][N-l])};
                if (X == 0) {
                    swap(X,Z);
                    hi = min(N, max(20, l+1));
                } else if (X > Z) {
                    swap(X, Z);
                }
            }
        }
        cout << (X % Num{ll(1000000007)}).to_longlong() << endl;
    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	dreamoonandbinary solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}