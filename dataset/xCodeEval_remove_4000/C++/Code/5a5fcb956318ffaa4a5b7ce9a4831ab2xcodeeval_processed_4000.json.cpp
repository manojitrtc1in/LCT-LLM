















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

	template<class Container> Container collect() const{return Container(first, last);}

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
		assert(MOD>0);
		
		assert(gdbgetstr(*this));
		
	}
	
	DEFINEGETSTR(id4)
	

	template<class U> static auto id2()->decltype(std::declval<U>()%MOD, void());
	template<class U
		, class=decltype(id2<U>()) 

		> id4(U v)
		{
			assert(MOD>0);
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















struct Empty{ int _[0];
	bool operator==(Empty) const{return true;}
	bool operator!=(Empty) const{return false;}
};

std::ostream& operator<<(std::ostream& stream, Empty ){
	return stream<<"{}";
}



template<class EdgeWeight_=Empty>
struct Graph{
	using EdgeWeight=EdgeWeight_;

	static constexpr bool weightedEdge=not std::is_same<EdgeWeight, Empty>::value;

	struct Edge{
		int node; EdgeWeight weight;
	};
	std::vector<std::vector<Edge>> add;

	Graph(std::vector<std::vector<Edge>> add): add(std::move(add)){}
	Graph(int numNode): add(numNode){}
	Graph(){
		
		assert(gdbgetstr(*this));
		
	}
	
	DEFINEGETSTR(Graph)
	

	

	auto& operator[](int index){ return add[index]; }
	auto const& operator[](int index) const{ return add[index]; }
	auto size() const{return add.size();}


	template<bool directed> void addEdge(int first, int sec, EdgeWeight weight={}){
		if constexpr(not directed)
			add[sec].push_back({first, weight});
		add[first].push_back({sec, std::move(weight)});
	}

	void addEdgeDirected(int first, int sec, EdgeWeight weight){ addEdge<true>(first, sec, std::move(weight)); }
	void addEdgeUndirected(int first, int sec, EdgeWeight weight){ addEdge<false>(first, sec, std::move(weight)); }

	template<bool okay=not weightedEdge, class=typename std::enable_if<okay, int>::type>
	void addEdgeDirected(int first, int sec){ addEdgeDirected(first, sec, {}); }

	template<bool okay=not weightedEdge, class=typename std::enable_if<okay, int>::type>
	void addEdgeUndirected(int first, int sec){ addEdgeUndirected(first, sec, {}); }

	template<bool directed> void read(int numNode, int numEdge){
		assert(add.empty()); add.resize(numNode);
		for(int _=0;_<numEdge;++_){
			int first, sec; std::cin>>first>>sec;
			--first;--sec;
			EdgeWeight weight{};
			if constexpr(weightedEdge){
				std::cin>>weight;
			}
			addEdge<directed>(first, sec, weight);
		}
	}

	void readUndirected(int numNode, int numEdge){ return read<false>(numNode, numEdge); }
	void readDirected(int numNode, int numEdge){ return read<true>(numNode, numEdge); }

	void readUndirected(){
		int numNode, numEdge; std::cin>>numNode>>numEdge;
		read<false>(numNode, numEdge);
	}

	

	void mapEdge(auto f ) const{
		for(int node=0; node<(int)add.size(); ++node)
			for(auto const& [target, weight]: add[node]){
				f(node, target, weight);
			}
	}

	template<bool reverse=false>
	auto transformEdge(auto f ) const{
		using ResultEdgeValue=std::decay_t<decltype(f(std::declval<EdgeWeight>()))>;
		Graph<ResultEdgeValue> result((int)add.size());
		mapEdge([&](int a, int b, auto const& weight){
			if(reverse) std::swap(a, b);
			result.addEdgeDirected(a, b, f(weight));
		});
		return result;
	}

	auto reverseEdge(auto f) const{
		return transformEdge<true>(f);
	}

	auto reverseEdge() const{
		return reverseEdge([&](auto const& it){
			return it;
		});
	}

	friend decltype(auto) operator<<(std::ostream& stream, Graph const& data){
		bool first=true;
		stream<<"Graph{";
		for(int node=0; node<(int)data.size(); ++node){
			for(auto [other, weight]: data.add[node]) {
				if(first) first=false; else stream<<", ";
				if constexpr(decltype(data)::weightedEdge){
					stream<<node<<" --("<<weight<<")-> "<<other;
				}else{
					stream<<node<<" -> "<<other;
				}
			}
		}
		return stream<<"}";
	}
};













template<class EdgeWeight,
	bool par_,
	bool depth_,
	bool subtreeSize_,
	bool visited_=false,
	bool orderOf_=false,
	bool low_=false,
	bool postorder_=false,
	bool lastOrderOf_=false,
	class Custom=Empty  

	>
struct Dfs{
	Graph<EdgeWeight> const& graph;
	using Edge=typename Graph<EdgeWeight>::Edge;

	static bool constexpr custom_=not std::is_same<Custom, Empty>::value;

	std::conditional_t<par_        , std::vector<Edge>, Empty> par        ;
	std::conditional_t<depth_      , std::vector<int> , Empty> depth      ;
	std::conditional_t<subtreeSize_, std::vector<int> , Empty> subtreeSize;
	std::conditional_t<visited_    , std::vector<char>, Empty> visited    ;
	std::conditional_t<orderOf_    , std::vector<int> , Empty> orderOf    ;
	std::conditional_t<lastOrderOf_, std::vector<int> , Empty> lastOrderOf;
	std::conditional_t<orderOf_    , int              , Empty> lastOrder  ;
	std::conditional_t<low_        , std::vector<int> , Empty> low        ;
	std::conditional_t<postorder_  , std::vector<int> , Empty> postorder  ;  


	typename std::conditional<custom_, std::vector<Custom>, Empty>::type custom;

	Dfs(Graph<EdgeWeight> const& graph, int root=-1): graph(graph){
		if constexpr(par_) {
			static_assert(not visited_);
			par.assign(graph.size(), {-1, {}});
			par[root]={-1, {}};
		}
		if constexpr(depth_) {
			depth.assign(graph.size(), 0);
			

		}
		if constexpr(subtreeSize_) subtreeSize.assign(graph.size(), 1);
		if constexpr(visited_) visited.assign(graph.size(), false);
		if constexpr(orderOf_){ orderOf.resize(graph.size(), -1); lastOrder=0; }
		if constexpr(lastOrderOf_){ lastOrderOf.resize(graph.size(), -1); lastOrder=0; }
		if constexpr(postorder_) postorder.reserve(graph.size());
		static_assert(not (visited_ and orderOf_), "orderOf can be used to deduce visited");
		if constexpr(low_){
			static_assert(orderOf_, "cannot compute low without orderOf");
			low.resize(graph.size());
		}

		if constexpr(custom_){
			

			custom.assign(graph.size(), {});
		}

		if constexpr(visited_){
			assert(root==-1);
			for(int node=0; node<(int)graph.size(); ++node){
				if(not visited[node]) runInternal(node);
			}
		}else{
			runInternal(root);
		}
	}


	void runInternal(int node){ 

		

		if constexpr(subtreeSize_) subtreeSize[node]=1;
		if constexpr(visited_){
			assert(not visited[node]);
			visited[node]=true;
		}
		if constexpr(orderOf_){
			assert(orderOf[node]==-1);
			orderOf[node]=lastOrder++;
		}
		if constexpr(low_){
			low[node]=lastOrder;
		}
		for(auto [child, weight]: graph.add[node]) {
			if constexpr(visited_){
				if(visited[child]) {
					continue;
				}
			}else if constexpr(par_)
				if(child==par[node].node) continue;

			if constexpr(par_) par[child]={node, weight};
			if constexpr(depth_) depth[child]=depth[node]+1;
			if constexpr(custom_) {
				

			}

			runInternal(child);
			
			if constexpr(subtreeSize_) subtreeSize[node]+=subtreeSize[child];
		}
		if constexpr(lastOrderOf_) lastOrderOf[node]=lastOrder;
		if constexpr(postorder_) postorder.push_back(node);
	}


};








template<class T=int, class U=T, class V=std::common_type_t<T, U, int64_t>, bool always_simplify=true>
struct Fraction{
	T numer; U denom;

	

	constexpr Fraction(T x={}): numer(x), denom(1) {}

	

	constexpr Fraction(T a, U b): numer(a), denom(b) {
		if constexpr(std::is_signed<U>::value){
			if(denom<0){ numer=-numer; denom=-denom; }
		}
		if constexpr(always_simplify) *this=this->_simplify();
	}

	static Fraction rawx(T a, U b){
		

		Fraction result; result.numer=a; result.denom=b; return result;
	}

	template<bool X=always_simplify>
	static Fraction raw(T a, U b){
		

		static_assert(X==always_simplify and X, "if not always_simplify just use constructor?");
		assert(std::__gcd(a, b)==1 and b>0);
		return rawx(a, b);
	}

	void constexpr check() const{
		assert(denom>0);
		if constexpr(always_simplify)
			assert(std::__gcd(numer, denom)==1);
	}


		check(); other.check();                                                     \
		return (V)numer*other.denom OP (V)other.numer*denom;                \
	}
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)


	template<class W> explicit operator W() const{
		static_assert(not std::is_integral<W>::value);
		return W(numer)/W(denom);
	}

	private:
	[[nodiscard]] Fraction _simplify() const{
		auto g=std::__gcd(numer, denom);
		if constexpr(std::is_signed<U>::value){
			assert(g>0);
			assert(denom>0);
		}
		return rawx(numer/g, denom/g);
	}
	public:

	template<bool X=always_simplify> 

	[[nodiscard]] Fraction simplify() const{
		static_assert(X==always_simplify and not X, "no need to simplify if always_simplify is on");
		return _simplify();
	}

	[[nodiscard]] Fraction operator*(Fraction other)const{ return Fraction{numer*other.numer, denom*other.denom}; }
	[[nodiscard]] Fraction operator/(Fraction other)const{ return Fraction{numer*other.denom, denom*other.numer}; }

	[[nodiscard]] Fraction operator+(Fraction other)const{ return Fraction{numer*other.denom+denom*other.numer, denom*other.denom}; }
	[[nodiscard]] Fraction operator-(Fraction other)const{ return Fraction{numer*other.denom-denom*other.numer, denom*other.denom}; }


	ASSIGNOP(+) ASSIGNOP(-) ASSIGNOP(*) ASSIGNOP(/)


	friend std::ostream& operator<<(std::ostream& stream, Fraction const& f){
		if(f.denom==1){
			return stream<<f.numer;
		}else{
			return stream<<f.numer<<'/'<<f.denom;
		}
	}
};
















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



