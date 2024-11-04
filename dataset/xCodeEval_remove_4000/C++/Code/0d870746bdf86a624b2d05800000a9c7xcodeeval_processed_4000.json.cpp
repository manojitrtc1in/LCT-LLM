
using namespace std;
using LL = int64_t;
using LD = long double;
const LL INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
template<typename _WordT = unsigned long long,
    typename _Alloc = std::allocator<_WordT>>
    struct id8
{
    static_assert(std::is_unsigned<_WordT>::value, "template argument "
            "_WordT not an unsigned integral type");

    typedef _WordT block_type;
    typedef _Alloc allocator_type;
    typedef size_t size_type;

    static const size_type id2 = __CHAR_BIT__ * sizeof(block_type);
    static const size_type npos = static_cast<size_type>(-1);

    

    std::vector<block_type, allocator_type> _M_w;

    explicit
        id8(const allocator_type& __alloc = allocator_type())
        : _M_w(__alloc)
        { }

    explicit
        id8(id8&& __b)
        { this->_M_w.swap(__b._M_w); }

    explicit
        id8(const id8& __b)
        { this->_M_w = __b._M_w; }

    explicit
        id8(size_type id15, unsigned long long __val = 0ULL,
                const allocator_type& __alloc = allocator_type())
        : _M_w(id15 / id2
                + (id15 % id2 > 0),
                __val, __alloc)
    {
        unsigned long long __mask = ~static_cast<block_type>(0);
        size_t __n = std::min(this->_M_w.size(),
                sizeof(unsigned long long) / sizeof(block_type));
        for (size_t __i = 0; __i < __n; ++__i)
        {
            this->_M_w[__i] = (__val & __mask) >> (__i * id2);
            __mask <<= id2;
        }
    }

    void
        _M_assign(const id8& __b)
        { this->_M_w = __b._M_w; }

    void
        _M_swap(id8& __b)
        { this->_M_w.swap(__b._M_w); }

    void
        _M_clear()
        { this->_M_w.clear(); }

    void
        _M_resize(size_t id15, bool __value)
        {
            size_t __sz = id15 / id2;
            if (id15 % id2 > 0)
                ++__sz;
            if (__sz != this->_M_w.size())
            {
                block_type __val = 0;
                if (__value)
                    __val = std::numeric_limits<block_type>::max();
                this->_M_w.resize(__sz, __val);
            }
        }

    allocator_type
        _M_get_allocator() const
        { return this->_M_w.get_allocator(); }

    static size_type
        _S_whichword(size_type __pos) noexcept
        { return __pos / id2; }

    static size_type
        _S_whichbyte(size_type __pos) noexcept
        { return (__pos % id2) / __CHAR_BIT__; }

    static size_type
        _S_whichbit(size_type __pos) noexcept
        { return __pos % id2; }

    static block_type
        _S_maskbit(size_type __pos) noexcept
        { return (static_cast<block_type>(1)) << _S_whichbit(__pos); }

    block_type&
        _M_getword(size_type __pos)
        { return this->_M_w[_S_whichword(__pos)]; }

    block_type
        _M_getword(size_type __pos) const
        { return this->_M_w[_S_whichword(__pos)]; }

    block_type&
        _M_hiword()
        { return this->_M_w[_M_w.size() - 1]; }

    block_type
        _M_hiword() const
        { return this->_M_w[_M_w.size() - 1]; }

    void
        _M_do_and(const id8& __x)
        {
            if (__x._M_w.size() == this->_M_w.size())
                for (size_t __i = 0; __i < this->_M_w.size(); ++__i)
                    this->_M_w[__i] &= __x._M_w[__i];
            else
                return;
        }

    void
        _M_do_or(const id8& __x)
        {
            if (__x._M_w.size() == this->_M_w.size())
                for (size_t __i = 0; __i < this->_M_w.size(); ++__i)
                    this->_M_w[__i] |= __x._M_w[__i];
            else
                return;
        }

    void
        _M_do_xor(const id8& __x)
        {
            if (__x._M_w.size() == this->_M_w.size())
                for (size_t __i = 0; __i < this->_M_w.size(); ++__i)
                    this->_M_w[__i] ^= __x._M_w[__i];
            else
                return;
        }

