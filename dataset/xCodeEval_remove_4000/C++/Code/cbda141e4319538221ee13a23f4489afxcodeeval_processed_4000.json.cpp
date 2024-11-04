











































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


        



        


        {                   \
        cin >> n[i];    \
        } 





        {                   \
        cout << n[i];   \
        } 







        
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

        inline int id8(LLI& lld){
            return scanf("%lld", &lld);
        }
        inline int id4(ULLI& ulli){
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
        inline void id3(int &a,int &b){
            a=inpI();
            b=inpI();
        }
        inline void id6(int &a,int &b,int &c){
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

        inline void id11(double N) {
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
        inline int id5(ULLI u){
            return printf("%llu\n",u);
        }
        inline int id0(LLI lli){
            return printf("%lld\n",lli);
        }
        inline void id7(int a) {
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
        inline void id1(int a,int b){
            printf("%d ",a);
            id7(b);
        }
        inline int id2(char *s){
            return printf("%s\n",s);
        }
        
        template<typename T1> void QL_swap(T1 &x, T1 &y){
            
            T1 tmp;
            tmp=x;
            x=y;
            y=tmp;
        }


        


        void id9(char *a,char *b){
            char tmp=*a;
            *a=*b;
            *b=tmp;
        }


        
        
        template<typename T1> T1 gcd(T1 a, T1 b) {
            if (!b)return a;
            return gcd(b, a%b);
        }
        LD id10(int x1,int y1,int x2,int y2){

            return sqrt( (x1-x2)*(x1-x2)/1. + (y1-y2)*(y1-y2)/1. );
        }
    }
}




using namespace QoE_Library::QL_Bare_Minimum;








int countPower(int n,int base=10){
    int d=0;
    while(!(n%base)){
        ++d;
        n/=base;
    }
    return d;
}

int dp[MAT_SIZE][2],pred[MAT_SIZE][MAT_SIZE][2],a[MAT_SIZE][MAT_SIZE][2];


int main(){

    clock_t t = clock();



    FILE *fIn = freopen("D:\\DUMP\\input.in", "r", stdin);
    FILE *fOut = freopen("D:\\DUMP\\output.out", "w", stdout);
    FILE *fLog = freopen("D:\\DUMP\\log.log", "w", stderr);
    assert(fIn&&fOut&&fLog);

    int T=1;



    P_II **a=new P_II *[MAT_SIZE];
    P_II **pred=new P_II*[MAT_SIZE];
    id12(i,MAT_SIZE){
        a[i]=new P_II[MAT_SIZE];
        pred[i]=new P_II[MAT_SIZE];
    }

    while (T--){
        int n=inpI();
        int m=n;
        id12(i,n){
            dp[i][0]=1000000005;
            dp[i][1]=1000000005;
        }
        int specialR=-1,specialC=-1;
        bool f=0;
        id12(i,n){
            id12(j,m){
                int t=inpI();

                
                if(!t)specialR=i,specialC=j,f=1,t=10;
                a[i][j][0]=countPower(t,2);
                a[i][j][1]=countPower(t,5);
            }
        }



        dp[0][0]=a[0][0][0],dp[0][1]=a[0][0][1];
        id12(i,n){
            id12(j,m){
                if(in_bounds(i,j+1,n,m)){
                    id12(k,2){
                        if(dp[j+1][k] > dp[j][k]+a[i][j+1][k]){
                            dp[j+1][k]=dp[j][k]+a[i][j+1][k];
                            pred[i][j+1][k]='L';
                        }
                    }
                }
                if(in_bounds(i+1,j,n,m)){
                    id12(k,2){
                        dp[j][k]+=a[i+1][j][k];
                        pred[i+1][j][k]='U';
                    }
                }
            }
        }


        


        dp[0]=a[0][0];
        id12(i,n){
            id12(j,m){
                if(in_bounds(i,j+1,n,m)){
                    if(min(dp[j+1].first,dp[j+1].second) > min(dp[j].first+a[i][j+1].first,dp[j].second+a[i][j+1].second)){
                        dp[j+1].first=dp[j].first+a[i][j+1].first;
                        dp[j+1].second=dp[j].second+a[i][j+1].second;
                        pred[i][j+1]='L';
                    }
                }
                if(in_bounds(i+1,j,n,m)){
                    dp[j].first+=a[i+1][j].first;
                    dp[j].second+=a[i+1][j].second;
                    pred[i+1][j]='U';
                }
            }
        }

        string s;
        int r,idx;
        if(dp[n-1][0]<dp[n-1][1])idx=0;
        else idx=1;
        r=dp[n-1][idx];
        if(f&&r>=1){
            id12(i,specialC)s+='R';
            id12(i,specialR)s+='D';
            QL_FOR(i,specialC+1,m,1)s+='R';
            QL_FOR(i,specialR+1,n,1)s+='D';
            r=1;
        }else{
            int j=m-1,i=n-1;
            while(!!i||!!j){
                if('U'==pred[i][j][idx]){
                    s='D'+s;
                    --i;
                }else if('L'==pred[i][j][idx]){
                    s='R'+s;
                    --j;
                }
            }
        }
        cout<<r<<endl<<s<<endl;
    }


    t = clock() - t;
    

    cout << "time = " << (double)t/CLOCKS_PER_SEC;

}

