
































template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}


template<typename T, typename U> static inline void amin(T &x, U y) { 
    if (y < x) 
        x = y; 
}

template<typename T, typename U> static inline void amax(T &x, U y) { 
    if (x < y) 
        x = y; 
}

template<typename T,typename U> std::ostream& operator<<(std::ostream& out, std::pair<T,U> a) {
    out<<a.fi<<" "<<a.se;
    return out;
}

template<typename T,typename U> std::istream& operator>>(std::istream& in, std::pair<T,U> &a) {
    in>>a.fi>>a.se;
    return in;
}

inline long long toint(const std::string &s) {std::stringstream ss; ss << s; long long x; ss >> x; return x;}
inline std::string tostring(long long number) {std::stringstream ss; ss << number; return ss.str();}
inline std::string tobin(long long x) {return std::bitset<63>(x).to_string();}

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());



























using namespace std;
using namespace __gnu_pbds;

namespace NT{
    template<typename T>
    struct bigger_type{};
    template<typename T> using bigger_type_t = typename bigger_type<T>::type;
    template<> struct bigger_type<int>{using type = long long;};
    template<> struct bigger_type<unsigned int>{using type = unsigned long long;};
    

    

 
    template<typename int_t = unsigned long long>
    struct Mod_Int{
        static inline int_t add(int_t const&a, int_t const&b, int_t const&mod){
            int_t ret = a+b;
            if(ret>=mod) ret-=mod;
            return ret;
        }
        static inline int_t sub(int_t const&a, int_t const&b, int_t const&mod){
            return add(a, mod-b);
        }
        static inline int_t mul(int_t const&a, int_t const&b, int_t const&mod){
            uint64_t ret = a * (uint64_t)b - (uint64_t)((long double)a * b / mod - 1.1) * mod;
            if(-ret < ret){
                ret = mod-1-(-ret-1)%mod;
            } else {
                ret%=mod;
            }
                
            

            int64_t out = ret;
            
            return out;
            

        }
        static inline int_t pow(int_t const&a, int_t const&b, int_t const&mod){
            int_t ret = 1;
            int_t base = a;
            for(int i=0;b>>i;++i){
                if((b>>i)&1) ret = mul(ret, base, mod);
                base = mul(base, base, mod);
            }
            return ret;
        }
    };
 
    template<typename T>
    typename enable_if<is_integral<T>::value, bool>::type is_prime(T x){
        if(x<T(4)) return x>T(1);
        for(T i=2;i*i<=x;++i){
            if(x%i == 0) return false;
        }
        return true;
    }
 
    template<typename T>
    typename enable_if<is_integral<T>::value, bool>::type id6(T const&x, T base){
        if(x<T(4)) return x>T(1);
        if(x%2 == 0) return false;
        base%=x;
        if(base == 0) return true;
 
        T xm1 = x-1;
        int j = 1;
        T d = xm1/2;
        while(d%2 == 0){ 

            d/=2;
            ++j;
        }
        T t = Mod_Int<T>::pow(base, d, x);
        if(t==T(1) || t==T(xm1)) return true;
        for(int k=1;k<j;++k){
            t = Mod_Int<T>::mul(t, t, x);
            if(t == xm1) return true;
            if(t<=1) break;
        }
        return false;
    }
 
    template<typename T>
    typename enable_if<is_integral<T>::value, bool>::type id9(T const&){return true;}
    template<typename T, typename... S>
    typename enable_if<is_integral<T>::value, bool>::type id9(T const&x, T const&base, S const&...bases){
        if(!id6(x, base)) return false;
        return id9(x, bases...);
    }
 
    template<typename T>
    typename enable_if<is_integral<T>::value, bool>::type id1(T const&x){
        if(x < 316349281) return id9(x, T(11000544), T(31481107));
        if(x < 4759123141ull) return id9(x, T(2), T(7), T(61));
        return id9(x, T(2), T(325), T(9375), T(28178), T(450775), T(9780504), T(1795265022));
    }
 
