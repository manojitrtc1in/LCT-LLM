


using namespace std; 
typedef long long ll;



template< typename T >
struct id10 {
    std::vector< T > data;
    id10(int sz) {
        data.assign(++sz, 0);
    }
    
    inline T sum(int k) {
        T ret = 0;
        for (++k; k > 0; k -= k & -k) ret += data[k];
        return (ret);
    }
    
    inline T sum(int left, int right) {
        return sum(right) - sum(left - 1);
    }
    
    
    inline void add(int k, T x) {
        for (++k; k < data.size(); k += k & -k) data[k] += x;
    }
    
    int lower_bound(ll k) {
        if (k <= 0) return 0;
        int res = 0;
        int N = 1; while (N < (int)data.size()) N *= 2;
        for (int i = N / 2; i > 0; i /= 2) {
            if (res + i < (int)data.size() && data[res + i] < k) {
                k -= data[res + i];
                res += i;
            }
        }
        return res;
    }
    void print() {
        std::cout << "[ ";
        for (int i = 0; i < data.size() - 1; i++) {
            std::cout << sum(i, i);
            if (i < data.size() - 2) cout << ", ";
        }
        std::cout << " ]" << endl;
    }
};


enum {
    NOTFOUND = 0xFFFFFFFFFFFFFFFFLLU
};
class id13 {
private:
    const uint64_t size;    
    static const uint64_t blockBitNum = 16;
    static const uint64_t LEVEL_L = 512;
    static const uint64_t LEVEL_S = 16;
    std::vector<uint64_t> L;   
    std::vector<uint16_t> S;   
    std::vector<uint16_t> B;   
    uint64_t numOne = 0;       
public:
    explicit id13(const uint64_t n) : size(n) {
        const uint64_t s = (n + blockBitNum - 1) / blockBitNum + 1;   
        this->B.assign(s, 0);
        this->L.assign(n / LEVEL_L + 1, 0);
        this->S.assign(n / LEVEL_S + 1, 0);
    }
    
    void setBit(const uint64_t bit, const uint64_t pos){
        assert(bit == 0 or bit == 1);
        assert(pos < this->size);
        const uint64_t blockPos = pos / blockBitNum;
        const uint64_t offset = pos % blockBitNum;
        if (bit == 1) { B.at(blockPos) |= (1LLU << offset); }
        else          { B.at(blockPos) &= (~(1LLU << offset)); }
    }
    
    uint64_t access(const uint64_t pos) {
        assert(pos < this->size);
        const uint64_t blockPos = pos / blockBitNum;
        const uint64_t offset   = pos % blockBitNum;
        return ((B.at(blockPos) >> offset) & 1);
    }
    void build() {
        uint64_t num = 0;
        for (uint64_t i = 0; i <= size; i++){
            if (i % LEVEL_L == 0) {
                L.at(i / LEVEL_L) = num;
            }
            if (i % LEVEL_S == 0) {
                S.at(i / LEVEL_S) = num - L.at(i / LEVEL_L);
            }
            if (i != size and i % blockBitNum == 0) {
                num += this->popCount(this->B.at(i / blockBitNum));
            }
        }
        this-> numOne = num;
    }
    
    uint64_t rank(const uint64_t bit, const uint64_t pos) {
        assert(bit == 0 or bit == 1);
        assert(pos <= this->size);
        if (bit) {
            return L[pos / LEVEL_L] + S[pos / LEVEL_S] + popCount(B[pos / blockBitNum] & ((1 << (pos % blockBitNum)) - 1));
        }
        else {
            return pos - rank(1, pos);
        }
    }
    
