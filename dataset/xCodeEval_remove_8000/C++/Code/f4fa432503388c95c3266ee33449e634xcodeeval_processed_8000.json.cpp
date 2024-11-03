


































template<class T> T read(){
	T result;
	std::cin>>result;
	assert(std::cin);
	return result;
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
auto id4(const T& x) -> decltype(void(*x), std::true_type());

std::false_type id4(...);

template<class T> auto range(T first, T last){
	if constexpr(std::is_integral<T>::value){
		assert(first<=last);  

		return Range<int_iter<T>>{first, last};
	}else{
		static_assert(decltype(id4(first))::value, "value type is neither integral nor id4");
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



template<class T> auto reverse_range(T& value){
	return range(value.rbegin(), value.rend());
}








template<class T, class=std::enable_if<std::is_integral<T>::value, int>>
auto id7(T first){return Range<int_iter<T>, unreachable_iter>{first, {}};}

template<class T> T&& identity(T&& x){ return x; }









auto ceilDiv(auto a, auto b){
	return (a+b-1)/b;
}










template<class X, class Y, class CompareXT, class CompareYT,
	bool id9=false, bool id2=false
	>
struct KeepLD_{
	

	CompareYT compareY;

	std::map<X, Y, CompareXT> items;  

	


	void add(X x, Y y){
		auto [iter, inserted]=items.insert({x, y});
		if(not inserted){
			

			if(compareY(y, iter->second)){
				

				iter->second=y;
				++iter;
				while(iter!=items.end() and not compareY(iter->second, y))
					iter=items.erase(iter);
				checkConsistency();
				return;
			}else{
				

				checkConsistency();
				return;
			}
		}

		assert(inserted);
		if(iter!=items.begin() and not compareY(y, std::prev(iter)->second)){
			

			items.erase(iter);
			checkConsistency();
			return;
		}

		++iter;
		while(iter!=items.end() and not compareY(iter->second, y))
			iter=items.erase(iter);

		checkConsistency();
	}

	void checkConsistency() const{
		
			
		
		assert(std::is_sorted(
					begin(items), end(items),
					[&](auto const& first, auto const& sec){
						return compareY(sec.second, first.second);
					}));

		
	}

	struct QueryResult{
		bool have;
		X x_;
		Y y_;
		X x() const{assert(have); return x_;}
		Y y() const{assert(have); return y_;}
	};

	

	

	QueryResult maxYXGEPrimitive(X x) const{
		auto iter=items.lower_bound(x);
		if(iter==items.end()) return {false, {}, {}};
		return {true, iter->first, iter->second};
	}

	QueryResult maxYXGTPrimitive(X x) const{
		auto iter=items.upper_bound(x);
		if(iter==items.end()) return {false, {}, {}};
		return {true, iter->first, iter->second};
	}

	QueryResult minYXLTPrimitive(X x) const{
		auto iter=items.lower_bound(x);
		if(iter==items.begin()) return {false, {}, {}};
		--iter;
		return {true, iter->first, iter->second};
	}

	QueryResult minYXLEPrimitive(X x) const{
		auto iter=items.upper_bound(x);
		if(iter==items.begin()) return {false, {}, {}};
		--iter;
		return {true, iter->first, iter->second};
	}

	

	

	

	template<bool Enable=id9==id2> \
	std::enable_if_t< Enable, QueryResult > mxx 
		return id9 ? myy 
	} \
	template<bool Enable=id9!=id2> \
	std::enable_if_t< Enable, QueryResult > myy 
		return id9 ? myy 
	}

	D(max, GE, min, LE)
	D(max, GT, min, LT)
	D(min, LT, max, GT)
	D(min, LE, max, GE)
	


};

template<class X, class Y, class CompareXT, class CompareYT,
	bool id9=false, bool id2=false
	>
auto keepLD(CompareXT compareX, CompareYT compareY){
	return KeepLD_<X, Y, CompareXT, CompareYT, id9, id2>{compareY, {compareX}};
}





template<class X, class Y=X> using KeepLD=KeepLD_<X, Y, std::less<X>, std::less<Y>>;
template<class X, class Y=X> using KeepLU=KeepLD_<X, Y, std::less<X>, std::greater<Y>, false, true>;
template<class X, class Y=X> using KeepRD=KeepLD_<X, Y, std::greater<X>, std::less<Y>, true, false>;
template<class X, class Y=X> using KeepRU=KeepLD_<X, Y, std::greater<X>, std::greater<Y>, true, true>;

template<class X, class Y=X> using KeepInner=KeepRD<X, Y>; 

template<class X, class Y=X> using KeepOuter=KeepLU<X, Y>; 



























template <class F, class... X>
auto id8(F&& f, X&&... x) -> decltype(void(std::forward<F>(f)(std::forward<X>(x)...)), std::true_type());

std::false_type id8(...);












bool evaluatesToTrue(auto const& fn){ 

	if constexpr(std::is_same<decltype(fn()),void>::value){
		fn(); return false;
	}else{
		return fn();
	}
}







template <bool first, class Detail, class Data>
auto id13(Data& data, int layer) -> decltype(void(
			Detail::template combine<first>(data, data, data, layer)
			), std::true_type());
template <bool first, class Detail>
std::false_type id13(...);



template <class Node, class Detail>
struct id3{
	std::vector<Node> data;

	id3(){}
	id3(int number){ assign(number); }
	id3(std::size_t number){ assign(number); }
	id3(auto&& container){ assign(container.begin(), container.end()); }
	template<class First, class Last, class=decltype(std::declval<First>()[0])>
	id3(First first, Last last){ assign(first, last); }
	id3(int number, Node const& node){ assign(number, node); }
	


	

	void assign(int number){
		assign(number, Node{});
	}
	void assign(int number, Node const& node){ assign(number, [&]{ return node; }); }
	void assign(int number, auto const& generator){
		data.reserve(number*2); data.resize(number);
		for(int i=0; i<number; ++i) {
			if(data.size()>=data.capacity()) __builtin_unreachable();
			if constexpr(decltype(id8(generator, 0))::value){
				data.push_back(generator(i));
			}else{
				data.push_back(generator());
			}
		}
		for(int i=number; --i;) combineAt<true>(i);
	}
	template<class First, class Last>
	void assign(First first, Last last){
		assign(int(last-first), [&](int index){ return first[index]; });
	}

	private:

	template<class F, class T>
	static decltype(auto) id10(F const& f, T&& t, int layer) {
		if constexpr(decltype(id8(f, std::forward<T>(t)))::value) return f(std::forward<T>(t));
		else {
			assert(layer>=0);
			return f(std::forward<T>(t), layer);
		}
	}

	public:
	static void forAncestorIndexDown(int node,auto const& fn){
		for(int shift=31^__builtin_clz(node);shift>=0;--shift)
			if(IS_TRUE(fn(node>>shift))) break;
	}
	static void forStrictAncestorIndexDown(int node,auto const& fn
            

            ){
		for(int shift=31^__builtin_clz(node);shift;--shift)
			if(IS_TRUE(id10(fn, node>>shift, shift))) break;
	}
	static void forAncestorIndexUp(int node,auto const& fn){
		for(int y=node;y;y>>=1)
			if(IS_TRUE(fn(y))) break;
	}
	static void forStrictAncestorIndexUp(int node,auto const& fn){
		forAncestorIndexUp(node>>1, fn);
	}
	static void forRangeIndex_(int leftNode, int rightNode, auto const& leftfn, auto const& rightfn){
		

		


		

		assert(leftNode<=rightNode);
		if(leftNode==rightNode) return;
		int layer=0;
		while(leftNode<rightNode){
			if(leftNode&1) if(IS_TRUE(id10(leftfn, leftNode++, layer))) break;
			if(rightNode&1) if(IS_TRUE(id10(rightfn, --rightNode, layer))) break;
			leftNode>>=1;rightNode>>=1; ++layer;
		}
	}
	void forRangeIndex(int leftNode, int rightNode, auto const& leftfn, auto const& rightfn)const{
		

		assert(leftNode>=offset());
		assert(rightNode>=offset());
		forRangeIndex_(leftNode, rightNode, leftfn, rightfn);
	}
	int layerOf(int node) const{
		

		assert(node<(int)data.size());
		int layer=std::max(0, (31^__builtin_clz((int)data.size()))-(31^__builtin_clz(node))-1);
		if((node<<layer)<offset()) ++layer;
		assert((node<<layer)>=offset());
		assert((node<<layer)<(int)data.size());
		return layer;
	}
	int leftLeaf(int node) const{
		return node<<layerOf(node);
	}
	int rightLeaf(int node) const{
		return ((node+1)<<layerOf(node))-1;
	}

	auto rangeIterate(int left, int right){ struct Result{ int node, left1; };
		

		

		assert(offset()<=left);
		assert(left<right);
		assert(right<=offset()*2);

		auto bit=left&-left;
		if(left+bit<=right){
			return Result{left>>__builtin_ctz(bit), left+bit};
		}
		int pos=31^__builtin_clz(left xor right);
		return Result{left>>pos, left+(1<<pos)};
	}

	void forRangeIndexOrdered(int leftNode, int rightNode, auto f){
		int tmp=leftNode;
		while(tmp!=rightNode){
			

			

			auto [node, tmpx]=rangeIterate(tmp, rightNode);
			tmp=tmpx;
			f(node);
		}
	}

	

	std::vector<int> rangeIndices(int leftNode, int rightNode)const{
		std::vector<int> left, right;
		forRangeIndex(leftNode, rightNode, [&](auto const& it){
			left.push_back(it);
		}, [&](auto const& it){
			right.push_back(it);
		});
		left.insert(left.end(), right.rbegin(), right.rend());
		return left;
	}

	auto rangeIndicesWithLayer(int leftNode, int rightNode)const{
		struct Item{int node, layer;};
		std::vector<Item> left, right;

		forRangeIndex(leftNode, rightNode, [&](int nodeIndex, int layer){
			left.push_back({nodeIndex, layer});
		}, [&](int nodeIndex, int layer){
			right.push_back({nodeIndex, layer});
		});
		left.insert(left.end(), right.rbegin(), right.rend());
		return left;
	}



	

	

	int leftmostSatisfy(int leftNode, int rightNode, auto const& func ){
		if(leftNode==rightNode) return -1;
		pushAll(leftNode); pushAll(rightNode-1);
		int result=-1;
		forRangeIndex(leftNode, rightNode, [&](int node){
			if(func(node)) { result=node; return true; }
			return false;
		}, [&](int node){
			if(func(node)) result=node;
		});
		if(result<0) return -1;
		while(result<offset()){
			pushAt(result);
			result<<=1;
			if(not func(result)) ++result;
		}
		return result-offset();
	}
	int rightmostSatisfy(int leftNode, int rightNode, auto const& func ){
		if(leftNode==rightNode) return -1;
		pushAll(leftNode); pushAll(rightNode-1);
		int result=-1;
		forRangeIndex(leftNode, rightNode, [&](int node){
			if(func(node)) result=node;
		}, [&](int node){
			if(func(node)) { result=node; return true; }
			return false;
		});
		if(result<0) return -1;
		while(result<offset()){
			pushAt(result);
			result<<=1;
			if(func(result+1)) ++result;
		}
		assert(result>=0);
		return result-offset();
	}
	void forRangeIndex(int leftNode, int rightNode, auto const& fn){
		forRangeIndex(leftNode,rightNode,fn,fn);
	}
	int size()const{ return int(data.size()/2u); }
	int offset()const{ return size(); }

	

	static void push(Node&, Node&, Node&, int ){
    }

	void pushAt(int node, int nodeLayer){
		assert(1<=node); assert(node<offset());
		static_cast<Detail*>(this)->push(data[node], data[node<<1], data[node<<1|1], nodeLayer);
	}

	void pushAt(int node){
        pushAt(node, layerOf(node));
    }

	void pushAll(int node){
		assert(node>=offset());
		forStrictAncestorIndexDown(node, [&](int node, int layer){
			pushAt(node, layer);
		});
	}

	template<bool first> void combineAt(int node, int layer){
		if constexpr(decltype(id13<first, Detail>(data[0], layer))::value){
			assert(layer==layerOf(node));
			Detail::template combine<first>(data[node], data[node<<1], data[node<<1|1], layer);
		}else{
			Detail::template combine<first>(data[node], data[node<<1], data[node<<1|1]);
		}
	}

	template<bool first> void combineAt(int node){
		combineAt<first>(node, layerOf(node));
	}

	void combineAll(int node){
		assert(node>=offset());
		forStrictAncestorIndexUp(node, [&](int it){
			combineAt<false>(it);
		});
	}

    

	void forRange(int leftNode, int rightNode, auto const& leftfn, auto const& rightfn
			

			)const{
		forRangeIndex(leftNode, rightNode,
				[&](auto it, auto layer){ return id10(leftfn,  data[it], layer); },
				[&](auto it, auto layer){ return id10(rightfn, data[it], layer); });
	}

	void forRange(int leftNode, int rightNode, auto const& fn)const{
		forRange(leftNode,rightNode,fn,fn);
	}


	void forRange(int leftNode, int rightNode, auto const& leftfn, auto const& rightfn
			

			){
		forRangeIndex(leftNode, rightNode,
				[&](auto it, auto layer){ return id10(leftfn,  data[it], layer); },
				[&](auto it, auto layer){ return id10(rightfn, data[it], layer); });
	}

	void forRange(int leftNode, int rightNode, auto const& fn){
		forRange(leftNode,rightNode,fn,fn);
	}
    



	static Node combined(Node const& left, Node const& right){
		

		Node result;
		Detail::template combine<true>(result, left, right);
		return result;
	}

	Node combinedRange1NoPush(int left, int right, Node leftMerge, Node rightMerge) const{
		

		assert(0<=left); assert(left<=right); assert(right<=offset());

		auto leftNode=left+offset(), rightNode=right+offset();

		Node leftAnswer=leftMerge, rightAnswer=rightMerge;
        forRange(leftNode, rightNode,
                [&](Node node){ leftAnswer=combined(leftAnswer, node); },
                [&](Node node){ rightAnswer=combined(node, rightAnswer); }
                );
		return combined(leftAnswer, rightAnswer);
	}

	Node combinedRangeNoPush(int left, int right, Node identity) const{
		return combinedRange1NoPush(left, right, identity, identity);
	}

	

	Node combinedRangeNoPush(int left, int right) const{
		assert(left<right);
		if(left+1==right) return data[left+offset()];
		return combinedRange1NoPush(left+1, right-1, data[left+offset()], data[right+offset()-1]);
	}

	Node combinedRange(int left, int right, Node identity) {
        if(left<right){
            pushAll(left+offset());
            pushAll(right-1+offset());
        }
        return combinedRangeNoPush(left, right, identity);
    }

	Node combinedRange(int left, int right) {
        if(left<right){
            pushAll(left+offset());
            pushAll(right-1+offset());
        }
        return combinedRangeNoPush(left, right);
    }

	template<class T> T reduceRange(int leftNode, int rightNode, T initial, auto const& function ) const {
		

		

		forRange(leftNode, rightNode, [&](Node const& node){ initial=function(std::move(initial), node); });
		return initial;
	}

	auto longestPrefixSatisfy(int const left, int right, Node identity, auto condition  ){
		struct{
			Node node;
			int len;
			int right; 

		}result{identity, 0, 0};

		auto const nodes=rangeIndicesWithLayer(left+offset(), right+offset());
		assert(condition(identity));

		for(auto [x, layer]: nodes){
			assert(
					condition(combined(result.node, data[x]))==
					condition(combined(identity, combined(result.node, data[x])))
				  );
			if(condition(combined(result.node, data[x]))){
				result.node=combined(result.node, data[x]);
				result.len+=1<<layer;
			}else{
				while(layer){
					x<<=1; layer--;
					if(condition(combined(result.node, data[x]))){
						result.node=combined(result.node, data[x]);
						result.len+=1<<layer;
						x++;
						assert(not condition(combined(result.node, data[x])));
					}
				}
				assert(x>=offset());
				break;
			}
		}

		result.right=left+result.len;
		return result;
	}
};

















struct closestNextLarger_node{
	int v=-1;
};

struct closestNextLarger_segmenttree: id3<closestNextLarger_node, closestNextLarger_segmenttree>{  

	using id3::id3;
	

	template<bool first>
	static void combine(closestNextLarger_node& parent, closestNextLarger_node const& left, closestNextLarger_node const& right){
		parent.v=std::max(left.v, right.v);
	}


	void set(int index, int value){
		index+=offset();
		data[index].v=value;
		combineAll(index);
	}

	int get(int left, int right){
		if(left==right) return 0;
		assert(left<=right);
		left+=offset(); right+=offset();
		pushAll(left); pushAll(right-1);
		return reduceRange(left, right, -1, [&](int result, closestNextLarger_node const& node){ return std::max(result, node.v); });
	}
};

std::vector<int> closestPrevInValueRange(
		auto const& container, 

		int endValue,        

		auto valueMapper,    

		auto id1, 

		auto id11 

		){
	

	closestNextLarger_segmenttree tree(endValue);
	int index=0;
	std::vector<int> result(container.size());
	for(auto value: container){
		result[index]=tree.get(valueMapper(id1(value)), valueMapper(id11(value)));
		tree.set(valueMapper(value), index);
		index++;
	}
	return result;
}

std::vector<int> closestPrevInValueRange(auto const& container, int endValue,
		auto id1,
		auto id11
		){
	return closestPrevInValueRange(container, endValue, [&](int value){ return value; }, id1, id11);
}


std::vector<int> closestPrevLT(auto const& container, int endValue){
	return closestPrevInValueRange(container, endValue,
			[&](int value){return 0;},
			[&](int value){return value;});
}

std::vector<int> closestPrevLE(auto const& container, int endValue){
	return closestPrevInValueRange(container, endValue,
			[&](int value){return 0;},
			[&](int value){return value+1;});
}

std::vector<int> closestPrevGT(auto const& container, int endValue){
	return closestPrevInValueRange(container, endValue,
			[&](int value){return value+1;},
			[&](int value){return endValue;});
}

std::vector<int> closestPrevGE(auto const& container, int endValue){
	return closestPrevInValueRange(container, endValue,
			[&](int value){return value;},
			[&](int value){return endValue;});
}





std::vector<int> closestNext
	std::vector<int> containerReversed(container.rbegin(), container.rend()); \
	auto result=closestPrev
	std::reverse(begin(result), end(result)); \
	for(auto& value: result) \
		value=int(result.size())-1-value; \
	return result; \
}

