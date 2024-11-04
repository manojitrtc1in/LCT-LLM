
















































































































































































































#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long double dl;

int main()
{
    dl a,d,dis=0.0; int n; cin>>a>>d>>n;
    for(int i=1;i<=n;i++){
        dis+=d;
        dis=dis-(dl)(4*a*((int)((dl)dis/(dl)(4*a))));
        if((int)(dis/a)==0){
            cout<<setprecision(6)<<dis<<" "<<0<<"\n"; continue;
        }
        if((int)(dis/a)==1){
            cout<<setprecision(6)<<a<<" "<<(dl)dis-a<<"\n"; continue;
        }
        if((int)(dis/a)==2){
            cout<<setprecision(6)<<(dl)-dis+3*a<<" "<<a<<"\n"; continue;
        }
        if((int)(dis/a)==3){
            cout<<setprecision(6)<<0<<" "<<(dl)4*a-dis<<"\n"; continue;
        }
        cout<<"0 0\n";
    }
    return 0;
}
