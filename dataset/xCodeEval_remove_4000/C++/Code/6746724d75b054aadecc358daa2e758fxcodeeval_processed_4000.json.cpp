

using namespace std;








const int MOD = 1e9+7;
const int M = 1e5+10;

map<LL,int>b;


void solve(int x)
{
    while(x)
    {
        if(x&1) printf("1");
        else    printf("0");
        x>>=1;
    }
    puts("");
    return ;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    while(cin>>t)
    {
        b.clear();
        LL tem ,x,a,bit;
        char c;
        for(int i=0;i<t;i++)
        {
            cin>>c>>a;
            tem = a,x = 0,bit=0;
            while(tem)
            {
                if(tem%10%2)    x  |=  (1<<bit);
                tem/=10;
                bit++;
                

                

            }
          

          

            {
                if(c=='+') b[x]++;
                if(c=='-') b[x]--;
            }
            if(c=='?') cout<<b[x]<<endl;
        }
    }
    return 0;
}
