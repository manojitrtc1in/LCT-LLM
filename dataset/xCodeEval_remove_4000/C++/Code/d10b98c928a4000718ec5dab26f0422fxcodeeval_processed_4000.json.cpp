












template<class T> T read(){
	T result; std::cin>>result; return result;
}







template<class T>
struct int_iter{
	

	using iterator_category = std::random_access_iterator_tag;
	using value_type = T;
	

	using difference_type = T;
	using pointer = T*;
	using reference = T&;

	T x;
	constexpr int_iter(T x):x{x}{}
	T operator*()const{return x;}
	int_iter& operator++(){ ++x; return *this; }
	int_iter& operator--(){ --x; return *this; }


	int_iter& operator op
	int_iter friend operator op(int_iter x, difference_type y){ return x op
	operation(+) operation(-)

	int_iter friend operator+(difference_type y, int_iter x){ return x += y; }


	auto operator op(int_iter const& other) const{return x op other.x;}
	operation(-) operation(<) operation(>) operation(<=) operation(>=) operation(==) operation(!=)


	T operator[](difference_type y)const{ return x+y; }
};

struct unreachable_iter{
	template<class T, class U,
		class=std::enable_if<
			std::is_same<T, unreachable_iter>::value xor std::is_same<U, unreachable_iter>::value, int>
	> friend bool operator!=(T const& first, U const& sec){ return true; }
};

template<class T> auto range(T first, T last);


template<class A, class B=A>
struct Range{
	A first; B last;
	constexpr Range(A first, B last):first{std::move(first)},last{std::move(last)}{}

	

	

	template<class Container> Range(Container& container):
		first(std::begin(container)), last(std::end(container)){}

	constexpr A const& begin() const{return first;}
	constexpr B const& end() const{return last;}
	constexpr auto size() const{ return last-first; }

	Range take(std::size_t len)const{
		return Range{first, std::next(first, len)};
	}
	Range drop(std::size_t len)const{
		return Range{std::next(first, len), last};
	}

	Range const& sort    () const{ std::sort(first, last); return *this; }
	template<class F> Range const& sort_by (F const& compare) const{ std::sort(first, last, compare); return *this; }
	template<class F> Range const& sort_key(F const& key) const{
		std::sort(first, last, [&](auto const& first, auto const& sec){
			return key(first)<key(sec);
		});
		return *this;
	}

	template<class T> Range const& shuffle(T&& engine) const{ std::shuffle(first, last, engine); return *this; }
	Range& unique() { last=std::unique(first, last); return *this; }
	

	auto reverse() const{
		return range(
				std::make_reverse_iterator(last),
				std::make_reverse_iterator(first)
				);
		
	}

	auto const& assign(Range other) const{
		assert(size()==other.size());
		std::copy(other.first, other.last, first);
		return *this;
	}
	auto const& copy_to(A const& iterator) const{
		std::copy(first, last, iterator);
		return *this;
	}
	auto const& copy_to(Range const& range) const{
		std::copy(first, last, range.first);
		return *this;
	}

