#include<bits/stdc++.h>




using namespace std;
#define time ios_base::sync_with_stdio(0);cin.tie(0);
#define dpp(arr,val) memset(arr,val,sizeof (arr))
#define ll long long
#define ull unsigned long long
#define ld long double
#define PQ priority_queue
#define pii pair<int,int>
#define pll pair<ll,ll>
#define S second
#define F first



double eps= 0.0000001;
double pi=acos(-1);


ll fastpower(ll b,ll p)
{
    ll ans=1;
    while(p)
    {
        if (p%2)
        {
            ans=(ans*b);
        }
        b=b*b;
        p/=2;
    }
    return ans;
}
ll fastpowermod(ll b,ll p,ll m)
{
    ll ans=1;
    while(p)
    {
        if (p%2)
        {
            ans=((ans%m)*(b%m))%m;
        }
        b=((b%m)*(b%m))%m;
        p/=2;
    }
    return ans%m;
}
string  makeitstring(ll n)
{
    string ans;
    bool ch=0;
    if (n<0)
    {
        n*=-1;
        ch=1;
    }
    if (n==0)
    {
        ans="0";
    };
    while (n)
    {
        ll mo=n%10;
        mo+=48;
        char m=mo;
        ans=m+ans;
        n/=10;
    }
    if (ch)
    {
        ans='-'+ans;
    }
    return ans;
}




























bool compare(double f,double s)
{
    return  (abs(f-s)<eps);
}
ll gcd(ll a,ll b)
{
    while(b!=0)
    {
        ll a2=a;
        a=b;
        b=a2%b;
    }
    return a;
}
























int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
char grid[100][100];
int cum[1000];
vector<ll>v;
int a,b,c,d,n,cnt,now;
bool solvable;
bool check(int x,int y)
{
return (y<a&&y>=0&&x<b&&x>=0)||((y>=a&&y<a+c&&x<d&&x>=0));
}
void stars()
{
 for (int i=0;i<max(b,d);i++)
    {
        for (int j=0;j<a+c;j++)
        {
        grid[i][j]='.';
        }
    }
}
void solve(int x,int y)
{
    cnt++;
    if (cnt>v[now]){now++;}
    

    grid[x][y]=now+'a';
    for (int i=0;i<4;i++)
    {
    int xx=x+dx[i];
    int yy=y+dy[i];
    if (check(xx,yy)&&grid[xx][yy]=='.'){solve(xx,yy);return ;}
     }

}
int main()
{


    

    

    

    time;
    cin>>a>>b>>c>>d>>n;
    int sum=0;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        sum+=x;
        v.push_back(sum);
    }
    for (int i=0;i<b;i++)
    {
        for (int j=0;j<a;j++)
        {
        if (solvable){continue;}

         cnt=0;
         stars();
         solve(i,j);
         now=0;
         if (cnt==a*b+c*d){solvable=1;}
        }
    }
    if (solvable){cout<<"YES"<<endl;}
    else {cout<<"NO";return 0;}
    for (int i=0;i<max(b,d);i++)
    {
        for (int j=0;j<a+c;j++)
        {
            cout<<grid[i][j];
        }
        cout<<endl;
    }
    return 0;

}
