

#include<iostream>








 
using namespace std;
 
typedef long long ll;
#define F first
#define S second
#define rep(i,n) for(i=0;i<n;i++)
#define srt(i) sort(i.begin(),i.end())
#define vct(i,n) vector<ll> i(n)
#define vctp(i,n) vector < pair<ll,ll> > i(n);
#define arrp(i,n) pair<ll,ll> i[n];
#define modu(i) ((i<0)?(-1*i):(i)) 

#define endl '\n'
#define MOD 1e9+7;
#define che cout<<"yoyo";
 


 
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