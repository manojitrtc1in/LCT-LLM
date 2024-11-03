










































































#define __STDC_FORMAT_MACROS
#include<inttypes.h>








#define _CAT(a,b) a##b
#define CAT(a,b) _CAT(a,b)
#define _10TH(a,b,c,d,e,f,g,h,i,CNT,...) CNT
#define VA_CNT(...) _10TH(__VA_ARGS__,9,8,7,6,5,4,3,2,1)
#define VA_SEL(a,...) CAT(a,VA_CNT(__VA_ARGS__))(__VA_ARGS__)

#define _VA_GTONE(...) _10TH(__VA_ARGS__,1,1,1,1,1,1,1,1,0)
#define VA_GTONE(a,...) CAT(a,_VA_GTONE(__VA_ARGS__))(__VA_ARGS__)

#define foreach(e,c) for(__typeof((c).begin())e=(c).begin();e!=(c).end();++e)


#define MIN_GCC(a,b,c) (__GNUC__ > (a) || \
              (__GNUC__ == (a) && (__GNUC_MINOR__ > (b) || \
                                 (__GNUC_MINOR__ == (b) && \
								 __GNUC_PATCHLEVEL__ >= (c)))))



								  
								  





#define bac back()
#define fro front()
#define emp empty()
#define fi first
#define se second
#define siz size()
#define ins insert
#define era erase
#define mp make_pair
#define be begin()
#define en end()
#define rbe rbegin()
#define ren rend()
#define sz size()
#define pub push_back
#define puf push_front
#define pob pop_back()
#define pof pop_front()
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define pq priority_queue
#define si (int)



#define F(i,n) for(int i=0; i<(int)(n); ++i)
#define FO(i,a,b) for(int i=(a); i<(int)(b); ++i)
#define OF(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);--i)
#define FE(it,c)  for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define FER(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); )
#define ALL(c) (c).begin(),(c).end()
#define ZERO(c) memset(c,0,sizeof(c))








#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<stdint.h>
#include<cstring>
#include<iostream>
#include<set>
#include<climits>
#include<bitset>
#include<limits>
#include<sstream>






#ifdef DEBUG
	#undef NDEBUG
	#pragma message "Compiling in DEBUG mode."
#else
	#define NDEBUG
#endif

#include <cstdio>
#include <cfloat>



#define  LOG0(str) 			fprintf(stderr,"%s:%d - " str "\n",__FILE__,__LINE__)
#define  LOG1(str,...)		fprintf(stderr,"%s:%d - " str "\n",__FILE__,__LINE__,__VA_ARGS__)

#define LOG(...) VA_GTONE(LOG,__VA_ARGS__)


#ifdef NDEBUG
	#define DE if(0)
#else
	#define DE
#endif


#if defined NDEBUG and not defined ASSERTS
	#define ASS(x)
	#define FLOAT_OK(x)
	#define ASSERT_FLOAT(x)
#else
	#include<cassert>
	#define ASS(x) assert(x)
	#define FLOAT_OK(x) ((x) <= LDBL_MAX && (x) >= -LDBL_MAX)
	#define ASSERT_FLOAT(f) ASS(FLOAT_OK(f))
#endif

#define DV(x) (E<#x<": "<(x)<N)
#define XX L("XX");


#if defined DEBUG or defined COLOR_CONSOLE
	#ifdef _WIN32
		#include<windows.h>
		int ecolor = 12;
		int ocolor = 10;
		inline void ec(int a){static HANDLE h=GetStdHandle(-12);SetConsoleTextAttribute(h,a?ecolor:0xf);}
		inline void oc(int a){static HANDLE h=GetStdHandle(-11);SetConsoleTextAttribute(h,a?ocolor:0xf);}
	#else
		

	#endif
#else
	#define ec(x)
	#define oc(x)
#endif

struct _E{template<class T>_E&operator<(const T&_t){DE{ec(1);std::cerr<<_t;ec(0);}return*this;}}E;







#include<stdint.h>

#include<utility>




typedef unsigned int uint;


namespace ab{

typedef int8_t i8;
typedef uint8_t ui8;
typedef int16_t i16;
typedef uint16_t ui16;
typedef int32_t i32;
typedef uint32_t ui32;
typedef int64_t i64;
typedef uint64_t ui64;



typedef i64 ll;
typedef ui64 ull;

typedef std::pair<i32,i32> pii;
typedef std::pair<double,double> pdd;
typedef std::vector<i32> vi;
#define VE std::vector
#define umap unordered_map
#define umultimap unordered_multimap

typedef unsigned short ushort;
typedef unsigned char uchar;

struct Void {};


template<typename I>struct FloatFrom{typedef Void R;};
template<>struct FloatFrom<i32>{typedef double R;};
template<>struct FloatFrom<ui32>{typedef double R;};
template<>struct FloatFrom<i64>{typedef long double R;};
template<>struct FloatFrom<ui64>{typedef long double R;};
template<>struct FloatFrom<i16>{typedef float R;};
template<>struct FloatFrom<ui16>{typedef float R;};
template<>struct FloatFrom<i8>{typedef float R;};
template<>struct FloatFrom<ui8>{typedef float R;};
template<>struct FloatFrom<float>{typedef float R;};
template<>struct FloatFrom<double>{typedef double R;};
template<>struct FloatFrom<long double>{typedef long double R;};

template<typename I>struct Double{typedef Void R;};
template<>struct Double<i8>{typedef i16 R;};
template<>struct Double<ui8>{typedef ui16 R;};
template<>struct Double<i16>{typedef i32 R;};
template<>struct Double<ui16>{typedef ui32 R;};
template<>struct Double<i32>{typedef i64 R;};
template<>struct Double<ui32>{typedef ui64 R;};

template<>struct Double<float>{typedef float R;};
template<>struct Double<double>{typedef double R;};
template<>struct Double<long double>{typedef long double R;};


#if defined __GNUC__ and ( __WORDSIZE == 64 )
typedef __int128_t i128;
typedef __uint128_t ui128;
template<>struct Double<i64>{typedef i128 R;};
template<>struct Double<ui64>{typedef ui128 R;};
#endif


}



#include<cstdlib>






namespace ab
{

	
	
	
	
	
	
	
	

}









namespace ab
{


template<bool cond, typename T, typename F> struct IF {typedef T R;};
template<typename T, typename F> struct IF<false,T,F> {typedef F R;};

template <bool B, class T = void> struct ENABLE_IF {typedef T R;};
template <class T> struct ENABLE_IF<false, T> {};

template <bool B, class T = void> struct DISABLE_IF {typedef T R;};
template <class T> struct DISABLE_IF<true, T> {};



template<class A, class B> struct SAME{ static const bool r = false;};
template<typename T> struct SAME<T,T>{	static const bool r = true;};


template<typename T>
struct IS_CLASS{
	template<typename C> static char (&f(int C::*))[1];
	template<typename C> static char (&f(...))[2];

	static bool const r = sizeof(f<T>(0))==sizeof(char);
};






template<class T> struct RR{typedef T R;};
template<class T> struct RR<T&>{typedef T R;};



template<class T> struct RC{typedef T R;};
template<class T> struct RC<const T>{typedef T R;};



template<class T> struct RRC{typedef typename RC<typename RR<T>::R>::R R;};


#define TYPE(T,...) typename T<__VA_ARGS__>::R





struct TRU{static const bool r = true;  typedef TRU R;};
struct FAL{static const bool r = false; typedef FAL R;};





#define HAS_MEMBER(member_alias, member)																									\
template<typename __T> struct HAS_CLASS_##member_alias {																											\
    struct Fallback { void member(); };																											\
    struct Derived : __T, Fallback { };																											\
																											\
    template<typename C, C> struct ChT;																											\
																											\
    template<typename C> static char (&f(ChT<void (Fallback::*)(), &C::member>*))[1];													\
    template<typename C> static char (&f(...))[2];																								\
																											\
    static const bool r = sizeof(f<Derived>(0)) == 2;																						\
};																										\
template<typename __T>																											\
struct HAS_##member_alias																											\
{																											\
	typedef typename IF<IS_CLASS<__T>::r, HAS_CLASS_##member_alias<__T>, FAL>::R R;														\
	static const bool r = R::r;																									\
};
















#define HAS_MEMBER_SIG(member_name, member_signature)																			\
template<typename CLS>																							\
struct HAS_SIG_##member_name																															\
{																									\
    template<typename C, C> struct ChT;																													\
	template<typename C> static char (&f(ChT<member_signature, &C::member_name>*))[1];																\
	template<typename C> static char (&f(...))[2];																									\
	static const bool r = sizeof(f<CLS>(0)) == sizeof(char);																							\
};




HAS_MEMBER(OPERATOR_CALL, operator());










}


namespace ab{

struct Lambda1{
	template<class A1>
	const A1& operator()(const A1& a1)const{return a1;}
	template<class A1>
	      A1& operator()(      A1& a1)const{return a1;}
	
	template<class A1,class A2>
	const A1& operator()(const A1& a1, const A2&)const{return a1;}
	template<class A1,class A2>
	      A1& operator()(      A1& a1, const A2&)const{return a1;}
	
