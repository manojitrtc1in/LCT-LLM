




































































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
    cout<<a[x-1]<<" "<<b[y-1];
    return 0;
}



