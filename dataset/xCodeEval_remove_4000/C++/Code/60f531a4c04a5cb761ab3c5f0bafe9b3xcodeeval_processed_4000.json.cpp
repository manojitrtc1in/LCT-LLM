












































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
        inline void id4(int &a,int &b){
            a=inpI();
            b=inpI();
        }
        inline void id5(int &a,int &b,int &c){
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

        inline void id8(double N) {
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
        inline void id6(int a) {
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
            id6(b);
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


        


        void id7(char *a,char *b){
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












using namespace std;
int mod = 1000000007;

int f[60][60], n;
int color[100];

bool dfs(int v)
{
    color[v] = 1;
    for(int i = 0; i < n; i++)
        if(f[v][i])
        {
            if(color[i] == 1) return true;
            if(color[i] == 0)
            {
                if(dfs(i)) return true;
            }
        }
        color[v] = 2;
        return false;
}

int main()
{
    

    int i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            f[i][j] = 0;

    for(i = 0; i < n * (n - 1) / 2 - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        f[a][b] = 1;
    }
    bool fl = false;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            if(i!= j && f[i][j] == 0 && f[j][i] == 0)
            {
                fl = true;
                break;
            }
            if(fl) break;
    }
    int v = i, u = j;
    for(i = 0; i < n; i++) color[i] = 0;
    f[v][u] = 1;
    fl = false;
    for(i = 0; i < n; i++)
        if(color[i] == 0)
        {
            if(dfs(i)) 
            {
                fl = true;
                break;
            }
        }
        if(fl) swap(v,u);
        printf("%d %d", v + 1, u + 1);
        

        return 0;
}




int main(){

    clock_t t = clock();



    FILE *fIn = freopen("G:\\DUMP\\input.in", "r", stdin);
    

    FILE *fLog = freopen("G:\\DUMP\\log.log", "w", stderr);
    


    int n;
    string s[2];
    cin>>s[0]>>s[1]>>n;

    
    int W[26][26];
    id9(i,26){
        id9(j,26){
            W[i][j]=INT_MAX/1000;
        }
    }
    int l=SZ(s[0]);
    if(l!=SZ(s[1])){
        cout<<-1<<endl;
        return 0;
    }
    while(n--){
        char c,d;
        int t;
        cin>>c>>d>>t;
        c-='a',d-='a';
        

        W[c][d]=min(W[c][d],t);
    }

    id9(k,26){
        id9(i,26){
            id9(j,26){
                W[i][j]=min(W[i][j],W[i][k]+W[k][j]);
            }
        }
    }
    int r=0;
    bool f=1;
    id9(i,l){
        if(s[0][i]!=s[1][i]){
            int p=INT_MAX/1000;
            char c;
            id9(j,2){
                if(p>W[s[j][i]-'a'][s[1-j][i]-'a']){
                    p=W[s[j][i]-'a'][s[1-j][i]-'a'];
                    c=s[1-j][i];
                }
            }

            id9(h,26){
                int x=W[s[0][i]-'a'][h] + W[s[1][i]-'a'][h];
                if(p>x){
                    p=x;
                    c=h+'a';
                }
            }

            if(p!=INT_MAX/1000){
                r+=p;
                s[0][i]=s[1][i]=c;
            }
            else{
                f=0;
                break;
            }
        }
    }

    


    multimap<pair<char,char>,int > m;

    while(n--){
        char c,d;
        int t;
        cin>>c>>d>>t;
        M_Ins(m,MKP(c,d),t);
    }
    int l=SZ(s[0]);
    if(l!=SZ(s[1])){
        cout<<-1<<endl;
        return 0;
    }
    int cn=0;
    id9(i,l){
        if(s[0][i]!=s[1][i])++cn;
    }
    int r=0;
    bool f=1;
    id9(j,l){
        if(!cn)break;
        int v=INT_MAX;
        char c;

        multimap<pair<char,char>,int >::iterator it,it2;
        if(s[0][j]!=s[1][j]){
            

            id9(i,2){
                it=m.find(MKP(s[i][j],s[1-i][j]));
                if(it!= m.end()){
                    if(v>it->second)v=it->second,c=s[1-i][j];
                }
            }
            

            id9(h,26){
                it=m.find(MKP(s[0][j],'a'+h) );
                it2=m.find(MKP(s[1][j],'a'+h)); 
                if(it!=m.end() && it2!=m.end()){
                    if(v>it->second+it2->second)v=it->second+it2->second,c='a'+h;
                }
            }
            if(v==INT_MAX){
                f=0;break;
            }
            r+=v;
            s[0][j]=s[1][j]=c;
            --cn;
        }
    }

    


    for(multimap<int,pair<char,char> >::iterator it=m.begin();it!=m.end();++it){
        if(!cn)break;

        id9(j,l){
            id9(i,2){
                if(s[i][j]!=s[1-i][j] && s[i][j]==it->second.first && s[1-i][j]==it->second.second){
                    r+=it->first;
                    s[i][j]=it->second.second;
                    --cn;
                }
            }
        }
    }

    if(f)cout<<r<<endl<<s[0];
    else cout<<-1<<endl;

    t = clock() - t;
    

    cout << "time = " << (double)t/CLOCKS_PER_SEC;

}



