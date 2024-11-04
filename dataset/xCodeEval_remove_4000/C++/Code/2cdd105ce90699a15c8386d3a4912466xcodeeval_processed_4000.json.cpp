
using namespace std;
 
 
 







































			  && id42(__builtin_popcountll)



			  && id42(__builtin_ctzll)













		  && !defined(DBZ_NO_MSVC_BUILTIN_BITSCANFORWARD64) 
























 

namespace sul
{

template<typename BLK = unsigned long long, typename ALC = std::allocator<BLK>>
class DBZ
{
	static_assert(std::is_unsigned<BLK>::value, "BLK is not an unsigned integral type");
 
public:
	typedef size_t size_type;
	typedef BLK id7;
	typedef ALC allocator_type;
	static constexpr size_type id6 = std::numeric_limits<id7>::digits;
	static constexpr size_type npos = std::numeric_limits<size_type>::max();
	class reference
	{
	public:
		constexpr reference(DBZ<BLK, ALC>& bitset, size_type bit_pos);
		constexpr reference(const reference&) noexcept = default;
		constexpr reference(reference&&) noexcept = default;
		~reference() noexcept = default;
		constexpr reference& operator=(bool v);
		constexpr reference& operator=(const reference& rhs);
		constexpr reference& operator=(reference&& rhs) noexcept;
		constexpr reference& operator&=(bool v);
		constexpr reference& operator|=(bool v);
		constexpr reference& operator^=(bool v);
		constexpr reference& operator-=(bool v);
		[[nodiscard]] constexpr bool operator~() const;
		[[nodiscard]] constexpr operator bool() const;
		constexpr void operator&() = delete;
		constexpr reference& set();
		constexpr reference& reset();
		constexpr reference& flip();
		constexpr reference& assign(bool v);
	private:
		id7& id8;
		id7 m_mask;
	};
	typedef bool const_reference;
	constexpr DBZ(const DBZ<BLK, ALC>& other) = default;
	constexpr DBZ(DBZ<BLK, ALC>&& other) noexcept = default;
	constexpr DBZ<BLK, ALC>& operator=(
	  const DBZ<BLK, ALC>& other) = default;
	constexpr DBZ<BLK, ALC>& operator=(
	  DBZ<BLK, ALC>&& other) noexcept = default;
	constexpr explicit DBZ(const allocator_type& allocator = allocator_type());
	constexpr explicit DBZ(size_type nbits,
	                                  unsigned long long init_val = 0,
	                                  const allocator_type& allocator = allocator_type());
	constexpr DBZ(std::initializer_list<id7> init_vals,
	                         const allocator_type& allocator = allocator_type());
	template<typename _CharT, typename _Traits>
	constexpr explicit DBZ(
	  std::basic_string_view<_CharT, _Traits> str,
	  typename std::basic_string_view<_CharT, _Traits>::size_type pos = 0,
	  typename std::basic_string_view<_CharT, _Traits>::size_type n =
	    std::basic_string_view<_CharT, _Traits>::npos,
	  _CharT zero = _CharT('0'),
	  _CharT one = _CharT('1'),
	  const allocator_type& allocator = allocator_type());
	template<typename _CharT, typename _Traits, typename _Alloc>
	constexpr explicit DBZ(
	  const std::basic_string<_CharT, _Traits, _Alloc>& str,
	  typename std::basic_string<_CharT, _Traits, _Alloc>::size_type pos = 0,
	  typename std::basic_string<_CharT, _Traits, _Alloc>::size_type n =
	    std::basic_string<_CharT, _Traits, _Alloc>::npos,
	  _CharT zero = _CharT('0'),
	  _CharT one = _CharT('1'),
	  const allocator_type& allocator = allocator_type());
	template<typename _CharT, typename _Traits = std::char_traits<_CharT>>
	constexpr explicit DBZ(
	  const _CharT* str,
	  typename std::basic_string<_CharT>::size_type pos = 0,
	  typename std::basic_string<_CharT>::size_type n = std::basic_string<_CharT>::npos,
	  _CharT zero = _CharT('0'),
	  _CharT one = _CharT('1'),
	  const allocator_type& allocator = allocator_type());
	~DBZ() noexcept = default;
	constexpr void resize(size_type nbits, bool value = false);
	constexpr void clear();
	constexpr void push_back(bool value);
	constexpr void pop_back();
	constexpr void append(id7 B_);
	constexpr void append(std::initializer_list<id7> B_s);
	template<typename BLKInputIterator>
	constexpr void append(BLKInputIterator first, BLKInputIterator last);
	constexpr DBZ<BLK, ALC>& operator&=(
	  const DBZ<BLK, ALC>& rhs);
	constexpr DBZ<BLK, ALC>& operator|=(
	  const DBZ<BLK, ALC>& rhs);
	constexpr DBZ<BLK, ALC>& operator^=(
	  const DBZ<BLK, ALC>& rhs);
	constexpr DBZ<BLK, ALC>& operator-=(
	  const DBZ<BLK, ALC>& rhs);
	constexpr DBZ<BLK, ALC>& operator<<=(size_type shift);
	constexpr DBZ<BLK, ALC>& operator>>=(size_type shift);
	[[nodiscard]] constexpr DBZ<BLK, ALC> operator<<(size_type shift) const;
	[[nodiscard]] constexpr DBZ<BLK, ALC> operator>>(size_type shift) const;
	[[nodiscard]] constexpr DBZ<BLK, ALC> operator~() const;
	constexpr DBZ<BLK, ALC>& set(size_type pos, size_type len, bool value);
	constexpr DBZ<BLK, ALC>& set(size_type pos, bool value = true);
	constexpr DBZ<BLK, ALC>& set();
	constexpr DBZ<BLK, ALC>& reset(size_type pos, size_type len);
	constexpr DBZ<BLK, ALC>& reset(size_type pos);
	constexpr DBZ<BLK, ALC>& reset();
	constexpr DBZ<BLK, ALC>& flip(size_type pos, size_type len);
	constexpr DBZ<BLK, ALC>& flip(size_type pos);
	constexpr DBZ<BLK, ALC>& flip();
	[[nodiscard]] constexpr bool test(size_type pos) const;
	[[nodiscard]] constexpr bool test_set(size_type pos, bool value = true);
	[[nodiscard]] constexpr bool all() const;
	[[nodiscard]] constexpr bool any() const;
	[[nodiscard]] constexpr bool none() const;
	[[nodiscard]] constexpr size_type count() const noexcept;
	[[nodiscard]] constexpr reference operator[](size_type pos);
	[[nodiscard]] constexpr const_reference operator[](size_type pos) const;
	[[nodiscard]] constexpr size_type size() const noexcept;
	[[nodiscard]] constexpr size_type num_B_s() const noexcept;
	[[nodiscard]] constexpr bool empty() const noexcept;
	[[nodiscard]] constexpr size_type capacity() const noexcept;
	constexpr void reserve(size_type num_bits);
	constexpr void shrink_to_fit();
	[[nodiscard]] constexpr bool is_subset_of(const DBZ<BLK, ALC>& bitset) const;
	[[nodiscard]] constexpr bool is_proper_subset_of(
	  const DBZ<BLK, ALC>& bitset) const;
	[[nodiscard]] constexpr bool intersects(const DBZ<BLK, ALC>& bitset) const;
	[[nodiscard]] constexpr size_type find_first() const;
	[[nodiscard]] constexpr size_type find_next(size_type prev) const;
	constexpr void swap(DBZ<BLK, ALC>& other);
	[[nodiscard]] constexpr allocator_type get_allocator() const;
	template<typename _CharT = char,
	         typename _Traits = std::char_traits<_CharT>,
	         typename _Alloc = std::allocator<_CharT>>
	[[nodiscard]] constexpr std::basic_string<_CharT, _Traits, _Alloc> to_string(
	  _CharT zero = _CharT('0'),
	  _CharT one = _CharT('1')) const;
	template<typename Function, typename... Parameters>
	constexpr void id31(Function&& function, Parameters&&... parameters) const;
	[[nodiscard]] constexpr id7* data() noexcept;
	[[nodiscard]] constexpr const id7* data() const noexcept;
	template<typename BLK_, typename ALC_>
	friend constexpr bool operator==(const DBZ<BLK_, ALC_>& lhs,
	                                 const DBZ<BLK_, ALC_>& rhs);
 
