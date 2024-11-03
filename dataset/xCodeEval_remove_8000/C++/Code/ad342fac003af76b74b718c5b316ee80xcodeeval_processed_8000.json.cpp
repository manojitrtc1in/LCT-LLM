




























	
	


	
	

	
	



namespace olymp::utils {
}  


namespace olymp::utils {



template<typename type>
struct is_integral : public std::is_integral<type> {};


template<>
struct is_integral<__int128_t> : public std::true_type {};

template<>
struct is_integral<__uint128_t> : public std::true_type {};


template<typename type>
inline constexpr bool id19 = is_integral<type>::value;





template<typename type>
struct is_floating_point : public std::is_floating_point<type> {};

template<typename type>
inline constexpr bool id21 = is_floating_point<type>::value;





template<typename type>
struct is_signed : public std::is_signed<type> {};


template<>
struct is_signed<__int128_t> : public std::true_type {};


template<typename type>
inline constexpr bool id0 = is_signed<type>::value;





template<typename type>
struct is_unsigned : public std::is_unsigned<type> {};


template<>
struct is_unsigned<__uint128_t> : public std::true_type {};


template<typename type>
inline constexpr bool id4 = is_unsigned<type>::value;





template<typename type>
struct make_signed : public std::make_signed<type> {};


template<>
struct make_signed<__int128_t> {
	using type = __int128_t;
};

template<>
struct make_signed<__uint128_t> {
	using type = __int128_t;
};


template<typename type>
using make_signed_t = typename make_signed<type>::type;





template<typename type>
struct make_unsigned : public std::make_unsigned<type> {};


template<>
struct make_unsigned<__int128_t> {
	using type = __uint128_t;
};

template<>
struct make_unsigned<__uint128_t> {
	using type = __uint128_t;
};


template<typename type>
using make_unsigned_t = typename make_unsigned<type>::type;





template<typename type>
struct is_precise : public is_integral<type> {};

template<typename type>
inline constexpr bool id10 = is_precise<type>::value;





template<typename type>
struct is_division_accurate : public std::bool_constant<
	id21<type> && !id19<type>
> {};

template<typename type>
inline constexpr bool id22 = is_division_accurate<type>::value;





template<typename type>
struct is_sqrt_accurate : public std::bool_constant<
	id21<type> && !id19<type>
> {};

template<typename type>
inline constexpr bool id24 = is_sqrt_accurate<type>::value;





template<typename type>
struct is_fmod_positive : public std::false_type {};

template<typename type>
inline constexpr bool id6 = is_fmod_positive<type>::value;



template<typename type>
struct wider_int;

template<>
struct wider_int<int8_t> {
	using type = int16_t;
};

template<>
struct wider_int<uint8_t> {
	using type = uint16_t;
};

template<>
struct wider_int<int16_t> {
	using type = int32_t;
};

template<>
struct wider_int<uint16_t> {
	using type = uint32_t;
};

template<>
struct wider_int<int32_t> {
	using type = int64_t;
};

template<>
struct wider_int<uint32_t> {
	using type = uint64_t;
};


template<>
struct wider_int<long> {
	using type = int64_t;
};

template<>
struct wider_int<unsigned long> {
	using type = uint64_t;
};




template<>
struct wider_int<long> {
	using type = __int128_t;
};

template<>
struct wider_int<unsigned long> {
	using type = __uint128_t;
};


template<>
struct wider_int<long long> {
	using type = __int128_t;
};

template<>
struct wider_int<unsigned long long> {
	using type = __uint128_t;
};


template<typename type>
using wider_int_t = typename wider_int<type>::type;

template<typename type>
struct zero_helper {
	constexpr type operator () (const type &) const
	{
		return 0;
	}
};

template<typename type>
[[nodiscard]] constexpr type zero_v(const type &x)
{
	return zero_helper<type>()(x);
}

template<typename type>
struct one_helper {
	constexpr type operator () (const type &) const
	{
		return static_cast<type>(1);
	}
};

template<typename type>
[[nodiscard]] constexpr type one_v(const type &x)
{
	return one_helper<type>()(x);
}

}  


namespace olymp::numeric {

template<typename value_t, typename int_t>
value_t bin_pow(value_t a, int_t k)
{
	if constexpr (utils::id0<int_t>) OLYMP_ASSERT_USER(k >= 0);
	value_t result = utils::one_v(a);
	if (k > 0) {
		while (k > 1) {
			if (k & 1) result *= a;
			k >>= 1;
			a *= a;
		}
		result *= a;
	}
	return result;
}

}  


namespace olymp::numeric {

namespace impl {

template<typename value_t>
std::tuple<value_t, value_t, value_t> id3(const value_t &a, const value_t &b)
{
	if (b == 0) return {a, 1, 0};
	auto [d, x1, y1] = id3(b, a % b);
	return {std::move(d), y1, x1 - y1 * (a / b)};
}

}  


using std::abs;


__int128_t abs(__int128_t x)
{
	return x < 0 ? -x : x;
}




template<typename a_t, typename b_t, typename result_t = std::common_type_t<a_t, b_t>>
std::tuple<result_t, result_t, result_t> egcd(const a_t &a, const b_t &b)
{
	auto res = impl::id3(
		abs(static_cast<result_t>(a)),
		abs(static_cast<result_t>(b))
	);
	if (a < 0) std::get<1>(res) = -std::get<1>(res);
	if (b < 0) std::get<2>(res) = -std::get<2>(res);
	return res;
}

}  


namespace olymp::utils {



template<typename int_t>
struct numeric_limits : public std::numeric_limits<int_t> {
};

namespace impl {



struct numeric_limits_int128_t {
	static constexpr bool is_specialized = true;
	


	static constexpr __int128_t min() noexcept
	{
		return static_cast<__int128_t>(static_cast<__uint128_t>(1) << 127);
	}
	static constexpr __int128_t lowest() noexcept
	{
		return static_cast<__int128_t>(static_cast<__uint128_t>(1) << 127);
	}
	static constexpr __int128_t max() noexcept
	{
		return static_cast<__int128_t>((static_cast<__uint128_t>(1) << 127) - 1);
	}
};

struct numeric_limits_uint128_t {
	static constexpr bool is_specialized = true;
	

	
	static constexpr __uint128_t min() noexcept { return 0; }
	static constexpr __uint128_t lowest() noexcept { return 0; }
	static constexpr __uint128_t max() noexcept { return static_cast<__uint128_t>(-1); }
};



template<typename f_t, typename s_t>
struct numeric_limits_pair {
	using value_type = std::pair<f_t, s_t>;

