












































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

        inline void id12(double N) {
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



    

    map<string,int> m0;
    map<string,int> m1;
    map<string,int> m2;

    int n,nc;
    cin>>n;
    nc=n;
    string s;
    while(nc--){
        cin>>s;
    }
    nc=n;
    int i=0;

    while( i++ < (n*(n-1))/2 ){
        string s[2];


        getline(cin,s[0],'-');

        getline(cin,s[1],' ');

        getline(cin,s[2],':');
        

        getline(cin,s[3]);

        char c;
        int g1;

        int g2;


        

        cin>>s[0]>>g1>>c>>g2;

        int idx=s[0].find_first_of('-');
        s[1]=s[0].substr(idx+1);
        s[0].erase(idx);

        

        if(m2.find(s[0])==m2.end()){
            M_Ins(m2,s[0],g1);
            

        }else m2[s[0]]+=g1;
        if(m2.find(s[1])==m2.end()){
            M_Ins(m2,s[1],g2);
        }else m2[s[1]]+=g2;

        

        if(m1.find(s[1])==m1.end()){
            M_Ins(m1,s[1],g2-g1);
        }else m1[s[1]]+=g2-g1;

        

        if(m1.find(s[0])==m1.end()){
            M_Ins(m1,s[0],g1-g2);
        }else m1[s[0]]+=g1-g2;

        if(g1==g2){
            

            if(m0.find(s[0])==m0.end()){
                M_Ins(m0,s[0],1);
            }else m0[s[0]]+=1;
            if(m0.find(s[1])==m0.end()){
                M_Ins(m0,s[1],1);
            }else m0[s[1]]+=1;

        }else if(g1<g2){
            

            if(m0.find(s[1])==m0.end()){
                M_Ins(m0,s[1],3);
            }else m0[s[1]]+=3;


        }else{ 

            

            if(m0.find(s[0])==m0.end()){
                M_Ins(m0,s[0],3);
            }else m0[s[0]]+=3;
        }
    }
    int cnt=0;
    

    multimap<int,string,bool(*)(int,int)> rm0(revCmp);
    multimap<int,string,bool(*)(int,int)> rm1(revCmp);
    multimap<int,string,bool(*)(int,int)> rm2(revCmp);

    

    map<string,int>::iterator it1=m0.begin();
    int prevval=it1->second;

    for(;it1!=m0.end();++it1){
        M_Ins(rm0,it1->second,it1->first);
    }

    cnt=0;
    multimap<int,string,bool(*)(int,int)>::iterator it2=rm0.begin();
    prevval=it2->first;
    

    for(;it2!=rm0.end();++it2){
        if(cnt++<n/2 || prevval==it2->first)continue;

        string s=it2->second;
        

        m1.erase(m1.find(s));
        m2.erase(m2.find(s));
        

    }

    

    for(map<string,int>::iterator it=m1.begin();it!=m1.end();++it){
        M_Ins(rm1,it->second,it->first);
    }
    cnt=0;
    multimap<int,string,bool(*)(int,int)>::iterator it3=rm1.begin();
    prevval=it3->first;
    for(;it3!=rm1.end();++it3){
        if(cnt++<n/2 || prevval==it3->first)continue;

        string s=it3->second;

        

        m2.erase(m2.find(s));
    }

    

    for(map<string,int>::iterator it=m2.begin();it!=m2.end();++it){
        cout<<it->first<<endl;
    }



    t = clock() - t;
    

    cout << "time = " << (double)t/CLOCKS_PER_SEC;

}




int scores[3][50]={0};

bool id11(int ptr1,int ptr2){
    if(scores[0][ptr1]!=scores[0][ptr2])return scores[0][ptr1]>scores[0][ptr2];
    if(scores[1][ptr1]!=scores[1][ptr2])return scores[1][ptr1]>scores[1][ptr2];
    return scores[2][ptr1]>scores[2][ptr2];
}

int main(){

    clock_t t = clock();



    FILE *fIn = freopen("D:\\DUMP\\input.in", "r", stdin);
    FILE *fOut = freopen("D:\\DUMP\\output.out", "w", stdout);
    assert(fIn&&fOut);


    int n,nc;
    cin>>n;
    nc=n;
    string s;
    V_S v;
    while(nc--){
        cin>>s;
        PB(v,s);
    }
    int i=0;

    while( i++ < (n*(n-1))/2 ){
        string s[2];

        char c;
        int g1;
        int g2;

        

        cin>>s[0]>>g1>>c>>g2;

        int idx=s[0].find_first_of('-');
        s[1]=s[0].substr(idx+1);
        s[0].erase(idx);


        V_S::iterator ptr1=find(v.begin(),v.end(),s[0]);
        V_S::iterator ptr2=find(v.begin(),v.end(),s[1]);

        

        if(g1>g2)scores[0][ptr1-v.begin()]+=3;
        else if(g1<g2)scores[0][ptr2-v.begin()]+=3;
        else{
            scores[0][ptr1-v.begin()]+=1;
            scores[0][ptr2-v.begin()]+=1;
        }
        

        scores[1][ptr1-v.begin()]+=g1-g2;
        scores[1][ptr2-v.begin()]+=g2-g1;

        

        scores[2][ptr1-v.begin()]+=g1;
        scores[2][ptr2-v.begin()]+=g2;
    }

    int d=0;

    int index_sort[50];
    QL_FOR_DEF(i,n)index_sort[i]=i;
    sort(index_sort,index_sort+n,id11);

    V_S sortedNames;
    QL_FOR_DEF(i,n/2){
        PB(sortedNames,v[index_sort[i]]);
    }
    sort(sortedNames.begin(),sortedNames.end());

    QL_FOR_DEF(i,n/2){
        cout<<sortedNames[i]<<endl;
    }

        t = clock() - t;
        

        cout << "time = " << (double)t/CLOCKS_PER_SEC;

    }