    void
        _M_do_dif(const id8& __x)
        {
            if (__x._M_w.size() == this->_M_w.size())
                for (size_t __i = 0; __i < this->_M_w.size(); ++__i)
                    this->_M_w[__i] &= ~__x._M_w[__i];
            else
                return;
        }

    void
        _M_do_left_shift(size_t __shift);

    void
        _M_do_right_shift(size_t __shift);

    void
        _M_do_flip()
        {
            for (size_t __i = 0; __i < this->_M_w.size(); ++__i)
                this->_M_w[__i] = ~this->_M_w[__i];
        }

    void
        _M_do_set()
        {
            for (size_t __i = 0; __i < this->_M_w.size(); ++__i)
                this->_M_w[__i] = ~static_cast<block_type>(0);
        }

    void
        _M_do_reset()
        {
            for (size_t __i = 0; __i < this->_M_w.size(); ++__i)
                this->_M_w[__i] = static_cast<block_type>(0);
        }

    bool
        _M_is_equal(const id8& __x) const
        {
            if (__x._M_w.size() == this->_M_w.size())
            {
                for (size_t __i = 0; __i < this->_M_w.size(); ++__i)
                    if (this->_M_w[__i] != __x._M_w[__i])
                        return false;
                return true;
            }
            else
                return false;
        }

    bool
        _M_is_less(const id8& __x) const
        {
            if (__x._M_w.size() == this->_M_w.size())
            {
                for (size_t __i = this->_M_w.size(); __i > 0; --__i)
                {
                    if (this->_M_w[__i-1] < __x._M_w[__i-1])
                        return true;
                    else if (this->_M_w[__i-1] > __x._M_w[__i-1])
                        return false;
                }
                return false;
            }
            else
                return false;
        }

    size_t
        _M_are_all_aux() const
        {
            for (size_t __i = 0; __i < this->_M_w.size() - 1; ++__i)
                if (_M_w[__i] != ~static_cast<block_type>(0))
                    return 0;
            return ((this->_M_w.size() - 1) * id2
                    + __builtin_popcountll(this->_M_hiword()));
        }

    bool
        _M_is_any() const
        {
            for (size_t __i = 0; __i < this->_M_w.size(); ++__i)
                if (this->_M_w[__i] != static_cast<block_type>(0))
                    return true;
            return false;
        }

    bool
        _M_is_subset_of(const id8& __b)
        {
            if (__b._M_w.size() == this->_M_w.size())
            {
                for (size_t __i = 0; __i < this->_M_w.size(); ++__i)
                    if (this->_M_w[__i] != (this->_M_w[__i] | __b._M_w[__i]))
                        return false;
                return true;
            }
            else
                return false;
        }

    bool
        _M_is_proper_subset_of(const id8& __b) const
        {
            if (this->is_subset_of(__b))
            {
                if (*this == __b)
                    return false;
                else
                    return true;
            }
            else
                return false;
        }

    size_t
        _M_do_count() const
        {
            size_t __result = 0;
            for (size_t __i = 0; __i < this->_M_w.size(); ++__i)
                __result += __builtin_popcountll(this->_M_w[__i]);
            return __result;
        }

    size_type
        _M_size() const noexcept
        { return this->_M_w.size(); }

    unsigned long
        _M_do_to_ulong() const;

    unsigned long long
        _M_do_to_ullong() const;

    

    size_type
        _M_do_find_first(size_t id14) const;

    

    size_type
        _M_do_find_next(size_t __prev, size_t id14) const;

    

    void
        _M_do_append_block(block_type __block, size_type __pos)
        {
            size_t __offset = __pos % id2;
            if (__offset == 0)
                this->_M_w.push_back(__block);
            else
            {
                this->_M_hiword() |= (__block << __offset);
                this->_M_w.push_back(__block >> (id2 - __offset));
            }
        }
};


