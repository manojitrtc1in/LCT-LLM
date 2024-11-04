

























std::istream& operator>>(std::istream& is, __int128& x) {
    std::string s;
    is >> s;
    x = 0;
    bool neg = false;
    size_t i = 0;
    if (s[i] == '-') {
        neg = true;
        i++;
    }
    if (s[i] == '+')
        i++;
    for (; i < s.size(); i++) {
        if (!std::isdigit(s[i]))
            throw std::runtime_error(std::string("Non-numeric character: ") + s[i]);
        x *= 10;
        x += s[i] - '0';
    }
    if (neg)
        x *= -1;
    return is;
}

std::istream& operator>>(std::istream& is, __float128& x) {
    long double d;
    is >> d;
    x = d;
    return is;
}

template <class T1, class T2>
std::istream& operator>>(std::istream& is, std::pair<T1, T2>& p) {
    return is >> p.first >> p.second;
}

template <class T1>
std::istream& operator>>(std::istream& is, std::tuple<T1>& t) {
    return is >> std::get<0>(t);
}

template <class T1, class T2>
std::istream& operator>>(std::istream& is, std::tuple<T1, T2>& t) {
    return is >> std::get<0>(t) >> std::get<1>(t);
}

template <class T1, class T2, class T3>
std::istream& operator>>(std::istream& is, std::tuple<T1, T2, T3>& t) {
    return is >> std::get<0>(t) >> std::get<1>(t) >> std::get<2>(t);
}

template <class T1, class T2, class T3, class T4>
std::istream& operator>>(std::istream& is, std::tuple<T1, T2, T3, T4>& t) {
    return is >> std::get<0>(t) >> std::get<1>(t) >> std::get<2>(t) >> std::get<3>(t);
}

template <class T, size_t N>
std::istream& operator>>(std::istream& is, std::array<T, N>& a) {
    for (auto& elem : a) is >> elem;
    return is;
}

template <class T, class Allocator>
std::istream& operator>>(std::istream& is, std::vector<T, Allocator>& v) {
    for (auto& elem : v) is >> elem;
    return is;
}

std::ostream& operator<<(std::ostream& os, __int128 x) {
    if (x < 0) {
        os << "-";
        x *= -1;
    }
    std::string s;
    do {
        s.push_back('0' + x % 10);
        x /= 10;
    } while (x > 0);
    for (auto it = s.crbegin(); it != s.crend(); it++)
        os << *it;
    return os;
}

std::ostream& operator<<(std::ostream& os, __float128 x) {
    return os << (long double)x;
}

template <class T1, class T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
    return os << p.first << " " << p.second;
}

template <class T1>
std::ostream& operator<<(std::ostream& os, const std::tuple<T1>& t) {
    return os << std::get<0>(t);
}

template <class T1, class T2>
std::ostream& operator<<(std::ostream& os, const std::tuple<T1, T2>& t) {
    return os << std::get<0>(t) << " " << std::get<1>(t);
}

template <class T1, class T2, class T3>
std::ostream& operator<<(std::ostream& os, const std::tuple<T1, T2, T3>& t) {
    return os << std::get<0>(t) << " " << std::get<1>(t) << " " << std::get<2>(t);
}

template <class T1, class T2, class T3, class T4>
std::ostream& operator<<(std::ostream& os, const std::tuple<T1, T2, T3, T4>& t) {
    return os << std::get<0>(t) << " " << std::get<1>(t) << " " << std::get<2>(t) << " " << std::get<3>(t);
}

template <class T, size_t N>
std::ostream& operator<<(std::ostream& os, const std::array<T, N>& a) {
    for (auto it = a.begin(); it != a.end(); it++) {
        if (it != a.begin()) os << " ";
        os << *it;
    }
    return os;
}

template <class T, class Allocator>
std::ostream& operator<<(std::ostream& os, const std::vector<T, Allocator>& v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        if (it != v.begin()) os << " ";
        os << *it;
    }
    return os;
}

template <class Key, class Compare, class Allocator>
std::ostream& operator<<(std::ostream& os, const std::set<Key, Compare, Allocator>& s) {
    for (auto it = s.begin(); it != s.end(); it++) {
        if (it != s.begin()) os << " ";
        os << *it;
    }
    return os;
}

template <class Key, class Hash, class KeyEqual, class Allocator>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<Key, Hash, KeyEqual, Allocator>& us) {
    for (auto it = us.begin(); it != us.end(); it++) {
        if (it != us.begin()) os << " ";
        os << *it;
    }
    return os;
}

template <class T, class Container>
std::ostream& operator<<(std::ostream& os, std::stack<T, Container> s) {
    std::vector<T> vector;
    for (; !s.empty(); s.pop()) vector.push_back(s.top());
    for (auto it = vector.rbegin(); it != vector.rend(); it++) {
        if (it != vector.rbegin()) os << " ";
        os << *it;
    }
    return os;
}

