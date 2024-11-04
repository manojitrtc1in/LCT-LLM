#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* int_to_string(long long n)
{
    char* ans = (char*)malloc(21 * sizeof(char));
    sprintf(ans, "%lld", n);
    return ans;
}

char* sum(char* a, char* b)
{
    int k;
    int size_a = strlen(a);
    int size_b = strlen(b);
    if (size_a > size_b)
    {
        k = size_a - size_b;
        for (int i = 0; i < k; i++)
        {
            char* zero = "0";
            strcat(b, zero);
        }
    }
    else
    {
        k = size_b - size_a;
        for (int i = 0; i < k; i++)
        {
            char* zero = "0";
            strcat(a, zero);
        }
    }
    int vect[7000];
    memset(vect, 0, sizeof(vect));
    int qw = 0;
    for (int i = size_a - 1; i >= 0; i--)
    {
        vect[size_a - i - 1] = (a[i] - '0') + (b[i] - '0');
    }
    for (int i = 0; i < size_a; i++)
    {
        if (vect[i] > 9)
        {
            if (i == size_a - 1)
            {
                vect[size_a] = vect[i] / 10;
                vect[i] %= 10;
                break;
            }
            vect[i + 1] += (vect[i] / 10);
            vect[i] %= 10;
        }
    }
    char* res = (char*)malloc((size_a + 1) * sizeof(char));
    for (int i = 0; i < size_a; i++)
    {
        res[i] = (vect[i] + '0');
    }
    res[size_a] = '\0';
    int res_size = strlen(res);
    for (int i = 0; i < res_size / 2; i++)
    {
        char temp = res[i];
        res[i] = res[res_size - i - 1];
        res[res_size - i - 1] = temp;
    }
    return res;
}

char* multiply(char* a, char* b)
{
    int vect[7000][7000];
    memset(vect, 0, sizeof(vect));
    int size_a = strlen(a);
    int size_b = strlen(b);
    for (int i = size_a - 1; i >= 0; i--)
    {
        for (int u = 0; u < size_a - i - 1; u++)
            vect[size_a - i - 1][u] = 0;
        for (int j = size_b - 1; j >= 0; j--)
        {
            vect[size_a - i - 1][j + size_a - i - 1] = (a[i] - '0') * (b[j] - '0');
        }
        for (int u = 0; u < size_a - i - 1 + size_b; u++)
        {
            if (vect[size_a - i - 1][u] > 9)
            {
                if (u == size_a - i - 1 + size_b - 1)
                {
                    vect[size_a - i - 1][u + 1] = vect[size_a - i - 1][u] / 10;
                    vect[size_a - i - 1][u] = vect[size_a - i - 1][u] % 10;
                    break;
                }
                vect[size_a - i - 1][u + 1] += (vect[size_a - i - 1][u] / 10);
                vect[size_a - i - 1][u] = vect[size_a - i - 1][u] % 10;
            }
        }
    }
    char* res[7000];
    for (int i = 0; i < size_a; i++)
    {
        res[i] = (char*)malloc((size_a + size_b) * sizeof(char));
        memset(res[i], '\0', (size_a + size_b) * sizeof(char));
        int res_index = 0;
        for (int p = size_a - i - 1 + size_b - 1; p >= 0; p--)
        {
            char h[2];
            h[0] = (vect[i][p] + '0');
            h[1] = '\0';
            strcat(res[i], h);
        }
    }
    char* ans = (char*)malloc(100 * sizeof(char));
    strcpy(ans, "0");
    for (int i = 0; i < size_a; i++)
    {
        ans = sum(ans, res[i]);
    }
    return ans;
}

