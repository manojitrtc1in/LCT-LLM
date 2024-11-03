






























namespace lz {

using std::integral_constant;
using std::cout;
using std::endl;



struct NoProperty {
	using Tag = NoProperty;
	using ValueType = NoProperty;
	using NextProperty = NoProperty;

	NoProperty() = default;

protected:
    template<typename ...Args, size_t N>
    NoProperty(const std::tuple<Args...> &tp, std::integral_constant<size_t, N> t)
	{
	}


};


    namespace PropertyPrivate {

        template<typename P>
        struct CountProperty
        : public integral_constant<size_t, CountProperty<typename P::NextProperty>::value + 1>
        { };

        template<>
        struct CountProperty<NoProperty>
        : public integral_constant<size_t, 0>
        { };

        template<typename... T>
        struct CountVariadic;

        template<typename Head, typename...T>
        struct CountVariadic<Head, T...>
        : public integral_constant< size_t, CountVariadic<T...>::value + 1>
        { };

        template<>
        struct CountVariadic<>
        : public integral_constant<size_t, 0>
        { };


        template<typename QueryTag, typename Tag, typename Property>
        struct Get;


        template <typename Property, typename CntTag, typename Tuple, size_t CntId>
		struct AssignTuple;

        template<typename Property, typename Tag, typename QueryTag>
        struct GetType;

    } 



template<typename P>
struct PropertySize:public std::integral_constant<
	size_t, PropertySize<typename P::NextProperty>::value + 1> {};

template<>
struct PropertySize<NoProperty>
: public integral_constant<size_t, 0> { };


template<typename _Tag, typename _ValueType, typename _NextProperty = NoProperty >
struct Property: public _NextProperty
{
    template<typename QueryTag, typename Tag, typename Property>
    friend struct PropertyPrivate::Get;

    template <typename Property, typename CntTag, typename Tuple, size_t CntId>
    friend struct PropertyPrivate::AssignTuple;

    using Tag = _Tag;
    using ValueType = _ValueType;
    using NextProperty = _NextProperty;

    template<typename QueryTag>
    using QueryValueType = typename PropertyPrivate::GetType<Property, Tag, QueryTag>::ValueType;

    template<typename QueryTag>
    using QueryPropertyType = typename PropertyPrivate::GetType<Property, Tag, QueryTag>::PropertyType;

    Property() = default;






    Property(ValueType &&value, const NextProperty & np):
		NextProperty(np), m_value(value){}

protected:
    template<typename ...Args, size_t N>
    Property(const std::tuple<Args...> &tp, std::integral_constant<size_t, N> t):
		m_value(std::get<N>(tp)), NextProperty(tp, std::integral_constant<size_t, N + 1>())
	{

	}
public:
    template<typename ...Args>
	Property( const std::tuple<Args...> &tp):
		Property(tp, std::integral_constant<size_t, 0>())
	{

	}

















































    template<typename QueryTag>
    QueryValueType<QueryTag>& operator[](QueryTag tag)
	{
    	using Base = QueryPropertyType<QueryTag>;
    	return this->Base::m_value;
	}
    template<typename QueryTag>
	const QueryValueType<QueryTag>& operator[](QueryTag tag) const
	{
		using Base = QueryPropertyType<QueryTag>;
		return this->Base::m_value;
	}

    template<typename QueryTag>
    constexpr bool contains(QueryTag tag) const
    {
    	return !std::is_same<decltype((*this)[tag]), NoProperty>::value;
    }

protected:
    ValueType m_value;

};





    namespace PropertyPrivate {

	template<typename Property, typename Tag, typename QueryTag>
	struct GetType
	{
	private:
		using NextProperty = typename Property::NextProperty  ;
		using NextTag = typename NextProperty::Tag;
	public:
		using ValueType = typename GetType<NextProperty, NextTag, QueryTag>::ValueType;
		using PropertyType = typename GetType<NextProperty, NextTag, QueryTag>::PropertyType;
	};

	template<typename Property, typename QueryTag>
	struct GetType<Property, QueryTag, QueryTag>
	{
		using ValueType = typename Property::ValueType;
		using PropertyType = Property;
	};

	template<typename Property, typename QueryTag>
	struct GetType<Property, NoProperty, QueryTag>
	{
		using ValueType = NoProperty;
		using PropertyType = NoProperty;
	};





	template <typename Property, typename Tag, typename Tuple, size_t Id>
	struct AssignTuple
	{
		static void apply(Property &p, const Tuple &t)
		{



			p[Tag()] = std::get<Id>(t);

			AssignTuple<typename Property::NextProperty,
						typename Property::NextProperty::Tag,
						Tuple,
						Id + 1>::apply(p, t);
		}
		static void apply(Property &p, Tuple &&t)
		{



			 p[Tag()] = std::get<Id>(t);

			 AssignTuple<typename Property::NextProperty,
						 typename Property::NextProperty::Tag,
						 Tuple,
						 Id + 1>::apply(p, t);
		}

	};

	template <typename Property, typename Tuple, size_t CntId>
	struct AssignTuple<Property, NoProperty, Tuple, CntId>
	{
		static void apply(Property &p, const Tuple &t)
		{

		}
	};












    } 






































template<typename P>
struct ChooseDefineProperties
{
	P properties;
	void set(const P &_p) { properties = _p; }
};
template<> struct ChooseDefineProperties<NoProperty>
{
	void set(const NoProperty &_p) {  }
};





















} 




























