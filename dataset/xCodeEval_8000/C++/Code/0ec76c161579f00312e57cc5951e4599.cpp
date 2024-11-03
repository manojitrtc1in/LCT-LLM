#include <stdio.h>
#include <bits/stdc++.h>

#define psh  push
#define psb  push_back
#define ppb  pop_back
#define mkp  make_pair
#define emp  emplace
#define empb emplace_back
#define empf emplace_front
#define emph emplace_hint
#define fst  first
#define sec  second
#define Lwb  lower_bound
#define Upb  upper_bound

#define foi(i, a, b) for(int i=(a); i<(b); ++i)
#define iof(i, a, b) for(int i=(a)-1; i>=(b); --i)
#define fol(i, a, b) for(LL i=(a); i<(b); ++i)
#define lof(i, a, b) for(LL i=(a)-1; i>=(b); --i)
#define trvl(x, c)   for(auto& x : c)

using std::ios;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;

using std::pair;
using std::string;
using std::bitset;
using std::valarray;
using std::make_pair;

using std::array;
using std::vector;
using std::deque;
using std::forward_list;
using std::list;
using std::stack;
using std::queue;
using std::priority_queue;
using std::set;
using std::multiset;
using std::unordered_set;
using std::map;
using std::multimap;
using std::unordered_map;

using std::function;
using std::initializer_list;

using std::all_of;
using std::any_of;
using std::none_of;
using std::for_each;
using std::find_if;
using std::find_if_not;
using std::find_end;
using std::find_first_of;
using std::adjacent_find;
using std::count_if;
using std::mismatch;
using std::is_permutation;
using std::search_n;
using std::copy_n;
using std::copy_if;
using std::copy_backward;
using std::move_backward;
using std::swap;
using std::swap_ranges;
using std::iter_swap;
using std::replace_if;
using std::replace_copy;
using std::replace_copy_if;
using std::fill;
using std::fill_n;
using std::generate_n;
using std::remove_if;
using std::remove_copy;
using std::remove_copy_if;
using std::unique;
using std::unique_copy;
using std::reverse;
using std::reverse_copy;
using std::rotate_copy;
using std::random_shuffle;
using std::is_partitioned;
using std::partition;
using std::stable_partition;
using std::partition_copy;
using std::partition_point;
using std::sort;
using std::stable_sort;
using std::partial_sort;
using std::partial_sort_copy;
using std::is_sorted;
using std::is_sorted_until;
using std::nth_element;
using std::lower_bound;
using std::upper_bound;
using std::equal_range;
using std::binary_search;
using std::inplace_merge;
using std::set_union;
using std::set_intersection;
using std::set_difference;
using std::set_symmetric_difference;
using std::min;
using std::max;
using std::minmax;
using std::min_element;
using std::max_element;
using std::minmax_element;
using std::lexicographical_compare;
using std::next_permutation;
using std::prev_permutation;

using std::accumulate;
using std::adjacent_difference;
using std::inner_product;
using std::partial_sum;
using std::iota;































#if __SIZEOF_INT128__ == 16
	inline __int128 abs(const __int128 &x){    return x<0 ? -x : x;    }
#endif

template<typename T> inline T& chkmin(T& a, const T& b){    return a>b ? a=b : a;    }
template<typename T> inline T& chkmax(T& a, const T& b){    return a<b ? a=b : a;    }
template<typename T> inline T& toabs (T& x){    return x=abs(x);    }
template<typename T> inline bool cmplss(const T& a, const T& b){    return a<b;    }
template<typename T> inline bool cmpgtr(const T& a, const T& b){    return b<a;    }
template<typename T> inline T SQ(const T& x){ return x*x; }

template<typename T1, typename T2, typename T3>
struct tripple
{
	T1 x; T2 y; T3 z;

	constexpr tripple() = default;
	constexpr tripple(const T1 &_x, const T2 &_y, const T3 &_z)
		:x(_x), y(_y), z(_z){}
	constexpr tripple(const tripple<T1, T2, T3> &_t)
		:x(_t.x), y(_t.y), z(_t.z){}
	template<typename U1, typename U2, typename U3>
		constexpr tripple(const tripple<U1, U2, U3> &_t)
			:x(_t.x), y(_t.y), z(_t.z){}
	
	tripple& operator=(const tripple<T1, T2, T3> &_t)
	{
		x=_t.x; y=_t.y; z=_t.z;
		return *this;
	}
	template<typename U1, typename U2, typename U3>
		tripple& operator=(const tripple<U1, U2, U3> &_t)
		{
			x=_t.x; y=_t.y; z=_t.z;
			return *this;
		}

	template<typename U1, typename U2, typename U3>
		tripple operator+(const tripple<U1, U2, U3> &_t)
		{
			return tripple<T1, T2, T3>(x+_t.x, y+_t.y, z+_t.z);
		}

