





















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
using std::unordered_multiset;
using std::map;
using std::multimap;
using std::unordered_map;
using std::unordered_multimap;

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































template<typename T> inline T& toabs (T&);

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

	T1& operator[](int p)
	{
		switch(p)
		{
			case 0: return x; break;
			case 1: return y; break;
			case 2: return z; break;
			default: return x; break;
		}
	}

	const T1& operator[](int p) const
	{
		switch(p)
		{
			case 0: return x; break;
			case 1: return y; break;
			case 2: return z; break;
			default: return x; break;
		}
	}

	tripple& toabs()
	{
		toabs(x); toabs(y); toabs(z);
		return *this;
	}

	tripple& rotate()
	{
		swap(x,y); swap(y,z);
		return *this;
	}

	tripple& sortlss()
	{
		if(z<y) swap(y,z);
		if(y<x) swap(x,y);
		if(z<y) swap(y,z);
		return *this;
	}

	tripple& sort()
	{
		return sortlss();
	}

	tripple& sortgtr()
	{
		if(z>y) swap(y,z);
		if(y>x) swap(x,y);
		if(z>y) swap(y,z);
		return *this;
	}

	void check()
	{
		cout<<x<<":"<<y<<":"<<z;
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

using LL   = long long;
using uLL  = unsigned long long;
using uint = unsigned int;
using DB   = double;
using LDB  = long double;
using u32  = unsigned int;
using u16  = unsigned short;
using u64  = unsigned long long;


	using LLL  = __int128;


template<typename T1, typename T2, typename T3> using TRI = tripple<T1, T2, T3>;
template<typename T> using PQ = priority_queue<T>;
template<typename T> using HASHS  = unordered_set<T>;
template<typename T> using HASHMS = unordered_multiset<T>;
template<typename T1, typename T2> using HASHM  = unordered_map<T1, T2>;
template<typename T1, typename T2> using HASHMM = unordered_multimap<T1, T2>;

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

const short id13 = 0x7fff;
const u16   id11 = 0xffff;
const int   id20 = 0x7fffffff;
const u32   id14 = 0xffffffff;
const LL    id18 = 0x7fffffffffffffff;
const uLL   id8 = 0xffffffffffffffff;
const u32   RAND_max  = 1u<<31;
const uLL   id17 = 1uLL<<63;

const int Inf    = (1<<30)-1;
const int id21  = 0x3f3f3f3f;
const int id10  = 0x7f7f7f7f;
const LL  lInf   = (1LL<<62)-1;
const LL  id1 = 0x3f3f3f3f3f3f3f3fLL;
const LL  id22 = 0x7f7f7f7f7f7f7f7fLL;
const DB  dInf   = 1e15;

template<typename T> inline T& chkmin(T& a, const T& b){    return a>b ? a=b : a;    }
template<typename T> inline T& chkmax(T& a, const T& b){    return a<b ? a=b : a;    }
template<typename T> inline bool id9(const T& a, const T& b){    return a<b;    }
template<typename T> inline bool id19(const T& a, const T& b){    return b<a;    }
template<typename T> inline T sqr(const T& x){ return x*x; }
template<typename T> inline T& toabs (T& x){    return x=abs(x);    }

	inline __int128& toabs(__int128 &x){    return x<0 ? x=-x : x;    }


inline int rnd15 (){    return rand()&id13;    }
inline int rnd16 (){    return rnd15() | (rnd15()&1)<<15;    }
inline int rnd31 (){    return rnd15()<<16 | rnd16();    }
inline int rnd32 (){    return rnd16()<<16 | rnd16();    }
inline u32 id15(){    return ((u32)rnd16())<<16 | ((u32)rnd16());      }
inline LL  rnd63 (){    return ((LL)rnd31())<<32 | ((LL)id15());       }
inline LL  rnd64 (){    return ((LL)id15())<<32 | ((LL)id15());      }
inline uLL id4(){    return ((uLL)id15())<<32 | ((uLL)id15());    }
inline int rnd   (){    return rnd31();     }
inline LL  lrnd  (){    return rnd63();     }
inline u32 urnd  (){    return id15();    }
inline uLL ullrnd(){    return id4();    }
inline DB  drnd  (){    return 1.0*lrnd()/id17;    }

inline int rnd(int L, int R){
	return L<0 ? int( lrnd()%((LL)R-L+1)+L ) : rnd()%(R-L+1)+L;
}
inline LL lrnd(LL L, LL R){
	return lrnd()%(R-L+1)+L;
}
inline DB drnd(DB L, DB R){
	return drnd()*(R-L)+L;
}

inline uLL MSK(int x){    return x==0 ? 0 : (1uLL<<x)-1;    }
inline int topbit  (const int &x){    return x==0 ? -1 : 31-__builtin_clz(x);    }
inline int topbit  (const LL  &x){    return x==0 ? -1 : 63-__builtin_clzll(x);    }
inline int botbit  (const int &x){    return x==0 ? 32 : __builtin_ffs(x)-1;    }
inline int botbit  (const LL  &x){    return x==0 ? 64 : __builtin_ffsll(x)-1;    }
inline int popcount(const int &x){    return __builtin_popcount(x);    }
inline int popcount(const LL  &x){    return __builtin_popcountll(x);    }
inline int lowbit  (const int &x){    return x&-x;    }
inline LL  lowbit  (const LL  &x){    return x&-x;    }
inline int highbit (const int &x){    return x==0 ? 0 : 1<<topbit(x);    }
inline LL  highbit (const LL  &x){    return x==0 ? 0 : 1LL<<topbit(x);    }
template<typename T> inline bool id7(const T &x){    return lowbit(x)==x;    }

template<typename T1, typename T2, typename T3>
inline bool inrange(const T1& a, const T2 &b, const T3 &c){
	return a<=b && b<=c;
}

inline int addMod(int, int, int);
inline int mulMod(int, int, int);
inline int subMod(int ,int, int);
template<typename T> T gcd(const T &a, const T &b){    return b==0 ? a : gcd(b,a%b);    }
template<typename T> T lcm(const T &a, const T &b){    return a/gcd(a,b)*b;    }

inline int id3(int, int, int);
template<typename T1, typename T2> inline T1 fpow(T1 x, T2 y){
	T1 mul=1;
	for(; y; y>>=1, x*=x) if(y&1) mul*=x;
	return mul;
}

template<typename T1, typename T2>
inline T1 cldiv(const T1 &x, const T2 &y){
	return (x+y-1)/y;
}
template<typename T1, typename T2>
inline T1 fldiv(const T1 &x, const T2 &y){
	return (x-y+1)/y;
}

inline char& to_upper(char &ch){    return ('a'<=ch && ch<='z') ? ch+='A'-'a' : ch;    }
inline char& to_lower(char &ch){    return ('A'<=ch && ch<='Z') ? ch+='a'-'A' : ch;    }
inline string& to_upper(string &s){
	for(char& ch : s) to_upper(ch);
	return s;
}
inline string& to_lower(string &s){
	for(char& ch : s) to_lower(ch);
	return s;
}
inline uLL Hash(const string &s, uLL base=233){
	uLL ret=0;
	for(const char& ch : s) ret=ret*base + ch;
	return ret;
}

inline char getch()
{
	static const int Buf=1048576;
	static char buf[Buf+1], *head=buf, *tail=buf;
	if(head==tail) *(tail= (head=buf) + fread(buf,1,Buf,stdin))=0;
	return *head++;
}

inline u32 id24()
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

inline uLL id16()
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


	inline LLL id0()
	{
		LLL ret=0; int sign=0; char ch=getch();
		while(ch!='-' && (ch<'0' || '9'<ch)) ch=getch();
		if(ch=='-') sign=1, ch=getch();
		while('0'<=ch && ch<='9') ret=(ret<<3) + (ret<<1) + ch-'0', ch=getch();
		if(sign) ret=-ret;
		return ret;
	}


inline char rdch()
{
	char ch=getch();
	while(ch<33 || 126<ch) ch=getch();
	return ch;
}

inline int  read()   {    return rdint();    }
inline u32  readu()  {    return id24();    }
inline LL   readll() {    return rdLL();     }
inline uLL  readull(){    return id16();    }
inline char readc()  {    return rdch();     }


	inline LLL readlll() {    return id0();    }



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
	for(const char& ch : s) putch(ch);
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


	inline void write(LLL x)
	{
		static int a[50],len=0,sign=0;
		if(x==0){ putch('0'); return; }
		len=0; sign= x<0 ? 1 : 0; toabs(x);
		while(x) a[++len]=x%10, x/=10;
		if(sign) putch('-');
		while(len) putch(a[len--]+'0');
	}


inline void flushbuf(){    putch(0,1);    }
inline void id2(){    putch('\n'); putch(0,1);    }
template<typename T> inline void writeln(T x)  {    write(x); putch('\n');    }
template<typename T> inline void id23(T x){    write(x); putch('\n'); putch(0,1);    }

const int USEFILE = 0;
const int id12 = 0;
const int id6 = 0;

const int Mod=1000000007;
const DB  eps=1e-10;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};

