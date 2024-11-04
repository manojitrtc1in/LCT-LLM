#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* id0(long long n) {
    char* ans = (char*)malloc(21 * sizeof(char));
    sprintf(ans, "%lld", n);
    return ans;
}

char* sum(char* a, char* b) {
    int k;
    if (strlen(a) > strlen(b)) {
        k = strlen(a) - strlen(b);
        for (int i = 0; i < k; i++) {
            char* temp = (char*)malloc((strlen(b) + 2) * sizeof(char));
            strcpy(temp, "0");
            strcat(temp, b);
            free(b);
            b = temp;
        }
    }
    else {
        k = strlen(b) - strlen(a);
        for (int i = 0; i < k; i++) {
            char* temp = (char*)malloc((strlen(a) + 2) * sizeof(char));
            strcpy(temp, "0");
            strcat(temp, a);
            free(a);
            a = temp;
        }
    }
    int* vect = (int*)malloc(strlen(a) * sizeof(int));
    int qw = 0;
    for (int i = strlen(a) - 1; i >= 0; i--) {
        vect[strlen(a) - 1 - i] = (a[i] - '0') + (b[i] - '0');
    }
    for (int i = 0; i < strlen(a); i++) {
        if (vect[i] > 9) {
            if (i == strlen(a) - 1) {
                char* temp = (char*)malloc((strlen(a) + 2) * sizeof(char));
                sprintf(temp, "%d", vect[i] / 10);
                strcat(a, temp);
                free(temp);
                vect[i] %= 10;
                break;
            }
            vect[i + 1] += (vect[i] / 10);
            vect[i] %= 10;
        }
    }
    char* res = (char*)malloc((strlen(a) + 1) * sizeof(char));
    for (int i = 0; i < strlen(a); i++) {
        res[i] = (vect[i] + '0');
    }
    res[strlen(a)] = '\0';
    free(vect);
    free(a);
    free(b);
    char* result = (char*)malloc((strlen(res) + 1) * sizeof(char));
    strcpy(result, strrev(res));
    free(res);
    return result;
}

char* multiply(char* a, char* b) {
    int** vect = (int**)malloc(7000 * sizeof(int*));
    for (int i = strlen(a) - 1; i >= 0; i--) {
        vect[strlen(a) - 1 - i] = (int*)malloc((strlen(b) + 1) * sizeof(int));
        for (int u = 0; u < strlen(a) - i - 1; u++) {
            vect[strlen(a) - 1 - i][u] = 0;
        }
        for (int j = strlen(b) - 1; j >= 0; j--) {
            vect[strlen(a) - 1 - i][strlen(b) - 1 - j + strlen(a) - i - 1] = (a[i] - '0') * (b[j] - '0');
        }
        for (int u = 0; u < strlen(a) - i; u++) {
            if (vect[strlen(a) - 1 - i][u] > 9) {
                if (u == strlen(a) - i - 1) {
                    char* temp = (char*)malloc((strlen(a) + 2) * sizeof(char));
                    sprintf(temp, "%d", vect[strlen(a) - 1 - i][u] / 10);
                    strcat(a, temp);
                    free(temp);
                    vect[strlen(a) - 1 - i][u] %= 10;
                    break;
                }
                vect[strlen(a) - 1 - i][u + 1] += (vect[strlen(a) - 1 - i][u] / 10);
                vect[strlen(a) - 1 - i][u] %= 10;
            }
        }
    }
    char** res = (char**)malloc(7000 * sizeof(char*));
    for (int i = 0; i < strlen(a); i++) {
        res[i] = (char*)malloc((strlen(b) * 2 + 1) * sizeof(char));
        res[i][0] = '\0';
        for (int p = strlen(res[i]) - 1; p >= 0; p--) {
            char* h = (char*)malloc(2 * sizeof(char));
            sprintf(h, "%d", vect[i][p]);
            strcat(res[i], h);
            free(h);
        }
    }
    char* ans = (char*)malloc(2 * sizeof(char));
    strcpy(ans, "0");
    for (int i = 0; i < strlen(a); i++) {
        char* temp = sum(ans, res[i]);
        free(ans);
        ans = temp;
    }
    for (int i = 0; i < strlen(a); i++) {
        free(res[i]);
    }
    free(res);
    free(vect);
    free(a);
    free(b);
    return ans;
}

