









int freq1[27], freq2[27];

int main() {

    int n;
    scanf("%d", &n);
    getchar();
    char* question = malloc(15);

    int left = INT_MIN / 2;
    int right = INT_MAX / 2;

    for(int i = 0; i < n && left <= right; i++) {

        gets(question);
        

        if(question[0] == '>' && question[1] == '=' && question[strlen(question) -1 ] == 'Y' ||
                (question[0] == '<' && question[1] != '=' && question[strlen(question) - 1] == 'N')) {

            char* tok = strtok(question, " ");
            tok = strtok(NULL, " ");
            if(atoi(tok) > left)
                left = atoi(tok);


        } else if(question[0] == '>' && question[1] != '=' && question[strlen(question) - 1] == 'Y' ||
                  (question[0] == '<' && question[1] == '=' && question[strlen(question) - 1] == 'N')) {

            char* tok = strtok(question, " ");
            tok = strtok(NULL, " ");
            if(atoi(tok) + 1 > left)
                left = atoi(tok) + 1;

        } else if(question[0] == '<' && question[1] == '=' && question[strlen(question) - 1] == 'Y' ||
                  (question[0] == '>' && question[1] != '=' && question[strlen(question) - 1] == 'N')) {

            char* tok = strtok(question, " ");
            tok = strtok(NULL, " ");
            if(atoi(tok) < right)
                right = atoi(tok);

        } else if(question[0] == '<' && question[1] != '=' && question[strlen(question) - 1] == 'Y' ||
                  (question[0] == '>' && question[1] == '=' && question[strlen(question) - 1] == 'N')) {

            char* tok = strtok(question, " ");
            tok = strtok(NULL, " ");
            if(atoi(tok) - 1 < right)
                right = atoi(tok) - 1;

        }
    }

    if(left <= right) {

        printf("%d", right);

    } else
        printf("Impossible");
    return 0;
}