	template<class A1,class A2,class A3>
	const A1& operator()(const A1& a1, const A2&, const A3&)const{return a1;}
	template<class A1,class A2,class A3>
	      A1& operator()(      A1& a1, const A2&, const A3&)const{return a1;}
};
static Lambda1 _1;




struct Lambda2{
	template<class A1,class A2>
	const A2& operator()(const A1& a1, const A2& a2)const{return a2;}
	template<class A1,class A2>
	      A2& operator()(const A1& a1,       A2& a2)const{return a2;}
	
	template<class A1,class A2,class A3>
	const A2& operator()(const A1& a1, const A2& a2, const A3& a3)const{return a2;}
	template<class A1,class A2,class A3>
	      A2& operator()(const A1& a1,       A2& a2, const A3& a3)const{return a2;}
};
static Lambda2 _2;




struct Lambda3{
	template<class A1,class A2,class A3>
	const A3& operator()(const A1& a1, const A2& a2, const A3& a3)const{return a3;}
	template<class A1,class A2,class A3>
	      A3& operator()(const A1& a1, const A2& a2,       A3& a3)const{return a3;}
};
static Lambda3 _3;









template<class L, class A1, class A2, class A3> struct RET_TYPE3{typedef L& R;};

template<class L, class A1> struct RET_TYPE1{typedef typename RET_TYPE3<L,A1,A1,A1>::R R;};
template<class L, class A1, class A2> struct RET_TYPE2{typedef typename RET_TYPE3<L,A1,A2,A2>::R R;};








template<class L> struct IS_LAMBDA{static const bool r = false;};







template<class L, class A1, class A2, class A3> struct IS_LAMBDA3{
static const bool r = !SAME<L&, typename RET_TYPE3<L,A1,A2,A3>::R&>::r;};

template<class L, class A1, class A2> struct IS_LAMBDA2{
static const bool r = !SAME<typename RR<L>::R, typename RR<typename RET_TYPE2<L,A1,A2>::R>::R>::r;};

template<class L, class A1> struct IS_LAMBDA1{
static const bool r = !SAME<typename RR<L>::R, typename RR<typename RET_TYPE1<L,A1>::R>::R>::r;};




template<class T, class A1>
typename ENABLE_IF  < IS_LAMBDA1<T,A1>::r,      typename RET_TYPE1<T,const A1>::R>::R Eval(const T& t, const A1& a1){return t(a1);}
template<class T, class A1>
typename ENABLE_IF  < IS_LAMBDA1<T,A1>::r,      typename RET_TYPE1<T,      A1>::R>::R Eval(const T& t,       A1& a1){return t(a1);}

template<class T, class A1>
typename DISABLE_IF < IS_LAMBDA1<T,A1>::r,      typename RET_TYPE1<T,A1>::R&>::R Eval(      T& t, const A1& a1){return t;}




template<class T, class A1, class A2>
typename ENABLE_IF < IS_LAMBDA2<T,A1,A2>::r,      typename RET_TYPE2<T,const A1,const A2>::R>::R Eval(const T& t, const A1& a1, const A2& a2){return t(a1,a2);}
template<class T, class A1, class A2>
typename ENABLE_IF < IS_LAMBDA2<T,A1,A2>::r,      typename RET_TYPE2<T,const A1,      A2>::R>::R Eval(const T& t, const A1& a1,       A2& a2){return t(a1,a2);}
template<class T, class A1, class A2>
typename ENABLE_IF < IS_LAMBDA2<T,A1,A2>::r,      typename RET_TYPE2<T,      A1,const A2>::R>::R Eval(const T& t,       A1& a1, const A2& a2){return t(a1,a2);}
template<class T, class A1, class A2>
typename ENABLE_IF < IS_LAMBDA2<T,A1,A2>::r,      typename RET_TYPE2<T,      A1,      A2>::R>::R Eval(const T& t,       A1& a1,       A2& a2){return t(a1,a2);}

template<class T, class A1, class A2>
typename DISABLE_IF< IS_LAMBDA2<T,A1,A2>::r,      typename RET_TYPE2<T,A1,A2>::R&>::R Eval(      T& t, const A1& a1, const A2& a2){return t;}




template<class T, class A1, class A2, class A3>
typename ENABLE_IF  < IS_LAMBDA3<T,A1,A2,A3>::r,      typename RET_TYPE3<T,const A1,const A2,const A3>::R>::R Eval(const T& t, const A1& a1, const A2& a2, const A3& a3){return t(a1,a2,a3);}
template<class T, class A1, class A2, class A3>
typename ENABLE_IF  < IS_LAMBDA3<T,A1,A2,A3>::r,      typename RET_TYPE3<T,const A1,const A2,      A3>::R>::R Eval(const T& t, const A1& a1, const A2& a2,       A3& a3){return t(a1,a2,a3);}
template<class T, class A1, class A2, class A3>
typename ENABLE_IF  < IS_LAMBDA3<T,A1,A2,A3>::r,      typename RET_TYPE3<T,const A1,      A2,const A3>::R>::R Eval(const T& t, const A1& a1,       A2& a2, const A3& a3){return t(a1,a2,a3);}
template<class T, class A1, class A2, class A3>
typename ENABLE_IF  < IS_LAMBDA3<T,A1,A2,A3>::r,      typename RET_TYPE3<T,const A1,      A2,      A3>::R>::R Eval(const T& t, const A1& a1,       A2& a2,       A3& a3){return t(a1,a2,a3);}
template<class T, class A1, class A2, class A3>
typename ENABLE_IF  < IS_LAMBDA3<T,A1,A2,A3>::r,      typename RET_TYPE3<T,      A1,const A2,const A3>::R>::R Eval(const T& t,       A1& a1, const A2& a2, const A3& a3){return t(a1,a2,a3);}
template<class T, class A1, class A2, class A3>
typename ENABLE_IF  < IS_LAMBDA3<T,A1,A2,A3>::r,      typename RET_TYPE3<T,      A1,const A2,      A3>::R>::R Eval(const T& t,       A1& a1, const A2& a2,       A3& a3){return t(a1,a2,a3);}
template<class T, class A1, class A2, class A3>
typename ENABLE_IF  < IS_LAMBDA3<T,A1,A2,A3>::r,      typename RET_TYPE3<T,      A1,      A2,const A3>::R>::R Eval(const T& t,       A1& a1,       A2& a2, const A3& a3){return t(a1,a2,a3);}
template<class T, class A1, class A2, class A3>
typename ENABLE_IF  < IS_LAMBDA3<T,A1,A2,A3>::r,      typename RET_TYPE3<T,      A1,      A2,      A3>::R>::R Eval(const T& t,       A1& a1,       A2& a2,       A3& a3){return t(a1,a2,a3);}

template<class T, class A1, class A2, class A3>
typename DISABLE_IF < IS_LAMBDA3<T,A1,A2,A3>::r,      typename RET_TYPE3<T,A1,A2,A3>::R&>::R Eval(      T& t, const A1& a1, const A2& a2, const A3& a3){return t;}







template<class L1, class L2>
class LambdaPlus{
public:
	LambdaPlus(const L1& _l1, const L2& _l2) : l1(_l1), l2(_l2){}
	
	template<class A1>
	typename RET_TYPE1<LambdaPlus,A1>::R operator()(const A1& a1)const{
		return Eval(l1,a1) + Eval(l2,a1);
	}
	
	template<class A1, class A2>
	typename RET_TYPE2<LambdaPlus,A1,A2>::R operator()(const A1& a1, const A2& a2)const{
		return Eval(l1,a1,a2) + Eval(l2,a1,a2);
	}
	
	template<class A1, class A2, class A3>
	typename RET_TYPE3<LambdaPlus,A1,A2,A3>::R operator()(const A1& a1, const A2& a2, const A3& a3)const{
		return Eval(l1,a1,a2,a3) + Eval(l2,a1,a2,a3);
	}
	
private:
	const L1& l1;
	const L2& l2;
};

template<class L1, class L2>
typename ENABLE_IF<HAS_OPERATOR_CALL<L1>::r or HAS_OPERATOR_CALL<L2>::r, LambdaPlus<L1,L2> >::R operator+(const L1& l1, const L2& l2){
	return LambdaPlus<L1,L2>(l1,l2);
}



template<class L1, class L2>
class LambdaMinus{
public:
	LambdaMinus(const L1& _l1, const L2& _l2) : l1(_l1), l2(_l2){}
	
	template<class A1>
	typename RET_TYPE1<LambdaMinus,A1>::R operator()(const A1& a1)const{
		return Eval(l1,a1) - Eval(l2,a1);
	}
	
	template<class A1, class A2>
	typename RET_TYPE2<LambdaMinus,A1,A2>::R operator()(const A1& a1, const A2& a2)const{
		return Eval(l1,a1,a2) - Eval(l2,a1,a2);
	}
	
