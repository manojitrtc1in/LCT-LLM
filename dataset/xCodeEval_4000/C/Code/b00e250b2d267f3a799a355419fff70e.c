#pragma region kyopuro_templates
#pragma GCC optimize("Ofast")
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
#include<time.h>
#include<ctype.h>
typedef long long ll;
typedef long double ld;
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define rrep(i,l,r)for(ll i=(l);i>=(r);i--)
#define INF (1LL<<62)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N (1 << 20)
#define YES printf("Yes\n")
#define NO printf("No\n")
#define PN printf("\n")
#define charsize 100005 

#define PI 3.141592653589793238

void swap(ll *a, ll *b){ll c;c=*b;*b=*a;*a= c;}
void cin(ll *n){ scanf("%lld",&(*n)); }
void PriAll1(ll a[], ll n){ rep(i,0,n){ printf("%lld",a[i]); if(i!=n-1) printf(" "); }PN; }
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
#define max3(a,b,c) (max(a,b)>c?max(a,b):c)
#define min3(a,b,c) (min(a,b)>c?c:max(a,b))




ll minn(ll n, ll a[]){ll b=INF;rep(i,0,n) b=min(b,a[i]);return b;}
ll maxn(ll n, ll a[]){ll b=-INF;rep(i,0,n) b=max(b,a[i]);return b;}
ll POW(ll a, ll b){ll c=1;rep(i,0,b) c*=a;return c;}
double POW_d(double a, int b){double c=1;rep(i,0,b) c*=a;return c;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll mod_MOD1(ll n){n+= n<0?((-n)/MOD1+1)*MOD1:0; return n%=MOD1;}
ll mod_p(ll n ,ll p){n+= n<0?((-n)/p+1)*p:0; return n%=p;}
ll change_into_num(char s[] , ll len, ll p){ return !p ? 0 : POW(10,p-1)*(s[len-p]-'0') + change_into_num(s,len,p-1); }
ll digits(ll a, ll b){return a/b?1+digits(a/b,b):1;}
ll base(ll n, ll a, ll i){return i==1?n%a:base(n/a,a,i-1);}
ll is_inArr1(ll x, ll n){ return ( x<0 || x>=n ) ? 0 : 1 ; }
ll is_inArr2(ll y, ll x, ll h, ll w){ return ( y<0 || y>=h || x<0 || x>=w ) ? 0 : 1 ; }


void lr_lower( int *l, int *r, ll am, ll val , int type ){ (type<3) ? ( am < val ?  ( *l = (*l+*r)/2 ) : ( *r= (*l+*r)/2 ) ) : ( am <= val ? ( *l = (*l+*r)/2 ) : ( *r= (*l+*r)/2 ) ); }
void lr_upper( int *l, int *r, ll am, ll val , int type ){ (type<3) ? ( am <= val ?  ( *l = (*l+*r)/2 ) : ( *r= (*l+*r)/2 ) ) : ( am < val ? ( *l = (*l+*r)/2 ) : ( *r= (*l+*r)/2 ) ); }
int cmp_lower( ll a, ll b, int type ){ return (type==1) ? ( a==b ? 1 : 0 ) : (type==2) ? ( a>=b ? 1 : 0 ) : ( a>b ? 1 : 0 ) ; }
int cmp_upper( ll a, ll b, int type ){ return (type==1) ? ( a==b ? 1 : 0 ) : (type==2) ? ( a<=b ? 1 : 0 ) : ( a<b ? 1 : 0 ) ; }


ll lower_bound( ll a[], int l, int r, ll val , int type ){  while(r-l>1) lr_lower(&l,&r,a[ (l+r)/2 ],val,type);  return cmp_lower(a[l],val,type) ? l : cmp_lower(a[r],val,type) ? r : -1;  }


ll upper_bound( ll a[], int l, int r, ll val , int type ){  while(r-l>1) lr_upper(&l,&r,a[ (l+r)/2 ],val,type); return cmp_upper(a[r],val,type) ? r : cmp_upper(a[l],val,type) ? l : -1; }


ll count(ll a[], int l, int r, ll x){  int p = lower_bound(a,l,r,x,1);  return p==-1 ? 0 : upper_bound(a,p,r,x,1)-p+1; }

ll *factors[2] , fac_cnt=0 , is_factor_prepared=0;
ll factor_pre(){  rep(i,0,1){ if(is_factor_prepared++) return 0; }  ll tmp=(1e6)/2+1, fac_tmp[tmp];  rep(i,0,tmp){fac_tmp[i]=i?2*i+1:2;}  rep(i,1,tmp){if(fac_tmp[i]){  repp(j,3,tmp/(2*i+1)+1,2 ){  if( j*(2*i+1)<tmp ) fac_tmp[ (j*(2*i+1)-1)/2 ]=0;  }  }else continue;}  rep(i,0,tmp){if(fac_tmp[i]){  rep(j,0,2){ factors[j] = (ll*) realloc( factors[j] , sizeof(ll)*( fac_cnt +1 ) );  factors[j][j?fac_cnt++:fac_cnt]=j?0:fac_tmp[i];  }  } }  return 0;  }
ll factor(ll n, ll new_common_plus){ factor_pre();  rep(i,0,fac_cnt){ ll cnt=0; rep(j,0,1){ while( ( cnt+= n %factors[0][i]==0 ? 1 : 0 )  && (n/=factors[0][i]) %factors[0][i]==0 ) continue; } factors[1][i]= new_common_plus==1 ? cnt :  new_common_plus==2 ? max(factors[1][i],cnt) : factors[1][i]+cnt ;  if( factors[0][i]> n ) break; } return n; }
ll judge_prime(ll n){ factor_pre(); rep(i,0,fac_cnt){ if(n<factors[0][i]*factors[0][i] || n==factors[0][i]) break; else if(n%factors[0][i]==0) n/=n; }  return n==1?0:1; }

#pragma region mod
ll *mf_arr, *inv_arr, *finv_arr, is_minv_made, is_mf_made, num_of_inv=3*1e5+10;
void makeinv(ll n , ll mod){  
    if(is_minv_made++) return;
    inv_arr = (ll*) malloc((n + 1) * sizeof(ll));
    finv_arr = (ll*) malloc((n + 1) * sizeof(ll));
    inv_arr[1] = finv_arr[0] = finv_arr[1] = 1;
    rep(i,2,n+1){ 
        inv_arr[i] = mod - inv_arr[mod % i] * (mod / i) % mod;
        finv_arr[i] = finv_arr[i - 1] * inv_arr[i] % mod;  
    }  
}
void make_mf(ll n, ll mod){
    if(is_mf_made++) return;
    mf_arr = (ll*) malloc((n + 1) * sizeof(ll));
    ll x = mf_arr[0] = mf_arr[1] = 1;
    rep(i,2,n+1){
        x = x * i % mod;
        mf_arr[i]=x;
    }
}
ll m_inv(ll x, ll mod, ll is_fac){ makeinv(num_of_inv, mod);  return is_fac ? finv_arr[x] : inv_arr[x]; }
ll m_f(ll x, ll mod){ make_mf(num_of_inv, mod);  return mf_arr[x]; }
ll mod_nck(ll n, ll k, ll mod){ return m_f(n, mod) * m_inv(k, mod, 1) % mod * m_inv(n-k, mod, 1) % mod; }
ll m_p(ll r, ll n, ll mod){
    ll t = 1, s = r;
    while(n > 0){ 
        t = (n & 1) ? t * s % mod : t;
        s = s * s % mod;
        n >>= 1;
    } 
    return r ? t : 0;
}
#pragma endregion mod


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
void strsortup(fr*a,int n){qsort(a,n,sizeof(fr),cmp1);}
void strsortdown(fr*a,int n){qsort(a,n,sizeof(fr),cmp2);}

void sort_partial(ll a[],int begin,int end,int is_increase){
    ll *b;  b = (ll *) malloc( sizeof(ll)*(end-begin) );

    rep(i,begin,end) b[i-begin]=a[i];
    if(is_increase) sortup(b,end-begin); else sortdown(b,end-begin);
    rep(i,begin,end) a[i]=b[i-begin];
}






























































#pragma region AVL



typedef struct node_AVL_set{  
    ll val;
    int diff;
    int cnt;
    struct node_AVL_set *child[2];
}AVL_set;
void AVL_set_inside_rotate(AVL_set **node, int is_right){
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
int AVL_set_inside_update(AVL_set **node, ll data, int add){
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
                        delta = AVL_set_inside_update(&(*node)->child[l], next_node->val, add);
                    }
                }
            }
        }else{
            l = data >= (*node)->val ? 1 : 0;
            delta_sign = data < (*node)->val ? 1 : -1;
            delta = AVL_set_inside_update(&(*node)->child[l], data, add);
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
                    AVL_set_inside_rotate(&(*node)->child[rotate_l], !rotate_right);
                }
                AVL_set_inside_rotate(node, rotate_right);
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

