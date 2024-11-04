












































using namespace std;

namespace QoE_Library{

    namespace QL_Bare_Minimum{

        const double PI = 3.141592653589793238460;
        const long double E= 2.7182818284590452353;





        



        




        



        


        





        


        



        



        




        






        





        

        





        






        





        





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








        

        const long double pi=10000*acos(-1.0L);

        


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
            if (!b)
                return a;
            else 
                return gcd(b, a%b);
        }
        LD id10(int x1,int y1,int x2,int y2){

            return sqrt( (x1-x2)*(x1-x2)/1. + (y1-y2)*(y1-y2)/1. );
        }
    }
}



using namespace QoE_Library::QL_Bare_Minimum;




bool revCmp(int a, int b){
    return a > b;
}



int main(){

    clock_t t = clock();


    FILE *fIn = freopen("D:\\DUMP\\input.in", "r", stdin);
    FILE *fOut = freopen("D:\\DUMP\\output.out", "w", stdout);
    assert(fIn&&fOut);

    int n;
    string s;
    int T=1;
    

    while(T--){
        cin>>n>>s;
        int a[1001]={0},lastr=-1;
        a[0]=1;
        QL_FOR_DEF(i,s.length()){
            if(a[i]==8)
                int d=0;
            if(s[i]=='='){
                a[i+1]=a[i];
            }
            else if(s[i]=='L'){
                
                a[i+1]=min(1,a[i]-1);
            }
            else if(s[i]=='R'){
                
                a[i+1]=a[i]+1;
                

                lastr=i+1;
            }
            bool fit=0;
            if(a[i+1]<1){
                a[i+1]=1;
                int j=i;
                while(j>=0&&!fit){
                    if('L'==s[j]){
                        if(a[j]>a[j+1])fit=1;
                        else a[j]=a[j+1]+1;
                    }else if('R'==s[j]){
                        if(a[j]<a[j+1])fit=1;
                        else{
                            a[j+1]=a[j]+1;
                            

                            i=j;
                        }
                    }else{
                        if(a[j]==a[j+1])fit=1;
                        else a[j]=a[j+1];
                    }
                    --j;
                }
            }
        }

        
        int en;
        

        en=lastr;
        while(en+1<n&&s[en+1]=='=')++en;

        if(a[i+1]<1){
            int j=i+1;
            

            while(j&&j>en){
                ++a[j--];
            }
            
            int tmp=a[j+1];
            while(j&&j>=lastr)
                a[j--]=tmp+1;

            if(j&&'R'==s[j-1]&&a[j]<=a[j+1]){
                if('L'==s[j])
                    a[j]=1+a[j+1];
                else if('='==s[j])
                    a[j]=a[j+1];
            }


        }
    }

    

    QL_FOR_DEF(i,s.length()+1){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


t = clock() - t;


cout << "time = " << (double)t/CLOCKS_PER_SEC;

}

