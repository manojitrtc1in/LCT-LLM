






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
double id13(double a, double b){double c=1;rep(i,0,b) c*=a;return c;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll id12(ll n){n+= n<0?((-n)/MOD1+1)*MOD1:0; return n%=MOD1;}
ll mod_p(ll n ,ll p){n+= n<0?((-n)/p+1)*p:0; return n%=p;}
ll id9(char s[] , ll len, ll p){ return !p ? 0 : POW(10,p-1)*(s[len-p]-'0') + id9(s,len,p-1); }
ll digits(ll a, ll b){return a/b?1+digits(a/b,b):1;}
ll base(ll n, ll a, ll i){return i==1?n%a:base(n/a,a,i-1);}

void lr_lower( int *l, int *r, ll am, ll val , int type ){ (type<3) ? ( am < val ?  ( *l = (*l+*r)/2 ) : ( *r= (*l+*r)/2 ) ) : ( am <= val ? ( *l = (*l+*r)/2 ) : ( *r= (*l+*r)/2 ) ); }
void lr_upper( int *l, int *r, ll am, ll val , int type ){ (type<3) ? ( am <= val ?  ( *l = (*l+*r)/2 ) : ( *r= (*l+*r)/2 ) ) : ( am < val ? ( *l = (*l+*r)/2 ) : ( *r= (*l+*r)/2 ) ); }
int cmp_lower( ll a, ll b, int type ){ return (type==1) ? ( a==b ? 1 : 0 ) : (type==2) ? ( a>=b ? 1 : 0 ) : ( a>b ? 1 : 0 ) ; }
int cmp_upper( ll a, ll b, int type ){ return (type==1) ? ( a==b ? 1 : 0 ) : (type==2) ? ( a<=b ? 1 : 0 ) : ( a<b ? 1 : 0 ) ; }


ll lower_bound( ll a[], int l, int r, ll val , int type ){  while(r-l>1) lr_lower(&l,&r,a[ (l+r)/2 ],val,type);  return cmp_lower(a[l],val,type) ? l : cmp_lower(a[r],val,type) ? r : -1;  }


ll upper_bound( ll a[], int l, int r, ll val , int type ){  while(r-l>1) lr_upper(&l,&r,a[ (l+r)/2 ],val,type); return cmp_upper(a[r],val,type) ? r : cmp_upper(a[l],val,type) ? l : -1; }


ll count(ll a[], int l, int r, ll x){  int p = lower_bound(a,l,r,x,1);  return p==-1 ? 0 : upper_bound(a,p,r,x,1)-p+1; }

ll *factors[2] , fac_cnt=0 , id6=0;
ll factor_pre(){  rep(i,0,1){ if(id6++) return 0; }  ll tmp=(1e6)/2+1, fac_tmp[tmp];  rep(i,0,tmp){fac_tmp[i]=i?2*i+1:2;}  rep(i,1,tmp){if(fac_tmp[i]){  repp(j,3,tmp/(2*i+1)+1,2 ){  if( j*(2*i+1)<tmp ) fac_tmp[ (j*(2*i+1)-1)/2 ]=0;  }  }else continue;}  rep(i,0,tmp){if(fac_tmp[i]){  rep(j,0,2){ factors[j] = realloc( factors[j] , sizeof(ll)*( fac_cnt +1 ) );  factors[j][j?fac_cnt++:fac_cnt]=j?0:fac_tmp[i];  }  } }  return 0;  }
ll factor(ll n, ll id7){ factor_pre();  rep(i,0,fac_cnt){ ll cnt=0; rep(j,0,1){ while( ( cnt+= n %factors[0][i]==0 ? 1 : 0 )  && (n/=factors[0][i]) %factors[0][i]==0 ) continue; } factors[1][i]= id7==1 ? cnt :  id7==2 ? max2(factors[1][i],cnt) : factors[1][i]+cnt ;  if( factors[0][i]> n ) break; } return n; }
ll judge_prime(ll n){ factor_pre(); rep(i,0,fac_cnt){ if(n<factors[0][i]*factors[0][i] || n==factors[0][i]) break; else if(n%factors[0][i]==0) n/=n; }  return n==1?0:1; }

ll *mf_arr,*inv_arr,*id10,id3=0,id1=0;
ll makeinv(ll n , ll mod){  rep(i,0,1){if(id3++) return 0;}  inv_arr = realloc(inv_arr, sizeof(ll)*2 );  id10 = realloc(id10, sizeof(ll)*2 );  inv_arr[1]=1;id10[0]=id10[1]=1;  rep(i,2,n+1){  inv_arr = realloc(inv_arr, sizeof(ll)*(i+1) );  id10 = realloc(id10, sizeof(ll)*(i+1) );  inv_arr[i]= mod - inv_arr[mod%i] * (mod / i) % mod;  id10[i] = id10[i - 1] * inv_arr[i] % mod;  }  return 0; }
ll id8(ll n, ll mod){  rep(i,0,1){ if(id1++) return 0; }  mf_arr = realloc(mf_arr, sizeof(ll)*2 );  ll x=1;  mf_arr[0]=mf_arr[1]=x;  rep(i,2,n+1){   x=x*i%mod;  mf_arr = realloc(mf_arr, sizeof(ll)*(i+1) );  mf_arr[i]=x; }  return 0;  }
ll m_inv(ll x, ll mod, ll is_fac ){ makeinv(2*1e6+10,mod);  return is_fac?id10[x]:inv_arr[x]; }
ll m_f(ll x, ll mod){  id8(2*1e6+10,mod);  return mf_arr[x];  }


ll m_p(ll r,ll n,ll mod){  ll t=1,s=r;  while(n>0){ t = (n&1) ? t*s%mod : t;  s=s*s%mod; n>>=1; }  return r?t:0;  }
ll id4(ll a, ll b, ll mod){ return a*b%mod; }
ll id11(ll a, ll b, ll c, ll mod){ return id4(a*b%mod,c,mod); }
ll id5(ll a, ll b, ll c, ll d, ll mod){ return id11(a*b%mod,c,d,mod); }
ll id0(ll a, ll b, ll c, ll d, ll e, ll mod){ return id5(a*b%mod,c,d,e,mod); }

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

typedef struct{ ll a , b;}fr;
int cmp1( const void *p, const void *q ) { return ((fr*)p) ->a - ((fr*)q)->a;}
int cmp2( const void *p, const void *q ) { return ((fr*)q) ->a - ((fr*)p)->a;}
void id14(fr*a,int n){qsort(a,n,sizeof(fr),cmp1);}
void id2(fr*a,int n){qsort(a,n,sizeof(fr),cmp2);}

ll l,r,kk;
ll dp[20][1025][2];
ll cnt[20][1025][2];

ll ss(ll n){
    ll d=digits(n,10),ans=0;
    rep(i,0,20) rep(j,0,1025) rep(k,0,2) dp[i][j][k]=-1;
    rep(i,0,20) rep(j,0,1025) rep(k,0,2) cnt[i][j][k]=0;
    dp[0][0][1]=0;
    cnt[0][0][1]=1;
    rep(i,1,d){
        dp[i][0][0]=0;
        cnt[i][0][0]=1;
    }
    rep(i,0,d){
        

        ll p=base(n,10,d-i);
        

        rep(j,0,1<<10){
            if(dp[i][j][0]==-1&&dp[i][j][1]==-1) continue;
            

            

            rep(k,0,10){
                if(!j&&!k) continue;
                

                if(k<p){
                    if(dp[i+1][j|(1<<k)][0]==-1) dp[i+1][j|(1<<k)][0]=0;
                    if(dp[i][j][0]!=-1){
                        dp[i+1][j|(1<<k)][0]+=dp[i][j][0]*10+k*cnt[i][j][0];
                        cnt[i+1][j|(1<<k)][0]+=cnt[i][j][0];
                        cnt[i+1][j|(1<<k)][0]%=MOD2;
                    }
                    if(dp[i][j][1]!=-1){
                        dp[i+1][j|(1<<k)][0]+=dp[i][j][1]*10+k*cnt[i][j][1];
                        cnt[i+1][j|(1<<k)][0]+=cnt[i][j][1];
                        cnt[i+1][j|(1<<k)][0]%=MOD2;
                    }
                    dp[i+1][j|(1<<k)][0]%=MOD2;
                    

                    

                }
                if(k==p){
                    if(dp[i][j][0]!=-1 && dp[i+1][j|(1<<k)][0]==-1) dp[i+1][j|(1<<k)][0]=0;
                    if(dp[i][j][1]!=-1 && dp[i+1][j|(1<<k)][1]==-1) dp[i+1][j|(1<<k)][1]=0;
                    if(dp[i][j][0]!=-1){
                        dp[i+1][j|(1<<k)][0]+=dp[i][j][0]*10+k*cnt[i][j][0];
                        cnt[i+1][j|(1<<k)][0]+=cnt[i][j][0];
                        cnt[i+1][j|(1<<k)][0]%=MOD2;
                    } 
                    if(dp[i][j][1]!=-1){
                        dp[i+1][j|(1<<k)][1]+=dp[i][j][1]*10+k*cnt[i][j][1];
                        cnt[i+1][j|(1<<k)][1]+=cnt[i][j][1];
                        cnt[i+1][j|(1<<k)][1]%=MOD2;
                    }
                    if(dp[i+1][j|(1<<k)][0]!=-1) dp[i+1][j|(1<<k)][0]%=MOD2;
                    if(dp[i+1][j|(1<<k)][1]!=-1) dp[i+1][j|(1<<k)][1]%=MOD2;
                    

                }
                if(k>p&&i){
                    if(dp[i][j][0]==-1){
                        

                        continue; }
                    if(dp[i+1][j|(1<<k)][0]==-1) dp[i+1][j|(1<<k)][0]=0;
                    dp[i+1][j|(1<<k)][0]+=dp[i][j][0]*10+k*cnt[i][j][0];
                    cnt[i+1][j|(1<<k)][0]+=cnt[i][j][0];
                    cnt[i+1][j|(1<<k)][0]%=MOD2;
                    dp[i+1][j|(1<<k)][0]%=MOD2;
                    

                }
                

            }
        }
        

        

        

        

        

        

    }
    

    

    

    

    

    

    

    

    

    rep(i,0,1<<10){
        if(__builtin_popcount(i)<=kk){
            if(dp[d][i][0]!=-1) ans+=dp[d][i][0];
            if(dp[d][i][1]!=-1) ans+=dp[d][i][1];
            ans%=MOD2;
        }
    }
    return ans;
}





int main(void){
    

    ll ans=0;
    cin(&l);
    cin(&r);
    cin(&kk);
    

    

    ll R=ss(r);
    ll L=ss(l-1);
    ans=mod_p(R-L,MOD2);
    printf("%lld\n",ans  );
    

    return 0;
}