template <class T, class Container>
std::ostream& operator<<(std::ostream& os, std::queue<T, Container> q) {
    for (; !q.empty(); q.pop()) {
        os << q.front();
        if (q.size() > 1) os << " ";
    }
    return os;
}

template <class T, class Allocator>
std::ostream& operator<<(std::ostream& os, const std::deque<T, Allocator>& d) {
    for (auto it = d.begin(); it != d.end(); it++) {
        if (it != d.begin()) os << " ";
        os << *it;
    }
    return os;
}

template <class T, class Container, class Compare>
std::ostream& operator<<(std::ostream& os, std::priority_queue<T, Container, Compare> pq) {
    for (; !pq.empty(); pq.pop()) {
        os << pq.top();
        if (pq.size() > 1) os << " ";
    }
    return os;
}

std::string pretty(std::string_view s) {
    std::stringstream ss;
    ss << s;
    return ss.str();
}

template <class T>
typename std::enable_if<std::is_integral<T>::value, std::string>::type pretty(T x) {
    std::stringstream ss;
    ss << x;
    return ss.str();
}

template <class T>
typename std::enable_if<std::is_floating_point<T>::value, std::string>::type pretty(T x) {
    std::stringstream ss;
    ss << x;
    return ss.str();
}

std::string pretty(__int128 x) {
    std::stringstream ss;
    ss << x;
    return ss.str();
}

std::string pretty(__float128 x) {
    std::stringstream ss;
    ss << x;
    return ss.str();
}

template <class T1, class T2>
std::string pretty(const std::pair<T1, T2>& p) {
    std::stringstream ss;
    ss << "(" << pretty(p.first) << ", " << pretty(p.second) << ")";
    return ss.str();
}

template <class T1>
std::string pretty(const std::tuple<T1>& t) {
    std::stringstream ss;
    ss << "(" << pretty(std::get<0>(t)) << ")";
    return ss.str();
}

template <class T1, class T2>
std::string pretty(const std::tuple<T1, T2>& t) {
    std::stringstream ss;
    ss << "(" << pretty(std::get<0>(t)) << ", " << pretty(std::get<1>(t)) << ")";
    return ss.str();
}

template <class T1, class T2, class T3>
std::string pretty(const std::tuple<T1, T2, T3>& t) {
    std::stringstream ss;
    ss << "(" << pretty(std::get<0>(t)) << ", " << pretty(std::get<1>(t)) << ", " << pretty(std::get<2>(t)) << ")";
    return ss.str();
}

template <class T1, class T2, class T3, class T4>
std::string pretty(const std::tuple<T1, T2, T3, T4>& t) {
    std::stringstream ss;
    ss << "(" << pretty(std::get<0>(t)) << ", " << pretty(std::get<1>(t)) << ", " << pretty(std::get<2>(t)) << ", " << pretty(std::get<3>(t)) << ")";
    return ss.str();
}

template <class T, size_t N>
std::string pretty(const std::array<T, N>& a) {
    std::stringstream ss;
    ss << "[";
    for (auto it = a.begin(); it != a.end(); it++) {
        if (it != a.begin()) ss << ", ";
        ss << pretty(*it);
    }
    ss << "]";
    return ss.str();
}

template <class T, class Allocator>
std::string pretty(const std::vector<T, Allocator>& v) {
    std::stringstream ss;
    ss << "[";
    for (auto it = v.begin(); it != v.end(); it++) {
        if (it != v.begin()) ss << ", ";
        ss << pretty(*it);
    }
    ss << "]";
    return ss.str();
}

template <class Key, class Compare, class Allocator>
std::string pretty(const std::set<Key, Compare, Allocator>& s) {
    std::stringstream ss;
    ss << "{";
    for (auto it = s.begin(); it != s.end(); it++) {
        if (it != s.begin()) ss << ", ";
        ss << pretty(*it);
    }
    ss << "}";
    return ss.str();
}

template <class Key, class T, class Compare, class Allocator>
std::string pretty(const std::map<Key, T, Compare, Allocator>& m) {
    std::stringstream ss;
    ss << "{";
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it != m.begin()) ss << ", ";
        ss << pretty(it->first) << ": " << pretty(it->second);
    }
    ss << "}";
    return ss.str();
}

template <class Key, class T, class Hash, class KeyEqual, class Allocator>
std::string pretty(const std::unordered_map<Key, T, Hash, KeyEqual, Allocator>& um) {
    std::stringstream ss;
    ss << "{";
    for (auto it = um.begin(); it != um.end(); it++) {
        if (it != um.begin()) ss << ", ";
        ss << pretty(it->first) << ": " << pretty(it->second);
    }
    ss << "}";
    return ss.str();
}

