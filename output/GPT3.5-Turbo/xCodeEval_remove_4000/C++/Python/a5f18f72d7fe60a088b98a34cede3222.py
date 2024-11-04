import sys
from typing import List, Tuple

def solve(n: int, k: List[int]) -> int:
    p = primes(5000)
    d = id7(5001)
    id0 = [[0] * 5001 for _ in range(5001)]
    id0[0] = []
    id0[1] = []
    for i in range(2, 5001):
        id0[i] = id0[i - 1][:]
        if d[i] == i:
            id0[i].append(1)
        else:
            for q in range(i, 1, -1):
                if q % d[q] == 0:
                    id0[i].append(p.index(d[q]))
                    break
    answer = 0
    q = getQty(k, 5001)
    lost = 0
    still = [True] * 5001
    cur = [0] * len(p)
    while True:
        cur = [0] * len(p)
        for i in range(5001):
            if still[i] and id0[i]:
                cur[len(id0[i]) - 1] += q[i]
        pos = cur.index(max(cur))
        if cur[pos] <= n // 2:
            pos = -2
        step = sys.maxsize
        for i in range(5001):
            if still[i] and len(id0[i]) - 1 != pos:
                answer += q[i] * sum(id0[i])
                lost += q[i]
                still[i] = False
            elif still[i]:
                step = min(step, id0[i][-1])
        if pos == -2:
            break
        answer += step * lost
        for i in range(5001):
            if still[i]:
                id0[i][-1] -= step
                if id0[i][-1] == 0:
                    id0[i].pop()
    return answer

def primes(n: int) -> List[int]:
    isPrime = id5(n)
    res = []
    for i in range(n):
        if isPrime[i]:
            res.append(i)
    return res

def id5(n: int) -> List[bool]:
    res = [True] * n
    res[0] = False
    res[1] = False
    for i in range(2, int(n ** 0.5)):
        if res[i]:
            for j in range(i * i, n, i):
                res[j] = False
    return res

def id7(n: int) -> List[int]:
    res = [0] * n
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
    answer = solve(n, k)
    print(answer)

if __name__ == "__main__":
    main()
