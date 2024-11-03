#include "bits/stdc++.h"
using namespace std;




static const int MOD=1000000007; 

static const double eps=1e-8;







    

    typedef long long lld;
    typedef unsigned long long u64;
    typedef pair<int, int> pii;

    

    template<class T> inline T MIN(const T x, const T y){ return (x<y)?x:y; }
    template<class T> inline T MAX(const T x, const T y){ return (x>y)?x:y; }

    template<class T> inline void UPDMIN(T &x, const T y){ if(x>y)x=y; }
    template<class T> inline void UPDMAX(T &x, const T y){ if(x<y)x=y; }

    

    template<class T>  inline int SIZE(const T &x){ return (int)x.size(); }
    template<class T>  inline int LENGTH(const T &x){ return (int)x.length(); }
    template<class T1, class T2> inline pair<T1, T2> MP(const T1 &x, const T2 &y){ return make_pair(x, y); }

    

    inline int BINT(const int x){ return 1<<x; }
    inline lld BLLD(const int x){ return 1LL<<x; }
    inline int BINT_TEST(const int s, const int x){ return (s&BINT(x))!=0; }
    inline int BLLD_TEST(const lld s, const int x){ return (s&BLLD(x))!=0LL; }

    template<class T> inline T LOWBIT(const T x){ return (x^(x-1))&x; }
    template<class T> inline int BITCOUNT(const T x){ return (!x)?x:(1+BITCOUNT(x&(x-1))); }

    

    const double PI=acos(-1.0);
    const double EPS=1e-5;

    

    template<class T> inline T SQR(const T x){ return x*x; }
    template<class T1, class T2> inline T1 POW(const T1 x, const T2 y){
        if(!y)return 1;else if((y&1)==0){
            return SQR(POW(x, y>>1));
        }else return POW(x, y^1)*x;
    }

    

    template<class T> inline T GCD(const T x, const T y){
        if(x<0)return GCD(-x, y);
        if(y<0)return GCD(x, -y);
        return (!y)?x:GCD(y, x%y);
    }
    template<class T> inline T LCM(const T x, const T y){
        if(x<0)return LCM(-x, y);
        if(y<0)return LCM(x, -y);
        return x*(y/GCD(x, y));
    }
    template<class T> inline T EEA(const T a, const T b, T &x, T &y){
        
        if(a<0){ T d=EEA(-a, b, x, y); x=-x; return d; }
        if(b<0){ T d=EEA(a, -b, x, y); y=-y; return d; }
        if(!b){
            x=1; y=0; return a;
        }else{
            T d=EEA(b, a%b, x, y);
            T t=x; x=y; y=t-(a/b)*y;
            return d;
        }
    }
    template<class T> inline vector<pair<T, int> > FACTORIZE(T x){
        vector<pair<T, int> > ret;
        if(x<0)x=-x;
        for (T i=2;x>1;){
            if(x%i==0){
                int count=0;
                for(;x%i==0;x/=i)count++;
                ret.push_back(MP(i, count));
            }
            i++;if(i>x/i)i=x;
        }
        return ret;
    }
    template<class T> inline int ISPRIME(const T x){
        if(x<=1)return 0;
        for(T i=2; SQR(i)<=x; i++)if(x%i==0)return 0;
        return 1;
    }
    template<class T> inline T EULARFUNCTION(T x){
        vector<pair<T, int> > f=FACTORIZE(x);
        for(typename vector<pair<T, int> >::iterator it=f.begin(); it!=f.end(); it++){
            x=x/it->first*(it->first-1);
        }
        return x;
    }
    template<class T> inline T INVERSEE(const T a, const T b=MOD){
        T x, y;
        EEA(a, b, x, y);
        return x?x:1;
    }
    int *PRIMELIST(const int til, int *length=NULL){
        int *foo=(int*)malloc(sizeof(int)*(til+1));
        int len=0;
        memset(foo, 0, sizeof(int)*(til+1));
        for(int i=2; i<=til; i++){
            if(!foo[i])foo[len++]=i;
            for(int j=0; j<len && foo[j]<=til/i; j++){
                foo[foo[j]*i]=1;
                if(i%foo[j]==0)break;
            }
        }
        if(length!=NULL){
            *length=len;
        }
        foo[len++]=0;
        foo=(int*)realloc(foo, sizeof(int)*len);
        return foo;
    }

    

    template<class T> inline T MOD_STD(const T x, const T m=MOD){ return (x%m+m)%m; }
    template<class T> inline void MOD_STD(T *x, const T m=MOD){ *x=(*x%m+m)%m; }
    template<class T> inline T MOD_ADD(const T x, const T y, const T m=MOD){ return (x+y)%m; }
    template<class T> inline void MOD_ADD(T *x, const T y, const T m=MOD){ *x=(*x+y)%m; }
    template<class T> inline T MOD_MUL(const T x, const T y, const T m=MOD){ return (T)((1LL*x*y)%m); }
    template<class T> inline void MOD_MUL(T *x, const T y, const T m=MOD){ *x=(T)((1LL*(*x)*y)%m); }
    template<class T1, class T2> inline T1 MOD_POW(const T1 x, const T2 y, const T1 m=MOD){
        if(y==0)return 1%m;else if((y&1)==0){
            T1 z=MOD_POW(x, y>>1, m); return MOD_MUL(z, z, m);
        }else return MOD_MUL(MOD_POW(x, y^1, m), x, m);
    }
    inline lld MODL_MUL(lld x, lld y, const lld m=MOD){
        MOD_STD(&x, m);
        MOD_STD(&y, m);
        if(x<y)swap(x, y);
        lld z=0LL;
        while(y>0){
            if(y&1){
                MOD_ADD(&z, x, m);
            }
            MOD_ADD(&x, x, m);
            y>>=1;
        }
        return z;
    }
    inline lld MODL_POW(const lld x, const lld y, const lld m=MOD){
        if(y==0LL)return 1LL%m;else if((y&1)==0LL){
            lld z=MODL_POW(x, y>>1, m); return MODL_MUL(z, z, m);
        }else return MODL_MUL(MODL_POW(x, y^1, m), x, m);
    }

    

    template<class T> class MATX{
        private:
            unsigned long hig, wid;
            T *data;

            void __init(){
                this->data=(T*)malloc(sizeof(T)*this->hig*this->wid);
                memset(this->data, 0, sizeof(T)*this->hig*this->wid);
            }

        public:
            MATX(){ 
                this->hig=this->wid=1;
                __init();
            }
            MATX(const unsigned long _len){
                this->hig=this->wid=_len;
                __init();
            }
            MATX(const unsigned long _hig, const unsigned long _wid){
                this->hig=_hig;
                this->wid=_wid;
                __init();
            }
            MATX(const MATX &rhs){
                this->hig=rhs.hig;
                this->wid=rhs.wid;
                this->data=(T*)malloc(sizeof(T)*this->hig*this->wid);
                for(unsigned long x=0; x<this->hig; x++)
                    for(unsigned long y=0; y<this->wid; y++)
                        this->data[x*this->wid+y]=rhs.at(x, y);
            }
            ~MATX(){
                free(this->data);
            }

            T & operator()(const unsigned long x, const unsigned long y){
                if(x>=this->hig || y>=this->wid)return (*(T*)NULL);
                return this->data[x*this->wid+y];
            }

            T * operator[](const unsigned long x){
                if(x>=this->hig)return (T*)NULL;
                return this->data+(x*this->wid);
            }

            MATX & operator=(const MATX &rhs){
                if(this->hig!=rhs.hig || this->wid!=rhs.wid){
                    free(this->data);
                    this->hig=rhs.hig;
                    this->wid=rhs.wid;
                    this->data=(T*)malloc(sizeof(T)*this->hig*this->wid);
                }
                for(unsigned long x=0; x<this->hig; x++)
                    for(unsigned long y=0; y<this->wid; y++)
                        this->data[x*this->wid+y]=rhs.at(x, y);
                return *this;
            }

            const MATX operator+(const MATX &opn) const{
                MATX ret(*this);
                for(unsigned long x=0; x<ret.hig; x++)
                    for(unsigned long y=0; y<ret.wid; y++)
                        ret.data[x*ret.wid+y]+=opn.at(x, y);
                return ret;
            }
            const MATX operator-(const MATX &opn) const{
                MATX ret(*this);
                for(unsigned long x=0; x<ret.hig; x++)
                    for(unsigned long y=0; y<ret.wid; y++)
                        ret.data[x*ret.wid+y]-=opn.at(x, y);
                return ret;
            }
            const MATX operator*(const MATX &opn) const{
                MATX ret(this->hig, opn.wid);
                const unsigned long len=MIN(this->wid, opn.hig);
                for(unsigned long x=0; x<ret.hig; x++)
                    for(unsigned long y=0; y<ret.wid; y++)
                        for(unsigned long z=0; z<len; z++)
                            ret.data[x*ret.wid+y]+=this->at(x, z)*opn.at(z, y);
                return ret;
            }

            const MATX mul(const MATX &opn) const{ return *this*opn; }
            template<class T2> const MATX mul(const MATX &opn, const T2 m) const{
                MATX ret(this->hig, opn.wid);
                const unsigned long len=MIN(this->wid, opn.wid);
                for(unsigned long x=0; x<ret.hig; x++)
                    for(unsigned long y=0; y<ret.wid; y++)
                        for(unsigned long z=0; z<len; z++)
                            MOD_ADD(&ret.data[x*ret.wid+y], MOD_MUL(this->at(x, z), opn.at(z, y), m), m);
                return ret;
            }

            MATX & operator +=(const MATX &rhs){
                *this=*this+rhs;
                return *this;
            }
            MATX & operator -=(const MATX &rhs){
                *this=*this-rhs;
                return *this;
            }
            MATX & operator *=(const MATX &rhs){
                *this=*this*rhs;
                return *this;
            }

            const MATX pow(const unsigned long p) const{
                MATX buff(*this), ret(this->hig, this->wid);
                ret.set_one();
                if(p>0)for(unsigned long i=1;;i<<=1){
                    if(p&i)ret*=buff;
                    buff*=buff;
                    if(i>(p>>1))break;
                }
                return ret;
            }
            template<class T2> const MATX pow(const unsigned long p, const T2 m) const{
                MATX buff(*this), ret(this->hig, this->wid);
                ret.set_one();
                if(p>0)for(unsigned long i=1;;i<<=1){
                    if(p&i)ret=ret.mul(buff, m);
                    buff=buff.mul(buff, m);
                    if(i>(p>>1))break;
                }
                return ret;
            }


            const T at(const unsigned long x, const unsigned long y) const{
                if(x>=this->hig || y>=this->wid)return 0;
                return this->data[x*wid+y];
            }

            void show() const{
                for(unsigned long x=0; x<this->hig; x++){
                    for(unsigned long y=0; y<this->wid; y++)
                        cout<<this->at(x, y)<<" ";
                    cout<<endl;
                }
            }

            void set_one(){
                for(unsigned long x=0; x<this->hig; x++)
                    for(unsigned long y=0; y<this->wid; y++)
                        this->data[x*this->wid+y]=(x==y)?1:0;
            }

    };

    

    template<class T> class complex_t{
        public:
        T r, i;

        complex_t(T x=0.0, T y=0.0){ this->r=x; this->i=y; }
        complex_t operator + (const complex_t &opn) const { return complex_t(this->r+opn.r, this->i+opn.i); }
        complex_t operator - (const complex_t &opn) const { return complex_t(this->r-opn.r, this->i-opn.i); }
        complex_t operator * (const complex_t &opn) const { return complex_t(this->r*opn.r-this->i*opn.i, this->r*opn.i+this->i*opn.r); }
    };

    template<class T> void fast_fourier_trans(complex_t<T> f[], const int len, const int is_dft){
        for(int i=1, j=len>>1; i<len-1; i++){
            if(i<j)swap(f[i], f[j]);
            int k=len>>1;
            while(j>=k){
                j-=k;
                k>>=1;
            }
            if(j<k)j+=k;
        }
        for(int h=2; h<=len; h<<=1){
            complex_t<T> wn(cos(is_dft?(-2*PI/h):(2*PI/h)), sin(is_dft?(-2*PI/h):(2*PI/h)));
            for(int i=0; i<len; i+=h){
                complex_t<T> wm(1.0, 0.0);
                for(int j=i; j<i+(h>>1); j++){
                    complex_t<T> u = f[j];
                    complex_t<T> t = wm*f[j+(h>>1)];
                    f[j] = u+t;
                    f[j+(h>>1)] = u-t;
                    wm = wm*wn;
                }
            }
        }
        if(!is_dft){
            for(int i=0; i<len; i++)
                f[i].r/=len*1.0;
        }
    }

    

    class MILLERRABIN{
        private:
        static const int prime_table[12];
        int witness(lld a, lld d, lld s, lld n){
            lld r=MODL_POW(a, d, n);
            if(r==1 || r==n-1)return 0;
            for(int i=0; i<s-1; i++){
                r = MODL_MUL(r, r, n);
                if(r==1)return 1;
                if(r==n-1)return 0;
            }
            return 1;
        }
        public:
        int test(const lld n){
            if(n<=2LL) return 0;
            lld p=n-1LL, s=0LL;
            while(!(p&1)){ p>>=1;s++; }
            for(int i=0; i<12 && this->prime_table[i]<n; i++){
                if(witness(this->prime_table[i], p, s, n))return 0;
            }
            return 1;
        }
    };
    const int MILLERRABIN::prime_table[12] = { 2, 3, 5, 7, 11, 13 ,17, 19, 23, 29, 31, 37 };

    


    template<class T> inline int fsign(const T x){
        if(x>-eps && x<eps)return 0;
        return (x<0.0)?-1:1;
    }

    template<class T> class point_t{
        public:
        T x, y;
        point_t (){
            this->x=0.0;
            this->y=0.0;
        }
        point_t (const T _x, const T _y){
            this->x=_x;
            this->y=_y;
        }
        point_t operator - (const point_t &rhs) const{
            return point_t(this->x-rhs.x, this->y-rhs.y);
        }
        T operator ^ (const point_t &rhs) const{
            return this->x*rhs.y - this->y*rhs.x;
        }
        T operator * (const point_t &rhs) const{
            return this->x*rhs.x + this->y*rhs.y;
        }
        bool operator < (const point_t &rhs) const{
            if(fsign(this->y-rhs.y)!=0)
                return fsign(this->y-rhs.y)<0;
            return fsign(this->x-rhs.x)<0;
        }
        T cross(const point_t &p, const point_t &q) const{
            return (p-*this)^(q-*this);
        }
        void rotate(const double radian){
            T x0=x, y0=y;
            T sinr=sin(radian);
            T cosr=cos(radian);
            x=x0*cosr-y0*sinr;
            y=x0*sinr+y0*cosr;
        }
        void rotate(const point_t &p, const double radian){
            T x0=x-p.x, y0=y-p.y;
            T sinr=sin(radian);
            T cosr=cos(radian);
            x=x0*cosr-y0*sinr+p.x;
            y=x0*sinr+y0*cosr+p.y;
        }
        T dist2(const point_t &lhs, const point_t &rhs) const{
            return (lhs-rhs)*(lhs-rhs);
        }
        T dist2(const point_t &rhs) const{
            return (*this-rhs)*(*this-rhs);
        }
        T dist(const point_t &lhs, const point_t &rhs) const{
            return sqrt((lhs-rhs)*(lhs-rhs));
        }
        T dist(const point_t &rhs) const{
            return sqrt((*this-rhs)*(*this-rhs));
        }
    };

    template<class T> class segment_t{
        public:
        point_t<T> p, q;
        segment_t (){
            this->p.x=this->p.y=0.0;
            this->q.x=this->q.y=0.0;
        }
        template<class T2> segment_t (const point_t<T2> &_p, const point_t<T2> &_q){
            this->p.x=_p.x;
            this->p.y=_p.y;
            this->q.x=_q.x;
            this->q.y=_q.y;
        }
        segment_t (const T px, const T py, const T qx, const T qy){
            this->p.x=px;
            this->p.y=py;
            this->q.x=qx;
            this->q.y=qy;
        }
        T length() const{
            return this->p.dist(this->q);
        }
        T length2() const{
            return this->p.dist2(this->q);
        }
        int contain(const point_t<T> &pnt, const int ignore_endpoint=0) const{
            if(ignore_endpoint){
                return fsign((this->p-pnt)^(this->q-pnt))==0
                    && fsign((pnt.x-this->p.x)*(pnt.x-this->q.x)) <0
                    && fsign((pnt.y-this->p.y)*(pnt.y-this->q.y)) <0;
            }else{
                return fsign((this->p-pnt)^(this->q-pnt))==0
                    && fsign((pnt.x-this->p.x)*(pnt.x-this->q.x)) <=0
                    && fsign((pnt.y-this->p.y)*(pnt.y-this->q.y)) <=0;
            }
        }
        int intersection(const segment_t &sa, const segment_t &sb, const int ignore_endpoint=0) const{
            if(!ignore_endpoint){
                if(sa.contain(sb.p) || sa.contain(sb.q) || sb.contain(sa.p) || sb.contain(sa.q))
                    return 1;
            }
            return fsign(sa.p.cross(sa.q, sb.p))*fsign(sa.p.cross(sa.q, sb.q))<0
                && fsign(sb.p.cross(sb.q, sa.p))*fsign(sb.p.cross(sb.q, sa.q))<0;
        }
        int intersection(const segment_t &rhs, const int ignore_endpoint=0) const{
            return this->intersection(*this, rhs, ignore_endpoint);
        }
    };

    #ifndef __APPLE__
    template<class T> static int compare_pas(const void *x, const void *y, void *z){
    #else
    template<class T> static int compare_pas(void *z, const void *x, const void *y){
    #endif
        const point_t<T> *p1 = (point_t<T>*)x;
        const point_t<T> *p2 = (point_t<T>*)y;
        const point_t<T> *p0 = (point_t<T>*)z;
        int sgn = fsign(((*p1)-(*p0))^((*p2)-(*p0)));
        if(sgn!=0)return -sgn;
        return fsign(p0->dist2(*p1)-p0->dist2(*p2));
    }
    template<class T> void polar_angle_sort(point_t<T> *pnts, const int n){
        int p=0;
        for(int i=1; i<n; i++){
            if(pnts[p]<pnts[i])p=i;
        }
        swap(pnts[0], pnts[p]);
        #ifndef __APPLE__
        qsort_r(pnts+1, n-1, sizeof(point_t<T>), compare_pas<T>, pnts);
        #else
        qsort_r(pnts+1, n-1, sizeof(point_t<T>), pnts, compare_pas<T>);
        #endif
    }

    template<class T> void graham(point_t<T> *pnts, const int n, int *idx, int &m){
        polar_angle_sort(pnts, n);
        m=0;
        if(n<3)return;
        idx[m++]=0;
        idx[m++]=1;
        for(int i=2; i<n; i++){
            while(m>1 && fsign(pnts[idx[m-2]].cross(pnts[idx[m-1]], pnts[i]))<=0)m--;
            idx[m++]=i;
        }
    }

    

    template<class T> class maxflow_c{
        private:
        size_t capv, cape;
        size_t cnte;
        struct mf_edge_t;
        struct mf_vertex_t{
            mf_edge_t *head, *hold;
            size_t idx, hig;
        } *vertex, **vque;
        struct mf_edge_t{
            mf_vertex_t *src, *dst;
            mf_edge_t *nxt, *rsv;
            T cap, cur;
        } *edge_pool, *edge_tail;
        struct dncnode_t{
            mf_vertex_t *vtx;
            T precap, reflux;
        } *dinic_stack_pool;
        public:
        maxflow_c(const size_t numv, const size_t nume){
            this->capv=numv;
            this->cape=nume;
            this->vertex=(mf_vertex_t*)malloc(sizeof(mf_vertex_t)*numv);
            for(size_t i=0; i<numv; i++){
                this->vertex[i].idx=i;
            }
            this->vque=NULL;
            this->edge_pool=(mf_edge_t*)malloc(sizeof(mf_edge_t)*(nume<<1));
            this->dinic_stack_pool=NULL;
            this->reset();
        };
        ~maxflow_c(){
            if(this->dinic_stack_pool!=NULL)
                free(this->dinic_stack_pool);
            free(this->edge_pool);
            if(this->vque!=NULL)
                free(this->vque);
            free(this->vertex);
        }
        void reset(){
            for(size_t i=0; i<this->capv; i++)
                this->vertex[i].head=NULL;
            this->edge_tail=this->edge_pool;
            this->cnte=0;
        }
        void add_edge(const size_t u, const size_t v, const T c, const T r=0){
            assert(u<this->capv && v<this->capv);
            assert(this->cnte<this->cape);
            this->edge_tail->nxt=this->vertex[u].head;
            this->edge_tail->rsv=this->edge_tail+1;
            this->edge_tail->src=&this->vertex[u];
            this->edge_tail->dst=&this->vertex[v];
            this->edge_tail->cap=c;
            this->edge_tail->cur=0;
            this->vertex[u].head=this->edge_tail++;
            this->edge_tail->nxt=this->vertex[v].head;
            this->edge_tail->rsv=this->edge_tail-1;
            this->edge_tail->src=&this->vertex[v];
            this->edge_tail->dst=&this->vertex[u];
            this->edge_tail->cap=r;
            this->edge_tail->cur=0;
            this->vertex[v].head=this->edge_tail++;
            this->cnte++;
        }
        size_t higlev(const size_t src, const size_t trm){
            assert(src<this->capv && trm<this->capv);
            if(this->vque==NULL)
                this->vque=(mf_vertex_t**)malloc(sizeof(mf_vertex_t*)*this->capv);
            size_t lef=0, rig=0;
            for(size_t i=0; i<this->capv; i++)
                this->vertex[i].hig=numeric_limits<size_t>::max();
            this->vertex[src].hig=0;
            this->vque[rig++]=&this->vertex[src];
            for(; lef<rig; lef++){
                mf_vertex_t *vtx=this->vque[lef];
                for(mf_edge_t *edge=vtx->head; edge!=NULL; edge=edge->nxt){
                    if(edge->cur<edge->cap && edge->dst->hig>vtx->hig+1){
                        edge->dst->hig=vtx->hig+1;
                        this->vque[rig++]=edge->dst;
                    }
                }
            }
            this->vque[rig++]=NULL;
            return this->vertex[trm].hig;
        }
        T dinic(const size_t src, const size_t trm){
            assert(src<this->capv && trm<this->capv && src!=trm);
            T foo=0;
            if(this->dinic_stack_pool==NULL)
                this->dinic_stack_pool=(dncnode_t*)malloc(sizeof(dncnode_t)*this->capv);
            while(higlev(src, trm)<numeric_limits<size_t>::max()){
                for(size_t i=0; this->vque[i]!=NULL; i++){
                    this->vque[i]->hold=this->vque[i]->head;
                }
                dncnode_t *top=this->dinic_stack_pool;
                top->vtx=&this->vertex[src];
                top->precap=numeric_limits<T>::max();
                top->reflux=0;
                while(this->vertex[src].hold!=NULL){
                    if(top->vtx->idx!=trm && top->vtx->hold!=NULL && top->vtx->hold->cur<top->vtx->hold->cap && top->vtx->hold->src->hig+1==top->vtx->hold->dst->hig){
                        dncnode_t *prv=top++;
                        top->vtx=prv->vtx->hold->dst;
                        top->precap=MIN(prv->precap-prv->reflux, prv->vtx->hold->cap-prv->vtx->hold->cur);
                        top->reflux=0;
                    }else if(top->vtx->idx==trm){
                        T inc=top->precap;
                        foo+=inc;
                        while(top->precap==top->reflux+inc){
                            inc+=top->reflux;
                            top--;
                            top->vtx->hold->cur+=inc;
                            top->vtx->hold->rsv->cur-=inc;
                        }
                        top->reflux+=inc;
                    }else{
                        if(top->vtx->hold==NULL){
                            T ref=top->reflux;
                            top--;
                            top->vtx->hold->cur+=ref;
                            top->vtx->hold->rsv->cur-=ref;
                            top->reflux+=ref;
                        }
                        top->vtx->hold=top->vtx->hold->nxt;
                    }
                }
            }
            return foo;
        }
    };




struct stnode_t{
    int lef, rig;
    lld val;
    stnode_t *chd[2];
} pool[6000000], *head[110000];

struct stnode_queue_t{
    size_t lef, rig;
    size_t req, cnt;
    stnode_t *foo[6000000];
    void clear(){
        this->lef=this->rig=0;
        this->req=this->cnt=0;
    }
    stnode_t *get(){
        this->req++;
        assert(this->req<=this->cnt);
        this->lef++;
        if(this->lef==6000000)this->lef=0;
        return this->foo[this->lef];
    }
    void set(stnode_t *spot){
        this->cnt++;
        this->foo[this->rig]=spot;
        this->rig++;
        if(this->rig==6000000)this->rig=0;
    }
} nodeq;

int n, m;
int cur[110000];

set<int> seq[110000];

void build(stnode_t **hook, const int lef, const int rig){
    stnode_t *node=*hook=nodeq.get();
    node->lef=lef;
    node->rig=rig;
    node->val=0LL;
    if(lef!=rig){
        const int mid=(lef+rig)>>1;
        build(&node->chd[0], lef, mid);
        build(&node->chd[1], mid+1, rig);
    }else{
        node->chd[0]=node->chd[1]=NULL;
    }
}

inline void recycl(stnode_t *node, stnode_t *zero){
    if(node->chd[0]!=NULL && node->chd[0]!=zero->chd[0])recycl(node->chd[0], zero->chd[0]);
    if(node->chd[1]!=NULL && node->chd[1]!=zero->chd[1])recycl(node->chd[1], zero->chd[1]);
    nodeq.set(node);
}

void update(stnode_t **hook, stnode_t *zero, const int y, const lld d){
    stnode_t *node=*hook;
    if(node->val+d==0LL){
        

        recycl(node, zero);
        node=*hook=zero;
    }else{
        stnode_t prev=*node;
        if(node!=zero)
            nodeq.set(node);
        node=*hook=nodeq.get();
        node->lef=prev.lef;
        node->rig=prev.rig;
        node->val=prev.val+d;
        node->chd[0]=prev.chd[0];
        node->chd[1]=prev.chd[1];
        if(node->chd[0]!=NULL && y<=node->chd[0]->rig){
            update(&node->chd[0], zero->chd[0], y, d);
        }else if(node->chd[1]!=NULL && y>=node->chd[1]->lef){
            update(&node->chd[1], zero->chd[1], y, d);
        }
    }
    

}

void update(const int x, const int y, const lld d){
    for(int i=x; i<=n; i+=LOWBIT(i)){
        

        update(&head[i], head[0], y, d);
    }
}

lld presum(stnode_t *node, const int rig){
    if(node->rig<=rig){
        

        return node->val;
    }else{
        lld foo=0LL;
        if(rig>=node->chd[0]->lef){
            foo+=presum(node->chd[0], rig);
        }
        if(rig>=node->chd[1]->lef){
            foo+=presum(node->chd[1], rig);
        }
        return foo;
    }
}

lld presum(const int x, const int y){
    lld foo=0LL;
    for(int i=x; i; i-=LOWBIT(i)){
        

        foo+=presum(head[i], y);
    }
    return foo;
}

inline uint32_t getuint32(){
    uint32_t foo=0;
    char c=0;
    while(c<'0' || c>'9')
        c=getchar();
    while('0'<=c && c<='9'){
        foo=foo*10+(c-'0'); 
        c=getchar();
    }
    return foo;
}

int main(){
    ios::sync_with_stdio(0);
    

    if(1){
        n=getuint32();
        m=getuint32();
        nodeq.clear();
        for(int i=0; i<6000000; i++)nodeq.set(&pool[i]);
        for(int i=0; i<n; i++)seq[i].clear();
        build(&head[0], 1, n);
        for(int i=1; i<=n; i++)head[i]=head[0];
        for(int y=1; y<=n; y++){
            int c;
            

            c=getuint32();
            c--;
            cur[y]=c;
            seq[c].insert(y);
            if(SIZE(seq[c])>1){
                set<int>::iterator it=seq[c].find(y);
                it--;
                int x=*it;
                update(x, y, y-x);
            }
        }
        for(int i=0; i<m; i++){
            int z, x, y;
            

            z=getuint32();
            x=getuint32();
            y=getuint32();
            if(z==1){
                

                int c=cur[x];
                set<int>::iterator it=seq[c].find(x);
                if(SIZE(seq[c])>1){
                    int pos=x;
                    int prv=-1;
                    int nxt=-1;
                    if(it!=seq[c].begin()){
                        it--;
                        prv=*it++;
                    }
                    if((++it)!=seq[c].end()){
                        nxt=*it;
                    }
                    it--;
                    if(~prv){
                        update(prv, pos, prv-pos);
                    }
                    if(~nxt){
                        update(pos, nxt, pos-nxt);
                    }
                    if(~prv && ~nxt){
                        update(prv, nxt, nxt-prv);
                    }
                }
                seq[c].erase(it);
                

                c=y-1;
                seq[c].insert(x);
                it=seq[c].find(x);
                if(SIZE(seq[c])>1){
                    int pos=x;
                    int prv=-1;
                    int nxt=-1;
                    if(it!=seq[c].begin()){
                        it--;
                        prv=*it++;
                    }
                    if((++it)!=seq[c].end()){
                        nxt=*it;
                    }
                    it--;
                    if(~prv && ~nxt){
                        update(prv, nxt, prv-nxt);
                    }
                    if(~prv){
                        update(prv, pos, pos-prv);
                    }
                    if(~nxt){
                        update(pos, nxt, nxt-pos);
                    }
                }
                cur[x]=c;
            }else{
                cout<<presum(y, y)-presum(x-1, y)<<endl;
            }
        }
    }
    return 0;
}
