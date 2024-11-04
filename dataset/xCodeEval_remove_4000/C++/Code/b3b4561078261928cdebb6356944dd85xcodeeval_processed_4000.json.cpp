




















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
auto id6(const T& x) -> decltype(void(*x), std::true_type());

std::false_type id6(...);

template<class T> auto range(T first, T last){
	if constexpr(std::is_integral<T>::value){
		assert(first<=last);  

		return Range<int_iter<T>>{first, last};
	}else{
		static_assert(decltype(id6(first))::value, "value type is neither integral nor id6");
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
















struct Empty{ int _[0];
	bool operator==(Empty) const{return true;}
	bool operator!=(Empty) const{return false;}
};

std::ostream& operator<<(std::ostream& stream, Empty ){
	return stream<<"{}";
}








template<class Data, class F, bool id1, bool id4, class ActualClass> struct id12{

	void beforeChange(int ){}  




	struct Node{
		Data data;
		int par; 

	};
	std::vector<Node> data;
	F merge_function;

	id12(F merge_function): data(), merge_function(merge_function) {
		static_assert(id1 or id4);
	}

	void assign(int n, auto starting_data ){
		data.clear(); data.reserve(n);
		for(int i=0; i<n; ++i){
			if(data.size()>=data.capacity()) __builtin_unreachable();
			data.push_back({starting_data(i), -1});
		}
	}

	void assign(int n){
		assign(n, [&](int ){ return Data {}; });
	}

	bool isRoot(int node) const{return data[node].par<0;}

	int root(int node)






	{
		if(isRoot(node)
				) return node;
		if constexpr(id1){
			((ActualClass*) this)->beforeChange(node);
			return 
				data[node].par= root(data[node].par);
		}else{
			return 
				root(data[node].par);
		}
	}

	auto join(int a, int b){
		struct Result{
			bool already_joined;
			int newRoot;
			Data* data;
            
            bool just_joined() const{return not already_joined;}
		};

		a=root(a); b=root(b);

		if(a==b) return Result{true, b, &data[b].data};

		if(id4){
			if(data[a].par<data[b].par) std::swap(a, b);
			else if(data[a].par==data[b].par) --data[b].par;
		}

		beforeChange(a);
		data[a].par=b;
		if(not std::is_same<Empty, Data>::value){
			((ActualClass*) this)->beforeChange(b);
			data[b].data=merge_function(
					std::move(data[b].data),
					std::move(data[a].data),
					b,
					a);
		}

		return Result{false, b, &data[b].data};
	}
};

template<class Data, class F, bool id1, bool id4> struct Dsu_:
	id12<Data, F, id1, id4, Dsu_<Data, F, id1, id4>> {
	using Base=id12<Data, F, id1, id4, Dsu_<Data, F, id1, id4>>;
	using Base::Base;
};
















template<
		class Data, 

		bool id1=true, bool id4=true, 


		class _F 

		>
	Dsu_<Data, _F, id1, id4>
	Dsu(_F merge_function){ return {merge_function}; }



template<bool id1=true, bool id4=true>
auto Dsu(){
	return Dsu<Empty, id1, id4>(
			[](Empty, Empty, int, int){return Empty {};}
			);
}







template<class T, class F> struct id7{
	std::vector<std::vector<T>> data;
	F minFunction;

	

	id7(std::vector<T> a, F minFunction): data{}, minFunction(std::move(minFunction)){
		data.push_back({});
		for(auto item: a)
			this->push_back({item});
	}

	void push_back(T item){
		data[0].push_back(std::move(item));
		for(int const layer: range(1, int(data.size()))){
			data[layer].push_back(minFunction(data[layer-1][data[layer].size()], data[layer-1].back()));
		}
		int newLayer=int(data.size());
		if((1<<(newLayer-1))<int(data.back().size())){
			data.push_back({minFunction(data.back()[0], data.back()[1<<(newLayer-1)])});
		}
		assert(std::cerr<<"");
	}
	
	void pop_back(){
		for(auto& item: data) item.pop_back();
		if(data.size()>1 and data.back().empty()) data.pop_back();
	}

	T operator()(int left, int right) const{
		assert(left<right);
		auto const layer=31^__builtin_clz(right-left);
		assert(left+(1<<layer)>=right-(1<<layer)); assert(right-(1<<layer)>=left);
		auto result=minFunction(
				data[layer][left], data[layer][right-(1<<layer)]);
		{
		auto const tmp=[&]{
			auto tmp=data[0][left];
			for(int const i: range(left, right)){
				tmp=minFunction(tmp, data[0][i]);
			}
			assert(tmp==result);
			return true;
		}; assert(tmp());}
		return result;
	}

};



template<class T, class F> 
id7<T, F> RMQ(std::vector<T> a, F minFunction){ return {std::move(a), std::move(minFunction)}; }



template<class T>
auto RMQ(std::vector<T> a){ return RMQ(std::move(a), [&](T const& first, T const& sec)->T const&{
	return std::min(first, sec);
}); }

template<class T>
auto id10(std::vector<T> a){ return RMQ(std::move(a), [&](T const& first, T const& sec)->T const&{
	return std::max(first, sec);
}); }










template<class D>  

struct SegmentCollectionTemplate{
	D& actual(){ return static_cast<D&>(*this); }
	D const& actual() const{ return static_cast<D const&>(*this); }

	

	void id11(int left, int right){}
	void id2(int left, int right){}

	std::map<int, int> segments; 


	void consistencyCheck() const{
		{
		auto const tmp=[&]{
			
			int last=INT_MIN;
			for(auto [left, right]: segments){
				assert(last<left);
				assert(left<right);
				last=right;
			}

			return true;
		}; assert(tmp());}
	}

	using Iter=std::map<int, int>::iterator;

	Iter primitiveAddSegment(int left, int right){
		auto const [iterator, inserted]=segments.insert({left, right});
		assert(inserted);
		consistencyCheck();
		actual().id11(left, right);
		return iterator;
	}

	Iter primitiveDeleteSegment(Iter iter){
		actual().id2(iter->first, iter->second);
		auto result=segments.erase(iter);
		consistencyCheck();
		return result;
	}

	void addSegment(int left, int right){
		assert(left<right);
		auto iter=segments.lower_bound(left);
		if(iter!=segments.begin()){
			auto p=std::prev(iter);
			assert(p->first<left);
			if(p->second>=left){
				left=p->first;
				right=std::max(right, p->second);
				primitiveDeleteSegment(p);
			}
		}

		while(iter!=segments.end() and iter->first<=right){
			assert(iter->first>=left);
			right=std::max(right, iter->second);
			iter=primitiveDeleteSegment(iter);
		}

		primitiveAddSegment(left, right);
	}

	void deleteSegment(int left, int right){
		assert(left<right);
		auto iter=segments.lower_bound(left);
		if(iter!=segments.begin()){
			auto p=std::prev(iter);
			auto [t, u]=*p;
			assert(t<left);
			if(u>=left){
				primitiveDeleteSegment(p);
				primitiveAddSegment(t, left);
				if(right<u){
					primitiveAddSegment(right, u);
					return;
				}
			}
		}

		while(iter!=segments.end() and iter->first<=right){
			auto const [t, u]=*iter;
			iter=primitiveDeleteSegment(iter);
			assert(t>=left);
			assert(t<=right);
			if(u>right){
				primitiveAddSegment(right, u);
				break;
			}
		}
	}
};

template<class A, class B>
auto id13(A id11, B id2){
	struct Result: SegmentCollectionTemplate<Result>{
		using Base=SegmentCollectionTemplate<Result>;
		A id3;
		B id8;
		Result(A id3, B id8): Base(), id3(std::move(id3)), id8(std::move(id8)) {}
		void id11(int left, int right){ id3(left, right); }
		void id2(int left, int right){ id8(left, right); }
	};
	return Result {std::move(id11), std::move(id2)};
}








int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int const numNode=read<int>();
	int const numQuery=read<int>();

	struct Edge{int u, v, weight;};
	std::vector<Edge> edges(numNode-1);
	for(auto& [u, v, weight]: edges){
		std::cin>>u>>v>>weight;
		--u;--v;
	}
	std::sort(begin(edges), end(edges), [&](auto const& first, auto const& sec){
		return first.weight<sec.weight;
	});

	struct DsuData{
		std::vector<int> nodes;
		std::vector<int> edgeWeights;
	};

	int curWeight;
	auto d=Dsu<DsuData>(
			[&](DsuData data_b, DsuData data_a, int , int ) ->DsuData{

				assert(data_a.nodes.size()==data_a.edgeWeights.size()+1);
				assert(data_b.nodes.size()==data_b.edgeWeights.size()+1);
				
				if(data_b.nodes.size()<data_a.nodes.size()) std::swap(data_a, data_b);
				for(auto x: data_a.nodes) data_b.nodes.push_back(x);
				data_b.edgeWeights.push_back(curWeight);
				for(auto x: data_a.edgeWeights) data_b.edgeWeights.push_back(x);
				return data_b;
			});
	d.assign(numNode, [&](int node)->DsuData{
		return DsuData{.nodes={node}, .edgeWeights={}};
	});


	for(auto [u, v, weight]: edges){
		curWeight=weight;
		auto tmp=d.join(u, v);
		assert(tmp.just_joined());
	}

	auto [dsuNodeList, dsuEdgeWeights]=std::move(d.data[d.root(0)].data);
	assert(int(dsuNodeList.size())==numNode);
	assert(int(dsuEdgeWeights.size())==numNode-1);
	auto const id5=id10(dsuEdgeWeights);

	std::vector<int> id9(numNode);
	for(int const index: range(0, numNode)){
		id9[dsuNodeList[index]]=index;
	}


	auto const id14=RMQ(id9);
	auto const id15=id10(id9);


	std::set<int> boundaryValues;

	auto segments=id13(
	[&](int left, int right){
		auto const [iterator, inserted]=boundaryValues.insert(id14(left, right));
		assert(inserted);
		if(right-left>1){
			auto const [iterator, inserted]=boundaryValues.insert(id15(left, right));
			assert(inserted);
		}
	},
	[&](int left, int right){
		boundaryValues.erase(boundaryValues.find(
					id14(left, right)));
		if(right-left>1){
			boundaryValues.erase(boundaryValues.find(
						id15(left, right)));
		}
	});


	std::vector<char> open(numNode, false);


	for(int _=numQuery; _--;){
		char type; std::cin>>type;
		switch(type){
			case '1':
				{
					int const left=read<int>()-1;
					int const right=read<int>();
					segments.addSegment(left, right);

					for(int const index: range(left, right)){
						open[index]=true;
					}

				}
				break;
			case '2':
				{
					int const left=read<int>()-1;
					int const right=read<int>();
					segments.deleteSegment(left, right);

					for(int const index: range(left, right)){
						open[index]=false;
					}

				}
				break;
			case '3':
				{
					int const node=read<int>()-1;
					int result=-1;

					assert((boundaryValues.empty())==(std::accumulate(begin(open), end(open), 0)==0));

					if(not boundaryValues.empty()){
						int left=std::min(id9[node], *boundaryValues.begin());
						int right=std::max(id9[node], *boundaryValues.rbegin());
						if(left!=right){
							assert(left<right);
							result=id5(left, right);
						}
					}
					std::cout<<result<<'\n';
				}
				break;
			default: assert(false); __builtin_unreachable();
		}
	}
}
