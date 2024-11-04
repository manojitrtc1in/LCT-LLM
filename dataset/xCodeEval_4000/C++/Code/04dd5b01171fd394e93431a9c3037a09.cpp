#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int CH_SIZE = 8;
const int LOG_CH = 3;

uint32_t xor128(){
    static uint32_t x = 123456789;
  static uint32_t y = 362436069;
  static uint32_t z = 521288629;
  static uint32_t w = 88675123;
  uint32_t t;

  t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

struct node{
    node *l,*r;
    int cnt;
    int v;
};


const int POOL_SIZE=20000000;
node pool[POOL_SIZE];
int tail;
node *alloc(){
    assert(tail<POOL_SIZE);
    return &pool[tail++];
}

inline int count(node *t){
    return t?t->cnt:0;
}

inline node *update(node *t){
    if(!t)return t;
    t->cnt=count(t->l)+1+count(t->r);
    return t;
}

node *merge(node *a,node *b){
    if(!a)return b;
    if(!b)return a;

    if(xor128()%(count(a)+count(b))<count(a)){
         node *x=alloc();
         x->v=a->v;
         x->l=a->l;
         x->r=merge(a->r,b);
         return update(x);
    }
    else{
        node *x=alloc();
        x->v=b->v;
        x->r=b->r;
        x->l=merge(a,b->l);
        return update(x);
    }
}

pair<node *,node *>split(node *t,int k){
    if(!t)return {(node *)NULL,(node *)NULL};
    if(k<=count(t->l)){
        pair<node *,node *>s=split(t->l,k);
        node *x=alloc();
        x->v=t->v;
        x->r=t->r;
        x->l=s.second;
        return {s.first,update(x)};
    }
    else{
        pair<node *,node *>s=split(t->r,k-count(t->l)-1);
        node *x=alloc();
        x->v=t->v;
        x->l=t->l;
        x->r=s.first;
        return {update(x),s.second};
    }
}

node *root[111111];


int lb(node *t,int k){
    if(!t)return 0;
    if(t->v<k){
        return 1+count(t->l)+lb(t->r,k);
    }
    return lb(t->l,k);
}

int ub(node *t,int k){
    if(!t)return 0;
    if(t->v<=k){
        return 1+count(t->l)+ub(t->r,k);
    }
    return ub(t->l,k);
}

node *ins(node *t,int v){
    int c=lb(t,v);
    pair<node *,node *>s=split(t,c);

    node *x=alloc();
    x->v=v;
    x->l=x->r=NULL;
    x->cnt=1;
    return merge(s.first,merge(x,s.second));
}

node *er(node *t,int v){
    int c=lb(t,v);
    pair<node *,node *>s1=split(t,c);
    pair<node *,node *>s2=split(s1.second,1);
    return merge(s1.first,s2.second);
}

template<class T>
class Array {
public:
	Array() {}

	Array(int n) {
		h = 0;
		for (int i = 1; i < n; i *= CH_SIZE) h += LOG_CH;
	}

	T *mutable_get(int k) {
		auto p = mutable_get(k, root, 0, h);
		root = p.first;
		return &p.second->value;
	}

	T immutable_get(int k) {
		return immutable_get(k, root, 0, h)->value;
	}

private:
	struct node {
		node *ch[CH_SIZE] = {};
		T value;

		node() {}
		node(T value) : value(value) {}
	};

	int h;
	node *root = nullptr;

	node *immutable_get(int a, node *x, int l, int d) {
		if (d == 0) return x;
		int id = (a - l) >> (d - LOG_CH);
		return immutable_get(a, x->ch[id], l + (id << (d - LOG_CH)), d - LOG_CH);
	}

	pair<node *, node *> mutable_get(int a, node *x, int l, int d) {
		x = x != nullptr ? new node(*x) : new node();
		if (d == 0) return make_pair(x, x);
		int id = (a - l) >> (d - LOG_CH);
		auto p = mutable_get(a, x->ch[id], l + (id << (d - LOG_CH)), d - LOG_CH);
		x->ch[id] = p.first;
		return make_pair(x, p.second);
	}
};


void deb(node *t){
    if(!t)return;
    deb(t->l);
    cout<<t->v<<" ";
    deb(t->r);
}
void debug(node *t){
    deb(t);
    cout<<endl;
}

template<class _Key, class _Tp> class MapIterator;

template<class _Key, class _Tp> class Map {
private:
    using iterator = MapIterator<_Key, _Tp>;
    struct node {
        pair<const _Key, _Tp> data;
        node *_M_left, *_M_right, *_M_parent;
        node(const _Key& _key, const _Tp& _value) noexcept
         : data(_key, _value), _M_left(nullptr), _M_right(nullptr), _M_parent(nullptr){}
        inline bool isRoot() const noexcept { return !_M_parent; }
        void rotate(const bool right) noexcept {
            node *p = _M_parent, *g = p->_M_parent;
            if(right){
                if((p->_M_left = _M_right)) _M_right->_M_parent = p;
                _M_right = p, p->_M_parent = this;
            }else{
                if((p->_M_right = _M_left)) _M_left->_M_parent = p;
                _M_left = p, p->_M_parent = this;
            }
            if(!(_M_parent = g)) return;
            if(g->_M_left == p) g->_M_left = this;
            if(g->_M_right == p) g->_M_right = this;
        }
    };
    friend MapIterator<_Key, _Tp>;
    node *root, *_M_header, *start;
    size_t _M_node_count;
    node *splay(node *u) noexcept {
        while(!(u->isRoot())){
            node *p = u->_M_parent, *gp = p->_M_parent;
            if(p->isRoot()){
                u->rotate((u == p->_M_left));
            }else{
                bool flag = (u == p->_M_left);
                if((u == p->_M_left) == (p == gp->_M_left)){
                    p->rotate(flag), u->rotate(flag);
                }else{
                    u->rotate(flag), u->rotate(!flag);
                }
            }
        }
        return root = u;
    }
    static node *increment(node *ver) noexcept {
        if(ver->_M_right){
            ver = ver->_M_right;
            while(ver->_M_left) ver = ver->_M_left;
        }else{
            node *nx = ver->_M_parent;
            while(ver == nx->_M_right) ver = nx, nx = nx->_M_parent;
            ver = nx;
        }
        return ver;
    }
    static node *decrement(node *ver) noexcept {
        if(ver->_M_left){
            ver = ver->_M_left;
            while(ver->_M_right) ver = ver->_M_right;
        }else{
            node *nx = ver->_M_parent;
            while(ver == nx->_M_left) ver = nx, nx = nx->_M_parent;
            ver = nx;
        }
        return ver;
    }
    node *join(node *ver1, node *ver2, const node *ver) noexcept {
        while(ver2->_M_left) ver2 = ver2->_M_left;
        splay(ver2)->_M_left = ver1;
        return ver1 ? (ver1->_M_parent = ver2) : (start = ver2);
    }
    node *_find(const _Key& _key, bool push=false) noexcept {
        node *cur = nullptr, *nx = root;
        do {
            cur = nx;
            if(cur == _M_header || cur->data.first > _key) nx = cur->_M_left;
            else if(cur->data.first < _key) nx = cur->_M_right;
            else return splay(cur);
        }while(nx);
        if(!push) return _M_header;
        if(cur == _M_header || cur->data.first > _key){
            nx = new node(_key, _Tp());
            cur->_M_left = nx, nx->_M_parent = cur;
            if(cur == start) start = nx;
            return _M_node_count++, splay(nx);
        }else{
            nx = new node(_key, _Tp());
            cur->_M_right = nx, nx->_M_parent = cur;
            return _M_node_count++, splay(nx);
        }
    }
    node *_insert(node *ver) noexcept {
        node *cur = nullptr, *nx = root;
        do {
            cur = nx;
            if(cur == _M_header || cur->data.first > ver->data.first) nx = cur->_M_left;
            else nx = cur->_M_right;
        }while(nx);
        if(cur == _M_header || cur->data.first > ver->data.first){
            cur->_M_left = ver, ver->_M_parent = cur;
            if(cur == start) start = ver;
            return _M_node_count++, splay(ver);
        }else{
            cur->_M_right = ver, ver->_M_parent = cur;
            return _M_node_count++, splay(ver);
        }
    }
    node *_erase(node *root_ver){
        assert(root_ver != _M_header);
        if(root_ver->_M_left) root_ver->_M_left->_M_parent = nullptr;
        if(root_ver->_M_right) root_ver->_M_right->_M_parent = nullptr;
        node *res = join(root_ver->_M_left, root_ver->_M_right, root_ver);
        delete root_ver;
        return _M_node_count--, res;
    }
    node *_erase(const _Key& _key){
        node *ver = _find(_key);
        return _erase(ver);
    }
    node *_lower_bound(const _Key& _key) noexcept {
        node *cur = nullptr, *nx = root, *res = nullptr;
        do {
            cur = nx;
            if(cur == _M_header){ nx = cur->_M_left; continue; }
            else if(cur->data.first >= _key){
                nx = cur->_M_left;
                if(!res || cur->data.first <= res->data.first) res = cur;
            }else nx = cur->_M_right;
        }while(nx);
        splay(cur);
        return res ? res : _M_header;
    }
    node *_upper_bound(const _Key& _key) noexcept {
        node *cur = nullptr, *nx = root, *res = nullptr;
        do {
            cur = nx;
            if(cur == _M_header){ nx = cur->_M_left; continue; }
            else if(cur->data.first > _key){
                nx = cur->_M_left;
                if(!res || cur->data.first <= res->data.first) res = cur;
            }else nx = cur->_M_right;
        }while(nx);
        splay(cur);
        return res ? res : _M_header;
    }
    void clear_dfs(node *cur) noexcept {
        if(cur->_M_left) clear_dfs(cur->_M_left);
        if(cur->_M_right) clear_dfs(cur->_M_right);
        delete cur;
    }

public:
    Map() noexcept : _M_node_count(0){ root = _M_header = start = new node(_Key(), _Tp()); }
    ~Map() noexcept { clear_dfs(root); }
    friend ostream& operator<< (ostream& os, Map& mp) noexcept {
        for(auto& val : mp) os << '{' << val.first << ',' << val.second << "} ";
        return os;
    }
    _Tp& operator[](const _Key& _key) noexcept { return _find(_key, true)->data.second; }
    const _Tp& at(const _Key& _key){
        node *res = _find(_key);
        if(res == _M_header) __throw_out_of_range(__N("Map::at"));
        return res->data.second;
    }
    size_t size() const noexcept { return _M_node_count; }
    bool empty() const noexcept { return size() == 0; }
    iterator begin() const noexcept { return iterator(start); }
    iterator end() const noexcept { return iterator(_M_header); }
    void clear() noexcept { clear_dfs(root), _M_node_count = 0, root = _M_header = start = new node(_Key(), _Tp()); }
    iterator find(const _Key& _key) noexcept { return iterator(_find(_key)); }
    iterator insert(const _Key& _key, const _Tp& _value) noexcept
        { return iterator(_insert(new node(_key, _value))); }
    iterator erase(const _Key& _key){ return iterator(_erase(_key)); }
    iterator erase(const iterator& itr){ return iterator(_erase(splay(itr.node_ptr))); }
    iterator lower_bound(const _Key& _key) noexcept { return iterator(_lower_bound(_key)); }
    iterator upper_bound(const _Key& _key) noexcept { return iterator(_upper_bound(_key)); }
};

template<class _Key, class _Tp>
class MapIterator {
private:
    friend Map<_Key, _Tp>;
    typename Map<_Key, _Tp>::node *node_ptr;
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = pair<const _Key, _Tp>;
    using difference_type = pair<const _Key, _Tp>;
    using pointer = pair<const _Key, _Tp>*;
    using reference = pair<const _Key, _Tp>&;

private:
    MapIterator(typename Map<_Key, _Tp>::node *mp) noexcept : node_ptr(mp){}

public:
    MapIterator() noexcept : node_ptr(){}
    MapIterator(const MapIterator& itr) noexcept : node_ptr(itr.node_ptr){}
    MapIterator& operator=(const MapIterator& itr) & { return node_ptr = itr.node_ptr, *this; }
    MapIterator& operator=(const MapIterator&& itr) & noexcept { return node_ptr = itr.node_ptr, *this; }
    reference operator*() const { return node_ptr->data; }
    pointer operator->() const { return &(node_ptr->data); }
    MapIterator& operator++() noexcept { return node_ptr = Map<_Key, _Tp>::increment(node_ptr), *this; }
    MapIterator operator++(int) noexcept { return MapIterator(Map<_Key, _Tp>::increment(this->node_ptr)); }
    MapIterator& operator--() noexcept { return node_ptr = Map<_Key, _Tp>::decrement(node_ptr), *this; }
    MapIterator operator--(int) noexcept { return MapIterator(Map<_Key, _Tp>::decrement(this->node_ptr)); }
    bool operator==(const MapIterator& itr) const noexcept { return !(*this != itr); };
    bool operator!=(const MapIterator& itr) const noexcept { return node_ptr != itr.node_ptr; }
};

Map<string, int>mp;

signed main(){
    int Q;scanf("%d",&Q);

    root[0]=NULL;
    vector<Array<int>>val(111111);
    val[0]=Array<int>(111111);
    rep(i,111111){
        *val[0].mutable_get(i)=-1;
    }
    char buf[22],buf2[22];
    rep(i,Q){
        string s,t;

        scanf(" %s",buf);
        s=buf;
        int v;
        if(s!="undo"){
            scanf(" %s",buf2);
            t=buf2;
            if(mp.find(t)!=mp.end())v=mp[t];
            else{
                v=mp.size();
                mp[t]=v;
            }
        }



        root[i+1]=root[i];
        val[i+1]=val[i];

        if(s=="set"){
            int x;scanf("%d",&x);
            if(val[i+1].immutable_get(v)!=-1){
                root[i+1]=er(root[i+1],val[i+1].immutable_get(v));
            }
            root[i+1]=ins(root[i+1],x);
            *val[i+1].mutable_get(v)=x;
        }
        else if(s=="remove"){
            if(val[i+1].immutable_get(v)>=0){
                root[i+1]=er(root[i+1],val[i+1].immutable_get(v));
                *val[i+1].mutable_get(v)=-1;
            }
        }
        else if(s=="query"){
            if(val[i+1].immutable_get(v)==-1)puts("-1");
            else printf("%d\n",lb(root[i+1],val[i+1].immutable_get(v)));
        }
        else{
            int x;scanf("%d",&x);
            root[i+1]=root[i-x];
            val[i+1]=val[i-x];
        }
        
        fflush(stdout);
    }
    return 0;
}
