#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x)(x).begin(),(x).end()
#define fori(i,n)for(int i=0; i<int(n);++i)
#define rep(i,s,e)for(int i=s; i<=int(e);++i)
#define repr(i,s,e)for(int i=s; i>=int(e);--i)
#define temp template<typename
#define CONCEPT(c)enable_if_t<c,bool> =true

temp T>
using V=vector<T>;

using uint=unsigned int;
using ll=long long int;
using ull=unsigned ll;
using pi=pair<int,int>;
using pll=pair<ll,ll>;
using vll=V<ll>;
using vvll=V<vll>;
using vi=V<int>;
using vvi=V<vi>;
using vb=V<bool>;
using vvb=V<vb>;
using vpi=V<pi>;
using vvpi=V<vpi>;

using is=istream;
using os=ostream;

temp T>using minpq=priority_queue<T,V<T>,greater<T>>;
temp T>using maxpq=priority_queue<T>;

temp T>void smax(T&t,const T&t2){ if(t2>t)t=t2; }
temp T>void smin(T&t,const T&t2){ if(t2<t)t=t2; }

temp T>inline constexpr T MAX_VAL=numeric_limits<T>::max();
temp T>inline constexpr T MIN_VAL=numeric_limits<T>::lowest();

temp T>T ceil_pow2(T n){ T t=1; while(t<n)t<<=1; return t; }

namespace reading::details{
temp T>
struct reader{ void operator()(T&t,is&in){in>>t;} };

temp...Args>
void read(is&in,Args&...args){(reader<Args>()(args,in),...);}

temp T>
struct it_reader{
	void operator()(T&arr,is&in){for(auto&a:arr)read(in,a);}
};
temp T>struct reader<deque<T>>:it_reader<deque<T>>{};
temp T>struct reader<V<T>>:it_reader<V<T>>{};
temp T,size_t N>struct reader<array<T,N>>:it_reader<array<T,N>>{};
temp T,class T2>struct reader<pair<T,T2>>{
	void operator()(pair<T,T2>&tup,is&in){read(in,tup.first,tup.second);}
};
temp...Args>struct reader<tuple<Args...>>{
	void operator()(tuple<Args...>&tup,is&in){
		apply([&](auto&&...args){(read(in,args),...);},tup);
	}
};
} 

temp...Args>void read(Args&...args){
	reading::details::read(cin,args...);
}
temp T>T read_one(){ T t; read(t); return t; }

#define RO(command,type)constexpr auto command=read_one<type>
RO(rc,char);
RO(ri,int);
RO(rll,ll);
RO(rd,double);
RO(rs,string);
RO(rpi,pi);
RO(rpll,pll);
#undef RO

temp T=int>V<V<T>>rmat(int r,int c){V<V<T>>mat(r,V<T>(c));read(mat);return mat;}
temp T=int>V<T>rarr(int n){V<T>arr(n);read(arr);return arr;}

namespace printing::details {
temp T>
struct printer{
	void operator()(const T&t,os&out){out<<t;}
};

temp...Args>
void print(os&out,const Args&...args){(printer<Args>()(args,out),...); }

temp T>
void print_tuple(os&out,const T&t){
	bool first=true;
	auto p=[&](auto&&v){
		if(!first)print(out,' ');
		first=false;
		print(out,v);
	};
	apply([&](auto&&...x){(p(x),...);},t);
}

#define tupleprinter(V)temp...Args>struct printer<V<Args...>>{ \
	void operator()(const V<Args...>&tup,os&out){ \
		print_tuple(out,tup); \
	} \
};
tupleprinter(pair);
tupleprinter(tuple);
#undef tupleprinter

temp T,char delim>struct it_printer{
	void operator()(const T&arr,os&out){
		bool first=true;
		for(const auto&a:arr){
			if(first)first=false,print(out,a);
			else print(out,delim,a);
		}
	}
};

temp T>struct printer<V<T>>:it_printer<V<T>,' '>{};
temp T>struct printer<V<V<T>>>:it_printer<V<V<T>>,'\n'>{};
temp T>struct printer<deque<T>>:it_printer<deque<T>,' '>{};
temp T,size_t N>struct printer<array<T,N>>:it_printer<array<T,N>,' '>{};

temp T>struct map_printer{
	void operator()(const T&m,os&out){
		print(out,"Map{");
		bool first=true;
		for(const auto&[k,v]:m)
			if(first)first=false,print(out,k,"=>",v);
			else print(out,",",k,"=>",v);
		print(out,'}');
	}
};
#define mapprinter(V)temp...Args>struct printer<V<Args...>>:map_printer<V<Args...>>{};
mapprinter(unordered_map);
mapprinter(map);
mapprinter(unordered_multimap);
mapprinter(multimap);
#undef mapprinter

