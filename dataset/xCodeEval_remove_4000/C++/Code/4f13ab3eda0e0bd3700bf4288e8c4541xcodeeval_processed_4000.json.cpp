
using namespace std;
struct FAST_IO{
	FAST_IO(){
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	}
}id1;

template<class T, class U=T>
T exchange(T& obj, U&& new_value){
    T old_value=move(obj);
    obj=forward<U>(new_value);
    return old_value;
}


using INT=int;

using i
DEF_NUM(8)DEF_NUM(16)DEF_NUM(32)DEF_NUM(64)
using i128=long long;using u128=unsigned long long;
using usize=uintptr_t;using isize=intptr_t;
using f32=float;using f64=double;using f128=long double;







auto &_=std::ignore;
using ll=long long;
template<class T>
using vec=vector<T>;
template<bool B,class T=void>
using enableif_t=typename enable_if<B,T>::type;


template<class U> \
struct name{\
	template<class T>\
	constexpr static auto is(int i)->decltype(exp,true){return true;}\
	template<class T>\
	constexpr static bool is(...){return false;}\
	static const bool value=is<U>(1);\
};









constexpr struct{\
	template<class T>\
	constexpr operator T()const {return numeric_limits<T>::exp();}\
} name;

DEF_CAN(Out,(cout<<*(T*)(0))) DEF_CAN(For,begin(*(T*)(0)))
DEF_INF(INF,max) DEF_INF(MINF,min)
DEF_CAN(Array,declval<T>()[0])

template<size_t i,class T>
auto operator>>(istream& is,T &r)->decltype(id3,is){
	return is;
}
template<size_t i=0,class T>
auto operator>>(istream& is,T &r)->decltype(id4,is){
	is>>get<i>(r);
	return operator>> <i+1>(is,r);
}

template<size_t i,class ...Args>
auto operator>>(istream& is,const tuple<Args&...> &r)->decltype(END_TUPLET(tuple<Args&...>),is){
	return is;
}
template<size_t i=0,class ...Args>
auto operator>>(istream& is,const tuple<Args&...> &r)->decltype(FOR_TUPLET(tuple<Args&...>),is){
	is>>get<i>(r);
	return operator>> <i+1>(is,r);
}

template<class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLE(T,Out),c+1);
template<size_t i,class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLEN(T,For),id3,c+1);
template<size_t i=0,class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLEN(T,For),id4,c+1);
template<class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLEN(T,Out),ENABLE(T,For),c+1);


template<class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLE(T,Out),c+1){
	os << cv;
	while (*c!='}') c++;
	return c+1;
}
template<size_t i,class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLEN(T,For),id3,c+1){
	return c;
}
template<size_t i,class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLEN(T,For),id4,c+1){
	while (*c!='{') os << *c++;
	c=__format(os,c,get<i>(cv));
	return __format<i+1>(os,c,cv);
}
template<class T>
auto __format(ostream &os,const char *c,const T& cv)->decltype(ENABLEN(T,Out),ENABLE(T,For),c+1){
	const char *ct=c+1;
	if (cv.size()==0){
		int b=1;
		while (1){
			if (*ct=='}') b--;
			if (*ct=='{') b++;
			if (!b) break;
			ct++;
		}
	}else{
		for (auto &i:cv){
			const char *cc=c+1;
			while (*cc!='{') os << *cc++;
			cc=__format(os,cc,i);
			while (*cc!='}') os << *cc++;
			ct=cc;
		}
	}
	return ct+1;
}
void _format(ostream &os,const char *c){
	while (*c!='{'&&*c!='\0') os<< *c++;
}
template<class T,class ...Args>
void _format(ostream &os,const char *c,const T &a,const Args& ...rest){
	while (*c!='{'&&*c!='\0') os<< *c++;
	if (*c=='{') c=__format(os,c,a);
	_format(os,c,rest...);
}
template<class ...Args>
string format(const char *c,const Args& ...rest){
	ostringstream os;
	_format(os,c,rest...);
	return os.str();
}
template<class ...Args>
ostream& print(const char *c,const Args& ...rest){return _format(cout,c,rest...),cout;}
template<class ...Args>
ostream& println(const char *c,const Args& ...rest){return print(c,rest...)<<endl;}









