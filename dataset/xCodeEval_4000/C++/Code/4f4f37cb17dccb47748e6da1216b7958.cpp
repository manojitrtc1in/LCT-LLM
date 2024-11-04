#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define unique(a) (a).erase(std::unique((a).begin(),(a).end()),(a).end())
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vil vector<long long>
#define vii vector<pair<int,int>>
#define viil vector<pair<long long,long long>>





#define lsb(x) (x&-x)
#define lsbu(x) (x&(x+1))
#define msb(x) __lg(x)
#define msbu(x)




























#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set_pair tree<pair<int,int>, null_type, less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>

typedef tree<int , null_type ,  less_equal<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_multiset;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;





struct comp { 

    bool operator() (const pair <int , int> &a, const pair <int , int> &b) const {
        return a.first < b.first;
    }
};


#define INF 1e9+9
int nmax() {return -1 * INF;}
template<typename Arg, typename... Args>
int nmax(Arg a, Args... args) { return std::max(a, nmax(args...)); }

int nmin() {return INF;}
template<typename Arg, typename... Args>
int nmin(Arg a, Args... args) { return std::min(a, nmin(args...)); }


void ans22(bool x) {if (x) cout << "YES" << endl; else cout << "NO" << endl;}




bool onsegment(pair<int, int> p, pair<int, int> q, pair<int, int> r)
{
    if (q.first <= max(p.second, r.first) && q.first >= min(p.first, r.first) &&
            q.second <= max(p.second, r.second) && q.second >= min(p.second, r.second))
        return true;

    return false;
}









int orientation(pair<int, int> p, pair<int, int> q, pair<int, int> r)
{
    int val = (q.second - p.second) * (r.first - q.first) -
              (q.first - p.first) * (r.second - q.second);

    if (val == 0) return 0;  


    return (val > 0) ? 1 : 2; 

}



#define dsu(n) parent_dsu.resize(n);rank_dsu.resize(n,0);iota(parent_dsu.begin(),parent_dsu.end(),0)
vector<int> parent_dsu, rank_dsu;
void make_set_dsu(int v) {
    parent_dsu[v] = v;  

    rank_dsu[v] = 0;     

}

int find_set_dsu(int v) {
    if (v == parent_dsu[v])
        return v;
    return parent_dsu[v] = find_set_dsu(parent_dsu[v]); 

    

}

void union_sets_dsu(int a, int b) {
    a = find_set_dsu(a);
    b = find_set_dsu(b);
    if (a != b) {
        if (rank_dsu[a] < rank_dsu[b])
            swap(a, b);
        parent_dsu[b] = a;
        if (rank_dsu[a] == rank_dsu[b])
            rank_dsu[a]++;
    }
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};



void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
void __print(const vector<int>& x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}


template<typename T>void __print(stack<T> st) {while (!st.empty()) {cerr << st.top() << " "; st.pop();};}
template<typename T>void __print(queue<T> st) {while (!st.empty()) {cerr << st.front() << " "; st.pop();};}
template<typename T>void __print(deque<T> st) {while (!st.empty()) {cerr << st.front() << " "; st.pop_front();};}


void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

long long ccccc = 0;
#ifndef ONLINE_JUDGE
#define tle ccccc++;assert(ccccc<1e7)
#define wd(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define tle
#define wd(x...)
#endif


#define int long long


#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;



const int MAXN = 3000000;

const int NEUTRAL_VALUE = 0;
const int NEUTRAL_DELTA = 0;

int joinValues(int leftValue, int rightValue) {
    return (leftValue + rightValue);
}

int joinDeltas(int oldDelta, int newDelta) {
    return oldDelta + newDelta;
}

int joinValueWithDelta(int value, int delta, int length) {
    return value + delta*length;
}



struct treap {
    int nodeValue;
    int subTreeValue;
    int delta;
    int count;
    int prio;
    treap *l;
    treap *r;
};