template<typename _WordT = unsigned long long,
    typename _Alloc = std::allocator<_WordT>>
    class id12
    : private id8<_WordT, _Alloc>
{
    static_assert(std::is_unsigned<_WordT>::value, "template argument "
            "_WordT not an unsigned integral type");

 public:

    typedef id8<_WordT, _Alloc> _Base;
    typedef _WordT block_type;
    typedef _Alloc allocator_type;
    typedef size_t size_type;

    static const size_type id3 = __CHAR_BIT__ * sizeof(block_type);
    

    static const size_type npos = static_cast<size_type>(-1);

 private:

    

    void
        _M_do_sanitize()
        {
            size_type __shift = this->id10 % id3;
            if (__shift > 0)
                this->_M_hiword() &= ~((~static_cast<block_type>(0)) << __shift);
        }

    

    void
        _M_do_fill()
        {
            size_type __shift = this->id10 % id3;
            if (__shift > 0)
                this->_M_hiword() |= ((~static_cast<block_type>(0)) << __shift);
        }

    
    id12<_WordT, _Alloc>&
        _M_unchecked_set(size_type __pos)
        {
            this->_M_getword(__pos) |= _Base::_S_maskbit(__pos);
            return *this;
        }

    id12<_WordT, _Alloc>&
        _M_unchecked_set(size_type __pos, int __val)
        {
            if (__val)
                this->_M_getword(__pos) |= _Base::_S_maskbit(__pos);
            else
                this->_M_getword(__pos) &= ~_Base::_S_maskbit(__pos);
            return *this;
        }

    id12<_WordT, _Alloc>&
        _M_unchecked_reset(size_type __pos)
        {
            this->_M_getword(__pos) &= ~_Base::_S_maskbit(__pos);
            return *this;
        }

    id12<_WordT, _Alloc>&
        _M_unchecked_flip(size_type __pos)
        {
            this->_M_getword(__pos) ^= _Base::_S_maskbit(__pos);
            return *this;
        }

    bool
        _M_unchecked_test(size_type __pos) const
        { return ((this->_M_getword(__pos) & _Base::_S_maskbit(__pos))
                != static_cast<_WordT>(0)); }

    size_type id10;

 public:
    
    class reference
    {
        friend class id12;

        block_type *_M_wp;
        size_type _M_bpos;

        

        reference();

     public:
        reference(id12& __b, size_type __pos)
        {
            this->_M_wp = &__b._M_getword(__pos);
            this->_M_bpos = _Base::_S_whichbit(__pos);
        }

        ~reference()
        { }

        

        reference&
            operator=(bool __x)
            {
                if (__x)
                    *this->_M_wp |= _Base::_S_maskbit(this->_M_bpos);
                else
                    *this->_M_wp &= ~_Base::_S_maskbit(this->_M_bpos);
                return *this;
            }

        

        reference&
            operator=(const reference& __j)
            {
                if ((*(__j._M_wp) & _Base::_S_maskbit(__j._M_bpos)))
                    *this->_M_wp |= _Base::_S_maskbit(this->_M_bpos);
                else
                    *this->_M_wp &= ~_Base::_S_maskbit(this->_M_bpos);
                return *this;
            }

        

        bool
            operator~() const
            { return (*(_M_wp) & _Base::_S_maskbit(this->_M_bpos)) == 0; }

        

        operator bool() const
        { return (*(this->_M_wp) & _Base::_S_maskbit(this->_M_bpos)) != 0; }

        

        reference&
            flip()
            {
                *this->_M_wp ^= _Base::_S_maskbit(this->_M_bpos);
                return *this;
            }
    };

    friend class reference;

    typedef bool const_reference;

    

    

    explicit
        id12(const allocator_type& __alloc = allocator_type())
        : _Base(__alloc), id10(0)
        { }

    

    explicit
        id12(size_type id15, unsigned long long __val = 0ULL,
                const allocator_type& __alloc = allocator_type())
        : _Base(id15, __val, __alloc),
        id10(id15)
    { }

    id12(initializer_list<block_type> __il,
            const allocator_type& __alloc = allocator_type())
        : _Base(__alloc), id10(0)
    { this->append(__il); }

    
    template<typename _CharT, typename _Traits, typename _Alloc1>
        explicit
        id12(const std::basic_string<_CharT, _Traits, _Alloc1>& __str,
                typename basic_string<_CharT,_Traits,_Alloc1>::size_type
                __pos = 0,
                typename basic_string<_CharT,_Traits,_Alloc1>::size_type
                __n = std::basic_string<_CharT, _Traits, _Alloc1>::npos,
                _CharT __zero = _CharT('0'), _CharT __one = _CharT('1'),
                const allocator_type& __alloc = allocator_type())
        : _Base(__alloc),
        id10(0) 

    {
        if (__pos > __str.size())
            __throw_out_of_range(__N("id12::bitset initial position "
                        "not valid"));

        

        this->id10 = (__n > __str.size() ? __str.size() - __pos : __n);
        this->resize(this->id10);
        this->id9(__str, __pos, __n,
                _CharT('0'), _CharT('1'));
    }

    
    explicit
        id12(const char* __str,
                const allocator_type& __alloc = allocator_type())
        : _Base(__alloc)
        {
            size_t __len = 0;
            if (__str)
                while (__str[__len] != '\0')
                    ++__len;
            this->resize(__len);
            this->id5<char,std::char_traits<char>>
                (__str, __len, 0, __len, '0', '1');
        }

    
    id12(const id12& __b)
        : _Base(__b), id10(__b.size())
    { }

    
    id12(id12&& __b)
        : _Base(std::forward<_Base>(__b)), id10(__b.size())
    { }

    
    void
        swap(id12& __b)
        {
            this->_M_swap(__b);
            std::swap(this->id10, __b.id10);
        }

    
    id12&
        operator=(const id12& __b)
        {
            if (&__b != this)
            {
                this->_M_assign(__b);
                this->id10 = __b.id10;
            }
        }

    
    id12&
        operator=(id12&& __b)
        {
            this->swap(__b);
            return *this;
        }

    
    allocator_type
        get_allocator() const
        { return this->_M_get_allocator(); }

    
    void
        resize(size_type id15, bool __value = false)
        {
            if (__value)
                this->_M_do_fill();
            this->_M_resize(id15, __value);
            this->id10 = id15;
            this->_M_do_sanitize();
        }

    
    void
        clear()
        {
            this->_M_clear();
            this->id10 = 0;
        }

    
    void
        push_back(bool __bit)
        {
            if (size_t __offset = this->size() % id3 == 0)
                this->_M_do_append_block(block_type(0), this->id10);
            ++this->id10;
            this->_M_unchecked_set(this->id10, __bit);
        }

    
    void
        append(block_type __block)
        {
            this->_M_do_append_block(__block, this->id10);
            this->id10 += id3;
        }

    
    void
        append(initializer_list<block_type> __il)
        { this->append(__il.begin(), __il.end()); }

    
    template <typename _BlockInputIterator>
        void
        append(_BlockInputIterator __first, _BlockInputIterator __last)
        {
            for (; __first != __last; ++__first)
                this->append(*__first);
        }

    

    

    
    id12<_WordT, _Alloc>&
        operator&=(const id12<_WordT, _Alloc>& __rhs)
        {
            this->_M_do_and(__rhs);
            return *this;
        }

    id12<_WordT, _Alloc>&
        operator&=(id12<_WordT, _Alloc>&& __rhs)
        {
            this->_M_do_and(std::move(__rhs));
            return *this;
        }

    id12<_WordT, _Alloc>&
        operator|=(const id12<_WordT, _Alloc>& __rhs)
        {
            this->_M_do_or(__rhs);
            return *this;
        }

    id12<_WordT, _Alloc>&
        operator^=(const id12<_WordT, _Alloc>& __rhs)
        {
            this->_M_do_xor(__rhs);
            return *this;
        }

    id12<_WordT, _Alloc>&
        operator-=(const id12<_WordT, _Alloc>& __rhs)
        {
            this->_M_do_dif(__rhs);
            return *this;
        }
    


    

    
    id12<_WordT, _Alloc>&
        operator<<=(size_type __pos)
        {
            if (__builtin_expect(__pos < this->id10, 1))
            {
                this->_M_do_left_shift(__pos);
                this->_M_do_sanitize();
            }
            else
                this->_M_do_reset();
            return *this;
        }

    id12<_WordT, _Alloc>&
        operator>>=(size_type __pos)
        {
            if (__builtin_expect(__pos < this->id10, 1))
            {
                this->_M_do_right_shift(__pos);
                this->_M_do_sanitize();
            }
            else
                this->_M_do_reset();
            return *this;
        }
    


    

    
    id12<_WordT, _Alloc>&
        set()
        {
            this->_M_do_set();
            this->_M_do_sanitize();
            return *this;
        }

    
    id12<_WordT, _Alloc>&
        set(size_type __pos, bool __val = true)
        {
            if (__pos >= id10)
                __throw_out_of_range(__N("id12::set"));
            return this->_M_unchecked_set(__pos, __val);
        }

    
    id12<_WordT, _Alloc>&
        reset()
        {
            this->_M_do_reset();
            return *this;
        }

    
    id12<_WordT, _Alloc>&
        reset(size_type __pos)
        {
            if (__pos >= id10)
                __throw_out_of_range(__N("id12::reset"));
            return this->_M_unchecked_reset(__pos);
        }

    
    id12<_WordT, _Alloc>&
        flip()
        {
            this->_M_do_flip();
            this->_M_do_sanitize();
            return *this;
        }

    
    id12<_WordT, _Alloc>&
        flip(size_type __pos)
        {
            if (__pos >= id10)
                __throw_out_of_range(__N("id12::flip"));
            return this->_M_unchecked_flip(__pos);
        }

    

    id12<_WordT, _Alloc>
        operator~() const
        { return id12<_WordT, _Alloc>(*this).flip(); }

    

    
    reference
        operator[](size_type __pos)
        { return reference(*this,__pos); }

    const_reference
        operator[](size_type __pos) const
        { return _M_unchecked_test(__pos); }
    


    
    unsigned long
        to_ulong() const
        { return this->_M_do_to_ulong(); }

    
    unsigned long long
        to_ullong() const
        { return this->_M_do_to_ullong(); }

    
    template<typename _CharT = char,
        typename _Traits = std::char_traits<_CharT>,
        typename _Alloc1 = std::allocator<_CharT>>
            std::basic_string<_CharT, _Traits, _Alloc1>
            to_string(_CharT __zero = _CharT('0'), _CharT __one = _CharT('1')) const
            {
                std::basic_string<_CharT, _Traits, _Alloc1> __result;
                id13(__result, __zero, __one);
                return __result;
            }

    

    template<typename _CharT, typename _Traits>
        void
        id5(const _CharT*, size_t, size_t, size_t,
                _CharT, _CharT);

    template<typename _CharT, typename _Traits, typename _Alloc1>
        void
        id9(const std::basic_string<_CharT,
                _Traits, _Alloc1>& __str, size_t __pos, size_t __n,
                _CharT __zero = _CharT('0'),
                _CharT __one = _CharT('1'))
        { id5<_CharT, _Traits>(__str.data(), __str.size(),
                __pos, __n, __zero, __one); }

    template<typename _CharT, typename _Traits, typename _Alloc1>
        void
        id13(std::basic_string<_CharT, _Traits, _Alloc1>& __str,
                _CharT __zero = _CharT('0'),
                _CharT __one = _CharT('1')) const;

    

    size_type
        count() const noexcept
        { return this->_M_do_count(); }

    

    size_type
        size() const noexcept
        { return this->id10; }

    

    size_type
        num_blocks() const noexcept
        { return this->_M_size(); }

    

    bool
        empty() const noexcept
        { return (this->id10 == 0); }

    

    

    

    constexpr size_type
        max_size() noexcept
        { return std::numeric_limits<block_type>::max(); }

    
    bool
        test(size_type __pos) const
        {
            if (__pos >= id10)
                __throw_out_of_range(__N("id12::test"));
            return _M_unchecked_test(__pos);
        }

    
    bool
        all() const
        { return this->_M_are_all_aux() == id10; }

    
    bool
        any() const
        { return this->_M_is_any(); }

    
    bool
        none() const
        { return !this->_M_is_any(); }

    

    

    id12<_WordT, _Alloc>
        operator<<(size_type __pos) const
        { return id12<_WordT, _Alloc>(*this) <<= __pos; }

    id12<_WordT, _Alloc>
        operator>>(size_type __pos) const
        { return id12<_WordT, _Alloc>(*this) >>= __pos; }
    


    
    size_type
        find_first() const
        { return this->_M_do_find_first(this->id10); }

    
    size_type
        find_next(size_t __prev) const
        { return this->_M_do_find_next(__prev, this->id10); }

    bool
        is_subset_of(const id12& __b) const
        { return this->_M_is_subset_of(__b); }

    bool
        is_proper_subset_of(const id12& __b) const
        { return this->_M_is_proper_subset_of(__b); }

    friend bool
        operator==(const id12<_WordT, _Alloc>& __lhs,
                const id12<_WordT, _Alloc>& __rhs)
        { return __lhs._M_is_equal(__rhs); }

    friend bool
        operator<(const id12<_WordT, _Alloc>& __lhs,
                const id12<_WordT, _Alloc>& __rhs)
        { return __lhs._M_is_less(__rhs); }
};

