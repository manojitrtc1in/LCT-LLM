#include <iostream>
namespace myt{
    int *f=nullptr,MOD;
    

    template <class T> inline T max(T a,T b){return a>b?a:b;}
    template <class T> inline T min(T a,T b){return a>b?b:a;}
    template <class T> inline T abs(T a){return a>0?a:-a;}
    template <class T> inline T gcd(T a,T b){return b==0?a:gcd(b,a%b);}
    template <class T> inline T extgcd(T a,T b,T &x,T &y){
        if(b==0){
            x=1;
            y=0;
            return a;
        }
        T ans=extgcd(b,a%b,x,y),nx,ny;
        nx=-y;
        ny=-((a/b)*y+x);
        x=nx;
        y=ny;
        return ans;
    }
    template <class T> inline void swap(T &a,T &b){
        T temp=a;
        a=b;
        b=temp;
        return ;
    }
    void IOS(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        return ;
    }
    
    

    inline int add(int a,int b){return ((long long int)a+(long long int)b+MOD)%MOD;}
    inline int mul(int a,int b){return ((long long int)a*(long long int)b)%MOD;}
    inline int pow(int a,int t){
        int ans=1;
        while(t){
            if(t&1)ans=mul(ans,a);
            t>>=1;
            a=mul(a,a);
        }
        return ans;
    }
    int rev(int n){return pow(n,MOD-2);}
    int C(int n,int m){return mul(f[n],rev(mul(f[n-m],f[m])));}
    int H(int n,int m){return C(n+m-1,m);}
    void precalf(int n){
        delete f;
        f=new int[n];
        f[0]=f[1]=1;
        for(int i=2;i<n;i++)f[i]=mul(f[i],i);
        return ;
    }
    

    struct BIG{
        int TOP;
        long long int *a;
        int s;
        int now;
        BIG(int n){
            TOP=n;
            a=new long long int[1];
            s=0;
            now=1;
        }
        void in(){
            delete [] a;
            a=new long long int [1];
            s=0;
            now=1;
            std::string c;
            long long int temp=0;
            std::cin>>c;
            
            for(char i:c){
                temp*=10;
                temp+=i-'0';
                if(temp>TOP){
                    push(temp/10);
                    temp%=10;
                }
            }
            
            
            return ;
        }
        void push(long long int n){
            
        }
        void pull(){
            for(int i=0;i<s;i++)if(a[i]>TOP){
                push(0);
                a[i+1]+=a[i]/TOP;
                a[i]%=TOP;
            }
            return ;
        }
        void out(){
            std::cout<<a[0];
            int temp;
            for(int i=1;i<s;i++){
                temp=TOP;
                while(temp/10>a[i]){
                    std::cout<<0;
                    temp/=10;
                }
                std::cout<<a[i];
            }
            return ;
        }
        BIG operator +(const BIG &n){
            BIG temp(TOP);
            
            
            return temp;
        }
        BIG operator *(const BIG &n){
            BIG temp(TOP);
            
            
            return temp;
        }
        BIG operator +=(const BIG &n){
            
            return *this;
        }
        BIG operator *=(const BIG &n){
            
            return *this;
        }
    };
    
    

