



#include<bits/stdc++.h>
using namespace std;



bool cmp(int a,int b)
{
    return a>b;
}

const int x[4]={1,10,100,1000};
vector<int> a;
string s;

int value(string n){
	int ans=0;
	for (int i=n.size()-1;i>=0;i--){
		ans+=(n[i]-'0')*(x[n.size()-1-i]);
	}
	return ans;
}

int main(){
	cin>>s;
	int beg=0;
	for (int i=0;i<s.size();i++){
		if (s[i]==',') {
			a.push_back(value(s.substr(beg,i-beg)));
			beg=i+1;
		}
	}
	a.push_back(value(s.substr(beg,s.size()-beg)));
	sort(a.begin(),a.end());
	bool flag=true;
	for (int i=0;i<a.size();i++){
		if (a[i]==a[i+1]) continue;
		if (a[i]+1==a[i+1]){
			if (flag==true) {
				cout<<a[i]<<"-";
				flag=false;
			}
		}
		else {
			if (flag==false){
				flag=true;
				cout<<a[i];
			}
			else cout<<a[i];
			if (i!=a.size()-1) cout<<",";
		}
	}
}
