

























 


 
 









namespace tsl {
	namespace rh {
		template <std::size_t GrowthFactor> class id50 {
		  public:
			explicit id50(std::size_t &id6) {
				if (id6 > max_bucket_count()) {
					TSL_RH_THROW_OR_TERMINATE(std::length_error,
											  "The hash table exceeds its maxmimum size.");
				}
				if (id6 > 0) {
					id6 = round_up_to_power_of_two(id6);
					m_mask = id6 - 1;
				} else {
					m_mask = 0;
				}
			}
			std::size_t bucket_for_hash(std::size_t hash) const noexcept { return hash & m_mask; }
			std::size_t id33() const {
				if ((m_mask + 1) > max_bucket_count() / GrowthFactor) {
					TSL_RH_THROW_OR_TERMINATE(std::length_error,
											  "The hash table exceeds its maxmimum size.");
				}
 
				return (m_mask + 1) * GrowthFactor;
			}
			std::size_t max_bucket_count() const {
				return (std::numeric_limits<std::size_t>::max() / 2) + 1;
			}
			void clear() noexcept { m_mask = 0; }
 
		  private:
			static std::size_t round_up_to_power_of_two(std::size_t value) {
				if (is_power_of_two(value)) {
					return value;
				}
				if (value == 0) {
					return 1;
				}
				--value;
				for (std::size_t i = 1; i < sizeof(std::size_t) * CHAR_BIT; i *= 2) {
					value |= value >> i;
				}
				return value + 1;
			}
			static constexpr bool is_power_of_two(std::size_t value) {
				return value != 0 && (value & (value - 1)) == 0;
			}
 
		  protected:
			static_assert(is_power_of_two(GrowthFactor) && GrowthFactor >= 2,
						  "GrowthFactor must be a power of two >= 2.");
 
			std::size_t m_mask;
		};
		template <class GrowthFactor = std::ratio<3, 2>> class id23 {
		  public:
			explicit id23(std::size_t &id6) {
				if (id6 > max_bucket_count()) {
					TSL_RH_THROW_OR_TERMINATE(std::length_error,
											  "The hash table exceeds its maxmimum size.");
				}
 
				if (id6 > 0) {
					m_mod = id6;
				} else {
					m_mod = 1;
				}
			}
			std::size_t bucket_for_hash(std::size_t hash) const noexcept { return hash % m_mod; }
			std::size_t id33() const {
				if (m_mod == max_bucket_count()) {
					TSL_RH_THROW_OR_TERMINATE(std::length_error,
											  "The hash table exceeds its maxmimum size.");
				}
				const double id33 =
					std::ceil(double(m_mod) * REHASH_SIZE_MULTIPLICATION_FACTOR);
				if (!std::isnormal(id33)) {
					TSL_RH_THROW_OR_TERMINATE(std::length_error,
											  "The hash table exceeds its maxmimum size.");
				}
				if (id33 > double(max_bucket_count())) {
					return max_bucket_count();
				} else {
					return std::size_t(id33);
				}
			}
			std::size_t max_bucket_count() const { return MAX_BUCKET_COUNT; }
			void clear() noexcept { m_mod = 1; }
 
		  private:
			static constexpr double REHASH_SIZE_MULTIPLICATION_FACTOR =
				1.0 * GrowthFactor::num / GrowthFactor::den;
			static const std::size_t MAX_BUCKET_COUNT = std::size_t(double(
				std::numeric_limits<std::size_t>::max() / REHASH_SIZE_MULTIPLICATION_FACTOR));
			static_assert(REHASH_SIZE_MULTIPLICATION_FACTOR >= 1.1,
						  "Growth factor should be >= 1.1.");
			std::size_t m_mod;
		};
		namespace detail {
			static constexpr const std::array<std::size_t, 40> id40 = {
				{1ul,		  5ul,			17ul,		  29ul,		   37ul,		53ul,
				 67ul,		  79ul,			97ul,		  131ul,	   193ul,		257ul,
				 389ul,		  521ul,		769ul,		  1031ul,	  1543ul,		2053ul,
				 3079ul,	  6151ul,		12289ul,	  24593ul,	 49157ul,		98317ul,
				 196613ul,	393241ul,		786433ul,	 1572869ul,   3145739ul,   6291469ul,
				 12582917ul,  25165843ul,   50331653ul,   100663319ul, 201326611ul, 402653189ul,
				 805306457ul, 1610612741ul, 3221225473ul, 4294967291ul}};
			template <unsigned int IPrime> static constexpr std::size_t mod(std::size_t hash) {
				return hash % id40[IPrime];
			}
			static constexpr const std::array<std::size_t (*)(std::size_t), 40> id42 = {
				{&mod<0>,  &mod<1>,  &mod<2>,  &mod<3>,  &mod<4>,  &mod<5>,  &mod<6>,  &mod<7>,
				 &mod<8>,  &mod<9>,  &mod<10>, &mod<11>, &mod<12>, &mod<13>, &mod<14>, &mod<15>,
				 &mod<16>, &mod<17>, &mod<18>, &mod<19>, &mod<20>, &mod<21>, &mod<22>, &mod<23>,
				 &mod<24>, &mod<25>, &mod<26>, &mod<27>, &mod<28>, &mod<29>, &mod<30>, &mod<31>,
				 &mod<32>, &mod<33>, &mod<34>, &mod<35>, &mod<36>, &mod<37>, &mod<38>, &mod<39>}};
		} 

		class id24 {
		  public:
			explicit id24(std::size_t &id6) {
				auto it_prime = std::lower_bound(detail::id40.begin(), detail::id40.end(),
												 id6);
				if (it_prime == detail::id40.end()) {
					TSL_RH_THROW_OR_TERMINATE(std::length_error,
											  "The hash table exceeds its maxmimum size.");
				}
 
				id3 =
					static_cast<unsigned int>(std::distance(detail::id40.begin(), it_prime));
				if (id6 > 0) {
					id6 = *it_prime;
				} else {
					id6 = 0;
				}
			}
 
			std::size_t bucket_for_hash(std::size_t hash) const noexcept {
				return detail::id42[id3](hash);
			}
 
			std::size_t id33() const {
				if (id3 + 1 >= detail::id40.size()) {
					TSL_RH_THROW_OR_TERMINATE(std::length_error,
											  "The hash table exceeds its maxmimum size.");
				}
 
				return detail::id40[id3 + 1];
			}
 
			std::size_t max_bucket_count() const { return detail::id40.back(); }
 
			void clear() noexcept { id3 = 0; }
 
		  private:
			unsigned int id3;
 
