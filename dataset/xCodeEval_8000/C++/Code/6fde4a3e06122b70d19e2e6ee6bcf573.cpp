

#include <iostream>
#include <cstdio>
#include <cstring>
#include <tuple>
#include <ctime>
#ifndef GRAPH_UTILITY_H
#define GRAPH_UTILITY_H









#ifndef LZ_MAP_H_
#define LZ_MAP_H_



#include <memory>
#include <type_traits>
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





template<typename _ValueType>
struct SharedArrayMap: public MapFacade<std::ptrdiff_t, _ValueType>
{
private:
	std::shared_ptr<_ValueType> sp;
public:
	SharedArrayMap(std::shared_ptr<_ValueType> sp):sp(sp){}
	SharedArrayMap() :sp(nullptr) {}

	SharedArrayMap(size_t n)
	:sp(new _ValueType[n], std::default_delete<_ValueType[]>())  { }

	auto operator[](ptrdiff_t d) const ->decltype(sp.get()[d])
	{
		return	sp.get()[d];
	}
};





template<typename Key>
struct IdentityMap:public MapFacade<Key, Key>
{
	const Key& operator[](const Key &key) const
	{
		return key;
	}
};

template<typename I>
class IteratorMap:public MapFacade<


typename std::iterator_traits<I>::difference_type
,
typename std::iterator_traits<I>::value_type



>
{
	I i;
public:
	IteratorMap() = default;
	IteratorMap(I i):i(i){}

	using Iterator = I;
	Iterator iterator() const { return i;}

	auto operator[](typename std::iterator_traits<I>::difference_type key) const ->decltype(i[key])
	{

		return i[key];
	}
};
template<typename I>
IteratorMap<I> makeIteratorMap(I i)
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
	explicit ComposeMap(const FM &fm,  const SM &sm):fm(fm), sm(sm) {}


	FirstMap firstMap() const { return fm; }
	SecondMap secondMap() const { return sm; }

	template<typename Key>
	auto operator[](Key && key) const ->decltype(sm[fm[key]])
	{
		return sm[fm[key]];
	}
};

template<typename FM, typename SM>
ComposeMap<FM, SM>
makeComposeMap(const FM &fm, const SM &sm)

{
	return ComposeMap<FM, SM>(fm, sm);
}

}





#endif 


#include <memory>



namespace lz {
	namespace GraphUtilityPrivate {
	}


struct DirectedGraphTag {};
struct UndirectedGraphTag {};













struct VertexIndexTag {};
struct EdgeIndexTag {};

struct EdgeWeightTag {};





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

	using OutEdgeIterator = typename G::OutEdgeIterator;

	using VertexProperties = typename G::VertexProperties;
	using EdgeProperties = typename G::EdgeProperties;

	template<typename Tag>
	using VertexPropertyMap = typename G::template VertexPropertyMap<Tag>;

	template<typename Tag>
	using EdgePropertyMap = typename G::template EdgePropertyMap<Tag>;

};







template<typename G, typename Tag>
class VertexPropertyMap
{



	using _ValueType = typename std::decay<decltype(typename GraphTraits<G>::VertexProperties()[Tag()])>::type;
	G *g = nullptr;
public:
	using KeyType = typename GraphTraits<G>::VertexDescriptor;
	using ValueType = _ValueType;

	VertexPropertyMap() = default;
	VertexPropertyMap(G &_g):g(&_g) { }
	auto operator[](KeyType u) const->decltype(g->vertexProperties(u)[Tag()])
	{
		return g->vertexProperties(u)[Tag()];
	}

	using Type = VertexPropertyMap<G, Tag>;

	struct ConstType
	{
		using KeyType = typename GraphTraits<G>::VertexDescriptor;
		using ValueType = _ValueType;
		const G *g;
		ConstType():g(nullptr){}
		ConstType(const G &g):g(&g){}
		auto operator[](KeyType u) const->decltype(g->vertexProperties(u)[Tag()])
		{
			return g->vertexProperties(u)[Tag()];
		}
	};
};


template<typename G, typename Tag>
class EdgePropertyMap
{


	using _ValueType = typename std::decay<decltype(typename GraphTraits<G>::EdgeProperties()[Tag()])>::type;
	G *g = nullptr;
public:
	using KeyType = typename GraphTraits<G>::EdgeDescriptor;
	using ValueType = _ValueType;

