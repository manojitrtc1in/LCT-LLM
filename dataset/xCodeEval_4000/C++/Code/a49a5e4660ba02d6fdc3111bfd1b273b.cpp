

#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define mp make_pair
#define pb push_back
#define mscanf(...) if(0 == scanf(__VA_ARGS__)){fprintf(stderr, "Could not parse arguments\n");}

#define ONLINE_JUDGE2

#ifndef ONLINE_JUDGE
#include "debugging.cpp"
#else
#define debug(...) ;
#endif


































static uint64_t splitmix64(uint64_t x) {
    

    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}

uint64_t integer_hash(uint64_t x) {


    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
}

long unsigned int get_random(){
    static mt19937 rnd(integer_hash(chrono::steady_clock::now().time_since_epoch().count()));
    return rnd();
}

const int MAXPARTS = 40.1e5;
int nxtFreeId = 1;
struct Part{
    bool used;
    int length;
    uint64_t hash_value;
    int left;
    int right;
    Part(bool used_ = false, int length_ = 0, uint64_t hash_value_ = 0, int left_=0, int right_=0):used(used_),length(length_),hash_value(hash_value_), left(left_), right(right_){}
} part_list[MAXPARTS];
ostream& operator<<(ostream &str, const Part &f) {
    return str << "{" << f.length << "," << f.hash_value << "," << f.left <<"," << f.right<< "}";
}


vector<uint64_t > mul_powers(1,1);
uint64_t merged_hash(int a_length, uint64_t a_hash, int b_length, uint64_t b_hash){
    static const uint64_t FIXED_MULTIPLYER = integer_hash(3 | (chrono::steady_clock::now().time_since_epoch().count()));


    while(sz(mul_powers) <= b_length)mul_powers.push_back(mul_powers[sz(mul_powers)-1]*FIXED_MULTIPLYER);
    return b_hash + mul_powers[b_length] * a_hash;
    (void)a_length;
}
uint64_t merged_hash(int ida, int  idb){
    return merged_hash(part_list[ida].length, part_list[ida].hash_value, part_list[idb].length, part_list[idb].hash_value);
}
int getEmptyPart() {
    if(!part_list[0].used){
        part_list[0].used = true;
        part_list[0].left = part_list[0].right = 0;
        part_list[0].length = 0;
        part_list[0].hash_value = 0;
    }
    return 0;
}
int getNextFreeIndex(){
    while(part_list[nxtFreeId].used){
        ++nxtFreeId;
        if(nxtFreeId == MAXPARTS){
            assert(false);
            nxtFreeId = 1;
        }
    }
    part_list[nxtFreeId].used = true;
    return nxtFreeId;
}
void recalc(int id){
    part_list[id].length = part_list[part_list[id].left].length + part_list[part_list[id].right].length;
    part_list[id].hash_value = merged_hash(part_list[id].left, part_list[id].right);
}
int merge(int a, int b){
    debug("start merge",a,b,part_list[a],part_list[b]);
    if(a == 0)return b;
    if(b == 0)return a;
    int u = getNextFreeIndex();
    if((int)(get_random() % (part_list[a].length + part_list[b].length)) < part_list[a].length){
        if(part_list[a].left == 0){
            part_list[u].left = a;
            part_list[u].right = b;
        } else {
            part_list[u].left = part_list[a].left;
            part_list[u].right = merge(part_list[a].right, b);
        }
    } else {
        if(part_list[b].right == 0){
            part_list[u].left = a;
            part_list[u].right = b;
        } else {
            part_list[u].right = part_list[b].right;
            part_list[u].left = merge(a, part_list[b].left);
        }
    }
    recalc(u);
    debug("end merge",a,b,part_list[a],part_list[b], u, part_list[u]);
    return u;
}
uint64_t get_subhash(int p, int f, int t){
    if(f == t)return 0;
    assert(p > 0);
    assert(part_list[p].length >= t);
    if(f == 0 && t == part_list[p].length)return part_list[p].hash_value;
    assert(f >= 0 && t <= part_list[p].length);
    if(f >= part_list[ part_list[p].left].length)return get_subhash(part_list[p].right, f - part_list[ part_list[p].left].length, t - part_list[ part_list[p].left].length);
    if(t <= part_list[ part_list[p].left].length)return get_subhash(part_list[p].left, f,t);
    int m = part_list[ part_list[p].left].length;
    auto a_hash = get_subhash(part_list[p].left, f, m);
    auto b_hash = get_subhash(part_list[p].right, 0, t-m);
    return merged_hash(m-f, a_hash, t-m, b_hash);
}
int getPartFromBrace(ll b){
    assert(b > 0);
    int u = getNextFreeIndex();
    part_list[u].left = part_list[u].right = getEmptyPart();
    part_list[u].length = 1;
    part_list[u].hash_value = integer_hash(b);
    return u;
}