	template<typename U1, typename U2, typename U3>
		tripple operator-(const tripple<U1, U2, U3> &_t)
		{
			return tripple<T1, T2, T3>(x-_t.x, y-_t.y, z-_t.z);
		}

	template<typename U1, typename U2, typename U3>
		tripple operator*(const tripple<U1, U2, U3> &_t)
		{
			return tripple<T1, T2, T3>(x*_t.x, y*_t.y, z*_t.z);
		}

	template<typename U1, typename U2, typename U3>
		tripple operator/(const tripple<U1, U2, U3> &_t)
		{
			return tripple<T1, T2, T3>(x/_t.x, y/_t.y, z/_t.z);
		}

	template<typename U1, typename U2, typename U3>
		tripple operator%(const tripple<U1, U2, U3> &_t)
		{
			return tripple<T1, T2, T3>(x%_t.x, y%_t.y, z%_t.z);
		}

	template<typename U1, typename U2, typename U3>
		tripple operator&(const tripple<U1, U2, U3> &_t)
		{
			return tripple<T1, T2, T3>(x&_t.x, y&_t.y, z&_t.z);
		}

	template<typename U1, typename U2, typename U3>
		tripple operator|(const tripple<U1, U2, U3> &_t)
		{
			return tripple<T1, T2, T3>(x|_t.x, y|_t.y, z|_t.z);
		}

	template<typename U1, typename U2, typename U3>
		tripple operator^(const tripple<U1, U2, U3> &_t)
		{
			return tripple<T1, T2, T3>(x^_t.x, y^_t.y, z^_t.z);
		}

	template<typename U>
		tripple operator+(const U &o)
		{
			return tripple<T1, T2, T3>(x+o, y+o, z+o);
		}

	template<typename U>
		tripple operator-(const U &o)
		{
			return tripple<T1, T2, T3>(x-o, y-o, z-o);
		}
	
	template<typename U>
		tripple operator*(const U &o)
		{
			return tripple<T1, T2, T3>(x*o, y*o, z*o);
		}
	
	template<typename U>
		tripple operator/(const U &o)
		{
			return tripple<T1, T2, T3>(x/o, y/o, z/o);
		}

	template<typename U>
		tripple operator%(const U &o)
		{
			return tripple<T1, T2, T3>(x%o, y%o, z%o);
		}

	template<typename U>
		tripple operator&(const U &o)
		{
			return tripple<T1, T2, T3>(x&o, y&o, z&o);
		}
	
	template<typename U>
		tripple operator|(const U &o)
		{
			return tripple<T1, T2, T3>(x|o, y|o, z|o);
		}
	
	template<typename U>
		tripple operator^(const U &o)
		{
			return tripple<T1, T2, T3>(x^o, y^o, z^o);
		}

	tripple operator~()
	{
		return tripple<T1, T2, T3>(~x, ~y, ~z);
	}

	tripple operator+()
	{
		return *this;
	}

	tripple operator-()
	{
		return tripple<T1, T2, T3>(-x, -y, -z);
	}

	tripple& operator++()
	{
		++x; ++y; ++z;
		return *this;
	}

	tripple& operator--()
	{
		--x; --y; --z;
		return *this;
	}

	tripple operator++(int)
	{
		return tripple<T1, T2, T3>(x++, y++, z++);
	}

	tripple operator--(int)
	{
		return tripple<T1, T2, T3>(x--, y--, z--);
	}

	template<typename U1, typename U2, typename U3>
		tripple& operator+=(const tripple<U1, U2, U3> &_t)
		{
			x+=_t.x; y+=_t.y; z+=_t.z;
			return *this;
		}

	template<typename U1, typename U2, typename U3>
		tripple& operator-=(const tripple<U1, U2, U3> &_t)
		{
			x-=_t.x; y-=_t.y; z-=_t.z;
			return *this;
		}

	template<typename U1, typename U2, typename U3>
		tripple& operator*=(const tripple<U1, U2, U3> &_t)
		{
			x*=_t.x; y*=_t.y; z*=_t.z;
			return *this;
		}

	template<typename U1, typename U2, typename U3>
		tripple& operator/=(const tripple<U1, U2, U3> &_t)
		{
			x/=_t.x; y/=_t.y; z/=_t.z;
			return *this;
		}

	template<typename U1, typename U2, typename U3>
		tripple& operator%=(const tripple<U1, U2, U3> &_t)
		{
			x%=_t.x; y%=_t.y; z%=_t.z;
			return *this;
		}

	template<typename U1, typename U2, typename U3>
		tripple& operator&=(const tripple<U1, U2, U3> &_t)
		{
			x&=_t.x; y&=_t.y; z&=_t.z;
			return *this;
		}

