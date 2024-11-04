








int main() {

    int y, k, n;

    scanf("%d %d %d", &y, &k, &n);
    int x = k - y % k;
    int find  = 0;
    while(x + y <= n) {

        printf("%d ", x);
        find = 1;
        x+= k;
    }

    if(!find)
        printf("-1");

    return 0;

}