int get_subpart(int p, int f, int t){
    if(f == t)return getEmptyPart();
    if(f == 0 && t == part_list[p].length){
        return p;
    }
    assert(p > 0);
    assert(part_list[p].length >= t);
    int m = part_list[ part_list[p].left].length;
    int pl = (f < m)?get_subpart(part_list[p].left ,f,min(m,t)):0;
    int pr = (t > m)?get_subpart(part_list[p].right,max(0,f-m),t-m):0;
    if(pl == 0)return pr;
    if(pr == 0)return pl;
    int u = getNextFreeIndex();
    part_list[u].left = pl;
    part_list[u].right = pr;
    recalc(u);
    return u;
}

template< class Type, class LazyType >
struct SegmentTree{
    typedef Type (*SegmentTreeValueMergerPointer)(Type a, Type b);
    typedef Type (*SegmentTreeValueLazyMergerPointer)(Type a, LazyType b, int F, int T);
    typedef LazyType (*SegmentTreeLazyMergerPointer)(LazyType a, LazyType b);
    int S;
    int SP2;
    Type neutral_value, empty_value;
    LazyType neutral_lazy_value;
    SegmentTreeValueMergerPointer valueMerger;
    SegmentTreeValueLazyMergerPointer valueLazyMerger;
    SegmentTreeLazyMergerPointer lazyMerger;
    struct Entry{
        Type data;
        LazyType lazy;
        bool markReset;
        Entry(Type data_, LazyType lazy_, bool markReset_=false):data(data_), lazy(lazy_), markReset(markReset_){}
    };
    vector<Entry> entries;
    SegmentTree(int N, Type neutral_value_, Type empty_value_, LazyType neutral_lazy_value_, SegmentTreeValueMergerPointer valueMerger_, SegmentTreeValueLazyMergerPointer valueLazyMerger_, SegmentTreeLazyMergerPointer lazyMerger_){
        neutral_value = neutral_value_;
        empty_value = empty_value_;
        neutral_lazy_value = neutral_lazy_value_;
        valueLazyMerger = valueLazyMerger_;
        valueMerger = valueMerger_;
        lazyMerger = lazyMerger_;
        S = N;
        entries = vector<Entry>(S*2+2, Entry(neutral_value, neutral_lazy_value));
        SP2 = 1;
        while(SP2*2 <= S)SP2*=2;
    }
    Type query(int f, int t);
    void update(int f, int t, LazyType change);
    bool debugTree();
    void reset(int f, int t);
    void init(vector<Type> &initialValues);
    Type mergeValues(Type v1, Type v2){
        return valueMerger(v1,v2);
    }
    LazyType mergeLazy(LazyType old, LazyType upd){
        return lazyMerger(old, upd);
    }
    Type mergeValueLazy(Type old, LazyType upd, int F, int T){
        return valueLazyMerger(old, upd, F, T);
    }
    int get_mid(int D, int P2){
        return (((P2>>1)|P2) <= D)?P2:D-(P2>>1);
    }
    void distributeReset(int id, int F, int T){
        assert(entries[id].markReset);
        entries[id].markReset = false;
        if(F+1==T)return;
        entries[id*2+1] = entries[id*2+2] = Entry(neutral_value, neutral_lazy_value, true);
    }
    Type query(int id, int P2, int F, int T, int f, int t){
        if(entries[id].markReset)distributeReset(id,F,T);
        f = max(f,F);
        t = min(t,T);
        if(f >= t)return empty_value;
        if(f == F && t == T)return entries[id].data;
        int M = F + get_mid(T-F, P2);
        Type r1 = query(id*2+1, P2 >> 1, F, M, f, t);
        Type r2 = query(id*2+2, P2 >> 1, M, T, f, t);
        auto res = mergeValueLazy(mergeValues(r1,r2), entries[id].lazy, f, t);
        debug(id,F,T,f,t,r1,r2,res);
        return res;
    }
    void update(int id, int P2, int F, int T, int f, int t, LazyType change){
        if(entries[id].markReset)distributeReset(id,F,T);
        f = max(f, F);
        t = min(t, T);
        if(f >= t)return;
        if(f == F && t == T){
            entries[id].lazy = mergeLazy(entries[id].lazy, change);
            entries[id].data = mergeValueLazy(entries[id].data, change, F, T);
        } else {
            int M = F + get_mid(T-F, P2);
            update(id*2+1, P2 >> 1, F, M, f, t, change);
            update(id*2+2, P2 >> 1, M, T, f, t, change);
            entries[id].data = mergeValueLazy(mergeValues(entries[id*2+1].data, entries[id*2+2].data), entries[id].lazy, F, T);
        }
    }
    void reset(int id, int P2, int F, int T, int f, int t){
        if(entries[id].markReset)return;
        f = max(f, F);
        t = min(t, T);
        if(f >= t)return;
        if(f == F && t == T){
            entries[id] = Entry(neutral_value, neutral_lazy_value, true);
        } else {
            int M = F + get_mid(T-F, P2);
            update(id*2+1, P2 >> 1, F, M, F, T, entries[id].lazy);
            update(id*2+2, P2 >> 1, M, T, F, T, entries[id].lazy);
            entries[id].lazy = neutral_lazy_value;
            reset(id*2+1, P2 >> 1, F, M, f, t);
            reset(id*2+2, P2 >> 1, M, T, f, t);
            entries[id].data = mergeValueLazy(mergeValues(entries[id*2+1].data, entries[id*2+2].data), entries[id].lazy, F, T);
        }
    }
    void init(int id, int P2, int F, int T, vector<Type> & initialValues){
        entries[id] = Entry(neutral_value, neutral_lazy_value, false);
        if(F+1==T){
            entries[id].data = initialValues[F];
        } else {
            int M = F + get_mid(T-F, P2);
            init(id*2+1, P2 >> 1, F, M, initialValues);
            init(id*2+2, P2 >> 1, M, T, initialValues);
            entries[id].data = mergeValueLazy(mergeValues(entries[id*2+1].data, entries[id*2+2].data), entries[id].lazy, F, T);
        }
    }
    void debugTree(int id, int P2, int F, int T){
        cerr << "(" << id << "," << F << "," << T <<"):" << entries[id].data << " " << entries[id].lazy << " " << entries[id].markReset << endl;
        if(F+1==T){
            return;
        } else {
            int M = F + get_mid(T-F, P2);
            debugTree(id*2+1, P2 >> 1, F, M);
            debugTree(id*2+2, P2 >> 1, M, T);
        }
    }
};
template< class Type, class LazyType >
Type SegmentTree<Type,LazyType>::query(int f, int t){
    auto res = query(0,SP2,0,S,f,t);
    return res;
}
template< class Type, class LazyType >
void SegmentTree<Type,LazyType>::update(int f, int t, LazyType change){
    update(0,SP2,0,S,f,t,change);
}
template< class Type, class LazyType >
bool SegmentTree<Type,LazyType>::debugTree(){
    debugTree(0,SP2,0,S);
    return true;
}
template< class Type, class LazyType >
void SegmentTree<Type,LazyType>::reset(int f, int t){
    reset(0,SP2,0,S,f,t);
}
template< class Type, class LazyType >
void SegmentTree<Type,LazyType>::init(vector<Type> &initialValues){
    assert(initialValues.size() == (unsigned int) S);
    init(0,SP2,0,S,initialValues);
}

































