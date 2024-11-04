








int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    char** matrix = (char**)malloc(sizeof(char*) * n);
    for(int i = 0; i < n; i++)
        matrix[i] = malloc(m);

    getchar();

    for(int i = 0; i < n; i++) {

        gets(matrix[i]);
        for(int j = 0; j < m; j++)
            if(matrix[i][j] == '.') {
                if((i + j) % 2 == 0)
                    matrix[i][j] = 'B';
                else
                    matrix[i][j] = 'W';

            }

    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            printf("%c", matrix[i][j]);
        printf("\n");


    }
    return 0;

}