	static constexpr bool is_specialized = true;
	

	
	static constexpr value_type min() noexcept {
		return std::make_pair<f_t, s_t>(
			numeric_limits<f_t>::min(),
			numeric_limits<s_t>::min()
		);
	}
	static constexpr value_type lowest() noexcept {
		return std::make_pair<f_t, s_t>(
			numeric_limits<f_t>::lowest(),
			numeric_limits<s_t>::lowest()
		);
	}
	static constexpr value_type max() noexcept {
		return std::make_pair<f_t, s_t>(
			numeric_limits<f_t>::max(),
			numeric_limits<s_t>::max()
		);
	}
};

}  




template<>
struct numeric_limits<__int128_t> : public std::conditional_t<
	std::numeric_limits<__int128_t>::is_specialized,
	std::numeric_limits<__int128_t>,
	impl::numeric_limits_int128_t
> {};

template<>
struct numeric_limits<__uint128_t> : public std::conditional_t<
	std::numeric_limits<__uint128_t>::is_specialized,
	std::numeric_limits<__uint128_t>,
	impl::numeric_limits_uint128_t
> {};



template<typename f_t, typename s_t>
struct numeric_limits<std::pair<f_t, s_t>> : public std::conditional_t<
	(
		std::numeric_limits<f_t>::is_specialized &&
		std::numeric_limits<s_t>::is_specialized
	),
	impl::numeric_limits_pair<f_t, s_t>,
	std::numeric_limits<std::pair<f_t, s_t>>
> {};



}  



























namespace olymp::numeric {






namespace impl {

template<typename int_t>
using enable_if_integral_t = std::enable_if_t<utils::id19<int_t>, int_t>;

template<typename value_t, value_t md>
struct is_p2_or_zero : public std::bool_constant<!(md & (md - 1))> {
};

template<typename value_t, value_t md>
constexpr auto id11 = is_p2_or_zero<value_t, md>::value;

template<typename value_t>
struct mult_value_helper_var;

template<>
struct mult_value_helper_var<uint32_t> {
	using type = uint64_t;
};


template<>
struct mult_value_helper_var<uint64_t> {
	using type = __uint128_t;
};


template<typename value_t, uint64_t user_md>
struct mult_value_helper;

template<uint64_t user_md>
struct mult_value_helper<uint32_t, user_md> {
	using type = std::conditional_t<
		id11<uint32_t, user_md>,
		uint32_t,
		std::conditional_t<(user_md <= 0xffff), uint32_t, uint64_t>
	>;
};

template<>
struct mult_value_helper<uint32_t, 0x100000000> {
	using type = uint32_t;
};


template<uint64_t user_md>
struct mult_value_helper<uint64_t, user_md> {
	using type = std::conditional_t<id11<uint64_t, user_md>, uint64_t, __uint128_t>;
};


template<>
struct mult_value_helper<uint64_t, 0> {
	using type = uint64_t;
};

template<typename value_t, uint64_t user_md>
using mult_value_t = typename mult_value_helper<value_t, user_md>::type;

template<typename value_t, value_t md>
struct calc_mult_md : public std::integral_constant<
	value_t,
	!id11<value_t, md> && utils::numeric_limits<value_t>::max() / md >= 1 ?
		(utils::numeric_limits<value_t>::max() / md * md) :
		md
> {
};

template<typename value_t, typename mult_value_t, value_t md>
struct module_const_value_helper {
	static constexpr value_t modulus = md;
	
	static constexpr bool is_const_value = true;
	
	static constexpr bool fit_twice =
		modulus <= (static_cast<value_t>(1) << (sizeof(value_t) * 8 - 1));
	static constexpr value_t p2mod = (static_cast<value_t>(-1) % modulus + 1) % modulus;
	
	using value_type = value_t;
	using mult_value_type = mult_value_t;
	
	using mult_type = module_const_value_helper<
		mult_value_t, mult_value_t, calc_mult_md<mult_value_t, md>::value
	>;
};

template<typename value_t>
class id13 {
public:
	constexpr id13() = default;
	explicit constexpr id13(value_t md) : md_(md) {}
	
	constexpr value_t divide (value_t x) const {
		return x / md_;
	}
	
private:
	value_t md_{};
};

template<typename tag, typename value_t, typename mult_value_t, template<typename> typename divider_tmpl>
struct module_var_value_helper {
	static value_t modulus;
	
	static constexpr bool is_const_value = false;
	
	static bool fit_twice;
	static value_t p2mod;
	
	using divider_t = divider_tmpl<value_t>;
	static divider_t divider;
	
	using value_type = value_t;
	using mult_value_type = mult_value_t;
	using mult_type = module_var_value_helper<
		tag, mult_value_t, mult_value_t, divider_tmpl
	>;
	
	static constexpr void init_value(value_t val)
	{
		do_init_value(val, val);
	}

	static constexpr bool is_p2_or_zero(mult_value_t md)
	{
		return !(md & (md - 1));
	}
	
	static constexpr mult_value_t calc_mult_md(mult_value_t md)
	{
		return (
			!module_var_value_helper::is_p2_or_zero(md) &&
			utils::numeric_limits<mult_value_t>::max() / md >= 1
		) ?
			(utils::numeric_limits<mult_value_t>::max() / md * md) :
			md;
	}
	
