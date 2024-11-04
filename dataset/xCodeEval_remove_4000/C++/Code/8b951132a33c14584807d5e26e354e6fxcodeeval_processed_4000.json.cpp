








namespace Ssvtl {

  template<typename T>
  class VectorIterator :
      std::iterator<std::random_access_iterator_tag, T> {
  private:
    using _alloc = std::allocator<T>;
  public:
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using difference_type = typename std::allocator_traits<_alloc>::difference_type;
    using iterator_category = std::random_access_iterator_tag;
    using size_type = typename std::allocator_traits<_alloc>::size_type;

    using it = VectorIterator;
    using iterator_traits = std::iterator_traits<it>;

  public:
    explicit VectorIterator(pointer value) {
      m_value = value;
    }

    VectorIterator(it& other) noexcept:
        m_value(other.m_value) {
    }

    VectorIterator(it&& other) noexcept:
        m_value(std::move(other.m_value)) {
    }

    reference operator*() noexcept {
      return *m_value;
    }

    pointer operator->() noexcept {
      return m_value;
    }

    const VectorIterator& operator++() noexcept {
      m_value++;
      return *this;
    }

    VectorIterator operator++(int) noexcept {
      VectorIterator tmp = *this;
      ++(*this);
      return tmp;
    }

    VectorIterator& operator--() noexcept {
      m_value--;
      return *this;
    }

    VectorIterator operator--(int) noexcept {
      VectorIterator tmp = *this;
      --(*this);
      return tmp;
    }

    VectorIterator& operator=(const VectorIterator& other) noexcept {
      m_value = other.m_value;
      return *this;
    }

    VectorIterator& operator+=(const size_type n) noexcept {
      m_value += n;
      return *this;
    }

    VectorIterator& operator-=(const size_type n) noexcept {
      m_value -= n;
      return *this;
    }

    VectorIterator operator+(const size_type n) noexcept {
      VectorIterator tmp = *this;
      tmp += n;
      return tmp;
    }

    VectorIterator operator-(const size_type n) noexcept {
      VectorIterator tmp = *this;
      tmp -= n;
      return tmp;
    }

    size_type operator-(const VectorIterator<T> other) noexcept {
      return m_value - other.m_value;
    }

    VectorIterator operator[](size_type n) noexcept {
      return *this + n;
    }

    bool operator<(VectorIterator& other) {
      return m_value < other.m_value;
    }

    bool operator>(VectorIterator& other) {
      return m_value > other.m_value;
    }

    bool operator==(VectorIterator& other) {
      return m_value == other.m_value;
    }

    bool operator!=(VectorIterator& other) {
      return m_value != other.m_value;
    }

    bool operator>=(VectorIterator& other) {
      return m_value >= other.m_value;
    }

    bool operator<=(VectorIterator& other) {
      return m_value <= other.m_value;
    }

  private:
    pointer m_value;
  };

  template<typename T, typename Alloc = std::allocator<T>>
  class Vector {
  private:
    using _alloc_traits = std::allocator_traits<Alloc>;

  public:
    

    using _alloc = Alloc;

    using value_type = T;
    using reference = T&;
    using const_reference = const T&;

    using pointer = typename _alloc_traits::pointer;
    using const_pointer = typename _alloc_traits::const_pointer;

    using size_type = typename _alloc_traits::size_type;
    using difference_type = typename _alloc_traits::difference_type;

    using iterator = VectorIterator<value_type>;

    explicit Vector() = default;

    explicit Vector(size_type size) {
      resize(size);
    }

    Vector(std::initializer_list<value_type> list) :
        Vector(
            std::distance(list.begin(), list.end())) {

      _assignRange(list.begin(), list.end());
    }

    Vector(Vector& other) noexcept {
      reserve(other.capacity());
      resize(other.size());
      std::copy(other.begin(), other.end(), begin());
    }

