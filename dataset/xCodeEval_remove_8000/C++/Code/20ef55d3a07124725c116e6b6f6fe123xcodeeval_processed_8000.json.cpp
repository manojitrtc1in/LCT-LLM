

















using namespace std;






































































        




















       
      
        








           






































































    


























     










































































        







































































































   

















     












































    


































































































































































































   



































       






















































 










 










 
















































































































































































 








 















































































    















































    
  











            








           
































































































    



















































































































                    





































































                    

















































            


        

















        


    



    






























        


        
        




















































































































































































































      




































        


    
    

























































































    































































































































































































































































    








































               






    


































































































































           










        













	

	

	

	

	

    

    

    

    

	

	

	

	

	

    

    

    

    

	

	

	

	

	

	

	

	

	    
	

	

	

	

    

	

	

	

	

	

	

	

	    
	

	    
	    
	

	



    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    



    


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	



	



	

	

	




	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

			
	

	


	

	

	




	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	



	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	



	int main(){
		int t;
		cin>>t;
		while(t--){
			int n,m;
			cin>>n>>m;
			int total = (n*m)/2;
			int id0 = (n*m)/3;
			if ((n*m)%3==1){
				id0--;
			}
			id0/=2;
			cout<<total - id0<<endl; 	
	}	
		return 0;
	}