    template <class T> struct matrix{
        T* a;
        int n;
        int m;
        matrix(){
            n=m=0;
            a=nullptr;
        }
        matrix(int x,int y){
            n=x;
            m=y;
            a=new T[n][m];
        }
        void in(int size){
            n=m=size;
            delete [] a;
            a=new T[n][m];
            for(int i=0;i<n;i++)for(int j=0;j<m;j++)std::cin>>a[i][j];
            return ;
        }
        void out(){
            for(int i=0;i<n;i++){
                std::cout<<a[i][0];
                for(int j=1;j<m;j++)std::cout<<" "<<a[i][j];
                std::cout<<"\n";
            }
            return ;
        }
        matrix<T> operator *(const matrix<T> &b){
            matrix temp(n,b.m);
            for(int i=0;i<n;i++)for(int j=0;j<b.m;j++){
                temp.a[i][j]=0;
                for(int k=0;k<m;k++)temp.a[i][j]+=a[i][k]*b.a[k][j];
            }
            return temp;
        }
        matrix<T> operator +(const matrix<T> &b){
            matrix temp(n,m);
            for(int i=0;i<n;i++)for(int j=0;j<m;j++)temp.a[i][j]=a[i][j]+b.a[i][j];
            return temp;
        }
        matrix<T> operator +=(const matrix<T> &b){
            for(int i=0;i<n;i++)for(int j=0;j<m;j++)a[i][j]+=b.a[i][j];
            return *this;
        }
        matrix<T> operator *=(const matrix<T> &b){
            matrix temp(n,b.m);
            for(int i=0;i<n;i++)for(int j=0;j<b.m;j++){
                temp.a[i][j]=0;
                for(int k=0;k<m;k++)temp.a[i][j]+=a[i][k]*b.a[k][j];
            }
            return *this=temp;
        }
        matrix<T> operator =(const matrix<T> &b){
            delete [] a;
            n=b.n;
            m=b.m;
            a=new T[n][m];
            for(int i=0;i<n;i++)for(int j=0;j<m;j++)a[i][j]=b.a[i][j];
            return *this;
        }
    };
    
    

    struct DJS{
        int* ptr;
        DJS(int n){
            delete [] ptr;
            ptr=new int[n];
            for(int i=0;i<n;i++)ptr[i]=i;
        }
        void merge(int a,int b){ptr[b]=a;}
        int find(int n){return ptr[n]==n?n:find(ptr[n]);}
        bool same(int a,int b){return find(a)==find(b);}
    };
    
    

    template <class T> struct Vector{
        T* ptr;
        int s;
        int now;
        void clear(){
            delete [] ptr;
            ptr=new T;
            now=1;
            s=0;
            return ;
        }
        void in(int n){
            resize(n);
            for(int i=0;i<n;i++)std::cin>>ptr[i];
            return ;
        }
        inline void push_back(T val){
            if(now==s){
                now<<=1;
                T* temp=ptr;
                ptr=new T[now];
                for(int i=0;i<s;i++)ptr[i]=temp[i];
                delete [] temp;
            }
            ptr[s++]=val;
            return ;
        }
        inline void pop_back(){
            s--;
            return ;
        }
        void resize(int n){
            now=1;
            while(now<n)now<<=1;
            T* temp=ptr;
            ptr=new T[now];
            for(int i=0;i<s;i++)ptr[i]=temp[i];
            s=n;
            return ;
        }
        T& operator [](int n){return ptr[n];}
        inline int size(){return s;}
        inline void in(){
            T temp;
            std::cin>>temp;
            push_back(temp);
            return ;
        }
        inline bool empty(){return s==0;}
    };
    template <class T> struct Queue{
        T* ptr;
        int last;
        int now;
        int start;
        Queue(){
            ptr=new T[1];
            now=1;
            last=start=0;
        }
        inline void push(T n){
            if(last==now){
                T* temp=ptr;
                int cnt=0;
                now<<=1;
                ptr=new T[now];
                for(int i=start;i<last;i++)ptr[cnt++]=temp[i];
                last=cnt;
                start=0;
                delete [] temp;
            }
            ptr[last++]=n;
            return ;
        }
        inline void pop(){
            start++;
            return ;
        }
        void clear(){
            delete [] ptr;
            ptr=new T[1];
            now=1;
            start=last=0;
            return ;
        }
        T& operator [](int n){return ptr[start+n];}
        T front(){return ptr[start];}
        inline bool empty(){return last==start;}
        inline int size(){return last-start;}
    };
    template <class T> struct Stack{
        T* ptr;
        int s;
        int now;
        Stack(){
            ptr=new T[1];
            now=1;
            s=0;
        }
        inline void push(T n){
            if(now==s){
                now<<=1;
                T* temp=ptr;
                ptr=new T[now];
                for(int i=0;i<s;i++)ptr[i]=temp[i];
                delete [] temp;
            }
            ptr[s++]=n;
            return ;
        }
        inline void pop(){
            s--;
            return ;
        }
        void clear(){
            delete [] ptr;
            ptr=new T[1];
            s=0;
            now=1;
            return ;
        }
        T& operator [](int n){return ptr[s-n-1];}
        T top(){return ptr[s-1];}
        inline bool empty(){return s==0;}
        inline int size(){return s;}
    };
    template <class T> struct Deque{
        
    };
    template <class T> struct set{
        
    };
    template <class T1,class T2> struct map{
        
    };
    template <class T1,class T2> struct Pair{
        T1 first;
        T2 second;
        void in(){
            std::cin>>first>>second;
            return ;
        }
        void out(){
            std::cout<<first<<" "<<second<<"\n";
            return ;
        }
    };
    
    