	static constexpr void do_init_value(value_t val, value_t src_val)
	{
		module_var_value_helper::modulus = val;
		module_var_value_helper::fit_twice =
			val <= (static_cast<value_t>(1) << (sizeof(value_t) * 8 - 1));
		module_var_value_helper::p2mod = (static_cast<value_t>(-1) % val + 1) % val;
		module_var_value_helper::divider = divider_t(src_val);
		if constexpr (!std::is_same_v<module_var_value_helper, mult_type>) {
			mult_type::do_init_value(module_var_value_helper::calc_mult_md(val), src_val);
		}
	}
};

template<typename tag, typename value_t, typename mult_value_t, template<typename> typename divider_tmpl>
inline value_t module_var_value_helper<tag, value_t, mult_value_t, divider_tmpl>::modulus = 0;

template<typename tag, typename value_t, typename mult_value_t, template<typename> typename divider_tmpl>
inline bool module_var_value_helper<tag, value_t, mult_value_t, divider_tmpl>::fit_twice = false;

template<typename tag, typename value_t, typename mult_value_t, template<typename> typename divider_tmpl>
inline value_t module_var_value_helper<tag, value_t, mult_value_t, divider_tmpl>::p2mod = 0;

template<typename tag, typename value_t, typename mult_value_t, template<typename> typename divider_tmpl>
inline divider_tmpl<value_t> module_var_value_helper<tag, value_t, mult_value_t, divider_tmpl>::divider;

template<typename value_t, typename module_info_t, typename src_module_info_t>
struct fast_mod_helper_var {
	typename module_info_t::value_type operator () (value_t value) const
	{
		if constexpr (std::is_same_v<typename src_module_info_t::value_type, value_t>)
			return value - src_module_info_t::divider.divide(value) * src_module_info_t::modulus;
		else if constexpr (std::is_same_v<typename module_info_t::value_type, value_t>)
			return value - module_info_t::divider.divide(value) * src_module_info_t::modulus;
		else
			return value % src_module_info_t::modulus;
	}
};

template<typename value_t, typename module_info_t, typename src_module_info_t>
struct fast_mod_helper_var_noinline {
	__attribute__((noinline)) typename module_info_t::value_type operator () (value_t value) const
	{
		if constexpr (std::is_same_v<typename src_module_info_t::value_type, value_t>)
			return value - src_module_info_t::divider.divide(value) * src_module_info_t::modulus;
		else if constexpr (std::is_same_v<typename module_info_t::value_type, value_t>)
			return value - module_info_t::divider.divide(value) * src_module_info_t::modulus;
		else
			return value % src_module_info_t::modulus;
	}
};

template<typename value_t, typename module_info_t, typename src_module_info_t>
struct fast_mod_helper {
	constexpr typename module_info_t::value_type operator () (value_t value) const
	{
		if constexpr (src_module_info_t::is_const_value) {
			if constexpr (
				id11<typename src_module_info_t::value_type, src_module_info_t::modulus>
			)
				return value;
			else
				return value % src_module_info_t::modulus;
		}
		else {
			return fast_mod_helper_var<value_t, module_info_t, src_module_info_t>()(value);
		}
	}
};

template<typename value_t, typename module_info_t, typename src_module_info_t>
struct fast_mod_helper_noinline {
	constexpr typename module_info_t::value_type operator () (value_t value) const
	{
		if constexpr (src_module_info_t::is_const_value)
		{
			if constexpr (
				id11<typename src_module_info_t::value_type, src_module_info_t::modulus>
			)
				return value;
			else
				return value % src_module_info_t::modulus;
		}
		else {
			return fast_mod_helper_var_noinline<value_t, module_info_t, src_module_info_t>()(value);
		}
	}
};

template<typename module_info_t, typename src_module_info_t>
struct value_helper_common {
	using value_t = typename module_info_t::value_type;
	using mult_value_t = typename module_info_t::mult_value_type;

	template<typename int_t>
	[[nodiscard]] constexpr value_t from_negative(int_t value) const noexcept
	{
		using uint_t = utils::make_unsigned_t<int_t>;
		uint_t x = ~(static_cast<uint_t>(value));
		if (x >= module_info_t::modulus) {
			if (sizeof(int_t) > sizeof(value_t) || module_info_t::fit_twice) {
				x = fast_mod_helper_noinline<uint_t, module_info_t, src_module_info_t>()(x);
			}
			else {
				x -= module_info_t::modulus;
			}
		}
		return module_info_t::modulus - 1 - x;
	}

	template<typename int_t>
	[[nodiscard]] constexpr value_t init(int_t value) const noexcept
	{
		using uint_t = utils::make_unsigned_t<int_t>;
		return value < 0 ?
			from_negative(value) :
			static_cast<uint_t>(value) >= module_info_t::modulus ?
				fast_mod_helper_noinline<
					uint_t, module_info_t, src_module_info_t
				>()(static_cast<uint_t>(value)) :
				value;
	}
	
	[[nodiscard]] constexpr value_t init(bool value) const noexcept
	{
		return init(static_cast<uint32_t>(value));
	}
	
	template<typename int_t>
	[[nodiscard]] constexpr int_t convert_to(value_t value) const noexcept
	{
		if constexpr (std::is_same_v<module_info_t, src_module_info_t>)
			return value;
		else
			return fast_mod_helper<value_t, module_info_t, src_module_info_t>()(value);
	}
	
	[[nodiscard]] constexpr value_t plus(value_t l, value_t r) const noexcept
	{
		if (module_info_t::fit_twice) {
			l += r;
			if (l >= module_info_t::modulus) l -= module_info_t::modulus;
		}
		else {
			auto tmp = l;
			l += r;
			if (l < tmp) l += module_info_t::p2mod;
			else if (l >= module_info_t::modulus) l -= module_info_t::modulus;
		}
		return l;
	}
	
	[[nodiscard]] constexpr value_t minus(value_t l, value_t r) const noexcept
	{
		if (module_info_t::fit_twice) {
			l -= r;
			if (l >= module_info_t::modulus) l += module_info_t::modulus;
		}
		else {
			auto tmp = l;
			l -= r;
			if (l > tmp) l -= module_info_t::p2mod;
		}
		return l;
	}
	
	[[nodiscard]] constexpr mult_value_t mult(value_t l, value_t r) const noexcept
	{
		return l * static_cast<mult_value_t>(r);
	}
	
	[[nodiscard]] constexpr value_t plusplus(value_t v) const noexcept
	{
		return (v == module_info_t::modulus - 1) ? 0 : v + 1;
	}
	
	[[nodiscard]] constexpr value_t minusminus(value_t v) const noexcept
	{
		return v ? v - 1 : module_info_t::modulus - 1;
	}
};

struct convert_value_helper {
	template<typename value_t, typename int_t, value_t md>
	[[nodiscard]] constexpr std::enable_if_t<
		md == 0 || md == 0x100000000 || !id11<value_t, md>, int_t
	> to(value_t value) const
	{
		return value;
	}
	
