

using namespace std;











typedef long long int LL ;
typedef unsigned long long int uLL ;

const int    MOD = 1e9+7;
const int    N   = 100000+5;
const double eps = 1e-6;
const double PI  = acos(-1.0);



int main()
{
    string str = "123456";
    int n,k,g,b;
    cin>>n>>k>>g>>b;
    string s="";
    int curg=0,curb=0;

    for(int i=1; i<=n; i++)
    {
        if (curg==k||curb==k)
        {
            if (s[s.length()-1]=='G')
            {
                s+='B';
                curg=0;
                b--;
                curb=1;
            }
            else
            {
                s+='G';
                curb=0;
                curg=1;
                g--;
            }
            continue;
        }
        if (g>b)
        {
            s+='G';
            curg++;
            g--;
        }
        else
        {
            s+='B';
            b--;
            curb++;
        }
    }
    if (b<0||g<0) cout<<"NO";
    else cout<<s<<endl;
    return 0;
}