    Vector(Vector&& other) noexcept
        :
        m_data(std::move(other.m_data)),
        m_size(std::move(other.m_size)),
        m_capacity(std::move(other.m_capacity)) {
    }

    pointer data() noexcept {
      return m_data;
    }

    reference operator[](size_type n) noexcept {
      return m_data[n];
    }

    reference at(size_type n) {
      _outOfRangeCheck(n);

      return (*this)[n];
    };

    reference front() const {
      return *begin();
    }

    reference back() {
      if (size() == 0) {
        return front();
      }
      return *(end() - 1);
    }

    size_type size() const noexcept {
      return m_size;
    }

    iterator begin() const noexcept {
      return iterator(m_data);
    }

    iterator end() noexcept {
      return begin() + size();
    }

    size_type capacity() noexcept {
      return m_capacity;
    }

    void resize(const size_type newSize) {
      if (newSize < size()) {
        iterator startDestroy = begin() + newSize;
        iterator endDestroy = end();

        if (std::is_destructible_v<value_type>) {
          std::destroy(startDestroy, endDestroy);
        }
      }

      if (newSize > size()) {
        if (capacity() < newSize) {
          _reallocMem(newSize);
        }
      }

      m_size = newSize;
    }

    template<typename... ValT>
    decltype(auto) id2(ValT&& ... values) {
      if (size() == capacity()) {
        _addMem();
      }

      m_size++;
      *back() = value_type(std::forward<ValT>(values)...);
    }

    [[nodiscard]] bool empty() const noexcept {
      return size() == 0;
    }

    void reserve(size_type n) {
      if (n > capacity()) {
        _reallocMem(n);
      }
    }

    void push_back(value_type val) {
      if (size() >= capacity()) {
        _addMem();
      }

      m_size++;
      back() = val;
    }

    void clear() noexcept {
      if (size() == 0) {
        return;
      }

      _destroyRange(begin(), end());
      m_size = 0;
    }

    void pop_back() {
      _destroy(end() - 1);
      m_size--;
    }

    void pop_front() {
      _destroy(begin());
      if (std::is_move_assignable_v<value_type>) {
        std::move(begin() + 1, end(), iterator(begin()));
      } else {
        std::copy(begin() + 1, end(), iterator(begin()));
      }
      m_size--;
    }

    ~Vector() {
      resize(0);
    }

  private:
    pointer m_data = nullptr;
    size_type m_size = 0;
    size_type m_capacity = 0;

    template<typename It>
    void _assignRange(It first,
                      It last) {
      iterator next = begin();
      iterator _end = end();
      

      for (; first != last; ++first, ++next) {
        *next = *first;
      }
    }

    void _outOfRangeCheck(size_type index) {
      if (index >= size()) {
        std::stringstream msgs;
        msgs << "vector::_outOfRangeCheck"
             << '\n' << '\t' << "index is " << index << " >= "
             << "vector.size()"
             << " is "
             << size();

        throw std::out_of_range(msgs.str());
      }
    }

    void _reallocMem(const size_type newCapacity) {
      std::allocator<value_type> alloc;

      pointer newMem;

      if (newCapacity != 0) {
        newMem = alloc.allocate(newCapacity);
        if (newMem == nullptr) {
          throw std::bad_alloc();
        }

        if (std::is_move_assignable_v<value_type>) {
          std::move(begin(), end(), iterator(newMem));
        } else {
          std::copy(begin(), end(), iterator(newMem));
        }
      } else {
        newMem = nullptr;
      }

      if (m_data != nullptr) {
        _destroyRange(begin(), end());
        alloc.deallocate(m_data, capacity());
      }













      m_data = newMem;
      m_capacity = newCapacity;
    }

    void _addMem() {
      size_type newCapacity = size() == 0 ? 1 : size() * 2;
      _reallocMem(newCapacity);
    }

    void _destroy(iterator pos) {
      _destroyRange(pos, pos + 1);
    }