template<class T>
uintptr_t flat(T* b){
	return reinterpret_cast<uintptr_t>(b);
}
template<class T>
auto index(const T a[],uintptr_t p)->decltype(ENABLEN(T,Array),tuple<int>()){
	return (p-flat(&a[0]))/sizeof(T);
}
template<class T>
auto index(const T a[],uintptr_t p)->decltype(ENABLE(T,Array),
	tuple_cat(tuple<int>(),index(a[0],p))){
	int i=(p-flat(a))/sizeof(a[0]);
	p-=i*sizeof(a[0]);
	return tuple_cat(tuple<int>(i),index(a[0],p));
}

template<class T,class ...Args>
struct Rtar{
	T& a;tuple<Args...> n;
	Rtar(T& a,tuple<Args...> n):a(a),n(n){}
};
template<class T,class ...Args>
Rtar<T,Args&...> rtar(T &a,Args&... rest){
	return Rtar<T,Args&...>(a,tie(rest...));
}
template<size_t i,class U,class ...Args,class T=tuple<Args&...>>
auto operator>>(istream& is,Rtar<U,Args&...> r)->decltype(id3,is){
	return is>>r.a;
}
template<size_t i=0,class U,class ...Args,class T=tuple<Args&...>>
auto operator>>(istream& is,Rtar<U,Args&...> r)->decltype(id4,is){
	r.a=typename decay<U>::type(get<i>(r.n));
	for (auto &w:r.a)
		operator>> <i+1>(is,Rtar<decltype(w),Args&...>(w,r.n));
	return is;
}
template<class T1,class T2>
bool cmin(T1 &a,const T2 b){return a>b?a=b,1:0;}
template<class T1,class T2>
bool cmax(T1 &a,const T2 b){return a<b?a=b,1:0;}
template<class T1,class T2,class ...T3>
bool cmin(T1 &a,const T2 b,const T3 ...rest){return cmin(a,b)|cmin(a,rest...);}
template<class T1,class T2,class ...T3>
bool cmax(T1 &a,const T2 b,const T3 ...rest){return cmax(a,b)|cmax(a,rest...);}

bool id5=true;

constexpr ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
constexpr ll lcm(ll a,ll b){return a*b/gcd(a,b);}
template<class T>
T power(T a,size_t b,const T &unit=1){
	if (b==0) return unit;
	if (b&1) return a*power(a*a,b>>1,unit);
	return power(a*a,b>>1,unit);
}
constexpr ll ceildiv(const ll a,const ll b){return a/b+(a%b?1:0);}
tuple<ll,ll,ll> id0(ll a,ll b){

	if (b==0) return make_tuple(a,1,0);
	ll g,x,y;
	tie(g,x,y)=id0(b,a%b);
	return make_tuple(g,y,x-a/b*y);
}
tuple<ll,ll,ll> id2(ll a,ll b){

	auto k=id0(a,b);
	if (get<1>(k)<0) {
		get<1>(k)+=b;
		get<2>(k)-=a;
	}
	return k;
}
char gc(){
	char c;
	while ((c=cin.get()),(!isdigit(c)));
	return c;
}


template<class T,size_t d> \
array<T,d>& operator x
template<class T,size_t d>\
array<T,d>& operator x
template<class T,size_t d> \
array<T,d> operator x(const array<T,d>& a,const array<T,d>& b){array<T,d> c;for (int i=0;i<d;i++) c[i]=a[i] x b[i];return c;}\
template<class T,size_t d>\
array<T,d> operator x(const array<T,d>& a,const T& b){array<T,d> c;for (int i=0;i<d;i++) c[i]=a[i] x b;return c;}\

op_array(+) op_array(-) op_array(*) op_array(/)
template<class T>
using vec2=array<T,2>;
template<class T>
using vec3=array<T,3>;
template<class T,size_t d>
T dot(const array<T,d>& a,const array<T,d>& b){
	T c=0;
	for (auto& i:a*b) c+=i;
	return c;
}
template<class T,size_t d>
T abs(const array<T,d>& a){return sqrt(dot(a,a));}
template<class T>
__int128 crs(const vec2<T> &a,const vec2<T> &b){return (__int128)a[0]*b[1]-(__int128)a[1]*b[0];}
template<class T>
vec3<T> crs(const vec3<T> &a,const vec3<T> &b){return {a[1]*b[2]-a[2]*b[1],a[2]*b[0]-a[0]*b[2],a[0]*b[1]-a[1]*b[0]};}
template<class T,size_t d>
istream& operator>>(istream& is,array<T,d> &p){
	copy_n(istream_iterator<T>(is),d,p.begin());
	return is;
}

template<class Tx,class Ty=Tx>


