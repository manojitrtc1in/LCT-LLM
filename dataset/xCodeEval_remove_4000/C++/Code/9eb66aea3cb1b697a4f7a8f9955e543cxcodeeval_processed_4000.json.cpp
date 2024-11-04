





namespace ds {

class SAAlgo
{
public:
    virtual ~SAAlgo() {}

public:
    virtual void run(const int *r, int *sa, int *rank, int length, int sigma) = 0;

protected:
    static void sort(const int *r, const int *s, int *t, int length, int *cnt, int sigma);
};

class SAAlgoDA: public SAAlgo
{
public:
    virtual void run(const int *r, int *sa, int *rank, int length, int sigma);

private:
    static bool equal(const int *r, int len, int x, int y);

};

class id0: public SAAlgo
{
public:
    virtual void run(const int *r, int *sa, int *rank, int length, int sigma);

private:
    void doRun(int *r, int *sa, int length, int sigma);
    static bool equal(const int *r, int x, int y);
    bool cmp(int t, const int *r, int x, int y);

private:
    int *_cnt;
    int *_r;
    int *_sa;
    int *_sa0;
    int *_sa12;
    int *_rank12;

};

class SuffixArray
{
public:
    explicit SuffixArray(const std::vector<int> &r, SAAlgo *algo=new SAAlgoDA);
    explicit SuffixArray(const std::string &s, SAAlgo *algo=new SAAlgoDA);
    virtual ~SuffixArray();

public:
    const std::vector<int>& sa() const { return _sa; }
    int sa(int i) const { return _sa[i]; }
    const std::vector<int>& rank() const { return _rank; }
    int rank(int i) const { return _rank[i]; }
    const std::vector<int>& height() const { return _height; }
    int height(int i) const { return _height[i]; }

private:
    template<typename TContainer>
    void initialize(const TContainer &r);
    void run();
    void calcHeight();

private:
    int _sigma;
    std::vector<int> _r;
    SAAlgo *_algo;
    std::vector<int> _sa;
    std::vector<int> _rank;
    std::vector<int> _height;

};

}