namespace lz {






template<typename Map>
struct MapTraits
{
	using KeyType = typename Map::KeyType;
	using ValueType = typename Map::ValueType;
};

template<typename Key, typename Value>
struct MapFacade
{
	using KeyType = Key;
	using ValueType = Value;
};


template<typename UniqueArray>
struct id7: public MapFacade<std::ptrdiff_t, typename UniqueArray::element_type&>
{
	id7(UniqueArray &&u):u(move(u))
	{

	}
	typename UniqueArray::element_type& operator[](ptrdiff_t d) const
	{
		return u[d];
	}
private:
	UniqueArray u;
};


template<typename UniqueArray>
id7<typename std::remove_reference<UniqueArray>::type> id9(UniqueArray && u)
{
	return id7<typename std::remove_reference<UniqueArray>::type>(move(u));
}















template<typename _ValueType>
struct id21: public MapFacade<std::ptrdiff_t, _ValueType&>
{
	id21(std::shared_ptr<_ValueType> sp):sp(sp){}
	id21() :sp(nullptr) {}

	id21(size_t n)
	:sp(new _ValueType[n], std::default_delete<_ValueType[]>())  { }

	_ValueType& operator[](ptrdiff_t d) const
	{
		return	sp.get()[d];
	}
private:
	std::shared_ptr<_ValueType> sp;
};


















template<typename Key>
struct IdentityMap:public MapFacade<Key, Key>
{
	Key operator[](Key key) const
	{
		return key;
	}
};

template<typename UnaryFunction, typename Key, typename Value>
class FunctionMap:public MapFacade<Key, Value>
{
	const UnaryFunction* f = nullptr;
	using Base = MapFacade<Key, Value>;
public:
	const UnaryFunction* function(){ return f;}

	explicit FunctionMap() = default;
	explicit FunctionMap(const UnaryFunction &f):f(&f) {}
	typename Base::ValueType operator[](typename Base::KeyType key) const
	{
		return (*f)(key);
	}
};
template<typename I,
		 typename Key = typename std::iterator_traits<I>::difference_type,
		 typename Value = decltype(I()[Key()]) >
class IteratorMap:public MapFacade<Key, Value>
{
	I i;
	using Base = MapFacade<Key, Value>;
public:
	IteratorMap() = default;
	IteratorMap(I i):i(i){}

	using Iterator = I;
	Iterator iterator() const { return i;}

	typename Base::ValueType operator[](typename Base::KeyType key)
	{
		return i[key];
	}
};
template<typename I>
IteratorMap<I> id3(I i)
{
	return IteratorMap<I>(i);
}


template<typename FM, typename SM>
class ComposeMap:public MapFacade<typename MapTraits<FM>::KeyType, typename MapTraits<SM>::ValueType >
{
	FM fm;
	SM sm;
	using Base = MapFacade<typename MapTraits<FM>::KeyType, typename MapTraits<SM>::ValueType>;
public:
	using FirstMap = FM;
	using SecondMap = SM;

	explicit ComposeMap() = default;






	explicit ComposeMap(FM fm,  SM sm):fm(fm), sm(sm) {}


	FirstMap firstMap() const { return fm; }
	SecondMap secondMap() const { return sm; }

	typename Base::ValueType operator[](typename Base::KeyType key) const
	{
		return sm[fm[key]];
	}
};

template<typename FM, typename SM>
ComposeMap<typename std::remove_reference<FM>::type,
  	  	   typename std::remove_reference<SM>::type> id0(FM fm, SM sm)

{
	return ComposeMap<typename std::remove_reference<FM>::type,
					  typename std::remove_reference<SM>::type>(fm, sm) ;
}







}













namespace lz {
	namespace GraphUtilityPrivate {
	}


struct DirectedGraphTag {};
struct UndirectedGraphTag {};


struct VertexIndexTag {};
struct EdgeIndexTag {};



template<typename Graph>
typename Graph::VertexDescriptor
opposite(const Graph &g,
         typename Graph::EdgeDescriptor e,
         typename Graph::VertexDescriptor u)
{
    if(g.source(e) != u) return g.source(e);
    return g.target(e);
}

template<typename G>
struct GraphTraits
{
	using VertexDescriptor = typename G::VertexDescriptor;
	using EdgeDescriptor = typename G::EdgeDescriptor;

	using VertexIterator = typename G::VertexIterator;
	using EdgeIterator = typename G::EdgeIterator;

	using DirectedCategory = typename G::DirectedCategory;

	using id18 = typename G::id18;

	using VertexProperties = typename G::VertexProperties;
	using EdgeProperties = typename G::EdgeProperties;

	template<typename Tag>
	using id24 = typename G::template id24<Tag>;

	template<typename Tag>
	using id1 = typename G::template id1<Tag>;

};







template<typename G, typename Tag>
class id24
{
	using _ValueType = typename std::decay<decltype(typename GraphTraits<G>::VertexProperties()[Tag()])>::type;
	G *g = nullptr;
public:
	using KeyType = typename GraphTraits<G>::VertexDescriptor;
	using ValueType = _ValueType&;

	id24() = default;
	id24(G &_g):g(&_g) { }
	ValueType operator[](typename GraphTraits<G>::VertexDescriptor u) const
	{
		return g->vertexProperties(u)[Tag()];
	}

	using Type = id24<G, Tag>;

	struct ConstType
	{
		using KeyType = typename GraphTraits<G>::VertexDescriptor;
		using ValueType = const _ValueType &;
		const G *g;
		ConstType():g(nullptr){}
		ConstType(const G &g):g(&g){}
		ValueType operator[](KeyType u) const
		{
			return g->vertexProperties(u)[Tag()];
		}
	};
};


template<typename G, typename Tag>
class id1
{
	using _ValueType = typename std::decay<decltype(typename GraphTraits<G>::EdgeProperties()[Tag()])>::type;
	G *g = nullptr;
public:
	using KeyType = typename GraphTraits<G>::EdgeDescriptor;
	using ValueType = _ValueType&;

