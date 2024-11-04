



































using namespace std;
mt19937 mr(time(0));
typedef long long int ll;
typedef string str;
typedef double dbl;
struct LL {

    static ll m; 

    long long int val;

    LL(ll v) {val=reduce(v);};
    LL(int v) {val=reduce((ll)v);};
    LL() {val=0;};
    ~LL(){};
    LL(const LL& l) {val=l.val;};
    LL& operator=(int l) {val=l; return *this;}
    LL& operator=(ll l) {val=l; return *this;}
    LL& operator=(LL l) {val=l.val; return *this;}

    static void setMod(ll m) { assert(m); LL::m = m; }

    static long long int reduce(ll x, ll md = m) {
        x %= md;
        while (x >= md) x-=md;
        while (x < 0) x+=md;
        return x;
    }

    bool operator<(const LL& b) { return val<b.val; }
    bool operator<=(const LL& b) { return val<=b.val; }
    bool operator!=(const LL& b) { return val!=b.val; }
    bool operator==(const LL& b) { return val==b.val; }
    bool operator>=(const LL& b) { return val>=b.val; }
    bool operator>(const LL& b) { return val>b.val; }

    LL operator+(const LL& b) { return LL(val+b.val); }
    LL operator+(const ll& b) { return (*this+LL(b)); }
    LL& operator+=(const LL& b) { return (*this=*this+b); }
    LL& operator+=(const ll& b) { return (*this=*this+b); }

    LL operator-(const LL& b) { return LL(val-b.val); }
    LL operator-(const ll& b) { return (*this-LL(b)); }
    LL& operator-=(const LL& b) { return (*this=*this-b); }
    LL& operator-=(const ll& b) { return (*this=*this-b); }

    LL operator*(const LL& b) { return LL(val*b.val); }
    LL operator*(const ll& b) { return (*this*LL(b)); }
    LL& operator*=(const LL& b) { return (*this=*this*b); }
    LL& operator*=(const ll& b) { return (*this=*this*b); }

    static LL exp(const LL& x, const ll& y){
        ll z = y;
        z = reduce(z,m-1);
        LL ret = 1;
        LL w = x;
        while (z) {
            if (z&1) ret *= w;
            z >>= 1; w *= w;
        }
        return ret;
    }
    LL& operator^=(ll y) { return (*this=LL(val^y)); }

    LL operator/(const LL& b) { return ((*this)*exp(b,-1)); }
    LL operator/(const ll& b) { return (*this/LL(b)); }
    LL operator/=(const LL& b) { return ((*this)*=exp(b,-1)); }
    LL& operator/=(const ll& b) { return (*this=*this/LL(b)); }

}; ostream& operator<<(ostream& os, const LL& obj) { return os << obj.val; }
ll LL::m = MOD;

typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<int,LL> piL;
typedef pair<ll,ll> pll;
typedef pair<LL,LL> pLL;
typedef pair<dbl,dbl> pdd;
using namespace std;






























class oset {
public:
    struct Node {                                                               


        int id;
        Node* left;                                                             

        Node* right;                                                            


        int height;                                                             

        int nodeCount;                                                          


        int leftHeight() {                                                      

            if (left == nullptr) return 0;
            else return left->height;
        }

        int rightHeight() {                                                     

            if (right == nullptr) return 0;
            else return right->height;
        }

        int leftNodeCount() {                                                   

            if (left == nullptr) return 0;
            else return left->nodeCount;
        }

        int rightNodeCount() {                                                  

            if (right == nullptr) return 0;
            else return right->nodeCount;
        }


        void update() {                                                         

            height = 1 + max(leftHeight(), rightHeight());
            nodeCount = 1 + leftNodeCount() + rightNodeCount();
        }


        Node(int ID = 0,                                   

                Node* LEFT = nullptr, Node* RIGHT = nullptr) {                  

            id = ID;
            left = LEFT;
            right = RIGHT;
            update();
        }




    };

    Node* tree;
    oset() {
        tree = nullptr;
    }




    

    

    


