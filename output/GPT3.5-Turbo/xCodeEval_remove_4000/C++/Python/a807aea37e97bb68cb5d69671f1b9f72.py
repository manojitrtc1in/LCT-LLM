import sys
from typing import List, Tuple
from heapq import heappush, heappop

def solve(N: int, K: List[int]) -> int:
    MX = 5000
    K.sort()
    C = [0] * (MX+1)
    for k in K:
        C[k] += 1

    P = []
    is_prime = [True] * (MX+1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, MX+1):
        if is_prime[i]:
            P.append(i)
            for j in range(i*i, MX+1, i):
                is_prime[j] = False

    M = len(P)

    D = [[0] * M for _ in range(MX+1)]
    for i in range(M):
        p = P[i]
        for p in range(P[i], MX+1, P[i]):
            for j in range(MX+1):
                D[j][i] += j // p

    for i in range(MX+1):
        D[i].reverse()

    Pref = [[0] * (M+1) for _ in range(MX+1)]
    for i in range(MX+1):
        for j in range(M):
            Pref[i][j+1] = Pref[i][j] + D[i][j]

    CountPref = [0] * (MX+2)
    tot = 0
    for i in range(MX+1):
        CountPref[i+1] = CountPref[i] + C[i]
        tot += C[i] * Pref[i][M]

    use = K[N//2]
    W = []
    base = 0
    for i in range(MX+1):
        if C[i] == 0:
            continue

        x = 0
        length = 0
        while x < M and D[i][x] == D[use][x]:
            length += D[i][x]
            x += 1
        if x < M:
            length += min(D[i][x], D[use][x])
        W.append((length, C[i]))
        base += (Pref[i][M] - length) * C[i]

    W.sort()

    ans = float('inf')
    for w in W:
        cur = 0
        for ww in W:
            cur += abs(ww[0] - w[0]) * ww[1]
        ans = min(ans, base + cur)

    return ans

def from_input_string(input_string: str) -> Tuple[int, List[int]]:
    lines = input_string.strip().split('\n')
    N = int(lines[0])
    K = list(map(int, lines[1].split()))
    return N, K

def to_input_string(inputs: Tuple[int, List[int]]) -> str:
    N, K = inputs
    res = []
    res.append(str(N))
    res.append(' '.join(str(k) for k in K))
    return '\n'.join(res)

def from_output_string(output_string: str) -> int:
    return int(output_string.strip())

def to_output_string(output: int) -> str:
    return str(output)
