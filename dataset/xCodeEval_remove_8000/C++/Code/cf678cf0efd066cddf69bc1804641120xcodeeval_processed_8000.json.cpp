

















using namespace std;



































































































































































       










































































































































































































































































   




















































































    





































































































































































































































































































































































































































































































































        
















































































    



















    






        
















   
















































 	












































        
       


















































































































    




































































     








 














    
    

















































































































































    



























































































































































































    
    

    

    

    

    

    

    

    

    
  


        
        
























                  










        
        
        





















   


















 




















     








        






         






         











    

























































































































        































                
















int max(int a,int b){
    if (a>b){
        return a;
    }
    else{
        return b;
    }
}























































































    
    










        
        




































































































































































































































































           






































           

































        





























   




























































     










     








     




     








         




















     






































































































       











































































































































































































































        
        






























       






























































































                






















     
      














































































































































































































































































































































    









































































































































































































































































































                






        




    
    


        


























            








        























































        
        












        


        





















        


























































































        








       






            
































            


















        
       
            
            
        



























































































































        









































































































                












        



















































































































































































        











































































































































         






















































































































      










































        
      
    


    
    




        






















        
        









































int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int r = 0,b=0;
        for (int i=0;i<n;i++){
            if (s[i]=='R'){
                r++;
            }
            else if (s[i]=='B'){
                b++;
            }
        }
        

        

        

        

        

        

        

        


        r= 0;
        b= 0;
        bool f = true;
        for (int i=0;i<n;i++){
            if (s[i]=='W'){
                if ((r==0 && b!=0)||(r!=0 && b==0)){
                        f =false;
                        break;
                }
                else{
                    r = 0;
                    b=0;
                }
            }
             else if (s[i]=='R'){
                r++;
            }
            else if (s[i]=='B'){
                b++;
            }    
        }
        if (!f){
             cout<<"NO"<<endl;
        }
        else{
              if ((r==0 && b!=0)||(r!=0 && b==0)){
                       cout<<"NO"<<endl;
                }
                else{
                    cout<<"YES"<<endl;
                }
        }
    }
    return 0;
}