	template<typename U1, typename U2, typename U3>
		tripple& operator|=(const tripple<U1, U2, U3> &_t)
		{
			x|=_t.x; y|=_t.y; z|=_t.z;
			return *this;
		}

	template<typename U1, typename U2, typename U3>
		tripple& operator^=(const tripple<U1, U2, U3> &_t)
		{
			x^=_t.x; y^=_t.y; z^=_t.z;
			return *this;
		}

	template<typename U>
		tripple& operator+=(const U &o)
		{
			x+=o; y+=o; z+=o;
			return *this;
		}

	template<typename U>
		tripple& operator-=(const U &o)
		{
			x-=o; y-=o; z-=o;
			return *this;
		}
	
	template<typename U>
		tripple& operator*=(const U &o)
		{
			x*=o; y*=o; z*=o;
			return *this;
		}
	
	template<typename U>
		tripple& operator/=(const U &o)
		{
			x/=o; y/=o; z/=o;
			return *this;
		}
	
	template<typename U>
		tripple& operator%=(const U &o)
		{
			x%=o; y%=o; z%=o;
			return *this;
		}
	
	template<typename U>
		tripple& operator&=(const U &o)
		{
			x&=o; y&=o; z&=o;
			return *this;
		}

	template<typename U>
		tripple& operator|=(const U &o)
		{
			x|=o; y|=o; z|=o;
			return *this;
		}
	
	template<typename U>
		tripple& operator^=(const U &o)
		{
			x^=o; y^=o; z^=o;
			return *this;
		}

	template<typename U>
		tripple operator<<(const U &o)
		{
			return tripple<T1, T2, T3>(x<<o, y<<o, z<<o);
		}

	template<typename U>
		tripple operator>>(const U &o)
		{
			return tripple<T1, T2, T3>(x>>o, y>>o, z>>o);
		}

	template<typename U>
		tripple& operator<<=(const U &o)
		{
			x<<=o; y<<=o; z<<=o;
			return *this;
		}

	template<typename U>
		tripple& operator>>=(const U &o)
		{
			x>>=o; y>>=o; z>>=o;
			return *this;
		}

	template<typename U1, typename U2, typename U3>
		tripple operator<<(const tripple<U1, U2, U3> &_t)
		{
			return tripple<T1, T2, T3>(x<<_t.x, y<<_t.y, z<<_t.z);
		}

	template<typename U1, typename U2, typename U3>
		tripple operator>>(const tripple<U1, U2, U3> &_t)
		{
			return tripple<T1, T2, T3>(x>>_t.x, y>>_t.y, z>>_t.z);
		}

	template<typename U1, typename U2, typename U3>
		tripple& operator<<=(const tripple<U1, U2, U3> &_t)
		{
			x<<=_t.x; y<<=_t.y; z<<=_t.z;
			return *this;
		}

	template<typename U1, typename U2, typename U3>
		tripple& operator>>=(const tripple<U1, U2, U3> &_t)
		{
			x>>=_t.x; y>>=_t.y; z>>=_t.z;
			return *this;
		}

	friend ostream& operator<<(ostream &out, const tripple<T1, T2, T3> &t)
	{
		out<<t.x<<" "<<t.y<<" "<<t.z;
		return out;
	}

	friend istream& operator>>(istream &in, tripple<T1, T2, T3> &t)
	{
		in>>t.x>>t.y>>t.z;
		return in;
	}
};

template<typename T1, typename T2, typename T3>
inline bool operator==(const tripple<T1, T2, T3> &a, const tripple<T1, T2, T3> &b)
{
	return a.x==b.x && a.y==b.y && a.z==b.z;
}

template<typename T1, typename T2, typename T3>
inline bool operator<(const tripple<T1, T2, T3> &a, const tripple<T1, T2, T3> &b)
{
	return a.x<b.x || ( !(b.x<a.x) && (b.y<a.y || ( !(b.y<a.y) && a.z<b.z) ) );
}

template<typename T1, typename T2, typename T3>
inline bool operator!=(const tripple<T1, T2, T3> &a, const tripple<T1, T2, T3> &b)
{
	return !(a==b);
}

template<typename T1, typename T2, typename T3>
inline bool operator>(const tripple<T1, T2, T3> &a, const tripple<T1, T2, T3> &b)
{
	return b<a;
}

template<typename T1, typename T2, typename T3>
inline bool operator<=(const tripple<T1, T2, T3> &a, const tripple<T1, T2, T3> &b)
{
	return !(b<a);
}

template<typename T1, typename T2, typename T3>
inline bool operator>=(const tripple<T1, T2, T3> &a, const tripple<T1, T2, T3> &b)
{
	return !(a<b);
}

