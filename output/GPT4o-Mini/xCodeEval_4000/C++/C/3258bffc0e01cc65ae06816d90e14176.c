#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 100000
#define MOD 1000000007LL
#define INF 1e9
#define LINF 1e18
#define EPS 1e-9

char s[MAX_SIZE];
long long Map[256] = {0};
long long q = 0;

void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
char* cppstr_infile = "FILE.IN";
char* cppstr_outfile = "FILE.OUT";

void Input() {
    scanf("%s", s);
}

void Solve() {
    long long baseAnswer = 1;
    for (int i = 0; s[i] != '\0'; i++) {
        char x = s[i];
        if (x >= '0' && x <= '9') continue;
        if (x == '?') { q++; continue; }
        Map[x]++;
    }
    for (long long i = 10; i > 10 - (sizeof(Map) / sizeof(Map[0])); i--) baseAnswer *= i;
    if (s[0] >= 'A' && s[0] <= 'J') { baseAnswer /= 10; baseAnswer *= 9; }
    if (s[0] == '?') { baseAnswer *= 9; q--; }
    printf("%lld", baseAnswer);
    for (long long i = 0; i < q; i++) printf("0");
}

int main(int argc, char* argv[]) {
    ControlIO(argc, argv);
    TimerStart();
    Input();
    Solve();
    TimerStop();
    return 0;
}

void ControlIO(int argc, char* argv[]) {
    char infile[100], outfile[100];
    strcpy(infile, cppstr_infile);
    strcpy(outfile, cppstr_outfile);
    
    if (argc > 1) {
        freopen(argv[1], "r", stdin);
    }
    if (argc > 2) {
        freopen(argv[2], "w", stdout);
    }
}

void TimerStart() {
    // Timer start logic can be added here if needed
}

void TimerStop() {
    // Timer stop logic can be added here if needed
}

void Exit() {
    TimerStop(); exit(0);
}
