#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int a[10], b[10];
char s[MAX_LEN];
int r, rr, x, y, xx, yy, zero;

void calc(int x){
    int y = 10 - x; 
    if (!a[x] || !a[y]) return;
    int r = 1; 
    for (int i = 0; i < 10; i++) {
        r += (a[i] - (i == x)) < (a[9-i] - (9-i == y)) ? (a[i] - (i == x)) : (a[9-i] - (9-i == y));
    }
    if (r > rr) {
        rr = r;
        xx = x;
        yy = y;
    }
}

int main(){
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        a[s[i] - '0']++;
    }
    
    r = 0;
    x = y = s[0] - '0';
    for (int i = 0; i <= a[0]; i++) {
        a[0] -= i;
        rr = 0;
        xx = yy = s[0] - '0';
        calc(1);
        calc(2);
        calc(3);
        calc(4);
        calc(5);
        if (rr + i > r) {
            r = rr + i;
            zero = i;
            x = xx;
            y = yy;
        }
        a[0] += i;
    }
    
    if (!x) {
        zero--;
    }
    a[0] -= zero;
    memcpy(b, a, sizeof(a));
    a[x]--;
    b[y]--;
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < a[i] - (a[i] < b[9-i]); j++) {
            printf("%d", i);
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < a[i] && j < b[9-i]; j++) {
            printf("%d", i);
        }
    }
    if (a[x] >= 0) {
        printf("%d", x);
    }
    for (int i = 0; i < zero; i++) {
        printf("0");
    }
    printf("\n");
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < b[9-i] - (a[i] < b[9-i]); j++) {
            printf("%d", 9-i);
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < a[i] && j < b[9-i]; j++) {
            printf("%d", 9-i);
        }
    }
    if (b[y] >= 0) {
        printf("%d", y);
    }
    for (int i = 0; i < zero; i++) {
        printf("0");
    }
    printf("\n");
    
    return 0;
}
