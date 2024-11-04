












































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

        template <typename T1> class id0{
        public:
            T1 x,y,z;
            id0(T1 x1,T1 y1,T1 z1):x(x1),y(y1),z(z1){
            }
            id0(){}
        };





        




        





        



        


        





        


        



        



        




        






        





        

        





        






        









        











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
        inline void id8(int &a,int &b){
            a=inpI();
            b=inpI();
        }
        inline void id11(int &a,int &b,int &c){
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

        inline void id14(double N) {
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
        inline void id12(int a) {
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
        inline void id5(int a,int b){
            printf("%d ",a);
            id12(b);
        }
        inline int id6(char *s){
            return printf("%s\n",s);
        }
        
        template<typename T1> void QL_swap(T1 &x, T1 &y){
            
            T1 tmp;
            tmp=x;
            x=y;
            y=tmp;
        }


        


        void id13(char *a,char *b){
            char tmp=*a;
            *a=*b;
            *b=tmp;
        }


        
        
        template<typename T1> T1 gcd(T1 a, T1 b) {
            if (!b)return a;
            return gcd(b, a%b);
        }
        LLI id1(LLI x1,LLI y1,LLI x2,LLI y2){

            return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        }
        

        template<typename T1> T1 dotProd(T1 x1,T1 y1,T1 z1,T1 x2,T1 y2,T1 z2){
            return x1*x2+y1*y2+z1*z2;
        }
        

        template<typename T1> id0<T1> crossProd(id0<T1> v1, id0<T1> v2){
            id0<T1> v;
            v.x=v1.y*v2.z - v2.y*v1.z;
            v.y=v1.z*v2.x - v2.z*v1.x;
            v.z=v1.x*v2.y - v2.x*v1.y;
            return v;
        }
    }
}




using namespace QoE_Library::QL_Bare_Minimum;








bool id9(char* first, char* second, int base = 10){
    int length[] = {strlen(first), strlen(second)};
    int i = 0, j, n, carry = 0;
    while ( '\0' != first[i] && '\0' != second[i] ){
        n = first[i]-'0' + second[i]-'0' + carry;
        carry = n/base;
        if ( 0 < carry )
            n-= carry*base;
        first[i] = char(n + '0');
        ++i;
    }

    
    while (i < length[1] && second[i] != '\0'){
        n = second[i]-'0' + carry;
        carry = n/base;
        

        first[i] = char(n - carry*base + '0');
        ++i;
    }
    while (i < length[0] && first[i] != '\0'){
        n = first[i]-'0' + carry;
        carry = n/base;
        

        first[i] = char(n - carry*base + '0');
        ++i;
    }
    if ( 0 < carry ){
        first[i++] = char(carry + '0');
    }
    first[i] = '\0';

    return true;
}



int id7(int N, int id4, int* primesList){

    int *sieve = new int[N+1]();
    sieve[0] = -1;
    sieve[1] = -1;

    int id3 = 0;

    QL_FOR(i, 2, N, 1){
        if (-1 == sieve[i])
            continue;

        QL_FOR(j, 2*i, N, i)
            if (sieve[j] != -1)
                sieve[j] = -1;
    }
    id15(k, N){
        if ( -1 != sieve[k] ){
            primesList[id3] = k;
            id3++;

            if (id3 >= id4)
                break;
        }
    }
    delete sieve;

    return id3;
}

int computeFactors(ULLI n, int* primesList, int id3, map<ULLI,int>& factors, int id10 = INT_MAX){

    int id2 = 0;
    int i = 0, j = -1;
    ULLI sqrtN = sqrt(n+1.);
    

    while ( i < id3 && primesList[i] <= sqrtN){
        if ( 0 == n%primesList[i]){
            

            if ( factors.end() == factors.find(primesList[i]) ){
                factors.insert(make_pair(primesList[i], 0) );
                ++id2; 
            }
        }

        while ( 0 == n%primesList[i]){
            n /= primesList[i];

            ++factors[primesList[i]];
        }
        if (id2 >= id10)
            return id2;

        

        if(1==n)break;
        ++i;
    }

    

    if (n >= primesList[i]){
        factors.insert(make_pair(n, 1) );
        ++id2;
    }

    
    if ( INT_MAX != id10 )
        return factors.size();

    int numFactors = 1;
    

    for (map<ULLI, int>::const_reverse_iterator it = factors.rbegin(); it != factors.rend(); ++it ){
        numFactors *= it->second+1;
    }
    return numFactors;
}
bool checkDist(int j,int k){
    int c=0;
    while(j){
        if(j%10!=k%10)++c;
        j/=10,k/=10;
    }
    if(c<2)return 1;
    return 0;
}
int main(){

    clock_t t = clock();



    FILE *fIn = freopen("G:\\DUMP\\input.in", "r", stdin);
    

    

    


    int n,i=0;
    cin>>n;
    V_I vi;
    PB(vi,1000);
    while(i++<n){
        int t;
        cin>>t;
        PB(vi,t);
    }
    bool  f=1;

    id15(i,SZ(v)){
        id15(j,4){
            if(in[j]==v[i][j]){
                if(v[i]<in){
                    if(in[j]<'9'){
                        v[i][j]+=1;
                    }else f=0;
                    break;
                }
            }else if(in[j]<v[i][j]){
                char t=v[i][j];
                v[i][j]=in[j];
                if(v[i]<in){
                    v[i][j]+=1;
                    break;
                }
            }else if(in[j]>v[i][j]){
                if(v[i]<in){
                    v[i][j]+=1;
                    break;
                }
            }
        }
        in=v[i];
        if(v[i]<st||v[i]>en){
            f=0;
            break;
        }
    }


    QL_FOR(i,1,SZ(vi),1){
        QL_FOR(j,vi[i-1],2012,1){
            if( (j<vi[i] || vi[i-1]>vi[i] || !in_range(vi[i],1000,2011) ) &&checkDist(j,vi[i])){
                vi[i]=j;
                break;
            }
        }
        if(vi[i]<1000||vi[i]>2011||vi[i]<vi[i-1]){
            f=0;
            break;
        }
    }
    if(!f)cout<<"No solution"<<endl;
    else{
        QL_FOR(i,1,SZ(vi),1){
            cout<<vi[i]<<endl;
        }
    }

    t = clock() - t;
    

    cout << "time = " << (double)t/CLOCKS_PER_SEC;

}


