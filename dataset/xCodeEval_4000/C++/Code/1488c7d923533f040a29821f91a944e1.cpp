


#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=109;
long long a[N][N];
long long q,n,m,d,w,k,l,r,sum,sum1,sum2,sum3;
pair< long long ,long long>p[N];
bool flag,flag1,flag2,flag3,ff;
bool mem[109][109][10009];
bool visited[N];
bool visited1[N];


vector< long long >v[N];
map<long long ,long long >mp;
map<long long,long long>mp1;
long long frg[200009];
string s,s1;
long long ans,ans1;
int main(){
cin>>q;
while(q--)
{
   


   cin>>n;
   for(int i=1;i<=n;i++)v[i].clear();
   if(n==1)cout<<1<<endl;
   else if(n==2)cout<<-1<<endl;
  

   else if(n!=2&&n%2==0)
   {
       ans=1;
       for(int i=1;i<=n;i++)

        for(int j=1;j<=n;j++)
          a[i][j]=ans,v[j].push_back(a[i][j]),ans++;
        k=1;w=1;
      for(int i=1;i<=n;i++)
      {
          if(k%2==1)
           

            for(int j=v[i].size()-1;j>=0;j--)
              a[w][k]=v[k][j],w++;
        k++;
        w=1;

      }
      for(int i=1;i<=n;i++){
        if(i!=1)cout<<endl;
        for(int j=1;j<=n;j++)cout<<a[i][j]<<" ";}

   }
   else
   {
       ans=1;
       for(int i=1;i<=n;i++)

        for(int j=1;j<=n;j++)
          a[i][j]=ans,v[j].push_back(a[i][j]),ans++;
       k=1;w=1;
      for(int i=1;i<=n;i++)
      {
          if(k%2==1)
            for(int j=v[i].size()-1;j>=0;j--)
              a[w][k]=v[k][j],w++;
        k++;
        w=1;

      }
      

     long long ddd=(n/2+1);
      long long jjj=ddd;
      sum2=jjj;

      


    for(int i= 2;i<=n;i++)
    {
        if(sum2!=n+1&&i%2==0)
        sum2++;
        else
        jjj--;
        

        if(i%2==0&&sum2!=n+1)
            swap(a[ddd][i],a[sum2][i]);
        else if(i%2==0&&sum2==n+1)
            swap(a[ddd][i],a[jjj][i]);

    }

      for(int i=1;i<=n;i++){
        if(i!=1)cout<<endl;
        for(int j=1;j<=n;j++)cout<<a[i][j]<<" ";}



   }

}}

