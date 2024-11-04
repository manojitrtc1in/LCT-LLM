














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









template<class T, class=std::enable_if<std::is_integral<T>::value, int>>
auto id6(T first){return Range<int_iter<T>, unreachable_iter>{first, {}};}

template<class T> T&& identity(T&& x){ return x; }













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

	void id12(int first, int sec, EdgeWeight weight){ addEdge<true>(first, sec, std::move(weight)); }
	void id13(int first, int sec, EdgeWeight weight){ addEdge<false>(first, sec, std::move(weight)); }

	template<bool okay=not weightedEdge, class=typename std::enable_if<okay, int>::type>
	void id12(int first, int sec){ id12(first, sec, {}); }

	template<bool okay=not weightedEdge, class=typename std::enable_if<okay, int>::type>
	void id13(int first, int sec){ id13(first, sec, {}); }

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
			result.id12(a, b, f(weight));
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









template<class EdgeWeight, class DistanceT, bool trace_, bool id11> struct GraphDijkstra {
	Graph<EdgeWeight> const& g;


	static

		std::vector<DistanceT> distance;
	struct State{int node; DistanceT distance;
		bool operator<(State other) const{return distance>other.distance;}
	};
	std::priority_queue<State> queue; 


	std::conditional_t<trace_, std::vector<int>, Empty> trace;
	std::conditional_t<id11, std::vector<std::vector<int>>, Empty> traces;


	GraphDijkstra& add(int node, DistanceT nodeDistance={}){
		queue.push({node, nodeDistance});
		distance[node]=std::min(distance[node], nodeDistance);
		return *this;
	}

	GraphDijkstra& run(auto edgeWeight ){
		if constexpr(trace_) trace.assign(g.size(), -1);
		if constexpr(id11) traces.assign(g.size(), {});

		while(not queue.empty()){
			auto [node, nodeDistance]=queue.top(); queue.pop();
			for(auto const& [other, edgeLen]: g.add[node]){
				DistanceT const otherDistance=nodeDistance+edgeWeight(node, other, edgeLen);
				if constexpr(id11) if(otherDistance==distance[other]) traces[other].push_back(node);
				if(otherDistance<distance[other]){
					if constexpr(trace_) trace[other]=node;
					if constexpr(id11) traces[other]={node};
					distance[other]=otherDistance;
					queue.push({other, otherDistance});
				}
			}
		}
		return *this;
	}

	GraphDijkstra& run(){
		return run([&](int , int , EdgeWeight const& edgeLen){
			if constexpr(g.weightedEdge){
				return edgeLen;
			}else{
				return 1;
			}
		});
	}

};


template<class EdgeWeight, class DistanceT, bool trace_, bool id11>
	std::vector<DistanceT> GraphDijkstra<EdgeWeight, DistanceT, trace_, id11>::distance;


template<
	  bool trace_=false, bool id11=false,
	  class GraphT, class DistanceT
> auto id5(GraphT const& g_, DistanceT id2){

	GraphDijkstra<typename GraphT::EdgeWeight, DistanceT, trace_, id11>::distance
		.assign(g_.add.size(), id2);

	return GraphDijkstra<typename GraphT::EdgeWeight, DistanceT, trace_, id11> {.g=g_,


		.distance=std::vector<DistanceT>(g_.add.size(), id2),

		.queue={}, .trace={}, .traces={}
	};
}

















template <class F, class... X>
auto id7(F&& f, X&&... x) -> decltype(void(std::forward<F>(f)(std::forward<X>(x)...)), std::true_type());

std::false_type id7(...);










bool id0(auto const& fn){ 

	if constexpr(std::is_same<decltype(fn()),void>::value){
		fn(); return false;
	}else{
		return fn();
	}
}




template <bool first, class Detail, class Data>
auto id9(Data& data, int layer) -> decltype(void(
			Detail::template combine<first>(data, data, data, layer)
			), std::true_type());