template<typename T1, typename T2, typename T3>
inline void swap(const tripple<T1, T2, T3> &a, const tripple<T1, T2, T3> &b)
{
	swap(a.x,b.x); swap(a.y,b.y); swap(a.z,b.z);
}

template<typename T1, typename T2, typename U1, typename U2>
inline pair<T1, T2> operator+(const pair<T1, T2> &a, const pair<U1, U2> &b)
{
	return pair<T1, T2>(a.first + b.first, a.second + b.second);
}

template<typename T1, typename T2, typename U1, typename U2>
inline pair<T1, T2> operator-(const pair<T1, T2> &a, const pair<U1, U2> &b)
{
	return pair<T1, T2>(a.first - b.first, a.second - b.second);
}

template<typename T1, typename T2, typename U1, typename U2>
inline pair<T1, T2> operator*(const pair<T1, T2> &a, const pair<U1, U2> &b)
{
	return pair<T1, T2>(a.first * b.first, a.second * b.second);
}

template<typename T1, typename T2, typename U1, typename U2>
inline pair<T1, T2> operator/(const pair<T1, T2> &a, const pair<U1, U2> &b)
{
	return pair<T1, T2>(a.first / b.first, a.second / b.second);
}

template<typename T1, typename T2, typename U1, typename U2>
inline pair<T1, T2> operator%(const pair<T1, T2> &a, const pair<U1, U2> &b)
{
	return pair<T1, T2>(a.first % b.first, a.second % b.second);
}

template<typename T1, typename T2, typename U1, typename U2>
inline pair<T1, T2> operator&(const pair<T1, T2> &a, const pair<U1, U2> &b)
{
	return pair<T1, T2>(a.first & b.first, a.second & b.second);
}

template<typename T1, typename T2, typename U1, typename U2>
inline pair<T1, T2> operator|(const pair<T1, T2> &a, const pair<U1, U2> &b)
{
	return pair<T1, T2>(a.first | b.first, a.second | b.second);
}

template<typename T1, typename T2, typename U1, typename U2>
inline pair<T1, T2> operator^(const pair<T1, T2> &a, const pair<U1, U2> &b)
{
	return pair<T1, T2>(a.first ^ b.first, a.second ^ b.second);
}

template<typename T1, typename T2, typename U1, typename U2>
inline pair<T1, T2> operator<<(const pair<T1, T2> &a, const pair<U1, U2> &b)
{
	return pair<T1, T2>(a.first<<b.first, a.second<<b.second);
}

template<typename T1, typename T2, typename U1, typename U2>
inline pair<T1, T2> operator>>(const pair<T1, T2> &a, const pair<U1, U2> &b)
{
	return pair<T1, T2>(a.first>>b.first, a.second>>b.second);
}

template<typename T1, typename T2>
inline pair<T1, T2> operator~(const pair<T1, T2> &a)
{
	return pair<T1, T2>(~a.first, ~a.second);
}

template<typename T1, typename T2>
inline pair<T1, T2>& operator++(pair<T1, T2> &a)
{
	a.first++; a.second++;
	return a;
}

template<typename T1, typename T2>
inline pair<T1, T2> operator++(pair<T1, T2> &a, int)
{
	return pair<T1, T2>(a.first++, a.second++);
}

template<typename T1, typename T2>
inline pair<T1, T2>& operator--(pair<T1, T2> &a)
{
	a.first--; a.second--;
	return a;
}

template<typename T1, typename T2>
inline pair<T1, T2> operator--(pair<T1, T2> &a, int)
{
	return pair<T1, T2>(a.first--, a.second--);
}

template<typename T1, typename T2, typename U1, typename U2>
inline pair<T1, T2>& operator+=(pair<T1, T2> &a, const pair<U1, U2> &b)
{
	a.first+=b.first; a.second+=b.second;
	return a;
}

template<typename T1, typename T2, typename U1, typename U2>
inline pair<T1, T2>& operator-=(pair<T1, T2> &a, const pair<U1, U2> &b)
{
	a.first-=b.first; a.second-=b.second;
	return a;
}

template<typename T1, typename T2, typename U1, typename U2>
inline pair<T1, T2>& operator*=(pair<T1, T2> &a, const pair<U1, U2> &b)
{
	a.first*=b.first; a.second*=b.second;
	return a;
}

template<typename T1, typename T2, typename U1, typename U2>
inline pair<T1, T2>& operator/=(pair<T1, T2> &a, const pair<U1, U2> &b)
{
	a.first/=b.first; a.second/=b.second;
	return a;
}

template<typename T1, typename T2, typename U1, typename U2>
inline pair<T1, T2>& operator%=(pair<T1, T2> &a, const pair<U1, U2> &b)
{
	a.first%=b.first; a.second%=b.second;
	return a;
}