	id1() = default;
	id1(G &_g):g(&_g) { }
	ValueType operator[](KeyType u) const
	{
		return g->edgeProperties(u)[Tag()];
	}

	using Type = id1<G, Tag>;

	struct ConstType
	{
	private:
		const G *g;
	public:
		using KeyType = typename GraphTraits<G>::EdgeDescriptor;
		using ValueType = const _ValueType &;

		ConstType():g(nullptr){}
		ConstType(const G &g):g(&g){}
		ValueType operator[](KeyType u) const
		{
			return g->edgeProperties(u)[Tag()];
		}
	};
};







































template<typename G, typename Tag>
typename id24<G, Tag>::Type
id26(G &g, Tag)
{
	return typename id24<G, Tag>::Type(g);
}

template<typename G, typename Tag>
typename id24<G, Tag>::ConstType
id26(const G &g, Tag tag)

{
	return typename id24<G, Tag>::ConstType(g);
}

template<typename G, typename Tag>
auto id23( G &g, Tag tag)
->decltype(typename id1<G, Tag>::Type(g))
{
	return typename id1<G, Tag>::Type(g);
}

template<typename G, typename Tag>
auto id23(const G &g, Tag tag)
->decltype(typename id1<G, Tag>::ConstType(g))
{
	return typename id1<G, Tag>::ConstType(g);
}














































template<typename ValueType, typename VertexIndexMap, typename VertexNumberType>
auto
id14(VertexIndexMap indexMap, VertexNumberType n)
->decltype(id0(indexMap, id21<ValueType>(n)) )

{

	return id0(indexMap, id21<ValueType>(n) );
}






















































































} 























namespace lz {

enum class DefaultColorType: unsigned char
{
    White,
    Gray,
    Black,
	Green,
	Red,
};

template<typename ColorType = DefaultColorType>
struct ColorTraits
{
	using Type = ColorType;
	static ColorType white() { return ColorType::White; }
	static ColorType gray() { return ColorType::Gray; }
	static ColorType black() { return ColorType::Black; }
	static ColorType green() { return ColorType::Green; }
	static ColorType red() { return ColorType::Red; }
};

















template<typename Derived>
struct FacadeBase
{
protected:
	Derived& derived()
	{ return *static_cast<Derived*>(this); }

	Derived const& derived() const
	{ return *static_cast<Derived const*>(this); }
};



template<typename Derived>
struct EqualityComparableFacade
{
	friend bool operator!=(const Derived &a, const Derived &b)
	{
		return !(a == b);
	}
};



template<typename Derived>
struct LessThanComparableFacade
{
	friend bool operator>(const Derived &a, const Derived &b)
	{
		return b < a;
	}
	friend bool operator<=(const Derived &a, const Derived &b)
	{
		return !(b < a);
	}
	friend bool operator>=(const Derived &a, const Derived &b)
	{
		return !(a < b);
	}
};


















































































































template <class F1, class F2>
struct id16 : F1, F2
{
	id16(F1 f1, F2 f2)
		: F1(f1), F2(f2)
	{

	}

	using F1::operator();
	using F2::operator();
};

template <class F1, class F2>
id16<F1, F2> id5(F1 f1, F2 f2)
{
	return id16<F1, F2>(f1, f2);
}










template<typename T>
int id6(T x)
{
    if(x == 0) return 1;
    int r = 0;
    for(;x > 0; x >>= 1)
    {
        r ++;
    }
    return r;
}



template<typename T>
T modPow(T a, T b, const T &c)
{
    T r = 1;
    while(b > 0)
    {
        if(b & 1) r = r * b % c;
        a = a * a % c;
        b >>= 1;
    }
    return r;
}





} 







