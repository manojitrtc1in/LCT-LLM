

using namespace std;











typedef long long int LL ;
typedef unsigned long long int uLL ;

const int    MOD = 1e9+7;
const int    N   = 100000+5;
const double eps = 1e-6;
const double PI  = acos(-1.0);



int main()
{
    int n,k,g,b;
    cin>>n>>k>>g>>b;
    string s="";
    int leng=0,lenb=0;

    for(int i=1; i<=n; i++)
    {
        if(leng==k||lenb==k)
        {
            if(s[s.length()-1]=='G')
            {
                s+='B';
                leng = 0,lenb = 1,b--;
            }
            else {
                s+='G';
                leng = 1,lenb = 0,g--;
            }
            continue;
        }
        if(g>b){
            s+='G';
            leng++;
            g--;
        }
        else {
            s+='B';
            lenb++;
            b--;
        }
    }
    if (b<0||g<0) cout<<"NO";
    else cout<<s<<endl;
    return 0;
}







