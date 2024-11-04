















namespace btree
{
  enum class color_t : char
  {
    red,
    black,
  };

  enum direction_t
  {
    left,
    right,
  };

  inline direction_t other_direction(direction_t d)
  {
    return d == left ? right : left;
  }

  template <typename KeyType, template <typename, typename> class... Plugins>
  struct rb_tree_container;

  template <typename KeyType, typename NodeType, template <typename, typename> class... Plugins>
  struct btree_container;

  template <typename KeyType, typename NodeType>
  class indexation_plugin
    {
    public:
      class node_t
      {
      public:
          std::size_t node_count () const { return id0; }

      private:
        std::size_t id0 = 1;
        
      public:

        void on_new_child ()
        {
          auto current = static_cast<NodeType *> (this)->parent();
          while (current) 
          {
            current->id0 += id0;
            current = current->parent ();
          }
        }

        void before_takeout ()
        {
          auto current = static_cast<NodeType *> (this)->parent();
          while (current) 
          {
            current->id0 -= id0;
            current = current->parent ();
          }
        }
      };

      template <typename TreeType>
      class tree_t
      {
      public:
        template <typename ArgType>
        std::size_t index (const ArgType &key)
        {
          auto current = static_cast<TreeType*> (this)->root();
          std::size_t id2 = 0;
          while (current)
            {
              if (key < current->key ())
                current = current->child (left);
              else if (current->key () < key)
                {
                  id2 += (current->child (left) ? current->child (left)->node_count () :0) + 1;
                  current = current->child (right);
                }
              else
                {
                  id2 += (current->child (left) ? current->child (left)->node_count () :0);
                  break;
                }
            }
          if (current)
            return id2;

          return static_cast<std::size_t> (-1);
        }
      };
    };

  template <typename KeyType, typename NodeType, template <typename, typename> class... Plugins>
  struct btree_container
  {
    class tree_t;
    class node_t;

  public:
    class node_t : public Plugins<KeyType, NodeType>::node_t...
    {
    public:
      template <typename ArgType>
      explicit node_t(ArgType&& key) : m_key(std::forward<ArgType>(key))
      {
      }

      const auto& key() const { return m_key; }
      const NodeType* child(direction_t direction) const { return m_children[direction].get(); }
      NodeType* child(direction_t direction) { return m_children[direction].get(); }
      const NodeType* parent() const { return m_parent; }
      NodeType* parent() { return m_parent; }
      NodeType *furthest_node (direction_t direction)
      {
        auto cur_node = this;
        while (auto next_node = cur_node->child (direction))
          cur_node = next_node;
        return static_cast<NodeType *> (cur_node);
      }

      NodeType *next_node (direction_t direction)
      {
        if (auto c = child (direction))
          {
            return c->furthest_node (other_direction(direction));
          }

        auto cur_node = this;
        while (cur_node->parent () && cur_node->direction_from_parent () == direction)
          cur_node = cur_node->parent ();
        return cur_node->parent ();
      }

      NodeType* uncle()
      {
        assert (m_parent);
        return m_parent->sibling();
      }

      NodeType* sibling()
      {
        return m_parent->child(other_direction(direction_from_parent()));
      }

      int child_count()
      {
        int cnt = 0;
        for (auto direction : {left, right})
          cnt += (m_children[direction] != nullptr);
        return cnt;
      }

      NodeType* single_child()
      {
        assert (child_count() <= 1);
        for (auto child_direction : {left, right})
        {
          if (auto c = child(child_direction))
            return c;
        }
        return nullptr;
      }

      bool is_root()
      {
        return m_parent == nullptr;
      }

      direction_t direction_from_parent() const
      {
        assert (m_parent);
        for (auto b : {left, right})
          if (m_parent->m_children[b].get() == this)
            return b;
        assert (false);
        return left;
      }

      std::unique_ptr<NodeType> take_out()
      {
        std::initializer_list<int> {(static_cast<TYPENAME_IF_NOT_MSVC Plugins<KeyType, NodeType>::node_t*> (this)->before_takeout (), 0)...};
        auto& n = location();
        n->m_parent = nullptr;
        return std::move(n);
      }

      NodeType* append_child(direction_t dir, std::unique_ptr<NodeType> node)
      {
        node->m_parent = static_cast<NodeType *>(this);
        assert (m_children[dir] == nullptr);
        m_children[dir] = std::move(node);
        std::initializer_list<int> {(static_cast<TYPENAME_IF_NOT_MSVC Plugins<KeyType, NodeType>::node_t*> (m_children[dir].get ())->on_new_child (),0)...};
        return m_children[dir].get();
      }

    private:
      std::array<std::unique_ptr<NodeType>, 2> m_children;
      NodeType* m_parent = nullptr;
      KeyType m_key;

      std::unique_ptr<NodeType>& location() const
      {
        return m_parent->m_children[this->direction_from_parent()];
      }

