











                                   

#include        <map>              

 #include       <set>             

  #include      <list>           

   #include     <ctime>         

   #include     <cmath>         

  #include      <queue>          

 #include       <deque>           

#include        <vector>           

#include        <string>           

 #include       <cstdio>          

  #include      <cstdlib>        

   #include     <iomanip>       

   #include     <conio.h>       

  #include      <cstdarg>        

 #include       <string.h>        

#include        <iostream>         

#include        <algorithm>        

                                  

using namespace std;             

                                

typedef long long       LL;     

typedef long double     LD;      

                                  

typedef set <int>       SI;        

typedef set <LL>        SL;        

typedef vector <int>    VI;       

typedef vector <LL>     VL;      

typedef map <int, int>  MII;    

typedef map <LL, int>   MLI;    

typedef map <LL, LL>    MLL;    

typedef pair <int, int> PII;     

typedef pair <LL, LL>   PLL;      

typedef vector <PII>    VPII;      

typedef vector <PLL>    VPLL;      

typedef set <PII>       SPII;     

typedef set <PLL>       SPLL;    

typedef deque <int>     QI;     

typedef deque <LL>      QL;     

typedef deque <PII>     QPII;    

typedef deque <PLL>     QPLL;     

                                   




#define y0 kJesAn8JhyEgzkno
#define y1 g30Nw3ymqaurzaN3
#define yn mdoANnEj1m5V8g7S
#define j1 NMlhtyfqMoapN4Br
#define tm a3F49kBH56bdQsRO
#define lr SodXmN2Ffn3l3AzR

#define endl '\n'
#define EPS 1e-8l
#define INFD 1e12l
#define INF32 ~(1l<<31l)
#define INF64 ~(1ll<<63ll)
#define HAII ('z'-'a'+2)
#define MOD7 1000000007ll
#define MOD9 1000000009ll
#ifdef __GNUC__
 #define TYP typeof
#else
 #define TYP decltype
#endif
#define MPR(a,b) make_pair<TYP(a),TYP(a)>((TYP(a))(a),(TYP(a))(b))
#define FOR(i,f,t) for(TYP(f+0)_=t,i=f;i<=_;++i)
#define FORd(i,f,t)for(TYP(f+0)_=t,i=f;i>=_;--i)
#define RFI(t)     for(TYP(t+0)_=t,i=0;i<=_;++i)
#define RFJ(t)     for(TYP(t+0)_=t,j=0;j<=_;++j)
#define RFZ RFI
#define WLK(i,c)   for(TYP((c). begin())i=(c). begin();i!=(c). end();++i)
#define WLKr(i,c)  for(TYP((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)
#define WBI(i,b,x) for(TYP((int)0+x) _=x,i=0,b=_&1ll;i<sizeof(x)<<3;b=0!=(_&1ll<<++i))
#define WBIr(i,b,x) for(TYP((int)0+x) _=x,i=(sizeof(x)<<3)-1,b=0!=(_&(1ll<<(sizeof(x)<<3)-1));i>=0;b=0!=(_&1ll<<--i))
#define WBS(i,x)   WBI(i,__,x)if( __)
#define WBSr(i,x) WBIr(i,__,x)if( __)
#define WBC(i,x)   WBI(i,__,x)if(!__)
#define WBCr(i,x) WBIr(i,__,x)if(!__)
#define ITR(x)  TYP(x. begin())
#define ITRr(x) TYP(x.rbegin())

#define SWITCH(x) switch(x){
#define CASE(x) case x:{
#define ESAC    }break;
#define DONNER  default:{
#define IMMER   while(1)
#define WENN(x) if(x){
#define DANN(x) }else if(x){
#define SONST   }else{
#define GUT     }




template <typename T> const T&CIN(){static T x;cin>>x;return x;}
#define GIB(T) CIN<T>()
#define GIBi CIN<int>()
#define GIBf CIN<LD>()
#define GIBl CIN<LL>()
#define GIBs CIN<string>()


#define CLSS(x) clock_t x=clock();
#define CLSE(x,stm)stm<<"Time for '"<<#x<<"' is "<<(LD)(clock()-x)/CLOCKS_PER_SEC<<" sec"<<endl;
#define CLSEE(x) CLSE(x,cerr)
#define CLSEO(x) CLSE(x,cout)



