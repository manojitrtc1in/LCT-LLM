#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

typedef double dbl;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<dbl,dbl> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<dbl> vd;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<pii> vp;

#define eps 1e-9
#define inf 1000000000
#define infll 1000000000000000000LL
#define infdbl 1e15
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define px first
#define py second
#define sz(x) ((int)(x).size())
#define intclz(x) __builtin_clz(x)
#define intctz(x) __builtin_ctz(x)
#define intln(x) (32-intclz(x))
#define intbc(x) __builtin_popcount(x)
#define llclz(x) __builtin_clzll(x)
#define llctz(x) __builtin_ctzll(x)
#define llln(x) (64-llclz(x))
#define llbc(x) __builtin_popcountll(x)
#define atbit(x,i) (((x)>>(i))&1)
#define tof(x) __typeof(x)
#define FORab(i,a,b) for (int i=(a); i<=(b); ++i)
#define RFORab(i,a,b) for (int i=(a); i>=(b); --i)
#define FOR1(i,n) FORab(i,1,(n))
#define RFOR1(i,n) RFORab(i,(n),1)
#define FOR(i,n) FORab(i,0,(n)-1)
#define RFOR(i,n) RFORab(i,(n)-1,0)
#define allstl(i,x,t) for (t::iterator i = (x).begin(); i!=(x).end(); ++i)
#define rallstl(i,x,t) for (t::reverse_iterator i = (x).rbegin(); i!=(x).rend(); ++i)
#define begend(x) (x).begin(),(x).end()
#define rbegend(x) (x).rbegin(),(x).rend()
#define ms(a,v) memset(a,v,sizeof(a))
#define msn(a,v,n) memset(a,v,n*sizeof(a[0]))
#define mcp(d,s,n) memcpy(d,s,n*sizeof(s[0]))
#define clamp(x,a,b) min(max(x,a),b)




namespace suffix_tree {
    const int charclass = 27;

    int id(char c) {
        if (islower(c)) return c-'a';
        else if (c == '$') return 26;
        return -1;
    }

    struct node;
    struct active_state {
        node* cnode;
        node* suffix_link_from;
        char cedge;
        int clen;
        int remainder;
        active_state(node* cnode=NULL, char cedge=0, char clen=0, int remainder=0) : cnode(cnode), suffix_link_from(NULL), cedge(cedge), clen(clen), remainder(remainder) {}

        string show();
    };

    node *pool;
    int poolsz;
    node* alloc_node(int data);

    struct node {
        int data;
        
        int from, to;
        node* parent;
        node* suffix_link;
        node* nxt[charclass];

        node* next(char c) {
            if (id(c) == -1) return NULL;
            return nxt[id(c)];
        }

        void reset(int _data) {
            data = _data;
            from = to = -1;
            parent = suffix_link = NULL;
            FOR(i,charclass) nxt[i] = NULL;
        }

        node* split(string& s, int breaklen, int newfrom, node* suffix_link_from) { 

            node* A = alloc_node(poolsz); 

            node* B = alloc_node(poolsz); 


            A->parent = parent;
            parent = B->parent = A;

            A->from = from, A->to = from + breaklen;
            from = A->to;
            B->from = newfrom;

            A->nxt[id(s[from])] = this;
            A->nxt[id(s[newfrom])] = B;

            if (suffix_link_from != NULL) suffix_link_from->suffix_link = A;
#ifdef debug
            cerr<<"after split : P "<<show()<<", A "<<A->show()<<", B "<<B->show();
            if (suffix_link_from != NULL) cerr<<" with sfx_link from "<<suffix_link_from->show();
            cerr<<endl;
#endif
            return A;
        }

        string show() {
            if (from == -1) return "(ROOT)";
            char s[100];
            sprintf(s, "(%d,%d)[%d]", from, to, data);
            return string(s);
        }
    };

    struct sfxMachine {
        ll distinct_substrings;
        int leaves;
        
        node* root;
        string s;

        active_state cstate;

        void init() {
            cstate = active_state();
            cstate.cnode = root = alloc_node(0);
            root->data = 0;

            distinct_substrings = leaves = 0;
        }

