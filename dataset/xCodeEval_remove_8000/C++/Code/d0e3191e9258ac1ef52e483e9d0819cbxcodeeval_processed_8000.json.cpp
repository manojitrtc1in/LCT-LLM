















































using namespace std;
static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
static const double PI2 = 8.0 * atan(1.0);
typedef long long ll;
typedef unsigned long long ull;






template<class T> T MIN(const T& a, const T& b) { return a < b ? a : b; }
template<class T> T MAX(const T& a, const T& b) { return a > b ? a : b; }
template<class T> void MIN_UPDATE(T& a, const T& b) { if (a > b) a = b; }
template<class T> void MAX_UPDATE(T& a, const T& b) { if (a < b) a = b; }


typedef unsigned int uint32_t;

typedef unsigned long long ull;



namespace wat_array {

	enum {
		NOTFOUND = 0
	};

	class BitArray {

	private:
		enum {
			BLOCK_BITNUM = 32,
			TABLE_INTERVAL = 4,
		};

	public:
		BitArray();
		~BitArray();
		BitArray(uint32_t size);
		uint32_t length() const;
		uint32_t one_num() const;

		void Init(uint32_t size);
		void Clear();
		void SetBit(uint32_t bit, uint32_t pos);

		void Build();
		uint32_t Rank(uint32_t bit, uint32_t pos) const;
		uint32_t Select(uint32_t bit, uint32_t rank) const;
		uint32_t Lookup(uint32_t pos) const;

		static uint32_t PopCount(uint32_t x);
		static uint32_t PopCountMask(uint32_t x, uint32_t offset);
		static uint32_t SelectInBlock(uint32_t x, uint32_t rank);
		static uint32_t GetBitNum(uint32_t one_num, uint32_t num, uint32_t bit);
		void PrintForDebug(std::ostream& os) const;

		void Save(std::ostream& os) const;
		void Load(std::istream& is);

	private:
		uint32_t RankOne(uint32_t pos) const;
		uint32_t SelectOutBlock(uint32_t bit, uint32_t& rank) const;

	private:
		std::vector<uint32_t> bit_blocks_;
		std::vector<uint32_t> rank_tables_;
		uint32_t length_;
		uint32_t id12;
	};

	

	struct ListResult{
		ListResult(uint32_t c, uint32_t freq) : c(c), freq(freq){}
		uint32_t c;
		uint32_t freq;
		bool operator < (const ListResult& lr) const {
			if (c != lr.c) return c < lr.c;
			return freq < lr.freq;
		}
	};


	class WatArray{
	public:
		
		WatArray();

		
		~WatArray();

		
		void Init(const std::vector<uint32_t>& array);

		void Init(const BitArray& ba, uint32_t width, uint32_t length);

		
		void Clear();

		
		uint32_t Lookup(uint32_t pos) const;

		
		uint32_t Rank(uint32_t c, uint32_t pos) const;

		
		uint32_t Select(uint32_t c, uint32_t rank) const;

		
		uint32_t RankLessThan(uint32_t c, uint32_t pos) const;

		
		uint32_t RankMoreThan(uint32_t c, uint32_t pos) const;

		
		void RankAll(uint32_t c, uint32_t pos, uint32_t& rank,
			uint32_t& id14, uint32_t& id0) const;

		
		uint32_t FreqRange(uint32_t min_c, uint32_t max_c, uint32_t beg_pos, uint32_t end_pos) const;

		
		void MaxRange(uint32_t beg_pos, uint32_t end_pos, uint32_t& pos, uint32_t& val) const;

		
		void MinRange(uint32_t beg_pos, uint32_t end_pos, uint32_t& pos, uint32_t& val) const;

		
		void QuantileRange(uint32_t beg_pos, uint32_t end_pos, uint32_t k, uint32_t& pos, uint32_t& val) const;

		
		void ListModeRange(uint32_t min_c, uint32_t max_c, uint32_t beg_pos, uint32_t end_pos, uint32_t num, std::vector<ListResult>& res) const;

		
		void ListMinRange(uint32_t min_c, uint32_t max_c, uint32_t beg_pos, uint32_t end_pos, uint32_t num, std::vector<ListResult>& res) const;

		
		void ListMaxRange(uint32_t min_c, uint32_t max_c, uint32_t beg_pos, uint32_t end_pos, uint32_t num, std::vector<ListResult>& res) const;

		
		uint32_t Freq(uint32_t c) const;

		
		uint32_t FreqSum(uint32_t min_c, uint32_t max_c) const;

		
		uint32_t alphabet_num() const;

		
		uint32_t length() const;

		
		void Save(std::ostream& os) const;

		
		void Load(std::istream& is);

