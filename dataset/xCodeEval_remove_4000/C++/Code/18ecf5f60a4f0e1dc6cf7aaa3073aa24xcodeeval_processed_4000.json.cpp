




















using namespace std;














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
                self_const_pointer id28 = this;
                if (id28->m_left != 0) return id28->m_left->max();

                self_const_pointer id1 = id28->m_parent;
                while (id28 == id1->m_left)
                {
                    id28 = id1;
                    id1 = id1->m_parent;
                }

                if (!id28->isEnd())
                {
                    id28 = id1;
                }

                return const_cast<self_pointer>(id28);
            }

            self_pointer next() const
            {
                self_const_pointer id28 = this;
                if (id28->m_right != 0) return id28->m_right->min();

                self_const_pointer id1 = id28->m_parent;
                while (id28 == id1->m_right)
                {
                    id28 = id1;
                    id1 = id1->m_parent;
                }

                if (!id28->isEnd())
                {
                    id28 = id1;
                }

                return const_cast<self_pointer>(id28);
            }

            size_t position() const
            {
                if (m_parent == 0) return 0;
                if (isEnd()) return m_parent->m_subtreeSize;

                size_t id19 = leftSize();
                self_const_pointer id28 = this;

                while (!id28->isEnd())
                {
                    if (id28 == id28->m_parent->m_right)
                    {
                        id19 += id28->m_parent->leftSize() + 1;
                    }
                    id28 = id28->m_parent;
                }

                return id19 - id28->m_parent->m_subtreeSize - 1; 

            }

            size_t reversePosition() const
            {
                if (m_parent == 0) return 0;
                if (isEnd()) return m_parent->m_subtreeSize;

                size_t id19 = rightSize();
                self_const_pointer id28 = this;

                while (!id28->isEnd())
                {
                    if (id28 == id28->m_parent->m_left)
                    {
                        id19 += id28->m_parent->rightSize() + 1;
                    }
                    id28 = id28->m_parent;
                }

                return id19 - id28->m_parent->m_subtreeSize - 1; 

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

        id16(const tree_reference id32) : m_end(ValueType()), m_size(0)
        {
            setRoot(0);
            this->operator=(id32);
        }

        template <typename InputIterator>
        id16(InputIterator id30, const InputIterator & id10, const Comparator& id12 = Comparator()) : m_end(ValueType()), id24(id12), m_size(0)
        {
            setRoot(0);
            while (id30 != id10)
            {
                insert(*id30);
                ++id30;
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

        std::pair<iterator, bool> insert(const ValueType& id27)
        {
            node_pointer id23 = new node(id27);
            insertAndRebalance(id23);

            return std::make_pair(iterator(id23), true);
        }

        size_t erase(const ValueType& id36)
        {
            std::pair<iterator, iterator> id34 = equal_range(id36);
            size_t id6 = m_size;
            erase(id34.first, id34.second);
            return id6 - m_size;
        }

        iterator erase(const_iterator p_begin, const_iterator p_end)
        {
            while (p_begin != p_end)
            {
                node_pointer id15 = const_cast<node_pointer>(p_begin.id5);
                ++p_begin;
                deleteNode(id15);
            }
            return iterator(const_cast<node_pointer>(p_end.id5));
        }

        iterator erase(const_iterator id29)
        {
            node_pointer id15 = const_cast<node_pointer>(id29.id5);
            node_pointer id9 = id15->next();
            deleteNode(id15);
            return iterator(id9);
        }

        size_t count(const ValueType& id17)
        {
            std::pair<iterator, iterator> id34 = equal_range(id17);
            return id34.second.position() - id34.first.position();
        }

        iterator find(const ValueType& id17) const
        {
            iterator id3 = lower_bound(id17);
            return (*const_cast<Comparator*>(&id24))(id17, *id3) ? iterator(const_cast<node_pointer>(&m_end)) : id3;
        }

        iterator lower_bound(const ValueType& id17) const
        {
            return lower_bound_impl(id17, m_root, &m_end);
        }

        iterator upper_bound(const ValueType& id17) const
        {
            return upper_bound_impl(id17, m_root, &m_end);
        }

        std::pair<iterator, iterator> equal_range(const ValueType& id17) const
        {
            const_node_pointer id28 = m_root;
            const_node_pointer id3 = &m_end;
            Comparator* l_comparator = const_cast<Comparator*>(&id24);

            while (id28 != 0)
            {
                if ((*l_comparator)(id28->m_value, id17))
                {
                    id28 = id28->m_right;
                }
                else if ((*l_comparator)(id17, id28->m_value))
                {
                    id3 = id28;
                    id28 = id28->m_left;
                }
                else
                {
                    const_node_pointer id37 = id28;
                    const_node_pointer id2 = id3;
                    id3 = id28;
                    id28 = id28->m_left;
                    id37 = id37->m_right;

                    return std::make_pair(lower_bound_impl(id17, id28, id3),
                        upper_bound_impl(id17, id37, id2));
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

        tree_reference operator=(const tree_reference id32)
        {
            if (this != &id32)
            {
                clear();
                copy(id32.m_root, m_root);
                setRoot(m_root);
                m_size = id32.m_size;
                id24 = id32.id24;
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

        inline void setRoot(node_pointer id20)
        {
            m_root = id20;
            m_end.m_left = id20;
            m_end.m_right = id20;
            m_end.m_parent = id20;
            if (id20 != 0)
            {
                id20->m_parent = &m_end;
            }
        }

        void insertAndRebalance(node_pointer id21)
        {
            appendNode(id21);
            id21->m_isRed = true;
            node_pointer id4;
            while (id21 != m_root && id21->m_parent->m_isRed)
            {
                if (id21->m_parent->m_parent != &m_end && id21->m_parent == id21->m_parent->m_parent->m_left)
                {
                    id4 = id21->m_parent->m_parent->m_right;
                    if (id4 != 0 && id4->m_isRed)
                    {
                        id21->m_parent->m_isRed = false;
                        id4->m_isRed = false;
                        id21->m_parent->m_parent->m_isRed = true;
                        id21 = id21->m_parent->m_parent;
                    }
                    else
                    {
                        if (id21 == id21->m_parent->m_right)
                        {
                            id21 = id21->m_parent;
                            leftRotation(id21);
                        }
                        id21->m_parent->m_isRed = false;
                        if (id21->m_parent->m_parent != &m_end)
                        {
                            id21->m_parent->m_parent->m_isRed = true;
                            rightRotation(id21->m_parent->m_parent);
                        }
                    }
                }
                else
                {
                    if (id21->m_parent->m_parent != &m_end && (id4 = id21->m_parent->m_parent->m_left) != 0 && id4->m_isRed)
                    {
                        id21->m_parent->m_isRed = false;
                        id4->m_isRed = false;
                        id21->m_parent->m_parent->m_isRed = true;
                        id21 = id21->m_parent->m_parent;
                    }
                    else
                    {
                        if (id21 == id21->m_parent->m_left)
                        {
                            id21 = id21->m_parent;
                            rightRotation(id21);
                        }
                        id21->m_parent->m_isRed = false;
                        if (id21->m_parent->m_parent != &m_end)
                        {
                            id21->m_parent->m_parent->m_isRed = true;
                            leftRotation(id21->m_parent->m_parent);
                        }
                    }
                }
            }
            m_root->m_isRed = false;
        }

        void appendNode(node_pointer id18)
        {
            node_pointer id22 = &m_end;
            node_pointer id33 = m_root;

            while (id33 != 0)
            {
                id22 = id33;
                ++(id33->m_subtreeSize);
                if (id24(id18->m_value, id33->m_value))
                {
                    id33 = id33->m_left;
                }
                else
                {
                    id33 = id33->m_right;
                }
            }

            id18->m_parent = id22;
            if (id22 == &m_end)
            {
                setRoot(id18);
            }
            else
            {
                if (id24(id18->m_value, id22->m_value))
                {
                    id22->m_left = id18;
                }
                else
                {
                    id22->m_right = id18;
                }
            }
            ++m_size;
        }

        node_pointer selectK(node_pointer p_root, size_t p_index) const
        {
            if (p_root == 0 || p_root->m_subtreeSize < p_index) return const_cast<node_pointer>(&m_end);

            while (true)
            {
                size_t id19 = p_root->leftSize() + 1;
                if (p_index == id19) return p_root;
                else if (p_index < id19)
                {
                    p_root = p_root->m_left;
                }
                else
                {
                    p_root = p_root->m_right;
                    p_index -= id19;
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

        iterator lower_bound_impl(const ValueType& id17, const_node_pointer id31, const_node_pointer id0) const
        {
            Comparator* l_comparator = const_cast<Comparator*>(&id24);
            while (id31 != 0)
            {
                if ((*l_comparator)(id31->m_value, id17))
                {
                    id31 = id31->m_right;
                }
                else
                {
                    id0 = id31;
                    id31 = id31->m_left;
                }
            }

            return iterator(const_cast< node_pointer >(id0));
        }

        iterator upper_bound_impl(const ValueType& id17, const_node_pointer id31, const_node_pointer id0) const
        {
            Comparator* l_comparator = const_cast<Comparator*>(&id24);
            while (id31 != 0)
            {
                if ((*l_comparator)(id17, id31->m_value))
                {
                    id0 = id31;
                    id31 = id31->m_left;
                }
                else
                {
                    id31 = id31->m_right;
                }
            }

            return iterator(const_cast< node_pointer >(id0));
        }

        void copy(const tree_node<ValueType>* const p_copySource, tree_node<ValueType>* & id35)
        {
            if (p_copySource != 0)
            {
                id35 = new node(p_copySource->m_value);

                id35->m_isRed = p_copySource->m_isRed;
                id35->m_subtreeSize = p_copySource->m_subtreeSize;

                copy(p_copySource->m_left, id35->m_left);
                if (id35->m_left != 0) id35->m_left->m_parent = id35;

                copy(p_copySource->m_right, id35->m_right);
                if (id35->m_right != 0) id35->m_right->m_parent = id35;
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

            node_pointer id26 = y;
            while (id26 != &m_end)
            {
                --(id26->m_subtreeSize);
                id26 = id26->m_parent;
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





int main()
{
    map < int, boost::id16 < int > > M;
    map < int, boost::id16 < int > > U;
    int n;
    scanf("%d", &n);
    REP(i, n)
    {
        int a, t, x;
        scanf("%d%d%d", &a, &t, &x);
        if (a == 1)
        {
            
            auto it = M.lower_bound(x);
            if (it == M.end() || it->first > x)
            {
                boost::id16 < int > pom;
                pom.insert(t);
                M[x] = pom;
            }
            else it->second.insert(t);
        }
        else if (a == 2)
        {
            auto it = U.lower_bound(x);
            if (it == U.end() || it->first > x)
            {
                boost::id16 < int > pom;
                pom.insert(t);
                U[x] = pom;
            }
            else it->second.insert(t);
        }
        else
        {
            auto it = M.find(x);
            if (it == M.end())
            {
                printf("0\n");
                continue;
            }
            auto it1 = it->second.upper_bound(t);
            if (it1 == it->second.begin())
            {
                printf("0\n");
                continue;
            }

            int cnt1 = (--it1).position() + 1;

            int cnt2;
            auto it3 = U.find(x);
            if (it3 == U.end()) cnt2 = 0;
            else
            {
                auto it4 = it3->second.upper_bound(t);
                if (it4 == it3->second.begin()) cnt2 = 0;
                else cnt2 = (--it4).position() + 1;
            }
            
            printf("%d\n", cnt1 - cnt2);
        }
    }
    return 0;
}