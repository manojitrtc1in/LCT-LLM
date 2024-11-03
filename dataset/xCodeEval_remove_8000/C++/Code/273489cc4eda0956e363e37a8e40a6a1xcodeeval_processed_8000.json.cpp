
















using namespace std;

int main()
{
	t{
		int n , m;
		cin >> n >> m;
		int comp[n][m];
		for(int i=0;i<n;i++)
		    {
		    	for(int j=0;j<m;j++)
		    	    {
		    	    	cin>>comp[i][j];
					}
			}
			
		int arr[n][m];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i == 0 || i == n - 1)
				{
					if (j == 0 || j == m - 1)
						arr[i][j] = 2;
					else
						arr[i][j] = 3;
				}
				else
				{
					if (j == 0 || j == m - 1)
						arr[i][j] = 3;
					else
						arr[i][j] = 4;
				}
			}
		}
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if(arr[i][j]<comp[i][j])
				   {
				   	flag = 1;
				   	break;
				   }
				   
			}
		if(flag == 1)
		   break;
		}
		
		if(flag == 1)
		   cout<<"NO"<<endl;
		else
		   {
		   cout<<"YES"<<endl;
		  for(int i=0;i<n;i++)
		    {
		    	for(int j=0;j<m;j++)
		    	    {
		    	    	cout<<arr[i][j]<<" ";
					}
				cout<<endl;
			}
	}
}
return 0;
}