	private:
		uint32_t GetAlphabetNum(const std::vector<uint32_t>& array) const;
		uint32_t Log2(uint32_t x) const;
		uint32_t PrefixCode(uint32_t x, uint32_t len, uint32_t total_len) const;
		static uint32_t GetMSB(uint32_t x, uint32_t pos, uint32_t len);
		static uint32_t GetLSB(uint32_t x, uint32_t pos);
		void SetArray(const std::vector<uint32_t>& array);
		void SetOccs(const std::vector<uint32_t>& array);
		void GetBegPoses(const std::vector<uint32_t>& array, uint32_t id2,
			std::vector<std::vector<uint32_t> >& id1) const;

		struct id10{
			id10(uint32_t beg_node, uint32_t end_node, uint32_t beg_pos, uint32_t end_pos,
			uint32_t depth, uint32_t prefix_char) :
			beg_node(beg_node), end_node(end_node), beg_pos(beg_pos), end_pos(end_pos),
			depth(depth), prefix_char(prefix_char) {}
			uint32_t beg_node;
			uint32_t end_node;
			uint32_t beg_pos;
			uint32_t end_pos;
			uint32_t depth;
			uint32_t prefix_char;
			void print() {
				std::cout << beg_node << " " << end_node << " "
					<< beg_pos << " " << end_pos << " "
					<< depth << " ";
				for (uint32_t i = 0; i < depth; ++i){
					std::cout << GetMSB(prefix_char, i, depth);
				}
				std::cout << std::endl;
			}
		};

		class id3;
		class id11;
		class id9;

		template <class Comparator>
		void ListRange(uint32_t min_c, uint32_t max_c,
			uint32_t beg_pos, uint32_t end_pos,
			uint32_t num, std::vector<ListResult>& res) const {
			res.clear();
			if (end_pos > length_ || beg_pos >= end_pos) return;

			std::priority_queue<id10, std::vector<id10>, Comparator> qons;
			qons.push(id10(0, length_, beg_pos, end_pos, 0, 0));

			while (res.size() < num && !qons.empty()){
				id10 qon = qons.top();
				qons.pop();
				if (qon.depth >= id4){
					res.push_back(ListResult(qon.prefix_char, qon.end_pos - qon.beg_pos));
				}
				else {
					std::vector<id10> next;
					ExpandNode(min_c, max_c, qon, next);
					for (size_t i = 0; i < next.size(); ++i){
						qons.push(next[i]);
					}
				}
			}
		}

		bool CheckPrefix(uint32_t prefix, uint32_t depth, uint32_t min_c, uint32_t max_c) const;
		void ExpandNode(uint32_t min_c, uint32_t max_c,
			const id10& qon, std::vector<id10>& next) const;

		std::vector<BitArray> bit_arrays_;
		BitArray occs_;

		uint32_t id8;
		uint32_t id4;
		uint32_t length_;
	};

	BitArray::BitArray() : length_(0), id12(0){
	}

	BitArray::BitArray(uint32_t length){
		Init(length);
	}

	BitArray::~BitArray(){
	}

	uint32_t BitArray::length() const {
		return length_;
	}

	uint32_t BitArray::one_num() const{
		return id12;
	}

	void BitArray::Init(uint32_t length){
		length_ = length;
		id12 = 0;
		uint32_t block_num = (length + BLOCK_BITNUM - 1) / BLOCK_BITNUM;
		bit_blocks_.resize(block_num);
	}

	void BitArray::Clear(){
		std::vector<uint32_t>().swap(bit_blocks_);
		std::vector<uint32_t>().swap(rank_tables_);
		length_ = 0;
		id12 = 0;
	}

