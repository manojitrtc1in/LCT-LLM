












using namespace std;
const int Maxn = 1000 + 10;
char s[Maxn][Maxn];
char ___[Maxn];
int X[Maxn * Maxn], Y[Maxn * Maxn];
int read()
{
    int rt = 0, in = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') in = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {rt = rt * 10 + ch - '0'; ch = getchar();}
    return rt * in;
}

int main()
{
    int T = read();
    while(T--)
    {
        int n = read(), m = read();
        X[0] = Y[0] = 0;
        for(int i = 1; i <= n; i++) scanf("%s",s[i]+1);
        bool Flag = 1;
        for(int i = 0; i < m; i++)	___[i] = '1';
        ___[m] = 0;
		for(int i = 1; i < n; i++)
        	if(strcmp(s[i]+1, ___) != 0)
        		Flag = 0;
        if(n % 2 == 0)	Flag = 0;
        ___[m-1] = '0';
        
        if(Flag && strcmp(s[n]+1, ___) == 0)
        {
        	X[++X[0]] = n, Y[++Y[0]] = 1;
        	X[++X[0]] = n-1, Y[++Y[0]] = 1;
        	X[++X[0]] = n-1, Y[++Y[0]] = 2;
        	s[n][1] = s[n-1][1] = s[n-1][2] = '0';
		}
		___[m-1] = '1';
		___[0] = '0';
		if(Flag && strcmp(s[n]+1, ___) == 0)
        {
        	X[++X[0]] = n, Y[++Y[0]] = 2;
        	X[++X[0]] = n-1, Y[++Y[0]] = 1;
        	X[++X[0]] = n-1, Y[++Y[0]] = 2;
        	s[n][2] = s[n-1][1] = s[n-1][2] = '0';
		}
        for(int i = 1; i < n; i += 2)
        {
            for(int j = 1; j < m; j++)
            {
                if(j != m-1)
                {
                    int tot = 0;
                    if(s[i][j] == '0' && s[i+1][j] == '0')  continue;
                    if(s[i][j] == '1')  tot++, s[i][j] = '0', X[++X[0]] = i, Y[++Y[0]] = j;
                    if(s[i+1][j] == '1')    tot++, s[i+1][j] = '0', X[++X[0]] = i + 1, Y[++Y[0]] = j;
                    if(tot == 1)
                    {
                        X[++X[0]] = i, Y[++Y[0]] = j+1;
                        X[++X[0]] = i+1, Y[++Y[0]] = j+1;
                        if(s[i][j+1] == '0')    s[i][j+1] = '1';
                        else    s[i][j+1] = '0';
                        if(s[i+1][j+1] == '0')  s[i+1][j+1] = '1';
                        else    s[i+1][j+1] = '0';
                    }
                    if(tot == 2)
                    {
                        X[++X[0]] = i, Y[++Y[0]] = j + 1;
                        if(s[i][j+1] == '0')    s[i][j+1] = '1';
                        else    s[i][j+1] = '0';
                    }
                }
                if(j == m-1)
                {
                    int cnt = 0;
                    if(s[i][j] == '1')          cnt++;
                    if(s[i+1][j] == '1')        cnt++;
                    if(s[i][j+1] == '1')        cnt++;
                    if(s[i+1][j+1] == '1')      cnt++;
                    if(cnt == 0)    continue;
                    if(cnt == 3)
                    {
                        if(s[i][j] == '1')          X[++X[0]] = i, Y[++Y[0]] = j;
                        if(s[i+1][j] == '1')        X[++X[0]] = i + 1, Y[++Y[0]] = j;
                        if(s[i][j+1] == '1')        X[++X[0]] = i, Y[++Y[0]] = j + 1;
                        if(s[i+1][j+1] == '1')      X[++X[0]] = i + 1, Y[++Y[0]] = j + 1;
                        s[i][j] = s[i+1][j] = s[i][j+1] = s[i+1][j+1] = '0';
                    }
                    if(cnt == 2)
                    {
                        bool flag = 0;
                        int XX = 0, YY = 0;
                        if(!flag && s[i][j] == '1') s[i][j] = '0', flag = 1, XX = i, YY = j, X[++X[0]] = i, Y[++Y[0]] = j;
                        if(!flag && s[i+1][j] == '1') s[i+1][j] = '0', flag = 1, XX = i+1, YY = j, X[++X[0]] = i+1, Y[++Y[0]] = j;
                        if(!flag && s[i][j+1] == '1') s[i][j+1] = '0', flag = 1, XX = i, YY = j+1, X[++X[0]] = i, Y[++Y[0]] = j+1;
                        if(!flag && s[i+1][j+1] == '1') s[i+1][j+1] = '0', flag = 1, XX = i+1, YY = j+1, X[++X[0]] = i+1, Y[++Y[0]] = j+1;

                        if(s[i][j] == '0' && !(XX == i && YY == j))  s[i][j] = '1', X[++X[0]] = i, Y[++Y[0]] = j;
                        if(s[i+1][j] == '0' && !(XX == i+1 && YY == j))  s[i+1][j] = '1', X[++X[0]] = i+1, Y[++Y[0]] = j;
                        if(s[i][j+1] == '0' && !(XX == i && YY == j+1))  s[i][j+1] = '1', X[++X[0]] = i, Y[++Y[0]] = j+1;
                        if(s[i+1][j+1] == '0' && !(XX == i+1 && YY == j+1))  s[i+1][j+1] = '1', X[++X[0]] = i+1, Y[++Y[0]] = j+1;

                        if(s[i][j] == '1')          X[++X[0]] = i, Y[++Y[0]] = j;
                        if(s[i+1][j] == '1')        X[++X[0]] = i + 1, Y[++Y[0]] = j;
                        if(s[i][j+1] == '1')        X[++X[0]] = i, Y[++Y[0]] = j + 1;
                        if(s[i+1][j+1] == '1')      X[++X[0]] = i + 1, Y[++Y[0]] = j + 1;
                        s[i][j] = s[i+1][j] = s[i][j+1] = s[i+1][j+1] = '0';
                    }
                    if(cnt == 1)
                    {
                        int XX = 0, YY = 0;
                        if(s[i][j] == '1')          s[i][j] = '0', XX = i, YY = j, X[++X[0]] = i, Y[++Y[0]] = j;
                        if(s[i+1][j] == '1')        s[i+1][j] = '0', XX = i+1, YY = j, X[++X[0]] = i + 1, Y[++Y[0]] = j;
                        if(s[i][j+1] == '1')        s[i][j+1] = '0', XX = i, YY = j+1, X[++X[0]] = i, Y[++Y[0]] = j + 1;
                        if(s[i+1][j+1] == '1')      s[i+1][j+1] = '0', XX = i+1, YY = j+1, X[++X[0]] = i + 1, Y[++Y[0]] = j + 1;

                        int tot = 0;
                        if(tot <= 1 && s[i][j] == '0' && !(XX == i && YY == j))  tot++, s[i][j] = '1', X[++X[0]] = i, Y[++Y[0]] = j;
                        if(tot <= 1 && s[i+1][j] == '0' && !(XX == i+1 && YY == j))  tot++, s[i+1][j] = '1', X[++X[0]] = i+1, Y[++Y[0]] = j;
                        if(tot <= 1 && s[i][j+1] == '0' && !(XX == i && YY == j+1))  tot++, s[i][j+1] = '1', X[++X[0]] = i, Y[++Y[0]] = j+1;
                        if(tot <= 1 && s[i+1][j+1] == '0' && !(XX == i+1 && YY == j+1))  tot++, s[i+1][j+1] = '1', X[++X[0]] = i+1, Y[++Y[0]] = j+1;

                        bool flag = 0;
                        XX = 0, YY = 0;
                        if(!flag && s[i][j] == '1') s[i][j] = '0', flag = 1, XX = i, YY = j, X[++X[0]] = i, Y[++Y[0]] = j;
                        if(!flag && s[i+1][j] == '1') s[i+1][j] = '0', flag = 1, XX = i+1, YY = j, X[++X[0]] = i+1, Y[++Y[0]] = j;
                        if(!flag && s[i][j+1] == '1') s[i][j+1] = '0', flag = 1, XX = i, YY = j+1, X[++X[0]] = i, Y[++Y[0]] = j+1;
                        if(!flag && s[i+1][j+1] == '1') s[i+1][j+1] = '0', flag = 1, XX = i+1, YY = j+1, X[++X[0]] = i+1, Y[++Y[0]] = j+1;

                        if(s[i][j] == '0' && !(XX == i && YY == j))  s[i][j] = '1', X[++X[0]] = i, Y[++Y[0]] = j;
                        if(s[i+1][j] == '0' && !(XX == i+1 && YY == j))  s[i+1][j] = '1', X[++X[0]] = i+1, Y[++Y[0]] = j;
                        if(s[i][j+1] == '0' && !(XX == i && YY == j+1))  s[i][j+1] = '1', X[++X[0]] = i, Y[++Y[0]] = j+1;
                        if(s[i+1][j+1] == '0' && !(XX == i+1 && YY == j+1))  s[i+1][j+1] = '1', X[++X[0]] = i+1, Y[++Y[0]] = j+1;

                        if(s[i][j] == '1')          X[++X[0]] = i, Y[++Y[0]] = j;
                        if(s[i+1][j] == '1')        X[++X[0]] = i + 1, Y[++Y[0]] = j;
                        if(s[i][j+1] == '1')        X[++X[0]] = i, Y[++Y[0]] = j + 1;
                        if(s[i+1][j+1] == '1')      X[++X[0]] = i + 1, Y[++Y[0]] = j + 1;
                        s[i][j] = s[i+1][j] = s[i][j+1] = s[i+1][j+1] = '0';
                    }
                    if(cnt == 4)
                    {
                        if(j != m-1)
                        {
                            X[++X[0]] = i, Y[++Y[0]] = j; s[i][j] = '0';
                            X[++X[0]] = i+1, Y[++Y[0]] = j; s[i+1][j] = '0';
                            X[++X[0]] = i, Y[++Y[0]] = j+1; s[i][j+1] = '0';
                            continue;
                        }
                        if(j == m-1)
                        {
                            X[++X[0]] = i, Y[++Y[0]] = j; s[i][j] = '0';
                            X[++X[0]] = i+1, Y[++Y[0]] = j; s[i+1][j] = '0';
                            X[++X[0]] = i, Y[++Y[0]] = j+1; s[i][j+1] = '0';

                            int XX = 0, YY = 0;
                            if(s[i][j] == '1')          s[i][j] = '0', XX = i, YY = j, X[++X[0]] = i, Y[++Y[0]] = j;
                            if(s[i+1][j] == '1')        s[i+1][j] = '0', XX = i+1, YY = j, X[++X[0]] = i + 1, Y[++Y[0]] = j;
                            if(s[i][j+1] == '1')        s[i][j+1] = '0', XX = i, YY = j+1, X[++X[0]] = i, Y[++Y[0]] = j + 1;
                            if(s[i+1][j+1] == '1')      s[i+1][j+1] = '0', XX = i+1, YY = j+1, X[++X[0]] = i + 1, Y[++Y[0]] = j + 1;

                            int tot = 0;
                            if(tot <= 1 && s[i][j] == '0' && !(XX == i && YY == j))  tot++, s[i][j] = '1', X[++X[0]] = i, Y[++Y[0]] = j;
                            if(tot <= 1 && s[i+1][j] == '0' && !(XX == i+1 && YY == j))  tot++, s[i+1][j] = '1', X[++X[0]] = i+1, Y[++Y[0]] = j;
                            if(tot <= 1 && s[i][j+1] == '0' && !(XX == i && YY == j+1))  tot++, s[i][j+1] = '1', X[++X[0]] = i, Y[++Y[0]] = j+1;
                            if(tot <= 1 && s[i+1][j+1] == '0' && !(XX == i+1 && YY == j+1))  tot++, s[i+1][j+1] = '1', X[++X[0]] = i+1, Y[++Y[0]] = j+1;

                            bool flag = 0;
                            XX = 0, YY = 0;
                            if(!flag && s[i][j] == '1') s[i][j] = '0', flag = 1, XX = i, YY = j, X[++X[0]] = i, Y[++Y[0]] = j;
                            if(!flag && s[i+1][j] == '1') s[i+1][j] = '0', flag = 1, XX = i+1, YY = j, X[++X[0]] = i+1, Y[++Y[0]] = j;
                            if(!flag && s[i][j+1] == '1') s[i][j+1] = '0', flag = 1, XX = i, YY = j+1, X[++X[0]] = i, Y[++Y[0]] = j+1;
                            if(!flag && s[i+1][j+1] == '1') s[i+1][j+1] = '0', flag = 1, XX = i+1, YY = j+1, X[++X[0]] = i+1, Y[++Y[0]] = j+1;

                            if(s[i][j] == '0' && !(XX == i && YY == j))  s[i][j] = '1', X[++X[0]] = i, Y[++Y[0]] = j;
                            if(s[i+1][j] == '0' && !(XX == i+1 && YY == j))  s[i+1][j] = '1', X[++X[0]] = i+1, Y[++Y[0]] = j;
                            if(s[i][j+1] == '0' && !(XX == i && YY == j+1))  s[i][j+1] = '1', X[++X[0]] = i, Y[++Y[0]] = j+1;
                            if(s[i+1][j+1] == '0' && !(XX == i+1 && YY == j+1))  s[i+1][j+1] = '1', X[++X[0]] = i+1, Y[++Y[0]] = j+1;

                            if(s[i][j] == '1')          X[++X[0]] = i, Y[++Y[0]] = j;
                            if(s[i+1][j] == '1')        X[++X[0]] = i + 1, Y[++Y[0]] = j;
                            if(s[i][j+1] == '1')        X[++X[0]] = i, Y[++Y[0]] = j + 1;
                            if(s[i+1][j+1] == '1')      X[++X[0]] = i + 1, Y[++Y[0]] = j + 1;
                            s[i][j] = s[i+1][j] = s[i][j+1] = s[i+1][j+1] = '0';    
                        }
                    }
                }

            }
        }
        

        

        if(n % 2 == 1)
        {
            for(int i = n-1; i <= n-1; i++)
            {
                for(int j = 1; j < m; j++)
                {
                    if(j != m-1)
                    {
                        int tot = 0;
                        if(s[i][j] == '0' && s[i+1][j] == '0')  continue;
                        if(s[i][j] == '1')  tot++, s[i][j] = '0', X[++X[0]] = i, Y[++Y[0]] = j;
                        if(s[i+1][j] == '1')    tot++, s[i+1][j] = '0', X[++X[0]] = i + 1, Y[++Y[0]] = j;
                        

                        

                        if(tot == 1)
                        {
                            X[++X[0]] = i, Y[++Y[0]] = j+1;
                            X[++X[0]] = i+1, Y[++Y[0]] = j+1;
                            if(s[i][j+1] == '0')    s[i][j+1] = '1';
                            else    s[i][j+1] = '0';
                            if(s[i+1][j+1] == '0')  s[i+1][j+1] = '1';
                            else    s[i+1][j+1] = '0';
                        }
                        if(tot == 2)
                        {
                            X[++X[0]] = i, Y[++Y[0]] = j + 1;
                            if(s[i][j+1] == '0')    s[i][j+1] = '1';
                            else    s[i][j+1] = '0';
                        }
                    }
                    if(j == m-1)
                    {
                        int cnt = 0;
                        if(s[i][j] == '1')          cnt++;
                        if(s[i+1][j] == '1')        cnt++;
                        if(s[i][j+1] == '1')        cnt++;
                        if(s[i+1][j+1] == '1')      cnt++;
                        if(cnt == 0)    continue;
                        if(cnt == 3)
                        {
                            if(s[i][j] == '1')          X[++X[0]] = i, Y[++Y[0]] = j;
                            if(s[i+1][j] == '1')        X[++X[0]] = i + 1, Y[++Y[0]] = j;
                            if(s[i][j+1] == '1')        X[++X[0]] = i, Y[++Y[0]] = j + 1;
                            if(s[i+1][j+1] == '1')      X[++X[0]] = i + 1, Y[++Y[0]] = j + 1;
                            s[i][j] = s[i+1][j] = s[i][j+1] = s[i+1][j+1] = '0';
                        }
                        if(cnt == 2)
                        {
                            bool flag = 0;
                            int XX = 0, YY = 0;
                            if(!flag && s[i][j] == '1') s[i][j] = '0', flag = 1, XX = i, YY = j, X[++X[0]] = i, Y[++Y[0]] = j;
                            if(!flag && s[i+1][j] == '1') s[i+1][j] = '0', flag = 1, XX = i+1, YY = j, X[++X[0]] = i+1, Y[++Y[0]] = j;
                            if(!flag && s[i][j+1] == '1') s[i][j+1] = '0', flag = 1, XX = i, YY = j+1, X[++X[0]] = i, Y[++Y[0]] = j+1;
                            if(!flag && s[i+1][j+1] == '1') s[i+1][j+1] = '0', flag = 1, XX = i+1, YY = j+1, X[++X[0]] = i+1, Y[++Y[0]] = j+1;

                            if(s[i][j] == '0' && !(XX == i && YY == j))  s[i][j] = '1', X[++X[0]] = i, Y[++Y[0]] = j;
                            if(s[i+1][j] == '0' && !(XX == i+1 && YY == j))  s[i+1][j] = '1', X[++X[0]] = i+1, Y[++Y[0]] = j;
                            if(s[i][j+1] == '0' && !(XX == i && YY == j+1))  s[i][j+1] = '1', X[++X[0]] = i, Y[++Y[0]] = j+1;
                            if(s[i+1][j+1] == '0' && !(XX == i+1 && YY == j+1))  s[i+1][j+1] = '1', X[++X[0]] = i+1, Y[++Y[0]] = j+1;

                            if(s[i][j] == '1')          X[++X[0]] = i, Y[++Y[0]] = j;
                            if(s[i+1][j] == '1')        X[++X[0]] = i + 1, Y[++Y[0]] = j;
                            if(s[i][j+1] == '1')        X[++X[0]] = i, Y[++Y[0]] = j + 1;
                            if(s[i+1][j+1] == '1')      X[++X[0]] = i + 1, Y[++Y[0]] = j + 1;
                            s[i][j] = s[i+1][j] = s[i][j+1] = s[i+1][j+1] = '0';
                        }
                        if(cnt == 1)
                        {
                            int XX = 0, YY = 0;
                            if(s[i][j] == '1')          s[i][j] = '0', XX = i, YY = j, X[++X[0]] = i, Y[++Y[0]] = j;
                            if(s[i+1][j] == '1')        s[i+1][j] = '0', XX = i+1, YY = j, X[++X[0]] = i + 1, Y[++Y[0]] = j;
                            if(s[i][j+1] == '1')        s[i][j+1] = '0', XX = i, YY = j+1, X[++X[0]] = i, Y[++Y[0]] = j + 1;
                            if(s[i+1][j+1] == '1')      s[i+1][j+1] = '0', XX = i+1, YY = j+1, X[++X[0]] = i + 1, Y[++Y[0]] = j + 1;

                            int tot = 0;
                            if(tot <= 1 && s[i][j] == '0' && !(XX == i && YY == j))  tot++, s[i][j] = '1', X[++X[0]] = i, Y[++Y[0]] = j;
                            if(tot <= 1 && s[i+1][j] == '0' && !(XX == i+1 && YY == j))  tot++, s[i+1][j] = '1', X[++X[0]] = i+1, Y[++Y[0]] = j;
                            if(tot <= 1 && s[i][j+1] == '0' && !(XX == i && YY == j+1))  tot++, s[i][j+1] = '1', X[++X[0]] = i, Y[++Y[0]] = j+1;
                            if(tot <= 1 && s[i+1][j+1] == '0' && !(XX == i+1 && YY == j+1))  tot++, s[i+1][j+1] = '1', X[++X[0]] = i+1, Y[++Y[0]] = j+1;

                            bool flag = 0;
                            XX = 0, YY = 0;
                            if(!flag && s[i][j] == '1') s[i][j] = '0', flag = 1, XX = i, YY = j, X[++X[0]] = i, Y[++Y[0]] = j;
                            if(!flag && s[i+1][j] == '1') s[i+1][j] = '0', flag = 1, XX = i+1, YY = j, X[++X[0]] = i+1, Y[++Y[0]] = j;
                            if(!flag && s[i][j+1] == '1') s[i][j+1] = '0', flag = 1, XX = i, YY = j+1, X[++X[0]] = i, Y[++Y[0]] = j+1;
                            if(!flag && s[i+1][j+1] == '1') s[i+1][j+1] = '0', flag = 1, XX = i+1, YY = j+1, X[++X[0]] = i+1, Y[++Y[0]] = j+1;

                            if(s[i][j] == '0' && !(XX == i && YY == j))  s[i][j] = '1', X[++X[0]] = i, Y[++Y[0]] = j;
                            if(s[i+1][j] == '0' && !(XX == i+1 && YY == j))  s[i+1][j] = '1', X[++X[0]] = i+1, Y[++Y[0]] = j;
                            if(s[i][j+1] == '0' && !(XX == i && YY == j+1))  s[i][j+1] = '1', X[++X[0]] = i, Y[++Y[0]] = j+1;
                            if(s[i+1][j+1] == '0' && !(XX == i+1 && YY == j+1))  s[i+1][j+1] = '1', X[++X[0]] = i+1, Y[++Y[0]] = j+1;

                            if(s[i][j] == '1')          X[++X[0]] = i, Y[++Y[0]] = j;
                            if(s[i+1][j] == '1')        X[++X[0]] = i + 1, Y[++Y[0]] = j;
                            if(s[i][j+1] == '1')        X[++X[0]] = i, Y[++Y[0]] = j + 1;
                            if(s[i+1][j+1] == '1')      X[++X[0]] = i + 1, Y[++Y[0]] = j + 1;
                            s[i][j] = s[i+1][j] = s[i][j+1] = s[i+1][j+1] = '0';
                        }
                        if(cnt == 4)
                        {
                            if(j != m-1)
                            {
                                X[++X[0]] = i, Y[++Y[0]] = j; s[i][j] = '0';
                                X[++X[0]] = i+1, Y[++Y[0]] = j; s[i+1][j] = '0';
                                X[++X[0]] = i, Y[++Y[0]] = j+1; s[i][j+1] = '0';
                                continue;
                            }
                            if(j == m-1)
                            {
                                X[++X[0]] = i, Y[++Y[0]] = j; s[i][j] = '0';
                                X[++X[0]] = i+1, Y[++Y[0]] = j; s[i+1][j] = '0';
                                X[++X[0]] = i, Y[++Y[0]] = j+1; s[i][j+1] = '0';

                                int XX = 0, YY = 0;
                                if(s[i][j] == '1')          s[i][j] = '0', XX = i, YY = j, X[++X[0]] = i, Y[++Y[0]] = j;
                                if(s[i+1][j] == '1')        s[i+1][j] = '0', XX = i+1, YY = j, X[++X[0]] = i + 1, Y[++Y[0]] = j;
                                if(s[i][j+1] == '1')        s[i][j+1] = '0', XX = i, YY = j+1, X[++X[0]] = i, Y[++Y[0]] = j + 1;
                                if(s[i+1][j+1] == '1')      s[i+1][j+1] = '0', XX = i+1, YY = j+1, X[++X[0]] = i + 1, Y[++Y[0]] = j + 1;

                                int tot = 0;
                                if(tot <= 1 && s[i][j] == '0' && !(XX == i && YY == j))  tot++, s[i][j] = '1', X[++X[0]] = i, Y[++Y[0]] = j;
                                if(tot <= 1 && s[i+1][j] == '0' && !(XX == i+1 && YY == j))  tot++, s[i+1][j] = '1', X[++X[0]] = i+1, Y[++Y[0]] = j;
                                if(tot <= 1 && s[i][j+1] == '0' && !(XX == i && YY == j+1))  tot++, s[i][j+1] = '1', X[++X[0]] = i, Y[++Y[0]] = j+1;
                                if(tot <= 1 && s[i+1][j+1] == '0' && !(XX == i+1 && YY == j+1))  tot++, s[i+1][j+1] = '1', X[++X[0]] = i+1, Y[++Y[0]] = j+1;

                                bool flag = 0;
                                XX = 0, YY = 0;
                                if(!flag && s[i][j] == '1') s[i][j] = '0', flag = 1, XX = i, YY = j, X[++X[0]] = i, Y[++Y[0]] = j;
                                if(!flag && s[i+1][j] == '1') s[i+1][j] = '0', flag = 1, XX = i+1, YY = j, X[++X[0]] = i+1, Y[++Y[0]] = j;
                                if(!flag && s[i][j+1] == '1') s[i][j+1] = '0', flag = 1, XX = i, YY = j+1, X[++X[0]] = i, Y[++Y[0]] = j+1;
                                if(!flag && s[i+1][j+1] == '1') s[i+1][j+1] = '0', flag = 1, XX = i+1, YY = j+1, X[++X[0]] = i+1, Y[++Y[0]] = j+1;

                                if(s[i][j] == '0' && !(XX == i && YY == j))  s[i][j] = '1', X[++X[0]] = i, Y[++Y[0]] = j;
                                if(s[i+1][j] == '0' && !(XX == i+1 && YY == j))  s[i+1][j] = '1', X[++X[0]] = i+1, Y[++Y[0]] = j;
                                if(s[i][j+1] == '0' && !(XX == i && YY == j+1))  s[i][j+1] = '1', X[++X[0]] = i, Y[++Y[0]] = j+1;
                                if(s[i+1][j+1] == '0' && !(XX == i+1 && YY == j+1))  s[i+1][j+1] = '1', X[++X[0]] = i+1, Y[++Y[0]] = j+1;

                                if(s[i][j] == '1')          X[++X[0]] = i, Y[++Y[0]] = j;
                                if(s[i+1][j] == '1')        X[++X[0]] = i + 1, Y[++Y[0]] = j;
                                if(s[i][j+1] == '1')        X[++X[0]] = i, Y[++Y[0]] = j + 1;
                                if(s[i+1][j+1] == '1')      X[++X[0]] = i + 1, Y[++Y[0]] = j + 1;
                                s[i][j] = s[i+1][j] = s[i][j+1] = s[i+1][j+1] = '0';    
                            }
                        }
                    }
                }
            }
        }
        cout << X[0] / 3 << endl;








        for(int i = 1; i <= X[0]; i += 3)
            printf("%d %d %d %d %d %d\n",X[i],Y[i],X[i+1],Y[i+1],X[i+2],Y[i+2]);
    }
    return 0;
}
 	 			 	 	    				 	 				 				