	template<typename value_t, typename int_t, value_t md>
	[[nodiscard]] constexpr std::enable_if_t<
		md != 0 && md != 0x100000000 && id11<value_t, md>, int_t
	> to(value_t value) const
	{
		return value & (md - 1);
	}
};

template<typename value_t, value_t md>
struct value_helper_simple {
	template<typename int_t>
	[[nodiscard]] constexpr value_t init(int_t value) const noexcept
	{
		return value;
	}
	
	template<typename int_t>
	[[nodiscard]] constexpr int_t convert_to(value_t value) const noexcept
	{
		return convert_value_helper().to<value_t, int_t, md>(value);
	}
	
	[[nodiscard]] constexpr value_t plus(value_t l, value_t r) const noexcept
	{
		return l + r;
	}
	
	[[nodiscard]] constexpr value_t minus(value_t l, value_t r) const noexcept
	{
		return l - r;
	}
	
	[[nodiscard]] constexpr value_t mult(value_t l, value_t r) const noexcept
	{
		return l * r;
	}
	
	[[nodiscard]] constexpr value_t plusplus(value_t v) const noexcept
	{
		return v + 1;
	}
	
	[[nodiscard]] constexpr value_t minusminus(value_t v) const noexcept
	{
		return v - 1;
	}
};

template<typename module_info_t, typename src_module_info_t>
struct value_helper : public value_helper_common<module_info_t, src_module_info_t> {
};

template<
	typename value_t, typename mult_value_t, value_t md,
	typename src_value_t, typename src_mult_value_t, src_value_t src_md
>
struct value_helper<
	module_const_value_helper<value_t, mult_value_t, md>,
	module_const_value_helper<src_value_t, src_mult_value_t, src_md>
> : public std::conditional_t<
	id11<value_t, md>,
	value_helper_simple<value_t, md>,
	value_helper_common<
		module_const_value_helper<value_t, mult_value_t, md>,
		module_const_value_helper<src_value_t, src_mult_value_t, src_md>
	>
> {
};

template<typename module_info_t>
struct get_mod_helper;

template<typename value_t, typename mult_value_t, value_t md>
struct get_mod_helper<module_const_value_helper<value_t, mult_value_t, md>> {
	constexpr value_t operator () () const
	{
		return md;
	}
};

template<>
struct get_mod_helper<module_const_value_helper<uint32_t, uint32_t, 0>> {
	constexpr uint64_t operator () () const
	{
		return 0x100000000;
	}
};


template<>
struct get_mod_helper<module_const_value_helper<uint64_t, uint64_t, 0x100000000>> {
	constexpr __uint128_t operator () () const
	{
		return static_cast<__uint128_t>(1) << 64;
	}
};

template<>
struct get_mod_helper<module_const_value_helper<uint64_t, uint64_t, 0x100000000>> {
	constexpr uint64_t operator () () const
	{
		return 0;
	}
};


template<typename tag, typename value_t, typename mult_value_t, template<typename> typename divider_tmpl>
struct get_mod_helper<module_var_value_helper<tag, value_t, mult_value_t, divider_tmpl>> {
	value_t operator () () const
	{
		return module_var_value_helper<tag, value_t, mult_value_t, divider_tmpl>::modulus;
	}
};

template<typename value_t, value_t md, typename value2_t, value2_t md2>
struct is_md_divides_base : public std::bool_constant<
	(
		(
			md2 == 0x100000000 &&
			md <= utils::numeric_limits<uint64_t>::max() &&
			id11<value_t, md>
		) ||
		(md2 == 0 && md <= 0xFFFFFFFF && id11<value_t, md>) ||
		(
			md2 && md2 != 0x100000000 && (
				(!md && md2 % 0x100000000 == 0) ||
				(md && md != 0x100000000 && md2 % md == 0)
			)
		)
	)
> {
};

template<typename module_info_t, typename module_info2_t>
struct is_md_divides : public is_md_divides_base<
	typename module_info_t::value_type, module_info_t::modulus,
	typename module_info2_t::value_type, module_info2_t::modulus
> {
};

template<
	typename tag, typename value_t, typename mult_value_t, template<typename> typename divider_tmpl,
	typename tag2, typename value2_t, typename mult_value2_t, template<typename> typename divider2_tmpl
>
struct is_md_divides<
	module_var_value_helper<tag, value_t, mult_value_t, divider_tmpl>,
	module_var_value_helper<tag2, value2_t, mult_value2_t, divider2_tmpl>
> : public std::false_type {
};

template<typename module_info_t>
struct modular_base_checker : public std::true_type {
};

template<typename value_t, typename mult_value_t, value_t md>
struct modular_base_checker<
	module_const_value_helper<value_t, mult_value_t, md>
> : public std::true_type {
	static_assert(
		md != 0 || std::is_same_v<value_t, uint32_t>,
		"Use `val_t`=`uint32_t` for module=2**32"
	);
	static_assert(
		md != 0 || std::is_same_v<mult_value_t, uint32_t>,
		"Use `mult_val_t`=`uint32_t` for module=2**32"
	);
	static_assert(
		md != 0x100000000 || std::is_same_v<value_t, uint64_t>,
		"Use `val_t`=`uint64_t` for module=2**64"
	);
	static_assert(
		md != 0x100000000 || std::is_same_v<mult_value_t, uint64_t>,
		"Use `mult_val_t`=`uint64_t` for module=2**64"
	);
	static_assert(
		!md || md == 0x100000000 || md <= utils::numeric_limits<value_t>::max(),
		"`val_t` is too small for `md`"
	);
};



template<typename module_info_t, typename src_module_info_t>
class id20 {
public:
	static_assert(
		std::is_same_v<
			typename module_info_t::mult_value_type,
			typename src_module_info_t::mult_value_type
		>,
		"inconsistent mult_value_type in module_info_t and src_module_info_t"
	);
	using value_t = typename module_info_t::value_type;
	using mult_value_t = typename module_info_t::mult_value_type;
	using mult_t = id20<typename module_info_t::mult_type, src_module_info_t>;
	using module_info_type = module_info_t;
	