namespace lz{







template <
	class Derived,
	class Category,
	class T,
	class Distance = std::ptrdiff_t,
	class Pointer = T*,
	class Reference = T&
>
class IteratorFacade;



template <
	class Derived,
	class T,
	class Distance ,
	class Pointer,
	class Reference
>
class IteratorFacade<Derived, std::forward_iterator_tag, T, Distance, Pointer, Reference>
		: public std::iterator<std::forward_iterator_tag, T, Distance, Pointer, Reference>,
		  public lz::FacadeBase<Derived>,
		  public lz::EqualityComparableFacade<Derived>
{
	using Base = std::iterator<std::forward_iterator_tag, T, Distance, Pointer, Reference>;
public:
  	friend Derived operator++(Derived& a, int)
	{
		Derived	tmp(a);
		++a;
		return tmp;
	}

	typename Base::pointer operator->() const
	{
		return &*this->derived();
	}









};



template <
	class Derived,
	class T,
	class Distance,
	class Pointer,
	class Reference
>
class IteratorFacade<Derived, std::bidirectional_iterator_tag, T, Distance, Pointer, Reference>
		: public IteratorFacade<Derived, std::forward_iterator_tag, T, Distance, Pointer, Reference>
{
	using Base = IteratorFacade<Derived, std::forward_iterator_tag, T, Distance, Pointer, Reference>;
public:
	using iterator_category = std::bidirectional_iterator_tag;

	friend Derived operator--(Derived&a, int)
	{
		Derived	tmp(a);
		--a;
		return tmp;
	}
};



template <
	class Derived,
	class T,
	class Distance,
	class Pointer,
	class Reference
>
class IteratorFacade<Derived, std::random_access_iterator_tag, T, Distance, Pointer, Reference>
		: public IteratorFacade<Derived,std::bidirectional_iterator_tag, T, Distance, Pointer, Reference>
		, public lz::LessThanComparableFacade<Derived>
{
	using Base = IteratorFacade<Derived,std::bidirectional_iterator_tag, T, Distance, Pointer, Reference>;

public:
	using iterator_category = std::random_access_iterator_tag;

	friend Derived operator+(const Derived &a, typename Base::difference_type b)
	{
		Derived res = a;
		res += b;
		return res;
	}
	friend Derived operator+(typename Base::difference_type b, const Derived &a)
	{
		Derived res = a;
		res += b;
		return res;
	}
	Derived operator-(typename Base::difference_type b) const
	{
		Derived res = this->derived();
		res += -b;
		return res;
	}
	Derived& operator-=(typename Base::difference_type o)
	{
		this->derived() += -o;
		return this->derived();
	}

	typename Base::reference operator[](typename Base::difference_type o) const
	{
		return *(this->derived() + o);
	}



























};


template<typename Integer>
class IntegerIterator: public IteratorFacade<
							IntegerIterator<Integer>,
							std::random_access_iterator_tag,
							Integer,
							std::ptrdiff_t,
							Integer*,
							Integer>
{
	Integer m_val;
	using Base = IteratorFacade<
			IntegerIterator<Integer>,
			std::random_access_iterator_tag,
			Integer,
			std::ptrdiff_t,
			Integer*,
			Integer>;
	using Derived = IntegerIterator<Integer>;
public:
	IntegerIterator() = default;
	explicit IntegerIterator(Integer val):m_val(val) {}

	

	Derived& operator++()
	{
		++ m_val;
		return this->derived();
	}
	typename Base::reference operator*() const
	{
		return m_val;
	}
	bool operator==(Derived const& f) const
	{
		return m_val == f.m_val;
	}

	

	Derived& operator--()
	{
		-- m_val;
		return this->derived();
	}

	

	Derived& operator+=(typename Base::difference_type n)
	{
		m_val += n;
		return this->derived();
	}
	typename Base::difference_type operator-(Derived const& f) const
	{
		return m_val - f.m_val;
	}

	bool operator<(IntegerIterator const& f) const
	{
		return m_val < f.m_val;
	}



};



} 











namespace lz {


using std::vector;
using std::cout;
using std::endl;
using std::pair;
using std::make_pair;

template<typename DirectedCategory = DirectedGraphTag,
         typename VP = NoProperty,
         typename EP = NoProperty,
         typename GP = NoProperty>
class id25;

    namespace AdjacencyListPrivate {

    using VertexDescriptor = int;
    using EdgeDescriptor = int;
    using SizeType = int;



    

    template<typename VP>
    struct VertexData: public ChooseDefineProperties<VP>
	{
    	EdgeDescriptor head;
    	VertexData(EdgeDescriptor _head, const VP &vp):head(_head)
    	{
    		ChooseDefineProperties<VP>::set(vp);
    	}
	};

    

	template<typename EP>
	struct EdgeData:ChooseDefineProperties<EP>
	{
		VertexDescriptor source, target;
		EdgeDescriptor next;

		EdgeData(VertexDescriptor source, VertexDescriptor target, EdgeDescriptor next, const EP & ep)
		:source(source), target(target), next(next)
		{
			ChooseDefineProperties<EP>::set(ep);
		}
	};

    

    template<typename VP, typename EP, typename GP>
    struct GraphData:public ChooseDefineProperties<GP>
    {
        vector<VertexData<VP> > v;
        vector<EdgeData<EP> > e;
        EdgeDescriptor addEdge(VertexDescriptor a, VertexDescriptor b, const EP &ep = EP())
		{
			this->e.push_back(EdgeData<EP>(a, b, this->v[a].head, ep));
			return this->v[a].head = this->e.size() - 1;
		}
    };



    template<typename G>
    class id18: public IteratorFacade<
		id18<G>,
		std::forward_iterator_tag,
		typename GraphTraits<G>::EdgeDescriptor,
		std::ptrdiff_t,
		typename GraphTraits<G>::EdgeDescriptor*,
		typename GraphTraits<G>::EdgeDescriptor >
	{
    	template<typename D, typename VP, typename EP, typename GP> friend class id25;

    	EdgeDescriptor i; 

    	const G *g;
    	id18(EdgeDescriptor i, const G *g): i(i), g(g) {} 


	public:
    	id18():i(-1), g(nullptr) {}

    	id18& operator++()
		{
    		i = g->e[i].next;
    		return *this;
		}
    	typename id18::reference operator*() const
    	{
    		return G::R2V(i);
    	}
    	bool operator==(id18 const& o) const
		{
    		return G::R2V(i) == G::R2V(o.i) && g == o.g;
		}
	};

    

    

    

    

    

    template<typename Direction, typename VP, typename EP, typename GP>
    struct DistinguishDirectionGraph: public GraphData<VP, EP, GP>
    {
    	static EdgeDescriptor V2R(EdgeDescriptor e) { return e; }
    	static EdgeDescriptor R2V(EdgeDescriptor e) { return e; }
    	using GraphData<VP, EP, GP>::addEdge;
    };