    void _destroyRange(iterator first,
                       iterator end) {
      if (std::is_destructible_v<value_type> == false) {
        return;
      }



      std::destroy(first, end);
    }
  };

  template<class T>
  class Node {
  public:
    using value_type = T;

    value_type _value = value_type();
    Node<value_type>* _next, * _prev;
  };

  template<typename Node>
  class ListIterator :
      std::bidirectional_iterator_tag {
  public:
    using value_type = Node;
    using size_type = size_t;
    using pointer = value_type*;
    using reference = value_type&;
    using difference_type = ptrdiff_t;
    using iterator_category = std::bidirectional_iterator_tag;
    using iterator_traits = std::iterator_traits<ListIterator>;
  public:
    explicit ListIterator(pointer ptr)
        :
        _ptr(ptr) {}

    virtual ListIterator& operator++() {
      _ptr = _ptr->_next;
      return *this;
    }

    virtual ListIterator& operator--() {
      _ptr = _ptr->_prev;
      return *this;
    }

    virtual ListIterator operator++(int) {
      ListIterator it = *this;
      ++(*this);
      return it;
    }

    virtual ListIterator operator--(int) {
      ListIterator it = *this;
      --(*this);
      return it;
    }

    typename Node::value_type& operator*() {
      return _ptr->_value;
    }

    pointer operator->() {
      return _ptr;
    }

    bool operator==(const ListIterator& other) const {
      return _ptr == other._ptr;
    }

    bool operator!=(const ListIterator& other) const {
      return _ptr != other._ptr;
    }

    pointer getPointer() {
      return _ptr;
    }

  private:
    pointer _ptr;
  };

  template<typename Node>
  class id1 :
      ListIterator<Node> {
  public:
    using value_type = Node;
    using size_type = size_t;
    using pointer = value_type*;
    using reference = value_type&;
    using difference_type = ptrdiff_t;
    using iterator_category = std::bidirectional_iterator_tag;
    using iterator_traits = std::iterator_traits<id1>;
  public:
    explicit id1(pointer ptr)
        :
        _ptr(ptr) {}

    id1& operator++() override {
      _ptr = _ptr->_prev;
      return *this;
    }

    id1& operator--() override {
      _ptr = _ptr->_next;
      return *this;
    }

    id1 operator++(int) override {
      id1 it = *this;
      --(*this);
      return it;
    }

    id1 operator--(int) override {
      id1 it = *this;
      ++(*this);
      return it;
    }

  private:
    pointer _ptr;
  };

  template<typename Node>
  class id4 :
      std::bidirectional_iterator_tag {
  public:
    using value_type = Node;
    using size_type = size_t;
    using pointer = value_type*;
    using reference = value_type&;
    using difference_type = ptrdiff_t;
    using iterator_category = std::bidirectional_iterator_tag;
    using iterator_traits = std::iterator_traits<id4>;
  public:
    explicit id4(pointer ptr)
        :
        _ptr(ptr) {}

    virtual id4& operator++() {
      _ptr = _ptr->_next;
      return *this;
    }

    virtual id4& operator--() {
      _ptr = _ptr->_prev;
      return *this;
    }

    virtual id4 operator++(int) {
      id4 it = *this;
      ++(*this);
      return it;
    }

    virtual id4 operator--(int) {
      id4 it = *this;
      --(*this);
      return it;
    }

    const typename Node::value_type& operator*() {
      return _ptr->_value;
    }

    bool operator==(const id4& other) const {
      return _ptr == other._ptr;
    }

    bool operator!=(const id4& other) const {
      return _ptr != other._ptr;
    }

  private:
    pointer _ptr;
  };

