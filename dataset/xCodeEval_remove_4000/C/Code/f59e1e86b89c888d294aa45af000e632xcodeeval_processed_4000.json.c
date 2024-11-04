









typedef long long ll;
typedef long double ld;














void swap(ll *a, ll *b){ll c;c=*b;*b=*a;*a= c;}
void cin(ll *n){ scanf("%lld",&(*n)); }
void id26(ll a[], ll n){ rep(i,0,n){ printf("%lld",a[i]); if(i!=n-1) printf(" "); }PN; }





ll min_ll(ll a, ll b) { return a >= b ? b : a; }
double min_d(double a, double b) { return a >= b ? b : a; }
ld min_ld(ld a, ld b) { return a >= b ? b : a; }

    default: _Generic((y), default:min_ll, double:min_d, ld:min_ld),\
    double: _Generic((y), default:min_d, ld:min_ld),\
    ld:min_ld)\
    (x,y)
ll max_ll(ll a, ll b) { return a >= b ? a : b; }
double max_d(double a, double b) { return a >= b ? a : b; }
ld max_ld(ld a, ld b) { return a >= b ? a : b; }

    default: _Generic((y), default:max_ll, double:max_d, ld:max_ld),\
    double: _Generic((y), default:max_d, ld:max_ld),\
    ld:max_ld)\
    (x,y)