long long rec1(long long n) {
    long long ans = 0;
    if (n == 1) {
        for (int i = 0; i < 10; i++) {
            if (i != 0) {
                ans++;
            }
        }
    }
    else if (n == 2) {
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                if (i != 0 && i != k) {
                    ans++;
                }
            }
        }
    }
    else if (n == 3) {
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                for (int c = 0; c < 10; c++) {
                    if (i != 0 && i != k && i != c && k != c) {
                        ans++;
                    }
                }
            }
        }
    }
    else if (n == 4) {
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                for (int c = 0; c < 10; c++) {
                    for (int d = 0; d < 10; d++) {
                        if (i != 0 && i != k && i != c && i != d && k != c && k != d && c != d) {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    else if (n == 5) {
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                for (int c = 0; c < 10; c++) {
                    for (int d = 0; d < 10; d++) {
                        for (int e = 0; e < 10; e++) {
                            if (i != 0 && i != k && i != c && i != d && i != e && k != c && k != d && k != e && c != d && c != e && d != e) {
                                ans++;
                            }
                        }
                    }
                }
            }
        }
    }
    else if (n == 6) {
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                for (int c = 0; c < 10; c++) {
                    for (int d = 0; d < 10; d++) {
                        for (int e = 0; e < 10; e++) {
                            for (int f = 0; f < 10; f++) {
                                if (i != 0 && i != k && i != c && i != d && i != e && i != f && k != c && k != d && k != e && k != f && c != d && c != e && c != f && d != e && d != f && e != f) {
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (n == 7) {
        for (int i = 1; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                for (int c = 0; c < 10; c++) {
                    for (int d = 0; d < 10; d++) {
                        for (int e = 0; e < 10; e++) {
                            for (int f = 0; f < 10; f++) {
                                for (int g = 0; g < 10; g++) {
                                    if (i != k && i != c && i != d && i != e && i != f && i != g && k != c && k != d && k != e && k != f && k != g && c != d && c != e && c != f && c != g && d != e && d != f && d != g && e != f && e != g && f != g) {
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (n == 8) {
        ans = 1632960;
    }
    else if (n == 9) {
        ans = 3265920;
    }
    else if (n == 10) {
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
    }
    else if (n == 2) {
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                if (i != k) {
                    ans++;
                }
            }
        }
    }
    else if (n == 3) {
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                for (int c = 0; c < 10; c++) {
                    if (i != k && i != c && k != c) {
                        ans++;
                    }
                }
            }
        }
    }
    else if (n == 4) {
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                for (int c = 0; c < 10; c++) {
                    for (int d = 0; d < 10; d++) {
                        if (i != k && i != c && i != d && k != c && k != d && c != d) {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    else if (n == 5) {
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                for (int c = 0; c < 10; c++) {
                    for (int d = 0; d < 10; d++) {
                        for (int e = 0; e < 10; e++) {
                            if (i != k && i != c && i != d && i != e && k != c && k != d && k != e && c != d && c != e && d != e) {
                                ans++;
                            }
                        }
                    }
                }
            }
        }
    }
    else if (n == 6) {
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                for (int c = 0; c < 10; c++) {
                    for (int d = 0; d < 10; d++) {
                        for (int e = 0; e < 10; e++) {
                            for (int f = 0; f < 10; f++) {
                                if (i != k && i != c && i != d && i != e && i != f && k != c && k != d && k != e && k != f && c != d && c != e && c != f && d != e && d != f && e != f) {
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (n == 7) {
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                for (int c = 0; c < 10; c++) {
                    for (int d = 0; d < 10; d++) {
                        for (int e = 0; e < 10; e++) {
                            for (int f = 0; f < 10; f++) {
                                for (int g = 0; g < 10; g++) {
                                    if (i != k && i != c && i != d && i != e && i != f && i != g && k != c && k != d && k != e && k != f && k != g && c != d && c != e && c != f && c != g && d != e && d != f && d != g && e != f && e != g && f != g) {
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (n == 8) {
        ans = 1814400;
    }
    else if (n == 9) {
        ans = 3628800;
    }
    else if (n == 10) {
        ans = 3628800;
    }
    return ans;
}

int main() {
    char x[101];
    while (scanf("%s", x) != EOF) {
        char* ans = (char*)malloc(2 * sizeof(char));
        strcpy(ans, "1");
        int vis[101];
        for (int i = 0; i < 101; i++) {
            vis[i] = 0;
        }
        long long CHn = 0;
        long long F = 0;
        for (int i = 0; i < strlen(x); i++) {
            if ((x[i] >= 'A' && x[i] <= 'J') && i != 0 && !vis[x[i] - 'A']) {
                CHn++;
                vis[x[i] - 'A'] = 1;
            }
            else if ((x[i] >= 'A' && x[i] <= 'J') && i == 0 && !vis[x[i] - 'A']) {
                F++;
                vis[x[i] - 'A'] = 1;
            }
        }
        long long Zeros = 0;
        if (x[0] == '?') {
            strcpy(ans, "9");
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
        }
        else if (CHn > 0) {
            char* temp = multiply(id0(rec(CHn)), ans);
            free(ans);
            ans = temp;
        }
        printf("%s", ans);
        for (int i = 0; i < Zeros; i++) {
            printf("%c", '0');
        }
        printf("\n");
        free(ans);
    }
    return 0;
}