      friend class tree_t;
    };

    class iterator_t
    {
      using node_type = NodeType;
      using self = iterator_t;
    public:
      using iterator_category = std::bidirectional_iterator_tag;
      using reference = const KeyType &;
      using pointer = const KeyType *;
      using value_type = const KeyType;
      using difference_type = std::size_t;
    public:
      iterator_t (node_type *node) : m_node (node) {}
      self &operator++ ()
      {
        m_node = m_node->next_node (right);
        return *this;
      }

      self &operator-- ()
      {
        if (m_node == nullptr)
          return *this; 

        m_node = m_node->next_node (left);
        return *this;
      }

      reference operator* ()
      {
        return m_node->key ();
      }  

      bool operator== (const self &other)
      {
        return m_node == other.m_node;
      }

      bool operator!= (const self &other)
      {
        return !(*this == other);
      }

    private:
      node_type *m_node;
    };

    class tree_t : public Plugins<KeyType, NodeType>::template tree_t<tree_t>...
    {
    public:
      using iterator = iterator_t;

      iterator_t begin ()
      {
        return {furthest_node (left)};
      }

      iterator_t end ()
      {
        return {nullptr};
      }


      void clear ()
      {
        m_root.reset ();
      }

      std::unique_ptr<NodeType> take_out(NodeType *node)
      {
        if (node->parent ())
          return node->take_out ();
        else
          return std::move (m_root);
      }

      void replace_with_child(NodeType *node)
      {
        auto cnt = node->child_count();
        auto parent = node->parent ();
        auto direction = parent ? node->direction_from_parent() : left;
        auto taken_out = take_out (node);
        if (cnt == 0)
          return;
        if (parent)
          parent->append_child(direction, take_out (node->single_child()));
        else
          m_root = node->single_child()->take_out();
      }

      void rotate(NodeType *node, direction_t dir)
      {
        auto prev_parent = node->parent();
        direction_t prev_direction;
        if (prev_parent)
           prev_direction = node->direction_from_parent();
        auto id1 = take_out (node);
        auto heritor = take_out (node->child(other_direction(dir)));
        if (heritor->child(dir))
          node->append_child(other_direction(dir), take_out (heritor->child(dir)));

        heritor->append_child(dir, std::move(id1));
        if (prev_parent)
          prev_parent->append_child(prev_direction, std::move(heritor));
        else
          m_root = std::move (heritor);
      }

      template <typename ArgType>
      std::size_t erase(const ArgType& key)
      {
        auto current = preerase(key);
        if (!current)
          return 0;

        replace_with_child(current);
        return 1;
      }

      const NodeType* root() const { return m_root.get(); }

    protected:
      NodeType *furthest_node (direction_t direction)
      {
        return m_root->furthest_node (direction);
      }

      template <typename ArgType>
      NodeType* preinsert(ArgType&& key)
      {
        auto create_node = [](auto&& key)
        {
          auto node = std::make_unique<NodeType>(std::forward<ArgType>(key));
          return node;
        };

        auto current = m_root.get();
        if (!current)
        {
          m_root = create_node(std::forward<ArgType>(key));
          current = m_root.get();
        }
        else
        {
          while (true)
          {
            auto check_child = [&](direction_t direction)
            {
              if (!current->child(direction))
              {
                current = current->append_child(direction, create_node(std::forward<ArgType>(key)));
                return true;
              }

              current = current->child(direction);
              return false;
            };

            if (key < current->key())
            {
              if (check_child(left))
                break;
            }
            else
            {
              if (check_child(right))
                break;
            }
          }
        }
        return current;
      }

      template <typename ArgType>
      NodeType* preerase(const ArgType& key)
      {
        if (!m_root)
          return nullptr;

        auto current = m_root.get();
        while (current)
        {
          if (key < current->key())
            current = current->child(left);
          else if (key > current->key())
            current = current->child(right);
          else
            break;
        }

        if (!current)
          return nullptr;

        auto cnt = current->child_count();
        if (cnt <= 1)
          return current;

        auto child = current->child(left);
        while (auto next_child = child->child(right))
          child = next_child;

        current->m_key = child->m_key;
        return child;
      }

    private:
      std::unique_ptr<NodeType> m_root;

      friend struct rb_tree_container<KeyType>;
    };
  };

  template <typename KeyType, template<typename, typename> class... Plugins>
  struct rb_tree_container
  {
    class tree_t;

    struct node_t : btree_container<KeyType, node_t, Plugins...>::node_t
    {
      using parent_t = typename btree_container<KeyType, node_t, Plugins...>::node_t;
      using parent_t::parent_t;
    public:
      auto color() const { return m_color; }

      auto child_color(direction_t direction)
      {
        if (!this->child(direction))
          return color_t::black;

        return this->child(direction)->color();
      }

    private:
      color_t m_color = color_t::red;
      void paint(color_t value) { m_color = value; }