    template<typename VP,
			 typename EP,
			 typename GP>
    struct DistinguishDirectionGraph<UndirectedGraphTag, VP, EP, GP>
    	:public GraphData<VP, EP, GP>
    {
    	static EdgeDescriptor V2R(EdgeDescriptor e) { return e << 1; }
    	static EdgeDescriptor R2V(EdgeDescriptor e) { return e >> 1; }
    	using Base = GraphData<VP, EP, GP>;
    	EdgeDescriptor addEdge(VertexDescriptor a, VertexDescriptor b, const EP &ep = EP())
		{
    		Base::addEdge(a, b, ep);
			return Base::addEdge(b, a, ep) >> 1;
		}
    };

    } 





template<typename D, typename VP, typename EP, typename GP>
class id24< id25<D, VP, EP, GP>, VertexIndexTag>
	:public IdentityMap<typename GraphTraits< id25<D, VP, EP, GP> >::VertexDescriptor>
{
public:
	id24() = default;
	id24(const id25<D, VP, EP, GP> &_g){}

	using Type = id24< id25<D, VP, EP, GP>, VertexIndexTag>;
	using ConstType = Type;
};

template<typename D, typename VP, typename EP, typename GP>
class id1<id25<D, VP, EP, GP>, EdgeIndexTag>
	:public IdentityMap<typename GraphTraits<id25<D, VP, EP, GP>>::EdgeDescriptor>
{
public:
	id1() = default;
	id1(const id25<D, VP, EP, GP> &_g){}
	using Type = id1;
	using ConstType = Type;
};




template<typename Direction, typename VP,
		 typename EP, typename GP>
class id25: private AdjacencyListPrivate::DistinguishDirectionGraph<
					 Direction, VP, EP, GP>
{
	template<typename G> friend class AdjacencyListPrivate::id18;

	using VertexData = AdjacencyListPrivate::VertexData<VP> ;
	using EdgeData = AdjacencyListPrivate::EdgeData<EP> ;
	using G = id25;
	using Base = AdjacencyListPrivate::DistinguishDirectionGraph<
				 Direction, VP, EP, GP>;
public:
	using DirectedCategory = Direction;
	using VertexProperties = VP;
	using EdgeProperties = EP;
	using GraphProperties = GP;

	using VertexDescriptor = AdjacencyListPrivate::VertexDescriptor ;
	using EdgeDescriptor = AdjacencyListPrivate::EdgeDescriptor ;
	using SizeType = AdjacencyListPrivate::SizeType;

	using VertexIterator = IntegerIterator<VertexDescriptor>;
	using EdgeIterator = IntegerIterator<EdgeDescriptor>;
	using id18 = AdjacencyListPrivate::id18<G>;
	template<typename Tag>
	using id24 = lz::id24<G, Tag>;
	template<typename Tag>
	using id1 = lz::id1<G, Tag>;

	explicit id25(SizeType n = 0, const VP & vp = VP())
	{
		this->v.assign(n, VertexData(-1, vp));
	}
	void clear()
	{
		this->v.clear();
		this->e.clear();
	}
	VertexDescriptor addVertex(const VP &vp = VP())
	{
		this->v.push_back(VertexData(-1, vp));
		return this->v.size() - 1;
	}
	SizeType vertexNumber() const { return this->v.size(); }
	SizeType edgeNumber() const { return this->R2V(this->e.size() - 1) + 1; }
	const GP& graphProperties() const { return this->properties; }
	GP& graphProperties() { return this->properties; }
	VertexDescriptor source(EdgeDescriptor e) const { return this->e[this->V2R(e)].source; }
	VertexDescriptor target(EdgeDescriptor e) const { return this->e[this->V2R(e)].target; }

	VP& vertexProperties(VertexDescriptor u)
	{ return this->v[u].properties; }
	const VP& vertexProperties(VertexDescriptor u) const
	{ return this->v[u].properties; }

	EP& edgeProperties(EdgeDescriptor e)
	{ return this->e[this->V2R(e)].properties; }
	const EP& edgeProperties(EdgeDescriptor e) const
	{ return this->e[this->V2R(e)].properties; }

	EdgeDescriptor addEdge(VertexDescriptor a, VertexDescriptor b, const EP &ep = EP())
	{ return this->Base::addEdge(a, b, ep); }

	template<typename Tag>
	typename id24<Tag>::Type
	id8(Tag tag)
	{
		return id26<G, Tag>(*this, tag);
	}

	template<typename Tag>
	typename id24<Tag>::ConstType
	id8(Tag tag) const
	{
		return id26<G, Tag>(*this, tag);





	}



	template<typename Tag>
	typename id1<Tag>::Type
	id10(Tag tag)

	{ return id23(*this, tag); }

	template<typename Tag>
	typename id1<Tag>::ConstType
	id10(Tag tag) const
	{ return id23(*this, tag); }


	pair<VertexIterator, VertexIterator> vertices() const
	{
		return make_pair(VertexIterator(0),
						 VertexIterator(this->vertexNumber()));
	}
	pair<EdgeIterator, EdgeIterator> edges() const
	{
		return make_pair(EdgeIterator(0), EdgeIterator(this->edgeNumber()));
	}
	pair<id18, id18> outEdges(VertexDescriptor u) const
	{
		return make_pair(id18(this->v[u].head, this),
						 id18(-1, this)) ;
	}

};







} 



