long long rec1(long long n)
{
    long long ans = 0;
    if (n == 1)
    {
        for (int i = 0; i < 10; i++)
        {
            if (i != 0)
                ans++;
        }
    }
    else if (n == 2)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int k = 0; k < 10; k++)
                if (i != 0 && i != k)
                    ans++;
        }
    }
    else if (n == 3)
    {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    if (i != 0 && i != k && i != c && k != c)
                        ans++;
    }
    else if (n == 4)
    {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        if (i != 0 && i != k && i != c && i != d && k != c && k != d && c != d)
                            ans++;
    }
    else if (n == 5)
    {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        for (int e = 0; e < 10; e++)
                            if (i != 0 && i != k && i != c && i != d && i != e && k != c && k != d && k != e && c != d && c != e && d != e)
                                ans++;
    }
    else if (n == 6)
    {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        for (int e = 0; e < 10; e++)
                            for (int f = 0; f < 10; f++)
                                if (i != 0 && i != k && i != c && i != d && i != e && i != f && k != c && k != d && k != e && k != f && c != d && c != e && c != f && d != e && d != f && e != f)
                                    ans++;
    }
    else if (n == 7)
    {
        for (int i = 1; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        for (int e = 0; e < 10; e++)
                            for (int f = 0; f < 10; f++)
                                for (int g = 0; g < 10; g++)
                                    if (i != k && i != c && i != d && i != e && i != f && i != g && k != c && k != d && k != e && k != f && k != g && c != d && c != e && c != f && c != g && d != e && d != f && d != g && e != f && e != g && f != g)
                                        ans++;
    }
    else if (n == 8)
    {
        ans = 1632960;
    }
    else if (n == 9)
    {
        ans = 3265920;
    }
    else if (n == 10)
    {
        ans = 3265920;
    }
    return ans;
}

long long rec(long long n)
{
    long long ans = 0;
    if (n == 1)
    {
        for (int i = 0; i < 10; i++)
        {
            ans++;
        }
    }
    else if (n == 2)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int k = 0; k < 10; k++)
                if (i != k)
                    ans++;
        }
    }
    else if (n == 3)
    {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    if (i != k && i != c && k != c)
                        ans++;
    }
    else if (n == 4)
    {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        if (i != k && i != c && i != d && k != c && k != d && c != d)
                            ans++;
    }
    else if (n == 5)
    {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        for (int e = 0; e < 10; e++)
                            if (i != k && i != c && i != d && i != e && k != c && k != d && k != e && c != d && c != e && d != e)
                                ans++;
    }
    else if (n == 6)
    {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        for (int e = 0; e < 10; e++)
                            for (int f = 0; f < 10; f++)
                                if (i != k && i != c && i != d && i != e && i != f && k != c && k != d && k != e && k != f && c != d && c != e && c != f && d != e && d != f && e != f)
                                    ans++;
    }
    else if (n == 7)
    {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        for (int e = 0; e < 10; e++)
                            for (int f = 0; f < 10; f++)
                                for (int g = 0; g < 10; g++)
                                    if (i != k && i != c && i != d && i != e && i != f && i != g && k != c && k != d && k != e && k != f && k != g && c != d && c != e && c != f && c != g && d != e && d != f && d != g && e != f && e != g && f != g)
                                        ans++;
    }
    else if (n == 8)
    {
        ans = 1814400;
    }
    else if (n == 9)
    {
        ans = 3628800;
    }
    else if (n == 10)
    {
        ans = 3628800;
    }
    return ans;
}

int main()
{
    char x[101];
    while (scanf("%s", x) != EOF)
    {
        char* ans = (char*)malloc(100 * sizeof(char));
        strcpy(ans, "1");
        int vis[101];
        memset(vis, 0, sizeof(vis));
        int size_x = strlen(x);
        long long CHn = 0;
        long long F = 0;
        for (int i = 0; i < size_x; i++)
        {
            if ((x[i] >= 'A' && x[i] <= 'J') && i != 0 && !vis[x[i] - 'A'])
            {
                CHn++;
                vis[x[i] - 'A'] = 1;
            }
            else if ((x[i] >= 'A' && x[i] <= 'J') && i == 0 && !vis[x[i] - 'A'])
            {
                F++;
                vis[x[i] - 'A'] = 1;
            }
        }
        long long Zeros = 0;
        if (x[0] == '?')
            strcpy(ans, "9");
        for (int i = 1; i < size_x; i++)
        {
            if (x[i] == '?')
            {
                Zeros++;
            }
        }
        if (F != 0)
        {
            char* rec1_result = int_to_string(rec1(F + CHn));
            ans = multiply(rec1_result, ans);
        }
        else if (CHn > 0)
        {
            char* rec_result = int_to_string(rec(CHn));
            ans = multiply(rec_result, ans);
        }
        printf("%s", ans);
        for (int i = 0; i < Zeros; i++)
        {
            printf("%c", '0');
        }
        printf("\n");
        free(ans);
    }
    return 0;
}