template <class Key, class Hash, class KeyEqual, class Allocator>
std::string pretty(const std::unordered_set<Key, Hash, KeyEqual, Allocator>& us) {
    std::stringstream ss;
    ss << "{";
    for (auto it = us.begin(); it != us.end(); it++) {
        if (it != us.begin()) ss << ", ";
        ss << pretty(*it);
    }
    ss << "}";
    return ss.str();
}

template <class T, class Container>
std::string pretty(std::stack<T, Container> s) {
    std::vector<T> vector;
    for (; !s.empty(); s.pop()) vector.push_back(s.top());
    std::stringstream ss;
    ss << "[";
    for (auto it = vector.rbegin(); it != vector.rend(); it++) {
        if (it != vector.rbegin()) ss << ", ";
        ss << pretty(*it);
    }
    ss << "]";
    return ss.str();
}

template <class T, class Container>
std::string pretty(std::queue<T, Container> q) {
    std::stringstream ss;
    ss << "[";
    for (; !q.empty(); q.pop()) {
        ss << pretty(q.front());
        if (q.size() > 1) ss << ", ";
    }
    ss << "]";
    return ss.str();
}

template <class T, class Allocator>
std::string pretty(const std::deque<T, Allocator>& d) {
    std::stringstream ss;
    ss << "[";
    for (auto it = d.begin(); it != d.end(); it++) {
        if (it != d.begin()) ss << ", ";
        ss << pretty(*it);
    }
    ss << "]";
    return ss.str();
}

template <class T, class Container, class Compare>
std::string pretty(std::priority_queue<T, Container, Compare> pq) {
    std::stringstream ss;
    ss << "[";
    for (; !pq.empty(); pq.pop()) {
        ss << pretty(pq.top());
        if (pq.size() > 1) ss << ", ";
    }
    ss << "]";
    return ss.str();
}

class ScopedTimer {
  public:
    ScopedTimer()
        : start_(std::chrono::steady_clock::now()) {}

    ScopedTimer(std::string_view prefix, std::string_view name)
        : prefix_(prefix), name_(name), start_(std::chrono::steady_clock::now()) {}

    template <class Period = std::ratio<1>>
    double get() const {
        const std::chrono::duration<double, Period> dur = std::chrono::steady_clock::now() - start_;
        return dur.count();
    }


    ~ScopedTimer() {
        std::cout << prefix_ << name_ << " " << pretty(get<std::milli>()) << " ms" << std::endl;
    }


  private:
    std::string prefix_;
    std::string name_;
    std::chrono::steady_clock::time_point start_;
};

namespace rng {

thread_local std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());

template <class T>
typename std::enable_if<std::is_integral<T>::value, T>::type get(T low, T high) {
    std::uniform_int_distribution<T> dist(low, high);
    return dist(mt);
}

template <class T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type get(T low, T high) {
    std::uniform_real_distribution<T> dist(low, high);
    return dist(mt);
}

template <class T>
typename std::enable_if<std::is_integral<T>::value, T>::type get() {
    return get<T>(0, std::numeric_limits<T>::max());
}

template <class T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type get() {
    return get<T>(0, 1);
}

}  


struct chash {
	const uint64_t C = (long long)(2e18 * M_PI) + 71;
	const int RANDOM = rng::get<int>();

    template <class T>
	long long operator()(T x) const {
		return __builtin_bswap64((std::hash<T>()(x) ^ RANDOM) * C);
	}
};





using namespace __gnu_pbds;

template <typename Key>
using ordered_set = tree<Key, null_type, std::less<Key>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename Key, typename Mapped>
using ordered_map = tree<Key, Mapped, std::less<Key>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename Key>
using hash_set = gp_hash_table<Key, null_type, chash>;

template <typename Key, typename Mapped>
using hash_map = gp_hash_table<Key, Mapped, chash>;

template <typename Key, typename Cmp_Fn, typename Tag, template <typename Const_Node_Iterator, typename Node_Iterator, typename Cmp_Fn_, typename Allocator_> class Node_Update, typename Allocator>
std::ostream& operator<<(std::ostream& os, const tree<Key, null_type, Cmp_Fn, Tag, Node_Update, Allocator>& t) {
    for (auto it = t.begin(); it != t.end(); ++it) {
        if (it != t.begin()) os << " ";
        os << *it;
    }
    return os;
}

template <typename Key, typename Hash_Fn, typename Eq_Fn, typename Comp_Probe_Fn, typename Probe_Fn, typename Resize_Policy, bool id0, typename Allocator>
std::ostream& operator<<(std::ostream& os, const gp_hash_table<Key, null_type, Hash_Fn, Eq_Fn, Comp_Probe_Fn, Probe_Fn, Resize_Policy, id0, Allocator>& gp) {
    for (auto it = gp.begin(); it != gp.end(); ++it) {
        if (it != gp.begin()) os << " ";
        os << *it;
    }
    return os;
}

