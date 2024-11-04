import sys
from typing import List, Tuple

def solve() -> int:
    fact = [0] * 201010
    revFact = [0] * 202020
    fact[0] = 1
    N = 200000
    for i in range(1, N + 1):
        fact[i] = fact[i - 1] * i % 998244353
    revFact[N] = pow(fact[N], 998244353 - 2, 998244353)
    for i in range(N - 1, -1, -1):
        revFact[i] = revFact[i + 1] * (i + 1) % 998244353
    
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.append(a[0])
    cnt = 0
    for i in range(n):
        cnt += a[i] != a[i + 1]
    if k == 1 or n == 1:
        print(0)
        return 0
    ans = 0
    freeChoices = k - 2
    for i in range(cnt // 2 + 1):
        cur = (fact[cnt] * revFact[i] % 998244353 * revFact[cnt - i] % 998244353 * pow(freeChoices, cnt - 2 * i, 998244353) % 998244353 * pow(k, n - cnt, 998244353) % 998244353)
        ans += cur
    ans %= 998244353
    tot = pow(k, n, 998244353) - ans
    if tot < 0:
        tot += 998244353
    print(tot * pow(2, 998244353 - 2, 998244353) % 998244353)
    return 0

if __name__ == "__main__":
    solve()