	template<class A1, class A2, class A3>
	typename RET_TYPE3<LambdaMinus,A1,A2,A3>::R operator()(const A1& a1, const A2& a2, const A3& a3)const{
		return Eval(l1,a1,a2,a3) - Eval(l2,a1,a2,a3);
	}
	
private:
	const L1& l1;
	const L2& l2;
};

template<class L1, class L2>
typename ENABLE_IF<HAS_OPERATOR_CALL<L1>::r or HAS_OPERATOR_CALL<L2>::r, LambdaMinus<L1,L2> >::R operator-(const L1& l1, const L2& l2){
	return LambdaMinus<L1,L2>(l1,l2);
}






template<class L1>
class LambdaUnaryMinus{
public:
	LambdaUnaryMinus(const L1& _l1) : l1(_l1){}
	
	template<class A1>
	typename RET_TYPE1<LambdaUnaryMinus,A1>::R operator()(const A1& a1)const{
		return -Eval(l1,a1);
	}
	
	template<class A1, class A2>
	typename RET_TYPE2<LambdaUnaryMinus,A1,A2>::R operator()(const A1& a1, const A2& a2)const{
		return -Eval(l1,a1,a2);
	}
	
	template<class A1, class A2, class A3>
	typename RET_TYPE3<LambdaUnaryMinus,A1,A2,A3>::R operator()(const A1& a1, const A2& a2, const A3& a3)const{
		return -Eval(l1,a1,a2,a3);
	}
	
private:
	const L1& l1;
};

template<class L1>
typename ENABLE_IF<HAS_OPERATOR_CALL<L1>::r, LambdaUnaryMinus<L1> >::R operator-(const L1& l1){
	return LambdaUnaryMinus<L1>(l1);
}






template<class L1, class L2>
class LambdaMultiplies{
public:
	LambdaMultiplies(const L1& _l1, const L2& _l2) : l1(_l1), l2(_l2){}
	
	template<class A1>
	typename RET_TYPE1<LambdaMultiplies,A1>::R operator()(const A1& a1)const{
		return Eval(l1,a1) * Eval(l2,a1);
	}
	
	template<class A1, class A2>
	typename RET_TYPE2<LambdaMultiplies,A1,A2>::R operator()(const A1& a1, const A2& a2)const{
		return Eval(l1,a1,a2) * Eval(l2,a1,a2);
	}
	
	template<class A1, class A2, class A3>
	typename RET_TYPE3<LambdaMultiplies,A1,A2,A3>::R operator()(const A1& a1, const A2& a2, const A3& a3)const{
		return Eval(l1,a1,a2,a3) * Eval(l2,a1,a2,a3);
	}
	
private:
	const L1& l1;
	const L2& l2;
};

template<class L1, class L2>
typename ENABLE_IF<HAS_OPERATOR_CALL<L1>::r or HAS_OPERATOR_CALL<L2>::r, LambdaMultiplies<L1,L2> >::R operator*(const L1& l1, const L2& l2){
	return LambdaMultiplies<L1,L2>(l1,l2);
}




template<class L1, class L2>
class LambdaDivides{
public:
	LambdaDivides(const L1& _l1, const L2& _l2) : l1(_l1), l2(_l2){}
	
	template<class A1>
	typename RET_TYPE1<LambdaDivides,A1>::R operator()(const A1& a1)const{
		return Eval(l1,a1) / Eval(l2,a1);
	}
	
	template<class A1, class A2>
	typename RET_TYPE2<LambdaDivides,A1,A2>::R operator()(const A1& a1, const A2& a2)const{
		return Eval(l1,a1,a2) / Eval(l2,a1,a2);
	}
	
	template<class A1, class A2, class A3>
	typename RET_TYPE3<LambdaDivides,A1,A2,A3>::R operator()(const A1& a1, const A2& a2, const A3& a3)const{
		return Eval(l1,a1,a2,a3) / Eval(l2,a1,a2,a3);
	}
	
private:
	const L1& l1;
	const L2& l2;
};

template<class L1, class L2>
typename ENABLE_IF<HAS_OPERATOR_CALL<L1>::r or HAS_OPERATOR_CALL<L2>::r, LambdaDivides<L1,L2> >::R operator/(const L1& l1, const L2& l2){
	return LambdaDivides<L1,L2>(l1,l2);
}














template<class L1, class L2>
class LambdaPlusAssign{
public:
	LambdaPlusAssign(L1& _l1, const L2& _l2) : l1(_l1), l2(_l2){}
	
	template<class A1> typename RET_TYPE1<LambdaPlusAssign,A1>::R operator()(const A1& a1)const{return Eval(l1,a1) += Eval(l2,a1);}
	template<class A1> typename RET_TYPE1<LambdaPlusAssign,A1>::R operator()(      A1& a1)const{return Eval(l1,a1) += Eval(l2,a1);}
	
	template<class A1, class A2> typename RET_TYPE2<LambdaPlusAssign,const A1,const A2>::R operator()(const A1& a1, const A2& a2)const{return Eval(l1,a1,a2) += Eval(l2,a1,a2);}
	template<class A1, class A2> typename RET_TYPE2<LambdaPlusAssign,const A1,      A2>::R operator()(const A1& a1,       A2& a2)const{return Eval(l1,a1,a2) += Eval(l2,a1,a2);}
	template<class A1, class A2> typename RET_TYPE2<LambdaPlusAssign,      A1,const A2>::R operator()(      A1& a1, const A2& a2)const{return Eval(l1,a1,a2) += Eval(l2,a1,a2);}
	template<class A1, class A2> typename RET_TYPE2<LambdaPlusAssign,      A1,      A2>::R operator()(      A1& a1,       A2& a2)const{return Eval(l1,a1,a2) += Eval(l2,a1,a2);}
	
	template<class A1, class A2, class A3> typename RET_TYPE3<LambdaPlusAssign,A1,A2,A3>::R operator()(const A1& a1, const A2& a2, const A3& a3)const{return Eval(l1,a1,a2,a3) += Eval(l2,a1,a2,a3);}
	template<class A1, class A2, class A3> typename RET_TYPE3<LambdaPlusAssign,A1,A2,A3>::R operator()(const A1& a1, const A2& a2,       A3& a3)const{return Eval(l1,a1,a2,a3) += Eval(l2,a1,a2,a3);}
	template<class A1, class A2, class A3> typename RET_TYPE3<LambdaPlusAssign,A1,A2,A3>::R operator()(const A1& a1,       A2& a2, const A3& a3)const{return Eval(l1,a1,a2,a3) += Eval(l2,a1,a2,a3);}
	template<class A1, class A2, class A3> typename RET_TYPE3<LambdaPlusAssign,A1,A2,A3>::R operator()(const A1& a1,       A2& a2,       A3& a3)const{return Eval(l1,a1,a2,a3) += Eval(l2,a1,a2,a3);}
	template<class A1, class A2, class A3> typename RET_TYPE3<LambdaPlusAssign,A1,A2,A3>::R operator()(      A1& a1, const A2& a2, const A3& a3)const{return Eval(l1,a1,a2,a3) += Eval(l2,a1,a2,a3);}
	template<class A1, class A2, class A3> typename RET_TYPE3<LambdaPlusAssign,A1,A2,A3>::R operator()(      A1& a1, const A2& a2,       A3& a3)const{return Eval(l1,a1,a2,a3) += Eval(l2,a1,a2,a3);}
	template<class A1, class A2, class A3> typename RET_TYPE3<LambdaPlusAssign,A1,A2,A3>::R operator()(      A1& a1,       A2& a2, const A3& a3)const{return Eval(l1,a1,a2,a3) += Eval(l2,a1,a2,a3);}
	template<class A1, class A2, class A3> typename RET_TYPE3<LambdaPlusAssign,A1,A2,A3>::R operator()(      A1& a1,       A2& a2,       A3& a3)const{return Eval(l1,a1,a2,a3) += Eval(l2,a1,a2,a3);}
	
private:
	L1& l1;
	const L2& l2;
};


template<class L1, class L2>
typename ENABLE_IF<IS_LAMBDA<L1>::r or IS_LAMBDA<L2>::r, LambdaPlusAssign<L1,L2> >::R operator+=(L1& l1, const L2& l2){
	return LambdaPlusAssign<L1,L2>(l1,l2);
}










template<class L1, class L2>
class LambdaLess{
public:
	LambdaLess(const L1& _l1, const L2& _l2) : l1(_l1), l2(_l2){}
	
	template<class A1>
	typename RET_TYPE1<LambdaLess,A1>::R operator()(const A1& a1)const{
		return Eval(l1,a1) < Eval(l2,a1);
	}
	
	template<class A1, class A2>
	typename RET_TYPE2<LambdaLess,A1,A2>::R operator()(const A1& a1, const A2& a2)const{
		return Eval(l1,a1,a2) < Eval(l2,a1,a2);
	}
	
	template<class A1, class A2, class A3>
	typename RET_TYPE3<LambdaLess,A1,A2,A3>::R operator()(const A1& a1, const A2& a2, const A3& a3)const{
		return Eval(l1,a1,a2,a3) < Eval(l2,a1,a2,a3);
	}
	
private:
	const L1& l1;
	const L2& l2;
};
template<class L1, class L2>
typename ENABLE_IF<HAS_OPERATOR_CALL<L1>::r or HAS_OPERATOR_CALL<L2>::r, LambdaLess<L1,L2> >::R operator<(const L1& l1, const L2& l2){
	return LambdaLess<L1,L2>(l1,l2);
}





template<class L1, class L2>
class LambdaGreater{
public:
	LambdaGreater(const L1& _l1, const L2& _l2) : l1(_l1), l2(_l2){}
	
