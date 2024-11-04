





















template <class Node, class Detail>
struct id3{
 std::vector<Node> data;
 id3(){}
 id3(int number){ assign(number); }
 id3(auto&& container){ assign(container.begin(), container.end()); }
 template<class First, class Last, class=decltype(std::declval<First>()[0])>
 id3(First first, Last last){ assign(first, last); }
 id3(int number, Node const& node){ assign(number, node); }
 void assign(int number){
  assign(number, Node{});
 }
 template<class First, class Last, class=decltype(std::declval<First>()[0])>
 void assign(First first, Last last){
  assign([&](int index){ return first[index]; }, int(last-first));
 }
 void assign(int number, Node const& node){ assign(number, [&]{ return node; }); }
 void assign(int number, auto const& generator){
  data.reserve(number*2); data.resize(number);
  for(int i=0; i<number; ++i) {
   if(data.size()>=data.capacity()) __builtin_unreachable();
   if constexpr(std::is_invocable_v<decltype(generator), int>){
    data.push_back(generator(i));
   }else{
    data.push_back(generator());
   }
  }
  for(int i=number; --i;) Detail::combine(data[i], data[i<<1], data[i<<1|1]);
 }
 private:
 static bool evaluatesToTrue(auto const& fn){
  if constexpr(std::is_same_v<decltype(fn()),void>){
   fn(); return false;
  }else{
   return fn();
  }
 }
 template<class F, class T>
 static decltype(auto) id7(F const& f, T&& t, int layer) {
  if constexpr(std::is_invocable_v<F, T&&>) return f(std::forward<T>(t));
  else return f(std::forward<T>(t), layer);
 }
 public:
 static void forStrictAncestorIndexDown(int node,auto const& fn){
  for(int shift=31^__builtin_clz(node);shift;--shift)
   if(evaluatesToTrue([&]{ return (fn(node>>shift)); })) break;
 }
 static void forStrictAncestorIndexUp(int node,auto const& fn){
  for(int y=node>>1;y;y>>=1)
   if(evaluatesToTrue([&]{ return (fn(y)); })) break;
 }
 static void forRangeIndex(int leftNode, int rightNode, auto const& leftfn, auto const& rightfn){
  int layer=0;
  while(leftNode<rightNode){
   if(leftNode&1) if(evaluatesToTrue([&]{ return (id7(leftfn, leftNode++, layer)); })) break;
   if(rightNode&1) if(evaluatesToTrue([&]{ return (id7(rightfn, --rightNode, layer)); })) break;
   leftNode>>=1;rightNode>>=1; ++layer;
  }
 }
 static void forRangeIndex(int leftNode, int rightNode, auto const& fn){
  forRangeIndex(leftNode,rightNode,fn,fn);
 }
 int offset()const{ return int(data.size()/2u); }
 void pushAll(int node){
  assert(node>=offset());
  forStrictAncestorIndexDown(node, [&](int it){
   if constexpr(std::is_invocable_v<decltype(Detail::push), Node, Node, Node>)
    Detail::push(data[it], data[it<<1], data[it<<1|1]);
   else{
    Detail::push(data[it], data[it<<1]);
    Detail::push(data[it], data[it<<1|1]);
   }
  });
 }
 void combineAll(int node){
  assert(node>=offset());
  forStrictAncestorIndexUp(node, [&](int it){
   Detail::combine(data[it], data[it<<1], data[it<<1|1]);
  });
 }
 void forRange(int leftNode, int rightNode, auto const& leftfn, auto const& rightfn){
  assert(leftNode>=offset());
  assert(rightNode>=offset());
  forRangeIndex(leftNode, rightNode,
    [&](auto it, auto layer){ return id7(leftfn, data[it], layer); },
    [&](auto it, auto layer){ return id7(rightfn, data[it], layer); });
 }
 void forRange(int leftNode, int rightNode, auto const& fn){
  forRange(leftNode,rightNode,fn,fn);
 }
 template<class T> T reduceRange(int leftNode, int rightNode, T initial, auto const& function) {
  forRange(leftNode, rightNode, [&](Node const& node){ initial=function(std::move(initial), node); });
  return initial;
 }
};
       
 
       
 
       
 
       
 
template int const& std::min<int>(int const&,int const&);
template<class T=int,auto f=(T const&(*)(T const&,T const&))std::min<T>>
struct RMQ{
 std::vector<std::vector<T>> d;
 RMQ():d(){}
 RMQ(std::vector<T> x):d(){
  assign(std::move(x));
 }
 void assign(std::vector<T> x){
  d.assign(1,std::move(x));
  for(int step=1;step<(int)d.back().size();step<<=1){
   std::vector<T> const& a=d.back();
   std::vector<T> b(begin(a),end(a)-step);
   std::transform(begin(b),end(b),begin(a)+step,begin(b),f);
   d.push_back(std::move(b));
  }
 }
 T operator[](int i)const{ return d[0][i]; }
 T get(int l,int r)const{
  assert(l<r);
  int layer=std::__lg(r-l);
  return f(d[layer][l],d[layer][r-(1<<layer)]);
 }
 template<class U> T get(U lr)const{
  auto [l,r]=lr;
  return get(l,r);
 }
 T getrange(int l,int r)const{
  return get(std::minmax(l,r));
 }
};
struct suffixarray_t{
 std::vector<int> rankof;
 std::vector<int> order;
};
suffixarray_t suffixarray(std::string const& s){
 suffixarray_t out{std::vector<int>(s.size()+1),std::vector<int>(s.size()+1)};
 auto& [rankof,order]=out;
 std::copy(begin(s),end(s),begin(rankof));
 std::vector<int> cnt;
 std::vector<std::vector<int>::iterator> it;
 std::vector<int> newrank,oldorder;
 unsigned prefix_len=1,nrank=128;
 while(true){
  cnt.assign(nrank,0);
  for(unsigned x=0;x<order.size();++x)
   ++cnt[x+prefix_len>=rankof.size() ? 0 : rankof[x+prefix_len]];
  it.resize(nrank);
  it[0]=begin(order);
  for(unsigned i=1;i<nrank;++i)
   it[i]=it[i-1]+cnt[i-1];
  for(unsigned x=0;x<rankof.size();++x)
   *it[x+prefix_len>=rankof.size() ? 0 : rankof[x+prefix_len]]++=x;
  cnt.assign(nrank,0);
  for(int x:rankof)++cnt[x];
  std::swap(order,oldorder);
  order.resize(oldorder.size());
  it.resize(nrank);
  it[0]=begin(order);
  for(unsigned i=1;i<nrank;++i)
   it[i]=it[i-1]+cnt[i-1];
  for(auto x:oldorder)
   *it[rankof[x]]++=x;
  newrank.resize(rankof.size());
  nrank=1;
  newrank[order[0]]=0;
  for(unsigned i=1;i<order.size();++i){
   auto a=order[i-1],b=order[i];
   if(rankof[a]!=rankof[b] or rankof[a+prefix_len]!=rankof[b+prefix_len])
    ++nrank;
   newrank[b]=nrank-1;
  }
  prefix_len*=2;
  std::swap(rankof,newrank);
  if(nrank==rankof.size())
   break;
 }
 return out;
}
std::vector<int> lcp(std::string const& s,std::vector<int> const& rankof,std::vector<int> const& order){
 assert(rankof.size()==s.size()+1);
 assert(rankof.size()==order.size());
 std::vector<int> out(s.size());
 int id1=0;
 for(unsigned i=0;i<s.size();++i){
  unsigned r=rankof[i];
  assert(order[r]==(int)i);
  if(r+1==order.size()){
   assert(id1==0);
   continue;
  }
  unsigned j=order[r+1];
  while(s[i+id1]==s[j+id1]) ++id1;
  out[r]=id1;
  if(id1) --id1;
 }
 return out;
}

