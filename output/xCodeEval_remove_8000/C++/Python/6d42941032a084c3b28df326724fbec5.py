import sys
from typing import List

MOD = 998244353

def solve(n: int, m: int, a: List[int], w: List[int]) -> List[int]:
    W1 = 0
    W2 = 0
    for i in range(n):
        if a[i]:
            W1 += w[i]
        else:
            W2 += w[i]
    
    probs = [0] * (m + 1)
    probs[0] = 1
    for i in range(m):
        new_probs = [0] * (m + 1)
        for d1 in range(i + 1):
            d2 = d1 - i
            w1 = W1 + d1
            w2 = W2 + d2
            w0 = w1 + w2
            if probs[d1] and (w2 >= 0):
                id16 = pow(w0, MOD - 2, MOD)
                if w2 > 0:
                    new_probs[d1] = (new_probs[d1] + (probs[d1] * w2 * id16) % MOD) % MOD
                new_probs[d1 + 1] = (new_probs[d1 + 1] + (probs[d1] * w1 * id16) % MOD) % MOD
        probs = new_probs
    
    id4 = [0] * (m + 1)
    id29 = [0] * (m + 1)
    id4[0] = 1
    id29[0] = 1
    for i in range(1, m + 1):
        id4[i] = (id4[i - 1] * ((1 + pow(W1 + i - 1, MOD - 2, MOD)) % MOD)) % MOD
    for i in range(1, m + 1):
        id29[i] = (id29[i - 1] * ((1 - pow(W2 - i + 1, MOD - 2, MOD)) % MOD)) % MOD
    
    coef1 = 0
    coef2 = 0
    for i in range(m + 1):
        coef1 = (coef1 + (id4[i] * probs[i]) % MOD) % MOD
    for i in range(m + 1):
        coef2 = (coef2 + (id29[i] * probs[m - i]) % MOD) % MOD
    
    res = []
    for i in range(n):
        if a[i]:
            res.append((w[i] * coef1) % MOD)
        else:
            res.append((w[i] * coef2) % MOD)
    return res

def main() -> None:
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    w = list(map(int, input().split()))
    res = solve(n, m, a, w)
    for r in res:
        print(r)

if __name__ == "__main__":
    main()
