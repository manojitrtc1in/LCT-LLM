



































































using namespace std;


typedef  long long unsigned int  par12i;
typedef unsigned long long UL;
typedef unsigned char UC;
typedef long long ll;
typedef double dasmlao;




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




























  
    
        

            

      

        

  
        
         
                
       

long  id21(long long id19)
{
    if (id19 == 0)
        return 1;
    int id1 = 0;
    while (id19 != 0) {
        id19 = id19 / 10;
        id1++;
    }
    return id1;
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
char id12(string strA, string strB)
{
    

    unordered_map<char, int> m1;
 
    

    for ( int id20 = 0; id20 < strB.length(); id20++)
        m1[strB[id20]]++;
 
    

    for (int id20 = 0; id20 < strA.length(); id20++)
        m1[strA[id20]]--;
 
    for (auto h1 = m1.begin(); h1 != m1.end(); h1++) {
 
        

        

        if (h1->second == 1)
            return h1->first;
    }
}
 


void id3(int arr[], int n)
{
    

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    

    for (int i = n - 1; i >= 0; i--) {
        

        swap(arr[0], arr[i]);
 
        

        heapify(arr, i, 0);
    }
}





void id2(int arr[], int id8, int id16)
{
    for (int id5 = 0; id5 < id8 - 1 && id16 > 0; ++id5) {
 
        

        

        int indexPosition = id5;
        for (int pppp = id5 + 1; pppp < id8; pppp++) {
 
            

            

            if (id16 <= pppp - id5)
                break;
 
            

            

            

            if (arr[pppp] > arr[indexPosition])
                indexPosition = pppp;
        }
 
        

        

        for (int pppp = indexPosition; pppp> id5; pppp--)
            swap(arr[pppp], arr[pppp - 1]);
 
        

        

        id16 -= indexPosition - id5;
    }
}









void id14(int sw212)
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
     
     par12i id11,id4,id0=11,id9, id6,id10=100099;
     cin>>id11;
     
     id4=12;id6=3; id9=5;
     if( id9>id6)
     {
          
          

    for(par12i id13=1; id13<=id11; id13++)
     {
          if(id4>id0)
          {
               

						

               for(par12i id15=12;id15>=8 ; id15--)
               {
                    

               }
               
               

               
               

               
               

              
               
               if(id10>1000)
               {
                    
                    
                    if(id10==100099)
                    {
                        
                        if(id10%1==0)
                        {
                            
                            
                        
                         
                           

                           

                         
                         
                            

                          
                                
                                
                                
                                long long unsigned int  id17,v2,v4,v3,ve;
                                cin>>id17;
                               
                               
                              
    for (v2 = 1; v2 <= id17; v2++) {
 
      
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
               
               
               
               
 




               for(long id7 =0; id7<=1000; id7++)
               {
                    if(id7>2000)
                    {
                         

                    }
                    else
                    {
                         

                    }
               }
               
          }
          
          
          
          
          
     }
     
     
     for(par12i id18 =0; id18<100; id18++)
     {
          if(12>1)
          {
               

               
               
		}
     
    }
          }
     
    

          
     
     
     
     
     
     else
     {
          

          

          

          for(par12i id9=88; id9<1222; id9++)
          {
               

          }
          for(par12i id9 =122; id9<124; id9++)
          {
               

          }
          
     }


     

			

			

			


			


			
			

     
     
     
     
     
	

	return 0;
}




