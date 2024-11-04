#include <algorithm>
#include <stack>
#include <istream>
#include <stdio.h>
#include <map>
#include <math.h>
#include <vector>
#include <iostream>
#include <queue>
#include <string.h>
#include <set>
#include <cstdio>
#define FR(i,n) for(int i=0;i<n;i++)
#define MAX 2005
#define mkp pair <int,int>
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
    for(int i=0;i<=26;i++) {
        if(vis[i]){
            if(vis[i]%2){
                bool f=1;
                for(int j=26;j>i;j--){
                    if(vis[j]%2){
                        vis[j]--;
                        vis[i]++;
                        f=0;
                        break;
                    }
                }
                if(f)c=i+'a';
            }
            int tmp=vis[i]/2;
            

            for(int k=0;k<tmp;k++)out[top++]=i+'a';
        }
    }
    

     for(int i=0;i<=26;i++)
     {
         if(vis[i]==1)c=i+'a';
     }
     for(int i=0;i<top;i++)
     {
         printf("%c",out[i]);
     }
     if(c!='.')
     printf("%c",c);
     for(int i=top-1;i>=0;i--)
     {
         printf("%c",out[i]);
     }
    return 0;
}


     


        

         



            

            
            

            


            
            

            


            

            