			static_assert(std::numeric_limits<decltype(id3)>::max() >= detail::id40.size(),
						  "The type of id3 is not big enough.");
		};
 
	} 

 
	namespace detail_robin_hash {
		template <typename T> struct make_void { using type = void; };
		template <typename T, typename = void> struct has_is_transparent : std::false_type {};
		template <typename T>
		struct has_is_transparent<T, typename make_void<typename T::is_transparent>::type>
			: std::true_type {};
		template <typename U> struct is_power_of_two_policy : std::false_type {};
		template <std::size_t GrowthFactor>
		struct is_power_of_two_policy<tsl::rh::id50<GrowthFactor>>
			: std::true_type {};
		template <class T> const T &clamp(const T &v, const T &lo, const T &hi) {
			return std::min(hi, std::max(lo, v));
		}
		template <typename T, typename U>
		static T numeric_cast(U value, const char *error_message = "numeric_cast() failed.") {
			T ret = static_cast<T>(value);
			if (static_cast<U>(ret) != value) {
				TSL_RH_THROW_OR_TERMINATE(std::runtime_error, error_message);
			}
			const bool id21 =
				(std::is_unsigned<T>::value && std::is_unsigned<U>::value) ||
				(std::is_signed<T>::value && std::is_signed<U>::value);
			if (!id21 && (ret < T{}) != (value < U{})) {
				TSL_RH_THROW_OR_TERMINATE(std::runtime_error, error_message);
			}
 
			return ret;
		}
		using id7 = std::uint_least32_t;
		template <bool StoreHash> class bucket_entry_hash {
		  public:
			bool bucket_hash_equal(std::size_t ) const noexcept { return true; }
			id7 truncated_hash() const noexcept { return 0; }
 
		  protected:
			void set_hash(id7 ) noexcept {}
		};
		template <> class bucket_entry_hash<true> {
		  public:
			bool bucket_hash_equal(std::size_t hash) const noexcept {
				return m_hash == id7(hash);
			}
			id7 truncated_hash() const noexcept { return m_hash; }
 
		  protected:
			void set_hash(id7 hash) noexcept { m_hash = id7(hash); }
 
		  private:
			id7 m_hash;
		};
		template <typename ValueType, bool StoreHash>
		class bucket_entry : public bucket_entry_hash<StoreHash> {
			using bucket_hash = bucket_entry_hash<StoreHash>;
 
		  public:
			using value_type = ValueType;
			using distance_type = std::int_least16_t;
			bucket_entry() noexcept
				: bucket_hash(), id8(id12),
				  id29(false) {}
			bucket_entry(bool last_bucket) noexcept
				: bucket_hash(), id8(id12),
				  id29(last_bucket) {}
			bucket_entry(const bucket_entry &other) noexcept(
				std::is_nothrow_copy_constructible<value_type>::value)
				: bucket_hash(other), id8(id12),
				  id29(other.id29) {
				if (!other.empty()) {
					::new (static_cast<void *>(std::addressof(m_value))) value_type(other.value());
					id8 = other.id8;
				}
			}
			bucket_entry(bucket_entry &&other) noexcept(
				std::is_nothrow_move_constructible<value_type>::value)
				: bucket_hash(std::move(other)),
				  id8(id12),
				  id29(other.id29) {
				if (!other.empty()) {
					::new (static_cast<void *>(std::addressof(m_value)))
						value_type(std::move(other.value()));
					id8 = other.id8;
				}
			}
			bucket_entry &operator=(const bucket_entry &other) noexcept(
				std::is_nothrow_copy_constructible<value_type>::value) {
				if (this != &other) {
					clear();
					bucket_hash::operator=(other);
					if (!other.empty()) {
						::new (static_cast<void *>(std::addressof(m_value)))
							value_type(other.value());
					}
					id8 = other.id8;
					id29 = other.id29;
				}
				return *this;
			}
			bucket_entry &operator=(bucket_entry &&) = delete;
			~bucket_entry() noexcept { clear(); }
			void clear() noexcept {
				if (!empty()) {
					destroy_value();
					id8 = id12;
				}
			}
			bool empty() const noexcept {
				return id8 == id12;
			}
			value_type &value() noexcept {
				return *reinterpret_cast<value_type *>(std::addressof(m_value));
			}
			const value_type &value() const noexcept {
				return *reinterpret_cast<const value_type *>(std::addressof(m_value));
			}
			distance_type id0() const noexcept {
				return id8;
			}
			bool last_bucket() const noexcept { return id29; }
			void set_as_last_bucket() noexcept { id29 = true; }
			template <typename... Args>
			void id51(distance_type id0,
										   id7 hash, Args &&... value_type_args) {
				::new (static_cast<void *>(std::addressof(m_value)))
					value_type(std::forward<Args>(value_type_args)...);
				this->set_hash(hash);
				id8 = id0;
			}
			void swap_with_value_in_bucket(distance_type &id0,
										   id7 &hash, value_type &value) {
				using std::swap;
				swap(value, this->value());
				swap(id0, id8);
				(void)hash;
				if (StoreHash) {
					const id7 tmp_hash = this->truncated_hash();
					this->set_hash(hash);
					hash = tmp_hash;
				}
			}
			static id7 truncate_hash(std::size_t hash) noexcept {
				return id7(hash);
			}
 
		  private:
			void destroy_value() noexcept { value().~value_type(); }
 
		  public:
			static const distance_type DIST_FROM_IDEAL_BUCKET_LIMIT = 4096;
			static_assert(DIST_FROM_IDEAL_BUCKET_LIMIT <=
							  std::numeric_limits<distance_type>::max() - 1,
						  "DIST_FROM_IDEAL_BUCKET_LIMIT must be <= "
						  "std::numeric_limits<distance_type>::max() - 1.");
 
		  private:
			using storage =
				typename std::aligned_storage<sizeof(value_type), alignof(value_type)>::type;
			static const distance_type id12 = -1;
			distance_type id8;
			bool id29;
			storage m_value;
		};
		template <class ValueType, class KeySelect, class ValueSelect, class Hash, class KeyEqual,
				  class Allocator, bool StoreHash, class GrowthPolicy>
		class id4 : private Hash, private KeyEqual, private GrowthPolicy {
		  private:
			template <typename U>
			using has_mapped_type =
				typename std::integral_constant<bool, !std::is_same<U, void>::value>;
 
			static_assert(noexcept(std::declval<GrowthPolicy>().bucket_for_hash(std::size_t(0))),
						  "GrowthPolicy::bucket_for_hash must be noexcept.");
			static_assert(noexcept(std::declval<GrowthPolicy>().clear()),
						  "GrowthPolicy::clear must be noexcept.");
 
		  public:
			template <bool IsConst> class id38;
			using key_type = typename KeySelect::key_type;
			using value_type = ValueType;
			using size_type = std::size_t;
			using difference_type = std::ptrdiff_t;
			using hasher = Hash;
			using key_equal = KeyEqual;
			using allocator_type = Allocator;
			using reference = value_type &;
			using const_reference = const value_type &;
			using pointer = value_type *;
			using const_pointer = const value_type *;
			using iterator = id38<false>;
			using const_iterator = id38<true>;
 