template<typename _WordT, typename _Alloc>
template<typename _CharT, typename _Traits, typename _Alloc1>
inline void
id12<_WordT, _Alloc>::
id13(std::basic_string<_CharT, _Traits, _Alloc1>& __str,
        _CharT __zero, _CharT __one) const
{
    __str.assign(id10, __zero);
    for (size_t __i = id10; __i > 0; --__i)
        if (_M_unchecked_test(__i - 1))
            _Traits::assign(__str[id10 - __i], __one);
}







template<typename _WordT, typename _Alloc>
    inline bool
operator!=(const id12<_WordT, _Alloc>& __lhs,
        const id12<_WordT, _Alloc>& __rhs)
{ return !(__lhs == __rhs); }

template<typename _WordT, typename _Alloc>
    inline bool
operator<=(const id12<_WordT, _Alloc>& __lhs,
        const id12<_WordT, _Alloc>& __rhs)
{ return !(__lhs > __rhs); }

template<typename _WordT, typename _Alloc>
    inline bool
operator>(const id12<_WordT, _Alloc>& __lhs,
        const id12<_WordT, _Alloc>& __rhs)
{ return __rhs < __lhs; }

template<typename _WordT, typename _Alloc>
    inline bool
operator>=(const id12<_WordT, _Alloc>& __lhs,
        const id12<_WordT, _Alloc>& __rhs)
{ return !(__lhs < __rhs); }