        void extend(int at) {
            stack<int> stk;
            stk.push(at);
            while (!stk.empty()) {
                at = stk.top();
                stk.pop();
                node* cur = cstate.cnode;
                if (!cstate.remainder) continue;
#ifdef debug
                cerr<<"--"<<cstate.show()<<endl;
#endif
                while (cstate.clen and cur->nxt[id(cstate.cedge)]->to != -1 and cur->nxt[id(cstate.cedge)]->from + cstate.clen >= cur->nxt[id(cstate.cedge)]->to) {
                    cstate.cnode = cur->nxt[id(cstate.cedge)];
                    cstate.clen -= cur->nxt[id(cstate.cedge)]->to - cur->nxt[id(cstate.cedge)]->from;
                    if (cstate.clen) {
                        cstate.cedge = s[at - cstate.clen];
                    } else {
                        cstate.cedge = 0;
                    }
                    cur = cstate.cnode;
#ifdef debug
                    cerr<<"-stepped with '"<<s[at]<<"' from the node "<<cur->show()<<" over edge ["<<cstate.cnode->show()<<"]"<<endl;
#endif
                }
                if (cstate.clen) {
#ifdef debug
                    cerr<<"in middle of edge "<<cstate.show()<<' '<<(cur->nxt[id(cstate.cedge)]==NULL)<<endl;
#endif
                    if (s[ cur->nxt[id(cstate.cedge)]->from + cstate.clen ] == s[at]) { 

#ifdef debug
                        cerr<<"continuing with '"<<s[at]<<"' from the node "<<cur->show()<<" to edge ["<<cur->nxt[id(cstate.cedge)]->show()<<"]"<<endl;
#endif
                        ++cstate.clen;
                        if (cur->nxt[id(cstate.cedge)]->from + cstate.clen == cur->nxt[id(cstate.cedge)]->to) {
                            cstate.cnode = cur->nxt[id(cstate.cedge)];
                            cstate.cedge = 0;
                            cstate.clen = 0;
#ifdef debug
                            cerr<<":stepped with '"<<s[at]<<"' from the node "<<cur->show()<<" over edge ["<<cstate.cnode->show()<<"]"<<endl;
#endif
                        }
                    } else { 

                        ++leaves;

                        node* P = cur->nxt[id(cstate.cedge)]; 

                        --cstate.remainder; 

#ifdef debug
                        cerr<<"splitting with '"<<s[at]<<"' the edge "<<P->show()<<endl;
#endif
                        cstate.suffix_link_from = P = cur->nxt[id(cstate.cedge)] = P->split(s, cstate.clen, at, cstate.suffix_link_from); 

                        P->suffix_link = root;

                        if (cur == root) {
                            if (cstate.clen) {
                                --cstate.clen;
                                cstate.cedge = s[at - cstate.clen];
#ifdef debug
                                cerr<<"root split "<<cstate.show()<<endl;
#endif
                            }
                        } else if (cur->suffix_link != NULL) {
                            cstate.cnode = cur->suffix_link;
#ifdef debug
                            cerr<<"following suffix link "<<cstate.cnode->show()<<endl;
#endif
                        } else {
                            cstate.cnode = root;
#ifdef debug
                            cerr<<"no suffix link, jumping to "<<cstate.cnode->show()<<endl;
#endif
                        }
                        stk.push(at);
                    }
                } else {
                    if (cur->nxt[id(s[at])] != NULL) { 

                        cstate.cedge = s[at];
                        cstate.clen = 1;
                        if (cur->nxt[id(cstate.cedge)]->from + cstate.clen == cur->nxt[id(cstate.cedge)]->to) {
                            cstate.cnode = cur->nxt[id(s[at])];
                            cstate.cedge = 0;
                            cstate.clen = 0;
                            if (cstate.suffix_link_from != NULL) cstate.suffix_link_from->suffix_link = cur;
                            cstate.suffix_link_from = cur;
#ifdef debug
                            cerr<<"stepped with '"<<s[at]<<"' from the node "<<cur->show()<<" over edge ["<<cstate.cnode->show()<<"]"<<endl;
                            if (cstate.suffix_link_from != NULL) cerr<<"with sfx_link from "<<cstate.suffix_link_from->show()<<" to "<<cur->show()<<endl;
#endif
                        } else {
                            if (cstate.suffix_link_from != NULL) cstate.suffix_link_from->suffix_link = cur;
                            cstate.suffix_link_from = cur;
#ifdef debug
                            cerr<<"going with '"<<s[at]<<"' from the node "<<cur->show()<<" to edge ["<<cur->nxt[id(s[at])]->show()<<"]"<<endl;
                            if (cstate.suffix_link_from != NULL) cerr<<"with sfx_link from "<<cstate.suffix_link_from->show()<<" to "<<cur->show()<<endl;
#endif
                        }
                    } else { 

                        ++leaves;

                        --cstate.remainder; 

                        node* C = alloc_node(poolsz);
                        C->parent = cur;
                        C->from = at;
                        cur->nxt[id(s[at])] = C;
                        if (cstate.suffix_link_from != NULL) cstate.suffix_link_from->suffix_link = cur;
                        cstate.suffix_link_from = cur;
#ifdef debug
                        cerr<<"..........direct insert with '"<<s[at]<<"' at "<<cur->show()<<" ["<<C->show()<<"]"<<endl;
                        cerr<<cstate.show()<<endl;
                        if (cstate.suffix_link_from != NULL) cerr<<"with sfx_link from "<<cstate.suffix_link_from->show()<<" to "<<cur->show()<<endl;
#endif
                        if (cur == root) {
                            if (cstate.clen) {
                                --cstate.clen;
                                cstate.cedge = s[at - cstate.clen];
#ifdef debug
                                cerr<<"root split "<<cstate.show()<<endl;
#endif
                            }
                        } else if (cur->suffix_link != NULL) {
                            cstate.cnode = cur->suffix_link;
#ifdef debug
                            cerr<<"following suffix link "<<cstate.cnode->show()<<endl;
#endif
                        } else {
                            cstate.cnode = root;
#ifdef debug
                            cerr<<"no suffix link, jumping to "<<cstate.cnode->show()<<endl;
#endif
                        }
                        stk.push(at);
                    }
                }
            }
        }