struct DataValue{
    bool fail;
    int bracesToOpen;
    int bracesToClose;
    DataValue(bool fail_ = true, int bracesToOpen_ = 0, int bracesToClose_ = 0):fail(fail_), bracesToOpen(bracesToOpen_), bracesToClose(bracesToClose_){}
};
ostream& operator<<(ostream &str, const DataValue &f) {
    if(f.fail){
        return str << "FAIL";
    } else {
        return str << "(" << part_list[f.bracesToOpen].length << "[" << part_list[f.bracesToOpen].hash_value << "]," << part_list[f.bracesToClose].length << "[" << part_list[f.bracesToClose].hash_value<< "])";
    }
}

void initialize(const vector<int> & vv, SegmentTree<DataValue,ll> &segmentTree){
    vector<DataValue> initialValues(sz(vv));
    FOR(i,0,sz(vv)){
        int v = vv[i];
        if(v < 0)initialValues[i]=DataValue(false,getPartFromBrace(abs(v)),getEmptyPart());
        else initialValues[i]=DataValue(false,getEmptyPart(),getPartFromBrace(abs(v)));
    }
    segmentTree.init(initialValues);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,K;
    cin >> N >> K;
    SegmentTree<DataValue,ll> segmentTree(N
            ,DataValue(false,getEmptyPart(), getEmptyPart())
            ,DataValue(false, getEmptyPart(), getEmptyPart())
            ,0,
            [](DataValue a, DataValue b) -> DataValue{
            if (a.fail || b.fail) return DataValue(true);
            if(part_list[a.bracesToClose].length < part_list[b.bracesToOpen].length){
                if(part_list[a.bracesToClose].hash_value == get_subhash(b.bracesToOpen,0,part_list[a.bracesToClose].length)){
                    auto remaining = get_subpart(b.bracesToOpen,part_list[a.bracesToClose].length, part_list[b.bracesToOpen].length);
                    return DataValue(false,merge(a.bracesToOpen, remaining),b.bracesToClose);
                } else {
                    return DataValue(true);
                }
            }
            if(part_list[b.bracesToOpen].hash_value == get_subhash(a.bracesToClose,0,part_list[b.bracesToOpen].length)){
                auto remaining = get_subpart(a.bracesToClose,part_list[b.bracesToOpen].length, part_list[a.bracesToClose].length);
                return DataValue(false,a.bracesToOpen, merge(b.bracesToClose, remaining));
            } else {
                return DataValue(true);
            }
            }
            ,[](DataValue v, ll x, int F, int T) -> DataValue{
                if(x == 0)return v;
            if(x < 0)return DataValue(false,getPartFromBrace(abs(x)),getEmptyPart());
            else return DataValue(false,getEmptyPart(),getPartFromBrace(abs(x)));
            (void) v;
            (void) F;
            (void) T;
            }
            ,[](ll a, ll b) -> ll{
            return b;
            (void)a;});
    vector<int> currentValues(N);
    FOR(i,0,N){
        cin >> currentValues[i];
    }
    ll neededValues = 0;
    initialize(currentValues,segmentTree);
    debug(segmentTree.debugTree());
    int Q;
    cin >> Q;
    FOR(q,0,Q){
        if(MAXPARTS * 9 < nxtFreeId * 10){
            neededValues += nxtFreeId;
            FOR(i,1,nxtFreeId+1)part_list[i].used = false;
            nxtFreeId = 1;
            initialize(currentValues,segmentTree);
        }
        int ty,a,b;
        cin >> ty >> a >> b;
        debug("QUERY", ty,a,b);
        if(ty == 1){
            segmentTree.update(a-1,a,b);
            currentValues[a-1] = b;
            debug(segmentTree.debugTree());
        } else {
            int memNxtFree = nxtFreeId;
            auto res = segmentTree.query(a-1,b);
            debug(res);
            if(!res.fail && part_list[res.bracesToOpen].length == 0 && part_list[res.bracesToClose].length == 0){
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
            FOR(i,memNxtFree+1,nxtFreeId)part_list[i].used = false;
            nxtFreeId = memNxtFree;
        }
    }
    cerr << nxtFreeId + neededValues << endl;
    return 0;
}