template<typename T1, typename T2, typename U1, typename U2>
inline pair<T1, T2>& operator&=(pair<T1, T2> &a, const pair<U1, U2> &b)
{
	a.first&=b.first; a.second&=b.second;
	return a;
}

template<typename T1, typename T2, typename U1, typename U2>
inline pair<T1, T2>& operator|=(pair<T1, T2> &a, const pair<U1, U2> &b)
{
	a.first|=b.first; a.second|=b.second;
	return a;
}

template<typename T1, typename T2, typename U1, typename U2>
inline pair<T1, T2>& operator^=(pair<T1, T2> &a, const pair<U1, U2> &b)
{
	a.first^=b.first; a.second^=b.second;
	return a;
}

template<typename T1, typename T2, typename U1, typename U2>
inline pair<T1, T2>& operator<<=(pair<T1, T2> &a, const pair<U1, U2> &b)
{
	a.first<<=b.first; a.second<<=b.second;
	return a;
}

template<typename T1, typename T2, typename U1, typename U2>
inline pair<T1, T2>& operator>>=(pair<T1, T2> &a, const pair<U1, U2> &b)
{
	a.first>>=b.first; a.second>>=b.second;
	return a;
}

template<typename T1, typename T2, typename U>
inline pair<T1, T2> operator+(const pair<T1, T2> &a, const U &b)
{
	return pair<T1, T2>(a.first+b, a.second+b);
}

template<typename T1, typename T2, typename U>
inline pair<T1, T2> operator-(const pair<T1, T2> &a, const U &b)
{
	return pair<T1, T2>(a.first-b, a.second-b);
}

template<typename T1, typename T2, typename U>
inline pair<T1, T2> operator*(const pair<T1, T2> &a, const U &b)
{
	return pair<T1, T2>(a.first*b, a.second*b);
}

template<typename T1, typename T2, typename U>
inline pair<T1, T2> operator/(const pair<T1, T2> &a, const U &b)
{
	return pair<T1, T2>(a.first/b, a.second/b);
}

template<typename T1, typename T2, typename U>
inline pair<T1, T2> operator%(const pair<T1, T2> &a, const U &b)
{
	return pair<T1, T2>(a.first%b, a.second%b);
}

template<typename T1, typename T2, typename U>
inline pair<T1, T2> operator&(const pair<T1, T2> &a, const U &b)
{
	return pair<T1, T2>(a.first&b, a.second&b);
}

template<typename T1, typename T2, typename U>
inline pair<T1, T2> operator|(const pair<T1, T2> &a, const U &b)
{
	return pair<T1, T2>(a.first|b, a.second|b);
}

template<typename T1, typename T2, typename U>
inline pair<T1, T2> operator^(const pair<T1, T2> &a, const U &b)
{
	return pair<T1, T2>(a.first^b, a.second^b);
}

template<typename T1, typename T2, typename U>
inline pair<T1, T2> operator<<(const pair<T1, T2> &a, const U &b)
{
	return pair<T1, T2>(a.first<<b, a.second<<b);
}

template<typename T1, typename T2, typename U>
inline pair<T1, T2> operator>>(const pair<T1, T2> &a, const U &b)
{
	return pair<T1, T2>(a.first>>b, a.second>>b);
}

template<typename T1, typename T2, typename U>
inline pair<T1, T2>& operator+=(pair<T1, T2> &a, const U &b)
{
	a.first+=b; a.second+=b;
	return a;
}

template<typename T1, typename T2, typename U>
inline pair<T1, T2>& operator-=(pair<T1, T2> &a, const U &b)
{
	a.first-=b; a.second-=b;
	return a;
}

template<typename T1, typename T2, typename U>
inline pair<T1, T2>& operator*=(pair<T1, T2> &a, const U &b)
{
	a.first*=b; a.second*=b;
	return a;
}

template<typename T1, typename T2, typename U>
inline pair<T1, T2>& operator/=(pair<T1, T2> &a, const U &b)
{
	a.first/=b; a.second/=b;
	return a;
}

template<typename T1, typename T2, typename U>
inline pair<T1, T2>& operator%=(pair<T1, T2> &a, const U &b)
{
	a.first%=b; a.second%=b;
	return a;
}

template<typename T1, typename T2, typename U>
inline pair<T1, T2>& operator&=(pair<T1, T2> &a, const U &b)
{
	a.first&=b; a.second&=b;
	return a;
}

template<typename T1, typename T2, typename U>
inline pair<T1, T2>& operator|=(pair<T1, T2> &a, const U &b)
{
	a.first|=b; a.second|=b;
	return a;
}

template<typename T1, typename T2, typename U>
inline pair<T1, T2>& operator^=(pair<T1, T2> &a, const U &b)
{
	a.first^=b; a.second^=b;
	return a;
}