	void BitArray::Build() {
		id12 = 0;
		uint32_t table_num = ((bit_blocks_.size() + TABLE_INTERVAL - 1) / TABLE_INTERVAL) + 1;
		rank_tables_.resize(table_num);
		for (size_t i = 0; i < bit_blocks_.size(); ++i){
			if ((i % TABLE_INTERVAL) == 0){
				rank_tables_[i / TABLE_INTERVAL] = id12;
			}
			id12 += PopCount(bit_blocks_[i]);
		}
		rank_tables_.back() = id12;
	}

	void BitArray::SetBit(uint32_t bit, uint32_t pos) {
		if (!bit) return;
		bit_blocks_[pos / BLOCK_BITNUM] |= (1LLU << (pos % BLOCK_BITNUM));
	}

	uint32_t BitArray::Rank(uint32_t bit, uint32_t pos) const {
		if (pos > length_) return NOTFOUND;
		if (bit) return RankOne(pos);
		else return pos - RankOne(pos);
	}

	uint32_t BitArray::Select(uint32_t bit, uint32_t rank) const {
		if (bit){
			if (rank > id12) return NOTFOUND;
		}
		else {
			if (rank > length_ - id12) return NOTFOUND;
		}

		uint32_t block_pos = SelectOutBlock(bit, rank);
		uint32_t block = (bit) ? bit_blocks_[block_pos] : ~bit_blocks_[block_pos];
		return block_pos * BLOCK_BITNUM + SelectInBlock(block, rank);
	}

	uint32_t BitArray::SelectOutBlock(uint32_t bit, uint32_t& rank) const {
		

		uint32_t left = 0;
		uint32_t right = rank_tables_.size();
		while (left < right){
			uint32_t mid = (left + right) / 2;
			uint32_t length = BLOCK_BITNUM * TABLE_INTERVAL * mid;
			if (GetBitNum(rank_tables_[mid], length, bit) < rank) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}

		uint32_t table_ind = (left != 0) ? left - 1 : 0;
		uint32_t block_pos = table_ind * TABLE_INTERVAL;
		rank -= GetBitNum(rank_tables_[table_ind],
			block_pos * BLOCK_BITNUM,
			bit);

		

		for (; block_pos < bit_blocks_.size(); ++block_pos){
			uint32_t rank_next = GetBitNum(PopCount(bit_blocks_[block_pos]), BLOCK_BITNUM, bit);
			if (rank <= rank_next){
				break;
			}
			rank -= rank_next;
		}
		return block_pos;
	}

	uint32_t BitArray::SelectInBlock(uint32_t x, uint32_t rank) {
		uint32_t x1 = x - ((x & 0xAAAAAAAAAAAAAAAALLU) >> 1);
		uint32_t x2 = (x1 & 0x3333333333333333LLU) + ((x1 >> 2) & 0x3333333333333333LLU);
		uint32_t x3 = (x2 + (x2 >> 4)) & 0x0F0F0F0F0F0F0F0FLLU;

		uint32_t pos = 0;
		for (;; pos += 8){
			uint32_t rank_next = (x3 >> pos) & 0xFFLLU;
			if (rank <= rank_next) break;
			rank -= rank_next;
		}

		uint32_t v2 = (x2 >> pos) & 0xFLLU;
		if (rank > v2) {
			rank -= v2;
			pos += 4;
		}

		uint32_t v1 = (x1 >> pos) & 0x3LLU;
		if (rank > v1){
			rank -= v1;
			pos += 2;
		}

		uint32_t v0 = (x >> pos) & 0x1LLU;
		if (v0 < rank){
			rank -= v0;
			pos += 1;
		}

		return pos;
	}

	uint32_t BitArray::Lookup(uint32_t pos) const {
		return (bit_blocks_[pos / BLOCK_BITNUM] >> (pos % BLOCK_BITNUM)) & 1LLU;
	}


	uint32_t BitArray::RankOne(uint32_t pos) const {
		uint32_t block_ind = pos / BLOCK_BITNUM;
		uint32_t table_ind = block_ind / TABLE_INTERVAL;
		assert(table_ind < rank_tables_.size());

		uint32_t rank = rank_tables_[table_ind];
		for (uint32_t i = table_ind * TABLE_INTERVAL; i < block_ind; ++i){
			rank += PopCount(bit_blocks_[i]);
		}
		rank += PopCountMask(bit_blocks_[block_ind], pos % BLOCK_BITNUM);
		return rank;
	}



