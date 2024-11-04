




using namespace std;
using namespace __gnu_pbds;



using ll = long long; using ld = long double;
using ii = pair<int, int>; using iii = tuple<int, int, int>;
using vb = vector<bool>; using vc = vector<char>; using vi = vector<int>; using vl = vector<long long>;
using vii = vector<ii>; using vll = vector<ll>;
using vvb = vector<vector<bool>>; using vvc = vector<vector<char>>; using vvi = vector<vector<int>>; using vvl= vector<vector<long long>>;
using Al = unordered_map<int, vi>; using AL = unordered_map<int, vi>;
using ordered_set = tree<int,null_type,less<>,rb_tree_tag,tree_order_statistics_node_update>;
using ordered_set_ii = tree<ii,null_type,less<>,rb_tree_tag,tree_order_statistics_node_update>;
using ordered_multiset =  tree<int,null_type,less_equal<>,rb_tree_tag,tree_order_statistics_node_update>; 




struct pair_hash {
    inline size_t operator()(const pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};













struct triple_hash {
    inline size_t operator()(const tuple<int,int,int> & v) const {
        auto &[a,b,c]=v;
        return a*31*31+b*31+c;
    }
};







































int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};































class UnionFind {                                

private:
    vi p, rank, setSize;                           

    int numSets;
public:
    UnionFind(int N) {
        p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);                           

        setSize.assign(N, 1);                        

        numSets = N;                                 

    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    int numDisjointSets() { return numSets; }      

    int sizeOfSet(int i) { return setSize[findSet(i)]; } 


    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;                 

        int x = findSet(i), y = findSet(j);          

        if (rank[x] > rank[y]) swap(x, y);           

        p[x] = y;                                    

        if (rank[x] == rank[y]) ++rank[y];           

        setSize[y] += setSize[x];                    

        --numSets;                                   

    }
};




class id1 {                              

private:
    vll ft;                                        

public:
    id1(int m) { ft.assign(m+1, 0); }      


    void build(const vll &f) {
        int m = (int)f.size()-1;                     

        ft.assign(m+1, 0);
        for (int i = 1; i <= m; ++i) {               

            ft[i] += f[i];                             

            if (i+LSOne(i) <= m)                       

                ft[i+LSOne(i)] += ft[i];                 

        }
    }

    id1(const vll &f) { build(f); }        


    id1(int m, const vi &s) {              

        vll f(m+1, 0);
        for (int i = 0; i < (int)s.size(); ++i)      

            ++f[s[i]];                                 

        build(f);                                    

    }

    ll rsq(int j) {                                

        ll sum = 0;
        for (; j; j -= LSOne(j))
            sum += ft[j];
        return sum;
    }

    ll rsq(int i, int j) { return rsq(j) - rsq(i-1); } 


    

    void update(int i, ll v) {
        for (; i < (int)ft.size(); i += LSOne(i))
            ft[i] += v;
    }

    int select(ll k) {                             

        int p = 1;
        while (p*2 < (int)ft.size()) p *= 2;
        int i = 0;
        while (p) {
            if (k > ft[i+p]) {
                k -= ft[i+p];
                i += p;
            }
            p /= 2;
        }
        return i+1;
    }
};

class id2 {                                     

private:
    id1 ft;                                

public:
    id2(int m) : ft(id1(m)) {}
    void range_update(int ui, int uj, ll v) {
        ft.update(ui, v);                            

        ft.update(uj+1, -v);                         

    }                                              

    ll point_query(int i) { return ft.rsq(i); }    

};

class id0  {                                    

private:                                         

    id2 rupq;                                     

    id1 purq;                              

public:
    id0(int m) : rupq(id2(m)), purq(id1(m)) {} 

    void range_update(int ui, int uj, ll v) {
        rupq.range_update(ui, uj, v);                

        purq.update(ui, v*(ui-1));                   

        purq.update(uj+1, -v*uj);                    

    }
    ll rsq(int j) {
        return rupq.point_query(j)*j -               

               purq.rsq(j);                          

    }
    ll rsq(int i, int j) { return rsq(j) - rsq(i-1); } 

};






























































































































































































































































































































































































































































































































































































































































































int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        if (n == 4) {
            cout << "1 1 1 1" << endl;
            continue;
        }
        if (n == 6) {
            cout << "3 1 1 1" << endl;
            continue;
        }
        n-=2;
        if (n%2) {
            cout << n / 2 << " " << n - n / 2 << " 1 1" << endl;
        } else {
            n -= 4;
            cout << n << " " << 2 << " 2 2" << endl;
        }
    }
}