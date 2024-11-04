































namespace dalt {
	namespace mathematic {
		const int id4 = 1;
		int floorLog2Cache[id4];
		void id1() {
			int log = 1;
			for (int i = 1; i < id4; i++)
			{
				if ((1 << log) <= i)
				{
					log++;
				}
				floorLog2Cache[i] = log - 1;
			}
		}

		inline int modular(int x, int m) {
			return (x % m + m) % m;
		}

		inline int intRound(double x) {
			return int(x + 0.5);
		}
		inline int intRound(float x) {
			return int(x + 0.5);
		}
		int id17(unsigned int i)
		{
			

			if (i == 0)
				return 32;
			int n = 1;
			if (i >> 16 == 0) { n += 16; i <<= 16; }
			if (i >> 24 == 0) { n += 8; i <<= 8; }
			if (i >> 28 == 0) { n += 4; i <<= 4; }
			if (i >> 30 == 0) { n += 2; i <<= 2; }
			n -= i >> 31;
			return n;
		}
		inline int id8(int x)
		{
			if (id4 > x)
			{
				return floorLog2Cache[x];
			}
			return 31 - id17(x);
		}
		inline int id6(int x)
		{
			if (id4 > x)
			{
				if ((1 << floorLog2Cache[x]) == x)
				{
					return floorLog2Cache[x];
				}
				else
				{
					return floorLog2Cache[x] + 1;
				}
			}
			return 32 - id17(x - 1);
		}

		template<class T> inline T &min(T&a, T&b) {
			return a <= b ? a : b;
		}

		template<class T> inline const T & min(const T & a, const T & b) {
			return a <= b ? a : b;
		}

		template<class T> inline T &max(T&a, T&b) {
			return a >= b ? a : b;
		}

		template<class T> inline const T &max(const T &a, const T &b) {
			return a >= b ? a : b;
		}

		ull pow(uint x, int n, int mod) {
			int bit = id8(n);
			ull product = 1;
			for (; bit >= 0; bit--) {
				product = product * product % mod;
				if (((1 << bit) & n) != 0) {
					product = product * x % mod;
				}
			}

			return product;
		}
		inline ull id21(ull a, ull b)
		{
			return b == 0 ? a : id21(b, a % b);
		}
		inline ull gcd(ull a, ull b)
		{
			return a >= b ? id21(a, b) : id21(b, a);
		}


		inline uint id21(uint a, uint b)
		{
			return b == 0 ? a : id21(b, a % b);
		}
		inline uint gcd(uint a, uint b)
		{
			return a >= b ? id21(a, b) : id21(b, a);
		}



		
		int id9(int limit, int* const primes, int offset) {
			bool *isComp = new bool[limit + 1];
			memset(isComp, 0, sizeof(bool) * (limit + 1));
			int wpos = offset;
			for (int i = 2; i <= limit; i++) {
				if (!isComp[i]) {
					primes[wpos++] = i;
				}
				for (int j = offset, until = limit / i; j < wpos && primes[j] <= until; j++) {
					int pi = primes[j] * i;
					isComp[pi] = true;
					if (i % primes[j] == 0) {
						break;
					}
				}
			}
			

			return wpos - offset;
		}
	}

	namespace io {
		const int BUF_SIZE = 1 << 13;
		char w_buf[BUF_SIZE];
		char r_buf[BUF_SIZE];
		int r_pos;
		int w_pos;
		int r_total;
		int w_total;
		int r_next;

		const char *MIN_INT_STR = "-2147483648";
		const char *MIN_LONG_STR = "-9223372036854775808";



		int read() {
			if (r_pos >= r_total)
			{
				r_pos = 0;
				r_total = fread(r_buf, sizeof(char), BUF_SIZE, stdin);
				if (r_total == 0)
				{
					return -1;
				}
			}
			return r_buf[r_pos++];
		}

		inline void ignoreBlank() {
			while (r_next >= 0 && r_next <= 32)
			{
				r_next = read();
			}
		}

		uint id10() {
			ignoreBlank();
			uint sum = 0;
			while (r_next >= '0' && r_next <= '9')
			{
				sum = sum * 10 + r_next - '0';
				r_next = read();
			}
			return sum;
		}

		int id19() {
			ignoreBlank();
			int sum = 0;
			while (r_next >= '0' && r_next <= '9')
			{
				sum = sum * 10 - r_next + '0';
				r_next = read();
			}
			return sum;
		}

