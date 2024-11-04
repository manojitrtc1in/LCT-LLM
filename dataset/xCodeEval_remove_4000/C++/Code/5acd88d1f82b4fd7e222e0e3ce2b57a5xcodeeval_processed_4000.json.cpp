










using namespace std;


using namespace __gnu_pbds;
template <typename T,typename R>
using os = tree<pair<T,R>, null_type, less<pair<T,R>>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long  ll;
typedef long double ld;

















template <typename T, size_t N> int SIZE(const T (&t)[N]){ return N; } template<typename T> int SIZE(const T &t){ return t.size(); } string to_string(const string s, int x1=0, int x2=1e9){ return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c){ return string({c}); } template<size_t N> string to_string(const bitset<N> &b, int x1=0, int x2=1e9){ string t = ""; for(int id7 = min(x1,SIZE(b)),  id6 = min(x2, SIZE(b)-1); id7 <= id6; ++id7){ t += b[id7] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1=0, int x2=1e9, C... coords); int id1 = 0, id3 = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { id1++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; id1--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(id3, ' '); string res = ""; bool first = true; if(id1 == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; id1++; if(e != l){ if(rnk > 1) { res += n_l; id3 = id1; }; } else{ id3 = 0; } res += to_string(*e, coords...); id1--; } res += "]"; if(id1 == 0) res += n_l; return res; } void dbgm(){;} template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgm(T...); }

clock_t time_p=clock();
std::istream& in(std::cin);
std::ostream& ot(std::cout);
 
void Auriel()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
 
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t id5 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id5);
    }
};
template <typename  R>
void println(R r){
    for(auto i:r)
        cout<<i<<" ";
    cout<<endl;
 
}
template <typename  R>
void print(R r){
    int e=0;
    for(auto i:r)
        cout<<i<<endl;
}
template <typename R>
void id4(R &r){
    for(auto &i:r)
        cin>>i;
}




 




template <typename T>
T inverse(T a, T m) {
   T u = 0, v = 1;
   while (a != 0) {
       T t = m / a;
       m -= t * a;
       swap(a, m);
       u -= t * v;
       swap(u, v);
   }
   assert(m == 1);
   return u;
}
 
template <typename T>
class Modular {
public:
   using Type = typename decay<decltype(T::value)>::type;
 
   constexpr Modular() : value() {}
   template <typename U>
   Modular(const U& x) {
       value = normalize(x);
   }
 
   template <typename U>
   static Type normalize(const U& x) {
       Type v;
       if (-mod() <= x && x < mod())
           v = static_cast<Type>(x);
       else
           v = static_cast<Type>(x % mod());
       if (v < 0) v += mod();
       return v;
   }
 
   const Type& operator()() const { return value; }
   template <typename U>
   explicit operator U() const {
       return static_cast<U>(value);
   }
   constexpr static Type mod() { return T::value; }
 
   Modular& operator+=(const Modular& other) {
       if ((value += other.value) >= mod()) value -= mod();
       return *this;
   }
   Modular& operator-=(const Modular& other) {
       if ((value -= other.value) < 0) value += mod();
       return *this;
   }
   template <typename U>
   Modular& operator+=(const U& other) {
       return *this += Modular(other);
   }
   template <typename U>
   Modular& operator-=(const U& other) {
       return *this -= Modular(other);
   }
   Modular& operator++() { return *this += 1; }
   Modular& operator--() { return *this -= 1; }
   Modular operator++(int) {
       Modular result(*this);
       *this += 1;
       return result;
   }
   Modular operator--(int) {
       Modular result(*this);
       *this -= 1;
       return result;
   }
   Modular operator-() const { return Modular(-value); }
 
   template <typename U = T>
   typename enable_if<is_same<typename Modular<U>::Type, int>::value,
           Modular>::type&
   operator*=(const Modular& rhs) {

       uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
   uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x),
            d, m;
   asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(mod()));
   value = m;

       value = normalize(static_cast<int64_t>(value) *
                         static_cast<int64_t>(rhs.value));

       return *this;
   }
   template <typename U = T>
   typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value,
           Modular>::type&
   operator*=(const Modular& rhs) {
       int64_t q = static_cast<int64_t>(static_cast<long double>(value) *
                                        rhs.value / mod());
       value = normalize(value * rhs.value - q * mod());
       return *this;
   }
   template <typename U = T>
   typename enable_if<!is_integral<typename Modular<U>::Type>::value,
           Modular>::type&
   operator*=(const Modular& rhs) {
       value = normalize(value * rhs.value);
       return *this;
   }
 
   Modular& operator/=(const Modular& other) {
       return *this *= Modular(inverse(other.value, mod()));
   }
 
   template <typename U>
   friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
 
   template <typename U>
   friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
 
   template <typename U>
   friend std::istream& operator>>(std::istream& stream, Modular<U>& number);
 
private:
   Type value;
};
 
