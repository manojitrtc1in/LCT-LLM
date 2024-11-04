



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {

    int n;
    scanf("%d", &n);
    getchar();
    char* team1 = malloc(11);
    char* team2 = malloc(11);
    team1[0] = '\0';
    team2[0] = '\0';
    int goals1 = 0, goals2 = 0;
    char* goal = malloc(11);

    for(int i = 0; i < n; i++) {

        gets(goal);

        if(team1[0] == '\0' && team2[0] == '\0') {

            strcpy(team1, goal);
            goals1++;

        } else if(team2[0] == '\0' && strcmp(team1, goal) != 0) {

            strcpy(team2, goal);
            goals2++;

        } else {

            if(strcmp(team1, goal) == 0)
                goals1++;
            else
                goals2++;

        }

    }
    if(goals1 > goals2)
        puts(team1);
    else
        puts(team2);
    return 0;

}
