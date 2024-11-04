








using namespace std;








































































int main()
{
    FAST;

    

    READ;
    

    WRITE;

   int t;
   cin>>t;
   while(t--)
    {
        string s;
        cin>>s;     
        if(s.length()%2!=0){
            cout<<"NO"<<endl;
        }else{
            int nB=0;
            for (int i = 0; i < s.length(); ++i)
            {
                if(s[i]=='B'){
                    nB++;
                }
            }
            if(nB==s.length()/2){
                cout<<"YES"<<endl;
            }else
            {
                cout<<"NO"<<endl;
            }
        }
    } 
   
}






 

 

 

 

 

 

 

 

 

 

 


 






 

 


 
