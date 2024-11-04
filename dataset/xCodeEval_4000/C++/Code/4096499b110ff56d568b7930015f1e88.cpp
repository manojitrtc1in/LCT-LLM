#include<algorithm>
#include<cctype>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<functional>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>
#define sf scanf
#define pf printf
#define fr freopen
#define ps for(;;)
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(int i=a;i<=b;++i)
#define rp(i,a,b) for(int i=a;i>=b;--i)
#define vp(i,a) for(int i=0;i<int(a.size());++i)
#define wp(i,a) for(int i=int(a.size())-1;i>=0;--i)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
namespace DataStructures{
    template<class VAL,class CMP=std::less<VAL> >class Set{
    private:
        struct node{
            inline node(const VAL&_value,node*_left,node*_right,
                node*_parent,const bool&_black,const int&_size):
            value(_value),left(_left),right(_right),
                parent(_parent),black(_black),size(_size){
            }
            VAL value;
            node*left,*right,*parent;
            bool black;
            int size;
        }*root,*nil;
        inline void clear(node*x){
            if(x!=nil){
                clear(x->left);
                clear(x->right);
                delete x;
            }
        }
        inline void left_rotate(node*x){
            node*y=x->right;
            x->right=y->left;
            if(y->left!=nil)
                y->left->parent=x;
            y->parent=x->parent;
            if(x->parent==nil)
                root=y;
            else if(x==x->parent->left)
                x->parent->left=y;
            else
                x->parent->right=y;
            y->left=x;
            x->parent=y;
            y->size=x->size;
            x->size=x->left->size+x->right->size+1;
        }
        inline void right_rotate(node*x){
            node*y=x->left;
            x->left=y->right;
            if(y->right!=nil)
                y->right->parent=x;
            y->parent=x->parent;
            if(x->parent==nil)
                root=y;
            else if(x==x->parent->left)
                x->parent->left=y;
            else
                x->parent->right=y;
            y->right=x;
            x->parent=y;
            y->size=x->size;
            x->size=x->left->size+x->right->size+1;
        }
        inline void insert_fixup(node*z){
            while(!z->parent->black){
                if(z->parent==z->parent->parent->left){
                    node*y=z->parent->parent->right;
                    if(!y->black){
                        z->parent->black=true;
                        y->black=true;
                        (z=z->parent->parent)->black=false;
                    }else{
                        if(z==z->parent->right)
                            left_rotate(z=z->parent);
                        z->parent->black=true;
                        z->parent->parent->black=false;
                        right_rotate(z->parent->parent);
                    }
                }else{
                    node*y=z->parent->parent->left;
                    if(!y->black){
                        z->parent->black=true;
                        y->black=true;
                        (z=z->parent->parent)->black=false;
                    }else{
                        if(z==z->parent->left)
                            right_rotate(z=z->parent);
                        z->parent->black=true;
                        z->parent->parent->black=false;
                        left_rotate(z->parent->parent);
                    }
                }
            }
            root->black=true;
        }
        inline void erase(node*z){
            node*y;
            for(y=z;y!=nil;y=y->parent)
                --y->size;
            if(z->left==nil||z->right==nil)
                y=z;
            else{
                y=z->right;
                while(y->left!=nil)
                    y=y->left;
                z->value=y->value;
                y=z->right;
                while(y->left!=nil){
                    --y->size;
                    y=y->left;
                }
            }
            node*x=y->left==nil?y->right:y->left;
            x->parent=y->parent;
            if(y->parent==nil)
                root=x;
            else if(y==y->parent->left)
                y->parent->left=x;
            else
                y->parent->right=x;
            if(y->black)
                erase_fixup(x);
            delete y;
        }
        inline void erase_fixup(node*x){
            while(x!=root&&x->black){
                if(x==x->parent->left){
                    node*w=x->parent->right;
                    if(!w->black){
                        w->black=true;
                        x->parent->black=false;
                        left_rotate(x->parent);
                        w=x->parent->right;
                    }
                    if(w->left->black&&w->right->black){
                        w->black=false;
                        x=x->parent;
                    }else{
                        if(w->right->black){
                            w->left->black=true;
                            w->black=false;
                            right_rotate(w);
                            w=x->parent->right;
                        }
                        w->black=x->parent->black;
                        x->parent->black=true;
                        w->right->black=true;
                        left_rotate(x->parent);
                        x=root;
                    }
                }else{
                    node*w=x->parent->left;
                    if(!w->black){
                        w->black=true;
                        x->parent->black=false;
                        right_rotate(x->parent);
                        w=x->parent->left;
                    }
                    if(w->left->black&&w->right->black){
                        w->black=false;
                        x=x->parent;
                    }else{
                        if(w->left->black){
                            w->right->black=true;
                            w->black=false;
                            left_rotate(w);
                            w=x->parent->left;
                        }
                        w->black=x->parent->black;
                        x->parent->black=true;
                        w->left->black=true;
                        right_rotate(x->parent);
                        x=root;
                    }
                }
            }
            x->black=true;
        }
        inline node*clone(node*x,node*y){
            if(x.size==0)
                return nil;
            node*z=new node(*x);
            z->left=clone(x->left,z);
            z->right=clone(x->right,z);
            z->parent=y;
            return z;
        }
    public:
        class Iterator{
        private:
            node*pointer;
            friend class Set;
            inline Iterator(node*_pointer=0):
            pointer(_pointer){
            }
            inline node*precursor(node*x){
                if(x->left->size){
                    x=x->left;
                    while(x->right->size)
                        x=x->right;
                    return x;
                }else{
                    node*y=x->parent;
                    while(y->size&&x==y->left){
                        x=y;
                        y=y->parent;
                    }
                    return y;
                }
            }
            inline node*successor(node*x){
                if(x->right->size){
                    x=x->right;
                    while(x->left->size)
                        x=x->left;
                    return x;
                }else{
                    node*y=x->parent;
                    while(y->size&&x==y->right){
                        x=y;
                        y=y->parent;
                    }
                    return y;
                }
            }
        public:
            inline Iterator(){
            }
            inline bool operator==(const Iterator&a){
                return pointer==a.pointer;
            }
            inline bool operator!=(const Iterator&a){
                return pointer!=a.pointer;
            }
            inline const VAL&operator*(){
                return pointer->value;
            }
            inline VAL*operator->(){
                return &pointer->value;
            }
            inline Iterator&operator++(){
                pointer=successor(pointer);
                return*this;
            }
            inline Iterator operator++(int){
                Iterator t=*this;
                pointer=successor(pointer);
                return t;
            }
            inline Iterator&operator--(){
                pointer=precursor(pointer);
                return*this;
            }
            inline Iterator operator--(int){
                Iterator t=*this;
                pointer=precursor(pointer);
                return t;
            }
        };
        inline Set(){
            root=nil=(node*)malloc(sizeof(node));
            nil->black=true;
            nil->size=0;
        }
        inline Set(const Set&a){
            nil=new node(*a.nil);
            root=clone(a.root,nil);
        }
        inline~Set(){
            clear(root);
            free(nil);
        }
        inline Set&operator=(const Set&a){
            clear(root);
            root=clone(a.root,nil);
            return*this;
        }
        inline Iterator Begin(){
            node*z=root;
            while(z!=nil&&z->left!=nil)
                z=z->left;
            return Iterator(z);
        }
        inline Iterator ReverseBegin(){
            node*z=root;
            while(z!=nil&&z->right!=nil)
                z=z->right;
            return Iterator(z);
        }
        inline Iterator End(){
            return Iterator(nil);
        }
        inline Iterator ReverseEnd(){
            return Iterator(nil);
        }
        inline void Clear(){
            clear(root);
            root=nil;
        }
        inline void Insert(const VAL&a){
            node*y=nil,*x=root;
            while(x!=nil){
                y=x;
                ++x->size;
                if(CMP()(a,x->value))
                    x=x->left;
                else
                    x=x->right;
            }
            node*z=new node(a,nil,nil,y,false,1);
            if(y==nil)
                root=z;
            else if(CMP()(z->value,y->value))
                y->left=z;
            else
                y->right=z;
            insert_fixup(z);
        }
        inline void Erase(const Iterator&a){
            erase(a.pointer);
        }
        inline void Erase(const Iterator&a,Iterator&b){
            for(Iterator i=a;i!=b;Erase(i++));
        }
        inline void Erase(const VAL&a){
            node*z=root;
            while(true){
                if(CMP()(a,z->value))
                    z=z->left;
                else if(CMP()(z->value,a))
                    z=z->right;
                else
                    break;
            }
            erase(z);
        }
        inline int Count(const VAL&a){
            return CountLessEqual(a)-CountLess(a);
        }
        inline int CountLess(const VAL&a){
            int r=0;
            node*z=root;
            while(z!=nil){
                if(CMP()(z->value,a)){
                    r+=z->left->size+1;
                    z=z->right;
                }else
                    z=z->left;
            }
            return r;
        }
        inline int CountLessEqual(const VAL&a){
            int r=0;
            node*z=root;
            while(z!=nil){
                if(!CMP()(a,z->value)){
                    r+=z->left->size+1;
                    z=z->right;
                }else
                    z=z->left;
            }
            return r;
        }
        inline int CountGreater(const VAL&a){
            int r=0;
            node*z=root;
            while(z!=nil){
                if(CMP()(a,z->value)){
                    r+=z->right->size+1;
                    z=z->left;
                }else
                    z=z->right;
            }
            return r;
        }
        inline int CountGreaterEqual(const VAL&a){
            int r=0;
            node*z=root;
            while(z!=nil){
                if(!CMP()(z->value,a)){
                    r+=z->right->size+1;
                    z=z->left;
                }else
                    z=z->right;
            }
            return r;
        }
        inline Iterator NthElement(int a){
            node*z=root;
            while(true){
                if(z->left->size>=a)
                    z=z->left;
                else if((z->left->size+1)<a){
                    a-=z->left->size+1;
                    z=z->right;
                }else
                    return Iterator(z);
            }
        }
        inline Iterator Precursor(const VAL&a){
            node*z=root,*r=nil;
            while(z!=nil){
                if(CMP()(z->value,a)){
                    r=z;
                    z=z->right;
                }else
                    z=z->left;
            }
            return Iterator(r);
        }
        inline Iterator Successor(const VAL&a){
            node*z=root,*r=nil;
            while(z!=nil){
                if(CMP()(a,z->value)){
                    r=z;
                    z=z->left;
                }else
                    z=z->right;
            }
            return Iterator(r);
        }
        inline Iterator Find(const VAL&a){
            node*z=root,*r=nil;
            while(z!=nil){
                if(CMP()(a,z->value))
                    z=z->left;
                else if(CMP()(z->value,a))
                    z=z->right;
                else break;
            }
            return Iterator(r);
        }
        inline Iterator LowerBound(const VAL&a){
            node*z=root,*r=nil;
            while(z!=nil){
                if(!CMP()(z->value,a)){
                    r=z;
                    z=z->left;
                }else
                    z=z->right;
            }
            return Iterator(r);
        }
        inline Iterator UpperBound(const VAL&a){
            return Successor(a);
        }
        inline std::pair<Iterator,Iterator> EqualRange(const VAL&a){
            return std::make_pair(LowerBound(a),UpperBound(a));
        }
        inline int Size(){
            return root->size;
        }
        inline bool Empty(){
            return root->size==0;
        }
        inline const VAL&Front(){
            return*Begin();
        }
        inline const VAL&Back(){
            return*ReverseBegin();
        }
    };
    template<class IFO>class DynamicTree{
    private:
        struct node{
            inline node(const IFO&_ifo):
            ch({0,0}),pr(0),ifo(_ifo),rev(false){
            }
            node*ch[2],*pr;
            IFO ifo;
            bool rev;
        };
        inline int direct(node*x){
            if(!x->pr)
                return 2;
            if(x==x->pr->ch[0])
                return 0;
            if(x==x->pr->ch[1])
                return 1;
            return 2;
        }
        inline void down(node*x){
            if(x->rev){
                x->ifo.Reverse();
                swap(x->ch[0],x->ch[1]);
                for(int i=0;i<2;++i)
                    if(x->ch[i])
                        x->ch[i]->rev^=1;
                x->rev=false;
            }
            x->ifo.Down(x->ch[0]?&x->ch[0]->ifo:0,x->ch[1]?&x->ch[1]->ifo:0);
        }
        inline void update(node*x){
            for(int i=0;i<2;++i)
                if(x->ch[i])
                    down(x->ch[i]);
            x->ifo.Update(x->ch[0]?&x->ch[0]->ifo:0,x->ch[1]?&x->ch[1]->ifo:0);
        }
        inline void setchd(node*x,node*y,int d){
            x->ch[d]=y;
            if(y)
                y->pr=x;
            update(x);
        }
        inline void rotate(node*x){
            node*y=x->pr,*z=y->pr;
            int d1=direct(x),d2=direct(y);
            setchd(y,x->ch[!d1],d1);
            setchd(x,y,!d1);
            if(d2<2)
                setchd(z,x,d2);
            else
                x->pr=z;
        }
        inline void release(node*x){
            if(direct(x)<2)
                release(x->pr);
            down(x);
        }
        inline void splay(node*x){
            release(x);
            while(direct(x)<2){
                node*y=x->pr;
                if(direct(y)==2)
                    rotate(x);
                else if(direct(x)==direct(y))
                    rotate(y),rotate(x);
                else
                    rotate(x),rotate(x);
            }
        }
        inline node*access(node*x){
            node*y=0;
            while(x){
                splay(x);
                setchd(x,y,1);
                y=x;
                x=x->pr;
            }
            return y;
        }
        inline void evert(node*x){
            access(x);
            splay(x);
            x->rev=1;
        }
    public:
        class Pointer{
        private:
            node*p;
            friend class DynamicTree;
        public:
            inline Pointer(node*_p=0):
            p(_p){
            }
            inline bool operator==(const Pointer&a){
                return p==a.p;
            }
            inline bool operator!=(const Pointer&a){
                return p!=a.p;
            }
            inline const IFO&operator*(){
                return p->ifo;
            }
            inline const IFO*operator->(){
                return &p->ifo;
            }
        };
        inline Pointer Make(const IFO&a){
            return new node(a);
        }
        inline bool Linked(const Pointer&a,const Pointer&b){
            access(a.p);
            node*z=access(b.p);
            return z==access(a.p);
        }
        inline void Link(const Pointer&a,const Pointer&b){
            evert(b.p);
            b.p->pr=a.p;
        }
        inline void Cut(const Pointer&a,const Pointer&b){
            access(b.p);
            node*z=access(a.p);
            if(z==a.p){
                splay(b.p);
                b.p->pr=0;
            }else{
                access(b.p);
                splay(a.p);
                a.p->pr=0;
            }
        }
        inline Pointer Root(const Pointer&a){
            access(a.p);
            splay(a.p);
            node*r=a.p;
            while(r->ch[1])
                r=r->ch[1];
            return Pointer(r);
        }
        inline void Evert(const Pointer&a){
            evert(a.p);
        }
        inline Pointer LCA(const Pointer&a,const Pointer&b){
            access(a.p);
            return Pointer(access(b.p));
        }
        inline IFO Query(const Pointer&a){
            splay(a.p);
            IFO p=a.p->ifo;
            p.Update(0,0);
            return p;
        }
        inline IFO Query(const Pointer&a,const Pointer&b){
            if(a.p==b.p)
                return Query(a.p);
            access(a.p);
            node*c=access(b.p);
            IFO p=c.ifo;
            if(c==b.p){
                splay(a.p);
                IFO q=a.p->ifo;
                q.Reverse();
                p.Update(&q,0);
                return p;
            }else if(c==a.p)
                p.Update(0,&a.p->ch[1]->ifo);
            else{
                splay(a.p);
                IFO q=a.p->ifo;
                q.Reverse();
                p.Update(&q,&c->ch[1]->ifo);
            }
            return p;
        }
        inline IFO EdgeQuery(const Pointer&a){
            return Query(a);
        }
        inline IFO EdgeQuery(const Pointer&a,const Pointer&b){
            access(a.p);
            node*c=access(b.p);
            if(c==b.p){
                splay(a.p);
                IFO q=a.p->ifo;
                q.Reverse();
                return q;
            }else if(c==a.p)
                return a.p->ch[1]->ifo;
            else{
                splay(a.p);
                node*t=c->ch[1];
                while(t->ch[0])
                    t=t->ch[0];
                splay(t);
                if(t->ch[1])
                    down(t->ch[1]);
                IFO p=t->ifo,q=a.p->ifo;
                q.Reverse();
                p.Update(&q,t->ch[1]?&t->ch[1]->ifo:0);
                return p;
            }
        }
        inline void Modify(const Pointer&a,const std::function<void(IFO*)>&f){
            splay(a.p);
            f(&a.p->ifo);
            update(a.p);
        }
        inline void Modify(const Pointer&a,const Pointer&b,const std::function<void(IFO*,IFO*,IFO*)>&f){
            if(a.p==b.p){
                splay(a.p);
                f(0,&a.p->ifo,0);
                update(a.p);
                return ;
            }
            access(a.p);
            node*c=access(b.p);
            IFO p=c->ifo;
            if(c==b.p){
                splay(a.p);
                f(&a.p->ifo,&b.p->ifo,0);
            }else if(c==a)
                f(0,&a.p->ifo,&a.p->ch[1]->ifo);
            else{
                splay(a);
                f(&a.p->ifo,&c->ifo,&c->ch[1]->ifo);
            }
            update(c);
        }
        inline void EdgeModify(const Pointer&a,const std::function<void(IFO*)>&f){
            Modify(a,f);
        }
        inline void EdgeModify(const Pointer&a,const Pointer&b,const std::function<void(IFO*,IFO*)>&f){
            access(a.p);
            node*c=access(b.p);
            IFO p=c->ifo;
            if(c==b.p){
                splay(a.p);
                f(&a.p->ifo,0);
            }else if(c==a)
                f(0,&a.p->ch[1]->ifo);
            else{
                splay(a);
                f(&a.p->ifo,&c->ch[1]->ifo);
            }
            update(c);
        }
    };
}
using namespace DataStructures;
int n,q,f[100010];
vi to[100010],wi[100010];
int prt[100010],prtw[100010];
struct Info{
    int val,sum,lc1,rc1,ful1;
    Info(int _val):val(_val){
        if(val==0)
            sum=0;
        else
            sum=f[1];
        lc1=val;
        rc1=val;
        ful1=val;
    }
    void Down(Info*a,Info*b){
    }
    void Update(Info*a,Info*b){
        if(a==0&&b==0){
            if(val==0)
            sum=0;
            else
                sum=f[1];
            lc1=val;
            rc1=val;
            ful1=val;
        }else if(a==0){
            if(val==0){
                lc1=0;
                rc1=b->rc1;
                sum=b->sum;
                ful1=0;
            }else{
                if(b->lc1==0){
                    lc1=1;
                    rc1=b->rc1;
                    sum=b->sum+f[1];
                    ful1=0;
                }else if(b->ful1==1){
                    rc1=lc1=b->lc1+1;
                    sum=f[lc1];
                    ful1=1;
                }else{
                    lc1=b->lc1+1;
                    rc1=b->rc1;
                    sum=b->sum-f[b->lc1]+f[lc1];
                    ful1=0;
                }
            }
        }else if(b==0){
            if(val==0){
                lc1=a->lc1;
                rc1=0;
                sum=a->sum;
                ful1=0;
            }else{
                if(a->rc1==0){
                    rc1=1;
                    lc1=a->lc1;
                    sum=a->sum+f[1];
                    ful1=0;
                }else if(a->ful1==1){
                    rc1=lc1=a->lc1+1;
                    sum=f[lc1];
                    ful1=1;
                }else{
                    rc1=a->rc1+1;
                    lc1=a->lc1;
                    sum=a->sum-f[a->rc1]+f[rc1];
                    ful1=0;
                }
            }
        }else{
            if(val==0){
                lc1=a->lc1;
                rc1=b->rc1;
                sum=a->sum+b->sum;
                ful1=0;
            }else if(a->ful1&&b->ful1){
                rc1=lc1=a->lc1+b->lc1+1;
                sum=f[lc1];
                ful1=1;
            }else if(a->ful1){
                lc1=a->lc1+1+b->lc1;
                rc1=b->rc1;
                sum=(f[a->lc1+1+b->lc1])+(b->sum-f[b->lc1]);
                ful1=0;
            }else if(b->ful1){
                rc1=b->rc1+1+a->rc1;
                lc1=a->lc1;
                sum=(f[b->rc1+1+a->rc1])+(a->sum-f[a->rc1]);
                ful1=0;
            }else{
                lc1=a->lc1;
                rc1=b->rc1;
                sum=(a->sum-f[a->rc1])+(b->sum-f[b->lc1])+f[a->rc1+b->lc1+1];
                ful1=0;
            }
        }


    }
    void Reverse(){
        swap(lc1,rc1);
    }
};
DynamicTree<Info>::Pointer ptr[100010];
void dfs(int u,int p){
    vp(i,to[u])
        if(to[u][i]!=p){
            prt[to[u][i]]=u;
            prtw[to[u][i]]=wi[u][i];
            dfs(to[u][i],u);
        }
}
struct Ans{
    int id,u,v,l;
};
bool operator<(Ans a,Ans b){
    return a.l<b.l;
}
void modi(Info*ii){
    ii->val=0;
}
int ans[100010];
int main(){
    sf("%d%d",&n,&q);
    lp(i,1,n-1)sf("%d",f+i);
    lp(i,1,n-1){
        int u,v,w;
        sf("%d%d%d",&u,&v,&w);
        to[u].pb(v);
        wi[u].pb(w);
        to[v].pb(u);
        wi[v].pb(w);
    }
    dfs(1,0);
    DynamicTree<Info> tree;
    lp(i,1,n)ptr[i]=tree.Make(Info(1));
    lp(i,2,n)tree.Link(ptr[prt[i]],ptr[i]);
    vector<pair<int,int> > edges;
    lp(i,2,n)edges.pb(mp(prtw[i],i));
    sort(edges.begin(),edges.end());
    vector<Ans>ass;
    lp(i,1,q){
        Ans t;
        sf("%d%d%d",&t.u,&t.v,&t.l);
        t.id=i;
        ass.pb(t);
    }
    sort(ass.begin(),ass.end());
    int hehep=0;
    vp(i,ass){
        while(hehep<edges.size()&&edges[hehep].first<ass[i].l){
            tree.Modify(ptr[edges[hehep].second],modi);
            ++hehep;
        }
        int u=ass[i].u,v=ass[i].v,id=ass[i].id;
        ans[id]=tree.EdgeQuery(ptr[u],ptr[v]).sum;
    }
    lp(i,1,q)pf("%d\n",ans[i]);
    return 0;
}
