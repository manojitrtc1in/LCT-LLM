#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* id0(long long n) {
    char* ans = (char*)malloc(21 * sizeof(char)); // Enough for long long
    sprintf(ans, "%lld", n);
    return ans;
}

char* sum(char* a, char* b) {
    int k;
    if (strlen(a) > strlen(b)) {
        k = strlen(a) - strlen(b);
        for (int i = 0; i < k; i++) {
            memmove(b + 1, b, strlen(b) + 1);
            b[0] = '0';
        }
    } else {
        k = strlen(b) - strlen(a);
        for (int i = 0; i < k; i++) {
            memmove(a + 1, a, strlen(a) + 1);
            a[0] = '0';
        }
    }
    
    long long vect[7000] = {0};
    int qw = 0;
    for (int i = strlen(a) - 1; i >= 0; i--) {
        vect[qw++] = (a[i] - '0') + (b[i] - '0');
    }
    
    for (int i = 0; i < qw; i++) {
        if (vect[i] > 9) {
            if (i == qw - 1) {
                vect[i + 1] += vect[i] / 10;
                vect[i] %= 10;
                qw++;
                break;
            }
            vect[i + 1] += (vect[i] / 10);
            vect[i] %= 10;
        }
    }
    
    char* res = (char*)malloc((qw + 1) * sizeof(char));
    for (int i = 0; i < qw; i++) {
        res[i] = vect[i] + '0';
    }
    res[qw] = '\0';
    
    // Reverse the result
    for (int i = 0; i < qw / 2; i++) {
        char temp = res[i];
        res[i] = res[qw - i - 1];
        res[qw - i - 1] = temp;
    }
    
    return res;
}

char* multiply(char* a, char* b) {
    long long vect[7000][7000] = {0};
    for (int i = strlen(a) - 1; i >= 0; i--) {
        for (int u = 0; u < strlen(a) - i - 1; u++) {
            vect[strlen(a) - i - 1][u] = 0;
        }
        for (int j = strlen(b) - 1; j >= 0; j--) {
            vect[strlen(a) - i - 1][strlen(b) - j - 1] = (a[i] - '0') * (b[j] - '0');
        }
        for (int u = 0; u < strlen(b); u++) {
            if (vect[strlen(a) - i - 1][u] > 9) {
                if (u == strlen(b) - 1) {
                    vect[strlen(a) - i - 1][u + 1] += vect[strlen(a) - i - 1][u] / 10;
                    vect[strlen(a) - i - 1][u] %= 10;
                    break;
                }
                vect[strlen(a) - i - 1][u + 1] += (vect[strlen(a) - i - 1][u] / 10);
                vect[strlen(a) - i - 1][u] %= 10;
            }
        }
    }
    
    char* res[7000];
    for (int i = 0; i < strlen(a); i++) {
        res[i] = (char*)malloc(7000 * sizeof(char));
        for (int p = strlen(b) - 1; p >= 0; p--) {
            char h[2] = {(char)(vect[i][p] + '0'), '\0'};
            strcat(res[i], h);
        }
    }
    
    char* ans = id0(0);
    for (int i = 0; i < strlen(a); i++) {
        char* temp = sum(ans, res[i]);
        free(ans);
        ans = temp;
    }
    
    return ans;
}

long long rec1(long long n) {
    long long ans = 0;
    if (n == 1) {
        for (int i = 0; i < 10; i++) {
            if (i != 0) ans++;
        }
    } else if (n == 2) {
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                if (i != 0 && i != k) ans++;
            }
        }
    } else if (n == 3) {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    if (i != 0 && i != k && i != c && k != c) ans++;
    } else if (n == 4) {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        if (i != 0 && i != k && i != c && i != d && k != c && k != d && c != d) ans++;
    } else if (n == 5) {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        for (int e = 0; e < 10; e++)
                            if (i != 0 && i != k && i != c && i != d && i != e && k != c && k != d && k != e && c != d && c != e && d != e) ans++;
    } else if (n == 6) {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        for (int e = 0; e < 10; e++)
                            for (int f = 0; f < 10; f++)
                                if (i != 0 && i != k && i != c && i != d && i != e && i != f && k != c && k != d && k != e && k != f && c != d && c != e && c != f && d != e && d != f && e != f) ans++;
    } else if (n == 7) {
        for (int i = 1; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        for (int e = 0; e < 10; e++)
                            for (int f = 0; f < 10; f++)
                                for (int g = 0; g < 10; g++)
                                    if (i != k && i != c && i != d && i != e && i != f && i != g && k != c && k != d && k != e && k != f && k != g && c != d && c != e && c != f && c != g && d != e && d != f && d != g && e != f && e != g && f != g) ans++;
    } else if (n == 8) {
        ans = 1632960;
    } else if (n == 9) {
        ans = 3265920;
    } else if (n == 10) {
        ans = 3265920;
    }
    return ans;
}

long long rec(long long n) {
    long long ans = 0;
    if (n == 1) {
        for (int i = 0; i < 10; i++) {
            ans++;
        }
    } else if (n == 2) {
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                if (i != k) ans++;
            }
        }
    } else if (n == 3) {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    if (i != k && i != c && k != c) ans++;
    } else if (n == 4) {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        if (i != k && i != c && i != d && k != c && k != d && c != d) ans++;
    } else if (n == 5) {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        for (int e = 0; e < 10; e++)
                            if (i != k && i != c && i != d && i != e && k != c && k != d && k != e && c != d && c != e && d != e) ans++;
    } else if (n == 6) {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        for (int e = 0; e < 10; e++)
                            for (int f = 0; f < 10; f++)
                                if (i != k && i != c && i != d && i != e && i != f && k != c && k != d && k != e && k != f && c != d && c != e && c != f && d != e && d != f && e != f) ans++;
    } else if (n == 7) {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        for (int e = 0; e < 10; e++)
                            for (int f = 0; f < 10; f++)
                                for (int g = 0; g < 10; g++)
                                    if (i != k && i != c && i != d && i != e && i != f && i != g && k != c && k != d && k != e && k != f && k != g && c != d && c != e && c != f && c != g && d != e && d != f && d != g && e != f && e != g && f != g) ans++;
    } else if (n == 8) {
        ans = 1814400;
    } else if (n == 9) {
        ans = 3628800;
    } else if (n == 10) {
        ans = 3628800;
    }
    return ans;
}

int main() {
    char x[101];
    
    while (scanf("%s", x) != EOF) {
        char* ans = id0(1);
        
        int vis[101] = {0};
        long long CHn = 0;
        long long F = 0;
        
        for (int i = 0; i < strlen(x); i++) {
            if ((x[i] >= 'A' && x[i] <= 'J') && i != 0 && !vis[x[i] - 'A']) {
                CHn++;
                vis[x[i] - 'A'] = 1;
            } else if ((x[i] >= 'A' && x[i] <= 'J') && i == 0 && !vis[x[i] - 'A']) {
                F++;
                vis[x[i] - 'A'] = 1;
            }
        }
        
        long long Zeros = 0;
        if (x[0] == '?') {
            ans = id0(9);
        }
        for (int i = 1; i < strlen(x); i++) {
            if (x[i] == '?') {
                Zeros++;
            }
        }
        
        if (F != 0) {
            char* temp = multiply(id0(rec1(F + CHn)), ans);
            free(ans);
            ans = temp;
        } else if (CHn > 0) {
            char* temp = multiply(id0(rec(CHn)), ans);
            free(ans);
            ans = temp;
        }
        
        printf("%s", ans);
        for (int i = 0; i < Zeros; i++) printf("0");
        printf("\n");
        
        free(ans);
    }
    return 0;
}
