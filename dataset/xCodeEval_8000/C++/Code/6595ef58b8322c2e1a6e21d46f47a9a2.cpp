#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>		

#include <cassert>
#include <iomanip>		

#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define ALL(u) (u).begin(),(u).end()

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

typedef pair<int, int> PII;

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;


















#ifndef BOOST_ORDER_STATISTICS_HPP
#define BOOST_ORDER_STATISTICS_HPP

#include <stdexcept>

namespace boost
{
	const char g_iteratorsOutOufBoundsException[] = "Iterator's operation exceeded bounds";

	template<typename ValueType, typename Comparator = std::less<ValueType> >
	class order_statistics_tree
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
				self_const_pointer l_currentNode = this;
				if (l_currentNode->m_left != 0) return l_currentNode->m_left->max();

				self_const_pointer l_currentParent = l_currentNode->m_parent;
				while (l_currentNode == l_currentParent->m_left)
				{
					l_currentNode = l_currentParent;
					l_currentParent = l_currentParent->m_parent;
				}

				if (!l_currentNode->isEnd())
				{
					l_currentNode = l_currentParent;
				}

				return const_cast<self_pointer>(l_currentNode);
			}

			self_pointer next() const
			{
				self_const_pointer l_currentNode = this;
				if (l_currentNode->m_right != 0) return l_currentNode->m_right->min();

				self_const_pointer l_currentParent = l_currentNode->m_parent;
				while (l_currentNode == l_currentParent->m_right)
				{
					l_currentNode = l_currentParent;
					l_currentParent = l_currentParent->m_parent;
				}

				if (!l_currentNode->isEnd())
				{
					l_currentNode = l_currentParent;
				}

				return const_cast<self_pointer>(l_currentNode);
			}

			size_t position() const
			{
				if (m_parent == 0) return 0;
				if (isEnd()) return m_parent->m_subtreeSize;

				size_t l_lesserValuesCounter = leftSize();
				self_const_pointer l_currentNode = this;

				while (!l_currentNode->isEnd())
				{
					if (l_currentNode == l_currentNode->m_parent->m_right)
					{
						l_lesserValuesCounter += l_currentNode->m_parent->leftSize() + 1;
					}
					l_currentNode = l_currentNode->m_parent;
				}

				return l_lesserValuesCounter - l_currentNode->m_parent->m_subtreeSize - 1; 

			}

			size_t reversePosition() const
			{
				if (m_parent == 0) return 0;
				if (isEnd()) return m_parent->m_subtreeSize;

				size_t l_lesserValuesCounter = rightSize();
				self_const_pointer l_currentNode = this;

				while (!l_currentNode->isEnd())
				{
					if (l_currentNode == l_currentNode->m_parent->m_left)
					{
						l_lesserValuesCounter += l_currentNode->m_parent->rightSize() + 1;
					}
					l_currentNode = l_currentNode->m_parent;
				}

				return l_lesserValuesCounter - l_currentNode->m_parent->m_subtreeSize - 1; 

			}

			inline bool isEnd() const
			{
				return m_parent == m_right;
			}
		};

		typedef tree_node<ValueType> node;
		typedef tree_node<ValueType>* node_pointer;
		typedef const tree_node<ValueType>* const_node_pointer;
		typedef order_statistics_tree<ValueType, Comparator>& tree_reference;

	public:

		template<typename TypeOfValue>
		class citerator
		{
			typedef citerator<TypeOfValue>				self;
			typedef tree_node<TypeOfValue>				node;
			friend class order_statistics_tree<TypeOfValue, Comparator>;
		public:
			typedef std::bidirectional_iterator_tag		iterator_category;
			typedef ptrdiff_t							difference_type;
			typedef TypeOfValue							value_type;
			typedef const TypeOfValue*					pointer;
			typedef const TypeOfValue&					reference;

			explicit citerator(const node* p_pointingNode = 0) : m_pointingNode(p_pointingNode) {}

			reference operator*() const
			{
				return m_pointingNode->m_value;
			}

			pointer operator->() const
			{
				return &(m_pointingNode->m_value);
			}

			inline bool operator==(const self& p_rhs) const
			{
				return m_pointingNode == p_rhs.m_pointingNode;
			}

			inline bool operator!=(const self& p_rhs) const
			{
				return m_pointingNode != p_rhs.m_pointingNode;
			}

			self& operator++()
			{
				if (m_pointingNode->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				m_pointingNode = m_pointingNode->next();
				return *this;
			}

			self operator++(int)
			{
				if (m_pointingNode->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				self l_temporaryIterator = *this;
				m_pointingNode = m_pointingNode->next();
				return l_temporaryIterator;
			}

			self& operator--()
			{
				const node* l_previousNeighbor = m_pointingNode->previous();
				if (l_previousNeighbor->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				m_pointingNode = l_previousNeighbor;
				return *this;
			}

			self operator--(int)
			{
				const node* l_previousNeighbor = m_pointingNode->previous();
				if (l_previousNeighbor->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				self l_temporaryIterator = *this;
				m_pointingNode = l_previousNeighbor;
				return l_temporaryIterator;
			}

			size_t position() const
			{
				return m_pointingNode->position();
			}

		private:
			const node* m_pointingNode;
		};
		


		template<typename TypeOfValue>
		class niterator
		{
			typedef niterator<TypeOfValue>				self;
			typedef tree_node<TypeOfValue>				node;
			friend class order_statistics_tree<TypeOfValue, Comparator>;
		public:
			typedef std::bidirectional_iterator_tag		iterator_category;
			typedef ptrdiff_t							difference_type;
			typedef TypeOfValue							value_type;
			typedef TypeOfValue*						pointer;
			typedef TypeOfValue&						reference;

			explicit niterator(node* p_pointingNode = 0) : m_pointingNode(p_pointingNode) {}

			reference operator*() const
			{
				return m_pointingNode->m_value;
			}

			pointer operator->() const
			{
				return &(m_pointingNode->m_value);
			}

			inline bool operator==(const self& p_rhs) const
			{
				return m_pointingNode == p_rhs.m_pointingNode;
			}

			inline bool operator!=(const self& p_rhs) const
			{
				return m_pointingNode != p_rhs.m_pointingNode;
			}

			self& operator++()
			{
				if (m_pointingNode->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				m_pointingNode = m_pointingNode->next();
				return *this;
			}

			self operator++(int)
			{
				if (m_pointingNode->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				self l_temporaryIterator = *this;
				m_pointingNode = m_pointingNode->next();
				return l_temporaryIterator;
			}

			self& operator--()
			{
				node* l_previousNeighbor = m_pointingNode->previous();
				if (l_previousNeighbor->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				m_pointingNode = l_previousNeighbor;
				return *this;
			}

			self operator--(int)
			{
				node* l_previousNeighbor = m_pointingNode->previous();
				if (l_previousNeighbor->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				self l_temporaryIterator = *this;
				m_pointingNode = l_previousNeighbor;
				return l_temporaryIterator;
			}

			size_t position() const
			{
				return m_pointingNode->position();
			}

			operator citerator<ValueType>() const
			{
				return citerator<ValueType>(m_pointingNode);
			}

		private:
			node* m_pointingNode;
		};
		


		template<typename TypeOfValue>
		class criterator
		{
			typedef criterator<TypeOfValue>				self;
			typedef tree_node<TypeOfValue>				node;
			friend class order_statistics_tree<TypeOfValue, Comparator>;
		public:
			typedef std::bidirectional_iterator_tag		iterator_category;
			typedef ptrdiff_t							difference_type;
			typedef TypeOfValue							value_type;
			typedef const TypeOfValue*					pointer;
			typedef const TypeOfValue&					reference;

			explicit criterator(const node* p_pointingNode = 0) : m_pointingNode(p_pointingNode) {}

			reference operator*() const
			{
				return m_pointingNode->m_value;
			}

			pointer operator->() const
			{
				return &(m_pointingNode->m_value);
			}

			inline bool operator==(const self& p_rhs) const
			{
				return m_pointingNode == p_rhs.m_pointingNode;
			}

			inline bool operator!=(const self& p_rhs) const
			{
				return m_pointingNode != p_rhs.m_pointingNode;
			}

			self& operator++()
			{
				if (m_pointingNode->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				m_pointingNode = m_pointingNode->previous();
				return *this;
			}

			self operator++(int)
			{
				if (m_pointingNode->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				self l_temporaryIterator = *this;
				m_pointingNode = m_pointingNode->previous();
				return l_temporaryIterator;
			}

			self& operator--()
			{
				const node* l_previousNeighbor = m_pointingNode->next();
				if (l_previousNeighbor->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				m_pointingNode = l_previousNeighbor;
				return *this;
			}

			self operator--(int)
			{
				const node* l_previousNeighbor = m_pointingNode->next();
				if (l_previousNeighbor->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				self l_temporaryIterator = *this;
				m_pointingNode = l_previousNeighbor;
				return l_temporaryIterator;
			}

			size_t position() const
			{
				return m_pointingNode->reversePosition();
			}

		private:
			const node* m_pointingNode;
		};
		


		template<typename TypeOfValue>
		class riterator
		{
			typedef riterator<TypeOfValue>				self;
			typedef tree_node<TypeOfValue>				node;
			friend class order_statistics_tree<TypeOfValue, Comparator>;
		public:
			typedef std::bidirectional_iterator_tag		iterator_category;
			typedef ptrdiff_t							difference_type;
			typedef TypeOfValue							value_type;
			typedef const TypeOfValue*					pointer;
			typedef const TypeOfValue&					reference;

			explicit riterator(node* p_pointingNode = 0) : m_pointingNode(p_pointingNode) {}

			reference operator*() const
			{
				return m_pointingNode->m_value;
			}

			pointer operator->() const
			{
				return &(m_pointingNode->m_value);
			}

			inline bool operator==(const self& p_rhs) const
			{
				return m_pointingNode == p_rhs.m_pointingNode;
			}

			inline bool operator!=(const self& p_rhs) const
			{
				return m_pointingNode != p_rhs.m_pointingNode;
			}

			self& operator++()
			{
				if (m_pointingNode->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				m_pointingNode = m_pointingNode->previous();
				return *this;
			}

			self operator++(int)
			{
				if (m_pointingNode->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				self l_temporaryIterator = *this;
				m_pointingNode = m_pointingNode->previous();
				return l_temporaryIterator;
			}

			self& operator--()
			{
				node* l_previousNeighbor = m_pointingNode->next();
				if (l_previousNeighbor->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				m_pointingNode = l_previousNeighbor;
				return *this;
			}

			self operator--(int)
			{
				node* l_previousNeighbor = m_pointingNode->next();
				if (l_previousNeighbor->isEnd()) throw std::runtime_error(g_iteratorsOutOufBoundsException);
				self l_temporaryIterator = *this;
				m_pointingNode = l_previousNeighbor;
				return l_temporaryIterator;
			}

			size_t position() const
			{
				return m_pointingNode->reversePosition();
			}

			operator criterator<ValueType>() const
			{
				return criterator<ValueType>(m_pointingNode);
			}

			operator niterator<ValueType>() const
			{
				return niterator<ValueType>(m_pointingNode);
			}

		private:
			node* m_pointingNode;
		};
		


		typedef niterator<ValueType> iterator;
		typedef citerator<ValueType> const_iterator;
		typedef riterator<ValueType> reverse_iterator;
		typedef criterator<ValueType> const_reverse_iterator;

		order_statistics_tree(const Comparator& p_comparator = Comparator()) : m_end(ValueType()), m_comparator(p_comparator), m_size(0)
		{
			setRoot(0);
		}

		order_statistics_tree(const tree_reference p_copyPattern) : m_end(ValueType()), m_size(0)
		{
			setRoot(0);
			this->operator=(p_copyPattern);
		}

		template <typename InputIterator>
		order_statistics_tree(InputIterator p_firstElement, const InputIterator & p_lastElement, const Comparator& p_comparator = Comparator()) : m_end(ValueType()), m_comparator(p_comparator), m_size(0)
		{
			setRoot(0);
			while (p_firstElement != p_lastElement)
			{
				insert(*p_firstElement);
				++p_firstElement;
			}
		}

		~order_statistics_tree()
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

		std::pair<iterator, bool> insert(const ValueType& p_insertingValue)
		{
			node_pointer l_insertingNode = new node(p_insertingValue);
			insertAndRebalance(l_insertingNode);

			return std::make_pair(iterator(l_insertingNode), true);
		}

		size_t erase(const ValueType& p_deletingValue)
		{
			std::pair<iterator, iterator> l_equalRange = equal_range(p_deletingValue);
			size_t l_sizeBeforeDeleting = m_size;
			erase(l_equalRange.first, l_equalRange.second);
			return l_sizeBeforeDeleting - m_size;
		}

		iterator erase(const_iterator p_begin, const_iterator p_end)
		{
			while (p_begin != p_end)
			{
				node_pointer l_deletingNode = const_cast<node_pointer>(p_begin.m_pointingNode);
				++p_begin;
				deleteNode(l_deletingNode);
			}
			return iterator(const_cast<node_pointer>(p_end.m_pointingNode));
		}

		iterator erase(const_iterator l_deletingElement)
		{
			node_pointer l_deletingNode = const_cast<node_pointer>(l_deletingElement.m_pointingNode);
			node_pointer l_nextNode = l_deletingNode->next();
			deleteNode(l_deletingNode);
			return iterator(l_nextNode);
		}

		size_t count(const ValueType& p_searchingValue)
		{
			std::pair<iterator, iterator> l_equalRange = equal_range(p_searchingValue);
			return l_equalRange.second.position() - l_equalRange.first.position();
		}

		iterator find(const ValueType& p_searchingValue) const
		{
			iterator l_foundValue = lower_bound(p_searchingValue);
			return (*const_cast<Comparator*>(&m_comparator))(p_searchingValue, *l_foundValue) ? iterator(const_cast<node_pointer>(&m_end)) : l_foundValue;
		}

		iterator lower_bound(const ValueType& p_searchingValue) const
		{
			return lower_bound_impl(p_searchingValue, m_root, &m_end);
		}

		iterator upper_bound(const ValueType& p_searchingValue) const
		{
			return upper_bound_impl(p_searchingValue, m_root, &m_end);
		}

		std::pair<iterator, iterator> equal_range(const ValueType& p_searchingValue) const
		{
			const_node_pointer l_currentNode = m_root;
			const_node_pointer l_foundValue = &m_end;
			Comparator* l_comparator = const_cast<Comparator*>(&m_comparator);

			while (l_currentNode != 0)
			{
				if ((*l_comparator)(l_currentNode->m_value, p_searchingValue))
				{
					l_currentNode = l_currentNode->m_right;
				}
				else if ((*l_comparator)(p_searchingValue, l_currentNode->m_value))
				{
					l_foundValue = l_currentNode;
					l_currentNode = l_currentNode->m_left;
				}
				else
				{
					const_node_pointer l_rootForUpperBound = l_currentNode;
					const_node_pointer l_searchingEnd = l_foundValue;
					l_foundValue = l_currentNode;
					l_currentNode = l_currentNode->m_left;
					l_rootForUpperBound = l_rootForUpperBound->m_right;

					return std::make_pair(lower_bound_impl(p_searchingValue, l_currentNode, l_foundValue),
						upper_bound_impl(p_searchingValue, l_rootForUpperBound, l_searchingEnd));
				}
			}

			return std::make_pair(iterator(const_cast<node_pointer>(l_foundValue)), iterator(const_cast<node_pointer>(l_foundValue)));
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

		void swap(tree_reference p_swappingObject)
		{
			std::swap(p_swappingObject.m_size, m_size);
			std::swap(p_swappingObject.m_root, m_root);
			std::swap(p_swappingObject.m_end.m_left, m_end.m_left);
			std::swap(p_swappingObject.m_end.m_right, m_end.m_right);
			std::swap(p_swappingObject.m_end.m_parent, m_end.m_parent);
			std::swap(p_swappingObject.m_comparator, m_comparator);

			if (m_root)
			{
				m_root->m_parent = &m_end;
			}

			if (p_swappingObject.m_root)
			{
				p_swappingObject.m_root->m_parent = &p_swappingObject.m_end;
			}
		}

		tree_reference operator=(const tree_reference p_copyPattern)
		{
			if (this != &p_copyPattern)
			{
				clear();
				copy(p_copyPattern.m_root, m_root);
				setRoot(m_root);
				m_size = p_copyPattern.m_size;
				m_comparator = p_copyPattern.m_comparator;
			}

			return *this;
		}

		Comparator key_comp() const
		{
			return m_comparator;
		}

	private:

		void leftRotation(node_pointer p_rotationNode)
		{
			node_pointer l_newSubTreeRoot = p_rotationNode->m_right;
			p_rotationNode->m_right = l_newSubTreeRoot->m_left;
			if (l_newSubTreeRoot->m_left != 0)
			{
				l_newSubTreeRoot->m_left->m_parent = p_rotationNode;
			}
			l_newSubTreeRoot->m_parent = p_rotationNode->m_parent;
			if (p_rotationNode->m_parent == &m_end)
			{
				setRoot(l_newSubTreeRoot);
			}
			else
			{
				if (p_rotationNode == p_rotationNode->m_parent->m_left)
				{
					p_rotationNode->m_parent->m_left = l_newSubTreeRoot;
				}
				else
				{
					p_rotationNode->m_parent->m_right = l_newSubTreeRoot;
				}
			}
			l_newSubTreeRoot->m_left = p_rotationNode;
			p_rotationNode->m_parent = l_newSubTreeRoot;

			l_newSubTreeRoot->m_subtreeSize = p_rotationNode->m_subtreeSize;
			p_rotationNode->m_subtreeSize = p_rotationNode->leftSize() + p_rotationNode->rightSize() + 1;
		}

		void rightRotation(node_pointer p_rotationNode)
		{
			node_pointer l_newSubTreeRoot = p_rotationNode->m_left;
			p_rotationNode->m_left = l_newSubTreeRoot->m_right;
			if (l_newSubTreeRoot->m_right != 0)
			{
				l_newSubTreeRoot->m_right->m_parent = p_rotationNode;
			}
			l_newSubTreeRoot->m_parent = p_rotationNode->m_parent;
			if (p_rotationNode->m_parent == &m_end)
			{
				setRoot(l_newSubTreeRoot);
			}
			else
			{
				if (p_rotationNode == p_rotationNode->m_parent->m_right)
				{
					p_rotationNode->m_parent->m_right = l_newSubTreeRoot;
				}
				else
				{
					p_rotationNode->m_parent->m_left = l_newSubTreeRoot;
				}
			}
			l_newSubTreeRoot->m_right = p_rotationNode;
			p_rotationNode->m_parent = l_newSubTreeRoot;

			l_newSubTreeRoot->m_subtreeSize = p_rotationNode->m_subtreeSize;
			p_rotationNode->m_subtreeSize = p_rotationNode->leftSize() + p_rotationNode->rightSize() + 1;
		}

		inline void setRoot(node_pointer p_newRoot)
		{
			m_root = p_newRoot;
			m_end.m_left = p_newRoot;
			m_end.m_right = p_newRoot;
			m_end.m_parent = p_newRoot;
			if (p_newRoot != 0)
			{
				p_newRoot->m_parent = &m_end;
			}
		}

		void insertAndRebalance(node_pointer p_checkingNode)
		{
			appendNode(p_checkingNode);
			p_checkingNode->m_isRed = true;
			node_pointer l_uncle;
			while (p_checkingNode != m_root && p_checkingNode->m_parent->m_isRed)
			{
				if (p_checkingNode->m_parent->m_parent != &m_end && p_checkingNode->m_parent == p_checkingNode->m_parent->m_parent->m_left)
				{
					l_uncle = p_checkingNode->m_parent->m_parent->m_right;
					if (l_uncle != 0 && l_uncle->m_isRed)
					{
						p_checkingNode->m_parent->m_isRed = false;
						l_uncle->m_isRed = false;
						p_checkingNode->m_parent->m_parent->m_isRed = true;
						p_checkingNode = p_checkingNode->m_parent->m_parent;
					}
					else
					{
						if (p_checkingNode == p_checkingNode->m_parent->m_right)
						{
							p_checkingNode = p_checkingNode->m_parent;
							leftRotation(p_checkingNode);
						}
						p_checkingNode->m_parent->m_isRed = false;
						if (p_checkingNode->m_parent->m_parent != &m_end)
						{
							p_checkingNode->m_parent->m_parent->m_isRed = true;
							rightRotation(p_checkingNode->m_parent->m_parent);
						}
					}
				}
				else
				{
					if (p_checkingNode->m_parent->m_parent != &m_end && (l_uncle = p_checkingNode->m_parent->m_parent->m_left) != 0 && l_uncle->m_isRed)
					{
						p_checkingNode->m_parent->m_isRed = false;
						l_uncle->m_isRed = false;
						p_checkingNode->m_parent->m_parent->m_isRed = true;
						p_checkingNode = p_checkingNode->m_parent->m_parent;
					}
					else
					{
						if (p_checkingNode == p_checkingNode->m_parent->m_left)
						{
							p_checkingNode = p_checkingNode->m_parent;
							rightRotation(p_checkingNode);
						}
						p_checkingNode->m_parent->m_isRed = false;
						if (p_checkingNode->m_parent->m_parent != &m_end)
						{
							p_checkingNode->m_parent->m_parent->m_isRed = true;
							leftRotation(p_checkingNode->m_parent->m_parent);
						}
					}
				}
			}
			m_root->m_isRed = false;
		}

		void appendNode(node_pointer p_inserting)
		{
			node_pointer l_insertionParent = &m_end;
			node_pointer l_insertionPlace = m_root;

			while (l_insertionPlace != 0)
			{
				l_insertionParent = l_insertionPlace;
				++(l_insertionPlace->m_subtreeSize);
				if (m_comparator(p_inserting->m_value, l_insertionPlace->m_value))
				{
					l_insertionPlace = l_insertionPlace->m_left;
				}
				else
				{
					l_insertionPlace = l_insertionPlace->m_right;
				}
			}

			p_inserting->m_parent = l_insertionParent;
			if (l_insertionParent == &m_end)
			{
				setRoot(p_inserting);
			}
			else
			{
				if (m_comparator(p_inserting->m_value, l_insertionParent->m_value))
				{
					l_insertionParent->m_left = p_inserting;
				}
				else
				{
					l_insertionParent->m_right = p_inserting;
				}
			}
			++m_size;
		}

		node_pointer selectK(node_pointer p_root, size_t p_index) const
		{
			if (p_root == 0 || p_root->m_subtreeSize < p_index) return const_cast<node_pointer>(&m_end);

			while (true)
			{
				size_t l_lesserValuesCounter = p_root->leftSize() + 1;
				if (p_index == l_lesserValuesCounter) return p_root;
				else if (p_index < l_lesserValuesCounter)
				{
					p_root = p_root->m_left;
				}
				else
				{
					p_root = p_root->m_right;
					p_index -= l_lesserValuesCounter;
				}
			}
		}

		void deleteTree(node_pointer p_deletingNode)
		{
			if (p_deletingNode != 0)
			{
				deleteTree(p_deletingNode->m_left);
				deleteTree(p_deletingNode->m_right);
				delete p_deletingNode;
				--m_size;
			}
		}

		iterator lower_bound_impl(const ValueType& p_searchingValue, const_node_pointer p_currentNode, const_node_pointer p_foundValue) const
		{
			Comparator* l_comparator = const_cast<Comparator*>(&m_comparator);
			while (p_currentNode != 0)
			{
				if ((*l_comparator)(p_currentNode->m_value, p_searchingValue))
				{
					p_currentNode = p_currentNode->m_right;
				}
				else
				{
					p_foundValue = p_currentNode;
					p_currentNode = p_currentNode->m_left;
				}
			}

			return iterator(const_cast< node_pointer >(p_foundValue));
		}

		iterator upper_bound_impl(const ValueType& p_searchingValue, const_node_pointer p_currentNode, const_node_pointer p_foundValue) const
		{
			Comparator* l_comparator = const_cast<Comparator*>(&m_comparator);
			while (p_currentNode != 0)
			{
				if ((*l_comparator)(p_searchingValue, p_currentNode->m_value))
				{
					p_foundValue = p_currentNode;
					p_currentNode = p_currentNode->m_left;
				}
				else
				{
					p_currentNode = p_currentNode->m_right;
				}
			}

			return iterator(const_cast< node_pointer >(p_foundValue));
		}

		void copy(const tree_node<ValueType>* const p_copySource, tree_node<ValueType>* & p_copyTarget)
		{
			if (p_copySource != 0)
			{
				p_copyTarget = new node(p_copySource->m_value);

				p_copyTarget->m_isRed = p_copySource->m_isRed;
				p_copyTarget->m_subtreeSize = p_copySource->m_subtreeSize;

				copy(p_copySource->m_left, p_copyTarget->m_left);
				if (p_copyTarget->m_left != 0) p_copyTarget->m_left->m_parent = p_copyTarget;

				copy(p_copySource->m_right, p_copyTarget->m_right);
				if (p_copyTarget->m_right != 0) p_copyTarget->m_right->m_parent = p_copyTarget;
			}
		}

		void deleteNode(node_pointer p_deletingNode)
		{
			ValueType v;
			node null(v);
			null.m_subtreeSize = 0;

			node_pointer y = 0;
			node_pointer x = 0;

			if (p_deletingNode->m_left == 0 || p_deletingNode->m_right == 0)
			{
				y = p_deletingNode;
			}
			else
			{
				y = p_deletingNode->next();
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

			node_pointer l_nodeToResizeItsSubtree = y;
			while (l_nodeToResizeItsSubtree != &m_end)
			{
				--(l_nodeToResizeItsSubtree->m_subtreeSize);
				l_nodeToResizeItsSubtree = l_nodeToResizeItsSubtree->m_parent;
			}

			if (p_deletingNode != y)
			{
				p_deletingNode->m_left->m_parent = y;
				y->m_left = p_deletingNode->m_left;

				if (y != p_deletingNode->m_right)
				{
					x->m_parent = y->m_parent;
					y->m_parent->m_left = x;
					y->m_right = p_deletingNode->m_right;
					p_deletingNode->m_right->m_parent = y;
				}
				else
				{
					x->m_parent = y;
				}

				if (p_deletingNode == m_root)
				{
					setRoot(y);
				}
				else if (p_deletingNode->m_parent->m_left == p_deletingNode)
				{
					p_deletingNode->m_parent->m_left = y;
				}
				else
				{
					p_deletingNode->m_parent->m_right = y;
				}

				y->m_parent = p_deletingNode->m_parent;
				std::swap(y->m_isRed, p_deletingNode->m_isRed);
				y->m_subtreeSize = p_deletingNode->m_subtreeSize;
				y = p_deletingNode;
			}
			else
			{
				x->m_parent = y->m_parent;
				if (m_root == p_deletingNode)
				{
					setRoot(x);
				}
				else if (p_deletingNode->m_parent->m_left == p_deletingNode)
				{
					p_deletingNode->m_parent->m_left = x;
				}
				else
				{
					p_deletingNode->m_parent->m_right = x;
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
		Comparator		m_comparator;
		size_t			m_size;
		node_pointer	m_root;
	};

} 


#endif  


const int MR = 1e5 + 10;

int getInd(char c)
{
	switch (c)
	{
	case 'A': return 0;
	case 'C': return 1;
	case 'G': return 2;
	case 'T': return 3;
	default: return -1;
	}
}

boost::order_statistics_tree < int > tree[4][10][10];

char s[MR], e[20];

int main()
{
	scanf("%s", s);
	int n = strlen(s);

	REP(i, n)FORQ(m, 1, 10)
		tree[getInd(s[i])][m - 1][i%m].insert(i);

	int q;
	scanf("%d", &q);
	REP(cnt, q)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			int x;
			char c[2];
			scanf("%d%s", &x, c); x--;
			FORQ(m, 1, 10)
				tree[getInd(s[x])][m - 1][x%m].erase(x);
			FORQ(m, 1, 10)
				tree[getInd(c[0])][m - 1][x%m].insert(x);

			s[x] = c[0];
		}
		else
		{
			int l, r;
			scanf("%d%d%s", &l, &r, e); l--; r--;
			int dl = strlen(e), ans = 0;
			REP(i, dl)
			{
				auto itl = tree[getInd(e[i])][dl - 1][(i + l) % dl].lower_bound(l);
				auto itr = tree[getInd(e[i])][dl - 1][(i + l) % dl].upper_bound(r);

				if (itl != itr)
				{
					if (itr != tree[getInd(e[i])][dl - 1][(i + l) % dl].end())
						ans += itr.position() - itl.position();
					else
					{
						itr--;
						ans += itr.position() - itl.position() + 1;
					}
				}
			}

			printf("%d\n", ans);
		}
	}

	return 0;
}