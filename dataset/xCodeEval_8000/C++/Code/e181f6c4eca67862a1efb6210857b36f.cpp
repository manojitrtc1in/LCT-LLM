




























































































































































































































































































































































































































































































































































#include <bits/stdc++.h>


using namespace std;
int main(){
long long x,y;
cin>>x;
long long a[x],b[x];
for(int i=0;i<x;i++){
    cin>>y;
    a[y-1]=i+1;
}
for(int i=0;i<x;i++){
    cout<<a[i]<<" ";
}
cout<<"\n";
    return 0;
}