template <typename Key, typename Mapped, typename Cmp_Fn, typename Tag, template <typename Const_Node_Iterator, typename Node_Iterator, typename Cmp_Fn_, typename Allocator_> class Node_Update, typename Allocator>
std::string pretty(const tree<Key, Mapped, Cmp_Fn, Tag, Node_Update, Allocator>& t) {
    std::stringstream ss;
    ss << "{";
    for (auto it = t.begin(); it != t.end(); ++it) {
        if (it != t.begin()) ss << ", ";
        ss << pretty(it->first) << ": " << pretty(it->second);
    }
    ss << "}";
    return ss.str();
}

template <typename Key, typename Cmp_Fn, typename Tag, template <typename Const_Node_Iterator, typename Node_Iterator, typename Cmp_Fn_, typename Allocator_> class Node_Update, typename Allocator>
std::string pretty(const tree<Key, null_type, Cmp_Fn, Tag, Node_Update, Allocator>& t) {
    std::stringstream ss;
    ss << "{";
    for (auto it = t.begin(); it != t.end(); ++it) {
        if (it != t.begin()) ss << ", ";
        ss << pretty(*it);
    }
    ss << "}";
    return ss.str();
}

template <typename Key, typename Mapped, typename Hash_Fn, typename Eq_Fn, typename Comp_Probe_Fn, typename Probe_Fn, typename Resize_Policy, bool id0, typename Allocator>
std::string pretty(const gp_hash_table<Key, Mapped, Hash_Fn, Eq_Fn, Comp_Probe_Fn, Probe_Fn, Resize_Policy, id0, Allocator>& gp) {
    std::stringstream ss;
    ss << "{";
    for (auto it = gp.begin(); it != gp.end(); ++it) {
        if (it != gp.begin()) ss << ", ";
        ss << pretty(it->first) << ": " << pretty(it->second);
    }
    ss << "}";
    return ss.str();
}

template <typename Key, typename Hash_Fn, typename Eq_Fn, typename Comp_Probe_Fn, typename Probe_Fn, typename Resize_Policy, bool id0, typename Allocator>
std::string pretty(const gp_hash_table<Key, null_type, Hash_Fn, Eq_Fn, Comp_Probe_Fn, Probe_Fn, Resize_Policy, id0, Allocator>& gp) {
    std::stringstream ss;
    ss << "{";
    for (auto it = gp.begin(); it != gp.end(); ++it) {
        if (it != gp.begin()) ss << ", ";
        ss << pretty(*it);
    }
    ss << "}";
    return ss.str();
}




template <typename Key>
using hash_set = unordered_set<Key, chash>;

template <typename Key, typename Mapped>
using hash_map = unordered_map<Key, Mapped, chash>;



std::vector<std::string> split(std::string_view s, const std::vector<char>& delims = {' ', '\f', '\n', '\r', '\t', '\v'}) {
    std::vector<std::string> v{""};
    size_t i = 0;    
    while (i < s.size()) {
        while (i < s.size() && !std::count(delims.begin(), delims.end(), s[i])) {
            v.back().push_back(s[i]);
            i++;
        }
        if (i < s.size()) {
            v.emplace_back();
            i++;
        }
    }
    return v;
}

template <class T>
void min_assign(T& var, T x) {
    var = std::min(var, x);
}

template <class T>
void max_assign(T& var, T x) {
    var = std::max(var, x);
}

const int INF = 1e9;
const long long LLINF = 1e18;
ScopedTimer exec_time(LOG_PREFIX, "exec_time");


















using namespace std;

using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using vvi = vector<vi>;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
using vvll = vector<vll>;
using ld = long double;
using ull = unsigned long long;
using vc = vector<char>;
using vvc = vector<vc>;

template <class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T> using max_heap = priority_queue<T>;


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << setprecision(numeric_limits<double>::max_digits10) << fixed;
    int ts;
    cin >> ts;
    while(ts--){
        int n;
        cin >> n;
        int be = 0, en = n;
        while(en-be > 1){
            int mi = (en+be)/2;
            cout << "? " << be+1 << " " << mi << endl << flush;
            vi v(mi-be);
            cin >> v;
            if(v[0] == -1){
                return 0;
            }
            int go = 0, ba = 0;
            FOR(i,0,v.size()){
                if(v[i]-1 < be || v[i]-1 >= mi){
                    ba++;
                }
                else{
                    go++;
                }
            }
            if(go%2 == 1){
                en = mi;
            }
            else{
                be = mi;
            }
        }
        cout << "! " << be+1 << endl << flush;
    }
    return 0;
}