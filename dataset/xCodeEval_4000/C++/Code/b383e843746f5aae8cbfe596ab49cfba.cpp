


































































#include<bits/stdc++.h>
using namespace std;
int main()
{
   int x,y,i,j;
   cin>>x;
   int a[x];
   for(i=0; i<x; i++)
   {
       cin>>a[i];
   }
   cin>>y;
   int b[y];
   for(j=0; j<y; j++)
   {
       cin>>b[j];
   }
   sort(a,a+x);
   sort(b,b+y);
   for(i=0; i<x; i++)
   {
       for(j=0; j<y; j++)
       {
           int sum = a[i]+b[j];
           int c = binary_search(a,a+x,sum);
           int d = binary_search(b,b+y,sum);
           if
            (c==0 && d==0)
           {
               cout<<a[i]<<" "<<b[j];
               return 0;
           }
       }
   }

}


