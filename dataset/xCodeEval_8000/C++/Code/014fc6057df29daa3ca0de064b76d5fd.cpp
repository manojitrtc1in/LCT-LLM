#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args> void ndarray(vector<T>& vec, const V& val, int len, Args... args) { vec.resize(len), for_each(begin(vec), end(vec), [&](T& v) { ndarray(v, val, args...); }); }
template <typename T> bool chmax(T &m, const T q) { return m < q ? (m = q, true) : false; }
template <typename T> bool chmin(T &m, const T q) { return m > q ? (m = q, true) : false; }
int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> int arglb(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <typename T> int argub(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), x)); }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T, size_t sz> ostream &operator<<(ostream &os, const array<T, sz> &arr) { os << '['; for (auto v : arr) os << v << ','; os << ']'; return os; }
#if __cplusplus >= 201703L
template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) { os << '('; std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os << ')'; }
#endif
template <typename T> ostream &operator<<(ostream &os, const deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T, typename TH> ostream &operator<<(ostream &os, const unordered_set<T, TH> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <typename TK, typename TV, typename TH> ostream &operator<<(ostream &os, const unordered_map<TK, TV, TH> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
#ifdef HITONANODE_LOCAL
const string COLOR_RESET = "\033[0m", BRIGHT_GREEN = "\033[1;32m", BRIGHT_RED = "\033[1;31m", BRIGHT_CYAN = "\033[1;36m", NORMAL_CROSSED = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", NORMAL_FAINT = "\033[0;2m";
#define dbg(x) cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl
#define dbgif(cond, x) ((cond) ? cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl : cerr)
#else
#define dbg(x) (x)
#define dbgif(cond, x) 0
#endif

template <> struct std::numeric_limits<__int128> {
    static __int128 max() noexcept { return ((__int128(1) << 126) - 1) * 2 + 1; }
    static __int128 min() noexcept { return -max() - 1; }
    static __int128 lowest() noexcept { return min(); }
};
__int128 str2i128(std::string str) {
    __int128 ret = 0;
    bool minus = false;
    for (auto c : str) {
        if (c == '-')
            minus = true;
        else
            ret = ret * 10 + c - '0';
    }
    return minus ? -ret : ret;
}
std::istream &operator>>(std::istream &is, __int128 &x) {
    std::string s;
    return is >> s, x = str2i128(s), is;
}
std::ostream &operator<<(std::ostream &os, const __int128 &x) {
    __int128 tmp = x;
    if (tmp == 0) return os << 0;
    std::vector<int> ds;
    if (tmp < 0) {
        os << '-';
        while (tmp) {
            int d = tmp % 10;
            if (d > 0) d -= 10;
            ds.emplace_back(-d), tmp = (tmp - d) / 10;
        }
    } else {
        while (tmp) ds.emplace_back(tmp % 10), tmp /= 10;
    }
    std::reverse(ds.begin(), ds.end());
    for (auto i : ds) os << i;
    return os;
}







template <class Digraph, typename V = int, typename C = V> class NetworkSimplex {
public:
    using Node = int;
    using Arc = int;
    static const int INVALID = -1;
    typedef V Value; 

    typedef C Cost;  


public:
    enum ProblemType { INFEASIBLE, OPTIMAL, UNBOUNDED };

    

    

    

    

    

    

    

    

    

    enum SupplyType {
        

        

        GEQ,
        

        

        LEQ
    };

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    enum PivotRule {

        

        

        

        FIRST_ELIGIBLE,

        

        

        BEST_ELIGIBLE,

        

        

        

        

        BLOCK_SEARCH,

        

        

        

        

        CANDIDATE_LIST,

        

        

        

        

        ALTERING_LIST
    };

private:
    using IntVector = std::vector<int>;
    using ValueVector = std::vector<Value>;
    using CostVector = std::vector<Cost>;
    using CharVector = std::vector<signed char>;
    enum ArcState { STATE_UPPER = -1, STATE_TREE = 0, STATE_LOWER = 1 };
    enum ArcDirection { DIR_DOWN = -1, DIR_UP = 1 };

private:
    

    const Digraph &_graph;
    int _node_num;
    int _arc_num;
    int _all_arc_num;
    int _search_arc_num;

    

    bool _has_lower;
    SupplyType _stype;
    Value _sum_supply;

    

    IntVector _source;
    IntVector _target;

    

    ValueVector _lower;
    ValueVector _upper;
    ValueVector _cap;
    CostVector _cost;
    ValueVector _supply;
    ValueVector _flow;
    CostVector _pi;

    

    IntVector _parent;
    IntVector _pred;
    IntVector _thread;
    IntVector _rev_thread;
    IntVector _succ_num;
    IntVector _last_succ;
    CharVector _pred_dir;
    CharVector _state;
    IntVector _dirty_revs;
    int _root;

    

    int in_arc, join, u_in, v_in, u_out, v_out;
    Value delta;

    const Value MAX;

public:
    

    

    

    

    

    const Value INF;

private:
    

    class FirstEligiblePivotRule {
    private:
        

        const IntVector &_source;
        const IntVector &_target;
        const CostVector &_cost;
        const CharVector &_state;
        const CostVector &_pi;
        int &_in_arc;
        int _search_arc_num;

        

        int _next_arc;

    public:
        

        FirstEligiblePivotRule(NetworkSimplex &ns)
            : _source(ns._source), _target(ns._target), _cost(ns._cost), _state(ns._state), _pi(ns._pi), _in_arc(ns.in_arc), _search_arc_num(ns._search_arc_num), _next_arc(0) {}

        

        bool findEnteringArc() {
            Cost c;
            for (int e = _next_arc; e != _search_arc_num; ++e) {
                c = _state[e] * (_cost[e] + _pi[_source[e]] - _pi[_target[e]]);
                if (c < 0) {
                    _in_arc = e;
                    _next_arc = e + 1;
                    return true;
                }
            }
            for (int e = 0; e != _next_arc; ++e) {
                c = _state[e] * (_cost[e] + _pi[_source[e]] - _pi[_target[e]]);
                if (c < 0) {
                    _in_arc = e;
                    _next_arc = e + 1;
                    return true;
                }
            }
            return false;
        }

    }; 


    

    class BestEligiblePivotRule {
    private:
        

        const IntVector &_source;
        const IntVector &_target;
        const CostVector &_cost;
        const CharVector &_state;
        const CostVector &_pi;
        int &_in_arc;
        int _search_arc_num;

    public:
        

        BestEligiblePivotRule(NetworkSimplex &ns)
            : _source(ns._source), _target(ns._target), _cost(ns._cost), _state(ns._state), _pi(ns._pi), _in_arc(ns.in_arc), _search_arc_num(ns._search_arc_num) {}

        

        bool findEnteringArc() {
            Cost c, min = 0;
            for (int e = 0; e != _search_arc_num; ++e) {
                c = _state[e] * (_cost[e] + _pi[_source[e]] - _pi[_target[e]]);
                if (c < min) {
                    min = c;
                    _in_arc = e;
                }
            }
            return min < 0;
        }

    }; 


    

    class BlockSearchPivotRule {
    private:
        

        const IntVector &_source;
        const IntVector &_target;
        const CostVector &_cost;
        const CharVector &_state;
        const CostVector &_pi;
        int &_in_arc;
        int _search_arc_num;

        

        int _block_size;
        int _next_arc;

    public:
        

        BlockSearchPivotRule(NetworkSimplex &ns)
            : _source(ns._source), _target(ns._target), _cost(ns._cost), _state(ns._state), _pi(ns._pi), _in_arc(ns.in_arc), _search_arc_num(ns._search_arc_num), _next_arc(0) {
            

            const double BLOCK_SIZE_FACTOR = 1.0;
            const int MIN_BLOCK_SIZE = 10;

            _block_size = std::max(int(BLOCK_SIZE_FACTOR * std::sqrt(double(_search_arc_num))), MIN_BLOCK_SIZE);
        }

        

        bool findEnteringArc() {
            Cost c, min = 0;
            int cnt = _block_size;
            int e;
            for (e = _next_arc; e != _search_arc_num; ++e) {
                c = _state[e] * (_cost[e] + _pi[_source[e]] - _pi[_target[e]]);
                if (c < min) {
                    min = c;
                    _in_arc = e;
                }
                if (--cnt == 0) {
                    if (min < 0) goto search_end;
                    cnt = _block_size;
                }
            }
            for (e = 0; e != _next_arc; ++e) {
                c = _state[e] * (_cost[e] + _pi[_source[e]] - _pi[_target[e]]);
                if (c < min) {
                    min = c;
                    _in_arc = e;
                }
                if (--cnt == 0) {
                    if (min < 0) goto search_end;
                    cnt = _block_size;
                }
            }
            if (min >= 0) return false;

        search_end:
            _next_arc = e;
            return true;
        }

    }; 


    

    class CandidateListPivotRule {
    private:
        

        const IntVector &_source;
        const IntVector &_target;
        const CostVector &_cost;
        const CharVector &_state;
        const CostVector &_pi;
        int &_in_arc;
        int _search_arc_num;

        

        IntVector _candidates;
        int _list_length, _minor_limit;
        int _curr_length, _minor_count;
        int _next_arc;

    public:
        

        CandidateListPivotRule(NetworkSimplex &ns)
            : _source(ns._source), _target(ns._target), _cost(ns._cost), _state(ns._state), _pi(ns._pi), _in_arc(ns.in_arc), _search_arc_num(ns._search_arc_num), _next_arc(0) {
            

            const double LIST_LENGTH_FACTOR = 0.25;
            const int MIN_LIST_LENGTH = 10;
            const double MINOR_LIMIT_FACTOR = 0.1;
            const int MIN_MINOR_LIMIT = 3;

            _list_length = std::max(int(LIST_LENGTH_FACTOR * std::sqrt(double(_search_arc_num))), MIN_LIST_LENGTH);
            _minor_limit = std::max(int(MINOR_LIMIT_FACTOR * _list_length), MIN_MINOR_LIMIT);
            _curr_length = _minor_count = 0;
            _candidates.resize(_list_length);
        }

        

        bool findEnteringArc() {
            Cost min, c;
            int e;
            if (_curr_length > 0 && _minor_count < _minor_limit) {
                

                

                ++_minor_count;
                min = 0;
                for (int i = 0; i < _curr_length; ++i) {
                    e = _candidates[i];
                    c = _state[e] * (_cost[e] + _pi[_source[e]] - _pi[_target[e]]);
                    if (c < min) {
                        min = c;
                        _in_arc = e;
                    } else if (c >= 0) {
                        _candidates[i--] = _candidates[--_curr_length];
                    }
                }
                if (min < 0) return true;
            }

            

            min = 0;
            _curr_length = 0;
            for (e = _next_arc; e != _search_arc_num; ++e) {
                c = _state[e] * (_cost[e] + _pi[_source[e]] - _pi[_target[e]]);
                if (c < 0) {
                    _candidates[_curr_length++] = e;
                    if (c < min) {
                        min = c;
                        _in_arc = e;
                    }
                    if (_curr_length == _list_length) goto search_end;
                }
            }
            for (e = 0; e != _next_arc; ++e) {
                c = _state[e] * (_cost[e] + _pi[_source[e]] - _pi[_target[e]]);
                if (c < 0) {
                    _candidates[_curr_length++] = e;
                    if (c < min) {
                        min = c;
                        _in_arc = e;
                    }
                    if (_curr_length == _list_length) goto search_end;
                }
            }
            if (_curr_length == 0) return false;

        search_end:
            _minor_count = 1;
            _next_arc = e;
            return true;
        }

    }; 


    

    class AlteringListPivotRule {
    private:
        

        const IntVector &_source;
        const IntVector &_target;
        const CostVector &_cost;
        const CharVector &_state;
        const CostVector &_pi;
        int &_in_arc;
        int _search_arc_num;

        

        int _block_size, _head_length, _curr_length;
        int _next_arc;
        IntVector _candidates;
        CostVector _cand_cost;

        

        class SortFunc {
        private:
            const CostVector &_map;

        public:
            SortFunc(const CostVector &map) : _map(map) {}
            bool operator()(int left, int right) { return _map[left] < _map[right]; }
        };

        SortFunc _sort_func;

    public:
        

        AlteringListPivotRule(NetworkSimplex &ns)
            : _source(ns._source), _target(ns._target), _cost(ns._cost), _state(ns._state), _pi(ns._pi), _in_arc(ns.in_arc), _search_arc_num(ns._search_arc_num), _next_arc(0), _cand_cost(ns._search_arc_num), _sort_func(_cand_cost) {
            

            const double BLOCK_SIZE_FACTOR = 1.0;
            const int MIN_BLOCK_SIZE = 10;
            const double HEAD_LENGTH_FACTOR = 0.01;
            const int MIN_HEAD_LENGTH = 3;

            _block_size = std::max(int(BLOCK_SIZE_FACTOR * std::sqrt(double(_search_arc_num))), MIN_BLOCK_SIZE);
            _head_length = std::max(int(HEAD_LENGTH_FACTOR * _block_size), MIN_HEAD_LENGTH);
            _candidates.resize(_head_length + _block_size);
            _curr_length = 0;
        }

        

        bool findEnteringArc() {
            

            int e;
            Cost c;
            for (int i = 0; i != _curr_length; ++i) {
                e = _candidates[i];
                c = _state[e] * (_cost[e] + _pi[_source[e]] - _pi[_target[e]]);
                if (c < 0) {
                    _cand_cost[e] = c;
                } else {
                    _candidates[i--] = _candidates[--_curr_length];
                }
            }

            

            int cnt = _block_size;
            int limit = _head_length;

            for (e = _next_arc; e != _search_arc_num; ++e) {
                c = _state[e] * (_cost[e] + _pi[_source[e]] - _pi[_target[e]]);
                if (c < 0) {
                    _cand_cost[e] = c;
                    _candidates[_curr_length++] = e;
                }
                if (--cnt == 0) {
                    if (_curr_length > limit) goto search_end;
                    limit = 0;
                    cnt = _block_size;
                }
            }
            for (e = 0; e != _next_arc; ++e) {
                c = _state[e] * (_cost[e] + _pi[_source[e]] - _pi[_target[e]]);
                if (c < 0) {
                    _cand_cost[e] = c;
                    _candidates[_curr_length++] = e;
                }
                if (--cnt == 0) {
                    if (_curr_length > limit) goto search_end;
                    limit = 0;
                    cnt = _block_size;
                }
            }
            if (_curr_length == 0) return false;

        search_end:

            

            int new_length = std::min(_head_length + 1, _curr_length);
            std::partial_sort(_candidates.begin(), _candidates.begin() + new_length, _candidates.begin() + _curr_length, _sort_func);

            

            _in_arc = _candidates[0];
            _next_arc = e;
            _candidates[0] = _candidates[new_length - 1];
            _curr_length = new_length - 1;
            return true;
        }

    }; 


public:
    NetworkSimplex(const Digraph &graph)
        : _graph(graph), MAX(std::numeric_limits<Value>::max()), INF(std::numeric_limits<Value>::has_infinity ? std::numeric_limits<Value>::infinity() : MAX) {
        

        

        

        static_assert(std::numeric_limits<Value>::max() > 0, "max() must be greater than 0");

        

        reset();
    }

    template <typename LowerMap> NetworkSimplex &lowerMap(const LowerMap &map) {
        _has_lower = true;
        for (Arc a = 0; a < _arc_num; a++) _lower[a] = map[a];
        return *this;
    }
    template <typename UpperMap> NetworkSimplex &upperMap(const UpperMap &map) {
        for (Arc a = 0; a < _arc_num; a++) _upper[a] = map[a];
        return *this;
    }
    

    template <typename CostMap> NetworkSimplex &costMap(const CostMap &map) {
        for (Arc a = 0; a < _arc_num; a++) _cost[a] = map[a];
        return *this;
    }
    template <typename SupplyMap> NetworkSimplex &supplyMap(const SupplyMap &map) {
        for (Node n = 0; n < _node_num; n++) _supply[n] = map[n];
        return *this;
    }
    NetworkSimplex &stSupply(const Node &s, const Node &t, Value k) { 

        for (int i = 0; i != _node_num; ++i) _supply[i] = 0;
        _supply[s] = k, _supply[t] = -k;
        return *this;
    }

    

    

    

    

    

    NetworkSimplex &supplyType(SupplyType supply_type) {
        _stype = supply_type;
        return *this;
    }

    


    

    

    

    

    

    

    ProblemType run(PivotRule pivot_rule = BLOCK_SEARCH) {
        if (!init()) return INFEASIBLE;
        return start(pivot_rule);
    }

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    NetworkSimplex &resetParams() {
        for (int i = 0; i != _node_num; ++i) { _supply[i] = 0; }
        for (int i = 0; i != _arc_num; ++i) {
            _lower[i] = 0;
            _upper[i] = INF;
            _cost[i] = 1;
        }
        _has_lower = false;
        _stype = GEQ;
        return *this;
    }

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    NetworkSimplex &reset() {
        

        _node_num = _graph.countNodes();
        _arc_num = _graph.countArcs();
        int all_node_num = _node_num + 1;
        int max_arc_num = _arc_num + 2 * _node_num;

        _source.resize(max_arc_num);
        _target.resize(max_arc_num);

        _lower.resize(_arc_num);
        _upper.resize(_arc_num);
        _cap.resize(max_arc_num);
        _cost.resize(max_arc_num);
        _supply.resize(all_node_num);
        _flow.resize(max_arc_num);
        _pi.resize(all_node_num);

        _parent.resize(all_node_num);
        _pred.resize(all_node_num);
        _pred_dir.resize(all_node_num);
        _thread.resize(all_node_num);
        _rev_thread.resize(all_node_num);
        _succ_num.resize(all_node_num);
        _last_succ.resize(all_node_num);
        _state.resize(max_arc_num);

        for (int a = 0; a < _arc_num; ++a) {
            _source[a] = _graph.source(a);
            _target[a] = _graph.target(a);
        }
        

        resetParams();
        return *this;
    }

    


    template <typename Number = Cost> Number totalCost() const {
        Number c = 0;
        for (Arc a = 0; a < _arc_num; a++) c += Number(_flow[a]) * Number(_cost[a]);
        return c;
    }

    Value flow(const Arc &a) const { return _flow[a]; }
    template <typename FlowMap> void flowMap(FlowMap &map) const {
        for (Arc a = 0; a < _arc_num; a++) { map.set(a, _flow[a]); }
    }
    ValueVector flowMap() const { return _flow; }

    Cost potential(const Node &n) const { return _pi[n]; }
    template <typename PotentialMap> void potentialMap(PotentialMap &map) const {
        for (int n = 0; n < _graph.V; n++) { map.set(n, _pi[n]); }
    }
    CostVector potentialMap() const { return _pi; }

private:
    

    bool init() {
        if (_node_num == 0) return false;

        

        _sum_supply = 0;
        for (int i = 0; i != _node_num; ++i) { _sum_supply += _supply[i]; }
        if (!((_stype == GEQ && _sum_supply <= 0) || (_stype == LEQ && _sum_supply >= 0))) return false;

        

        


        

        if (_has_lower) {
            for (int i = 0; i != _arc_num; ++i) {
                Value c = _lower[i];
                if (c >= 0) {
                    _cap[i] = _upper[i] < MAX ? _upper[i] - c : INF;
                } else {
                    _cap[i] = _upper[i] < MAX + c ? _upper[i] - c : INF;
                }
                _supply[_source[i]] -= c;
                _supply[_target[i]] += c;
            }
        } else {
            for (int i = 0; i != _arc_num; ++i) { _cap[i] = _upper[i]; }
        }

        

        Cost ART_COST;
        if (true) {
            ART_COST = std::numeric_limits<Cost>::max() / 2 + 1;
        } else {
            ART_COST = 0;
            for (int i = 0; i != _arc_num; ++i) {
                if (_cost[i] > ART_COST) ART_COST = _cost[i];
            }
            ART_COST = (ART_COST + 1) * _node_num;
        }

        

        for (int i = 0; i != _arc_num; ++i) {
            _flow[i] = 0;
            _state[i] = STATE_LOWER;
        }

        

        _root = _node_num;
        _parent[_root] = -1;
        _pred[_root] = -1;
        _thread[_root] = 0;
        _rev_thread[0] = _root;
        _succ_num[_root] = _node_num + 1;
        _last_succ[_root] = _root - 1;
        _supply[_root] = -_sum_supply;
        _pi[_root] = 0;

        

        if (_sum_supply == 0) {
            

            _search_arc_num = _arc_num;
            _all_arc_num = _arc_num + _node_num;
            for (int u = 0, e = _arc_num; u != _node_num; ++u, ++e) {
                _parent[u] = _root;
                _pred[u] = e;
                _thread[u] = u + 1;
                _rev_thread[u + 1] = u;
                _succ_num[u] = 1;
                _last_succ[u] = u;
                _cap[e] = INF;
                _state[e] = STATE_TREE;
                if (_supply[u] >= 0) {
                    _pred_dir[u] = DIR_UP;
                    _pi[u] = 0;
                    _source[e] = u;
                    _target[e] = _root;
                    _flow[e] = _supply[u];
                    _cost[e] = 0;
                } else {
                    _pred_dir[u] = DIR_DOWN;
                    _pi[u] = ART_COST;
                    _source[e] = _root;
                    _target[e] = u;
                    _flow[e] = -_supply[u];
                    _cost[e] = ART_COST;
                }
            }
        } else if (_sum_supply > 0) {
            

            _search_arc_num = _arc_num + _node_num;
            int f = _arc_num + _node_num;
            for (int u = 0, e = _arc_num; u != _node_num; ++u, ++e) {
                _parent[u] = _root;
                _thread[u] = u + 1;
                _rev_thread[u + 1] = u;
                _succ_num[u] = 1;
                _last_succ[u] = u;
                if (_supply[u] >= 0) {
                    _pred_dir[u] = DIR_UP;
                    _pi[u] = 0;
                    _pred[u] = e;
                    _source[e] = u;
                    _target[e] = _root;
                    _cap[e] = INF;
                    _flow[e] = _supply[u];
                    _cost[e] = 0;
                    _state[e] = STATE_TREE;
                } else {
                    _pred_dir[u] = DIR_DOWN;
                    _pi[u] = ART_COST;
                    _pred[u] = f;
                    _source[f] = _root;
                    _target[f] = u;
                    _cap[f] = INF;
                    _flow[f] = -_supply[u];
                    _cost[f] = ART_COST;
                    _state[f] = STATE_TREE;
                    _source[e] = u;
                    _target[e] = _root;
                    _cap[e] = INF;
                    _flow[e] = 0;
                    _cost[e] = 0;
                    _state[e] = STATE_LOWER;
                    ++f;
                }
            }
            _all_arc_num = f;
        } else {
            

            _search_arc_num = _arc_num + _node_num;
            int f = _arc_num + _node_num;
            for (int u = 0, e = _arc_num; u != _node_num; ++u, ++e) {
                _parent[u] = _root;
                _thread[u] = u + 1;
                _rev_thread[u + 1] = u;
                _succ_num[u] = 1;
                _last_succ[u] = u;
                if (_supply[u] <= 0) {
                    _pred_dir[u] = DIR_DOWN;
                    _pi[u] = 0;
                    _pred[u] = e;
                    _source[e] = _root;
                    _target[e] = u;
                    _cap[e] = INF;
                    _flow[e] = -_supply[u];
                    _cost[e] = 0;
                    _state[e] = STATE_TREE;
                } else {
                    _pred_dir[u] = DIR_UP;
                    _pi[u] = -ART_COST;
                    _pred[u] = f;
                    _source[f] = u;
                    _target[f] = _root;
                    _cap[f] = INF;
                    _flow[f] = _supply[u];
                    _state[f] = STATE_TREE;
                    _cost[f] = ART_COST;
                    _source[e] = _root;
                    _target[e] = u;
                    _cap[e] = INF;
                    _flow[e] = 0;
                    _cost[e] = 0;
                    _state[e] = STATE_LOWER;
                    ++f;
                }
            }
            _all_arc_num = f;
        }

        return true;
    }

    

    

    bool checkBoundMaps() {
        for (int j = 0; j != _arc_num; ++j) {
            if (_upper[j] < _lower[j]) return false;
        }
        return true;
    }

    

    void findJoinNode() {
        int u = _source[in_arc];
        int v = _target[in_arc];
        while (u != v) {
            if (_succ_num[u] < _succ_num[v]) {
                u = _parent[u];
            } else {
                v = _parent[v];
            }
        }
        join = u;
    }

    

    

    bool findLeavingArc() {
        

        

        int first, second;
        if (_state[in_arc] == STATE_LOWER) {
            first = _source[in_arc];
            second = _target[in_arc];
        } else {
            first = _target[in_arc];
            second = _source[in_arc];
        }
        delta = _cap[in_arc];
        int result = 0;
        Value c, d;
        int e;

        

        for (int u = first; u != join; u = _parent[u]) {
            e = _pred[u];
            d = _flow[e];
            if (_pred_dir[u] == DIR_DOWN) {
                c = _cap[e];
                d = c >= MAX ? INF : c - d;
            }
            if (d < delta) {
                delta = d;
                u_out = u;
                result = 1;
            }
        }

        

        for (int u = second; u != join; u = _parent[u]) {
            e = _pred[u];
            d = _flow[e];
            if (_pred_dir[u] == DIR_UP) {
                c = _cap[e];
                d = c >= MAX ? INF : c - d;
            }
            if (d <= delta) {
                delta = d;
                u_out = u;
                result = 2;
            }
        }

        if (result == 1) {
            u_in = first;
            v_in = second;
        } else {
            u_in = second;
            v_in = first;
        }
        return result != 0;
    }

    

    void changeFlow(bool change) {
        

        if (delta > 0) {
            Value val = _state[in_arc] * delta;
            _flow[in_arc] += val;
            for (int u = _source[in_arc]; u != join; u = _parent[u]) {
                _flow[_pred[u]] -= _pred_dir[u] * val;
            }
            for (int u = _target[in_arc]; u != join; u = _parent[u]) {
                _flow[_pred[u]] += _pred_dir[u] * val;
            }
        }
        

        if (change) {
            _state[in_arc] = STATE_TREE;
            _state[_pred[u_out]] = (_flow[_pred[u_out]] == 0) ? STATE_LOWER : STATE_UPPER;
        } else {
            _state[in_arc] = -_state[in_arc];
        }
    }

    

    void updateTreeStructure() {
        int old_rev_thread = _rev_thread[u_out];
        int old_succ_num = _succ_num[u_out];
        int old_last_succ = _last_succ[u_out];
        v_out = _parent[u_out];

        

        if (u_in == u_out) {
            

            _parent[u_in] = v_in;
            _pred[u_in] = in_arc;
            _pred_dir[u_in] = u_in == _source[in_arc] ? DIR_UP : DIR_DOWN;

            

            if (_thread[v_in] != u_out) {
                int after = _thread[old_last_succ];
                _thread[old_rev_thread] = after;
                _rev_thread[after] = old_rev_thread;
                after = _thread[v_in];
                _thread[v_in] = u_out;
                _rev_thread[u_out] = v_in;
                _thread[old_last_succ] = after;
                _rev_thread[after] = old_last_succ;
            }
        } else {
            

            

            int thread_continue = old_rev_thread == v_in ? _thread[old_last_succ] : _thread[v_in];

            

            

            int stem = u_in;             

            int par_stem = v_in;         

            int next_stem;               

            int last = _last_succ[u_in]; 

            int before, after = _thread[last];
            _thread[v_in] = u_in;
            _dirty_revs.clear();
            _dirty_revs.push_back(v_in);
            while (stem != u_out) {
                

                next_stem = _parent[stem];
                _thread[last] = next_stem;
                _dirty_revs.push_back(last);

                

                before = _rev_thread[stem];
                _thread[before] = after;
                _rev_thread[after] = before;

                

                _parent[stem] = par_stem;
                par_stem = stem;
                stem = next_stem;

                

                last = _last_succ[stem] == _last_succ[par_stem] ? _rev_thread[par_stem] : _last_succ[stem];
                after = _thread[last];
            }
            _parent[u_out] = par_stem;
            _thread[last] = thread_continue;
            _rev_thread[thread_continue] = last;
            _last_succ[u_out] = last;

            

            

            if (old_rev_thread != v_in) {
                _thread[old_rev_thread] = after;
                _rev_thread[after] = old_rev_thread;
            }

            

            for (int i = 0; i != int(_dirty_revs.size()); ++i) {
                int u = _dirty_revs[i];
                _rev_thread[_thread[u]] = u;
            }

            

            

            int tmp_sc = 0, tmp_ls = _last_succ[u_out];
            for (int u = u_out, p = _parent[u]; u != u_in; u = p, p = _parent[u]) {
                _pred[u] = _pred[p];
                _pred_dir[u] = -_pred_dir[p];
                tmp_sc += _succ_num[u] - _succ_num[p];
                _succ_num[u] = tmp_sc;
                _last_succ[p] = tmp_ls;
            }
            _pred[u_in] = in_arc;
            _pred_dir[u_in] = u_in == _source[in_arc] ? DIR_UP : DIR_DOWN;
            _succ_num[u_in] = old_succ_num;
        }

        

        int up_limit_out = _last_succ[join] == v_in ? join : -1;
        int last_succ_out = _last_succ[u_out];
        for (int u = v_in; u != -1 && _last_succ[u] == v_in; u = _parent[u]) {
            _last_succ[u] = last_succ_out;
        }

        

        if (join != old_rev_thread && v_in != old_rev_thread) {
            for (int u = v_out; u != up_limit_out && _last_succ[u] == old_last_succ; u = _parent[u]) {
                _last_succ[u] = old_rev_thread;
            }
        } else if (last_succ_out != old_last_succ) {
            for (int u = v_out; u != up_limit_out && _last_succ[u] == old_last_succ; u = _parent[u]) {
                _last_succ[u] = last_succ_out;
            }
        }

        

        for (int u = v_in; u != join; u = _parent[u]) { _succ_num[u] += old_succ_num; }
        

        for (int u = v_out; u != join; u = _parent[u]) { _succ_num[u] -= old_succ_num; }
    }

    

    void updatePotential() {
        Cost sigma = _pi[v_in] - _pi[u_in] - _pred_dir[u_in] * _cost[in_arc];
        int end = _thread[_last_succ[u_in]];
        for (int u = u_in; u != end; u = _thread[u]) { _pi[u] += sigma; }
    }

    

    bool initialPivots() {
        Value curr, total = 0;
        std::vector<Node> supply_nodes, demand_nodes;
        for (int u = 0; u < _node_num; ++u) {
            curr = _supply[u];
            if (curr > 0) {
                total += curr;
                supply_nodes.push_back(u);
            } else if (curr < 0) {
                demand_nodes.push_back(u);
            }
        }
        if (_sum_supply > 0) total -= _sum_supply;
        if (total <= 0) return true;

        IntVector arc_vector;
        if (_sum_supply >= 0) {
            if (supply_nodes.size() == 1 && demand_nodes.size() == 1) {
                

                std::vector<char> reached(_node_num, false);
                Node s = supply_nodes[0], t = demand_nodes[0];
                std::vector<Node> stack;
                reached[t] = true;
                stack.push_back(t);
                while (!stack.empty()) {
                    Node u, v = stack.back();
                    stack.pop_back();
                    if (v == s) break;
                    

                    for (auto a : _graph.in_eids[v]) {
                        if (reached[u = _graph.source(a)]) continue;
                        int j = a;
                        if (_cap[j] >= total) {
                            arc_vector.push_back(j);
                            reached[u] = true;
                            stack.push_back(u);
                        }
                    }
                }
            } else {
                

                for (int i = 0; i != int(demand_nodes.size()); ++i) {
                    Node v = demand_nodes[i];
                    Cost c, min_cost = std::numeric_limits<Cost>::max();
                    Arc min_arc = INVALID;
                    for (auto a : _graph.in_eids[v]) {
                        

                        c = _cost[a];
                        if (c < min_cost) {
                            min_cost = c;
                            min_arc = a;
                        }
                    }
                    if (min_arc != INVALID) { arc_vector.push_back(min_arc); }
                }
            }
        } else {
            

            for (Node u : supply_nodes) {
                Cost c, min_cost = std::numeric_limits<Cost>::max();
                Arc min_arc = INVALID;
                for (auto a : _graph.out_eids[u]) {
                    c = _cost[a];
                    if (c < min_cost) {
                        min_cost = c;
                        min_arc = a;
                    }
                }
                if (min_arc != INVALID) { arc_vector.push_back(min_arc); }
            }
        }

        

        for (int i = 0; i != int(arc_vector.size()); ++i) {
            in_arc = arc_vector[i];
            if (_state[in_arc] * (_cost[in_arc] + _pi[_source[in_arc]] - _pi[_target[in_arc]]) >= 0) continue;
            findJoinNode();
            bool change = findLeavingArc();
            if (delta >= MAX) return false;
            changeFlow(change);
            if (change) {
                updateTreeStructure();
                updatePotential();
            }
        }
        return true;
    }

    

    ProblemType start(PivotRule pivot_rule) {
        

        switch (pivot_rule) {
        case FIRST_ELIGIBLE: return start<FirstEligiblePivotRule>();
        case BEST_ELIGIBLE: return start<BestEligiblePivotRule>();
        case BLOCK_SEARCH: return start<BlockSearchPivotRule>();
        case CANDIDATE_LIST: return start<CandidateListPivotRule>();
        case ALTERING_LIST: return start<AlteringListPivotRule>();
        }
        return INFEASIBLE; 

    }

    template <typename PivotRuleImpl> ProblemType start() {
        PivotRuleImpl pivot(*this);

        

        if (!initialPivots()) return UNBOUNDED;

        

        while (pivot.findEnteringArc()) {
            findJoinNode();
            bool change = findLeavingArc();
            if (delta >= MAX) return UNBOUNDED;
            changeFlow(change);
            if (change) {
                updateTreeStructure();
                updatePotential();
            }
        }

        

        for (int e = _search_arc_num; e != _all_arc_num; ++e) {
            if (_flow[e] != 0) return INFEASIBLE;
        }

        

        if (_has_lower) {
            for (int i = 0; i != _arc_num; ++i) {
                Value c = _lower[i];
                if (c != 0) {
                    _flow[i] += c;
                    _supply[_source[i]] += c;
                    _supply[_target[i]] -= c;
                }
            }
        }

        

        

        if (_sum_supply == 0) {
            if (_stype == GEQ) {
                Cost max_pot = -std::numeric_limits<Cost>::max();
                for (int i = 0; i != _node_num; ++i) {
                    if (_pi[i] > max_pot) max_pot = _pi[i];
                }
                if (max_pot > 0) {
                    for (int i = 0; i != _node_num; ++i) _pi[i] -= max_pot;
                }
            } else {
                Cost min_pot = std::numeric_limits<Cost>::max();
                for (int i = 0; i != _node_num; ++i) {
                    if (_pi[i] < min_pot) min_pot = _pi[i];
                }
                if (min_pot < 0) {
                    for (int i = 0; i != _node_num; ++i) _pi[i] -= min_pot;
                }
            }
        }

        return OPTIMAL;
    }
}; 


template <typename Capacity = long long, typename Weight = long long> struct mcf_graph_ns {

    struct Digraph {
        const int V;
        int E;
        std::vector<std::vector<int>> in_eids, out_eids;
        std::vector<std::pair<int, int>> arcs;
        Digraph(int V = 0) : V(V), E(0), in_eids(V), out_eids(V){};
        int add_edge(int s, int t) {
            assert(0 <= s and s < V);
            assert(0 <= t and t < V);
            in_eids[t].push_back(E), out_eids[s].push_back(E), arcs.emplace_back(s, t), E++;
            return E - 1;
        }
        int countNodes() const noexcept { return V; }
        int countArcs() const noexcept { return E; }
        int source(int arcid) const { return arcs[arcid].first; }
        int target(int arcid) const { return arcs[arcid].second; }
    };

    struct edge {
        int eid;
        int from, to;
        Capacity lo, hi;
        Weight weight;
    };

    int n;
    std::vector<Capacity> bs;
    bool infeasible;
    std::vector<edge> Edges;

    mcf_graph_ns(int V = 0) : n(V), bs(V), infeasible(false) {}

    int add_edge(int from, int to, Capacity lower, Capacity upper, Weight weight) {
        assert(from >= 0 and from < n);
        assert(to >= 0 and to < n);
        int idnow = Edges.size();
        Edges.push_back({idnow, from, to, lower, upper, weight});
        return idnow;
    }
    void set_supply(int v, Capacity b) {
        assert(v >= 0 and v < n);
        bs[v] = b;
    }
    std::vector<Capacity> flow;
    std::vector<Capacity> potential;

    template <typename RetVal = __int128> [[nodiscard]] RetVal solve() {
        std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

        std::vector<int> vid(n), eid(Edges.size());
        std::iota(vid.begin(), vid.end(), 0);
        std::shuffle(vid.begin(), vid.end(), rng);
        std::iota(eid.begin(), eid.end(), 0);
        std::shuffle(eid.begin(), eid.end(), rng);

        flow.clear();
        potential.clear();
        Digraph graph(n + 1);

        std::vector<Capacity> supplies(graph.countNodes());
        std::vector<Capacity> lowers(Edges.size());
        std::vector<Capacity> uppers(Edges.size());
        std::vector<Weight> weights(Edges.size());

        for (int i = 0; i < n; i++) supplies[vid[i]] = bs[i];
        for (auto i : eid) {
            const auto &e = Edges[i];
            int arc = graph.add_edge(vid[e.from], vid[e.to]);
            lowers[arc] = e.lo;
            uppers[arc] = e.hi;
            weights[arc] = e.weight;
        }

        NetworkSimplex<Digraph, Capacity, Weight> ns(graph);
        auto status = ns.supplyMap(supplies).costMap(weights).lowerMap(lowers).upperMap(uppers).run(decltype(ns)::BLOCK_SEARCH);

        if (status == decltype(ns)::INFEASIBLE) {
            return infeasible = true, 0;
        } else {
            flow.resize(Edges.size());
            potential.resize(n);
            for (int i = 0; i < int(Edges.size()); i++) flow[eid[i]] = ns.flow(i);
            for (int i = 0; i < n; i++) potential[i] = ns.potential(vid[i]);
            return ns.template totalCost<RetVal>();
        }
    }
};


int main() {
    int N, M;
    cin >> N >> M;
    vector<lint> A(N);
    cin >> A;
    constexpr lint inf = 1LL << 60;
    const int g0 = N;
    mcf_graph_ns<lint, __int128> graph(g0 + 1);

    REP(i, N) {
        graph.add_edge(g0, i, 0, 1, 0);
        graph.add_edge(i, g0, 0, 1, 0);
    }
    while (M--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph.add_edge(v, u, 0, 1LL << 60, A[v] - A[u]);
    }
    graph.solve();
    

    vector<lint> ret(N);
    REP(i, N) {
        ret[i] = A[i] + (graph.potential[i] - graph.potential[N]);
    }
    for (auto x : ret) cout << x << ' ';
    cout << endl;
}
