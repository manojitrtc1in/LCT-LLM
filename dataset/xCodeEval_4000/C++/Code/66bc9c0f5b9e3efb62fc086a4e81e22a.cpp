







#include <iostream>
#define IOS ios::sync_with_stdio(false)
#include <array>
#include <cstring>
#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include<bits/stdc++.h>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <forward_list>
#include <thread>
#include <random>
#include <complex>
#include <deque>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <ctime>











#include <stdio.h>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>


using namespace std;


typedef  long long unsigned int  par12i;
typedef unsigned long long UL;
typedef unsigned char UC;
typedef long long ll;
typedef double dasmlao;
#define left asdleft
#define right asdright
#define link asdlink
#define khtmkryrr  cout<<"\n"
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvpii = vector<vpii>;
using vvpll = vector<vpll>;
#define unlink asdunlink
#define y0 asdy0
#define y1 asdy1
#define hao cout<<"yes";


#define HAO cout<<"YES";
#define nahiko cout<<"no";


#define NAHIKO cout<<"NO";



#define looplga while
#define mp make_pair
#define mtp make_tuple

#define pb push_back









  
    
        

            

      

        

  
        
         
                
       

long  totalginokitteh(long long aqw333412345)
{
    if (aqw333412345 == 0)
        return 1;
    int sur45321111133 = 0;
    while (aqw333412345 != 0) {
        aqw333412345 = aqw333412345 / 10;
        sur45321111133++;
    }
    return sur45321111133;
}






void heapify(int arr[], int n, int i)
{
    int smallest = i; 

    int l = 2 * i + 1; 

    int r = 2 * i + 2; 

 
    

    if (l < n && arr[l] < arr[smallest])
        smallest = l;
 
    

    if (r < n && arr[r] < arr[smallest])
        smallest = r;
 
    

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
 
        

        heapify(arr, n, smallest);
    }
}
char arebhgwanmaafido(string strA, string strB)
{
    

    unordered_map<char, int> m1;
 
    

    for ( int aaaaaaaaaaaaaa = 0; aaaaaaaaaaaaaa < strB.length(); aaaaaaaaaaaaaa++)
        m1[strB[aaaaaaaaaaaaaa]]++;
 
    

    for (int aaaaaaaaaaaaaa = 0; aaaaaaaaaaaaaa < strA.length(); aaaaaaaaaaaaaa++)
        m1[strA[aaaaaaaaaaaaaa]]--;
 
    for (auto h1 = m1.begin(); h1 != m1.end(); h1++) {
 
        

        

        if (h1->second == 1)
            return h1->first;
    }
}
 


void kuchhbhinikkkaaalega__kya(int arr[], int n)
{
    

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    

    for (int i = n - 1; i >= 0; i--) {
        

        swap(arr[0], arr[i]);
 
        

        heapify(arr, i, 0);
    }
}





void kuchhhbhinikal__loyrr(int arr[], int vvvvvvvvvvvvvvvvvvvvvvvvvvv, int wwwwwwwwwwwwwwwwwwwwwwwwwww)
{
    for (int ddddddddd = 0; ddddddddd < vvvvvvvvvvvvvvvvvvvvvvvvvvv - 1 && wwwwwwwwwwwwwwwwwwwwwwwwwww > 0; ++ddddddddd) {
 
        

        

        int indexPosition = ddddddddd;
        for (int pppp = ddddddddd + 1; pppp < vvvvvvvvvvvvvvvvvvvvvvvvvvv; pppp++) {
 
            

            

            if (wwwwwwwwwwwwwwwwwwwwwwwwwww <= pppp - ddddddddd)
                break;
 
            

            

            

            if (arr[pppp] > arr[indexPosition])
                indexPosition = pppp;
        }
 
        

        

        for (int pppp = indexPosition; pppp> ddddddddd; pppp--)
            swap(arr[pppp], arr[pppp - 1]);
 
        

        

        wwwwwwwwwwwwwwwwwwwwwwwwwww -= indexPosition - ddddddddd;
    }
}









void printDivisors(int sw212)
{
    

    for (int vs12=1; vs12<=sqrt(sw212); vs12++)
    {
        if (sw212%vs12 == 0)
        {
            

            if (vs12/1== vs12)
            {
               

            }
 
            else
            {

               

            }
        }
    }
}





int main() 
{
     
     par12i q12__0p,o_____p,p____o=11,c_____p, c___p,dece12___1234078=100099;
     cin>>q12__0p;
     
     o_____p=12;c___p=3; c_____p=5;
     if( c_____p>c___p)
     {
          
          

    for(par12i v9__y6=1; v9__y6<=q12__0p; v9__y6++)
     {
          if(o_____p>p____o)
          {
               

						

               for(par12i o__p=12;o__p>=8 ; o__p--)
               {
                    

               }
               
               

               
               

               
               

              
               
               if(dece12___1234078>1000)
               {
                    
                    
                    if(dece12___1234078==100099)
                    {
                        
                        if(dece12___1234078%1==0)
                        {
                            
                            
                        
                         
                           

                           

                         
                         
                            

                          
                                
                                
                                
                                long long unsigned int  a1q2,v2,v4,v3,ve;
                                cin>>a1q2;
                               
                               
                              
    for (v2 = 1; v2 <= a1q2; v2++) {
 
      
        for (v3 = 1; v3 <=v2; v3++) {
 
            
            if (v3 == 1 || v3 == v2)
            {
                cout <<1<<" ";
            }
 
           
            else
            {
                cout <<0<<" ";
            }
        }
        khtmkryrr;
    }
                                
                                
                                
                                
                                
                                
   
   
     
                  
                           
                           
                           

                           
                           

            
                        } 
                         
                    }
                    else
                    {
                         

                    }
              
               }
               else
               {
                    

                    
                    if(12>4)
                    {
                         

                    }
                    else
                    {
                         

                    }
               }
              
              
               
          }
          else
          {
               

               for(par12i o_p=12; o_p<120; o_p++)
               {
                    

               }
               
               
               
               
 




               for(long v___x_0 =0; v___x_0<=1000; v___x_0++)
               {
                    if(v___x_0>2000)
                    {
                         

                    }
                    else
                    {
                         

                    }
               }
               
          }
          
          
          
          
          
     }
     
     
     for(par12i cx___12__ =0; cx___12__<100; cx___12__++)
     {
          if(12>1)
          {
               

               
               
		}
     
    }
          }
     
    

          
     
     
     
     
     
     else
     {
          

          

          

          for(par12i c_____p=88; c_____p<1222; c_____p++)
          {
               

          }
          for(par12i c_____p =122; c_____p<124; c_____p++)
          {
               

          }
          
     }


     

			

			

			


			


			
			

     
     
     
     
     
	

	return 0;
}