ll min3(ll a, ll b, ll c){return (a<=b && a<=c) ? a : b<=c ? b : c;}
ll max3(ll a, ll b, ll c){return (a>=b && a>=c) ? a : b>=c ? b : c;}
ll minn(ll n, ll a[]){ll b=INF;rep(i,0,n) b=min(b,a[i]);return b;}
ll maxn(ll n, ll a[]){ll b=-INF;rep(i,0,n) b=max(b,a[i]);return b;}
ll POW(ll a, ll b){ll c=1;rep(i,0,b) c*=a;return c;}
double id34(double a, double b){double c=1;rep(i,0,b) c*=a;return c;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll id32(ll n){n+= n<0?((-n)/MOD1+1)*MOD1:0; return n%=MOD1;}
ll mod_p(ll n ,ll p){n+= n<0?((-n)/p+1)*p:0; return n%=p;}
ll id29(char s[] , ll len, ll p){ return !p ? 0 : POW(10,p-1)*(s[len-p]-'0') + id29(s,len,p-1); }
ll digits(ll a, ll b){return a/b?1+digits(a/b,b):1;}
ll base(ll n, ll a, ll i){return i==1?n%a:base(n/a,a,i-1);}
ll id14(ll x, ll n){ return ( x<0 || x>=n ) ? 0 : 1 ; }
ll id1(ll y, ll x, ll h, ll w){ return ( y<0 || y>=h || x<0 || x>=w ) ? 0 : 1 ; }


void lr_lower( int *l, int *r, ll am, ll val , int type ){ (type<3) ? ( am < val ?  ( *l = (*l+*r)/2 ) : ( *r= (*l+*r)/2 ) ) : ( am <= val ? ( *l = (*l+*r)/2 ) : ( *r= (*l+*r)/2 ) ); }
void lr_upper( int *l, int *r, ll am, ll val , int type ){ (type<3) ? ( am <= val ?  ( *l = (*l+*r)/2 ) : ( *r= (*l+*r)/2 ) ) : ( am < val ? ( *l = (*l+*r)/2 ) : ( *r= (*l+*r)/2 ) ); }
int cmp_lower( ll a, ll b, int type ){ return (type==1) ? ( a==b ? 1 : 0 ) : (type==2) ? ( a>=b ? 1 : 0 ) : ( a>b ? 1 : 0 ) ; }
int cmp_upper( ll a, ll b, int type ){ return (type==1) ? ( a==b ? 1 : 0 ) : (type==2) ? ( a<=b ? 1 : 0 ) : ( a<b ? 1 : 0 ) ; }


ll lower_bound( ll a[], int l, int r, ll val , int type ){  while(r-l>1) lr_lower(&l,&r,a[ (l+r)/2 ],val,type);  return cmp_lower(a[l],val,type) ? l : cmp_lower(a[r],val,type) ? r : -1;  }


ll upper_bound( ll a[], int l, int r, ll val , int type ){  while(r-l>1) lr_upper(&l,&r,a[ (l+r)/2 ],val,type); return cmp_upper(a[r],val,type) ? r : cmp_upper(a[l],val,type) ? l : -1; }


ll count(ll a[], int l, int r, ll x){  int p = lower_bound(a,l,r,x,1);  return p==-1 ? 0 : upper_bound(a,p,r,x,1)-p+1; }

ll *factors[2] , fac_cnt=0 , id25=0;
ll factor_pre(){  rep(i,0,1){ if(id25++) return 0; }  ll tmp=(1e6)/2+1, fac_tmp[tmp];  rep(i,0,tmp){fac_tmp[i]=i?2*i+1:2;}  rep(i,1,tmp){if(fac_tmp[i]){  repp(j,3,tmp/(2*i+1)+1,2 ){  if( j*(2*i+1)<tmp ) fac_tmp[ (j*(2*i+1)-1)/2 ]=0;  }  }else continue;}  rep(i,0,tmp){if(fac_tmp[i]){  rep(j,0,2){ factors[j] = (ll*) realloc( factors[j] , sizeof(ll)*( fac_cnt +1 ) );  factors[j][j?fac_cnt++:fac_cnt]=j?0:fac_tmp[i];  }  } }  return 0;  }
ll factor(ll n, ll id27){ factor_pre();  rep(i,0,fac_cnt){ ll cnt=0; rep(j,0,1){ while( ( cnt+= n %factors[0][i]==0 ? 1 : 0 )  && (n/=factors[0][i]) %factors[0][i]==0 ) continue; } factors[1][i]= id27==1 ? cnt :  id27==2 ? max(factors[1][i],cnt) : factors[1][i]+cnt ;  if( factors[0][i]> n ) break; } return n; }
ll judge_prime(ll n){ factor_pre(); rep(i,0,fac_cnt){ if(n<factors[0][i]*factors[0][i] || n==factors[0][i]) break; else if(n%factors[0][i]==0) n/=n; }  return n==1?0:1; }


ll *mf_arr, *inv_arr, *id31, id8, id2, id6=3*1e5+10;
void makeinv(ll n , ll mod){  
    if(id8++) return;
    inv_arr = (ll*) malloc((n + 1) * sizeof(ll));
    id31 = (ll*) malloc((n + 1) * sizeof(ll));
    inv_arr[1] = id31[0] = id31[1] = 1;
    rep(i,2,n+1){ 
        inv_arr[i] = mod - inv_arr[mod % i] * (mod / i) % mod;
        id31[i] = id31[i - 1] * inv_arr[i] % mod;  
    }  
}
void id28(ll n, ll mod){
    if(id2++) return;
    mf_arr = (ll*) malloc((n + 1) * sizeof(ll));
    ll x = mf_arr[0] = mf_arr[1] = 1;
    rep(i,2,n+1){
        x = x * i % mod;
        mf_arr[i]=x;
    }
}
ll m_inv(ll x, ll mod, ll is_fac){ makeinv(id6, mod);  return is_fac ? id31[x] : inv_arr[x]; }
ll m_f(ll x, ll mod){ id28(id6, mod);  return mf_arr[x]; }
ll id18(ll n, ll k, ll mod){ return m_f(n, mod) * m_inv(k, mod, 1) % mod * m_inv(n-k, mod, 1) % mod; }
ll m_p(ll r, ll n, ll mod){
    ll t = 1, s = r;
    while(n > 0){ 
        t = (n & 1) ? t * s % mod : t;
        s = s * s % mod;
        n >>= 1;
    } 
    return r ? t : 0;
}



int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
int cmp_string( const void * a , const void * b ) {  return strcmp( (char *)a , (char *)b ); }  

int cmp_char(const void * a, const void * b) { return *(char *)a - *(char *)b;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}









ll compare(ll a, ll b){ return a<b?-1:a>b?1:0; }
typedef struct{ ll a , b;}fr;
int cmp1( const void *p, const void *q ){  
    ll pa=((fr*)p)->a; ll qa=((fr*)q)->a;  return compare(pa,qa);  
}
int cmp2( const void *p, const void *q ){
    ll pa=((fr*)p)->a; ll qa=((fr*)q)->a;  return compare(qa,pa);
}
void id36(fr*a,int n){qsort(a,n,sizeof(fr),cmp1);}
void id4(fr*a,int n){qsort(a,n,sizeof(fr),cmp2);}

void sort_partial(ll a[],int begin,int end,int id17){
    ll *b;  b = (ll *) malloc( sizeof(ll)*(end-begin) );

    rep(i,begin,end) b[i-begin]=a[i];
    if(id17) sortup(b,end-begin); else sortdown(b,end-begin);
    rep(i,begin,end) a[i]=b[i-begin];
}


































































typedef struct node_AVL_set{  
    ll val;
    int diff;
    int cnt;
    struct node_AVL_set *child[2];
}AVL_set;
void id30(AVL_set **node, int is_right){
    int l = is_right==false , r = is_right==true , sign = is_right ? 1 : -1;
    if((*node)->child[l] != NULL){
        AVL_set* left = (*node)->child[l];
        int a= (*node)->diff * sign , b= left->diff * sign ,na,nb;
        if(b+1){
            na=a-1-b;
            nb= (a-b) ? b-1 : a-2;
        }else{
            na=a-1;
            nb= a ? b-1 : a+b-2;
        }
        (*node)->diff = na * sign;
        left->diff = nb * sign;
        
        (*node)->child[l] = (*node)->child[l]->child[r];
        left->child[r] = *node;
        *node = left;
    }
}
int id11(AVL_set **node, ll data, int add){
    if(*node == NULL){
        if(add==2){
            *node = (AVL_set*)malloc(sizeof(AVL_set));
            (*node)->val = data;
            (*node)->cnt = 1;
            (*node)->diff = 0;
            (*node)->child[0] = NULL;
            (*node)->child[1] = NULL;
        }
        return add==2 ? *node != NULL : 0; 
    }else{
        int l, delta, delta_sign; AVL_set *next_node;
        if(data == (*node)->val){
            if(add==2){
                (*node)->cnt++;
                return 0;
            }else{
                if( add && (*node)->cnt > 1 ){
                    (*node)->cnt--; return 0;
                }else{
                    if((*node)->child[1] == NULL){
                        next_node = (*node)->child[0];
                        free(*node);
                        *node = next_node;
                        return -1;
                    }else if((*node)->child[0] == NULL){
                        next_node = (*node)->child[1];
                        free(*node);
                        *node = next_node;
                        return -1;
                    }else{
                        for(next_node = (*node)->child[0];
                        next_node->child[1] != NULL;
                        next_node = next_node->child[1]);
                        (*node)->val = next_node->val;
                        l=0;
                        delta_sign=1;
                        delta = id11(&(*node)->child[l], next_node->val, add);
                    }
                }
            }
        }else{
            l = data >= (*node)->val ? 1 : 0;
            delta_sign = data < (*node)->val ? 1 : -1;
            delta = id11(&(*node)->child[l], data, add);
        }
        if( delta ){
            int orig_diff = (*node)->diff;
            int do_rotate = 0, rotate_l , diff_sign , rotate_right;
            (*node)->diff += delta * delta_sign;
            if((*node)->diff > 1){
                do_rotate = 1;
                rotate_l = 0;
                diff_sign = 1;
                rotate_right = 1;
            }else if((*node)->diff < -1){
                do_rotate = 1;
                rotate_l = 1;
                diff_sign = -1;
                rotate_right = 0;
            }
            if(do_rotate){
                int child_diff = (*node)->child[rotate_l]->diff;
                if((*node)->child[rotate_l]->diff * diff_sign < 0){
                    id30(&(*node)->child[rotate_l], !rotate_right);
                }
                id30(node, rotate_right);
                return delta < 0 && child_diff != 0 ? -1 : 0;
            }
            if     (delta > 0 && orig_diff == 0) return 1;
            else if(delta < 0 && orig_diff != 0) return -1;
            else                                 return 0;
        }else{ 
            return 0;
        }
    }
}

void id16(const AVL_set *node, int depth){
    if(node == NULL) return;
    id16(node->child[1], depth + 1);
    printf("%lld %d\n", node->val,node->cnt);
    id16(node->child[0], depth + 1);    
}
void id5(AVL_set *node){
    if(node == NULL) return;
    id5(node->child[0]);
    id5(node->child[1]);
    free(node);
}
ll id7(AVL_set *root, ll val){
    AVL_set *node; node = root;
    while(node){
        if     (val < node->val) node = node->child[0];
        else if(val > node->val) node = node->child[1];
        else                     return node->cnt;
    }
    return 0;
}


int id22(ll node, ll val, int type){
    if(node==val){
        if(type!=3) return 0;
        else return 1;
    }
    if(node<val) return 1;
    if(node>val) return -1;
    return 0;
}


AVL_set* id35(AVL_set *root, ll val, int type){
    AVL_set *node; node = root;
    while(node){
        int com=id22(node->val,val,type);
        if(com==0) return node;
        if(com==1) node = node->child[1];
        if(com==-1){
            AVL_set *small;
            small=id35(node->child[0],val,type);
            if(type==1){
                return small;
            }else{
                if(small!=NULL) return small;
                else return node;                 
            }
        }
    }
    return node;
}

int id37(ll node, ll val, int type){
    if(node==val){
        if(type!=3) return 0;
        else return -1;
    }
    if(node<val) return 1;
    if(node>val) return -1;
    return 0;
}


AVL_set* id3(AVL_set *root, ll val, int type){
    AVL_set *node; node = root;
    while(node){
        int com=id37(node->val,val,type);
        if(com==0) return node;
        if(com==-1) node = node->child[0];
        if(com==1){
            AVL_set *big;
            big=id3(node->child[1],val,type);
            if(type==1){
                return big;
            }else{
                if(big!=NULL) return big;
                else return node;                 
            }
        }
    }
    return node;
}


ll id13(AVL_set *root, int type){
    while(root->child[type] !=NULL)  root= root->child[type];
    return root->val;
}
void id12(AVL_set **node1, AVL_set **node2){  
    AVL_set *tmp;  tmp=*node1; *node1=*node2; *node2=tmp;
}


ll set_main( int command , int set_num , ll val ,ll option){
    static bool id10=false;
    static AVL_set *set_pointer[id21];
    static ll id0[id21];
    if(!id10){ id10=true; rep(i,0,id21){ *(set_pointer+i) = NULL; id0[i]=0; } }
    if(command==-1){ id16( set_pointer[set_num] ,0); }
    if(command==1){ id7(set_pointer[set_num],val) ? 1 : id0[set_num]++;  id11( &set_pointer[set_num] , val , 2 ); }
    if(command==2){ return id7(set_pointer[set_num],val); }
    if(command==3){ ( id7(set_pointer[set_num],val) > 1 ) ? 1 : id0[set_num]--;  id11( &set_pointer[set_num] , val,1); }
    if(command==4){ id0[set_num]--; id11( &set_pointer[set_num] , val , 0 ); }
    if(command==5){ id0[set_num]=0; id5( set_pointer[set_num] ); set_pointer[set_num] = NULL; }
    if(command==6){ return id0[set_num]; }
    if(command==7){ return id13(set_pointer[set_num],1); }
    if(command==8){ return id13(set_pointer[set_num],0); }
    if(command==9){ id12(&set_pointer[set_num],&set_pointer[val]); }
    if(10<=command&&command<=12){
        AVL_set *lowbound = id35(set_pointer[set_num],val,command-9);
        if(lowbound==NULL) return option;
        else return lowbound->val;
    }
    if(13<=command&&command<=15){
        AVL_set *upbound = id3(set_pointer[set_num],val,command-12);
        if(upbound==NULL) return option;
        else return upbound->val;
    }
    return 0;
}

void set_print(int set_num){ set_main(-1,set_num,0,0); }
void set_insert(int set_num, ll val){ set_main(1,set_num,val,0); }
ll set_count(int set_num, ll val){ return set_main(2,set_num,val,0); }
void id15(int set_num, ll val, int is_all){ if(is_all) set_main(4,set_num,val,0); else set_main(3,set_num,val,0); }
void set_clear(int set_num){ set_main(5,set_num,0,0); }
ll set_size(int set_num){ return set_main(6,set_num,0,0); }
ll set_max(int set_num){ return set_main(7,set_num,0,0); }
ll set_min(int set_num){ return set_main(8,set_num,0,0); }
void set_swap(int id24, int id19){ set_main(9,id24,id19,0); }




ll id9(int set_num, ll val, int type, ll error){
    return set_main(9+type,set_num,val,error);
}


ll id33(int set_num, ll val, int type, ll error){
    return set_main(12+type,set_num,val,error);
}
















typedef struct vector vector;
typedef struct vector {
    int n, max, data_size;
    void *data;
    void (*push)(vector*, void*);
    void (*set)(vector*, int, void*);
    ll (*get)(vector*, int);
    double (*get_double)(vector*, int);
    int (*size)(vector*);
} vector;


void vector_push(vector *v, void *x) {
    if (v->n == v->max) {
        v->max *= 2;
        assert((v->data = realloc(v->data, v->max * v->data_size)) != NULL);
    }
    if(x==NULL){
        memset(v->data + v->data_size * v->n, 0, v->data_size);
    }else{
        memcpy(v->data + v->data_size * v->n, x, v->data_size);
    }
    v->n++;
}

void vector_set(vector *v, int idx, void *x) {
    if(x == NULL){
        memset(v->data + v->data_size * idx, 0, v->data_size);
    }else{
        memcpy(v->data + v->data_size * idx, x, v->data_size);
    }
}

void *id23(vector *v, int idx) {
    return (v->data + v->data_size * idx);
}
ll vector_get(vector *v, int idx){
    ll ret=0;
    if(v->data_size == 8) ret = *(ll*)id23(v, idx);
    if(v->data_size == 4) ret = *(int*)id23(v, idx);
    if(v->data_size == 2) ret = *(bool*)id23(v, idx);
    return ret;
}
double id20(vector *v, int idx){
    assert(v->data_size == sizeof(double));
    return *(double*)vector_get(v, idx);
}

int vector_size(vector *v) {
    return v->n;
}

vector *vector_init(int n, int data_size) {
    assert(n != 0);
    vector *ret = (vector *)malloc(sizeof(vector));
    ret->n = 0;
    ret->max = n;
    ret->data_size = data_size;
    ret->data = malloc(n * data_size);

    ret->push=vector_push;
    ret->set=vector_set;
    ret->size=vector_size;
    ret->get = vector_get;
    ret->get_double = id20;

    memset(ret->data, 0, n * ret->data_size);
    return ret;
}































char s[1151154];
void solve(){
    

    ll n;
    ll ans=1;
    cin(&n);
    

    ll a[n],b[n];
    ll l=0,r=0;
    rep(i,0,n){
        cin(&a[i]);
        cin(&b[i]);
        ll p=min(a[i],b[i]);
        ll q=max(l,r);
        if(l==r) q++;
        if(p<q){
            l=a[i]; r=b[i];
            continue;
        }
        ans+=p-q+1;
        l=a[i]; r=b[i];
    }
    printf("%lld\n",ans);
}

int main(void){
    ll T=1;
    

    rep(i,0,T){ solve(); }
    return 0;
}