	template<typename BLK_, typename ALC_>
	friend constexpr bool operator<(const DBZ<BLK_, ALC_>& lhs,
	                                const DBZ<BLK_, ALC_>& rhs);
 
private:
	template<typename T>
	struct dependent_false : public std::false_type
	{
	};
 
	std::vector<BLK, ALC> m_B_s;
	size_type id28;
 
	static constexpr id7 zero_B_ = id7(0);
	static constexpr id7 id29 = id7(~zero_B_);
	static constexpr size_type id38 = id6 - 1;
 
	static constexpr size_type B_s_required(size_type nbits) noexcept;
 
	static constexpr size_type B__index(size_type pos) noexcept;
	static constexpr size_type bit_index(size_type pos) noexcept;
 
	static constexpr id7 bit_mask(size_type pos) noexcept;
	static constexpr id7 bit_mask(size_type first, size_type last) noexcept;
 
	static constexpr void set_B__bits(id7& B_,
	                                     size_type first,
	                                     size_type last,
	                                     bool val = true) noexcept;
	static constexpr void flip_B__bits(id7& B_,
	                                      size_type first,
	                                      size_type last) noexcept;
 
	static constexpr size_type B__count(const id7& B_) noexcept;
	static constexpr size_type B__count(const id7& B_, size_type nbits) noexcept;
 
	static constexpr size_type count_B__trailing_zero(const id7& B_) noexcept;
 
	template<typename _CharT, typename _Traits>
	constexpr void id20(std::basic_string_view<_CharT, _Traits> str,
	                                typename std::basic_string_view<_CharT, _Traits>::size_type pos,
	                                typename std::basic_string_view<_CharT, _Traits>::size_type n,
	                                _CharT zero,
	                                _CharT one);
 
	constexpr id7& get_B_(size_type pos);
	constexpr const id7& get_B_(size_type pos) const;
	constexpr id7& id41();
	constexpr id7 id41() const;
 
	

	constexpr size_type extra_bits_number() const noexcept;
	

	constexpr size_type unused_bits_number() const noexcept;
 
	template<typename BinaryOperation>
	constexpr void apply(const DBZ<BLK, ALC>& other, BinaryOperation binary_op);
	template<typename UnaryOperation>
	constexpr void apply(UnaryOperation id21);
	constexpr void apply_left_shift(size_type shift);
	constexpr void apply_right_shift(size_type shift);
 
	

	constexpr void sanitize();
 
	

