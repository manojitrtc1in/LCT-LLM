from collections import deque
from itertools import accumulate
import sys

MX = 5000

class Sieve:
    def __init__(self, n):
        self.n = n
        self.is_prime = [True] * (n + 1)
        self.is_prime[0] = self.is_prime[1] = False
        for i in range(2, int(n**0.5) + 1):
            if self.is_prime[i]:
                for j in range(i * i, n + 1, i):
                    self.is_prime[j] = False

    def primes(self):
        return [i for i in range(self.n + 1) if self.is_prime[i]]

class DChaoticV:
    def solve(self, cin, cout):
        N = int(cin.readline())
        K = list(map(int, cin.readline().split()))
        K.sort()
        C = [0] * (MX + 1)
        for k in K:
            C[k] += 1

        P = Sieve(MX).primes()
        M = len(P)

        D = [[0] * M for _ in range(MX + 1)]
        for i in range(M):
            p = P[i]
            for p in (P[i],):
                for j in range(MX + 1):
                    D[j][i] += j // p

        for i in range(MX + 1):
            D[i].reverse()

        Pref = [[0] * (M + 1) for _ in range(MX + 1)]
        for i in range(MX + 1):
            for j in range(M):
                Pref[i][j + 1] = Pref[i][j] + D[i][j]

        CountPref = [0] * (MX + 2)
        tot = 0
        for i in range(MX + 1):
            CountPref[i + 1] = CountPref[i] + C[i]
            tot += C[i] * Pref[i][M]

        use = K[N // 2]
        W = []
        base = 0
        for i in range(MX + 1):
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

        cout.write(f"{ans}\n")

if __name__ == "__main__":
    input = sys.stdin.read
    output = sys.stdout
    solver = DChaoticV()
    solver.solve(input, output)