namespace ds {

using namespace std;

SuffixArray::SuffixArray(const vector<int> &r, SAAlgo *algo)
    : _algo(algo)
{
    assert(_algo);
    initialize(r);
    run();
}

SuffixArray::SuffixArray(const string &s, SAAlgo *algo)
    : _algo(algo)
{
    assert(_algo);
    initialize(s);
    run();
}

SuffixArray::~SuffixArray()
{
    if (_algo) delete _algo;
}

template<typename TContainer>
void SuffixArray::initialize(const TContainer &r)
{
    _r.reserve(r.size() + 1);
    _r.assign(r.begin(), r.end());
    map<int, int> hash;
    _sigma = 1;
    for (vector<int>::const_iterator cit = _r.begin(); cit != _r.end(); cit++) hash[*cit] = _sigma;
    for (map<int, int>::iterator now = hash.begin(); now != hash.end(); now++) now->second = _sigma++;
    for (size_t i = 0; i < _r.size(); i++) _r[i] = hash[_r[i]];
    _r.push_back(0);
}

void SuffixArray::run()
{
    _sa.resize(_r.size());
    _rank.resize(_r.size());
    _algo->run(_r.data(), _sa.data(), _rank.data(), _r.size(), _sigma);
    calcHeight();
}

void SuffixArray::calcHeight()
{
    int n = _r.size();
    _height.resize(n);
    for (int i = 0, k = 0; i + 1 < n; i++, k -= k > 0) {
        while (_r[i + k] == _r[_sa[_rank[i] - 1] + k]) k++;
        _height[_rank[i]] = k;
    }
}



void SAAlgo::sort(const int *r, const int *s, int *t, int length, int *cnt, int sigma)
{
    memset(cnt, 0, sizeof(int) * sigma);
    

    for (int i = 0; i < length; i++) cnt[r[s[i]]]++;
    for (int j = 1; j < sigma; j++) cnt[j] += cnt[j - 1];
    for (int i = length - 1; i >= 0; i--) t[--cnt[r[s[i]]]] = s[i];
}

bool SAAlgoDA::equal(const int *r, int len, int x, int y)
{
    return r[x] == r[y] && r[x + len] == r[y + len];
}

void SAAlgoDA::run(const int *r, int *sa, int *rank, int length, int sigma)
{
    int *buf = new int[length * 3];
    int *cnt = buf;
    int *p_rank = cnt + length;
    int *n_rank = p_rank + length;
    int *p_sa = p_rank;
    memcpy(n_rank, r, sizeof(int) * length);
    for (int i = 0; i < length; i++) p_sa[i] = i;
    sort(n_rank, p_sa, sa, length, cnt, sigma);
    for (int len = 1; sigma < length; len <<= 1) {
        swap(p_rank, n_rank);
        p_sa = n_rank;
        int p = 0;
        for (int i = length - len; i < length; i++) p_sa[p++] = i;
        for (int i = 0; i < length; i++) if (sa[i] >= len) p_sa[p++] = sa[i] - len;
        sort(p_rank, p_sa, sa, length, cnt, sigma);
        sigma = 0;
        n_rank[sa[0]] = sigma++;
        for (int i = 1; i < length; i++)
            n_rank[sa[i]] = equal(p_rank, len, sa[i - 1], sa[i])? sigma - 1 : sigma++;
    }
    memcpy(rank, n_rank, sizeof(int) * length);
    delete[] buf;
}

void id0::run(const int *r, int *sa, int *rank, int length, int sigma)
{
    int *buf = new int[length * 12];
    _cnt = buf;
    _r = _cnt + length;
    _sa = _r + length * 3;
    _sa0 = _sa + length * 3;
    _sa12 = _sa0 + length;
    _rank12 = _sa12 + length;
    memcpy(_r, r, sizeof(int) * length);
    doRun(_r, _sa, length, sigma);
    memcpy(sa, _sa, sizeof(int) * length);
    for (int i = 0; i < length; i++) rank[sa[i]] = i;
    delete[] buf;
}

void id0::doRun(int *r, int *sa, int length, int sigma)
{


    

    int len12 = 0, len1 = (length + 1) / 3;
    for (int i = 0; i < length; i++) if (i % 3) _sa0[len12++] = i;
    r[length] = r[length + 1] = 0;
    sort(r + 2, _sa0, _sa12, len12, _cnt, sigma);
    sort(r + 1, _sa12, _sa0, len12, _cnt, sigma);
    sort(r, _sa0, _sa12, len12, _cnt, sigma);
    int *n_r = r + length, *n_sa = sa + length;
    int n_sigma = 0;
    n_r[F(_sa12[0])] = n_sigma++;
    for (int i = 1; i < len12; i++)
        n_r[F(_sa12[i])] = equal(r, _sa12[i - 1], _sa12[i])? n_sigma - 1 : n_sigma++;
    if (n_sigma < len12) doRun(n_r, n_sa, len12, n_sigma);
    else for (int i = 0; i < len12; i++) n_sa[n_r[i]] = i;
    

    int len0 = 0;
    if (length % 3 == 1) _sa12[len0++] = length - 1;
    for (int i = 0; i < len12; i++)
        if (n_sa[i] < len1)
            _sa12[len0++] = n_sa[i] * 3;
    sort(r, _sa12, _sa0, len0, _cnt, sigma);
    for (int i = 0; i < len12; i++) _sa12[i] = rF(n_sa[i]);
    for (int i = 0; i < len12; i++) _rank12[_sa12[i]] = i;
    

    int k = 0, i = 0, j = 0;
    while (i < len0 && j < len12)
        sa[k++] = cmp(_sa12[j] % 3, r, _sa0[i], _sa12[j])? _sa0[i++] : _sa12[j++];
    while (i < len0) sa[k++] = _sa0[i++];
    while (j < len12) sa[k++] = _sa12[j++];


}

bool id0::equal(const int *r, int x, int y)
{
    return r[x] == r[y] && r[x + 1] == r[y + 1] && r[x + 2] == r[y + 2];
}

bool id0::cmp(int t, const int *r, int x, int y)
{
    if (r[x] != r[y]) return r[x] < r[y];
    if (t == 1) return _rank12[x + 1] < _rank12[y + 1];
    else return cmp(1, r, x + 1, y + 1);
}

}








namespace ds {

template<typename T, typename TCompare=std::less<T> >
class SparseTable
{
    static TCompare _compare;
public:
    explicit SparseTable(const std::vector<T> &a);

public:
    T query(size_t left, size_t right) const;

private:
    void initialize(const std::vector<T> &a);

private:
    std::vector<std::vector<T> > _st;

};

}









namespace ds {

template<typename T, typename TCompare>
TCompare SparseTable<T, TCompare>::_compare;

template<typename T, typename TCompare>
SparseTable<T, TCompare>::SparseTable(const std::vector<T> &a)
{
    initialize(a);
}

template<typename T, typename TCompare>
T SparseTable<T, TCompare>::query(size_t left, size_t right) const
{
    assert(left < right);
    assert(right <= _st.front().size());
    if (right - left == 1) return _st.front()[left];
    size_t level = 0;
    size_t half = 1;
    for (size_t len = half << 1; len < right - left; half = len, len <<= 1) level++;
    return min(_st[level][left], _st[level][right - half], _compare);
}

template<typename T, typename TCompare>
void SparseTable<T, TCompare>::initialize(const std::vector<T> &a)
{
    _st.reserve(20);
    _st.push_back(a);
    for (size_t level = 1, len = 2, half = 1; len <= a.size(); level++, half = len, len <<= 1) {
        std::vector<int> &lower = _st.back();
        _st.push_back(std::vector<int>());
        std::vector<int> &upper = _st.back();
        upper.reserve(a.size() - len + 1);
        for (size_t i = 0; i + len <= a.size(); i++)
            upper.push_back(min(lower[i], lower[i + half], _compare));
    }
}

}