	EdgePropertyMap() = default;
	EdgePropertyMap(G &_g):g(&_g) { }
	ValueType operator[](KeyType u) const
	{
		return g->edgeProperties(u)[Tag()];
	}

	using Type = EdgePropertyMap<G, Tag>;

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
typename VertexPropertyMap<G, Tag>::Type
makeVertexPropertyMap(G &g, Tag)
{
	return typename VertexPropertyMap<G, Tag>::Type(g);
}

template<typename G, typename Tag>
typename VertexPropertyMap<G, Tag>::ConstType
makeVertexPropertyMap(const G &g, Tag tag)

{
	return typename VertexPropertyMap<G, Tag>::ConstType(g);
}

template<typename G, typename Tag>
auto makeEdgePropertyMap( G &g, Tag tag)
->decltype(typename EdgePropertyMap<G, Tag>::Type(g))
{
	return typename EdgePropertyMap<G, Tag>::Type(g);
}

template<typename G, typename Tag>
auto makeEdgePropertyMap(const G &g, Tag tag)
->decltype(typename EdgePropertyMap<G, Tag>::ConstType(g))
{
	return typename EdgePropertyMap<G, Tag>::ConstType(g);
}














































template<typename ValueType, typename VertexIndexMap, typename VertexNumberType>
auto
makeVertexIndexComposeMap(VertexIndexMap indexMap, VertexNumberType n)
->decltype(makeComposeMap(indexMap, SharedArrayMap<ValueType>(n)) )

{

	return makeComposeMap(indexMap, SharedArrayMap<ValueType>(n) );
}






















































































} 





#endif 



#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H


#include <vector>
#include <tuple>
#include <algorithm>
#ifndef PORPERTY_H
#define PORPERTY_H




#include <iostream>
#include <typeinfo>
#include <vector>

#include <type_traits>
#include <tuple>
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






    explicit Property(ValueType &&value, const NextProperty & np):
		NextProperty(np), m_value(value)
    {


    }

    Property(const ValueType &value): m_value(value){}
    Property(ValueType &&value): m_value(std::move(value)){}

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
    	cout << "SBSB" << endl;
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







#endif 






#ifndef LZ_ITERATOR_FACADE_H_
#define LZ_ITERATOR_FACADE_H_
#include <iterator>
#ifndef UTILITY_H
#define UTILITY_H

#include <functional>



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
struct LambdaOverloadSet : F1, F2
{
	LambdaOverloadSet(F1 f1, F2 f2)
		: F1(f1), F2(f2)
	{

	}

	using F1::operator();
	using F2::operator();
};

template <class F1, class F2>
LambdaOverloadSet<F1, F2> lambdaOverload(F1 f1, F2 f2)
{
	return LambdaOverloadSet<F1, F2>(f1, f2);
}










template<typename T>
int integerBitLength(T x)
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


#endif 


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




