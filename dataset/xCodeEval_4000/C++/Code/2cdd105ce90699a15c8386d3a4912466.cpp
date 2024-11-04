#include "bits/stdc++.h"
using namespace std;
 
 
 
#ifndef SUL_DBZ_HPP
#define SUL_DBZ_HPP
#define SUL_DBZ_VERSION_MAJOR 1
#define SUL_DBZ_VERSION_MINOR 2
#define SUL_DBZ_VERSION_PATCH 1
#include <memory>
#include <vector>
#include <algorithm>
#include <string>
#include <string_view>
#include <functional>
#include <type_traits>
#include <limits>
#include <cmath>
#include <cassert>
#if !defined(DBZ_NO_LIBPOPCNT)
#	if __has_include(<libpopcnt.h>)
#		include <libpopcnt.h>
#		define DBZ_CAN_USE_LIBPOPCNT true
#	endif
#endif
#if !defined(DBZ_CAN_USE_LIBPOPCNT)
#	define DBZ_CAN_USE_LIBPOPCNT false
#endif
#if !defined(DBZ_NO_STD_BITOPS)
#	if __has_include(<bit>)
#		include <bit>
#		ifdef __cpp_lib_bitops
#			define DBZ_CAN_USE_STD_BITOPS true
#		endif
#	endif
#endif
#if !defined(DBZ_CAN_USE_STD_BITOPS)
#	define DBZ_CAN_USE_STD_BITOPS false
#endif
#if !DBZ_CAN_USE_STD_BITOPS && !defined(DBZ_NO_COMPILER_BUILTIN)
#	if defined(__clang__)
#		ifdef __has_builtin
#			if __has_builtin(__builtin_popcount) && __has_builtin(__builtin_popcountl) \
			  && __has_builtin(__builtin_popcountll)
#				define DBZ_CAN_USE_CLANG_BUILTIN_POPCOUNT true
#			endif
#			if __has_builtin(__builtin_ctz) && __has_builtin(__builtin_ctzl) \
			  && __has_builtin(__builtin_ctzll)
#				define DBZ_CAN_USE_CLANG_BUILTIN_CTZ true
#			endif
#		endif
#	elif defined(__GNUC__) 

#		define DBZ_CAN_USE_GCC_BUILTIN true
#	elif defined(_MSC_VER)
#		if defined(_M_IX86) || defined(_M_ARM) || defined(_M_X64) || defined(_M_ARM64)
#			include <intrin.h>
#			pragma intrinsic(_BitScanForward)
#			define DBZ_CAN_USE_MSVC_BUILTIN_BITSCANFORWARD true
#		endif
#		if(defined(_M_X64) || defined(_M_ARM64)) \
		  && !defined(DBZ_NO_MSVC_BUILTIN_BITSCANFORWARD64) 

#			pragma intrinsic(_BitScanForward64)
#			define DBZ_CAN_USE_MSVC_BUILTIN_BITSCANFORWARD64 true
#		endif
#	endif
#endif
#if !defined(DBZ_CAN_USE_CLANG_BUILTIN_POPCOUNT)
#	define DBZ_CAN_USE_CLANG_BUILTIN_POPCOUNT false
#endif
#if !defined(DBZ_CAN_USE_CLANG_BUILTIN_CTZ)
#	define DBZ_CAN_USE_CLANG_BUILTIN_CTZ false
#endif
#if !defined(DBZ_CAN_USE_GCC_BUILTIN)
#	define DBZ_CAN_USE_GCC_BUILTIN false
#endif
#if !defined(DBZ_CAN_USE_MSVC_BUILTIN_BITSCANFORWARD)
#	define DBZ_CAN_USE_MSVC_BUILTIN_BITSCANFORWARD false
#endif
#if !defined(DBZ_CAN_USE_MSVC_BUILTIN_BITSCANFORWARD64)
#	define DBZ_CAN_USE_MSVC_BUILTIN_BITSCANFORWARD64 false
#endif
#if !defined(DBZ_CAN_USE_MSVC_BUILTIN)
#	define DBZ_CAN_USE_MSVC_BUILTIN false
#endif
 