int mod;
using modular=ModularP<mod>;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int const number=read<int>();
	std::cin>>mod;

	auto const comb=makeComb<modular>(number);

	Graph<> g;
	g.readUndirected(number, number-1);
	
	int const root=0;
	auto tmp=Dfs<decltype(g)::EdgeWeight,
		 true, 

		 false, 

		 false, 

		 false, 

		 false, 

		 false, 

		 true, 

		 false 

	>{g, root};
	auto const par=std::move(tmp.par);
	auto const postorder=std::move(tmp.postorder);

	for(int const node: range(0, number)) if(node!=root){
		g[node].erase(std::find_if(begin(g[node]), end(g[node]), [&](auto const& it){
			return it.node==par[node].node;
		}));
	}


	std::vector<std::vector<modular>> f(number-1, std::vector<modular>(number));


	std::vector<modular> result(number-1);

	using F=Fraction<modular, modular, modular, false>;

	for(auto node: postorder){

		modular sh {};
		std::vector<modular> tmp(number);

		for(int const max: range(0, number-1)){

			std::vector<modular> hPrefix(int(g[node].size()+1)), hSuffix(int(g[node].size()+1));
			hPrefix[0]=hSuffix.back()=1;
			for(int const i: range(0, int(g[node].size()))){
				hPrefix[i+1]=hPrefix[i]*f[max][g[node][i].node];
			}
			for(int i=int(g[node].size()); i--;)
				hSuffix[i]=hSuffix[i+1]*f[max][g[node][i].node];
	


			sh+=hSuffix[0];
			f[max][node]+=sh*(1-int(g[node].size()));

			for(int const i: range(0, int(g[node].size()))){
				auto const largeChild=g[node][i].node;
				tmp[largeChild] += hPrefix[i]*hSuffix[i+1];
				f[max][node]+= f[max][largeChild] * tmp[largeChild];
			}
		}
	}

	for(int const max: range(0, number-1)){
		modular result_=1;
		for(auto [child, _]: g[root]) result_*=f[max][child];

		for(int const max1: range(0, max)){
			result_-=comb(max+1, max1+1)*result[max1];
		}

		result[max]=result_;

		std::cout<<
			int(result_)
			<<' ';
	}
	std::cout<<'\n';
}
