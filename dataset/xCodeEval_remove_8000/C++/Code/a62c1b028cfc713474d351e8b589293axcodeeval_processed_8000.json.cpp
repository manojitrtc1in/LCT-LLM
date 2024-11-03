
 
using namespace std;
 
long long q,k,a,x,b,ans,c,ans1;
map<long long,long long> mp;
string s;
char s1,s2;
int main(){
    scanf("%lld",&a);
    cin>>s;




    for(int i = 0; i < a; i++){
    	if(i%2==0){
    		s1='r';s2='b';
    	} else {s1='b';s2='r';}
    	if(s[i]!=s1){
    		if(s[i]=='b')
    		ans++;
			else ans1++;
    	} 
    	if(s[i]!=s2){
    		if(s[i]=='r')
    		x++;
			else c++;
        } 
    }
	cout<<min(max(ans,ans1),max(c,x)); 	
}