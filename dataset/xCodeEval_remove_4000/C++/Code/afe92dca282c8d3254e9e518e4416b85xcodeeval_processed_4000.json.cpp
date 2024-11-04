







using namespace __gnu_pbds;
using namespace std;






































































string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
inline void yes(){cout<<"YES\n";exit(0);}
inline void no(){cout<<"NO\n";exit(0);}
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;






void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}

const int mod=998244353;
const int N=3e5+9;
const ld eps=1e-9;
const ld PI=acos(-1.0);



















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
    typename enable_if<is_integral<T>::value, bool>::type id0(T const&x, T base){
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
    typename enable_if<is_integral<T>::value, bool>::type id2(T const&){return true;}
    template<typename T, typename... S>
    typename enable_if<is_integral<T>::value, bool>::type id2(T const&x, T const&base, S const&...bases){
        if(!id0(x, base)) return false;
        return id2(x, bases...);
    }

    template<typename T>
    typename enable_if<is_integral<T>::value, bool>::type id6(T const&x){
        if(x < 316349281) return id2(x, T(11000544), T(31481107));
        if(x < 4759123141ull) return id2(x, T(2), T(7), T(61));
        return id2(x, T(2), T(325), T(9375), T(28178), T(450775), T(9780504), T(1795265022));
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
    typename enable_if<is_integral<T>::value, T>::type id9(T const&x){
        assert(x>=T(0));
        T ret = static_cast<T>(cbrt(x));
        while(ret>0 && ret*ret*ret>x) --ret;
        while(x-ret*ret*ret>3*ret*(ret+1))
            ++ret;
        return ret;
    }
    
    vector<uint16_t> saved;
    

    

    uint64_t id3(uint64_t const&x, uint64_t const&k, uint64_t const&it_max, uint32_t id4){
        if(__gcd((uint64_t)k, x)!=1) return __gcd((uint64_t)k, x);
        

        saved.clear();
        uint64_t scaledn = k*x;
        if(scaledn>>62) return 1;
        uint32_t id7 = isqrt(scaledn);
        uint32_t cutoff = isqrt(2*id7)/id4;
        uint32_t q0 = 1;
        uint32_t p1 = id7;
        uint32_t q1 = scaledn-p1*p1;

        if(q1 == 0){
            uint64_t factor = __gcd(x, (uint64_t)p1);
            return factor==x ? 1:factor;
        }

        uint32_t multiplier = 2*k;
        uint32_t id1 = cutoff * multiplier;
        


        uint32_t i, j;
        uint32_t p0 = 0;
        uint32_t sqrtq = 0;

        for(i=0;i<it_max;++i){
            uint32_t q, bits, tmp;

            tmp = id7 + p1 - q1;
            q = 1;
            if (tmp >= q1)
                q += tmp / q1;

            p0 = q * q1 - p1;
            q0 = q0 + (p1 - p0) * q;

            if (q1 < id1) {
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
            tmp = id7 + p0 - q0;
            q = 1;
            if (tmp >= q0)
                q += tmp / q0;

            p1 = q * q0 - p0;
            q1 = q1 + (p0 - p1) * q;

            if (q0 < id1) {
                tmp = q0 / __gcd(q0, multiplier);

                if (tmp < cutoff) {
                    saved.push_back((uint16_t) tmp);
                }
            }
        }

        if(sqrtq == 1) { return 1;}
        if(i == it_max) { return 1;}

        q0 = sqrtq;
        p1 = p0 + sqrtq * ((id7 - p0) / sqrtq);
        q1 = (scaledn - (uint64_t)p1 * (uint64_t)p1) / (uint64_t)q0;

        for(j=0;j<it_max;++j) {
            uint32_t q, tmp;

            tmp = id7 + p1 - q1;
            q = 1;
            if (tmp >= q1)
                q += tmp / q1;

            p0 = q * q1 - p1;
            q0 = q0 + (p1 - p0) * q;

            if (p0 == p1) {
                q0 = q1;
                break;
            }

            tmp = id7 + p0 - q0;
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
    uint64_t id5(uint64_t const&x){
        for(uint64_t i=2;i<=min((int64_t)5000,(int64_t)x/2-1);i++){
            uint64_t p=(uint64_t)((1.0*x)/(i*1.0)+eps);
            if(p*i==x) return i;
        }
        static array<uint32_t, 16> multipliers{1, 3, 5, 7, 11, 3*5, 3*7, 3*11, 5*7, 5*11, 7*11, 3*5*7, 3*5*11, 3*7*11, 5*7*11, 3*5*7*11};

        uint64_t id8 = id9(x);
        if(id8*id8*id8 == x) return id8;
        uint64_t sqrt_x = isqrt(x);
        if(sqrt_x*sqrt_x == x) return sqrt_x;

        

        uint32_t iter_lim = 300;
        for(uint32_t iter_fact = 1;iter_fact<20000;iter_fact*=4){
            for(uint32_t const&k : multipliers){
                if(numeric_limits<uint64_t>::max()/k<=x) continue; 

                uint32_t const it_max = iter_fact*iter_lim;
                uint64_t factor = id3(x, k, it_max, 1);
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
    typename enable_if<is_integral<T>::value, vector<T>>::type id10(T x){
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
                if(!id6(x)){
                    T factor = id5(x);
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

using ll = int64_t;

unordered_map<ll,ll>mp;
int main()
{
    fast;
    ll i,j,k,n,m,x;
    cin>>n;
    ll ans=1;
    for(i=1;i<=n;i++){
        cin>>x;
        auto v=NT::factorize(x);
        for(auto x:v) mp[x]++;
    }
    for(auto x:mp) ans=ans*(x.S+1)%mod;
    cout<<ans<<nl;
    cout.flush();
    return 0;
}