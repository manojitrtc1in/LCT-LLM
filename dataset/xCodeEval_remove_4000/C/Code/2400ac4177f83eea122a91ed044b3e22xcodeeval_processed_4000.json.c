








int main() {

    int n;
    scanf("%d", &n);
    getchar();
    char* team1 = malloc(11);
    char* team2 = malloc(11);
    team1[0] = '\0';
    team2[0] = '\0';
    int id1 = 0, id0 = 0;
    char* goal = malloc(11);

    for(int i = 0; i < n; i++) {

        gets(goal);

        if(team1[0] == '\0' && team2[0] == '\0') {

            strcpy(team1, goal);
            id1++;

        } else if(team2[0] == '\0' && strcmp(team1, goal) != 0) {

            strcpy(team2, goal);
            id0++;

        } else {

            if(strcmp(team1, goal) == 0)
                id1++;
            else
                id0++;

        }

    }
    if(id1 > id0)
        puts(team1);
    else
        puts(team2);
    return 0;

}
