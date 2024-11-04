#include <stdio.h>
#include <string.h>

char z[] = "6\"k\"=\"3,\"iG\"17G\"6m?\"C@f\"2<6z\"ki1,\"1Y[{s\"dnF)N\"1j.&{o\"aZ>k}1\"173exa+\"atUi,},\"1canZ35z\"b*-!Ps6l\"1z<F!WJlC\"fQrp~1])H\"1}8l0AiPTl\"nXgm";

char q[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!";

int zz(char *x) {
    int a = 0;
    int len = strlen(q);
    for (int i = 0; i < strlen(x); i++) {
        a = a * len + strchr(q, x[i]) - q;
    }
    return a;
}

int main() {
    int k[100];
    char *token = strtok(z, "\"");
    int i = 0;
    while (token != NULL) {
        k[i++] = zz(token);
        token = strtok(NULL, "\"");
    }

    int n, m;
    scanf("%d %d", &n, &m);

    printf("%d\n", k[n] % m);

    return 0;
}