temp T>struct set_printer{
	void operator()(const T&s,os&out){
		print(out,"Set{");
		bool first=true;
		for(const auto&k:s)
			if(first)first=false,print(out,k);
			else print(out,",",k);
		print(out,'}');
	}
};
#define setprinter(V)temp...Args>struct printer<V<Args...>>:set_printer<V<Args...>>{};
setprinter(unordered_set);
setprinter(set);
setprinter(unordered_multiset);
setprinter(multiset);
#undef setprinter

temp T>struct printer<optional<T>>{
	void operator()(const optional<T>&t,os&out){
		print(out,"Optional{");
		if(t.has_value())print(out,t.value());
		else print(out,"Empty");
		print(out,"}");
	}
};

template<bool is_first>void print_spaced(os&){}
template<bool is_first,class T,class...Args>
void print_spaced(os&out,const T&t,const Args&...args){
	if constexpr(!is_first)print(out,' ');
	print(out,t);
	print_spaced<false>(out,args...);
}
} 

temp...Args>
void print(const Args&...args){ printing::details::print_spaced<true>(cout,args...); }
temp...Args>
void println(const Args&...args){print(args...,'\n');}
temp...Args>
void printerr(const Args&...args){
	printing::details::print_spaced<true>(cerr,args...);
}
temp...Args>void printerrln(const Args&...args){ printerr("Debug:",args...,'\n'); }
#define PRINTERR(v)printerrln(#v,"=",v)

temp T>struct Wide{using type=T;};
template<>struct Wide<int>{using type=ll;};
template<>struct Wide<ll>{using type=__int128_t;};
template<>struct Wide<__int128_t>{}; 

template<>struct Wide<uint>{using type=ull;};
template<>struct Wide<unsigned long>{using type=ull;};
template<>struct Wide<ull>{using type=__uint128_t;}; 
template<>struct Wide<__uint128_t>{}; 


temp T>using wide_t=typename Wide<T>::type;
temp T>wide_t<T>wide(const T&t){return t;}
temp T>wide_t<T>widemul(const T&a,const T&b){return wide(a)*b;}

tuple<int,int,int>egcd(int a,int b){ 

	if(a==0)return { 0,1,b };
	auto[x,y,g]=egcd(b%a,a);
	return { y-(b / a)*x,x,g };
}

int invmod(int v,int mod){
	auto xyp=egcd(v,mod);
	assert(get<2>(xyp)==1); 

	auto inv=get<0>(xyp);
	if(inv<0)inv+=mod;
	assert(inv<mod&&0<=inv);
	return inv;
}

temp T>T safe_mod(T v,int MOD){ v%=MOD;return v<0 ? v+MOD : v; }
temp T>T mulmod(T a,T b,T m){ return widemul(a,b)%m; }
temp T>T powermod(T a,ll exp,T m){
	T res=1;
	while(exp){
		if(exp&1)res=mulmod(res,a,m);
		a=mulmod(a,a,m),exp /=2;
	}
	return res;
}

temp T>constexpr T max_sqrt(){
	T s=MAX_VAL<T>;
	T l=1,r=s / 2;
	while(l+1<r){
		T m=(l+r)/ 2;
		if(m>s / m)r=m;
		else l=m;
	}
	return l;
}

temp T>T isqrt(T t){
	static constexpr T _max_sqrt=max_sqrt<T>();
	T l=1,r=_max_sqrt+1;
	while(l+1<r){
		T m=(l+r)/ 2;
		if(m*m>t)r=m;
		else l=m;
	}
	return l;
}

template<int MOD>
struct MInt {
	int v;
	MInt()=default;
	temp T,CONCEPT(is_integral_v<T>)>
	MInt(T v):v(safe_mod(v,MOD)){}
	MInt&operator+=(const MInt&rhs){ v+=rhs.v;if(v>=MOD)v-=MOD;return*this; }
	MInt&operator-=(const MInt&rhs){ v-=rhs.v;if(v<0)v+=MOD;return*this; }
	MInt&operator*=(const MInt&rhs){ v=widemul(v,rhs.v)%MOD;return*this; }
	MInt&operator/=(const MInt&rhs){ return*this*=rhs.inv(); }
	MInt operator+(const MInt&rhs)const { auto t=*this;return t+=rhs; }
	MInt operator-(const MInt&rhs)const { auto t=*this;return t-=rhs; }
	MInt operator*(const MInt&rhs)const { auto t=*this;return t*=rhs; }
	MInt operator/(const MInt&rhs)const { auto t=*this;return t /=rhs; }
	bool operator==(const MInt&rhs)const { return v==rhs.v; }
	bool operator!=(const MInt&rhs)const { return v!=rhs.v; }
	MInt inv()const { return { invmod(v,MOD)}; }
	friend istream&operator>>(istream&in,MInt&v){ ll t;in>>t;v=MInt(t);return in; }
	friend ostream&operator<<(ostream&out,const MInt&v){ return out<<v.v; }
	MInt pow(ll power)const { return { powermod(v,power,MOD)}; };
	int val()const { return v; }
};