        void build() {
            init();
            FOR(i,sz(s)) {
                cstate.suffix_link_from = NULL;
                ++cstate.remainder;
#ifdef debug
                cerr<<"processing at "<<i<<"("<<s[i]<<")"<<endl;
                cerr<<cstate.show()<<endl;
#endif
                extend(i);
                distinct_substrings += leaves;
#ifdef debug
                cerr<<endl;
#endif
            }
        }

        bool go(char c) { 

            if (id(c)==-1) return false;
            if (cstate.clen) { 

                if (s[ cstate.cnode->nxt[id(cstate.cedge)]->from + cstate.clen ] == c) { 

                    ++cstate.clen;
                    if (cstate.cnode->nxt[id(cstate.cedge)]->from + cstate.clen == cstate.cnode->nxt[id(cstate.cedge)]->to) {
                        cstate.cnode = cstate.cnode->nxt[id(cstate.cedge)];
                        cstate.cedge = 0;
                        cstate.clen = 0;
                    }
                    return true;
                } else { 

                    return false;
                }
            } else {
                if (cstate.cnode->nxt[id(c)] != NULL) { 

                    cstate.cedge = c;
                    cstate.clen = 1;
                    if (cstate.cnode->nxt[id(c)]->from + cstate.clen == cstate.cnode->nxt[id(c)]->to) {
                        cstate.cnode = cstate.cnode->nxt[id(c)];
                        cstate.cedge = 0;
                        cstate.clen = 0;
                    }
                    return true;
                } else { 

                    return false;
                }
            }
        }

        bool cango(char c) { 

            if (id(c)==-1) return false;
            if (cstate.clen) { 

                if (s[ cstate.cnode->nxt[id(cstate.cedge)]->from + cstate.clen ] == c) { 

                    return true;
                } else { 

                    return false;
                }
            } else {
                if (cstate.cnode->nxt[id(c)] != NULL) { 

                    return true;
                } else { 

                    return false;
                }
            }
        }

        bool leaf_path() { 

            node* x = cstate.cnode->next(cstate.cedge);
            return (x and x->to == -1);
        }

        void show() {
            int idx = 0;
            FOR(j,poolsz) {
                auto i = pool + j;
                if (!idx) ++idx;
                else {
                    cerr<<"at node "<<i->data<<", parent "<<i->parent->data<<" : "<<i->from<<','<<i->to<<' '<<s.substr(i->from,(i->to==-1?s.length():i->to) - i->from)<<", sfx link : "<<(i->suffix_link?i->suffix_link->data : -1)<<endl;
                    ++idx;
                }
            }
        }
    };

    node* alloc_node(int data) {
        pool[poolsz].reset(poolsz);
        return &(pool[poolsz++]);
    }

    string active_state::show() {
        char s[100];
        sprintf(s, ", %c, %d, remainder %d", cedge?cedge:'#', clen, remainder);
        return cnode->show() + string(s);
    }
}




char s1[5009];
char s2[5009];

suffix_tree::node Pool[20109];

void gen() {
    srand(time(NULL));
    freopen("in2.txt", "wt", stdout);
    int T = 100;
    FOR(cas,T) {
        int n = 5000;
        FOR(i,n) cout<<(char)(rand()%26 + 'a');
        cout<<endl;
        FOR(i,n) cout<<(char)(rand()%26 + 'a');
        cout<<endl;
    }
}

int main() {
    

    


    

    


    while (scanf("%s%s", s1, s2) == 2) {
        int z2 = strlen(s2);
        suffix_tree::pool = Pool;
        suffix_tree::poolsz = 0;

        suffix_tree::sfxMachine t1, t2;
        t1.s = s1; t1.s += '$'; t1.build();
        

        t2.s = s2; t2.s += '$'; t2.build();
        


        int L = -1;
        FOR(b,z2) {
            t1.cstate = suffix_tree::active_state(t1.root);
            t2.cstate = suffix_tree::active_state(t2.root);
            FORab(e,b,z2-1) {
                if (!t1.go(s2[e])) break;
                assert(t2.go(s2[e]));
                if (L == -1 or e-b+1 < L) {
                    if (t1.leaf_path() and t2.leaf_path()) {
                        L = e-b+1;
                    }
                }
            }
        }
        cout<<L<<endl;
        

    }

    return 0;
}