	constexpr bool check_unused_bits() const noexcept;
	constexpr bool check_size() const noexcept;
	constexpr bool check_consistency() const noexcept;
};
 
template<typename integral_type, typename = std::enable_if_t<std::is_integral_v<integral_type>>>
DBZ(integral_type) -> DBZ<>;
template<typename BLK, typename ALC>
constexpr bool operator!=(const DBZ<BLK, ALC>& lhs,
                          const DBZ<BLK, ALC>& rhs);
template<typename BLK, typename ALC>
constexpr bool operator<=(const DBZ<BLK, ALC>& lhs,
                          const DBZ<BLK, ALC>& rhs);
 
template<typename BLK, typename ALC>
constexpr bool operator>(const DBZ<BLK, ALC>& lhs,
                         const DBZ<BLK, ALC>& rhs);
 
template<typename BLK, typename ALC>
constexpr bool operator>=(const DBZ<BLK, ALC>& lhs,
                          const DBZ<BLK, ALC>& rhs);
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC> operator&(const DBZ<BLK, ALC>& lhs,
                                                     const DBZ<BLK, ALC>& rhs);
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC> operator|(const DBZ<BLK, ALC>& lhs,
                                                     const DBZ<BLK, ALC>& rhs);
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC> operator^(const DBZ<BLK, ALC>& lhs,
                                                     const DBZ<BLK, ALC>& rhs);
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC> operator-(const DBZ<BLK, ALC>& lhs,
                                                     const DBZ<BLK, ALC>& rhs);
 
template<typename _CharT, typename _Traits, typename BLK, typename ALC>
constexpr std::basic_ostream<_CharT, _Traits>& operator<<(
  std::basic_ostream<_CharT, _Traits>& os,
  const DBZ<BLK, ALC>& bitset);
 
template<typename _CharT, typename _Traits, typename BLK, typename ALC>
constexpr std::basic_istream<_CharT, _Traits>& operator>>(std::basic_istream<_CharT, _Traits>& is,
                                                          DBZ<BLK, ALC>& bitset);
template<typename BLK, typename ALC>
constexpr void swap(DBZ<BLK, ALC>& id22,
                    DBZ<BLK, ALC>& id13);
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>::reference::reference(
  DBZ<BLK, ALC>& bitset,
  size_type bit_pos)
  : id8(bitset.get_B_(bit_pos)), m_mask(DBZ<BLK, ALC>::bit_mask(bit_pos))
{
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::reference& DBZ<BLK, ALC>::
  reference::operator=(bool v)
{
	assign(v);
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::reference& DBZ<BLK, ALC>::
  reference::operator=(const DBZ<BLK, ALC>::reference& rhs)
{
	assign(rhs);
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::reference& DBZ<BLK, ALC>::
  reference::operator=(DBZ::reference&& rhs) noexcept
{
	assign(rhs);
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::reference& DBZ<BLK, ALC>::
  reference::operator&=(bool v)
{
	if(!v)
	{
		reset();
	}
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::reference& DBZ<BLK, ALC>::
  reference::operator|=(bool v)
{
	if(v)
	{
		set();
	}
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::reference& DBZ<BLK, ALC>::
  reference::operator^=(bool v)
{
	if(v)
	{
		flip();
	}
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::reference& DBZ<BLK, ALC>::
  reference::operator-=(bool v)
{
	if(v)
	{
		reset();
	}
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr bool DBZ<BLK, ALC>::reference::operator~() const
{
	return (id8 & m_mask) == zero_B_;
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>::reference::operator bool() const
{
	return (id8 & m_mask) != zero_B_;
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::reference& DBZ<BLK, ALC>::
  reference::set()
{
	id8 |= m_mask;
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::reference& DBZ<BLK, ALC>::
  reference::reset()
{
	id8 &= ~m_mask;
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::reference& DBZ<BLK, ALC>::
  reference::flip()
{
	id8 ^= m_mask;
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::reference& DBZ<BLK, ALC>::
  reference::assign(bool v)
{
	if(v)
	{
		set();
	}
	else
	{
		reset();
	}
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>::DBZ(const allocator_type& allocator)
  : m_B_s(allocator), id28(0)
{
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>::DBZ(size_type nbits,
                                                           unsigned long long init_val,
                                                           const allocator_type& allocator)
  : m_B_s(B_s_required(nbits), allocator), id28(nbits)
{
	if(nbits == 0 || init_val == 0)
	{
		return;
	}
 
	constexpr size_t id39 = std::numeric_limits<unsigned long long>::digits;
	constexpr size_t id44 = id39 / id6;
	if constexpr(id44 == 1)
	{
		m_B_s[0] = init_val;
	}
	else
	{
		const unsigned long long id17 = static_cast<unsigned long long>(id29);
		const size_t id4 = std::min(m_B_s.size(), id44);
		for(size_t i = 0; i < id4; ++i)
		{
			m_B_s[i] = id7((init_val >> (i * id6) & id17));
		}
	}
	sanitize();
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>::DBZ(
  std::initializer_list<id7> init_vals,
  const allocator_type& allocator)
  : m_B_s(allocator), id28(0)
{
	append(init_vals);
}
 
template<typename BLK, typename ALC>
template<typename _CharT, typename _Traits>
constexpr DBZ<BLK, ALC>::DBZ(
  std::basic_string_view<_CharT, _Traits> str,
  typename std::basic_string_view<_CharT, _Traits>::size_type pos,
  typename std::basic_string_view<_CharT, _Traits>::size_type n,
  _CharT zero,
  _CharT one,
  const allocator_type& allocator)
  : m_B_s(allocator), id28(0)
{
	assert(pos < str.size());
	id20(str, pos, n, zero, one);
}
 
template<typename BLK, typename ALC>
template<typename _CharT, typename _Traits, typename _Alloc>
constexpr DBZ<BLK, ALC>::DBZ(
  const std::basic_string<_CharT, _Traits, _Alloc>& str,
  typename std::basic_string<_CharT, _Traits, _Alloc>::size_type pos,
  typename std::basic_string<_CharT, _Traits, _Alloc>::size_type n,
  _CharT zero,
  _CharT one,
  const allocator_type& allocator)
  : m_B_s(allocator), id28(0)
{
	assert(pos < str.size());
	id20(std::basic_string_view<_CharT, _Traits>(str), pos, n, zero, one);
}
 
template<typename BLK, typename ALC>
template<typename _CharT, typename _Traits>
constexpr DBZ<BLK, ALC>::DBZ(
  const _CharT* str,
  typename std::basic_string<_CharT>::size_type pos,
  typename std::basic_string<_CharT>::size_type n,
  _CharT zero,
  _CharT one,
  const allocator_type& allocator)
  : m_B_s(allocator), id28(0)
{
	id20(std::basic_string_view<_CharT, _Traits>(str), pos, n, zero, one);
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::resize(size_type nbits, bool value)
{
	if(nbits == id28)
	{
		return;
	}
 
	const size_type id16 = num_B_s();
	const size_type id43 = B_s_required(nbits);
 
	const id7 init_value = value ? id29 : zero_B_;
	if(id43 != id16)
	{
		m_B_s.resize(id43, init_value);
	}
 
	if(value && nbits > id28 && id16 > 0)
	{
		

		const size_type extra_bits = extra_bits_number();
		if(extra_bits > 0)
		{
			m_B_s[id16 - 1] |= (init_value << extra_bits);
		}
	}
 
	id28 = nbits;
	sanitize();
	assert(check_consistency());
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::clear()
{
	m_B_s.clear();
	id28 = 0;
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::push_back(bool value)
{
	const size_type id23 = id28++;
	if(id28 <= m_B_s.size() * id6)
	{
		if(value)
		{
			set(id23, value);
		}
	}
	else
	{
		m_B_s.push_back(id7(value));
	}
	assert(operator[](id23) == value);
	assert(check_consistency());
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::pop_back()
{
	if(empty())
	{
		return;
	}
 
	--id28;
	if(m_B_s.size() > B_s_required(id28))
	{
		m_B_s.pop_back();
		

		assert(extra_bits_number() == 0);
	}
	else
	{
		sanitize();
	}
	assert(check_consistency());
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::append(id7 B_)
{
	const size_type extra_bits = extra_bits_number();
	if(extra_bits == 0)
	{
		m_B_s.push_back(B_);
	}
	else
	{
		id41() |= (B_ << extra_bits);
		m_B_s.push_back(id7(B_ >> (id6 - extra_bits)));
	}
 
	id28 += id6;
	assert(check_consistency());
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::append(std::initializer_list<id7> B_s)
{
	if(B_s.size() == 0)
	{
		return;
	}
 
	append(std::cbegin(B_s), std::cend(B_s));
}
 
template<typename BLK, typename ALC>
template<typename BLKInputIterator>
constexpr void DBZ<BLK, ALC>::append(BLKInputIterator first,
                                                        BLKInputIterator last)
{
	if(first == last)
	{
		return;
	}
 
	

	if constexpr(std::is_same_v<
	               typename std::iterator_traits<BLKInputIterator>::iterator_category,
	               std::random_access_iterator_tag>)
	{
		assert(std::distance(first, last) > 0);
		m_B_s.reserve(m_B_s.size() + static_cast<size_type>(std::distance(first, last)));
	}
 
	const size_type extra_bits = extra_bits_number();
	const size_type unused_bits = unused_bits_number();
	if(extra_bits == 0)
	{
		auto pos = m_B_s.insert(std::end(m_B_s), first, last);
		assert(std::distance(pos, std::end(m_B_s)) > 0);
		id28 +=
		  static_cast<size_type>(std::distance(pos, std::end(m_B_s))) * id6;
	}
	else
	{
		id41() |= (*first << extra_bits);
		id7 B_ = id7(*first >> unused_bits);
		++first;
		while(first != last)
		{
			B_ |= (*first << extra_bits);
			m_B_s.push_back(B_);
			id28 += id6;
			B_ = id7(*first >> unused_bits);
			++first;
		}
		m_B_s.push_back(B_);
		id28 += id6;
	}
 
	assert(check_consistency());
}
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>& DBZ<BLK, ALC>::operator&=(
  const DBZ<BLK, ALC>& rhs)
{
	assert(size() == rhs.size());
	

	for(size_type i = 0; i < m_B_s.size(); ++i)
	{
		m_B_s[i] &= rhs.m_B_s[i];
	}
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>& DBZ<BLK, ALC>::operator|=(
  const DBZ<BLK, ALC>& rhs)
{
	assert(size() == rhs.size());
	

	for(size_type i = 0; i < m_B_s.size(); ++i)
	{
		m_B_s[i] |= rhs.m_B_s[i];
	}
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>& DBZ<BLK, ALC>::operator^=(
  const DBZ<BLK, ALC>& rhs)
{
	assert(size() == rhs.size());
	

	for(size_type i = 0; i < m_B_s.size(); ++i)
	{
		m_B_s[i] ^= rhs.m_B_s[i];
	}
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>& DBZ<BLK, ALC>::operator-=(
  const DBZ<BLK, ALC>& rhs)
{
	assert(size() == rhs.size());
	

	for(size_type i = 0; i < m_B_s.size(); ++i)
	{
		m_B_s[i] &= ~rhs.m_B_s[i];
	}
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>& DBZ<BLK, ALC>::operator<<=(
  size_type shift)
{
	if(shift != 0)
	{
		if(shift >= id28)
		{
			reset();
		}
		else
		{
			apply_left_shift(shift);
			sanitize(); 

		}
	}
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>& DBZ<BLK, ALC>::operator>>=(
  size_type shift)
{
	if(shift != 0)
	{
		if(shift >= id28)
		{
			reset();
		}
		else
		{
			apply_right_shift(shift);
		}
	}
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC> DBZ<BLK, ALC>::operator<<(
  size_type shift) const
{
	return DBZ<BLK, ALC>(*this) <<= shift;
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC> DBZ<BLK, ALC>::operator>>(
  size_type shift) const
{
	return DBZ<BLK, ALC>(*this) >>= shift;
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC> DBZ<BLK, ALC>::operator~() const
{
	DBZ<BLK, ALC> bitset(*this);
	bitset.flip();
	return bitset;
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>& DBZ<BLK, ALC>::set(size_type pos,
                                                                                  size_type len,
                                                                                  bool value)
{
	assert(pos < size());
	if(len == 0)
	{
		return *this;
	}
	assert(pos + len - 1 < size());
 
	const size_type id12 = B__index(pos);
	const size_type id41 = B__index(pos + len - 1);
	const size_type id18 = bit_index(pos);
	const size_type id1 = bit_index(pos + len - 1);
 
	if(id12 == id41)
	{
		set_B__bits(m_B_s[id12], id18, id1, value);
	}
	else
	{
		size_type id24 = id12;
		size_type id25 = id41;
 
		if(id18 != 0)
		{
			++id24; 

			set_B__bits(m_B_s[id12], id18, id38, value);
		}
 
		if(id1 != id38)
		{
			--id25; 

			set_B__bits(m_B_s[id41], 0, id1, value);
		}
 
		const id7 id35 = value ? id29 : zero_B_;
		for(size_type i = id24; i <= id25; ++i)
		{
			m_B_s[i] = id35;
		}
	}
 
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>& DBZ<BLK, ALC>::set(size_type pos,
                                                                                  bool value)
{
	assert(pos < size());
 
	if(value)
	{
		m_B_s[B__index(pos)] |= bit_mask(pos);
	}
	else
	{
		m_B_s[B__index(pos)] &= ~bit_mask(pos);
	}
 
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>& DBZ<BLK, ALC>::set()
{
	std::fill(std::begin(m_B_s), std::end(m_B_s), id29);
	sanitize();
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>& DBZ<BLK, ALC>::reset(size_type pos,
                                                                                    size_type len)
{
	return set(pos, len, false);
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>& DBZ<BLK, ALC>::reset(size_type pos)
{
	return set(pos, false);
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>& DBZ<BLK, ALC>::reset()
{
	std::fill(std::begin(m_B_s), std::end(m_B_s), zero_B_);
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>& DBZ<BLK, ALC>::flip(size_type pos,
                                                                                   size_type len)
{
	assert(pos < size());
	if(len == 0)
	{
		return *this;
	}
	assert(pos + len - 1 < size());
 
	const size_type id12 = B__index(pos);
	const size_type id41 = B__index(pos + len - 1);
	const size_type id18 = bit_index(pos);
	const size_type id1 = bit_index(pos + len - 1);
 
	if(id12 == id41)
	{
		flip_B__bits(m_B_s[id12], id18, id1);
	}
	else
	{
		size_type id24 = id12;
		size_type id25 = id41;
 
		if(id18 != 0)
		{
			++id24; 

			flip_B__bits(m_B_s[id12], id18, id38);
		}
 
		if(id1 != id38)
		{
			--id25; 

			flip_B__bits(m_B_s[id41], 0, id1);
		}
 
		for(size_type i = id24; i <= id25; ++i)
		{
			m_B_s[i] = id7(~m_B_s[i]);
		}
	}
 
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>& DBZ<BLK, ALC>::flip(size_type pos)
{
	assert(pos < size());
	m_B_s[B__index(pos)] ^= bit_mask(pos);
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>& DBZ<BLK, ALC>::flip()
{
	std::transform(
	  std::cbegin(m_B_s), std::cend(m_B_s), std::begin(m_B_s), std::bit_not<id7>());
	sanitize();
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr bool DBZ<BLK, ALC>::test(size_type pos) const
{
	assert(pos < size());
	return (m_B_s[B__index(pos)] & bit_mask(pos)) != zero_B_;
}
 
template<typename BLK, typename ALC>
constexpr bool DBZ<BLK, ALC>::test_set(size_type pos, bool value)
{
	bool const result = test(pos);
	if(result != value)
	{
		set(pos, value);
	}
	return result;
}
 
template<typename BLK, typename ALC>
constexpr bool DBZ<BLK, ALC>::all() const
{
	if(empty())
	{
		return true;
	}
 
	const id7 id35 = id29;
	if(extra_bits_number() == 0)
	{
		for(const id7& B_: m_B_s)
		{
			if(B_ != id35)
			{
				return false;
			}
		}
	}
	else
	{
		for(size_type i = 0; i < m_B_s.size() - 1; ++i)
		{
			if(m_B_s[i] != id35)
			{
				return false;
			}
		}
		if(id41() != (id35 >> unused_bits_number()))
		{
			return false;
		}
	}
	return true;
}
 
template<typename BLK, typename ALC>
constexpr bool DBZ<BLK, ALC>::any() const
{
	for(const id7& B_: m_B_s)
	{
		if(B_ != zero_B_)
		{
			return true;
		}
	}
	return false;
}
 
template<typename BLK, typename ALC>
constexpr bool DBZ<BLK, ALC>::none() const
{
	return !any();
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::size_type DBZ<BLK,
                                                                              ALC>::count()
  const noexcept
{
	if(empty())
	{
		return 0;
	}
 

	const size_type count =
	  static_cast<size_type>(popcnt(m_B_s.data(), m_B_s.size() * sizeof(id7)));

	size_type count = 0;
 
	

	for(size_type i = 0; i < m_B_s.size() - 1; ++i)
	{
		count += B__count(m_B_s[i]);
	}
 
	

	const id7& B_ = id41();
	const size_type extra_bits = extra_bits_number();
	if(extra_bits == 0)
	{
		count += B__count(B_);
	}
	else
	{
		count += B__count(B_, extra_bits);
	}

	return count;
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::reference DBZ<BLK, ALC>::
operator[](size_type pos)
{
	assert(pos < size());
	return DBZ<BLK, ALC>::reference(*this, pos);
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::const_reference DBZ<
  BLK,
  ALC>::operator[](size_type pos) const
{
	return test(pos);
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::size_type DBZ<BLK,
                                                                              ALC>::size()
  const noexcept
{
	return id28;
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::size_type DBZ<BLK, ALC>::
  num_B_s() const noexcept
{
	return m_B_s.size();
}
 
template<typename BLK, typename ALC>
constexpr bool DBZ<BLK, ALC>::empty() const noexcept
{
	return size() == 0;
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::size_type DBZ<BLK,
                                                                              ALC>::capacity()
  const noexcept
{
	return m_B_s.capacity() * id6;
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::reserve(size_type num_bits)
{
	m_B_s.reserve(B_s_required(num_bits));
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::shrink_to_fit()
{
	m_B_s.shrink_to_fit();
}
 
template<typename BLK, typename ALC>
constexpr bool DBZ<BLK, ALC>::is_subset_of(
  const DBZ<BLK, ALC>& bitset) const
{
	assert(size() == bitset.size());
	for(size_type i = 0; i < m_B_s.size(); ++i)
	{
		if((m_B_s[i] & ~bitset.m_B_s[i]) != zero_B_)
		{
			return false;
		}
	}
	return true;
}
 
template<typename BLK, typename ALC>
constexpr bool DBZ<BLK, ALC>::is_proper_subset_of(
  const DBZ<BLK, ALC>& bitset) const
{
	assert(size() == bitset.size());
	bool id36 = false;
	for(size_type i = 0; i < m_B_s.size(); ++i)
	{
		const id7& id15 = m_B_s[i];
		const id7& id34 = bitset.m_B_s[i];
 
		if((id15 & ~id34) != zero_B_)
		{
			return false;
		}
		if((~id15 & id34) != zero_B_)
		{
			id36 = true;
		}
	}
	return id36;
}
 
template<typename BLK, typename ALC>
constexpr bool DBZ<BLK, ALC>::intersects(
  const DBZ<BLK, ALC>& bitset) const
{
	const size_type id2 = std::min(m_B_s.size(), bitset.m_B_s.size());
	for(size_type i = 0; i < id2; ++i)
	{
		if((m_B_s[i] & bitset.m_B_s[i]) != zero_B_)
		{
			return true;
		}
	}
	return false;
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::size_type DBZ<BLK, ALC>::
  find_first() const
{
	for(size_type i = 0; i < m_B_s.size(); ++i)
	{
		if(m_B_s[i] != zero_B_)
		{
			return i * id6 + count_B__trailing_zero(m_B_s[i]);
		}
	}
	return npos;
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::size_type DBZ<BLK, ALC>::
  find_next(size_type prev) const
{
	if(empty() || prev >= (size() - 1))
	{
		return npos;
	}
 
	const size_type first_bit = prev + 1;
	const size_type id12 = B__index(first_bit);
	const size_type id18 = bit_index(first_bit);
	const id7 id30 = id7(m_B_s[id12] >> id18);
 
	if(id30 != zero_B_)
	{
		return first_bit + count_B__trailing_zero(id30);
	}
	else
	{
		for(size_type i = id12 + 1; i < m_B_s.size(); ++i)
		{
			if(m_B_s[i] != zero_B_)
			{
				return i * id6 + count_B__trailing_zero(m_B_s[i]);
			}
		}
	}
	return npos;
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::swap(DBZ<BLK, ALC>& other)
{
	std::swap(m_B_s, other.m_B_s);
	std::swap(id28, other.id28);
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::allocator_type DBZ<
  BLK,
  ALC>::get_allocator() const
{
	return m_B_s.get_allocator();
}
 
template<typename BLK, typename ALC>
template<typename _CharT, typename _Traits, typename _Alloc>
constexpr std::basic_string<_CharT, _Traits, _Alloc> DBZ<BLK, ALC>::to_string(
  _CharT zero,
  _CharT one) const
{
	const size_type len = size();
	std::basic_string<_CharT, _Traits, _Alloc> str(len, zero);
	for(size_type id32 = 0; id32 < m_B_s.size(); ++id32)
	{
		if(m_B_s[id32] == zero_B_)
		{
			continue;
		}
		id7 mask = id7(1);
		const size_type limit =
		  id32 * id6 < len ? len - id32 * id6 : id6;
		for(size_type i_bit = 0; i_bit < limit; ++i_bit)
		{
			if((m_B_s[id32] & mask) != zero_B_)
			{
				_Traits::assign(str[len - (id32 * id6 + i_bit + 1)], one);
			}
			mask <<= 1;
		}
	}
	return str;
}
 
template<typename BLK, typename ALC>
template<typename Function, typename... Parameters>
constexpr void DBZ<BLK, ALC>::id31(Function&& function,
                                                                 Parameters&&... parameters) const
{
	if constexpr(!std::is_invocable_v<Function, size_t, Parameters...>)
	{
		static_assert(dependent_false<Function>::value, "Function take invalid arguments");
		

	}
 
	if constexpr(std::is_same_v<std::invoke_result_t<Function, size_t, Parameters...>, void>)
	{
		size_type i_bit = find_first();
		while(i_bit != npos)
		{
			std::invoke(
			  std::forward<Function>(function), i_bit, std::forward<Parameters>(parameters)...);
			i_bit = find_next(i_bit);
		}
	}
	else if constexpr(std::is_convertible_v<std::invoke_result_t<Function, size_t, Parameters...>,
	                                        bool>)
	{
		size_type i_bit = find_first();
		while(i_bit != npos)
		{
			if(!std::invoke(
			     std::forward<Function>(function), i_bit, std::forward<Parameters>(parameters)...))
			{
				break;
			}
			i_bit = find_next(i_bit);
		}
	}
	else
	{
		static_assert(dependent_false<Function>::value, "Function have invalid return type");
		

	}
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::id7* DBZ<BLK, ALC>::
  data() noexcept
{
	return m_B_s.data();
}
 
template<typename BLK, typename ALC>
constexpr const typename DBZ<BLK, ALC>::id7* DBZ<
  BLK,
  ALC>::data() const noexcept
{
	return m_B_s.data();
}
 
template<typename BLK_, typename ALC_>
[[nodiscard]] constexpr bool operator==(const DBZ<BLK_, ALC_>& lhs,
                                        const DBZ<BLK_, ALC_>& rhs)
{
	return (lhs.id28 == rhs.id28) && (lhs.m_B_s == rhs.m_B_s);
}
 
template<typename BLK_, typename ALC_>
[[nodiscard]] constexpr bool operator<(const DBZ<BLK_, ALC_>& lhs,
                                       const DBZ<BLK_, ALC_>& rhs)
{
	using size_type = typename DBZ<BLK_, ALC_>::size_type;
	using id7 = typename DBZ<BLK_, ALC_>::id7;
	const size_type lhs_size = lhs.size();
	const size_type rhs_size = rhs.size();
	const size_type id14 = lhs.m_B_s.size();
	const size_type id45 = rhs.m_B_s.size();
 
	if(lhs_size == rhs_size)
	{
		

		if(lhs_size == 0)
		{
			return false;
		}
 
		for(size_type i = id14 - 1; i > 0; --i)
		{
			if(lhs.m_B_s[i] != rhs.m_B_s[i])
			{
				return lhs.m_B_s[i] < rhs.m_B_s[i];
			}
		}
		return lhs.m_B_s[0] < rhs.m_B_s[0];
	}
 
	

	if(lhs_size == 0)
	{
		return true;
	}
	if(rhs_size == 0)
	{
		return false;
	}
 
	const bool id33 = rhs_size > lhs_size;
	const DBZ<BLK_, ALC_>& id5 = id33 ? rhs : lhs;
	const size_type id11 = std::max(id14, id45);
	const size_type id37 = std::min(id14, id45);
	for(size_type i = id11 - 1; i >= id37; --i)
	{
		if(id5.m_B_s[i] != id7(0))
		{
			return id33;
		}
	}
 
	for(size_type i = id37 - 1; i > 0; --i)
	{
		if(lhs.m_B_s[i] != rhs.m_B_s[i])
		{
			return lhs.m_B_s[i] < rhs.m_B_s[i];
		}
	}
	if(lhs.m_B_s[0] != rhs.m_B_s[0])
	{
		return lhs.m_B_s[0] < rhs.m_B_s[0];
	}
	return lhs_size < rhs_size;
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::size_type DBZ<BLK, ALC>::
  B_s_required(size_type nbits) noexcept
{
	return nbits / id6 + static_cast<size_type>(nbits % id6 > 0);
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::size_type DBZ<BLK, ALC>::
  B__index(size_type pos) noexcept
{
	return pos / id6;
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::size_type DBZ<BLK, ALC>::
  bit_index(size_type pos) noexcept
{
	return pos % id6;
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::id7 DBZ<BLK, ALC>::
  bit_mask(size_type pos) noexcept
{
	return id7(id7(1) << bit_index(pos));
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::id7 DBZ<BLK, ALC>::
  bit_mask(size_type first, size_type last) noexcept
{
	first = bit_index(first);
	last = bit_index(last);
	if(last == (id38))
	{
		return id7(id29 << first);
	}
	else
	{
		return id7(((id7(1) << (last + 1)) - 1) ^ ((id7(1) << first) - 1));
	}
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::set_B__bits(id7& B_,
                                                                size_type first,
                                                                size_type last,
                                                                bool val) noexcept
{
	if(val)
	{
		B_ |= bit_mask(first, last);
	}
	else
	{
		B_ &= ~bit_mask(first, last);
	}
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::flip_B__bits(id7& B_,
                                                                 size_type first,
                                                                 size_type last) noexcept
{
	B_ ^= bit_mask(first, last);
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::size_type DBZ<BLK, ALC>::
  B__count(const id7& B_) noexcept
{

	return static_cast<size_type>(std::popcount(B_));

	if(B_ == zero_B_)
	{
		return 0;
	}
 

	constexpr size_t id40 = std::numeric_limits<unsigned>::digits;
	constexpr size_t id26 = std::numeric_limits<unsigned long>::digits;
	constexpr size_t id39 = std::numeric_limits<unsigned long long>::digits;
	if constexpr(id6 <= id40)
	{
		return static_cast<size_type>(__builtin_popcount(static_cast<unsigned int>(B_)));
	}
	else if constexpr(id6 <= id26)
	{
		return static_cast<size_type>(__builtin_popcountl(static_cast<unsigned long>(B_)));
	}
	else if constexpr(id6 <= id39)
	{
		return static_cast<size_type>(__builtin_popcountll(static_cast<unsigned long long>(B_)));
	}

 
	size_type count = 0;
	id7 mask = 1;
	for(size_type bit_index = 0; bit_index < id6; ++bit_index)
	{
		count += static_cast<size_type>((B_ & mask) != zero_B_);
		mask <<= 1;
	}
	return count;

}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::size_type DBZ<BLK, ALC>::
  B__count(const id7& B_, size_type nbits) noexcept
{
	assert(nbits <= id6);

	const id7 id27 = id7(B_ << (id6 - nbits));
	return static_cast<size_type>(std::popcount(id27));

	const id7 id27 = id7(B_ << (id6 - nbits));
	if(id27 == zero_B_)
	{
		return 0;
	}
 

	constexpr size_t id40 = std::numeric_limits<unsigned>::digits;
	constexpr size_t id26 = std::numeric_limits<unsigned long>::digits;
	constexpr size_t id39 = std::numeric_limits<unsigned long long>::digits;
	if constexpr(id6 <= id40)
	{
		return static_cast<size_type>(__builtin_popcount(static_cast<unsigned int>(id27)));
	}
	else if constexpr(id6 <= id26)
	{
		return static_cast<size_type>(
		  __builtin_popcountl(static_cast<unsigned long>(id27)));
	}
	else if constexpr(id6 <= id39)
	{
		return static_cast<size_type>(
		  __builtin_popcountll(static_cast<unsigned long long>(id27)));
	}

 
	size_type count = 0;
	id7 mask = 1;
	for(size_type bit_index = 0; bit_index < nbits; ++bit_index)
	{
		count += static_cast<size_type>((B_ & mask) != zero_B_);
		mask <<= 1;
	}
 
	return count;

}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::size_type DBZ<BLK, ALC>::
  count_B__trailing_zero(const id7& B_) noexcept
{
	assert(B_ != zero_B_);

	return static_cast<size_type>(std::countr_zero(B_));


	constexpr size_t id40 = std::numeric_limits<unsigned>::digits;
	constexpr size_t id26 = std::numeric_limits<unsigned long>::digits;
	constexpr size_t id39 = std::numeric_limits<unsigned long long>::digits;
	if constexpr(id6 <= id40)
	{
		return static_cast<size_type>(__builtin_ctz(static_cast<unsigned int>(B_)));
	}
	else if constexpr(id6 <= id26)
	{
		return static_cast<size_type>(__builtin_ctzl(static_cast<unsigned long>(B_)));
	}
	else if constexpr(id6 <= id39)
	{
		return static_cast<size_type>(__builtin_ctzll(static_cast<unsigned long long>(B_)));
	}
 

	constexpr size_t id26 = std::numeric_limits<unsigned long>::digits;
	constexpr size_t id3 = std::numeric_limits<unsigned __int64>::digits;
	if constexpr(id6 <= id26)
	{
		unsigned long index = std::numeric_limits<unsigned long>::max();
		_BitScanForward(&index, static_cast<unsigned long>(B_));
		return static_cast<size_type>(index);
	}
	else if constexpr(id6 <= id3)
	{

		unsigned long index = std::numeric_limits<unsigned long>::max();
		_BitScanForward64(&index, static_cast<unsigned __int64>(B_));
		return static_cast<size_type>(index);

		constexpr unsigned long max_ul = std::numeric_limits<unsigned long>::max();
		unsigned long low = B_ & max_ul;
		if(low != 0)
		{
			unsigned long index = std::numeric_limits<unsigned long>::max();
			_BitScanForward(&index, low);
			return static_cast<size_type>(index);
		}
		unsigned long high = B_ >> id26;
		unsigned long index = std::numeric_limits<unsigned long>::max();
		_BitScanForward(&index, high);
		return static_cast<size_type>(id26 + index);

	}

 
	id7 mask = id7(1);
	for(size_type i = 0; i < id6; ++i)
	{
		if((B_ & mask) != zero_B_)
		{
			return i;
		}
		mask <<= 1;
	}
	assert(false); 

	return npos; 


}
 
template<typename BLK, typename ALC>
template<typename _CharT, typename _Traits>
constexpr void DBZ<BLK, ALC>::id20(
  std::basic_string_view<_CharT, _Traits> str,
  typename std::basic_string_view<_CharT, _Traits>::size_type pos,
  typename std::basic_string_view<_CharT, _Traits>::size_type n,
  [[maybe_unused]] _CharT zero,
  _CharT one)
{
	assert(pos < str.size());
 
	const size_type size = std::min(n, str.size() - pos);
	id28 = size;
 
	m_B_s.clear();
	m_B_s.resize(B_s_required(size));
	for(size_t i = 0; i < size; ++i)
	{
		const _CharT c = str[(pos + size - 1) - i];
		assert(c == zero || c == one);
		if(c == one)
		{
			set(i);
		}
	}
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::id7& DBZ<BLK, ALC>::
  get_B_(size_type pos)
{
	return m_B_s[B__index(pos)];
}
 
template<typename BLK, typename ALC>
constexpr const typename DBZ<BLK, ALC>::id7& DBZ<
  BLK,
  ALC>::get_B_(size_type pos) const
{
	return m_B_s[B__index(pos)];
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::id7& DBZ<BLK, ALC>::
  id41()
{
	return m_B_s[m_B_s.size() - 1];
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::id7 DBZ<BLK, ALC>::
  id41() const
{
	return m_B_s[m_B_s.size() - 1];
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::size_type DBZ<BLK, ALC>::
  extra_bits_number() const noexcept
{
	return bit_index(id28);
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::size_type DBZ<BLK, ALC>::
  unused_bits_number() const noexcept
{
	return id6 - extra_bits_number();
}
 
template<typename BLK, typename ALC>
template<typename BinaryOperation>
constexpr void DBZ<BLK, ALC>::apply(
  const DBZ<BLK, ALC>& other,
  BinaryOperation binary_op)
{
	assert(num_B_s() == other.num_B_s());
	std::transform(std::cbegin(m_B_s),
	               std::cend(m_B_s),
	               std::cbegin(other.m_B_s),
	               std::begin(m_B_s),
	               binary_op);
}
 
template<typename BLK, typename ALC>
template<typename UnaryOperation>
constexpr void DBZ<BLK, ALC>::apply(UnaryOperation id21)
{
	std::transform(std::cbegin(m_B_s), std::cend(m_B_s), std::begin(m_B_s), id21);
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::apply_left_shift(size_type shift)
{
	assert(shift > 0);
	assert(shift < capacity());
 
	const size_type id9 = shift / id6;
	const size_type bits_offset = shift % id6;
 
	if(bits_offset == 0)
	{
		for(size_type i = m_B_s.size() - 1; i >= id9; --i)
		{
			m_B_s[i] = m_B_s[i - id9];
		}
	}
	else
	{
		const size_type id19 = id6 - bits_offset;
		for(size_type i = m_B_s.size() - 1; i > id9; --i)
		{
			m_B_s[i] =
			  id7((m_B_s[i - id9] << bits_offset)
			             | id7(m_B_s[i - id9 - 1] >> id19));
		}
		m_B_s[id9] = id7(m_B_s[0] << bits_offset);
	}
 
	

	std::fill(std::begin(m_B_s),
	          std::begin(m_B_s)
	            + static_cast<typename decltype(m_B_s)::difference_type>(id9),
	          zero_B_);
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::apply_right_shift(size_type shift)
{
	assert(shift > 0);
	assert(shift < capacity());
 
	const size_type id9 = shift / id6;
	const size_type bits_offset = shift % id6;
	const size_type id0 = m_B_s.size() - id9 - 1;
 
	if(bits_offset == 0)
	{
		for(size_type i = 0; i <= id0; ++i)
		{
			m_B_s[i] = m_B_s[i + id9];
		}
	}
	else
	{
		const size_type id19 = id6 - bits_offset;
		for(size_type i = 0; i < id0; ++i)
		{
			m_B_s[i] =
			  id7((m_B_s[i + id9] >> bits_offset)
			             | id7(m_B_s[i + id9 + 1] << id19));
		}
		m_B_s[id0] = id7(m_B_s[m_B_s.size() - 1] >> bits_offset);
	}
 
	

	std::fill(
	  std::begin(m_B_s)
	    + static_cast<typename decltype(m_B_s)::difference_type>(id0 + 1),
	  std::end(m_B_s),
	  zero_B_);
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::sanitize()
{
	size_type shift = id28 % id6;
	if(shift > 0)
	{
		id41() &= ~(id29 << shift);
	}
}
 
template<typename BLK, typename ALC>
constexpr bool DBZ<BLK, ALC>::check_unused_bits() const noexcept
{
	const size_type extra_bits = extra_bits_number();
	if(extra_bits > 0)
	{
		return (id41() & (id29 << extra_bits)) == zero_B_;
	}
	return true;
}
 
template<typename BLK, typename ALC>
constexpr bool DBZ<BLK, ALC>::check_size() const noexcept
{
	return B_s_required(size()) == m_B_s.size();
}
 
template<typename BLK, typename ALC>
constexpr bool DBZ<BLK, ALC>::check_consistency() const noexcept
{
	return check_unused_bits() && check_size();
}
 
template<typename BLK, typename ALC>
constexpr bool operator!=(const DBZ<BLK, ALC>& lhs,
                          const DBZ<BLK, ALC>& rhs)
{
	return !(lhs == rhs);
}
 
template<typename BLK, typename ALC>
constexpr bool operator<=(const DBZ<BLK, ALC>& lhs,
                          const DBZ<BLK, ALC>& rhs)
{
	return !(rhs < lhs);
}
 
template<typename BLK, typename ALC>
constexpr bool operator>(const DBZ<BLK, ALC>& lhs,
                         const DBZ<BLK, ALC>& rhs)
{
	return rhs < lhs;
}
 
template<typename BLK, typename ALC>
constexpr bool operator>=(const DBZ<BLK, ALC>& lhs,
                          const DBZ<BLK, ALC>& rhs)
{
	return !(lhs < rhs);
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC> operator&(const DBZ<BLK, ALC>& lhs,
                                                     const DBZ<BLK, ALC>& rhs)
{
	DBZ<BLK, ALC> result(lhs);
	return result &= rhs;
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC> operator|(const DBZ<BLK, ALC>& lhs,
                                                     const DBZ<BLK, ALC>& rhs)
{
	DBZ<BLK, ALC> result(lhs);
	return result |= rhs;
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC> operator^(const DBZ<BLK, ALC>& lhs,
                                                     const DBZ<BLK, ALC>& rhs)
{
	DBZ<BLK, ALC> result(lhs);
	return result ^= rhs;
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC> operator-(const DBZ<BLK, ALC>& lhs,
                                                     const DBZ<BLK, ALC>& rhs)
{
	DBZ<BLK, ALC> result(lhs);
	return result -= rhs;
}
 
template<typename _CharT, typename _Traits, typename BLK, typename ALC>
constexpr std::basic_ostream<_CharT, _Traits>& operator<<(
  std::basic_ostream<_CharT, _Traits>& os,
  const DBZ<BLK, ALC>& bitset)
{
	

	return os << bitset.template to_string<_CharT, _Traits>();
}
 
template<typename _CharT, typename _Traits, typename BLK, typename ALC>
constexpr std::basic_istream<_CharT, _Traits>& operator>>(std::basic_istream<_CharT, _Traits>& is,
                                                          DBZ<BLK, ALC>& bitset)
{
	

	constexpr _CharT zero = _CharT('0');
	constexpr _CharT one = _CharT('1');
	typename std::basic_istream<_CharT, _Traits>::sentry s(is);
	if(!s)
	{
		return is;
	}
 
	DBZ<BLK, ALC> id10;
	_CharT val;
	is.get(val);
	while(is.good())
	{
		if(val == one)
		{
			id10.push_back(true);
		}
		else if(val == zero)
		{
			id10.push_back(false);
		}
		else
		{
			is.unget();
			break;
		}
		is.get(val);
	}
 
	bitset.clear();
	if(!id10.empty())
	{
		for(typename DBZ<BLK, ALC>::size_type i = id10.size() - 1;
		    i > 0;
		    --i)
		{
			bitset.push_back(id10.test(i));
		}
		bitset.push_back(id10.test(0));
	}
 
	return is;
}
 
template<typename BLK, typename ALC>
constexpr void swap(DBZ<BLK, ALC>& id22,
                    DBZ<BLK, ALC>& id13)
{
	id22.swap(id13);
}
 

} 


 


 
using fbs = sul::DBZ<>;
void solution() {
    char c='z';
    string s;
    cin>>s;
    int pos=0;
    for (int i=0;i<s.size();i++) if (s[i]<c){
        c=s[i];
        pos=i;
    }
    s.erase(pos,1);
    cout<<c<<" "<<s;
  }
signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0); int tc = 1;

  freopen("input.txt", "r", stdin);

  cin >> tc;
  for (int test = 1; test <= tc; test ++) {
    solution(); cout << "\n";
  }
}