    namespace Btrie{
        struct node{
            node* l;
            node* r;
            int size;
            void pull(){
                
            }
        };
    }
    
    

    namespace treap{
        long long int now=1934798273948LL;
        bool rnd(int a,int b){
            now^=13247183478198LL;
            now%=(a+b);
            return now>=b;
        }
        template <class T> struct node{
            node* l;
            node* r;
            T val;
            int size;
            node(T n){
                l=r=nullptr;
                val=n;
                size=1;
            }
            void pull(){
                size=1;
                if(l)size+=l->size;
                if(r)size+=r->size;
                return ;
            }
            int lsize(){return l?l->size+1:1;}
        };
        template <class T> void splitbysize(node<T>* s,int x,node<T>*&a,node<T>*&b){
            if(!s)a=b=nullptr;
            else if(s->lsize()>=x){
                b=s;
                splitbysize(s->l,x,a,b->l);
            }
            else{
                a=s;
                splitbysize(s->r,x-s->lsize(),a->r,b);
            }
            return ;
        }
        template <class T> void splitbyval(node<T>* s,int x,node<T>*&a,node<T>*&b){
            
        }
        template <class T> node<T>* merge(node<T> *a,node<T> *b){
            if(!a)return b;
            if(!b)return a;
            if(rnd(a->size,b->size)){
                a->r=merge(a->r,b);
                return a;
            }
            else{
                b->l=merge(a,b->l);
                return b;
            }
        }
        template <class T> struct tp{
            node<T> *root;
            void insert(T val){
                node<T>* a,*b;
                splitbyval(root,val,a,b);
                root=merge(a,new node<T>(val));
                root=merge(root,b);
                return ;
            }
            void erase(T val){
                
                
                return ;
            }
            bool find(T val){
                
                
                return false;
            }
            
        };
    }
    
    