	template<class A1>
	typename RET_TYPE1<LambdaGreater,A1>::R operator()(const A1& a1)const{
		return Eval(l1,a1) > Eval(l2,a1);
	}
	
	template<class A1, class A2>
	typename RET_TYPE2<LambdaGreater,A1,A2>::R operator()(const A1& a1, const A2& a2)const{
		return Eval(l1,a1,a2) > Eval(l2,a1,a2);
	}
	
	template<class A1, class A2, class A3>
	typename RET_TYPE3<LambdaGreater,A1,A2,A3>::R operator()(const A1& a1, const A2& a2, const A3& a3)const{
		return Eval(l1,a1,a2,a3) > Eval(l2,a1,a2,a3);
	}
	
private:
	const L1& l1;
	const L2& l2;
};

template<class L1, class L2>
typename ENABLE_IF<HAS_OPERATOR_CALL<L1>::r or HAS_OPERATOR_CALL<L2>::r, LambdaGreater<L1,L2> >::R operator>(const L1& l1, const L2& l2){
	return LambdaGreater<L1,L2>(l1,l2);
}






template<class L1, class L2>
class LambdaDotStar{
public:
	LambdaDotStar(L1& _l1, const L2& _l2) : l1(_l1), l2(_l2) {}
	
	template<class A1> typename RET_TYPE1<LambdaDotStar,const A1>::R operator()(const A1& a1)const{return Eval(l1,a1).*Eval(l2,a1);}
	template<class A1> typename RET_TYPE1<LambdaDotStar,      A1>::R operator()(      A1& a1)const{return Eval(l1,a1).*Eval(l2,a1);}
	
	template<class A1, class A2> typename RET_TYPE2<LambdaDotStar,const A1,const A2>::R operator()(const A1& a1, const A2& a2)const{return Eval(l1,a1,a2).*Eval(l2,a1,a2);}
	template<class A1, class A2> typename RET_TYPE2<LambdaDotStar,const A1,      A2>::R operator()(const A1& a1,       A2& a2)const{return Eval(l1,a1,a2).*Eval(l2,a1,a2);}
	template<class A1, class A2> typename RET_TYPE2<LambdaDotStar,      A1,const A2>::R operator()(      A1& a1, const A2& a2)const{return Eval(l1,a1,a2).*Eval(l2,a1,a2);}
	template<class A1, class A2> typename RET_TYPE2<LambdaDotStar,      A1,      A2>::R operator()(      A1& a1,       A2& a2)const{return Eval(l1,a1,a2).*Eval(l2,a1,a2);}
	
	template<class A1, class A2, class A3> typename RET_TYPE3<LambdaDotStar,const A1,const A2,const A3>::R operator()(const A1& a1, const A2& a2, const A3& a3)const{return Eval(l1,a1,a2,a3).*Eval(l2,a1,a2,a3);}
	template<class A1, class A2, class A3> typename RET_TYPE3<LambdaDotStar,const A1,const A2,      A3>::R operator()(const A1& a1, const A2& a2,       A3& a3)const{return Eval(l1,a1,a2,a3).*Eval(l2,a1,a2,a3);}
	template<class A1, class A2, class A3> typename RET_TYPE3<LambdaDotStar,const A1,      A2,const A3>::R operator()(const A1& a1,       A2& a2, const A3& a3)const{return Eval(l1,a1,a2,a3).*Eval(l2,a1,a2,a3);}
	template<class A1, class A2, class A3> typename RET_TYPE3<LambdaDotStar,const A1,      A2,      A3>::R operator()(const A1& a1,       A2& a2,       A3& a3)const{return Eval(l1,a1,a2,a3).*Eval(l2,a1,a2,a3);}
	template<class A1, class A2, class A3> typename RET_TYPE3<LambdaDotStar,      A1,const A2,const A3>::R operator()(      A1& a1, const A2& a2, const A3& a3)const{return Eval(l1,a1,a2,a3).*Eval(l2,a1,a2,a3);}
	template<class A1, class A2, class A3> typename RET_TYPE3<LambdaDotStar,      A1,const A2,      A3>::R operator()(      A1& a1, const A2& a2,       A3& a3)const{return Eval(l1,a1,a2,a3).*Eval(l2,a1,a2,a3);}
	template<class A1, class A2, class A3> typename RET_TYPE3<LambdaDotStar,      A1,      A2,const A3>::R operator()(      A1& a1,       A2& a2, const A3& a3)const{return Eval(l1,a1,a2,a3).*Eval(l2,a1,a2,a3);}
	template<class A1, class A2, class A3> typename RET_TYPE3<LambdaDotStar,      A1,      A2,      A3>::R operator()(      A1& a1,       A2& a2,       A3& a3)const{return Eval(l1,a1,a2,a3).*Eval(l2,a1,a2,a3);}

private:
	L1& l1;
	const L2& l2;
};



template<class PTR, class T>
LambdaDotStar<const T,PTR> bv(const PTR& ptr, const T& t){
	return LambdaDotStar<const T,PTR>(t,ptr);
}
template<class PTR, class T>
LambdaDotStar<T,PTR> bv(const PTR& ptr, T& t){
	return LambdaDotStar<T,PTR>(t,ptr);
}










template<> struct IS_LAMBDA<Lambda1>{static const bool r = true;};
template<> struct IS_LAMBDA<Lambda2>{static const bool r = true;};
template<> struct IS_LAMBDA<Lambda3>{static const bool r = true;};
template<class A,class B> struct IS_LAMBDA<LambdaPlus<A,B> >{static const bool r = true;};
template<class A,class B> struct IS_LAMBDA<LambdaMinus<A,B> >{static const bool r = true;};
template<class A,class B> struct IS_LAMBDA<LambdaMultiplies<A,B> >{static const bool r = true;};
template<class A,class B> struct IS_LAMBDA<LambdaDivides<A,B> >{static const bool r = true;};
template<class A,class B> struct IS_LAMBDA<LambdaPlusAssign<A,B> >{static const bool r = true;};






















template<class A1, class A2, class A3> struct RET_TYPE3<Lambda1,A1,A2,A3>{typedef A1& R;};
template<class A1, class A2, class A3> struct RET_TYPE3<Lambda2,A1,A2,A3>{typedef A2& R;};
template<class A1, class A2, class A3> struct RET_TYPE3<Lambda3,A1,A2,A3>{typedef A3& R;};








template<class L1, class L2, class A1, class A2, class A3> struct RET_TYPE3<LambdaPlus<L1,L2>,A1,A2,A3>{
	typedef __typeof(TYPE(RRC,typename RET_TYPE3<L1,A1,A2,A3>::R)() + TYPE(RRC,typename RET_TYPE3<L2,A1,A2,A3>::R)()) R;
};

template<class L1, class L2, class A1, class A2, class A3> struct RET_TYPE3<LambdaMinus<L1,L2>,A1,A2,A3>{
	typedef __typeof(TYPE(RRC,typename RET_TYPE3<L1,A1,A2,A3>::R)() - TYPE(RRC,typename RET_TYPE3<L2,A1,A2,A3>::R)()) R;
};

template<class L1, class A1, class A2, class A3> struct RET_TYPE3<LambdaUnaryMinus<L1>,A1,A2,A3>{
	typedef __typeof(- TYPE(RRC,typename RET_TYPE3<L1,A1,A2,A3>::R)()) R;
};

template<class L1, class L2, class A1, class A2, class A3> struct RET_TYPE3<LambdaMultiplies<L1,L2>,A1,A2,A3>{
	typedef __typeof(*(typename RRC<typename RET_TYPE3<L1,A1,A2,A3>::R>::R*)NULL * *(typename RRC<typename RET_TYPE3<L2,A1,A2,A3>::R>::R*)NULL) R;
};

template<class L1, class L2, class A1, class A2, class A3> struct RET_TYPE3<LambdaDivides<L1,L2>,A1,A2,A3>{
	typedef __typeof(typename RRC<typename RET_TYPE3<L1,A1,A2,A3>::R>::R() / typename RRC<typename RET_TYPE3<L2,A1,A2,A3>::R>::R()) R;
};



template<class L1, class L2, class A1, class A2, class A3> struct RET_TYPE3<LambdaPlusAssign<L1,L2>,A1,A2,A3>{
	typedef __typeof(*(new typename RRC<typename RET_TYPE3<L1,A1,A2,A3>::R>::R) += *(new typename RRC<typename RET_TYPE3<L2,A1,A2,A3>::R>::R))& R;
};




template<class L1, class L2, class A1, class A2, class A3> struct RET_TYPE3<LambdaLess<L1,L2>,A1,A2,A3>{
	typedef __typeof(*(new typename RRC<typename RET_TYPE3<L1,A1,A2,A3>::R>::R) < *(new typename RRC<typename RET_TYPE3<L2,A1,A2,A3>::R>::R)) R;
};
template<class L1, class L2, class A1, class A2, class A3> struct RET_TYPE3<LambdaGreater<L1,L2>,A1,A2,A3>{
	typedef __typeof(*(new typename RRC<typename RET_TYPE3<L1,A1,A2,A3>::R>::R) > *(new typename RRC<typename RET_TYPE3<L2,A1,A2,A3>::R>::R)) R;
};



template<class L1, class L2, class A1, class A2, class A3> struct RET_TYPE3<LambdaDotStar<L1,L2>,A1,A2,A3>{
	typedef __typeof(*(new typename RRC<typename RET_TYPE3<L1,A1,A2,A3>::R>::R) .* *(new typename RRC<typename RET_TYPE3<L2,A1,A2,A3>::R>::R)) R;
};






template<class F, class L1>
class LambdaBinder1{
public:
	LambdaBinder1(const F& _f, const L1& _l1) : f(_f), l1(_l1) {}
	
