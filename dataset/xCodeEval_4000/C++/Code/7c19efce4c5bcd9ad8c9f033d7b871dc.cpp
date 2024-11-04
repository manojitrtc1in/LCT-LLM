#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long




string multiply(string& num1, string& num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
    return "0";
 
    

    

    vector<int> result(len1 + len2, 0);
 
    

    

    int i_n1 = 0;
    int i_n2 = 0;
     
    

    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
 
        

        

        i_n2 = 0;
         
        

        for (int j=len2-1; j>=0; j--)
        {
            

            int n2 = num2[j] - '0';
 
            

            

            

            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
 
            

            carry = sum/10;
 
            

            result[i_n1 + i_n2] = sum % 10;
 
            i_n2++;
        }
 
        

        if (carry > 0)
            result[i_n1 + i_n2] += carry;
 
        

        

        i_n1++;
    }
 
    

    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;
 
    

    

    if (i == -1)
    return "0";
 
    

    string s = "";
     
    while (i >= 0)
        s += std::to_string(result[i--]);
 
    return s;
}


int32_t main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int p = n;
		int dig = 0;
		int ans = 1e9;
		while(p>0){
			dig++;
			p/=10;
		}
		p = n;
		string r = to_string(p);
		for(int f=0;f<(1<<dig);f++){
			string st;
			for(int j=0;j<dig;j++){
				if((f & (1<<j)) == 0) {
					st.push_back(r[j]);
				}
			}
			

		}
		
		for(int i=0;i<=61;i++){
			int move = 0;

			int x = (1ll<<i);
			string t = to_string(x);
			

			int n2 = t.length();
			int n1 = r.length();
			int j = 0,k = 0;
			
			while(j<n1 && k<n2){
				if(r[j] == t[k]){
					j++;
					k++;
				}
				else{
					move++;
					j++;
				}
				
			}
			if(j == n1)move+=(n2-k);
			else move+=(n1-j);
			

			ans = min(ans,move);
			
			
		}
		
		
		
		cout<<ans<<endl;
		
		
		
	}
	return 0;
}