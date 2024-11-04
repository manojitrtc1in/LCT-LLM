













using namespace std;


using namespace __gnu_pbds;

int n,a,b,rankk=1,ans,tmp=1,tot,num;
priority_queue<int>q,q2;
deque<int>d,d2;
bool check()
{
    if(n==1&&d[0]==1)cout<<0,exit(0);
  else if(n==1)cout<<1,exit(0);

  for(int i=1;i<n;i++)
      if(d[i]<=d[i-1])re 0;
   re (d[0]==1);
}


int test()
{ int ok=0,steps=0;
  for(int i=0;i<n;i++)
   if(d2[i]==tmp&& (i==n-1||d2[i]<d2[i+1]))tmp++,ok=1;
   else if(ok)re oo;
   rankk=tmp;
   

    while(!q2.empty() )
      {
       int val=-q2.top(),ok=0;
       if(rankk==val)
        {d2.push_back(val),q2.pop(),rankk++;
         if(!d2.empty())
         { if(d2.front()!=0) q2.push(-d2.front());
           d2.pop_front();
         }
        }
       else re oo;

       steps++;
       if(rankk>n)break;
      }

 re steps;
}


void input()
{ cin>>n,q.push(-oo),q2.push(-oo);
    for(int i=0;i<n;i++)
     {cin>>a;
      if(a)q.push(-a),q2.push(-a);
     }
    for(int i=0;i<n;i++)
     cin>>b,d.push_back(b),d2.push_back(b),num+=(b>0);
     

}


int main()
{
    yalla;
    input();
    

    if(check())cout<<0;
    else
    {
     while(!q.empty() )
     {
      int val=-q.top(),ok=0;
      if(rankk==val)
       d.push_back(val),q.pop(),rankk++,ok=1;

       if(!d.empty())
       { if(d.front()!=0&&tot<num) q.push(-d.front()),tot++;
         d.pop_front();
         if(!ok)d.push_back(0);
       }
        ans++;
      if(rankk>n)break;
     }
    cout<<min(ans ,test() )<<endl;
   }
    re 0;
}