		  private:
			static constexpr bool STORE_HASH =
				StoreHash || ((sizeof(tsl::detail_robin_hash::bucket_entry<value_type, true>) ==
							   sizeof(tsl::detail_robin_hash::bucket_entry<value_type, false>)) &&
							  (sizeof(std::size_t) == sizeof(id7) ||
							   is_power_of_two_policy<GrowthPolicy>::value) &&
							  (!std::is_arithmetic<key_type>::value ||
							   !std::is_same<Hash, std::hash<key_type>>::value));
			static constexpr bool USE_STORED_HASH_ON_LOOKUP = StoreHash;
			static bool USE_STORED_HASH_ON_REHASH(size_type bucket_count) {
				(void)bucket_count;
				if (STORE_HASH && sizeof(std::size_t) == sizeof(id7)) {
					return true;
				} else if (STORE_HASH && is_power_of_two_policy<GrowthPolicy>::value) {
					return (bucket_count - 1) <= std::numeric_limits<id7>::max();
				} else {
					return false;
				}
			}
			using bucket_entry = tsl::detail_robin_hash::bucket_entry<value_type, STORE_HASH>;
			using distance_type = typename bucket_entry::distance_type;
			using buckets_allocator =
				typename std::allocator_traits<allocator_type>::template rebind_alloc<bucket_entry>;
			using buckets_container_type = std::vector<bucket_entry, buckets_allocator>;
 
		  public:
			template <bool IsConst> class id38 {
				friend class id4;
 
			  private:
				using bucket_entry_ptr =
					typename std::conditional<IsConst, const bucket_entry *, bucket_entry *>::type;
				id38(bucket_entry_ptr bucket) noexcept : m_bucket(bucket) {}
 
			  public:
				using iterator_category = std::forward_iterator_tag;
				using value_type = const typename id4::value_type;
				using difference_type = std::ptrdiff_t;
				using reference = value_type &;
				using pointer = value_type *;
				id38() noexcept {}
				template <bool id44 = IsConst,
						  typename std::enable_if<id44>::type * = nullptr>
				id38(const id38<!id44> &other) noexcept
					: m_bucket(other.m_bucket) {}
				id38(const id38 &other) = default;
				id38(id38 &&other) = default;
				id38 &operator=(const id38 &other) = default;
				id38 &operator=(id38 &&other) = default;
				const typename id4::key_type &key() const {
					return KeySelect()(m_bucket->value());
				}
				template <
					class U = ValueSelect,
					typename std::enable_if<has_mapped_type<U>::value && IsConst>::type * = nullptr>
				const typename U::value_type &value() const {
					return U()(m_bucket->value());
				}
				template <class U = ValueSelect,
						  typename std::enable_if<has_mapped_type<U>::value && !IsConst>::type * =
							  nullptr>
				typename U::value_type &value() {
					return U()(m_bucket->value());
				}
				reference operator*() const { return m_bucket->value(); }
				pointer operator->() const { return std::addressof(m_bucket->value()); }
				id38 &operator++() {
					while (true) {
						if (m_bucket->last_bucket()) {
							++m_bucket;
							return *this;
						}
						++m_bucket;
						if (!m_bucket->empty()) {
							return *this;
						}
					}
				}
				id38 operator++(int) {
					id38 tmp(*this);
					++*this;
 
					return tmp;
				}
				friend bool operator==(const id38 &lhs, const id38 &rhs) {
					return lhs.m_bucket == rhs.m_bucket;
				}
				friend bool operator!=(const id38 &lhs, const id38 &rhs) {
					return !(lhs == rhs);
				}
 
			  private:
				bucket_entry_ptr m_bucket;
			};
 
		  public:
			id4(size_type bucket_count, const Hash &hash, const KeyEqual &equal,
					   const Allocator &alloc, float id19 = id49,
					   float id30 = id43)
				: Hash(hash), KeyEqual(equal), GrowthPolicy(bucket_count),
				  id46(
					  [&]() {
						  if (bucket_count > max_bucket_count()) {
							  TSL_RH_THROW_OR_TERMINATE(
								  std::length_error, "The map exceeds its maximum bucket count.");
						  }
 
						  return bucket_count;
					  }(),
					  alloc),
				  id39(id46.empty() ? static_empty_bucket_ptr()
												   : id46.data()),
				  id25(bucket_count), id47(0), id2(false),
				  id15(false) {
				if (id25 > 0) {
					id46.back().set_as_last_bucket();
				}
				this->id19(id19);
				this->id30(id30);
			}
 
			id4(const id4 &other)
				: Hash(other), KeyEqual(other), GrowthPolicy(other),
				  id46(other.id46),
				  id39(id46.empty() ? static_empty_bucket_ptr()
												   : id46.data()),
				  id25(other.id25), id47(other.id47),
				  id26(other.id26),
				  id37(other.id37),
				  id2(other.id2),
				  id28(other.id28),
				  id15(other.id15) {}
 