template <typename TY, typename TX> TX B2L(TY(*f)(const TX&),TX l,TX r,const TY&q){while(l!=r){TX mit=l+r>>1;  if(f(mit)<q)l=mit+1;else r=mit;}return l;}
template <typename TY, typename TX> TX B2R(TY(*f)(const TX&),TX l,TX r,const TY&q){while(l!=r){TX mit=l+r+1>>1;if(f(mit)>q)r=mit-1;else l=mit;}return l;}
template <typename TY, typename TX> TX B2F(TY(*f)(const TX&),TX l,TX r,const TY&q){while(r-l<EPS){TX mit=(l+r)/2.0l;if(f(mit)<q)l=mit;else r=mit;}return (l+r)/2.0l;}

template <typename TY, typename TX> TX T3A(TY(*f)(const TX&),TX l,TX r,const TY&d=6){TY t;while(r-l>=d){t=(r-l)/3;TY xl=l+t,xr=r-t;if(f(xl)>f(xr)) r=xr;else l=xl;}TY o=f(l);if(r-l>=1)FOR(i,l,r)if((t=f(i))>o){o=t;l=i;};return l;}
template <typename TY, typename TX> TX T3I(TY(*f)(const TX&),TX l,TX r,const TY&d=6){TY t;while(r-l>=d){t=(r-l)/3;TY xl=l+t,xr=r-t;if(f(xl)<f(xr)) r=xr;else l=xl;}TY o=f(l);if(r-l>=1)FOR(i,l,r)if((t=f(i))<o){o=t;l=i;};return l;}

template <typename T> T SQR(const T&x){return x*x;}
template <typename T> T PWM(const T&x,const T&e,const T&m){T y=x,r=1;WBI(i,b,e){if(b)r=r*y%m;y=y*y%m;};return r;}
template <typename T> T INV(const T&x,const T&m){return PWM<T>(x,m-2,m);}
template <typename T> T GCD(const T&a,const T&b){T x=a,y=b;while(y){x%=y;swap(x,y);}return x;}

template <typename T> T HYP(const T&x,const T&y){return sqrt(x*x+y*y);}
template <typename T> T DTL(const T&A,const T&B,const T&C,const T&px,const T&py){return fabsl(A*px+B*py+C)/sqrtl(A*A+B*B);}

template <typename T> void ABC(T&A,T&B,T&C,const T&px1,const T&py1,const T&px2,const T&py2){A=py2-py1;B=px1-px2;C=-A*px1-B*py1;}

template <typename T> int F12(T x,map<T,int>&r){int o=0;while(x>1){int f=0;for(T i=2;i*i<=x;++i)if(0==x%i){++o;++r[i];x/=i;f=1;break;}if(!f){++o;++r[x];break;}}return o;}
template <typename T> int C12(T x){int o=0;while(x>1){int f=0;for(T i=2;i*i<=x;++i)if(0==x%i){++o;x/=i;f=1;break;}if(!f){++o;break;}}return o;}
template <typename T> void DEN(typename map<T,int>::const_iterator b,typename map<T,int>::const_iterator e,vector<T>&r,T z=1){if(b==e){r.push_back(z);return;}TYP(b)c=b;++c;RFZ(b->second){DEN(c,e,r,z);z*=b->first;}}

template <typename T> void DMP(vector<T>&x){WLK(it,x)cout<<*it<<' ';cout<<endl;};

PLL operator +(const PLL&l, const PLL&r){
    return make_pair(l.first + r.first, 0);
}

PLL operator -(const PLL&l, const PLL&r){
    return make_pair(l.first - r.first, 0);
}

#include <stdint.h>
#define DEN_RECOUNT(x) x->cnt=1+(0==x->recht?0:x->recht->cnt)+(0==x->links?0:x->links->cnt);x->kesum=x->key+(0==x->recht?T():x->recht->kesum)+(0==x->links?T():x->links->kesum)
#define DEN_REVATER(x) if(x->recht)x->recht->vater=x;if(x->links)x->links->vater=x
#define DEN_REVATERL(x) if(x->links)x->links->vater=x
#define DEN_REVATERR(x) if(x->recht)x->recht->vater=x
#define DEN_RENEUER(x) DEN_RECOUNT(x); DEN_REVATER(x)
#define DEN_RENEUERR(x) DEN_RECOUNT(x); DEN_REVATERR(x)
#define DEN_RENEUERL(x) DEN_RECOUNT(x); DEN_REVATERL(x)