treap nodes[MAXN];
int nodes_cnt;
vector<int> rnd;

static int getCount(treap* root) {
    return root ? root->count : 0;
}

static int getSubTreeValue(treap* root) {
    return root ? root->subTreeValue : NEUTRAL_VALUE;
}

void update(treap *root) {
    if (!root) return;
    root->subTreeValue = joinValues(joinValues(getSubTreeValue(root->l), root->nodeValue), getSubTreeValue(root->r));
    root->count = 1 + getCount(root->l) + getCount(root->r);
}

void applyDelta(treap *root, int delta) {
    if (!root) return;
    root->delta = joinDeltas(root->delta, delta);
    root->nodeValue = joinValueWithDelta(root->nodeValue, delta, 1);
    root->subTreeValue = joinValueWithDelta(root->subTreeValue, delta, root->count);
}

void pushDelta(treap* root) {
    if (!root) return;
    applyDelta(root->l, root->delta);
    applyDelta(root->r, root->delta);
    root->delta = NEUTRAL_DELTA;
}

void merge(treap* &t, treap* l, treap* r) {
    pushDelta(l);
    pushDelta(r);
    if (!l)
        t = r;
    else if (!r)
        t = l;
    else if (l->prio < r->prio)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    update(t);
}

void split(treap* t, treap* &l, treap* &r, int key) {
    pushDelta(t);
    if (!t)
        l = r = NULL;
    else if (key <= getCount(t->l))
        split(t->l, l, t->l, key), r = t;
    else
        split(t->r, t->r, r, key - getCount(t->l) - 1), l = t;
    update(t);
    

    

}

int get(treap* t, int index) {
    pushDelta(t);
    if (index < getCount(t->l))
        return get(t->l, index);
    else if (index > getCount(t->l))
        return get(t->r, index - getCount(t->l) - 1);
    return t->nodeValue;
}

void insert(treap* &t, treap* item, int index) {
    pushDelta(t);
    if (!t)
        t = item;
    else if (item->prio < t->prio)
        split(t, item->l, item->r, index), t = item;
    else if (index <= getCount(t->l))
        insert(t->l, item, index);
    else
        insert(t->r, item, index - getCount(t->l) - 1);
    update(t);
}

void insert(treap* &root, int index, int value) {
    treap *item = &nodes[nodes_cnt];
    item->nodeValue = value;
    item->subTreeValue = value;
    item->delta = NEUTRAL_DELTA;
    item->count = 1;
    item->prio = rnd[nodes_cnt];


    ++nodes_cnt;
    insert(root, item, index);
}

void remove(treap* &t, int index) {
    pushDelta(t);
    if (index == getCount(t->l))
        merge(t, t->l, t->r);
    else if (index < getCount(t->l))
        remove(t->l, index);
    else
        remove(t->r, index - getCount(t->l) - 1);
    update(t);
}

int query(treap* &root, int a, int b) {
    treap *l1, *r1;
    split(root, l1, r1, b + 1);
    treap *l2, *r2;
    split(l1, l2, r2, a);
    int res = getSubTreeValue(r2);
    treap *t;
    merge(t, l2, r2);
    merge(root, t, r1);
    return res;
}

void modify(treap* &root, int a, int b, int delta) {
    treap *l1, *r1;
    split(root, l1, r1, b + 1);
    treap *l2, *r2;
    split(l1, l2, r2, a);
    applyDelta(r2, delta);
    treap *t;
    merge(t, l2, r2);
    merge(root, t, r1);
}

void print(treap* t) {
    if (!t) return;
    pushDelta(t);
    print(t->l);
    cout << t->nodeValue << " ";
    print(t->r);
}



std::pair <int, int> lower_bound (treap* &t, int key, int index) {
    pushDelta(t);
    if (!t)
        return { -1, MAXN};
    if (key == t->nodeValue)
        return {key, index + getCount(t->l)};
    if (key < t->nodeValue) {
        std::pair <int, int> ret = lower_bound(t->l, key, index);
        if (ret.second == MAXN)
            ret = {t->nodeValue, index + getCount(t->l)};
        return ret;
    }
    return lower_bound(t->r, key, index + 1 + getCount(t->l));
}

