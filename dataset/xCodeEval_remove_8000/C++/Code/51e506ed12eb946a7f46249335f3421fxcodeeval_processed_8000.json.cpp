

using namespace std;
































			














































































































































































































		



















































		




















































						


					






































					


				




		




			




		

































			




















			


		




		




































			




		


































	















































		
























































		




























					
					










						














						


					
					


















					






















































































	













































		










































					








					


















				
























































						


















					


























				




























			

























































				




			






			








			






















































































			












		



































































































		








































			
			


		










				












			




				






































				


		





































































































































		




		


		
		















































































































				





























































































































			
			
































				
































		










			


				






				


			
			
			
			




















 








 
















 














































































			




















































				






				












				














		
		



























		


	








		










		
		












	
	


	






























		












































					






						


				
















				


		




























































		




		














			






		








































































		


























		
































				
















					




				












		
		
		
		














  








  




  










  


















  


















































	
	
	






	










		




		  






		  






		






		












		













































		
	
			




























				


































































































	


	
























































































				
				


			



































			
















				


				








				


























		































































						
















						






						






















































						
















						






						
































	
































			








































			
















			
			














		



















		






























			


			











































































			













































































			
















































































































			


		












		





int main(){
	fast input output
	ll t;
	cin>>t;
	while(t--){
		ll n,x,curr,t1;
		cin>>n;
		vector<ll> v;
		ll s=0;
		for (int i = 0; i < n; ++i)
		{
			cin>>x;
			v.pb(x);
			s+=x;
		}
		curr=v[0];
		t1=-curr;
		if(curr<0 || s!=0){
			cout<<"No"<<endl;
			continue;
		}
		
		bool flag1=false,flag=true;
		if(curr==0){
		    flag1=true;
		}
		for (int i = 1; i < n; ++i)
		{
			if(flag1){
				if(v[i]!=0){
					flag=false;
					break;
				}
			}
			else{
			
				if(v[i]<t1){
				

					flag=false;
					break;
				}
				else if(v[i]==t1){
				    flag=true;
					flag1=true;
				}
				else{
				    flag=false;
					t1=-(v[i]-t1);
				}
			}
		}
		if(flag){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
}