inline int addMod(int x, int y, int mod=Mod){    return x+y>=mod ? x+y-mod : x+y;    }
inline int mulMod(int x, int y, int mod=Mod){    return 1LL*x*y%mod;    }
inline int subMod(int x, int y, int mod=Mod){    return x-y<0 ? x-y+mod : x-y;    }

inline int id3(int x, int y, int mod=Mod)
{
	int mul=1;
	for(; y; y>>=1, x=mulMod(x,x,mod)) if(y&1) mul=mulMod(mul,x,mod);
	return mul;
}

inline bool dsame(DB x, DB y)
{
	return abs(x-y) < eps;
}

inline void usefile()
{
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
}

const int Maxn=100010;
const int Max=100000;
const int SZ=2000;

struct Query
{
	int l,r,k,t,id;
	Query(int l=0, int r=0, int k=0, int t=0, int id=0)
		:l(l),r(r),k(k),t(t),id(id){}
};

void INIT()
{
	
	return;
}

int id5()
{
	int n, m;
	cin>>n>>m;
	VI a(n,0);
	for(int i=0; i<n; i++) cin>>a[i];
	VI b(a);
	vector<Query> Q;
	vector<TIII > upd;
	for(int ty,l,r,k,p,v,i=1; i<=m; i++)
	{
		cin>>ty;
		if(ty==1)
		{
			cin>>l>>r>>k; l--; r--;
			Q.empb(l,r,k,upd.size(),Q.size());
		}
		else
		{
			cin>>p>>v; p--;
			upd.empb(p,a[p],v);
			a[p]=v;
		}
	}
	a=b;

	auto cmp = [=](const Query& a, const Query &b) -> bool
	{
		if(a.t/SZ != b.t/SZ) return a.t/SZ < b.t/SZ;
		if(a.l/SZ != b.l/SZ) return a.l/SZ < b.l/SZ;
		if(a.l/SZ & 1) return a.r<b.r;
		return b.r<a.r;
	};

	sort(Q.begin(), Q.end(), cmp);






	VI ord(Max+10,0), cnt(Max+10,0);
	vector<PII > bound(Max+10,PII(Max+1,Max));
	bound[0]=PII(1,Max);
	int L=0, R=-1, T=0;

	auto print = [&]() -> void
	{
		for(int i=1; i<=n; i++) if(bound[i].fst<=bound[i].sec) cout<<"lay: "<<i<<" "<<bound[i].fst<<":"<<bound[i].sec<<endl;
		for(int i=1; i<=n; i++) if(cnt[i]>0) cout<<i<<": "<<cnt[i]<<endl;
	};

	auto add = [&](int x) -> void
	{


		int tmp=cnt[x]; cnt[x]++;
		ord[bound[tmp].sec]++;
		bound[tmp+1].fst--;
		bound[tmp].sec--;


	};

	auto rmv = [&](int x) -> void
	{


		int tmp=cnt[x]; cnt[x]--;
		ord[bound[tmp].fst]--;
		bound[tmp-1].sec++;
		bound[tmp].fst++;


	};

	auto apply = [&](int indx, int flag) -> void
	{


		int pos=upd[indx].x;
		int nxt=flag ? upd[indx].z : upd[indx].y;


		if(inrange(L,pos,R))
		{
			rmv(a[pos]);
			add(nxt);
		}
		a[pos]=nxt;
	};

	VI ans(Q.size(),0);
	for(auto& q : Q)
	{
		int t=q.t, ll=q.l, rr=q.r, k=q.k;
		while(T<t) apply(T++, 1);
		while(T>t) apply(--T, 0);
		while(R<rr) add(a[++R]);
		while(L>ll) add(a[--L]);
		while(R>rr) rmv(a[R--]);
		while(L<ll) rmv(a[L++]);




		int res=Inf;
		for(int l=bound[ord[Max]].fst, r=bound[ord[Max]].sec, sum=(r-l+1); ord[r]>0; r=bound[ord[r]].fst-1)
		{
			sum=r-l+1;


			while(sum<k && ord[l-1]>0)
			{
				l=bound[ord[l-1]].fst;
				sum=(r-l+1);
			}


			if(sum>=k) chkmin(res,ord[r]-ord[l]);
		}


		if(res!=Inf) ans[q.id]=res;
		else ans[q.id]=-1;




	}

	for(int v : ans) cout<<v<<endl;

	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	srand((uLL)(new char));

	INIT();

	if(USEFILE) usefile();

	int T=id6 ? Inf : 1;
	if(id12) cin>>T;
	while(T-- && id5()==0);

	return 0;
}