template<typename T1, typename T2, typename U>
inline pair<T1, T2>& operator<<=(pair<T1, T2> &a, const U &b)
{
	a.first<<=b; a.second<<=b;
	return a;
}

template<typename T1, typename T2, typename U>
inline pair<T1, T2>& operator>>=(pair<T1, T2> &a, const U &b)
{
	a.first>>=b; a.second>>=b;
	return a;
}

template<typename T1, typename T2>
inline ostream& operator<<(ostream &out, const pair<T1, T2> &p)
{
	out<<p.first<<" "<<p.second;
	return out;
}

template<typename T1, typename T2>
inline istream& operator>>(istream &in, pair<T1, T2> &p)
{
	in>>p.first>>p.second;
	return in;
}

#if __SIZEOF_INT128__ == 16
	inline ostream& operator<<(ostream& out, __int128 &x)
	{
		static int a[50],len=0,sign=0;
		len=0; sign=x<0 ? 1 : 0; toabs(x);
		while(x) a[++len]=x%10, x/=10;
		if(sign) out<<'-';
		while(len) out<<a[len--];
		return out;
	}

	inline istream& operator>>(istream& in, __int128 &x)
	{
		int sign=0; char ch; in>>ch; x=0;
		while(ch!='-' && (ch<'0' || '9'<ch)) in>>ch;
		if(ch=='-') sign=1, in>>ch;
		while('0'<=ch && ch<='9') x=(x<<3) + (x<<1) + ch-'0', in>>ch;
		if(sign) x=-x;
		return in;
	}
#endif

using LL   = long long;
using uLL  = unsigned long long;
using uint = unsigned int;
using DB   = double;
using LDB  = long double;
using u32  = unsigned int;
using u16  = unsigned short;
using u64  = unsigned long long;

#if __SIZEOF_INT128__ == 16
	using LLL  = __int128;
#endif

using PII = pair<int,int>;
using PLI = pair<LL,int>;
using PIL = pair<int,LL>;
using PLL = pair<LL,LL>;

using TIII = tripple<int,int,int>;
using TIIL = tripple<int,int,LL>;
using TILI = tripple<int,LL,int>;
using TILL = tripple<int,LL,LL>;
using TLII = tripple<LL,int,int>;
using TLIL = tripple<LL,int,LL>;
using TLLI = tripple<LL,LL,int>;
using TLLL = tripple<LL,LL,LL>;

using VI  = vector<int>;
using VL  = vector<LL>;
using QI  = queue<int>;
using QL  = queue<LL>;
using STI = stack<int>;
using STL = stack<LL>;
using PQI = priority_queue<int>;
using PQL = priority_queue<LL>;
using DQI = deque<int>;
using DQL = deque<LL>;

using MII = map<int,int>;
using MLI = map<LL,int>;
using MIL = map<int,LL>;
using MLL = map<LL,LL>;
using MSI = map<string,int>;
using MSL = map<string,LL>;
using SI  = set<int>;
using SL  = set<LL>;
using HASHSI  = unordered_set<int>;
using HASHSL  = unordered_set<LL>;
using HASHMII = unordered_map<int,int>;
using HASHMLI = unordered_map<LL,int>;
using HASHMIL = unordered_map<int,LL>;
using HASHMLL = unordered_map<LL,LL>;

const short MSK15 = 0x7fff;
const u16   MSK16 = 0xffff;
const int   MSK31 = 0x7fffffff;
const u32   MSK32 = 0xffffffff;
const LL    MSK63 = 0x7fffffffffffffff;
const uLL   MSK64 = 0xffffffffffffffff;
const u32   RAND_max  = 1u<<31;
const uLL   LRAND_max = 1uLL<<63;

const int Inf    = (1<<30)-1;
const int mInf1  = 0x3f3f3f3f;
const int mInf2  = 0x7f7f7f7f;
const LL  lInf   = (1LL<<62)-1;
const LL  lmInf1 = 0x3f3f3f3f3f3f3f3fLL;
const LL  lmInf2 = 0x7f7f7f7f7f7f7f7fLL;
const DB  dInf   = 1e15;

inline int rnd15() {    return rand()&MSK15;    }
inline int rnd16() {    return rnd15() | (rnd15()&1)<<15;    }
inline int rnd31() {    return rnd15()<<16 | rnd16();    }
inline int rnd32() {    return rnd16()<<16 | rnd16();    }
inline u32 rndu32(){    return ((u32)rnd16())<<16 | ((u32)rnd16());      }
inline LL  rnd63() {    return ((LL)rnd31())<<32 | ((LL)rndu32());       }
inline LL  rnd64() {    return ((LL)rndu32())<<32 | ((LL)rndu32());      }
inline uLL rndu64(){    return ((uLL)rndu32())<<32 | ((uLL)rndu32());    }
inline int rnd()   {    return rnd31();     }
inline LL  lrnd()  {    return rnd63();     }
inline u32 urnd()  {    return rndu32();    }
inline uLL ullrnd(){    return rndu64();    }
inline DB  drnd()  {    return 1.0*lrnd()/LRAND_max;    }