    void printTree() { printTree(tree); }
    void printTree(Node* node, int depth = 0) {                                 

        for (int d = 0; d < depth; d++) cout << "    ";
        if (node == nullptr) cout << "nullptr" << endl;
        else {
            ++depth;
            for (int d = 0; d < depth-1; d++) cout << "    ";cout << "Left child {" << endl;
            printTree(node->left,depth);

            for (int d = 0; d < depth-1; d++) cout << "    ";cout << "} Right Child {" << endl;
            printTree(node->right,depth);

            for (int d = 0; d < depth-1; d++) cout << "    ";cout << "}" << endl;
        }
    }

    int sz() { return (tree==nullptr)?0:(tree->nodeCount); }
    int NLE(int a) { return NLE(a,tree); }
    int NLE(int a, Node* node) {
        if (node == nullptr) return 0;
        if (node->id>a) return NLE(a,node->left);
        else return NLE(a,node->right) + 1+((node->left==nullptr)?0:node->left->nodeCount);
    }
    int NLT(int a) {return NLE(a-1);}


    

    

    


    Node* rotateLeft(Node *node) {                                              

                                                                                


        if (node == nullptr) return node;                                       

        if (node->right == nullptr) return node;                                


        Node* ret = node->right;                                                

        node->right = ret->left;                                                

        ret->left = node;                                                       


        ret->left->update();                                                    

        ret->update();                                                          


        return ret;
    }


    Node* rotateRight(Node* node) {                                             

                                                                                


        if (node == nullptr) return node;                                       

        if (node->left == nullptr) return node;                                 


        Node* ret = node->left;                                                 

        node->left = ret->right;                                                

        ret->right = node;                                                      


        ret->right->update();                                                   

        ret->update();                                                          


        return ret;
    }




    

    

    



    pair<Node*,Node*> searchAndBalanceHelper(int id, Node* node) {              

                                                                                


        pair<Node*,Node*> ret = make_pair(nullptr, nullptr);                    


        if (node == nullptr) return ret;                                        

        else if (id == node->id) ret.first = node;                              

        else if (id < node->id) {                                               

            ret = searchAndBalanceHelper(id, node->left);                       

            node->left = ret.second;                                            

        } else {                                                                

            ret = searchAndBalanceHelper(id, node->right);                      

            node->right = ret.second;                                           

        }

        node->update();

        while (node->leftHeight() - node->rightHeight() >= 2) {                 

            if (node->left->id < id)                                        

                node->left = rotateLeft(node->left);
            node = rotateRight(node);
            return make_pair(ret.first, node);
        }

        while (node->rightHeight() - node->leftHeight() >= 2) {                 

            if (node->right->id > id)                                            

                node->right = rotateRight(node->right);
            node = rotateLeft(node);
            return make_pair(ret.first, node);
        }

        return make_pair(ret.first, node);
    }


    pair<Node*,Node*> searchAndBalanceHelper(Node* key, Node* node) {           

        return searchAndBalanceHelper(key->id, node);
    }


    Node* findParent(Node* key, Node* node) {                                   

                                                                                

        if (node == nullptr) return nullptr;                                    

        if (key->id == node->id) return key;                                    


        else if (key->id < node->id) {                                          


            Node* ret = findParent(key, node->left);                            

            if (ret == key) return node;                                        

            else return ret;                                                    


        } else {                                                                


            Node* ret = findParent(key, node->right);                           

            if (ret == key) return node;                                        

            else return ret;                                                    


        }
    }


    Node* findParent(int id, Node* node) {                                      

                                                                                

        Node* key = new Node(id);                                               

        Node* ret = findParent(key, node);                                      


        if (ret == key) ret = nullptr;                                          

        return ret;
    }


    Node* findInorder(int num, Node* node) {                                    

                                                                                

        if (node == nullptr) return nullptr;                                    

        else if (num < 0) return nullptr;                                       

        else if (num >= node->nodeCount) return nullptr;                        


        else if (num == node->leftNodeCount()) return node;                     

        else if (num > node->leftNodeCount())                                   

            return findInorder(num-node->leftNodeCount()-1, node->right);       

        else return findInorder(num, node->left);                               

    }




    

    

    



    Node* insertNodeHelp(Node* key, Node* node) {                               

                                                                                


        if (node->id == key->id) return nullptr;                                

        else if (node->id > key->id) {                                          


            if (node->left == nullptr) return node->left = key;                 

            else return insertNodeHelp(key, node->left);                        


        } else {                                                                


            if (node->right == nullptr) return node->right = key;               

            else return insertNodeHelp(key, node->right);                       


        }
    }