    uint64_t select(const uint64_t bit, const uint64_t rank) {
        assert(bit == 0 or bit == 1);
        assert(rank > 0);
        if (bit == 0 and rank > this->size - this-> numOne) { return NOTFOUND; }
        if (bit == 1 and rank > this-> numOne)              { return NOTFOUND; }
        
        uint64_t large_idx = 0;
        {
            uint64_t left = 0;
            uint64_t right = L.size();
            while (right - left > 1) {
                uint64_t mid = (left + right) / 2;
                uint64_t r = L.at(mid);
                r = (bit) ? r : mid * LEVEL_L - L.at(mid);
                if (r < rank) {
                    left = mid;
                    large_idx = mid;
                } else {
                    right = mid;
                }
            }
        }
        
        uint64_t small_idx = (large_idx * LEVEL_L) / LEVEL_S;
        {
            uint64_t left = (large_idx * LEVEL_L) / LEVEL_S;
            uint64_t right = std::min(((large_idx  + 1) * LEVEL_L) / LEVEL_S, (uint64_t)S.size());
            while (right - left > 1) {
                uint64_t mid = (left + right) / 2;
                uint64_t r = L.at(large_idx) + S.at(mid);
                r = (bit) ? r :mid * LEVEL_S - r;
                if (r < rank) {
                    left = mid;
                    small_idx = mid;
                } else {
                    right = mid;
                }
            }
        }
        
        uint64_t rank_pos = 0;
        {
            const uint64_t id9 = (small_idx * LEVEL_S) / blockBitNum;
            uint64_t total_bit = L.at(large_idx) + S.at(small_idx);
            if (bit == 0) {
                total_bit = small_idx * LEVEL_S - total_bit;
            }
            for (uint64_t i = 0;; ++i) {
                uint64_t b = popCount(B.at(id9 + i));
                if (bit == 0) {
                    b = blockBitNum - b;
                }
                if (total_bit + b >= rank) {
                    uint64_t block = (bit) ? B.at(id9 + i) : ~B.at(id9 + i);
                    rank_pos = (id9 + i) * blockBitNum + selectInBlock(block, rank - total_bit);
                    break;
                }
                total_bit += b;
            }
        }
        return rank_pos + 1;
    }
    uint64_t getNumOne() const {
        return numOne;
    }
    void debug() {
        std::cout << "LEVEL_L(" << L.size() << ")" << std::endl;
        for (uint64_t i = 0 ; i < L.size(); ++i) {
            std::cout << L.at(i) << ", ";
        }
        std::cout << std::endl;
        std::cout << "LEVEL_S(" << S.size() << ")" << std::endl;
        for (uint64_t i = 0 ; i < S.size(); ++i) {
            std::cout << S.at(i) << ", ";
        }
        std::cout << std::endl;
    }
private:
    uint64_t popCount(uint64_t x) {
        x = (x & 0x5555555555555555ULL) + ((x >> 1) & 0x5555555555555555ULL);
        x = (x & 0x3333333333333333ULL) + ((x >> 2) & 0x3333333333333333ULL);
        x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0fULL;
        x = x + (x >>  8);
        x = x + (x >> 16);
        x = x + (x >> 32);
        return x & 0x7FLLU;
    }
    uint64_t selectInBlock(uint64_t x, uint64_t rank) {
        uint64_t x1 = x - ((x & 0xAAAAAAAAAAAAAAAALLU) >> 1);
        uint64_t x2 = (x1 & 0x3333333333333333LLU) + ((x1 >> 2) & 0x3333333333333333LLU);
        uint64_t x3 = (x2 + (x2 >> 4)) & 0x0F0F0F0F0F0F0F0FLLU;
        uint64_t pos = 0;
        for (;;  pos += 8){
            uint64_t rank_next = (x3 >> pos) & 0xFFLLU;
            if (rank <= rank_next) break;
            rank -= rank_next;
        }
        uint64_t v2 = (x2 >> pos) & 0xFLLU;
        if (rank > v2) {
            rank -= v2;
            pos += 4;
        }
        uint64_t v1 = (x1 >> pos) & 0x3LLU;
        if (rank > v1){
            rank -= v1;
            pos += 2;
        }
        uint64_t v0  = (x >> pos) & 0x1LLU;
        if (v0 < rank){
            rank -= v0;
            pos += 1;
        }
        return pos;
    }
};
class id2 {
private:
    std::vector<id13> bit_arrays;
    std::vector<uint64_t> begin_one;                    
    std::map<uint64_t, uint64_t> begin_alphabet;        
    std::vector<std::vector<uint64_t>> cumulative_sum;  
    uint64_t size;                                 
    uint64_t maximum_element;                      
    uint64_t bit_size;                             
public:
    id2 (const std::vector<uint64_t> &array) {
        assert(array.size() > 0);
        size = array.size();
        maximum_element =  *max_element(array.begin(), array.end()) + 1;
        bit_size = get_num_of_bit(maximum_element);
        if (bit_size == 0) {
            bit_size = 1;
        }
        for (uint64_t i = 0; i < bit_size; ++i) {
            id13 sv(size);
            bit_arrays.push_back(sv);
        }
        this->begin_one.resize(bit_size);
        this->cumulative_sum.resize(bit_size + 1, std::vector<uint64_t>(size + 1, 0));
        for (uint64_t j = 0; j < array.size(); ++j) {
            this->cumulative_sum.at(0).at(j + 1) = this->cumulative_sum.at(0).at(j) + array[j];
        }
        std::vector<uint64_t> v(array);
        for (uint64_t i = 0; i < bit_size; ++i) {
            std::vector<uint64_t> temp;
            
            for (uint64_t j = 0; j < v.size(); ++j) {
                uint64_t c = v.at(j);
                uint64_t bit = (c >> (bit_size - i - 1)) & 1;  
                if (bit == 0) {
                    temp.push_back(c);
                    bit_arrays.at(i).setBit(0, j);
                }
            }
            this->begin_one.at(i) = temp.size();
            
            for (uint64_t j = 0; j < v.size(); ++j) {
                uint64_t c = v.at(j);
                uint64_t bit = (c >> (bit_size - i - 1)) & 1;  
                if (bit == 1) {
                    temp.push_back(c);
                    bit_arrays.at(i).setBit(1, j);
                }
            }
            for (uint64_t j = 0; j < temp.size(); ++j) {
                this->cumulative_sum.at(i + 1).at(j + 1) = this->cumulative_sum.at(i + 1).at(j) + temp.at(j);
            }
            bit_arrays.at(i).build();
            v = temp;
        }
        
        for (int i = v.size() - 1; i >= 0; --i) {
            this->begin_alphabet[v.at(i)] = i;
        }
    }
    