	template<class A1>
	int operator()(const A1& a1){
		return f(Eval(l1,a1));
	}
	template<class A1, class A2>
	int operator()(const A1& a1, const A2& a2){
		return f(Eval(l1,a1,a2));
	}
	template<class A1, class A2, class A3>
	int operator()(const A1& a1, const A2& a2, const A3& a3){
		return f(Eval(l1,a1,a2,a3));
	}
	
private:
	const F& f;
	const L1& l1;
};

template<typename F, class L1>
LambdaBinder1<F,L1> bf(const F& f, const L1& l1){
	return LambdaBinder1<F,L1>(f,l1);
}



template<class F, class L1, class L2>
class LambdaBinder2{
public:
	LambdaBinder2(const F& _f, const L1& _l1, const L2& _l2) : f(_f), l1(_l1), l2(_l2) {}
	
	template<class A1>
	int operator()(const A1& a1){
		return f(Eval(l1,a1),Eval(l2,a1));
	}
	template<class A1, class A2>
	int operator()(const A1& a1, const A2& a2){
		return f(Eval(l1,a1,a2),Eval(l2,a1,a2));
	}
	template<class A1, class A2, class A3>
	int operator()(const A1& a1, const A2& a2, const A3& a3){
		return f(Eval(l1,a1,a2,a3),Eval(l2,a1,a2,a3));
	}
	
private:
	const F& f;
	const L1& l1;
	const L2& l2;
};

template<typename F, class L1, class L2>
LambdaBinder2<F,L1,L2> bf(const F& f, const L1& l1, const L2& l2){
	return LambdaBinder2<F,L1,L2>(f,l1,l2);
}



template<class F, class L1, class L2, class L3>
class LambdaBinder3{
public:
	LambdaBinder3(const F& _f, const L1& _l1, const L2& _l2, const L3& _l3) : f(_f), l1(_l1), l2(_l2), l3(_l3) {}
	
	template<class A1>
	int operator()(const A1& a1){
		return f(Eval(l1,a1),Eval(l2,a1),Eval(l3,a1));
	}
	template<class A1, class A2>
	int operator()(const A1& a1, const A2& a2){
		return f(Eval(l1,a1,a2),Eval(l2,a1,a2),Eval(l3,a1,a2));
	}
	template<class A1, class A2, class A3>
	int operator()(const A1& a1, const A2& a2, const A3& a3){
		return f(Eval(l1,a1,a2,a3),Eval(l2,a1,a2,a3),Eval(l3,a1,a2,a3));
	}
	
private:
	const F& f;
	const L1& l1;
	const L2& l2;
	const L3& l3;
};

template<typename F, class L1, class L2, class L3>
LambdaBinder3<F,L1,L2,L3> bf(const F& f, const L1& l1, const L2& l2, const L3& l3){
	return LambdaBinder3<F,L1,L2,L3>(f,l1,l2,l3);
}












}




namespace ab
{



template<typename T, typename IDX=int>
struct binomial
{
	binomial() : n(0), k(0), val(1) {}
	binomial(const IDX& nn, const IDX& kk) : n(nn), val(1){
		ASS(0<=kk);
		if(2*kk<nn){
			k = 0;
			while(k<kk)moveR();
		}
		else{
			k=nn;
			while(k>kk)moveL();
		}
	}
	IDX n,k;
	T val;
	
	operator T(){
		return val;
	}

	bool outside(){
		bool ret = n<0 || k<0 || k>n;
		if(ret)val=0;
		return ret;
	}

	void moveL(){
		--k;
		if(outside()) return;

		if(k==n) val=1;
		else
		{
			val*=(k+1);
			val/=(n-k);
		}
	}
	void moveR(){
		++k;
		if(outside()) return;

		if(k==0) val=1;
		else
		{
			val*=(n-k+1);
			val/=(k);
		}
	}
	void moveD(){
		++n;
		if(outside()) return;

		if(n==k) val=1;
		else
		{
			val*=n;
			val/=(n-k);
		}
	}
	void moveU(){
		--n;
		if(outside()) return;

		val*=(n-k+1);
		val/=(n+1);
	}
};





#define gcd __gcd





template<typename T>
T gcdExt(T a, T b, T& aaa, T& bbb)
{
	T a0 = a;
	T b0 = b;

	T aa = 0;
	T bb = 1;
	aaa = 1;
	bbb = 0;
	

	

	while(b != 0)
	{
		T q = a/b;
		a = a%b;
		

		aaa -= aa*q;
		bbb -= bb*q;
		swap(a,b);
		swap(aa,aaa);
		swap(bb,bbb);
	}

	ASS(a0*aaa + b0*bbb == a);

	return a;
}



template<class T, class E, class OP>
inline T fpow(T a, E exp, const OP& op, const T& neutral = 1){
	T r = neutral;
	while(exp){
		if(exp&1){
			r = op(r,a);
			--exp;
		}
		else{
			exp >>= 1;
			a = op(a,a);
		}
	}
	return r;
}

template<class T, class E>
inline T fpow(T a, E exp){
	return fpow(a, exp, _1 * _2);
}



template<class T> const T& max2(const T& a, const T& b){return a<b?b:a;}
template<class T> const T& min2(const T& a, const T& b){return b<a?b:a;}





}



namespace ab{
	
template<int mod1 = (1<<31)-1, int mod2 = (1<<31)-19>
struct H2{
	H2() : h1(0), h2(0) {}
	H2(int x) : h1(x%mod1), h2(x%mod2) {}
	ui32 h1,h2;
	H2& operator+=(const H2& o){
		h1 = (h1+o.h1)%mod1;
		h2 = (h2+o.h2)%mod2;
		return *this;
	}
	H2 operator+(const H2& o)const{
		return H2(*this)+=o;
	}
	H2& operator-=(const H2& o){
		h1 = (mod1+h1-o.h1)%mod1;
		h2 = (mod2+h2-o.h2)%mod2;
		return *this;
	}
	H2 operator-(const H2& o)const{
		return H2(*this)-=o;
	}
	H2& operator*=(const H2& o){
		h1 = (1ULL*h1*o.h1)%mod1;
		h2 = (1ULL*h2*o.h2)%mod2;
		return *this;
	}
	H2 operator*(const H2& o)const{
		return H2(*this)*=o;
	}
	
	bool operator==(const H2& o)const{
		return h1==o.h1 and h2==o.h2;
	}
	
	bool operator!=(const H2& o)const{
		return !operator==(o);
	}
};

template<int mod1 = (1<<31)-1>
struct H1{
	H1() : h1(0) {}
	H1(int x) : h1(x%mod1) {}
	ui32 h1;
	H1& operator+=(const H1& o){
		h1 = (h1+o.h1);
		if(h1>=mod1)h1-=mod1;
		return *this;
	}
	H1 operator+(const H1& o)const{
		return H1(*this)+=o;
	}
	H1& operator-=(const H1& o){
		h1 = (mod1+h1-o.h1);
		if(h1>=mod1)h1-=mod1;
		return *this;
	}
	H1 operator-(const H1& o)const{
		return H1(*this)-=o;
	}
	H1& operator*=(const H1& o){
		h1 = (1ULL*h1*o.h1)%mod1;
		return *this;
	}
	H1 operator*(const H1& o)const{
		return H1(*this)*=o;
	}
	H1& operator/=(const H1& o){
		

		return (*this)*=fpow(o, mod1-2, _1 * _2, H1(1));
	}
	H1 operator/(const H1& o)const{
		return H1(*this)/=o;
	}
	
	
	
	operator ui32()const{
		return h1;
	}
};



struct H1X{
	H1X(int mod) : mod1(mod), h1(0) {}
	H1X(int mod, int x) : mod1(mod), h1(x%mod1) {}
	