      friend class tree_t;
    };

    class tree_t : public btree_container<KeyType, node_t, Plugins...>::tree_t
    {
      

      using self = tree_t;
      using base = typename btree_container<KeyType, node_t, Plugins...>::tree_t;
    public:
      using node_t = node_t;
    public:
      template <typename ArgType>
      void insert(ArgType&& key)
      {
        auto current = this->preinsert(std::forward<ArgType>(key));
        while (true)
        {
          auto parent = current->parent();
          if (!parent)
          {
            current->paint(color_t::black);
            break;
          }

          if (parent->m_color == color_t::black)
            break;

          auto grand_parent = parent->parent();
          auto uncle = current->uncle();
          if (uncle && uncle->m_color == color_t::red)
          {
            parent->paint(color_t::black);
            uncle->paint(color_t::black);
            grand_parent->paint(color_t::red);
            current = grand_parent;
            continue;
          }

          if (current->direction_from_parent() != parent->direction_from_parent())
          {
            this->rotate(parent, other_direction(current->direction_from_parent()));
            std::swap(current, parent);
          }

          this->rotate(grand_parent, other_direction(current->direction_from_parent()));
          std::swap(grand_parent->m_color, parent->m_color);
          break;
        }
      }

      template <typename ArgType>
      std::size_t erase(const ArgType& key)
      {
        auto m = this->preerase(key);
        if (!m)
          return 0;

        if (m->color() == color_t::red)
          return (this->replace_with_child(m) , 1);
        auto c = m->single_child();
        auto p = m->parent();
        auto s = p ? m->sibling() : nullptr;
        auto n_direction = p ? m->direction_from_parent() : left;
        this->replace_with_child(m);
        if (c && c->color() == color_t::red)
        {
          c->paint(color_t::black);
          return 1;
        }
        auto n = c;

        while (true)
        {
          if (p == nullptr)
            return 1;

          if (s->color() == color_t::red)
          {
            std::swap(p->m_color, s->m_color);
            this->rotate(p, n_direction);
            s = p->child (other_direction(n_direction)); 

          }

          if (s->child_color(left) == color_t::black
            && s->child_color(right) == color_t::black)
          {
            if (p->color() == color_t::black)
            {
              s->paint(color_t::red);
              n = p;
              p = n->parent();
              s = p ? n->sibling() : nullptr;
              n_direction = p ? n->direction_from_parent() : left;
              continue;
            }

            std::swap(s->m_color, p->m_color);
            break;
          }
          if (s->child_color (n_direction) == color_t::red)
          {
            this->rotate(s, other_direction(n_direction));
            std::swap(s->m_color, s->parent ()->m_color);
            s = s->parent ();
          }

          this->rotate(p, n_direction);
          std::swap(p->m_color, s->m_color);
          s->child(other_direction(n_direction))->paint(color_t::black);
          break;
        }
        return 1;
      }
    };
  };

  template <typename KeyType>
  using rb_tree = typename rb_tree_container<KeyType>::tree_t;
  template <typename KeyType>
  using indexed_rb_tree = typename rb_tree_container<KeyType, indexation_plugin>::tree_t;
} 




class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
      long long n;
      in >> n;
      std::vector<long long> a (n);
      btree::indexed_rb_tree<long long> tree;
      std::vector<std::array<long long, 2>> value_index;
      for (long long i = 0; i < n; ++i)
      {
        in >> a[i];
        value_index.push_back({a[i],i});
        tree.insert(i);
      }
      std::sort(value_index.begin (), value_index.end ());
      auto it = value_index.begin ();
      long long cur_index = 0;
      long long count = 0;
      long long used = 0;
      bool first = true;
      while (it != value_index.end ())
      {
        auto next_it = it;
        ++next_it;
        while (next_it != value_index.end () && next_it->at(0) == prev(next_it)->at(0))
          ++next_it;
        
        auto next = lower_bound (it, next_it, std::array<long long, 2>{it->at(0), cur_index});
        bool loop = true;
        auto start = next;
        auto go = [&](long long index)
        {
          if (index >= cur_index)
            count += tree.index (index) - tree.index (cur_index) + (first ? 1 : 0);
          else 
            count += (n - used - tree.index (cur_index) + 1) + tree.index (index) + (first ? 1 : 0);

          if (!first)
            tree.erase (cur_index);

          if (first)
            first = false;

          cur_index = index;
          ++used;
        };

        if (next == it || next == next_it)
          {
            next = it;
            loop = false;
          }
        while (next != next_it)
          {
            go ((*next)[1]);
            ++next;
          }

        if (loop)
        {
          next = it;
          while (next != start)
            {
              go ((*next)[1]);  

              ++next;
            }
          loop = false;
        }
        it = next_it;
      }
      out << count << '\n';
    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}



int main ()
{
  solve (std::cin, std::cout);
}