#endif 




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
class AdjacencyList;

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
    class OutEdgeIterator: public IteratorFacade<
		OutEdgeIterator<G>,
		std::forward_iterator_tag,
		typename GraphTraits<G>::EdgeDescriptor,
		std::ptrdiff_t,
		typename GraphTraits<G>::EdgeDescriptor*,
		typename GraphTraits<G>::EdgeDescriptor >
	{
    	template<typename D, typename VP, typename EP, typename GP>
    	friend class lz::AdjacencyList;



    	EdgeDescriptor i; 

    	const G *g;
    	OutEdgeIterator(EdgeDescriptor i, const G *g): i(i), g(g) {} 


	public:
    	OutEdgeIterator():i(-1), g(nullptr) {}

    	OutEdgeIterator& operator++()
		{
    		i = g->e[i].next;
    		return *this;
		}
    	typename OutEdgeIterator::reference operator*() const
    	{
    		return G::R2V(i);
    	}
    	bool operator==(OutEdgeIterator const& o) const
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
class VertexPropertyMap< AdjacencyList<D, VP, EP, GP>, VertexIndexTag>
	:public IdentityMap<typename GraphTraits< AdjacencyList<D, VP, EP, GP> >::VertexDescriptor>
{
public:
	VertexPropertyMap() = default;
	VertexPropertyMap(const AdjacencyList<D, VP, EP, GP> &_g){}

	using Type = VertexPropertyMap< AdjacencyList<D, VP, EP, GP>, VertexIndexTag>;
	using ConstType = Type;
};

template<typename D, typename VP, typename EP, typename GP>
class EdgePropertyMap<AdjacencyList<D, VP, EP, GP>, EdgeIndexTag>
	:public IdentityMap<typename GraphTraits<AdjacencyList<D, VP, EP, GP>>::EdgeDescriptor>
{
public:
	EdgePropertyMap() = default;
	EdgePropertyMap(const AdjacencyList<D, VP, EP, GP> &_g){}
	using Type = EdgePropertyMap;
	using ConstType = Type;
};




template<typename Direction, typename VP,
		 typename EP, typename GP>
class AdjacencyList: private AdjacencyListPrivate::DistinguishDirectionGraph<
					 Direction, VP, EP, GP>
{
	template<typename G> friend class AdjacencyListPrivate::OutEdgeIterator;

	using VertexData = AdjacencyListPrivate::VertexData<VP> ;
	using EdgeData = AdjacencyListPrivate::EdgeData<EP> ;
	using G = AdjacencyList;
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
	using OutEdgeIterator = AdjacencyListPrivate::OutEdgeIterator<G>;
	template<typename Tag>
	using VertexPropertyMap = lz::VertexPropertyMap<G, Tag>;
	template<typename Tag>
	using EdgePropertyMap = lz::EdgePropertyMap<G, Tag>;

	explicit AdjacencyList(SizeType n = 0, const VP & vp = VP())
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
	typename VertexPropertyMap<Tag>::Type
	vertexPropertyMap(Tag tag)
	{
		return makeVertexPropertyMap<G, Tag>(*this, tag);
	}

	template<typename Tag>
	typename VertexPropertyMap<Tag>::ConstType
	vertexPropertyMap(Tag tag) const
	{
		return makeVertexPropertyMap<G, Tag>(*this, tag);





	}



	template<typename Tag>
	typename EdgePropertyMap<Tag>::Type
	edgePropertyMap(Tag tag)

	{ return makeEdgePropertyMap<G, Tag>(*this, tag); }

	template<typename Tag>
	typename EdgePropertyMap<Tag>::ConstType
	edgePropertyMap(Tag tag) const
	{
		return makeEdgePropertyMap<G, Tag>(*this, tag);
	}


	pair<VertexIterator, VertexIterator> vertices() const
	{
		return make_pair(VertexIterator(0),
						 VertexIterator(this->vertexNumber()));
	}
	pair<EdgeIterator, EdgeIterator> edges() const
	{
		return make_pair(EdgeIterator(0), EdgeIterator(this->edgeNumber()));
	}
	pair<OutEdgeIterator, OutEdgeIterator> outEdges(VertexDescriptor u) const
	{
		return make_pair(OutEdgeIterator(this->v[u].head, this),
						 OutEdgeIterator(-1, this)) ;
	}

};







} 



#endif 





#ifndef LZ_PARAMETER_H_
#define LZ_PARAMETER_H_



#include <utility>

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












#define LZ_PARAMETER_KEYWORD(tag_namespace,name)                    \
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



#define LZ_PARAMETER_KEYWORD_TAG_NAMESPACE(name)   \
	LZ_PARAMETER_KEYWORD(tag, name)



}

















template<typename ParamPack, typename KeywordType, typename Default = ParamNotFound>
using ChooseParamType =	typename std::conditional<

	!std::is_same<typename Parameter::GetParamPack<ParamPack, KeywordType>::ParamPackType::Reference, ParamNotFound >::value,

	typename Parameter::GetParamPack<ParamPack, KeywordType>::ParamPackType::Reference,


	Default>::type;




} 



















#endif 
















#ifndef STRONG_COMPONENTS_H
#define STRONG_COMPONENTS_H

#include <utility>
#include <functional>




#ifndef DEPTH_FIRST_SEARCH_H
#define DEPTH_FIRST_SEARCH_H

#include <tuple>
#include <algorithm>
#include <vector>
#include <type_traits>
#include <iostream>
#include <memory>












namespace lz {

using std::tie;
using std::pair;


using std::vector;
using std::cout;
using std::endl;



namespace DepthFirstSearchKeywords {