constexpr int MOD=998244353;


using mi=MInt<MOD>;
using vmi=V<mi>;
using vvmi=V<vmi>;

mi factorial(int i){
	static vmi dp(1,mi(1));
	while(int(dp.size())<=i)dp.pb(dp.back()*int(dp.size()));
	return dp.at(i);
}
mi ifactorial(int i){
	static vmi dp(2,mi(1));
	while(int(dp.size())<=i){
		static constexpr int N=256;
		int cur=dp.size();
		mi last=dp[cur-1].inv();
		rep(i,cur,cur+N-1)dp.pb(last*=i);
		last=last.inv();
		repr(i,cur+N-1,cur){
			dp[i]=last;
			last*=i;
		}
	}
	return dp.at(i);
}
mi nck(int n,int k){
	assert(n>=0&&k>=0&&n>=k);
	return factorial(n)*ifactorial(n-k)*ifactorial(k);
}

size_t get_random_from_clock(){
	rand();
	return chrono::steady_clock::now().time_since_epoch().count();
}

mt19937 my_random_gen(get_random_from_clock());
temp T>
T randI(T l=MAX_VAL<T>,T r=MIN_VAL<T>){
	

	if(l==MAX_VAL<T>)swap(l,r);
	else if(r==MIN_VAL<T>){
		r=l; l=0;
	}
	if constexpr(is_integral_v<T>){
		return uniform_int_distribution<T>(l,r)(my_random_gen);
	} else {
		static_assert(is_floating_point_v<T>);
		return uniform_real_distribution<T>(l,r)(my_random_gen);
	}
}
constexpr auto randint=randI<int>;
constexpr auto randll=randI<ll>;
constexpr auto randf=randI<float>;
constexpr auto randd=randI<double>;

namespace hashing::details {
size_t splitmix64(size_t x){
	x+=0x9e3779b97f4a7c15;
	x=(x^(x>>30))*0xbf58476d1ce4e5b9;
	x=(x^(x>>27))*0x94d049bb133111eb;
	return x^(x>>31);
}

size_t combine_hashes(size_t h1,size_t h2){
	return h1^(splitmix64(h2)+0x9e3779b9+(h1<<6)+(h1>>2));
}

temp T>size_t auto_hash(const T&t){ return hash<T>()(t); }

temp T>void update_hash(size_t&h,const T&t){ h=combine_hashes(h,auto_hash(t)); }

temp T>size_t auto_hash_tuples(const T&t){
	size_t ans=0;
	apply([&ans](auto&&...t){(update_hash(ans,t),...);},t);
	return ans;
}

temp...Args>size_t auto_hash(const tuple<Args...>&t){
	return auto_hash_tuples(t);
}

temp T,typename U>size_t auto_hash(const pair<T,U>&t){
	return auto_hash_tuples(t);
}

temp T>size_t auto_hash_arrays(const T&a){
	size_t ans=0;
	for(const auto&i : a)update_hash(ans,i);
	return ans;
}

temp T,size_t N>
size_t auto_hash(const array<T,N>&a){
	return auto_hash_arrays(a);
}

temp T>
size_t auto_hash(const vector<T>&a){
	return auto_hash_arrays(a);
}
} 


#define stdhash(...)\
struct std::hash<__VA_ARGS__>{ \
	size_t operator()(const __VA_ARGS__&v)const { \
		return hashing::details::auto_hash(v); \
	} \
};

temp...Args>
stdhash(tuple<Args...>);

temp T,typename U>
stdhash(pair<T,U>);

temp T,size_t N>
stdhash(array<T,N>);

temp T>
stdhash(vector<T>);
#undef stdhash


temp T>
struct custom_hash {
	size_t operator()(T x)const {
		static const size_t FIXED_RANDOM=get_random_from_clock();
		return hashing::details::splitmix64(hash<T>()(x)+FIXED_RANDOM);
	}
};

temp T,typename U>
using hash_map=unordered_map<T,U,custom_hash<T>>;
temp T>
using hash_set=unordered_set<T,custom_hash<T>>;

temp T,class C>wide_t<T>sum_impl(const C&v){ wide_t<T>o{}; for(auto&a : v)o+=a;return o; }
temp T>auto sum(const V<T>&v){ return sum_impl<T>(v); }
temp T>auto sum(const deque<T>&v){ return sum_impl<T>(v); }
temp T,size_t N>auto sum(const array<T,N>&v){ return sum_impl<T>(v); }
temp T>void reverse(T&v){ reverse(all(v)); }
temp T,typename KEY>void sort(T&v,KEY&&getkey){
 sort(all(v),[&](const auto&a,const auto&b){return getkey(a)<getkey(b);});
}
temp T>void sort(T&v){ sort(all(v)); }
temp T>T sorted(T v){ sort(v); return v; }

