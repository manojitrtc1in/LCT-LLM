import sys
from typing import List

def solve(id: int, p: List[float], n: int, k: int) -> float:
    if p[id] <= 1e-9:
        return 0.0
    
    subret = [0.0] * (k+1)
    subret[0] = dp = p[id]
    for i in range(1, (1 << n)):
        dp = 0.0
        if (i >> id) & 1:
            continue
        sum = 0.0
        for j in range(n):
            if (i >> j) & 1:
                sum += p[j]
                dp += dp ^ (1 << j) * p[j]
        dp /= 1 - sum
        subret[bin(i).count('1')] += dp
    
    ret = 0.0
    for i in range(k):
        ret += subret[i]
    
    return ret

def main():
    n, k = map(int, input().split())
    p = list(map(float, input().split()))
    
    for i in range(n):
        print(solve(i, p, n, k))

if __name__ == "__main__":
    main()