namespace lz{


struct ParamNotFound {
	using Keyword = ParamNotFound;
	using Reference = ParamNotFound;
	using Next = ParamNotFound;
};
struct EmptyParamPack;


namespace Parameter{



template<typename _Tag>
struct Keyword;
template<typename _Keyword, typename _Default>
struct Default;

template<typename _Keyword, typename _Default>
struct LazyDefault;

template<typename ArgList, typename QueryKeyword, typename Keyword>
struct GetParamPackImpl
{
	using ParamPackType = typename GetParamPackImpl<typename ArgList::Next,
							QueryKeyword, typename ArgList::Next::Keyword>::ParamPackType;
};

template<typename ArgList, typename QueryKeyword>
struct GetParamPackImpl<ArgList, QueryKeyword, QueryKeyword>
{
	using ParamPackType = ArgList;
};

template<typename ArgList, typename QueryKeyword>
struct GetParamPackImpl<ArgList, QueryKeyword, EmptyParamPack>
{
	using ParamPackType = EmptyParamPack;
};

template<typename ArgList, typename QueryKeyword>
struct GetParamPack
{
	using ParamPackType = typename GetParamPackImpl<ArgList, QueryKeyword, typename ArgList::Keyword>::ParamPackType;
};



template<typename ArgList, typename QueryKeyword, typename Base = typename GetParamPack<ArgList, QueryKeyword>::ParamPackType >
struct GetReference
{
	static auto apply(const ArgList &ag)
	->decltype(std::forward<typename Base::Reference>(ag.Base::ref))
	{




		return std::forward<typename Base::Reference>(ag.Base::ref);
	}
};

template<typename ParamPack, typename QueryKeyword>
struct GetReference<ParamPack, QueryKeyword, EmptyParamPack>
{
	static ParamNotFound apply(const ParamPack &ag)
	{
		return ParamNotFound();
	}
};

template<typename _Keyword, typename _Default>
struct Default
{
	using Keyword =_Keyword;
	using Reference =_Default;

	Reference ref;
	Default(Reference ref):ref(std::forward<Reference>(ref)) {}

	Default(const Default &o)
	:ref(std::forward<Reference>(o.ref)) {}
};

template<typename _Keyword, typename _Default>
struct LazyDefault
{
	using Keyword =_Keyword;
	using Reference =_Default;

	Reference ref;

	LazyDefault(Reference ref):ref(std::forward<Reference>(ref)) {}

	LazyDefault(const LazyDefault &o)
	:ref(std::forward<Reference>(o.ref)) {}
};


template<typename ParamPack, typename Default,
		 typename Base = typename GetParamPack<ParamPack, typename Default::Keyword>::ParamPackType>
struct ComputeDefault
{
	static auto apply(const ParamPack &ar, Default o)
	->decltype(ar[typename Default::Keyword()])
	{
		return ar[typename Default::Keyword()];
	}
};
template<typename ParamPack, typename Default>
struct ComputeDefault<ParamPack, Default, EmptyParamPack>
{
	static auto apply(const ParamPack &ar, Default o)
	->decltype(std::forward<typename Default::Reference>(o.ref))
	{
		return std::forward<typename Default::Reference>(o.ref);
	}
};



template<typename ParamPack, typename LazyDefault,
		 typename Base = typename GetParamPack<ParamPack, typename LazyDefault::Keyword>::ParamPackType>
struct ComputeLazyDefault
{
	static auto apply(const ParamPack &ar, LazyDefault o)
	->decltype(ar[typename LazyDefault::Keyword()])
	{
		return ar[typename LazyDefault::Keyword()];
	}
};
template<typename ParamPack, typename LazyDefault>
struct ComputeLazyDefault<ParamPack, LazyDefault, EmptyParamPack>
{
	static auto apply(const ParamPack &ar, LazyDefault o)
	->decltype(o.ref())
	{
		return o.ref();
	}
};





} 




struct EmptyParamPack
{

	using Keyword = EmptyParamPack;
	using Reference = EmptyParamPack;
	using Next = EmptyParamPack;

	template<typename QTag>
	ParamNotFound operator[](Parameter::Keyword<QTag>) const
	{
		return ParamNotFound();
	}

	template<typename QK, typename D>
	auto operator[](Parameter::Default<QK, D> o) const
	->decltype(std::forward<decltype(o.ref)>(o.ref))
	{
		return std::forward<decltype(o.ref)>(o.ref);
	}


	template<typename QK, typename D>
	auto operator[](Parameter::LazyDefault<QK, D> o) const
	->decltype(o.ref())
	{
		return o.ref();
	}



















































};



namespace Parameter{






template<typename _Keyword, typename _Reference, typename _Next = EmptyParamPack>
struct ParamPack:public _Next
{


	template<typename QK>
	using QueryReference = decltype(GetReference<ParamPack, typename std::decay<QK>::type>::apply(

			std::declval<ParamPack>()
			   ) );

	_Reference ref;
	ParamPack(_Reference _ref):ref(std::forward<_Reference>(*&_ref)  )
	{








	}
	ParamPack(_Reference ref, const _Next &next):ref(std::forward<_Reference>(ref)), _Next(next) {}

	ParamPack(const ParamPack &o)
	:ref(std::forward<_Reference>(o.ref)), _Next(*static_cast<const _Next*>(&o) )


	{



	}

	template<typename OKeyword, typename OReference>
	ParamPack<OKeyword, OReference, ParamPack> operator,(ParamPack<OKeyword, OReference> o) const
	{
		return ParamPack<OKeyword, OReference, ParamPack>
				(std::forward<OReference>(o.ref), *this);
	}

	template<typename QTag>
	auto operator[](Parameter::Keyword<QTag>) const
	->decltype(GetReference<ParamPack, Parameter::Keyword<QTag> >::apply(*this))
	{




		return GetReference<ParamPack, Parameter::Keyword<QTag> >::apply(*this);
	}