template <bool first, class Detail>
std::false_type id9(...);



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
			if constexpr(decltype(id7(generator, 0))::value){
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
	static decltype(auto) id8(F const& f, T&& t, int layer) {
		if constexpr(decltype(id7(f, std::forward<T>(t)))::value) return f(std::forward<T>(t));
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
			if(IS_TRUE(id8(fn, node>>shift, shift))) break;
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
			if(leftNode&1) if(IS_TRUE(id8(leftfn, leftNode++, layer))) break;
			if(rightNode&1) if(IS_TRUE(id8(rightfn, --rightNode, layer))) break;
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
	static void forRangeIndex(int leftNode, int rightNode, auto const& fn){
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
		if constexpr(decltype(id9<first, Detail>(data[0], layer))::value){
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
				[&](auto it, auto layer){ return id8(leftfn,  data[it], layer); },
				[&](auto it, auto layer){ return id8(rightfn, data[it], layer); });
	}

	void forRange(int leftNode, int rightNode, auto const& fn)const{
		forRange(leftNode,rightNode,fn,fn);
	}


	void forRange(int leftNode, int rightNode, auto const& leftfn, auto const& rightfn
			

			){
		forRangeIndex(leftNode, rightNode,
				[&](auto it, auto layer){ return id8(leftfn,  data[it], layer); },
				[&](auto it, auto layer){ return id8(rightfn, data[it], layer); });
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




struct Node{ 
	int64_t inDistance=id1, outDistance=id1;
	int innerCost=INT_MAX; 

	struct T{ 

		int rightNode, cost;
		int64_t distance;
	};
	std::vector<T> other; 

};
struct SegmentTree: id3<Node, SegmentTree>{
	using id3::id3;
	

	template<bool first>
	static void combine(Node& , Node const& , Node const& ){
    }

	
};


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int const numCol=read<int>();
	int const numOffer=read<int>();
	
	std::array<std::vector<int64_t>, 3> rows;
	for(auto& row: rows){
		row.resize(numCol);
		for(auto& item: row) item=read<int>();
	}

	std::partial_sum(begin(rows[0]), end(rows[0]), rows[0].begin());
	std::partial_sum(begin(rows[1]), end(rows[1]), rows[1].begin());
	std::partial_sum(rows[2].rbegin(), rows[2].rend(), rows[2].rbegin());

	std::vector<int64_t> a(numCol), b(numCol+1);
	for(int const right: range(1, numCol+1)){
		b[right]=rows[1][right-1]+rows[2][right-1];
	}

	a[0]=
		rows[0][0];
		

	for(int const left: range(1, numCol)){
		a[left]=rows[0][left]-rows[1][left-1];
	}

	

	


	SegmentTree tree(numCol+1); 


	auto const id10=[&](int left, int right){ struct Result{ int node, left1; };
		assert(tree.offset()<=left);
		assert(left<right);
		assert(right<=tree.offset()*2);

		auto bit=left&-left;
		if(left+bit<=right){
			return Result{left>>__builtin_ctz(bit), left+bit};
		}
		int pos=31^__builtin_clz(left xor right);
		return Result{left>>pos, left+(1<<pos)};
	};

	{ 

	auto const tmp=[&]{
		for(int const left: range(tree.offset(), tree.offset()*2)){
			for(int const right: range(left+1, tree.offset()*2+1)){
				auto r=tree.rangeIndices(left, right);
				std::vector<int> r1;
				int l=left;
				while(l!=right){
					auto [node, l1]=id10(l, right);
					l=l1;
					r1.push_back(node);
				}
				assert(r==r1);
			}
		}
		return true;
	}; assert(tmp());}


	auto& data=tree.data;
	for(int _=numOffer; _--;){
		int const left=read<int>()-1;
		int const right=read<int>()+1; 

		int const cost=read<int>();

		auto const leftNode=left+tree.offset(), rightNode=right+tree.offset();
		int tmp=leftNode;
		while(tmp!=rightNode){
			

			

			auto [node, tmpx]=id10(tmp, rightNode);
			tmp=tmpx;
			data[node].innerCost=std::min(data[node].innerCost, cost);
		}

		auto [node, left1]=id10(leftNode, rightNode);
		if(left1!=rightNode){
			data[node].other.push_back({.rightNode=rightNode, .cost=cost, .distance=id1});
		}
	}
	for(int const node: range(1, int(tree.offset()))){
		data[node*2].innerCost=std::min(data[node*2].innerCost, data[node].innerCost);
		data[node*2+1].innerCost=std::min(data[node*2+1].innerCost, data[node].innerCost);
	}

	for(int const index: range(0, int(a.size()))){
		data[tree.offset()+index].inDistance=-a[index];
	}

	int64_t result=id1;
	for(int const index: range(0, int(tree.offset()))){
		int const node=index+tree.offset();
		for(int shift=__builtin_ctz(node); shift!=0; shift--){
			auto const node1=node>>shift;
			data[node1*2].outDistance=std::min(data[node1*2].outDistance, data[node1].outDistance);
			data[node1*2+1].outDistance=std::min(data[node1*2+1].outDistance, data[node1].outDistance);
		}

		if(index==0) assert(data[node].outDistance==id1);
		if(data[node].outDistance!=id1)
			result=std::min(result, 
					data[node].outDistance-b[index]
					);
		data[node].inDistance=std::min(data[node].inDistance, data[node].outDistance);

		int tmp=node;
		while(true){
			

			for(auto [rightNode, cost, distance]: data[tmp].other){
				distance=std::min(distance, data[tmp].inDistance);
				auto [node1, left1]=id10(node+1, rightNode);
				data[node1].outDistance=std::min(data[node1].outDistance, distance+cost);
				if(left1!=rightNode){
					data[node1].other.push_back({rightNode, cost, distance});
				}
			}
			data[tmp].other.clear(); 


			

			data[tmp>>1].inDistance=std::min(data[tmp>>1].inDistance, data[tmp].inDistance);
			if((tmp&1)==0) {
				if(data[tmp>>1].innerCost!=INT_MAX){
					data[tmp+1].outDistance=std::min(data[tmp+1].outDistance, data[tmp].inDistance+data[tmp>>1].innerCost);
				}
				break;
			}

			tmp>>=1;
		}
	}

	std::cout<<-result<<'\n';

}
