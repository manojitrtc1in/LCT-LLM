





























namespace lz {

using std::integral_constant;
using std::cout;
using std::endl;



struct NoProperty {
	using Tag = NoProperty;
	using ValueType = NoProperty;
	using NextProperty = NoProperty;


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



    } 




template<typename _Tag, typename _ValueType, typename _NextProperty = NoProperty >
struct Property: public _NextProperty
{
    template<typename QueryTag, typename Tag, typename Property>
    friend struct PropertyPrivate::Get;

    using Tag = _Tag;
    using ValueType = _ValueType;
    using NextProperty = _NextProperty;

    constexpr Property() = default;

    template<typename Head, typename... Args>
    explicit Property(const Head &value, Args ...args)
    : m_value(value), NextProperty(args...)
    {
        static_assert(PropertyPrivate::CountProperty<Property>::value ==
                      PropertyPrivate::CountVariadic<Head, Args...>::value,
                       "Parameters number is not equal");
    }


    template<typename Head, typename... Args>
    explicit Property(Head &&value, Args ...args)
    : m_value(value), NextProperty(args...)
    {

        static_assert(PropertyPrivate::CountProperty<Property>::value ==
                      PropertyPrivate::CountVariadic<Head, Args...>::value,
                       "Parameters number is not equal");
    }


    template<typename QueryTag>
    auto operator[](QueryTag tag)
    ->decltype(PropertyPrivate::Get<Property, Tag, QueryTag>::get(*this))
	{
    	return PropertyPrivate::Get<Property, Tag, QueryTag>::get(*this);
	}
    template<typename QueryTag>
	auto operator[](QueryTag tag) const
    ->decltype(PropertyPrivate::Get<Property, Tag, QueryTag>::get(*this))
	{
		return PropertyPrivate::Get<Property, Tag, QueryTag>::get(*this);
	}

    template<typename QueryTag>
    constexpr bool contains(QueryTag tag) const
    {
    	return !std::is_same<decltype((*this)[tag]), NoProperty::ValueType>::value;
    }
private:
    ValueType m_value;

};





    namespace PropertyPrivate {

        template<typename Property, typename Tag, typename QueryTag>
        struct Get
        {
            typedef typename Property::NextProperty  NextProperty;

            static auto get(Property &p)
            ->decltype(Get<NextProperty, typename NextProperty::Tag, QueryTag>::
            		   get(static_cast<NextProperty&>(p)))
            {
                return Get<NextProperty, typename NextProperty::Tag, QueryTag>::
                       get(static_cast<NextProperty&>(p));
            }

            static auto get(const Property &p)
            ->decltype(Get<NextProperty, typename NextProperty::Tag, QueryTag>::
            		   get(static_cast<const NextProperty&>(p)))
            {
                return Get<NextProperty, typename NextProperty::Tag, QueryTag>::
                       get(static_cast<const NextProperty&>(p));
            }

        };

        template<typename Property, typename QueryTag>
        struct Get<Property, QueryTag, QueryTag>
        {
            typedef typename Property::ValueType ValueType;

            static ValueType& get(Property &p)
            {
                return p.m_value;
            }

            static const ValueType& get(const Property &p)
            {
                return p.m_value;
            }
        };

        template<typename QueryTag>
        struct Get<NoProperty, NoProperty::Tag, QueryTag>
        {

