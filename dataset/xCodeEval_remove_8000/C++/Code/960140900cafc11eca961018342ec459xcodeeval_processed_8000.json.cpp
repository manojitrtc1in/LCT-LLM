
const int BARIER = 0;
class Rng{
private:
    static std::mt19937 engine;
public:
    static std::mt19937& get_engine(){
        return engine;
    }
    template<typename T>
    static void set_seed(T const& seed){
        engine = std::mt19937(seed);
    }
    static void timebased_seed(){
        engine = std::mt19937(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
    }
    template<typename T>
    static typename std::enable_if<std::is_integral<T>::value, T>::type uniform(T l, T r){
        return std::uniform_int_distribution<T>(l, r)(engine);
    }
    template<typename T>
    static typename std::enable_if<std::is_floating_point<T>::value, T>::type uniform(T l, T r){
        return std::uniform_real_distribution<T>(l, r)(engine);
    }
};
std::mt19937 Rng::engine(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
class Timer{
public:
    template<typename S, typename T, typename... U>
    static S id1(T func, std::string const& name, U&&... u){
        auto time_begin = std::chrono::high_resolution_clock::now();
        S ret = func(std::forward<U>(u)...);
        auto time_end = std::chrono::high_resolution_clock::now();
        auto timespan = std::chrono::duration_cast<std::chrono::nanoseconds>(time_end - time_begin);
        std::cerr << "Execution of '" << name << "' took " << std::fixed << std::setprecision(6) << timespan.count()*1e-9 << "\n";
        return ret;
    }
};
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
using namespace std;
class id12{
public:
    static constexpr int64_t BASE = 1e18;
    static constexpr int DIGITS = 18;
private:
    bool is_neg;
    vector<int64_t> data;
public:
    id12():is_neg(false), data(1, 0){}
    id12(int64_t const&val):is_neg(val<0){
        int64_t abs_val = abs(val);
        if(abs_val < BASE){
            data = {abs_val};
        } else {
            data = {abs_val%BASE, abs_val/BASE};
        }
    }
    id12 operator+(id12 const&o)const{
        id12 ret;
        ret.is_neg = is_neg;
        ret.data.assign(1+max(data.size(), o.data.size()), 0);
        copy(data.begin(), data.end(), ret.data.begin());
        int64_t carry = 0;
        for(unsigned int i=0;i<o.data.size();++i){
            ret.data[i]+=o.data[i] + carry;
            carry = 0;
            if(ret.data[i] >= BASE){
                carry = 1;
                ret.data[i]-=BASE;
            }
        }
        for(unsigned int i=o.data.size();carry;++i){
            ret.data[i]+=carry;
            carry = 0;
            if(ret.data[i] >= BASE){
                carry = 1;
                ret.data[i]-=BASE;
            }
        }
        return ret.trim();
    }
    id12 operator*(int64_t const&o)const{
        if(o == 0){
            return id12(0);
        }
        if(o<0){
            return operator*(-o).negate();
        }
        if(o&1){
            return operator+(operator*(o-1));
        }
        return operator+(*this)*(o/2);
    }
    id12& operator+=(id12 const&o){
        *this = operator+(o);
        return *this;
    }
    id12& operator*=(int64_t const&o){
        *this = operator*(o);
        return *this;
    }
    id12& trim(){
        while(data.size()>1 && data.back() == 0){
            data.pop_back();
        }
        return *this;
    }
    bool is_zero()const{
        for(auto const&e:data) if(e) return false;
        return true;
    }
    id12& negate(){
        is_neg = !is_neg;
        if(is_zero()) is_neg = false;
        return *this;
    }
    friend ostream& operator<<(ostream&o, id12 const&b){
        if(b.is_neg) o << '-';
        o << b.data.back();
        o << setfill('0');
        for(auto it = next(b.data.rbegin());it != b.data.rend();++it){
            o << setw(9) << *it;
        }
        o << setw(0) << setfill(' ');
        return o;
    }
    friend istream& operator>>(istream&in, id12 &b){
        static string tmp;
        in >> tmp;

        if(tmp[0] == '-'){
            b.is_neg = true;
            tmp = tmp.substr(1, -1);
        } else {
            b.is_neg = false;
        }


        b.data.resize((tmp.size()+DIGITS-1)/DIGITS);
        unsigned int i, j;
        for(i=tmp.size()-DIGITS, j=0;i>0;i-=DIGITS, ++j){
            b.data[j] = stoll(tmp.substr(i, DIGITS));
        }
        b.data[j] = stoll(tmp.substr(0, i+DIGITS));
        return in;
    }
};
template<size_t len>
struct id16{
    unsigned int data[len];
    static constexpr unsigned int bits = 31;
    id16(){memset(data, 0, sizeof(data));}
    id16(long long const&_a){
        memset(data, 0, sizeof(data));
        unsigned long long a = _a;
        data[0] = a&((1u<<bits)-1);
        data[1] = a>>bits;
        data[1]&=~(1u<<bits);
        if(a>~a){
            for(size_t i=2;i<len;++i){
                data[i] = (1u<<bits)-1;
            }
        }
    }
    id16& operator+=(id16 const&o){
        unsigned int carry = 0;
        for(size_t i=0;i<len;++i){
            data[i]+=o.data[i] + carry;
            carry = data[i]>>bits;
            data[i]&=~(1u<<bits);
        }
        return *this;
    }
    id16& operator-=(id16 const&o){
        unsigned int carry = 0;
        for(size_t i=0;i<len;++i){
            data[i]-=o.data[i] + carry;
            carry = data[i]>>bits;
            data[i]&=~(1u<<bits);
        }
        return *this;
    }
    id16 operator+(id16 const&o)const{
        id16 ret(*this);
        ret+=o;
        return ret;
    }
    id16 operator-(id16 const&o)const{
        id16 ret(*this);
        ret-=o;
        return ret;
    }
    void multo(id16 const&o, id16 &ret)const{
        static unsigned int tmp[len+1];
        memset(tmp, 0, sizeof(tmp));
        for(size_t i=0;i<len;++i){
            unsigned long long val = 0;
            for(size_t j=0;j<len-i;++j){
                val+= data[i]*(unsigned long long)o.data[j]+tmp[i+j];
                tmp[i+j] = val&((1u<<bits)-1);
                val>>=bits;
            }
        }
        memcpy(ret.data, tmp, sizeof(ret.data));
    }
    id16& operator*=(id16 const&o){
        multo(o, *this);
        return *this;
    }
    id16 operator*(id16 const&o)const{
        id16 ret;
        multo(o, ret);
        return ret;
    }
    id16& negate(){
        unsigned int carry = 0;
        for(size_t i=0;i<len;++i){
            data[i] = ~data[i] + !carry;
            carry = (data[i]>>bits);
            data[i]&=~(1u<<bits);
        }
        return *this;
    }
    id16 operator-()const{
        id16 ret(*this);
        ret.negate();
        return ret;
    }
    bool operator<(id16 const&o)const{
        if(data[len-1]>>(bits-1)!=o.data[len-1]>>(bits-1)){
            return data[len-1]>>(bits-1);
        }
        for(size_t i=len-1;~i;--i){
            if(data[i]!=o.data[i]) return data[i]<o.data[i];
        }
        return false;
    }
    bool operator>(id16 const&o)const{
        return o<*this;
    }
    bool operator<=(id16 const&o)const{
        return !(operator>(o));
    }
    bool operator>=(id16 const&o)const{
        return !(operator<(o));
    }
    bool operator==(id16 const&o)const{
        for(size_t i=0;i<len;++i){
            if(data[i] !=o.data[i]) return false;
        }
        return true;
    }
    bool operator!=(id16 const&o)const{
        return !operator==(o);
    }
    bool operator!()const{
        for(size_t i=0;i<len;++i){
            if(data[i]) return false;
        }
        return true;
    }
    bool is_negative()const{
        return data[len-1]>>(bits-1);
    }
    void print_binary(ostream&o, id16 const&b){
        o << "[";
        for(size_t i=len;i>0;--i){
            o << bitset<bits>(b.data[i-1]);
        }
        o << "]";
    }
    friend ostream& operator<<(ostream&o, id16 const&b){
        if(b.is_negative()){
            return o << '-' << -b << "\n";
        }
        id12 ret(0);
        int64_t base = 1u<<bits;
        for(int i = len-1;i>=0;--i){
            ret*=base;
            ret+=id12(b.data[i]);
        }
        o << ret;
        return o;
    }
    explicit operator long double()const{
        if(is_negative()){
            return (long double)operator-();
        }
        long double ret = 0.0;
        long double base = 1u<<bits;
        for(int i = len-1;i>=0;--i){
            ret = ret * base + data[i];
        }
        return ret;
    }
    friend istream& operator>>(istream&i, id16 &b){
        int64_t tmp;
        i >> tmp;
        b = id16(tmp);
        return i;
    }
};
template<size_t len>
struct id15{
    unsigned int data[len];
    uint16_t siz;
    bool sign;
    static constexpr unsigned int bits = 32;
    id15(){
        data[0] = 0;
        siz = 1;
        sign = false;
    }
    id15(long long a){
        sign = false;
        if(a<0){
            sign = true;
            a=-a;
        }
        siz = 0;
        do{
            long long b = a>>bits;
            data[siz] = a - (b<<bits);
            a = b;
            ++siz;
        } while(a);
    }
    void trim(){
        while(siz>1 && !data[siz-1]) --siz;
    }
    int comp_unsigned(id15 const&o)const{
        uint16_t lim = min(siz, o.siz);
        for(unsigned int i=lim;i<siz;++i){
            if(data[i]){
                return 1;
            }
        }
        for(unsigned int i=lim;i<o.siz;++i){
            if(o.data[i]){
                return -1;
            }
        }
        for(unsigned int i=lim-1;i+1;--i){
            if(data[i]!=o.data[i]){
                return data[i] < o.data[i]?-1:1;
            }
        }
        return 0;
    }
    int comp(id15 const&o)const{
        int sign_mul = 1-2*sign;
        if(sign != o.sign){
            return sign_mul;
        }
        return sign_mul * comp_unsigned(o);
    }
    bool operator<(id15 const&o)const{
        return comp(o)<0;
    }
    bool operator>(id15 const&o)const{
        return comp(o)>0;
    }
    bool operator<=(id15 const&o)const{
        return comp(o)<=0;
    }
    bool operator>=(id15 const&o)const{
        return comp(o)>=0;
    }
    bool operator==(id15 const&o)const{
        return comp(o)==0;
    }
    bool operator!=(id15 const&o)const{
        return comp(o)!=0;
    }
    bool operator!()const{
        return operator==(ZERO);
    }
    id15 operator-()const{
        id15 ret(*this);
        if(!!ret){
            ret.sign ^=1;
        }
        return ret;
    }
    id15 operator*(id15 const&o)const{
        id15 ret;
        ret.siz = min(siz+o.siz, (int)len);
        ret.sign = (sign!=o.sign);
        fill(ret.data, ret.data+ret.siz, 0);
        for(unsigned int i=0;i<siz;++i){
            unsigned long long carry = 0, id7;
            for(unsigned int j=0;j<o.siz;++j){
                carry+= data[i]*(unsigned long long)o.data[j] + ret.data[i+j];
                id7 = carry >> bits;
                ret.data[i+j] = carry - (id7<<bits);
                carry = id7;
            }
            for(unsigned int j=i+o.siz;carry;++j){
                carry+= ret.data[j];
                id7 = carry >> bits;
                ret.data[j] = carry - (id7<<bits);
                carry = id7;
            }
        }
        ret.trim();
        return ret;
    }
    id15& operator*=(id15 const&o){
        *this = operator*(o);
        return *this;
    }
    static void unsigned_add(id15 &ret, id15 const&A, id15 const&B){
        const id15 *a = &A, *b = &B;
        if(a->siz < b->siz) swap(a, b);
        ret.sign = A.sign;
        unsigned long long carry = 0, id7;
        unsigned int j;
        for(j=0;j<b->siz;++j){
            carry+=(unsigned long long)a->data[j] + (unsigned long long)b->data[j];
            id7 = carry>>bits;
            ret.data[j] = carry - (id7<<bits);
            carry = id7;
        }
        for(;j<a->siz;++j){
            carry+=a->data[j];
            id7 = carry>>bits;
            ret.data[j] = carry - (id7<<bits);
            carry = id7;
        }
        if(carry){
            ret.data[j++] = carry;
        }
        ret.siz = j;
        ret.trim();
    }
    static void unsigned_subtract(id15 &ret, id15 const&A, id15 const&B){
        int com = A.comp_unsigned(B);
        if(com == 0){
            ret.sign = false;
            ret.siz = 1;
            ret.data[0] = 0;
            return;
        }
        ret.sign = A.sign;
        const id15 *a = &A, *b = &B;
        if(com < 0){
            ret.sign ^= true;
            swap(a, b);
        }
        unsigned int id9 = min(A.siz, B.siz);
        unsigned long long carry = 0, id7;
        unsigned int j;
        for(j=0;j<id9;++j){
            carry+=(unsigned long long)a->data[j] - (unsigned long long)b->data[j];
            id7 = carry>>bits;
            ret.data[j] = carry - (id7<<bits);
            carry = -(id7 & 1u);
        }
        for(;carry;++j){

            carry+=a->data[j];
            id7 = carry>>bits;
            ret.data[j] = carry - (id7<<bits);
            carry = -(id7 & 1u);
        }
        copy(a->data+j, a->data+a->siz, ret.data+j);
        ret.siz = a->siz;
        ret.trim();
    }
    static void add(id15 &ret, id15 const&A, id15 const&B){
        if(A.sign == B.sign){
            unsigned_add(ret, A, B);
        } else {
            unsigned_subtract(ret, A, B);
        }
    }
    static void sub(id15 &ret, id15 const&A, id15 const&B){
        if(A.sign != B.sign){
            unsigned_add(ret, A, B);
        } else {
            unsigned_subtract(ret, A, B);
        }
    }
    id15 operator+(id15 const&o)const{
        id15 ret;
        add(ret, *this, o);
        return ret;
    }
    id15& operator+=(id15 const&o){
        add(*this, *this, o);
        return *this;
    }
    id15 operator-(id15 const&o)const{
        id15 ret;
        sub(ret, *this, o);
        return ret;
    }
    id15 operator-=(id15 const&o){
        sub(*this, *this, o);
        return *this;
    }
    void print_binary(ostream&o, id15 const&b){
        o << "[";
        o << sign << "/" << len << "/";
        for(size_t i=siz;i>0;--i){
            o << bitset<bits>(b.data[i-1]);
        }
        o << "]";
    }
    friend ostream& operator<<(ostream&o, id15 const&b){
        if(b.sign){
            return o << '-' << -b;
        }
        id12 ret(0);
        int64_t base = 1ll<<bits;
        for(int i = b.siz-1;i>=0;--i){
            ret*=base;
            ret+=id12(b.data[i]);
        }
        o << ret;
        return o;
    }
    explicit operator long double()const{
        if(sign){
            return (long double)operator-();
        }
        long double ret = 0.0;
        long double base = 1ll<<bits;
        for(int i = siz-1;i>=0;--i){
            ret = ret * base + data[i];
        }
        return ret;
    }
    friend istream& operator>>(istream&i, id15 &b){
        int64_t tmp;
        i >> tmp;
        b = id15(tmp);
        return i;
    }
    static const id15 ZERO;
};
template<size_t len>
const id15<len> id15<len>::ZERO(0);
template<typename FLOAT>
class Lp_Seidel{
private:
    vector<FLOAT> proj_down(vector<FLOAT> const&vec, vector<FLOAT> const&plane, size_t j){



        vector<FLOAT> ret (vec.size()-1);
        if(plane[j] < FLOAT(0)){
            for(size_t i=0;i+1<vec.size();++i){
                ret[i] = vec[j] * plane[i+(i>=j)] - vec[i+(i>=j)]* plane[j];
            }
        } else {
            for(size_t i=0;i+1<vec.size();++i){
                ret[i] = vec[i+(i>=j)]*plane[j] - vec[j]*plane[i+(i>=j)];
            }
        }
        return ret;
    }
    vector<FLOAT> proj_up(vector<FLOAT> const&vec, vector<FLOAT> const&plane, size_t j){



        vector<FLOAT> ret(vec.size()+1);
        copy(vec.begin(), vec.begin()+j, ret.begin());
        copy(vec.begin()+j, vec.end(), ret.begin()+j+1);
        for(size_t i=0;i<vec.size();++i){
            ret[j]+=vec[i]*plane[i+(i>=j)];
        }
        FLOAT denom = plane[j];
        if(denom < FLOAT(0)){
            denom = -denom;
        }
        for(size_t i=0;i<vec.size();++i){
            ret[i+(i>=j)]*=denom;
        }
        if(plane[j] >= FLOAT(0)){
            ret[j] = -ret[j];
        }
        return ret;
    }
    FLOAT planescal(vector<FLOAT> const&x, vector<FLOAT> const&a){

        FLOAT ret=0;
        for(size_t i=0;i<x.size();++i){
            ret+=x[i]*a[i];
        }
        return ret;
    }
    vector<FLOAT> solve(vector<vector<FLOAT> > const &A, vector<FLOAT> const&c, int d, FLOAT const& id6){
        int n=A.size();
        if(d==1){
            vector<FLOAT> ret(2);
            ret[0] = (c[0]<FLOAT(0) ? -id6 : id6);
            ret[1] = 1ull;
            for(int i=0;i<n;++i){
                if(ret[0]*A[i][0]+ret[1]*A[i].back()>FLOAT(0)){
                    if(!A[i][0]){
                        do{}while(0);
                        return vector<FLOAT>();
                    }
                    ret[0] = -A[i].back();
                    ret[1] = A[i][0];
                    if(ret[1] < FLOAT(0)){
                        ret[1] = -ret[1];
                        ret[0] = -ret[0];
                    }
                    do{}while(0);
                }
            }
            for(int i=0;i<n;++i){
                if(ret[0]*A[i][0]+ret[1]*A[i].back()>FLOAT(0)){
                    do{}while(0);
                    return vector<FLOAT>();
                }
            }
            return ret;
        }
        FLOAT id5 = id6 * id6;
        vector<FLOAT> x(d+1);
        for(int i=0;i<d;++i){
            x[i] = (c[i]<FLOAT(0)?-id6:id6);
        }
        x.back() = FLOAT(1);
        for(size_t i=0;i<A.size();++i){
            if(planescal(x, A[i])>FLOAT(0)){
                int k = 0;
                while(k<d && !A[i][k]) ++k;
                if(k==d) {do{}while(0); return vector<FLOAT>();}
                vector<vector<FLOAT> > A2(i);
                for(size_t j=0;j<A2.size();++j){
                    A2[j] = proj_down(A[j], A[i], k);
                }
                shuffle(A2.begin(), A2.end(), Rng::get_engine());
                do{}while(0);
                vector<FLOAT> c2 = proj_down(c, A[i], k);
                vector<FLOAT> x2 = solve(A2, c2, d-1, id5);
                if(x2.empty()) return x2;
                x = proj_up(x2, A[i], k);
                do{}while(0);
                do{}while(0);
                do{}while(0);
            }
        }
        return x;
    }
public:
    vector<FLOAT> solve(vector<vector<FLOAT> > const &A, vector<FLOAT> const&c, const FLOAT& barier = FLOAT((long long)1e9)){

        return solve(A, c, c.size(), barier);
    }
    vector<FLOAT> solve(vector<vector<FLOAT> > A, vector<FLOAT> const&b, vector<FLOAT> const&c){

        for(unsigned int i=0;i<A.size();++i){
            A[i].push_back(-b[i]);
        }
        return solve(A, c);
    }
};
template<typename Big_Int>
class Lp_Clarkson{
private:
    vector<int> sample_subset(vector<int64_t> const&weight, unsigned int siz){
        int64_t total_weight = accumulate(weight.begin(), weight.end(), 0ll);
        vector<int64_t> samples;
        while(samples.size() < siz){
            int64_t new_sample = Rng::uniform<int64_t>(0, total_weight-1);
            if(find(samples.begin(), samples.end(), new_sample) == samples.end()){
                samples.push_back(new_sample);
            }
        }
        sort(samples.begin(), samples.end());
        vector<int> ret;
        int64_t left_weight = 0;
        for(unsigned int i=0, j=0;i<weight.size() && j<samples.size();){
            if(samples[j] < left_weight + weight[i]){
                ret.push_back(i);
                ++j;
            } else {
                left_weight+=weight[i];
                ++i;
            }
        }
        return ret;
    }
    bool is_satisfied(vector<Big_Int> const&x, vector<Big_Int> const&a){

        Big_Int ret=0;
        for(size_t i=0;i<x.size();++i){
            ret+=x[i]*a[i];
        }
        return ret <= Big_Int(0);
    }
    vector<Big_Int> solve(vector<vector<Big_Int> > const&A, vector<Big_Int> const&c, const unsigned int sample_size){
        Lp_Seidel<Big_Int> sub_lp;
        if(A.size() < sample_size){
            return sub_lp.solve(A, c);
        } else {
            int equations = A.size();
            int variables = c.size();
            vector<int64_t> weight(equations, 1);
            vector<Big_Int> x;
            vector<vector<Big_Int> > id13;
            vector<char> id18(equations, 0);
            for(unsigned int iteration=1;;++iteration){
                id13.clear();
                vector<int> subspace = sample_subset(weight, sample_size);
                for(int const&e:subspace){
                    id13.push_back(A[e]);
                }
                x = sub_lp.solve(id13, c);
                if(x.empty()){
                    return x;
                }
                int64_t id10 = 0;
                for(int i=0;i<equations;++i){
                    id18[i] = !is_satisfied(x, A[i]);
                    if(id18[i]){
                        id10+=weight[i];
                    }
                }
                if(id10 == 0){
                    cerr << "Iterations: " << iteration;
                    cerr << ", max weight: " << *max_element(weight.begin(), weight.end()) << "\n";
                    break;
                }
                if(id10*3*variables <= accumulate(weight.begin(), weight.end(), 0ll)){
                    for(int i=0;i<equations;++i){
                        if(id18[i]){
                            weight[i]*=2;
                        }
                    }

                }
            }
            return x;
        }
    }
public:
    vector<Big_Int> solve(vector<vector<Big_Int> > const&A, vector<Big_Int> const&c){
        return solve(A, c, c.size()*c.size()*4);
    }
    vector<Big_Int> solve(vector<vector<Big_Int> > A, vector<Big_Int> const&b, vector<Big_Int> const&c){

        for(unsigned int i=0;i<A.size();++i){
            A[i].push_back(-b[i]);
        }
        return solve(A, c);
    }
};
template<typename Big_Int>
void id11(unsigned int n, bool debug = false){
    std::cout << "Computing " << n << "!\n";
    Big_Int val(1);
    for(unsigned int i=1;i<=n;++i){
        val*=i;
        if(debug)
            std::cerr << i << " : " << val << "\n";
    }
    std::cerr << "Printing\n";
    std::cout << val << endl;
}
template<typename Big_Int>
void id0(int n){
    Big_Int a(5432123456789ll);
    Big_Int b(9876543210123ll);
    Big_Int c;
    for(int it=0;it<4*n;++it){
        std::cout << a << " + " << b << " = " << a+b << "\n";
        std::cout << b << " + " << a << " = " << b+a << "\n";
        std::cout << a << " - " << b << " = " << a-b << "\n";
        std::cout << b << " - " << a << " = " << b-a << "\n";
        c = a; c+=b;
        std::cout << a << " + " << b << " = " << c << "\n";
        c = b; c+=a;
        std::cout << b << " + " << a << " = " << c << "\n";
        c = a; c-=b;
        std::cout << a << " - " << b << " = " << c << "\n";
        c = b; c-=a;
        std::cout << b << " - " << a << " = " << c << "\n";
        a=-a;
        if(it%4 == 3){
            a*=it;
        } else {
            swap(a, b);
        }
    }
}
template<typename Big_Int>
void id8(int n, int k){
    std::cout << "Addmul test " << n << " " << k << "\n";;
    Rng::set_seed(635241);
    Big_Int ret(0);
    for(int i=0;i<n;++i){
        Big_Int cur(1);
        for(int j=0;j<k;++j){
            Big_Int mu(Rng::uniform(1ll, (long long)1e15));
            cur*=mu;
        }
        ret+=cur;
    }
    std::cout << ret << "\n";
}
void test_timer(){
    std::function<int64_t(int64_t)> fib = [&](int64_t x){return x<2?x:fib(x-1)+fib(x-2);};
    Timer::id1<int64_t>(fib, "Timer test", 35);
    Timer::id1<int64_t>(fib, "Timer test", 40);
}
template<typename Big_Int, typename Solver>
void test_lp(std::string const&path){
    std::cerr << "LP Test: " << path << "\n";
    std::ifstream in;
    in.open(path.c_str());
    int variables, constraints;
    in >> variables >> constraints;
    std::vector<std::vector<Big_Int> > A(constraints, std::vector<Big_Int>(variables));
    std::vector<Big_Int> b(constraints), c(variables);
    for(auto &e:c) in >> e;
    for(int i=0;i<constraints;++i){
        for(auto &e:A[i]) in >> e;
        in >> b[i];
    }
    std::function<std::vector<Big_Int>()> solve = [&](){
        Solver solver;
        return solver.solve(A, b, c);
    };
    std::vector<Big_Int> solution = Timer::id1<vector<Big_Int>>(solve, "solve LP");
    std::cerr << "Solution:\n";
    for(auto &e:solution){
        std::cerr << e << " ";
    }
    cerr << "\n";
}
template<typename Big_Int, typename Solver>
void id14(int n){
    cerr << "Enclosing annulus test (" << n << ")\n";
    cerr << "Int: " << typeid(Big_Int).name()<< ", Solver: " << typeid(Solver).name() << "\n";
    Rng::set_seed(1234);
    vector<pair<int, int> > pts(n);
    for(auto &e:pts){
        e.first = Rng::uniform(-10000, 10000);
        e.second = Rng::uniform(-10000, 10000);
    }
    Rng::set_seed(24680);
    vector<vector<Big_Int> > A;
    vector<Big_Int> b, c;
    c = {Big_Int(0), Big_Int(0), -1, 1};
    for(auto const&e:pts){
        A.push_back({Big_Int(-2*e.first), Big_Int(-2*e.second), -1, 0});
        b.emplace_back(-e.first*e.first-e.second*e.second);
        A.push_back({Big_Int(2*e.first), Big_Int(2*e.second), 0, 1});
        b.emplace_back(e.first*e.first+e.second*e.second);
    }
    std::function<std::vector<Big_Int>()> solve = [&](){
        Solver solver;
        return solver.solve(A, b, c);
    };
    std::vector<Big_Int> solution = Timer::id1<vector<Big_Int>>(solve, "solve enclosing circle LP");
    std::cerr << "Solution:\n";
    for(auto &e:solution){
        std::cerr << e << " ";
    }
    cerr << "\n";
    if(!solution.empty()){
        Big_Int r_sq = solution[2]*solution[4] - solution[1]*solution[1] + solution[2]*solution[2];
        Big_Int R_sq = solution[3]*solution[4] - solution[1]*solution[1] + solution[2]*solution[2];
        Big_Int id17 = solution[3] - solution[2];
        cerr << "area^2: " << (long double)id17 / (long double)solution[4] << "\n";
        cerr << "r^2: " << (long double)r_sq / (long double)(solution[4]*solution[4]) << "\n";
        cerr << "R^2: " << (long double)R_sq / (long double)(solution[4]*solution[4]) << "\n";
    }
    cerr << "\n";
}
void id4(){
    auto id3 = [&](){
        using DOUBLE = id15<12>;
        int N, M;
        cin >> N >> M;
        vector<vector<DOUBLE> > A;
        vector<DOUBLE> b, c(4);
        A.reserve(N+M);
        vector<pair<int, int> > p2(N), p(M);
        for(int i=0;i<N;++i){
            cin >> p2[i].first >> p2[i].second;
        }
        for(int i=0;i<M;++i){
            cin >> p[i].first >> p[i].second;
        }
        for(int it=0;it<2;++it){
            N=p.size();
            M=p2.size();
            A.clear();
            b.clear();
            for(int i=0;i<N;++i){
                int x, y, z;
                tie(x, y) = p[i];
                z=x*x+y*y;
                A.push_back({x, y, 1, 1});
                b.push_back(z);
            }
            for(int i=0;i<M;++i){
                int x, y, z;
                tie(x, y) = p2[i];
                z=x*x+y*y;
                A.push_back({-x, -y, -1, 1});
                b.push_back(-z);
            }
            c[3] = 1;
            Lp_Clarkson<DOUBLE> solver;
            vector<DOUBLE> x = solver.solve(A, b, c);
            if(!x.empty()){
                DOUBLE res = 0;
                for(size_t i=0;i<c.size();++i) res+=x[i]*c[i];
                DOUBLE dist = res;
                if(dist>DOUBLE(0)){
                    cout << "YES\n";
                    return;
                }
            } else {
            }
            p.swap(p2);
        }
        cout << "NO\n";
    };
    int TTT = 1;
    while(TTT--){
        id3();
    }
}
signed id2(){
    using DOUBLE = id15<25>;
    freopen("codejam_d.in", "r", stdin);
    freopen("codejam_d.out", "w", stdout);
    cin.tie(0); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    for(int cas=1;cas<=T;++cas){
        cout << "Case 
        cerr << "Case 
        int n; cin >> n;
        vector<vector<DOUBLE> > A;
        vector<DOUBLE> b, c(4);
        A.reserve(n);
        do{}while(0);
        for(int i=0;i<n;++i){
            int x, y, z;
            cin >> x >> y >> z;
            A.push_back({x, y, z, 1});
            b.push_back(0);
        }
        c[3] = 1;
        Lp_Clarkson<DOUBLE> solver;
  vector<DOUBLE> x = solver.solve(A, b, c);
  bool did = false;
  if(!x.empty()){
            if(x[3] > DOUBLE(0)){
                did = true;
            }
  }
        if(did) cout << "NO\n";
        else cout << "YES\n";
        cerr << (did?"NO\n":"YES\n");
    }
    return 0;
}
using namespace std;
int main()
{
    id4();
    return 0;
}
