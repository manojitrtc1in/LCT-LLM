








int main() {

    int k, d;

    scanf("%d %d", &k, &d);

    if(d == 0 && k == 1) {

        printf("0");
        return 0;

    } else if(d == 0 && k != 0) {

        printf("No solution");
        return 0;

    }

    printf("%c", d + '0');

    for(int i = 1; i < k; i++)
        printf("0");

    return 0;

}