    uint64_t access(uint64_t pos) {
        if (pos >= this->size) { return NOTFOUND; }
        uint64_t c = 0;
        for (uint64_t i = 0; i < bit_arrays.size(); ++i) {
            uint64_t bit = bit_arrays.at(i).access(pos);   
            c = (c <<= 1) | bit;
            pos = bit_arrays.at(i).rank(bit, pos);
            if (bit) {
                pos += this->begin_one.at(i);
            }
        }
        return c;
    }
    
    uint64_t select(uint64_t c, uint64_t rank) {
        assert(rank > 0);
        if (c >= maximum_element) {
            return NOTFOUND;
        }
        if (this->begin_alphabet.find(c) == this->begin_alphabet.end()) {
            return NOTFOUND;
        }
        uint64_t index = this->begin_alphabet.at(c) + rank;
        for (uint64_t i = 0; i < bit_arrays.size(); ++i){
            uint64_t bit = ((c >> i) & 1);      
            if (bit == 1) {
                index -= this->begin_one.at(bit_size - i - 1);
            }
            index = this->bit_arrays.at(bit_size - i - 1).select(bit, index);
        }
        return index;
    }
    
    uint64_t maxRange(uint64_t begin_pos, uint64_t end_pos) {
        return quantileRange(begin_pos, end_pos, end_pos - begin_pos - 1);
    }
    
    uint64_t minRange(uint64_t begin_pos, uint64_t end_pos) {
        return quantileRange(begin_pos, end_pos, 0);
    }
    
    
    uint64_t quantileRange(uint64_t begin_pos, uint64_t end_pos, uint64_t k) {
        if ((end_pos > size || begin_pos >= end_pos) || (k >= end_pos - begin_pos)) {
            return NOTFOUND;
        }
        uint64_t val = 0;
        for (uint64_t i = 0; i < bit_size; ++i) {
            const uint64_t id11 = bit_arrays.at(i).rank(0, begin_pos);
            const uint64_t id0 = bit_arrays.at(i).rank(0, end_pos);
            const uint64_t id18 = id0 - id11;     
            const uint64_t bit = (k < id18) ? 0 : 1;                       
            if (bit) {
                k -= id18;
                begin_pos = this->begin_one.at(i) + begin_pos - id11;
                end_pos = this->begin_one.at(i) + end_pos - id0;
            }
            else {
                begin_pos = id11;
                end_pos = id11 + id18;
            }
            val = ((val << 1) | bit);
        }
        uint64_t left = 0;
        for (uint64_t i = 0; i < bit_size; ++i) {
            const uint64_t bit = (val >> (bit_size - i - 1)) & 1;  
            left = bit_arrays.at(i).rank(bit, left);               
            if (bit) {
                left += this->begin_one.at(i);
            }
        }
        const uint64_t rank = begin_pos + k - left + 1;
        return select(val, rank) - 1;
    }
    