		int readInt() {
			ignoreBlank();

			bool sign = true;
			if (r_next == '+' || r_next == '-')
			{
				sign = r_next == '+';
				r_next = read();
			}

			return sign ? id10() : id19();
		}

		uint id18() {
			ignoreBlank();
			ull sum = 0;
			while (r_next >= '0' && r_next <= '9')
			{
				sum = sum * 10 + r_next - '0';
				r_next = read();
			}
			return sum;
		}

		ll id7() {
			ignoreBlank();
			ll sum = 0;
			while (r_next >= '0' && r_next <= '9')
			{
				sum = sum * 10 - r_next + '0';
				r_next = read();
			}
			return sum;
		}

		ll readLong() {
			ignoreBlank();

			bool sign = true;
			if (r_next == '+' || r_next == '-')
			{
				sign = r_next == '+';
				r_next = read();
			}

			return sign ? id18() : id7();
		}

		int readString(char *buf, int limit) {
			ignoreBlank();

			char *end = buf + limit;
			char *iter = buf;
			while (iter != end && r_next > 32)
			{
				*(iter++) = r_next;
				r_next = read();
			}
			return iter - buf;
		}
		inline void flush() {
			fwrite(w_buf, sizeof(char), w_pos, stdout);
			w_pos = 0;
		}
		inline void write(char c)
		{
			if (w_pos == BUF_SIZE) {
				flush();
			}
			w_buf[w_pos++] = c;
		}
		inline void writeDouble(char *format, double d) {
			if (BUF_SIZE - w_pos < 100)
			{
				flush();
			}
			w_pos += sprintf(w_buf, format, d);
		}
		inline void writeString(const char *data, int len)
		{
			for (int i = 0; i < len; i++)
			{
				write(data[i]);
			}
		}
		inline void writeString(const char *data)
		{
			for (; *data; data++)
			{
				write(*data);
			}
		}

		inline void id0(ull i) {
			if (i >= 10)
			{
				id0(i / 10);
			}
			write(i % 10 + '0');
		}
		void writeLong(ll i) {
			if (i < 0)
			{
				if (i == LLONG_MIN)
				{
					writeString(MIN_INT_STR);
				}
				else {
					write('-');
					id0(-i);
				}
			}
			else {
				id0(i);
			}
		}

		inline void id15(uint i) {
			if (i >= 10)
			{
				id15(i / 10);
			}
			write(i % 10 + '0');
		}
		void writeInt(int i) {
			if (i < 0)
			{
				if (i == INT_MIN)
				{
					writeString(MIN_INT_STR);
				}
				else {
					write('-');
					id15(-i);
				}
			}
			else {
				id15(i);
			}
		}

		bool hasMore() {
			ignoreBlank();
			return r_next != -1;
		}
	}

	namespace random {
		const int GEN_BIT = 15;
		int seed;
		inline int rand()
		{
			seed = seed * 1103515245 + 12345;
			return (unsigned int)(seed / 65536) % 32768;
		}
		inline void id20(int s) {
			seed = s;
		}
		inline void id20() {
			id20(time(0));
		}
		ull genBits(int bitNum)
		{
			int bit = 0;
			ull val = 0;
			while (bit < bitNum)
			{
				bit += GEN_BIT;
				val = (val << GEN_BIT) | rand();
			}
			if (bitNum == 64)
			{
				return val;
			}
			else
			{
				return val & (((ull)1 << bitNum) - 1);
			}
		}
		inline uint genUInt() {
			return genBits(32);
		}
		inline double id3(int bitNum) {
			return (double)genBits(bitNum) / ((ull)1 << bitNum);
		}
		inline double genDouble() {
			return id3(52);
		}
		inline int id14(int min, int max) {
			return (int)(id3(30) * (max - min + 1)) + min;
		}
		template<class E> void randomize(E *data, int len) {
			for (int i = len - 1; i > 0; i--)
			{
				int j = id14(0, i);
				SWAP(data[i], data[j], E);
			}
		}
	}