  template<typename Node>
  class id5 :
      id4<Node> {
  public:
    using value_type = Node;
    using size_type = size_t;
    using pointer = value_type*;
    using reference = value_type&;
    using difference_type = ptrdiff_t;
    using iterator_category = std::bidirectional_iterator_tag;
    using iterator_traits = std::iterator_traits<id5>;
  public:
    explicit id5(pointer ptr)
        :
        _ptr(ptr) {}

    id5& operator++() override {
      _ptr = _ptr->_prev;
      return *this;
    }

    id5& operator--() override {
      _ptr = _ptr->_next;
      return *this;
    }

    id5 operator++(int) override {
      id5 it = *this;
      --(*this);
      return it;
    }

    id5 operator--(int) override {
      id5 it = *this;
      ++(*this);
      return it;
    }

  private:
    pointer _ptr;
  };

  template<class T, class Allocator = std::allocator<Node<T>>>
  class List {
  public:
    using value_type = T;
    using size_type = size_t;
    using pointer = typename std::allocator_traits<Allocator>::pointer;
    using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;
    using reference = value_type&;
    using const_reference = const value_type&;
    using node_type = Node<value_type>;
    using iterator = ListIterator<node_type>;
    using const_iterator = id4<node_type>;
    using reverse_iterator = id1<node_type>;
    using const_reverse_iterator = id5<node_type>;
  public:
    List() {
      std::allocator<node_type> alloc;

      _size = 0;
      pointer first = alloc.allocate(1);
      pointer last = alloc.allocate(1);

      first->_next = last;
      first->_prev = nullptr;

      last->_next = nullptr;
      last->_prev = first;

      _head = first;
      _tail = last;
    };

    explicit List(size_type size) :
        List() {
      for (size_type i = 0; i < size; ++i) {
        this->push_back(value_type());
      }
    }

    List(const List& other) :
        List() {
      _constructFromList(other);
    }

    List(size_type size,
         const value_type& value) :
        List() {
      for (size_type i = 0; i < size; ++i) {
        this->push_back(value);
      }
    }

    List(std::initializer_list<value_type> l) :
        List() {
      for (auto& elem: l) {
        this->push_back(elem);
      }
    }

    iterator begin() noexcept { return ++iterator(_head); }

    const_iterator begin() const noexcept { return ++const_iterator(_head); }

    iterator end() { return iterator(_tail); }

    const_iterator end() const noexcept { return const_iterator(_tail); }

    const_iterator cbegin() const noexcept { return ++const_iterator(_head); }

    const_iterator cend() const noexcept { return const_iterator(_tail); }

    reverse_iterator rbegin() noexcept { return ++reverse_iterator(_tail); }

    const_reverse_iterator rbegin() const noexcept { return ++const_reverse_iterator(_tail); }

    reverse_iterator rend() noexcept { return reverse_iterator(_head); }

    const_reverse_iterator rend() const noexcept { return const_reverse_iterator(_head); }

    const_reverse_iterator crbegin() const noexcept { return ++const_reverse_iterator(_tail); }

    const_reverse_iterator crend() const noexcept { return reverse_iterator(_head); }

    iterator insert(iterator pos,
                    const value_type& value) {
      std::allocator<node_type> alloc;

      _size++;

      pointer newNode = alloc.allocate(1);
      newNode->_value = value;

      return _insertPointer(pos, newNode);
    }

    iterator erase(iterator pos) {
      std::allocator<node_type> alloc;

      if (pos == this->end() ||
          pos == --(this->begin())
          ) {
        return this->end();
      }

      _size--;

      auto nextIter = _relinkPointer(pos);

      alloc.deallocate(pos.getPointer(), 1);

      return nextIter;
    }

    void push_front(const value_type& value) {
      insert(this->begin(), value);
    }

    void push_back(const value_type& value) {
      insert(this->end(), value);
    }

    void pop_front() { erase(this->begin()); }

    void pop_back() { erase(--(this->end())); }

    void resize(size_type count,
                const value_type& value = value_type()) {
      if (_size > count) {
        auto diff = _size - count;
        for (size_type i = 0; i < diff; ++i) {
          this->pop_back();
        }
      } else if (_size < count) {
        auto diff = count - _size;
        for (size_type i = 0; i < diff; ++i) {
          this->push_back(value);
        }
      }

      _size = count;
    }

