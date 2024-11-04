



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
        const long double E= 2.7182818284590452353;

#define SETZERO(a) memset(a,0,sizeof(a))
#define SETVAL(a,val) memset(a,val,sizeof(a))
#define SETDP(a) memset(a,-1,sizeof(a))



#define in_bounds(x, y, r, c) (x < r && y < c && x >= 0 && y >= 0)



#define min3(a,b,c) (a<min(b,c))?a:min(b,c)




#define CHAR_TO_INDEX(c,startC) ((int)c - (int)startC)

        

#define SZ_ARR(A) sizeof(A)/sizeof(A[0])
        

#define SZ(C) C.size()

#define ALL(x) (x).begin(), (x).end()

        

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


        

#define QL_M_FOR(m,it) for(map<int,int>::iterator it=m.begin();it!=m.end();++it)
#define QL_M_R_FOR(m,rit) for(map<int,int>::reverse_iterator rit=m.rbegin();rit!=m.rend();++rit)


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
        typedef map<int,int>::iterator M_II_IT;

        

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



        

        const long double pi=10000*acos(-1.0L);

        inline void inpS(char *a){
            scanf("%s", a);
        }

        inline int inpLLI(LLI& lld){
            return scanf("%lld", &lld);
        }
        inline int inpULLI(ULLI& ulli){
            return scanf("%llu", &ulli);
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
        inline int outpULLI(ULLI u){
            return printf("%llu\n",u);
        }
        inline int outpLLI(LLI lli){
            return printf("%lld\n",lli);
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
            if (!b)
                return a;
            else 
                return gcd(b, a%b);
        }
        LD euclideanDist(int x1,int y1,int x2,int y2){

            return sqrt( (x1-x2)*(x1-x2)/1. + (y1-y2)*(y1-y2)/1. );
        }
    }
}
#endif  


#if 01
using namespace QoE_Library::QL_Bare_Minimum;

#define PRINT_TIME 0
#define GEN_TEST_CASES 0


int main(){
#if PRINT_TIME
    clock_t t = clock();
#endif

#if 0
    FILE *fIn = freopen("D:\\DUMP\\input.in", "r", stdin);
    FILE *fOut = freopen("D:\\DUMP\\output.out", "w", stdout);
    assert(fIn&&fOut);
#endif
    

    string tot,totc,f,fc,s,sc;
    cin>>tot>>f>>s;
    totc=tot,fc=f,sc=s;
    

    strrev(const_cast<char*>(totc.c_str()) ); 
    strrev(const_cast<char*>(fc.c_str()) ); 
    strrev(const_cast<char*>(sc.c_str()) ); 
    int idx1,idx2;
    bool fl=true,fwd=false,bkw=false;


#if 0
    
    idx1=tot.find(f);
    idx2=totc.find(sc);
    if(idx1==string::npos || idx2==string::npos)fl=false;
    if(fl){
        idx2=tot.length()-idx2-1;
        idx2-=s.length()-1;
        if(idx1+f.length()<=idx2)fwd=true;
    }
    fl=true;
    

    idx1=totc.find(f);
    idx2=tot.find(sc);
    if(idx1==string::npos || idx2==string::npos)fl=false;
    if(fl){
        idx2=tot.length()-idx2-1;
        idx2-=s.length()-1;
        if(idx1+f.length()<=idx2)bkw=true;
    }
#endif

    
    idx1=tot.find(f);
    idx2=tot.find(s,idx1+f.size());
    fwd=(idx1!=string::npos && idx2!=string::npos);

    idx1=totc.find(f);
    idx2=totc.find(s,idx1+f.size());
    bkw=(idx1!=string::npos && idx2!=string::npos);

    if(fwd&&bkw)cout<<"both";
    else if(fwd)cout<<"forward";
    else if(bkw)cout<<"backward";
    else cout<<"fantasy";

#if PRINT_TIME
    t = clock() - t;
    

    cout << "time = " << (double)t/CLOCKS_PER_SEC;
#endif
}
#endif