template <typename T>
class Der {
public:

    class Den {
    friend class Der <T>;
    public:
        T key;

        Den *vater;
        Den *links;
        Den *recht;

        Den(Der <T> *d) :                      cnt(1), vater(NULL), links(NULL), recht(NULL), priora(d->_random())           {};
        Den(Der <T> *d, T k) :                 cnt(1), kesum(k), vater(NULL), links(NULL), recht(NULL), priora(d->_random()), key(k)   {};
        Den(Der <T> *d, T k, Den *l, Den *r) : cnt(1), kesum(k), vater(NULL), links(l),    recht(r),    priora(d->_random()), key(k)   {DEN_RENEUER(this);};
        Den(const Den &x) :                    cnt(x.cnt), kesum(x.kesum), vater(NULL), links(x.l),  recht(x.r),  priora(x.priora),     key(x.k) {};
    private:
        T kesum;
        uint64_t priora;
        size_t cnt;
        Der <T> *der;
    };

    class iterator {
    friend class Der <T>;
    public:

        const T &operator *() const {
            if(NULL == this->den) return this->null_key;
            return this->den->key;
        }

        const T *operator ->() const {
            if(NULL == this->den) return &this->null_key;
            return &this->den->key;
        }

        iterator &operator ++(){
            this->_increment();
            return *this;
        }

        iterator &operator ++(int){
            iterator temp(*this);
            this->_increment();
            return temp;
        }

        iterator &operator --(){
            this->_decrement();
            return *this;
        }

        iterator &operator --(int){
            iterator temp(*this);
            this->_decrement();
            return temp;
        }

        bool operator != (const iterator &l) const {
            return l.den != this->den;
        }

        bool operator == (const iterator &l) const {
            return l.den == this->den;
        }

        iterator() :                  den(NULL)  {}
        iterator(Den *n) :            den(n)     {}
        iterator(const iterator &i) : den(i.den) {}

    protected:

        T null_key;
        Den *den;

        void __fastcall _increment(){
            if(NULL == this->den) return;

            if(NULL != this->den->recht){
                this->den = this->den->recht;

                

                if(NULL != this->den) while(this->den->links) this->den = this->den->links;

            }else{
                while(NULL != this->den->vater){
                    

                    if(this->den->vater->links == this->den){
                        this->den = this->den->vater;
                        return;
                    }else{
                        this->den = this->den->vater;
                    }
                }

                

                if(NULL == this->den->vater){
                    this->den = NULL;
                }
            }
        }

        void __fastcall _decrement(){
            if(NULL == this->den) return;

            if(NULL != this->den->links){
                this->den = this->den->links;

                

                if(NULL != this->den) while(this->den->recht) this->den = this->den->recht;

            }else{
                while(NULL != this->den->vater){
                    

                    if(this->den->vater->recht == this->den){
                        this->den = this->den->vater;
                        return;
                    }else{
                        this->den = this->den->vater;
                    }
                }

                

                if(NULL == this->den->vater){
                    this->den = NULL;
                }
            }
        }
    };

    class reverse_iterator : public iterator {
    public:
        iterator &operator ++(){
            this->_decrement();
            return *this;
        }

        iterator operator ++(int){
            iterator temp(*this);
            this->_decrement();
            return temp;
        }

        iterator &operator --(){
            this->_increment();
            return *this;
        }

        iterator operator --(int){
            iterator temp(*this);
            this->_increment();
            return temp;
        }

        reverse_iterator() :                          iterator()  {}
        reverse_iterator(Den *n) :                    iterator(n) {}
        reverse_iterator(const reverse_iterator &i) : iterator(i) {}
    };

    Der(){
        this->_init();
    };

    iterator __fastcall begin() const {
        Den *noch = this->root;
        if(NULL != noch) while(NULL != noch->links) noch = noch->links;
        return iterator(noch);
    }

    const iterator &__fastcall end() const {
        return this->ende;
    }

    reverse_iterator __fastcall rbegin() const {
        Den *noch = this->root;
        if(NULL != noch){
            while(NULL != noch->recht){
                noch = noch->recht;
            }

        }
        return reverse_iterator(noch);
    }

