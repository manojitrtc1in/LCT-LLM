
























using namespace std;

typedef long long ll;

int n,k;
string st;
int b[400000+5];

int main(){
	

	cin>>n>>k;
	cin>>st;
	for(int i = 0;i<26;i++)
		for(int j=0;j<st.size();j++)
			if(st[j] == i+'a'&&k>0){
				k--;
				b[j]=1;
			}
		
	
		for(int i = 0;i<st.size();i++)
			if(b[i] == 0)
				cout<<st[i];
	
	
	
	return 0;
}