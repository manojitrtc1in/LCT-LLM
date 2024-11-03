










using namespace std;











const ld pi=2*asin(1);
template<typename T> vector<T> inp(vector<T>A,ll n){
	cin>>n;
	for (int i=0;i<n;i++){
		ll x;
		cin>>x;
		A.append(x);
	}
	return A;
}
template<typename T> void disp(vector<T>A){
	for (auto& i:A){
		cout<<i<<' ';
	}
	cout<<endl;
}
bool Prime(ll n){
	if (n<=1){return false;}
	for (int i=2;i<=sqrt(n);i++){
		if (n%i==0){return false;}
	}
	return true;
}
bool ne(ll n,ll d){
	if (d==1){return true;}
	if (d==2){
		if (n%2==0||n>19){return true;}
	}
	if (d==3){
		string g=str(n);
		ll z=g.size();
		string x=g;
		sort(all(x));
		if (g[z-1]=='0'&&n>=30){return true;}
		else if ((g[z-1]=='3'&&n>=3)||(g[z-1]=='6'&&n>=6)||(g[z-1]=='9')||(g[z-1]=='2'&&n>=12)||(g[z-1]=='5'&&n>=15)||(g[z-1]=='8'&&n>=18)||(g[z-1]=='1'&&n>=21)||in(all(x),'3')==1){return true;}
		else if (n>=30||n%3==0){return true;}
		else{
			return false;		
		}
	}
	if (d==4){
		string x=str(n);
		ll z=x.size();
		string g=x;
		sort(all(g));
		if (n%4==0||n>=40){return true;}
		if ((x[z-1]=='6'&&n>=16)||(x[z-1]=='0'&&n>=20)||(x[z-1]=='2'&&n>=12)||(x[z-1]=='8'&&n>=8)||in(all(g),'4')){return true;}
		return false;
	}
	if (d==5){
		if (n%5==0||n>=50){return true;}
		return false;
	}
	if (d==6){
		string x=str(n);
		ll z=x.size();
		string g=x;
		sort(all(g));
		if (n>=60||n%6==0){return true;}
		if (in(all(g),'6')||(x[z-1]=='8'&&n>=18)||(x[z-1]=='6'&&n>=36)||(x[z-1]=='4'&&n>=24)||(x[z-1]=='2'&&n>=12)||(x[z-1]=='0'&&n>=30)){return true;}
			return false;
	}
	if (d==7){
		string x=str(n);
		ll z=x.size();
		string g=x;
		sort(all(g));
		if (n>=70||n%7==0){return true;}
		if (in(all(g),'7')||(x[z-1]=='8'&&n>=28)||(x[z-1]=='6'&&n>=56)||(x[z-1]=='4'&&n>=14)||(x[z-1]=='2'&&n>=42)||(x[z-1]=='1'&&n>=21)||(x[z-1]=='3'&&n>=63)||(x[z-1]=='5'&&n>=35)||(x[z-1]=='9'&&n>=49)){return true;}
		return false;
	}
	if (d==8){
		string x=str(n);
		ll z=x.size();
		string g=x;
		sort(all(g));
		if (n>=80||n%8==0){return true;}
		if (in(all(g),'8')||(x[z-1]=='6'&&n>=16)||(x[z-1]=='4'&&n>=24)||(x[z-1]=='2'&&n>=32)||(x[z-1]=='0'&&n>=40)){return true;}
			return false;
	}
	if (d==9){
		string x=str(n);
		ll z=x.size();
		string g=x;
		sort(all(g));
		if (n>=90||n%9==0){return true;}
		if (in(all(g),'9')||(x[z-1]=='8'&&n>=18)||(x[z-1]=='6'&&n>=36)||(x[z-1]=='4'&&n>=54)||(x[z-1]=='2'&&n>=72)||(x[z-1]=='1'&&n>=81)||(x[z-1]=='3'&&n>=63)||(x[z-1]=='5'&&n>=45)||(x[z-1]=='7'&&n>=27)){return true;}
		return false;
	}
	return false;
}
int main(){
    int t;
    cin>>t;
    while (t--){
    	int q,d;
    	cin>>q>>d;
    	ll x;
    	while (q--){
    		cin>>x;
    		if (ne(x,d)){cout<<"YES"<<endl;}
    		else{cout<<"NO"<<endl;}
    	}
    }
	return 0;
}