	uint32_t BitArray::PopCount(uint32_t x) {
		x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
		x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
		x = (x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f);
		x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff);
		x = (x & 0x0000ffff) + ((x >> 16) & 0x0000ffff);
		return x;
	}

	uint32_t BitArray::PopCountMask(uint32_t x, uint32_t offset) {
		if (offset == 0) return 0;
		return PopCount(x & ((1LU << offset) - 1));
	}

	uint32_t BitArray::GetBitNum(uint32_t one_num, uint32_t num, uint32_t bit) {
		if (bit) return one_num;
		else return num - one_num;
	}

	void BitArray::PrintForDebug(std::ostream& os) const {
		for (uint32_t i = 0; i < length_; ++i){
			if (Lookup(i)) os << "1";
			else           os << "0";
			if (((i + 1) % 8) == 0) {
				os << " ";
			}
		}
	}

	void BitArray::Save(std::ostream& os) const{
		os.write((const char*)(&length_), sizeof(length_));
		os.write((const char*)(&bit_blocks_[0]), sizeof(bit_blocks_[0]) * bit_blocks_.size());
	}

	void BitArray::Load(std::istream& is){
		Clear();
		is.read((char*)(&length_), sizeof(length_));
		Init(length_);
		is.read((char*)(&bit_blocks_[0]), sizeof(bit_blocks_[0]) * bit_blocks_.size());
		Build();
	}

	WatArray::WatArray() : id8(0), id4(0), length_(0){
	}

	WatArray::~WatArray() {
	}

	void WatArray::Clear(){
		vector<BitArray>().swap(bit_arrays_);
		occs_.Clear();
		id8 = 0;
		id4 = 0;
		length_ = 0;
	}

	void WatArray::Init(const vector<uint32_t>& array){
		Clear();
		id8 = GetAlphabetNum(array);
		id4 = Log2(id8);

		length_ = static_cast<uint32_t>(array.size());
		SetArray(array);
		SetOccs(array);
	}

	uint32_t WatArray::Lookup(uint32_t pos) const{
		if (pos >= length_) return NOTFOUND;
		uint32_t st = 0;
		uint32_t en = length_;
		uint32_t c = 0;
		for (size_t i = 0; i < bit_arrays_.size(); ++i){
			const BitArray& ba = bit_arrays_[i];
			uint32_t boundary = st + ba.Rank(0, en) - ba.Rank(0, st);
			uint32_t bit = ba.Lookup(st + pos);
			c <<= 1;
			if (bit){
				pos = ba.Rank(1, st + pos) - ba.Rank(1, st);
				st = boundary;
				c |= 1LLU;
			}
			else {
				pos = ba.Rank(0, st + pos) - ba.Rank(0, st);
				en = boundary;
			}

		}
		return c;
	}

	uint32_t WatArray::Rank(uint32_t c, uint32_t pos) const{
		uint32_t id14 = 0;
		uint32_t id0 = 0;
		uint32_t rank = 0;
		RankAll(c, pos, rank, id14, id0);
		return rank;
	}

	uint32_t WatArray::RankLessThan(uint32_t c, uint32_t pos) const{
		uint32_t id14 = 0;
		uint32_t id0 = 0;
		uint32_t rank = 0;
		RankAll(c, pos, rank, id14, id0);
		return id14;
	}

	uint32_t WatArray::RankMoreThan(uint32_t c, uint32_t pos) const{
		uint32_t id14 = 0;
		uint32_t id0 = 0;
		uint32_t rank = 0;
		RankAll(c, pos, rank, id14, id0);
		return id0;
	}

	void WatArray::RankAll(uint32_t c, uint32_t pos,
		uint32_t& rank, uint32_t& id14, uint32_t& id0) const{
		if (c >= id8) {
			id14 = NOTFOUND;
			id0 = NOTFOUND;
			rank = NOTFOUND;
			return;
		}
		if (pos >= length_) {
			pos = length_;
		}
		uint32_t beg_node = 0;
		uint32_t end_node = length_;
		id14 = 0;
		id0 = 0;

		for (size_t i = 0; i < bit_arrays_.size() && beg_node < end_node; ++i){
			const BitArray& ba = bit_arrays_[i];
			uint32_t id6 = ba.Rank(0, beg_node);
			uint32_t id5 = beg_node - id6;
			uint32_t id13 = ba.Rank(0, end_node);
			uint32_t boundary = beg_node + id13 - id6;
			uint32_t bit = GetMSB(c, i, bit_arrays_.size());
			if (!bit){
				id0 += ba.Rank(1, pos) - id5;
				pos = beg_node + ba.Rank(0, pos) - id6;
				end_node = boundary;
			}
			else {
				id14 += ba.Rank(0, pos) - id6;
				pos = boundary + ba.Rank(1, pos) - (beg_node - id6);
				beg_node = boundary;
			}
		}
		rank = pos - beg_node;
	}


	uint32_t WatArray::Select(uint32_t c, uint32_t rank) const{
		if (c >= id8) {
			return NOTFOUND;
		}
		if (rank > Freq(c)){
			return NOTFOUND;
		}

		for (size_t i = 0; i < bit_arrays_.size(); ++i){
			uint32_t lower_c = c & ~((1LLU << (i + 1)) - 1);
			uint32_t beg_node = occs_.Select(1, lower_c + 1) - lower_c;
			const BitArray& ba = bit_arrays_[id4 - i - 1];
			uint32_t bit = GetLSB(c, i);
			uint32_t before_rank = ba.Rank(bit, beg_node);
			rank = ba.Select(bit, before_rank + rank) - beg_node + 1;
		}
		return rank - 1;
	}

	uint32_t WatArray::FreqRange(uint32_t min_c, uint32_t max_c, uint32_t begin_pos, uint32_t end_pos) const{
		if (min_c >= id8) return 0;
		if (max_c <= min_c) return 0;
		if (end_pos > length_ || begin_pos > end_pos) return 0;
		return
			+RankLessThan(max_c, end_pos)
			- RankLessThan(min_c, end_pos)
			- RankLessThan(max_c, begin_pos)
			+ RankLessThan(min_c, begin_pos);
	}

	void WatArray::MaxRange(uint32_t begin_pos, uint32_t end_pos, uint32_t& pos, uint32_t& val) const {
		QuantileRange(begin_pos, end_pos, end_pos - begin_pos - 1, pos, val);
	}

	void WatArray::MinRange(uint32_t begin_pos, uint32_t end_pos, uint32_t& pos, uint32_t& val) const {
		QuantileRange(begin_pos, end_pos, 0, pos, val);
	}

	void WatArray::QuantileRange(uint32_t begin_pos, uint32_t end_pos, uint32_t k, uint32_t& pos, uint32_t& val) const {
		if (end_pos > length_ || begin_pos >= end_pos) {
			pos = NOTFOUND;
			val = NOTFOUND;
			return;
		}

		val = 0;
		uint32_t beg_node = 0;
		uint32_t end_node = length_;
		for (size_t i = 0; i < bit_arrays_.size(); ++i){
			const BitArray& ba = bit_arrays_[i];
			uint32_t id6 = ba.Rank(0, beg_node);
			uint32_t id13 = ba.Rank(0, end_node);
			uint32_t id5 = beg_node - id6;
			uint32_t beg_zero = ba.Rank(0, begin_pos);
			uint32_t end_zero = ba.Rank(0, end_pos);
			uint32_t beg_one = begin_pos - beg_zero;
			uint32_t end_one = end_pos - end_zero;
			uint32_t boundary = beg_node + id13 - id6;

			if (end_zero - beg_zero > k){
				end_node = boundary;
				begin_pos = beg_node + beg_zero - id6;
				end_pos = beg_node + end_zero - id6;
				val = val << 1;
			}
			else {
				beg_node = boundary;
				begin_pos = boundary + beg_one - id5;
				end_pos = boundary + end_one - id5;
				val = (val << 1) + 1;
				k -= end_zero - beg_zero;
			}
		}

		uint32_t rank = begin_pos - beg_node;
		pos = Select(val, rank + 1);
	}

	class WatArray::id3{
	public:
		id3() {}
		bool operator() (const id10& lhs,
			const id10& rhs) const {
			if (lhs.end_pos - lhs.beg_pos != rhs.end_pos - rhs.beg_pos) {
				return lhs.end_pos - lhs.beg_pos < rhs.end_pos - rhs.beg_pos;
			}
			else if (lhs.depth != rhs.depth) {
				return lhs.depth < rhs.depth;
			}
			else {
				return lhs.beg_pos > rhs.beg_pos;
			}
		}
	};

	class WatArray::id11{
	public:
		id11() {}
		bool operator() (const id10& lhs,
			const id10& rhs) const {
			if (lhs.depth != rhs.depth)
				return lhs.depth < rhs.depth;
			else return lhs.beg_node > rhs.beg_node;
		}
	};

	class WatArray::id9{
	public:
		id9() {}
		bool operator() (const id10& lhs,
			const id10& rhs) const {
			if (lhs.depth != rhs.depth)
				return lhs.depth < rhs.depth;
			else return lhs.beg_node < rhs.beg_node;
		}
	};




	void WatArray::ListModeRange(uint32_t min_c, uint32_t max_c, uint32_t beg_pos, uint32_t end_pos,
		uint32_t num, vector<ListResult>& res) const {
		ListRange<id3>(min_c, max_c, beg_pos, end_pos, num, res);
	}

	void WatArray::ListMinRange(uint32_t min_c, uint32_t max_c, uint32_t beg_pos, uint32_t end_pos,
		uint32_t num, vector<ListResult>& res) const {
		ListRange<id11>(min_c, max_c, beg_pos, end_pos, num, res);
	}

	void WatArray::ListMaxRange(uint32_t min_c, uint32_t max_c, uint32_t beg_pos, uint32_t end_pos,
		uint32_t num, vector<ListResult>& res) const {
		ListRange<id9>(min_c, max_c, beg_pos, end_pos, num, res);
	}

	bool WatArray::CheckPrefix(uint32_t prefix, uint32_t depth, uint32_t min_c, uint32_t max_c) const {
		if (PrefixCode(min_c, depth, id4) <= prefix &&
			PrefixCode(max_c - 1, depth, id4) >= prefix) return true;
		else return false;
	}

	void WatArray::ExpandNode(uint32_t min_c, uint32_t max_c,
		const id10& qon, vector<id10>& next) const{
		const BitArray& ba = bit_arrays_[qon.depth];

		uint32_t id6 = ba.Rank(0, qon.beg_node);
		uint32_t id13 = ba.Rank(0, qon.end_node);
		uint32_t id5 = qon.beg_node - id6;
		uint32_t beg_zero = ba.Rank(0, qon.beg_pos);
		uint32_t end_zero = ba.Rank(0, qon.end_pos);
		uint32_t beg_one = qon.beg_pos - beg_zero;
		uint32_t end_one = qon.end_pos - end_zero;
		uint32_t boundary = qon.beg_node + id13 - id6;
		if (end_zero - beg_zero > 0){ 

			uint32_t next_prefix = qon.prefix_char << 1;
			if (CheckPrefix(next_prefix, qon.depth + 1, min_c, max_c)) {
				next.push_back(id10(qon.beg_node,
					boundary,
					qon.beg_node + beg_zero - id6,
					qon.beg_node + end_zero - id6,
					qon.depth + 1,
					next_prefix));
			}
		}
		if (end_one - beg_one > 0){ 

			uint32_t next_prefix = (qon.prefix_char << 1) + 1;
			if (CheckPrefix(next_prefix, qon.depth + 1, min_c, max_c)) {
				next.push_back(id10(boundary,
					qon.end_node,
					boundary + beg_one - id5,
					boundary + end_one - id5,
					qon.depth + 1,
					next_prefix));
			}
		}
	}

	uint32_t WatArray::Freq(uint32_t c) const {
		if (c >= id8) return NOTFOUND;
		return occs_.Select(1, c + 2) - occs_.Select(1, c + 1) - 1;
	}

	uint32_t WatArray::FreqSum(uint32_t min_c, uint32_t max_c) const {
		if (max_c > id8 || min_c > max_c) return NOTFOUND;
		return occs_.Select(1, max_c + 1) - occs_.Select(1, min_c + 1) - (max_c - min_c);
	}

	uint32_t WatArray::alphabet_num() const{
		return id8;
	}

	uint32_t WatArray::length() const{
		return length_;
	}

	uint32_t WatArray::GetAlphabetNum(const std::vector<uint32_t>& array) const {
		uint32_t alphabet_num = 0;
		for (size_t i = 0; i < array.size(); ++i){
			if (array[i] >= alphabet_num){
				alphabet_num = array[i] + 1;
			}
		}
		return alphabet_num;
	}

	uint32_t WatArray::Log2(uint32_t x) const{
		if (x == 0) return 0;
		x--;
		uint32_t bit_num = 0;
		while (x >> bit_num){
			++bit_num;
		}
		return bit_num;
	}

	uint32_t WatArray::PrefixCode(uint32_t x, uint32_t len, uint32_t bit_num) const{
		return x >> (bit_num - len);
	}

	uint32_t WatArray::GetMSB(uint32_t x, uint32_t pos, uint32_t len) {
		return (x >> (len - (pos + 1))) & 1LLU;
	}

	uint32_t WatArray::GetLSB(uint32_t x, uint32_t pos) {
		return (x >> pos) & 1LLU;
	}

	void WatArray::SetArray(const vector<uint32_t>& array) {
		if (id8 == 0) return;
		bit_arrays_.resize(id4, length_);

		vector<vector<uint32_t> > id1;
		GetBegPoses(array, id4, id1);

		for (size_t i = 0; i < array.size(); ++i){
			uint32_t c = array[i];
			for (uint32_t j = 0; j < id4; ++j){
				uint32_t prefix_code = PrefixCode(c, j, id4);
				uint32_t bit_pos = id1[j][prefix_code]++;
				bit_arrays_[j].SetBit(GetMSB(c, j, id4), bit_pos);
			}
		}

		for (size_t i = 0; i < bit_arrays_.size(); ++i){
			bit_arrays_[i].Build();
		}
	}

	void WatArray::SetOccs(const vector<uint32_t>& array){
		vector<uint32_t> counts(id8);
		for (size_t i = 0; i < array.size(); ++i){
			counts[array[i]]++;
		}

		occs_.Init(array.size() + id8 + 1);
		uint32_t sum = 0;
		for (size_t i = 0; i < counts.size(); ++i){
			occs_.SetBit(1, sum);
			sum += counts[i] + 1;
		}
		occs_.SetBit(1, sum);
		occs_.Build();
	}

	void WatArray::GetBegPoses(const vector<uint32_t>& array,
		uint32_t id2,
		vector< vector<uint32_t> >& id1) const{
		id1.resize(id2);
		for (uint32_t i = 0; i < id1.size(); ++i){
			id1[i].resize(1 << i);
		}

		for (size_t i = 0; i < array.size(); ++i){
			uint32_t c = array[i];
			for (uint32_t j = 0; j < id2; ++j){
				id1[j][PrefixCode(c, j, id2)]++;
			}
		}

		for (size_t i = 0; i < id1.size(); ++i){
			uint32_t sum = 0;
			vector<uint32_t>& id7 = id1[i];
			for (size_t j = 0; j < id7.size(); ++j){
				uint32_t num = id7[j];
				id7[j] = sum;
				sum += num;
			}
		}
	}

	void WatArray::Save(ostream& os) const{
		os.write((const char*)(&id8), sizeof(id8));
		os.write((const char*)(&length_), sizeof(length_));
		for (size_t i = 0; i < bit_arrays_.size(); ++i){
			bit_arrays_[i].Save(os);
		}
		occs_.Save(os);
	}

	void WatArray::Load(istream& is){
		Clear();
		is.read((char*)(&id8), sizeof(id8));
		id4 = Log2(id8);
		is.read((char*)(&length_), sizeof(length_));

		bit_arrays_.resize(id4);
		for (size_t i = 0; i < bit_arrays_.size(); ++i){
			bit_arrays_[i].Load(is);
			bit_arrays_[i].Build();
		}
		occs_.Load(is);
		occs_.Build();
	}

}

int main() {
	std::ios::sync_with_stdio(false);

	string s;
	cin >> s;

	vector<uint32_t> A(s.size() + 1, (1 << 20) - 1);
	vector<int> stk;
	REP(i, s.size()) {
		if (s[i] == '(') {
			stk.push_back(i + 1);
		}
		else {
			if (stk.empty()) {
				continue;
			}

			A[stk.back()] = i + 1;
			stk.pop_back();
		}
	}

	wat_array::WatArray wa;
	wa.Init(A);

	int m;
	cin >> m;
	REP(i, m) {
		int l, r;
		cin >> l >> r;

		cout << wa.FreqRange(0, r + 1, l, r + 1) * 2 << endl;;
	}
}
