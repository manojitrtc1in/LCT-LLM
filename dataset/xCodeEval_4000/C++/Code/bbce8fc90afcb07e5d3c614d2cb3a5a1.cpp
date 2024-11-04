#if 01




#pragma once
#ifndef _QL_PRECOMPILATION_BARE_MINIMUM_HPP_
#define _QL_PRECOMPILATION_BARE_MINIMUM_HPP_



#include<iostream>
#include <fstream>



#include <cstdlib>


#include<stdio.h>



#include <time.h>

#include <map>
#include <vector>
#include <string>
#include <cstring>

#include <set>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <stack>
#include <limits.h>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <assert.h>
#include <complex>
#include <valarray>
#include <iterator>

using namespace std;

namespace QoE_Library{

    namespace QL_Bare_Minimum{

        

        

        const double PI = 3.141592653589793238460;
        

        const long double pi=10000*acos(-1.0L);
        const long double E= 2.7182818284590452353;
        const long double eps=1e-10;


        

        

        const int DX4[]={0,1,0,-1};
        const int DY4[]={1,0,-1,0};
        const int DX8[]={-1,-1,-1,0,0,1,1,1};
        const int DY8[]={-1,0,1,-1,1,-1,0,1};
        const int neigh4[][2]={{-1,0},{1,0},{0,-1},{0,1}};
        const int neigh8[][2]={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
        const int neigh9[][2]={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{0,0}};

        template <typename T1> class Vector3D{
        public:
            T1 x,y,z;
            Vector3D(T1 x1,T1 y1,T1 z1):x(x1),y(y1),z(z1){
            }
            Vector3D(){}
        };

#define SETZERO(a) memset(a,0,sizeof(a))
#define SETVAL(a,val) memset(a,val,sizeof(a))
#define SETDP(a) memset(a,-1,sizeof(a))

        

#define in_bounds(x, y, r, c) (x < r && y < c && x >= 0 && y >= 0)
#define in_range(x, lo, hi) (x <= hi && x >= lo )

        

#define min3(a,b,c) (a<min(b,c))?a:min(b,c)
#define max3(a,b,c) ((a>max(b,c))?a:max(b,c))


        

#define CHAR_TO_INDEX(c,startC) ((int)c - (int)startC)

        

#define SZ_ARR(A) sizeof(A)/sizeof(A[0])
        

#define SZ(C) C.size()

#define ALL(x) (x).begin(), (x).end()

#define NOT_FOUND(x,val) ((x).find(val)==(x).end())

        

#define MKP(i,j) make_pair(i,j)
        

#define M_Ins(_m_,i,j) _m_.insert(make_pair(i,j))

        

#define PB(A,B) A.push_back(B);

        

#define SORT(A) sort( A.begin(),A.end() )


        

#define FOR(i, first, last, increment) for (int i = (first); i < (last); i = i + (increment))
#define QL_FOR FOR

#define DEBUGGING 1

        

#define FOR_DEF(i, last) QL_FOR(i, 0, last, 1)
#define QL_FOR_DEF FOR_DEF


        

        

#define REPEAT(N) for (int __i__ = 0; __i__ < (N); ++__i__)



        

#define R_FOR(i, first, last, increment) for (int i = ((first) - 1); i >= (last); i = i - (increment))
#define QL_R_FOR R_FOR



        

#define R_FOR_DEF(i, first) QL_R_FOR(i, first, 0, 1)
#define QL_R_FOR_DEF R_FOR_DEF
#if 0
#define FOR_STL(i,stl) for(typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#endif

#define EXISTS(c,e) ((c).find(e)!=(c).end())

        

#define QL_M_FOR(m,T1,T2,it) for(map<T1,T2>::iterator it=m.begin();it!=m.end();++it)
#define QL_M_R_FOR(m,T1,T2,rit) for(map<T1,T2>::reverse_iterator rit=m.rbegin();rit!=m.rend();++rit)

#if 0
#define QL_M_FOR(m,it) QL_M_FOR(m,int,int,it)   

#define QL_M_R_FOR(m,rit) QL_M_R_FOR(m,int,int,it)   

#endif

        typedef unsigned long long int ulli_t;
        typedef ulli_t ULLI;
        typedef vector<ulli_t> uivector_t;
        typedef uivector_t::iterator uivector_it_t;
        typedef uivector_t::const_iterator uivector_cit_t;


        typedef long long int lli_t;
        typedef lli_t LLI;
        typedef vector<lli_t> ivector_t;
        typedef ivector_t::iterator ivector_it_t;
        typedef ivector_t::const_iterator ivector_cit_t;


        

        typedef pair<int,int> p_ii_t;
        typedef p_ii_t P_II;
        typedef pair<LLI,LLI> p_llilli_t;
        typedef p_llilli_t P_LLILLI;

        

        typedef vector<int> v_i_t;
        typedef v_i_t V_I;
        typedef vector<LLI> v_lli_t;
        typedef v_lli_t V_LLI;
        typedef vector<ULLI> v_ulli_t;
        typedef v_ulli_t V_ULLI;

        typedef vector<p_ii_t> v_p_ii_t;
        typedef v_p_ii_t V_P_II;

        typedef vector<v_i_t> vv_i_t;
        typedef vv_i_t VV_I;
        typedef vector<v_p_ii_t> vv_p_ii_t;
        typedef vv_p_ii_t VV_P_II;

        typedef vector<string> v_s_t;
        typedef v_s_t V_S;

        

        typedef map<int,int> M_II;
        typedef M_II::iterator M_II_IT;
        typedef M_II::reverse_iterator M_II_RIT;

        

        typedef multimap<int,int> MM_II;
        typedef MM_II::reverse_iterator MM_II_RIT;

        

        typedef queue<int> q_i_t;
        typedef q_i_t Q_I;

        typedef long double ld_t;
        typedef ld_t LD;


        
#define read1(n) cin >> n;
#define read2(m, n) cin >> m >> n;
#define read3(m, n, o) cin >> m >> n >> o;
        

#define readArr1D(n, size)  QL_FOR_DEF(i, size) \
        {                   \
        cin >> n[i];    \
        } 

#define write1(n) cout << n;
#define write2(m, n) cout << m << n;
#define write3(m, n, o) cout << m << n << o;
#define writeArr1D(n, size) QL_FOR_DEF(i, size) \
        {                   \
        cout << n[i];   \
        } 

#define DBG(x)              cout<<__LINE__<<" :: "<<#x<< ": "<<x<<endl;
#define DBG2(x, y)          cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<endl;
#define DBG3(x, y, z)       cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<" | "<<#z<<": "<<z<<endl;
#define DBG4(a, b, c, d)    cout<<__LINE__<<" :: "<<#a<< ": "<<a<<" | "<<#b<< ": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;


        
        template<typename T1> inline T1 to_type(string s){
            T1 a;
            istringstream sin(s);
            sin>>a;
            

            

            return a;
        }
        template<typename T1> inline string to_str(T1 a){
            ostringstream sout;
            string s;
            sout>>a;
            

            

            return sout.str();
        }

        inline void inpS(char *a){
            scanf("%s", a);
        }

        

        inline int inpI() {
            int n = 0;
            int ch = getchar();
            

            int sign = 1;
            while(ch < '0' || ch > '9') {
                if (ch == '-') sign = -1; 
                ch = getchar();
                

            }
            while(ch >= '0' && ch <= '9')
                n = (n<<3) + (n<<1) + ch - '0', ch = getchar();
            

            n = n*sign;

            return n;
        }
        inline void inpI2(int &a,int &b){
            a=inpI();
            b=inpI();
        }
        inline void inpI3(int &a,int &b,int &c){
            a=inpI();
            b=inpI();
            c=inpI();
        }

        inline double inpD() {
            double res = 0.0;
            char c;
            while(1) {
                c = getchar();
                

                if(c == ' ' || c == '\n') continue;
                else break;
            }
            res = c - '0';
            while(1) {
                c = getchar();
                

                if(c >= '0' && c <= '9') res = 10 * res + c - '0';
                else break;
            }
            if(c == '.') {
                double decimal = 0.0, divi = 1.0;
                while(1) {
                    c = getchar();
                    

                    if(c >= '0' && c <= '9') decimal += (c - '0') / (divi *= 10.0);
                    else break;
                }
                res += decimal;
            }
            return res;
        }

        inline void outpD(double N) {
            char buff[24],sz=0;
            int integer = N;
            int decimal = (N - integer) * 10000000;
            int tmp = decimal;

            while(decimal) {
                buff[sz++] = '0' + decimal % 10;
                decimal /= 10;
            }
            for(int decimal2 = 1000000; decimal2 > tmp; decimal2 /= 10) {
                buff[sz++] = '0';
            }
            buff[sz++] = '.';
            if(integer == 0) buff[sz++] = '0';
            while(integer) {
                buff[sz++] = '0' + integer % 10;
                integer /= 10;
            }
            while(--sz>=0)
                putchar(buff[sz]);
            

            putchar(10);
            

        }
        inline void outpI(int a) {
            char c;
            char snum[20];
            int i=0;
            int sign = 0;
            if(a < 0) sign = 1;
            a = abs(a);
            do {
                snum[i++]=a%10+48;
                a=a/10;
            } while(a!=0);
            i=i-1;
            if(sign) 
                putchar('-');
            


            while(i>=0)
                putchar(snum[i--]);
            

            putchar('\n');
            

        }
        inline void outpI2(int a,int b){
            printf("%d ",a);
            outpI(b);
        }
        inline int outpS(char *s){
            return printf("%s\n",s);
        }
        
        template<typename T1> void QL_swap(T1 &x, T1 &y){
            
            T1 tmp;
            tmp=x;
            x=y;
            y=tmp;
        }


        

#if 0
        void QL_swapChars(char *a,char *b){
            char tmp=*a;
            *a=*b;
            *b=tmp;
        }
#endif

        
        
        template<typename T1> T1 gcd(T1 a, T1 b) {
            if (!b)return a;
            return gcd(b, a%b);
        }
        LLI euclideanDistSq(LLI x1,LLI y1,LLI x2,LLI y2){

            return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        }
        template<typename T> LD euclideanDist(T x1,T y1,T x2,T y2){
            return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        }
        

        template<typename T1> T1 dotProd(T1 x1,T1 y1,T1 z1,T1 x2,T1 y2,T1 z2){
            return x1*x2+y1*y2+z1*z2;
        }
        

        template<typename T1> Vector3D<T1> crossProd(Vector3D<T1> v1, Vector3D<T1> v2){
            Vector3D<T1> v;
            v.x=v1.y*v2.z - v2.y*v1.z;
            v.y=v1.z*v2.x - v2.z*v1.x;
            v.z=v1.x*v2.y - v2.x*v1.y;
            return v;
        }
    }
}
#endif  


#if 01
using namespace QoE_Library::QL_Bare_Minimum;

#define PRINT_TIME 0
#define GEN_TEST_CASES 0
#define MAT_SIZE 1005



LD find360Angle(LD x,LD y){
    if(!y&&!x)return -1;
    LD a=atan2(abs(y),abs(x));
    if(x*y<0)a=90-a;

    if(x<0&&y>0)a+=90;
    else if(x<0&&y<0)a+=180;
    else if(x>0&&y<0)a+=270;
    return a;
}
class Point{
public:
    int x,y;
};





inline LLI orientation(Point p,Point q,Point r) {
    LLI val = (q.y - p.y) * (r.x - q.x) -
        (q.x - p.x) * (r.y - q.y);

    if(val == 0ll) return 0;
    else if(val < 0ll) return -1;
    else return 1;
}
inline bool isLeft(int x1, int y1, int x2, int y2, int x3, int y3) {
  LLI dx1 = x2 - x1;
  LLI dy1 = y2 - y1;
  LLI dx2 = x3 - x1;
  LLI dy2 = y3 - y1;
  return dx1*dy2 - dx2*dy1 > 0;
}
#if 0
inline bool isLeft(Point& a,Point& b,Point& c){
    return ( (LLI)(b.x - a.x)*(LLI)(c.y - a.y) - (LLI)(b.y - a.y)*(LLI)(c.x - a.x)) > 0LL;
}
#endif
int below[505][505];


int rx[505],ry[505],bx[505],by[505];
int main(){
#if PRINT_TIME
    clock_t t = clock();
#endif

#if 0
    FILE *fIn = freopen("G:\\DUMP\\input.in", "r", stdin);
    

    

    

#endif

    

    int n,m,t;
    

    cin>>n>>m;
    QL_FOR_DEF(i,n){
        

        cin>>rx[i]>>ry[i];
        

        

    }
    QL_FOR_DEF(i,m){
        cin>>bx[i]>>by[i];
        

        

    }

    

    QL_FOR_DEF(i,n){
        QL_FOR(j,i+1,n,1){
            int id1,id2;
            Point mdpt;

            

            if(rx[i]==rx[j])continue;
            

#if 01
            if(rx[i]<rx[j])id1=i,id2=j;
            else id1=j,id2=i;
#endif

#if 0
            mdpt.x=rx[i];
            mdpt.y=ry[i]-1;
#endif
            QL_FOR_DEF(k,m){
                

                
                

                if(!isLeft(rx[id1],ry[id1],rx[id2],ry[id2],bx[k],by[k]) && rx[id1]<bx[k]&&bx[k]<=rx[id2])++below[id1][id2],++below[id2][id1];
            }
        }
    }
    int tot=0;
    QL_FOR_DEF(i,n){
        QL_FOR(j,i+1,n,1){
            QL_FOR(k,j+1,n,1){
                

                



                

                int lst[]={i,j,k};
                int net=0;

                
#if 0
                Point cent;

#if 0
                cent.x=(r[i].x+r[j].x+r[k].x)/3;
                cent.y=(r[i].y+r[j].y+r[k].y)/3;
#endif
                QL_FOR_DEF(p,3){
                    QL_FOR(q,p+1,3,1){
                        Point mdpt;
#if 0
                        mdpt.x=(r[lst[p]].x+r[lst[q]].x)/2;
                        mdpt.y=(r[lst[p]].y+r[lst[q]].y)/2;
                        --mdpt.y;
#else
                        int o=-1;
                        while(o++<2)if(o!=p&&o!=q)break;
                        cent.x=r[lst[o]].x;
                        cent.y=r[lst[o]].y;

                        mdpt.x=r[lst[p]].x;
                        mdpt.y=r[lst[p]].y-1;
#endif
                        int id1,id2;
                        if(r[lst[p]].x<=r[lst[q]].x)id1=p,id2=q;
                        else id1=q,id2=p;
                        if(isLeft(r[lst[p]],r[lst[q]],mdpt)==isLeft(r[lst[p]],r[lst[q]],cent))net+=below[lst[id1]][lst[id2]];
                        else net-=below[lst[id1]][lst[id2]];
                    }
                }
#endif

                
                int minid=i,maxid=j,remain=k;
                QL_FOR_DEF(p,3){
                    if(rx[lst[p]]<rx[minid])minid=lst[p];
                    if(rx[lst[p]]>rx[maxid])maxid=lst[p];
                }
                QL_FOR_DEF(p,3){
                    if(lst[p]==minid || lst[p]==maxid)continue;
                    remain=lst[p];
                }
                net=below[remain][minid]+below[remain][maxid]-below[minid][maxid];
                if(!net)++tot;
            }
        }
    }
    cout<<tot<<endl;

    

#if 0
    multimap<LD,Point>::iterator it,it2,it3,it4;
    int tot=0;
    

    for(it=mp.begin();it!=mp.end();++it){
        

        if(it->second.c)continue;
        for(it2=it;it2!=mp.end();++it2){

        }
    }
#endif  


#if PRINT_TIME
    t = clock() - t;
    

    cout << "time = " << (double)t/CLOCKS_PER_SEC;
#endif
}
#endif
#endif