namespace ds {

class id1
{
public:
    explicit id1(size_t upper);
    ~id1();

public:
    void update(size_t x, int inc);
    int query(size_t x);
    size_t bsearch(int x);

private:
    static size_t lowbit(size_t x) { return -x & x; }

private:
    std::vector<int> _tree;

};

}






namespace ds {

using namespace std;

id1::id1(size_t upper)
{
    assert(upper > 0);
    while (upper > lowbit(upper)) upper += lowbit(upper);
    _tree.resize(upper + 1);
}

id1::~id1()
{
}

void id1::update(size_t x, int inc)
{
    assert(x < _tree.size());
    for (size_t i = x; i < _tree.size(); i += lowbit(i)) _tree[i] += inc;
}

int id1::query(size_t x)
{
    assert(x < _tree.size());
    int sum = 0;
    for (size_t i = x; i > 0; i -= lowbit(i)) sum += _tree[i];
    return sum;
}

size_t id1::bsearch(int x)
{
    assert(_tree.back() >= x);
    size_t cnt = 0;
    int sum = 0;
    for (size_t i = _tree.size() - 1; i > 0; i >>= 1) {
        if (sum + _tree[cnt + i] >= x) continue;
        sum += _tree[cnt += i];
    }
    return cnt + 1;
}

}







using namespace std;
using namespace ds;
const int MAX_LENGTH = 200000;
char buf[MAX_LENGTH + 10];


vector<int> r;
vector<int> begins;
struct Query {
    Query(): ans(0) {}
    friend ostream& operator<<(ostream &out, const Query &q)
    {
        out << "Q<"
            << q.l << ", "
            << q.r << ", "
            << q.k << "| "
            << q.lower << ", "
            << q.upper << ">: "
            << q.ans;
        return out;
    }
    int l, r, k;
    int lower, upper;
    int ans;
};
vector<Query> queries;
struct Event {
    Event(int _q, int _s, int _p): q(_q), sign(_s), pos(_p) {}
    friend bool operator<(const Event &a, const Event &b)
    {
        return a.pos < b.pos;
    }
    friend ostream& operator<<(ostream &out, const Event &e)
    {
        out << "E<"
            << e.q << ", "
            << e.sign << ", "
            << e.pos << ">";
        return out;
    }
    int q;
    int sign;
    int pos;
};
vector<Event> events;

template<typename T>
ostream& operator<<(ostream &out, const std::vector<T> &v)
{
    out << "v<";
    for (int i = 0; i < v.size(); i++)
        out << i << ": " << v[i] << ", ";
    out << ">";
    return out;
}

void ReadIn()
{
    int n, q;
    scanf("%d%d", &n, &q);
    r.reserve(MAX_LENGTH * 2 + 10);
    begins.resize(n + 1);
    for (int i = 0, offset = 0; i < n; i++) {
        scanf("%s", buf);
        

        begins[i] = offset;
        for (char *s = buf; *s; s++) r.push_back(*s);
        r.push_back(i + 0x80);
        offset += strlen(buf) + 1;
    }
    begins.back() = r.size();
    

    

    queries.resize(q);
    for (int i = 0; i < q; i++) {
        scanf("%d%d%d",
            &queries[i].l,
            &queries[i].r,
            &queries[i].k);
        queries[i].l--;
        queries[i].r--;
        queries[i].k--;
    }
    

}

void Solve()
{
    SuffixArray sa(r, new id0);
    

    

    

    

    

    

    

    

    

    events.reserve(queries.size() << 1);
    SparseTable<int> lcp(sa.height());
    for (int q = 0; q < queries.size(); q++) {
        events.push_back(Event(q, -1, begins[queries[q].l]));
        events.push_back(Event(q, 1, begins[queries[q].r + 1]));
        int pos = sa.rank(begins[queries[q].k]);
        int len = begins[queries[q].k + 1]
                - begins[queries[q].k] - 1;
        int lower = 1, upper = pos + 1, mid;
        while (lower < upper) {
            mid = (lower + upper) >> 1;
            if (lcp.query(mid, pos + 1) < len) lower = mid + 1;
            else upper = mid; 
        }
        queries[q].lower = lower - 1;
        lower = pos + 1;
        upper = r.size() + 2;
        while (lower < upper) {
            mid = (lower + upper + 1) >> 1;
            if (lcp.query(pos + 1, mid) < len) upper = mid - 1;
            else lower = mid;
        }
        queries[q].upper = lower;
    }
    sort(events.begin(), events.end());
    

    id1 t(r.size() + 2);
    int p = 0;
    for (int e = 0; e < events.size(); e++) {
        Query &query = queries[events[e].q];
        while (p < events[e].pos) {
            

            t.update(sa.rank(p++) + 1, 1);
        }
        

        query.ans += events[e].sign * (t.query(query.upper) - t.query(query.lower));
        

    }
    

    for (int i = 0; i < queries.size(); i++)
        printf("%d\n", queries[i].ans);
}

int main()
{
    ReadIn();
    Solve();
    return 0;
}