	template<class F> auto any  (F const& function) const{ return std::any_of(first, last, function); }
	template<class F> auto all  (F const& function) const{ return std::all_of(first, last, function); }
	template<class F> auto none (F const& function) const{ return std::none_of(first, last, function); }
	template<class F> auto count(F const& function) const{ return std::count_if(first, last, function); }
	template<class F> auto find (F const& function) const{ return std::find_if(first, last, function); }
};


template <typename T>
auto id3(const T& x) -> decltype(void(*x), std::true_type());

std::false_type id3(...);

template<class T> auto range(T first, T last){
	if constexpr(std::is_integral<T>::value){
		assert(first<=last);  

		return Range<int_iter<T>>{first, last};
	}else{
		static_assert(decltype(id3(first))::value, "value type is neither integral nor id3");
		return Range<T>{first, last};
	}
}

template<class T> auto range(T&& value){
	using T1=typename std::decay<T>::type;
	if constexpr(std::is_integral<T1>::value)
		return Range<int_iter<T1>>{{{}}, std::forward<T>(value)};
	else
		return Range<typename std::decay<decltype(value.begin())>::type>{std::forward<T>(value)};
}









template<class T, class=std::enable_if<std::is_integral<T>::value, int>>
auto id0(T first){return Range<int_iter<T>, unreachable_iter>{first, {}};}

template<class T> T&& identity(T&& x){ return x; }














int64_t id5(int64_t a, int64_t b, int64_t mod){
	uint64_t result=
		(uint64_t)a*(uint64_t)b-
		uint64_t((long double)a*b/mod)*(uint64_t)mod;
	result+=mod;
	if(result>=uint64_t(mod)){
		result-=mod;
		if(result>=uint64_t(mod)) result-=mod;
	}
	return int64_t(result);
}








template<class T> struct extended_gcd_result { T a, ax; };
template<class T> extended_gcd_result<T> id1(T x, T y){
	static_assert(std::is_signed<T>::value, ""); 

	T a=x,b=y, ax=1,bx=0;
	while(b!=0){
		T q=a/b, t=a%b;
		a=b; b=t;
		t=T(ax-bx*q); ax=bx; bx=t;
	}
	
	return {a, ax};
}






















template<class F, bool comparable=false> struct id4 {
	static auto MOD()

	->decltype(MOD){ return MOD; }
	using T=typename std::decay<decltype(MOD)>::type;

	T val;
	explicit operator T() const { return val; }
	id4():val(){
		
		assert(gdbgetstr(*this));
		
	}
	
	DEFINEGETSTR(id4)
	

	template<class U> static auto id2()->decltype(std::declval<U>()%MOD, void());
	template<class U
		, class=decltype(id2<U>()) 

		> id4(U v)
		{
			id6 (std::is_unsigned<T>::value){
				assert(v>=0);
			}

			
			val=T(v%MOD);
			if(val<0)val+=MOD;
		}

	template<class U> static id4 raw(U value){ 

		assert(0<=value); assert(value<MOD);
		id4 result; result.val=value; return result;
	}


	template <bool _=comparable> \
	[[nodiscard]] typename std::enable_if<_, bool>::type operator OP(id4 b) const { return val OP b.val; }
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)