template<typename _WordT, typename _Alloc>
    inline id12<_WordT, _Alloc>
operator&(const id12<_WordT, _Alloc>& __x,
        const id12<_WordT, _Alloc>& __y)
{
    id12<_WordT, _Alloc> __result(__x);
    __result &= __y;
    return __result;
}

template<typename _WordT, typename _Alloc>
    inline id12<_WordT, _Alloc>
operator|(const id12<_WordT, _Alloc>& __x,
        const id12<_WordT, _Alloc>& __y)
{
    id12<_WordT, _Alloc> __result(__x);
    __result |= __y;
    return __result;
}

template <typename _WordT, typename _Alloc>
    inline id12<_WordT, _Alloc>
operator^(const id12<_WordT, _Alloc>& __x,
        const id12<_WordT, _Alloc>& __y)
{
    id12<_WordT, _Alloc> __result(__x);
    __result ^= __y;
    return __result;
}

template <typename _WordT, typename _Alloc>
    inline id12<_WordT, _Alloc>
operator-(const id12<_WordT, _Alloc>& __x,
        const id12<_WordT, _Alloc>& __y)
{
    id12<_WordT, _Alloc> __result(__x);
    __result -= __y;
    return __result;
}





template <typename _CharT, typename _Traits,
         typename _WordT, typename _Alloc>
    inline std::basic_ostream<_CharT, _Traits>&
