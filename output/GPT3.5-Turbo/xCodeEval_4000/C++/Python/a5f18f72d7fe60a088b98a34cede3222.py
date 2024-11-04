import sys
from typing import List, Tuple

def solve(n: int, k: List[int]) -> int:
    p = primes(5000)
    d = divisorTable(5001)
    divisors = [[] for _ in range(5001)]
    divisors[0] = []
    divisors[1] = []
    for i in range(2, 5001):
        divisors[i] = divisors[i - 1][:]
        if d[i] == i:
            divisors[i].append(1)
        else:
            for q in range(i, 1, -1):
                if q % d[q] == 0:
                    divisors[i].append(p.index(d[q]))
                    break
    answer = 0
    q = getQty(k, 5001)
    lost = 0
    still = [True] * 5001
    cur = [0] * len(p)
    while True:
        cur = [0] * len(p)
        for i in range(5001):
            if still[i] and divisors[i]:
                cur[len(divisors[i]) - 1] += q[i]
        pos = cur.index(max(cur))
        if cur[pos] <= n // 2:
            pos = -2
        step = sys.maxsize
        for i in range(5001):
            if still[i] and len(divisors[i]) - 1 != pos:
                answer += q[i] * sum(divisors[i])
                lost += q[i]
                still[i] = False
            elif still[i]:
                step = min(step, divisors[i][-1])
        if pos == -2:
            break
        answer += step * lost
        for i in range(5001):
            if still[i]:
                divisors[i][-1] -= step
                if divisors[i][-1] == 0:
                    divisors[i].pop()
    return answer

def primes(n: int) -> List[int]:
    isPrime = primalityTable(n)
    res = []
    for i in range(n):
        if isPrime[i]:
            res.append(i)
    return res

def primalityTable(n: int) -> List[bool]:
    res = [True] * n
    if n > 0:
        res[0] = False
    if n > 1:
        res[1] = False
    for i in range(2, int(n ** 0.5)):
        if res[i]:
            for j in range(i * i, n, i):
                res[j] = False
    return res

def divisorTable(n: int) -> List[int]:
    res = [0] * n
    if n > 1:
        res[1] = 1
    for i in range(2, n):
        if res[i] == 0:
            res[i] = i
            if i * i < n:
                for j in range(i * i, n, i):
                    res[j] = i
    return res

def getQty(arr: List[int], length: int) -> List[int]:
    res = [0] * length
    for i in arr:
        res[i] += 1
    return res

def main() -> None:
    n = int(input())
    k = list(map(int, input().split()))
    result = solve(n, k)
    print(result)

if __name__ == "__main__":
    main()
