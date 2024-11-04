












































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

        template <typename T1> class id8{
        public:
            T1 x,y,z;
            id8(T1 x1,T1 y1,T1 z1):x(x1),y(y1),z(z1){
            }
            id8(){}
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
        inline void id9(int &a,int &b){
            a=inpI();
            b=inpI();
        }
        inline void id10(int &a,int &b,int &c){
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
        inline void id5(int a) {
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
        inline void id0(int a,int b){
            printf("%d ",a);
            id5(b);
        }
        inline int id4(char *s){
            return printf("%s\n",s);
        }
        
        template<typename T1> void QL_swap(T1 &x, T1 &y){
            
            T1 tmp;
            tmp=x;
            x=y;
            y=tmp;
        }


        


        void id1(char *a,char *b){
            char tmp=*a;
            *a=*b;
            *b=tmp;
        }


        
        
        template<typename T1> T1 gcd(T1 a, T1 b) {
            if (!b)return a;
            return gcd(b, a%b);
        }
        LLI id3(LLI x1,LLI y1,LLI x2,LLI y2){

            return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        }
        template<typename T> LD id6(T x1,T y1,T x2,T y2){
            return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        }
        

        template<typename T1> T1 dotProd(T1 x1,T1 y1,T1 z1,T1 x2,T1 y2,T1 z2){
            return x1*x2+y1*y2+z1*z2;
        }
        

        template<typename T1> id8<T1> crossProd(id8<T1> v1, id8<T1> v2){
            id8<T1> v;
            v.x=v1.y*v2.z - v2.y*v1.z;
            v.y=v1.z*v2.x - v2.z*v1.x;
            v.z=v1.x*v2.y - v2.x*v1.y;
            return v;
        }
    }
}




using namespace QoE_Library::QL_Bare_Minimum;







LD id2(LD x,LD y){
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

inline bool isLeft(Point& a,Point& b,Point& c){
    return ( (LLI)(b.x - a.x)*(LLI)(c.y - a.y) - (LLI)(b.y - a.y)*(LLI)(c.x - a.x)) > 0LL;
}

int below[505][505];


int rx[505],ry[505],bx[505],by[505];
int main(){

    clock_t t = clock();



    FILE *fIn = freopen("G:\\DUMP\\input.in", "r", stdin);
    

    

    



    

    int n,m,t;
    

    cin>>n>>m;
    id7(i,n){
        

        cin>>rx[i]>>ry[i];
        

        

    }
    id7(i,m){
        cin>>bx[i]>>by[i];
        

        

    }

    

    id7(i,n){
        QL_FOR(j,i+1,n,1){
            int id1,id2;
            Point mdpt;

            

            if(rx[i]==rx[j])continue;
            


            if(rx[i]<rx[j])id1=i,id2=j;
            else id1=j,id2=i;



            mdpt.x=rx[i];
            mdpt.y=ry[i]-1;

            id7(k,m){
                

                
                

                if(!isLeft(rx[id1],ry[id1],rx[id2],ry[id2],bx[k],by[k]) && rx[id1]<bx[k]&&bx[k]<=rx[id2])++below[id1][id2],++below[id2][id1];
            }
        }
    }
    int tot=0;
    id7(i,n){
        QL_FOR(j,i+1,n,1){
            QL_FOR(k,j+1,n,1){
                

                



                

                int lst[]={i,j,k};
                int net=0;

                

                Point cent;


                cent.x=(r[i].x+r[j].x+r[k].x)/3;
                cent.y=(r[i].y+r[j].y+r[k].y)/3;

                id7(p,3){
                    QL_FOR(q,p+1,3,1){
                        Point mdpt;

                        mdpt.x=(r[lst[p]].x+r[lst[q]].x)/2;
                        mdpt.y=(r[lst[p]].y+r[lst[q]].y)/2;
                        --mdpt.y;

                        int o=-1;
                        while(o++<2)if(o!=p&&o!=q)break;
                        cent.x=r[lst[o]].x;
                        cent.y=r[lst[o]].y;

                        mdpt.x=r[lst[p]].x;
                        mdpt.y=r[lst[p]].y-1;

                        int id1,id2;
                        if(r[lst[p]].x<=r[lst[q]].x)id1=p,id2=q;
                        else id1=q,id2=p;
                        if(isLeft(r[lst[p]],r[lst[q]],mdpt)==isLeft(r[lst[p]],r[lst[q]],cent))net+=below[lst[id1]][lst[id2]];
                        else net-=below[lst[id1]][lst[id2]];
                    }
                }


                
                int minid=i,maxid=j,remain=k;
                id7(p,3){
                    if(rx[lst[p]]<rx[minid])minid=lst[p];
                    if(rx[lst[p]]>rx[maxid])maxid=lst[p];
                }
                id7(p,3){
                    if(lst[p]==minid || lst[p]==maxid)continue;
                    remain=lst[p];
                }
                net=below[remain][minid]+below[remain][maxid]-below[minid][maxid];
                if(!net)++tot;
            }
        }
    }
    cout<<tot<<endl;

    


    multimap<LD,Point>::iterator it,it2,it3,it4;
    int tot=0;
    

    for(it=mp.begin();it!=mp.end();++it){
        

        if(it->second.c)continue;
        for(it2=it;it2!=mp.end();++it2){

        }
    }




    t = clock() - t;
    

    cout << "time = " << (double)t/CLOCKS_PER_SEC;

}