id15(LT)
id15(LE)
id15(GT)
id15(GE)






















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
integer_sequence<T, first, rest...> id17(
	integer_sequence<T, rest...>
	);

template<class T, bool id14, T first, T last>
struct make_integer_sequence_range_{};

template<class T, T first, T last>
struct make_integer_sequence_range_<T, true, first, last>{
	using type=integer_sequence<T>;
};

template<class T, T first, T last>
struct make_integer_sequence_range_<T, false, first, last>{
	using type=
		decltype(id17<T, first>(typename make_integer_sequence_range_<T, first+1>=last, first+1, last>::type{}));
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
void id12(std::ostream& stream, std::tuple<Types...> const& data,
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
		id12(stream, data, make_index_sequence<sizeof...(Types)-1>{});
		prettybracket(')')
	}
	return stream;
}




































std::string id0;

void id5(void const*){}


friend char const* id6(T const& data){ \
	std::stringstream stream; \
	stream<<data; \
	id0=std::move(stream).str(); \
	return id0.c_str(); \
}













struct Node{
	int minimum=INT_MAX;
};
struct SegmentTree: id3<Node, SegmentTree>{
	using id3::id3;
	

	template<bool first>
	static void combine(Node& parent, Node const& left, Node const& right){
		parent.minimum=std::min(left.minimum, right.minimum);
    }