	LZ_PARAMETER_KEYWORD(tag, initializeVertex)
	LZ_PARAMETER_KEYWORD(tag, startVertex)
	LZ_PARAMETER_KEYWORD(tag, discoverVertex)
	LZ_PARAMETER_KEYWORD(tag, examineEdge)
	LZ_PARAMETER_KEYWORD(tag, treeEdge)
	LZ_PARAMETER_KEYWORD(tag, treeEdgeReturn)
	LZ_PARAMETER_KEYWORD(tag, notTreeEdge)
	LZ_PARAMETER_KEYWORD(tag, finishEdge)
	LZ_PARAMETER_KEYWORD(tag, finishVertex)


	LZ_PARAMETER_KEYWORD(tag, colorMap)
	LZ_PARAMETER_KEYWORD(tag, white)
	LZ_PARAMETER_KEYWORD(tag, black)
	LZ_PARAMETER_KEYWORD(tag, vertexIndexMap)


	LZ_PARAMETER_KEYWORD(tag, isInit)
	LZ_PARAMETER_KEYWORD(tag, isTree)
	LZ_PARAMETER_KEYWORD(tag, outEdges)
	LZ_PARAMETER_KEYWORD(tag, enterVertex)
}



	namespace DepthFirstSearchPrivate {


	using namespace DepthFirstSearchKeywords;


	template<typename G, typename ParamPack>
	struct Impl
	{
		using Vertex = typename GraphTraits<G>::VertexDescriptor;
		using OutEdgeIterator = typename GraphTraits<G>::OutEdgeIterator;
		using Edge = typename GraphTraits<G>::EdgeDescriptor;
		using DirectedTag = typename GraphTraits<G>::DirectedCategory;

		const G &g;
		const ParamPack &p;


		Impl(const G &g, const ParamPack &p):g(g), p(p)
		{
			init(p[isInit], p[isTree]);


			chooseEnterVertex(p[enterVertex], p[isTree]);
		}


		void dfsNotRecursive(Vertex u)
		{
			std::vector<std::pair<Vertex, OutEdgeIterator > > stack;

			stack.push_back(std::make_pair(u,  p[outEdges](g, u).first)   );


			while(!stack.empty())
			{
				auto u = stack.back().first;
				auto& ei = stack.back().second;

				p[discoverVertex](u);
				for(;ei != p[outEdges](g, u).second; ++ ei)
				{
					auto e = *ei;
					auto to = opposite(g, e, u);
					p[examineEdge](e, u);
					if(p[colorMap][to] == p[white]())
					{
						p[treeEdge](e, u);
						p[colorMap][to] = p[black]();
						stack.push_back(std::make_pair(to, p[outEdges](g, to).first));
						break;
					}
					else
					{
						p[notTreeEdge](e, u);
					}
				}
				if(ei == p[outEdges](g, u).second)
				{
					stack.pop_back();
					if(!stack.empty())
					{
						p[treeEdgeReturn](*stack.back().second, stack.back().first);
						++stack.back().second;
					}
				}

			}

		}






		void dfs(Vertex u)
		{
			p[colorMap][u] = p[black]();
			p[discoverVertex](u);
			auto ei_pair = p[outEdges](g, u);
			for(auto ei = ei_pair.first; ei != ei_pair.second; ++ ei)
			{
				auto e = *ei;
				auto to = opposite(g, e, u);
				p[examineEdge](e, u);
				if(p[colorMap][to] == p[white]())
				{
					p[treeEdge](e, u);
					dfs(to);
					p[treeEdgeReturn](e, u);
				}
				else
				{
					p[notTreeEdge](e, u);
				}
				p[finishEdge](e, u);
			}
			p[finishVertex](u);
		}
		void dfsPolytree(Vertex u)
		{
			p[discoverVertex](u);
			for(auto ei = p[outEdges](g, u); ei.first != ei.second; ++ ei.first)
			{
				auto e = *ei.first;
				auto to = g.target(e);
				p[examineEdge](e, u);
				p[treeEdge](e, u);
				dfsPolytree(to);
				p[treeEdgeReturn](e, u);
				p[finishEdge](e, u);
			}
			p[finishVertex](u);
		}

		void dfsTree(Vertex u, Vertex fa)
		{
			p[discoverVertex](u);
			for(auto ei = p[outEdges](g, u); ei.first != ei.second; ++ ei.first)
			{
				auto e = *ei.first;
				auto to = lz::opposite(g, e, u);
				p[examineEdge](e, u);
				if(to != fa)
				{
					p[treeEdge](e, u);
					dfsTree(to, u);
					p[treeEdgeReturn](e, u);
				}
				else
				{
					p[notTreeEdge](e, u);
				}
				p[finishEdge](e, u);
			}
			p[finishVertex](u);
		}

