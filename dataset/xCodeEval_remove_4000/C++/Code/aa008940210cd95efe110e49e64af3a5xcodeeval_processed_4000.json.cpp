






































using namespace std;

using i8=int8_t;using u8=uint8_t;using i16=int16_t;using u16=uint16_t;using i32=int32_t;using u32=uint32_t;using i64=int64_t;using u64=uint64_t;using f32=float;using f64=double;using f80=long double;
template<size_t N>using cbuf=char[N];
enum Bool:u8{False,True};

[[maybe_unused]] const u32 E9=1e9,E8=1e8,E7=1e7,E6=1e6,E5=1e5,E4=1e4,E3=1e3,E2=1e2;





namespace Fmt{
	template<char...r>struct Str{static constexpr cbuf<sizeof...(r)+1>v={r...,'\0'};};template<char...r>constexpr cbuf<sizeof...(r)+1>Str<r...>::v;

	template<u64 n,char...r>struct I2Str:I2Str<(n>>8),(char)n,r...>{};template<char...r>struct I2Str<0,r...>:Str<r...>{};

	template<class A,typename B,bool f=1,u8 n=2,u32 i=0,char...r>struct StrStrImpl:StrStrImpl<A,B,!B::v[i+1],n-!B::v[i+1],i+1,r...,B::v[i]>{};
	template<class B,typename A,u8 n,u32 i,char...r>struct StrStrImpl<B,A,1,n,i,r...>:StrStrImpl<A,B,!*B::v,n-!*B::v,0,r...>{};
	template<class A,typename B,u32 i,char...r>struct StrStrImpl<A,B,1,0,i,r...>:Str<r...>{};

	template<class S,typename...R> struct StrStr:StrStrImpl<S,StrStr<R...>>{};template<class S>struct StrStr<S>:S{};

	template<class S,bool f=1,u32 i=0,char...r>struct StrRSan:StrRSan<S,S::v[i+1]>='A',i+1,r...,S::v[i]>{};template<class S,u32 i,char...r>struct StrRSan<S,0,i,r...>:Str<r...>{};

	template<class T>struct FmtS;

	template<u64 f,u64 e,u64 p,typename T,typename...R>struct Fmt:StrStr<Fmt<e,f,p,T>,Fmt<f,e,p,R...>>{};
	template<u64 f,u64 e,u64 p,typename T>struct Fmt<f,e,p,T>:StrStr<Str<'%'>,I2Str<p>,StrRSan<FmtS<T>>,I2Str<e>>{};

	
	F(_*,"p",typename _);F(i8,GET_OR_DEFAULT(SCNd8,"hhd"));F(i16,SCNd16);F(i32,SCNd32);F(i64,SCNd64);F(u8,GET_OR_DEFAULT(SCNu8,"hhu"));F(u16,SCNu16);F(u32,SCNu32);F(u64,SCNu64);F(char,"c");F(char*,"s");F(const char*,"s");F(char[_],"s",size_t _);F(bool,FmtS<u8>::v);F(f32,"f");F(f64,"lf");F(f80,"Lf");
	

	template<class A,typename B>struct Ref{A v;B _;};
	template<>struct Ref<char**,char*>{char**_;char*v;};
}

template<u64 p=0,u64 e='\n',u64 f=' ',typename...R>__forceinline int pr(R...r){return printf(Fmt::Fmt<f,e,p,R...>::v,r...);}
template<class...R>__forceinline int sc(R&&...r){return scanf(Fmt::Fmt<0,0,0,remove_reference_t<R>...>::v,Fmt::Ref<add_pointer_t<R>,R>{&r,r}.v...);}

template<u64 f=' ',typename...R>string spr(R...r){cbuf<E5>_;sprintf(_,Fmt::Fmt<f,0,0,R...>::v,r...);return _;}


























void FSWP(FILE*&a,FILE*&b){swap(a,b);}void FSWP(const FILE*a,const FILE*b){swap(*const_cast<FILE*>(a),*const_cast<FILE*>(b));}




template<class T>int scmp(T a,T b){return (*b<*a)-(*a<*b);}












template<class T>T rrand(T a,T b){static mt19937 G(time(0));return uniform_int_distribution<T>(a,b)(G);}