	H1X& operator=(const H1X& o){
		ASS(mod1==o.mod1);
		

		h1 = o.h1;
		return *this;
	}
	const int mod1;
	ui32 h1;
	H1X& operator+=(const H1X& o){
		ASS(mod1==o.mod1);
		h1 = (h1+o.h1)%mod1;
		return *this;
	}
	H1X operator+(const H1X& o)const{
		return H1X(*this)+=o;
	}
	H1X& operator-=(const H1X& o){
		ASS(mod1==o.mod1);
		h1 = (mod1+h1-o.h1)%mod1;
		return *this;
	}
	H1X operator-(const H1X& o)const{
		return H1X(*this)-=o;
	}
	H1X& operator*=(const H1X& o){
		ASS(mod1==o.mod1);
		h1 = (1ULL*h1*o.h1)%mod1;
		return *this;
	}
	H1X operator*(const H1X& o)const{
		return H1X(*this)*=o;
	}
	H1X& operator/=(const H1X& o){
		ASS(mod1==o.mod1);
		

		return (*this)*=fpow(o,mod1-2, (_1 * _2), H1X(mod1,1));
	}
	H1X operator/(const H1X& o)const{
		return H1X(*this)/=o;
	}
	
	
	
	operator ui32()const{
		return h1;
	}
};

}



#if __cplusplus >= 201103L
#include <unordered_map>
namespace std{
#else
#include <ext/hash_map>
namespace __gnu_cxx{
#endif

template<int h1, int h2> struct hash<ab::H2<h1,h2> >{
	size_t operator()(const ab::H2<h1,h2>& h)const{
		return h.h1^h.h2;
	}
};
template<int h1> struct hash<ab::H1<h1> >{
	size_t operator()(const ab::H1<h1>& h)const{
		return h.h1;
	}
};

}




#include<map>
#include<iostream>



#if __cplusplus >= 201103L
namespace std{
#else
#include <ext/hash_map>
namespace __gnu_cxx{
#define unordered_map hash_map
#define unordered_multimap hash_multimap

#endif



template<>template<class A,class B>struct hash<std::map<A,B> >{
    size_t operator()(const std::map<A,B>& m) const{
        size_t r = m.size();
        if(!r)return 0;
        __typeof(m.begin()) i=m.be;
        r^=hash<__typeof(i)>()(i);
        ++i;
        r^=cbitl(hash<__typeof(i)>()(*i),sizeof(r)*8/4);
        i=m.end();
        --i;
        r^=cbitl(hash<__typeof(i)>()(*i),sizeof(r)*8/2);
        return r;
    }
};
template<>template<class A, class B>struct hash<pair<A,B> >{
    size_t operator()(const pair<A,B>& p) const{
        return hash<A>()(p.first) ^ cbitl(hash<B>()(p.second),sizeof(size_t)*8/2);
    }
};
} 






template<class A, class B, class C, class D>
inline std::pair<A,B>& operator+=(std::pair<A,B>& p, const std::pair<C,D>& o){
	p.first+=o.first;
	p.second+=o.second;
	return p;
}
template<class A, class B, class C, class D>
inline std::pair<A,B>& operator-=(std::pair<A,B>& p, const std::pair<C,D>& o){
	p.first-=o.first;
	p.second-=o.second;
	return p;
}
template<class A, class B, class C, class D>
inline std::pair<A,B>& operator*=(std::pair<A,B>& p, const std::pair<C,D>& o){
	p.first*=o.first;
	p.second*=o.second;
	return p;
}
template<class A, class B, class C, class D>
inline std::pair<A,B>& operator/=(std::pair<A,B>& p, const std::pair<C,D>& o){
	p.first/=o.first;
	p.second/=o.second;
	return p;
}

template<class Afi, class Ase, class Bfi, class Bse>
inline std::pair<__typeof(Afi()+Bfi()),__typeof(Ase()+Bse())>&
operator+(const std::pair<Afi,Ase>& a, const std::pair<Bfi,Bse>& b){
	return std::make_pair(a.fi+b.fi, a.se+b.se);
}
template<class Afi, class Ase, class Bfi, class Bse>
inline std::pair<__typeof(Afi()-Bfi()),__typeof(Ase()-Bse())>&
operator-(const std::pair<Afi,Ase>& a, const std::pair<Bfi,Bse>& b){
	return std::make_pair(a.fi-b.fi, a.se-b.se);
}
template<class Afi, class Ase, class Bfi, class Bse>
inline std::pair<__typeof(Afi()*Bfi()),__typeof(Ase()*Bse())>&
operator*(const std::pair<Afi,Ase>& a, const std::pair<Bfi,Bse>& b){
	return std::make_pair(a.fi*b.fi, a.se*b.se);
}
template<class Afi, class Ase, class Bfi, class Bse>
inline std::pair<__typeof(Afi()/Bfi()),__typeof(Ase()/Bse())>&
operator/(const std::pair<Afi,Ase>& a, const std::pair<Bfi,Bse>& b){
	return std::make_pair(a.fi/b.fi, a.se/b.se);
}








template<class T, class U>
inline std::vector<T>& operator+=(std::vector<T>& v, const std::vector<U>& o){
	ASS(v.siz == o.siz);
	F(i,v.siz) v[i] += o[i];
	return v;
}


template<class T>
inline std::vector<T>& operator*=(std::vector<T>& v, const T& a){
	F(i,v.siz) v[i] *= a;
	return v;
}







template<class A,class B>inline std::ostream&operator<<(std::ostream&o,const std::pair<A,B>&p){o<<'<'<<p.first<<", "<<p.second<<'>';return o;}
template<class A,class B>inline std::ostream&operator<<(std::ostream&o,const std::map<A,B>&m){o<<'\n';FE(k,m)o<<"map["<<k->first<<"] -> "<<k->se<<'\n';return o;}
template<class A>inline std::ostream&operator<<(std::ostream&o,const std::vector<A>&_v){o<<'\n';F(i,_v.sz)o<<"vector["<<i<<"] = "<<_v[i]<<'\n';return o;}








namespace ab{






template<class T, class AGG_FUN>
class ITree{

private:
	std::vector<T> tree;
	uint tsize;
	AGG_FUN* aggFun;
	
public:
	ITree(const AGG_FUN& _fun) : tsize(1), aggFun(&_fun){
		tree.resize(tsize*2);
	}
	
	ITree(const ITree& o) : tree(o.tree), tsize(o.tsize), aggFun(o.aggFun){}
	ITree& operator=(const ITree& o){
		tree = o.tree;
		tsize = o.tsize;
		aggFun = o.aggFun;
		return *this;
	}
	
	void set(uint where, const T& what){
		check(where);
		
		where+=tsize;
		tree[where] = what;
		while(where!=1){
			where>>=1;
			tree[where] = (*aggFun)(tree[where*2],tree[where*2+1]);
		}
	}
	
	const T& get(uint where)const{
		if(where>=tsize) return T();
		return tree[tsize+where];
	}
	
	const T& operator[](uint where)const{
		return get(where);
	}
	
	T get(uint fr, uint to)const{
		ASS(fr<to);
		if(fr>=tsize)return T();
		if(to>tsize) to=tsize;
		
		fr += tsize;  to += tsize-1;
		T lresult = T();
		T rresult = T();
		while(fr<to){
			if((fr&1)==1) lresult = (*aggFun)(tree[fr],lresult), fr>>=1, ++fr;
			else fr>>=1;
			if((to&1)==0) rresult = (*aggFun)(rresult,tree[to]), to>>=1, --to;
			else to>>=1;
		}
		if(fr==to)lresult=(*aggFun)(lresult,tree[fr]);
		return (*aggFun)(lresult,rresult);
	}
	
	const T& root()const{
		return tree[1];
	}
	
private:
	void check(uint where){
		if(where<tsize)return;
		
		uint oldPos = tsize;
		uint moves = 0;
		while(where >= tsize) tsize <<= 1, ++moves;
		
		tree.resize(tsize*2);
		uint newPos = tsize;
		
		while(oldPos){
			for(uint i=0; i<oldPos; ++i){
				tree[newPos+i] = tree[oldPos+i];
				tree[oldPos+i] = T();
			}
			oldPos >>= 1;
			newPos >>= 1;
		}
		
		

		while(newPos>0){
			tree[newPos] = (*aggFun)(tree[newPos*2], tree[newPos*2+1]);
			newPos >>= 1;
		}
	}
	
};

template<class T, class AGG_FUN>
ITree<T,AGG_FUN> getITree(const AGG_FUN& aggFun = std::plus<T>()){
	return ITree<T,AGG_FUN>(aggFun);
}

































template<class T, class MOD, class AGG_FUN, class MOD_FUN>
class ITreeMod{
public:
	ITreeMod(const AGG_FUN& _fun, const MOD_FUN& _modFun) : tsize(1), aggFun(_fun), modFun(_modFun){
		tree.resize(tsize*2);
	}
	
	template<class FUN>
	void mod(uint where, const FUN& fun){
		check(where);
		
		where += size;
		fun(tree[where].se);
		modFun(tree[where].fi = T(), tree[where].se);
		updateToRoot(where);
	}
	
	

	void set(uint where, const T& what){
		T was = get(where);
		mod(where, what - was);
	}
	
	const T& get(uint where)const{
		if(where >= size) return T();
		
		where += size;
		T result = tree[where].fi;
		while(where != 1){
			where >>= 1;
			modFun(result, tree[where].se, 1);
		}
		return result;
	}
	
