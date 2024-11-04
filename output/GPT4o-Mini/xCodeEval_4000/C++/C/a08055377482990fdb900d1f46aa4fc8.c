#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAGIC 20000000
#define MAX 1000005

int t, la, ma, at, to[MAX];
int p[MAX];
struct {
    int *first;
    int second;
} pp[MAX];
int **s;
int m[300][2];
int x[289][289];