    pair<bool,Node*> insertNode(Node* key, Node* node) {                        

                                                                                


        Node* ret;                                                              

        if (node == nullptr) ret = (node = key);                                

        else ret = insertNodeHelp(key, node);                                   


        if (ret == nullptr) return make_pair(0,node);
        else {

            pair<Node*,Node*> found = searchAndBalanceHelper(key,node);         

            Node* chk = found.first;
            node = found.second;
            assert(chk == ret);                                                 

            return make_pair(1,node);

        }
    }


    pair<bool,Node*> insertNode(int id, Node* node) {              

        return insertNode(new Node(id), node);
    }

    void ins(int id) {
        tree = insertNode(id, tree).second;
    }



    

    

    



    pair<bool,Node*> removeNodeHelper(Node* found, Node* node) {                

                                                                                


        if (found==nullptr) return make_pair(0,node);                           


        int deg = 0 + ((found->left != nullptr)?1:0)                            

                    + ((found->right != nullptr)?2:0);
                                                                                

                                                                                


        int id = found->id;                                                     

        int parentId;
        Node* parent = findParent(id, node);                                    

        if (parent == nullptr) parentId = -69;                                  

        else parentId = parent->id;

        pair<bool,Node*> ret;                                                   


        if (deg == 0) {                                                         


            if (parent != nullptr) {                                            


                if (id<parentId) parent->left = nullptr;                        

                else parent->right = nullptr;                                   

                ret = make_pair(1,node);

            } else {
                ret = make_pair(1,nullptr);                                     

            }

        }

        if (deg == 1) {

            if (parent != nullptr) {                                            


                if (id<parentId) parent->left = found->left;                    

                else parent->right = found->left;                               

                ret = make_pair(1,node);

            } else {
                ret = make_pair(1,node->left);                                  

            }

        }

        if (deg == 2) {

            if (parent != nullptr) {                                            


                if (id<parentId) parent->left = found->right;                   

                else parent->right = found->right;                              

                ret = make_pair(1,node);

            } else {
                ret = make_pair(1,node->right);                                 

            }

        }

        if (deg == 3) {


            Node* successor = found->right;                                     

            Node* id0 = found;                                    


            while (successor->left != nullptr) {                                


                id0 = successor;
                successor = successor->left;

            }

            if (successor != found->right) {                                    


                id0->left = successor->right;
                successor->right = found->right;                                


            }

            successor->left = found->left;                                      


            if (parent != nullptr) {                                            


                if (id<parentId) parent->left = successor;                      

                else parent->right = successor;                                 

                ret = make_pair(1,node);

            } else {
                ret = make_pair(1,successor);                                   

            }

        }

        ret.second = searchAndBalanceHelper(id+1,ret.second).second;

        return ret;

    }


    pair<bool,Node*> removeNode(Node* key, Node* node) {                        

                                                                                

        pair<Node*,Node*> ret = searchAndBalanceHelper(key, node);              

        Node* found = ret.first;                                                

        node = ret.second;
        return removeNodeHelper(found, node);
    }


    pair<bool,Node*> removeNode(int idx, Node* node) {                          

                                                                                

        Node* key = findInorder(idx,node);                                      

        if (key == nullptr) return make_pair(false,node);                       

        else return removeNodeHelper(key,node);                                 

    }




    

    

    



    void printInorderHelperL(Node* node) {                                      


        if (node!=nullptr) {

            printInorderHelperL(node->left);
            cout << node->id << ", ";
            printInorderHelperL(node->right);

        }

    }


    void printInorderHelperR(Node* node) {                                      


        if (node!=nullptr) {

            printInorderHelperR(node->left);
            cout << ", " << node->id;
            printInorderHelperR(node->right);

        }

    }


    void printInorder(Node* node) {                                             


        if (node!=nullptr) {

            printInorderHelperL(node->left);
            cout << node->id;
            printInorderHelperR(node->right);

        }

        cout << endl;

    }

};

ll cases,N,M,Q,K,X,Y;