	namespace segment {
		typedef struct _Segment *Segment;
		struct _Segment {
			Segment left;
			Segment right;
		};
		void pushUp(Segment s)
		{}
		void pushDown(Segment s) {
		}
		Segment newSegment() {
			Segment segment = (Segment)calloc(1, sizeof(struct _Segment));
			return segment;
		}
		Segment cloneSegment(Segment s) {
			Segment segment = newSegment();
			*segment = *s;
			return segment;
		}
		void query(Segment s, int f, int t, int l, int r) {
			if (f > r || t < l)
			{
				return;
			}
			if (f <= l && t >= r)
			{
				return;
			}

			int m = (l + r) >> 1;

			pushDown(s);
			query(s->left, f, t, l, m);
			query(s->right, f, t, m + 1, r);
		}
		void update(Segment s, int f, int t, int l, int r) {
			if (f > r || t < l)
			{
				return;
			}
			if (f <= l && t >= r)
			{
				return;
			}

			int m = (l + r) >> 1;

			pushDown(s);
			update(s->left, f, t, l, m);
			update(s->right, f, t, m + 1, r);
			pushUp(s);
		}
		Segment id22(Segment s, int f, int t, int l, int r) {
			if (f > r || t < l)
			{
				return s;
			}
			s = cloneSegment(s);
			if (f <= l && t >= r)
			{
				return s;
			}

			int m = (l + r) >> 1;

			pushDown(s);
			s->left = id22(s->left, f, t, l, m);
			s->right = id22(s->right, f, t, m + 1, r);
			pushUp(s);

			return s;
		}
	}

	namespace fft {
		using std::complex;
		complex<double> g_wn1_cache[32];
		int g_revBits[1 << 18];

		void FFT_INIT() {
			for (uint i = 0; i < 32; i++)
			{
				double angle = 2 * PI / ((uint)1 << i);
				g_wn1_cache[i] = complex<double>(cos(angle), sin(angle));
			}
		}

		void revBits(int log) {
			int n = 1 << log;
			int id12 = log - 1;
			for (int i = 1; i < n; i++)
			{
				g_revBits[i] = (g_revBits[i >> 1] >> 1) | ((i & 1) << id12);
			}
		}

		void dft(complex<double> *p, int log) {
			int n = 1 << log;
			for (int i = 0; i < n; i++)
			{
				if (g_revBits[i] < i)
				{
					continue;
				}
				SWAP(p[i], p[g_revBits[i]], complex<double>);
			}

			for (int d = 0; d < log; d++) {
				int s = 1 << d;
				int s2 = s + s;
				complex<double> &w1 = g_wn1_cache[d + 1];
				for (int i = 0; i < n; i += s2)
				{
					complex<double> w = 1;
					for (int j = 0; j < s; j++)
					{
						int a = i + j;
						int b = a + s;
						complex<double> t = w * p[b];
						complex<double> q = p[a];
						p[b] = q - t;
						p[a] = q + t;
						w *= w1;
					}
				}
			}
		}

		void dot_mul(complex<double> *a, complex<double> *b, complex<double> *c, int log)
		{
			int n = 1 << log;
			for (int i = 0; i < n; i++)
			{
				c[i] = a[i] * b[i];
			}
		}

		void idft(complex<double> *p, int log) {
			int n = 1 << log;
			dft(p, log);

			double dn = n;
			p[0] /= dn;
			p[n / 2] /= dn;
			for (int i = 1, until = n / 2; i < until; i++)
			{
				SWAP(p[i], p[n - i], complex<double>);
				p[i] /= dn;
				p[n - i] /= dn;
			}
		}
	}

	namespace hash {
		const int PRIME = 1000000007;
		typedef struct _Hash *Hash;
		struct _Hash {
			int *h;
			int *inv;
		};
		Hash newHash(char *data, int len, int x)
		{
			ASSERT(len > 0);

			Hash hash = (Hash)calloc(1, sizeof(struct _Hash));

			int *h = (int*)calloc(len, sizeof(int));
			int *inv = (int*)calloc(len, sizeof(int));

			inv[0] = 1;
			ull y = mathematic::pow(x, PRIME - 2, PRIME);
			for (int i = 1; i < len; i++)
			{
				inv[i] = inv[i - 1] * y % PRIME;
			}

			ull xi = 1;
			h[0] = data[0];
			for (int i = 1; i < len; i++)
			{
				xi = xi * x % PRIME;
				h[i] = (xi * data[i] + h[i - 1]) % PRIME;
			}

			hash->h = h;
			hash->inv = inv;

			return hash;
		}
		int doHash(Hash hash, int min, int max) {
			if (min == 0)
			{
				return hash->h[max];
			}
			return (mathematic::modular(hash->h[max] - hash->h[min - 1], PRIME) * (ull)hash->inv[min] % PRIME);
		}
	}

	namespace st {
		typedef struct _ST *ST;
		using mathematic::id8;
		struct _ST {
			void ***min;
			int(*cmp)(void*, void*);
		};

		void* minItem(void *a, void *b, int(*cmp)(void*, void*))
		{
			return cmp(a, b) <= 0 ? a : b;
		}

