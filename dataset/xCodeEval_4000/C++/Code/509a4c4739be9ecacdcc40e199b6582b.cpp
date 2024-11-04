













































#include <bits/stdc++.h>
using namespace std;
long long cnt,ans;
int main()
{
 long long t;
 cin>>t;
 while(t--){
 	long long n,m,r,c;
 	cin>>n>>m>>r>>c;
 	long long mex;
 	mex =max(abs(abs(n-r)+abs(m-c)) , abs(abs(1-r)+abs(1-c)));
  mex = max(mex , abs(1-r) + abs(m-c));
  mex = max(mex , abs(n-r) + abs(1-c)); 
  cout <<mex<<endl;
  }
}
