
typedef long long int ll;


















 


using ull = unsigned long long int;
using dd = double;
using ldd = long double;
using namespace std;
const int mod=998244353;
const int N=2e5+5;
 
 





   
   


  

  

int main()
{ 
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    
    while (t--)
    {
        int a;
        cin>>a;
        int maxx=0;
        set<int>st;
        map<int,int>freq;
        

        int arr[a];
        for (int i = 0; i < a; i++)
        {
            cin>>arr[i];
            st.insert(arr[i]);
            freq[arr[i]]++;
        }
        for(auto g:st)
        {
            

            maxx=max(maxx,freq[g]);
            

        }
        cout<<maxx<<endl;
    }
     
    }


 	 	 			  	    	         						