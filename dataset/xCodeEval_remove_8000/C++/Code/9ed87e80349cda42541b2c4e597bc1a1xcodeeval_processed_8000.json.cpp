
























using namespace std;



















        
























        


































































































































































        



























































































































      












































































































































            


            


































































































































































































































































































       







































































































































































      














































































int dx[] = {1,0,0,-1,1,-1,1,-1};
int dy[] = {0,-1,1,0,1,-1,-1,1};




















      


        
















































































































              








































































































       






























   









    


















                  


        
               






































































































































































































































































 


  




















































 













































































































    














    


    




    
























            




    


















    








        











        






 













 














































































































        


















































        




























































































































































































































































































































































































































































        































































                





















































































































    





































































































































                






























































































































































            


















































 




  


 










 









































































                


























        










































                


























        
























































































































































































      








         
























































     


     








     










     










     















































































































int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        

        

        

       
        ll maxi = id0;
        ll mini = id1;

        for (int i=0;i<n;i++){
            cin>>arr[i];
            if (i!=0){
                if (arr[i]>maxi){
                    maxi=arr[i];
                }
            }
            if (i!=n-1){
                if (arr[i]<mini){
                    mini=arr[i];
                }
            }
        }
         if (n==1){
            cout<<0<<endl;
            continue;
        }
        ll res = max(maxi-arr[0],arr[n-1]-mini);
        for (int i=0;i<n-1;i++){
            res = max(res,arr[i]-arr[i+1]);
        }
        cout<<res<<endl;

        }
    
    return 0;
}