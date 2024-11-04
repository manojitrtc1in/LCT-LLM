









int freq[3002];
int main() {

    int n;
    scanf("%d", &n);
    int array[n];

    for(int i = 0; i < n; i++) {

        scanf("%d", &array[i]);
        freq[array[i]] = 1;
    }

    for(int i = 1; i <= 3001; i++) {

        if(!freq[i]) {

            printf("%d", i);
            return 0;

        }

    }

    return 0;

}
