










































using namespace __gnu_pbds; 

using namespace  std ;

typedef vector<int>vi ;
typedef vector<int>vll ;
typedef vector<vector<int> >vvl ;
typedef pair<int,int> pll ;
typedef vector<pll>vpll ;
typedef vector<string>vstr;
typedef vector<bool>vbool ;
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T = int>
void readArray(vector<T> &v, int n){T a ;for(int i=0 ; i<n ; i=i+1){cin>>a ;v.push_back(a);}}
template <class T = int>
void printArray(vector<T> &v , int a = 0){for(int i=a ; i<v.size() ; i=i+1){cout<<v[i]<<" " ;}cout<<endl ;}

const int mod  = 1000000007;




int id1(string str1 , int x = 0){int a,b;b = sz(str1);a = 0;int c = 1;reverse(all(str1));for(int i=0 ; i<b ; i++){a+=(str1[i]-'0')*c;c*=10;if(x){c%=mod;a%=mod;}}return(a);}
string id0(int x){string str1 = "";while(x){int c = x%10;str1+=(c+'0');x/=10;}reverse(all(str1));return(str1);}
double logy(int n , int b){if(b==0){return(-1);}if(n==1){return(0);}return((double)log10(n)/(double)log10(b));}
long long power(long long k , long long n , long long m=mod){long long res = 1;while(n){if(n%2!=0){res = (res*k)%m ;}k = (k*k)%m ;n = n/2 ;}return(res) ;}
double powerD(double k , long long n ){double res = 1;while(n){if(n%2!=0){res = (res*k) ;}k = (k*k) ;n = n/2 ;}return(res) ;}
int id2(int a , int b , int &x , int &y){if(a==0){x = 0;y = 1;return(b);}int x1,y1;int g = id2(b%a,a,x1,y1);x = y1 - (b/a)*x1;y = x1;return(g);}
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) {return((a/gcd(a,b))*b);}
void coordinateCompress(vll &v){vll v1 = v;distinct(v1);for(auto &j : v){j = upperB(all(v1),j) - v1.begin();}}
double distance(pair<double,double> a , pair<double,double> b){return((double)(sqrt( ((a.first-b.first)*(a.first-b.first)) + ((a.second-b.second)*(a.second-b.second)))));}
const int ddx[8] = {-1,1,0,0,-1,1,-1,1};
const int ddy[8] = {0,0,-1,1,-1,-1,1,1};
const int N = 300003;  

const int M = 300003;  

const int inf = 1e9;
const int minf = -1e9-5;
int n,m,k,a1,a2,a3,h,t;


string str,str1,str2;
bool ok = true;
int askQuery(vll &tmp)
{
    wr1("?");
    printArray(tmp);
    int a;
    cin>>a;
    return(a);
}
void solveIt()
{
    

    

    int a,b,c,d,i,j,x,y,z,tt;
    double p,q,r,w;
    

    char ch;
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    cin>>n>>k;
    if(n%k==0)
    {
        i = 1;
        j = n/k;
        x = 0;
        while(j--)
        {
            vll tmp;
            p = k;
            while(p--)
            {
                tmp.pb(i);
                i++;
            }
            x^=askQuery(tmp);
        }
        wr2("!",x);
        return;
    }
    if(k%2==0)
    {
        if(n%2)
        {
            wr1("-1");
            return;
        }
    }
    i = 1;
    c = 0;
    x = 0;
    while(i<=n)
    {
        int c1 =  n - i + 1;
        if(c1%2==0 && (k-c1/2)<=(n-c1) && c1/2<=k)
        {
            

            

            

            

            j = 1;
            while(j<i)
            {
                vll tmp;
                for(int p = j ; p<j+k ; p++)
                {
                    tmp.pb(p);
                }
                x^=askQuery(tmp);
                j+=k;
            }
            vll tmp[2];
            c1/=2;
            for(j=i ; j<i+c1 ; j++)
            {
                tmp[0].pb(j);
                tmp[1].pb(j+c1);
            }
            for(j=1 ; j<=n ; j++)
            {
                if(sz(tmp[0])<k)
                {
                    tmp[0].pb(j);
                    tmp[1].pb(j);
                }
                else
                {
                    break;
                }
            }
            x^=askQuery(tmp[0])^askQuery(tmp[1]);
            wr2("!",x);
            return;
        }
        if(i+k-1>n)
        {
            break;
        }
        i+=k;
    }
    

    y = k - (n-i+1);
    z = y/2;
    if(3*z<i)
    {
        

        i = 1;
        x = 0;
        c = 0;
        while(true)
        {
            if(i+k-1>n)
            {
                break;
            }
            vll tmp;
            p = k;
            while(sz(tmp)<k)
            {
                tmp.pb(i);
                i++;
            }
            x^=askQuery(tmp);
        }
        vll tmp[3];
        p = i - 1;
        while(i<=n)
        {
            tmp[0].pb(i);
            tmp[1].pb(i);
            tmp[2].pb(i);
            i++;
        }
        i = 1;
        while(sz(tmp[0])<k)
        {
            tmp[0].pb(i);
            tmp[1].pb(i);
            tmp[2].pb(i);
            i++;
        }
        j = k - y;
        a3 = i;
        while(z--)
        {
            tmp[1][j] = tmp[2][j] = i;
            j++;
            i++;
        }
        i = 1;
        while(j<k)
        {
            tmp[2][j] = i;
            i++;
            j++;
        }
        vll val(3);
        for(i=0 ; i<3 ; i++)
        {
            val[i] = askQuery(tmp[i]);
        }
        y = val[0]^val[1];
        z = val[0]^val[2];
        y^=z;
        y^=val[0];
        x^=y;

        wr2("!",x);
        return;
    }
    

    

    

    

    

    

    

    

    

    

    

    i = 1;
    j = n;
    x = 0;
    z = n%k;
    

    while(i<j)
    {
        y = j-i+1;
        z = min(z,y/2);
        vll tmp,gmp;
        for(int p = i ; p<i+z ; p++)
        {
            tmp.pb(p);
        }
        for(int p = j ; p>j-z ; p--)
        {
            gmp.pb(p);
        }
        for(int p = 1 ; p<=n ; p++)
        {
            if((p>=i && p<i+z) || (p>j-z && p<=j))
            {
                continue;
            }
            if(sz(tmp)<k)
            {
                tmp.pb(p);
                gmp.pb(p);
            }
            else
            {
                break;
            }
        }
        x^=askQuery(tmp)^askQuery(gmp);
        i+=z;
        j-=z;
    }
    wr2("!",x);
}
int32_t main()
{
    

    

    

    

    

    FastIO;
    PRECISION(12);
    

    

    

    

    int t = 1;
    

    while(t--)
    {
        solveIt();
    }
    

    

    

    

    

    

    


}