	using src_value_t = typename src_module_info_t::value_type;
	using src_mult_value_t = typename src_module_info_t::mult_value_type;
	using src_module_info_type = src_module_info_t;
	using src_t = id20<src_module_info_t, src_module_info_t>;
	
	friend class id20<src_module_info_t, src_module_info_t>;
	friend class id20<typename module_info_t::mult_type, src_module_info_t>;
	
	struct id14 {
		constexpr id14(value_t value) : value(value) {}
		
		value_t value;
	};
	
	id20() noexcept = default;

	id20(const id20 &) noexcept = default;
	id20(id20 &&) noexcept = default;
	
	id20 &operator = (const id20 &) noexcept = default;
	id20 &operator = (id20 &&) noexcept = default;
	
	template<
		typename int_t,
		typename impl::enable_if_integral_t<int_t> * = nullptr
	>
	constexpr id20(int_t value) noexcept :
		value_(value_helper<module_info_t, src_module_info_t>().init(value))
	{}
	
	constexpr id20(id14 value) noexcept :
		value_(value.value)
	{}
	
	template<
		typename module_info2_t, typename src_module_info2_t,
		typename std::enable_if_t<
			(
				is_md_divides<src_module_info_t, src_module_info2_t>::value &&
				!std::is_same_v<id20<module_info2_t, src_module_info2_t>, src_t>
			),
			void
		> * = nullptr
	>
	constexpr id20(id20<module_info2_t, src_module_info2_t> r) noexcept :
		id20(static_cast<typename src_module_info2_t::value_type>(r))
	{}
	
	template<
		typename modular_base2_t,
		typename std::enable_if_t<
			!std::is_same_v<modular_base2_t, id20> &&
				std::is_same_v<modular_base2_t, src_t>,
			void
		> * = nullptr
	>
	constexpr id20(modular_base2_t r) noexcept :
		id20(id14(r.value_))
	{}
	
	template<
		typename module_info2_t, typename src_module_info2_t,
		typename std::enable_if_t<
			!src_module_info2_t::is_const_value, void
		> * = nullptr
	>
	constexpr id20(id20<module_info2_t, src_module_info2_t> r) noexcept :
		id20(static_cast<typename src_module_info2_t::value_type>(r))
	{
		OLYMP_ASSERT_USER(src_module_info2_t::modulus % src_module_info_t::modulus == 0);
	}
	
	template<
		typename int_t,
		typename impl::enable_if_integral_t<int_t> * = nullptr
	>
	[[nodiscard]] explicit constexpr operator int_t() const noexcept
	{
		return value_helper<module_info_t, src_module_info_t>().template convert_to<int_t>(value_);
	}
	
	constexpr id20 &operator += (id20 r) noexcept
	{
		value_ = value_helper<module_info_t, src_module_info_t>().plus(value_, r.value_);
		return *this;
	}
	
	constexpr id20 &operator -= (id20 r) noexcept
	{
		value_ = value_helper<module_info_t, src_module_info_t>().minus(value_, r.value_);
		return *this;
	}
	
	constexpr id20 &operator *= (id20 r) noexcept
	{
		auto mres = value_helper<module_info_t, src_module_info_t>().mult(
			static_cast<src_value_t>(*this),
			static_cast<src_value_t>(r)
		);
		if constexpr (std::is_same_v<module_info_t, src_module_info_t>) {
			mres = fast_mod_helper<
				mult_value_t, module_info_t, src_module_info_t
			>()(mres);
		}
		value_ = mres;
		return *this;
	}
	
	template<typename modular_base2_t>
	inline constexpr std::enable_if_t<
		std::is_same_v<modular_base2_t, id20<src_module_info_t, src_module_info_t>>,
		id20 &
	> operator *= (modular_base2_t r) noexcept
	{
		auto mres = value_helper<module_info_t, src_module_info_t>().mult(
			static_cast<src_value_t>(*this),
			static_cast<src_value_t>(r)
		);
		if constexpr (!std::is_same_v<mult_value_t, value_t>) {
			OLYMP_ASSERT_LIB(false);
		}
		value_ = mres;
		return *this;
	}
	
	

	constexpr id20 inv() const noexcept
	{
		using signed_mod_t = utils::make_signed_t<decltype(get_mod())>;
		if constexpr (get_mod() <= utils::numeric_limits<signed_mod_t>::max()) {
			auto [d, x, y] = egcd(
				static_cast<signed_mod_t>(value_),
				static_cast<signed_mod_t>(get_mod())
			);
			OLYMP_ASSERT_USER(d == 1);
			return x;
		}
		else {
			using signed_wmod_t = utils::make_signed_t<utils::wider_int_t<value_t>>;
			auto [d, x, y] = egcd(
				static_cast<signed_wmod_t>(value_),
				static_cast<signed_wmod_t>(get_mod())
			);
			OLYMP_ASSERT_USER(d == 1);
			return x;
		}
	}
	
	constexpr id20 &operator /= (id20 r) noexcept
	{
		*this *= r.inv();
		return *this;
	}
	
	template<typename modular_base2_t>
	inline constexpr std::enable_if_t<
		std::is_same_v<modular_base2_t, id20<src_module_info_t, src_module_info_t>>,
		id20 &
	> operator /= (modular_base2_t r) noexcept
	{
		*this *= r.inv();
		return *this;
	}
	
	constexpr id20 &operator ++ () noexcept
	{
		value_ = value_helper<module_info_t, src_module_info_t>().plusplus(value_);
		return *this;
	}
	
	constexpr id20 operator ++ (int) noexcept
	{
		id20 tmp = *this;
		++*this;
		return tmp;
	}
	
	constexpr id20 &operator -- () noexcept
	{
		value_ = value_helper<module_info_t, src_module_info_t>().minusminus(value_);
		return *this;
	}
	
	constexpr id20 operator -- (int) noexcept
	{
		id20 tmp = *this;
		--*this;
		return tmp;
	}
	
	constexpr id20 operator - () const noexcept
	{
		return id20(0) - *this;
	}
	
	[[nodiscard]] inline constexpr friend id20 operator + (id20 l, id20 r) noexcept
	{
		return id20(l) += r;
	}