		ST newST(void **data, int len, int(*cmp)(void*, void*)) {
			int log = id8(len) + 1;

			void ***min = (void***)calloc(log, sizeof(void**));
			for (int i = 0; i < log; i++)
			{
				min[i] = (void**)calloc(len, sizeof(void*));
			}

			memcpy(min[0], data, sizeof(void*)*len);
			for (int i = 1; i < log; i++)
			{
				int s = (1 << i);
				int h = s >> 1;
				for (int j = 0; j < len; j++)
				{
					if (j + h >= len)
					{
						min[i][j] = min[i - 1][j];
					}
					else
					{
						min[i][j] = minItem(min[i - 1][j], min[i - 1][j + s - h], cmp);
					}
				}
			}

			ST st = (ST)calloc(1, sizeof(struct _ST));
			st->cmp = cmp;
			st->min = min;

			return st;
		}

		void *query(ST st, int min, int max)
		{
			int len = max - min + 1;
			int log = id8(len);
			return minItem(st->min[log][min], st->min[log][max + 1 - (1 << log)], st->cmp);
		}
	}

	namespace hashmap {
		typedef struct _HashMapEntry *id13;
		typedef struct _HashMap *HashMap;
		typedef struct _HashMapIterator *HashMapIterator;
		struct  _HashMapEntry {
			id13 next;
			id13 last;
			void *val;
			void *key;
			int hash;
		} id2;
		struct  _HashMap {
			id13 *entries;
			int capacity;
			int size;
			double factor;
			int shrink;
			int mask;
			bool(*equal)(const void *a, const void *b);
			int(*hash)(const void*ptr);
		};
		struct  _HashMapIterator {
			HashMap map;
			id13 entry;
			int index;
		};
		id13 id11()
		{
			id13 entry = (id13)calloc(1, sizeof(struct  _HashMapEntry));
			return entry;
		}
		id13 id11(void *key, void *value, int hash)
		{
			id13 entry = id11();
			entry->hash = hash;
			entry->key = key;
			entry->val = value;
			return entry;
		}
		HashMap id5(int capacity, double factor, int(*hash)(const void*), bool(*equal)(const void*, const void*))
		{
			capacity = capacity / factor;
			int log = mathematic::id6(capacity);
			capacity = 1 << log;

			id13 *entries = (id13 *)calloc(capacity, sizeof(id13));
			for (int i = 0; i < capacity; i++)
			{
				entries[i] = &id2;
			}

			HashMap map = (HashMap)calloc(1, sizeof(struct _HashMap));
			map->capacity = capacity;
			map->entries = entries;
			map->factor = factor;
			map->shrink = capacity * factor;
			map->size = 0;
			map->hash = hash;
			map->equal = equal;
			map->mask = (1 << log) - 1;

			return map;
		}
		id13 checkList(id13 entry, void *key, int hash, bool(*equal)(const void*, const void*))
		{
			while (entry != &id2)
			{
				if (entry->key == key || (entry->hash == hash && equal(entry->key, key)))
				{
					return entry;
				}
				entry = entry->next;
			}
			return &id2;
		}
		inline int getHash(HashMap map, void*key)
		{
			uint h = map->hash(key);
			return h ^ (h >> 16);
		}
		inline int getIndex(HashMap map, int hash) {
			return map->mask & hash;
		}
		void add(HashMap map, void *key, void *value)
		{
			int hash = getHash(map, key);
			int index = getIndex(map, hash);
			id13 exist = checkList(map->entries[index], key, hash, map->equal);
			if (exist != &id2)
			{
				exist->val = value;
				return;
			}

			id13 newEntry = id11(key, value, hash);
			id13 top = map->entries[index];
			top->last = newEntry;
			newEntry->next = top;
			map->entries[index] = newEntry;

			map->size++;
		}
		void *find(HashMap map, void *key)
		{
			int hash = getHash(map, key);
			int index = getIndex(map, hash);
			id13 exist = checkList(map->entries[index], key, hash, map->equal);
			return exist == &id2 ? NULL : exist->val;
		}
		bool contain(HashMap map, void *key)
		{
			int hash = getHash(map, key);
			int index = getIndex(map, hash);
			id13 exist = checkList(map->entries[index], key, hash, map->equal);
			return exist != &id2;
		}
		void remove(HashMap map, void *key)
		{
			int hash = getHash(map, key);
			int index = getIndex(map, hash);
			id13 exist = checkList(map->entries[index], key, hash, map->equal);
			if (exist == &id2)
			{
				return;
			}
			exist->next->last = exist->last;
			if (exist->last)
			{
				exist->last->next = exist->next;
			}
			else
			{
				map->entries[index] = exist->next;
			}
			exist->next = NULL;
			exist->last = NULL;

			map->size--;
		}
		HashMapIterator newIterator(HashMap map)
		{
			HashMapIterator iterator = (HashMapIterator)calloc(1, sizeof(struct _HashMapIterator));
			iterator->entry = &id2;
			iterator->index = -1;
			iterator->map = map;
			return iterator;
		}
		bool hasMore(HashMapIterator iterator) {
			while (iterator->entry == &id2 && iterator->index + 1 < iterator->map->capacity)
			{
				iterator->entry = iterator->map->entries[++iterator->index];
			}
			return iterator->entry != &id2;
		}
		id13 nextEntry(HashMapIterator iterator) {
			id13 entry = iterator->entry;
			iterator->entry = entry->next;
			return entry;
		}
	}

