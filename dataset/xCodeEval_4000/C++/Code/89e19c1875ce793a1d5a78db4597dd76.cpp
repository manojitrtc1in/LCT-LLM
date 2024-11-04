#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	string s[n],ans[n],ans1[n],ans2[n],ans3[n],ans4[n],ans5[n];
	for(int i=0;i<n;i++) {
		cin>>s[i];
		ans[i]=s[i];
		ans1[i]=s[i];
		ans2[i]=ans3[i]=ans4[i]=ans5[i]=s[i];
	}
	int to=0,to1=0,to2=0,to3=0,to4=0,to5=0;
		string str[m];
	for(int j=0;j<m;j++) {
		string tt;
		for(int i=0;i<n;i++) tt.push_back(s[i][j]);
		str[j]=tt;
	}
	string a[m],a1[m],a2[m],a3[m],a4[m],a5[m];
	for(int i=0;i<m;i++) {
		a[i]=a1[i]=a2[i]=a3[i]=a4[i]=a5[i]=str[i];
	}
	int t=0,t1=0,t2=0,t3=0,t4=0,t5=0;
	for(int j=0;j<m;j++) {
		int cntr=0,cntr1=0,cnt=0,cnt1=0;
		for(int i=0;i<n;i++) {
			if(j%2){
				if(cntr==0 and s[i][j]!='G') cnt++;
				else if(cntr==1 and s[i][j]!='T') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and s[i][j]!='T') cnt1++;
				else if(cntr1==1 and s[i][j]!='G') cnt1++;
				cntr1=cntr1^1;
			}
			else {
				if(cntr==0 and s[i][j]!='A') cnt++;
				else if(cntr==1 and s[i][j]!='C') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and s[i][j]!='C') cnt1++;
				else if(cntr1==1 and s[i][j]!='A') cnt1++;
				cntr1=cntr1^1;
			}
		}
		if(j%2) {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans[i][j]='T';
					else ans[i][j]='G';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans[i][j]='G';
					else ans[i][j]='T';
					cntr^=1;
				}
			}
		}
		else {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans[i][j]='C';
					else ans[i][j]='A';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans[i][j]='A';
					else ans[i][j]='C';
					cntr^=1;
				}
			}
		}
		to+=min(cnt,cnt1);
	}
	for(int j=0;j<m;j++) {
		int cntr=0,cntr1=0,cnt=0,cnt1=0;
		for(int i=0;i<n;i++) {
			if(j%2==0){
				if(cntr==0 and s[i][j]!='G') cnt++;
				else if(cntr==1 and s[i][j]!='T') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and s[i][j]!='T') cnt1++;
				else if(cntr1==1 and s[i][j]!='G') cnt1++;
				cntr1=cntr1^1;
			}
			else {
				if(cntr==0 and s[i][j]!='A') cnt++;
				else if(cntr==1 and s[i][j]!='C') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and s[i][j]!='C') cnt1++;
				else if(cntr1==1 and s[i][j]!='A') cnt1++;
				cntr1=cntr1^1;
			}
		}
		if(j%2==0) {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans1[i][j]='T';
					else ans1[i][j]='G';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans1[i][j]='G';
					else ans1[i][j]='T';
					cntr^=1;
				}
			}
		}
		else {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans1[i][j]='C';
					else ans1[i][j]='A';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans1[i][j]='A';
					else ans1[i][j]='C';
					cntr^=1;
				}
			}
		}
		to1+=min(cnt,cnt1);
	}
	
	for(int j=0;j<m;j++) {
		int cntr=0,cntr1=0,cnt=0,cnt1=0;
		for(int i=0;i<n;i++) {
			if(j%2==0){
				if(cntr==0 and s[i][j]!='A') cnt++;
				else if(cntr==1 and s[i][j]!='T') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and s[i][j]!='T') cnt1++;
				else if(cntr1==1 and s[i][j]!='A') cnt1++;
				cntr1=cntr1^1;
			}
			else {
				if(cntr==0 and s[i][j]!='G') cnt++;
				else if(cntr==1 and s[i][j]!='C') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and s[i][j]!='C') cnt1++;
				else if(cntr1==1 and s[i][j]!='G') cnt1++;
				cntr1=cntr1^1;
			}
		}
		if(j%2==0) {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans2[i][j]='T';
					else ans2[i][j]='A';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans2[i][j]='A';
					else ans2[i][j]='T';
					cntr^=1;
				}
			}
		}
		else {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans2[i][j]='C';
					else ans2[i][j]='G';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans2[i][j]='G';
					else ans2[i][j]='C';
					cntr^=1;
				}
			}
		}
		to2+=min(cnt,cnt1);
	}
	
	
	for(int j=0;j<m;j++) {
		int cntr=0,cntr1=0,cnt=0,cnt1=0;
		for(int i=0;i<n;i++) {
			if(j%2){
				if(cntr==0 and s[i][j]!='A') cnt++;
				else if(cntr==1 and s[i][j]!='T') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and s[i][j]!='T') cnt1++;
				else if(cntr1==1 and s[i][j]!='A') cnt1++;
				cntr1=cntr1^1;
			}
			else {
				if(cntr==0 and s[i][j]!='G') cnt++;
				else if(cntr==1 and s[i][j]!='C') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and s[i][j]!='C') cnt1++;
				else if(cntr1==1 and s[i][j]!='G') cnt1++;
				cntr1=cntr1^1;
			}
		}
		if(j%2) {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans3[i][j]='T';
					else ans3[i][j]='A';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans3[i][j]='A';
					else ans3[i][j]='T';
					cntr^=1;
				}
			}
		}
		else {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans3[i][j]='C';
					else ans3[i][j]='G';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans3[i][j]='G';
					else ans3[i][j]='C';
					cntr^=1;
				}
			}
		}
		to3+=min(cnt,cnt1);
	}
	
	
	for(int j=0;j<m;j++) {
		int cntr=0,cntr1=0,cnt=0,cnt1=0;
		for(int i=0;i<n;i++) {
			if(j%2==0){
				if(cntr==0 and s[i][j]!='A') cnt++;
				else if(cntr==1 and s[i][j]!='G') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and s[i][j]!='G') cnt1++;
				else if(cntr1==1 and s[i][j]!='A') cnt1++;
				cntr1=cntr1^1;
			}
			else {
				if(cntr==0 and s[i][j]!='T') cnt++;
				else if(cntr==1 and s[i][j]!='C') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and s[i][j]!='C') cnt1++;
				else if(cntr1==1 and s[i][j]!='T') cnt1++;
				cntr1=cntr1^1;
			}
		}
		if(j%2==0) {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans4[i][j]='G';
					else ans4[i][j]='A';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans4[i][j]='A';
					else ans4[i][j]='G';
					cntr^=1;
				}
			}
		}
		else {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans4[i][j]='C';
					else ans4[i][j]='T';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans4[i][j]='T';
					else ans4[i][j]='C';
					cntr^=1;
				}
			}
		}
		to4+=min(cnt,cnt1);
	}
	
	
	for(int j=0;j<m;j++) {
		int cntr=0,cntr1=0,cnt=0,cnt1=0;
		for(int i=0;i<n;i++) {
			if(j%2){
				if(cntr==0 and s[i][j]!='A') cnt++;
				else if(cntr==1 and s[i][j]!='G') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and s[i][j]!='G') cnt1++;
				else if(cntr1==1 and s[i][j]!='A') cnt1++;
				cntr1=cntr1^1;
			}
			else {
				if(cntr==0 and s[i][j]!='T') cnt++;
				else if(cntr==1 and s[i][j]!='C') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and s[i][j]!='C') cnt1++;
				else if(cntr1==1 and s[i][j]!='T') cnt1++;
				cntr1=cntr1^1;
			}
		}
		if(j%2) {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans5[i][j]='G';
					else ans5[i][j]='A';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans5[i][j]='A';
					else ans5[i][j]='G';
					cntr^=1;
				}
			}
		}
		else {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans5[i][j]='C';
					else ans5[i][j]='T';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<n;i++) {
					if(cntr==0) ans5[i][j]='T';
					else ans5[i][j]='C';
					cntr^=1;
				}
			}
		}
		to5+=min(cnt,cnt1);
	}
	
	for(int j=0;j<n;j++) {
		int cntr=0,cntr1=0,cnt=0,cnt1=0;
		for(int i=0;i<m;i++) {
			if(j%2){
				if(cntr==0 and str[i][j]!='G') cnt++;
				else if(cntr==1 and str[i][j]!='T') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and str[i][j]!='T') cnt1++;
				else if(cntr1==1 and str[i][j]!='G') cnt1++;
				cntr1=cntr1^1;
			}
			else {
				if(cntr==0 and str[i][j]!='A') cnt++;
				else if(cntr==1 and str[i][j]!='C') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and str[i][j]!='C') cnt1++;
				else if(cntr1==1 and str[i][j]!='A') cnt1++;
				cntr1=cntr1^1;
			}
		}
		if(j%2) {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a[i][j]='T';
					else a[i][j]='G';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a[i][j]='G';
					else a[i][j]='T';
					cntr^=1;
				}
			}
		}
		else {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a[i][j]='C';
					else a[i][j]='A';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a[i][j]='A';
					else a[i][j]='C';
					cntr^=1;
				}
			}
		}
		t+=min(cnt,cnt1);
	}
	for(int j=0;j<n;j++) {
		int cntr=0,cntr1=0,cnt=0,cnt1=0;
		for(int i=0;i<m;i++) {
			if(j%2==0){
				if(cntr==0 and str[i][j]!='G') cnt++;
				else if(cntr==1 and str[i][j]!='T') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and str[i][j]!='T') cnt1++;
				else if(cntr1==1 and str[i][j]!='G') cnt1++;
				cntr1=cntr1^1;
			}
			else {
				if(cntr==0 and str[i][j]!='A') cnt++;
				else if(cntr==1 and str[i][j]!='C') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and str[i][j]!='C') cnt1++;
				else if(cntr1==1 and str[i][j]!='A') cnt1++;
				cntr1=cntr1^1;
			}
		}
		if(j%2==0) {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a1[i][j]='T';
					else a1[i][j]='G';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a1[i][j]='G';
					else a1[i][j]='T';
					cntr^=1;
				}
			}
		}
		else {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a1[i][j]='C';
					else a1[i][j]='A';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a1[i][j]='A';
					else a1[i][j]='C';
					cntr^=1;
				}
			}
		}
		t1+=min(cnt,cnt1);
	}
	
	for(int j=0;j<n;j++) {
		int cntr=0,cntr1=0,cnt=0,cnt1=0;
		for(int i=0;i<m;i++) {
			if(j%2==0){
				if(cntr==0 and str[i][j]!='A') cnt++;
				else if(cntr==1 and str[i][j]!='T') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and str[i][j]!='T') cnt1++;
				else if(cntr1==1 and str[i][j]!='A') cnt1++;
				cntr1=cntr1^1;
			}
			else {
				if(cntr==0 and str[i][j]!='G') cnt++;
				else if(cntr==1 and str[i][j]!='C') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and str[i][j]!='C') cnt1++;
				else if(cntr1==1 and str[i][j]!='G') cnt1++;
				cntr1=cntr1^1;
			}
		}
		if(j%2==0) {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a2[i][j]='T';
					else a2[i][j]='A';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a2[i][j]='A';
					else a2[i][j]='T';
					cntr^=1;
				}
			}
		}
		else {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a2[i][j]='C';
					else a2[i][j]='G';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a2[i][j]='G';
					else a2[i][j]='C';
					cntr^=1;
				}
			}
		}
		t2+=min(cnt,cnt1);
	}
	
	
	for(int j=0;j<n;j++) {
		int cntr=0,cntr1=0,cnt=0,cnt1=0;
		for(int i=0;i<m;i++) {
			if(j%2){
				if(cntr==0 and str[i][j]!='A') cnt++;
				else if(cntr==1 and str[i][j]!='T') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and str[i][j]!='T') cnt1++;
				else if(cntr1==1 and str[i][j]!='A') cnt1++;
				cntr1=cntr1^1;
			}
			else {
				if(cntr==0 and str[i][j]!='G') cnt++;
				else if(cntr==1 and str[i][j]!='C') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and str[i][j]!='C') cnt1++;
				else if(cntr1==1 and str[i][j]!='G') cnt1++;
				cntr1=cntr1^1;
			}
		}
		if(j%2) {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a3[i][j]='T';
					else a3[i][j]='A';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a3[i][j]='A';
					else a3[i][j]='T';
					cntr^=1;
				}
			}
		}
		else {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a3[i][j]='C';
					else a3[i][j]='G';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a3[i][j]='G';
					else a3[i][j]='C';
					cntr^=1;
				}
			}
		}
		t3+=min(cnt,cnt1);
	}
	
	
	for(int j=0;j<n;j++) {
		int cntr=0,cntr1=0,cnt=0,cnt1=0;
		for(int i=0;i<m;i++) {
			if(j%2==0){
				if(cntr==0 and str[i][j]!='A') cnt++;
				else if(cntr==1 and str[i][j]!='G') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and str[i][j]!='G') cnt1++;
				else if(cntr1==1 and str[i][j]!='A') cnt1++;
				cntr1=cntr1^1;
			}
			else {
				if(cntr==0 and str[i][j]!='T') cnt++;
				else if(cntr==1 and str[i][j]!='C') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and str[i][j]!='C') cnt1++;
				else if(cntr1==1 and str[i][j]!='T') cnt1++;
				cntr1=cntr1^1;
			}
		}
		if(j%2==0) {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a4[i][j]='G';
					else a4[i][j]='A';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a4[i][j]='A';
					else a4[i][j]='G';
					cntr^=1;
				}
			}
		}
		else {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a4[i][j]='C';
					else a4[i][j]='T';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a4[i][j]='T';
					else a4[i][j]='C';
					cntr^=1;
				}
			}
		}
		t4+=min(cnt,cnt1);
	}
	

	for(int j=0;j<n;j++) {
		int cntr=0,cntr1=0,cnt=0,cnt1=0;
		for(int i=0;i<m;i++) {
			if(j%2){
				if(cntr==0 and str[i][j]!='A') cnt++;
				else if(cntr==1 and str[i][j]!='G') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and str[i][j]!='G') cnt1++;
				else if(cntr1==1 and str[i][j]!='A') cnt1++;
				cntr1=cntr1^1;
			}
			else {
				if(cntr==0 and str[i][j]!='T') cnt++;
				else if(cntr==1 and str[i][j]!='C') cnt++;
				cntr=cntr^1;
				if(cntr1==0 and str[i][j]!='C') cnt1++;
				else if(cntr1==1 and str[i][j]!='T') cnt1++;
				cntr1=cntr1^1;
			}
		}
		if(j%2) {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a5[i][j]='G';
					else a5[i][j]='A';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a5[i][j]='A';
					else a5[i][j]='G';
					cntr^=1;
				}
			}
		}
		else {
			if(cnt>cnt1) {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a5[i][j]='C';
					else a5[i][j]='T';
					cntr^=1;
				}
			}
			else {
				cntr=0;
				for(int i=0;i<m;i++) {
					if(cntr==0) a5[i][j]='T';
					else a5[i][j]='C';
					cntr^=1;
				}
			}
		}
		t5+=min(cnt,cnt1);
	}
	
	int mn=min(to,min(to1,min(to2,min(to3,min(to4,to5)))));
	int mn1=min(t,min(t1,min(t2,min(t3,min(t4,t5)))));
	mn=min(mn,mn1);
	if(mn==to) {
		for(int i=0;i<n;i++) cout<<ans[i]<<endl;
	}
	else if(mn==to1)  {
		for(int i=0;i<n;i++) cout<<ans1[i]<<endl;
	}
	else if(mn==to2)  {
		for(int i=0;i<n;i++) cout<<ans2[i]<<endl;
	}
	else if(mn==to3)  {
		for(int i=0;i<n;i++) cout<<ans3[i]<<endl;
	}
	else if(mn==to4)  {
		for(int i=0;i<n;i++) cout<<ans4[i]<<endl;
	}
	else if(mn==to5)  {
		for(int i=0;i<n;i++) cout<<ans5[i]<<endl;
	}
	else if(mn==t)  {
		for(int i=0;i<n;i++) {
			string tt;
			for(int j=0;j<m;j++) tt.push_back(a[j][i]);
			cout<<tt<<endl;
		}
	}
	else if(mn==t1)  {
		for(int i=0;i<n;i++) {
			string tt;
			for(int j=0;j<m;j++) tt.push_back(a1[j][i]);
			cout<<tt<<endl;
		}
	}
	else if(mn==t2)  {
		for(int i=0;i<n;i++) {
			string tt;
			for(int j=0;j<m;j++) tt.push_back(a2[j][i]);
			cout<<tt<<endl;
		}
	}
	else if(mn==t3)  {
		for(int i=0;i<n;i++) {
			string tt;
			for(int j=0;j<m;j++) tt.push_back(a3[j][i]);
			cout<<tt<<endl;
		}
	}
	else if(mn==t4)  {
		for(int i=0;i<n;i++) {
			string tt;
			for(int j=0;j<m;j++) tt.push_back(a4[j][i]);
			cout<<tt<<endl;
		}
	}
	else if(mn==t5)  {
		for(int i=0;i<n;i++) {
			string tt;
			for(int j=0;j<m;j++) tt.push_back(a5[j][i]);
			cout<<tt<<endl;
		}
	}
	return 0;
}