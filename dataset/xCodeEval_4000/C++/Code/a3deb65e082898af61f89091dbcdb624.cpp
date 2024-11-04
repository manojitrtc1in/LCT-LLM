#include <iostream>
#include <bits/stdc++.h>
#include<sstream>


using namespace std;
int main()

{ 
    

 
 


 


  

     


 



























 

 

 



























int n , k ,arr[26]={0},c ,cc=0, i;
char req[25];
cin >> n >> k ;
for( i=97 ; i <= 122  ; i ++ ){
    req[i-97]=i;
}
req[i]='\0';
c= n/k;
for(int i = 0 ; i < c ; i++){
        int j ;
    for( j = 0 ; j < k ;j++){
        cout<< req[j];
    }

}
cc = n%k ;
for(int i = 0 ; i < cc ; i++){
    cout<<req[i];
}

return 0;
}