    template <class T> struct BIT{
        T* val=nullptr;
        int size=0;
        BIT(int n){val=new T[size=n];}
        BIT(Vector<T>&v){
            T* temp=new T[size=v.size];
            temp[0]=v[0];
            for(int i=1;i<size;i++)temp[i]=temp[i-1]+v[i];
            val=new T[size];
            for(int i=1;i<size;i++)v[i]=temp[i]-temp[i^(i&-i)];
            delete [] temp;
        }
        BIT(int* v,int n){
            val=new T[size=n];
            T* temp=new T[size];
            temp[0]=v[0];
            for(int i=1;i<size;i++)temp[i]=temp[i-1]+v[i];
            val=new T[size];
            for(int i=1;i<size;i++)v[i]=temp[i]-temp[i^(i&-i)];
            delete [] temp;
        }
        void init(int n){val=new T[size=n];}
        void init(Vector<T>&v){
            T* temp=new T[size=v.size];
            temp[0]=v[0];
            for(int i=1;i<size;i++)temp[i]=temp[i-1]+v[i];
            val=new T[size];
            for(int i=1;i<size;i++)v[i]=temp[i]-temp[i^(i&-i)];
            delete [] temp;
            return ;
        }
        void init(int* v,int n){
            val=new T[size=n];
            T* temp=new T[size];
            temp[0]=v[0];
            for(int i=1;i<size;i++)temp[i]=temp[i-1]+v[i];
            val=new T[size];
            for(int i=1;i<size;i++)v[i]=temp[i]-temp[i^(i&-i)];
            delete [] temp;
            return ;
        }
        T find(int x){
            T ans=0;
            while(x){
                ans+=val[x];
                x^=x&-x;
            }
            return ans;
        }
        void add(int pos,T x){
            while(pos<size){
                val[pos]+=x;
                pos+=pos&-pos;
            }
            return ;
        }
    };
    template <class T> struct BIT2{
        T* ptr=nullptr;
        int X;
        int Y;
        BIT2(int x,int y){ptr=new T[(X=x)*(Y=y)];}
        void init(int x,int y){ptr=new T[(X=x)*(Y=y)];}
        void add(int x,int y,T val){
            int temp;
            while(x<X){
                temp=y;
                while(temp<Y){
                    ptr[x][temp]+=val;
                    temp+=temp&-temp;
                }
                x+=x&-x;
            }
            return ;
        }
        T ask(int x,int y){
            int temp;
            T ans=0;
            while(x){
                temp=y;
                while(temp){
                    ans+=ptr[x][temp];
                    temp^=temp&-temp;
                }
                x^=x&-x;
            }
            return ans;
        }
    };
    
    

    template <class T> struct SEG_TREE{
        
    };
    
    

    template <class T>void Sort(T* a,int l,int r){
        if(r>l){
            int mid=(l+r)>>1,*temp,lpos=l,rpos;
            rpos=mid+1;
            Sort(a,l,mid);
            Sort(a,mid+1,r);
            temp=new int[r-l+1];
            for(int i=l;i<=r;i++){
                if(a[lpos]<a[rpos]){
                    temp[i-l]=a[lpos++];
                    if(lpos>mid){
                        while(rpos<=r){
                            temp[rpos-l]=a[rpos];
                            rpos++;
                        }
                        break;
                    }
                }
                else{
                    temp[i-l]=a[rpos++];
                    if(rpos>r){
                        i++;
                        while(lpos<=mid){
                            temp[i-l]=a[lpos];
                            lpos++;
                            i++;
                        }
                        break;
                    }
                }
            }
            for(int i=l;i<=r;i++)a[i]=temp[i-l];
            delete [] temp;
        }
        return ;
    }
    
    template <class T> void Sort(Vector<T>&a,int l,int r){
        if(r>l){
            int mid=(l+r)>>1,*temp,lpos=l,rpos;
            rpos=mid+1;
            Sort(a,l,mid);
            Sort(a,mid+1,r);
            temp=new T[r-l+1];
            for(int i=l;i<=r;i++){
                if(a[lpos]<a[rpos]){
                    temp[i-l]=a[lpos++];
                    if(lpos>mid){
                        while(rpos<=r){
                            temp[rpos-l]=a[rpos];
                            rpos++;
                        }
                        break;
                    }
                }
                else{
                    temp[i-l]=a[rpos++];
                    if(rpos>r){
                        i++;
                        while(lpos<=mid){
                            temp[i-l]=a[lpos];
                            lpos++;
                            i++;
                        }
                        break;
                    }
                }
            }
            for(int i=l;i<=r;i++)a[i]=temp[i-l];
            delete [] temp;
        }
        return ;
    }
    template <class T> void unique(T* a,int size){
        
    }
    template <class T> void unique(Vector<T>&v){
        
    }
    template <class T> void reverse(Vector<T>&v){
        int mid=v.size()>>1;
        for(int i=0;i<mid;i++)swap(v[i],v[v.size()-1-i]);
        return ;
    }
    template <class T> void reverse(T* a,int size){
        int mid=size>>1;
        for(int i=0;i<mid;i++)swap(a[i],a[size-1-i]);
        return ;
    }
    
    