inline int rnd(int L, int R){
	return L<0 ? int( lrnd()%((LL)R-L+1)+L ) : rnd()%(R-L+1)+L;
}
inline LL lrnd(LL L, LL R){
	return lrnd()%(R-L+1)+L;
}
inline DB drnd(DB L, DB R){
	return drnd()*(R-L)+L;
}

inline char getch()
{
	static const int Buf=1048576;
	static char buf[Buf+1], *head=buf, *tail=buf;
	if(head==tail) *(tail= (head=buf) + fread(buf,1,Buf,stdin))=0;
	return *head++;
}

inline u32 rdu32()
{
	u32 ret=0; char ch=getch();
	while(ch<'0' || '9'<ch) ch=getch();
	while('0'<=ch && ch<='9') ret=(ret<<3) + (ret<<1) + ch-'0', ch=getch();
	return ret;
}

inline int rdint()
{
	int ret=0, sign=0; char ch=getch();
	while(ch!='-' && (ch<'0' || '9'<ch)) ch=getch();
	if(ch=='-') sign=1, ch=getch();
	while('0'<=ch && ch<='9') ret=(ret<<3) + (ret<<1) + ch-'0', ch=getch();
	if(sign) ret=-ret;
	return ret;
}

inline uLL rduLL()
{
	uLL ret=0; char ch=getch();
	while(ch<'0' || '9'<ch) ch=getch();
	while('0'<=ch && ch<='9') ret=(ret<<3) + (ret<<1) + ch-'0', ch=getch();
	return ret;
}

inline LL rdLL()
{
	LL ret=0; int sign=0; char ch=getch();
	while(ch!='-' && (ch<'0' || '9'<ch)) ch=getch();
	if(ch=='-') sign=1, ch=getch();
	while('0'<=ch && ch<='9') ret=(ret<<3) + (ret<<1) + ch-'0', ch=getch();
	if(sign) ret=-ret;
	return ret;
}

#if __SIZEOF_INT128__ == 16
	inline LLL rdLLL()
	{
		LLL ret=0; int sign=0; char ch=getch();
		while(ch!='-' && (ch<'0' || '9'<ch)) ch=getch();
		if(ch=='-') sign=1, ch=getch();
		while('0'<=ch && ch<='9') ret=(ret<<3) + (ret<<1) + ch-'0', ch=getch();
		if(sign) ret=-ret;
		return ret;
	}
#endif

inline char rdch()
{
	char ch=getch();
	while(ch<33 || 126<ch) ch=getch();
	return ch;
}

inline int  read()   {    return rdint();    }
inline u32  readu()  {    return rdu32();    }
inline LL   readll() {    return rdLL();     }
inline uLL  readull(){    return rduLL();    }
inline char readc()  {    return rdch();     }

#if __SIZEOF_INT128__ == 16
	inline LLL readlll() {    return rdLLL();    }
#endif

inline void putch(char ch, int flag=0)
{
	static const int Buf=1048576;
	static char buf[Buf+1], *head=buf, *tail=buf+Buf;
	if(!flag) *head++=ch;
	if(head==tail || flag) fwrite(buf,1,head-buf,stdout), head=buf;
}

inline void write(char ch)
{
	putch(ch);
}

inline void write(const string &s)
{
	for(int i=0; i<int(s.size()); i++) putch(s[i]);
}

inline void write(int x)
{
	static int a[13],len=0,sign=0;
	if(x==0){ putch('0'); return; }
	len=0; sign= x<0 ? 1 : 0; toabs(x);
	while(x) a[++len]=x%10, x/=10;
	if(sign) putch('-');
	while(len) putch(a[len--]+'0');
}

inline void write(u32 x)
{
	static int a[13],len=0;
	if(x==0){ putch('0'); return; }
	len=0;
	while(x) a[++len]=x%10, x/=10;
	while(len) putch(a[len--]+'0');
}

inline void write(LL x)
{
	static int a[26],len=0,sign=0;
	if(x==0){ putch('0'); return; }
	len=0; sign= x<0 ? 1 : 0; toabs(x);
	while(x) a[++len]=x%10, x/=10;
	if(sign) putch('-');
	while(len) putch(a[len--]+'0');
}

inline void write(uLL x)
{
	static int a[26],len=0;
	if(x==0){ putch('0'); return; }
	len=0;
	while(x) a[++len]=x%10, x/=10;
	while(len) putch(a[len--]+'0');
}

