






















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
auto id2(const T& x) -> decltype(void(*x), std::true_type());

std::false_type id2(...);

template<class T> auto range(T first, T last){
	if constexpr(std::is_integral<T>::value){
		assert(first<=last);  

		return Range<int_iter<T>>{first, last};
	}else{
		static_assert(decltype(id2(first))::value, "value type is neither integral nor id2");
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
auto id3(T first){return Range<int_iter<T>, unreachable_iter>{first, {}};}

template<class T> T&& identity(T&& x){ return x; }






struct Data{
	std::vector<std::array<bool, 2>> have;
	Data(int len): have(len){}

	void add(int index, int side){
		assert(not have[index][side]);
		have[index][side]=true;
	}

	void remove(int index, int side){
		assert(have[index][side]);
		have[index][side]=false;
	}

	int compute(int pos){
		int numStep=0;
		while(pos!=0){
			pos=std::min({
				int(have.rend()-std::find_if(have.rend()-pos, have.rend(), [&](auto const& it){
					return it[0];
				})),
				int(have.rend()-std::find_if(have.rend()-pos, have.rend(), [&](auto const& it){
					return it[1];
				})),
			})-1;
			++numStep;
		}
		return numStep;
	}
};

















template <class F, class... X>
auto id4(F&& f, X&&... x) -> decltype(void(std::forward<F>(f)(std::forward<X>(x)...)), std::true_type());

std::false_type id4(...);












bool id0(auto const& fn){ 

	if constexpr(std::is_same<decltype(fn()),void>::value){
		fn(); return false;
	}else{
		return fn();
	}
}







template <bool first, class Detail, class Data>
auto id6(Data& data, int layer) -> decltype(void(
			Detail::template combine<first>(data, data, data, layer)
			), std::true_type());
template <bool first, class Detail>
std::false_type id6(...);



template <class Node, class Detail>
struct id1{
	std::vector<Node> data;

	id1(){}
	id1(int number){ assign(number); }
	id1(std::size_t number){ assign(number); }
	id1(auto&& container){ assign(container.begin(), container.end()); }
	template<class First, class Last, class=decltype(std::declval<First>()[0])>
	id1(First first, Last last){ assign(first, last); }
	id1(int number, Node const& node){ assign(number, node); }
	


	

	void assign(int number){
		assign(number, Node{});
	}
	void assign(int number, Node const& node){ assign(number, [&]{ return node; }); }
	void assign(int number, auto const& generator){
		data.reserve(number*2); data.resize(number);
		for(int i=0; i<number; ++i) {
			if(data.size()>=data.capacity()) __builtin_unreachable();
			if constexpr(decltype(id4(generator, 0))::value){
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
	static decltype(auto) id5(F const& f, T&& t, int layer) {
		if constexpr(decltype(id4(f, std::forward<T>(t)))::value) return f(std::forward<T>(t));
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
			if(IS_TRUE(id5(fn, node>>shift, shift))) break;
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
			if(leftNode&1) if(IS_TRUE(id5(leftfn, leftNode++, layer))) break;
			if(rightNode&1) if(IS_TRUE(id5(rightfn, --rightNode, layer))) break;
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
		if constexpr(decltype(id6<first, Detail>(data[0], layer))::value){
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
				[&](auto it, auto layer){ return id5(leftfn,  data[it], layer); },
				[&](auto it, auto layer){ return id5(rightfn, data[it], layer); });
	}

	void forRange(int leftNode, int rightNode, auto const& fn)const{
		forRange(leftNode,rightNode,fn,fn);
	}


	void forRange(int leftNode, int rightNode, auto const& leftfn, auto const& rightfn
			

			){
		forRangeIndex(leftNode, rightNode,
				[&](auto it, auto layer){ return id5(leftfn,  data[it], layer); },
				[&](auto it, auto layer){ return id5(rightfn, data[it], layer); });
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





auto const infinity=INT_MAX/2;
struct Node{
	std::array<std::array<int, 2>, 2> numMore; 


	Node(): numMore(){
		recomputeLeaf();
	}

	bool have(int side) const{
		assert(numMore[side][side]==bool(numMore[side][side]));
		return numMore[side][side];
	}
	void recomputeLeaf(){ 

		numMore[0][1]=have(0) ? 1: infinity;
		numMore[1][0]=have(1) ? 1: infinity;
	}
};
struct Data: id1<Node, Data>{
	using id1::id1;

	template<bool first>
	static void combine(Node& parent, Node const& left, Node const& right){
		for(int const start: range(0, 2)){
			for(int const finish: range(0, 2)){
				parent.numMore[start][finish]=std::min({
					infinity,
						right.numMore[start][0]+left.numMore[0][finish],
						right.numMore[start][1]+left.numMore[1][finish],
				});
			}
		}
    }

	void set(int index, int side, int value){
		index+=offset();

		assert(data[index].have(side)!=value); 

		data[index].numMore[side][side]=value;
		data[index].recomputeLeaf();

		combineAll(index);
	}

	void add(int index, int side){ set(index, side, 1); }
	void remove(int index, int side){ set(index, side, 0); }

	int compute(int pos){
		if(pos==0) return 0;
		if(pos==1) return 1;
		auto result=combinedRange(1, pos);
		return std::min({
			result.numMore[0][0],
			result.numMore[0][1],
			result.numMore[1][0],
			result.numMore[1][1],
		})+1;
	}

};


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int const number=read<int>();
	std::vector<int> a(number);
	for(auto& it: a) {
		std::cin>>it;
	}


	Data data(number+1); 

	data.add(0, 0);
	data.add(0, 1);

	std::vector<int> countLeft(number+1), countRight(number+1);
	countLeft[0]=countRight[0]=1; 


	for(auto it: a) if(countRight[it]++==0){
		data.add(it, 1);
	}

	int64_t result {};
	for(auto it: a){
		if(0==--countRight[it]){
			data.remove(it, 1); 

		}
		result+=data.compute(it);
		if(countLeft[it]++==0){
			data.add(it, 0); 

		}
	}

	std::cout<<result<<'\n';
}

