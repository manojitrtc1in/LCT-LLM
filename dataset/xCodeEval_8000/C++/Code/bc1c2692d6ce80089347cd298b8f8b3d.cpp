#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include <iterator>
#include<stack>
#include<queue>
#include <iomanip>
using namespace std;

int main(){
    
    
    
    
    







    
	
	
 
          
























































































   





















long long x,y,z,c=0;
cin>>x>>y>>z;
if (x+y<z)
	cout<<0<<" "<<0<<endl;
else if (x%z==0 || y%z==0||(x%z+y%z)<z)
	cout<<fixed<<setprecision(0)<<((x+y)/z)<<" "<<0<<endl;
else  {
	cout<<fixed<<setprecision(0)<<((x+y)/z)<<" "<<min(z-(y%z),z-(x%z))<<endl;
}



    return 0;
}