    void clear() {
      if (this->empty()) {
        return;
      }

      for (auto it = ++this->begin(); it != this->end(); ++it) {
        auto prevIter = --it;
        ++it;

        erase(prevIter);
      }
      erase(--(this->end()));
    }

    void swap(List& other) {
      auto t = *this;
      *this = other;
      other = t;
    }

    void splice(iterator pos,
                List& other) {
      auto prevIter = --pos;
      ++pos;

      prevIter->_next = other.begin().getPointer();
      other.begin()->_prev = prevIter.getPointer();

      (--other.end())->_next = pos.getPointer();
      pos->_prev = (--other.end()).getPointer();

      other._head->_next = other._tail;
      other._tail->_prev = other._head;

      _size += other._size;
      other._size = 0;
    }

    void reverse() {
      auto i = begin(), j = --end();

      auto n = _size / 2;
      for (size_type k = 0; k < n; ++k) {
        std::swap(i->_value, j->_value);
        ++i, --j;
      }
    }

    size_type remove(const value_type& value) {
      size_type deleted = 0;

      for (auto it = ++this->begin(); it != this->end(); ++it) {
        auto prevIter = --it;
        ++it;

        if (*prevIter == value && ++deleted) {
          erase(prevIter);
        }
      }
      if (*--this->end() == value) {
        erase(--this->end());
      }

      return deleted;
    }

    template<class UnaryPredicate>
    size_type remove_if(UnaryPredicate p) {
      size_type deleted = 0;

      for (auto it = ++this->begin(); it != this->end(); ++it) {
        auto prevIter = --it;
        ++it;

        if (p(*prevIter) && ++deleted) {
          erase(prevIter);
        }
      }
      if (p(*--this->end())) {
        erase(--this->end());
      }

      return deleted;
    }

    size_type size() const noexcept { return _size; }

    [[nodiscard]] bool empty() const noexcept { return _size == 0; }

    reference front() noexcept { return *begin(); }

    const_reference front() const noexcept { return *begin(); }

    reference back() noexcept { return *--end(); }

    const_reference back() const noexcept { return *--end(); }

    List& operator=(const List& other) {
      if (this == &other) {
        return *this;
      }

      this->clear();
      this->_constructFromList(other);
      return *this;
    }

    ~List() {
      std::allocator<node_type> alloc;

      this->clear();
      alloc.deallocate(_head, 1);
      alloc.deallocate(_tail, 1);
    }

  private:
    node_type* _head;
    node_type* _tail;
    size_type _size;

    iterator _insertPointer(iterator& pos,
                            node_type* ptr) {
      auto prevIter = --pos;
      ++pos;

      prevIter->_next = ptr;
      pos->_prev = ptr;

      ptr->_prev = prevIter.getPointer();
      ptr->_next = pos.getPointer();

      return iterator(ptr);
    }

    iterator _relinkPointer(iterator& pos) {
      auto prevIter = --pos;
      ++pos;

      auto nextIter = ++pos;
      --pos;

      prevIter->_next = nextIter.getPointer();
      nextIter->_prev = prevIter.getPointer();

      return nextIter;
    }

    void _constructFromList(const List& other) {
      for (auto it = other.begin(); it != other.end(); ++it) {
        this->push_back(*it);
      }
    }
  };

  template<typename T,
      typename Container = std::deque<T>>
  class Stack;

  template<typename T,
      typename Container>
  class Stack {
  protected:
    Container container_;

  public:
    using container_type = Container;
    using ContainerT = container_type;
    using reference = typename Container::reference;
    using ReferenceT = reference;
    using const_reference = typename Container::const_reference;
    using ConstReferenceT = const_reference;
    using size_type = typename Container::size_type;
    using SizeT = size_type;
    using value_type = typename Container::value_type;
    using ValueT = value_type;

    static_assert(std::is_same_v<T, ValueT>, "container adaptors require consistent types");