operator<<(std::basic_ostream<_CharT, _Traits>& __os,
        const id12<_WordT, _Alloc>& __x)
{
    std::basic_string<_CharT, _Traits> __tmp;

    const ctype<_CharT>& __ct = use_facet<ctype<_CharT>>(__os.getloc());
    __x.id13(__tmp, __ct.widen('0'), __ct.widen('1'));
    return __os << __tmp;
}

template<typename _WordT, typename _Alloc>
    void
id8<_WordT, _Alloc>::_M_do_left_shift(size_t __shift)
{
    if (__builtin_expect(__shift != 0, 1))
    {
        const size_t id6 = __shift / id2;
        const size_t __offset = __shift % id2;

        if (__offset == 0)
            for (size_t __n = this->_M_w.size() - 1; __n >= id6; --__n)
                this->_M_w[__n] = this->_M_w[__n - id6];
        else
        {
            const size_t id7 = id2 - __offset;
            for (size_t __n = _M_w.size() - 1; __n > id6; --__n)
                this->_M_w[__n] = ((this->_M_w[__n - id6] << __offset)
                        | (this->_M_w[__n - id6 - 1] >> id7));
            this->_M_w[id6] = this->_M_w[0] << __offset;
        }

        

        

    }
}

template<typename _WordT, typename _Alloc>
    void