	const T& operator[](uint where)const{
		return get(where);
	}
	
	T get(uint fr, uint to)const{
		ASS(fr<to);
		if(fr>=tsize) return T();
		if(to>tsize) to = tsize;
		
		fr+=tsize; to+=tsize-1;
		T lresult = T();
		T rresult = T();
		uint lagg=0;
		uint ragg=0;
		uint lsize = 0;
		uint rsize = 0;
		uint csize = 1;
		while(fr<to){
			if(lagg) modFun(lresult,tree[lagg].second,lsize), lagg>>=1;
			if(ragg) modFun(rresult,tree[ragg].second,rsize), ragg>>=1;
			
			if((fr&1)==1) lresult = aggFun(lresult,tree[fr].first), lsize+=csize, fr>>=1, lagg=fr, ++fr;
			else fr>>=1;
			if((to&1)==0) rresult = aggFun(tree[to].first,rresult), rsize+=csize, to>>=1, ragg=to, --to;
			else to>>=1;
			
			csize <<= 1;
		}
		if(lagg and fr==to and ragg){
			for(;;){
				T cresult = tree[fr].first;
				modFun(lresult,tree[lagg].second,lsize), lagg>>=1;
				modFun(rresult,tree[ragg].second,rsize), ragg>>=1;
				fr>>=1;
				if		(lagg==fr){
					lresult = aggFun(lresult,cresult), lsize += csize;
					break;
				}
				else if	(fr==ragg){
					rresult = aggFun(cresult,rresult), rsize += csize;
					break;
				}
				modFun(cresult,tree[fr].second,csize);
			}
			modFun(lresult,tree[lagg].second,lsize);
			modFun(rresult,tree[ragg].second,rsize);
		}
		else if(lagg and fr==to){
			rresult = tree[fr].first;
			ragg = fr;
			rsize = csize;
			
			modFun(lresult,tree[lagg].second,lsize);
		}
		else if(fr==to and ragg){
			lresult = tree[fr].first;
			lagg = fr;
			lsize = csize;
			
			modFun(rresult,tree[ragg].second,rsize);
		}
		else if(!lagg and !ragg){
			T result = tree[fr].first;
			while(fr!=1){
				fr>>=1;
				modFun(result, tree[fr].second, csize);
			}
			return result;
		}
		else{	

			modFun(lresult, tree[lagg].second,lsize);
			modFun(rresult, tree[ragg].second,rsize);
		}
		
		

		ASS(lagg and ragg);
		ASS(lagg != ragg);
		for(;;){
			lagg >>= 1;
			ragg >>= 1;
			if(lagg==ragg){
				lresult = aggFun(lresult,rresult);
				lsize += rsize;
				modFun(lresult, tree[lagg].second, lsize);
				break;
			}
			modFun(lresult, tree[lagg].second, lsize);
			modFun(rresult, tree[ragg].second, rsize);
		}
		while(lagg != 1){
			lagg>>=1;
			modFun(lresult, tree[lagg].second, lsize);
		}
		return lresult;
	}
	
	template<class FUN>
	void alter(uint fr, uint to,  const FUN& f){
		ASS(fr<to);
		
		check(to-1);
		
		fr += tsize; to += tsize-1;
		uint lupd = 0, lupd_size=0;
		uint rupd = 0, rupd_size=0;
		uint csize = 1;
		
		{
			if((fr&1)==1){
				f(tree[fr].second);
				modFun(tree[fr].first=T(), tree[fr].second, csize);
				if(!lupd)lupd=fr, lupd_size=csize;
				fr>>=1;
				++fr;
			}
			else fr>>=1;
			
			if((to&1)==0){
				f(tree[to].second);
				modFun(tree[to].first=T(), tree[to].second, csize);
				if(!rupd)rupd=to, rupd_size=csize;
				to>>=1;
				--to;
			}
			else to>>=1;
			
			csize <<= 1;
		}
		
		while(fr<to){
			if((fr&1)==1){
				f(tree[fr].second);
				update(fr,csize);
				if(!lupd)lupd=fr, lupd_size=csize;
				fr>>=1;
				++fr;
			}
			else fr>>=1;
			
			if((to&1)==0){
				f(tree[to].second);
				update(to,csize);
				if(!rupd)rupd=to, rupd_size=csize;
				to>>=1;
				--to;
			}
			else to>>=1;
			
			csize <<= 1;
		}
		if(fr==to){
			f(tree[fr].second);
			update(fr,csize);
			if(!lupd)lupd=fr, lupd_size=csize;
			else if(!rupd)rupd=fr, rupd_size=csize;
		}
		
		if(lupd and rupd){
			while(lupd_size < rupd_size)update(lupd >>= 1, lupd_size <<= 1);
			while(lupd_size > rupd_size)update(rupd >>= 1, rupd_size <<= 1);
			for(;;){
				lupd >>= 1; lupd_size <<= 1;
				rupd >>= 1;
				update(lupd, lupd_size);
				if(lupd == rupd)break;
				update(rupd, lupd_size);
			}
		}
		else if(rupd) lupd=rupd, lupd_size=rupd_size;
		
		while(lupd > 1) update(lupd >>= 1, lupd_size <<= 1);
	}
	
	template<class ARG>
	void plus(int fr, int to, const ARG& arg){
		alter(fr,to, _1 += arg);
	}
	template<class ARG>
	void minus(int fr, int to, const ARG& arg){
		alter(fr,to,arg, _1 -= _2);
	}
	template<class ARG>
	void multiplies(int fr, int to, const ARG& arg){
		alter(fr,to,arg, _1 *= _2);
	}
	template<class ARG>
	void divides(int fr, int to, const ARG& arg){
		alter(fr,to,arg, _1 /= _2);
	}
	
private:
	void update(int where, int ssize){
		tree[where].first = aggFun(tree[where*2].first, tree[where*2+1].first);
		modFun(tree[where].first, tree[where].second, ssize);
	}
	void updateToRoot(int where, int ssize){
		while(where>1){
			where>>=1;
			ssize<<=1;
			update(where,ssize);
		}
	}
	
public:
	uint size()const{
		return tsize;
	}
	