    template<typename T>
    typename enable_if<is_integral<T>::value, T>::type isqrt(T const&x){
        assert(x>=T(0));
        T ret = static_cast<T>(sqrtl(x));
        while(ret>0 && ret*ret>x) --ret;
        while(x-ret*ret>2*ret)
            ++ret;
        return ret;
    }
    template<typename T>
    typename enable_if<is_integral<T>::value, T>::type id10(T const&x){
        assert(x>=T(0));
        T ret = static_cast<T>(cbrt(x));
        while(ret>0 && ret*ret*ret>x) --ret;
        while(x-ret*ret*ret>3*ret*(ret+1))
            ++ret;
        return ret;
    }
    
    vector<uint16_t> saved;
    

    

    uint64_t id0(uint64_t const&x, uint64_t const&k, uint64_t const&it_max, uint32_t id8){
        if(__gcd((uint64_t)k, x)!=1) return __gcd((uint64_t)k, x);
        

        saved.clear();
        uint64_t scaledn = k*x;
        if(scaledn>>62) return 1;
        uint32_t id4 = isqrt(scaledn);
        uint32_t cutoff = isqrt(2*id4)/id8;
        uint32_t q0 = 1;
        uint32_t p1 = id4;
        uint32_t q1 = scaledn-p1*p1;
 
        if(q1 == 0){
            uint64_t factor = __gcd(x, (uint64_t)p1);
            return factor==x ? 1:factor;
        }
 
        uint32_t multiplier = 2*k;
        uint32_t id7 = cutoff * multiplier;
        

 
        uint32_t i, j;
        uint32_t p0 = 0;
        uint32_t sqrtq = 0;
 
        for(i=0;i<it_max;++i){
            uint32_t q, bits, tmp;
 
            tmp = id4 + p1 - q1;
            q = 1;
            if (tmp >= q1)
                q += tmp / q1;
 
            p0 = q * q1 - p1;
            q0 = q0 + (p1 - p0) * q;
 
            if (q1 < id7) {
                tmp = q1 / __gcd(q1, multiplier);
 
                if (tmp < cutoff) {
                    saved.push_back((uint16_t)tmp);
                }
            }
 
            bits = 0;
            tmp = q0;
            while(!(tmp & 1)) {
                bits++;
                tmp >>= 1;
            }
            if (!(bits & 1) && ((tmp & 7) == 1)) {
 
                sqrtq = (uint32_t)isqrt(q0);
 
                if (sqrtq * sqrtq == q0) {
                    for(j=0;j<saved.size();++j){
                        if(saved[j] == sqrtq) break;
                    }
                    if(j == saved.size()) break;
                    

                }
            }
            tmp = id4 + p0 - q0;
            q = 1;
            if (tmp >= q0)
                q += tmp / q0;
 
            p1 = q * q0 - p0;
            q1 = q1 + (p0 - p1) * q;
 
            if (q0 < id7) {
                tmp = q0 / __gcd(q0, multiplier);
 
                if (tmp < cutoff) {
                    saved.push_back((uint16_t) tmp);
                }
            }
        }
 
        if(sqrtq == 1) { return 1;}
        if(i == it_max) { return 1;}
 
        q0 = sqrtq;
        p1 = p0 + sqrtq * ((id4 - p0) / sqrtq);
        q1 = (scaledn - (uint64_t)p1 * (uint64_t)p1) / (uint64_t)q0;
 
        for(j=0;j<it_max;++j) {
            uint32_t q, tmp;
 
            tmp = id4 + p1 - q1;
            q = 1;
            if (tmp >= q1)
                q += tmp / q1;
 
            p0 = q * q1 - p1;
            q0 = q0 + (p1 - p0) * q;
 
            if (p0 == p1) {
                q0 = q1;
                break;
            }
 
            tmp = id4 + p0 - q0;
            q = 1;
            if (tmp >= q0)
                q += tmp / q0;
 
            p1 = q * q0 - p0;
            q1 = q1 + (p0 - p1) * q;
 
            if (p0 == p1)
                break;
        }
        if(j==it_max) {cerr << "RNG\n"; return 1;} 

 
        uint64_t factor = __gcd((uint64_t)q0, x);
        if(factor == x) factor=1;
        return factor;
    }
    uint64_t id3(uint64_t const&x){
        static array<uint32_t, 16> multipliers{1, 3, 5, 7, 11, 3*5, 3*7, 3*11, 5*7, 5*11, 7*11, 3*5*7, 3*5*11, 3*7*11, 5*7*11, 3*5*7*11};
 
        uint64_t id5 = id10(x);
        if(id5*id5*id5 == x) return id5;
 
        

        uint32_t iter_lim = 300;
        for(uint32_t iter_fact = 1;iter_fact<20000;iter_fact*=4){
            for(uint32_t const&k : multipliers){
                if(numeric_limits<uint64_t>::max()/k<=x) continue; 

                uint32_t const it_max = iter_fact*iter_lim;
                uint64_t factor = id0(x, k, it_max, 1);
                if(factor==1 || factor==x) continue;
                return factor;
            }
        }
        cerr << "failed to factor: " << x << "\n";
        assert(0);
        assert(0);
        return 1;
    }
 
