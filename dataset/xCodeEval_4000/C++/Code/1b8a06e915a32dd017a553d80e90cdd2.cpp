#include<bits/stdc++.h>
using namespace std;



string s[6];
vector<string> res;

void draw(vector <string> &w, int x,int y,int dx,int dy,string s){
	for (int k=0;k<s.size();k++,x+=dx,y+=dy){
		w[x][y]=s[k];
	}
	return;
}

int main(){
	for (int i=0;i<6;i++) cin>>s[i];
	sort(s,s+6);
	res.clear();
	do{
		if (s[0].size()+s[2].size()==s[1].size()+1&&s[3].size()+s[5].size()==s[4].size()+1){
			int l[6];
			for (int i=0;i<6;i++) l[i]=s[i].size()-1;
			if (s[0][0]==s[3][0]&&s[0][l[0]]==s[4][0]&&s[1][0]==s[3][l[3]]&&s[1][l[0]]==s[4][l[3]]&&s[1][l[1]]==s[5][0]&&s[2][0]==s[4][l[4]]&&s[2][l[2]]==s[5][l[5]]){
				int n=l[4]+1,m=l[1]+1;
				vector<string> w(n,string(m,'.'));
				draw(w,0,0,0,1,s[0]);
				draw(w,l[3],0,0,1,s[1]);
				draw(w,n-1,l[0],0,1,s[2]);
				draw(w,0,0,1,0,s[3]);
				draw(w,0,l[0],1,0,s[4]);
				draw(w,l[3],l[1],1,0,s[5]);
				if (res.size()==0||res>w) res=w;
			}
		}
	}
	while (next_permutation(s,s+6));
	if (res.size()==0) cout<<"Impossible"<<endl;
	for (int i=0;i<res.size();i++) cout<<res[i]<<endl;
}