		template<typename IsInit, typename IsTree>
		void init(IsInit, IsTree) {}


		void init(std::true_type, std::false_type)
		{
			for(auto vi = g.vertices(); vi.first != vi.second; ++vi.first)
			{
				auto u = *vi.first;
				p[colorMap][u] = p[white]();
				p[initializeVertex](u);
			}
		}

		void init(std::true_type, std::true_type)
		{
			for(auto vi = g.vertices(); vi.first != vi.second; ++vi.first)
			{
				auto u = *vi.first;
				p[initializeVertex](u);
			}
		}





		template<typename EnterVertex, typename is>
		void chooseEnterVertex(EnterVertex u, is)
		{
			p[startVertex](u);
			dfsDispatch(u, DirectedTag(), p[isTree]);
		}
		void chooseEnterVertex(ParamNotFound, std::false_type )
		{
			for(auto vi = g.vertices();vi.first != vi.second; ++vi.first)
			{
				auto u = *vi.first;
				if(p[colorMap][u] == p[white]())
				{
					p[startVertex](u);
					dfsDispatch(u, DirectedTag(), p[isTree]);
				}
			}
		}

		void chooseEnterVertex(ParamNotFound, std::true_type )
		{
			auto u = *g.vertices().first;
			p[startVertex](u);
			dfsDispatch(u, DirectedTag(), p[isTree]);
		}





		template<typename EnterVertex , typename Directed>
		void dfsDispatch(EnterVertex u, Directed, std::false_type )
		{


			dfs(u);
		}

		template<typename EnterVertex>
		void dfsDispatch(EnterVertex u, DirectedGraphTag, std::true_type)
		{
			dfsPolytree(u);
		}

		template<typename EnterVertex>
		void dfsDispatch(EnterVertex u, UndirectedGraphTag, std::true_type)
		{
			dfsTree(u, u);
		}



	};




	template<typename G, typename ParamPack>
	void dispatch(const G &g, const ParamPack &p , std::false_type )
	{


		auto _white = p[white | ColorTraits<>::white];
		auto _black = p[black | ColorTraits<>::black];
		auto _vertexIndexMap = p[vertexIndexMap | g.vertexPropertyMap(VertexIndexTag())];
		auto n = g.vertexNumber();
		auto indexMap = p[vertexIndexMap | g.vertexPropertyMap(VertexIndexTag())];
		auto _colorMap = p[colorMap ||
						   std::bind(makeVertexIndexComposeMap<decltype(_white()), decltype(indexMap), decltype(n) >,
								   indexMap, n)];

		auto _enterVertex = p[enterVertex];
		auto _isInit = p[isInit | std::true_type()];
		auto _outEdges = p[outEdges | std::mem_fn(&G::outEdges)];
		auto _isTree = std::false_type();


		using V = typename GraphTraits<G>::VertexDescriptor;
		using E = typename GraphTraits<G>::EdgeDescriptor;

		auto actionVertex = [](V u){};
		auto actionEdge = [](E e, V u){};

		auto newParamPack = (
				initializeVertex = p[initializeVertex | actionVertex],
				startVertex = p[startVertex | actionVertex],
				discoverVertex = p[discoverVertex | actionVertex],
				examineEdge = p[examineEdge | actionEdge],
				treeEdge = p[treeEdge | actionEdge],
				treeEdgeReturn = p[treeEdgeReturn | actionEdge],
				notTreeEdge = p[notTreeEdge | actionEdge],
				finishEdge = p[finishEdge | actionEdge],
				finishVertex = p[finishVertex | actionVertex],



				white = _white,
				black = _black,
				colorMap = _colorMap,

				isTree = _isTree,
				outEdges = _outEdges,
				isInit = _isInit,
				enterVertex =  _enterVertex);




		DepthFirstSearchPrivate::Impl <G, decltype(newParamPack)>

		impl(g, newParamPack);


	}

	

