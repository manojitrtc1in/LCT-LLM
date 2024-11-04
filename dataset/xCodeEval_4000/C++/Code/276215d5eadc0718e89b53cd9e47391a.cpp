











                                   

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
#define EPS 1e-13l
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
#define RFIJ(_n, _m) RFI(_n) RFJ(_m)
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
#define schnell __fastcall




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


#define SPARSEN(n1, n2, t, len, f, e) e t[30][len];\
int n2(int l,int r){int w=r-l+1;if(1==w)return t[0][l];int z=LOG2I(w);return f(t[z][l],t[z][r+1-(1<<z)]);}\
void n1(const e*d){FOR(i,0,len-1)t[0][i]=d[i];FOR(i,1,29)for(int a=0,b=1<<i-1;b<n;++a,++b)t[i][a]=f(t[i-1][a],t[i-1][b]);}
unsigned char superlog[] = {0x8b,0x44,0x24,0x04,0x0f,0xbd,0xc0,0xc2,0x04,0x00};
#define LOG2I(x) (((int __stdcall(*)(const int))(void *)superlog)(x))

template <typename TY, typename TX> TX B2L(TY(*f)(const TX&),TX l,TX r,const TY&q){while(l!=r){TX mit=l+r>>1;  if(f(mit)<q)l=mit+1;else r=mit;}return l;}
template <typename TY, typename TX> TX B2R(TY(*f)(const TX&),TX l,TX r,const TY&q){while(l!=r){TX mit=l+r+1>>1;if(f(mit)>q)r=mit-1;else l=mit;}return l;}
template <typename TY, typename TX> TX B2F(TY(*f)(const TX&),TX l,TX r,const TY&q){while(r-l>EPS){TX mit=(l+r)/2.0l;if(f(mit)<q)l=mit;else r=mit;}return (l+r)/2.0l;}

template <typename TY, typename TX> TX T3A(TY(*f)(const TX&),TX l,TX r,const TY&d=6){TY t;while(r-l>=d){t=(r-l)/3;TY xl=l+t,xr=r-t;if(f(xl)>f(xr)) r=xr;else l=xl;}TY o=f(l);if(r-l>=1)FOR(i,l,r)if((t=f(i))>o){o=t;l=i;};return l;}
template <typename TY, typename TX> TX T3I(TY(*f)(const TX&),TX l,TX r,const TY&d=6){TY t;while(r-l>=d){t=(r-l)/3;TY xl=l+t,xr=r-t;if(f(xl)<f(xr)) r=xr;else l=xl;}TY o=f(l);if(r-l>=1)FOR(i,l,r)if((t=f(i))<o){o=t;l=i;};return l;}

template <typename T> T SQR(const T&x){return x*x;}
template <typename T> T PWM(const T&x,const T&e,const T&m){T y=x,r=1;WBI(i,b,e){if(b)r=r*y%m;y=y*y%m;};return r;}
template <typename T> T INV(const T&x,const T&m){return PWM<T>(x,m-2,m);}
template <typename T> T GCD(const T&a,const T&b){T x=a,y=b;while(y){x%=y;swap(x,y);}return x;}

template <typename T> T HYP(const T&x,const T&y){return sqrt(x*x+y*y);}
template <typename T> T DTL(const T&A,const T&B,const T&C,const T&px,const T&py){return fabsl(A*px+B*py+C)/sqrtl(A*A+B*B);}

template <typename T> void ABC(T&A,T&B,T&C,const T&px1,const T&py1,const T&px2,const T&py2){A=py2-py1;B=px1-px2;C=-A*px1-B*py1;}
#define NABC(x1, y1, x2, y2) LD A,B,C;ABC(A,B,C,x1,y1,x2,y2);

template <typename T> int F12(T x,map<T,int>&r){int o=0;while(x>1){int f=0;for(T i=2;i*i<=x;++i)if(0==x%i){++o;++r[i];x/=i;f=1;break;}if(!f){++o;++r[x];break;}}return o;}
template <typename T> int C12(T x){int o=0;while(x>1){int f=0;for(T i=2;i*i<=x;++i)if(0==x%i){++o;x/=i;f=1;break;}if(!f){++o;break;}}return o;}
template <typename T> void DEN(typename map<T,int>::const_iterator b,typename map<T,int>::const_iterator e,vector<T>&r,T z=1){if(b==e){r.push_back(z);return;}TYP(b)c=b;++c;RFZ(b->second){DEN(c,e,r,z);z*=b->first;}}