using Node=int;
struct SegmentTree: id3<Node, SegmentTree>{
	using id3::id3;
	
	static void push(Node&, Node&){}
	static void combine(Node& parent, Node const& left, Node const& right){
		parent=std::max(left, right);
	}

	void set(int index, int value){
		index+=offset();
		data[index]=value;
		combineAll(index);
	}
	int operator[](int index) const{
		return data[index+offset()];
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int len; std::cin>>len;
	std::string string; string.reserve(len);
	std::cin>>string; assert((int)string.size()==len);
	std::reverse(begin(string),end(string));


	std::vector<int> order(len); std::iota(begin(order),end(order), 0); 

	std::sort(begin(order),end(order),[view=std::string_view(string)](auto const& first, auto const& sec){
		return view.substr(first)<view.substr(sec);
	});

	std::vector<int> rank(len); 

	for(int index=0;index<len;++index) rank[order[index]]=index;

	std::vector<int> common(len-1); 

	for(int index=0;index<len;++index) rank[order[index]]=index;
	for(int index=0;index<len-1;++index)
		while(string[order[index]+common[index]]==string[order[index+1]+common[index]])
			++common[index];

	auto [rank, order]=suffixarray(string);
	auto common=lcp(string, rank, order);

	assert(order[0]==len);
	order.erase(begin(order));
	assert(rank[len]==0); assert((int)rank.size()==len+1);
	rank.pop_back();
	for(auto & it: rank) --it;

	common.erase(begin(common));

	RMQ const id6(common);



	



	std::vector<int> result(len, 1);
	


	

	

	
	SegmentTree value1(len), value2(len, -len); 

	std::vector<std::vector<int>> events(len+1);
	events[1].push_back(0);
	value2.set(rank[0], 0);

	int finalResult=1;
	for(int left=1;left<len-1;++left) {
		

		



		for(auto it: events[left]){
			assert(it+result[it]==left);
			auto const r=rank[it];
			

			value2.set(r, -len); value1.set(r, left-it);
		}

		

		

		

		auto const value=[&](int left1){
			assert(value1[left1]>=0);
			return std::max({value1[left1], left+value2[left1]});
		};

		assert(result[left]==1);
		result[left]=0;

		for(int pos=left;pos<=left+1;++pos) {
			auto const i=rank[pos];

			std::vector<std::pair<int, int>> leftSegments, rightSegments;
			{
				int j=i, curCommon=INT_MAX, id0=0;
				assert(value(i)==0);


				auto const id4=[&](int node, int layer){
					return std::make_pair(
							std::min(curCommon,
								id6.d[layer][j]),
							std::max({id0,
								value1.data[node], left+value2.data[node]})
							);
				};
				auto const tryUse=[&](int node, int layer){
					auto const [id5, id8]=id4(node, layer);
					if(id5>=id8){
						curCommon=id5; id0=id8;
						j+=1<<layer; return true;
					}
					return false;
				};


				leftSegments.clear(); rightSegments.clear();
				assert((int)common.size()+1==len);
				assert(value1.offset()==len);

				value1.forRangeIndex(i+1+len, len*2,
						[&](int node, int layer){ leftSegments.push_back({node, layer}); },
						[&](int node, int layer){ rightSegments.push_back({node, layer}); });
				leftSegments.insert(end(leftSegments), rightSegments.rbegin(), rightSegments.rend());
				rightSegments.clear();

				bool id2=false;
				for(auto [node, layer]: leftSegments){
					if(not tryUse(node, layer)){
						while(layer>0){
							node<<=1; --layer;
							if(tryUse(node, layer)){
								++node;
								assert(not tryUse(node, layer));
							}
						}
						id2=true;
						break;
					}
				}
				assert(curCommon>=id0);
				result[left]=std::max(result[left], id0);
				{
					auto const nextNode=j+1+value1.offset();
					assert(id2==(nextNode<(int)value1.data.size()));

					if(id2){
						auto const [id5, id8]=id4(nextNode, 0);
						assert(id5<id8);
						result[left]=std::max(result[left], id5);
					}
				}
							

				while(j<(int)common.size()){
					curCommon=std::min(curCommon, common[j++]);

					if(curCommon+1<=result[left]) break;
					result[left]=std::max(result[left], std::min(curCommon, value(j)));
				}

			}

			{
				int j=i, curCommon=INT_MAX, id0=0;
				assert(value(i)==0);


				auto const id4=[&](int node, int layer){
					return std::make_pair(
							std::min(curCommon, id6.d[layer][j-(1<<layer)]),
							std::max({id0,
								value1.data[node], left+value2.data[node]})
							);
				};
				auto const tryUse=[&](int node, int layer){
					auto const [id5, id8]=id4(node, layer);
					if(id5>=id8){
						curCommon=id5; id0=id8;
						j-=1<<layer; return true;
					}
					return false;
				};


				leftSegments.clear(); rightSegments.clear();
				assert((int)common.size()+1==len);
				assert(value1.offset()==len);

				value1.forRangeIndex(len, len+j,
						[&](int node, int layer){ leftSegments.push_back({node, layer}); },
						[&](int node, int layer){ rightSegments.push_back({node, layer}); });
				rightSegments.insert(end(rightSegments), leftSegments.rbegin(), leftSegments.rend());
				leftSegments.clear();

				bool id2=false;
				for(auto [node, layer]: rightSegments){
					if(not tryUse(node, layer)){
						while(layer>0){
							node<<=1; --layer;
							if(not tryUse(node+1, layer)){
								++node;
							}else assert(not tryUse(node, layer));
						}
						id2=true;
						break;
					}
				}
				assert(curCommon>=id0);
				result[left]=std::max(result[left], id0);
				{
					auto const nextNode=j-1+value1.offset();
					assert(id2==(j!=0));

					if(id2){
						auto const [id5, id8]=id4(nextNode, 0);
						assert(id5<id8);
						result[left]=std::max(result[left], id5);
					}
				}


				while(j>0){
					curCommon=std::min(curCommon, common[--j]);

					if(curCommon+1<=result[left]) break;
					result[left]=std::max(result[left], std::min(curCommon, value(j)));
				}

			}
		}

		if(left+result[left]+1<=len) ++result[left];
		finalResult=std::max(finalResult, result[left]);
		events[left+result[left]].push_back(left);
		value2.set(rank[left], -left);
	}
	std::cout<<finalResult<<'\n';
}
