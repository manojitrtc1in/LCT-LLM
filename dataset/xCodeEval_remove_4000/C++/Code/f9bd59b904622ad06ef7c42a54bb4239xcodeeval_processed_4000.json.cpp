











                                   



 

  

   

   

  

 





 

  

   

   

  

 





                                  

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

                                   




















 

 































template <typename T> const T&CIN(){static T x;cin>>x;return x;}














template <typename TY, typename TX> TX id2(TY(*f)(const TX&),TX l,TX r,const TY&q){while(l!=r){TX mit=l+r>>1;  if(f(mit)<q)l=mit+1;else r=mit;}return l;}
template <typename TY, typename TX> TX id4(TY(*f)(const TX&),TX l,TX r,const TY&q){while(l!=r){TX mit=l+r+1>>1;if(f(mit)>q)r=mit-1;else l=mit;}return l;}
template <typename TY, typename TX> TX id5(TY(*f)(const TX&),TX l,TX r,const TY&q){while(r-l<EPS){TX mit=(l+r)/2.0l;if(f(mit)<q)l=mit;else r=mit;}return (l+r)/2.0l;}

template <typename TY, typename TX> TX id6(TY(*f)(const TX&),TX l,TX r,const TY&d=6){TY t;while(r-l>=d){t=(r-l)/3;TY xl=l+t,xr=r-t;if(f(xl)>f(xr)) r=xr;else l=xl;}TY o=f(l);if(r-l>=1)FOR(i,l,r)if((t=f(i))>o){o=t;l=i;};return l;}
template <typename TY, typename TX> TX id7(TY(*f)(const TX&),TX l,TX r,const TY&d=6){TY t;while(r-l>=d){t=(r-l)/3;TY xl=l+t,xr=r-t;if(f(xl)<f(xr)) r=xr;else l=xl;}TY o=f(l);if(r-l>=1)FOR(i,l,r)if((t=f(i))<o){o=t;l=i;};return l;}

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

LD id0(const int &idx){

    PLL pll = pli[idx];

    PLL suml, sumr;
    pli.sumiert_ein(pll, suml, sumr);

    LL id8 = voll + suml.first + pll.first;

    return (LD)id8 / (LD)(idx + 1);
}

bool funktion(const int &idx){
    return id0(idx) - EPS < pli[idx].first;
}

static void __fastcall id3(){
    cin >> n >> q;

    RFI(n - 1) pli.insert(make_pair(markelos[i] = id1, i));

    RFI(q - 1){
        int wahl = id1;

        if(1 == wahl){
            int kein = id1 - 1;
            int neun = id1;

            pli.erase(make_pair(markelos[kein], kein));
            markelos[kein] = neun;
            pli.insert(make_pair(markelos[kein], kein));

        }else{

            cin >> voll;

            cout << id0(id4(funktion, 0, n - 1, false)) << endl;
            

        }
    }


}




























unsigned char *old_esp;

unsigned char esp_save[] = {0x5a, 0x58, 0x89, 0x20, 0xff, 0xe2};
unsigned char esp_replace[] = {0x5a, 0x58, 0x89, 0xc4, 0xff, 0xe2};

int main(int argc, char* argv[]){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    freopen(FILE_INPUT, "r", stdin);
    

    
    freopen(FILE_OUTPUT, "w", stdout);
    

    cerr << fixed << setprecision(4);
    cout << fixed << setprecision(15);

    
    ESP_SAVE(old_esp);
    ESP_REPLACE((unsigned char*)malloc(STACK_SIZE)+STACK_SIZE-4);
    

    id3();

    
    ESP_REPLACE(old_esp);
    

    cout.flush();
    return 0;
};