temp T>void cumsum_inplace(T&v){
 for(auto it=v.begin(); it+1!=v.end();++it)(*it)+=*(it+1);
}
temp T>T cumsum(T v){ cumsum_inplace(v); return v; }
int constexpr popcnt(ll i){ return __builtin_popcountll(i); }
int constexpr ctz(ll i){ return __builtin_ctzll(i); }

temp T>[[nodiscard]]
V<T>mkunique(const V<T>&v){
 auto res=sorted(v);
 res.erase(unique(all(res)),res.end());
 return res;
}

temp K,class V>
class OneToOneHashMap {
 hash_map<K,V>k2v;
 hash_map<V,K>v2k;
 temp T1,class T2>
	static void erase(hash_map<T1,T2>&hm,const T1&t1,const T2&t2){
	auto it=hm.find(t1);
	assert(it!=hm.end()&&it->second==t2);
	hm.erase(it);
 }
public:
 auto begin()const { return k2v.begin(); }
 auto end()const { return k2v.end(); }
 size_t size()const { return k2v.size(); }
 bool empty()const { return size()==0u; }
 const V&get_key(const V&v)const { return v2k.at(v); }
 const K&get_value(const K&k)const { return k2v.at(k); }
 bool has_key(const K&k)const { return k2v.count(k); }
 bool has_value(const V&v)const { return v2k.count(v); }
 void erase_by_key(const K&k)const { erase(k,get_value(k)); }
 void erase_by_value(const V&v)const { erase(gey_key(v),v); }
 void erase(const K&k,const V&v){
	erase(k2v,k,v);
	erase(v2k,v,k);
 }
 void emplace(const K&k,const V&v){
	auto ans1=k2v.emplace(k,v);
	assert(ans1.second);
	auto ans2=v2k.emplace(v,k);
	assert(ans2.second);
 }
 friend ostream&operator<<(ostream&out,const OneToOneHashMap&o2o){
	out<<"OneToOneHashMap{\n";
	for(const auto&[k,v]: o2o.k2v)out<<k<<","<<v<<'\n'; 
	return out<<"}";
 }
};

int parity_factorial(int x) {
    int ans = 0;
    while (x != 0) {
        x /= 2;
        ans += x;
    }
    return ans;
}

int parity_nck(int n, int k) {
    assert(n >= k);
    assert(k >= 0);
    int ans =
        parity_factorial(n)
        - parity_factorial(n - k)
        - parity_factorial(k);
    return ans == 0 ? 1 : 0; 

}

vi B;
int n, k;
vb ans;

void add_power(int& l, int b) {
    if (l != 0 && b < 20 && l < (1 << 20)) {
        ll res = ll(l) * (1 << b);
        if (res < (1 << 20)) {
            l = int(res);
            return;
        }
    }
    l = 0;
}

void add_range(int l, int r) {
    int power = B[l];
    rep(i, l + 1, r) add_power(power, B[i]);
    if (power == 0) return;
    ans[power] = !ans[power];
}

int parity_n_choose_atleast_k(int n, int k) {
    int ans = 0;
    int parity = parity_factorial(n);
    k = max(k, 0);
    parity -= parity_factorial(k) + parity_factorial(n - k);
    rep(i, k, n) {
        ans += parity == 0 ? 1 : 0;
        parity += ctz(n - i);
        parity -= ctz(i + 1);
    }
    return ans % 2;
}

void add_prefix() {
    rep(i, 0, min(n - 2, 21)) {
        int rem = n - 1 - (i + 1);
        int par = parity_n_choose_atleast_k(rem, k - 1);
        if (par == 1) {
            

            add_range(0, i);
            add_range(n - i - 1, n - 1);
        }
    }
}

void add_subseq() {
    rep(sz, 1, 21) {
        

        int rem = n - 1 - (sz + 1);
        int par = parity_n_choose_atleast_k(rem, k - 2);
        if (par == 1) {
            rep(start, 1, n - 1 - sz) {
                

                add_range(start, start + sz - 1);
            }
        }
    }
}

void solve() {
    read(n, k);
    B.resize(n); read(B);
    ans = vb(1 << 20);

    

    if (k == 0) add_range(0, n - 1);
    add_prefix();
    add_subseq();

    bool first = false;
    repr(i, (1 << 20) - 1, 0) {
        first |= ans[i];
        if (first) {
            cout << (ans[i] ? 1 : 0);
        }
    }
    if (!first) cout << 0;
    cout << '\n';
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    solve();
    return 0;
}