	template<typename QK, typename D>
	auto operator[](Default<QK, D> o) const

	->decltype(ComputeDefault<ParamPack, Default<QK, D>>::apply(*this, o))
	{
		return ComputeDefault<ParamPack, Default<QK, D>>::apply(*this, o);
	}



	template<typename QK, typename D>
	auto operator[](LazyDefault<QK, D> o) const
	->decltype(ComputeLazyDefault<ParamPack, LazyDefault<QK, D> >::apply(*this, o))
	{
		return ComputeLazyDefault<ParamPack, LazyDefault<QK, D> >::apply(*this, o);
	}

	using Keyword = _Keyword;
	using Reference = _Reference;
	using Next = _Next;

};




template<typename _Tag>
struct Keyword
{
	using Tag = _Tag;

	template<typename T>
	auto operator=(T &&t) const
	->ParamPack<Keyword, decltype(std::forward<T>(t))>
	{


		return ParamPack<Keyword, decltype(std::forward<T>(t))>(std::forward<T>(t));
	}


	template<typename T>
	auto operator|(T &&t) const
	->Default<Keyword, decltype(std::forward<T>(t)) >
	{
		return Default<Keyword, decltype(std::forward<T>(t)) >(std::forward<T>(t));
	}

	template<typename T>
	auto operator||(T &&t) const
	->LazyDefault<Keyword, decltype(std::forward<T>(t))>
	{
		return LazyDefault<Keyword, decltype(std::forward<T>(t))>(std::forward<T>(t));
	}




	static const Keyword<Tag> instance;
};
template<typename _Tag>
const Keyword<_Tag> Keyword<_Tag>::instance = {};













    namespace tag_namespace                                         \
    {                                                               \
		struct name                                                 \
		{                                                           \
		};                                                          \
    }                                                               \
    namespace                                                       \
    {                                                               \
		::lz::Parameter::Keyword<tag_namespace::name> const& name   \
		= ::lz::Parameter::Keyword<tag_namespace::name>::instance;  \
    }																\


	LZ_PARAMETER_KEYWORD(tag, name)



}

















template<typename ParamPack, typename KeywordType, typename Default = ParamNotFound>
using ChooseParamType =	typename std::conditional<

	!std::is_same<typename Parameter::GetParamPack<ParamPack, KeywordType>::ParamPackType::Reference, ParamNotFound >::value,

	typename Parameter::GetParamPack<ParamPack, KeywordType>::ParamPackType::Reference,


	Default>::type;




} 































































namespace lz {

using std::tie;
using std::pair;
using std::stack;
using std::vector;
using std::cout;
using std::endl;



namespace DepthFirstSearchKeywords {

	LZ_PARAMETER_KEYWORD(tag, initializeVertex)
	LZ_PARAMETER_KEYWORD(tag, startVertex)
	LZ_PARAMETER_KEYWORD(tag, discoverVertex)
	LZ_PARAMETER_KEYWORD(tag, id11)
	LZ_PARAMETER_KEYWORD(tag, treeEdge)
	LZ_PARAMETER_KEYWORD(tag, id20)
	LZ_PARAMETER_KEYWORD(tag, id13)
	LZ_PARAMETER_KEYWORD(tag, finishEdge)
	LZ_PARAMETER_KEYWORD(tag, finishVertex)


	LZ_PARAMETER_KEYWORD(tag, colorMap)
	LZ_PARAMETER_KEYWORD(tag, white)
	LZ_PARAMETER_KEYWORD(tag, black)

	LZ_PARAMETER_KEYWORD(tag, isInit)
	LZ_PARAMETER_KEYWORD(tag, id15)
	LZ_PARAMETER_KEYWORD(tag, outEdges)
	LZ_PARAMETER_KEYWORD(tag, enterVertex)
}



	namespace DepthFirstSearchPrivate {


	using namespace DepthFirstSearchKeywords;


	template<typename G, typename ParamPack>
	struct Impl
	{
		const G &g;
		const ParamPack &p;

		Impl(const G &g, const ParamPack &p):g(g), p(p)
		{
			init(p[isInit]);
			id12(p[enterVertex]);
		}

		void dfs(typename GraphTraits<G>::VertexDescriptor u)
		{
			p[colorMap][u] = p[black]();
			p[discoverVertex](u);
			auto ei = p[outEdges](g, u);
			for(;ei.first != ei.second; ++ ei.first)
			{
				auto e = *ei.first;
				auto to = g.target(e);
				p[id11](e, u);
				if(p[colorMap][to] == p[white]())
				{
					p[treeEdge](e, u);
					dfs(to);
					p[id20](e, u);
				}
				else
				{
					p[id13](e, u);
				}
				p[finishEdge](e, u);
			}
			p[finishVertex](u);
		}

		void init(std::true_type)
		{
			auto&& vi = g.vertices();
			for(;vi.first != vi.second; ++vi.first)
			{
				auto&& u = *vi.first;
				p[colorMap][u] = p[white]();
				p[initializeVertex](u);
			}
		}
		void init(std::false_type) {}