			id4(id4 &&other) noexcept(
				std::is_nothrow_move_constructible<Hash>::value
					&&std::is_nothrow_move_constructible<KeyEqual>::value
						&&std::is_nothrow_move_constructible<GrowthPolicy>::value
							&&std::is_nothrow_move_constructible<buckets_container_type>::value)
				: Hash(std::move(static_cast<Hash &>(other))),
				  KeyEqual(std::move(static_cast<KeyEqual &>(other))),
				  GrowthPolicy(std::move(static_cast<GrowthPolicy &>(other))),
				  id46(std::move(other.id46)),
				  id39(id46.empty() ? static_empty_bucket_ptr()
												   : id46.data()),
				  id25(other.id25), id47(other.id47),
				  id26(other.id26),
				  id37(other.id37),
				  id2(other.id2),
				  id28(other.id28),
				  id15(other.id15) {
				other.GrowthPolicy::clear();
				other.id46.clear();
				other.id39 = static_empty_bucket_ptr();
				other.id25 = 0;
				other.id47 = 0;
				other.id26 = 0;
				other.id2 = false;
				other.id15 = false;
			}
			id4 &operator=(const id4 &other) {
				if (&other != this) {
					Hash::operator=(other);
					KeyEqual::operator=(other);
					GrowthPolicy::operator=(other);
 
					id46 = other.id46;
					id39 =
						id46.empty() ? static_empty_bucket_ptr() : id46.data();
					id25 = other.id25;
					id47 = other.id47;
 
					id26 = other.id26;
					id37 = other.id37;
					id2 = other.id2;
 
					id28 = other.id28;
					id15 = other.id15;
				}
				return *this;
			}
			id4 &operator=(id4 &&other) {
				other.swap(*this);
				other.clear();
				return *this;
			}
			allocator_type get_allocator() const { return id46.get_allocator(); }
			iterator begin() noexcept {
				std::size_t i = 0;
				while (i < id25 && id39[i].empty()) {
					i++;
				}
				return iterator(id39 + i);
			}
			const_iterator begin() const noexcept { return cbegin(); }
			const_iterator cbegin() const noexcept {
				std::size_t i = 0;
				while (i < id25 && id39[i].empty()) {
					i++;
				}
 
				return const_iterator(id39 + i);
			}
			iterator end() noexcept { return iterator(id39 + id25); }
			const_iterator end() const noexcept { return cend(); }
			const_iterator cend() const noexcept {
				return const_iterator(id39 + id25);
			}
			bool empty() const noexcept { return id47 == 0; }
			size_type size() const noexcept { return id47; }
			size_type max_size() const noexcept { return id46.max_size(); }
			void clear() noexcept {
				for (auto &bucket : id46) {
					bucket.clear();
				}
				id47 = 0;
				id2 = false;
			}
			template <typename P> std::pair<iterator, bool> insert(P &&value) {
				return insert_impl(KeySelect()(value), std::forward<P>(value));
			}
			template <typename P> iterator insert_hint(const_iterator hint, P &&value) {
				if (hint != cend() && compare_keys(KeySelect()(*hint), KeySelect()(value))) {
					return mutable_iterator(hint);
				}
				return insert(std::forward<P>(value)).first;
			}
			template <class InputIt> void insert(InputIt first, InputIt last) {
				if (std::is_base_of<
						std::forward_iterator_tag,
						typename std::iterator_traits<InputIt>::iterator_category>::value) {
					const auto id32 = std::distance(first, last);
					const size_type id17 = id26 - size();
					if (id32 > 0 && id17 < size_type(id32)) {
						reserve(size() + size_type(id32));
					}
				}
				for (; first != last; ++first) {
					insert(*first);
				}
			}
			template <class K, class M>
			std::pair<iterator, bool> id35(K &&key, M &&obj) {
				auto it = id45(std::forward<K>(key), std::forward<M>(obj));
				if (!it.second) {
					it.first.value() = std::forward<M>(obj);
				}
				return it;
			}
			template <class K, class M>
			iterator id35(const_iterator hint, K &&key, M &&obj) {
				if (hint != cend() && compare_keys(KeySelect()(*hint), key)) {
					auto it = mutable_iterator(hint);
					it.value() = std::forward<M>(obj);
					return it;
				}
				return id35(std::forward<K>(key), std::forward<M>(obj)).first;
			}
			template <class... Args> std::pair<iterator, bool> emplace(Args &&... args) {
				return insert(value_type(std::forward<Args>(args)...));
			}
			template <class... Args> iterator id27(const_iterator hint, Args &&... args) {
				return insert_hint(hint, value_type(std::forward<Args>(args)...));
			}
			template <class K, class... Args>
			std::pair<iterator, bool> id45(K &&key, Args &&... args) {
				return insert_impl(key, std::piecewise_construct,
								   std::forward_as_tuple(std::forward<K>(key)),
								   std::forward_as_tuple(std::forward<Args>(args)...));
			}
			template <class K, class... Args>
			iterator id16(const_iterator hint, K &&key, Args &&... args) {
				if (hint != cend() && compare_keys(KeySelect()(*hint), key)) {
					return mutable_iterator(hint);
				}
				return id45(std::forward<K>(key), std::forward<Args>(args)...).first;
			}
			iterator erase(iterator pos) {
				erase_from_bucket(pos);
				if (pos.m_bucket->empty()) {
					++pos;
				}
				id15 = true;
				return pos;
			}
			iterator erase(const_iterator pos) { return erase(mutable_iterator(pos)); }
			iterator erase(const_iterator first, const_iterator last) {
				if (first == last) {
					return mutable_iterator(first);
				}
				auto id36 = mutable_iterator(first);
				auto id48 = mutable_iterator(last);
				for (auto it = id36.m_bucket; it != id48.m_bucket; ++it) {
					if (!it->empty()) {
						it->clear();
						id47--;
					}
				}
				if (id48 == end()) {
					return end();
				}
				std::size_t id9 =
					static_cast<std::size_t>(id36.m_bucket - id39);
				std::size_t id20 =
					static_cast<std::size_t>(id48.m_bucket - id39);
				const std::size_t id1 =
					id20 -
					std::min(
						id20 - id9,
						std::size_t(id39[id20].id0()));
 
				while (id20 < id25 &&
					   id39[id20].id0() > 0) {
					id9 =
						id20 -
						std::min(
							id20 - id9,
							std::size_t(id39[id20].id0()));
					const distance_type new_distance =
						distance_type(id39[id20].id0() -
									  (id20 - id9));
					id39[id9].id51(
						new_distance, id39[id20].truncated_hash(),
						std::move(id39[id20].value()));
					id39[id20].clear();
 
					++id9;
					++id20;
				}
				id15 = true;
				return iterator(id39 + id1);
			}
			template <class K> size_type erase(const K &key) { return erase(key, hash_key(key)); }
			template <class K> size_type erase(const K &key, std::size_t hash) {
				auto it = find(key, hash);
				if (it != end()) {
					erase_from_bucket(it);
					id15 = true;
					return 1;
				} else {
					return 0;
				}
			}
			void swap(id4 &other) {
				using std::swap;
				swap(static_cast<Hash &>(*this), static_cast<Hash &>(other));
				swap(static_cast<KeyEqual &>(*this), static_cast<KeyEqual &>(other));
				swap(static_cast<GrowthPolicy &>(*this), static_cast<GrowthPolicy &>(other));
				swap(id46, other.id46);
				swap(id39, other.id39);
				swap(id25, other.id25);
				swap(id47, other.id47);
				swap(id26, other.id26);
				swap(id37, other.id37);
				swap(id2, other.id2);
				swap(id28, other.id28);
				swap(id15, other.id15);
			}
			template <class K, class U = ValueSelect,
					  typename std::enable_if<has_mapped_type<U>::value>::type * = nullptr>
			typename U::value_type &at(const K &key) {
				return at(key, hash_key(key));
			}
			template <class K, class U = ValueSelect,
					  typename std::enable_if<has_mapped_type<U>::value>::type * = nullptr>
			typename U::value_type &at(const K &key, std::size_t hash) {
				return const_cast<typename U::value_type &>(
					static_cast<const id4 *>(this)->at(key, hash));
			}
			template <class K, class U = ValueSelect,
					  typename std::enable_if<has_mapped_type<U>::value>::type * = nullptr>
			const typename U::value_type &at(const K &key) const {
				return at(key, hash_key(key));
			}
			template <class K, class U = ValueSelect,
					  typename std::enable_if<has_mapped_type<U>::value>::type * = nullptr>
			const typename U::value_type &at(const K &key, std::size_t hash) const {
				auto it = find(key, hash);
				if (it != cend()) {
					return it.value();
				} else {
					TSL_RH_THROW_OR_TERMINATE(std::out_of_range, "Couldn't find key.");
				}
			}
			template <class K, class U = ValueSelect,
					  typename std::enable_if<has_mapped_type<U>::value>::type * = nullptr>
			typename U::value_type &operator[](K &&key) {
				return id45(std::forward<K>(key)).first.value();
			}
			template <class K> size_type count(const K &key) const {
				return count(key, hash_key(key));
			}
			template <class K> size_type count(const K &key, std::size_t hash) const {
				if (find(key, hash) != cend()) {
					return 1;
				} else {
					return 0;
				}
			}
			template <class K> iterator find(const K &key) { return find_impl(key, hash_key(key)); }
			template <class K> iterator find(const K &key, std::size_t hash) {
				return find_impl(key, hash);
			}
			template <class K> const_iterator find(const K &key) const {
				return find_impl(key, hash_key(key));
			}
			template <class K> const_iterator find(const K &key, std::size_t hash) const {
				return find_impl(key, hash);
			}
			template <class K> bool contains(const K &key) const {
				return contains(key, hash_key(key));
			}
			template <class K> bool contains(const K &key, std::size_t hash) const {
				return count(key, hash) != 0;
			}
			template <class K> std::pair<iterator, iterator> equal_range(const K &key) {
				return equal_range(key, hash_key(key));
			}
			template <class K>
			std::pair<iterator, iterator> equal_range(const K &key, std::size_t hash) {
				iterator it = find(key, hash);
				return std::make_pair(it, (it == end()) ? it : std::next(it));
			}
			template <class K>
			std::pair<const_iterator, const_iterator> equal_range(const K &key) const {
				return equal_range(key, hash_key(key));
			}
			template <class K>
			std::pair<const_iterator, const_iterator> equal_range(const K &key,
																  std::size_t hash) const {
				const_iterator it = find(key, hash);
				return std::make_pair(it, (it == cend()) ? it : std::next(it));
			}
			size_type bucket_count() const { return id25; }
			size_type max_bucket_count() const {
				return std::min(GrowthPolicy::max_bucket_count(), id46.max_size());
			}
			float load_factor() const {
				if (bucket_count() == 0) {
					return 0;
				}
				return float(id47) / float(bucket_count());
			}
			float id19() const { return id28; }
			float id30() const { return id37; }
			void id19(float ml) {
				id28 =
					clamp(ml, float(MINIMUM_MIN_LOAD_FACTOR), float(MAXIMUM_MIN_LOAD_FACTOR));
			}
			void id30(float ml) {
				id37 =
					clamp(ml, float(MINIMUM_MAX_LOAD_FACTOR), float(MAXIMUM_MAX_LOAD_FACTOR));
				id26 = size_type(float(bucket_count()) * id37);
			}
			void rehash(size_type count) {
				count = std::max(count, size_type(std::ceil(float(size()) / id30())));
				rehash_impl(count);
			}
			void reserve(size_type count) {
				rehash(size_type(std::ceil(float(count) / id30())));
			}
			hasher hash_function() const { return static_cast<const Hash &>(*this); }
			key_equal key_eq() const { return static_cast<const KeyEqual &>(*this); }
			iterator mutable_iterator(const_iterator pos) {
				return iterator(const_cast<bucket_entry *>(pos.m_bucket));
			}
 