	[[nodiscard]] id4 operator+() const{ return *this; }
	[[nodiscard]] friend id4 operator-(id4 x) { x.val=x.val?MOD-x.val:0; return x; }
	id4& operator+=(id4 m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	id4& operator-=(id4 m) {
		if(std::is_signed<T>::value){
			if ((val -= m.val) < 0) val += MOD;
		}else{
			if (val < m.val) val+=MOD; 
			val-=m.val;
		}
		return *this;
	}
	id4& operator*=(id4 m) {
		

		

		

		

		

		

		

		

		

		

		



		id6(std::is_same<T, int>::value){
			val = int((int64_t)val*m.val%MOD);
		}else id6(std::is_same<T, int64_t>::value){
			val=id5(val, m.val, MOD);
		}else{
			

			val*=m.val;
			val%=MOD;
			

		}
		return *this;
	}
	template<class U>
	[[nodiscard]] id4 pow(U p) const {
		id6(std::is_signed<U>::value) assert(p>=0);
		id4 a=*this;
		id4 ans = 1; for (; p; p >>= 1, a *= a) if (p&1) ans *= a;
		return ans;
	}
	[[nodiscard]] id4 inv() const {
		auto tmp=id1(val, T(MOD));
		assert(tmp.a==1);
		if(tmp.ax<0)tmp.ax+=MOD;
		return raw(tmp.ax);
	}
	id4& operator/=(id4 m) { return (*this) *= m.inv(); }
	friend std::ostream& operator<<(std::ostream& stream, id4 m) {
		

		if(m.val>MOD/2){
			return stream<<'-'<<MOD-m.val<<'_';
		}else{
			return stream<<m.val<<'_';
		}
	}

	


	ARITHBINARYOP(+) ARITHBINARYOP(-) ARITHBINARYOP(*) ARITHBINARYOP(/)



};

template<class T, T x> struct TGetter{ static T get(){ return x; } };
template<int MOD> using Modular=id4<TGetter<int, MOD>>;
template<int64_t MOD> using Modular64=id4<TGetter<int64_t, MOD>>;
template<int MOD> using ModularComparable=id4<TGetter<int, MOD>, true>;
template<int64_t MOD> using ModularComparable64=id4<TGetter<int64_t, MOD>, true>;
template<int const& MOD> using ModularP=id4<TGetter<int const&, MOD>>; 

template<int64_t const& MOD> using ModularP64=id4<TGetter<int64_t const&, MOD>>; 
















using std::integer_sequence;
using std::index_sequence;
using std::make_integer_sequence;
using std::make_index_sequence;



template<class T, T... values>
struct integer_sequence{
	friend std::ostream& operator<<(std::ostream& stream, integer_sequence const&){
		std::initializer_list<T> data{values...};
		for(auto item: data) stream<<item<<' ';
		return stream;
	}
};

template<std::size_t... values> using index_sequence=integer_sequence<std::size_t, values...>;

template<class T, T first, T... rest>
integer_sequence<T, first, rest...> integer_sequence_concat_helper(
	integer_sequence<T, rest...>
	);

template<class T, bool first_ge_last, T first, T last>
struct make_integer_sequence_range_{};

template<class T, T first, T last>
struct make_integer_sequence_range_<T, true, first, last>{
	using type=integer_sequence<T>;
};

template<class T, T first, T last>
struct make_integer_sequence_range_<T, false, first, last>{
	using type=
		decltype(integer_sequence_concat_helper<T, first>(typename make_integer_sequence_range_<T, first+1>=last, first+1, last>::type{}));
};

template<class T, T first, T last> using make_integer_sequence_range=typename make_integer_sequence_range_<T, first>=last, first, last>::type;
template<std::size_t first, std::size_t last> using make_index_sequence_range=typename make_integer_sequence_range_<std::size_t, first>=last, first, last>::type;

template<class T, T last> using make_integer_sequence=make_integer_sequence_range<T, 0, last>;
template<std::size_t last> using make_index_sequence=make_integer_sequence<std::size_t, last>;

























template<class T> std::ostream& operator<<(std::ostream& stream, std::vector<T> const& data){
	prettybracket('[')
	if(not data.empty()){
		stream<<data[0];
		for(auto iter=std::next(data.begin()); iter!=data.end(); ++iter)
			stream<<prettyseparator<<*iter;
	}
	prettybracket(']')
	return stream;
}

template<class T, std::size_t N> std::ostream& operator<<(std::ostream& stream, std::array<T, N> const& data){
	prettybracket('[')
	if(not data.empty()){
		stream<<data[0];
		for(auto iter=std::next(data.begin()); iter!=data.end(); ++iter)
			stream<<prettyseparator<<*iter;
	}
	prettybracket(']')
	return stream;
}

template<class A, class B> std::ostream& operator<<(std::ostream& stream, std::pair<A, B> const& data){
	prettybracket('(')
	return stream<<data.first<<prettyseparator<<data.second ifpretty(<<')',);
}

template<class... Types, std::size_t... Is>
void tuple_print_helper(std::ostream& stream, std::tuple<Types...> const& data,
		index_sequence<Is...>
		){
	std::initializer_list<int>({
		(
		 stream<<prettyseparator<<std::get<Is+1>(data)
		 , 0)...
	});
}

template<class... Types> std::ostream& operator<<(std::ostream& stream, std::tuple<Types...> const& data){
	if(sizeof...(Types)==0){
		prettybracket("()")
	}else{
		prettybracket('(')
		stream<<std::get<0>(data);
		tuple_print_helper(stream, data, make_index_sequence<sizeof...(Types)-1>{});
		prettybracket(')')
	}
	return stream;
}




































std::string result_gdbgetstr;

void function_take_voidp(void const*){}


friend char const* gdbgetstr(T const& data){ \
	std::stringstream stream; \
	stream<<data; \
	result_gdbgetstr=std::move(stream).str(); \
	return result_gdbgetstr.c_str(); \
}























template<class modular>
std::vector<modular> inverseF(int limit){
	std::vector<modular> inverse(limit);
	inverse[1]=1;
	for(unsigned i=2;i<inverse.size();++i){
		if constexpr(std::is_floating_point<modular>::value){
			

			inverse[i]=1/modular(i);
		}else{
			assert(modular::MOD()%i!=0    or not "Mod is not prime, i is not invertible mod mod");
			inverse[i]=inverse[modular::MOD()%i]*modular::raw(modular::MOD()-modular::MOD()/i);
		}
	}
	return inverse;
}



template<class modular>
std::vector<modular> inverseFactF(int limit, std::vector<modular> inverse={}){
	if(inverse.empty()) inverse=inverseF<modular>(limit);
	else assert((int)inverse.size()==limit);

	inverse[0]=1;
	for(int index=3; index<(int)inverse.size(); ++index)
		inverse[index]*=inverse[index-1];
	return inverse;
}









template<class modular>
std::vector<modular> factF(int limit){
	std::vector<modular> fact(limit);
	fact[0]=1;
	for(int i=1; i<(int)fact.size(); ++i)
		fact[i]=fact[i-1]*i;
	return fact;
}



template<class modular, bool tolerant> struct Comb_internalStructure{
	std::vector<modular> fact, inverseFact;
	modular operator()(int a, int b)const{
		if(tolerant and (b<0 or b>a)) return 0;
		return fact[a]*inverseFact[b]*inverseFact[a-b];
	}
	modular inverseComb(int a, int b)const{
		if(b<0 or b>a) { assert(false); __builtin_unreachable(); }
		return inverseFact[a]*fact[b]*fact[a-b];
	}
	modular walk(int a, int b) const{
		return (*this)(a+b, b);
	}
};

template<class modular, bool tolerant=false>
Comb_internalStructure<modular, tolerant> makeComb(int limit){
	Comb_internalStructure<modular, tolerant> result;
	result.fact=factF<modular>(limit);
	result.inverseFact=inverseFactF<modular>(limit);
	return result;
}

template<class modular>
Comb_internalStructure<modular, true> makeTolerantComb(int limit){ return makeComb<modular, true>(limit); }




using modular=double;

using modular=Modular<998244353>;

auto comb=makeTolerantComb<modular>(int(2e6+1));

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int const number=read<int>();
	

