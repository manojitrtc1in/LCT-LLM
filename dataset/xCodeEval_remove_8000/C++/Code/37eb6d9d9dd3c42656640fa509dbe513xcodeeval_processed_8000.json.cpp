



















































































































































































































































































 
























































































































































































































































































































































































































































































































































 




 


 










 






 


























 

























 
































































































































































































 




 






 







































 








 




















































 

































 




 


 




 






 




















 




















 








 










































































 


















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































typedef long long LL;
using namespace std;

int t, n, num1[27], num2[27], ans[205][2];
char s1[55], s2[55];

int main()
{
	

	


	scanf("%d", &t);
	while(t--){
		set<int> st1[27], st2[27];
		scanf("%d %s %s", &n, s1 + 1, s2 + 1);
		memset(num1, 0, sizeof(num1));
		memset(num2, 0, sizeof(num2));
		for (int i = 1; i <= n; i++) num1[s1[i] - 'a']++, num2[s2[i] - 'a']++;
		for (int i = 1; i <= n; i++){
			st1[s1[i] - 'a'].insert(i), st2[s2[i] - 'a'].insert(i);
		}
		int f = 0;
		for (int i = 0; i < 26; i++) if((num1[i] + num2[i]) & 1) {f = 1; break;}
		if(f) {printf("No\n"); continue;}
		printf("Yes\n");
		int cnt = 0;
		for (int i = 1; i <= n; i++){
			if(s1[i] == s2[i]) {
				st1[s1[i] - 'a'].erase(i);
				st2[s2[i] - 'a'].erase(i);
				continue;
			}
			st1[s1[i] - 'a'].erase(i);
			if(st2[s1[i] - 'a'].empty()){
				int pos = *st1[s1[i] - 'a'].begin();
				st2[s2[i] - 'a'].erase(i);
				st1[s1[i] - 'a'].erase(pos);
				st1[s2[i] - 'a'].insert(pos);
				

				swap(s1[pos], s2[i]);
				ans[cnt][0] = pos, ans[cnt++][1] = i;
			}else{
				int pos = *st2[s1[i] - 'a'].begin();
				st2[s1[i] - 'a'].erase(pos);
				st1[s1[i + 1] - 'a'].erase(i + 1);
				st2[s1[i + 1] - 'a'].insert(pos);
				swap(s1[i + 1], s2[pos]);
				st2[s2[i] - 'a'].erase(i);
				st1[s2[i] - 'a'].insert(i + 1);
				swap(s1[i + 1], s2[i]);
				ans[cnt][0] = i + 1, ans[cnt++][1] = pos;
				ans[cnt][0] = i + 1, ans[cnt++][1] = i;
			}
			

		}
		printf("%d\n", cnt);
		for (int i = 0; i < cnt; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
	}

	return 0;
}