		  private:
			template <class K> std::size_t hash_key(const K &key) const {
				return Hash::operator()(key);
			}
			template <class K1, class K2> bool compare_keys(const K1 &key1, const K2 &key2) const {
				return KeyEqual::operator()(key1, key2);
			}
			std::size_t bucket_for_hash(std::size_t hash) const {
				const std::size_t bucket = GrowthPolicy::bucket_for_hash(hash);
				return bucket;
			}
			template <class U = GrowthPolicy,
					  typename std::enable_if<is_power_of_two_policy<U>::value>::type * = nullptr>
			std::size_t next_bucket(std::size_t index) const noexcept {
				return (index + 1) & this->m_mask;
			}
			template <class U = GrowthPolicy,
					  typename std::enable_if<!is_power_of_two_policy<U>::value>::type * = nullptr>
			std::size_t next_bucket(std::size_t index) const noexcept {
				index++;
				return (index != bucket_count()) ? index : 0;
			}
			template <class K> iterator find_impl(const K &key, std::size_t hash) {
				return mutable_iterator(static_cast<const id4 *>(this)->find(key, hash));
			}
			template <class K> const_iterator find_impl(const K &key, std::size_t hash) const {
				std::size_t ibucket = bucket_for_hash(hash);
				distance_type id0 = 0;
				while (id0 <= id39[ibucket].id0()) {
					if (TSL_RH_LIKELY((!USE_STORED_HASH_ON_LOOKUP ||
									   id39[ibucket].bucket_hash_equal(hash)) &&
									  compare_keys(KeySelect()(id39[ibucket].value()), key))) {
						return const_iterator(id39 + ibucket);
					}
 
					ibucket = next_bucket(ibucket);
					id0++;
				}
				return cend();
			}
			void erase_from_bucket(iterator pos) {
				pos.m_bucket->clear();
				id47--;
				std::size_t id13 = static_cast<std::size_t>(pos.m_bucket - id39);
				std::size_t ibucket = next_bucket(id13);
 
				while (id39[ibucket].id0() > 0) {
					const distance_type new_distance =
						distance_type(id39[ibucket].id0() - 1);
					id39[id13].id51(
						new_distance, id39[ibucket].truncated_hash(),
						std::move(id39[ibucket].value()));
					id39[ibucket].clear();
 
					id13 = ibucket;
					ibucket = next_bucket(ibucket);
				}
			}
			template <class K, class... Args>
			std::pair<iterator, bool> insert_impl(const K &key, Args &&... value_type_args) {
				const std::size_t hash = hash_key(key);
				std::size_t ibucket = bucket_for_hash(hash);
				distance_type id0 = 0;
				while (id0 <= id39[ibucket].id0()) {
					if ((!USE_STORED_HASH_ON_LOOKUP ||
						 id39[ibucket].bucket_hash_equal(hash)) &&
						compare_keys(KeySelect()(id39[ibucket].value()), key)) {
						return std::make_pair(iterator(id39 + ibucket), false);
					}
 
					ibucket = next_bucket(ibucket);
					id0++;
				}
				if (rehash_on_extreme_load()) {
					ibucket = bucket_for_hash(hash);
					id0 = 0;
 
					while (id0 <= id39[ibucket].id0()) {
						ibucket = next_bucket(ibucket);
						id0++;
					}
				}
				if (id39[ibucket].empty()) {
					id39[ibucket].id51(
						id0, bucket_entry::truncate_hash(hash),
						std::forward<Args>(value_type_args)...);
				} else {
					insert_value(ibucket, id0, bucket_entry::truncate_hash(hash),
								 std::forward<Args>(value_type_args)...);
				}
				id47++;
				return std::make_pair(iterator(id39 + ibucket), true);
			}
 
			template <class... Args>
			void insert_value(std::size_t ibucket, distance_type id0,
							  id7 hash, Args &&... value_type_args) {
				value_type value(std::forward<Args>(value_type_args)...);
				insert_value_impl(ibucket, id0, hash, value);
			}
 
			void insert_value(std::size_t ibucket, distance_type id0,
							  id7 hash, value_type &&value) {
				insert_value_impl(ibucket, id0, hash, value);
			}
			void insert_value_impl(std::size_t ibucket, distance_type id0,
								   id7 hash, value_type &value) {
				id39[ibucket].swap_with_value_in_bucket(id0, hash, value);
				ibucket = next_bucket(ibucket);
				id0++;
				while (!id39[ibucket].empty()) {
					if (id0 > id39[ibucket].id0()) {
						if (id0 >= bucket_entry::DIST_FROM_IDEAL_BUCKET_LIMIT) {
							id2 = true;
						}
						id39[ibucket].swap_with_value_in_bucket(id0, hash,
																	 value);
					}
					ibucket = next_bucket(ibucket);
					id0++;
				}
				id39[ibucket].id51(id0, hash,
															 std::move(value));
			}
			void rehash_impl(size_type count) {
				id4 new_table(count, static_cast<Hash &>(*this),
									 static_cast<KeyEqual &>(*this), get_allocator(),
									 id28, id37);
 
				const bool id10 = USE_STORED_HASH_ON_REHASH(new_table.bucket_count());
				for (auto &bucket : id46) {
					if (bucket.empty()) {
						continue;
					}
 
					const std::size_t hash = id10
												 ? bucket.truncated_hash()
												 : new_table.hash_key(KeySelect()(bucket.value()));
 
					new_table.insert_value_on_rehash(new_table.bucket_for_hash(hash), 0,
													 bucket_entry::truncate_hash(hash),
													 std::move(bucket.value()));
				}
 
				new_table.id47 = id47;
				new_table.swap(*this);
			}
 