	template<typename module_info2_t, typename src_module_info2_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<id20<module_info2_t, src_module_info2_t>, id20> &&
			std::is_same_v<id20<module_info2_t, src_module_info2_t>, mult_t>,
		mult_t
	> operator + (id20<module_info2_t, src_module_info2_t> l, id20 r) noexcept
	{
		return id20(static_cast<src_value_t>(l)) += r;
	}
	
	template<typename module_info2_t, typename src_module_info2_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<id20<module_info2_t, src_module_info2_t>, id20> &&
			std::is_same_v<id20<module_info2_t, src_module_info2_t>, mult_t>,
		mult_t
	> operator + (id20 l, id20<module_info2_t, src_module_info2_t> r) noexcept
	{
		return id20(l) += static_cast<src_value_t>(r);
	}
	
	[[nodiscard]] inline constexpr friend id20 operator - (id20 l, id20 r) noexcept
	{
		return id20(l) -= r;
	}

	template<typename module_info2_t, typename src_module_info2_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<id20<module_info2_t, src_module_info2_t>, id20> &&
			std::is_same_v<id20<module_info2_t, src_module_info2_t>, mult_t>,
		mult_t
	> operator - (id20<module_info2_t, src_module_info2_t> l, id20 r) noexcept
	{
		return id20(static_cast<src_value_t>(l)) -= r;
	}
	
	template<typename module_info2_t, typename src_module_info2_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<id20<module_info2_t, src_module_info2_t>, id20> &&
			std::is_same_v<id20<module_info2_t, src_module_info2_t>, mult_t>,
		mult_t
	> operator - (id20 l, id20<module_info2_t, src_module_info2_t> r) noexcept
	{
		return id20(l) -= static_cast<src_value_t>(r);
	}
	
	[[nodiscard]] inline constexpr friend mult_t operator * (id20 l, id20 r) noexcept
	{
		if constexpr (std::is_same_v<module_info_t, src_module_info_t>) {
			auto mres = value_helper<typename mult_t::module_info_type, src_module_info_t>().mult(
				static_cast<src_value_t>(l),
				static_cast<src_value_t>(r)
			);
			return mult_t(mres);
		}
		else {
			return mult_t(static_cast<src_value_t>(l)) *= static_cast<src_value_t>(r);
		}
	}
	
	template<typename modular_base_mult_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modular_base_mult_t, id20> &&
			std::is_same_v<modular_base_mult_t, mult_t>,
		mult_t
	> operator * (modular_base_mult_t l, id20 r) noexcept
	{
		return l *= static_cast<src_value_t>(r);
	}
	
	template<typename modular_base_mult_t = mult_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modular_base_mult_t, id20> &&
			std::is_same_v<modular_base_mult_t, mult_t>,
		mult_t
	> operator * (id20 l, modular_base_mult_t r) noexcept
	{
		return r *= static_cast<src_value_t>(l);
	}
	
	[[nodiscard]] inline constexpr friend mult_t operator / (id20 l, id20 r) noexcept
	{
		return l * r.inv();
	}
	
	template<typename modular_base_mult_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modular_base_mult_t, id20> &&
			std::is_same_v<modular_base_mult_t, mult_t>,
		mult_t
	> operator / (modular_base_mult_t l, id20 r) noexcept
	{
		return l /= static_cast<src_value_t>(r);
	}
	
	template<typename modular_base_mult_t = mult_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<modular_base_mult_t, id20> &&
			std::is_same_v<modular_base_mult_t, mult_t>,
		mult_t
	> operator / (id20 l, modular_base_mult_t r) noexcept
	{
		return l / static_cast<src_value_t>(r);
	}
	
	[[nodiscard]] inline constexpr friend bool operator == (id20 l, id20 r) noexcept
	{
		return static_cast<src_value_t>(l) == static_cast<src_value_t>(r);
	}
	
	template<typename module_info2_t, typename src_module_info2_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<id20<module_info2_t, src_module_info2_t>, id20> &&
			std::is_same_v<id20<module_info2_t, src_module_info2_t>, mult_t>,
		bool
	> operator == (id20<module_info2_t, src_module_info2_t> l, id20 r) noexcept
	{
		return static_cast<src_value_t>(l) == static_cast<src_value_t>(r);
	}
	
	template<typename module_info2_t, typename src_module_info2_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<id20<module_info2_t, src_module_info2_t>, id20> &&
			std::is_same_v<id20<module_info2_t, src_module_info2_t>, mult_t>,
		bool
	> operator == (id20 l, id20<module_info2_t, src_module_info2_t> r) noexcept
	{
		return static_cast<src_value_t>(l) == static_cast<src_value_t>(r);
	}
	
	[[nodiscard]] inline constexpr friend bool operator != (id20 l, id20 r) noexcept
	{
		return !(l == r);
	}
	
	template<typename module_info2_t, typename src_module_info2_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<id20<module_info2_t, src_module_info2_t>, id20> &&
			std::is_same_v<id20<module_info2_t, src_module_info2_t>, mult_t>,
		bool
	> operator != (id20<module_info2_t, src_module_info2_t> l, id20 r) noexcept
	{
		return !(l == r);
	}
	
	template<typename module_info2_t, typename src_module_info2_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<id20<module_info2_t, src_module_info2_t>, id20> &&
			std::is_same_v<id20<module_info2_t, src_module_info2_t>, mult_t>,
		bool
	> operator != (id20 l, id20<module_info2_t, src_module_info2_t> r) noexcept
	{
		return !(l == r);
	}
	
	[[nodiscard]] inline constexpr friend bool operator < (id20 l, id20 r) noexcept
	{
		return static_cast<src_value_t>(l) < static_cast<src_value_t>(r);
	}
	
	template<typename module_info2_t, typename src_module_info2_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<id20<module_info2_t, src_module_info2_t>, id20> &&
			std::is_same_v<id20<module_info2_t, src_module_info2_t>, mult_t>,
		bool
	> operator < (id20<module_info2_t, src_module_info2_t> l, id20 r) noexcept
	{
		return static_cast<src_value_t>(l) < static_cast<src_value_t>(r);
	}
	
	template<typename module_info2_t, typename src_module_info2_t>
	[[nodiscard]] inline constexpr friend typename std::enable_if_t<
		!std::is_same_v<id20<module_info2_t, src_module_info2_t>, id20> &&
			std::is_same_v<id20<module_info2_t, src_module_info2_t>, mult_t>,
		bool
	> operator < (id20 l, id20<module_info2_t, src_module_info2_t> r) noexcept
	{
		return static_cast<src_value_t>(l) < static_cast<src_value_t>(r);
	}
	