    uint64_t rank(uint64_t c, uint64_t pos) {
        assert(pos < size);
        if (c >= maximum_element) {
            return 0;
        }
        if (this->begin_alphabet.find(c) == this->begin_alphabet.end()) {
            return 0;
        }
        for (uint64_t i = 0; i < bit_size; ++i) {
            uint64_t bit = (c >> (bit_size - i - 1)) & 1;  
            pos = bit_arrays.at(i).rank(bit, pos);         
            if (bit) {
                pos += this->begin_one.at(i);
            }
        }
        uint64_t begin_pos = this->begin_alphabet.at(c);
        return pos - begin_pos;
    }
    
    uint64_t rangeFreq(uint64_t begin_pos, uint64_t end_pos, uint64_t min_c, uint64_t max_c) {
        if ((end_pos > size || begin_pos >= end_pos) || (min_c >= max_c) || min_c >= maximum_element) {
            return 0;
        }
        const auto id8 = rankAll(max_c, begin_pos, end_pos);
        const auto mini_t = rankAll(min_c, begin_pos, end_pos);
        return std::get<1>(id8) - std::get<1>(mini_t);
    }
    
    uint64_t rankLessThan(uint64_t c, uint64_t begin, uint64_t end) {
        auto t = rankAll(c, begin, end);
        return std::get<1>(t);
    }
    
    uint64_t rankMoreThan(uint64_t c, uint64_t begin, uint64_t end) {
        auto t = rankAll(c, begin, end);
        return std::get<2>(t);
    }
    