            static NoProperty::ValueType get(const NoProperty &p)
            {
                return NoProperty::ValueType();
            }
        };



    } 






template<typename Tag, typename ValueType, typename NextProperty, typename QueryTag>
auto get(Property<Tag, ValueType, NextProperty> & p, QueryTag tag)
-> decltype(PropertyPrivate::Get<Property<Tag, ValueType, NextProperty>, Tag, QueryTag>::get(p))
{
    return PropertyPrivate::Get<Property<Tag, ValueType, NextProperty>, Tag, QueryTag>::get(p);
}

template<typename Tag, typename ValueType, typename NextProperty, typename QueryTag>
auto get(const Property<Tag, ValueType, NextProperty> & p, QueryTag tag)
-> decltype(PropertyPrivate::Get<Property<Tag, ValueType, NextProperty>, Tag, QueryTag>::get(p))
{
    return PropertyPrivate::Get<Property<Tag, ValueType, NextProperty>, Tag, QueryTag>::get(p);
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




















struct ParamNotFound{};

	namespace UtilityPrivate{

		template<typename UserParam, typename DefaultParam>
		struct ChooseParam
		{
			static UserParam& get(UserParam &up, DefaultParam &dp)
			{
				return up;
			}
		};
		template<typename DefaultParam>
		struct ChooseParam<ParamNotFound, DefaultParam>
		{
			static DefaultParam& get(ParamNotFound &up, DefaultParam &dp)
			{
				return dp;
			}
		};

	} 


template<typename ParamRetrunType, typename Default>
auto id17(ParamRetrunType && p, Default && d) ->
decltype(UtilityPrivate::ChooseParam<typename std::remove_reference<ParamRetrunType>::type,
									 typename std::remove_reference<Default>::type >::get(p, d))
{
	return UtilityPrivate::ChooseParam<typename std::remove_reference<ParamRetrunType>::type,
									   typename std::remove_reference<Default>::type>::get(p, d);
}
















template<typename ParamReturnType, typename DefaultType>
using ChooseParamReturnType =  typename std::conditional<std::is_same<ParamReturnType, ParamNotFound>::value,
																DefaultType,
																ParamReturnType>::type;











template<typename Ret, typename Class>
struct MemberFuntionPointer
{
    using ReturnType = Ret;
    using ClassType = Class;
};



template<typename T, typename P>
MemberFuntionPointer<T, P> id9(T (P::*s)() )
{
    return MemberFuntionPointer<T, P>();
}










template<typename ParamName>
using GeneralParamReturnType =
typename std::result_of< ParamName(
		typename decltype(id9(ParamName()))::ClassType
)>::type;


















template <class F1, class F2>
struct id13 : F1, F2
{
	id13(F1 f1, F2 f2)
		: F1(f1), F2(f2)
	{

	}

	using F1::operator();
	using F2::operator();
};

template <class F1, class F2>
id13<F1, F2> id4(F1 f1, F2 f2)
{
	return id13<F1, F2>(f1, f2);
}


































































template<typename T>
int id5(T x)
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
















namespace lz {

using std::function;
using std::cout;
using std::endl;

template<typename Map>
struct MapTraits
{
	using KeyType = typename Map::KeyType;
	using ValueType = typename Map::ValueType;
};

template<typename Key, typename Value, typename ReferenceType = Value&>
struct MapFacade
{
	using KeyType = Key;
	using ValueType = Value;
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
	auto operator[](typename Base::KeyType key) const -> decltype((*f)[key])
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

	auto operator[](typename Base::KeyType key) const->decltype(i[key])
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
	explicit ComposeMap(FM fm, SM sm):fm(fm), sm(sm){}

	FirstMap firstMap() const { return fm; }
	SecondMap secondMap() const { return sm; }

	auto operator[](typename Base::KeyType key) const ->decltype(sm[fm[key]])
	{
		return sm[fm[key]];
	}
};

template<typename FM, typename SM>
ComposeMap<FM, SM> id0(FM fm, SM sm)
{
	return ComposeMap<FM, SM>(fm, sm);
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

	using id15 = typename G::id15;


	template<typename Tag>
	using id19 = typename G::template id19<Tag>;

	template<typename Tag>
	using id1 = typename G::template id1<Tag>;

};









template<typename G, typename VertexIndexMapName>
using ChooseVertexIndexMap = ChooseParamReturnType<GeneralParamReturnType<VertexIndexMapName>,
												   decltype( G().id6(VertexIndexTag()))  >;


template<typename GeneralParamName, typename VertexIndexMap, typename ValueType>
using ChooseVertexIndexComposeMap = ChooseParamReturnType<
		GeneralParamReturnType<GeneralParamName>,
		ComposeMap<VertexIndexMap, IteratorMap<ValueType*> >
>;


template<typename DefaultValueType, typename ParamReturnType, typename VertexIndexMap, typename VertexNumberType>
auto
id20(ParamReturnType paramMap, VertexIndexMap indexMap, VertexNumberType n)
->decltype(paramMap)
{
	return paramMap;
}

template<typename DefaultValueType, typename VertexIndexMap, typename VertexNumberType>
auto
id20( ParamNotFound, VertexIndexMap indexMap, VertexNumberType n)
->decltype(id0(indexMap, id3(new DefaultValueType[n])))
{
	return id0(indexMap, id3(new DefaultValueType[n]));
}

template<typename Map, typename ParamRetrunType>
void id8(Map map, ParamRetrunType )
{

}
template<typename Map>
void id8(Map map, ParamNotFound )
{


	delete[] map.secondMap().iterator();
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
		: public std::iterator<std::forward_iterator_tag, T, Distance, Pointer, Reference>
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






	bool operator!=(const Derived &o) const
	{
		return !(this->derived() == o);
	}


protected:

	Derived& derived()
	{
		return *static_cast<Derived*>(this);
	}

	Derived const& derived() const
	{
		return *static_cast<Derived const*>(this);
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












;	bool operator>(const Derived &o) const
	{
		return o < this->derived();
	}
	bool operator<=(const Derived &o) const
	{
		return !(o < this->derived());
	}
	bool operator>=(const Derived &o) const
	{
		return !(this->derived() < o);
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
class id21;

    namespace AdjacencyListPrivate {


    using VertexDescriptor = int;
    using EdgeDescriptor = int;



    

    template<typename VP> struct VertexData;

    template<>
    struct VertexData<NoProperty>
    {
    	using VP = NoProperty;
    	EdgeDescriptor head;
        VertexData(EdgeDescriptor head, const NoProperty &vp):head(head) {}
    };

    template<typename _VP>
    struct VertexData:public VertexData<NoProperty>
    {
    	using VP = _VP;
        VP vp;
        VertexData(EdgeDescriptor _head, const VP &vp): VertexData<NoProperty>(_head, NoProperty()), vp(vp) {}
    };




    

	template<typename EP> struct EdgeData;

	template<>
	struct EdgeData<NoProperty>
	{
		using EP = NoProperty;
		VertexDescriptor source, target;
		EdgeDescriptor next;
		EdgeData(VertexDescriptor source, VertexDescriptor target, EdgeDescriptor next, const NoProperty & ep)
		:source(source), target(target), next(next){}
	};
    template<typename _EP>
    struct EdgeData:public EdgeData<NoProperty>
    {
    	using EP = _EP;
    	EP ep;
        EdgeData(VertexDescriptor source, VertexDescriptor target, EdgeDescriptor next, const EP & ep)
    	:EdgeData<NoProperty>(source, target, next, NoProperty()), ep(ep){}
    };


    

	template<typename VP, typename EP, typename GP> struct GraphData;

    template<typename VP, typename EP>
    struct GraphData<VP, EP, NoProperty>
    {
        vector<VertexData<VP> > v;
        vector<EdgeData<EP> > e;
    };
    template<typename VP, typename EP, typename GP>
    struct GraphData:public GraphData<VP, EP, NoProperty>
    {
    	GraphData gp;
    };



    template<typename G>
    class id15:
    		public IteratorFacade<
				id15<G>,
				std::forward_iterator_tag,
				typename GraphTraits<G>::EdgeDescriptor,
				std::ptrdiff_t,
				typename GraphTraits<G>::EdgeDescriptor*,
				typename GraphTraits<G>::EdgeDescriptor
				>
	{
    	template<typename D, typename VP, typename EP, typename GP> friend class id21;
    	const G *g = nullptr;
    	EdgeDescriptor i; 

    	id15(EdgeDescriptor i, const G *g): i(i), g(g){} 

	public:
    	id15() = default;

    	id15& operator++()
		{
    		i = g->e[i].next;
    		return *this;
		}
    	typename id15::reference operator*() const
    	{
    		return G::R2V(i);
    	}
    	bool operator==(id15 const& o) const
		{
    		return G::R2V(i) == G::R2V(o.i) && g == o.g;
		}
	};

    template<typename G, typename Tag>
	class id19:
			public MapFacade<typename GraphTraits<G>::VertexDescriptor,
    						 decltype(typename G::VertexData::VP()[Tag()])>
	{
    	template<typename D, typename VP, typename EP, typename GP> friend class id21;
		G *g = nullptr;
		id19(G *_g):g(_g){}
	public:
		using Type = id19<G, Tag>;
		using ConstType = id19<const G, Tag>;

		id19() = default;
		auto operator[](typename GraphTraits<G>::VertexDescriptor u) const
		->decltype(get(g->v[u].vp, Tag()))
		{
			return get(g->v[u].vp, Tag());
		}
	};

    template<typename G>
    class id19<G, VertexIndexTag>: public IdentityMap<VertexDescriptor>
    {
    	template<typename D, typename VP, typename EP, typename GP> friend class id21;
    	id19(G *_g) {}
    public:
    	id19(){}
    	using Type = id19<G, VertexIndexTag>;
    	using ConstType = id19<const G, VertexIndexTag>;
    };


    template<typename G, typename Tag>
    class id1




   	{
    	template<typename D, typename VP, typename EP, typename GP> friend class id21;
       	G *g = nullptr;
       	id1(G *_g):g(_g){}
   	public :
		using Type = id1<G, Tag>;
		using ConstType = id1<const G, Tag>;

       	id1() = default;
       	auto operator[](typename GraphTraits<G>::EdgeDescriptor e) const
		->decltype(get(g->e[G::V2R(e)].ep, Tag()))
   		{
       		return get(g->e[G::V2R(e)].ep, Tag());
   		}
   	};

    template<typename G>
	class id1<G, EdgeIndexTag>: public IdentityMap<EdgeDescriptor>
	{
    	template<typename D, typename VP, typename EP, typename GP> friend class id21;
    	id1(G *_g){}
	public:
    	id1(){}
		using Type = id1<G, EdgeIndexTag>;
		using ConstType = id1<const G, EdgeIndexTag>;
	};



    template<typename VP, typename EP, typename GP>
    struct GraphDataWrapper: public GraphData<VP, EP, GP>
    {
    	EdgeDescriptor addSingleEdge(VertexDescriptor a, VertexDescriptor b, const EP &ep = EP())
		{
			this->e.push_back(EdgeData<EP>(a, b, this->v[a].head, ep));
			return this->v[a].head = this->e.size() - 1;
		}
    };

    

    

    

    

    

    template<typename Direction,
             typename VP,
             typename EP,
             typename GP>
    struct DistinguishDirectionGraph: public GraphDataWrapper<VP, EP, GP>
    {
    	static EdgeDescriptor V2R(EdgeDescriptor e) { return e; }
    	static EdgeDescriptor R2V(EdgeDescriptor e) { return e; }
    	EdgeDescriptor addEdge(VertexDescriptor a, VertexDescriptor b, const EP &ep = EP())
    	{
    		return this->addSingleEdge(a, b, ep);
    	}
    };

    template<typename VP,
			 typename EP,
			 typename GP>
    struct DistinguishDirectionGraph<UndirectedGraphTag, VP, EP, GP>: public GraphDataWrapper<VP, EP, GP>
    {
    	static EdgeDescriptor V2R(EdgeDescriptor e) { return e << 1; }
    	static EdgeDescriptor R2V(EdgeDescriptor e) { return e >> 1; }
    	EdgeDescriptor addEdge(VertexDescriptor a, VertexDescriptor b, const EP &ep = EP())
		{
    		this->addSingleEdge(a, b, ep);
			return this->addSingleEdge(b, a, ep) >> 1;
		}
    };

    } 



template<typename Direction,
		 typename VP,
		 typename EP,
		 typename GP>
class id21: private AdjacencyListPrivate::DistinguishDirectionGraph<
					 Direction,
					 VP,
					 EP,
					 GP>
{
	template<typename G> friend class AdjacencyListPrivate::id15;
	template<typename G, typename Tag> friend class AdjacencyListPrivate::id19;
	template<typename G, typename Tag> friend class AdjacencyListPrivate::id1;

	using VertexData = AdjacencyListPrivate::VertexData<VP> ;
	using EdgeData = AdjacencyListPrivate::EdgeData<EP> ;
	using G = id21;
	using Base = AdjacencyListPrivate::DistinguishDirectionGraph<
				 Direction,
				 VP,
				 EP,
				 GP>;
public:
	using DirectedCategory = Direction;
	using VertexProperties = VP;
	using EdgeProperties = EP;
	using GraphProperties = GP;

	using VertexDescriptor = AdjacencyListPrivate::VertexDescriptor ;
	using EdgeDescriptor = AdjacencyListPrivate::EdgeDescriptor ;

	using VertexIterator = IntegerIterator<VertexDescriptor>;
	using EdgeIterator = IntegerIterator<EdgeDescriptor>;
	using id15 = AdjacencyListPrivate::id15<G>;

	template<typename Tag>
	using id19 = AdjacencyListPrivate::id19<G, Tag>;

	template<typename Tag>
	using id1 = AdjacencyListPrivate::id1<G, Tag>;

	explicit id21(int n = 0, const VP & vp = VP())
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
	int vertexNumber() const { return this->v.size(); }
	int edgeNumber() const { return this->R2V(this->e.size() - 1) + 1; }
	const GP& graphProperties() const { return this->gp; }
	GP& graphProperties() { return this->gp; }
	VertexDescriptor source(EdgeDescriptor e) const { return this->e[this->V2R(e)].source; }
	VertexDescriptor target(EdgeDescriptor e) const { return this->e[this->V2R(e)].target; }

	VP& vertexProperties(VertexDescriptor u)
	{ return this->v[u].vp; }
	const VP& vertexProperties(VertexDescriptor u) const
	{ return this->v[u].vp; }

	EP& edgeProperties(EdgeDescriptor e)
	{ return this->e[e].ep; }
	const EP& edgeProperties(EdgeDescriptor e) const
	{ return this->e[e].ep; }

	EdgeDescriptor addEdge(VertexDescriptor a, VertexDescriptor b, const EP &ep = EP())
	{ return this->Base::addEdge(a, b, ep); }

	template<typename Tag>
	typename id19<Tag>::Type id6(Tag tag)
	{ return typename id19<Tag>::Type(this); }

	template<typename Tag>
	typename id19<Tag>::ConstType id6(Tag tag) const
	{ return typename id19<Tag>::ConstType(this); }

	template<typename Tag>
	typename id1<Tag>::Type id7(Tag tag)
	{ return typename id1<Tag>::Type(this); }

	template<typename Tag>
	typename id1<Tag>::ConstType id7(Tag tag) const
	{ return typename id1<Tag>::ConstType(this); }

	pair<VertexIterator, VertexIterator> vertices() const
	{
		return make_pair(VertexIterator(0),
						 VertexIterator(this->vertexNumber()));
	}
	pair<EdgeIterator, EdgeIterator> edges() const
	{
		return make_pair(EdgeIterator(0), EdgeIterator(this->edgeNumber()));
	}
	pair<id15, id15> outEdges(VertexDescriptor u) const
	{
		return make_pair(id15(this->v[u].head, this),
						 id15(-1, this)) ;
	}

};





} 




































namespace lz {

using std::tie;
using std::pair;
using std::stack;
using std::vector;
using std::cout;
using std::endl;


	namespace DepthFirstSearchPrivate {

	template<typename G, typename Params>
	struct Impl
	{
		using V = typename GraphTraits<G>::VertexDescriptor;

		using VertexIndexMap = ChooseVertexIndexMap<typename std::add_const<G>::type, decltype(&Params::vertexIndexMap)>;

		using DefaultColor = ColorTraits<>::Type;

		using ColorMap = ChooseVertexIndexComposeMap<decltype(&Params::colorMap), VertexIndexMap, DefaultColor>;


		VertexIndexMap indexMap;
		ColorMap colorMap;
		const G &g;
		Params &p;
		Impl(const G &g, Params &p):g(g), p(p)
		{
			indexMap = id17(p.vertexIndexMap(),
											  g.id6(VertexIndexTag()));

			colorMap = id20<ColorTraits<>::Type>(p.colorMap(), indexMap, g.vertexNumber());
		}

		auto outEdges(V u)
		->typename std::remove_reference<
			decltype(id17(p.outEdges(u), g.outEdges(u) )  )>::type
		{
			return id17(p.outEdges(u), g.outEdges(u) );
		};

		void init(std::true_type)
		{
			auto&& vi = g.vertices();
			for(;vi.first != vi.second; ++vi.first)
			{
				auto&& u = *vi.first;
				colorMap[u] = p.white();
				p.initializeVertex(u);
			}
		}
		void init(std::false_type) {}

		template<typename EnterVertex>
		void id11(EnterVertex u)
		{
			p.startVertex(u);
			dfs(u);
		}

		void id11(ParamNotFound )
		{
			auto&& vi = g.vertices();
			for(;vi.first != vi.second; ++vi.first)
			{
				auto&& u = *vi.first;
				if(colorMap[u] == p.white())
				{
					p.startVertex(u);
					dfs(u);
				}
			}
		}


		void dfs(typename GraphTraits<G>::VertexDescriptor u)
		{
			colorMap[u] = p.black();
			p.discoverVertex(u);
			auto ei = outEdges(u);
			for(;ei.first != ei.second; ++ ei.first)
			{
				auto e = *ei.first;
				auto to = g.target(e);
				p.id10(e, u);
				if(colorMap[to] == p.white())
				{
					p.treeEdge(e, u);
					dfs(to);
					p.id16(e, u);
				}
				else
				{
					p.id12(e, u);
				}
				p.finishEdge(e, u);
			}
			p.finishVertex(u);
		}

		void run()
		{
			init(typename Params::IsInit());
			id11(p.enterVertex());
			id8(colorMap, p.colorMap());
		}







	};



	} 










class DepthFirstSearchParams
{
	using DefaultColor = ColorTraits<>::Type;
public:
	template<typename V> void initializeVertex(V u) {}
	template<typename V> void startVertex(V u) {}
	template<typename V> void discoverVertex(V u) {}
	template<typename E, typename V> void id10(E e, V u) {}
	template<typename E, typename V> void treeEdge(E e, V u) {}
	template<typename E, typename V> void id16(E e, V u) {}
	template<typename E, typename V> void id12(E e, V u) {}
	template<typename E, typename V> void finishEdge(E e, V u) {}
	template<typename V> void finishVertex(V u) {}


	DefaultColor white() { return ColorTraits<>::white(); }
	DefaultColor black() { return ColorTraits<>::black(); }


	using IsInit = std::true_type;


	ParamNotFound vertexIndexMap() {}
	template<typename V>
	ParamNotFound outEdges(V u) {}
	ParamNotFound colorMap() {}
	ParamNotFound enterVertex(){}


};

template<typename G, typename Params>
void id18(const G &g, Params &&p)
{
	using RealParams = typename std::remove_reference<Params>::type;


	DepthFirstSearchPrivate::Impl<G, RealParams> impl(g, p);
	impl.run();




}








} 







namespace lz {

using std::swap;
using std::less;


struct StronglyConnectedComponentsParams{

	ParamNotFound vertexIndexMap(){}
	ParamNotFound id2(){}
	ParamNotFound rootMap(){}
};



    namespace StronglyConnectedComponentsPrivate {



	template<typename G, typename ComponentMap, typename Params>
	struct Impl: public DepthFirstSearchParams
	{
		using V = typename GraphTraits<G>::VertexDescriptor;
		using E = typename GraphTraits<G>::EdgeDescriptor;

		using VertexIndexMap = ChooseVertexIndexMap<typename std::add_const<G>::type, decltype(&Params::vertexIndexMap)>;


		using DiscoverTimeMap = ChooseVertexIndexComposeMap<decltype(&Params::id2), VertexIndexMap, size_t>;


		using RootMap = ChooseVertexIndexComposeMap<decltype(&Params::rootMap), VertexIndexMap, V>;



		using ComponentType = typename std::decay<typename MapTraits<ComponentMap>::ValueType>::type;
		using TimeType = typename std::decay<typename MapTraits<DiscoverTimeMap>::ValueType>::type;


		const G &g;
		ComponentMap compMap;
		Params &p;


		DiscoverTimeMap id2;
		RootMap rootMap;
		vector<bool> inStack;
		vector<V> stack;
		ComponentType compNumber = 0;
		TimeType dfsTime = 0;

		Impl(const G &g,
			 ComponentMap compMap,
			 Params & p):g(g), compMap(compMap), p(p)
		{
			VertexIndexMap
			indexMap = id17(
						p.vertexIndexMap(),
						g.id6(VertexIndexTag()));
			auto n = g.vertexNumber();

			id2 = id20<size_t>(p.id2(), indexMap, n);

			rootMap = id20<V>(p.rootMap(), indexMap, n);

			inStack.assign(n, 0);
		}



		DiscoverTimeMap colorMap() { return id2; }
		TimeType white() { return 0; }
		TimeType black()
		{
			return ++ dfsTime;
		}

		void discoverVertex(V u)
		{
			rootMap[u] = u;
			stack.push_back(u);
			inStack[u] = 1;
		}
		void id16(E e, V u)
		{
			V to = opposite(g, e, u);
			rootMap[u] = minRoot(rootMap[u], rootMap[to]);
		}
		void id12(E e, V u)
		{
			V to = opposite(g, e, u);
			if(inStack[to])
			{

				rootMap[u] = minRoot(rootMap[u], to);
			}

		}
		void finishVertex(V u)
		{
			if(u == rootMap[u])
			{
				V tmp;
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
	private:
		V minRoot(V u, V v)
		{
			return id2[u] < id2[v] ? u : v;
		}
	};







    } 




    template<typename G, typename ComponentMap, typename Params = StronglyConnectedComponentsParams>

    typename std::decay<typename MapTraits<ComponentMap>::ValueType>::type

	id14(const G &g, ComponentMap compMap, Params &&p = StronglyConnectedComponentsParams() )
    {
		static_assert(std::is_same<typename GraphTraits<G>::DirectedCategory, DirectedGraphTag>::value, "this graph is not directed");

		using RealParams = typename std::remove_reference<Params>::type;

		StronglyConnectedComponentsPrivate::Impl<G, ComponentMap, RealParams> impl(g, compMap, p);

		id18(g, impl);
		id8(impl.rootMap, p.rootMap());
		id8(impl.id2, p.id2());


		return impl.compNumber;



    }



}
































using namespace std;
using namespace lz;


using G = id21<>;



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
	int ans = id14(g, id3(compMap.begin()));







	if(ans == 1) puts("YES");
	else puts("NO");




	return 0;





}





