	template<typename int_t>
	constexpr id20 &pow_this(int_t k) noexcept
	{
		return (*this = bin_pow(*this, k));
	}
	
	template<typename int_t>
	[[nodiscard]] constexpr mult_t pow(int_t k) const noexcept
	{
		return mult_t(*this).pow_this(k);
	}

	template<typename int_t>
	[[nodiscard]] inline friend constexpr mult_t pow(id20 a, int_t k) noexcept
	{
		return a.pow(k);
	}


	template<typename int_t>
	constexpr id20 &operator ^= (int_t k) noexcept
	{
		return pow_this(k);
	}
	
	template<typename int_t>
	[[nodiscard]] constexpr id20 operator ^ (int_t k) const noexcept
	{
		return id20(*this) ^= k;
	}

	
	[[nodiscard]] constexpr value_t load() const noexcept
	{
		return value_;
	}
	
	static constexpr auto get_mod() noexcept
	{
		return get_mod_helper<src_module_info_t>()();
	}
	
	static constexpr auto get_real_mod() noexcept
	{
		return get_mod_helper<module_info_t>()();
	}
	
	template<typename type = module_info_t>
	static constexpr std::enable_if_t<
		std::is_same_v<type, module_info_t> && !type::is_const_value, void
	> init_module(value_t md) noexcept
	{
		type::init_value(md);
	}
	
private:
	using static_checker = modular_base_checker<module_info_t>;
	static_assert(static_checker::value, "static checker failed");

	value_t value_{0};
};

template<typename module_info_t>
struct limits_max_helper {
	using value_type = typename module_info_t::value_type;
	
	constexpr value_type operator () () const noexcept
	{
		return module_info_t::modulus - 1;
	}
};

template<>
struct limits_max_helper<module_const_value_helper<uint32_t, uint32_t, 0>> {
	constexpr uint32_t operator () () const
	{
		return static_cast<uint32_t>(-1);
	}
};

template<>
struct limits_max_helper<module_const_value_helper<uint64_t, uint64_t, 0x100000000>> {
	constexpr uint64_t operator () () const
	{
		return static_cast<uint64_t>(-1);
	}
};

}  

}  


namespace olymp::utils {

template<typename module_info_t, typename src_module_info_t>
struct numeric_limits<numeric::impl::id20<module_info_t, src_module_info_t>> {
	static constexpr typename module_info_t::value_type min() noexcept { return 0; }
	static constexpr typename module_info_t::value_type lowest() noexcept { return 0; }
	static constexpr typename module_info_t::value_type max() noexcept
	{
		return numeric::impl::limits_max_helper<src_module_info_t>()();
	}
};

}  


namespace olymp::numeric {
namespace impl {

template<typename module_info_t, typename src_module_info_t>
std::istream &operator >> (std::istream &is, id20<module_info_t, src_module_info_t> &r)
{
	typename src_module_info_t::value_type x;
	is >> x;
	r = x;
	return is;
}

template<typename module_info_t, typename src_module_info_t>
std::ostream &operator << (std::ostream &os, id20<module_info_t, src_module_info_t> r)
{
	return os << static_cast<typename src_module_info_t::value_type>(r);
}

template<uint64_t user_md>
using modular_base_value_t = std::conditional_t<
	(user_md > 0 && user_md <= static_cast<uint64_t>(utils::numeric_limits<uint32_t>::max()) + 1),
	uint32_t,
	uint64_t
>;

template<typename module_info_t>
struct modular_helper {
	using type = id20<module_info_t, module_info_t>;
};

template<uint64_t user_md, typename value_t, typename mult_value_t>
struct module_info_const_helper {
	using type = module_const_value_helper<value_t, mult_value_t, user_md>;
};

template<typename value_t, typename mult_value_t>
struct module_info_const_helper<0, value_t, mult_value_t> {
	using type = module_const_value_helper<value_t, mult_value_t, 0x100000000>;
};

template<typename value_t, typename mult_value_t>
struct module_info_const_helper<0x100000000, value_t, mult_value_t> {
	using type = module_const_value_helper<value_t, mult_value_t, 0>;
};

template<typename tag, typename value_t, typename mult_value_t, template<typename> typename divider_tmpl>
struct module_info_var_helper {
	using type = module_var_value_helper<tag, value_t, mult_value_t, divider_tmpl>;
};

}  


template<
	uint64_t m,
	typename value_t = impl::modular_base_value_t<m>,
	typename mult_value_t = impl::mult_value_t<value_t, m>
>
using modular = typename impl::modular_helper<
	typename impl::module_info_const_helper<m, value_t, mult_value_t>::type
>::type;

using modular32 = modular<0x100000000>;
using modular64 = modular<0>;

template<typename tag, typename value_t>
using modular_var_slow = typename impl::modular_helper<
	typename impl::module_info_var_helper<
		tag, value_t, typename impl::mult_value_helper_var<value_t>::type, impl::id13
	>::type
>::type;

}  








namespace olymp::utils {

inline clock_t &id1()
{
	static clock_t id15;
	return id15;
}

inline clock_t &id17()
{
	static clock_t id9;
	return id9;
}

inline void id12()
{
	auto &id18 = id1();
	auto &id8 = id17();
	id18 = id8 = clock();
}

inline double id2()
{
	const auto &t0 = id1();
	auto t1 = clock();
	return (t1 - t0) * 1000.0 / CLOCKS_PER_SEC;
}

inline double id23()
{
	auto &t0 = id17();
	auto t1 = clock();
	double result = (t1 - t0) * 1000.0 / CLOCKS_PER_SEC;
	t0 = t1;
	return result;
}

inline void id25([[maybe_unused]] std::string_view step_name = {})
{


	if (step_name.empty()) {
		fprintf(stderr, "Step time = %0.0lf ms\n", id23());
	}
	else {
		fprintf(stderr, "Step '");
		fwrite(step_name.data(), 1, step_name.size(), stderr);
		fprintf(stderr, "' time = %0.0lf ms\n", id23());
	}


}

inline void id7()
{


	fprintf(stderr, "Execution time = %0.0lf ms\n", id2());


}

}  


