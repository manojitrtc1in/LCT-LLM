



























using namespace std;















typedef pair<int, int> PII;

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		

		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t id15 = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + id15);
	}
};

unordered_map<long long, int, custom_hash> safe_map;

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;























namespace boost
{
	const char g_iteratorsOutOufBoundsException[] = "Iterator's operation exceeded bounds";

	template<typename ValueType, typename Comparator = std::less<ValueType> >
	class id16
	{
	private:

		template<typename TypeOfValue>
		class tree_node
		{
			typedef tree_node<TypeOfValue>* self_pointer;
			typedef const tree_node<TypeOfValue>* self_const_pointer;

		public:

			tree_node(const TypeOfValue& p_value) :
				m_left(0),
				m_right(0),
				m_parent(0),
				m_isRed(false),
				m_subtreeSize(1),
				m_value(p_value)
			{}

			self_pointer		 m_left;
			self_pointer		 m_right;
			self_pointer		 m_parent;
			bool			     m_isRed;
			size_t				 m_subtreeSize;
			TypeOfValue			 m_value;

			size_t leftSize() const
			{
				if (m_left == 0) return 0;
				else return m_left->m_subtreeSize;
			}

			size_t rightSize() const
			{
				if (m_right == 0) return 0;
				else return m_right->m_subtreeSize;
			}

			self_pointer min() const
			{
				self_const_pointer l_result = this;
				while (l_result->m_left != 0)
					l_result = l_result->m_left;
				return const_cast<self_pointer>(l_result);
			}

			self_pointer max() const
			{
				self_const_pointer l_result = this;
				while (l_result->m_right != 0)
					l_result = l_result->m_right;
				return const_cast<self_pointer>(l_result);
			}

			self_pointer previous() const
			{
				self_const_pointer id29 = this;
				if (id29->m_left != 0) return id29->m_left->max();

				self_const_pointer id1 = id29->m_parent;
				while (id29 == id1->m_left)
				{
					id29 = id1;
					id1 = id1->m_parent;
				}

				if (!id29->isEnd())
				{
					id29 = id1;
				}

				return const_cast<self_pointer>(id29);
			}

			self_pointer next() const
			{
				self_const_pointer id29 = this;
				if (id29->m_right != 0) return id29->m_right->min();

				self_const_pointer id1 = id29->m_parent;
				while (id29 == id1->m_right)
				{
					id29 = id1;
					id1 = id1->m_parent;
				}

				if (!id29->isEnd())
				{
					id29 = id1;
				}

				return const_cast<self_pointer>(id29);
			}

			size_t position() const
			{
				if (m_parent == 0) return 0;
				if (isEnd()) return m_parent->m_subtreeSize;

				size_t id20 = leftSize();
				self_const_pointer id29 = this;

				while (!id29->isEnd())
				{
					if (id29 == id29->m_parent->m_right)
					{
						id20 += id29->m_parent->leftSize() + 1;
					}
					id29 = id29->m_parent;
				}

				return id20 - id29->m_parent->m_subtreeSize - 1; 

			}

			size_t reversePosition() const
			{
				if (m_parent == 0) return 0;
				if (isEnd()) return m_parent->m_subtreeSize;

				size_t id20 = rightSize();
				self_const_pointer id29 = this;

				while (!id29->isEnd())
				{
					if (id29 == id29->m_parent->m_left)
					{
						id20 += id29->m_parent->rightSize() + 1;
					}
					id29 = id29->m_parent;
				}

				return id20 - id29->m_parent->m_subtreeSize - 1; 

			}

			inline bool isEnd() const
			{
				return m_parent == m_right;
			}
		};

		typedef tree_node<ValueType> node;
		typedef tree_node<ValueType>* node_pointer;
		typedef const tree_node<ValueType>* const_node_pointer;
		typedef id16<ValueType, Comparator>& tree_reference;

	public:

		template<typename TypeOfValue>
		class citerator
		{
			typedef citerator<TypeOfValue>				self;
			typedef tree_node<TypeOfValue>				node;
			friend class id16<TypeOfValue, Comparator>;
		public:
			typedef std::bidirectional_iterator_tag		iterator_category;
			typedef ptrdiff_t							difference_type;
			typedef TypeOfValue							value_type;
			typedef const TypeOfValue*					pointer;
			typedef const TypeOfValue&					reference;

			explicit citerator(const node* p_pointingNode = 0) : id5(p_pointingNode) {}

			reference operator*() const
			{
				return id5->m_value;
			}

			pointer operator->() const
			{
				return &(id5->m_value);
			}

			inline bool operator==(const self& p_rhs) const
			{
				return id5 == p_rhs.id5;
			}

			inline bool operator!=(const self& p_rhs) const
			{
				return id5 != p_rhs.id5;
			}

			self& operator++()
			{
				if (id5->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				id5 = id5->next();
				return *this;
			}

			self operator++(int)
			{
				if (id5->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				self id14 = *this;
				id5 = id5->next();
				return id14;
			}

			self& operator--()
			{
				const node* id8 = id5->previous();
				if (id8->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				id5 = id8;
				return *this;
			}

			self operator--(int)
			{
				const node* id8 = id5->previous();
				if (id8->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				self id14 = *this;
				id5 = id8;
				return id14;
			}

			size_t position() const
			{
				return id5->position();
			}

		private:
			const node* id5;
		};
		


		template<typename TypeOfValue>
		class niterator
		{
			typedef niterator<TypeOfValue>				self;
			typedef tree_node<TypeOfValue>				node;
			friend class id16<TypeOfValue, Comparator>;
		public:
			typedef std::bidirectional_iterator_tag		iterator_category;
			typedef ptrdiff_t							difference_type;
			typedef TypeOfValue							value_type;
			typedef TypeOfValue*						pointer;
			typedef TypeOfValue&						reference;

			explicit niterator(node* p_pointingNode = 0) : id5(p_pointingNode) {}

			reference operator*() const
			{
				return id5->m_value;
			}

			pointer operator->() const
			{
				return &(id5->m_value);
			}

			inline bool operator==(const self& p_rhs) const
			{
				return id5 == p_rhs.id5;
			}

			inline bool operator!=(const self& p_rhs) const
			{
				return id5 != p_rhs.id5;
			}

			self& operator++()
			{
				if (id5->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				id5 = id5->next();
				return *this;
			}

			self operator++(int)
			{
				if (id5->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				self id14 = *this;
				id5 = id5->next();
				return id14;
			}

			self& operator--()
			{
				node* id8 = id5->previous();
				if (id8->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				id5 = id8;
				return *this;
			}

			self operator--(int)
			{
				node* id8 = id5->previous();
				if (id8->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				self id14 = *this;
				id5 = id8;
				return id14;
			}

			size_t position() const
			{
				return id5->position();
			}

			operator citerator<ValueType>() const
			{
				return citerator<ValueType>(id5);
			}

		private:
			node* id5;
		};
		


		template<typename TypeOfValue>
		class criterator
		{
			typedef criterator<TypeOfValue>				self;
			typedef tree_node<TypeOfValue>				node;
			friend class id16<TypeOfValue, Comparator>;
		public:
			typedef std::bidirectional_iterator_tag		iterator_category;
			typedef ptrdiff_t							difference_type;
			typedef TypeOfValue							value_type;
			typedef const TypeOfValue*					pointer;
			typedef const TypeOfValue&					reference;

			explicit criterator(const node* p_pointingNode = 0) : id5(p_pointingNode) {}

			reference operator*() const
			{
				return id5->m_value;
			}

			pointer operator->() const
			{
				return &(id5->m_value);
			}

			inline bool operator==(const self& p_rhs) const
			{
				return id5 == p_rhs.id5;
			}

			inline bool operator!=(const self& p_rhs) const
			{
				return id5 != p_rhs.id5;
			}

			self& operator++()
			{
				if (id5->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				id5 = id5->previous();
				return *this;
			}

			self operator++(int)
			{
				if (id5->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				self id14 = *this;
				id5 = id5->previous();
				return id14;
			}

			self& operator--()
			{
				const node* id8 = id5->next();
				if (id8->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				id5 = id8;
				return *this;
			}

			self operator--(int)
			{
				const node* id8 = id5->next();
				if (id8->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				self id14 = *this;
				id5 = id8;
				return id14;
			}

			size_t position() const
			{
				return id5->reversePosition();
			}

		private:
			const node* id5;
		};
		


		template<typename TypeOfValue>
		class riterator
		{
			typedef riterator<TypeOfValue>				self;
			typedef tree_node<TypeOfValue>				node;
			friend class id16<TypeOfValue, Comparator>;
		public:
			typedef std::bidirectional_iterator_tag		iterator_category;
			typedef ptrdiff_t							difference_type;
			typedef TypeOfValue							value_type;
			typedef const TypeOfValue*					pointer;
			typedef const TypeOfValue&					reference;

			explicit riterator(node* p_pointingNode = 0) : id5(p_pointingNode) {}

			reference operator*() const
			{
				return id5->m_value;
			}

			pointer operator->() const
			{
				return &(id5->m_value);
			}

			inline bool operator==(const self& p_rhs) const
			{
				return id5 == p_rhs.id5;
			}

			inline bool operator!=(const self& p_rhs) const
			{
				return id5 != p_rhs.id5;
			}

			self& operator++()
			{
				if (id5->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				id5 = id5->previous();
				return *this;
			}

			self operator++(int)
			{
				if (id5->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				self id14 = *this;
				id5 = id5->previous();
				return id14;
			}

			self& operator--()
			{
				node* id8 = id5->next();
				if (id8->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				id5 = id8;
				return *this;
			}

			self operator--(int)
			{
				node* id8 = id5->next();
				if (id8->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				self id14 = *this;
				id5 = id8;
				return id14;
			}

			size_t position() const
			{
				return id5->reversePosition();
			}

			operator criterator<ValueType>() const
			{
				return criterator<ValueType>(id5);
			}

			operator niterator<ValueType>() const
			{
				return niterator<ValueType>(id5);
			}

		private:
			node* id5;
		};
		


		typedef niterator<ValueType> iterator;
		typedef citerator<ValueType> const_iterator;
		typedef riterator<ValueType> reverse_iterator;
		typedef criterator<ValueType> const_reverse_iterator;

		id16(const Comparator& id12 = Comparator()) : m_end(ValueType()), id24(id12), m_size(0)
		{
			setRoot(0);
		}

		id16(const tree_reference id33) : m_end(ValueType()), m_size(0)
		{
			setRoot(0);
			this->operator=(id33);
		}

		template <typename InputIterator>
		id16(InputIterator id31, const InputIterator & id10, const Comparator& id12 = Comparator()) : m_end(ValueType()), id24(id12), m_size(0)
		{
			setRoot(0);
			while (id31 != id10)
			{
				insert(*id31);
				++id31;
			}
		}

		~id16()
		{
			clear();
		}

		iterator begin()
		{
			return iterator(m_root != 0 ? m_root->min() : &m_end);
		}

		iterator end()
		{
			return iterator(&m_end);
		}

		const_iterator cbegin() const
		{
			return const_iterator(m_root != 0 ? m_root->min() : &m_end);
		}

		const_iterator cend() const
		{
			return const_iterator(&m_end);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(m_root != 0 ? m_root->max() : &m_end);
		}

		reverse_iterator rend()
		{
			return reverse_iterator(&m_end);
		}

		const_reverse_iterator crbegin() const
		{
			return const_reverse_iterator(m_root != 0 ? m_root->max() : &m_end);
		}

		const_reverse_iterator crend() const
		{
			return const_reverse_iterator(&m_end);
		}

		std::pair<iterator, bool> insert(const ValueType& id28)
		{
			node_pointer id23 = new node(id28);
			insertAndRebalance(id23);

			return std::make_pair(iterator(id23), true);
		}

		size_t erase(const ValueType& id37)
		{
			std::pair<iterator, iterator> id35 = equal_range(id37);
			size_t id6 = m_size;
			erase(id35.first, id35.second);
			return id6 - m_size;
		}

		iterator erase(const_iterator p_begin, const_iterator p_end)
		{
			while (p_begin != p_end)
			{
				node_pointer id17 = const_cast<node_pointer>(p_begin.id5);
				++p_begin;
				deleteNode(id17);
			}
			return iterator(const_cast<node_pointer>(p_end.id5));
		}

		iterator erase(const_iterator id30)
		{
			node_pointer id17 = const_cast<node_pointer>(id30.id5);
			node_pointer id9 = id17->next();
			deleteNode(id17);
			return iterator(id9);
		}

		size_t count(const ValueType& id18)
		{
			std::pair<iterator, iterator> id35 = equal_range(id18);
			return id35.second.position() - id35.first.position();
		}

		iterator find(const ValueType& id18) const
		{
			iterator id3 = lower_bound(id18);
			return (*const_cast<Comparator*>(&id24))(id18, *id3) ? iterator(const_cast<node_pointer>(&m_end)) : id3;
		}

		iterator lower_bound(const ValueType& id18) const
		{
			return lower_bound_impl(id18, m_root, &m_end);
		}

		iterator upper_bound(const ValueType& id18) const
		{
			return upper_bound_impl(id18, m_root, &m_end);
		}

		std::pair<iterator, iterator> equal_range(const ValueType& id18) const
		{
			const_node_pointer id29 = m_root;
			const_node_pointer id3 = &m_end;
			Comparator* l_comparator = const_cast<Comparator*>(&id24);

			while (id29 != 0)
			{
				if ((*l_comparator)(id29->m_value, id18))
				{
					id29 = id29->m_right;
				}
				else if ((*l_comparator)(id18, id29->m_value))
				{
					id3 = id29;
					id29 = id29->m_left;
				}
				else
				{
					const_node_pointer id38 = id29;
					const_node_pointer id2 = id3;
					id3 = id29;
					id29 = id29->m_left;
					id38 = id38->m_right;

					return std::make_pair(lower_bound_impl(id18, id29, id3),
						upper_bound_impl(id18, id38, id2));
				}
			}

			return std::make_pair(iterator(const_cast<node_pointer>(id3)), iterator(const_cast<node_pointer>(id3)));
		}

		iterator operator[](size_t p_order) const
		{
			return iterator(selectK(m_root, ++p_order));
		}

		inline size_t size() const
		{
			return m_size;
		}

		inline bool empty() const
		{
			return !m_size;
		}

		void clear()
		{
			deleteTree(m_root);
			setRoot(0);
			m_size = 0;
		}

		void swap(tree_reference id11)
		{
			std::swap(id11.m_size, m_size);
			std::swap(id11.m_root, m_root);
			std::swap(id11.m_end.m_left, m_end.m_left);
			std::swap(id11.m_end.m_right, m_end.m_right);
			std::swap(id11.m_end.m_parent, m_end.m_parent);
			std::swap(id11.id24, id24);

			if (m_root)
			{
				m_root->m_parent = &m_end;
			}

			if (id11.m_root)
			{
				id11.m_root->m_parent = &id11.m_end;
			}
		}

		tree_reference operator=(const tree_reference id33)
		{
			if (this != &id33)
			{
				clear();
				copy(id33.m_root, m_root);
				setRoot(m_root);
				m_size = id33.m_size;
				id24 = id33.id24;
			}

			return *this;
		}

		Comparator key_comp() const
		{
			return id24;
		}

	private:

		void leftRotation(node_pointer id25)
		{
			node_pointer id13 = id25->m_right;
			id25->m_right = id13->m_left;
			if (id13->m_left != 0)
			{
				id13->m_left->m_parent = id25;
			}
			id13->m_parent = id25->m_parent;
			if (id25->m_parent == &m_end)
			{
				setRoot(id13);
			}
			else
			{
				if (id25 == id25->m_parent->m_left)
				{
					id25->m_parent->m_left = id13;
				}
				else
				{
					id25->m_parent->m_right = id13;
				}
			}
			id13->m_left = id25;
			id25->m_parent = id13;

			id13->m_subtreeSize = id25->m_subtreeSize;
			id25->m_subtreeSize = id25->leftSize() + id25->rightSize() + 1;
		}

		void rightRotation(node_pointer id25)
		{
			node_pointer id13 = id25->m_left;
			id25->m_left = id13->m_right;
			if (id13->m_right != 0)
			{
				id13->m_right->m_parent = id25;
			}
			id13->m_parent = id25->m_parent;
			if (id25->m_parent == &m_end)
			{
				setRoot(id13);
			}
			else
			{
				if (id25 == id25->m_parent->m_right)
				{
					id25->m_parent->m_right = id13;
				}
				else
				{
					id25->m_parent->m_left = id13;
				}
			}
			id13->m_right = id25;
			id25->m_parent = id13;

			id13->m_subtreeSize = id25->m_subtreeSize;
			id25->m_subtreeSize = id25->leftSize() + id25->rightSize() + 1;
		}

		inline void setRoot(node_pointer id21)
		{
			m_root = id21;
			m_end.m_left = id21;
			m_end.m_right = id21;
			m_end.m_parent = id21;
			if (id21 != 0)
			{
				id21->m_parent = &m_end;
			}
		}

		void insertAndRebalance(node_pointer id22)
		{
			appendNode(id22);
			id22->m_isRed = true;
			node_pointer id4;
			while (id22 != m_root && id22->m_parent->m_isRed)
			{
				if (id22->m_parent->m_parent != &m_end && id22->m_parent == id22->m_parent->m_parent->m_left)
				{
					id4 = id22->m_parent->m_parent->m_right;
					if (id4 != 0 && id4->m_isRed)
					{
						id22->m_parent->m_isRed = false;
						id4->m_isRed = false;
						id22->m_parent->m_parent->m_isRed = true;
						id22 = id22->m_parent->m_parent;
					}
					else
					{
						if (id22 == id22->m_parent->m_right)
						{
							id22 = id22->m_parent;
							leftRotation(id22);
						}
						id22->m_parent->m_isRed = false;
						if (id22->m_parent->m_parent != &m_end)
						{
							id22->m_parent->m_parent->m_isRed = true;
							rightRotation(id22->m_parent->m_parent);
						}
					}
				}
				else
				{
					if (id22->m_parent->m_parent != &m_end && (id4 = id22->m_parent->m_parent->m_left) != 0 && id4->m_isRed)
					{
						id22->m_parent->m_isRed = false;
						id4->m_isRed = false;
						id22->m_parent->m_parent->m_isRed = true;
						id22 = id22->m_parent->m_parent;
					}
					else
					{
						if (id22 == id22->m_parent->m_left)
						{
							id22 = id22->m_parent;
							rightRotation(id22);
						}
						id22->m_parent->m_isRed = false;
						if (id22->m_parent->m_parent != &m_end)
						{
							id22->m_parent->m_parent->m_isRed = true;
							leftRotation(id22->m_parent->m_parent);
						}
					}
				}
			}
			m_root->m_isRed = false;
		}

		void appendNode(node_pointer id19)
		{
			node_pointer id26 = &m_end;
			node_pointer id34 = m_root;

			while (id34 != 0)
			{
				id26 = id34;
				++(id34->m_subtreeSize);
				if (id24(id19->m_value, id34->m_value))
				{
					id34 = id34->m_left;
				}
				else
				{
					id34 = id34->m_right;
				}
			}

			id19->m_parent = id26;
			if (id26 == &m_end)
			{
				setRoot(id19);
			}
			else
			{
				if (id24(id19->m_value, id26->m_value))
				{
					id26->m_left = id19;
				}
				else
				{
					id26->m_right = id19;
				}
			}
			++m_size;
		}

		node_pointer selectK(node_pointer p_root, size_t p_index) const
		{
			if (p_root == 0 || p_root->m_subtreeSize < p_index) return const_cast<node_pointer>(&m_end);

			while (true)
			{
				size_t id20 = p_root->leftSize() + 1;
				if (p_index == id20) return p_root;
				else if (p_index < id20)
				{
					p_root = p_root->m_left;
				}
				else
				{
					p_root = p_root->m_right;
					p_index -= id20;
				}
			}
		}

		void deleteTree(node_pointer id7)
		{
			if (id7 != 0)
			{
				deleteTree(id7->m_left);
				deleteTree(id7->m_right);
				delete id7;
				--m_size;
			}
		}

		iterator lower_bound_impl(const ValueType& id18, const_node_pointer id32, const_node_pointer id0) const
		{
			Comparator* l_comparator = const_cast<Comparator*>(&id24);
			while (id32 != 0)
			{
				if ((*l_comparator)(id32->m_value, id18))
				{
					id32 = id32->m_right;
				}
				else
				{
					id0 = id32;
					id32 = id32->m_left;
				}
			}

			return iterator(const_cast<node_pointer>(id0));
		}

		iterator upper_bound_impl(const ValueType& id18, const_node_pointer id32, const_node_pointer id0) const
		{
			Comparator* l_comparator = const_cast<Comparator*>(&id24);
			while (id32 != 0)
			{
				if ((*l_comparator)(id18, id32->m_value))
				{
					id0 = id32;
					id32 = id32->m_left;
				}
				else
				{
					id32 = id32->m_right;
				}
			}

			return iterator(const_cast<node_pointer>(id0));
		}

		void copy(const tree_node<ValueType>* const p_copySource, tree_node<ValueType>* & id36)
		{
			if (p_copySource != 0)
			{
				id36 = new node(p_copySource->m_value);

				id36->m_isRed = p_copySource->m_isRed;
				id36->m_subtreeSize = p_copySource->m_subtreeSize;

				copy(p_copySource->m_left, id36->m_left);
				if (id36->m_left != 0) id36->m_left->m_parent = id36;

				copy(p_copySource->m_right, id36->m_right);
				if (id36->m_right != 0) id36->m_right->m_parent = id36;
			}
		}

		void deleteNode(node_pointer id7)
		{
			ValueType v;
			node null(v);
			null.m_subtreeSize = 0;

			node_pointer y = 0;
			node_pointer x = 0;

			if (id7->m_left == 0 || id7->m_right == 0)
			{
				y = id7;
			}
			else
			{
				y = id7->next();
			}

			if (y->m_left != 0)
			{
				x = y->m_left;
			}
			else
			{
				x = y->m_right;
			}

			if (x == 0)
			{
				x = &null;
			}

			node_pointer id27 = y;
			while (id27 != &m_end)
			{
				--(id27->m_subtreeSize);
				id27 = id27->m_parent;
			}

			if (id7 != y)
			{
				id7->m_left->m_parent = y;
				y->m_left = id7->m_left;

				if (y != id7->m_right)
				{
					x->m_parent = y->m_parent;
					y->m_parent->m_left = x;
					y->m_right = id7->m_right;
					id7->m_right->m_parent = y;
				}
				else
				{
					x->m_parent = y;
				}

				if (id7 == m_root)
				{
					setRoot(y);
				}
				else if (id7->m_parent->m_left == id7)
				{
					id7->m_parent->m_left = y;
				}
				else
				{
					id7->m_parent->m_right = y;
				}

				y->m_parent = id7->m_parent;
				std::swap(y->m_isRed, id7->m_isRed);
				y->m_subtreeSize = id7->m_subtreeSize;
				y = id7;
			}
			else
			{
				x->m_parent = y->m_parent;
				if (m_root == id7)
				{
					setRoot(x);
				}
				else if (id7->m_parent->m_left == id7)
				{
					id7->m_parent->m_left = x;
				}
				else
				{
					id7->m_parent->m_right = x;
				}
			}

			if (!y->m_isRed)
			{
				RBdeleteFix(x);
			}

			if (x == &null)
			{
				if (m_root == &null)
				{
					setRoot(0);
				}
				else if (x->m_parent->m_left == x)
				{
					x->m_parent->m_left = 0;
				}
				else
				{
					x->m_parent->m_right = 0;
				}
			}

			--m_size;
			delete y;
		}

		void RBdeleteFix(node_pointer x)
		{
			node_pointer w = 0;
			while (x != m_root && !x->m_isRed)
			{
				if (x == x->m_parent->m_left)
				{
					w = x->m_parent->m_right;
					if (w->m_isRed)
					{
						w->m_isRed = false;
						x->m_parent->m_isRed = true;
						leftRotation(x->m_parent);
						w = x->m_parent->m_right;
					}
					if ((w->m_left == 0 || !w->m_left->m_isRed) && (w->m_right == 0 || !w->m_right->m_isRed))
					{
						w->m_isRed = true;
						x = x->m_parent;
					}
					else
					{
						if (w->m_right == 0 || !w->m_right->m_isRed)
						{
							w->m_left->m_isRed = false;
							w->m_isRed = true;
							rightRotation(w);
							w = x->m_parent->m_right;
						}
						w->m_isRed = x->m_parent->m_isRed;
						x->m_parent->m_isRed = false;
						if (w->m_right != 0)
							w->m_right->m_isRed = false;
						leftRotation(x->m_parent);
						x = m_root;
					}
				}
				else
				{
					w = x->m_parent->m_left;
					if (w->m_isRed)
					{
						w->m_isRed = false;
						x->m_parent->m_isRed = true;
						rightRotation(x->m_parent);
						w = x->m_parent->m_left;
					}
					if ((w->m_right == 0 || !w->m_right->m_isRed) && (w->m_left == 0 || !w->m_left->m_isRed))
					{
						w->m_isRed = true;
						x = x->m_parent;
					}
					else
					{
						if (w->m_left == 0 || !w->m_left->m_isRed)
						{
							w->m_right->m_isRed = false;
							w->m_isRed = true;
							leftRotation(w);
							w = x->m_parent->m_left;
						}
						w->m_isRed = x->m_parent->m_isRed;
						x->m_parent->m_isRed = false;
						if (w->m_left != 0)
							w->m_left->m_isRed = false;
						rightRotation(x->m_parent);
						x = m_root;
					}
				}
			}
			x->m_isRed = false;
		}

		node			m_end;
		Comparator		id24;
		size_t			m_size;
		node_pointer	m_root;
	};

} 






const int MR = 2e5 + 10;

int a[MR], res[MR];

vector<PII> Q[MR];

int main()
{
	boost::id16 < int > T;
	

	


	map<int, vector<int>> M;

	int n;
	scanf("%d", &n);
	REP(i, n)
	{
		scanf("%d", &a[i]);
		M[a[i]].push_back(i);
	}

	for (auto &p : M)
		reverse(p.second.begin(), p.second.end());

	int m;
	scanf("%d", &m);
	REP(i, m)
	{
		int k, pos;
		scanf("%d%d", &k, &pos); pos--;
		Q[k].push_back(MP(pos, i));
	}

	FORQ(k, 1, n)
	{
		auto it = M.end(); it--;

		while (true)
		{
			if (it->second.empty())
				M.erase(it);
			else
				break;

			it = M.end(); it--;
		}

		T.insert(it->second.back());
		it->second.pop_back();

		

		for (const auto& p : Q[k])
		{
			int pos = *T[p.first];
			int v = a[pos];

			res[p.second] = v;
		}
	}

	REP(i, m)
		printf("%d\n", res[i]);

	return 0;
}





































