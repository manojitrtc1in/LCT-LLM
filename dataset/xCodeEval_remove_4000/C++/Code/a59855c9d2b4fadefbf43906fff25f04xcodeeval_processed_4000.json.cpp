










 
using namespace std;
 
typedef long long ll;












 


 
int main()  
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
int n,i,j;
cin>>n;
string a;
cin>>a;
rep(i,(n/2))
{
    for(j=n/2;j<n;j++)
    {
        if(a[i]=='L' && a[j]=='R')
            {
                cout<<i+1<<" "<<j+1<<"\n";
                a[i]='D';a[j]='D';
                break;
            }
        else if(a[i]=='L' && a[j]=='L')
            {
                cout<<i+1<<" "<<j+1<<"\n";
                 a[i]='D';a[j]='D';
                break;
            }
            else if(a[i]=='R' && a[j]=='R')
            {
                cout<<i+1<<" "<<j+1<<"\n";
                 a[i]='D';a[j]='D';
                break;
            }
        else if (a[i]=='R' && a[j]=='L')
           {
            cout<<j+1<<" "<<i+1<<"\n";
             a[i]='D';a[j]='D';
            break;
           }
    }
}
return 0;
}   