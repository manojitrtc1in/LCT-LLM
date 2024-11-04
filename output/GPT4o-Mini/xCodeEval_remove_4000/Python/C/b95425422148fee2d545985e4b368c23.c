#include <stdio.h>
#include <string.h>

char z[] = "\"\"\"6\"k\"=\"3,\"iG\"17G\"6m?\"C@f\"2<6z\"ki1,\"1Y[{s\"dnF)N\"1j.&{o\"aZ>k}1\"173exa+\"atUi,},\"1canZ35z\"b*-!Ps6l\"1z<F!WJlC\"fQrp~1])H\"1}8l0AiPTl\"nXgm";
char q[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!";

long long zz(char *x) {
    long long a = 0;
    for (int i = 0; i < strlen(x); i++) {
        a = a * strlen(q) + (strchr(q, x[i]) - q);
    }
    return a;
}

int main() {
    long long k[100]; // Assuming a maximum of 100 elements
    char *token = strtok(z, "\"");
    int index = 0;

    while (token != NULL) {
        k[index++] = zz(token);
        token = strtok(NULL, "\"");
    }

    int n, m;
    scanf("%d %d", &n, &m);

    printf("%lld\n", k[n] % m);
    return 0;
}
