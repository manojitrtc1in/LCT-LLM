#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	long long t;
	cin >> t;
	int arr[1000000];

	while (t--)
	{
	    	
		int n;
		cin >> n;
		int freq[n+4]={0};
		int c = 0;
		int x = 0;
		int m=0;
		int max=0;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			if(arr[i]>max)
			max=arr[i];
		}
		for (int j = 0; j < n; j++)
		{
			freq[arr[j]]++;
			
		}
		for (int k = 1; k <= max; k++)
		{
			if (freq[k] >= 3)
			{
			    	x = 1;
			    m=k;
			

			
			}
		}
	
		if (x == 1)
			cout<<m<<"\n";
			else 
			cout << "-1\n";
		

	}
}

		 

		 

		


		 





		  


				   

				 
					



					

					
					



						
					
					



	



	

	
	



		
	
	


	


	  