	namespace sort {
		template<class T> void selectSort(T*ptr, int len, int(*cmp)(const void*, const void*))
		{
			for (int i = 0; i < len; i++)
			{
				int m = i;
				for (int j = i + 1; j < len; j++)
				{
					if (cmp(ptr + m, ptr + j) > 0) {
						m = j;
					}
				}
				if (m != i)
				{
					SWAP(ptr[m], ptr[i], T);
				}
			}
		}
		template<class T> void quickSort(T*ptr, int len, int(*cmp)(const void*, const void*)) {
			if (len <= 4)
			{
				selectSort(ptr, len, cmp);
				return;
			}
			int l = 0;
			int r = len - 1;
			for (int i = 1; i <= r; )
			{
				int c = cmp(&ptr[l], &ptr[i]);
				if (c > 0)
				{
					SWAP(ptr[l], ptr[i], T);
					l++;
					i++;
				}
				else if (c < 0)
				{
					SWAP(ptr[r], ptr[i], T);
					r--;
				}
				else
				{
					i++;
				}
			}

			quickSort(ptr, l, cmp);
			quickSort(ptr + r + 1, len - r - 1, cmp);
		}
		template<class T> void id16(T*ptr, int len, int(*cmp)(const void*, const void*)) {
			random::randomize(ptr, len);
			quickSort(ptr, len, cmp);
		}
	}
}




using std::vector;
using namespace dalt::io;
typedef struct _Node *Node;
struct _Node {
	vector<Node> children;
	int num;
	int id;
	int size;
	int version;
} nodes[200001];



vector<Node> numSet[200001];
ll appearance[200001];

void travel(Node node, Node head, int version)
{
	head->size++;
	node->version = version;
	for (int i = 0, until = node->children.size(); i < until; i++)
	{
		Node nearby = node->children[i];
		if (nearby->version == version)
		{
			continue;
		}
		if (nearby->num % version == 0)
		{
			travel(nearby, head, version);
		}	
	}
}

void solve() {
	int n = id10();
	for (int i = 1; i <= n; i++)
	{
		nodes[i].num = readInt();
		numSet[nodes[i].num].push_back(nodes + i);
		nodes[i].id = i;
	}

	for (int i = 1; i < n; i++)
	{
		Node a = nodes + readInt();
		Node b = nodes + readInt();
		a->children.push_back(b);
		b->children.push_back(a);
	}

	appearance[1] = (ll)n * (n - 1) / 2 + n;

	for (int i = 2; i <= 200000; i++)
	{
		for (int j = i; j <= 200000; j += i)
		{
			vector<Node> &vec = numSet[j];
			for (int k = 0, until = vec.size(); k < until; k++)
			{
				Node node = vec[k];
				if (node->version == i)
				{
					continue;
				}
				node->size = 0;
				travel(node, node, i);
				appearance[i] += (ll)node->size * (node->size + 1) / 2;
			}
		}
	}

	for (int i = 200000; i >= 1; i--)
	{
		for (int j = i + i; j <= 200000; j += i)
		{
			appearance[i] -= appearance[j];
		}
	}

	for (int i = 1; i <= 200000; i++)
	{
		if (appearance[i] == 0)
		{
			continue;
		}

		writeInt(i);
		write(' ');
		writeLong(appearance[i]);
		write('\n');
	}
}

int main() {

	freopen("E:\\DATABASE\\TESTCASE\\codeforces\\Contest45G.in", "r", stdin);
	freopen("E:\\DATABASE\\TESTCASE\\codeforces\\Contest45G.out", "w", stdout);


	solve();
	flush();
	return 0;
}
