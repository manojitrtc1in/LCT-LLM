





using namespace std;

















































    for (typeof(container.begin()) it = container.begin(); it != container.end(); it++) 



































enum {WHITE,GREY,BLACK};





        cin.tie();







typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<char> VC;
typedef vector<VC> VC2D;
typedef map<int,int> MPII;
typedef map<string,int> MPSI;
typedef map<int,string> MPIS;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef queue<int> QI;
typedef queue<QI> QII;
typedef stack<int> SI;
typedef stack<SI> SII;

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;






struct POINT{
    int x,y;
    POINT(){}
    POINT(int a,int b){x=a,y=b;}
    bool operator==(const POINT &a)const{return x==a.x and y==a.y;}
};



struct POINT_DOUBLE{
    double x,y;
    POINT_DOUBLE(){}
    POINT_DOUBLE(double a,double b){x=a,y=b;}
};



struct Node{
    int v,w;
    Node() {}
    bool operator<(const Node &a)const{return w>a.w;}
    Node(int _v,int _w){v=_v,w=_w;}
};

namespace MyTemplates{
    template<class T>T gcd(T a,T b){return b == 0 ? a : gcd(b, a % b);}

    template<typename T>T lcm(T a, T b) {return a / gcd(a,b) * b;}

    template<class T>T big_mod(T n,T p,T m){if(p==0)return (T)1;T x=big_mod(n,p/2,m);x=(x*x)%m;if(p&1)x=(x*n)%m;return x;}

    template<class T>T multiplication(T n,T p,T m){if(p==0)return (T)0;T x=multiplication(n,p/2,m);x=(x+x)%m;if(p&1)x=(x+n)%m;return x;}

    template<class T>T my_pow(T n,T p){if(p==0)return 1;T x=my_pow(n,p/2);x=(x*x);if(p&1)x=(x*n);return x;} 


    template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}


    template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}


    template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}


    template<class T> inline T Mod(T n,T m) {return (n%m+m)%m;} 


    template<class T> T MIN3(T a,T b,T c) {return min(a,min(b,c));} 


    template<class T> T MAX3(T a,T b,T c) {return max(a,max(b,c));} 


    template <class T> void print_vector(T &v){int sz=v.size();if(sz)cout<<v[0];for(int i = 1; i < sz; i++)cout << ' '<<v[i];cout<<"\n";}


    bool id0(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}

    bool id1(char ch){if (isalpha(ch) && !id0(ch)) return true; return false;}
}

namespace debug{
    int sum(){return 0;}
    template<typename T,typename... Args> T sum(T a,Args... args) {return a+sum(args...);}
    void print(){cout<<"\n";return;}template<typename T, typename... Args>void print(T a,Args... args){cout<<a<<" ";print(args...);}
}




    

    

    

    




class Solution{
public:
    void solve(istream& in, ostream& out);
};

void Solution :: solve(istream& cin, ostream& cout){
    int n;
    cin >> n;
    cout << n-- << " ";
    FOR(i,1,n+1,1) cout << i << " ";
    cout << endl;
}


int main(){
    

    

    Solution solution;
    std::istream& cin(std::cin);
    std::ostream& cout(std::cout);
    solution.solve(cin,cout);
    

    

    return 0;
}






