	std::vector<int> count(number);
	


	for(int _=number; _--;){
		auto const it=read<int>()-1;
		count[it]++;
	}

	count.erase(std::remove(begin(count), end(count), 0), end(count));
	
	if(count.size()==1){
		std::cout<<"1\n";
		return;
	}

	std::vector<int> countGcd(number+1); 

	for(int const i: range(0, number)){
		countGcd[std::__gcd(i, number)]++;
	}

	assert(count.size()>=2);
	std::sort(begin(count), end(count));
	std::vector<std::pair<int, int>> countDeduplicated; 

	int last=0;
	for(int const index: range(1, int(count.size())+1)){
		if(index==int(count.size()) or count[index]!=count[index-1]){
			countDeduplicated.push_back({count[index-1], index-last});
			last=index;
		}
	}
	
	auto gcdAll=std::accumulate(begin(count), end(count), 0, [&](auto const& first, auto const& sec){
		return std::__gcd(first, sec);
	});
	assert(number%gcdAll==0);

	int64_t sumSquaredCount_ {};
	for(auto c: count) sumSquaredCount_+=int64_t(c)*c;
	modular sumSquaredCount=sumSquaredCount_;

	auto const denomPart=[&]  (int d)->modular{
		

		

		auto const r=number/d;
		modular tmp=comb.fact[d];
		
		for(auto [c, repetition]: countDeduplicated){
			assert(c%r==0);
			c/=r;
			tmp*=comb.inverseFact[c].pow(repetition);
		}
		return tmp;
	};
	auto const numerPart=[&](int d)->modular{
		assert(d!=1); 


		auto const r=number/d;
		

		

		

		modular tmp = sumSquaredCount/r/r-d;
		return denomPart(d)*number*(1-tmp/d/(d-1));
	};

	modular numer {}, denom {};
	for(int const d: range(1, number+1)) if(countGcd[d]!=0 and gcdAll%(number/d)==0){
		numer+=numerPart(d)*countGcd[d];
		denom+=denomPart(d)*countGcd[d];
	}
	
	std::cout<<int(numer/denom)<<'\n';
}