namespace olymp::utils {

class rnd_t {
public:
	template<typename int_t = int>
	int_t get()
	{
		if constexpr (gen_.max() >= std::numeric_limits<int_t>::max()) {
			return gen_() & std::numeric_limits<int_t>::max();
		}
		else {
			std::uniform_int_distribution<int_t> d(0, std::numeric_limits<int_t>::max());
			return d(gen_);
		}
	}
	
	template<typename int_t = int>
	int_t operator () ()
	{
		return get<int_t>();
	}
	
	template<typename int_t>
	int_t operator () (int_t n)
	{
		std::uniform_int_distribution<int_t> d(0, n - 1);
		return d(gen_);
	}
	
	template<typename int_l_t, typename int_r_t>
	std::common_type_t<int_l_t, int_r_t> operator () (int_l_t l, int_r_t r)
	{
		std::uniform_int_distribution<std::common_type_t<int_l_t, int_r_t>> d(l, r);
		return d(gen_);
	}
	
	template<typename int_t>
	void seed(int_t &&value)
	{
		gen_.seed(std::forward<int_t>(value));
	}
	
	std::mt19937 &gen() { return gen_; }
	
	template<typename it_t>
	void shuffle(it_t b, it_t e)
	{
		std::shuffle(b, e, gen());
	}
	
	template<typename int_t>
	void discard(int_t n)
	{
		gen_.discard(n);
	}

private:
	std::mt19937 gen_{311311311};
};


thread_local

static inline rnd_t rnd;

}  


namespace olymp::utils {

template<typename a_t, typename b_t, typename less_t = std::less<a_t>>
inline constexpr std::enable_if_t<
	std::is_same_v<std::common_type_t<a_t, std::decay_t<b_t>>, a_t>,
	bool
> uin(a_t &a, b_t &&b, less_t &&less = less_t())
{
	return less(b, a) ? a = std::forward<b_t>(b), true : false;
}

template<typename a_t, typename b_t, typename less_t = std::less<a_t>>
inline constexpr std::enable_if_t<
	std::is_same_v<std::common_type_t<a_t, std::decay_t<b_t>>, a_t>,
	bool
> uax(a_t &a, b_t &&b, less_t &&less = less_t())
{
	return less(a, b) ? a = std::forward<b_t>(b), true : false;
}

}  












using olymp::utils::id25;
using olymp::utils::id7;
using olymp::utils::rnd;

template <class _T> inline _T sqr(const _T &x) { return x * x; }

namespace olymp {

__attribute__((constructor)) inline void init_main()
{
	utils::id12();
}

__attribute__((destructor)) inline void id16()
{
	utils::id7();
}

}  


using namespace olymp;
using namespace std;
using utils::uax;
using utils::uin;



using ld = long double;


using i64 = long long;
using u64 = unsigned long long;





const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-9;



const int MOD = 998244353;
using mint = numeric::modular<MOD>;

const int maxn = 42;
const int pp = 25;

int n, m, k, qq;
mint pre[13][13][maxn];
mint b[13][13][maxn];
mint d[maxn][maxn][13][13];
vector<int> g[13][13];
int req[1024000][3];
mint ans[1024000];

int dull(int n, int k, int m)
{
	int p[20];
	forn(i, n)
	{
		p[i] = i;
	}
	int ans = 0;
	do
	{
		int k1 = 0, k2 = 0;
		forn(i, n - 1)
		{
			if (p[i] > p[i + 1]) k2++;
		}
		if (k2 == m)
		{
			forn(i, n)
			{
				forn(j, i)
				{
					if (p[i] < p[j]) k1++;
				}
				if (k1 > k) break;
			}
			if (k1 == k)
			{
				ans++;
			}
		}
	}
	while (next_permutation(p, p + n));
	return ans;
}

mint id5(int n, int k, int m)
{
	clr(d);
	d[1][0][0][0] = 1;
	For(i, 1, n - 1)
	{
		forn(l, i)
		{
			forn(kk, k + 1)
			{
				forn(mm, m + 1)
				{
					const auto &dd = d[i][l][kk][mm];
					if (!dd) continue;
					forn(t, l + 1)
					{
						int kn = kk + (i - t);
						int mn = mm + 1;
						if (kn <= k && mn <= m) d[i + 1][t][kn][mn] += dd;
					}
					For(t, l + 1, i)
					{
						int kn = kk + (i - t);
						int mn = mm;
						if (kn <= k && mn <= m) d[i + 1][t][kn][mn] += dd;
					}
				}
			}
		}
	}
	mint ans = 0;
	forn(i, n)
	{
		ans += d[n][i][k][m];
	}
	return ans;
}

void precalc()
{
	For(k, 1, 11)
	{
		For(m, 1, 11)
		{
			mint a[90];
			int st = pp;
			int t = st + 15;
			int z = 0;


			For(n, 1, pp - 1)
			{
				pre[k][m][n] = id5(n, k, m);
			}
			For(n, st, t)
			{
				a[z] = id5(n, k, m);




				{
					z++;


				}
			}


			bool ff = false;
			int w = 0;
			For(i, 1, z - 1)
			{
				bool ok = true;
				Ford(j, z - 1, i)
				{
					a[j] = a[j] - a[j - 1];
				}
				For(j, i, z - 1)
				{


					if (a[j]) ok = false;
				}


				if (ok)
				{
					ff = true;
					break;
				}
				w = i;
			}
			++w;
			assert(ff);










			for (int id : g[k][m])
			{
				int n = req[id][0];


				if (n < pp) ans[id] = pre[k][m][n];
				else
				{
					ans[id] = 0;
					mint cc = 1;
					forn(i, w)
					{
						ans[id] += a[i] * cc;
						cc *= (n - pp - i);
						cc /= (i + 1);
					}
				}
			}
		}
	}
}

int main()
{

	freopen("input.txt", "rt", stdin);


	scanf("%d", &qq);
	forn(tt, qq)
	{
		forn(i, 3)
		{
			scanf("%d", &req[tt][i]);
		}
		g[req[tt][1]][req[tt][2]].pb(tt);


	}
	precalc();
	
	forn(tt, qq)
	{
		printf("%d\n", int(ans[tt]));
	}
	
	return 0;
}
