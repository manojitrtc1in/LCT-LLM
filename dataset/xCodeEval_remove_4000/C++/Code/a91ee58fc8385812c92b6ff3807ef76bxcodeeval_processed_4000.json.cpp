



using namespace std;

int main(){
    
    
    
    
    







    
	
	
 
          



























int w,a,b,m=0,l=0,hh=0;

cin>>w>>a>>b;
string x;
cin>>x;
if (((x.length())>w*b) || ((x.length())<w*a) )
	cout<<"No solution\n";
else{
	int m = ((double)x.length() / w), d = x.length() % w;
	for (int i=1;i<=w;i++){
		if (i<w){
			for(int j=0; j<m; j++) 
				cout<<x[hh++];
            cout<<endl;
		}
		else
		{
			while (hh<x.length()){
				cout<<x[hh++];
			}
            cout<<endl;
			

		}
      }
    
		
			
	

}
cout<<endl;

    return 0;
}