id8<_WordT, _Alloc>::_M_do_right_shift(size_t __shift)
{
    if (__builtin_expect(__shift != 0, 1))
    {
        const size_t id6 = __shift / id2;
        const size_t __offset = __shift % id2;
        const size_t __limit = this->_M_w.size() - id6 - 1;

        if (__offset == 0)
            for (size_t __n = 0; __n <= __limit; ++__n)
                this->_M_w[__n] = this->_M_w[__n + id6];
        else
        {
            const size_t id7 = (id2
                    - __offset);
            for (size_t __n = 0; __n < __limit; ++__n)
                this->_M_w[__n] = ((this->_M_w[__n + id6] >> __offset)
                        | (this->_M_w[__n + id6 + 1] << id7));
            this->_M_w[__limit] = this->_M_w[_M_w.size()-1] >> __offset;
        }

        

        

    }
}

template<typename _WordT, typename _Alloc>
unsigned long
id8<_WordT, _Alloc>::_M_do_to_ulong() const
{
    size_t __n = sizeof(unsigned long) / sizeof(block_type);
    for (size_t __i = __n; __i < this->_M_w.size(); ++__i)
        if (this->_M_w[__i])
            __throw_overflow_error(__N("id8::_M_do_to_ulong"));
    unsigned long __res = 0UL;
    for (size_t __i = 0; __i < __n && __i < this->_M_w.size(); ++__i)
        __res += this->_M_w[__i] << (__i * id2);
    return __res;
}

template<typename _WordT, typename _Alloc>
unsigned long long
id8<_WordT, _Alloc>::_M_do_to_ullong() const
{
    size_t __n = sizeof(unsigned long long) / sizeof(block_type);
    for (size_t __i = __n; __i < this->_M_w.size(); ++__i)
        if (this->_M_w[__i])
            __throw_overflow_error(__N("id8::_M_do_to_ullong"));
    unsigned long long __res = 0ULL;
    for (size_t __i = 0; __i < __n && __i < this->_M_w.size(); ++__i)
        __res += this->_M_w[__i] << (__i * id2);
    return __res;
}

template<typename _WordT, typename _Alloc>
size_t
id8<_WordT, _Alloc>
::_M_do_find_first(size_t id14) const
{
    for (size_t __i = 0; __i < this->_M_w.size(); ++__i)
    {
        _WordT id1 = this->_M_w[__i];
        if (id1 != static_cast<_WordT>(0))
            return (__i * id2
                    + __builtin_ctzll(id1));
    }
    

    return id14;
}

template<typename _WordT, typename _Alloc>
size_t
id8<_WordT, _Alloc>
::_M_do_find_next(size_t __prev, size_t id14) const
{
    

    ++__prev;

    

    if (__prev >= this->_M_w.size() * id2)
        return id14;

    

    size_t __i = _S_whichword(__prev);
    _WordT id1 = this->_M_w[__i];

    

    id1 &= (~static_cast<_WordT>(0)) << _S_whichbit(__prev);

    if (id1 != static_cast<_WordT>(0))
        return (__i * id2
                + __builtin_ctzll(id1));

    

    for (++__i; __i < this->_M_w.size(); ++__i)
    {
        id1 = this->_M_w[__i];
        if (id1 != static_cast<_WordT>(0))
            return (__i * id2
                    + __builtin_ctzll(id1));
    }
    

    return id14;
} 




