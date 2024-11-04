














using namespace std;
const int maxn = 2e6 + 3;
typedef long long ll;

void read(int &x) {
	char ch; bool flag = 0;
	for (ch = getchar(); !isdigit(ch) && ((flag |= (ch == '-')) || 1); ch = getchar());
	for (x = 0; isdigit(ch); x = (x << 1) + (x << 3) + ch - 48, ch = getchar());
	x *= 1 - 2 * flag;
}

int vis[maxn];
char out[maxn];int top=0;
char str[maxn];
int main() {
    memset(vis,0,sizeof(vis));
    scanf("%s",str);
    char c='.';
    int len=strlen(str);
    for(int i=0;i<len;i++)
        vis[str[i]-'a']++;
    for(int i=0;i<26;i++) {
        if(vis[i]%2==1){
                bool f=1;
                for(int j=25;j>i;j--){
                    if(!vis[j])continue;
                    if(vis[j]%2){
                        vis[j]--;
                        vis[i]++;
                        f=0;
                        break;
                    }
                }
                if(f)c=i+'a';
        }
    }
	int li = 0;
	for(int i = 0; i < 26; i++)
	{
		if(vis[i]==0) continue;
		int t = vis[i]/2;
		while(t--)
		{
			out[li++] = i+'a';
		}
	}
	if(c!='.') out[li++] = c;
	for(int i = 25; i >=0; i--)
	{
		if(vis[i]==0) continue;
		int t = vis[i]/2;
		while(t--)
		{
			out[li++] = i+'a';
		}
	}
	printf("%s\n",out);
	return 0;
}



     


        

         



            

            
            

            


            
            

            


            

            
