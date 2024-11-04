#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXI 536870912

#define FORN(i,a,b)     for (int i=(a),_b=(b); i<_b; i++)
#define RFORN(i,b,a)    for (int i=(b)-1,_a=(a); i>=_a; i--)
#define RESET(a,b)      memset((a),(b),sizeof(a))

#define SC(x)           scanf("%d",&x)
#define SC2(x,y)        scanf("%d %d",&x,&y)
#define PR(x)           printf("%d ",x)
#define PR2(x,y)        printf("%d %d ",x,y)
#define PRS(x)          printf("%s",x)
#define END             printf("\n")
#define EXIT(x)         {PRS(x);return 0;}
#define DBG(x)          {printf("--> %s = %d\n", #x, x);}

typedef struct {
    int fi;
    int se;
} ii;

int dp[5005][5005];

const int M = 1000000007;

int main(){
    char s[5005], t[5005];
    scanf("%s %s", s, t);
    RESET(dp, 0);
    int s_len = strlen(s);
    int t_len = strlen(t);
    FORN (i, 0, s_len)
        FORN (j, 0, t_len){
            if (s[i] == t[j]) dp[i + 1][j + 1] = (((dp[i + 1][j] % M)) + ((dp[i][j] + 1) % M)) % M;
            else dp[i + 1][j + 1] = dp[i + 1][j];
        }
    int re = 0;
    FORN (i, 0, s_len) re = (re + dp[i + 1][t_len] % M) % M;
    PR(re);
}