template <typename T>
bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) {
   return lhs.value == rhs.value;
}
template <typename T, typename U>
bool operator==(const Modular<T>& lhs, U rhs) {
   return lhs == Modular<T>(rhs);
}
template <typename T, typename U>
bool operator==(U lhs, const Modular<T>& rhs) {
   return Modular<T>(lhs) == rhs;
}
 
template <typename T>
bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) {
   return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(const Modular<T>& lhs, U rhs) {
   return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(U lhs, const Modular<T>& rhs) {
   return !(lhs == rhs);
}
 
template <typename T>
bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) {
   return lhs.value < rhs.value;
}
 
template <typename T>
Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) {
   return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(const Modular<T>& lhs, U rhs) {
   return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T>& rhs) {
   return Modular<T>(lhs) += rhs;
}
 
template <typename T>
Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) {
   return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(const Modular<T>& lhs, U rhs) {
   return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T>& rhs) {
   return Modular<T>(lhs) -= rhs;
}
 
template <typename T>
Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) {
   return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(const Modular<T>& lhs, U rhs) {
   return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T>& rhs) {
   return Modular<T>(lhs) *= rhs;
}
 
template <typename T>
Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) {
   return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(const Modular<T>& lhs, U rhs) {
   return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T>& rhs) {
   return Modular<T>(lhs) /= rhs;
}
 
template <typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
   assert(b >= 0);
   Modular<T> x = a, res = 1;
   U p = b;
   while (p > 0) {
       if (p & 1) res *= x;
       x *= x;
       p >>= 1;
   }
   return res;
}
 
template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
   return stream << number();
}
 
template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
   typename common_type<typename Modular<T>::Type, int64_t>::type x;
   stream >> x;
   number.value = Modular<T>::normalize(x);
   return stream;
}
 

 





























ll depth[200005],parent[200005],sz[200000];
void make_set(int v) {
    parent[v] = v;
    depth[v] = 0;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (depth[a] < depth[b])
            swap(a, b);
        parent[b] = a;
        if (depth[a] == depth[b])               
            depth[a]++;
    }
}
ll dfs(vector<ll> graph[],ll start,vi &visit,ll cntr){
    visit[start]=1;
    

   

   

   
    for(auto child:graph[start]){
        if(!visit[child]){
            

            

            

            if(find_set(start)!=find_set(child)){
                union_sets(start,child);
                sz[find_set(start)]++;

            }
                if(cntr<2){
                    cntr++;
                dfs(graph, child, visit,cntr);
                
                }
        }
 
    }
   

   if(cntr<2)
    return 0;
    else return 1;
 
 }


































 


 












































 
 




 






constexpr ll md = 1e9+7;  

using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;











ll ts(ll &lo,ll &hi,ll h,ll c, ll key,vi &v,ld &avg){
       

        ll ans=0;
        map<pair<ll,ll>,ll> mp;
        while(hi-lo>=3){
            ll mid1=lo+(hi-lo)/3,mid2=hi-(hi-lo)/3;
            ll id8=v[mid1],id2=v[mid2];
            

            ll xr1=id8/2,xr2=id2/2;
            ld avg1=ld((xr1+1)*h + xr1*c ) /ld(id8);
            ld avg2=ld((xr2+1)*h + xr2*c ) /ld(id2);
            if(abs(avg1-key)<=abs(avg2-key)){
                ans=id8;
                hi=mid2;
                avg=avg1;
               

            }
            else{
                ans=id2;
                lo=mid1;
                avg=avg2;
            }
            

            

            



        }
        return ans;

}
 vi v;
int main() {
    ios
    

    

    

    

    

    

    

    

    ll t; in>>t;
        ll flg=0;
        for(int i=1;i<=10000000;i+=2){
                v.pb(i);
                
        }
        if(t==30000) flg=1;
        ll cntr=1;
        
    while(t--){
        ll id0=0;
        ld avg=0;
        ld err=0;
        ll h,c,tmpr; in>>h>>c>>tmpr; ll ans;
        if(cntr==1&&h==2) id0=1;
        if(tmpr>=h) ans=1;
        else if(tmpr<=ld(h+c)/ld(2.0))
            ans=2;
        else{
            ll lo=0,hi=v.size();
            
            ans=ts(lo,hi,h,c,tmpr,v,avg);
            rep(i,lo,hi+1){
                ll id8=v[i];
                ll xr1=id8/2;
                ld avg1=ld((xr1+1)*h + xr1*c ) /ld(id8);
                if(abs(tmpr-avg1)<abs(tmpr-avg)){
                    avg=avg1;
                    ans=v[i];
                }
                else if(abs(tmpr-avg1)==abs(tmpr-avg)){
                    ans=min(ans,v[i]);
                }
            }
        
        if(abs(tmpr-avg)>=abs(tmpr - ld(h+c)/ld(2.0) )){ 
            avg=ld(h+c)/ld(2.0);
            ans=2;
        }
       

        }
        

        

        

            ot<<ans<<el;
        cntr++;
    }
    Auriel();
    
}