#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define CHUNK_SIZE 100000

bool prime(int N)
{
    if(N < 2) return false;
    for(int i = 2; i * i <= N; i++)
    {
        if(N % i == 0) return false;
    }
    return true;
}

bool sum2sq(int N)
{
    if(N != 2 && N % 4 != 1) return false;
    for(int A = 1; A * A < N; A++)
    {
        int B = (int)max(sqrt((double)(N - A * A)) - 2.0, 0.0);
        while(A * A + B * B < N) B++;
        if(A * A + B * B == N) return true;
    }
    return false;
}

int solve(int N)
{
    int baseInd = N / CHUNK_SIZE;
    int result = A[baseInd];
    for(int i = baseInd * CHUNK_SIZE + 1; i <= N; i++)
    {
        result += (prime(i) && sum2sq(i));
    }
    return result;
}

int main()
{
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d", solve(r) - solve(l - 1));

    return 0;
}
