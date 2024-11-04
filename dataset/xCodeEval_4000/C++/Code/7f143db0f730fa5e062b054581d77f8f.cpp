#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
template <typename T> inline void read(T &FF) {
    int RR = 1; FF = 0; char CH = getchar();
    for(; !isdigit(CH); CH = getchar()) if(CH == '-') RR = -RR;
    for(; isdigit(CH); CH = getchar()) FF = FF * 10 + CH - 48;
    FF *= RR;
}
inline void file(string str) {
    freopen((str + ".in").c_str(), "r", stdin);
    freopen((str + ".out").c_str(), "w", stdout);
}
std :: mt19937 _Rand(std :: chrono :: steady_clock :: now().time_since_epoch().count());
template<typename _Key> class treap {
    public:
    typedef unsigned long long LL;
    struct _Node {
        LL _Size, _Cnt;
	    struct _Node* _Son[2];
        _Key _Value;
        unsigned int _Order;
    };
    
    _Node* _Root = nullptr;
    _Node* _New_Node(const _Key &_V, LL _Cnt) {
		auto _It = new _Node;
		_It -> _Cnt = _It -> _Size = _Cnt;
        _It -> _Value = _V;
        _It -> _Son[0] = _It -> _Son[1] = nullptr;
        _It -> _Order = _Rand();
		return _It;
	}
    LL _Get_Size(_Node* _T) {
        return _T == nullptr ? 0 : _T -> _Size;
    }
    void _Push_Up(_Node* _T) {
        _T -> _Size = _Get_Size(_T -> _Son[0]) + _Get_Size(_T -> _Son[1]) + _T -> _Cnt;
    }
    std :: array<_Node*, 2> _Split(_Node* _T, const _Key &_V) {
        if(_T == nullptr) return {nullptr, nullptr};
        if(_T -> _Value < _V) {
            auto _It = _Split(_T -> _Son[1], _V);
            _T -> _Son[1] = _It[0]; _Push_Up(_T);
            return {_T, _It[1]};
        }
        auto _It = _Split(_T -> _Son[0], _V);
        _T -> _Son[0] = _It[1]; _Push_Up(_T);
        return {_It[0], _T};
    }
    std :: array<_Node*, 2> _SplitX(_Node* _T, const _Key &_V) {
        if(_T == nullptr) return {nullptr, nullptr};
        if(_V < _T -> _Value) {
            auto _It = _Split(_T -> _Son[0], _V);
            _T -> _Son[0] = _It[1]; _Push_Up(_T);
            return {_It[0], _T};
        }
        auto _It = _Split(_T -> _Son[1], _V);
        _T -> _Son[1] = _It[0]; _Push_Up(_T);
        return {_T, _It[1]};
    }
    _Node* _Merge(_Node* _X, _Node* _Y) {
        if(_X == nullptr) return _Y;
        if(_Y == nullptr) return _X;
        if(_X -> _Order > _Y -> _Order) {
            _X -> _Son[1] = _Merge(_X -> _Son[1], _Y);
            _Push_Up(_X);
            return _X;
        }
        _Y -> _Son[0] = _Merge(_X, _Y -> _Son[0]);
        _Push_Up(_Y);
        return _Y;
    }
    _Node* _Find(const _Key &_Value) {
        _Node* _P = _Root;
        while(_P != nullptr) {
            if(_Value < _P -> _Value)
                _P = _P -> _Son[0];
            else if(_P -> _Value < _Value)
                _P = _P -> _Son[1];
            else break;
        }
        return _P;
    }
    void _Push_Down(const _Key &_Value, const LL &_Cnt) {
        _Node* _P = _Root;
        while(_P != nullptr) {
            _P -> _Size += _Cnt;
            if(_Value < _P -> _Value) _P = _P -> _Son[0];
            else if(_P -> _Value < _Value) _P = _P -> _Son[1];
            else {
                _P -> _Cnt += _Cnt;
                break;
            }
        }
    }
    void _Ins(_Node* _Y) {
        _Node* _X = _Root; _Node* *_P = &_Root;
        LL _Cnt = _Y -> _Cnt; _Key _Value = _Y -> _Value;
        unsigned int _Order = _Y -> _Order;
        while(_X != nullptr) {
            if(_Order > _X -> _Order) {
                _Y -> _Size += _X -> _Size;
                auto _It = _Split(_X, _Value);
                _Y -> _Son[0] = _It[0];  
                _Y -> _Son[1] = _It[1];
                *_P = _Y; break;
            }
            _X -> _Size += _Cnt; *_P = _X;
            if(_Value < _X -> _Value)
                _P = &(_X -> _Son[0]), _X = *_P;
            else _P = &(_X -> _Son[1]), _X = *_P;
        }
        if(_X == nullptr) *_P = _Y;
    }
    void _clear(_Node* _X) {
        if(_X == nullptr) return;
        _clear(_X -> _Son[0]);
        _clear(_X -> _Son[1]);
        delete _X;
    }
    _Node* _Copy_Node(_Node* _X) {
        if(_X == nullptr) return nullptr;
        auto _It = new _Node; (*_It) = (*_X);
		_It -> _Son[0] = _Copy_Node(_X -> _Son[0]);
        _It -> _Son[1] = _Copy_Node(_X -> _Son[1]);
        return _It;
    }
    _Node* _Join(_Node* _X, _Node* _Y) {
        if(_X == nullptr) return _Y;
        if(_Y == nullptr) return _X;
        if(_X -> _Order < _Y -> _Order) std :: swap(_X, _Y);
        auto _P = _SplitX(_Y, _X -> _Value), _Q = _Split(_P[0], _X -> _Value);
        if(_Q[1] != nullptr) _X -> _Cnt += _Q[1] -> _Cnt;
        _X -> _Son[0] = _Join(_X -> _Son[0], _Q[0]);
        _X -> _Son[1] = _Join(_X -> _Son[1], _P[1]);
        _Push_Up(_X); return _X;
    }
    public :
    class iterator {
        struct _List {
            treap<_Key>* _Tr;
            _Node* _It;
            _Key first; LL second;
            void _flush() {
                if(_It == nullptr) first = second = 0;
                else first = _It -> _Value, second = _It -> _Cnt;
            }
        }_T;
        public:
        iterator(treap<_Key>* _R, _Node* _X) {_T._Tr = _R, _T._It = _X;}
        bool operator == (iterator _X) {
            return _T._It == _X -> _It;
        }
        bool operator != (iterator _X) {
            return _T._It != _X -> _It;
        }
        _List* operator -> () {
            _T._flush();
            return &_T;
        }
        _List operator * () {
            _T._flush();
            return _T;
        }
        iterator& operator ++ () {
            if(_T._It == nullptr) return *this;
            (*this) = (*(_T._Tr)).upper_bound(_T._It -> _Value);
            return *this;
        }
        iterator operator ++ (int) {
            if(_T._It == nullptr) return *this;
            auto _It = *this;
            (*this) = (*(_T._Tr)).upper_bound(_T._It -> _Value);
            return _It;
        }
        iterator& operator -- () {
            LL _Rank = 0;
            if(_T._It == nullptr) _Rank = (*(_T._Tr)).size();
            else _Rank = (*(_T._Tr)).order_of_key(_T._It -> _Value);
            if(!_Rank) _T._It = nullptr;
            else (*this) = (*(_T._Tr)).find_by_order(_Rank - 1);
            return *this;
        }
        iterator operator -- (int) {
            LL _Rank = 0; auto _It = *this;
            if(_T._It == nullptr) _Rank = (*(_T._Tr)).size();
            else _Rank = (*(_T._Tr)).order_of_key(_T._It -> _Value);
            if(!_Rank) _T._It = nullptr;
            else (*this) = (*(_T._Tr)).find_by_order(_Rank - 1);
            return _It;
        }
    };
    private:
    iterator _Packup(_Node* _X) {
        iterator _It(this, _X);
        return _It;
    }
    public:
    iterator insert(const _Key &_Value, const LL &_Cnt = 1) {
        assert(_Cnt >= 0);
        if(!_Cnt) return end();
        auto _It = _Find(_Value);
        if(_It == nullptr) {
            _It = _New_Node(_Value, _Cnt);
            _Ins(_It);
        }
        else _Push_Down(_Value, _Cnt);
        return _Packup(_It);
    }
    void erase(const _Key &_Value, LL _Cnt = 1) {
        assert(_Cnt >= 0);
        if(!_Cnt) return;
        _Cnt = std :: min(_Cnt, count(_Value));
        if(!_Cnt) return;
        _Node* _P = _Root; _Node* *_Q = &_Root;
        while(_P != nullptr) {
            _P -> _Size -= _Cnt;
            if(_Value < _P -> _Value) {
                _Q = &(_P -> _Son[0]), _P = *_Q;
            }
            else if(_P -> _Value < _Value) {
                _Q = &(_P -> _Son[1]), _P = *_Q;
            }
            else {
                _P -> _Cnt -= _Cnt;
                break;
            }
        }
        if(!_P -> _Cnt) {
            *_Q = _Merge(_P -> _Son[0], _P -> _Son[1]);
            delete _P;
        }
    }
    void erase(iterator _It) {
        if(_It == end()) return;
        erase(_It -> first, _It -> second);
    }
    LL size() {
        if(_Root == nullptr) return 0;
        return _Root -> _Size;
    }
    iterator find_by_order(LL _Rank) {
        assert(_Rank >= 0 && _Rank < size());
        _Node* _P = _Root; _Rank++;
        while(true) {
            LL _Size = _Get_Size(_P -> _Son[0]);
            if(_Rank <= _Size) _P = _P -> _Son[0];
            else if(_Rank > _Size + _P -> _Cnt) _Rank -= _Size + _P -> _Cnt, _P = _P -> _Son[1];
            else return _Packup(_P);
        }
    }
    LL count(const _Key &_Value) {
        auto _It = _Find(_Value);
        if(_It == nullptr) return 0;
        return _It -> _Cnt;
    }
    iterator find(const _Key &_Value) {
        auto _It = _Find(_Value);
        return _Packup(_It);
    }
    LL order_of_key(const _Key &_Value) {
        _Node* _P = _Root; LL _Rank = 0;
        while(_P != nullptr) {
            if(_Value < _P -> _Value) _P = _P -> _Son[0];
            else if(_P -> _Value < _Value) _Rank += _Get_Size(_P -> _Son[0]) + _P -> _Cnt, _P = _P -> _Son[1];
            else {
                _Rank += _Get_Size(_P -> _Son[0]);
                break;
            }
        }
        return _Rank;
    }
    LL order_of_key(iterator _It) {
        if(_It == end()) return size();
        _Key _Value = _It -> first;
        _Node* _P = _Root; LL _Rank = 0;
        while(_P != nullptr) {
            if(_Value < _P -> _Value) _P = _P -> _Son[0];
            else if(_P -> _Value < _Value) _Rank += _Get_Size(_P -> _Son[0]) + _P -> _Cnt, _P = _P -> _Son[1];
            else {
                _Rank += _Get_Size(_P -> _Son[0]);
                break;
            }
        }
        return _Rank;
    }
    _Key operator [] (LL _Rank) {
        assert(_Rank >= 0 && _Rank < size());
        return find_by_order(_Rank) -> first;
    }
    void clear() {
        _clear(_Root);
        _Root = nullptr;
    }
    iterator begin() {
        _Node *_P = _Root, *_Q = _Root;
        while(_P != nullptr) {
            _Q = _P;
            _P = _P -> _Son[0];
        } 
        return _Packup(_Q);
    }
    iterator end() {
        _Node* _It = nullptr;
        return _Packup(_It);
    }
    iterator lower_bound(const _Key &_Value) {
        LL _Rank = order_of_key(_Value);
        if(_Rank == size()) return end();
        return find_by_order(_Rank);
    }
    iterator upper_bound(const _Key &_Value) {
        _Node* _P = _Root; LL _Rank = 0;
        while(_P != nullptr) {
            if(_Value < _P -> _Value) _P = _P -> _Son[0];
            else if(_P -> _Value < _Value) _Rank += _Get_Size(_P -> _Son[0]) + _P -> _Cnt, _P = _P -> _Son[1];
            else {
                _Rank += _Get_Size(_P -> _Son[0])  + _P -> _Cnt;
                break;
            }
        }
        if(_Rank == size()) return end();
        return find_by_order(_Rank);
    }
    bool empty() {
        return _Root == nullptr;
    }
    treap<_Key>& operator = (const treap<_Key> &_Tr) {
        if(&_Tr == this) return *this;
        _Root = _Copy_Node(_Tr._Root);
        return *this;
    }
    _Key front() {
        _Node *_P = _Root, *_Q = _Root;
        while(_P != nullptr) {
            _Q = _P;
            _P = _P -> _Son[0];
        } 
        return _Q -> _Value;
    }
    _Key back() {
        _Node *_P = _Root, *_Q = _Root;
        while(_P != nullptr) {
            _Q = _P;
            _P = _P -> _Son[1];
        } 
        return _Q -> _Value;
    }
    void join(treap<_Key> &_Tr) {
        _Root = _Join(_Root, _Tr._Root);
        _Tr._Root = nullptr;
    }
    treap<_Key> split(const _Key &_Value) {
        auto _P = _Split(_Root, _Value);
        _Root = _P[0];
        treap<_Key> _Tr;
        _Tr._Root = _P[1];
        return _Tr;
    }
    treap<_Key> split(iterator _It) {
        if(_It == end()) {
            treap<_Key> _Tr;
            return _Tr;
        }
        return split(_It -> first);
    }
    treap<_Key> () : _Root(nullptr) {}
    treap<_Key> (const treap<_Key> &_Tr) {(*this) = _Tr;}
    ~treap<_Key>() {clear();}
};
const int N = 2e5 + 10;
int n, k, now, fst[N], nxt[N << 1], num[N << 1], deg[N];
void add(int u, int v) {
    nxt[++now] = fst[u], fst[u] = now, num[now] = v;
    nxt[++now] = fst[v], fst[v] = now, num[now] = u;
}

treap<int> q[N];
void solve(int x, int fa) {
    if(deg[x] == 1 && x != 1) {
        q[x].insert(1);
        return;
    }
    for(int i = fst[x]; i; i = nxt[i]) {
        if(num[i] == fa) continue;
        solve(num[i], x);
        q[x].join(q[num[i]]);
    }
    int p = q[x].back() + 1;
    q[x].erase(q[x].back()); q[x].insert(p);
}
int main() {
    

    read(n), read(k);
    for(int i = 1; i < n; i++) {
        int u, v; read(u), read(v); deg[u]++, deg[v]++;
        add(u, v);
    }
    solve(1, 0); LL t = -(n / 2) * 1LL * (n - n / 2), ans = t;
    LL r = 0;
    for(int i = 1; i <= k; i++) {
        if(!q[1].empty()) {
            r += q[1].back(); q[1].erase(q[1].back());
        }
        LL res = 0;
        if(n - r >= n / 2) res = t;
        else res = -(n - r) * r;
        res += i * 1LL * (n - i);
        

        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}