    std::tuple<uint64_t, uint64_t, uint64_t> rankAll(const uint64_t c, uint64_t begin, uint64_t end) {
        assert(end <= size);
        const uint64_t num = end - begin;
        if (begin >= end) {
            return std::make_tuple(0, 0, 0);
        }
        if (c >= maximum_element || end == 0) {
            return std::make_tuple(0, num, 0);
        }
        uint64_t id21 = 0, id1 = 0;
        for (size_t i = 0; i < bit_size && begin < end; ++i) {
            const uint64_t bit = (c >> (bit_size - i - 1)) & 1;
            const uint64_t id20 = this->bit_arrays.at(i).rank(0, begin);
            const uint64_t id22 = this->bit_arrays.at(i).rank(0, end);
            const uint64_t id3 = begin - id20;
            const uint64_t id19 = end - id22;
            if (bit) {
                id21 += (id22 - id20);    
                begin = this->begin_one.at(i) + id3;
                end = this->begin_one.at(i) + id19;
            } else {
                id1 += (id19 - id3);    
                begin = id20;
                end = id22;
            }
        }
        const uint64_t rank = num - id21 - id1;
        return std::make_tuple(rank, id21, id1);
    }
    
    
    std::vector<std::pair<uint64_t, uint64_t>> topk(uint64_t s, uint64_t e, uint64_t k) {
        assert(s < e);
        std::vector<std::pair<uint64_t, uint64_t>> result;
        
        auto c = [](const std::tuple<uint64_t, uint64_t, uint64_t, uint64_t, uint64_t> &l, const std::tuple<uint64_t, uint64_t, uint64_t, uint64_t, uint64_t> &r) {
            
            if (std::get<0>(l) != std::get<0>(r)) {
                return std::get<0>(l) < std::get<0>(r);
            }
            
            if (std::get<3>(l) != std::get<3>(r)) {
                return std::get<3>(l) > std::get<3>(r);
            }
            
            if (std::get<4>(l) != std::get<4>(r)) {
                return std::get<4>(l) > std::get<4>(r);
            }
            return true;
        };
        std::priority_queue<std::tuple<uint64_t, uint64_t, uint64_t, uint64_t, uint64_t>, std::vector<std::tuple<uint64_t, uint64_t, uint64_t, uint64_t, uint64_t>>, decltype(c)> que(c);  
        que.push(std::make_tuple(e - s, s, e, 0, 0));
        while (not que.empty()) {
            auto element = que.top(); que.pop();
            uint64_t width, left, right, depth, value;
            std::tie(width, left, right, depth, value) = element;
            if (depth >= this->bit_size) {
                result.emplace_back(std::make_pair(value, right - left));
                if (result.size() >= k) {
                    break;
                }
                continue;
            }
            
            const uint64_t left0 = this->bit_arrays.at(depth).rank(0, left);
            const uint64_t right0 = this->bit_arrays.at(depth).rank(0, right);
            if (left0 < right0) {
                que.push(std::make_tuple(right0 - left0, left0, right0, depth + 1, value));
            }
            
            const uint64_t left1 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, left);
            const uint64_t right1 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, right);
            if (left1 < right1) {
                que.push(std::make_tuple(right1 - left1, left1, right1, depth + 1, value | (1 << (bit_size - depth - 1))));
            }
        }
        return result;
    };
    
    uint64_t rangeSum(const uint64_t begin, const uint64_t end, const uint64_t x, const uint64_t y) {
        return rangeSum(begin, end, 0, 0, x, y);
    }
    
    uint64_t prevValue(const uint64_t begin_pos, const uint64_t end_pos, const uint64_t x, uint64_t y) {
        assert(end_pos <= size);
        const uint64_t num = end_pos - begin_pos;
        if (x >= y or y == 0) {
            return NOTFOUND;
        }
        if (y > maximum_element) {
            y = maximum_element;
        }
        if (begin_pos >= end_pos) {
            return NOTFOUND;
        }
        if (x >= maximum_element || end_pos == 0) {
            return NOTFOUND;
        }
        y--; 
        std::stack<std::tuple<uint64_t, uint64_t, uint64_t, uint64_t, bool>> s;   
        s.emplace(std::make_tuple(begin_pos, end_pos, 0, 0, true));
        while (not s.empty()) {
            uint64_t b, e, depth, c;
            bool tight;
            std::tie(b, e, depth, c, tight) = s.top(); s.pop();
            if (depth == bit_size) {
                if (c >= x) {
                    return c;
                }
                continue;
            }
            const uint64_t bit = (y >> (bit_size - depth - 1)) & 1;
            const uint64_t id20 = this->bit_arrays.at(depth).rank(0, b);
            const uint64_t id22 = this->bit_arrays.at(depth).rank(0, e);
            const uint64_t id3 = b - id20;
            const uint64_t id19 = e - id22;
            
            const uint64_t b0 = id20;
            const uint64_t e0 = id22;
            if (b0 != e0) { 
                const uint64_t c0 = ((c << 1) | 0);
                s.emplace(std::make_tuple(b0, e0, depth + 1, c0, tight and bit == 0));
            }
            
            const uint64_t b1 = this->begin_one.at(depth) + id3;
            const uint64_t e1 = this->begin_one.at(depth) + id19;
            if (b1 != e1) {
                if (not tight or bit == 1) {
                    const auto c1 = ((c << 1) | 1);
                    s.emplace(std::make_tuple(b1, e1, depth + 1, c1, tight));
                }
            }
        }
        return NOTFOUND;
    }
    
    uint64_t nextValue(const uint64_t begin_pos, const uint64_t end_pos, const uint64_t x, const uint64_t y) {
        assert(end_pos <= size);
        const uint64_t num = end_pos - begin_pos;
        if (x >= y or y == 0) {
            return NOTFOUND;
        }
        if (begin_pos >= end_pos) {
            return NOTFOUND;
        }
        if (x >= maximum_element || end_pos == 0) {
            return NOTFOUND;
        }
        std::stack<std::tuple<uint64_t, uint64_t, uint64_t, uint64_t, bool>> s;   
        s.emplace(std::make_tuple(begin_pos, end_pos, 0, 0, true));
        while (not s.empty()) {
            uint64_t b, e, depth, c;
            bool tight;
            std::tie(b, e, depth, c, tight) = s.top(); s.pop();
            if (depth == bit_size) {
                if (c < y) {
                    return c;
                }
                continue;
            }
            const uint64_t bit = (x >> (bit_size - depth - 1)) & 1;
            const uint64_t id20 = this->bit_arrays.at(depth).rank(0, b);
            const uint64_t id22 = this->bit_arrays.at(depth).rank(0, e);
            const uint64_t id3 = b - id20;
            const uint64_t id19 = e - id22;
            
            const uint64_t b1 = this->begin_one.at(depth) + id3;
            const uint64_t e1 = this->begin_one.at(depth) + id19;
            if (b1 != e1) {
                const auto c1 = ((c << 1) | 1);
                s.emplace(std::make_tuple(b1, e1, depth + 1, c1, tight and bit == 1));
            }
            
            const uint64_t b0 = id20;
            const uint64_t e0 = id22;
            if (b0 != e0) {
                if (not tight or bit == 0) {
                    const uint64_t c0 = ((c << 1) | 0);
                    s.emplace(std::make_tuple(b0, e0, depth + 1, c0, tight));
                }
            }
        }
        return NOTFOUND;
    }
    
    std::vector<std::tuple<uint64_t, uint64_t, uint64_t>> intersect(uint64_t _s1, uint64_t _e1, uint64_t _s2, uint64_t _e2) {
        assert(_s1 < _e1);
        assert(_s2 < _e2);
        std::vector<std::tuple<uint64_t, uint64_t, uint64_t>> intersection;
        std::queue<std::tuple<uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t>> que; 
        que.push(std::make_tuple(_s1, _e1, _s2, _e2, 0, 0));
        while (not que.empty()) {
            auto e = que.front(); que.pop();
            uint64_t s1, e1, s2, e2, depth, value;
            std::tie(s1, e1, s2, e2, depth, value) = e;
            if (depth >= this->bit_size) {
                intersection.emplace_back(std::make_tuple(value, e1 - s1, e2 - s2));
                continue;
            }
            
            uint64_t id15 = this->bit_arrays.at(depth).rank(0, s1);
            uint64_t id12 = this->bit_arrays.at(depth).rank(0, e1);
            uint64_t id5 = this->bit_arrays.at(depth).rank(0, s2);
            uint64_t id14 = this->bit_arrays.at(depth).rank(0, e2);
            if (id15 != id12 and id5 != id14) {
                que.push(std::make_tuple(id15, id12, id5, id14, depth + 1, value));
            }
            
            uint64_t id4 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, s1);
            uint64_t id7 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, e1);
            uint64_t id6 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, s2);
            uint64_t id16 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, e2);
            if (id4 != id7 and id6 != id16) {
                que.push(std::make_tuple(id4, id7, id6, id16, depth + 1, value | (1 << bit_size - depth - 1)));
            }
        }
        return intersection;
    };