			void insert_value_on_rehash(std::size_t ibucket, distance_type id0,
										id7 hash, value_type &&value) {
				while (true) {
					if (id0 > id39[ibucket].id0()) {
						if (id39[ibucket].empty()) {
							id39[ibucket].id51(id0,
																		 hash, std::move(value));
							return;
						} else {
							id39[ibucket].swap_with_value_in_bucket(id0,
																		 hash, value);
						}
					}
 
					id0++;
					ibucket = next_bucket(ibucket);
				}
			}
			bool rehash_on_extreme_load() {
				if (id2 || size() >= id26) {
					rehash_impl(GrowthPolicy::id33());
					id2 = false;
 
					return true;
				}
				if (id15) {
					id15 = false;
					if (id28 != 0.0f && load_factor() < id28) {
						reserve(size() + 1);
 
						return true;
					}
				}
 
				return false;
			}
 
		  public:
			static const size_type DEFAULT_INIT_BUCKETS_SIZE = 0;
			static constexpr float id43 = 0.5f;
			static constexpr float MINIMUM_MAX_LOAD_FACTOR = 0.2f;
			static constexpr float MAXIMUM_MAX_LOAD_FACTOR = 0.95f;
			static constexpr float id49 = 0.0f;
			static constexpr float MINIMUM_MIN_LOAD_FACTOR = 0.0f;
			static constexpr float MAXIMUM_MIN_LOAD_FACTOR = 0.15f;
			static_assert(MINIMUM_MAX_LOAD_FACTOR < MAXIMUM_MAX_LOAD_FACTOR,
						  "MINIMUM_MAX_LOAD_FACTOR should be < MAXIMUM_MAX_LOAD_FACTOR");
			static_assert(MINIMUM_MIN_LOAD_FACTOR < MAXIMUM_MIN_LOAD_FACTOR,
						  "MINIMUM_MIN_LOAD_FACTOR should be < MAXIMUM_MIN_LOAD_FACTOR");
			static_assert(MAXIMUM_MIN_LOAD_FACTOR < MINIMUM_MAX_LOAD_FACTOR,
						  "MAXIMUM_MIN_LOAD_FACTOR should be < MINIMUM_MAX_LOAD_FACTOR");
 
		  private:
			bucket_entry *static_empty_bucket_ptr() {
				static bucket_entry empty_bucket(true);
				return &empty_bucket;
			}
 
		  private:
			buckets_container_type id46;
			bucket_entry *id39;
			size_type id25;
			size_type id47;
			size_type id26;
			float id37;
			bool id2;
			float id28;
			bool id15;
		};
 
	} 

 
} 

 
namespace tsl {
	template <class Key, class T, class Hash = std::hash<Key>, class KeyEqual = std::equal_to<Key>,
			  class Allocator = std::allocator<std::pair<Key, T>>, bool StoreHash = false,
			  class GrowthPolicy = tsl::rh::id50<2>>
	class id14 {
	  private:
		template <typename U>
		using has_is_transparent = tsl::detail_robin_hash::has_is_transparent<U>;
		class KeySelect {
		  public:
			using key_type = Key;
 
			const key_type &operator()(const std::pair<Key, T> &key_value) const noexcept {
				return key_value.first;
			}
 
			key_type &operator()(std::pair<Key, T> &key_value) noexcept { return key_value.first; }
		};
		class ValueSelect {
		  public:
			using value_type = T;
 
			const value_type &operator()(const std::pair<Key, T> &key_value) const noexcept {
				return key_value.second;
			}
 
			value_type &operator()(std::pair<Key, T> &key_value) noexcept {
				return key_value.second;
			}
		};
		using ht = detail_robin_hash::id4<std::pair<Key, T>, KeySelect, ValueSelect, Hash,
												 KeyEqual, Allocator, StoreHash, GrowthPolicy>;
 
	  public:
		using key_type = typename ht::key_type;
		using mapped_type = T;
		using value_type = typename ht::value_type;
		using size_type = typename ht::size_type;
		using difference_type = typename ht::difference_type;
		using hasher = typename ht::hasher;
		using key_equal = typename ht::key_equal;
		using allocator_type = typename ht::allocator_type;
		using reference = typename ht::reference;
		using const_reference = typename ht::const_reference;
		using pointer = typename ht::pointer;
		using const_pointer = typename ht::const_pointer;
		using iterator = typename ht::iterator;
		using const_iterator = typename ht::const_iterator;
 
	  public:
		id14() : id14(ht::DEFAULT_INIT_BUCKETS_SIZE) {}
 
		explicit id14(size_type bucket_count, const Hash &hash = Hash(),
						   const KeyEqual &equal = KeyEqual(), const Allocator &alloc = Allocator())
			: m_ht(bucket_count, hash, equal, alloc) {}
 
		id14(size_type bucket_count, const Allocator &alloc)
			: id14(bucket_count, Hash(), KeyEqual(), alloc) {}
 
		id14(size_type bucket_count, const Hash &hash, const Allocator &alloc)
			: id14(bucket_count, hash, KeyEqual(), alloc) {}
 
		explicit id14(const Allocator &alloc)
			: id14(ht::DEFAULT_INIT_BUCKETS_SIZE, alloc) {}
 
		template <class InputIt>
		id14(InputIt first, InputIt last,
				  size_type bucket_count = ht::DEFAULT_INIT_BUCKETS_SIZE, const Hash &hash = Hash(),
				  const KeyEqual &equal = KeyEqual(), const Allocator &alloc = Allocator())
			: id14(bucket_count, hash, equal, alloc) {
			insert(first, last);
		}
 
		template <class InputIt>
		id14(InputIt first, InputIt last, size_type bucket_count, const Allocator &alloc)
			: id14(first, last, bucket_count, Hash(), KeyEqual(), alloc) {}
 
		template <class InputIt>
		id14(InputIt first, InputIt last, size_type bucket_count, const Hash &hash,
				  const Allocator &alloc)
			: id14(first, last, bucket_count, hash, KeyEqual(), alloc) {}
 
		id14(std::initializer_list<value_type> init,
				  size_type bucket_count = ht::DEFAULT_INIT_BUCKETS_SIZE, const Hash &hash = Hash(),
				  const KeyEqual &equal = KeyEqual(), const Allocator &alloc = Allocator())
			: id14(init.begin(), init.end(), bucket_count, hash, equal, alloc) {}
 
