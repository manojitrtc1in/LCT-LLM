

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
#include<set>
#include<vector>




using namespace std;

int main()
{
	int n;
	char a[55];
	scanf("%d", &n);
	scanf("%s", a);
	int t;
	int flag[27] = { 0 };
	int cnt[27] = { 0 };
	for (int i = 0; i < n; i++)
		if (a[i] >= 'a'&&a[i] <= 'z')
			flag[a[i] - 'a'] = 1;
	scanf("%d", &t);
	char aa[55];
	int tmp = 0;
	for (int i = 0; i < t; i++) {
		getchar();
		scanf("%s", aa);
		int ff = 0;
		int f[27] = { 0 };
		for(int j = 0;j<n;j++){
		    if( (flag[aa[j]-'a'] && aa[j]!=a[j]) || (a[j]!='*'&&aa[j]!=a[j])){
			   ff = 1;
			   break;
			}
		}
		if(ff){
		  tmp++;
		  continue;
		}
		for (int j = 0; j < n; j++) {
			if (!f[aa[j] - 'a']) {
				f[aa[j] - 'a'] = 1;
				cnt[aa[j] - 'a']++;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 26; i++) {
		if ((!flag[i]) && cnt[i] == t-tmp)
			ans++;
	}
	printf("%d\n", ans);
}