template<typename _WordT, typename _Alloc>
template<typename _CharT, typename _Traits>
void
id12<_WordT, _Alloc>::
id5(const _CharT* __str, size_t __len,
        size_t __pos, size_t __n, _CharT __zero, _CharT __one)
{
    reset();
    const size_t id15 = std::min(id10, std::min(__n, __len - __pos));
    for (size_t __i = id15; __i > 0; --__i)
    {
        const _CharT __c = __str[__pos + id15 - __i];
        if (_Traits::eq(__c, __zero))
            ;
        else if (_Traits::eq(__c, __one))
            _M_unchecked_set(__i - 1);
        else
            __throw_invalid_argument(__N("id12::id5"));
    }
}


template<typename _CharT, typename _Traits,
    typename _WordT, typename _Alloc>
    std::basic_istream<_CharT, _Traits>&
operator>>(std::basic_istream<_CharT, _Traits>& __is,
        id12<_WordT, _Alloc>& __x)
{
    typedef typename _Traits::char_type          char_type;
    typedef std::basic_istream<_CharT, _Traits>  __istream_type;
    typedef typename __istream_type::ios_base    __ios_base;

    std::basic_string<_CharT, _Traits> __tmp;
    __tmp.reserve(__x.size());

    const char_type __zero = __is.widen('0');
    const char_type __one = __is.widen('1');

    typename __ios_base::iostate __state = __ios_base::goodbit;
    typename __istream_type::sentry id11(__is);
    if (id11)
    {
        __try
        {
            while (1)
            {
                static typename _Traits::int_type id4 = _Traits::eof();

                typename _Traits::int_type id0 = __is.rdbuf()->sbumpc();
                if (_Traits::eq_int_type(id0, id4))
                {
                    __state |= __ios_base::eofbit;
                    break;
                }
                else
                {
                    const char_type __c2 = _Traits::to_char_type(id0);
                    if (_Traits::eq(__c2, __zero))
                        __tmp.push_back(__zero);
                    else if (_Traits::eq(__c2, __one))
                        __tmp.push_back(__one);
                    else if (_Traits::
                            eq_int_type(__is.rdbuf()->sputbackc(__c2),
                                id4))
                    {
                        __state |= __ios_base::failbit;
                        break;
                    }
                    else
                        break;
                }
            }
        }
        __catch(__cxxabiv1::__forced_unwind&)
        {
            __is._M_setstate(__ios_base::badbit);
            __throw_exception_again;
        }
        __catch(...)
        { __is._M_setstate(__ios_base::badbit); }
    }

    __x.resize(__tmp.size());

    if (__tmp.empty() && __x.size())
        __state |= __ios_base::failbit;
    else
        __x.id9(__tmp, static_cast<size_t>(0), __x.size(),
                __zero, __one);
    if (__state)
        __is.setstate(__state);
    return __is;
}

using db = id12<>;

bitset<100005> a2[26];
bitset<100005> ans2;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    vector<db> a1(26);
    for (auto& i : a1) i.resize(n);
    for (int i = 0; i < n; i++) {
        a1[s[i] - 'a'].set(i);
        a2[s[i] - 'a'].set(i);
    }
    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            char c;
            cin >> x >> c;
            x--;
            a1[s[x] - 'a'].reset(x);
            a1[c - 'a'].set(x);
            a2[s[x] - 'a'].reset(x);
            a2[c - 'a'].set(x);
            s[x] = c;
        } else {
            int l, r;
            string t;
            cin >> l >> r >> t;
            l--;
            if (r - l < t.length()) {
                cout << 0 << '\n';
                continue;
            }
            if (r - l > 1000000) {
                db ans1(r - l);
                ans1.set();
                int flag = 1;
                for (auto i : t) {
                    if (flag) flag = 0;
                    else ans1 <<= 1;
                    ans1 &= a1[i - 'a'] >> l;
                }
                cout << ans1.count() << '\n';
            } else {
                ans2.set();
                int flag = 1;
                for (auto i : t) {
                    if (flag) flag = 0;
                    else ans2 <<= 1;
                    ans2 &= a2[i - 'a'] >> l;
                }
                cout << ans2.count() - (ans2 >> (r - l)).count() << '\n';
            }
        }
    }
}