	const std::pair<T,MOD>* getTree()const{
		return tree;
	}
	
private:
	void check(uint where){
		if(where<tsize)return;
		
		uint oldPos = tsize;
		uint moves = 0;
		while(where >= tsize) tsize <<= 1, ++moves;
		
		tree.resize(tsize*2);
		uint newPos = tsize;
		
		while(oldPos){
			for(uint i=0; i<oldPos; ++i){
				tree[newPos+i] = tree[oldPos+i];
				tree[oldPos+i] = std::make_pair(T(),MOD());
			}
			oldPos >>= 1;
			newPos >>= 1;
		}
		updateToRoot(newPos << 1, tsize >> moves);
	}
	uint tsize;
	std::vector<std::pair<T,MOD> > tree;
	const AGG_FUN& aggFun;
	const MOD_FUN& modFun;
};


template<class T, class MOD, class AGG_FUN, class MOD_FUN>
ITreeMod<T,MOD,AGG_FUN,MOD_FUN> getITree(
			const AGG_FUN& _fun,
			const MOD_FUN& _modFun){
	return ITreeMod<T,MOD,AGG_FUN,MOD_FUN>(_fun,_modFun);
}

template<class T, class MOD, class AGG_FUN>
ITreeMod<T,MOD,AGG_FUN,LambdaPlusAssign<Lambda1,Lambda2> > getITree(
			const AGG_FUN& _fun){
	return ITreeMod<T,MOD,AGG_FUN,__typeof(_1 += _2)> (_fun,(_1 += _2));
}






template<class T, class MOD, class AGG_FUN, class MOD_FUN>
std::ostream& operator<<(std::ostream& os, const ITreeMod<T,MOD,AGG_FUN,MOD_FUN>& t){

	os << "CUMs:\n";
	uint csize = t.getSize();
	for(uint fi=1; fi<=t.getSize(); fi<<=1){
		for(uint j=fi; j<(fi<<1); ++j){
			os << t.getTree()[j].first;
			for(uint i=0; i<csize-1; ++i)os<<' ';
		}
		os<<'\n';
		csize/=2;
	}
	os << "\nMODs:\n";
	csize = t.getSize();
	for(uint fi=1; fi<=t.getSize(); fi<<=1){
		for(uint j=fi; j<(fi<<1); ++j){
			os << t.getTree()[j].second;
			for(uint i=0; i<csize-1; ++i)os<<' ';
		}
		os<<'\n';
		csize/=2;
	}
	os<<'\n'<<'\n';
	return os;
}



}










#define inl		inline __attribute__ ((always_inline))
#define ninl	__attribute__ ((noinline))







#ifdef DEBUG
	#undef FASTIO
#endif





#ifdef _WIN32



#ifndef NO_UNLOCKED
#define NO_UNLOCKED
#endif






#endif

#define AU(v,val) __typeof(val) v(val)

const char N='\n';
const char S=' ';

using namespace std;
using namespace __gnu_cxx;

namespace ab{}
using namespace ab;



template<class T>inline T cbitl(T x,int i){return (x<<i) ^ (x>>(sizeof(T)*8-i));}


template<class T>inline void sortu(T& t){t.resize(std::unique(ALL(t))-t.be);}


inline uint _rand(){
	if(RAND_MAX < (1<<15)) return (rand()<<15) | rand();
	else return rand();
}
#define RND _rand()


#define ri _rint()
#define rui _ruint()
#define rll _rll()
#define rull _rull()
#define rchar _rchar()
#define rstr _rstr()

#ifndef FASTIO
inline void _fin(int){}
inline void _fout(int){}
#ifdef IOSTREAM
inline int _rint(){int r;cin>>r;return r;}
inline uint _ruint(){uint r;cin>>r;return r;}
inline ull _rull(){ull r;cin>>r;return r;}
inline ll _rll(){ll r;cin>>r;return r;}
inline char _rchar(){return cin.get();}
inline string _rstr(){string s;cin>>s;return s;}
template<typename T>inline void W(const T& i){cout<<i; cout.flush();}
inline void W(){W('\n');}
#else
inline int _rint(){int r;scanf("%d",&r);return r;}
inline uint _ruint(){uint r;scanf("%u",&r);return r;}
inline ull _rull(){ull r;scanf("%" SCNu64,&r);return r;}
inline ull _rll(){ll r;scanf("%" SCNd64,&r);return r;}
inline char _rchar(){return getchar();}
inline string _rstr(){
	string s;
	char c=rchar;
	while(c!=-1 && !isgraph(c))c=rchar;
	for(;;){
		if(!isgraph(c))break;
		s+=c;
		c=rchar;
	}
	return s;
}
inline void W(char a='\n'){printf("%c",a);}
inline void W(const string&s){printf("%s",s.c_str());}
inline void W(int a){printf("%d",a);}
inline void W(uint a){printf("%u",a);}
inline void W(const ui64& a){printf("%" PRIu64,a);}
inline void W(const i64& a){printf("%" PRIi64,a);}
inline void W(const char *str){fputs(str,stdout);}
inline void W(const double& d){printf("%.20f",d);}
inline void W(const long double& d){printf("%.50Lf",d);}
#endif
#else

#ifndef NO_UNLOCKED
#define FREAD fread_unlocked
#define FWRITE fwrite_unlocked
#else
#define FREAD fread
#define FWRITE fwrite
#endif



const int _IB=32768;const int _OB=32768;
char _iB[_IB];int _iP = _IB;
char _oB[_OB];int _oP = 0;
inline void _fin(int mc){
	int r=_IB-_iP;
	if(r>mc)return;
	F(i,r) _iB[i]=_iB[i+_iP];	

    int rd=FREAD(_iB+r,1,_iP,stdin);
	if(rd!=_iP) _iB[r+rd]=0;
	_iP = 0;
}
inline void _fout(int mc){
	if(_OB-_oP>mc)return;
	FWRITE(_oB,1,_oP,stdout);
	_oP = 0;
}
inline void _W(char c='\n'){_oB[_oP++]=c;} 

inline char _rc(){return _iB[_iP++];}
inline char _rchar(){_fin(1);return _rc();}
inline string _rstr(){
	string s;
	for(;;){
		char c=rchar;
		if(!isprint(c)||isspace(c))break;
		s+=c;
	}
	return s;
}
template<class T>inline T _rur(){ 

    T r=0;char c=_rc();
    do c-='0',r=r*10+c,c=_rc();while(c>='0');
    return r;}
template<class T>inline T _rsi(){ 

	char c=_rc();
	while(c<'-')c=_rc();
	if(c=='-')return -_rur<T>();
	else{--_iP;return _rur<T>();}}
template<class T>inline T _ru(){  

	while(_rc()<'0');--_iP;
	return _rur<T>();
}

inline int _rint(){_fin(15);return _rsi<int>();}
inline uint _ruint(){_fin(15);return _ru<uint>();}
inline ll _rll(){_fin(25);return _rsi<ll>();}
inline ull _rull(){_fin(25);return _ru<ull>();}

const int _rs = 20; char _r[_rs];
template<class T>inline void _w(T i){	

	if(numeric_limits<T>::is_signed and i<0) _W('-'), i=-i;
	else if(i==0){_W('0'); return;}
	int pos = _rs;
	do _r[--pos]='0'+i%10, i/=10; while(i);
	do _W(_r[pos++]); while(pos<_rs);
}
inline void W(const char c){_fout(2);_W(c);}
inline void W(const int32_t& i){_fout(15);_w(i);}
inline void W(const uint32_t& i){_fout(15);_w(i);}
inline void W(const int64_t& i){_fout(25);_w(i);}
inline void W(const uint64_t& i){_fout(25);_w(i);}
inline void W(const char*str, int l){
	for(int b=0; b<l; b+=_OB){
		int num = min(_OB,l-b);
		_fout(num);
		memcpy(&_oB[_oP], str+b, num);
		_oP+=num;
	}
}
inline void W(const char*str){W(str,strlen(str));}
inline void W(const string&s){W(s.c_str(),s.siz);}
inline void W(double d){_fout(50);_oP+=sprintf(&_oB[_oP],"%.20f",d);}	

#endif
template<class A,class B>inline void W(const A&a,const B&b){W(a);W(b);}
template<class A,class B,class C>
inline void W(const A&a,const B&b,const C&c){W(a);W(b);W(c);}
template<class A,class B,class C,class DD>
inline void W(const A&a,const B&b,const C&c,const DD&dd){W(a);W(b);W(c);W(dd);}
template<class T>inline void sortall(T&t){sort(t.be,t.en);}
template<class T>inline void uniqall(T&t){t.resize(unique(t.be,t.en)-t.be);}

inline int count1(uint i){return __builtin_popcount(i);}
inline int count1(ull i){return __builtin_popcountll(i);}
inline int parity(uint i){return __builtin_parity(i);}
inline int parity(ull i){return __builtin_parityll(i);}
inline int ilog(uint i){return 31-__builtin_clz(i);} 

inline int ilog(ull i){return 63-__builtin_clzll(i);}
#define powerof2(x) !(x&(x-1))
#define subset(a,b) (a&b==a)
#define kbegin(k) ((1<<k)-1)
#define kend(k,n) ((kbegin(k)<<n-k)+1)
inline uint knext(uint a){uint b=(a|(a-1))+1;return b|((a^b)>>(__builtin_ctz(a)+2));}
#define fors(x,k,n) for(uint x=kbegin(k);x<kend(k,n);x=knext(x))

struct _O{template<class T>_O&operator<(const T&_t){
		oc(1);W(_t);oc(0);
		return *this;
}}O;

struct _I{
	_I&operator>(int32_t&_t){_t=ri;return*this;}
	_I&operator>(uint32_t&_t){_t=rui;return*this;}
	_I&operator>(int64_t&_t){_t=rll;return*this;}
	_I&operator>(uint64_t&_t){_t=rull;return*this;}
	_I&operator>(char&_t){_t=rchar;return*this;}
	_I&operator>(string&_t){_t=rstr;return*this;}
}I;




inline void tc();
#ifdef GEN
int argc;  char **argv;
int main(int _argc, char *_argv[]){
	argc = _argc;  argv = _argv;
	if(argc<2){
		O < "Usage: " < argv[0] < " NR_TESTU" < N;
		return 1;
	}
	srand(atoi(argv[1]));
#else
int main(){
#endif

#ifdef FASTIO
    setvbuf(stdin,0,_IONBF,0);setvbuf(stdout,0,_IONBF,0);
#elif defined IOSTREAM
	ios_base::sync_with_stdio(0);cout.precision(10);cout.setf(ios::fixed,ios::floatfield);
	#if not defined DEBUG and not defined COLOR_CONSOLE
	cin.tie(0);
	#endif
#endif

#ifdef DEBUG
#ifdef _WIN32
	ec(0);
	oc(0);
#else


#endif
#endif
	
#ifdef READ_NUM_TEST_CASES
	int nz=rui;F(i,nz)
#endif
	tc();
#ifdef FASTIO
    FWRITE(_oB,1,_oP,stdout);
#endif
	return 0;
}

















































typedef H1<1000000007> H;




int num0, num1;


inline void tc(){
	
	string s = rstr;
	
	int lasth = -1;
	
	F(i,s.siz) if(s[i]=='(') ++num0;
	else if(s[i]==')') ++num1;
	else lasth = i;
	
	int numh = s.siz - num0 - num1;
	
	if(numh==0 and num0 != num1){
		O<"-1"<N;
		return;
	}
	
	if(numh > num0-num1){
		O<"-1"<N;
		return;
	}
	
	vector<int> result;
	
	int sum = 0;
	F(i,s.siz){
		if(s[i] == '(')++sum;
		else --sum;
		
		
		if(s[i] == '#'){
			if(i == lasth){
				result.pub(((num0-num1)-numh+1));
				sum -= (num0-num1)-numh;
			}
			else result.pub(1);
		}
		
		if(sum<0){
			O<"-1"<N;
			return;
		}
	}
	
	F(i,result.siz) O < result[i] < N;
	
}

