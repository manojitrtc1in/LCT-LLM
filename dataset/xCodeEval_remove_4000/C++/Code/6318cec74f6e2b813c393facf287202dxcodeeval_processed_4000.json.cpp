

using namespace std;

int ma[100][100];
int ro[60];
int co[60];

int main()
{
    long long ans;
    int n, m;

    while(scanf("%d%d", &n, &m) == 2){
        ans = 0;
        memset(ro, 0, sizeof(ro));
        memset(co, 0, sizeof(co));
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                scanf("%d", &ma[i][j]);
            }
        }
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(ma[i][j] == 1){
                    ro[i] ++;
                    co[j] ++;
                }
            }
        }
        for(int i = 0; i < n; i ++){
            ans += ((LL)1 << ro[i]) - 1;
            

            

            ans += ((LL)1 << (m - ro[i])) - 1;
            

        }
        for(int i = 0; i < m; i ++){
            ans += ((LL)1 << co[i]) - 1;
            

            ans += ((LL)1 << (n - co[i])) - 1;
            

        }
        printf("%lld\n", ans - n * m);
    }

    return 0;
}