template <typename T> void DMP(vector<T>&x){WLK(it,x)cout<<*it<<' ';cout<<endl;};

int n;

int satra[5555];
int lcp[5555];
char sitra[5555];

void sa_build_fast(const char *ss, int *sa, int n){

    int *cl = new int[n];

    

    int *csort = new int[max(0x100, n)];
    memset(csort, 0, sizeof(int) * max(0x100, n));

    

    FOR(i, 0, n - 1) ++csort[ss[i]];
    FOR(i, 1, 0xff) csort[i] += csort[i - 1];
    FOR(i, 0, n - 1) sa[--csort[ss[i]]] = i;

    cl[sa[0]] = 0;

    int smss = 1;

    

    FOR(i, 1, n - 1){
        if(ss[sa[i]] != ss[sa[i - 1]]) ++smss;
        cl[sa[i]] = smss - 1;
    }

    int *sa_new = new int[n];
    int *cl_new = new int[n];

    

    for(int k2 = 1; k2 < n; k2 <<= 1){
        memset(csort, 0, sizeof(int) * smss);
        

        

        FOR(i, 0, n - 1) sa_new[i] = (sa[i] + n - k2) % n;
        

        FOR(i, 0, n - 1) csort[cl[sa[i]]]++;
        FOR(i, 1, smss - 1) csort[i] += csort[i - 1];
        FORd(i, n - 1, 0) sa[--csort[cl[sa_new[i]]]] = sa_new[i];

        cl_new[sa[0]] = 0;
        

        smss = 1;
        FOR(i, 1, n - 1){
            if(cl[sa[i]] != cl[sa[i - 1]] || cl[(sa[i] + k2) % n] != cl[(sa[i - 1] + k2) % n]) ++smss;
            cl_new[sa[i]] = smss - 1;
        }

        memcpy(cl, cl_new, n * sizeof(int));
    }

    

    delete sa_new;
    delete cl_new;
    delete csort;
    delete cl;
}

int k;

SPARSEN(sparse_create, sparse_query, sparsen, 5555, min, int);


int mozgi[5555];


char piski[5555][5555];






  

    

    

    


    
 
    
   



int lcpcmp(const char *li, const char *re){
    int raus = 0;
    while(*(li++) == *(re++)) ++raus;
    return raus;
}

int padp[5555];

static void __fastcall FadeDemonSolution(){

    




    cin >> sitra;
    cin >> k;


    

    


    

        

    


    n = strlen(sitra);
    sa_build_fast(sitra, satra, n + 1);

    


    FOR(i, 0, n){
        mozgi[satra[i]] = i;
    }


    FOR(i, 0, n - 1) lcp[i] = lcpcmp(sitra + satra[i], sitra + satra[i + 1]);

    

    

                 

    




    FOR(i, 0, n - 1){
        piski[mozgi[i]][1] = 1;
        

        for(int j = 1; j <= n; j += 2){
            int links = i - j;
            int recht = i + j;

            if(links < 0 || recht >= n) break;

            if(sitra[links] == sitra[recht]){
                

                

                piski[mozgi[links]][recht - links + 1] = 1;
            }else{
                break;
            }
        }

        for(int j = 2; j <= n; j += 2){
            int links = i - j;
            int recht = i + j;

            if(links < 0 || recht >= n) break;

            if(sitra[links] == sitra[recht]){
                

                

                piski[mozgi[links]][recht - links + 1] = 1;
            }else{
                break;
            }
        }

        for(int j = 0; j <= n; j += 2){
            int links = i - j;
            int recht = i + 1 + j;

            if(links < 0 || recht >= n) break;

            if(sitra[links] == sitra[recht]){
                

                

                piski[mozgi[links]][recht - links + 1] = 1;
            }else{
                break;
            }
        }

        for(int j = 1; j <= n; j += 2){
            int links = i - j;
            int recht = i + 1 + j;

            if(links < 0 || recht >= n) break;

            if(sitra[links] == sitra[recht]){
                

                

                piski[mozgi[links]][recht - links + 1] = 1;
            }else{
                break;
            }
        }
    }


    FOR(i, 0, n) padp[i] = 1;

    FOR(i, 1, n){
        FOR(j, padp[i], n){

            int ia = i;

            do {
                

                padp[ia] = 1 + j;

                if(piski[ia][j]){
                    


                    if(1 == k){

                        char *starte = sitra + satra[ia];
                        cout << string(starte, starte + j) << endl;

                        

                        

                        

                        return;

                    }else{
                        --k;
                    }
                }

            } while(lcp[ia++] >= j);
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