	template<typename G, typename ParamPack>
	void dispatch(const G &g, const ParamPack &p, std::true_type )
	{
		auto _enterVertex = p[enterVertex];
		auto _isInit = p[isInit | std::true_type()];
		auto _outEdges = p[outEdges | std::mem_fn(&G::outEdges)];
		auto _isTree = std::true_type();

		using V = typename GraphTraits<G>::VertexDescriptor;
		using E = typename GraphTraits<G>::EdgeDescriptor;

		auto actionVertex = [](V u) {};
		auto actionEdge = [](E e, V u) {};

		auto newParamPack = (
				initializeVertex = p[initializeVertex | actionVertex],
				startVertex = p[startVertex | actionVertex],
				discoverVertex = p[discoverVertex | actionVertex],
				examineEdge = p[examineEdge | actionEdge],
				treeEdge = p[treeEdge | actionEdge],
				treeEdgeReturn = p[treeEdgeReturn | actionEdge],
				notTreeEdge = p[notTreeEdge | actionEdge],
				finishEdge = p[finishEdge | actionEdge],
				finishVertex = p[finishVertex | actionVertex],

				isTree = _isTree,
				outEdges = _outEdges,
				isInit = _isInit,
				enterVertex =  _enterVertex);

		DepthFirstSearchPrivate::Impl <G, decltype(newParamPack)>
		impl(g, newParamPack);


	}



	}


template<typename G, typename ParamPack>
void depthFirstSearch(const G &g, const ParamPack &p)
{
	DepthFirstSearchPrivate::dispatch(g, p,
			p[DepthFirstSearchKeywords::isTree | std::false_type()] );
}































} 

#endif 







namespace lz {

using std::swap;
using std::less;

namespace StronglyConnectedComponentsKeywords {

	LZ_PARAMETER_KEYWORD(tag, vertexIndexMap)
	LZ_PARAMETER_KEYWORD(tag, discoverTimeMap)
	LZ_PARAMETER_KEYWORD(tag, rootMap)
}


    namespace StronglyConnectedComponentsPrivate {




    }








    template<typename G, typename ComponentMap, typename ParamPack = lz::EmptyParamPack>

    typename MapTraits<ComponentMap>::ValueType
	stronglyConnectedComponents(const G &g, ComponentMap compMap, const ParamPack &p = lz::EmptyParamPack() )
    {
		static_assert(std::is_same<typename GraphTraits<G>::DirectedCategory, DirectedGraphTag>::value, "this graph is not directed");

		namespace k = StronglyConnectedComponentsKeywords;

		auto indexMap = p[k::vertexIndexMap | g.vertexPropertyMap(VertexIndexTag())];

		using Vertex = typename GraphTraits<G>::VertexDescriptor;
		using Edge = typename GraphTraits<G>::EdgeDescriptor;


		auto n = g.vertexNumber();

		auto discoverTimeMap =
				p[k::discoverTimeMap ||
				 std::bind(makeVertexIndexComposeMap<size_t, decltype(indexMap), decltype(n) >,
						   indexMap, n) ];

		auto rootMap =  p[k::rootMap ||
						  std::bind(makeVertexIndexComposeMap<Vertex, decltype(indexMap), decltype(n) >,
						  		    indexMap, n)];

		using ComponentType = typename MapTraits<ComponentMap>::ValueType;
		using TimeType = typename MapTraits<decltype(discoverTimeMap)>::ValueType;

		using namespace DepthFirstSearchKeywords;

		ComponentType compNumber = 0;
		TimeType dfsTime = 0;

		std::vector<Vertex> stack;
		std::vector<bool>inStack(n, 0);


		auto minRoot = [&](Vertex u, Vertex v) ->Vertex
		{
			auto ans =  discoverTimeMap[u] < discoverTimeMap[v] ? u : v;
			return ans;
		};


		depthFirstSearch(g, (

				colorMap = discoverTimeMap,
				white = []()->TimeType { return 0; },
				black = [&]()->TimeType { return ++dfsTime; }
				,

				discoverVertex = [&](Vertex u)
				{
					rootMap[u] = u;
					stack.push_back(u);
					inStack[u] = 1;
				},

				treeEdgeReturn = [&](Edge e, Vertex u)
				{
					Vertex to = opposite(g, e, u);
					rootMap[u] = minRoot(rootMap[u], rootMap[to]);
				},

				notTreeEdge = [&](Edge e, Vertex u)
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





#endif 



























using namespace std;
using namespace lz;


using G = AdjacencyList<>;



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
	int ans = stronglyConnectedComponents(g, makeIteratorMap(compMap.begin()));









	if(ans == 1) puts("YES");
	else puts("NO");




	return 0;





}