		template<typename EnterVertex>
		void id12(EnterVertex u)
		{
			p[startVertex](u);
			dfs(u);
		}
		void id12(ParamNotFound )
		{
			auto&& vi = g.vertices();
			for(;vi.first != vi.second; ++vi.first)
			{
				auto&& u = *vi.first;
				if(p[colorMap][u] == p[white]())
				{
					p[startVertex](u);
					dfs(u);
				}
			}
		}


	};

	}


template<typename G, typename ParamPack>
void id22(const G &g, const ParamPack &p)
{
	using namespace DepthFirstSearchKeywords;

	auto _white = p[white | ColorTraits<>::white];
	auto _black = p[black | ColorTraits<>::black];
	auto _isInit = p[isInit | std::true_type()];

	auto _outEdges = p[outEdges | std::mem_fn(&G::outEdges)];
	auto id4 = p[id15 | g.id8(VertexIndexTag())];

	using ColorValue = decltype(_white());

	auto n = g.vertexNumber();

	auto iMap = p[id15 | g.id8(VertexIndexTag())];

	auto gg = std::bind(
			id14<ColorValue, decltype(iMap), decltype(n) >,
			iMap, n);


	auto _colorMap = p[colorMap
					   ||

					   std::bind(
					   			id14<ColorValue, decltype(iMap), decltype(n) >,
					   			iMap, n)

					   ];
	auto _enterVertex = p[enterVertex];

	using V = typename GraphTraits<G>::VertexDescriptor;
	using E = typename GraphTraits<G>::EdgeDescriptor;

	auto actionVertex = [](V u){};
	auto actionEdge = [](E e, V u){};

	auto id19 = (
			initializeVertex = p[initializeVertex | actionVertex],
			startVertex = p[startVertex | actionVertex],
			discoverVertex = p[discoverVertex | actionVertex],
			id11 = p[id11 | actionEdge],
			treeEdge = p[treeEdge | actionEdge],
			id20 = p[id20 | actionEdge],
			id13 = p[id13 | actionEdge],
			finishEdge = p[finishEdge | actionEdge],
			finishVertex = p[finishVertex | actionVertex],

			white = _white,
			black = _black,
			isInit = _isInit,
			outEdges = _outEdges,
			id15 = id4,
			colorMap = _colorMap,
			enterVertex =  _enterVertex);


	DepthFirstSearchPrivate::Impl
	<G, decltype(id19)>(g, id19);






}
























































































































































































































































































} 












namespace lz {

using std::swap;
using std::less;

namespace StronglyConnectedComponentsKeywords {

	LZ_PARAMETER_KEYWORD(tag, id15)
	LZ_PARAMETER_KEYWORD(tag, id2)
	LZ_PARAMETER_KEYWORD(tag, rootMap)
}


    namespace StronglyConnectedComponentsPrivate {




    }








    template<typename G, typename ComponentMap, typename ParamPack = lz::EmptyParamPack>

	auto id17(const G &g, ComponentMap compMap, const ParamPack &p = lz::EmptyParamPack() )
    {
		static_assert(std::is_same<typename GraphTraits<G>::DirectedCategory, DirectedGraphTag>::value, "this graph is not directed");

		namespace k = StronglyConnectedComponentsKeywords;

		auto indexMap = p[k::id15 | g.id8(VertexIndexTag())];

		using Vertex = typename GraphTraits<G>::VertexDescriptor;
		using Edge = typename GraphTraits<G>::EdgeDescriptor;


		auto n = g.vertexNumber();

		auto id2 =
				p[k::id2 ||
				 std::bind(id14<size_t, decltype(indexMap), decltype(n) >,
						   indexMap, n) ];

		auto rootMap =  p[k::rootMap ||
						  std::bind(id14<Vertex, decltype(indexMap), decltype(n) >,
						  		    indexMap, n)];


		using ComponentType = typename std::decay<typename MapTraits<ComponentMap>::ValueType>::type;
		using TimeType = typename std::decay<typename MapTraits<decltype(id2)>::ValueType>::type;

		using namespace DepthFirstSearchKeywords;

		ComponentType compNumber = 0;
		TimeType dfsTime = 0;

		std::vector<Vertex> stack;
		std::vector<bool>inStack(n, 0);


		auto minRoot = [&](Vertex u, Vertex v) ->Vertex
		{
			auto ans =  id2[u] < id2[v] ? u : v;
			return ans;
		};


		id22(g, (

				colorMap = id2,
				white =  []()->TimeType { return 0; },
				black = [&]()->TimeType { return ++dfsTime; }
				,

				discoverVertex = [&](Vertex u)
				{
					rootMap[u] = u;
					stack.push_back(u);
					inStack[u] = 1;
				},

				id20 = [&](Edge e, Vertex u)
				{
					Vertex to = opposite(g, e, u);
					rootMap[u] = minRoot(rootMap[u], rootMap[to]);
				},

				id13 = [&](Edge e, Vertex u)
				{
					Vertex to = opposite(g, e, u);
					if(inStack[to])
					{
						rootMap[u] = minRoot(rootMap[u], to);
					}
				},

				finishVertex = [&](Vertex u)
				{
					if(u == rootMap[u])
					{
						Vertex tmp;
						do
						{
							tmp = stack.back();
							stack.pop_back();
							compMap[tmp] = compNumber;
							inStack[tmp] = 0;
						}
						while(tmp != u);
						++compNumber;
					}
				}
		));





		return compNumber;


    }


















































































































































































































































































} 































using namespace std;
using namespace lz;


using G = id25<>;



int main()
{



	G g;
	int n;


	scanf("%d" , &n);

	for(int i = 0; i < n; ++ i) g.addVertex();



	for(int i = 0; i < n; ++ i)
	{
		for(int j = 0; j < n; ++ j)
		{
			int x;
			scanf("%d", &x);


			if(x)
			{


				g.addEdge(i, j);
			}
		}
	}



	vector<int> compMap(n);
	int ans = id17(g, id3(compMap.begin()));









	if(ans == 1) puts("YES");
	else puts("NO");




	return 0;





}




