struct base_slope_optimizer{
	using Txy=decltype(declval<Tx>()+declval<Ty>());
	using iter=typename map<Tx,Ty>::iterator;
	using v2=vec2<Txy>;
	template<class T1,class T2>
	static v2 _v(const pair<T1,T2>& p){
		return {p.first,p.second};
	}
	static v2 _v(const Tx& x,const Ty& y){
		return {x,y};
	}
	static v2 _v(const v2& x){
		return x;
	}
	static v2 _v(const iter& i){
		return _v(*i);
	}
	template<class fT>
	struct base_slopcmp{
		template<class T>
		bool operator()(const vec2<T>& a,const vec2<T>& b)const{
			return crs(a,b)>0;
		}
		template<class T1,class T2,class T3>
		__int128 operator()(const T1& a,
										const T2& b,
										const T3& c)const{
			const auto& aa=fT::_v(a);
			const auto& bb=fT::_v(b);
			const auto& cc=fT::_v(c);
			return crs(bb-aa,cc-bb);
		}
	};
	using slopcmp=base_slopcmp<base_slope_optimizer>;
	map<v2,iter,slopcmp> ks;
	map<Tx,Ty> points;
	void _eraseik(const iter& j){
		ks.erase(_v(j)-_v(prev(j)));
	}
	
	void _eraseik(const iter& i,const iter& j){
		ks.erase(_v(*j)-_v(*i));
	}
	
	void _insertik(const iter& i,const iter& j){
		ks[_v(*j)-_v(*i)]=j;
	}
	
	int insert(Tx x,Ty y){
		if (points.size()==0) {points.insert({x,y});return 0;}
		auto v=_v(x,y);
		auto i1=points.lower_bound(x);
		if (i1!=points.end()&&i1->first==x){

			if (y>=i1->second) return -1;
			if (i1!=points.begin())
				_eraseik(i1);
			if (next(i1)!=points.end())
				_eraseik(i1,next(i1));
			i1->second=y;
		}else{
			if (points.size()>=2){
				if (i1==points.end()){

					if (slopcmp()(prev(prev(i1)),prev(i1),v)<0)
						return -2;
					_eraseik(i1);
				}else if (i1==points.begin()){

					if (slopcmp()(v,i1,next(i1))<=0)
						return -3;
				}else{
					if (slopcmp()(prev(i1),v,i1)<=0)
						return -4;
					_eraseik(i1);
				}
			}
			i1=points.insert({x,y}).first;
		}
		decltype(i1) i0;
		if (i1!=points.begin()){
			i0=prev(i1);
			if (i0!=points.begin()){
				auto i00=prev(i0);
				while (slopcmp()(i00,i0,i1)<=0){
					_eraseik(i00,i0);
					points.erase(i0);
					if (i00==points.begin()){
						i0=i00;
						break;
					}
					tie(i00,i0)=make_tuple(prev(i00),i00);
				}
			}
		}
		auto i2=next(i1);
		if (i2!=points.end()){
			auto i3=next(i2);
			while (i3!=points.end()&&slopcmp()(i1,i2,i3)<=0){
				_eraseik(i2,i3);
				points.erase(i2);
				tie(i2,i3)=make_tuple(i3,next(i3));
			}
			_insertik(i1,i2);
		}
		if (i1!=points.begin()) _insertik(i0,i1);
		return 1;
	}
	pair<Tx,Ty> getK(Txy k){
		auto ki=ks.upper_bound(vec2<Txy>{1,k});
		if (ki==ks.end()) return *--points.end();
		return *prev(ki->second);
	}
};
int main(){
	int T;
	cin>>T;
	while (T--){
		int n;ll aa,bb;
		cin>>tie(n,aa,bb);
		const __int128 a=aa,b=bb;
		vec<ll> v(n+1,0);
		vec<__int128> vv(n+1,0);
		for (int i=1;i<=n;i++){
			cin>>v[i];
			vv[i]=v[i]+vv[i-1];
		}
		vec<__int128> dp(n+1,(ll)INF);
		dp[0]=0;
		base_slope_optimizer<__int128,__int128> opt;
		opt.insert(b*v[0],dp[0]-b*vv[0]-a*v[0]+0*b*v[0]);
		

		for (int i=1;i<=n;i++){
			auto [x,y]=opt.getK(i);
			dp[i]=y-x*i+b*vv[i]+a*v[i];




				

				

				

				

				



			opt.insert(b*v[i],dp[i]-b*vv[i]-a*v[i]+i*b*v[i]);
		}
		for (int j=0;j<n;j++){
			dp[j]+=b*(vv[n]-vv[j]-(n-j)*v[j]);
		}
		cout << (ll)*min_element(all(dp)) << endl;
	}
}