ll rd() {ll x;cin>>x; return x;}
dbl rdd() {dbl x;cin>>x; return x;}
str rds() {str x;cin>>x; return x;}
tc(T) void rds(char* S, T* sz) {*sz=strlen(strcpy(S,rds().c_str()));}
tc(T) void rG(int sz, vector<vector<T>>& adj, int E = -18852946) {
    if (E == -18852946) E = sz-1;
    adj.clear();
    F0(i,sz+1) adj.pb(vector<T>());
    F0(i,E) {
        T a = rd(); T b = rd();
        adj[a].pb(b); adj[b].pb(a);
    }
}

void fl() {cout.flush();}
void ds(int v) { cout << v << " "; }
void ds(ll v) { cout << v << " "; }
void ds(LL v) { cout << v << " "; }
void ds(dbl v) { cout << v << " "; }
void ds(char v) { cout << v << " "; }
void ds(str v) { cout << v << " "; }
void ds(char* v) { cout << v << " "; }
tcc(S,T) void ds(pair<S,T> v) {cout << v.f << " " << v.s << endl;}
tc(T) void ds(vector<T> v) { FE(x,v) ds(x); cout << endl; }
tc(T) void panic(T out) { ds(out); exit(0); }

tcc(S,T) bool updmin(S &a, T b) {
    S B = (S)b;
    if (B < a) {a = B; return 1;}
    return 0;
}

tcc(S,T) bool updmax(S &a, T b) {
    S B = (S)b;
    if (B > a) {a = B; return 1;}
    return 0;
}

tcc(S,T) S min(S a, T b) {
    S c = a; updmin(c, b); return c;
}

tcc(S,T) S max(S a, T b) {
    S c = a; updmax(c, b); return c;
}



bool witness(LL a, ll d, ll m) {
    LL x = LL::exp(a,m);
    if (x==LL(1)) return 1;
    F0(r,d) {
        if (x==LL(-1)) return 1;
        x = x*x;
    }
    return 0;
}



bool isPrime(ll x) {
    if (x < T6) {
        int j = 2;
        while (j*j <= x) {
            if (x%j==0) return 0;
            ++j;
        }
        return 1;
    }
    ll d = 0;
    ll m = 0;
    ll y = x;
    ll cur = LL::m;
    LL::m = x;
    bool ret = 1;
    while (y>>=1) {
        ++d; if (y&1) break;
    }
    m = y;
    if (x < 1e12) {
        ret = witness(2,d,m)
            && witness(13,d,m)
            && witness(23,d,m)
            && witness(1662803,d,m);
    } else {
        ret = witness(2,d,m)
            && witness(3,d,m)
            && witness(5,d,m)
            && witness(7,d,m)
            && witness(11,d,m)
            && witness(13,d,m)
            && witness(17,d,m)
            && witness(19,d,m)
            && witness(23,d,m)
            && witness(29,d,m)
            && witness(31,d,m)
            && witness(37,d,m)
            && witness(41,d,m);
    }
    LL::m = cur;
    return ret;
}




ll gcd(ll a, ll b) {
    return b?gcd(b, a % b):a;
}

void precalc() {
}

void reset() {
}

bool cmp(pii a, pii b) {
    return (a.s==b.s)?(a.f<b.f):(a.s<b.s);
}

bool debug = 0;

oset S = oset();
int ans(int Q) {
    return Q+(S.sz()>>1)-S.NLT(Q);
}
int fn(int x) {
    int L = x-200069;
    int R = x+200069;
    while (L<R-1) {
        int M = (L+R)>>1;
        

        if (ans(M)<=x) L=M;
        else R=M;
    }
    return L;
}

void read() {
    N = rd();
    int LASTANS = 0;
    F1(i,N) {
        X = rd(); K = rd();
        int a = fn(X);
        int b = fn(X-1);
        

        S.ins(a);
        S.ins(b);
        F0(j,K) {
            Q = (LASTANS+rd())%(MOD-6);
            cout << (LASTANS=ans(Q)) << endl;
        }
    }
}


int main() {

    precalc();

    bool trials = 0;
    bool interactive = 0;

    if (!interactive) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    if (trials) cases=rd();
    else cases=1;
    while (cases--) {
        read();
    }

}
