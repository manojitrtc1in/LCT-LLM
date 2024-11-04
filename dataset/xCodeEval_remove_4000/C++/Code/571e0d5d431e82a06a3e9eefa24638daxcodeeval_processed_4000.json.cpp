
using namespace std;

int i,t,T,k,j;
long long n,m,x,d;
string s;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--)
    {
        d=0;
        cin>>n>>k>>s;
        for(j=n-1;j>=0;j--) if (s[j]=='*')
        {
            d++;
            break;
        }
        for(i=0;i<j;i++) if (s[i]=='*')
        {
            d++;
            break;
        }
        if (i==j)
        {
            cout<<d<<'\n';
            continue;
        }
        while(j-i-1>=k)
        {
            i+=k;
            while(s[i]=='.') i--;
            if (s[i]=='*') d++;
            if (j-i-1<k) break;
            j-=k;
            while(s[j]=='.') j++;
            if (s[j]=='*') d++;
        }
        cout<<d<<'\n';
    }
    

    return 0;
}