	void set(int index, int value){
		index+=offset();
		debug("set", index, "to", value)
		data[index].minimum=value;
		combineAll(index);
	}

	int getMinimum(int left, int right){
		assert(left<=right);
		left+=offset(); right+=offset();
		return reduceRange(left, right, INT_MAX, [&](int result, Node const& node){ 
			return std::min(result, node.minimum);
		});
	}

	int operator[](int index){
		index+=offset();
		return data[index].minimum;
	}

};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int const number=read<int>();
	std::vector<int> p(number);
	for(auto& it: p) {
		std::cin>>it; --it;
	}

	KeepInner<int> disallowed;
	
	
	auto const id16=[&](std::vector<int> p){

		auto next=closestNextGT(p, number);
		auto prev=closestPrevLT(p, number);

		SegmentTree nextValues(number);  


		int left=0, right=0;
		while(true){

			

			



			if(right==left or nextValues.getMinimum(p[right-1]+1, number)>=prev[right-1]){
				

				


				while(true){
					if(right==number){
						return;
					}

					assert(nextValues[p[right]]==INT_MAX);
					nextValues.set(p[right], next[right]);
					++right;

					

					int const p2=right-1;
					int const p1=prev[p2];
					debug(p2, p1, nextValues.getMinimum(p[right-1]+1, number))
					if(nextValues.getMinimum(p[right-1]+1, number)<p1){
						

						break;
					}
				}
			}

			

			disallowed.add(left, right);
			debug(left, right);

			assert(left<right); 

			assert(nextValues[p[left]]==next[left]);
			nextValues.set(p[left], INT_MAX);
			++left;
		}
	};

	id16(p);
	for(auto& x: p) x=number-1-x;
	id16(p);

	int64_t result {};
	int lastx=0;
	for(auto [l, r]: reverse_range(disallowed.items)){
		assert(l>=lastx);
		result+=(l+1-lastx)*int64_t(number-r+1);
		lastx=l+1;
	}
	std::cout<<number*int64_t(number+1)/2-result<<'\n';
}