    const reverse_iterator &__fastcall rend() const {
        return this->rende;
    }

    size_t __fastcall count(const T &x) const {
        return NULL != this->_find(x);
    }

    size_t __fastcall size() const {
        return (NULL != this->root) ? this->root->cnt : 0;
    }

    bool __fastcall insert(const T &x){
        if(NULL != this->_find(x)) return false;
        if(NULL == root){
            this->root = new Den(this, x);
        }else{
            Den *l, *r;
            Den *ntw = new Den(this, x);

            this->_split(this->root, x, &l, &r);

            this->root = this->_merge(l, this->_merge(ntw, r));
        }
        return true;
    }

    bool __fastcall erase(const T &x){
        Den *den = this->_find(x);
        if(NULL == den) return false;
        this->_erase(den);
        return true;
    }

    bool __fastcall erase(const iterator &it){
        Den *den = it.den;
        if(NULL == den) return false;
        this->_erase(den);
        return true;
    }

    bool __fastcall erase_index(size_t index){
        Den *den = this->_find_index(index);
        if(NULL == den) return false;
        this->_erase(den);
        return true;
    }

    const T &at_index(size_t index) const {
        if(index >= this->size()) return this->null_key;
        Den *elm = this->_find_index(index);
        if(NULL == elm) return null_key;
        return elm->key;
    }

    const T &operator [](size_t index) const {
        if(index >= this->size()) return this->null_key;
        Den *elm = this->_find_index(index);
        if(NULL == elm) return null_key;
        return elm->key;
    }

    void __fastcall sumiert_ein(const T &x, T &li, T &re){
        li = re = T();
        if(NULL == this->root) return;
        Den *l, *r, *la, *ra;
        this->_split(this->root, x, &l, &r);
        


        li = l?l->kesum:T();
        re = r?r->kesum-r->key:T();

        this->root = this->_merge(l, r);
    }

    int32_t index_of(const T &x) const {
        Den *noch = this->root;
        if(NULL == noch) return -1;
        int32_t index = (NULL != noch->links) ? noch->links->cnt : 0;
        while(NULL != noch){
            if(noch->key < x){
                index += ((NULL != noch->recht && NULL != noch->recht->links) ? noch->recht->links->cnt : 0) + 1;
                noch = noch->recht;
            }else if(x < noch->key){
                index -= ((NULL != noch->links && NULL != noch->links->recht) ? noch->links->recht->cnt : 0) + 1;
                noch = noch->links;
            }else{
                return index;
            }
        }

        return -1;
    }

    iterator lower_bound(const T &x) const {
        Den *last, *noch = this->root;
        if(NULL == noch) return this->ende;
        last = NULL;

        while(NULL != noch){
            if(noch->key < x){
                noch = noch->recht;
            }else{
                last = noch;
                noch = noch->links;
            }
        }

        return iterator(last);
    }

    iterator upper_bound(const T &x) const {
        Den *last, *noch = this->root;
        if(NULL == noch) return this->ende;
        last = NULL;

        while(NULL != noch){
            if(noch->key <= x){
                noch = noch->recht;
            }else{
                last = noch;
                noch = noch->links;
            }
        }

        return iterator(last);
    }



private:

    T null_key;
    reverse_iterator rende;
    iterator ende;
    Den *root;
    uint64_t rseed;

    void _init(){
        this->root = NULL;
        this->rseed = (uint64_t) clock() + (uint64_t) time(NULL) * 0x43CB86F5E5ADD14Fll ^ 0xCB6E1B39BC5BE523ll;
    }

    uint64_t _random(){
        return this->rseed = this->rseed * 0x772AB22AEE93217Fll + 0x2923D6E4F44DACE1ll ^ 0x55EE1E3CFAE37628ll;
    }

    Den * __fastcall _merge(Den *l, Den *r){
        if(NULL == l) return r;
        if(NULL == r) return l;

        if(l->priora > r->priora){
            l->recht = this->_merge(l->recht, r);
            DEN_RENEUERR(l);
            return l;
        }else{
            r->links = this->_merge(l, r->links);
            DEN_RENEUERL(r);
            return r;
        }
    }