    template<typename T>
    typename enable_if<is_integral<T>::value, vector<T>>::type id11(T x){
        vector<T> ret;
        while(x%2 == 0){
            x/=2;
            ret.push_back(2);
        }
        for(uint32_t i=3;i*(T)i <= x;i+=2){
            while(x%i == 0){
                x/=i;
                ret.push_back(i);
            }
        }
        if(x>1) ret.push_back(x);
        return ret;
    }
 
    template<typename T>
    typename enable_if<is_integral<T>::value, vector<T>>::type factorize(T x){
        

        vector<T> ret;
        const uint32_t trial_limit = 5000;
        auto trial = [&](uint32_t const&i){
            while(x%i == 0){
                x/=i;
                ret.push_back(i);
            }
        };
        trial(2);
        trial(3);
        for(uint32_t i=5, j=2;i<trial_limit && i*i <= x;i+=j, j=6-j){
            trial(i);
        }
        if(x>1){
            static stack<T> s;
            s.push(x);
            while(!s.empty()){
                x = s.top(); s.pop();
                if(!id1(x)){
                    T factor = id3(x);
                    if(factor == 1 || factor == x){assert(0); return ret;}
                    

                    s.push(factor);
                    s.push(x/factor);
                } else {
                    ret.push_back(x);
                }
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
}
void id2()
{
    int n;
    cin>>n;
    map<int,int> cntw,cnth,timesw,timesh;
    map<int,map<int,int>> ww,hh;
    int w[n],h[n],c[n];
    for (int i = 0; i < n; ++i) {
        cin>>w[i]>>h[i]>>c[i];
        cntw[w[i]]+=c[i];
        cnth[h[i]]+=c[i];
        ww[w[i]][h[i]]+=c[i];
        hh[h[i]][w[i]]+=c[i];
    }
    int sigmac=accumulate(c,c+n,0ll);
    int g=0;
    for(auto u:cntw){
        g=__gcd(g,u.se);
    }
    int p=0,q=0;
    for(auto u:cntw){
        p+=u.se/g;
        timesw[u.fi]=u.se/g;
    }
    g=0;
    for(auto u:cnth){
        g=__gcd(g,u.se);
    }
    for(auto u:cnth){
        q+=u.se/g;
        timesh[u.fi]=u.se/g;
    }
    for(auto &u:ww){
        int st=u.se.begin()->fi;
        int rat=u.se[st]/timesh[st];
        for(auto x:u.se){
            if(x.se%timesh[x.fi]){
                cout<<0;
                return;
            }else if(x.se/timesh[x.fi]!=rat){
                cout<<0<<endl;return;
            }
        }
    }
    for(auto &u:hh){
        int st=u.se.begin()->fi;
        int rat=u.se[st]/timesw[st];
        for(auto x:u.se){
            if(x.se%timesw[x.fi]){
                cout<<0;
                return;
            }else if(x.se/timesw[x.fi]!=rat){
                cout<<0<<endl;return;
            }
        }
    }
    if(p>sigmac/q){
        cout<<0<<endl;
        return;
    }
    if(sigmac%(p*q)){
        cout<<0<<endl;
        return ;
    }
    auto factorization=NT::factorize(sigmac/(p*q));
    sort(all(factorization));
    int cnt=1;
    for (int i = 0; i < sz(factorization);) {
        int j;
        for (j = i; j < sz(factorization); ++j) {
            if(factorization[i]!=factorization[j])break;
        }
        cnt*=(j-i+1);
        i=j;
    }
    cout<<cnt; 
}
signed main()
{
    FAST;
    int testcases=1;
    

    for(int i=0;i<testcases;++i)
    {
        id2();
    }
    cerr<<endl<<"Time Elasped : "<<elasped_time<<endl;
    return 0;
}