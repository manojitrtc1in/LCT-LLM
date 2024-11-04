#include<algorithm>
#include<cctype>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<functional>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
namespace CoreLibrary{
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
                    pointer=&buffer[0];
                    end=pointer+buffer.size()-(1<<i)+t;
                    break;
                }
            }
        }
        inline void read(char&a){
            a=*pointer++;
        }
        inline void read(char*a){
            ignore();
            while(pointer!=end&&!std::isspace(*pointer))
                *a++=*pointer++;
            *a=0;
        }
        inline void read(int&a){
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
        }
        inline void read(long long&a){
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
        inline ~Reader(){
            fclose(file);
        }
        template<class VALUE_TYPE>inline Reader&operator>>(VALUE_TYPE&a){
            read(a);
            return*this;
        }
    };
    class Writer{
    private:
        std::FILE*file;
        std::vector<char>buffer;
        inline void write(char a){
            buffer.push_back(a);
        }
        inline void write(const char*a){
            while(*a)
                buffer.push_back(*a++);
        }
        inline void write(int a){
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
        }
        inline void write(long long a){
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
        }
    public:
        inline Writer(std::FILE*_file):
        file(_file){
        }
        inline Writer(std::string _file):
        file(std::fopen(_file.c_str(),"w")){
        }
        inline~Writer(){
            std::fwrite(&buffer[0],1,buffer.size(),file);
            fclose(file);
        }
        template<class VALUE_TYPE>inline Writer&operator<<(VALUE_TYPE a){
            write(a);
            return*this;
        }
    };
    template<class VALUE_TYPE>inline bool MakeMax(VALUE_TYPE&a,const VALUE_TYPE&b){
        if(a<b){
            a=b;
            return true;
        }
        return false;
    }
    template<class VALUE_TYPE>inline bool MakeMin(VALUE_TYPE&a,const VALUE_TYPE&b){
        if(a>b){
            a=b;
            return true;
        }
        return false;
    }
    template<class VALUE_TYPE>inline VALUE_TYPE Abs(const VALUE_TYPE&a){
        return a<VALUE_TYPE(0)?-a:a;
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
        inline int Empty(){
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
    template<typename FLOW_TYPE>class ISAP{
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
        FLOW_TYPE limit;
        inline void label(){
            height[sink]=0;
            std::queue<int>qu;
            qu.push(sink);
            while(!qu.empty()){
                int u=qu.front();
                qu.pop();
                for(std::vector<int>::iterator i=start[u].begin();i!=start[u].end();++i){
                    edge&e=edges[*i],&ev=edges[(*i)^1];
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
            FLOW_TYPE f=limit;
            for(int u=sink;u!=source;u=edges[from[u]^1].v)
                f=std::min(f,edges[from[u]].c);
            for(int u=sink;u!=source;u=edges[from[u]^1].v){
                edges[from[u]].c-=f;
                edges[from[u]^1].c+=f;
            }
            return f;
        }
    public:
        inline ISAP(const int&_n,const int&_source,
            const int&_sink,const FLOW_TYPE&_limit):
        start(_n),height(_n,_n),gap(_n+1),n(_n),cur(_n),
            from(_n),source(_source),sink(_sink),limit(_limit){
        }
        inline void AddEdge(const int&u,const int&v,const FLOW_TYPE&c){
            start[u].push_back(edges.size());
            edges.push_back(edge(v,c));
            start[v].push_back(edges.size());
            edges.push_back(edge(u,FLOW_TYPE(0)));
        }
        inline FLOW_TYPE Run(){
            label();
            FLOW_TYPE r=0;
            int u=source;
            while(height[source]!=n&&limit!=FLOW_TYPE(0)){
                if(u==sink){
                    FLOW_TYPE t=augment();
                    limit-=t;
                    r+=t;
                    u=source;
                }
                bool flag=false;
                for(std::vector<int>::iterator i=start[u].begin()+cur[u];i!=start[u].end();++i){
                    edge&e=edges[*i];
                    if(e.c!=FLOW_TYPE(0)&&height[u]==height[e.v]+1){
                        flag=true;
                        from[e.v]=*i;
                        cur[u]=i-start[u].begin();
                        u=e.v;
                        break;
                    }
                }
                if(!flag){
                    int mh=n-1;
                    for(std::vector<int>::iterator i=start[u].begin();i!=start[u].end();++i){
                        edge&e=edges[*i];
                        if(e.c!=FLOW_TYPE(0))
                            mh=std::min(mh,height[e.v]);
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
using namespace CoreLibrary;
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
int tmain(){
    

    

    Reader reader(stdin);
    Writer writer(stdout);
    int n,m;reader>>n>>m;
    ISAP<ll>flow(n,0,n-1,10000000000000000ll);
    lp(i,1,m){
        int u,v,c;
        reader>>u>>v>>c;
        flow.AddEdge(u-1,v-1,c);
        flow.AddEdge(v-1,u-1,c);
    }
    writer<<flow.Run()<<'\n';
    return 0;
}
template<typename value_type>
inline void read_value(value_type&a){
    char c;
    for(c=getchar();!isdigit(c)&&c!='-';c=getchar());
    a=value_type(0);
    bool flag=c=='-';
    for(;isdigit(c);c=getchar())
        a=a*value_type(10)+value_type(c-'0');
    if(flag)a=-a;
}
template<typename value_type>
inline void print_value(value_type a){
    bool flag=a<value_type(0);
    if(flag)a=-a;
    std::vector<char>t;
    do{
        t.push_back(a%10+'0');
        a/=10;
    }while(a!=value_type(0));
    if(flag)putchar('-');
    for(int i=int(t.size())-1;i>=0;--i)putchar(t[i]);
}
int n,m,g,sex[10010];
int main(){
    read_value(n);
    read_value(m);
    read_value(g);
    ISAP<int>mf(n+m+2,0,n+m+1,~0u>>1);
    for(int i=1;i<=n;++i)read_value(sex[i]);
    for(int i=1;i<=n;++i){
        int v;read_value(v);
        if(!sex[i])mf.AddEdge(0,i,v);
        else mf.AddEdge(i,n+m+1,v);
    }
    int ans=0;
    for(int i=1;i<=m;++i){
        int tsex,w,k,isf;
        read_value(tsex);
        read_value(w);
        read_value(k);
        ans+=w;
        for(int j=1;j<=k;++j){
            int t;read_value(t);
            if(!tsex)mf.AddEdge(n+i,t,~0u>>1);
            else mf.AddEdge(t,n+i,~0u>>1);
        }
        read_value(isf);
        if(!tsex)mf.AddEdge(0,n+i,w+isf*g);
        else mf.AddEdge(n+i,n+m+1,w+isf*g);
    }
    print_value(ans-mf.Run());
    putchar('\n');
    

    return 0;
}