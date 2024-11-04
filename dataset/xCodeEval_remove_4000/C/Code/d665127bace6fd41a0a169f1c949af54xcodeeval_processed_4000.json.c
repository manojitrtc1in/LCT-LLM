









typedef long long ll;
typedef long double ld;














void swap(ll *a, ll *b){ll c;c=*b;*b=*a;*a= c;}
void cin(ll *n){ scanf("%lld",&(*n)); }
ll max2(ll a,ll b){return a>=b?a:b;}
ll min2(ll a,ll b){return a>=b?b:a;}
ll min3(ll a, ll b, ll c){return (a<=b && a<=c) ? a : b<=c ? b : c;}
ll max3(ll a, ll b, ll c){return (a>=b && a>=c) ? a : b>=c ? b : c;}
ll minn(ll n, ll a[]){ll b=INF;rep(i,0,n) b=min2(b,a[i]);return b;}
ll maxn(ll n, ll a[]){ll b=-INF;rep(i,0,n) b=max2(b,a[i]);return b;}
ll POW(ll a, ll b){ll c=1;rep(i,0,b) c*=a;return c;}
double id31(double a, double b){double c=1;rep(i,0,b) c*=a;return c;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll id30(ll n){n+= n<0?((-n)/MOD1+1)*MOD1:0; return n%=MOD1;}
ll mod_p(ll n ,ll p){n+= n<0?((-n)/p+1)*p:0; return n%=p;}
ll id26(char s[] , ll len, ll p){ return !p ? 0 : POW(10,p-1)*(s[len-p]-'0') + id26(s,len,p-1); }
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

ll *factors[2] , fac_cnt=0 , id23=0;
ll factor_pre(){  rep(i,0,1){ if(id23++) return 0; }  ll tmp=(1e6)/2+1, fac_tmp[tmp];  rep(i,0,tmp){fac_tmp[i]=i?2*i+1:2;}  rep(i,1,tmp){if(fac_tmp[i]){  repp(j,3,tmp/(2*i+1)+1,2 ){  if( j*(2*i+1)<tmp ) fac_tmp[ (j*(2*i+1)-1)/2 ]=0;  }  }else continue;}  rep(i,0,tmp){if(fac_tmp[i]){  rep(j,0,2){ factors[j] = realloc( factors[j] , sizeof(ll)*( fac_cnt +1 ) );  factors[j][j?fac_cnt++:fac_cnt]=j?0:fac_tmp[i];  }  } }  return 0;  }
ll factor(ll n, ll id24){ factor_pre();  rep(i,0,fac_cnt){ ll cnt=0; rep(j,0,1){ while( ( cnt+= n %factors[0][i]==0 ? 1 : 0 )  && (n/=factors[0][i]) %factors[0][i]==0 ) continue; } factors[1][i]= id24==1 ? cnt :  id24==2 ? max2(factors[1][i],cnt) : factors[1][i]+cnt ;  if( factors[0][i]> n ) break; } return n; }
ll judge_prime(ll n){ factor_pre(); rep(i,0,fac_cnt){ if(n<factors[0][i]*factors[0][i] || n==factors[0][i]) break; else if(n%factors[0][i]==0) n/=n; }  return n==1?0:1; }

ll *mf_arr,*inv_arr,*id28,id8=0,id3=0,id6=2*1e6+10;
ll makeinv(ll n , ll mod){  rep(i,0,1){if(id8++) return 0;}  inv_arr = realloc(inv_arr, sizeof(ll)*2 );  id28 = realloc(id28, sizeof(ll)*2 );  inv_arr[1]=1;id28[0]=id28[1]=1;  rep(i,2,n+1){  inv_arr = realloc(inv_arr, sizeof(ll)*(i+1) );  id28 = realloc(id28, sizeof(ll)*(i+1) );  inv_arr[i]= mod - inv_arr[mod%i] * (mod / i) % mod;  id28[i] = id28[i - 1] * inv_arr[i] % mod;  }  return 0; }
ll id25(ll n, ll mod){  rep(i,0,1){ if(id3++) return 0; }  mf_arr = realloc(mf_arr, sizeof(ll)*2 );  ll x=1;  mf_arr[0]=mf_arr[1]=x;  rep(i,2,n+1){   x=x*i%mod;  mf_arr = realloc(mf_arr, sizeof(ll)*(i+1) );  mf_arr[i]=x; }  return 0;  }
ll m_inv(ll x, ll mod, ll is_fac ){ makeinv(id6,mod);  return is_fac?id28[x]:inv_arr[x]; }
ll m_f(ll x, ll mod){  id25(id6,mod);  return mf_arr[x];  }
ll id18(ll n, ll k, ll mod){ return m_f(n,mod)*m_inv(k,mod,1)%mod*m_inv(n-k,mod,1)%mod; }
ll m_p(ll r,ll n,ll mod){  ll t=1,s=r;  while(n>0){ t = (n&1) ? t*s%mod : t;  s=s*s%mod; n>>=1; }  return r?t:0;  }
ll id11(ll a, ll b, ll mod){ return a*b%mod; }
ll id29(ll a, ll b, ll c, ll mod){ return id11(a*b%mod,c,mod); }
ll id21(ll a, ll b, ll c, ll d, ll mod){ return id29(a*b%mod,c,d,mod); }
ll id2(ll a, ll b, ll c, ll d, ll e, ll mod){ return id21(a*b%mod,c,d,e,mod); }

int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
int cmp_string( const void * a , const void * b ) {  return strcmp( (char *)a , (char *)b ); }  

int cmp_char(const void * a, const void * b) { return *(char *)a - *(char *)b;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}
void sort_string(int n,int size,char s[][size]){ qsort( (void*)s , n , sizeof(s[0]) , cmp_string ); }
void sort_char(char *s){ qsort( (void *)s , strlen(s) , sizeof(char) , cmp_char ); }
ll unique_string(ll n ,ll size, char s[][size]){ ll ans=1; rep(i,1,n) if( strcmp(s[i],s[i-1]) ) ans++; return ans; }
ll unique_num(ll n , ll a[]){ ll ans=1; rep(i,1,n) if( a[i]!=a[i-1] ) ans++; return ans; }

ll compare(ll a, ll b){ return a<b?-1:a>b?1:0; }
typedef struct{ ll a , b;}fr;
int cmp1( const void *p, const void *q ){  
    ll pa=((fr*)p)->a; ll qa=((fr*)q)->a;  return compare(pa,qa);  
}
int cmp2( const void *p, const void *q ){
    ll pa=((fr*)p)->a; ll qa=((fr*)q)->a;  return compare(qa,pa);
}
void id32(fr*a,int n){qsort(a,n,sizeof(fr),cmp1);}
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
void id27(AVL_set **node, int is_right){
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
int id10(AVL_set **node, ll data, int add){
    if(*node == NULL){
        if(add==2){
            *node = malloc(sizeof(AVL_set));
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
                        delta = id10(&(*node)->child[l], next_node->val, add);
                    }
                }
            }
        }else{
            l = data >= (*node)->val ? 1 : 0;
            delta_sign = data < (*node)->val ? 1 : -1;
            delta = id10(&(*node)->child[l], data, add);
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
                    id27(&(*node)->child[rotate_l], !rotate_right);
                }
                id27(node, rotate_right);
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
ll id13(AVL_set *root, int type){
    while(root->child[type] !=NULL)  root= root->child[type];
    return root->val;
}
void id12(AVL_set **node1, AVL_set **node2){  
    AVL_set *tmp;  tmp=*node1; *node1=*node2; *node2=tmp;
}


ll set_main( int command , int set_num , ll val ){
    static bool id9=false;
    static AVL_set *set_pointer[id20];
    static ll id0[id20];
    if(!id9){ id9=true; rep(i,0,id20){ *(set_pointer+i) = NULL; id0[i]=0; } }
    if(command==-1){ id16( set_pointer[set_num] ,0); }
    if(command==1){ id7(set_pointer[set_num],val) ? 1 : id0[set_num]++;  id10( &set_pointer[set_num] , val , 2 ); }
    if(command==2){ return id7(set_pointer[set_num],val); }
    if(command==3){ ( id7(set_pointer[set_num],val) > 1 ) ? 1 : id0[set_num]--;  id10( &set_pointer[set_num] , val,1); }
    if(command==4){ id0[set_num]--; id10( &set_pointer[set_num] , val , 0 ); }
    if(command==5){ id0[set_num]=0; id5( set_pointer[set_num] ); set_pointer[set_num] = NULL; }
    if(command==6){ return id0[set_num]; }
    if(command==7){ return id13(set_pointer[set_num],1); }
    if(command==8){ return id13(set_pointer[set_num],0); }
    if(command==9){ id12(&set_pointer[set_num],&set_pointer[val]); }
    return 0;
}

void set_print(int set_num){ set_main(-1,set_num,0); }
void set_insert(int set_num, ll val){ set_main(1,set_num,val); }
ll set_count(int set_num, ll val){ return set_main(2,set_num,val); }
void id15(int set_num, ll val, int is_all){ if(is_all) set_main(4,set_num,val); else set_main(3,set_num,val); }
void set_clear(int set_num){ set_main(5,set_num,0); }
ll set_size(int set_num){ return set_main(6,set_num,0); }
ll set_max(int set_num){ return set_main(7,set_num,0); }
ll set_min(int set_num){ return set_main(8,set_num,0); }
void set_swap(ll id22, ll id19){ set_main(9,id22,id19); }


























char s[1151154];
void solve(){
    

    ll n,x,y;
    ll ans=0;
    cin(&n);
    cin(&x);
    cin(&y);
    

    ll d=y-x;
    if(!d){
        rep(i,0,n){
            printf("%lld ",x);
        }PN;
        return;
    }
    rrep(i,n-1,1){
        if(d%i==0){
            ll gap=d/i;
            ll a[n];
            a[n-1]=y;
            

            rrep(j,n-2,0){
                a[j]=a[j+1]-gap;
            }
            ll plus=0;
            if(a[0]<1){
                plus=(1-a[0])/gap;
                if((1-a[0])%gap){
                    plus++;
                }
            }
            rep(j,0,n){
                printf("%lld ",a[j]+plus*gap);
            }PN;
            return;
        }
    }
    printf("-1\n");
    

}

int main(void){
    ll T=1;
    cin(&T);
    rep(i,0,T){ solve(); }
    return 0;
}




