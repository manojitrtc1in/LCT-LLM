#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define GIGAMOD 1000000007
#define MAX_LENGTH 1000000

typedef struct {
    char *data;
    int length;
} String;

int check(char *tgt, char *src, int n) {
    char xDig = 0;
    for (int i = 0; i < n; i++) {
        if (src[i] == 'X') {
            if (xDig == 0) {
                xDig = tgt[i];
            } else {
                if (tgt[i] != xDig) return 0;
            }
        }
    }
    if (tgt[0] == '0') return 0;
    for (int i = 0; i < n; i++) {
        if (src[i] != '_' && src[i] != 'X' && tgt[i] != src[i]) return 0;
    }
    return 1;
}

int main() {
    int t = 1;
    for (int tc = 0; tc < t; tc++) {
        char sOG[MAX_LENGTH];
        scanf("%s", sOG);
        int n = strlen(sOG);
        
        if (n == 1) {
            if (sOG[0] == '0' || sOG[0] == '_' || sOG[0] == 'X')
                printf("1\n");
            else
                printf("0\n");
            continue;
        }

        int answer = 0;

        {
            char s[MAX_LENGTH];
            strcpy(s, sOG);
            bool shit = (s[n - 1] != '_' && s[n - 1] != 'X' && s[n - 1] != '0');
            shit |= (s[n - 2] != '_' && s[n - 2] != 'X' && s[n - 2] != '0');

            if (!shit) {
                if (s[n - 1] == 'X' || s[n - 2] == 'X') {
                    for (int i = 0; i < n; i++)
                        if (s[i] == 'X')
                            s[i] = '0';
                }
                s[n - 1] = '0';
                s[n - 2] = '0';

                answer += check("00", s, 2);
                for (int num = 0; num < 1000000; num++) {
                    char tgt[10];
                    sprintf(tgt, "%d00", num);
                    answer += check(tgt, s, 2);
                }
            }
        }

        {
            char s[MAX_LENGTH];
            strcpy(s, sOG);
            bool shit = (s[n - 1] != '_' && s[n - 1] != 'X' && s[n - 1] != '5');
            shit |= (s[n - 2] != '_' && s[n - 2] != 'X' && s[n - 2] != '2');
            shit |= (s[n - 1] == 'X' && s[n - 2] == 'X');

            if (!shit) {
                if (s[n - 1] == 'X') {
                    for (int i = 0; i < n; i++)
                        if (s[i] == 'X')
                            s[i] = '5';
                } else if (s[n - 2] == 'X') {
                    for (int i = 0; i < n; i++)
                        if (s[i] == 'X')
                            s[i] = '2';
                }

                s[n - 1] = '5';
                s[n - 2] = '2';

                answer += check("25", s, 2);
                for (int num = 0; num < 1000000; num++) {
                    char tgt[10];
                    sprintf(tgt, "%d25", num);
                    answer += check(tgt, s, 2);
                }
            }
        }

        {
            char s[MAX_LENGTH];
            strcpy(s, sOG);
            bool shit = (s[n - 1] != '_' && s[n - 1] != 'X' && s[n - 1] != '0');
            shit |= (s[n - 2] != '_' && s[n - 2] != 'X' && s[n - 2] != '5');
            shit |= (s[n - 1] == 'X' && s[n - 2] == 'X');

            if (!shit) {
                if (s[n - 1] == 'X') {
                    for (int i = 0; i < n; i++)
                        if (s[i] == 'X')
                            s[i] = '0';
                } else if (s[n - 2] == 'X') {
                    for (int i = 0; i < n; i++)
                        if (s[i] == 'X')
                            s[i] = '5';
                }

                s[n - 1] = '0';
                s[n - 2] = '5';

                answer += check("50", s, 2);
                for (int num = 0; num < 1000000; num++) {
                    char tgt[10];
                    sprintf(tgt, "%d50", num);
                    answer += check(tgt, s, 2);
                }
            }
        }

        {
            char s[MAX_LENGTH];
            strcpy(s, sOG);
            bool shit = (s[n - 1] != '_' && s[n - 1] != 'X' && s[n - 1] != '5');
            shit |= (s[n - 2] != '_' && s[n - 2] != 'X' && s[n - 2] != '7');
            shit |= (s[n - 1] == 'X' && s[n - 2] == 'X');

            if (!shit) {
                if (s[n - 1] == 'X') {
                    for (int i = 0; i < n; i++)
                        if (s[i] == 'X')
                            s[i] = '5';
                } else if (s[n - 2] == 'X') {
                    for (int i = 0; i < n; i++)
                        if (s[i] == 'X')
                            s[i] = '7';
                }

                s[n - 1] = '5';
                s[n - 2] = '7';

                answer += check("75", s, 2);
                for (int num = 0; num < 1000000; num++) {
                    char tgt[10];
                    sprintf(tgt, "%d75", num);
                    answer += check(tgt, s, 2);
                }
            }
        }

        printf("%d\n", answer);
    }
    return 0;
}