void AVL_set_inside_print(const AVL_set *node, int depth){
    if(node == NULL) return;
    AVL_set_inside_print(node->child[1], depth + 1);
    printf("%lld %d\n", node->val,node->cnt);
    AVL_set_inside_print(node->child[0], depth + 1);    
}
void AVL_set_inside_free(AVL_set *node){
    if(node == NULL) return;
    AVL_set_inside_free(node->child[0]);
    AVL_set_inside_free(node->child[1]);
    free(node);
}
ll AVL_set_inside_count(AVL_set *root, ll val){
    AVL_set *node; node = root;
    while(node){
        if     (val < node->val) node = node->child[0];
        else if(val > node->val) node = node->child[1];
        else                     return node->cnt;
    }
    return 0;
}


int AVL_set_lowcomp(ll node, ll val, int type){
    if(node==val){
        if(type!=3) return 0;
        else return 1;
    }
    if(node<val) return 1;
    if(node>val) return -1;
    return 0;
}


AVL_set* AVL_set_inside_lowerbound(AVL_set *root, ll val, int type){
    AVL_set *node; node = root;
    while(node){
        int com=AVL_set_lowcomp(node->val,val,type);
        if(com==0) return node;
        if(com==1) node = node->child[1];
        if(com==-1){
            AVL_set *small;
            small=AVL_set_inside_lowerbound(node->child[0],val,type);
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

int AVL_set_upcomp(ll node, ll val, int type){
    if(node==val){
        if(type!=3) return 0;
        else return -1;
    }
    if(node<val) return 1;
    if(node>val) return -1;
    return 0;
}


AVL_set* AVL_set_inside_upperbound(AVL_set *root, ll val, int type){
    AVL_set *node; node = root;
    while(node){
        int com=AVL_set_upcomp(node->val,val,type);
        if(com==0) return node;
        if(com==-1) node = node->child[0];
        if(com==1){
            AVL_set *big;
            big=AVL_set_inside_upperbound(node->child[1],val,type);
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


ll AVL_set_inside_minmax(AVL_set *root, int type){
    while(root->child[type] !=NULL)  root= root->child[type];
    return root->val;
}
void AVL_set_inside_swap(AVL_set **node1, AVL_set **node2){  
    AVL_set *tmp;  tmp=*node1; *node1=*node2; *node2=tmp;
}

#define set_MAX_SIZE 514511
ll set_main( int command , int set_num , ll val ,ll option){
    static bool set_is_init=false;
    static AVL_set *set_pointer[set_MAX_SIZE];
    static ll set_siz[set_MAX_SIZE];
    if(!set_is_init){ set_is_init=true; rep(i,0,set_MAX_SIZE){ *(set_pointer+i) = NULL; set_siz[i]=0; } }
    if(command==-1){ AVL_set_inside_print( set_pointer[set_num] ,0); }
    if(command==1){ AVL_set_inside_count(set_pointer[set_num],val) ? 1 : set_siz[set_num]++;  AVL_set_inside_update( &set_pointer[set_num] , val , 2 ); }
    if(command==2){ return AVL_set_inside_count(set_pointer[set_num],val); }
    if(command==3){ ( AVL_set_inside_count(set_pointer[set_num],val) > 1 ) ? 1 : set_siz[set_num]--;  AVL_set_inside_update( &set_pointer[set_num] , val,1); }
    if(command==4){ set_siz[set_num]--; AVL_set_inside_update( &set_pointer[set_num] , val , 0 ); }
    if(command==5){ set_siz[set_num]=0; AVL_set_inside_free( set_pointer[set_num] ); set_pointer[set_num] = NULL; }
    if(command==6){ return set_siz[set_num]; }
    if(command==7){ return AVL_set_inside_minmax(set_pointer[set_num],1); }
    if(command==8){ return AVL_set_inside_minmax(set_pointer[set_num],0); }
    if(command==9){ AVL_set_inside_swap(&set_pointer[set_num],&set_pointer[val]); }
    if(10<=command&&command<=12){
        AVL_set *lowbound = AVL_set_inside_lowerbound(set_pointer[set_num],val,command-9);
        if(lowbound==NULL) return option;
        else return lowbound->val;
    }
    if(13<=command&&command<=15){
        AVL_set *upbound = AVL_set_inside_upperbound(set_pointer[set_num],val,command-12);
        if(upbound==NULL) return option;
        else return upbound->val;
    }
    return 0;
}

void set_print(int set_num){ set_main(-1,set_num,0,0); }
void set_insert(int set_num, ll val){ set_main(1,set_num,val,0); }
ll set_count(int set_num, ll val){ return set_main(2,set_num,val,0); }
void set_erase(int set_num, ll val, int is_all){ if(is_all) set_main(4,set_num,val,0); else set_main(3,set_num,val,0); }
void set_clear(int set_num){ set_main(5,set_num,0,0); }
ll set_size(int set_num){ return set_main(6,set_num,0,0); }
ll set_max(int set_num){ return set_main(7,set_num,0,0); }
ll set_min(int set_num){ return set_main(8,set_num,0,0); }
void set_swap(int set_num1, int set_num2){ set_main(9,set_num1,set_num2,0); }




ll set_lowerbound(int set_num, ll val, int type, ll error){
    return set_main(9+type,set_num,val,error);
}


ll set_upperbound(int set_num, ll val, int type, ll error){
    return set_main(12+type,set_num,val,error);
}








#pragma endregion AVL


#pragma endregion kyopuro_templates


#pragma region seg_tree
ll seg_e_max(){ return -INF; }
ll seg_e_min(){ return INF; }
ll seg_e_sum(){ return 0; }
ll seg_e_gcd(){ return 0; }

ll seg_op_max(ll a, ll b){ return max(a,b); }
ll seg_op_min(ll a, ll b){ return min(a,b); }
ll seg_op_sum(ll a, ll b){ return a+b; }
ll seg_op_gcd(ll a, ll b){ return gcd(a,b); }


typedef struct seg_tree seg;
typedef struct seg_tree {
    int _n;
    ll *node;
    ll (*op)(ll, ll);
    ll (*e)(void);
    ll (*get)(seg*, int);
    ll (*prod)(seg*, int, int);
    void (*update)(seg*, int, ll);
} seg;


ll seg_get(seg *S, int x) {
    return S->node[S->_n / 2 + x];
}

ll seg_prod_inner(seg *S, int l, int r, int x, int from, int to) {
    if (l <= from && to <= r ) return S->node[x];
    if (r < from || to < l ) return S->e();
    return  S->op(
                seg_prod_inner(S, l, r, 2 * x + 1, from, (from + to) / 2),
                seg_prod_inner(S, l, r, 2 * x + 2, (from + to) / 2 + 1, to)
            );
}
ll seg_prod(seg *S, int l, int r) {
    return seg_prod_inner(S, l, r, 0, 0, S->_n / 2);
}

void seg_update(seg *S, int x, ll val) {
    ll c = S->_n / 2 + x;
    S->node[c] = val;
    while (c > 0) {
        c--; c /= 2;
        S->node[c] = S->op(S->node[2 * (c + 1)], S->node[2 * (c + 1) - 1]);
    }
}

seg *seg_init(int n, ll a[], ll (*op)(ll,ll), ll(*e)()) {
    seg *ret = (seg*)malloc(sizeof(seg));
    int x = 1;
    ret->_n = 0;
    while (x < n) {
        ret->_n += x;
        x *= 2;
    } 
    ret->_n += x;
    ret->node = (ll *)malloc(ret->_n * sizeof(ll));
    ret->op = op;
    ret->e = e;
    ret->get = seg_get;
    ret->prod = seg_prod;
    ret->update = seg_update;
    if(a==NULL){
        rep(i,0,x){
            ret->node[x-1+i]=ret->e();
        }
    }else{
        rep (i,0,x) {
            if (i < n) ret->node[x- 1 + i] = a[i];
            else ret->node[x - 1 + i] = ret->e();
        }
    }
    while (x /= 2) {
        rep (i,0,x) {
            int p = 2 * (x + i);
            ret->node[x + i - 1] = ret->op(ret->node[p], ret->node[p - 1]);
        }
    }
    return ret;
}

#pragma endregion seg_tree












void solve(){
    

    ll a,b;
    ll ans=0;
    cin(&a);
    cin(&b);
    

    

    

    

    

    printf("%lld\n",a^b);
}

int main(void){
    ll T=1;
    cin(&T);
    rep(i,0,T){ solve(); }
    return 0;
}