namespace Test{
	struct InputGen:public function<string()>{
		using function::function;
		template<class F>InputGen(F f,typename enable_if<is_arithmetic<decltype(f())>::value>::type* =0,typename enable_if<is_constructible<function<decltype(f())()>,F>::value>::type* =0):function([f](){return spr(f());}){}
		template<class S>InputGen(S&&s,typename enable_if<is_constructible<string,S>::value>::type* =0):function([s=(string)s]()mutable{auto _=s;s="";return _;}){}
		template<class T>InputGen(T x,typename enable_if<is_arithmetic<T>::value>::type* =0):InputGen(spr(x)){}
		InputGen(initializer_list<InputGen>&&v):function([Q=queue<InputGen>(v)]()mutable{string r;while(Q.size()&&(r=Q.front()()).empty())Q.pop();return r;}){}
	};

	template<u32 N=1,u64 S=' '>class Prod{
		vector<InputGen>v;
	public:
		Prod(initializer_list<InputGen>&&v):v(v){};
		auto operator()(){
			string r;
			repn(N)for(auto&f:v){
				auto _=f();
				if(_.empty())return _;
				if(r.size())r+=Fmt::I2Str<S>::v;
				r+=_;
			}
			return r;
		}
	};

	class Rep{
		InputGen c,o;u32 n;
	public:
		Rep(u32 n,InputGen&&f):c(""),o(f),n(n){}
		auto operator()(){
			auto _=c();
			if(_.size()+!n)return _;
			n--;c=o;return c();
		}
	};

	class Range{
		i64 n,a,d;
	public:
		Range(i64 n,i64 a=1,i64 d=1):n(n),a(a),d(d){}
		auto operator()(){
			if(!n)return""s;
			n--;a+=d;return spr(a-d);
		}
	};