		id14(std::initializer_list<value_type> init, size_type bucket_count,
				  const Allocator &alloc)
			: id14(init.begin(), init.end(), bucket_count, Hash(), KeyEqual(), alloc) {}
 
		id14(std::initializer_list<value_type> init, size_type bucket_count, const Hash &hash,
				  const Allocator &alloc)
			: id14(init.begin(), init.end(), bucket_count, hash, KeyEqual(), alloc) {}
 
		id14 &operator=(std::initializer_list<value_type> ilist) {
			m_ht.clear();
 
			m_ht.reserve(ilist.size());
			m_ht.insert(ilist.begin(), ilist.end());
 
			return *this;
		}
 
		allocator_type get_allocator() const { return m_ht.get_allocator(); }
		iterator begin() noexcept { return m_ht.begin(); }
		const_iterator begin() const noexcept { return m_ht.begin(); }
		const_iterator cbegin() const noexcept { return m_ht.cbegin(); }
		iterator end() noexcept { return m_ht.end(); }
		const_iterator end() const noexcept { return m_ht.end(); }
		const_iterator cend() const noexcept { return m_ht.cend(); }
		bool empty() const noexcept { return m_ht.empty(); }
		size_type size() const noexcept { return m_ht.size(); }
		size_type max_size() const noexcept { return m_ht.max_size(); }
		void clear() noexcept { m_ht.clear(); }
		std::pair<iterator, bool> insert(const value_type &value) { return m_ht.insert(value); }
		template <class P, typename std::enable_if<
							   std::is_constructible<value_type, P &&>::value>::type * = nullptr>
		std::pair<iterator, bool> insert(P &&value) {
			return m_ht.emplace(std::forward<P>(value));
		}
		std::pair<iterator, bool> insert(value_type &&value) {
			return m_ht.insert(std::move(value));
		}
		iterator insert(const_iterator hint, const value_type &value) {
			return m_ht.insert_hint(hint, value);
		}
		template <class P, typename std::enable_if<
							   std::is_constructible<value_type, P &&>::value>::type * = nullptr>
		iterator insert(const_iterator hint, P &&value) {
			return m_ht.id27(hint, std::forward<P>(value));
		}
		iterator insert(const_iterator hint, value_type &&value) {
			return m_ht.insert_hint(hint, std::move(value));
		}
		template <class InputIt> void insert(InputIt first, InputIt last) {
			m_ht.insert(first, last);
		}
		void insert(std::initializer_list<value_type> ilist) {
			m_ht.insert(ilist.begin(), ilist.end());
		}
		template <class M> std::pair<iterator, bool> id35(const key_type &k, M &&obj) {
			return m_ht.id35(k, std::forward<M>(obj));
		}
		template <class M> std::pair<iterator, bool> id35(key_type &&k, M &&obj) {
			return m_ht.id35(std::move(k), std::forward<M>(obj));
		}
		template <class M>
		iterator id35(const_iterator hint, const key_type &k, M &&obj) {
			return m_ht.id35(hint, k, std::forward<M>(obj));
		}
		template <class M> iterator id35(const_iterator hint, key_type &&k, M &&obj) {
			return m_ht.id35(hint, std::move(k), std::forward<M>(obj));
		}
		template <class... Args> std::pair<iterator, bool> emplace(Args &&... args) {
			return m_ht.emplace(std::forward<Args>(args)...);
		}
		template <class... Args> iterator id27(const_iterator hint, Args &&... args) {
			return m_ht.id27(hint, std::forward<Args>(args)...);
		}
		template <class... Args>
		std::pair<iterator, bool> id45(const key_type &k, Args &&... args) {
			return m_ht.id45(k, std::forward<Args>(args)...);
		}
		template <class... Args>
		std::pair<iterator, bool> id45(key_type &&k, Args &&... args) {
			return m_ht.id45(std::move(k), std::forward<Args>(args)...);
		}
		template <class... Args>
		iterator id45(const_iterator hint, const key_type &k, Args &&... args) {
			return m_ht.id16(hint, k, std::forward<Args>(args)...);
		}
		template <class... Args>
		iterator id45(const_iterator hint, key_type &&k, Args &&... args) {
			return m_ht.id16(hint, std::move(k), std::forward<Args>(args)...);
		}
		iterator erase(iterator pos) { return m_ht.erase(pos); }
		iterator erase(const_iterator pos) { return m_ht.erase(pos); }
		iterator erase(const_iterator first, const_iterator last) {
			return m_ht.erase(first, last);
		}
		size_type erase(const key_type &key) { return m_ht.erase(key); }
		size_type erase(const key_type &key, std::size_t id31) {
			return m_ht.erase(key, id31);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		size_type erase(const K &key) {
			return m_ht.erase(key);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		size_type erase(const K &key, std::size_t id31) {
			return m_ht.erase(key, id31);
		}
		void swap(id14 &other) { other.m_ht.swap(m_ht); }
		T &at(const Key &key) { return m_ht.at(key); }
		T &at(const Key &key, std::size_t id31) {
			return m_ht.at(key, id31);
		}
		const T &at(const Key &key) const { return m_ht.at(key); }
		const T &at(const Key &key, std::size_t id31) const {
			return m_ht.at(key, id31);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		T &at(const K &key) {
			return m_ht.at(key);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		T &at(const K &key, std::size_t id31) {
			return m_ht.at(key, id31);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		const T &at(const K &key) const {
			return m_ht.at(key);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		const T &at(const K &key, std::size_t id31) const {
			return m_ht.at(key, id31);
		}
 
		T &operator[](const Key &key) { return m_ht[key]; }
		T &operator[](Key &&key) { return m_ht[std::move(key)]; }
 
		size_type count(const Key &key) const { return m_ht.count(key); }
		size_type count(const Key &key, std::size_t id31) const {
			return m_ht.count(key, id31);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		size_type count(const K &key) const {
			return m_ht.count(key);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		size_type count(const K &key, std::size_t id31) const {
			return m_ht.count(key, id31);
		}
		iterator find(const Key &key) { return m_ht.find(key); }
		iterator find(const Key &key, std::size_t id31) {
			return m_ht.find(key, id31);
		}
		const_iterator find(const Key &key) const { return m_ht.find(key); }
		const_iterator find(const Key &key, std::size_t id31) const {
			return m_ht.find(key, id31);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		iterator find(const K &key) {
			return m_ht.find(key);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		iterator find(const K &key, std::size_t id31) {
			return m_ht.find(key, id31);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		const_iterator find(const K &key) const {
			return m_ht.find(key);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		const_iterator find(const K &key, std::size_t id31) const {
			return m_ht.find(key, id31);
		}
		bool contains(const Key &key) const { return m_ht.contains(key); }
		bool contains(const Key &key, std::size_t id31) const {
			return m_ht.contains(key, id31);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		bool contains(const K &key) const {
			return m_ht.contains(key);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		bool contains(const K &key, std::size_t id31) const {
			return m_ht.contains(key, id31);
		}
		std::pair<iterator, iterator> equal_range(const Key &key) { return m_ht.equal_range(key); }
		std::pair<iterator, iterator> equal_range(const Key &key, std::size_t id31) {
			return m_ht.equal_range(key, id31);
		}
		std::pair<const_iterator, const_iterator> equal_range(const Key &key) const {
			return m_ht.equal_range(key);
		}
		std::pair<const_iterator, const_iterator>
		equal_range(const Key &key, std::size_t id31) const {
			return m_ht.equal_range(key, id31);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		std::pair<iterator, iterator> equal_range(const K &key) {
			return m_ht.equal_range(key);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		std::pair<iterator, iterator> equal_range(const K &key, std::size_t id31) {
			return m_ht.equal_range(key, id31);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		std::pair<const_iterator, const_iterator> equal_range(const K &key) const {
			return m_ht.equal_range(key);
		}
		template <class K, class KE = KeyEqual,
				  typename std::enable_if<has_is_transparent<KE>::value>::type * = nullptr>
		std::pair<const_iterator, const_iterator>
		equal_range(const K &key, std::size_t id31) const {
			return m_ht.equal_range(key, id31);
		}
		size_type bucket_count() const { return m_ht.bucket_count(); }
		size_type max_bucket_count() const { return m_ht.max_bucket_count(); }
		float load_factor() const { return m_ht.load_factor(); }
		float id19() const { return m_ht.id19(); }
		float id30() const { return m_ht.id30(); }
		void id19(float ml) { m_ht.id19(ml); }
		void id30(float ml) { m_ht.id30(ml); }
		void rehash(size_type count) { m_ht.rehash(count); }
		void reserve(size_type count) { m_ht.reserve(count); }
		hasher hash_function() const { return m_ht.hash_function(); }
		key_equal key_eq() const { return m_ht.key_eq(); }
		iterator mutable_iterator(const_iterator pos) { return m_ht.mutable_iterator(pos); }
		friend bool operator==(const id14 &lhs, const id14 &rhs) {
			if (lhs.size() != rhs.size()) {
				return false;
			}
 
			for (const auto &id34 : lhs) {
				const auto id11 = rhs.find(id34.first);
				if (id11 == rhs.cend() || id34.second != id11->second) {
					return false;
				}
			}
 
			return true;
		}
 
		friend bool operator!=(const id14 &lhs, const id14 &rhs) {
			return !operator==(lhs, rhs);
		}
 
		friend void swap(id14 &lhs, id14 &rhs) { lhs.swap(rhs); }
 
	  private:
		ht m_ht;
	};
	template <class Key, class T, class Hash = std::hash<Key>, class KeyEqual = std::equal_to<Key>,
			  class Allocator = std::allocator<std::pair<Key, T>>, bool StoreHash = false>
	using robin_pg_map =
		id14<Key, T, Hash, KeyEqual, Allocator, StoreHash, tsl::rh::id24>;
 
} 

  
 
using namespace std;
 
typedef double C;
typedef complex<C> P;
 











 

 
mt19937_64 rnd(std::chrono::system_clock::now().time_since_epoch().count());
 
const int MAXN = 2e5 + 10;
 
int n, c, d = 0, ans = 0;
vector<int> a;
vector<int> indexes[MAXN];
vector<int> last, next;
tsl::id14<int, int> ctr;
 
void calcIndexes() {
	for (int i = 0; i < n; i++)
		indexes[a[i]].push_back(i);
}
 
void calcLast() {
	last.resize(n);
	int cur = -1;
	for (int i = 0; i < n; i++) {
		last[i] = cur;
		if (a[i] == d)
			cur = i;
	}
}
 
void calcNext() {
	next.resize(n);
	int cur = n;
	for (int i = n - 1; i >= 0; i--) {
		next[i] = cur;
		if (a[i] == d)
			cur = i;
	}
}
 
void calcOrder(int ind, vector<int> &order) {
	int el = a[ind], need = ctr[el] + 1;
	vector<int> l, r;
	int j = last[ind];
	while (l.size() < need) {
		l.push_back(j);
		if (*l.rbegin() == -1)
			break;
		j = last[j];
	}
	j = next[ind];
	while (r.size() < need) {
		r.push_back(j);
		if (*r.rbegin() == n)
			break;
		j = next[j];
	}
	reverse(all(l));
	l.insert(l.end(), r.begin(), r.end());
	int sz = indexes[el].size() + l.size();
	order.resize(sz);
	merge(all(indexes[el]), all(l), order.begin());
}
 
void id5(vector<int> &order, vector<int> &pfl) {
	int sum = 0;
	for (int i = 0; i < order.size(); i++) {
		if (i > 0)
			pfl.push_back(sum);
		if (0 <= order[i] && order[i] < n) {
			if (a[order[i]] == d)
				sum++;
			else if (a[order[i]] != d)
				sum--;
		}
	}
}
 
void id41(vector<int> &order, vector<int> &pfr) {
	int sum = 0;
	for (int i = 0; i < order.size() - 1; i++) {
		if (0 <= order[i] && order[i] < n) {
			if (a[order[i]] == d)
				sum++;
			else if (a[order[i]] != d)
				sum--;
		}
		pfr.push_back(sum);
	}
}
 
void smartSolve(int ind) {
	int el = a[ind], need = ctr[el] + 1;
	vector<int> order;
	calcOrder(ind, order);
 
	vector<int> pfl, pfr;
	id5(order, pfl);
	id41(order, pfr);
 
	int id22 = 3 * c + 10;
	vector<int> last(2 * id22, -2);
 
	for (int j = 0; j < pfr.size(); j++)
		if (last[pfr[j] + id22] == -2)
			last[pfr[j] + id22] = order[j];
 
	for (int j = 0; j < pfl.size(); j++) 
		if (last[pfl[j] + id22] != -2 && order[j] >= ind && last[pfl[j] + id22] <= ind)
			ans = max(ans, order[j + 1] - 1 - last[pfl[j] + id22]);
}
 
void id18(int el) {
	if (el == d) return;
 
	vector<int> pf(n);
 
	if (a[0] == el) pf[0]++;
	if (a[0] == d) pf[0]--;
	for (int j = 1; j < n; j++) {
		if (a[j] == el) pf[j]++;
		if (a[j] == d) pf[j]--;
		pf[j] += pf[j - 1];
	}
	vector<int> last(2 * n, -1);
	for (int j = 0; j < n; j++)
		if (last[pf[j] + n] == -1)
			last[pf[j] + n] = j;
 
	for (int j = 0; j < n; j++) {
		if (pf[j] == 0)
			ans = max(ans, j + 1);
		else if (last[pf[j] + n] != -1)
			ans = max(ans, j - last[pf[j] + n]);
	}
}
 
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	

	

 
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
 
	for (auto &i : a)
		ctr[i]++;
 
	for (auto &i : ctr)
		if (i.second > ctr[d])
			d = i.first;
 
	calcIndexes();
	calcLast();
	calcNext();
 
	c = 180;
 
	int last = -1;
	for (auto &i : ctr) {
		if (i.first == d)
			continue;
		if (i.second >= c)
			id18(i.first);
		else
			for (auto &j : indexes[i.first])
				smartSolve(j);
	}
 
	cout << ans;
	return 0;
}
