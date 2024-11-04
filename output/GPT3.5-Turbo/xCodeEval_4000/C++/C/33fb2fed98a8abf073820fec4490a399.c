#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* int_to_string(long long n)
{
    char* ans = (char*)malloc(20 * sizeof(char));
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
            char* temp = (char*)malloc(2 * sizeof(char));
            temp[0] = '0';
            temp[1] = '\0';
            strcat(temp, b);
            strcpy(b, temp);
            free(temp);
        }
    }
    else
    {
        k = size_b - size_a;
        for (int i = 0; i < k; i++)
        {
            char* temp = (char*)malloc(2 * sizeof(char));
            temp[0] = '0';
            temp[1] = '\0';
            strcat(temp, a);
            strcpy(a, temp);
            free(temp);
        }
    }
    int* vect = (int*)malloc(size_a * sizeof(int));
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
                vect = (int*)realloc(vect, (size_a + 1) * sizeof(int));
                vect[i + 1] = vect[i] / 10;
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
    free(vect);
    char* reversed_res = (char*)malloc((size_a + 1) * sizeof(char));
    int j = 0;
    for (int i = size_a - 1; i >= 0; i--)
    {
        reversed_res[j] = res[i];
        j++;
    }
    reversed_res[size_a] = '\0';
    free(res);
    return reversed_res;
}

char* multiply(char* a, char* b)
{
    int** vect = (int**)malloc(7000 * sizeof(int*));
    for (int i = 0; i < 7000; i++)
    {
        vect[i] = (int*)malloc(7000 * sizeof(int));
    }
    int size_a = strlen(a);
    int size_b = strlen(b);
    for (int i = size_a - 1; i >= 0; i--)
    {
        for (int u = 0; u < size_a - i - 1; u++)
        {
            vect[size_a - i - 1][u] = 0;
        }
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
                    vect[size_a - i - 1] = (int*)realloc(vect[size_a - i - 1], (size_a - i - 1 + size_b + 1) * sizeof(int));
                    vect[size_a - i - 1][u + 1] = vect[size_a - i - 1][u] / 10;
                    vect[size_a - i - 1][u] %= 10;
                    break;
                }
                vect[size_a - i - 1][u + 1] += (vect[size_a - i - 1][u] / 10);
                vect[size_a - i - 1][u] %= 10;
            }
        }
    }
    char** res = (char**)malloc(7000 * sizeof(char*));
    for (int i = 0; i < size_a; i++)
    {
        res[i] = (char*)malloc((size_a + size_b) * sizeof(char));
        res[i][0] = '\0';
        for (int p = size_a - i - 1 + size_b - 1; p >= 0; p--)
        {
            char* h = (char*)malloc(2 * sizeof(char));
            h[0] = (vect[i][p] + '0');
            h[1] = '\0';
            strcat(res[i], h);
            free(h);
        }
    }
    char* ans = (char*)malloc((size_a + size_b) * sizeof(char));
    ans[0] = '0';
    ans[1] = '\0';
    for (int i = 0; i < size_a; i++)
    {
        char* temp = sum(ans, res[i]);
        free(ans);
        ans = temp;
    }
    for (int i = 0; i < 7000; i++)
    {
        free(vect[i]);
        free(res[i]);
    }
    free(vect);
    free(res);
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
        char* ans = (char*)malloc(100000 * sizeof(char));
        ans[0] = '1';
        ans[1] = '\0';

        int vis[101];
        for (int i = 0; i < 101; i++)
            vis[i] = 0;

        long long CHn = 0;
        long long F = 0;
        int size_x = strlen(x);
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
            char* temp = multiply(int_to_string(rec1(F + CHn)), ans);
            free(ans);
            ans = temp;
        }
        else if (CHn > 0)
        {
            char* temp = multiply(int_to_string(rec(CHn)), ans);
            free(ans);
            ans = temp;
        }

        printf("%s", ans);
        for (int i = 0; i < Zeros; i++)
            printf("%c", '0');
        printf("\n");
        free(ans);
    }
    return 0;
}