    template <class T> void sum(T* a,T* s,int size){
        s[0]=0;
        for(int i=1;i<=size;i++)s[i]=s[i-1]+a[i];
        return ;
    }
    template <class T> void mul(T* a,T* s,int size){
        s[0]=1;
        for(int i=1;i<=size;i++)s[i]=mul(s[i-1],a[i]);
        return ;
    }
    template <class T> void sum(Vector<T> &a,Vector<T> &s){
        s[0]=0;
        for(int i=1;i<a.size;i++)s[i]=s[i-1]+a[i];
        return ;
    }
    template <class T> void mul(Vector<T> &a,Vector<T> &s){
        s[0]=1;
        for(int i=1;i<a.size;i++)s[i]=mul(s[i-1],a[i]);
        return ;
    }
    

    template <class T> void in(T* a,int size){
        for(int i=0;i<size;i++)std::cin>>a[i];
        return ;
    }
    template <class T> void in1(T* a,int size){
        for(int i=1;i<=size;i++)std::cin>>a[i];
        return ;
    }
    template <class T> void in(Vector<T>&a,int size){
        a.resize(size);
        for(int i=0;i<size;i++)std::cin>>a[i];
        return ;
    }
    template <class T> inline void in(T &a){
        std::cin>>a;
        return ;
    }
    template <class T> void pin(Vector<T> &a,int size){
        a.resize(size);
        for(int i=0;i<size;i++)a[i].in();
        return ;
    }
    
    

    template <class T> void out(T* a,int size,char c){
        for(int i=0;i<size;i++)std::cout<<a[i]<<c;
        return ;
    }
    template <class T> void out(Vector<T> &a,char c){
        for(int i=0;i<a.size;i++)std::cout<<a[i]<<c;
        return ;
    }
    template <class T> void pout(Vector<T> &a){
        for(int i=0;i<a.size;i++)a[i].out();
        return ;
    }
    template <class T> void dpout(Vector<T> &a){
        std::cout<<a[0].first;
        for(int i=1;i<a.size;i++)std::cout<<" "<<a[i].first;
        std::cout<<"\n"<<a[0].second;
        for(int i=1;i<a.size;i++)std::cout<<" "<<a[i].second;
        std::cout<<"\n";
        return ;
    }
    template <class T> inline void out(T a,char c){
        std::cout<<a<<c;
        return ;
    }
    template <class T> inline void out(T a){
        std::cout<<a;
        return ;
    }
}
using namespace myt;
const int TOP=4e3+10;
const int TT=15e6+10;
const int N=3e5+10;
#include <vector>
#define PB push_back
int main(){
    int n,a[N],ans=0,g,cnt[TT],temp;
    bool f=true,b[TT];
    std::vector<int> v;
    for(int i=3;i<TT;i+=2)b[i]=true;
    v.PB(2);
    for(long long int i=3;i<TT;i+=2)if(b[i]){
        v.PB((int)i);
        for(long long int j=i*i;j<TT;j+=(i<<1))b[j]=false;
    }
    in(n);
    in(a,n);
    for(int i=1;i<n;i++)if(a[i]!=a[0]){
        f=false;
        break;
    }
    if(f){
        out(-1,'\n');
        return 0;
    }
    g=a[0];
    for(int i=1;i<n;i++)g=gcd(g,a[i]);
    for(int i=2;i<TT;i++)cnt[i]=0;
    for(int i=0;i<n;i++)cnt[a[i]/g]++;
    for(int i=0;i<v.size();i++){
        temp=0;
        for(long long int j=v[i];j<TT;j+=v[i])temp+=cnt[j];
        ans=max(ans,temp);
    }
    out(n-ans,'\n');
}