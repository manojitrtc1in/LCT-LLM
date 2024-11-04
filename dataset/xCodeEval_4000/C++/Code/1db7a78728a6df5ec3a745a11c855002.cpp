#include<algorithm>
#include<cctype>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<functional>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
namespace FastIO{
    class Reader{
    private:
        std::FILE*file;
        std::vector<char>buffer;
        char*pointer,*end;
        inline void read_file(){
            for(int i=0;;++i){
                buffer.resize(buffer.size()+(1<<i));
                int t=std::fread(&buffer[0]+buffer.size()-(1<<i),1,(1<<i),file);
                if(t!=(1<<i)){
                    if(!buffer.empty()){
                        pointer=&buffer[0];
                        end=pointer+buffer.size()-(1<<i)+t;
                    }
                    break;
                }
            }
        }
        inline void ignore(){
            while(pointer!=end&&std::isspace(*pointer))
                ++pointer;
        }
    public:
        inline Reader(std::FILE*_file):
        file(_file){
            read_file();
        }
        inline Reader(std::string _file):
        file(std::fopen(_file.c_str(),"r")){
            read_file();
        }
        inline~Reader(){
            fclose(file);
        }
        inline Reader&operator>>(char&a){
            ignore();
            a=*pointer++;
            return*this;
        }
        inline Reader&operator>>(char*a){
            ignore();
            while(pointer!=end&&!std::isspace(*pointer))
                *a++=*pointer++;
            *a=0;
            return*this;
        }
        inline Reader&operator>>(int&a){
            ignore();
            bool f=false;
            if(*pointer=='-'){
                f=true;
                ++pointer;
            }
            a=0;
            while(pointer!=end&&std::isdigit(*pointer))
                a=a*10+*pointer++-'0';
            if(f)
                a=-a;
            return*this;
        }
        inline Reader&operator>>(long long&a){
            ignore();
            bool f=false;
            if(*pointer=='-'){
                f=true;
                ++pointer;
            }
            a=0;
            while(pointer!=end&&std::isdigit(*pointer))
                a=a*10+*pointer++-'0';
            if(f)
                a=-a;
            return*this;
        }
    };
    class Writer{
    private:
        std::FILE*file;
        std::vector<char>buffer;
    public:
        inline Writer(std::FILE*_file):
        file(_file){
        }
        inline Writer(std::string _file):
        file(std::fopen(_file.c_str(),"w")){
        }
        inline~Writer(){
            if(!buffer.empty())
                std::fwrite(&buffer[0],1,buffer.size(),file);
            fclose(file);
        }
        inline Writer&operator<<(char a){
            buffer.push_back(a);
            return*this;
        }
        inline Writer&operator<<(const char*a){
            while(*a)
                buffer.push_back(*a++);
            return*this;
        }
        inline Writer&operator<<(int a){
            if(a<0){
                buffer.push_back('-');
                a=-a;
            }
            static char t[10];
            char*p=t;
            do{
                int b=a/10;
                *p++=a-b*10+'0';
                a=b;
            }while(a);
            while(p>t)
                buffer.push_back(*--p);
            return*this;
        }
        inline Writer&operator<<(unsigned a){
            static char t[10];
            char*p=t;
            do{
                int b=a/10;
                *p++=a-b*10+'0';
                a=b;
            }while(a);
            while(p>t)
                buffer.push_back(*--p);
            return*this;
        }
        inline Writer&operator<<(long long a){
            if(a<0){
                buffer.push_back('-');
                a=-a;
            }
            static char t[19];
            char*p=t;
            do{
                long long b=a/10;
                *p++=a-b*10+'0';
                a=b;
            }while(a);
            while(p>t)
                buffer.push_back(*--p);
            return*this;
        }
    };
}
namespace NumberTheory{
    template<class VALUE_TYPE>inline VALUE_TYPE Abs(const VALUE_TYPE&a){
        return a<VALUE_TYPE(0)?-a:a;
    }
    template<class VALUE_TYPE>inline VALUE_TYPE Sqr(const VALUE_TYPE&a){
        return a*a;
    }
    template<class VALUE_TYPE>inline VALUE_TYPE Cub(const VALUE_TYPE&a){
        return a*a*a;
    }
    template<class VALUE_TYPE,class POW_TYPE>inline VALUE_TYPE Pow(VALUE_TYPE a,POW_TYPE b){
        VALUE_TYPE r=VALUE_TYPE(1);
        for(;b!=POW_TYPE(0);b>>=1,a=a*a)
            if(b%POW_TYPE(2)==1)
                r=r*a;
        return r;
    }
    template<class VALUE_TYPE,class POW_TYPE,class MOD_TYPE>inline VALUE_TYPE PowMod(VALUE_TYPE a,POW_TYPE b,const MOD_TYPE&c){
        VALUE_TYPE r=VALUE_TYPE(1);
        for(;b!=POW_TYPE(0);b>>=1,a=a*a%c)
            if(b%POW_TYPE(2)==1)
                r=r*a%c;
        return r;
    }
    template<class VALUE_TYPE>inline VALUE_TYPE Gcd(const VALUE_TYPE&a,const VALUE_TYPE&b){
        for(VALUE_TYPE t;b!=VALUE_TYPE(0);t=a,a=b,b=t%b);
        return a;
    }
    template<class VALUE_TYPE>inline VALUE_TYPE Lcm(const VALUE_TYPE&a,const VALUE_TYPE&b){
        return a*b/Gcd(a,b);
    }
}
namespace DataStructures{
    template<class VALUE_TYPE,class COMPARER_TYPE>class Set{
    private:
        struct node{
            inline node(const VALUE_TYPE&_value,node*_left,node*_right,
                node*_parent,const bool&_black,const int&_size,const int&_count):
            value(_value),left(_left),right(_right),
                parent(_parent),black(_black),size(_size),count(_count){
            }
            VALUE_TYPE value;
            node*left,*right,*parent;
            bool black;
            int size,count;
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
            x->size=x->left->size+x->right->size+x->count;
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
            x->size=x->left->size+x->right->size+x->count;
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
            if(z->left==nil||z->right==nil)
                y=z;
            else{
                y=z->right;
                while(y->left!=nil)
                    y=y->left;
                z->value=y->value;
                z->count=y->count;
                int t=y->count;
                y->count=0;
                y=z->right;
                while(y->left!=nil){
                    y->size-=t;
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
            if(!x->count)
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
            inline node*precursor(node*x){
                if(x->left->count){
                    x=x->left;
                    while(x->right->count)
                        x=x->right;
                    return x;
                }else{
                    node*y=x->parent;
                    while(y->count&&x==y->left){
                        x=y;
                        y=y->parent;
                    }
                    return y;
                }
            }
            inline node*successor(node*x){
                if(x->right->count){
                    x=x->right;
                    while(x->left->count)
                        x=x->left;
                    return x;
                }else{
                    node*y=x->parent;
                    while(y->count&&x==y->right){
                        x=y;
                        y=y->parent;
                    }
                    return y;
                }
            }
        public:
            inline Iterator(){
            }
            inline Iterator(node*_pointer):
            pointer(_pointer){
            }
            inline~Iterator(){
            }
            inline bool operator==(const Iterator&a){
                return pointer==a.pointer;
            }
            inline bool operator!=(const Iterator&a){
                return pointer!=a.pointer;
            }
            inline VALUE_TYPE operator*(){
                return pointer->value;
            }
            inline VALUE_TYPE*operator->(){
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
            root=nil=new node(VALUE_TYPE(),0,0,0,true,0,0);
        }
        inline Set(const Set&a){
            nil=new node(*a.nil);
            root=clone(a.root,nil);
        }
        inline~Set(){
            clear(root);
            delete nil;
        }
        inline Set&operator=(const Set&a){
            clear(root);
            root=clone(a.root,nil);
            return*this;
        }
        Iterator Begin(){
            node*z=root;
            while(z!=nil&&z->left!=nil)
                z=z->left;
            return Iterator(z);
        }
        Iterator ReverseBegin(){
            node*z=root;
            while(z!=nil&&z->right!=nil)
                z=z->right;
            return Iterator(z);
        }
        Iterator End(){
            return Iterator(nil);
        }
        Iterator ReverseEnd(){
            return Iterator(nil);
        }
        inline void Clear(){
            clear(root);
            root=nil;
        }
        inline void Insert(const VALUE_TYPE&a){
            node*y=nil,*x=root;
            while(x!=nil){
                y=x;
                ++x->size;
                if(COMPARER_TYPE()(a,x->value))
                    x=x->left;
                else if(COMPARER_TYPE()(x->value,a))
                    x=x->right;
                else{
                    ++x->count;
                    return;
                }
            }
            node*z=new node(a,nil,nil,y,false,1,1);
            if(y==nil)
                root=z;
            else if(COMPARER_TYPE()(z->value,y->value))
                y->left=z;
            else
                y->right=z;
            insert_fixup(z);
        }
        inline void Erase(const Iterator&a){
            node*z=root;
            while(true){
                z->size-=a.pointer->count;
                if(COMPARER_TYPE()(a.pointer->value,z->value))
                    z=z->left;
                else if(COMPARER_TYPE()(z->value,a.pointer->value))
                    z=z->right;
                else
                    break;
            }
            erase(z);
        }
        inline void Erase(const VALUE_TYPE&a){
            node*z=root;
            while(true){
                --z->size;
                if(COMPARER_TYPE()(a,z->value))
                    z=z->left;
                else if(COMPARER_TYPE()(z->value,a))
                    z=z->right;
                else
                    break;
            }
            if(!--z->count)
                erase(z);
        }
        inline int Count(const VALUE_TYPE&a){
            node*z=root;
            while(z!=nil){
                if(COMPARER_TYPE()(a,z->value))
                    z=z->left;
                else if(COMPARER_TYPE()(z->value,a))
                    z=z->right;
                else
                    return z->count;
            }
            return 0;
        }
        inline int CountLess(const VALUE_TYPE&a){
            int r=0;
            node*z=root;
            while(z!=nil){
                if(COMPARER_TYPE()(z->value,a)){
                    r+=z->left->size+z->count;
                    z=z->right;
                }else
                    z=z->left;
            }
            return r;
        }
        inline int CountLessEqual(const VALUE_TYPE&a){
            int r=0;
            node*z=root;
            while(z!=nil){
                if(!COMPARER_TYPE()(a,z->value)){
                    r+=z->left->size+z->count;
                    z=z->right;
                }else
                    z=z->left;
            }
            return r;
        }
        inline int CountGreater(const VALUE_TYPE&a){
            int r=0;
            node*z=root;
            while(z!=nil){
                if(COMPARER_TYPE()(a,z->value)){
                    r+=z->right->size+z->count;
                    z=z->left;
                }else
                    z=z->right;
            }
            return r;
        }
        inline int CountGreaterEqual(const VALUE_TYPE&a){
            int r=0;
            node*z=root;
            while(z!=nil){
                if(!COMPARER_TYPE()(z->value,a)){
                    r+=z->right->size+z->count;
                    z=z->left;
                }else
                    z=z->right;
            }
            return r;
        }
        inline Iterator NthElement(int a){
            node*z=root;
            while(true){
                if(z->left->size>a)
                    z=z->left;
                else if(z->left->size+z->count<=a){
                    a-=z->left->size+z->count;
                    z=z->right;
                }else
                    return Iterator(z);
            }
        }
        inline Iterator Precursor(const VALUE_TYPE&a){
            node*z=root,*r=nil;
            while(z!=nil){
                if(COMPARER_TYPE()(z->value,a)){
                    r=z;
                    z=z->right;
                }else
                    z=z->left;
            }
            return Iterator(r);
        }
        inline Iterator Successor(const VALUE_TYPE&a){
            node*z=root,*r=nil;
            while(z!=nil){
                if(COMPARER_TYPE()(a,z->value)){
                    r=z;
                    z=z->left;
                }else
                    z=z->right;
            }
            return Iterator(r);
        }
        inline int Size(){
            return root->size;
        }
        inline bool Empty(){
            return root->size==0;
        }
        inline VALUE_TYPE Front(){
            return*Begin();
        }
        inline VALUE_TYPE Back(){
            return*ReverseBegin();
        }
    };
}
namespace NetworkFlow{
    template<typename FLOW_TYPE>class MaxFlow{
    private:
        class edge{
        public:
            int v;
            FLOW_TYPE c;
            inline edge(const int&_v,const FLOW_TYPE&_c):
            v(_v),c(_c){
            }
        };
        std::vector<edge>edges;
        std::vector<std::vector<int> >start;
        std::vector<int>height,gap,cur,from;
        int n,source,sink;
        inline void label(){
            height[sink]=0;
            std::queue<int>qu;
            qu.push(sink);
            while(!qu.empty()){
                int u=qu.front();
                qu.pop();
                for(int i=0;i<start[u].size();++i){
                    edge&e=edges[start[u][i]],&ev=edges[start[u][i]^1];
                    if(ev.c!=FLOW_TYPE(0)&&height[e.v]==n){
                        height[e.v]=height[u]+1;
                        qu.push(e.v);
                    }
                }
            }
            for(int i=0;i<n;++i)
                ++gap[height[i]];
        }
        inline FLOW_TYPE augment(){
            FLOW_TYPE f=FLOW_TYPE(0);
            for(int u=sink;u!=source;u=edges[from[u]^1].v)
                if(f==FLOW_TYPE(0)||f>edges[from[u]].c)
                    f=edges[from[u]].c;
            for(int u=sink;u!=source;u=edges[from[u]^1].v){
                edges[from[u]].c-=f;
                edges[from[u]^1].c+=f;
            }
            return f;
        }
    public:
        inline MaxFlow(const int&_n,const int&_source,const int&_sink):
        start(_n),height(_n,_n),gap(_n+1),n(_n),
            cur(_n),from(_n),source(_source),sink(_sink){
        }
        inline void AddEdge(const int&u,const int&v,const FLOW_TYPE&c){
            start[u].push_back(edges.size());
            edges.push_back(edge(v,c));
            start[v].push_back(edges.size());
            edges.push_back(edge(u,FLOW_TYPE(0)));
        }
        inline FLOW_TYPE Run(){
            label();
            FLOW_TYPE r=FLOW_TYPE(0);
            int u=source;
            while(height[source]!=n){
                if(u==sink){
                    r+=augment();
                    u=source;
                }
                bool flag=false;
                for(int&i=cur[u];i<start[u].size();++i){
                    edge&e=edges[start[u][i]];
                    if(e.c!=FLOW_TYPE(0)&&height[u]==height[e.v]+1){
                        flag=true;
                        from[e.v]=start[u][i];
                        u=e.v;
                        break;
                    }
                }
                if(!flag){
                    int mh=n-1;
                    for(int i=0;i<start[u].size();++i){
                        edge&e=edges[start[u][i]];
                        if(e.c!=FLOW_TYPE(0)&&mh>height[e.v])
                            mh=height[e.v];
                    }
                    if(!--gap[height[u]])
                        break;
                    ++gap[height[u]=mh+1];
                    cur[u]=0;
                    if(u!=source)
                        u=edges[from[u]^1].v;
                }
            }
            return r;
        }
    };
}
using namespace std;
using namespace FastIO;
using namespace NumberTheory;
using namespace DataStructures;
using namespace NetworkFlow;
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
typedef long long ll;
char s[500010];int n;
int main(){
    sf("%s",s+1);
    n=strlen(s+1);
    

    

    if(n>=2600){
        static int cnt[410];
        lp(i,1,n)++cnt[s[i]];
        int id=-1;
        lp(i,'a','z')if(cnt[i]>=100){id=i;break;}
        lp(i,1,100)pf("%c",char(id));
        pf("\n");
    }else{
        static int dp1[2605][2605];
        static int frm1[2605][2605];
        for(int d=2;d<=n;++d){
            for(int i=1;i+d-1<=n;++i){
                int j=i+d-1;
                if(i==j)dp1[i][j]=1;
                else if(s[i]==s[j]){
                    dp1[i][j]=dp1[i+1][j-1]+2;
                    frm1[i][j]=0;
                }else{
                    if(dp1[i+1][j]>dp1[i][j-1]){
                        dp1[i][j]=dp1[i+1][j];
                        frm1[i][j]=1;
                    }else{
                        dp1[i][j]=dp1[i][j-1];
                        frm1[i][j]=2;
                    }
                }
            }
        }
        int tl=-1,tr=-1;
        lp(i,1,n){lp(j,i,n){
                if(dp1[i][j]==100){
                    tl=i;
                    tr=j;
                }
            }
        }
        if(tl!=-1){
            vector<char>ans;
            while(tl<tr){
                if(frm1[tl][tr]==0){
                    ans.push_back(s[tl]);
                    ++tl;--tr;
                }else if(frm1[tl][tr]==1){
                    ++tl;
                }else --tr;
            }
            vp(i,ans)pf("%c",ans[i]);
            wp(i,ans)pf("%c",ans[i]);
            pf("\n");
        }else{
            static int dp2[2605][2605];
            static int frm2[2605][2605];
            for(int d=1;d<=n;++d){
                for(int i=1;i+d-1<=n;++i){
                    int j=i+d-1;
                    if(i==j)dp2[i][j]=1;
                    else if(s[i]==s[j]){
                        dp2[i][j]=dp2[i+1][j-1]+2;
                        frm2[i][j]=0;
                    }else{
                        if(dp2[i+1][j]>dp2[i][j-1]){
                            dp2[i][j]=dp2[i+1][j];
                            frm2[i][j]=1;
                        }else{
                            dp2[i][j]=dp2[i][j-1];
                            frm2[i][j]=2;
                        }
                    }
                }
            }
            tl=1;tr=n;
            vector<char>ans;
            while(tl<=tr){
                if(frm2[tl][tr]==0){
                    ans.push_back(s[tl]);
                    ++tl;--tr;
                }else if(frm2[tl][tr]==1){
                    ++tl;
                }else --tr;
            }
            vp(i,ans)pf("%c",ans[i]);
            if(dp2[1][n]%2==1)ans.pop_back();
            wp(i,ans)pf("%c",ans[i]);
            pf("\n");
        }
    }
    

    return 0;
}