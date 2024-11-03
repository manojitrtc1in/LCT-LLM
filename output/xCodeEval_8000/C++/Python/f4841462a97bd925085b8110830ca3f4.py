import math

CHUNK_SIZE = 100000

def prime(N):
    if N < 2:
        return False
    for i in range(2, int(math.sqrt(N)) + 1):
        if N % i == 0:
            return False
    return True

def sum2sq(N):
    if N != 2 and N % 4 != 1:
        return False
    for A in range(1, int(math.sqrt(N))):
        B = int(max(math.sqrt(N - A * A) - 2.0, 0.0))
        while A * A + B * B < N:
            B += 1
        if A * A + B * B == N:
            return True
    return False

def solve(N):
    baseInd = N // CHUNK_SIZE
    result = A[baseInd]
    for i in range(baseInd * CHUNK_SIZE + 1, N + 1):
        result += prime(i) and sum2sq(i)
    return result

l, r = map(int, input().split())
print(solve(r) - solve(l - 1))
