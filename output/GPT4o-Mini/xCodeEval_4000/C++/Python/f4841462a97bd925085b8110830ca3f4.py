import math

CHUNK_SIZE = 100000

def _fill():
    N = 300000005
    p = [True] * N
    p[0] = p[1] = False

    bound = 20005
    for i in range(2, bound):
        if p[i]:
            for j in range(i * i, N, i):
                p[j] = False

    result = 0
    i = 0

    with open("output.txt", "w") as out:
        while i < N:
            if i % CHUNK_SIZE == 0:
                out.write(f"{result}, ")
            if i % (CHUNK_SIZE * 100) == 0:
                out.write('\n')
            i += 1
            if i < N and (i == 2 or i % 4 == 1):
                result += p[i]

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
    for A in range(1, int(math.sqrt(N)) + 1):
        B = max(int(math.sqrt(N - A * A)) - 2, 0)
        while A * A + B * B < N:
            B += 1
        if A * A + B * B == N:
            return True
    return False

def solve(N):
    baseInd = N // CHUNK_SIZE
    result = A[baseInd]
    for i in range(baseInd * CHUNK_SIZE + 1, N + 1):
        result += (prime(i) and sum2sq(i))
    return result

if __name__ == "__main__":
    _fill()
    l, r = map(int, input().split())
    print(solve(r) - solve(l - 1))