    void __fastcall _split(Den *wu, const T &x, Den **l, Den **r){
        if(NULL == wu){
            *l = *r = NULL;
        }else if(wu->key < x){
            this->_split(wu->recht, x, &wu->recht, r);
            *l = wu;
            DEN_RENEUERR(wu);
        }else{
            this->_split(wu->links, x, l, &wu->links);
            *r = wu;
            DEN_RENEUERL(wu);
        }
    }

    void __fastcall _split_reverse(Den *wu, const T &x, Den **l, Den **r){
        if(NULL == wu){
            *l = *r = NULL;
        }else if(wu->key <= x){
            this->_split_reverse(wu->recht, x, &wu->recht, r);
            *l = wu;
            DEN_RENEUERR(wu);
        }else{
            this->_split_reverse(wu->links, x, l, &wu->links);
            *r = wu;
            DEN_RENEUERL(wu);
        }
    }


    Den *__fastcall _find(const T &x) const {
        Den *noch = this->root;
        while(NULL != noch){
            if(noch->key < x){
                noch = noch->recht;
            }else if(x < noch->key){
                noch = noch->links;
            }else{
                return noch;
            }
        }

        return NULL;
    }

    Den *__fastcall _find_index(size_t idx) const {
        Den *noch = this->root;
        while(NULL != noch){
            size_t lsi = (NULL != noch->links) ? noch->links->cnt : 0;

            if(lsi > idx){
                noch = noch->links;
            }else if(idx > lsi){
                idx -= lsi + 1;
                noch = noch->recht;
            }else{
                return noch;
            }
        }

        return NULL;
    }

    void __fastcall _erase(const Den *den){
        if(NULL == this->root) return;
        Den *l, *r, *la, *ra;
        this->_split(this->root, den->key, &l, &r);
        this->_split_reverse(r, den->key, &la, &ra);
        this->root = this->_merge(l, ra);
        delete den;
    }
};






int n, q;

LL markelos[111111];
Der <PLL> pli;

LL voll;

LD kalkulieren(const int &idx){

    PLL pll = pli[idx];

    PLL suml, sumr;
    pli.sumiert_ein(pll, suml, sumr);

    LL wollte = voll + suml.first + pll.first;

    return (LD)wollte / (LD)(idx + 1);
}

bool funktion(const int &idx){
    return kalkulieren(idx) - EPS < pli[idx].first;
}

static void __fastcall FadeDemonSolution(){
    cin >> n >> q;

    RFI(n - 1) pli.insert(make_pair(markelos[i] = GIBi, i));

    RFI(q - 1){
        int wahl = GIBi;

        if(1 == wahl){
            int kein = GIBi - 1;
            int neun = GIBi;

            pli.erase(make_pair(markelos[kein], kein));
            markelos[kein] = neun;
            pli.insert(make_pair(markelos[kein], kein));

        }else{

            cin >> voll;

            cout << kalkulieren(B2R(funktion, 0, n - 1, false)) << endl;
            

        }
    }


}








#define MEMLIMIT_ALL 256
#define MEMLIMIT_STACK 32

#define ENABLE_ESP_REPLACE












#define STACK_SIZE (MEMLIMIT_STACK << 20)
#define ESP_SAVE(x) ((void __stdcall(*)(const void*))(void *)esp_save)(&x)
#define ESP_REPLACE(x) ((void __stdcall(*)(const void*))(void *)esp_replace)(x)

unsigned char *old_esp;

unsigned char esp_save[] = {0x5a, 0x58, 0x89, 0x20, 0xff, 0xe2};
unsigned char esp_replace[] = {0x5a, 0x58, 0x89, 0xc4, 0xff, 0xe2};

int main(int argc, char* argv[]){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef FILE_INPUT
    freopen(FILE_INPUT, "r", stdin);
    #endif

    #ifdef FILE_OUTPUT
    freopen(FILE_OUTPUT, "w", stdout);
    #endif

    cerr << fixed << setprecision(4);
    cout << fixed << setprecision(15);

    #ifdef ENABLE_ESP_REPLACE
    ESP_SAVE(old_esp);
    ESP_REPLACE((unsigned char*)malloc(STACK_SIZE)+STACK_SIZE-4);
    #endif

    FadeDemonSolution();

    #ifdef ENABLE_ESP_REPLACE
    ESP_REPLACE(old_esp);
    #endif

    cout.flush();
    return 0;
};