#if __SIZEOF_INT128__ == 16
	inline void write(LLL x)
	{
		static int a[50],len=0,sign=0;
		if(x==0){ putch('0'); return; }
		len=0; sign= x<0 ? 1 : 0; toabs(x);
		while(x) a[++len]=x%10, x/=10;
		if(sign) putch('-');
		while(len) putch(a[len--]+'0');
	}
#endif

inline void flushbuf(){    putch(0,1);    }
inline void endlflsh(){    putch('\n'); putch(0,1);    }
template<typename T> inline void writeln(T x)  {    write(x); putch('\n');    }
template<typename T> inline void writeflsh(T x){    write(x); putch('\n'); putch(0,1);    }

const int USEFILE = 0;
const int MULTITEST1 = 1;
const int MULTITEST2 = 0;

inline void usefile()
{
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
}

void INIT()
{
	
	return;
}

const int Maxn=200010;

struct Treenode
{
	PII val;
	int laz;
}node[Maxn<<2];

void update(int x)
{
	node[x].val=node[x<<1].val + node[x<<1|1].val;
}

void build(int x, int ll, int rr, const VI &a)
{
	node[x].val.first=node[x].val.second=0;
	node[x].laz=-1;
	if(ll==rr)
	{
		node[x].val.fst= a[ll]==0;
		node[x].val.sec= a[ll]==1;
		return;
	}
	build(x<<1,ll,ll+rr>>1,a);
	build(x<<1|1,ll+rr+2>>1,rr,a);
	update(x);
}

void markdown(int x, int ll, int rr)
{
	if(node[x].laz==-1) return;
	int mid=ll+rr>>1;
	node[x<<1].val.fst= node[x].laz==0 ? mid-ll+1 : 0;
	node[x<<1].val.sec= node[x].laz==1 ? mid-ll+1 : 0;
	node[x<<1|1].val.fst= node[x].laz==0 ? rr-mid : 0;
	node[x<<1|1].val.sec= node[x].laz==1 ? rr-mid : 0;
	node[x<<1].laz= node[x].laz;
	node[x<<1|1].laz= node[x].laz;
	node[x].laz=-1;
}

void assign(int x, int ll, int rr, int l, int r, int v)
{
	if(ll==l && rr==r)
	{
		node[x].val.fst= v==0 ? rr-ll+1 : 0;
		node[x].val.sec= v==1 ? rr-ll+1 : 0;
		node[x].laz=v;
		return;
	}
	markdown(x,ll,rr);
	int mid=ll+rr>>1;
	if(r<=mid) assign(x<<1,ll,mid,l,r,v);
	else if(l>mid) assign(x<<1|1,mid+1,rr,l,r,v);
	else assign(x<<1,ll,mid,l,mid,v), assign(x<<1|1,mid+1,rr,mid+1,r,v);
	update(x);
}

PII query(int x, int ll, int rr, int l, int r)
{
	if(ll==l && rr==r) return node[x].val;
	markdown(x,ll,rr);
	int mid=ll+rr>>1;
	if(r<=mid) return query(x<<1,ll,mid,l,r);
	else if(l>mid) return query(x<<1|1,mid+1,rr,l,r);
	else return query(x<<1,ll,mid,l,mid) + query(x<<1|1,mid+1,rr,mid+1,r);
}

int cmpdiff(int x, int ll, int rr, const VI &a)
{
	if(ll==rr)
	{
		PII v(a[ll]==0, a[ll]==1);




		return node[x].val!=v;
	}
	markdown(x,ll,rr);
	int mid=ll+rr>>1;
	return cmpdiff(x<<1,ll,mid,a) | cmpdiff(x<<1|1,mid+1,rr,a);
}

int SOVLE()
{
	int n,Q;
	cin>>n>>Q;

	VI s(n+10,0), t(n+10,0);
	vector<PII > q(Q+10,PII(0,0));

	for(int i=1; i<=n; i++)
	{
		char ch; cin>>ch;
		s[i]=ch=='1';
	}
	for(int i=1; i<=n; i++)
	{
		char ch; cin>>ch;
		t[i]=ch=='1';
	}

	for(int i=1; i<=Q; i++) cin>>q[i].fst>>q[i].sec;

	build(1,1,n,t);

	for(int i=Q; i>=1; i--)
	{
		PII res=query(1,1,n,q[i].fst,q[i].sec);




		if(res.fst<res.sec) assign(1,1,n,q[i].fst,q[i].sec,1);
		else if(res.fst==res.sec)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		else assign(1,1,n,q[i].fst,q[i].sec,0);


	}

	if(cmpdiff(1,1,n,s)) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;

	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	srand((uLL)(new char));

	INIT();

	if(USEFILE) usefile();

	int T=MULTITEST2 ? Inf : 1;
	if(MULTITEST1) cin>>T;
	while(T-- && SOVLE()==0);

	return 0;
}