    Stack() = default;

    explicit Stack(const Container& container) :
        container_(container) {}

    explicit Stack(Container&& container) noexcept:
        container_(std::move(container)) {}

    Stack(const Stack& other_stack) :
        Stack(other_stack.container_) {}

    Stack(Stack&& other_stack) noexcept:
        Stack(std::move(other_stack.container_)) {}

    template<typename Alloc,
        typename std::enable_if_t<std::uses_allocator<Container, Alloc>::value>* = nullptr>
    explicit Stack(const Alloc& alloc) noexcept:
        container_(alloc) {}

    template<typename Alloc,
        typename std::enable_if_t<std::uses_allocator<Container, Alloc>::value>* = nullptr>
    explicit Stack(const Container& container,
                   const Alloc& alloc) noexcept:
        container_(container, alloc) {}

    template<typename Alloc,
        typename std::enable_if_t<std::uses_allocator<Container, Alloc>::value>* = nullptr>
    explicit Stack(Container&& container,
                   const Alloc& alloc) noexcept:
        container_(std::move(container), alloc) {}

    template<typename Alloc,
        typename std::enable_if_t<std::uses_allocator<Container, Alloc>::value>* = nullptr>
    explicit Stack(const Stack& other_stack,
                   const Alloc& alloc) noexcept:
        container_(other_stack.container_, alloc) {}

    template<typename Alloc,
        typename std::enable_if_t<std::uses_allocator<Container, Alloc>::value>* = nullptr>
    explicit Stack(Stack&& other_stack,
                   const Alloc& alloc) noexcept:
        container_(std::move(other_stack.container_), alloc) {}

    ~Stack() = default;

    Stack& operator=(const Stack& other_stack) {
      container_ = other_stack.container_;
      return *this;
    }

    Stack& operator=(Stack&& other_stack) noexcept {
      container_ = std::move(other_stack.container_);
      return *this;
    }

    ReferenceT top() {
      return container_.back();
    }

    ReferenceT getTop() {
      return container_.back();
    }

    ConstReferenceT top() const {
      return container_.cback();
    }

    ConstReferenceT getTop() const {
      return container_.cback();
    }

    [[nodiscard]] bool empty() const {
      return container_.empty();
    }

    [[nodiscard]] bool isEmpty() const {
      return container_.empty();
    }

    SizeT size() const {
      return container_.size();
    }

    SizeT getSize() const {
      return container_.size();
    }

    void push(const ValueT& value) {
      container_.push_back(value);
    }

    void push(ValueT&& value) {
      container_.push_back(std::move(value));
    }

    template<typename... Args>
    decltype(auto) emplace(Args&& ... args) {
      container_.id2(std::forward<Args>(args)...);
    }

    void pop() {
      container_.pop_back();
    }

    void swap(Stack&& other_stack) {
      std::swap(container_, other_stack.container_);
    }





  };
}

struct Tower {
  size_t i;
  size_t height = 0;
};

int main() {
  std::setvbuf(stdout, nullptr, _IOFBF, 512);
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  size_t n_sets;
  std::cin >> n_sets;
  for (size_t set_i = 0; set_i < n_sets; set_i++) {
    size_t n, id0, delta;
    std::cin >> n >> id0 >> delta;
    

    auto cmpTower = [](const Tower& a,
                       const Tower& b) {
      return a.height > b.height;
    };
    std::priority_queue<Tower, Ssvtl::Vector<Tower>, decltype(cmpTower)> towers(cmpTower);
    for (size_t i = 0; i < id0; i++) {
      towers.push({i});
    }
    std::cout << "YES\n";
    for (size_t i = 0; i < n; i++) {
      Tower id3 = towers.top();
      towers.pop();
      size_t value;
      std::cin >> value;
      std::cout << id3.i + 1 << ' ';
      id3.height += value;
      towers.push(id3);
    }
    std::cout << '\n';
  }

  return 0;
}