std::pair <int, int> upper_bound (treap* &t, int key, int index) {
    pushDelta(t);
    if (!t)
        return { -1, MAXN};
    if (key < t->nodeValue) {
        std::pair <int, int> ret = upper_bound(t->l, key, index);
        if (ret.second == MAXN)
            ret = {t->nodeValue, index + getCount(t->l)};
        return ret;
    }
    return upper_bound(t->r, key, index + 1 + getCount(t->l));
}




std::pair <int, int> lower_bound (treap* &t, int x) {
    

    

    return lower_bound(t, x, 0);
}

std::pair <int, int> upper_bound (treap* &t, int x) {
    

    

    return upper_bound(t, x, 0);
}

#define sz(x) (int)(x).size()

#define all(x) (x).begin(), (x).end()
long long mod = 1e9 + 7;

int32_t main() {
    






#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    for (int i = 0; i < MAXN; i++)
        rnd.push_back(i);
    random_shuffle(rnd.begin(), rnd.end());

    int q, d;
    scanf("%lld %lld", &q, &d);

    treap *tleft = NULL , *tright = NULL;


    

    ordered_set V;
    long long ans = 0;
    int _n = 0;
    for (int i = 0; i < q; i++) {
        int v;
        scanf("%lld", &v);
        int p;
        int pos;
        if (V.find(v) == V.end()) {
            

            p = 1;
            _n++;
            pos = V.order_of_key(v);
        }
        else {
            V.erase(v);
            p = -1;
            _n--;
            pos = V.order_of_key(v);
        }

        if (p == -1) {
            

            remove(tleft, pos);
            remove(tright, pos);
        }

        

        

        int a = (int)V.order_of_key(v - d);
        int b = (int)V.order_of_key(v + d + 1) - 1;
        int x = (int)V.order_of_key(v);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         




        


        if (p == -1) { 

            modify(tright, a, x - 1, p);
            modify(tleft, x, b, p);
        }


     

            if (p == 1) {

                int l = (x - 1 - a < 0) ? 0 : query(tright, a, x - 1);
                int r = (b - x < 0) ? 0 : query(tleft, x, b);
                long long lcnt =  (x - a < 0) ? 0ll : x - a;
                int both = l - ((lcnt * (lcnt - 1)) / 2);
                

                

                ans += l + r - both;

                

                

                



                

                

                

                

                

                

                

                


                

                

                

                

                


                

                


            }
            else {
                int l = (x-1-a < 0ll) ? 0ll : (int)query(tright, a, x - 1);
                int r = (b - x < 0ll) ? 0ll : (int)query(tleft, x, b);
                int lcnt =  (x - a < 0ll) ? 0ll : x - a;
                int both = l - ((lcnt * (lcnt - 1ll)) / 2ll);
                

                

int h=ans;

        int rcnt =  (b-x+1ll < 0ll) ? 0ll : b - x+1ll;
                int both2 = r - ((rcnt * (rcnt - 1ll)) / 2ll);

                
                ans -= l + r - both;

                 

                 

                 


                  

                  

                    
                    


                    

                    

                    

                    

                    

                    

                    



                      

                




                

                

                



                

                

                

                

                

                

                

                


                

                

                

                

                


                

                



            }
        

        if (p == 1) { 

            modify(tright, a, x - 1, p);
            

            modify(tleft, x, b, p);
        }

        if (p == 1) {
            

            

            

            insert(tleft, pos,  (x - a < 0ll) ? 0ll : x - a);
            insert(tright, pos, (b - x + 1 < 0ll) ? 0ll : b - x + 1);
            V.insert(v);
        }

 

 

 



        printf("%lld\n", ans);


    }

    

    


    


    









    return 0;
}