#ifndef DBZ_NO_NAMESPACE
namespace sul
{
#endif
template<typename BLK = unsigned long long, typename ALC = std::allocator<BLK>>
class DBZ
{
	static_assert(std::is_unsigned<BLK>::value, "BLK is not an unsigned integral type");
 
public:
	typedef size_t size_type;
	typedef BLK B__type;
	typedef ALC allocator_type;
	static constexpr size_type bits_per_B_ = std::numeric_limits<B__type>::digits;
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
		B__type& m_B_;
		B__type m_mask;
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
	constexpr DBZ(std::initializer_list<B__type> init_vals,
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
	constexpr void append(B__type B_);
	constexpr void append(std::initializer_list<B__type> B_s);
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
	constexpr void iterate_bits_on(Function&& function, Parameters&&... parameters) const;
	[[nodiscard]] constexpr B__type* data() noexcept;
	[[nodiscard]] constexpr const B__type* data() const noexcept;
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
	size_type m_bits_number;
 
	static constexpr B__type zero_B_ = B__type(0);
	static constexpr B__type one_B_ = B__type(~zero_B_);
	static constexpr size_type B__last_bit_index = bits_per_B_ - 1;
 
	static constexpr size_type B_s_required(size_type nbits) noexcept;
 
	static constexpr size_type B__index(size_type pos) noexcept;
	static constexpr size_type bit_index(size_type pos) noexcept;
 
	static constexpr B__type bit_mask(size_type pos) noexcept;
	static constexpr B__type bit_mask(size_type first, size_type last) noexcept;
 
	static constexpr void set_B__bits(B__type& B_,
	                                     size_type first,
	                                     size_type last,
	                                     bool val = true) noexcept;
	static constexpr void flip_B__bits(B__type& B_,
	                                      size_type first,
	                                      size_type last) noexcept;
 
	static constexpr size_type B__count(const B__type& B_) noexcept;
	static constexpr size_type B__count(const B__type& B_, size_type nbits) noexcept;
 
	static constexpr size_type count_B__trailing_zero(const B__type& B_) noexcept;
 
	template<typename _CharT, typename _Traits>
	constexpr void init_from_string(std::basic_string_view<_CharT, _Traits> str,
	                                typename std::basic_string_view<_CharT, _Traits>::size_type pos,
	                                typename std::basic_string_view<_CharT, _Traits>::size_type n,
	                                _CharT zero,
	                                _CharT one);
 
	constexpr B__type& get_B_(size_type pos);
	constexpr const B__type& get_B_(size_type pos) const;
	constexpr B__type& last_B_();
	constexpr B__type last_B_() const;
 
	

	constexpr size_type extra_bits_number() const noexcept;
	

	constexpr size_type unused_bits_number() const noexcept;
 
	template<typename BinaryOperation>
	constexpr void apply(const DBZ<BLK, ALC>& other, BinaryOperation binary_op);
	template<typename UnaryOperation>
	constexpr void apply(UnaryOperation unary_op);
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
constexpr void swap(DBZ<BLK, ALC>& bitset1,
                    DBZ<BLK, ALC>& bitset2);
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>::reference::reference(
  DBZ<BLK, ALC>& bitset,
  size_type bit_pos)
  : m_B_(bitset.get_B_(bit_pos)), m_mask(DBZ<BLK, ALC>::bit_mask(bit_pos))
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
	return (m_B_ & m_mask) == zero_B_;
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>::reference::operator bool() const
{
	return (m_B_ & m_mask) != zero_B_;
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::reference& DBZ<BLK, ALC>::
  reference::set()
{
	m_B_ |= m_mask;
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::reference& DBZ<BLK, ALC>::
  reference::reset()
{
	m_B_ &= ~m_mask;
	return *this;
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::reference& DBZ<BLK, ALC>::
  reference::flip()
{
	m_B_ ^= m_mask;
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
  : m_B_s(allocator), m_bits_number(0)
{
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>::DBZ(size_type nbits,
                                                           unsigned long long init_val,
                                                           const allocator_type& allocator)
  : m_B_s(B_s_required(nbits), allocator), m_bits_number(nbits)
{
	if(nbits == 0 || init_val == 0)
	{
		return;
	}
 
	constexpr size_t ull_bits_number = std::numeric_limits<unsigned long long>::digits;
	constexpr size_t init_val_required_B_s = ull_bits_number / bits_per_B_;
	if constexpr(init_val_required_B_s == 1)
	{
		m_B_s[0] = init_val;
	}
	else
	{
		const unsigned long long B__mask = static_cast<unsigned long long>(one_B_);
		const size_t B_s_to_init = std::min(m_B_s.size(), init_val_required_B_s);
		for(size_t i = 0; i < B_s_to_init; ++i)
		{
			m_B_s[i] = B__type((init_val >> (i * bits_per_B_) & B__mask));
		}
	}
	sanitize();
}
 
template<typename BLK, typename ALC>
constexpr DBZ<BLK, ALC>::DBZ(
  std::initializer_list<B__type> init_vals,
  const allocator_type& allocator)
  : m_B_s(allocator), m_bits_number(0)
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
  : m_B_s(allocator), m_bits_number(0)
{
	assert(pos < str.size());
	init_from_string(str, pos, n, zero, one);
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
  : m_B_s(allocator), m_bits_number(0)
{
	assert(pos < str.size());
	init_from_string(std::basic_string_view<_CharT, _Traits>(str), pos, n, zero, one);
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
  : m_B_s(allocator), m_bits_number(0)
{
	init_from_string(std::basic_string_view<_CharT, _Traits>(str), pos, n, zero, one);
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::resize(size_type nbits, bool value)
{
	if(nbits == m_bits_number)
	{
		return;
	}
 
	const size_type old_num_B_s = num_B_s();
	const size_type new_num_B_s = B_s_required(nbits);
 
	const B__type init_value = value ? one_B_ : zero_B_;
	if(new_num_B_s != old_num_B_s)
	{
		m_B_s.resize(new_num_B_s, init_value);
	}
 
	if(value && nbits > m_bits_number && old_num_B_s > 0)
	{
		

		const size_type extra_bits = extra_bits_number();
		if(extra_bits > 0)
		{
			m_B_s[old_num_B_s - 1] |= (init_value << extra_bits);
		}
	}
 
	m_bits_number = nbits;
	sanitize();
	assert(check_consistency());
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::clear()
{
	m_B_s.clear();
	m_bits_number = 0;
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::push_back(bool value)
{
	const size_type new_last_bit = m_bits_number++;
	if(m_bits_number <= m_B_s.size() * bits_per_B_)
	{
		if(value)
		{
			set(new_last_bit, value);
		}
	}
	else
	{
		m_B_s.push_back(B__type(value));
	}
	assert(operator[](new_last_bit) == value);
	assert(check_consistency());
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::pop_back()
{
	if(empty())
	{
		return;
	}
 
	--m_bits_number;
	if(m_B_s.size() > B_s_required(m_bits_number))
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
constexpr void DBZ<BLK, ALC>::append(B__type B_)
{
	const size_type extra_bits = extra_bits_number();
	if(extra_bits == 0)
	{
		m_B_s.push_back(B_);
	}
	else
	{
		last_B_() |= (B_ << extra_bits);
		m_B_s.push_back(B__type(B_ >> (bits_per_B_ - extra_bits)));
	}
 
	m_bits_number += bits_per_B_;
	assert(check_consistency());
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::append(std::initializer_list<B__type> B_s)
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
		m_bits_number +=
		  static_cast<size_type>(std::distance(pos, std::end(m_B_s))) * bits_per_B_;
	}
	else
	{
		last_B_() |= (*first << extra_bits);
		B__type B_ = B__type(*first >> unused_bits);
		++first;
		while(first != last)
		{
			B_ |= (*first << extra_bits);
			m_B_s.push_back(B_);
			m_bits_number += bits_per_B_;
			B_ = B__type(*first >> unused_bits);
			++first;
		}
		m_B_s.push_back(B_);
		m_bits_number += bits_per_B_;
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
		if(shift >= m_bits_number)
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
		if(shift >= m_bits_number)
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
 
	const size_type first_B_ = B__index(pos);
	const size_type last_B_ = B__index(pos + len - 1);
	const size_type first_bit_index = bit_index(pos);
	const size_type last_bit_index = bit_index(pos + len - 1);
 
	if(first_B_ == last_B_)
	{
		set_B__bits(m_B_s[first_B_], first_bit_index, last_bit_index, value);
	}
	else
	{
		size_type first_full_B_ = first_B_;
		size_type last_full_B_ = last_B_;
 
		if(first_bit_index != 0)
		{
			++first_full_B_; 

			set_B__bits(m_B_s[first_B_], first_bit_index, B__last_bit_index, value);
		}
 
		if(last_bit_index != B__last_bit_index)
		{
			--last_full_B_; 

			set_B__bits(m_B_s[last_B_], 0, last_bit_index, value);
		}
 
		const B__type full_B_ = value ? one_B_ : zero_B_;
		for(size_type i = first_full_B_; i <= last_full_B_; ++i)
		{
			m_B_s[i] = full_B_;
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
	std::fill(std::begin(m_B_s), std::end(m_B_s), one_B_);
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
 
	const size_type first_B_ = B__index(pos);
	const size_type last_B_ = B__index(pos + len - 1);
	const size_type first_bit_index = bit_index(pos);
	const size_type last_bit_index = bit_index(pos + len - 1);
 
	if(first_B_ == last_B_)
	{
		flip_B__bits(m_B_s[first_B_], first_bit_index, last_bit_index);
	}
	else
	{
		size_type first_full_B_ = first_B_;
		size_type last_full_B_ = last_B_;
 
		if(first_bit_index != 0)
		{
			++first_full_B_; 

			flip_B__bits(m_B_s[first_B_], first_bit_index, B__last_bit_index);
		}
 
		if(last_bit_index != B__last_bit_index)
		{
			--last_full_B_; 

			flip_B__bits(m_B_s[last_B_], 0, last_bit_index);
		}
 
		for(size_type i = first_full_B_; i <= last_full_B_; ++i)
		{
			m_B_s[i] = B__type(~m_B_s[i]);
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
	  std::cbegin(m_B_s), std::cend(m_B_s), std::begin(m_B_s), std::bit_not<B__type>());
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
 
	const B__type full_B_ = one_B_;
	if(extra_bits_number() == 0)
	{
		for(const B__type& B_: m_B_s)
		{
			if(B_ != full_B_)
			{
				return false;
			}
		}
	}
	else
	{
		for(size_type i = 0; i < m_B_s.size() - 1; ++i)
		{
			if(m_B_s[i] != full_B_)
			{
				return false;
			}
		}
		if(last_B_() != (full_B_ >> unused_bits_number()))
		{
			return false;
		}
	}
	return true;
}
 
template<typename BLK, typename ALC>
constexpr bool DBZ<BLK, ALC>::any() const
{
	for(const B__type& B_: m_B_s)
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
 
#if DBZ_CAN_USE_LIBPOPCNT
	const size_type count =
	  static_cast<size_type>(popcnt(m_B_s.data(), m_B_s.size() * sizeof(B__type)));
#else
	size_type count = 0;
 
	

	for(size_type i = 0; i < m_B_s.size() - 1; ++i)
	{
		count += B__count(m_B_s[i]);
	}
 
	

	const B__type& B_ = last_B_();
	const size_type extra_bits = extra_bits_number();
	if(extra_bits == 0)
	{
		count += B__count(B_);
	}
	else
	{
		count += B__count(B_, extra_bits);
	}
#endif
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
	return m_bits_number;
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
	return m_B_s.capacity() * bits_per_B_;
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
	bool is_proper = false;
	for(size_type i = 0; i < m_B_s.size(); ++i)
	{
		const B__type& self_B_ = m_B_s[i];
		const B__type& other_B_ = bitset.m_B_s[i];
 
		if((self_B_ & ~other_B_) != zero_B_)
		{
			return false;
		}
		if((~self_B_ & other_B_) != zero_B_)
		{
			is_proper = true;
		}
	}
	return is_proper;
}
 
template<typename BLK, typename ALC>
constexpr bool DBZ<BLK, ALC>::intersects(
  const DBZ<BLK, ALC>& bitset) const
{
	const size_type min_B_s_number = std::min(m_B_s.size(), bitset.m_B_s.size());
	for(size_type i = 0; i < min_B_s_number; ++i)
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
			return i * bits_per_B_ + count_B__trailing_zero(m_B_s[i]);
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
	const size_type first_B_ = B__index(first_bit);
	const size_type first_bit_index = bit_index(first_bit);
	const B__type first_B__shifted = B__type(m_B_s[first_B_] >> first_bit_index);
 
	if(first_B__shifted != zero_B_)
	{
		return first_bit + count_B__trailing_zero(first_B__shifted);
	}
	else
	{
		for(size_type i = first_B_ + 1; i < m_B_s.size(); ++i)
		{
			if(m_B_s[i] != zero_B_)
			{
				return i * bits_per_B_ + count_B__trailing_zero(m_B_s[i]);
			}
		}
	}
	return npos;
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::swap(DBZ<BLK, ALC>& other)
{
	std::swap(m_B_s, other.m_B_s);
	std::swap(m_bits_number, other.m_bits_number);
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
	for(size_type i_B_ = 0; i_B_ < m_B_s.size(); ++i_B_)
	{
		if(m_B_s[i_B_] == zero_B_)
		{
			continue;
		}
		B__type mask = B__type(1);
		const size_type limit =
		  i_B_ * bits_per_B_ < len ? len - i_B_ * bits_per_B_ : bits_per_B_;
		for(size_type i_bit = 0; i_bit < limit; ++i_bit)
		{
			if((m_B_s[i_B_] & mask) != zero_B_)
			{
				_Traits::assign(str[len - (i_B_ * bits_per_B_ + i_bit + 1)], one);
			}
			mask <<= 1;
		}
	}
	return str;
}
 
template<typename BLK, typename ALC>
template<typename Function, typename... Parameters>
constexpr void DBZ<BLK, ALC>::iterate_bits_on(Function&& function,
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
constexpr typename DBZ<BLK, ALC>::B__type* DBZ<BLK, ALC>::
  data() noexcept
{
	return m_B_s.data();
}
 
template<typename BLK, typename ALC>
constexpr const typename DBZ<BLK, ALC>::B__type* DBZ<
  BLK,
  ALC>::data() const noexcept
{
	return m_B_s.data();
}
 
template<typename BLK_, typename ALC_>
[[nodiscard]] constexpr bool operator==(const DBZ<BLK_, ALC_>& lhs,
                                        const DBZ<BLK_, ALC_>& rhs)
{
	return (lhs.m_bits_number == rhs.m_bits_number) && (lhs.m_B_s == rhs.m_B_s);
}
 
template<typename BLK_, typename ALC_>
[[nodiscard]] constexpr bool operator<(const DBZ<BLK_, ALC_>& lhs,
                                       const DBZ<BLK_, ALC_>& rhs)
{
	using size_type = typename DBZ<BLK_, ALC_>::size_type;
	using B__type = typename DBZ<BLK_, ALC_>::B__type;
	const size_type lhs_size = lhs.size();
	const size_type rhs_size = rhs.size();
	const size_type lhs_B_s_size = lhs.m_B_s.size();
	const size_type rhs_B_s_size = rhs.m_B_s.size();
 
	if(lhs_size == rhs_size)
	{
		

		if(lhs_size == 0)
		{
			return false;
		}
 
		for(size_type i = lhs_B_s_size - 1; i > 0; --i)
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
 
	const bool rhs_longer = rhs_size > lhs_size;
	const DBZ<BLK_, ALC_>& longest_bitset = rhs_longer ? rhs : lhs;
	const size_type longest_B_s_size = std::max(lhs_B_s_size, rhs_B_s_size);
	const size_type shortest_B_s_size = std::min(lhs_B_s_size, rhs_B_s_size);
	for(size_type i = longest_B_s_size - 1; i >= shortest_B_s_size; --i)
	{
		if(longest_bitset.m_B_s[i] != B__type(0))
		{
			return rhs_longer;
		}
	}
 
	for(size_type i = shortest_B_s_size - 1; i > 0; --i)
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
	return nbits / bits_per_B_ + static_cast<size_type>(nbits % bits_per_B_ > 0);
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::size_type DBZ<BLK, ALC>::
  B__index(size_type pos) noexcept
{
	return pos / bits_per_B_;
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::size_type DBZ<BLK, ALC>::
  bit_index(size_type pos) noexcept
{
	return pos % bits_per_B_;
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::B__type DBZ<BLK, ALC>::
  bit_mask(size_type pos) noexcept
{
	return B__type(B__type(1) << bit_index(pos));
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::B__type DBZ<BLK, ALC>::
  bit_mask(size_type first, size_type last) noexcept
{
	first = bit_index(first);
	last = bit_index(last);
	if(last == (B__last_bit_index))
	{
		return B__type(one_B_ << first);
	}
	else
	{
		return B__type(((B__type(1) << (last + 1)) - 1) ^ ((B__type(1) << first) - 1));
	}
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::set_B__bits(B__type& B_,
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
constexpr void DBZ<BLK, ALC>::flip_B__bits(B__type& B_,
                                                                 size_type first,
                                                                 size_type last) noexcept
{
	B_ ^= bit_mask(first, last);
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::size_type DBZ<BLK, ALC>::
  B__count(const B__type& B_) noexcept
{
#if DBZ_CAN_USE_STD_BITOPS
	return static_cast<size_type>(std::popcount(B_));
#else
	if(B_ == zero_B_)
	{
		return 0;
	}
 
#	if DBZ_CAN_USE_GCC_BUILTIN || DBZ_CAN_USE_CLANG_BUILTIN_POPCOUNT
	constexpr size_t u_bits_number = std::numeric_limits<unsigned>::digits;
	constexpr size_t ul_bits_number = std::numeric_limits<unsigned long>::digits;
	constexpr size_t ull_bits_number = std::numeric_limits<unsigned long long>::digits;
	if constexpr(bits_per_B_ <= u_bits_number)
	{
		return static_cast<size_type>(__builtin_popcount(static_cast<unsigned int>(B_)));
	}
	else if constexpr(bits_per_B_ <= ul_bits_number)
	{
		return static_cast<size_type>(__builtin_popcountl(static_cast<unsigned long>(B_)));
	}
	else if constexpr(bits_per_B_ <= ull_bits_number)
	{
		return static_cast<size_type>(__builtin_popcountll(static_cast<unsigned long long>(B_)));
	}
#	endif
 
	size_type count = 0;
	B__type mask = 1;
	for(size_type bit_index = 0; bit_index < bits_per_B_; ++bit_index)
	{
		count += static_cast<size_type>((B_ & mask) != zero_B_);
		mask <<= 1;
	}
	return count;
#endif
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::size_type DBZ<BLK, ALC>::
  B__count(const B__type& B_, size_type nbits) noexcept
{
	assert(nbits <= bits_per_B_);
#if DBZ_CAN_USE_STD_BITOPS
	const B__type shifted_B_ = B__type(B_ << (bits_per_B_ - nbits));
	return static_cast<size_type>(std::popcount(shifted_B_));
#else
	const B__type shifted_B_ = B__type(B_ << (bits_per_B_ - nbits));
	if(shifted_B_ == zero_B_)
	{
		return 0;
	}
 
#	if DBZ_CAN_USE_GCC_BUILTIN || DBZ_CAN_USE_CLANG_BUILTIN_POPCOUNT
	constexpr size_t u_bits_number = std::numeric_limits<unsigned>::digits;
	constexpr size_t ul_bits_number = std::numeric_limits<unsigned long>::digits;
	constexpr size_t ull_bits_number = std::numeric_limits<unsigned long long>::digits;
	if constexpr(bits_per_B_ <= u_bits_number)
	{
		return static_cast<size_type>(__builtin_popcount(static_cast<unsigned int>(shifted_B_)));
	}
	else if constexpr(bits_per_B_ <= ul_bits_number)
	{
		return static_cast<size_type>(
		  __builtin_popcountl(static_cast<unsigned long>(shifted_B_)));
	}
	else if constexpr(bits_per_B_ <= ull_bits_number)
	{
		return static_cast<size_type>(
		  __builtin_popcountll(static_cast<unsigned long long>(shifted_B_)));
	}
#	endif
 
	size_type count = 0;
	B__type mask = 1;
	for(size_type bit_index = 0; bit_index < nbits; ++bit_index)
	{
		count += static_cast<size_type>((B_ & mask) != zero_B_);
		mask <<= 1;
	}
 
	return count;
#endif
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::size_type DBZ<BLK, ALC>::
  count_B__trailing_zero(const B__type& B_) noexcept
{
	assert(B_ != zero_B_);
#if DBZ_CAN_USE_STD_BITOPS
	return static_cast<size_type>(std::countr_zero(B_));
#else
#	if DBZ_CAN_USE_GCC_BUILTIN || DBZ_CAN_USE_CLANG_BUILTIN_CTZ
	constexpr size_t u_bits_number = std::numeric_limits<unsigned>::digits;
	constexpr size_t ul_bits_number = std::numeric_limits<unsigned long>::digits;
	constexpr size_t ull_bits_number = std::numeric_limits<unsigned long long>::digits;
	if constexpr(bits_per_B_ <= u_bits_number)
	{
		return static_cast<size_type>(__builtin_ctz(static_cast<unsigned int>(B_)));
	}
	else if constexpr(bits_per_B_ <= ul_bits_number)
	{
		return static_cast<size_type>(__builtin_ctzl(static_cast<unsigned long>(B_)));
	}
	else if constexpr(bits_per_B_ <= ull_bits_number)
	{
		return static_cast<size_type>(__builtin_ctzll(static_cast<unsigned long long>(B_)));
	}
 
#	elif DBZ_CAN_USE_MSVC_BUILTIN_BITSCANFORWARD
	constexpr size_t ul_bits_number = std::numeric_limits<unsigned long>::digits;
	constexpr size_t ui64_bits_number = std::numeric_limits<unsigned __int64>::digits;
	if constexpr(bits_per_B_ <= ul_bits_number)
	{
		unsigned long index = std::numeric_limits<unsigned long>::max();
		_BitScanForward(&index, static_cast<unsigned long>(B_));
		return static_cast<size_type>(index);
	}
	else if constexpr(bits_per_B_ <= ui64_bits_number)
	{
#		if DBZ_CAN_USE_MSVC_BUILTIN_BITSCANFORWARD64
		unsigned long index = std::numeric_limits<unsigned long>::max();
		_BitScanForward64(&index, static_cast<unsigned __int64>(B_));
		return static_cast<size_type>(index);
#		else
		constexpr unsigned long max_ul = std::numeric_limits<unsigned long>::max();
		unsigned long low = B_ & max_ul;
		if(low != 0)
		{
			unsigned long index = std::numeric_limits<unsigned long>::max();
			_BitScanForward(&index, low);
			return static_cast<size_type>(index);
		}
		unsigned long high = B_ >> ul_bits_number;
		unsigned long index = std::numeric_limits<unsigned long>::max();
		_BitScanForward(&index, high);
		return static_cast<size_type>(ul_bits_number + index);
#		endif
	}
#	endif
 
	B__type mask = B__type(1);
	for(size_type i = 0; i < bits_per_B_; ++i)
	{
		if((B_ & mask) != zero_B_)
		{
			return i;
		}
		mask <<= 1;
	}
	assert(false); 

	return npos; 

#endif
}
 
template<typename BLK, typename ALC>
template<typename _CharT, typename _Traits>
constexpr void DBZ<BLK, ALC>::init_from_string(
  std::basic_string_view<_CharT, _Traits> str,
  typename std::basic_string_view<_CharT, _Traits>::size_type pos,
  typename std::basic_string_view<_CharT, _Traits>::size_type n,
  [[maybe_unused]] _CharT zero,
  _CharT one)
{
	assert(pos < str.size());
 
	const size_type size = std::min(n, str.size() - pos);
	m_bits_number = size;
 
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
constexpr typename DBZ<BLK, ALC>::B__type& DBZ<BLK, ALC>::
  get_B_(size_type pos)
{
	return m_B_s[B__index(pos)];
}
 
template<typename BLK, typename ALC>
constexpr const typename DBZ<BLK, ALC>::B__type& DBZ<
  BLK,
  ALC>::get_B_(size_type pos) const
{
	return m_B_s[B__index(pos)];
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::B__type& DBZ<BLK, ALC>::
  last_B_()
{
	return m_B_s[m_B_s.size() - 1];
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::B__type DBZ<BLK, ALC>::
  last_B_() const
{
	return m_B_s[m_B_s.size() - 1];
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::size_type DBZ<BLK, ALC>::
  extra_bits_number() const noexcept
{
	return bit_index(m_bits_number);
}
 
template<typename BLK, typename ALC>
constexpr typename DBZ<BLK, ALC>::size_type DBZ<BLK, ALC>::
  unused_bits_number() const noexcept
{
	return bits_per_B_ - extra_bits_number();
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
constexpr void DBZ<BLK, ALC>::apply(UnaryOperation unary_op)
{
	std::transform(std::cbegin(m_B_s), std::cend(m_B_s), std::begin(m_B_s), unary_op);
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::apply_left_shift(size_type shift)
{
	assert(shift > 0);
	assert(shift < capacity());
 
	const size_type B_s_shift = shift / bits_per_B_;
	const size_type bits_offset = shift % bits_per_B_;
 
	if(bits_offset == 0)
	{
		for(size_type i = m_B_s.size() - 1; i >= B_s_shift; --i)
		{
			m_B_s[i] = m_B_s[i - B_s_shift];
		}
	}
	else
	{
		const size_type reverse_bits_offset = bits_per_B_ - bits_offset;
		for(size_type i = m_B_s.size() - 1; i > B_s_shift; --i)
		{
			m_B_s[i] =
			  B__type((m_B_s[i - B_s_shift] << bits_offset)
			             | B__type(m_B_s[i - B_s_shift - 1] >> reverse_bits_offset));
		}
		m_B_s[B_s_shift] = B__type(m_B_s[0] << bits_offset);
	}
 
	

	std::fill(std::begin(m_B_s),
	          std::begin(m_B_s)
	            + static_cast<typename decltype(m_B_s)::difference_type>(B_s_shift),
	          zero_B_);
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::apply_right_shift(size_type shift)
{
	assert(shift > 0);
	assert(shift < capacity());
 
	const size_type B_s_shift = shift / bits_per_B_;
	const size_type bits_offset = shift % bits_per_B_;
	const size_type last_B__to_shift = m_B_s.size() - B_s_shift - 1;
 
	if(bits_offset == 0)
	{
		for(size_type i = 0; i <= last_B__to_shift; ++i)
		{
			m_B_s[i] = m_B_s[i + B_s_shift];
		}
	}
	else
	{
		const size_type reverse_bits_offset = bits_per_B_ - bits_offset;
		for(size_type i = 0; i < last_B__to_shift; ++i)
		{
			m_B_s[i] =
			  B__type((m_B_s[i + B_s_shift] >> bits_offset)
			             | B__type(m_B_s[i + B_s_shift + 1] << reverse_bits_offset));
		}
		m_B_s[last_B__to_shift] = B__type(m_B_s[m_B_s.size() - 1] >> bits_offset);
	}
 
	

	std::fill(
	  std::begin(m_B_s)
	    + static_cast<typename decltype(m_B_s)::difference_type>(last_B__to_shift + 1),
	  std::end(m_B_s),
	  zero_B_);
}
 
template<typename BLK, typename ALC>
constexpr void DBZ<BLK, ALC>::sanitize()
{
	size_type shift = m_bits_number % bits_per_B_;
	if(shift > 0)
	{
		last_B_() &= ~(one_B_ << shift);
	}
}
 
template<typename BLK, typename ALC>
constexpr bool DBZ<BLK, ALC>::check_unused_bits() const noexcept
{
	const size_type extra_bits = extra_bits_number();
	if(extra_bits > 0)
	{
		return (last_B_() & (one_B_ << extra_bits)) == zero_B_;
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
 
	DBZ<BLK, ALC> reverse_bitset;
	_CharT val;
	is.get(val);
	while(is.good())
	{
		if(val == one)
		{
			reverse_bitset.push_back(true);
		}
		else if(val == zero)
		{
			reverse_bitset.push_back(false);
		}
		else
		{
			is.unget();
			break;
		}
		is.get(val);
	}
 
	bitset.clear();
	if(!reverse_bitset.empty())
	{
		for(typename DBZ<BLK, ALC>::size_type i = reverse_bitset.size() - 1;
		    i > 0;
		    --i)
		{
			bitset.push_back(reverse_bitset.test(i));
		}
		bitset.push_back(reverse_bitset.test(0));
	}
 
	return is;
}
 
template<typename BLK, typename ALC>
constexpr void swap(DBZ<BLK, ALC>& bitset1,
                    DBZ<BLK, ALC>& bitset2)
{
	bitset1.swap(bitset2);
}
 
#ifndef DBZ_NO_NAMESPACE
} 

#endif
 
#endif 

 
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
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
#endif
  cin >> tc;
  for (int test = 1; test <= tc; test ++) {
    solution(); cout << "\n";
  }
}