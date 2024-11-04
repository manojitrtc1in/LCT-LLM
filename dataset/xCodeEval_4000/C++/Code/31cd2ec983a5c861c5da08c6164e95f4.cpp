#include<iostream>
#include<string>

using namespace std;










int n,k;
string s;




template <typename T>
T myMax(T x, T y)
{
   return (x > y)? x: y;
}
template<class T, class U = char>
class A  {
public:
    T x;
    U y;
    A() {   cout<<"Constructor Called"<<endl;   }
};
template <class A_Type> class calc
{
  public:
    A_Type multiply(A_Type x, A_Type y);
    A_Type add(A_Type x, A_Type y);
};
template <class A_Type> A_Type calc<A_Type>::multiply(A_Type x,A_Type y)
{
  return x*y;
}
template <class A_Type> A_Type calc<A_Type>::add(A_Type x, A_Type y)
{
  return x+y;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>k;
    char z='a';
    s="a";
    for(int i=1;i<k;i++){
    	char x;
    	char y;
        for(int j=i;j<k;j++){
            x=96+i;
            y=97+j;
            s+=x;
            s+=y;
        }
        z++;
        s+=z;
        
    }
    int l=s.size();
    for(int i=0;i<n;i++) cout<<s[i%l];
}