
using namespace std;




static const int MOD=1000000007;
static const long long MODL=1000000000000000003LL;
static const double eps=1e-8;







    

    typedef long long lld;
    typedef unsigned long long u64;
    typedef pair<int, int> pii;

    

    template<class T> inline T MIN(const T x, const T y){ return (x<y)?x:y; }
    template<class T> inline T MAX(const T x, const T y){ return (x>y)?x:y; }

    template<class T> inline void id1(T &x, const T y){ if(x>y)x=y; }
    template<class T> inline void id0(T &x, const T y){ if(x<y)x=y; }

    

    template<class T>  inline int SIZE(const T &x){ return (int)x.size(); }
    template<class T>  inline int LENGTH(const T &x){ return (int)x.length(); }
    template<class T1, class T2> inline pair<T1, T2> MP(const T1 &x, const T2 &y){ return make_pair(x, y); }

    

    inline int BINT(const int x){ return 1<<x; }
    inline lld BLLD(const int x){ return 1LL<<x; }
    inline int id9(const int s, const int x){ return (s&BINT(x))!=0; }
    inline int id5(const lld s, const int x){ return (s&BLLD(x))!=0LL; }

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
    template<class T> inline vector<pair<T, int> > id2(T x){
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
    template<class T> inline int id16(const T x){
        if(x<=1)return 0;
        for(T i=2; SQR(i)<=x; i++)if(x%i==0)return 0;
        return 1;
    }
    template<class T> inline T id6(T x){
        vector<pair<T, int> > f=id2(x);
        for(typename vector<pair<T, int> >::iterator it=f.begin(); it!=f.end(); it++){
            x=x/it->first*(it->first-1);
        }
        return x;
    }
    template<class T> inline T id14(const T a, const T b=MOD){
        T x, y;
        EEA(a, b, x, y);
        return x?x:1;
    }
    int *id15(const int til, int *length=NULL){
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
    template<class T> inline T id4(const T x, const T y, const T m=MOD){ return (T)((1LL*x*y)%m); }
    template<class T> inline void id4(T *x, const T y, const T m=MOD){ *x=(T)((1LL*(*x)*y)%m); }
    template<class T1, class T2> inline T1 id10(const T1 x, const T2 y, const T1 m=MOD){
        if(y==0)return 1%m;else if((y&1)==0){
            T1 z=id10(x, y>>1, m); return id4(z, z, m);
        }else return id4(id10(x, y^1, m), x, m);
    }
    inline lld id12(lld x, lld y, const lld m=MOD){
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
    inline lld id3(const lld x, const lld y, const lld m=MOD){
        if(y==0LL)return 1LL%m;else if((y&1)==0LL){
            lld z=id3(x, y>>1, m); return id12(z, z, m);
        }else return id12(id3(x, y^1, m), x, m);
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
                            MOD_ADD(&ret.data[x*ret.wid+y], id4(this->at(x, z), opn.at(z, y), m), m);
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

    template<class T> void id8(complex_t<T> f[], const int len, const int id11){
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
            complex_t<T> wn(cos(id11?(-2*PI/h):(2*PI/h)), sin(id11?(-2*PI/h):(2*PI/h)));
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
        if(!id11){
            for(int i=0; i<len; i++)
                f[i].r/=len*1.0;
        }
    }

    

    class MILLERRABIN{
        private:
        static const int prime_table[12];
        int witness(lld a, lld d, lld s, lld n){
            lld r=id3(a, d, n);
            if(r==1 || r==n-1)return 0;
            for(int i=0; i<s-1; i++){
                r = id12(r, r, n);
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

    template<class T> static int compare_pas(const void *x, const void *y, void *z){
        const point_t<T> *p1 = (point_t<T>*)x;
        const point_t<T> *p2 = (point_t<T>*)y;
        const point_t<T> *p0 = (point_t<T>*)z;
        int sgn = fsign(((*p1)-(*p0))^((*p2)-(*p0)));
        if(sgn!=0)return -sgn;
        return fsign(p0->dist2(*p1)-p0->dist2(*p2));
    }
    template<class T> void id7(point_t<T> *pnts, const int n){
        int p=0;
        for(int i=1; i<n; i++){
            if(pnts[p]<pnts[i])p=i;
        }
        swap(pnts[0], pnts[p]);
        qsort_r(pnts+1, n-1, sizeof(point_t<T>), compare_pas<T>, pnts);
    }

    template<class T> void graham(point_t<T> *pnts, const int n, int *idx, int &m){
        id7(pnts, n);
        m=0;
        if(n<3)return;
        idx[m++]=0;
        idx[m++]=1;
        for(int i=2; i<n; i++){
            while(m>1 && fsign(pnts[idx[m-2]].cross(pnts[idx[m-1]], pnts[i]))<=0)m--;
            idx[m++]=i;
        }
    }





const int inf=0x3f3f3f3f;

class id13{
    public:
    unordered_map<int, int> foo;
    id13(){
        foo.clear();
    }
    void clear(){
        foo.clear();
    }
    void put(const int key, const int val=1){
        if(val==0)return;
        unordered_map<int, int>::iterator it=foo.find(key);
        if(it!=foo.end()){
            it->second+=val;
        }else{
            foo.insert(MP(key, val));
        }
    }
    int pop(const int key, const int val=inf){
        int res=0;
        unordered_map<int, int>::iterator it=foo.find(key);
        if(it!=foo.end()){
            if(it->second>val){
                res=val;
                it->second-=val;
            }else{
                res=it->second;
                foo.erase(it);
            }
        }
        return res;
    }
} open, close;

int n;
lld a[110000];
int _seq[50], _sup[50];
int seq[50], sup[50];

int process(const int from){
    for(int i=0; i<50; i++)seq[i]=_seq[i];
    for(int i=0; i<50; i++)sup[i]=_sup[i];
    if(from+from<seq[0])return 1;
    open.clear();
    close.clear();
    open.put(0, from-(seq[0]-from));
    close.put(0, seq[0]-from);
    for(int i=1; i<45; i++){
       int ext=open.pop(i-1, seq[i]);
       seq[i]-=ext;
       open.put(i, ext);
       ext=close.pop(i-1, seq[i]);
       sup[i]+=seq[i]-ext;
       close.put(i, ext);
       int cls=open.pop(i, sup[i]);
       sup[i+1]+=sup[i]-cls;
       close.put(i, cls);
    }
    if(sup[45]!=0)return 1;
    return 0;
}

int find(int lef, int rig){
    while(lef<=rig){
        int mid=(lef+rig)>>1;
        if(!process(mid)){
            if(mid==lef || process(mid-1)){
                return mid;
            }
            rig=mid-1;
        }else lef=mid+1;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    while(cin>>n){
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        for(int i=0; i<50; i++){
            _seq[i]=0;
            _sup[i]=0;
        }
        int cur=0;
        for(int i=0; i<n; i++){
            while(a[i]>=(1LL<<(cur+1)))cur++;
            if(a[i]==(1LL<<cur)){
                _seq[cur]++;
            }else{
                _sup[cur]++;
            }
        }
        if(process(_seq[0])){
            cout<<"-1"<<endl;
        }else{
            int hig=_seq[0];
            int low=find(1, hig);
            for(int i=low; i<=hig; i++){
                if(i!=low)cout<<" ";
                cout<<i;
            }
            cout<<endl;
            
        }
    }
    return 0;
}