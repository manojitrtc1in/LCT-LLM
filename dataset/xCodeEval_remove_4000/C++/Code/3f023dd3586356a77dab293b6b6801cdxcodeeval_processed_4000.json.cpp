
using namespace std;

	



















const ll MOD = 1e9 + 7;

string s ;
void solve(){
	

	cin>>s  ;
	map<string,int> mp;
	int dem =0;
	for(int i='a';i<='z';i++){
		for(int j='a';j<='z';j++){
			 string tmp ="";
			if(i==j){
				continue;
			}else{
				tmp+=i;
				tmp+=j;
				mp[tmp]=++dem;
			}
		}
	}
	cout<< mp[s]<<endl;
	mp.clear();

}

int main()
{

	faster;
	int t ;
	cin>>t;
	cin.ignore();
	while(t--){
		solve();
	}	

}