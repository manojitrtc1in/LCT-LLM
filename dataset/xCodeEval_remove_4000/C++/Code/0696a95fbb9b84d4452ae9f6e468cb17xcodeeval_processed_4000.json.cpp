












































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
        inline void id5(int &a,int &b){
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

        inline void id10(double N) {
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
        inline void id2(int a,int b){
            printf("%d ",a);
            id7(b);
        }
        inline int id3(char *s){
            return printf("%s\n",s);
        }
        
        template<typename T1> void QL_swap(T1 &x, T1 &y){
            
            T1 tmp;
            tmp=x;
            x=y;
            y=tmp;
        }


        


        void id8(char *a,char *b){
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
        template<typename T> LD id9(T x1,T y1,T x2,T y2){
            return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
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






int id4(V_S &v,int i,int j){
    int r=0;
    if( in_bounds(i,j,SZ(v),SZ(v[0])) && '1'==v[i][j]){
        ++r;
        v[i][j]='2';
        id11(k,8){
            r+=id4(v,i+DY8[k],j+DX8[k]);
        }
    }
    return r;
}
bool checkSides(V_S &v,int i,int j,int a,int id1,int id2){
    bool f=1;
    id11(k,a){
    

        int R=SZ(v);
        int C=SZ(v[0]);

        bool in1=in_bounds(i+k*DY8[id1],j+k*DX8[id1],R,C);
        bool in2=in_bounds(i+k*DY8[id2],j+k*DX8[id2],R,C);
        
        if( !in1||!in2 || '2'!=v[i+k*DY8[id1]][j+k*DX8[id1]] || '2'!=v[i+k*DY8[id2]][j+k*DX8[id2]] ){
        

            f=0;
            break;
        }
    }
    return f;
}

int main(){

    clock_t t = clock();



    FILE *fIn = freopen("G:\\DUMP\\input.in", "r", stdin);
    

    

    



    

    int t;
    cin>>t;
    int num=0;
    while(num++<t){
        if(35==num)
            int d=0;
        int n,m,tot=0;
        cin>>n>>m;
        V_S v;
        string s;
        id11(i,n){
            cin>>s;

            PB(v,s);
        }
        id11(i,n){
            id11(j,m){
                if('1'==v[i][j]){

                    

                    int r=id4(v,i,j);

                    if(5==i&&3==j)
                        int d=0;

                    

                    if(r%4 || r/4>250 || r<4)continue;

                    

                    int len=r/4+1;
                    if(6==i&&6==j)
                        int d=0;
                    tot+=checkSides(v,i,j,len,4,6)&&checkSides(v,i+r/4,j+r/4,len,1,3);          
                    tot+=checkSides(v,i,j,len,2,7)&&checkSides(v,i+2*len-2,j,len,0,5);
                }
            }
        }
        cout<<tot<<endl;
    }


    t = clock() - t;
    

    cout << "time = " << (double)t/CLOCKS_PER_SEC;

}