	bool Log=1;map<void*,pair<string,string>>BM;u32 No;
	int Input(void*_,char*b,int n){
		auto& G=*(InputGen*)_;auto& B=BM[_];int r=0;
		for(;;){
			if(B.a.size()) {
				if((int)B.a.size()<n-r){
					memcpy(b+r,B.a.data(),B.a.size());
					r+=B.a.size();B.a="";
				}else{
					memcpy(b+r,B.a.data(),n-r);
					B.a.erase(0,n-r);
					Log=Log||fprintf(stderr,"\n\nTest input data:\n
					B.b+={b,(size_t)n};
					return n;
				}
			}
			B.a=G();
			if(B.a.empty()){
				Log=Log||fprintf(stderr,"\n\nTest input data:\n
				B.b+={b,(size_t)r};
				return r;
			}
			B.a+='\n';
		}
	}

	int Output(void*s,const char*b,int n){*(string*)s+={b,(size_t)n};return n;}

	class id2:public iterator<input_iterator_tag,string>{
		InputGen g;shared_ptr<FILE>f;cbuf<E5>s;
	public:
		id2():g{}{*s=0;}
		id2(InputGen _):g(_),f(fropen(&g,Input),fclose){++*this;}
		id2&operator++(){fscanf(f.get(),"%s",s)>0||(*s=0);return*this;}
		string operator*(){return s;}
		bool operator!=(id2&o){return*s|*o.s;}bool operator==(id2&o){return!*s&!*o.s;}
	};

	struct Checker:public function<bool(string,string)>{
		using function::function;
		template<class T>Checker(T t,typename enable_if<is_constructible<InputGen,T>::value>::type* =0):function([I=InputGen(t)](string,string o){return equal(id2(I),{},id2(o),{});}){}
		template<class F>Checker(F f,typename enable_if<is_same<void,decltype(f())>::value>::type* =0):function([f](string i,string o){InputGen Q{i};i="";auto I=fropen(&Q,Input),O=fwopen(&i,Output);FSWP(I,stdin);FSWP(O,stdout);f();fflush(stdout);FSWP(I,stdin);FSWP(O,stdout);fclose(I);fclose(O);return equal(id2(i),{},id2(o),{});}){}
		template<class F>Checker(F f,typename enable_if<is_same<Bool,decltype(f())>::value>::type* =0):function([f](string,string o){InputGen Q{o};auto I=fropen(&Q,Input);FSWP(I,stdin);bool r=f();FSWP(I,stdin);fclose(I);return r;}){}
	};
}





void solve();






int main(){
	
	if(DEFINED(acm_files)){freopen(acm_in,"r",stdin);freopen(acm_out,"w",stdout);}
	solve();
	if(DEFINED(acm_files)){fclose(stdin);fflush(stdout);fclose(stdout);}
	
	

	TESTIO("2 2","5");
	TESTIO("10 1","55");
	TESTIO("723 9","157557417");
	
}

class id1{
	private:
		uint64_t UPPER, LOWER;

	public:
		

		id1();
		id1(const id1 & rhs);
		id1(id1 && rhs);
		id1(std::string & s);
		id1(const char *s);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		id1(const T & rhs)
			: UPPER(0), LOWER(rhs)
		{}

		template <typename S, typename T, typename = typename std::enable_if <std::is_integral<S>::value && std::is_integral<T>::value, void>::type>
		id1(const S & upper_rhs, const T & lower_rhs)
			: UPPER(upper_rhs), LOWER(lower_rhs)
		{}

		


		

		id1 & operator=(const id1 & rhs);
		id1 & operator=(id1 && rhs);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		id1 & operator=(const T & rhs){
			UPPER = 0;
			LOWER = rhs;
			return *this;
		}

		

		operator bool() const;
		operator uint8_t() const;
		operator uint16_t() const;
		operator uint32_t() const;
		operator uint64_t() const;

		

		id1 operator&(const id1 & rhs) const;

		void export_bits(std::vector<uint8_t> & ret) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		id1 operator&(const T & rhs) const{
			return id1(0, LOWER & (uint64_t) rhs);
		}

		id1 & operator&=(const id1 & rhs);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		id1 & operator&=(const T & rhs){
			UPPER = 0;
			LOWER &= rhs;
			return *this;
		}

		id1 operator|(const id1 & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		id1 operator|(const T & rhs) const{
			return id1(UPPER, LOWER | (uint64_t) rhs);
		}

		id1 & operator|=(const id1 & rhs);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		id1 & operator|=(const T & rhs){
			LOWER |= (uint64_t) rhs;
			return *this;
		}

		id1 operator^(const id1 & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		id1 operator^(const T & rhs) const{
			return id1(UPPER, LOWER ^ (uint64_t) rhs);
		}

		id1 & operator^=(const id1 & rhs);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		id1 & operator^=(const T & rhs){
			LOWER ^= (uint64_t) rhs;
			return *this;
		}

		id1 operator~() const;

		

		id1 operator<<(const id1 & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		id1 operator<<(const T & rhs) const{
			return *this << id1(rhs);
		}

		id1 & operator<<=(const id1 & rhs);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		id1 & operator<<=(const T & rhs){
			*this = *this << id1(rhs);
			return *this;
		}

		id1 operator>>(const id1 & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		id1 operator>>(const T & rhs) const{
			return *this >> id1(rhs);
		}

		id1 & operator>>=(const id1 & rhs);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		id1 & operator>>=(const T & rhs){
			*this = *this >> id1(rhs);
			return *this;
		}

		

		bool operator!() const;
		bool operator&&(const id1 & rhs) const;
		bool operator||(const id1 & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		bool operator&&(const T & rhs){
			return static_cast <bool> (*this && rhs);
		}

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		bool operator||(const T & rhs){
			return static_cast <bool> (*this || rhs);
		}

		

		bool operator==(const id1 & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		bool operator==(const T & rhs) const{
			return (!UPPER && (LOWER == (uint64_t) rhs));
		}

		bool operator!=(const id1 & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		bool operator!=(const T & rhs) const{
			return (UPPER | (LOWER != (uint64_t) rhs));
		}

		bool operator>(const id1 & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		bool operator>(const T & rhs) const{
			return (UPPER || (LOWER > (uint64_t) rhs));
		}

		bool operator<(const id1 & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		bool operator<(const T & rhs) const{
			return (!UPPER)?(LOWER < (uint64_t) rhs):false;
		}

		bool operator>=(const id1 & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		bool operator>=(const T & rhs) const{
			return ((*this > rhs) | (*this == rhs));
		}

		bool operator<=(const id1 & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		bool operator<=(const T & rhs) const{
			return ((*this < rhs) | (*this == rhs));
		}

		

		id1 operator+(const id1 & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		id1 operator+(const T & rhs) const{
			return id1(UPPER + ((LOWER + (uint64_t) rhs) < LOWER), LOWER + (uint64_t) rhs);
		}

		id1 & operator+=(const id1 & rhs);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		id1 & operator+=(const T & rhs){
			UPPER = UPPER + ((LOWER + rhs) < LOWER);
			LOWER = LOWER + rhs;
			return *this;
		}

		id1 operator-(const id1 & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		id1 operator-(const T & rhs) const{
			return id1((uint64_t) (UPPER - ((LOWER - rhs) > LOWER)), (uint64_t) (LOWER - rhs));
		}

		id1 & operator-=(const id1 & rhs);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		id1 & operator-=(const T & rhs){
			*this = *this - rhs;
			return *this;
		}

		id1 operator*(const id1 & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		id1 operator*(const T & rhs) const{
			return *this * id1(rhs);
		}

		id1 & operator*=(const id1 & rhs);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		id1 & operator*=(const T & rhs){
			*this = *this * id1(rhs);
			return *this;
		}

	private:
		std::pair <id1, id1> divmod(const id1 & lhs, const id1 & rhs) const;
		void init(const char * s);
		void ConvertToVector(std::vector<uint8_t> & current, const uint64_t & val) const;
		uint8_t HexToInt(const char *s) const;
		uint64_t ConvertToUint64(const char *s) const;

	public:
		id1 operator/(const id1 & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		id1 operator/(const T & rhs) const{
			return *this / id1(rhs);
		}

		id1 & operator/=(const id1 & rhs);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		id1 & operator/=(const T & rhs){
			*this = *this / id1(rhs);
			return *this;
		}

		id1 operator%(const id1 & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		id1 operator%(const T & rhs) const{
			return *this % id1(rhs);
		}

		id1 & operator%=(const id1 & rhs);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		id1 & operator%=(const T & rhs){
			*this = *this % id1(rhs);
			return *this;
		}

		

		id1 & operator++();
		id1 operator++(int);

		

		id1 & operator--();
		id1 operator--(int);

		

		id1 operator+() const;

		

		id1 operator-() const;

		

		const uint64_t & upper() const;
		const uint64_t & lower() const;

		

		uint8_t bits() const;

		

		std::string str(uint8_t base = 10, const unsigned int & len = 0) const;
};

const id1 id0(0);
const id1 id3(1);

id1::id1()
	: UPPER(0), LOWER(0)
{}

id1::id1(const id1 & rhs)
	: UPPER(rhs.UPPER), LOWER(rhs.LOWER)
{}

id1::id1(id1 && rhs)
	: UPPER(std::move(rhs.UPPER)), LOWER(std::move(rhs.LOWER))
{
	if (this != &rhs){
		rhs.UPPER = 0;
		rhs.LOWER = 0;
	}
}

id1::id1(std::string & s) {
	init(s.c_str());
}

id1::id1(const char *s) {
	init(s);
}

void id1::init(const char *s) {
	if (s == NULL || s[0] == 0) { id1(); return; }
	if (s[1] == 'x')
		s += 2;
	else if (*s == 'x')
		s++;

	UPPER = ConvertToUint64(s);
	LOWER = ConvertToUint64(s + 16);
}

uint64_t id1::ConvertToUint64(const char *s) const {
	int count = 0;
	uint64_t val = 0;
	uint8_t hv = HexToInt(s++);
	while (hv != 0xFF && count < 16) {
		val = (val << 4) | hv;
		hv = HexToInt(&s[count]);
		count++;
	}
	return val;
}

uint8_t id1::HexToInt(const char *s) const {
	uint8_t ret = 0xFF;
	if (*s >= '0' && *s <= '9') {
		ret = uint8_t(*s - '0');
	}
	else if (*s >= 'a' && *s <= 'f') {
		ret = uint8_t(*s - 'a' + 10);
	}
	else if (*s >= 'A' && *s <= 'F') {
		ret = uint8_t(*s - 'A' + 10);
	}
	return ret;
}

id1 & id1::operator=(const id1 & rhs){
	UPPER = rhs.UPPER;
	LOWER = rhs.LOWER;
	return *this;
}

id1 & id1::operator=(id1 && rhs){
	if (this != &rhs){
		UPPER = std::move(rhs.UPPER);
		LOWER = std::move(rhs.LOWER);
		rhs.UPPER = 0;
		rhs.LOWER = 0;
	}
	return *this;
}

id1::operator bool() const{
	return (bool) (UPPER | LOWER);
}

id1::operator uint8_t() const{
	return (uint8_t) LOWER;
}

id1::operator uint16_t() const{
	return (uint16_t) LOWER;
}

id1::operator uint32_t() const{
	return (uint32_t) LOWER;
}

id1::operator uint64_t() const{
	return (uint64_t) LOWER;
}

id1 id1::operator&(const id1 & rhs) const{
	return id1(UPPER & rhs.UPPER, LOWER & rhs.LOWER);
}

id1 & id1::operator&=(const id1 & rhs){
	UPPER &= rhs.UPPER;
	LOWER &= rhs.LOWER;
	return *this;
}

id1 id1::operator|(const id1 & rhs) const{
	return id1(UPPER | rhs.UPPER, LOWER | rhs.LOWER);
}

id1 & id1::operator|=(const id1 & rhs){
	UPPER |= rhs.UPPER;
	LOWER |= rhs.LOWER;
	return *this;
}

id1 id1::operator^(const id1 & rhs) const{
	return id1(UPPER ^ rhs.UPPER, LOWER ^ rhs.LOWER);
}

id1 & id1::operator^=(const id1 & rhs){
	UPPER ^= rhs.UPPER;
	LOWER ^= rhs.LOWER;
	return *this;
}

id1 id1::operator~() const{
	return id1(~UPPER, ~LOWER);
}

id1 id1::operator<<(const id1 & rhs) const{
	const uint64_t shift = rhs.LOWER;
	if (((bool) rhs.UPPER) || (shift >= 128)){
		return id0;
	}
	else if (shift == 64){
		return id1(LOWER, 0);
	}
	else if (shift == 0){
		return *this;
	}
	else if (shift < 64){
		return id1((UPPER << shift) + (LOWER >> (64 - shift)), LOWER << shift);
	}
	else if ((128 > shift) && (shift > 64)){
		return id1(LOWER << (shift - 64), 0);
	}
	else{
		return id0;
	}
}

id1 & id1::operator<<=(const id1 & rhs){
	*this = *this << rhs;
	return *this;
}

id1 id1::operator>>(const id1 & rhs) const{
	const uint64_t shift = rhs.LOWER;
	if (((bool) rhs.UPPER) || (shift >= 128)){
		return id0;
	}
	else if (shift == 64){
		return id1(0, UPPER);
	}
	else if (shift == 0){
		return *this;
	}
	else if (shift < 64){
		return id1(UPPER >> shift, (UPPER << (64 - shift)) + (LOWER >> shift));
	}
	else if ((128 > shift) && (shift > 64)){
		return id1(0, (UPPER >> (shift - 64)));
	}
	else{
		return id0;
	}
}

id1 & id1::operator>>=(const id1 & rhs){
	*this = *this >> rhs;
	return *this;
}

bool id1::operator!() const{
	return !(bool) (UPPER | LOWER);
}

bool id1::operator&&(const id1 & rhs) const{
	return ((bool) *this && rhs);
}

bool id1::operator||(const id1 & rhs) const{
	 return ((bool) *this || rhs);
}

bool id1::operator==(const id1 & rhs) const{
	return ((UPPER == rhs.UPPER) && (LOWER == rhs.LOWER));
}

bool id1::operator!=(const id1 & rhs) const{
	return ((UPPER != rhs.UPPER) | (LOWER != rhs.LOWER));
}

bool id1::operator>(const id1 & rhs) const{
	if (UPPER == rhs.UPPER){
		return (LOWER > rhs.LOWER);
	}
	return (UPPER > rhs.UPPER);
}

bool id1::operator<(const id1 & rhs) const{
	if (UPPER == rhs.UPPER){
		return (LOWER < rhs.LOWER);
	}
	return (UPPER < rhs.UPPER);
}

bool id1::operator>=(const id1 & rhs) const{
	return ((*this > rhs) | (*this == rhs));
}

bool id1::operator<=(const id1 & rhs) const{
	return ((*this < rhs) | (*this == rhs));
}

id1 id1::operator+(const id1 & rhs) const{
	return id1(UPPER + rhs.UPPER + ((LOWER + rhs.LOWER) < LOWER), LOWER + rhs.LOWER);
}

id1 & id1::operator+=(const id1 & rhs){
	UPPER += rhs.UPPER + ((LOWER + rhs.LOWER) < LOWER);
	LOWER += rhs.LOWER;
	return *this;
}

id1 id1::operator-(const id1 & rhs) const{
	return id1(UPPER - rhs.UPPER - ((LOWER - rhs.LOWER) > LOWER), LOWER - rhs.LOWER);
}

id1 & id1::operator-=(const id1 & rhs){
	*this = *this - rhs;
	return *this;
}

id1 id1::operator*(const id1 & rhs) const{
	

	uint64_t top[4] = {UPPER >> 32, UPPER & 0xffffffff, LOWER >> 32, LOWER & 0xffffffff};
	uint64_t bottom[4] = {rhs.UPPER >> 32, rhs.UPPER & 0xffffffff, rhs.LOWER >> 32, rhs.LOWER & 0xffffffff};
	uint64_t products[4][4];

	

	for(int y = 3; y > -1; y--){
		for(int x = 3; x > -1; x--){
			products[3 - x][y] = top[x] * bottom[y];
		}
	}

	

	uint64_t id4 = (products[0][3] & 0xffffffff);
	uint64_t third32  = (products[0][2] & 0xffffffff) + (products[0][3] >> 32);
	uint64_t second32 = (products[0][1] & 0xffffffff) + (products[0][2] >> 32);
	uint64_t first32  = (products[0][0] & 0xffffffff) + (products[0][1] >> 32);

	

	third32  += (products[1][3] & 0xffffffff);
	second32 += (products[1][2] & 0xffffffff) + (products[1][3] >> 32);
	first32  += (products[1][1] & 0xffffffff) + (products[1][2] >> 32);

	

	second32 += (products[2][3] & 0xffffffff);
	first32  += (products[2][2] & 0xffffffff) + (products[2][3] >> 32);

	

	first32  += (products[3][3] & 0xffffffff);

	

	third32  += id4 >> 32;
	second32 += third32  >> 32;
	first32  += second32 >> 32;

	

	id4 &= 0xffffffff;
	third32  &= 0xffffffff;
	second32 &= 0xffffffff;
	first32  &= 0xffffffff;

	

	return id1((first32 << 32) | second32, (third32 << 32) | id4);
}

id1 & id1::operator*=(const id1 & rhs){
	*this = *this * rhs;
	return *this;
}

void id1::ConvertToVector(std::vector<uint8_t> & ret, const uint64_t & val) const {
	ret.push_back(static_cast<uint8_t>(val >> 56));
	ret.push_back(static_cast<uint8_t>(val >> 48));
	ret.push_back(static_cast<uint8_t>(val >> 40));
	ret.push_back(static_cast<uint8_t>(val >> 32));
	ret.push_back(static_cast<uint8_t>(val >> 24));
	ret.push_back(static_cast<uint8_t>(val >> 16));
	ret.push_back(static_cast<uint8_t>(val >> 8));
	ret.push_back(static_cast<uint8_t>(val));
}

void id1::export_bits(std::vector<uint8_t> &ret) const {
	ConvertToVector(ret, const_cast<const uint64_t&>(UPPER));
	ConvertToVector(ret, const_cast<const uint64_t&>(LOWER));
}

std::pair <id1, id1> id1::divmod(const id1 & lhs, const id1 & rhs) const{
	

	if (rhs == id0){
		throw std::domain_error("Error: division or modulus by 0");
	}
	else if (rhs == id3){
		return std::pair <id1, id1> (lhs, id0);
	}
	else if (lhs == rhs){
		return std::pair <id1, id1> (id3, id0);
	}
	else if ((lhs == id0) || (lhs < rhs)){
		return std::pair <id1, id1> (id0, lhs);
	}

	std::pair <id1, id1> qr (id0, id0);
	for(uint8_t x = lhs.bits(); x > 0; x--){
		qr.first  <<= id3;
		qr.second <<= id3;

		if ((lhs >> (x - 1U)) & 1){
			++qr.second;
		}

		if (qr.second >= rhs){
			qr.second -= rhs;
			++qr.first;
		}
	}
	return qr;
}

id1 id1::operator/(const id1 & rhs) const{
	return divmod(*this, rhs).first;
}

id1 & id1::operator/=(const id1 & rhs){
	*this = *this / rhs;
	return *this;
}

id1 id1::operator%(const id1 & rhs) const{
	return divmod(*this, rhs).second;
}

id1 & id1::operator%=(const id1 & rhs){
	*this = *this % rhs;
	return *this;
}

id1 & id1::operator++(){
	return *this += id3;
}

id1 id1::operator++(int){
	id1 temp(*this);
	++*this;
	return temp;
}

id1 & id1::operator--(){
	return *this -= id3;
}

id1 id1::operator--(int){
	id1 temp(*this);
	--*this;
	return temp;
}

id1 id1::operator+() const{
	return *this;
}

id1 id1::operator-() const{
	return ~*this + id3;
}

const uint64_t & id1::upper() const{
	return UPPER;
}

const uint64_t & id1::lower() const{
	return LOWER;
}

uint8_t id1::bits() const{
	uint8_t out = 0;
	if (UPPER){
		out = 64;
		uint64_t up = UPPER;
		while (up){
			up >>= 1;
			out++;
		}
	}
	else{
		uint64_t low = LOWER;
		while (low){
			low >>= 1;
			out++;
		}
	}
	return out;
}

std::string id1::str(uint8_t base, const unsigned int & len) const{
	if ((base < 2) || (base > 16)){
		throw std::invalid_argument("Base must be in the range [2, 16]");
	}
	std::string out = "";
	if (!(*this)){
		out = "0";
	}
	else{
		std::pair <id1, id1> qr(*this, id0);
		do{
			qr = divmod(qr.first, base);
			out = "0123456789abcdef"[(uint8_t) qr.second] + out;
		} while (qr.first);
	}
	if (out.size() < len){
		out = std::string(len - out.size(), '0') + out;
	}
	return out;
}

id1 operator<<(const bool & lhs, const id1 & rhs){
	return id1(lhs) << rhs;
}

id1 operator<<(const uint8_t & lhs, const id1 & rhs){
	return id1(lhs) << rhs;
}

id1 operator<<(const uint16_t & lhs, const id1 & rhs){
	return id1(lhs) << rhs;
}

id1 operator<<(const uint32_t & lhs, const id1 & rhs){
	return id1(lhs) << rhs;
}

id1 operator<<(const uint64_t & lhs, const id1 & rhs){
	return id1(lhs) << rhs;
}

id1 operator<<(const int8_t & lhs, const id1 & rhs){
	return id1(lhs) << rhs;
}

id1 operator<<(const int16_t & lhs, const id1 & rhs){
	return id1(lhs) << rhs;
}

id1 operator<<(const int32_t & lhs, const id1 & rhs){
	return id1(lhs) << rhs;
}

id1 operator<<(const int64_t & lhs, const id1 & rhs){
	return id1(lhs) << rhs;
}

id1 operator>>(const bool & lhs, const id1 & rhs){
	return id1(lhs) >> rhs;
}

id1 operator>>(const uint8_t & lhs, const id1 & rhs){
	return id1(lhs) >> rhs;
}

id1 operator>>(const uint16_t & lhs, const id1 & rhs){
	return id1(lhs) >> rhs;
}

id1 operator>>(const uint32_t & lhs, const id1 & rhs){
	return id1(lhs) >> rhs;
}

id1 operator>>(const uint64_t & lhs, const id1 & rhs){
	return id1(lhs) >> rhs;
}

id1 operator>>(const int8_t & lhs, const id1 & rhs){
	return id1(lhs) >> rhs;
}

id1 operator>>(const int16_t & lhs, const id1 & rhs){
	return id1(lhs) >> rhs;
}

id1 operator>>(const int32_t & lhs, const id1 & rhs){
	return id1(lhs) >> rhs;
}

id1 operator>>(const int64_t & lhs, const id1 & rhs){
	return id1(lhs) >> rhs;
}

std::ostream & operator<<(std::ostream & stream, const id1 & rhs){
	if (stream.flags() & stream.oct){
		stream << rhs.str(8);
	}
	else if (stream.flags() & stream.dec){
		stream << rhs.str(10);
	}
	else if (stream.flags() & stream.hex){
		stream << rhs.str(16);
	}
	return stream;
}

void solve(){
	

	sca(u32,n,m);

	u64 ans=0;
	u64 mod=E9+7;

	auto C=[&mod](u64 n,u64 k){
		::id1 r=1;
		u64 d=1;
		if(k>n-k)k=n-k;
		forab(i,n-k+1,n){
			r*=i;
			if(d<=k){
				r/=d;
				d++;
			}
		}
		return (r%mod).lower();
	};

	forab(i,1,n){
		ans += C((m-1)+i-1, m-1) * C(m+(n-i+1)-1, m);
		ans %= mod;
	}

	pr((u64)ans);
}
