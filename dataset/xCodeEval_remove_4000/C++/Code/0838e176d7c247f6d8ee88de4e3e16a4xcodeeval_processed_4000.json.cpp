











































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

        inline int id9(LLI& lld){
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
        inline void id7(int &a,int &b,int &c){
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

        inline void id13(double N) {
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
        inline void id8(int a) {
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
            id8(b);
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


        


        void id10(char *a,char *b){
            char tmp=*a;
            *a=*b;
            *b=tmp;
        }


        
        
        template<typename T1> T1 gcd(T1 a, T1 b) {
            if (!b)return a;
            return gcd(b, a%b);
        }
        LD id11(int x1,int y1,int x2,int y2){

            return sqrt( (x1-x2)*(x1-x2)/1. + (y1-y2)*(y1-y2)/1. );
        }
    }
}




using namespace QoE_Library::QL_Bare_Minimum;










int id6(int *a,int m,int v){
    id14(i,m-v+1){
        if(!a[i]){
            int j=i;
            while(j<i+v){
                if(a[j])break;
                ++j;
            }
            if(j==i+v)return i;
            i=j;
        }
    }
    return -1;
}

void id12(int *a,int m,map<int,P_II> ls){
    id14(i,m){
        int j=i;
        while(j<m&&!a[j])++j;
        int free=j-i;
        int s=j;
        if(free){
            

            

            map<int,P_II>::iterator it;

            for(it=ls.begin();it!=ls.end();++it){
                if(it->second.first==j){
                    break;
                }
            }
            if(it!=ls.end()){
                int s1=it->second.first;
                int s2=it->second.second;
                QL_FOR(k,s1-free,s1,1)a[k]=1;
                QL_FOR(k,s2-free,s2,1)a[k]=0;
                it->second.first-=free;
                it->second.second-=free;
                

                i=it->second.first;
            }


            while(s<m&&a[s])++s;
            QL_FOR(k,j-free,j,1)a[k]=1;
            QL_FOR(k,s-free,s,1)a[k]=0;

        }else i=j;
    }
}


int main(){

    clock_t t = clock();



    FILE *fIn = freopen("D:\\DUMP\\input.in", "r", stdin);
    FILE *fOut = freopen("D:\\DUMP\\output.out", "w", stdout);
    FILE *fLog = freopen("D:\\DUMP\\log.log", "w", stderr);
    assert(fIn&&fOut&&fLog);

    int T=1;


    while (T--){
        LD n,a[100];
        LD x,y,vb,vs;
        cin>>n>>vb>>vs;
        id14(i,n)a[i]=inpI();
        cin>>x>>y;

        

        int *id=upper_bound(a+1,a+n,x);
        if(id-a>1)--id;
        if(id-a!=n-1){
            LD t1=((x-*id)*(x-*id) + y*y)/vs;
            LD t2=((x-*(id+1))*(x-*(id+1)) + y*y) +(*(id+1)-*id)/vb;
            if(t1>t2)++id;
        }
        cout<<id-a+1<<endl;

        LD dist=10e15;
        int id=2;
        QL_FOR(i,1,n,1){
            LD t1=sqrt((x-a[i])*(x-a[i]) + y*y)/vs + (a[i]-a[0])/vb;
            if(t1<=dist){
                id=i;
                dist=t1;
            }
        }
        cout<<id+1<<endl;
    }

    t = clock() - t;
    

    cout << "time = " << (double)t/CLOCKS_PER_SEC;

}

