
using namespace std;



















































using namespace __gnu_pbds;



typedef tree<int , null_type ,  less_equal<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_multiset;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;





struct comp { 

    bool operator() (const pair <int , int> &a, const pair <int , int> &b) const {
        return a.first < b.first;
    }
};



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




vector<int> id10, id0;
void id7(int v) {
    id10[v] = v;  

    id0[v] = 0;     

}

int id8(int v) {
    if (v == id10[v])
        return v;
    return id10[v] = id8(id10[v]); 

    

}

void id9(int a, int b) {
    a = id8(a);
    b = id8(b);
    if (a != b) {
        if (id0[a] < id0[b])
            swap(a, b);
        id10[b] = a;
        if (id0[a] == id0[b])
            id0[a]++;
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
        static const uint64_t id2 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id2);
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
















using namespace std;



const int MAXN = 3000000;

const int id4 = 0;
const int id1 = 0;

int joinValues(int leftValue, int rightValue) {
    return (leftValue + rightValue);
}

int id3(int oldDelta, int newDelta) {
    return oldDelta + newDelta;
}

int id5(int value, int delta, int length) {
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

static int id6(treap* root) {
    return root ? root->subTreeValue : id4;
}

void update(treap *root) {
    if (!root) return;
    root->subTreeValue = joinValues(joinValues(id6(root->l), root->nodeValue), id6(root->r));
    root->count = 1 + getCount(root->l) + getCount(root->r);
}

void applyDelta(treap *root, int delta) {
    if (!root) return;
    root->delta = id3(root->delta, delta);
    root->nodeValue = id5(root->nodeValue, delta, 1);
    root->subTreeValue = id5(root->subTreeValue, delta, root->count);
}

void pushDelta(treap* root) {
    if (!root) return;
    applyDelta(root->l, root->delta);
    applyDelta(root->r, root->delta);
    root->delta = id1;
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
    item->delta = id1;
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
    int res = id6(r2);
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




long long mod = 1e9 + 7;

int32_t main() {
    







    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);


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