private:
    uint64_t get_num_of_bit(uint64_t x) {
        if (x == 0) return 0;
        x--;
        uint64_t bit_num = 0;
        while (x >> bit_num) {
            ++bit_num;
        }
        return bit_num;
    }
    uint64_t rangeSum(const uint64_t begin, const uint64_t end, const uint64_t depth, const uint64_t c, const uint64_t x, const uint64_t y) {
        if (begin == end) {
            return 0;
        }
        if (depth == bit_size) {
            if (x <= c and c < y) {
                return c * (end - begin);   
            }
            return 0;
        }
        const uint64_t next_c = ((uint64_t)1 << (bit_size - depth - 1)) | c;                   
        const uint64_t id17 = (((uint64_t)1 << (bit_size - depth - 1)) - 1) | next_c;     
        if(id17 < x or y <= c) {
            return 0;
        }
        
        if (x <= c and id17 < y) {
            return this->cumulative_sum.at(depth).at(end) - this->cumulative_sum.at(depth).at(begin);
        }
        const uint64_t id20 = this->bit_arrays.at(depth).rank(0, begin);
        const uint64_t id22 = this->bit_arrays.at(depth).rank(0, end);
        const uint64_t id3 = begin - id20;
        const uint64_t id19 = end - id22;
        return rangeSum(id20, id22, depth + 1, c, x, y) +
               rangeSum(this->begin_one.at(depth) + id3, this->begin_one[depth] + id19, depth + 1, next_c, x, y);
    }
};
int main() {
    int n,q;cin >> n >> q;
    vector<int> a(n);
    vector<uint64_t> b(n);
    id10<ll> bit(n+1);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = i + 1 - a[i];
        if (a[i] < 0) b[i] = n+1;
        else {
            cnt++;
            if (a[i] == 0) {
                b[i] = i + 1;
            }
            else {
                b[i] = bit.lower_bound(cnt-a[i]);
            }
            bit.add(b[i],1);
        }
    }
    id2 wm(b);
    while(q--) {
        int x,y;cin >> x >> y;
        cout << wm.rangeFreq(x,n-y,x+1,n+1) << endl;
    }
    return 0;
}